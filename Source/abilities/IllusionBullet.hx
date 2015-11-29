package abilities;

/**
 * ...
 * @author RSGmaker
 */
class IllusionBullet extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires an illusion bullet";
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
			D.type = "preisenbullet";
			D.scale = 1;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			D.illusion = true;
			//D.illusiontime = 50;
			D.illusiontime = 50;
			D.illusionrate = 0.62;
			if (player.y < 100)
			{
				D.illusiondir = 1;
			}
			var spd = 10;
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