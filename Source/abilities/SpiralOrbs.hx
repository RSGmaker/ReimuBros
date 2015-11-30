package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SpiralOrbs extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires spiraling orbs";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 630;
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
			D.type = "starorb";
			D.scale = 1.0;
			D.dir = player.Ldir;
			/*D.Vspeed = 0;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 6;
			}
			else
			{
				D.Hspeed = -6;
			}*/
			D.Hspeed = 0;
			D.Vspeed = 6;
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			D.spiral = 0.1;
			D.spiralrate = 0.990;
			game.SendPlayerDanmaku(D);
			D.Hspeed = -D.Hspeed;
			D.Vspeed = -D.Vspeed;
			game.SendPlayerDanmaku(D);
			/*D.Vspeed = 1;
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