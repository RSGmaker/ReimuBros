package abilities;

/**
 * ...
 * @author RSGmaker
 */
class NoCooldown extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Cheat:Instant cooldown";
	}
	override public function init() 
	{
		super.init();
	}
	override public function onframe() 
	{
		super.onframe();
		if (player.cooldown > 0)
		{
			player.cooldown = 1;
		}
	}

}