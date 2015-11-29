package;

/**
 * ...
 * @author RSGmaker
 */
class YinYangOrbItem extends CarryItem
{
	public function new() 
	{
		super("yinyangorb");
		charname = "yinyangorbitem";
		image.image_speed = 0;
		scaleX = 0.3;
		scaleY = scaleX;
		
		removeonlevelend = false;
		canuse = true;
		
		itemtype = 2;
		Dropable = false;
		OffsetX = 12;
		OffsetY = 23;
		maxcooldown = 60;
		
		maxuses = 12;
		uses = maxuses;
	}
	override public function Use(player:Player) 
	{
		super.Use(player);
		
		var D:Dynamic = { };
		D.x = player.x;
		D.y = player.y + 10;
		D.type = "yinyangorb";
		D.scale = 0.4;
		D.dir = player.Ldir;
		D.Vspeed = 2;
		D.HP = 1;
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