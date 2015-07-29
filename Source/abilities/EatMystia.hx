package abilities;

/**
 * ...
 * @author RSGmaker
 */
class EatMystia extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Kills mystias on\ncontact";
	}
	override public function init() 
	{
		super.init();
		player.flags.set(Player.EatMystia, true);
	}
	
}