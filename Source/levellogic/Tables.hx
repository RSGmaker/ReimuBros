package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class Tables extends ArenaLogic
{

	public function new() 
	{
		super();
	}
	override public function start() 
	{
		//super.start();
		if (game.platformformation != 0)
		{
			game.platformformation = 0;
			game.setformation();
		}
		game.ProcessEvent("Spawntables", "Myself", null);
	}
}