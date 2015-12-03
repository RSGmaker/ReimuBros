package;

/**
 * ...
 * @author RSGmaker
 */
class Alice extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var leftshanghai:Bullet;
	public var rightshanghai:Bullet;
	public function new() 
	{
		super("alice");
		charname = "alice";
		accel = 0.4;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		pointvalue = 600;
		needtokill = true;
		HP = 1;
		reward = true;
	}
	override public function attack(player:Player):Bool
	{
		/*HP--;
		if (HP > 0)
		{
			invincibility = 10;
		}
		return HP < 1;*/
		if (leftshanghai.alive)
		{
			leftshanghai.alive = false;
			invincibility = 15;
			return false;
		}
		if (rightshanghai.alive)
		{
			rightshanghai.alive = false;
			invincibility = 15;
			return false;
		}
		return true;
	}
	public override function increaserank()
	{
			accel += 0.05;
			mxspd += 0.25;
			pointvalue += 400;
	}
	override public function update():Void 
	{
		this.scaleX = 0.6;
		this.scaleY = 0.6;
		if (invincibility > 0)
		{
			invincibility--;
		}
	if (!started)
		{
			var O = new Bullet();
			O.x = x-30;
			O.y = y+20;
			O.scaleX = 0.4;
			O.scaleY = O.scaleX;
			O.type = "shanghai";
			O.wraplimit = -1;
			O.ChangeAnimation("shanghai");
			game.AddObject(O);
			leftshanghai = O;
			
			O = new Bullet();
			O.x = x+30;
			O.y = y+20;
			O.scaleX = 0.4;
			O.scaleY = O.scaleX;
			O.type = "shanghai";
			O.wraplimit = -1;
			O.ChangeAnimation("shanghai");
			game.AddObject(O);
			rightshanghai = O;
			started = true;
		}
		var spr = "shanghai";
		if (Ldir < 0)
		{
			spr = spr + "F";
		}
		var Y = (y + height) - leftshanghai.height;
		leftshanghai.x = x - 30;
		leftshanghai.y = Y;
		leftshanghai.ChangeAnimation(spr);
		
		rightshanghai.x = x + 30+20;
		rightshanghai.y = Y;
		rightshanghai.ChangeAnimation(spr);
		if (!killed)
		{
		var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
			if (flipped == 0)
			{
				flipped = -1;
				powerup();
			}
		}
		else
		{
			dangerous = true;
		}
		if (Hspeed < mxspd && dir==1 && flipped < 1)
		{
			Hspeed += accel;
			if (Hspeed > mxspd)
			{
				Hspeed = mxspd;
			}
		}
		if (Hspeed > -mxspd && dir==-1 && flipped < 1)
		{
			Hspeed -= accel;
			if (Hspeed < -mxspd)
			{
				Hspeed = -mxspd;
			}
		}
		updphysics();
		updateanimation();
		
		if (ground != null)
		{
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				if (game.myplayer == ground.bonkedby)
				{
				var D:Dynamic = { };
				D.UID = UID;
				D.x = x;
				D.y = y;
				D.Hspeed = Hspeed;
				D.Vspeed = -10;
				game.SendEvent("Bump", D);
				}
			}
			else
			{
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -4;
				}
			}
			
		}
			if (y > 408 && wrapped)
			{
				alive = false;
				//killed = true;
				visible = false;
			}
		killable = flipped > 0;
	}
	else
	{
		y += 15;
	if (y > 600)
	{
	alive = false;
	}
	}
	leftshanghai.alive = alive && !killed && leftshanghai.alive;
	rightshanghai.alive = alive && !killed && rightshanghai.alive;
	}
	
	public override function bump(player:Player)
	{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * 4;
			}
			else
			{
				flipped = 30 * 7;
			}
		}
		else
		{
			flipped = 0;
		}
	}
}