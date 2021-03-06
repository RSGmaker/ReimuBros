package abilities;

/**
 * ...
 * @author RSGmaker
 */
class PreservePowBlock extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Extra POW Block uses";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.PreservePowBlock, true);
	}
}