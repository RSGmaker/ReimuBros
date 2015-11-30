package abilities;

/**
 * ...
 * @author RSGmaker
 */
class LargeYinYangOrbs extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a large yin-yang orb";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 570;
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
			//D.type = "yinyangorb";
			D.type = "shingyokuorb";
			D.image_speed = 1;
			D.spin = true;
			D.scale = 1.0;
			D.dir = player.Ldir;
			D.Vspeed = 2;
			D.HP = 4;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 9;
			}
			else
			{
				D.Hspeed = -9;
			}
			D.gravX = 0;
			D.gravY = 0.3;
			D.wrap = true;
			D.bounces = true;
			game.SendPlayerDanmaku(D);
		}
	}
}