package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SpawnShanghai extends PlayerAbility
{
	public var originalfairy:String;
	public var originalfairyscale:Float;
	public function new(player:Player)  
	{
		super(player);
		description = "Defeating fairies has a\nchance to spawn Shanghai\ndolls";
	}
	override public function init() 
	{
		super.init();
		originalfairy = player.zombiefairytype;
		originalfairyscale = player.zombiefairyscale;
		
		player.zombiefairytype = "shanghai";
		player.zombiefairyscale = 0.6;
		player.zombiefairychance += 0.05;
	}
	override public function lostability() 
	{
		player.zombiefairytype = originalfairy;
		player.zombiefairyscale = originalfairyscale;
		player.zombiefairychance -= 0.05;
		super.lostability();
	}
}