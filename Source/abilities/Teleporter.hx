package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Teleporter extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Teleports to your mouse's\nposition";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1260;
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
			player.x = Math.max(Math.min(player.stage.mouseX-40,800),0);
			player.y = Math.max(Math.min(player.stage.mouseY,500),0);
			if (player.x < 0)
			{
				player.x = 0;
			}
		}
	}
}