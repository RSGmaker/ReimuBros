package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class LavaLogic extends ArenaLogic
{

	public function new() 
	{
		super();
	}
	override public function start() 
	{
		super.start();
		game.ProcessEvent("CharWorld","Myself", null);
		var L = new LavaEntity();
		L.x = 0;
		L.y = 800;
		game.AddObject(L);
		var Y = 464;
		/*game.AddWarningSign(32, Y, 150);
		game.AddWarningSign(370, Y, 150);
		game.AddWarningSign(760, Y, 150);*/
		
		game.AddWarningSign(96, Y, 150);
		game.AddWarningSign(370, Y, 150);
		game.AddWarningSign(640, Y, 150);
	}
}