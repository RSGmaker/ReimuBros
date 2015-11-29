package abilities;

/**
 * ...
 * @author RSGmaker
 */
class LongerCombos extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Combos last longer";
	}
	override public function init() 
	{
		super.init();
	}
	override public function onkill(E:Entity) 
	{
		super.onkill(E);
		if (player.combotime > 0)
		{
			player.combotime += 30;
		}
	}
}