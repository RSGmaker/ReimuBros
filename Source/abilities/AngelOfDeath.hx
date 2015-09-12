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
<<<<<<< HEAD
			//if (Math.random() < 0.00125)
			if (Math.random() < 0.0008)
=======
			if (Math.random() < 0.0025)
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
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