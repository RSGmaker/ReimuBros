package abilities;

/**
 * ...
 * @author RSGmaker
 */
class WaterAffinity extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Unhindered by water";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.WaterAffinity, true);
	}
	override public function lostability() 
	{
		player.flags.set(Player.WaterAffinity, false);
		super.lostability();
	}
}