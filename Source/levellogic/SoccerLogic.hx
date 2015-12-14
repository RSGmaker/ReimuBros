package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class SoccerLogic extends ArenaLogic
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
		var B = new SoccerBall();
		B.x = 200;
		B.y = 100;
		B.allowalternate = true;
		B.UID = 34780.7892503;
		game.AddObject(B);
		B = new SoccerBall();
		B.x = 600 - 32;
		B.starty = 100;
		B.y = 100 + 160;
		B.allowalternate = true;
		B.alternate = true;
		B.UID = 237896.27806;
		game.AddObject(B);
		//game.ProcessEvent("Spawntables", "Myself", null);
	}
}