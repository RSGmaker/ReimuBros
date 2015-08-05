package;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.geom.ColorTransform;
import openfl.geom.Point;

/**
 * ...
 * @author RSGmaker
 */
class Lightning extends Entity
{

	public var Time:Int;
	public function new() 
	{
		super("lightning");
		type = "Lightning";
		Time = 25;
		y = -100;
	}
	override public function update():Void 
	{
		if (Time > 20)
		{
			alpha = 1-((Time-20)*0.25);
		}
		else
		{
			alpha = 1;
		}
		super.update();
		var T:GameView = game;
		var B = getBounds(T.gamestage);
		//nerf lightning size a bit
		B.right -= 120;
		B.left += 50;
		var P = game.myplayer;
		if (Time >= 0 && alpha>=1)
		{
		if (!P.killed && B.containsPoint(new Point(P.x+20, P.y+40)))
		{
			if (P.invincibility<=0 && !P.flags.get(Player.ElectricProof))
			{
				game.SendEvent("PlayerDeath", P.myMyon != null);
			}
		}
		if (game.Hoster)
		{
			var i = 0;
			while (i <T.activeEnemies.length)
			{
				var E = T.activeEnemies[i];
				if (B.containsPoint(new Point(E.x, E.y)))
				{
					game.SendEvent("Destroy", E.UID);
				}
				i++;
			}
			
		}
		}
		Time--;
		if (Time < 0)
		{
			alive = false;
		}
	}
}