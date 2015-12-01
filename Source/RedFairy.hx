package;

/**
 * ...
 * @author RSGmaker
 */
class RedFairy extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public var recovery:Int=4;
	
	public function new() 
	{
		super("RedFairy");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "red_fairy";
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 50;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			//UID = UID * 0.09;
			UID = UID * 0.7;
			if (UID < 0.4)
			{
				if (UID < 0.1)
				{
					if (UID < 0.01/* && spawns<1*/)
					{
						rename = "gold_fairy";
						recovery -= 1;
						accel += 0.2;
						mxspd += 1;
						pointvalue += 200;
					}
					else
					{
						rename = "green_fairy";
						recovery -= 1;
						pointvalue += 100;
					}
				}
				else
				{
					rename = "blue_fairy";
					accel += 0.1;
					mxspd += 0.5;
					pointvalue += 50;
					recovery += 1;
				}
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
	public override function bump(player:Player)
	{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * recovery;
			}
			else
			{
				flipped = 30 * (recovery+2);
			}
		}
		else
		{
			flipped = 0;
		}
	}
	
}