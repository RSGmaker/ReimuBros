package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MegaLaser extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a large laser";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 540;
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
			D.x = -30;
			
			D.y = player.height / 2;
			//D.y = y-player.y;
			D.size = 30;
			D.time = 14;
			D.user = player.UID;
			D.antiplayer = false;
			D.antienemy = true;
			game.SendEvent("LaserBeam",D);
		}
	}
}