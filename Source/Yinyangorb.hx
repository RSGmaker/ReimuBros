package;

/**
 * ...
 * @author RSGmaker
 */
class Yinyangorb extends Enemy
{
	//slowed
	public var accel:Float;
	
	public var mxspd:Float;
	public function new() 
	{
		super("yinyangorb");
		accel = 0.2;
		deccel = 0.05;
		mxspd = 2.5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		pointvalue = 100;
		fallaccel *= 0.25;
		image.image_speed = 0.5;
		needtokill = false;
		reward = false;
	}
	public override function increaserank()
	{
			pointvalue += 50;
	}
	override public function update():Void 
	{
		this.scaleX = 0.7;
		this.scaleY = 0.7;
		
	if (!started)
		{
			started = true;
		}
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
		if (ground != null && Vspeed == 0 && flipped <= 0)
		{
			Vspeed = -3.5;
		}
		updphysics();
		updateanimation();
		animate();
		
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
				D.Vspeed = -5;
				game.SendEvent("Bump", D);
				}
			}
			else
			{
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -2;
				}
			}
			
		}
			if (y > 408 && wrapped)
			{
				alive = false;
				killed = true;
				visible = false;
			}
		killable = flipped > 0;
	}
	else
	{
		y += 7.5;
	if (y > 600)
	{
	alive = false;
	}
	}
	}
	
	public override function bump()
	{
		alive = false;
		killed = true;
		if (ground != null && ground.bonkedby != null && ground.bonkedby.type=="Player")
		{
			var D:Dynamic = ground.bonkedby;
			D.score += pointvalue;
		}
	}
	
}