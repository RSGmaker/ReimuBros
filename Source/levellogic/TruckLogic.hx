package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class TruckLogic extends ArenaLogic
{

	public function new() 
	{
		super();
	}
	override public function start() 
	{
		super.start();
		game.spawnpaused = true;
		var D:Dynamic = { };
		D.type = "Trophy";
		D.UID = Math.random();
		D.x = 400;
		D.y = -100;
		game.SendEvent("SpawnItem", D);
	}
}