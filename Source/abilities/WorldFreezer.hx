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
		description = "Chills the stage";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 5100;
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