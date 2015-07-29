package;

/**
 * ...
 * @author RSGmaker
 */
class TrophyItem extends CarryItem
{
	public var timer:Int;
	public var started:Bool;
	public var twuck:Bool;
	public var spawned:Bool;
	public function new() 
	{
		super("trophy");
		game.trophyactive = true;
		started = false;
		twuck = false;
	}
	override public function Collect(player:Player) 
	{
		//prevent someone camping on pow block from grabbing it.
		//if (player.y < y || x != 400)
		if (player.y < y || Math.abs(400-x) > 64)
		{
			super.Collect(player);
			if (twuck && !spawned)
			{
				spawned = true;
				if (player.isme)
				{
					//game.SendEvent("SpawnHunters", null);
					game.ProcessEvent("SpawnHunters", "Myself", null);
				}
			}
		}
	}
	override public function update():Void 
	{
		super.update();
		if (!started)
		{
			if (UID < 0.1)
			{
				ChangeAnimation("truck");
				twuck = true;
			}
			started = true;
		}
		if (spawned)
		{
			despawntime = maxdespawntime;
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