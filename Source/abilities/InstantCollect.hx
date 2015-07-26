package abilities;

/**
 * ...
 * @author RSGmaker
 */
class InstantCollect extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1000;
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
		if (player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			if (player.isme)
			{
				var i = 0;
				var game = player.game;
				while (i < game.entities.length)
				{
					var E:Dynamic = game.entities[i];
					if (E.type == "Item")
					{
						E.Collect(player);
					}
					i++;
				}
			}
		}
	}
}