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
		description = "Cheeee~n";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 300;
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
				D.Hspeed = 10;
			}
			else
			{
				D.Hspeed = -10;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendEvent("PlayerDanmaku", D);
		}
	}
}