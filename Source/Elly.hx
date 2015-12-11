package;

/**
 * ...
 * @author RSGmaker
 */
class Elly extends Enemy
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
		super("elly");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		HP = 1;
		pointvalue = 500;
		rename = "elly";
		//rename = "okuu";
	}
	override public function CustomEvent(data:Dynamic) 
	{
		if (data.type == "charge")
		{
			shouldfire = true;
			//recharge = 100 + rng.quick(400);
			recharge = 60 + rng.quick(270);
			timetofire = 45;
		}
		if (data.type == "attack")
		{
			var spd = 8;
			var O = new Bullet();
			x = data.x;
			y = data.y;
			O.x = x;
			O.y = y+5;
			O.scaleX = 0.8;
			O.scaleY = O.scaleX;
			O.Hspeed = (spd * Ldir);
			//O.Vspeed = -4.5;
			//O.gravY = 0.13;
			//O.gravY = 0.12;
			//O.Vspeed = -spd;
			O.ChangeAnimation("blockE");
			O.image.image_speed = 1;
			//O.spin = true;
			//O.spinspeed = 20.0 * Ldir;
			game.AddObject(O);
			/*x = data.x;
			y = data.y;
			Ldir = data.Ldir;
			var D:Dynamic = { };
			D.x = -20;
			if (Ldir < 0)
			{
				//D.x -= 800;
			}
			///D.y = 32;
			D.x = x - 20;
			D.y = y + 32;
			if (Ldir < 0)
			{
				D.x -= 800;
			}
			//D.user = P.UID;
			D.antiplayer = true;
			D.antienemy = false;
			D.color = 0xFFFFFF;
			//D.user = UID;
			if (game.Hoster)
			{
				game.SendEvent("LaserBeam", D);
			}
			if (Ldir > 0)
			{
				x = 770;
			}
			if (Ldir < 0)
			{
				x = 20;
			}*/
				
			shouldfire = false;
		}
		//super.CustomEvent(data);
	}
	override public function attack(player:Player):Bool
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
			//recharge = 60 + rng.quick(90);
			recharge = 45 + rng.quick(60);
			//timetofire = 250 + (rng.seed % 700);
			
			/*var D:Dynamic = { };
			D.UID = UID;
			D.item = "Roukanken";
			if (game.Hoster && UID<0.5)
			{
				game.SendEvent("AttachItem", D);
			}*/
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
		enraged = false;
		doingability = false;
		if (flipped <= 0)
		{
			if (shouldfire && ground != null && game.Hoster && ground.type == "Block" && ground.solid && ground.y<500)
			{
			timetofire--;
			if (timetofire < 25)
			{
				Hspeed = 0;
				doingability = true;
				//visuallyEnraged = !visuallyEnraged;
				if (timetofire < 1)
				{
					var D:Dynamic = { };
					D.type = "attack";
					D.x = x;
					D.y = y;
					D.Ldir = Ldir;
					D.G = ground.UID;
					SendCustomEvent(D);
					D = { };
					D.UID = ground.UID;
					D.Destroy = 300;
					game.SendEvent("DestroyBlock", D);
					
				}
			}
			else
			{
				visuallyEnraged = false;
			}
			}
			else
			{
				
				recharge--;
				if (recharge < 45)
				{
					//visuallyEnraged = !visuallyEnraged;
					//doingability = true;
				}
				else
				{
					visuallyEnraged = false;
				}
				if (recharge < 1 && ground != null)
				{
				var P = game.myplayer;
				var Y = Math.abs(y - P.y);
				//if (P.ground != null && P.y < y - 64 && X < 200)
				//if ((Ldir > 0 && P.x > x && x<100) || (Ldir < 0 && P.x < x && x>680))
				//if ((Ldir > 0 && P.x > x && x<300 && x>0) || (Ldir < 0 && P.x < x && x>480 && x<770))
				if ((Ldir > 0 && P.x > x && x<700 && x>-10) || (Ldir < 0 && P.x < x && x>80 && x<770))
				{
				if (P.y < y+32 && Y < 64)
				{
					var D:Dynamic = { };
					D.type = "charge";
					SendCustomEvent(D);
				}
				}
				}
			}
		}
		/*if (HP > 1)
		{
			rename = "youmumyon";
		}
		else
		{
			rename = "youmu";
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
	if (!alive && game.myplayer == bonkedby)
	{
		game.unlockcharacter("elly");
	}
	}
	public override function bump(player:Player)
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