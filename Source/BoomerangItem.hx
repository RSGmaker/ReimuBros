package;

/**
 * ...
 * @author RSGmaker
 */
class BoomerangItem extends CarryItem
{
	public function new() 
	{
		super("Boomerang");
		image.image_speed = 0;
		
		removeonlevelend = false;
		canuse = true;
		
		itemtype = 2;
		Dropable = false;
		OffsetX = 12;
		OffsetY = 37;
		maxcooldown = 70;
		
		maxuses = 6;
		uses = maxuses;
	}
	override public function Use(player:Player) 
	{
		super.Use(player);
		
		var D:Dynamic = { };
		D.x = player.x;
		//D.y = player.y + 10;
		D.y = player.y + OffsetY;
		D.type = "Boomerang";
		D.spin = true;
		D.scale = 1;
		D.dir = player.Ldir;
		D.Vspeed = 0;
		D.HP = 999999;
		D.gravX = -0.5;
		D.image_speed = 2;
		if (player.Ldir >= 0)
		{
			D.Hspeed = 18;
		}
		else
		{
			D.Hspeed = -18;
			D.gravX = -D.gravX;
		}
		
		D.gravY = 0;
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
			OffsetY = holder.height - 52;
		}
	}
}