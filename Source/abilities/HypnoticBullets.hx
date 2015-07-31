package abilities;

/**
 * ...
 * @author RSGmaker
 */
class HypnoticBullets extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a hypnotic bullet";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 350;
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
			//D.y = player.y + 10;
			D.y = player.y + 30;
			D.type = "heartbullet";
			D.scale = 0.7;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			D.HP = 1;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 10.5;
			}
			else
			{
				D.Hspeed = -10.5;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.bumps = true;
			//D.wrap = true;
			//D.bounces = true;
			game.SendEvent("PlayerDanmaku", D);
			D.y -= 20;
			game.SendEvent("PlayerDanmaku", D);
		}
	}
}