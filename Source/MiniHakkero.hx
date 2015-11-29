package;
import abilities.AbsorbDamage;
import openfl.geom.Rectangle;
/**
 * ...
 * @author RSGmaker
 */
class MiniHakkero extends CarryItem
{
	public function new() 
	{
		super("minihakkero");
		charname = "MiniHakkero";
		removeonlevelend = false;
		canuse = true;
		
		itemtype = 2;
		Dropable = false;
		OffsetX = 12;
		OffsetY = 37;
		maxcooldown = 70;
	}
	override public function Use(player:Player) 
	{
		super.Use(player);
		
		var D:Dynamic = { };
		D.x = -8;
		D.y = y-player.y;
		D.user = player.UID;
		D.antiplayer = false;
		D.antienemy = true;
		game.SendEvent("LaserBeam",D);
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