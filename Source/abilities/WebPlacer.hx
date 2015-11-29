package abilities;

/**
 * ...
 * @author RSGmaker
 */
class WebPlacer extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Places spider webs";
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
				var D:Dynamic = { };
				D.x = player.x + (player.width / 2);
				D.y = player.y + (player.height / 2);
				D.d = 1000;
				game.SendEvent("Web", D);
			}
		}
	}
}