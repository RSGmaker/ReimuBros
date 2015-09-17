package;

/**
 * ...
 * @author RSGmaker
 */
class CameraItem extends CarryItem
{
	public var ammo:Int;
	public var cooldown:Int;
	private var maxammo:Int = 7;
	public function new() 
	{
		super("camera");
		DestroyOnRoundEnd = false;
		interactable = true;
		Dropable = false;
		//OffsetX = 32;
		//OffsetY = 48;
		OffsetX = 12;
		OffsetY = 37;
		ammo = maxammo;
		if (game.RoundType == GameView.TypeofRound.Danmaku)
		{
			ammo = 2;
			maxammo = 2;
		}
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
			if (Std.is(player.equipment,CameraItem))
			{
				var D:Dynamic = player.equipment;
				var M:CameraItem = D;
				if (M.maxammo < maxammo)
				{
					M.maxammo = maxammo;
				}
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
		interacttext = "Film:" + ammo;
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
			ammo--;
			//remove all bullets on screen.
			game.SendEvent("Camera",null);
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