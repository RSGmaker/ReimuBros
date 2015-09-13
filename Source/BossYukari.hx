package;
import abilities.AbsorbDamage;
import danmaku.DanmakuBullet;

/**
 * ...
 * @author RSGmaker
 */
class BossYukari extends Boss
{
	private var FA:Array<flash.filters.BitmapFilter>;
	private var glw:Array<flash.filters.GlowFilter>;
	public var maxtraintime:Int = 600;
	public function new() 
	{
		super("bossyukari", "yukari");
		shottime = maxtraintime;
		
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
		
		if (data.type == "train")
		{
			var i = 0;
			var xx = data.x;
			while (i < 20)
			{
			var B:Bullet = new Bullet();
			B.x = xx;
			B.y = data.y;
			if (B.x > 800)
			{	
				B.Ldir = -1;
				xx += 360;
			}
			else
			{
				xx -= 360;
			}
			B.Hspeed = data.speed;
			B.Vspeed = 0;
			B.ChangeAnimation("train");
			game.AddObject(B);
			i++;
			}
			var X = 100;
			if (data.x > 800)
			{
				X = 800 - 64 - X;
			}
			var P = new Particle("warning");
			P.x = X;
			P.y = data.y + 48;
			P.HP = 135;
			P.filters = FA;
			game.AddObject(P);
		}
		else
		{
			super.CustomEvent(data);
		}
	}
	override public function dodanmaku() 
	{
		//super.dodanmaku();
		if (game.Hoster)
		{
		if (shottime > 0)
		{
			shottime--;
			if (shottime <= 0)
			{
				/*var O = new DanmakuBullet("icebullet");
				O.x = cx;
				O.y = cy;
				O.Vspeed = 2;
				O.visuallyrotates = true;
				O.changeangle(DegreeToRadian(180 + (rng.random() * 20)));
				O.shotby = this;

				O.rotrate = -0.0095;
				O.rotdelay = 5;
				O.spiral = 1 - 0.01;
				O.currot = O.getangle();
					
				game.AddObject(O);
				O = new DanmakuBullet("icebullet");
				O.x = cx;
				O.y = cy;
				O.Vspeed = 2;
				O.visuallyrotates = true;
				O.changeangle(DegreeToRadian(0 - (rng.random() * 20)));
				O.shotby = this;
					
				O.rotrate = 0.0095;
				O.rotdelay = 5;
				O.spiral = 1 - 0.01;
				O.currot = O.getangle();
				game.AddObject(O);*/
				var X = -5000;
				var Y = 0;
				//var spd = 15;
				var spd = 30;
				if (Math.random() > 0.5)
				{
					X = 800 + -X + 300;
					spd = -spd;
				}
				var R = Math.floor(4 * Math.random()) * 160;
				Y += R-64;
				var D:Dynamic = { };
				D.type = "train";
				D.UID = UID;
				D.x = X;
				D.y = Y;
				D.speed = spd;
				SendCustomEvent(D);
					
				shottime = maxtraintime;
			}
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
				var O = new DanmakuBullet("yukaribullet");
				O.x = X;
				O.y = cy;
				O.Vspeed = 2;
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
	
}