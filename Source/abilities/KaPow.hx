package abilities;

/**
 * ...
 * @author RSGmaker
 */
class KaPow extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Flips all tiles";
	}
	override public function init() 
	{
		super.init();
<<<<<<< HEAD
		//player.maxcooldown = 7200;
		player.maxcooldown = 10800;
=======
		player.maxcooldown = 3600;
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
			game.SendEvent("POW!", D);
		}
	}
}