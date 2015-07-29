package abilities;

/**
 * ...
 * @author RSGmaker
 */
class HeavyBonk extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Hits 3 blocks at once";
	}
	override public function onheadbonk() 
	{
		super.onheadbonk();
		if (player.isme)
		{
			var headbonk = player.headbonk;
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
	
}