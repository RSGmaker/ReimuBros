package;

/**
 * ...
 * @author RSGmaker
 */
class Roukanken extends CarryItem
{
	public function new() 
	{
		super("Roukanken");
		charname = "Roukanken";
		removeonlevelend = false;
		interactable = true;
		Dropable = false;
		OffsetX = 25;
		//OffsetY = 0;
		OffsetY = -3;
		maxuses = 9;
		itemtype = 2;
		maxcooldown = 150;
		canuse = true;
		uses = maxuses;
		if (game.RoundType == GameView.TypeofRound.EventDanmaku)
		{
			uses = 2;
			maxuses = 2;
		}
	}
	override public function Use(player:Player) 
	{
		if ((player.x > 700 && player.Ldir > 0) || (player.x < 100 && player.Ldir < 0))
		{
			return;
		}
		super.Use(player);
		var D:Dynamic = { };
		D.x = -20;
		if (player.Ldir < 0)
		{
			//D.x -= 800;
		}
		///D.y = 32;
		D.x = player.x - 20;
		D.y = player.y + 32;
		if (player.Ldir < 0)
		{
			D.x -= 800;
		}
		//D.user = P.UID;
		D.antiplayer = false;
		D.antienemy = true;
		D.color = 0xFFFFFF;
		//D.user = UID;
		//if (game.Hoster)
		if (player.isme)
		{
			game.SendEvent("LaserBeam", D);
		}
		if (player.Ldir > 0)
		{
			player.x = 770;
		}
		if (player.Ldir < 0)
		{
			player.x = 20;
		}
		if (player.invincibility < 90)
		{
			player.invincibility = 90;
		}
		//game.SendEvent("Camera",null);
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
			OffsetX = 30;
			OffsetY = holder.height - 58;
		}
	}
}