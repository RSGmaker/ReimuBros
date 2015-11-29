package abilities;

/**
 * ...
 * @author RSGmaker
 */
class WeakLaser extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a weak laser\n(lacks piercing damage)";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 580;
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
			//D.x = -8;
			D.x = -player.middle;
			//D.y = player.y + (player.height - 20);
			D.y = (player.height - 20);
			D.user = player.UID;
			D.antiplayer = false;
			D.antienemy = true;
			D.piercing = false;
			game.SendEvent("LaserBeam",D);
		}
	}
}