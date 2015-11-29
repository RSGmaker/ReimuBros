package abilities;

/**
 * ...
 * @author RSGmaker
 */
class DollMaker extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Creates shanghai dolls";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 2400;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0)
		{
			//player.cooldown = player.maxcooldown;
			var i = 0;
			var count = 0;
			while (i < game.activeItems.length)
			{
				var E = game.activeItems[i];
				if (E.alive && E.subtype == "Myon")
				{
					var D:Dynamic = E;
					if (D.holder == player)
					{
						count++;
					}
				}
				i++;
			}
			if (count < 2)
			{
				player.cooldown = player.maxcooldown;
				var D:Dynamic = { };
				D.UID = player.UID;
				D.type = "shanghai";
				D.scale = 0.6;
				game.SendEvent("AttachZombieFairy", D);
			}
			else
			{
				player.message = "Doll limit reached";
				player.messagetime = 60;
			}
		}
	}
}