package abilities;

/**
 * ...
 * @author RSGmaker
 */
class ElectricProof extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Lightning-proof";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.ElectricProof, true);
	}
}