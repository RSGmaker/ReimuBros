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
		description = "Remove extra obstacles";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1000;
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