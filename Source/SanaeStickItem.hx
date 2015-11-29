package;

/**
 * ...
 * @author RSGmaker
 */
class SanaeStickItem extends CarryItem
{
	public function new() 
	{
		super("SanaeStick");
		image.image_speed = 0;
		
		removeonlevelend = false;
		canuse = true;
		
		itemtype = 2;
		Dropable = false;
		OffsetX = 12;
		OffsetY = 37;
		maxcooldown = 70;
		
		maxuses = 10;
		uses = maxuses;
	}
	override public function Use(player:Player) 
	{
		super.Use(player);
		
		var D:Dynamic = { };
		D.x = player.x;
		D.y = player.y + 0;
		D.type = "starbulletg";
		D.scale = 1;
		D.dir = player.Ldir;
		D.Vspeed = player.Vspeed;
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
	override public function Collect(player:Player) 
	{
		super.Collect(player);
		OffsetX = 12;
		OffsetY = 48;
	}
	override public function update():Void 
	{
		super.update();
		if (holder != null && holder.type == "Player")
		{
			OffsetY = holder.height - 20;
		}
	}
}