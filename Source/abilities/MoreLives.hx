package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MoreLives extends PlayerAbility
{
	var toggle:Bool;
	public function new(player:Player) 
	{
		super(player);
		description = "Each life is worth two";
	}
	override public function onloselife()
	{
		if (toggle)
		{
			player.cancel = true;
		}
		toggle = !toggle;
	}
}