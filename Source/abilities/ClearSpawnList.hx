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
		description = "Kills all unspawned\nenemies";
	}
	override public function init() 
	{
		super.init();
		//player.maxcooldown = 3600+1000;
<<<<<<< HEAD
		//player.maxcooldown = 7200+3000;
		//player.maxcooldown = 10200;
		player.maxcooldown = 15300;
=======
		player.maxcooldown = 3600+1500;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
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