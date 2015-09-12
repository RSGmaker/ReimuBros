package;
import openfl.display.Bitmap;
import openfl.geom.Point;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class BlackHole extends Entity
{
	public var thrownby:Player;
	public var visual:Bitmap;
	public var timeleft:Int;
	public function new() 
	{
		super(null);
		visual = new Bitmap(game.AL.GetAnimation("blackhole")[0]);
		visual.x -= visual.width/2;
		visual.y -= visual.height/2;
		timeleft = 550;
		scaleX = 0.05;
		scaleY = 0.05;
		addChild(visual);
	}
	public function kill(UID:Float)
	{
		if (thrownby == game.myplayer)
		{
			//game.SendEvent("Kill", UID);
			game.SendEvent("Obliterate", UID);
		}
	}
	override public function GetHitbox():Rectangle 
	{
		return new Rectangle(x, y, 16, 16);
		//return super.GetHitbox();
	}
	override public function update():Void 
	{
		super.update();
		//visual.x = -(visual.width / 2);
		//visual.y = visual.x
		rotation += 20;
		var i = 0;
		var L = game.activeEnemies;
		timeleft--;
		if (timeleft < 1)
		{
			if (scaleX <= 0)
			{
				alive = false;
			}
			else
			{
				scaleX -= 0.05;
				scaleY = scaleX;
			}
		}
		else
		{
			if (scaleX < 1)
			{
				scaleX += 0.05;
				scaleY = scaleX;
			}
		}
		/*if (scaleX < 1)
		{
			return;
		}*/
		while (i < L.length)
		{
			var E = L[i];
			if (!E.killed && E.invincibility<=0 && /*Math.abs(x - E.x) < 200 && */Math.abs(y - E.y) < 64)
			{
				var S = new Point(x - E.x, y - E.y);
				var P = 48 - (Math.floor(Math.abs(x - E.x)) >> 3);
				P = P >> 2;
				if (P > 0)
				{
				if (S.length < P)
				{
					E.x = x;
					E.y = y;
				}
				else
				{
					//S.normalize(16);
					S.normalize(P);
					//E.Hspeed = 0;
					//E.Vspeed = 0;
					E.x += S.x;
					E.y += S.y;
				}
				}
			}
			i++;
		}
		
		
		if (thrownby == game.myplayer)
		{
			var enemy = game.CollisionDetectTouchEnemy(this,true);
			var danger = game.CollisionDetectTouchDangerous(this,true);
			if (enemy != null && !enemy.killed && enemy.invincibility<=0)
			{
				//game.SendEvent("Kill", enemy.UID);
				kill(enemy.UID);
			}
			var DD:Dynamic = danger;
			if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
			{
				kill(danger.UID);
			}
		}
	}
}