package;

/**
 * ...
 * @author RSGmaker
 */
class Nitori extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	public var rename:String;
	public function new() 
	{
		super("nitori");
		charname = "Nitori";
		accel = 0.4;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		respawn = false;
		pointvalue = 1200;
		needtokill = false;
		reward = true;
		rewarditem = "Mini1up";
		alpha = 0.12;
		rename = "nitori";
	}
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 500;
	}
	override public function update():Void 
	{
		this.scaleX = 0.6;
		this.scaleY = 0.6;
		
	if (!started)
		{
			started = true;
			if (UID < 0.2)
			{
				rename = "sunny_milk";
				pointvalue += 500;
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
			//dangerous = true;
			dangerous = false;
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
		/*if (ground != null && Vspeed == 0 && flipped <= 0)
		{
			if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1), y - (192-96)) == null)
			{
				if (Hspeed > 0)
				{
					if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1) + 96, y - (192 - 96)) != null)
					{
						Vspeed = -15;
					}
				}
				if (Hspeed < 0)
				{
					if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1) - 96, y - (192 - 96)) != null)
					{
						Vspeed = -15;
					}
				}
			}
		}*/
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
				//killed = true;
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
	if (!alive && game.myplayer == bonkedby)
	{
		game.unlockcharacter("nitori");
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