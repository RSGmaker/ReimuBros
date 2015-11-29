package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class YuukaLogic extends ArenaLogic
{

	public function new() 
	{
		super();
	}
	override public function start() 
	{
		super.start();
		game.maxyuuka = 3;
	}
}