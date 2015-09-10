package abilities;

/**
 * ...
 * @author RSGmaker
 */
class WorldScorcher extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Turns everything to ash";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 7200+2000;
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
			game.SendEvent("CharWorld", D);
		}
	}
}