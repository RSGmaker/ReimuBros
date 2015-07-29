package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MoreZombieFairies extends PlayerAbility
{

	public function new(player:Player)  
	{
		super(player);
		description = "Defeating fairies spawns\nZombie fairies";
	}
	override public function init() 
	{
		super.init();
		player.zombiefairychance += 0.06;
	}
}