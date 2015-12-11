package;

/**
 * ...
 * @author RSGmaker
 */
class Wriggle extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public var recovery:Int = 6;
	public var recharge:Int = 0;
	public var maxrecharge:Int = 210;
	
	public function new() 
	{
		super("wriggle");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5.5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		pointvalue = 300;
		rename = "wriggle";
		this.scaleX = 0.7;
		this.scaleY = 0.7;
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		if (data.type == "kick")
		{
			x = data.x;
			y = data.y;
			Ldir = data.Ldir;
			Vspeed = -5;
			Hspeed = mxspd * 3 * Ldir;
			//rotation = Ldir * -60;
			rotateentity(Ldir * -60);
			recharge = maxrecharge;
			rename = CharHelper.changednafeature(CharHelper.getCharPreset("wriggle"),"Eyes","4");
		}
	}
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 100;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			//UID = UID * 0.09;
			//UID = UID * 0.7;
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
		/*if (ground != null && flipped<=0)
		{
			hopdelay--;
			if (hopdelay <= 0)
			{
				hopdelay = maxhopdelay;
				Vspeed = -4.5;
				Hspeed = mxspd * Ldir;
			}
			else if (Vspeed>=0)
			{
				Hspeed *= 0.85;
			}
		}*/
		
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
		recharge--;
		if (ground != null)
		{
			if (Vspeed >= 0)
			{
				if (rotation != 0)
				{
					rotation = 0;
					Hspeed *= 0.5;
				}
				rename = "wriggle";
			}
		if (recharge <= 0)
		{
			var P = game.myplayer;
			var Y = Math.abs(y - P.y);
			var X = Math.abs(x - P.x);
			if ((Ldir > 0 && P.x > x && x<700 && x>-10) || (Ldir < 0 && P.x < x && x>80 && x<770))
			{
				if (P.y < y+32 && Y < 64 && X < 200)
				{
					var D:Dynamic = { };
					D.type = "kick";
					D.x = x;
					D.y = y;
					D.Ldir = Ldir;
					SendCustomEvent(D);
				}
			}
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