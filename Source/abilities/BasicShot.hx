package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BasicShot extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a magic bullet";
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
			D.type = "bullet";
			D.scale = 0.8;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 5;
			}
			else
			{
				D.Hspeed = -5;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendEvent("PlayerDanmaku", D);
			D.Vspeed = 0.5;
			var i = 0;
			while (i < 1)
			{
				D.Vspeed += 0.5;
				D.Hspeed -= (D.dir*0.5);
				game.SendEvent("PlayerDanmaku", D);
				D.Vspeed *= -1;
				game.SendEvent("PlayerDanmaku", D);
				D.Vspeed *= -1;
				i++;
			}
		}
	}
}