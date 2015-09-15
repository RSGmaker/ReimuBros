package;

/**
 * ...
 * @author RSGmaker
 */
class Marisa extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rng:MersenneTwister;
	
	public var timetofire:Int;
	
	public var canfire:Bool;
	
	//public var HP:Int;
	
	public function new() 
	{
		super("marisa");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		HP = 1;
		pointvalue = 300;
	}
	override public function attack():Bool 
	{
		HP--;
		if (HP > 0)
		{
			invincibility = 10;
		}
		return HP < 1;
	}
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 150;
	}
	public override function update()
	{
		if (invincibility > 0)
		{
			invincibility--;
		}
		if (!started)
		{
			started = true;
			rng = new MersenneTwister();
			var seed:UInt = Math.floor((UID * 100000)+spawns);
			rng.twist(seed, 1, 100000);
			
			rng.seed += rng.twist(rng.seed, 1, 500)[0];
			timetofire = 200 + (rng.seed % 500);
			var items:Array<String> = ["MiniHakkero", "Camera","SpellCard"];
			var D:Dynamic = { };
					D.UID = UID;
					//D.item = "MiniHakkero";
					D.item = items[rng.quick(items.length)];
			//canfire = (D.item == "MiniHakkero");
			canfire = true;
			game.SendEvent("AttachItem", D);
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
		if (flipped <= 0)
		{
			timetofire--;
			if (timetofire < 140 && canfire)
			{
				Hspeed = 0;
				visuallyEnraged = !visuallyEnraged;
				if (timetofire < 1)
				{
					if (game.Hoster)
					{
						var D:Dynamic = { };
						/*D.x = x;
						D.y = y-30;
						D.Vspeed = 0;
						D.Hspeed = Ldir * 2;
						game.SendEvent("unyucannon", D);*/
						var D:Dynamic = { };
						D.x = x;
						if (Ldir < 0)
						{
							D.x -= 800;
						}
						D.y = y+32;
						//D.user = P.UID;
						D.antiplayer = true;
						D.antienemy = false;
						game.SendEvent("LaserBeam",D);
					}
					Ldir = -Ldir;
					rng.seed += rng.twist(rng.seed, 1, 500)[0];
					timetofire = 200 + (rng.seed % 500);
				}
			}
			else
			{
				visuallyEnraged = false;
			}
		}
		updphysics();
		updateanimation("marisa");
		
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
	public override function bump()
	{
		rng.seed += rng.twist(rng.seed, 1, 500)[0];
		timetofire = 200 + (rng.seed % 500);
		HP--;
		if (HP < 1)
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
	
}