package;

/**
 * ...
 * @author RSGmaker
 */
class Hina extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public var spinning:Int;
	
	public var rng:MersenneTwister;
	
	public var timetospin:Int;
	
	//0=normal
	//1=b+name
	//2=b+name+F
	//3=name+F
	public var spinstate:Int;
	
	public var minimum:Int = 50;
	
	public var variation:Int = 270;
	
	public var maxspin:Int = 120;
	
	
	public function new() 
	{
		super("Hina");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 3;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "hina";
		spinstate = 0;
		pointvalue = 300;
		this.scaleX = 0.8;
		this.scaleY = 0.8;
	}
	
	override public function attack():Bool 
	{
		return spinning<1;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.25;
			pointvalue += 100;
			minimum = Std.int(Math.max(30, minimum - 5));
			variation = Std.int(Math.max(150, variation - 15));
			maxspin = Std.int(Math.min(180, maxspin + 5));
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			rng = new MersenneTwister();
			var seed:UInt = Math.floor((UID * 100000)+spawns);
			rng.twist(seed, 1, 100000);
			
			rng.seed += rng.twist(rng.seed, 1, 600)[0];
			
			timetospin = minimum + rng.quick(variation);
			//timetospin = 200 + (rng.seed % 600);
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
		rename = "hina";
		doingability = false;
		if (spinning > 0 && flipped<1)
		{
			if (spinning > 1 || spinstate == 0)
			{
				spinning--;
			}
			if (spinstate == 1)
			{
				rename = "bhina";
			}
			if (spinstate == 2)
			{
				rename = "bhinaF";
			}
			if (spinstate == 3)
			{
				rename = "hinaF";
			}
			if (spinning & 1 == 1)
			{
				spinstate++;
			}
			if (spinstate > 3)
			{
				spinstate = 0;
			}
		}
		
		if (timetospin > 0 && spinning<1 && flipped<1)
		{
			timetospin--;
			if (timetospin <= 0)
			{
				spinning = maxspin;
				spinstate = 0;
				timetospin = minimum + rng.quick(variation);
			}
			else if (timetospin < 15)
			{
				//visuallyEnraged = !visuallyEnraged;
				doingability = true;
			}
			else
			{
				visuallyEnraged = false;
			}
		}
		else
		{
			visuallyEnraged = false;
		}
		
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
		if (spinning > 0)
		{
			return;
		}
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