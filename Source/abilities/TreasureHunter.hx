package abilities;

/**
 * ...
 * @author RSGmaker
 */
class TreasureHunter extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "May find hidden trophies\ninside blocks\n(resets each level)";
	}
	override public function onheadbonk() 
	{
		super.onheadbonk();
		//
		//if (game.Hoster)
		if (player.isme)
		{
			var headbonk:Dynamic = player.headbonk;
			if (headbonk != null && headbonk.type == "Block")
			{
				var B:Block = headbonk;
				if (!B.searched && !game.trophyactive && Math.random()>0.98)
				{
					var D:Dynamic = { };
					D.type = "Trophy";
					D.UID = Math.random();
					D.x = B.x;
					D.y = B.y-64;
					game.SendEvent("SpawnItem", D);
				}
				B.searched = true;
			}
		}
	}
}