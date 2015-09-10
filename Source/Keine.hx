package;

/**
 * ...
 * @author RSGmaker
 */
class Keine extends Enemy
{
	//slowed
	public var accel:Float;
	
	public var mxspd:Float;
	public var ex:Bool;
	public function new() 
	{
		super("Keine");
		accel = 0.15;
		deccel = 0.05;
		mxspd = 1.5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		ex = false;
		pointvalue = 300;
	}
	override public function attack():Bool 
	{
		if (!ex)
		{
			bump();
			invincibility = 20;
			Hspeed = 0;
			return false;
		}
		return true;
		//return ex;
		//return super.attack();
	}
	public override function increaserank()
	{
		accel += 0.02;
		mxspd += 0.25;
		pointvalue += 150;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
		}
		if (invincibility > 0)
		{
			invincibility--;
		}
		var MXS = mxspd;
		var acl = accel;
		var dir = Ldir;
		charname = "Keine";
		
		if (ex)
		{
			MXS += 2+rank;
			acl += 0.05;
			charname = charname + "ex";
		}
		if (!killed)
		{
		
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
		}
		else
		{
			dangerous = true;
			if (flipped == 0)
			{
				flipped = -1;
				ex = false;
				powerup();
			}
		}
		if (Hspeed < MXS && dir==1 && flipped < 1)
		{
			Hspeed += acl;
			if (Hspeed > MXS)
			{
				Hspeed = MXS;
			}
		}
		if (Hspeed > -MXS && dir==-1 && flipped < 1)
		{
			Hspeed -= acl;
			if (Hspeed < -MXS)
			{
				Hspeed = -MXS;
			}
		}
		updphysics();
		updateanimation("E"+charname);
		
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
	Ldir = dir;
	}
	public override function bump()
	{
		if (!ex)
		{
			Hspeed = mxspd+2+rank;
			if (Ldir > 0)
			{
				Hspeed = -Hspeed;
			}
		}
		else
		{
			Hspeed = accel * ( -Ldir);
		}
		if (flipped < 1)
		{
			if (!ex)
			{
				ex = true;
			}
			else
			{
			if (enraged)
			{
				flipped = 60 * 5;
			}
			else
			{
				flipped = 60 * 8;
			}
			}
		}
		else
		{
			flipped = -1;
		}
	}
}