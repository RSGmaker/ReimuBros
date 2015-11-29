package;

/**
 * ...
 * @author RSGmaker
 */
class SpellCardItem extends CarryItem
{
	public function new() 
	{
		super("spellcard");
		charname = "SpellCard";
		removeonlevelend = false;
		interactable = true;
		Dropable = false;
		OffsetX = 12;
		OffsetY = 37;
		canuse = true;
		itemtype = 2;
		maxcooldown = 500;
		maxuses = 2;
		uses = maxuses;
	}
	override public function Use(player:Player) 
	{
		super.Use(player);
		var P:Player = player;
		var spd = 8;
			var D:Dynamic = { };
			D.x = P.x;
			D.y = P.y + 30;
			D.type = "starbullety";
			D.scale = 1;
			D.dir = P.Ldir;
			D.Vspeed = 0;
			if (P.Ldir >= 0)
			{
				D.Hspeed = spd;
			}
			else
			{
				D.Hspeed = -spd;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendPlayerDanmaku(D);
			var i = 0;
			D.Vspeed = 1;
			//var P:flash.geom.Point = new flash.geom.Point(0, 0);
			while (i < 4)
			{
				D.Vspeed += 1;
				D.Hspeed -= D.dir;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				i++;
			}
			if (P.Ldir >= 0)
			{
				D.Hspeed = spd;
			}
			else
			{
				D.Hspeed = -spd;
			}
			D.Hspeed = -D.Hspeed;
			D.Vspeed = 0;
			game.SendPlayerDanmaku(D);
			i = 0;
			while (i < 4)
			{
				D.Vspeed += 1;
				D.Hspeed -= -D.dir;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				i++;
			}
			D.Hspeed = 0;
			D.Vspeed = 8;
			game.SendPlayerDanmaku(D);
			D.Vspeed = -8;
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