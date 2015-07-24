package;

/**
 * ...
 * @author RSGmaker
 */
class TrophyItem extends CarryItem
{
	public var timer:Int;
	public var started:Bool;
	public function new() 
	{
		super("trophy");
		game.trophyactive = true;
		started = false;
	}
	override public function Collect(player:Player) 
	{
		//prevent someone camping on pow block from grabbing it.
		if (player.y < y || x != 400)
		{
			super.Collect(player);
		}
	}
	override public function update():Void 
	{
		super.update();
		if (!started)
		{
			if (UID < 0.5)
			{
				ChangeAnimation("truck");
			}
			started = true;
		}
		if (holder != null && holder.type == "Player" && holder == game.myplayer)
		{
			if (holder.ground != null && holder.ground.type == "PowBlock")
			{
				timer++;
				if (timer > 120)
				{
					visible = !visible;
				}
				if (timer > 240)
				{
					game.SendEvent("Destroy", UID);
				}
			}
			else
			{
				timer = 0;
				visible = true;
			}
		}
	}
	public override function Death() 
	{
		if (holder.type == "Player")
		{
			var D:Dynamic = holder;
			D.score += 5000;
		}
	}
}