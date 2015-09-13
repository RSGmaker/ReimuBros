package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SuwakoHoop extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Throws an iron ring";
	}
	override public function init() 
	{
		super.init();
		//player.maxcooldown = 380;
		
		//player.maxcooldown = 640;
		player.warncooldown = true;
		
		//player.maxcooldown = 460;
		player.maxcooldown = 615;
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
			D.type = "suwakohoop";
			D.scale = 0.9;
			D.dir = player.Ldir;
			
			//D.HP = 22;
			D.HP = 18;
			D.Vspeed = -6;
			D.Hspeed = 20;
			if (player.Ldir >= 0)
			{
				//D.Hspeed = 10.5;
			}
			else
			{
				//D.Hspeed = -10.5;
				D.Hspeed = -D.Hspeed;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = true;
			D.bounces = true;
			D.topbounce = true;
			D.bouncedrain = true;
			game.SendEvent("PlayerDanmaku", D);
		}
	}
}