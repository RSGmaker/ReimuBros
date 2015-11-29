package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class BossArena extends ArenaLogic
{

	public function new() 
	{
		super();
		
	}
	override public function tick() 
	{
		//super.tick();
		var SpawnList = game.SpawnList;
		var RoundType = game.RoundType;
		if (SpawnList.length > 1)
		{
			game.ResetSpawnTimer();
		}
			
		if (!SpawnList.isEmpty())
		{
			DoSpawn();
		}
		else
		{
			var count = game.getenemycount();
			if (count < 1)
			{
				gotonextlevel();
			}
			else if (game.boss != null && count==1)
			{
				game.boss.outofminions();
			}
		}
	}
}