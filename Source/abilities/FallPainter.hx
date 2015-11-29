package abilities;

/**
 * ...
 * @author RSGmaker
 */
class FallPainter extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Bumping an enemy\nturns them red";
	}
	override public function init() 
	{
		super.init();
	}
	override public function onbump(E:Entity) 
	{
		super.onbump(E);
		if (Std.is(E, Enemy))
		{
			var D:Dynamic = E;
			var O:Enemy = D;
			if (O.enrageable)
			{
				game.SendEvent("Enrage", E.UID);
			}
		}
	}
}