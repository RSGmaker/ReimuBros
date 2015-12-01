package;

/**
 * ...
 * @author RSGmaker
 */
class Satori extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	public var rename:String;
	
	public var target:Player;
	
	public var wait:Int;
	
	public function new() 
	{
		super("satori");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "satori";
		target = null;
		scaleX = 0.7;
		scaleY = 0.7;
		pointvalue = 1000;
	}
	
	override public function attack(player:Player):Bool
	{
		if (rename == "koishi")
		{
			alpha = 0.2;
			wait = 0;
		}
		return alpha >= 1;
	}
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 200;
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		Hspeed = data.Hspeed;
		Vspeed = data.Vspeed;
		alpha = data.alpha;
		x = data.x;
		y = data.y;
	}
	public override function update()
	{
		if (!started)
		{
			if (UID < 0.5)
			{
				rename = "koishi";
			}
			else
			{
				//fallaccel += 0.3;
			}
			started = true;
			var A = game.GetPlayers();
			target = A[Std.int(99999 * UID) % A.length];
		}
		if (!target.alive)
		{
			var A = game.GetPlayers();
			target = A[Std.int((99993 * UID)) % A.length];
		}
		else if (flipped<=0)
		{
			if (rename == "satori")
			{
				/*if (target.controller[2] && Ldir >= 0)
				{
					Ldir = -1;
				}
				else if (target.controller[3] && Ldir <= 0)
				{
					Ldir = 1;
				}*/
				if (game.myplayer.controller[0] && ground != null && Vspeed == 0)
				{
					//Vspeed = -7;
					//Vspeed = -10;
					Vspeed = -5;
				}
			}
			if (rename == "koishi")
			{
				/*if (target.controller[3] && Ldir >= 0)
				{
					Ldir = -1;
					alpha = 1;
				}
				else if (target.controller[2] && Ldir <= 0)
				{
					Ldir = 1;
					alpha = 1;
				}
				if (target.controller[1] && ground != null && Vspeed == 0)
				{
					//turn invisible and invincible
					alpha = 0.2;
					wait = 0;
				}*/
			}
		}
		if (!killed)
		{
			/*if (target == game.myplayer && game.ControlEvent)
			{
			var D:Dynamic = { };
			D.Hspeed = Hspeed;
			D.Vspeed = Vspeed;
			D.alpha = alpha;
			D.x = x;
			D.y = y;
			SendCustomEvent(D);
			}*/
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
		if (alpha < 1)
		{
			if (wait < 90)
			{
				wait++;
			}
			else
			{
				alpha = 1;
			}
		}
		if (alpha == 1)
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
		var lground = ground;
		updphysics();
		updateanimation(rename);
		if (lground == null && ground != null && rename == "koishi"/* && y < 300*/)
		{
			Ldir = -Ldir;
		}
		
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
	if (!alive && game.myplayer == bonkedby)
	{
		game.unlockcharacter("satori");
	}
	}
	public override function bump(player:Player)
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