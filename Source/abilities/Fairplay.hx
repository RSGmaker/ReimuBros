package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Fairplay extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Removes extra obstacles";
	}
	override public function init() 
	{
		super.init();
<<<<<<< HEAD
		player.maxcooldown = 3000;
=======
		player.maxcooldown = 1000;
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
		if (player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			if (player.isme)
			{
				game.SendEvent("Fairplay", null);
			}
		}
	}
}