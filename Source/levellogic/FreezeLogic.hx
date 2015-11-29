package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class FreezeLogic extends ArenaLogic
{

	public function new() 
	{
		super();
	}
	override public function start() 
	{
		super.start();
		game.ProcessEvent("FreezeWorld","Myself", null);
	}
}