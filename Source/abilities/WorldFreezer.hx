package abilities;

/**
 * ...
 * @author RSGmaker
 */
class WorldFreezer extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Chills the world";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 3600+1000;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			var D:Dynamic = { };
			game.SendKillAll();
			game.SendEvent("FreezeWorld", D);
		}
	}
}