package;

/**
 * ...
 * @author RSGmaker
 */
class Kogasa extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var surprisetime:Int;
	public var shottime:Int;
	//public var controller:Array<Bool>;
	
	
	public function new() 
	{
		//super(main, "RedFairy");
		super("kogasa");
		//this.charname = "RedFairy";
		accel = 1;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		surprisetime = 40;
		shottime = 9;
		mxspd += 4;
	}
	
	/*public override function enrage()
	{
		accel += 0.2;
		mxspd += 1;
		//accel = 0.7;
		//mxspd = 6;
	}*/
	
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
			/*var i = 0;
			while (i < rank)
			{
				accel += 0.1;
				mxspd += 0.5;
				pointvalue += 50;
				i++;
			}*/
			started = true;
		}
		/*accel = 0.5;
		deccel = 0.1;
		mxspd = 4;*/
		if (surprisetime > 0)
		{
			surprisetime--;
			if (shottime > 0 && game.Hoster)
			{
				shottime--;
				if (shottime <= 0)
				{
					var D:Dynamic = { };
					D.UID = UID;
					game.SendEvent("ChenDanmaku", D);
					shottime = 10;
				}
			}
			if (surprisetime <= 0)
			{
				mxspd -= 4;
			}
		}
		if (enraged)
		{
			//accel += 0.2;
			//mxspd += 2;
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