package abilities;

/**
 * ...
 * @author RSGmaker
 */
class TileDanmaku extends PlayerAbility
{
	//public var destroytime:Int = 1300;
	public var destroytime:Int = 100;
	public function new(player:Player) 
	{
		super(player);
		description = "Throws blocks";
	}
	override public function init() 
	{
		super.init();
		//player.maxcooldown = 150;
		player.maxcooldown = 500;
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
		if (player.cooldown <= 0 && player.ground != null && player.ground.type == "Block" && player.ground.solid && player.ground.y<500)
		{
			player.cooldown = player.maxcooldown;
			var E:Dynamic = player.ground;
			//E.Destroy(1400);
			if (player.isme)
			{
			var D:Dynamic = { };
			//D.Destroy = 1400;
			//D.Destroy = 1300;
			D.Destroy = destroytime;
			D.UID = player.ground.UID;
			//D.x = player.ground.x;
			//D.y = player.ground.y;
			game.SendEvent("DestroyBlock", D);
			D = { };
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
			game.SendPlayerDanmaku(D);
			}
		}
	}
}