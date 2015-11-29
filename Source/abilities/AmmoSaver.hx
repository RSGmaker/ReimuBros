package abilities;

/**
 * ...
 * @author RSGmaker
 */
class AmmoSaver extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Items sometimes\ndon't lose charges";
	}
	override public function init() 
	{
		super.init();
	}
	override public function onframe() 
	{
		super.onframe();
	}
	override public function onchargeused(E:CarryItem) 
	{
		super.onchargeused(E);
		if (player.isme && E.uses < E.maxuses && Math.random()<0.5)
		{
			E.uses++;
		}
	}
}