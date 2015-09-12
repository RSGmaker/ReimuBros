package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SpawnShanghai extends PlayerAbility
{

	public function new(player:Player)  
	{
		super(player);
		description = "Defeating fairies has a\nchance to spawn Shanghai\ndolls";
	}
	override public function init() 
	{
		super.init();
		player.zombiefairytype = "shanghai";
		player.zombiefairyscale = 0.6;
		player.zombiefairychance += 0.05;
	}
}