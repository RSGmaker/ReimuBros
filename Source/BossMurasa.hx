package;
import danmaku.DanmakuBullet;
/**
 * ...
 * @author RSGmaker
 */
class BossMurasa extends Boss
{
	private var Anchor:DanmakuBullet;
	private var AnchorCooldown:Int = 300;
	private var ReverseDelay:Int;
	private var ReverseHspeed:Float;
	private var ReverseVspeed:Float;
	private var AnchorDist:Float;
	public function new() 
	{
		super("bossmurasa", "murasa");
		shottime = AnchorCooldown;
	}
	override public function outofminions() 
	{
		//force attack to play out even if wave is finished
		/*if (Anchor == null)
		{
			super.outofminions();
		}*/
		
		//end attack early if wave finishes during it.
		if (Anchor != null)
		{
			Anchor.alive = false;
			Anchor.killed = true;
			Anchor = null;
		}
		super.outofminions();
	}
	override public function CustomEvent(data:Dynamic) 
	{
		super.CustomEvent(data);
		if (data.type == "anchor")
		{
			ThrowAnchor(data.angle);
		}
	}
	private function ThrowAnchor(A:Float)
	{
		if (Anchor != null)
		{
			Anchor.alive = false;
			Anchor.killed = true;
			Anchor = null;
		}
		var X = cx;
		var Y = cy+32;
		//var A = 0.7 + (rng.quick(160) * 0.01);
		var S = 0.3;
		shottime = AnchorCooldown;
		Anchor = new DanmakuBullet("anchor");
		Anchor.alive = true;
		Anchor.killed = false;
		ReverseDelay = 30;
		Anchor.x = X;
		Anchor.y = Y;
		Anchor.Vspeed = S;
		//S -= 0.1;
		Anchor.visuallyrotates = true;
		//O.changeangle(1.57);
		Anchor.changeangle(A);
		Anchor.shotby = this;

		Anchor.currot = Anchor.getangle();
		Anchor.gravX = Anchor.Hspeed;
		Anchor.gravY = Anchor.Vspeed;
				
		ReverseHspeed = -Anchor.Hspeed;
		ReverseVspeed = -Anchor.Vspeed;
				
		Anchor.Hspeed = 0;
		Anchor.Vspeed = 0;
		AnchorDist = 0;
		game.AddObject(Anchor);
	}
	override public function dodanmaku() 
	{
		//super.dodanmaku();
		if (Anchor != null && !Anchor.alive)
		{
			Anchor.alive = false;
			Anchor.killed = true;
			Anchor = null;
		}
		if (Anchor == null)
		{
		//if (shottime > 0)
		{
			shottime--;
			if (shottime <= 0)
			{
				if (game.Hoster)
				{
					var D:Dynamic = { };
					D.type = "anchor";
					D.angle = 0.7 + (rng.quick(160) * 0.01);
					SendCustomEvent(D);
				}
			}
		}
		if (shottime < 25)
		{
			visuallyEnraged = !visuallyEnraged;
		}
		else
		{
			visuallyEnraged = false;
		}
		}
		else
		{
			if (Anchor.Vspeed>=0)
			{
				if ( Anchor.y + 30 >= 600)
				{
					Anchor.Hspeed = 0;
					Anchor.Vspeed = 0;
					ReverseDelay--;
					if (ReverseDelay < 1)
					{
						Anchor.gravX = ReverseHspeed;
						Anchor.gravY = ReverseVspeed;
					}
				}
				if (Anchor.Vspeed > 0)
				{
					
					AnchorDist += (Anchor.Vspeed + Math.abs(Anchor.Hspeed));
					//var C = (Anchor.Vspeed + Math.abs(Anchor.Hspeed))*3;
					//if (rng.quick(100) < C)
					if (AnchorDist>100)
					{
						AnchorDist -= 100;
						var S = 3;
						var PI2 = 314 + 314;
						//var A = rng.quick(PI2) * 0.01;
						var A;
						A = Anchor.currot - 1.57;
						/*if (rng.quick(100) > 50)
						{
							A += 3.14;
						}*/
						/*A += ( -0.1) + (rng.quick(200) * 0.01);*/
						var O = new DanmakuBullet("murasabullet");
						O.x = Anchor.x;
						O.y = Anchor.y;
						O.Vspeed = S;
						//S -= 0.1;
						O.visuallyrotates = true;
						//O.changeangle(1.57);
						O.changeangle(A);
						O.shotby = this;

						O.currot = O.getangle();
					
						game.AddObject(O);
						
						A = A + 3.14;
						O = new DanmakuBullet("murasabullet");
						O.x = Anchor.x;
						O.y = Anchor.y;
						O.Vspeed = S;
						//S -= 0.1;
						O.visuallyrotates = true;
						//O.changeangle(1.57);
						O.changeangle(A);
						O.shotby = this;

						O.currot = O.getangle();
					
						game.AddObject(O);
					}
				}
			}
			else
			{
				if (Anchor.y <= y+height)
				{
					Anchor.alive = false;
					Anchor.killed = true;
					Anchor = null;
				}
			}
		}
	}
}