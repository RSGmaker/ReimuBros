package;

/**
 * ...
 * @author RSGmaker
 */
class Seija extends Enemy
{
	public var accel:Float;
	
	public var mxspd:Float;
	//public var started:Bool;
	public var timer:Int;
	public var rng:MersenneTwister;
	public var flipping:Bool;
	public var countdown:Int;
	
	public function new() 
	{
		super("seija");
		accel = 0.6;
		deccel = 0.1;
		mxspd = 6;
		Ldir = 1;
		killed = false;
		flipped = -1;
		started = false;
		pointvalue = 500;
		flipping = false;
		this.scaleX = 0.8;
		this.scaleY = 0.8;
		//this.addChild(darkness);
	}
	/*public override function enrage()
	{
		accel += 0.1;
		//mxspd += 6;
	}*/
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
			timer = (60) + rng.twist(seed, 1, 30 * 8)[0];
			countdown = 90;
		}
		/*if (enraged)
		{
		if (game.Hoster)
		{
			game.SendEvent("FLIP!", null);
		}
		}*/
		//y += 1;
		
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
			//enraged = !enraged;
			visuallyEnraged = !visuallyEnraged;
			if (countdown <= 0)
			{
				//SoundManager.Play("fireballspawn");
				if (game.Hoster && ground != null)
				{
					game.SendEvent("FLIP!", null);
				}
				timer = (60) + rng.twist(rng.seed, 1, 30 * 8)[0];
				flipping = false;
				countdown = 90;
			}
			Hspeed = 0;
		}
		else
		{
			//countdown = 60;
			//enraged = false;
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
		/*if (flipped>0)
		{
			scaleY = -1;
		}
		else
		{
			scaleY = 1;
		}*/
		
		if (ground != null)
		{
			//if (ground.bonked > -1000 && game.Hoster && game.myplayer == ground.bonkedby)
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				//if (game.ismyplayer(ground.bonkedby) && game.Hoster)
				if (game.myplayer == ground.bonkedby)
				{
				//Vspeed = -4;
				//flipped = 30 * 10;
				var D:Dynamic = { };
				D.UID = UID;
				D.x = x;
				D.y = y;
				D.Hspeed = Hspeed;
				D.Vspeed = -10;
				//game.SendEvent("Bump", this.UID);
				game.SendEvent("Bump", D);
				}
			}
			else
			{
				//if ((controller[1]) && Vspeed == 0)
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -4;
					//Vspeed = -13;
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
		//Vspeed = -4;
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