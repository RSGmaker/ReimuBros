package;

/**
 * ...
 * @author RSGmaker
 */
class Seija extends Enemy
{
	public var accel:Float;
	
	public var mxspd:Float;
	public var timer:Int;
	public var rng:MersenneTwister;
	public var flipping:Bool;
	public var countdown:Int;
	
	public function new() 
	{
		super("seija");
		accel = 0.3;
		deccel = 0.05;
		mxspd = 3;
		Ldir = 1;
		killed = false;
		flipped = -1;
		started = false;
		pointvalue = 500;
		flipping = false;
		this.scaleX = 0.8;
		this.scaleY = 0.8;
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
			timer = (120) + rng.twist(seed, 1, 60 * 8)[0];
			countdown = 180;
		}
		
		if (!killed)
		{
			if (flipped < 1)
			{
			if (timer <= 0)
		{
			if (ground != null)
			{
				flipping = true;
			}
			else
			{
				flipping = false;
			}
		}
		else
		{
			timer -= 1;
		}
		if (flipping)
		{
			countdown -= 1;
			visuallyEnraged = !visuallyEnraged;
			if (countdown <= 0)
			{
				if (game.Hoster && ground != null)
				{
					game.SendEvent("FLIP!", null);
				}
				timer = (120) + rng.twist(rng.seed, 1, 60 * 8)[0];
				flipping = false;
				countdown = 180;
			}
			Hspeed = 0;
		}
		else
		{
			visuallyEnraged = false;
		}
			}
			else
			{
				flipping = false;
			}
		var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
			if (flipped == 0)
			{
				flipped = -1;
				if (!enraged)
				{
					rank++;
				}
			}
		}
		else
		{
			dangerous = true;
		}
		if (!flipping)
		{
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
		}
		var F = flipped;
		var LX = x;
		var LY = y;
		flipped = 0;
		updphysics();
		updateanimation();
		flipped = F;
		if (flipped > 0)
		{
			this.rotation = 90;
		}
		else
		{
			this.rotation = 0;
		}
		
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
		y += 7.5;
	if (y > 600)
	{
	alive = false;
	}
	}
	if (!alive && game.myplayer == bonkedby)
	{
		game.unlockcharacter("seija");
	}
	}
	public override function bump()
	{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 60 * 4;
			}
			else
			{
				flipped = 60 * 7;
			}
		}
		else
		{
			flipped = 0;
		}
	}
}