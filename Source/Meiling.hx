package;

/**
 * ...
 * @author RSGmaker
 */
class Meiling extends Enemy
{
	//slowed
	public var accel:Float;
	
	public var mxspd:Float;
	
	public var awake:Int;
	
	public var target:Player;
	
	public var rename:String;
	
	public var speedup:Bool;
	
	public function new() 
	{
		super("meiling");
		accel = 0.25;
		deccel = 0.05;
		mxspd = 2;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "meiling";
		scaleX = 0.7;
		scaleY = 0.7;
		pointvalue = 300;
	}
	
	override public function CustomEvent(data:Dynamic) 
	{
		super.CustomEvent(data);
		speedup = true;
	}
	
	public override function increaserank()
	{
			accel += 0.05;
			mxspd += 0.25;
			pointvalue += 100;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			awake = 150 + Math.floor(1800 * UID);
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
				rename = "meiling";
			}
		}
		else
		{
			dangerous = true;
		}
		if (flipped < 1)
		{
		if (target == null)
		{
			
			var L = game.GetPlayers();
			var i = 0;
			while (i < L.length)
			{
				var E = L[i];
				if (Math.abs(E.y - y) < 60)
				{
					if ((Ldir == -1 && E.x<x) || (Ldir==1 && E.x>x))
					{
						target = E;
						i = L.length;
					}
				}
				i++;
			}
			awake--;
			if (awake == 0 && target == null)
			{
				flipped = 60 * 20;
				awake = -1;
				rename = "meilingsleeping";
				Hspeed = 0;
			}
		}
		else if (target.alive && !target.killed && ground != null)
		{
			if (game.Hoster && Math.abs(target.y - y) < 60 && ((Ldir == -1 && target.x<x) || (Ldir==1 && target.x>x)))
			{
				//simulate double speed
				//x += Hspeed;
				//x += Hspeed;
				//speedup = true;
				var D:Dynamic = { };
				D.UID = UID;
				D.data = null;
				game.SendEvent("CustomEvent", D);
			}
			
		}
		if (speedup)
		{
			if (ground != null)
			{
				x += Hspeed;
				x += Hspeed;
			}
			else
			{
				speedup = false;
			}
		}
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
			rename = "meiling";
		}
	}
	
}