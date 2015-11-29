package;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class Bow extends CarryItem
{
	public function new() 
	{
		super("Bow");
		charname = "Bow";
		removeonlevelend = false;
		canuse = true;
		
		itemtype = 2;
		Dropable = false;
		OffsetX = 12;
		OffsetY = 37;
		maxcooldown = 60;
	}
	override public function Use(player:Player) 
	{
		super.Use(player);
		
		var D:Dynamic = { };
		D.x = player.x;
		D.y = player.y + 25;
		D.type = "Arrow";
		D.scale = 1;
		D.dir = player.Ldir;
		D.Vspeed = 0;
		D.HP = 1;
		if (player.Ldir >= 0)
		{
			D.Hspeed = 30;
		}
		else
		{
			D.Hspeed = -30;
			//D.type = "ArrowF";
		}
		D.gravX = 0;
		D.gravY = 0;
		D.wrap = false;
		D.bounces = false;
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
			//OffsetY = holder.height - 20;
			OffsetY = holder.height - 45;
			if (holder.Ldir >= 0)
			{
				OffsetX = 12;
				ChangeAnimation(charname);
			}
			else
			{
				OffsetX = -12;
				ChangeAnimation(charname+"F");
			}
		}
	}
}