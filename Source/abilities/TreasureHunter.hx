package abilities;

/**
 * ...
 * @author RSGmaker
 */
class TreasureHunter extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "May find hidden items\ninside blocks (resets\neach level)";
	}
	override public function onheadbonk() 
	{
		super.onheadbonk();
		//
		//if (game.Hoster)
		if (player.isme)
		{
			var headbonk:Dynamic = player.headbonk;
			if (headbonk != null && headbonk.type == "Block")
			{
				var B:Block = headbonk;
				//if (!B.searched && !game.trophyactive && Math.random()>0.98)
				if (!B.searched && !game.trophyactive && Math.random()>0.97)
				{
					var D:Dynamic = { };
					var items:Array<String> = ["Trophy","MiniHakkero", "Camera","SpellCard"];
					//D.type = "Trophy";
					///D.type = items[Std.int(Math.random() * items.length)];
					D.type = EntityItem.getitem("list:valuable");
					D.UID = Math.random();
					D.x = B.x;
					D.y = B.y-64;
					game.SendEvent("SpawnItem", D);
				}
				B.searched = true;
			}
		}
	}
}