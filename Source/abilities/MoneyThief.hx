package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MoneyThief extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "May take money from\ndefeated enemies";
	}
	override public function init() 
	{
		super.init();
	}
	override public function onkill(E:Entity) 
	{
		super.onkill(E);
		if (player.isme && Math.random()<0.10)
		{
			game.awardmoney(1);
		}
	}
}