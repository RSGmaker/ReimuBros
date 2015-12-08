package;

/**
 * ...
 * @author RSGmaker
 */
class Keine extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	public var ex:Bool;
	public function new() 
	{
		super("Keine");
		accel = 0.3;
		deccel = 0.1;
		mxspd = 3;
		Ldir = 1;
		killed = false;
		flipped = -1;
		ex = false;
		pointvalue = 300;
	}
	override public function attack(player:Player):Bool
	{
		if (!ex)
		{
			bump(player);
			invincibility = 10;
			Hspeed = 0;
			return false;
		}
		return true;
		//return ex;
		//return super.attack();
	}
	public override function increaserank()
	{
		fallaccel += 0.1;
		accel += 0.04;
		mxspd += 0.5;
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
			MXS += 4+rank;
			acl += 0.1;
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
	Ldir = dir;
	}
	public override function bump(player:Player)
	{
		if (!ex)
		{
			Hspeed = mxspd+4+rank;
			if (Ldir > 0)
			{
				Hspeed = -Hspeed;
			}
		}
		else
		{
			//Hspeed = accel * ( -Ldir);
			//Hspeed *= 0.5;
			var M = 5;
			Hspeed = Math.min(Math.max(-M,Hspeed * 0.5),M);
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
				flipped = 30 * 5;
			}
			else
			{
				flipped = 30 * 8;
			}
			}
		}
		else
		{
			flipped = -1;
		}
	}
}