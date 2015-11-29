package;

/**
 * ...
 * @author RSGmaker
 */
class Sakuya extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rng:MersenneTwister;
	
	public var recharge:Int;
	
	public var timetofire:Int;
	
	public var shouldfire:Bool;
	
	public var rename:String;
	
	//public var HP:Int;
	
	public function new() 
	{
		super("sakuya");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		HP = 1;
		pointvalue = 300;
		rename = "sakuya";
		//rename = "okuu";
	}
	override public function CustomEvent(data:Dynamic) 
	{
		shouldfire = true;
		recharge = 100 + rng.quick(400);
		timetofire = 45;
		//super.CustomEvent(data);
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
			pointvalue += 100;
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
			
			rng.seed += rng.twist(rng.seed, 1, 700)[0];
			//recharge = 200 + rng.quick(500);
			recharge = 60 + rng.quick(90);
			//timetofire = 250 + (rng.seed % 700);
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
		doingability = false;
		if (flipped <= 0)
		{
			if (shouldfire)
			{
			timetofire--;
			if (timetofire < 45)
			{
				///Hspeed = 0;
				//visuallyEnraged = !visuallyEnraged;
				doingability = true;
				if (timetofire < 1)
				{
					/*if (game.Hoster)
					{
						var D:Dynamic = { };
						D.x = x;
						D.y = y-30;
						D.Vspeed = 0;
						D.Hspeed = Ldir * 2;
						game.SendEvent("unyucannon", D);
					}*/
					var spd = 3;
					var O = new Bullet();
					O.x = x;
					O.y = y;
					O.Vspeed = -spd;
					O.ChangeAnimation("knifeE");
					O.image.image_speed = 0;
					game.AddObject(O);
					
					O = new Bullet();
					O.x = x-32;
					O.y = y;
					O.Vspeed = -spd;
					O.ChangeAnimation("knifeE");
					O.image.image_speed = 0;
					game.AddObject(O);
					
					O = new Bullet();
					O.x = x+32;
					O.y = y;
					O.Vspeed = -spd;
					O.ChangeAnimation("knifeE");
					O.image.image_speed = 0;
					game.AddObject(O);
					
					shouldfire = false;
					//Ldir = -Ldir;
					//rng.seed += rng.twist(rng.seed, 1, 700)[0];
					//timetofire = 250 + (rng.seed % 700);
				}
			}
			else
			{
				visuallyEnraged = false;
			}
			}
			else
			{
				visuallyEnraged = false;
				recharge--;
				if (recharge < 1)
				{
				var P = game.myplayer;
				var X = Math.abs(x - P.x);
				if (P.ground != null && P.y < y - 64 && X < 200)
				{
					SendCustomEvent(null);
				}
				}
			}
		}
		/*if (HP > 1)
		{
			rename = "utsuho";
		}
		else
		{
			rename = "okuu";
		}*/
		updphysics();
		//ChangeAnimation(rename);
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
	public override function bump()
	{
		recharge = 100 + rng.quick(400);
		timetofire = 45;
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