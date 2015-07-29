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
		description = "Extra powblock uses";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.PreservePowBlock, true);
	}
}