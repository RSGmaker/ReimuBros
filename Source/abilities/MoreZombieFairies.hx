package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MoreZombieFairies extends PlayerAbility
{
	public var amount:Float = 0.1;//0.05
	public function new(player:Player)  
	{
		super(player);
		description = "Zombie fairies spawn more\nfrequently";
	}
	override public function init() 
	{
		super.init();
		player.zombiefairychance += amount;
	}
	override public function lostability() 
	{
		player.zombiefairychance -= amount;
		super.lostability();
	}
}