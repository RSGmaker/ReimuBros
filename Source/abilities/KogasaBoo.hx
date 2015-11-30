package abilities;

/**
 * ...
 * @author RSGmaker
 */
class KogasaBoo extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Flipping an enemy can\ndefeat them instantly";
	}
	override public function onbump(E:Entity) 
	{
		super.onbump(E);
		if (Std.is(E, Enemy) && player.isme && Math.random()<0.2)
		{
			var D:Dynamic = E;
			var O:Enemy = D;
			if (O.flipped > 0)
			{
				game.SendEvent("Kill", O.UID);
				player.score += 200;
				player.ChangeExpression("Eyes", "26", 60, true);
				player.ChangeExpression("Mouth", "32");
			}
		}
	}
	/*override public function onheadbonk() 
	{
		super.onheadbonk();
		if (player.isme)
		{
			var headbonk = player.headbonk;
			if (headbonk.type == "Block")
			{
			var T = game.CollisionDetectPoint(headbonk.x - 32, headbonk.y);
			if (T != null)
			{
				game.SendEvent("Headbonk", T.UID);
			}
			T = game.CollisionDetectPoint(headbonk.x + 32, headbonk.y);
			if (T != null)
			{
				game.SendEvent("Headbonk", T.UID);
			}
			}
		}
	}*/
	
}