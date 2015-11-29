package;

/**
 * ...
 * @author RSGmaker
 */
class PointItem extends EntityItem
{

	public function new() 
	{
		super("Point");
	}
	public override function Collect(player:Player)
	{
		alive = false;
		player.score += 200;
		player.ChangeExpression("Mouth", "39", 80, true);
		//player.ChangeExpression("Eyes", "93", 80, false);
		player.ChangeExpression("Eyes", "93", 30, false);
		
		
		{
			SoundManager.Play("collectcoin");
		}
		var i = 0;
		var ent = game.entities;
		while (i < ent.length)
		{
			var E = ent[i];
			if (E.subtype == "RainbowUFO")
			{
				var DU:Dynamic = E;
				var U:RainbowUFO = DU;
				if (U.fuel > 0 && U.pointsneeded > 0)
				{
					U.pointsneeded--;
					return;
				}
			}
			i++;
		}
	}
}