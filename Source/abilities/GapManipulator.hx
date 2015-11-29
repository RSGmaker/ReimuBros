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
		description = "Interacts with gaps";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.GapManipulator, true);
	}
	override public function lostability() 
	{
		player.flags.set(Player.GapManipulator, false);
		super.lostability();
	}
}