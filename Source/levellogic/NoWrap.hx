package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class NoWrap extends ArenaLogic
{

	public function new() 
	{
		super();
	}
	override public function start() 
	{
		super.start();
		game.ProcessEvent("NoWrap", "Myself", null);
	}
}