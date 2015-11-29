package;

/**
 * ...
 * @author RSGmaker
 */
class Sekibanki extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public function new() 
	{
		super("sekibanki");
		HP = 2;
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "sekibanki";
		expressive = false;
		pointvalue = 400;
	}
	
	override public function attack():Bool 
	{
		HP--;
		if (HP > 0)
		{
			invincibility = 10;
		}
		return true;
		//return HP < 1;
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
			
		if (HP == 2)
		{
			rename = "sekibanki";
		}
		else
		{
			rename = "sekibankinohead";
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
		this.scaleX = 0.6;
		this.scaleY = 0.6;
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
				HP = 2;
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
	public function drophead()
	{
		var O = new Bullet();
		O.x = x;
		O.y = y;
		O.scaleX = scaleX;
		O.scaleY = O.scaleX;
		//O.Hspeed = (spd * Ldir);
		O.Hspeed = 0;
		O.Ldir = Ldir;
		O.Vspeed = -3;
		//O.gravY = 0.13;
		O.gravY = 0.6;
		//O.Vspeed = -spd;
		O.ChangeAnimation("sekibankihead");
		O.image.image_speed = 1;
		O.spin = true;
		O.spinspeed = 8.0 * Ldir;
		game.AddObject(O);
	}
	public override function bump()
	{
		if (HP == 2)
		{
			drophead();
		}
		HP--;
		if (HP < 1 || true)
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