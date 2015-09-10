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
		player.maxcooldown = 2800;
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
			D.scale = 0.4;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 6;
			}
			else
			{
				D.Hspeed = -6;
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