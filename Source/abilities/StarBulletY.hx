package abilities;

/**
 * ...
 * @author RSGmaker
 */
class StarBulletY extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Wide shot";
	}
	override public function init() 
	{
		super.init();
<<<<<<< HEAD
		player.maxcooldown = 1980;
=======
		player.maxcooldown = 660;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
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
			var spd = 8;
			var D:Dynamic = { };
			D.x = player.x;
			D.y = player.y + 30;
			D.type = "starbullety";
			D.scale = 0.8;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			if (player.Ldir >= 0)
			{
				D.Hspeed = spd;
			}
			else
			{
				D.Hspeed = -spd;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendEvent("PlayerDanmaku", D);
			var i = 0;
			D.Vspeed = 1;
			while (i < 4)
			{
				D.Vspeed += 1;
				D.Hspeed -= D.dir;
				game.SendEvent("PlayerDanmaku", D);
				D.Vspeed *= -1;
				game.SendEvent("PlayerDanmaku", D);
				D.Vspeed *= -1;
				i++;
			}
		}
	}
}