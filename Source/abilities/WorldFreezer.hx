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
<<<<<<< HEAD
		//player.maxcooldown = 7200+2000;
		//player.maxcooldown = 9200;
		player.maxcooldown = 13800;
=======
		player.maxcooldown = 3600+1000;
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
			game.SendKillAll();
			game.SendEvent("FreezeWorld", D);
		}
	}
}