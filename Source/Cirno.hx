package;

/**
 * ...
 * @author RSGmaker
 */
class Cirno extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	//public var controller:Array<Bool>;
	//how long until initiating countdown
	public var timer:Int;
	public var rng:MersenneTwister;
	//whether or not platform is suitable for freezing
	public var selfdestruct:Bool;
	//countdown to platform freeze
	public var countdown:Int;
	public var flaming:Bool;
	public var electric:Bool;
	public var rename:String;
	public var mxtimer:Int;
	public var killedby:Player;
	
	public function new() 
	{
		//super(main, "RedFairy");
		super("Cirno");
		//this.charname = "RedFairy";
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		selfdestruct = false;
		reward = false;
		pointvalue = 150;
		mxtimer = 90;
		//countdown = 90;
		respawn = false;
		rename = "ECirno";
		needtokill = false;
	}
	
	public override function enrage()
	{
		//accel = 0.7;
		//mxspd = 6;
		enraged = false;
	}
	public function targetplatform(D:Dynamic) {
		var min = ground.x;
		var max = ground.x;
		var T;
		while ((T = game.CollisionDetectPoint(min - 16, ground.y)) != null)
		{
			min = T.x;
		}
		while ((T = game.CollisionDetectPoint(max + 34, ground.y)) != null)
		{
			max = T.x;
		}
		D.minx = min;
		D.maxx = max;
	}
	public override function update()
	{
		//y += 1;
		if (!killed)
		{
		if (rng == null)
		{
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			timer = (60) + rng.twist(seed, 1, 30 * 30)[0];
			if (game.RoundType == GameView.TypeofRound.FireCirno || rng.twist(rng.seed, 1, 100)[0] > 90)
			{
				flaming = true;
				rename = "firecirno";
				mxtimer = 120;
			}//ElectricCirno
			else if (game.RoundType == GameView.TypeofRound.ElectricCirno || (game.level>30 && rng.twist(rng.seed, 1, 100)[0] > 97))
			{
				//flaming = true;
				electric = true;
				flaming = true;
				rename = "electriccirno";
				mxtimer = 180;
			}
			countdown = mxtimer;
		}
		if (timer <= 0)
		{
			if (ground != null && ((!ground.icy && !flaming) || (!ground.dangerous && flaming && y<500)) && x>0 && x<780)
			{
				selfdestruct = true;
			}
			else
			{
				selfdestruct = false;
			}
		}
		else
		{
			timer -= 1;
		}
		if (selfdestruct)
		{
			countdown -= 1;
			//enraged = !enraged;
			visuallyEnraged = !visuallyEnraged;
			if (countdown <= 0)
			{
				//SoundManager.Play("fireballspawn");
			if (game.Hoster && ground != null && ((!ground.icy && !flaming) || (!ground.dangerous && flaming && y<500)))
			{
				var D:Dynamic = { };
				D.UID = UID;
				D.y = ground.y;
				targetplatform(D);
				game.SendEvent("Cirnobomb", D);
				//alive = false;
			}
			}
			Hspeed = 0;
		}
		else
		{
			countdown = 90;
			//enraged = false;
			visuallyEnraged = false;
		}
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
		if (Hspeed < mxspd && dir==1 && flipped < 1 && !selfdestruct)
		{
			Hspeed += accel;
			if (Hspeed > mxspd)
			{
				Hspeed = mxspd;
			}
		}
		if (Hspeed > -mxspd && dir==-1 && flipped < 1 && !selfdestruct)
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
				killed = true;
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
		else
		{
			scaleX -= 0.2;
			scaleY -= 0.2;
			if (scaleX <= 0)
			{
				if (alive && killedby != null)
				{
					killedby.score += pointvalue;
				}
				alive = false;
			}
		}
	}
	public override function bump()
	{
		//alive = false;
		killed = true;
		if (ground != null && ground.bonkedby != null && ground.bonkedby.type=="Player")
		{
			var D:Dynamic = ground.bonkedby;
			//D.score += pointvalue;
			killedby = D;
		}
	}
	
}