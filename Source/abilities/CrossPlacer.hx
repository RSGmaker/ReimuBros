package abilities;

/**
 * ...
 * @author RSGmaker
 */
class CrossPlacer extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Places a cross";
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
			D.x = player.x + (player.width / 2);
			D.y = player.y + 0;
			//D.y = player.y + 40;
			D.type = "cross";
			D.scale = 0.1;
			D.maxscale = 1;
			D.dir = player.Ldir;
			D.Hspeed = 0;
			D.Vspeed = 0;
			D.timelimit = 360;
			D.gravX = 0;
			D.Vspeed = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendPlayerDanmaku(D);
			/*D.Vspeed = 0;
			D.gravY = 0;
			//D.y -= 20;
			D.y -= 30;
			game.SendPlayerDanmaku(D);*/
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