package;
import danmaku.DanmakuBullet;

/**
 * ...
 * @author RSGmaker
 */
class Boss extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var surprisetime:Int;
	public var shottime:Int;
	
	public var rng:MersenneTwister;
	
	private var filterArr:Array<flash.filters.BitmapFilter>;
	private var glow:Array<flash.filters.GlowFilter>;
	
	public var frame:Int;
	
	
	public var phase:Int;
	public var totalphases:Int;
	public var W2:Int;
	public var H2:Int;
	
	public var cx:Float;
	public var cy:Float;
	
	public var tx:Float;
	public var ty:Float;
	//whether or not the boss is flying in the air, and firing danmaku or just walking around
	public var firingdanmaku:Bool;
	public var rename:String;
	//public var unlock:String;
	
	
	public function new(bosstype:String="bosscirno") 
	{
		super(bosstype);
		rename = "cirno";
		subtype = "boss";
		accel = 1;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		surprisetime = 40;
		shottime = 9;
		mxspd += 4;
		//flash.filters.GradientGlowFilter
		filterArr = new Array<flash.filters.BitmapFilter>();
		glow = new Array<flash.filters.GlowFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 15;
		AB.blurY = 15;
		AB.color = 0xFF0000;
		AB.strength = 2;
		filterArr[filterArr.length] = AB;
		glow[glow.length] = AB;
		totalphases = 3;
		
		tx = 400;
		ty = 40;
		
		filters = filterArr;
		
		needtokill = true;
		
		firingdanmaku = true;
		ChangeAnimation(rename);
	}
	
	private function RadianToDegree(angle:Float):Float
	{
		//return Math.PI * angle / 180.0;
		//return angle * (180 / 3.14);
		return angle * 57.3248407;
	}
	private function DegreeToRadian(angle:Float):Float
	{
		//return Math.PI * angle / 180.0;
		//return angle * (180 / 3.14);
		return angle * 0.01744444;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 50;
	}
	public function outofminions()
	{
		if (firingdanmaku)
		{
			var D:Dynamic = { };
			var data:Dynamic = { };
			D.UID = UID;
			D.data = data;
			data.firing = !firingdanmaku;
			data.seed = rng.seed;
			data.phase = phase;
			game.SendEvent("CustomEvent", D);
			game.populatespawnlist();
		}
	}
	override public function CustomEvent(data:Dynamic) 
	{
		super.CustomEvent(data);
		firingdanmaku = data.firing;
		rng.seed = data.seed;
		phase = data.phase;
		frame = 0;
		visuallyEnraged = false;
	}
	public function defeated(P:Player)
	{
		if (P.isme)
		{
			game.unlockcharacter(rename);
			game.SendKillAll();
			var D:Dynamic = { };
			game.SendEvent("ClearSpawnList", D);
		}
	}
	public function dodanmaku()
	{
		if (shottime > 0)
		{
			shottime--;
			if (shottime <= 0)
			{
				var O = new DanmakuBullet("icebullet");
				O.x = cx;
				O.y = cy;
				O.Vspeed = 4;
				O.visuallyrotates = true;
				O.changeangle(DegreeToRadian(180 + (rng.random() * 20)));
				O.shotby = this;

				O.rotrate = -0.019;
				O.rotdelay = 5;
				O.spiral = 1 - 0.01;
				O.currot = O.getangle();
					
				game.AddObject(O);
				O = new DanmakuBullet("icebullet");
				O.x = cx;
				O.y = cy;
				O.Vspeed = 4;
				O.visuallyrotates = true;
				O.changeangle(DegreeToRadian(0 - (rng.random() * 20)));
				O.shotby = this;
					
				O.rotrate = 0.019;
				O.rotdelay = 5;
				O.spiral = 1 - 0.01;
				O.currot = O.getangle();
				game.AddObject(O);
					
				shottime = 10;
			}
		}
		if (game.rank > 0 || true)
		{
		if (frame % 350 < 25)
		{
			visuallyEnraged = !visuallyEnraged;
		}
		
		if (frame % 350 == 25)
		{
			visuallyEnraged = false;
			var i = 0;
			var X = cx - 200+(rng.quick(300));
			while (i < 5)
			{
				var O = new DanmakuBullet("icebullet");
				O.x = X;
				O.y = cy;
				O.Vspeed = 4;
				O.visuallyrotates = true;
				O.changeangle(1.57);
				O.shotby = this;

				O.currot = O.getangle();
					
				game.AddObject(O);
				i++;
				X += 32;
			}
		}
		}
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			rng.twist(seed, 1, 100000);
			W2 = (Math.floor(width) >> 1);
			H2 = (Math.floor(height) >> 1);
			if (game.boss != null)
			{
				alive = false;
			}
			else
			{
				game.boss = this;
			}
		}
		scaleX = 0.85;
		scaleY = 0.85;
		
		
		if (flipped < 1 || phase < totalphases)
		{
			invincibility = 10;
		}
		if (invincibility > 0)
		{
			invincibility--;
		}
		if (firingdanmaku && !killed)
		{
		//x = 400 - W2;
		//y = 10;
		var xx = tx - W2;
		var yy = ty - H2 + (H2 >> 1);
		cx = x + W2;
		cy = y + H2 + (H2 >> 1);
		Hspeed = 0;
		Vspeed = 0;
		var P:flash.geom.Point = new flash.geom.Point(cx - tx, cy - ty);
		if (P.length <= 4)
		{
			x = tx - (cx - x);
			y = ty - (cy - y);
		}
		else
		{
			P.normalize(4);
			Hspeed = -P.x;
			y -= P.y;
		}
		
		dodanmaku();
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
				//powerup();
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
				Ldir = 1;
				x = -32;
				y = - 200;
				if (rng.quick(100) > 50)
				{
					Ldir = -1;
					x = 832;
				}
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
	if (!alive/* && game.myplayer == bonkedby*/ && bonkedby != null)
	{
		if (bonkedby.type == "Player")
		{
			var D:Dynamic = bonkedby;
			defeated(D);
		}
		/*game.unlockcharacter(unlock);
		game.SendKillAll();
		var D:Dynamic = { };
		game.SendEvent("ClearSpawnList", D);*/
	}
	frame++;
	}
	public override function bump()
	{
		phase++;
		if (!firingdanmaku)
		{
			if (phase >= totalphases)
			{
				flipped = 30 * 10;
			}
			else
			{
				if (game.Hoster)
				{
					var D:Dynamic = { };
					var data:Dynamic = { };
					D.UID = UID;
					D.data = data;
					data.firing = !firingdanmaku;
					data.seed = rng.seed;
					data.phase = phase;
					game.populatespawnlist();
					game.SendEvent("CustomEvent", D);
				}
			}
		}
	}
	
}