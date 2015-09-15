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
	private function makewave(X:Float)
	{
		var Y = 0;
		var W = wavesine;
		while (Y <= 630)
		{
			var XX = X + (Math.sin(W)*150);
			W += 0.06;
			var B = new Bullet();
			B.x = XX;
			B.y = 600-Y;
			B.HP = wavetime+1;
			B.ChangeAnimation("bluelaser");
			game.AddObject(B);
			Y += 12;
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
				makewave(-150-dist);
				makewave(700+dist);
				//wavesine+= 0.25;
				wavesine+= 0.2;
				shottime = wavetime;
				
				if (dist > 0)
				{
					dist -= 20;
				}
				if (dist <= 0)
				{
					dist = 0;
				}
			}
		}
		if (frame % 325 < 25)
		{
			visuallyEnraged = !visuallyEnraged;
		}
		
		if (frame % 325 == 25)
		{
			visuallyEnraged = false;
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