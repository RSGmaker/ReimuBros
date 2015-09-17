package;
import abilities.AbsorbDamage;

/**
 * ...
 * @author RSGmaker
 */
class MiniHakkero extends CarryItem
{
	public var ammo:Int;
	public var cooldown:Int;
	private var maxammo:Int = 5;
	public function new() 
	{
		super("minihakkero");
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
			if (Std.is(player.equipment,MiniHakkero))
			{
				var D:Dynamic = player.equipment;
				var M:MiniHakkero = D;
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
		interacttext = "Energy:" + ammo;
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
			var D:Dynamic = { };
			/*D.x = x;
			if (P.Ldir < 0)
			{
				D.x -= 800;
			}
			else
			{
				D.x += 13;
			}*/
			D.x = -8;
			D.y = y-P.y;
			D.user = P.UID;
			D.antiplayer = false;
			D.antienemy = true;
			game.SendEvent("LaserBeam",D);
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