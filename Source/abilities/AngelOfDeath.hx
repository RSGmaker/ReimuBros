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
		description = "enemies may die\nat random";
	}
	override public function onframe() 
	{
		super.onframe();
		if (player.isme)
		{
			if (Math.random() < 0.0025)
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