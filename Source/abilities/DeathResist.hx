package abilities;

/**
 * ...
 * @author RSGmaker
 */
class DeathResist extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Resists death magic";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.DeathResistence, true);
	}
	override public function lostability() 
	{
		super.lostability();
		player.flags.set(Player.DeathResistence, false);
	}
}