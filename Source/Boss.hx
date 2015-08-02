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
	
	
	
	public var phase:Int;
	public var totalphases:Int;
	
	
	public function new() 
	{
		super("cirno");
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
		/*AB = new flash.filters.GlowFilter();
		AB.blurX = 10;
		AB.blurY = 10;
		AB.color = 0x000000;
		AB.strength = 2;
		filterArr[filterArr.length] = AB;
		glow[glow.length] = AB;
		AB = new flash.filters.GlowFilter();
		AB.blurX = 5;
		AB.blurY = 5;
		AB.color = 0x00FF00;
		AB.strength = 2;
		filterArr[filterArr.length] = AB;
		glow[glow.length] = AB;
		AB = new flash.filters.GlowFilter();
		AB.blurX = 0;
		AB.blurY = 0;
		AB.color = 0x000000;
		AB.strength = 2;
		filterArr[filterArr.length] = AB;
		glow[glow.length] = AB;*/
		
		filters = filterArr;
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
	public override function update()
	{
		if (!started)
		{
			started = true;
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			rng.twist(seed, 1, 100000);
		}
		/*var i = 0;
		//var reset = glow[0].color > 0x00F000;
		var reset = glow[0].color <= 0x000100;
		var R = true;
		while (i < glow.length)
		{
			//glow[i].strength++;
			
			if (reset)
			{
				if (R)
				{
					glow[i].color = 0x00FF00;
				}
				else
				{
					glow[i].color = 0x000000;
				}
				//glow[i].strength = R;
				//R += 0;
			}
			else
			{
				if (R)
				{
					glow[i].color -= 0x0001;
				}
				else
				{
					glow[i].color += 0x0001;
				}
			}
			R = !R;
			i++;
		}
		filters = filterArr;*/
		scaleX = 1;
		scaleY = 1;
		if (flipped < 1 || phase < totalphases)
		{
			invincibility = 10;
		}
		if (invincibility > 0)
		{
			invincibility--;
		}
		x = 400;
		y = 10;
		Hspeed = 0;
		Vspeed = 0;
		surprisetime = 100;
		if (surprisetime > 0)
		{
			surprisetime--;
			if (shottime > 0 && game.Hoster)
			{
				shottime--;
				if (shottime <= 0)
				{
					/*var D:Dynamic = { };
					D.UID = UID;
					game.SendEvent("ChenDanmaku", D);
					shottime = 10;*/
					var O = new DanmakuBullet("icebullet");
					O.x = x;
					O.y = y + 10;
					O.Vspeed = 4;
					O.visuallyrotates = true;
					O.changeangle(DegreeToRadian(180 + (rng.random() * 20)));
					//O.Vspeed =-0.2;
					//O.Hspeed = -3.5 - (rng.random()*3);
					O.shotby = this;

					O.rotrate = -0.019;
					O.rotdelay = 5;
					O.spiral = 1 - 0.01;
					O.currot = O.getangle();
					
					game.AddObject(O);
					O = new DanmakuBullet("icebullet");
					O.x = x;
					O.y = y + 10;
					O.Vspeed = 4;
					O.visuallyrotates = true;
					O.changeangle(DegreeToRadian(0 - (rng.random() * 20)));
					//O.Vspeed = -0.2;
					//O.Hspeed = 3.5 + (rng.random()*3);
					O.shotby = this;
					
					O.rotrate = 0.019;
					O.rotdelay = 5;
					O.spiral = 1 - 0.01;
					O.currot = O.getangle();
					game.AddObject(O);
					
					shottime = 10;
				}
			}
			if (surprisetime <= 0)
			{
				mxspd -= 4;
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
		updphysics();
		updateanimation();
		
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