package;

/**
 * ...
 * @author RSGmaker
 */
class CameraItem extends CarryItem
{
	public function new() 
	{
		super("camera");
		charname = "Camera";
		removeonlevelend = false;
		interactable = true;
		Dropable = false;
		//OffsetX = 12;
		OffsetX = 10;
		OffsetY = 37;
		maxuses = 5;
		itemtype = 2;
		maxcooldown = 450;
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
		super.Use(player);
		game.SendEvent("Camera",null);
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