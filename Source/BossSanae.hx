package;
import danmaku.DanmakuBullet;

/**
 * ...
 * @author RSGmaker
 */
class BossSanae extends Boss
{
	public var wavetime:Int = 20;
	public var wavesine:Float = 0;
	public var warning:Bool = false;
	private var FA:Array<flash.filters.BitmapFilter>;
	private var glw:Array<flash.filters.GlowFilter>;
	private var maxdist:Int = 300;
	private var dist:Int;
	private var LeftWall:Array<Bullet>;
	private var RightWall:Array<Bullet>;
	public function new() 
	{
		super("bosssanae", "sanae");
		//shottime = wavetime;
		shottime = 120;
		dist = maxdist;
		
		FA = new Array<flash.filters.BitmapFilter>();
		glw = new Array<flash.filters.GlowFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 10;
		AB.blurY = 10;
		AB.color = 0xFFFFFF;
		AB.strength = 1;
		FA[FA.length] = AB;
		glw[glow.length] = AB;
	}
	override public function CustomEvent(data:Dynamic) 
	{
		super.CustomEvent(data);
		if (data.type == "phase")
		{
			killwave(LeftWall);
			killwave(RightWall);
			LeftWall = null;
			RightWall = null;
			wavesine = 0;
			dist = maxdist;
		}
	}
	private function killwave(wave:Array<Bullet>)
	{
		var i = 0;
		if (wave != null)
		{
		while (i < wave.length)
		{
			if (wave[i] != null && wave[i].alive)
			{
				wave[i].HP = 0;
				wave[i].alive = false;
			}
			i++;
		}
		}
	}
	private function warn()
	{
		var P = new Particle("warning");
			P.x = 32;
			P.y = 48;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
			
			P = new Particle("warning");
			P.x = 800-64;
			P.y = 48;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
			
			//
			P = new Particle("warning");
			P.x = 32;
			P.y = 48+160;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
			
			P = new Particle("warning");
			P.x = 800-64;
			P.y = 48+160;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
			
			//
			P = new Particle("warning");
			P.x = 32;
			P.y = 48+320;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
			
			P = new Particle("warning");
			P.x = 800-64;
			P.y = 48+320;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
			
			//
			P = new Particle("warning");
			P.x = 32;
			P.y = 48+480;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
			
			P = new Particle("warning");
			P.x = 800-64;
			P.y = 48+480;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
	}
	private var waveindex:Int;
	private function makewave(X:Float,wave:Array<Bullet>)
	{
		var WI = wave.length - waveindex;
		//var Y = 0;
		var Y = -100;
		var W = wavesine;
		
		X = X + (Math.sin(W) * 75);
		var i = 0;
		var start = wave.length == 0;
		while (Y <= 630)
		{
			W += 0.2+0.02;
			if (i == WI || i-1 == WI || i-2 == WI || start)
			{
			//var XX = X + (Math.sin(W)*150);
			//var XX = X + (Math.sin(W)*125);
			var XX = X + (Math.sin(W)*50);
			//W += 0.06;
			//W += 0.0075;
			//W += 0.005;
			//W += 0.005+0.02;
			var B = null;
			if (wave[i] == null || !wave[i].alive)
			{
				B = new Bullet();
				B.ChangeAnimation("bluelaser");
				B.x = XX;
				B.y = 600 - Y;
				game.AddObject(B);
				wave[i] = B;
			}
			else
			{
				B = wave[i];
			}
			B.x = XX;
			B.y = 600-Y;
			//B.HP = wavetime+1;
			B.HP = 120;
			}
			else
			{
				if (wave[i] == null || !wave[i].alive)
				{
					
				}
				else
				{
					var B = wave[i];
					//B.HP = wavetime+1;
					B.HP = 120;
				}
			}
			Y += 12;
			i++;
		}
	}
	override public function dodanmaku() 
	{
		if (!warning)
		{
			warning = true;
			warn();
		}
		if (shottime > 0)
		{
			shottime--;
			if (shottime <= 0)
			{
				if (LeftWall == null)
				{
					LeftWall = new Array<Bullet>();
					RightWall = new Array<Bullet>();
				}
				makewave(-150-dist,LeftWall);
				makewave(700+dist,RightWall);
				//wavesine+= 0.25;
				//wavesine+= 0.2;
				//wavesine+= 0.01;
				//wavesine+= 0.015;
				wavesine+= 0.015;
				waveindex+=3;
				if (waveindex > LeftWall.length+1)
				{
					waveindex = 0;
				}
				shottime = 1;
				//shottime = wavetime;
				
				if (dist > 0)
				{
					dist -= 1;
				}
				if (dist <= 0)
				{
					dist = 0;
				}
			}
		}
		doingability = false;
		if (frame % 325 < 25)
		{
			//visuallyEnraged = !visuallyEnraged;
			doingability = true;
		}
		
		if (frame % 325 == 25)
		{
			//visuallyEnraged = false;
			//doingability = false;
			var i = 0;
			//var X = cx - 200 + (rng.quick(300));
			var X = cx;
			var Y = cy+32;
			var A = 0.7 + (rng.quick(160) * 0.01);
			var S = 3.5;
			while (i < 5)
			{
				var O = new DanmakuBullet("lbullet");
				O.x = X;
				O.y = Y;
				O.Vspeed = S;
				//S -= 0.1;
				O.visuallyrotates = true;
				//O.changeangle(1.57);
				O.changeangle(A);
				O.shotby = this;

				O.currot = O.getangle();
					
				game.AddObject(O);
				Y -= 32;
				i++;
				
				//X += 32;
			}
		}
		
	}
	override public function update() 
	{
		super.update();
		if (!firingdanmaku)
		{
			dist = maxdist;
		}
	}
}