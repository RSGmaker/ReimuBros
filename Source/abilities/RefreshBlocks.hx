package abilities;

/**
 * ...
 * @author RSGmaker
 */
class RefreshBlocks extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Refreshes all blocks";
	}
	override public function init() 
	{
		super.init();
<<<<<<< HEAD
		player.maxcooldown = 1290;
=======
		player.maxcooldown = 430;
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
			game.SendEvent("RefreshBlocks", null);
		}
	}
}