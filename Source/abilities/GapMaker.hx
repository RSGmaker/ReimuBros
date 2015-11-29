package abilities;

/**
 * ...
 * @author RSGmaker
 */
class GapMaker extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Makes holes in platforms";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 90;
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
		/*if (player.ground != null)
		{
			if (player.y<400)
			{
				player.y += 40;
			}
		}*/
		if (player.cooldown <= 0 && player.ground != null && player.ground.type == "Block" && player.ground.solid && player.ground.y<500)
		{
			player.cooldown = player.maxcooldown;
			var E:Dynamic = player.ground;
			//E.Destroy(1400);
			if (player.isme)
			{
			var D:Dynamic = { };
			//D.Destroy = 1400;
			D.Destroy = 60;
			D.UID = player.ground.UID;
			//D.x = player.ground.x;
			//D.y = player.ground.y;
			game.SendEvent("DestroyBlock", D);
			//player.y += 40;
			player.y += 30;
			player.Vspeed += player.fallaccel * 6;
			/*D = { };
			D.x = player.x;
			D.y = player.y + 30;
			D.type = "block";
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
			game.SendPlayerDanmaku(D);*/
			}
		}
	}
}