package;

/**
 * ...
 * @author RSGmaker
 */
class Cirno extends Enemy
{
	//slowed
	public var accel:Float;
	
	public var mxspd:Float;
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
		super("Cirno");
		accel = 0.25;
		deccel = 0.05;
		mxspd = 2;
		Ldir = 1;
		killed = false;
		flipped = -1;
		selfdestruct = false;
		reward = false;
		pointvalue = 150;
		mxtimer = 180;
		respawn = false;
		rename = "ECirno";
		needtokill = false;
	}
	
	public override function enrage()
	{
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
		if (!killed)
		{
		if (rng == null)
		{
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			timer = (120) + rng.twist(seed, 1, 60 * 30)[0];
			if (game.RoundType == GameView.TypeofRound.FireCirno || rng.twist(rng.seed, 1, 100)[0] > 90)
			{
				flaming = true;
				rename = "firecirno";
				mxtimer = 240;
			}
			else if (game.RoundType == GameView.TypeofRound.ElectricCirno || (game.level>30 && rng.twist(rng.seed, 1, 100)[0] > 97))
			{
				electric = true;
				flaming = true;
				rename = "electriccirno";
				mxtimer = 360;
			}
			countdown = mxtimer;
		}
		if (ground != null && !flaming && !electric)
		{
			 if (ground.type == "Block") 
			 {
				var D:Dynamic = ground;
				if (D.dangerous || D.charred)
				{
					killed = true;
				}
			 }
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
			visuallyEnraged = !visuallyEnraged;
			if (countdown <= 0)
			{
			if (game.Hoster && ground != null && ((!ground.icy && !flaming) || (!ground.dangerous && flaming && y<500)))
			{
				var D:Dynamic = { };
				D.UID = UID;
				D.y = ground.y;
				targetplatform(D);
				game.SendEvent("Cirnobomb", D);
			}
			}
			Hspeed = 0;
		}
		else
		{
			countdown = 180;
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
				killed = true;
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
		else
		{
			scaleX -= 0.1;
			scaleY -= 0.1;
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
		killed = true;
		if (ground != null && ground.bonkedby != null && ground.bonkedby.type=="Player")
		{
			var D:Dynamic = ground.bonkedby;
			killedby = D;
		}
	}
	
}