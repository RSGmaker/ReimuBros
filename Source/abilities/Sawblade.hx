package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Sawblade extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Releases a sawblade";
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
			D.y = player.y + 10;
			D.type = "sawblade";
			D.scale = 0.7;
			D.dir = player.Ldir;
			D.Vspeed = 2;
			D.submerge = true;
			D.spin = true;
			D.HP = 5;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 6;
			}
			else
			{
				D.Hspeed = -6;
			}
			D.gravX = 0;
			D.gravY = 0.6;
			D.wrap = true;
			D.rolls = true;
			//D.bounces = true;
			game.SendPlayerDanmaku(D);
		}
	}
}