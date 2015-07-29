package abilities;

/**
 * ...
 * @author RSGmaker
 */
class ClearSpawnList extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Kills all non present enemies";
	}
	override public function init() 
	{
		super.init();
		//player.maxcooldown = 3600+1000;
		player.maxcooldown = 3600+1500;
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
			game.SendEvent("ClearSpawnList", D);
		}
	}
}