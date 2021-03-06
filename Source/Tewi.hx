package;

/**
 * ...
 * @author RSGmaker
 */
class Tewi extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	public var timer:Int;
	public var rng:MersenneTwister;
	public var mntime:Int;
	
	public function new() 
	{
		super("tewi");
		accel = 0.4;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		pointvalue = 200;
		mntime = 0;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 100;
			mntime += 30;
			if (mntime > 100)
			{
				mntime = 100;
			}
	}
	public override function update()
	{
		
		if (!started)
		{
			started = true;
		}
		if (rng == null)
		{
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			timer = (45) + rng.twist(seed, 1, 7 * 30)[0];
			timer -= mntime;
		}
		if (game.Hoster && flipped <= 0)
		{
			if (timer > 0)
			{
				timer--;
			}
			else
			{
				timer = (45) + rng.twist(rng.seed, 1, 7 * 30)[0];
				timer -= mntime;
				var D:Dynamic = { };
				D.UID = UID;
				game.SendEvent("Hammerthrow", D);
			}
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