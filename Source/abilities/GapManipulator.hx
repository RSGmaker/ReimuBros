package abilities;

/**
 * ...
 * @author RSGmaker
 */
class GapManipulator extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Travels through gaps";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.GapManipulator, true);
	}
}