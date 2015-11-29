package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Nightmare extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Kills all flipped enemies\non stage";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 750;
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
			player.cooldown = player.maxcooldown;
			var i = 0;
			while (i < game.activeEnemies.length)
			{
				var E:Enemy = game.activeEnemies[i];
				if (E.flipped > 0 && E.invincibility < 1)
				{
					game.SendEvent("Kill", E.UID);
				}
				i++;
			}
			game.FlashColor(0x551A8B, 0.4, 0, 0.1);
		}
	}
}