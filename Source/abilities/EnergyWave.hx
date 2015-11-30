package abilities;

/**
 * ...
 * @author RSGmaker
 */
class EnergyWave extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a wave of energy that\nknocks enemies off their\nfeet";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 400;
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
			D.y = player.y - 30;
			D.type = "energywave";
			D.scale = 0.8;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			D.bumps = true;
			D.Hspeed = 22;
			if (player.Ldir < 0)
			{
				D.Hspeed = -D.Hspeed;
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