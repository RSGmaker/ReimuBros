package abilities;

/**
 * ...
 * @author RSGmaker
 */
class FlipResistance extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Prevents screen-flipping";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.FlipResistance, true);
	}
}