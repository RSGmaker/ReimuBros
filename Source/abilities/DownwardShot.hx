package abilities;

/**
 * ...
 * @author RSGmaker
 */
class DownwardShot extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires bullets downwards";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 570;
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
			var rate = 0.2;
			var D:Dynamic = { };
			D.x = player.x;
			D.y = player.y + 30;
			D.type = "pbullet";
			D.scale = 0.8;
			D.dir = player.Ldir;
			/*D.Vspeed = 0;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 10;
			}
			else
			{
				D.Hspeed = -10;
			}*/
			D.Hspeed = 0;
			//D.Vspeed = 10;
			D.Vspeed = 10*rate;
			
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendPlayerDanmaku(D);
			//D.Hspeed = 1;
			D.Hspeed = rate;
			
			var i = 0;
			while (i < 2)
			{
				//D.Hspeed += 1;
				D.Hspeed += rate;
				D.Vspeed -= D.dir*rate;
				game.SendPlayerDanmaku(D);
				D.Hspeed *= -1;
				game.SendPlayerDanmaku(D);
				D.Hspeed *= -1;
				i++;
			}
		}
	}
}