package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Hover extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Hovers above platforms\npreventing slipping & burning\nHandles great in mid-air";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.FireProof, true);
		player.ignoreice = true;
		
		player.Haccel = player.accel;
		player.Hdeccel = player.deccel;
	}
	override public function lostability() 
	{
		player.flags.set(Player.FireProof, false);
		player.ignoreice = false;
		
		player.Haccel *= 0.8;
		player.Hdeccel *= 0.8;
		super.lostability();
	}
}
	