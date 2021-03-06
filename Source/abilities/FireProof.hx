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
		description = "Fireproof";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.FireProof, true);
	}
	override public function lostability() 
	{
		player.flags.set(Player.FireProof, false);
		super.lostability();
	}
}