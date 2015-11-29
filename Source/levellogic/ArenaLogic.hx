package levellogic;

/**
 * The basic logic for classic mode.
 * @author RSGmaker
 */
class ArenaLogic extends LevelLogic
{

	public function new() 
	{
		super();
		
	}
	override public function start() 
	{
		super.start();
		if (game.platformformation != 0)
		{
			game.platformformation = 0;
			game.setformation();
		}
		game.ResetScroll();
		game.allowpowblock = true;
		game.powblock.solid = true;
		game.powblock.visible = true;
		game.maxyuuka = 1;
	}
	override public function update() 
	{
		//super.update();
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
		}
	}
	
}