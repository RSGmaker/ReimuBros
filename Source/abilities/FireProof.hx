package abilities;

/**
 * ...
 * @author RSGmaker
 */
class FireProof extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Fire proof";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.FireProof, true);
	}
}