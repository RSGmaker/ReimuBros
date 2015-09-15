package;

/**
 * ...
 * @author RSGmaker
 */
class SpellCardItem extends CarryItem
{
	public var ammo:Int;
	public var cooldown:Int;
	private var maxammo:Int = 1;
	public function new() 
	{
		super("spellcard");
		DestroyOnRoundEnd = false;
		interactable = true;
		Dropable = false;
		//OffsetX = 32;
		//OffsetY = 48;
		OffsetX = 12;
		OffsetY = 37;
		ammo = maxammo;
	}
	override public function Collect(player:Player) 
	{
		//super.Collect(player);
		OffsetX = 12;
		OffsetY = 48;
		var ok = false;
		if (player.equipment == null)
		{
			ok = true;
		}
		else if (!player.equipment.alive)
		{
			ok = true;
		}
		if (ok)
		{
			super.Collect(player);
			player.equipment = this;
		}
		else if (player.equipment != null)
		{
			//if (Type.typeof(player.equipment).getName() == Type.typeof(this).getName())
			if (Std.is(player.equipment,SpellCardItem))
			{
				var D:Dynamic = player.equipment;
				var M:SpellCardItem = D;
				if (M.ammo < maxammo)
				{
					M.ammo = maxammo;
					alive = false;
				}
				//killed = true;
				
			}
		}
	}
	override public function update():Void 
	{
		super.update();
		readyinteract = (holder == game.myplayer && cooldown<1);
		interacttext = "Use Spell Card";
		cooldown--;
		if (holder != null && holder.type == "Player")
		{
			OffsetY = holder.height - 20;
		}
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		alive = false;
		killed = true;
	}
	override public function interact(P:Player):Void 
	{
		//super.interact(P);
		if (cooldown > 0)
		{
			return;
		}
		cooldown = 15;
		if (P == holder && P == game.myplayer)
		{
		if (ammo > 0)
		{
			//fire a beam.
			ammo--;
			//var L = new LaserBeam();
			//var X = P.x;
			/*var D:Dynamic = { };
			D.x = x;
			if (P.Ldir < 0)
			{
				D.x -= 800;
			}
			else
			{
				D.x += 13;
			}
			D.y = y;
			D.user = P.UID;
			D.antiplayer = false;
			D.antienemy = true;
			game.SendEvent("LaserBeam",D);*/
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
			game.SendEvent("PlayerDanmaku", D);
			var i = 0;
			D.Vspeed = 1;
			//var P:flash.geom.Point = new flash.geom.Point(0, 0);
			while (i < 4)
			{
				D.Vspeed += 1;
				D.Hspeed -= D.dir;
				game.SendEvent("PlayerDanmaku", D);
				D.Vspeed *= -1;
				game.SendEvent("PlayerDanmaku", D);
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
			game.SendEvent("PlayerDanmaku", D);
			i = 0;
			while (i < 4)
			{
				D.Vspeed += 1;
				D.Hspeed -= -D.dir;
				game.SendEvent("PlayerDanmaku", D);
				D.Vspeed *= -1;
				game.SendEvent("PlayerDanmaku", D);
				D.Vspeed *= -1;
				i++;
			}
			D.Hspeed = 0;
			D.Vspeed = 8;
			game.SendEvent("PlayerDanmaku", D);
			D.Vspeed = -8;
			game.SendEvent("PlayerDanmaku", D);
		}
		if (ammo <= 0)
		{
			//alive = false;
			SendCustomEvent(null);
			//if (holder is Player)
			{
				var D:Dynamic = holder;
				var P:Player = D;
				P.equipment = null;
			}
		}
		}
	}
}