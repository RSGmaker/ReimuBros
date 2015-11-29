package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class PointCollectingLogic extends LevelLogic
{
	//public var progress:Float = 0.5;
	public var progress:Float = 0.3;
	public var lprogress:Float = 0.5;
	public var increment:Float = 0.05;
	
	//time before next reimu spawns.
	public var reimutimer:Int;
	
	public var totalreimus:Int;
	public var maxreimus:Int = 3;
	public function new() 
	{
		super();
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		if (data.type == "progress")
		{
			progress = data.progress;
		}
	}
	override public function updateprogressbar():Float 
	{
		return progress;
		//return super.updateprogressbar();
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
		//game.maxyuuka = 1;
		game.maxyuuka = 0;
	}
	override public function update() 
	{
		//super.update();
		
		if (game.Hoster)
		{
		if (game.activeEnemies.length == 0)
		{
			//spawn a reimu
			var D:Dynamic = { };
			D.type = "Reimu";
			D.UID = Math.random();
			if (Math.random() > 0.5)
			{
				D.x = 800;
				D.Ldir = -1;
			}
			else
			{
				D.x = -16;
				D.Ldir = 1;
			}
			D.y = -100;
			D.alive = true;
			D.Hspeed = 0;
			D.Vspeed = 0;
			D.enraged = false;
			D.visible = true;
			D.rank = game.rank;
			D.spawns = 0;
			game.SendEvent("SpawnEnemy", D);
		}
		totalreimus = 0;
		var i = 0;
		while (i < game.activeEnemies.length)
		{
			var E:Enemy = game.activeEnemies[i];
			if (Std.is(E, Reimu))
			{
				totalreimus++;
				/*var D:Dynamic = E;
				var R:Reimu = D;
				if (R.collected > 0)
				{
					progress -= (R.collected * increment);
				}*/
			}
			i++;
		}
		i = 0;
		var greedenabled = false;
		/*while (i < game.activeItems.length)
		{
			var E = game.activeItems[i];
			if (Std.is(E, PointItem))
			{
				greedenabled = true;
			}
			i++;
		}*/
		greedenabled = true;
		if (greedenabled)
		{
		reimutimer--;
		if (totalreimus < 1)
		{
			reimutimer--;
		}
		if (reimutimer < 1 && totalreimus< maxreimus)
		{
			reimutimer = 120;
			var D:Dynamic = { };
			D.type = "Reimu";
			D.UID = Math.random();
			if (Math.random() > 0.5)
			{
				D.x = 800;
				D.Ldir = -1;
			}
			else
			{
				D.x = -16;
				D.Ldir = 1;
			}
			D.y = 450;
			D.alive = true;
			D.Hspeed = 0;
			D.Vspeed = 0;
			D.enraged = false;
			D.visible = true;
			D.rank = game.rank;
			D.spawns = 0;
			game.SendEvent("SpawnEnemy", D);
		}
		}
		if (progress != lprogress)
		{
			lprogress = progress;
			var D:Dynamic = { };
			D.type = "progress";
			D.progress = progress;
		}
		if (progress >= 1)
		{
			//game.ResetSpawnTimer();
			gotonextlevel();
		}
		else if (progress <= 0)
		{
			//game.ResetSpawnTimer();
			game.SendEvent("Mission Failed", null);
		}
		}
	}
	override public function OnProcessEvent(evt:String, P:Player, data:Dynamic):Bool 
	{
		if (evt == "Collect")
		{
			if (P != null)
			{
				if (data < 0)
				{
					progress -= (increment*1.5);
				}
				else
				{
					var D:Dynamic = game.EntityFromUID(data);
					if (D != null && D.alive)
					{
						progress += increment;
					}
				}
			}
		}
		if (evt == "AttachItem")
		{
			return true;
		}
		return false;
		//return super.OnProcessEvent(evt, P, data);
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
		/*if (progress >= 1)
		{
			game.ResetSpawnTimer();
			gotonextlevel();
		}
		else if (progress <= 0)
		{
			game.ResetSpawnTimer();
			game.SendEvent("Mission Failed", null);
		}*/
		if (SpawnList.length < 2)
		{
			game.populatespawnlist();
		}
		if (!SpawnList.isEmpty())
		{
			DoSpawn();
		}
		/*else
		{
			var count = game.getenemycount();
			if (count < 1)
			{
				gotonextlevel();
			}
		}*/
	}
	
}