package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class ExplosiveLogic extends ArenaLogic
{

	public function new() 
	{
		super();
	}
	override public function CalculateLevelData(level:Int) 
	{
		super.CalculateLevelData(level);
		game.Obstacles = ["Explosives"];
		var epm = 26;
		game.epm = epm;
		game.ept = epm * (GameView.onetickperminutechance2);//the times 2 is for equalling "frame & 2>0" out above
		game.rept = (epm + 3 + (Math.floor(epm) >> 1)) * (GameView.onetickperminutechance2);
	}
}