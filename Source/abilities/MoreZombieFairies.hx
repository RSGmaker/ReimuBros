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
		description = "Zombie fairies spawn more\nfrequently";
	}
	override public function init() 
	{
		super.init();
		player.zombiefairychance += 0.05;
	}
}