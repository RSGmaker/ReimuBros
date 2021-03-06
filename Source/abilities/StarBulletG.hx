package abilities;

/**
 * ...
 * @author RSGmaker
 */
class StarBulletG extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Momentum-aimed shot";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 600;
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
			D.y = player.y + 0;
			D.type = "starbulletg";
			D.scale = 1;
			D.dir = player.Ldir;
			D.Vspeed = player.Vspeed;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 10;
			}
			else
			{
				D.Hspeed = -10;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendPlayerDanmaku(D);
		}
	}
}