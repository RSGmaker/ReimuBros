package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SwordBullets extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Throws swords";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 750;
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
			D.type = "sword";
			D.rotated = true;
			D.scale = 1;
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
			while (i < 2)
			{
				D.Vspeed += 1;
				D.Hspeed -= D.dir;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				i++;
			}
		}
	}
}