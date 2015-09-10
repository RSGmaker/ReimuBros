package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SuperSpeed extends PlayerAbility
{

	public function new(player:Player)  
	{
		super(player);
		description = "Moves quickly\nJumps higher\nFalls slowly";
	}
	override public function init() 
	{
		super.init();
		player.deccel -= 0.05;
		player.fallaccel -= 0.05;
		player.mxspd += 1;
	}
	override public function lostability() 
	{
		super.lostability();
		player.deccel += 0.05;
		player.fallaccel += 0.05;
		player.mxspd -= 1;
	}
}