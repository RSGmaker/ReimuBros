package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Cheeen extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Throws Chen";
	}
	override public function init() 
	{
		super.init();
<<<<<<< HEAD
		player.maxcooldown = 4200;
=======
		player.maxcooldown = 1400;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
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
			D.type = "EChen";
			D.scale = 0.8;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 12;
			}
			else
			{
				D.Hspeed = -12;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = true;
			D.wrapdrain = true;
			D.HP = 17;
			game.SendEvent("PlayerDanmaku", D);
		}
	}
}