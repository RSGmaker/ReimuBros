package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BasicWideShot extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a wave of bullets";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 610;
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
			D.x += D.Hspeed;
			game.SendPlayerDanmaku(D);
			//D.Vspeed = 1;
			var i = 0;
			var Y = D.y;
			while (i < 2)
			{
				D.x -= D.Hspeed * 2;
				Y -= 15;
				D.y = Y;
				var j = 0;
				while (j < i + 2)
				{
					game.SendPlayerDanmaku(D);
					D.y += 30;
					j++;
				}
				i++;
			}
		}
	}
}