package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BladeStrike extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Cuts down foes with blade\nand vigor";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 300;
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
			D.y = player.y + 30;
			D.type = "lightsword";
			D.scale = 1;
			D.emerge = true;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			//D.Hspeed = 0;
			D.Hspeed = 0.0001 * player.Ldir;
			D.rotated = true;
			D.piercing = true;
			if (player.Ldir < 0)
			{
				D.x -= 100;
			}
			else
			{
				D.x += player.width;
			}
			D.Vspeed = 0;
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			D.timelimit = 10;
			game.SendPlayerDanmaku(D);
			/*var D:Dynamic = { };
			D.x = player.x;
			D.y = player.y + 30;
			D.type = "pbullet";
			D.scale = 0.8;
			D.dir = player.Ldir;
			D.Vspeed = 0;
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
			D.Vspeed = 1;
			var i = 0;
			while (i < 1)
			{
				D.Vspeed += 1;
				D.Hspeed -= D.dir;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				i++;
			}*/
		}
	}
}