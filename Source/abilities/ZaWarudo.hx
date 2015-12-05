package abilities;

/**
 * ...
 * @author RSGmaker
 */
class ZaWarudo extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "「The World」";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 4800;
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
			game.SendEvent("ZaWarudo", D);
		}
	}
}