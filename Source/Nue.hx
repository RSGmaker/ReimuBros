package;

/**
 * ...
 * @author RSGmaker
 */
class Nue extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	//public var started:Bool;
	public var timer:Int;
	public var rng:MersenneTwister;
	public var flipping:Bool;
	public var countdown:Int;
	public var rename:String;
	public var have:Bool;
	public var isChar:Bool;
	public var disguised:Bool;
	public var frames:Int;
	public var unlock:Int;
	//public var have:Bool;
	public var alternate:Bool;
	public function new() 
	{
		//super(main, "RedFairy");
		super("Nue");
		//this.charname = "RedFairy";
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		HP = 0;
		rename = "reimu";
		frames = 0;
		alternate = false;
		isChar = false;
		disguised = false;
	}
	
	public override function enrage()
	{
		//accel = 0.7;
		//mxspd = 6;
	}
	public override function update()
	{
		if (rng == null)
		{
			rng = new MersenneTwister();
			rng.seed = Math.floor(UID * 100000);
			if (rng.twist(rng.seed, 1, 100)[0] < 50)
			{
			unlock = rng.twist(rng.seed, 1, Player.characters.length)[0];
			
			rename = Player.characters[unlock];
			if (rng.twist(rng.seed, 1, 100)[0] < 30)
			{
				var A = game.AL.GetAnimation(rename+"ALT");
				if (A != null && A.length > 0)
				{
					rename = rename+"ALT";
					alternate = true;
				}
			}
			have = Main._this.savedata.data.unlock[unlock];
			if (!have && alternate)
			{
				have = Main._this.savedata.data.alts[unlock];
			}
			isChar = true;
			this.scaleX = 0.8;
			this.scaleY = 0.8;
			}
			else
			{
				isChar = false;
				if (rng.twist(rng.seed, 1, 100)[0] < 60)
				{
					rename = "Point";
				}
				else
				{
					rename = "1up";
				}
			}
			disguised = true;
		}
		frames++;
		var S = rename;
		if (isChar)
		{
		if (frames & 1 > 0 && !have)
		{
			//enraged = !enraged;
			S = S + "U";
		}
		if (have)
		{
			//enraged = true;
			S = S + "U";
		}
		}
		enraged = false;
		
		//y += 1;
		if (!killed)
		{
		var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
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
		var F = flipped;
		flipped = 0;
		updphysics();
		//updateanimation(rename);
		updateanimation(S);
		flipped = F;
		if (flipped > 0)
		{
			this.rotation = 90;
			/*if (Hspeed > 0)
			{
				this.rotationZ = 270;
			}
			else if (Hspeed<0)
			{
				this.rotationZ = 90;
			}
			else if (this.rotationZ == 0)
			{
				this.rotationZ = 180;
			}*/
		}
		else
		{
			this.rotation = 0;
		}
		
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
				D.Hspeed = Hspeed * 0.5;
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
					HP = 0;
					//Vspeed = -13;
				}
			}
			
		}
			if ((y > 408 && wrapped) || y>800)
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
		if (disguised)
		{
			rename = "nue";
			disguised = false;
			isChar = false;
			this.scaleX = 0.8;
			this.scaleY = 0.8;
		}
		else
		{
		if (HP > 0)
		{
			HP--;
		}
		else
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
			HP = 0;
		}
		}
		}
	}
	
}