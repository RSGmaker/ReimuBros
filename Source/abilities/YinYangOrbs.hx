package abilities;

/**
 * ...
 * @author RSGmaker
 */
class YinYangOrbs extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Yin-yang orbs";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 380;
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
			D.type = "yinyangorb";
			D.scale = 0.4;
			D.dir = player.Ldir;
			D.Vspeed = 2;
			D.HP = 6;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 10.5;
			}
			else
			{
				D.Hspeed = -10.5;
			}
			D.gravX = 0;
			D.gravY = 0.4;
			D.wrap = true;
			D.bounces = true;
			game.SendEvent("PlayerDanmaku", D);
		}
	}
}