package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BoomerangScythe extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Throws a boomerang scythe";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 860;
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
			D.type = "scythe";
			D.scale = 1;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			D.HP = 999999;
			D.gravX = -0.25;
			D.image_speed = 1;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 9;
			}
			else
			{
				D.Hspeed = -9;
				D.gravX = -D.gravX;
			}
			
			D.gravY = 0;
			game.SendEvent("PlayerDanmaku", D);
		}
	}
}