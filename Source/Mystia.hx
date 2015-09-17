package;
//import org.eccesignum.utilities.MersenneTwister;
//import MersenneTwister;
/**
 * ...
 * @author RSGmaker
 */
class Mystia extends Enemy
{
	public var accel:Float;
	
	public var mxspd:Float;
	public var frames:Int;
	
	public var rng:MersenneTwister;
	public var mntime:Int;
	public var rename:String;
	public function new() 
	{
		super("Mystia");
		accel = 0.8;
		deccel = 0.1;
		mxspd = 6;
		Ldir = 1;
		killed = false;
		flipped = -1;
		frames = 0;
		image.image_speed = 0.4;
		rng = null;
		//mntime = 1;
		mntime = 45;
		pointvalue = 200;
		rename = "EMystia";
		subtype = "mystia";
	}
	
	public override function increaserank()
	{
			accel += 0.15;
			mxspd += 1;
			if (mntime < 80)
			{
				mntime += 5;
			}
			pointvalue += 100;
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
			rng.twist(seed, 1, 100000);
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
	
		updphysics();
		if (ground == null || Vspeed<0)
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
			frames = 0;
			
		}
		else
		{
			image.image_index = -0.001;
			if (flipped<=0)
			{
				if (frames == 0)
				{
					rng.seed += rng.twist(rng.seed, 1, 30)[0];
					//frames = mntime + (rng.seed % 30);
					frames = mntime;
				}
				Hspeed = 0;
				frames += 1;
				if (frames > 90)
				{
					rng.seed += rng.twist(rng.seed, 1, 800)[0];
					//Vspeed = -4 - ((rng.seed % 800)*0.01);
					//Vspeed = -7;
					Vspeed = -7;
				}
			}
			
		}
		animate();
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
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * 5;
			}
			else
			{
				flipped = 30 * 7;
			}
		}
		else
		{
			flipped = -1;
		}
	}
}