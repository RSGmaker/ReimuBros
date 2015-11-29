package abilities;

/**
 * ...
 * @author RSGmaker
 */
class HeavyHitter extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Hits blocks harder";
	}
	override public function onheadbonk() 
	{
		super.onheadbonk();
		if (player.isme)
		{
			var headbonk = player.headbonk;
			if (headbonk.type == "Block")
			{
				headbonk.bonked += Std.int(headbonk.bonked / 2);
			}
		}
	}
	
}