package;

/**
 * ...
 * @author RSGmaker
 */
class Hecatia extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public function new() 
	{
		super("Hecatia");
		HP = 3;
		accel = 0.5;
		deccel = 0.1;
		mxspd = 6;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "hecatia";
		pointvalue = 800;
	}
	
	override public function attack():Bool 
	{
		HP--;
		if (HP > 0)
		{
			invincibility = 10;
		}
		return HP < 1;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 200;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
		}
		if (!killed)
		{
			
		if (HP == 3)
		{
			rename = "hecatia";
		}
		else if (HP == 2)
		{
			rename = "hecatiam";
		}
		else if (HP < 2)
		{
			rename = "hecatiae";
		}
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
		this.scaleX = 0.8;
		this.scaleY = 0.8;
		updphysics();
		updateanimation(rename);
		
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
	}
	public override function bump()
	{
		HP--;
		if (HP < 1)
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
	
}