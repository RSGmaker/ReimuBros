package abilities;

/**
 * ...
 * @author RSGmaker
 */
class DiscLauncher extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Throws plates";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 700;
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
			D.y = player.y + 40;
			D.type = "disc";
			D.scale = 0.9;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			//D.HP = 1;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 18;
			}
			else
			{
				D.Hspeed = -18;
			}
			//D.friction = 0.36;
			D.friction = 0.6;
			D.timelimit = 270;
			D.gravX = 0;
			D.Vspeed = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendPlayerDanmaku(D);
			D.Vspeed = 0;
			D.gravY = 0;
			//D.y -= 20;
			D.y -= 30;
			game.SendPlayerDanmaku(D);
			/*var i = 0;
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