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
	public var preventdespawn:Bool;
	public function new() 
	{
		super("trophy");
		game.trophyactive = true;
		started = false;
		twuck = false;
		autocollect = true;
	}
	override public function Collect(player:Player) 
	{
		//prevent someone camping on pow block from grabbing it.
		//if (player.y < y || x != 400)
		player.ChangeExpression("Mouth", "32", 80, true);
		player.ChangeExpression("Eyes", "4", 80, false);
		if (game.GameFlags.get(Main.TruckHoarder))
		{
			game.spawnpaused = false;
		}
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
			if ((UID < 0.22 && game.level>15 && game.RoundType.getName() == "Normal") || game.GameFlags.get(Main.TruckHoarder))
			{
				ChangeAnimation("truck");
				autocollect = false;
				interacttext = "Claim truck...";
				//interacttext = interacttext+"...";
				twuck = true;
				if (game.GameFlags.get(Main.TruckHoarder))
				{
					preventdespawn = true;
				}
			}
			started = true;
		}
		if (spawned)
		{
			despawntime = maxdespawntime;
		}
		if (preventdespawn)
		{
			despawntime = maxdespawntime;
		}
		if (holder != null && holder.type == "Player")
		{
			autocollect = true;
			if (holder == game.myplayer)
			{
			if (holder.ground == null || holder.ground.type == "PowBlock")
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
	}
	public override function Death() 
	{
		if (holder!=null && holder.type == "Player")
		{
			var D:Dynamic = holder;
			D.score += 5000;
			if (twuck)
			{
				D.score += 5000;
				if (game.myplayer == holder)
				{
					game.unlockcharacter("mokou");
					game.unlockcharacter("kaguya");
					if (!Main._this.savedata.data.challenges[2])
					{
						game.ShowMessage("Truck Hoarder challenge");
						game.ShowMessage("is now available!");
						Main._this.savedata.data.challenges[2] = true;
					}
				}
			}
		}
	}
}