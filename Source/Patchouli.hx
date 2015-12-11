package;

/**
 * ...
 * @author RSGmaker
 */
class Patchouli extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rng:MersenneTwister;
	
	public var timetofire:Int;
	
	public var rename:String;
	
	public var shieldcolor:UInt = 0xFF9999;
	
	public var maxduration:Int = 500;
	
	public var minduration:Int = 200;
	
	public var maxHP = 4;
	public var shieldmodifier:Float = 9;
	
	//public var HP:Int;
	
	public function new() 
	{
		super("patchouli");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 3;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		HP = 3;
		pointvalue = 700;
		rename = "patchouli";
		reward = true;
		//rewarditem = "Power";
		//rename = "okuu";
	}
	override public function attack(player:Player):Bool
	{
		HP--;
		if (HP > 0)
		{
			invincibility = 10;
		}
		if (HP > 1)
		{
			var filterArr = new Array<flash.filters.BitmapFilter>();
			var AB = new flash.filters.GlowFilter();
			var D = Std.int(HP * shieldmodifier);
			AB.blurX = D;
			AB.blurY = D;
			AB.color = shieldcolor;
			AB.strength = 2;
			filterArr[filterArr.length] = AB;
		
			filters = filterArr;
		}
		else
		{
			filters = null;
		}
		return HP < 1;
	}
	public override function increaserank()
	{
			//accel += 0.1;
			//mxspd += 0.5;
			pointvalue += 100;
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		if (data.type == "spell")
		{
			var effects = ["flare", "lightning", "freeze","shield"];
			var effect = effects[Std.int(effects.length * data.R)];
			if (game.Hoster)
			{
				if (effect == "flare")
				{
					var D:Dynamic = { };
					D.x = x;
					D.y = y-30;
					D.Vspeed = 0;
					D.Hspeed = Ldir * 2;
					game.SendEvent("unyucannon", D);
				}
				if (effect == "lightning")
				{
					var D:Dynamic = { };
					D.x = (800-219)*Math.random();
					game.SendEvent("LightningStrike", D);
				}
				if (effect == "freeze")
				{
					game.SendEvent("FreezeWorld", null);
				}
			}
			if (effect == "shield")
			{
				if (HP < maxHP)
				{
					HP++;
					var filterArr = new Array<flash.filters.BitmapFilter>();
					var AB = new flash.filters.GlowFilter();
					var D = Std.int(HP * shieldmodifier);
					AB.blurX = D;
					AB.blurY = D;
					AB.color = shieldcolor;
					AB.strength = 2;
					filterArr[filterArr.length] = AB;
		
					filters = filterArr;
				}
			}
			if (effect == "flare")
			{
				Ldir = -Ldir;
			}
			//Ldir = -Ldir;
			rng.seed += rng.twist(rng.seed, 1, maxduration)[0];
			timetofire = minduration + (rng.seed % maxduration);
		}
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
			
			rng.seed += rng.twist(rng.seed, 1, maxduration)[0];
			timetofire = minduration + (rng.seed % maxduration);
			if (HP > 1)
			{
				var filterArr = new Array<flash.filters.BitmapFilter>();
				var AB = new flash.filters.GlowFilter();
				var D = Std.int(HP * shieldmodifier);
				AB.blurX = D;
				AB.blurY = D;
				AB.color = shieldcolor;
				AB.strength = 2;
				filterArr[filterArr.length] = AB;
		
				filters = filterArr;
			}
			if (UID < 0.3)
			{
				rewarditem = "Power";
			}
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
			timetofire--;
			if (timetofire < 140)
			{
				Hspeed = 0;
				//visuallyEnraged = !visuallyEnraged;
				doingability = true;
				if (timetofire < 1)
				{
					if (game.Hoster)
					{
						/*var D:Dynamic = { };
						D.x = x;
						D.y = y-30;
						D.Vspeed = 0;
						D.Hspeed = Ldir * 2;
						game.SendEvent("unyucannon", D);*/
						var D:Dynamic = { };
						D.R = Math.random();
						D.type = "spell";
						SendCustomEvent(D);
					}
					/*Ldir = -Ldir;
					rng.seed += rng.twist(rng.seed, 1, 700)[0];
					timetofire = 250 + (rng.seed % 700);*/
				}
			}
			else
			{
				visuallyEnraged = false;
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
	if (!alive && game.myplayer == bonkedby)
	{
		game.unlockcharacter("patchouli");
	}
	}
	public override function bump(player:Player)
	{
		rng.seed += rng.twist(rng.seed, 1, maxduration)[0];
		timetofire = minduration + (rng.seed % maxduration);
		HP--;
		if (HP > 1)
		{
			var filterArr = new Array<flash.filters.BitmapFilter>();
			var AB = new flash.filters.GlowFilter();
			var D = Std.int(HP * shieldmodifier);
			AB.blurX = D;
			AB.blurY = D;
			AB.color = shieldcolor;
			AB.strength = 2;
			filterArr[filterArr.length] = AB;
		
			filters = filterArr;
		}
		else
		{
			filters = null;
		}
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