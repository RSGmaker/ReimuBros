package abilities;

/**
 * ...
 * @author RSGmaker
 */
class AngelOfDeath extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Enemies may die randomly";
	}
	override public function onframe() 
	{
		super.onframe();
		if (player.isme)
		{
			if (Math.random() < 0.00125)
			{
				var game = player.game;
				var enemy = game.activeEnemies[Math.floor(game.activeEnemies.length * Math.random())];
				if (enemy != null && enemy.invincibility <= 0 && enemy.alive && !enemy.killed)
				{
					game.SendEvent("Attack", enemy.UID);
				}
			}
		}
	}
}