package;

/**
 * ...
 * @author RSGmaker
 */
class Satori extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	//public var controller:Array<Bool>;
	public var rename:String;
	
	public var target:Player;
	//public var frame:Int;
	
	public var wait:Int;
	
	public function new() 
	{
		//super(main, "RedFairy");
		super("satori");
		//this.charname = "RedFairy";
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
	}
	
	/*public override function enrage()
	{
		accel += 0.2;
		mxspd += 1;
		//accel = 0.7;
		//mxspd = 6;
	}*/
	override public function attack():Bool 
	{
		return alpha >= 1;
		//return super.attack();
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
			/*var i = 0;
			while (i < rank)
			{
				accel += 0.1;
				mxspd += 0.5;
				pointvalue += 50;
				i++;
			}*/
			if (UID < 0.5)
			{
				rename = "koishi";
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
				if (target.controller[2] && Ldir >= 0)
				{
					Ldir = -1;
				}
				else if (target.controller[3] && Ldir <= 0)
				{
					Ldir = 1;
				}
				if (target.controller[0] && ground != null && Vspeed == 0)
				{
					Vspeed = -7;
				}
			}
			if (rename == "koishi")
			{
				if (target.controller[3] && Ldir >= 0)
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
				}
			}
		}
		/*accel = 0.5;
		deccel = 0.1;
		mxspd = 4;*/
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
		//updphysics();
		//updateanimation();
		updphysics();
		updateanimation(rename);
		
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