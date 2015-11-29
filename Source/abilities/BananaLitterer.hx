package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BananaLitterer extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Drops a banana peel on\nthe ground";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 900;
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
			D.x = player.x;
			D.y = player.y+20;
			game.SendEvent("BananaPeel", D);
		}
	}
}