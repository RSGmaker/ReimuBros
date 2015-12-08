package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Expressionless extends PlayerAbility
{
	public var affected:Bool;
	public function new(player:Player) 
	{
		super(player);
		aesthetic = true;
		//description = "Does not express emotions";
	}
	override public function init() 
	{
		super.init();
		affected = player.expressive;
		if (affected)
		{
			player.expressive = false;
		}
	}
	override public function lostability() 
	{
		super.lostability();
		if (affected)
		{
			player.expressive = true;
		}
	}
}