package;

/**
 * Controls how the level/round plays out,
 * the levellogic is responsible for activating spawns and telling the game when the conditions have been met to start the next level.
 * @author RSGmaker
 */
class LevelLogic
{
	//make a version of this that will take over most of the enemy spawn mechanics, and tells gameview when the level is over, maybe it should also control the progress bar as well.
	
	public var game:GameView;
	public var started:Bool;
	public var horizontalscrolling:Bool;
	public var verticalscrolling:Bool;
	public var maxspawn_modifier:Float=1.0;
	//public var started:Bool;
	public function new() 
	{
		game = GameView._this;
	}
	//when level starts(spawn special objects at this point)
	public function start()
	{
		
	}
	//runs at level start if this is the hoster.
	public function hosterstart()
	{
		
	}
	//when the level ends(remove special objects,and etc)
	public function end()
	{
		
	}
	public function SendCustomEvent(data:Dynamic)
	{
		var D:Dynamic = { };
		//D.UID = UID;
		D.data = data;
		game.SendEvent("CustomLVLEvent", D);
	}
	public function CustomEvent(data:Dynamic)
	{
		
	}
	//when a event message is sent it is captured here, returing true prevents gameview from processing the event itself.
	public function OnProcessEvent(evt:String, P:Player, data:Dynamic):Bool
	{
		return false;
	}
	//edit epm, maxspawns and setspawnlist
	public function CalculateLevelData(level:Int)
	{
		var SpawnList = game.SpawnList;
		SpawnList.clear();
		game.updatelevelinfo();
		var spawnrate:Float;
		var rank:Int;
		var epm:Float;
		var enemytypes:Array<Enemy>;
		var maxspawns:Int;
		var Obstacles:Array<String>;
		var GameFlags = game.GameFlags;
		var RoundType = game.RoundType;
		
		
		
		
		/*var L = level - 1;
		var stage = Math.floor((L) / 5);

		var generalstage = stage % 6;*/
		var stage = game.currentstage;
		var generalstage = game.currentgeneralstage;
		var L = level - 1;
		if (L < 0)
		{
			L = 0;
		}
		spawnrate = 1.0;
		//rank = Math.floor(L / 30);
		rank = game.rank;
		L -= rank * Std.int(GameView.levelsperstage*0.45);
		//calculate available budget for this level
		var tpoints:Float = (L + 2);
		var points:Float = tpoints;// * 2.0;
		//points *= 1.1;
		//points += ((level-1) % 5);
		/*var lvl = ((level - 1) % 5);
		lvl++;*/
		var lvl = game.currentstagelevel;
		points += lvl;
		
		//points *= 1.35;
		//points *= 1.2;
		epm = 0;
		var R = 0.2 + (Math.random() * 0.2);
		R = R * points;
		var AR = R;
		var tmp = 0.7;
		while (AR > 1)
		{
			spawnrate *= 0.96;
			//spawnrate *= 0.965;
			///tmp *= 1.4;
			tmp *= 1.3;
			if (tmp < 1)
			{
				tmp = 1;
			}
			AR -= tmp;
		}
		points -= R;
		//calculate percentage of budget will be spent on events(a.k.a. obstacles).
		R = 0.4 + (Math.random() * 0.2);//; (points * 0.7);
		R = R * points;
		AR = R;
		while (AR > 1)
		{
			epm++;
			//tmp = (epm * 0.2);
			tmp = (epm * 0.18);
			if (tmp < 1)
			{
				tmp = 1;
			}
			AR -= tmp;
		}
		//remove part of budget spent on increasing epm(obstacles per minute).
		points -= R;
		//count number of players(since it doesnt have a .length property :/ )
		var A = game.Players.keys();
		var P = 0;
		while (A.hasNext())
		{
			A.next();
			P+=1;
		}
		var EVT = Math.random();
		var LV:Int = level;
		while (LV >= 30)
		{
			LV -= 30;
		}
		//if (level == 9)
		if (LV == 9)
		{
			//double chance of event
			//EVT *= 0.25;
			EVT *= 0.1;
		}
		//RoundType = GameView.TypeofRound.EventNormal;
		enemytypes = new Array<Enemy>();
		//points *= 1.35;
		//maxspawns = Math.ceil(points*0.85) + (P) + 1;
		var oms = Math.ceil(points) + (P) + 1;
		var MS:Float = (((game.currentranklevel+2)*(points / tpoints)) * 0.85)+rank+(P*0.5) + 1;
		//maxspawns = Math.ceil((((game.currentranklevel+2)*(points / tpoints)) * 0.85)+rank+(P*0.5)) + 1;
		maxspawns = Math.ceil(MS * maxspawn_modifier);
		Obstacles = new Array<String>();
		var T = level % 5;
		
		if (T == 0)
		{
			EVT = 0;
		}
		if (GameFlags.get(Main.EventRoundsOnly))
		{
			EVT = 0;
		}
		/*if (EVT < 0.05)
		{
			var E:Array<TypeofRound> = new Array<TypeofRound>();
			if (level != 9 || GameFlags.get(Main.EventRoundsOnly))
			{
				var BossRush = GameFlags.get(Main.Bossrush);
				if (!BossRush)
				{
				E[E.length] = GameView.TypeofRound.EventRumia;
				E[E.length] = GameView.TypeofRound.EventTable;
				E[E.length] = GameView.TypeofRound.EventCirno;
				E[E.length] = GameView.TypeofRound.EventBalloon;
				E[E.length] = GameView.TypeofRound.EventCharacters;
				if (level >= 11 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = GameView.TypeofRound.EventNue;
				}
				if (level > 5 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = GameView.TypeofRound.EventSeija;
					E[E.length] = GameView.TypeofRound.EventMarisa;
				}
				if (level > 15 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = GameView.TypeofRound.EventFireCirno;
					E[E.length] = GameView.TypeofRound.EventNoWrap;
				}
				if (level > 20 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = GameView.TypeofRound.EventYukari;
				}
				if (level > 50 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = GameView.TypeofRound.EventElectricCirno;
				}
				}
				else
				{
					E[E.length] = GameView.TypeofRound.EventYukari;
				}
				if ((level > 30) || GameFlags.get(Main.EventRoundsOnly) || BossRush)
				{
					if (generalstage == 0 || BossRush)
					{
						E[E.length] = GameView.TypeofRound.EventSanaeBoss;
					}
					if (generalstage == 3 || BossRush)
					{
						E[E.length] = GameView.TypeofRound.EventParseeBoss;
					}
					if (generalstage == 4 || BossRush)
					{
						E[E.length] = GameView.TypeofRound.EventMurasaBoss;
					}
					if (BossRush)
					{
						E[E.length] = GameView.TypeofRound.EventCirnoBoss;
					}
				}
			}
			else
			{
				E[E.length] = GameView.TypeofRound.EventCirno;
			}
			RoundType = E[(Math.floor(Math.random() * E.length))];
			
			if (level > 30 && LV == 9 && !GameFlags.get(Main.EventRoundsOnly))
			{
				RoundType = GameView.TypeofRound.EventCirnoBoss;
			}
		}
		//RoundType = GameView.TypeofRound.EventParseeBoss;
		//RoundType = GameView.TypeofRound.EventSeija;
		//RoundType = GameView.TypeofRound.EventMarisa;
		//RoundType = GameView.TypeofRound.EventNoWrap;
		
		
		
		var Ev:Array<TypeofRound> = new Array<TypeofRound>();
		if (GameFlags.get(Main.TableEvent))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventTable;
		}
		if (GameFlags.get(Main.CirnoEvent))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventCirno;
		}
		if (GameFlags.get(Main.FireCirno))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventFireCirno;
		}
		if (GameFlags.get(Main.ElectricCirno))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventElectricCirno;
		}
		if (GameFlags.get(Main.NueEvent))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventNue;
		}
		if (GameFlags.get(Main.BalloonEvent))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventBalloon;
		}
		if (GameFlags.get(Main.YukariEvent))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventYukari;
		}
		if (GameFlags.get(Main.Danmaku))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventDanmaku;
		}
		if (GameFlags.get(Main.SanaeBoss))
		{
			Ev[Ev.length] = GameView.TypeofRound.EventSanaeBoss;
		}
		if (Ev.length > 0)
		{
			RoundType = Ev[Math.floor(Math.random() * Ev.length)];
		}
		if (GameFlags.get(Main.NoEvents))
		{
			RoundType = GameView.TypeofRound.EventNormal;
		}*/
		//setup obstacles.
		
		//--basic obstacles--
		if ([GameView.TypeofRound.EventNormal,GameView.TypeofRound.EventRumia,GameView.TypeofRound.EventTable,GameView.TypeofRound.EventBalloon,GameView.TypeofRound.EventCharacters,GameView.TypeofRound.EventNoWrap,GameView.TypeofRound.EventScrolling,GameView.TypeofRound.EventDescending,GameView.TypeofRound.EventTruck,GameView.TypeofRound.EventSuwako,GameView.TypeofRound.EventPointCollecting,GameView.TypeofRound.EventSoccer].indexOf(RoundType)>-1)
		{
			if (stage>0)
			{
				//AddToArrayMultiple(Obstacles, "Cirno", 64);
				AddToArrayMultiple(Obstacles, "Cirno", 50);
				AddToArrayMultiple(Obstacles, "MrGhosty", 32);
			}
			AddToArrayMultiple(Obstacles, "Gap", 70);
			//AddToArrayMultiple(Obstacles, "Yinyangorb", 12); 
			AddToArrayMultiple(Obstacles, "Yinyangorb", 14); 
			/////AddToArrayMultiple(Obstacles, "MiniPowBlock", 2);
			AddToArrayMultiple(Obstacles, "Nitori", 2);
			if (stage>1)
			{
				AddToArrayMultiple(Obstacles, "UFO", 32);
			}
			{
				AddToArrayMultiple(Obstacles, "GiantSuika", 2);
				AddToArrayMultiple(Obstacles, "Trophy", 3);
			}
			if (stage>2 && RoundType != GameView.TypeofRound.EventDescending)
			{
				AddToArrayMultiple(Obstacles, "Yuuka", 5);
			}
			if (stage>3)
			{
				if (RoundType != GameView.TypeofRound.EventPointCollecting)
				{
					AddToArrayMultiple(Obstacles, "Reimu", 5);
				}
				AddToArrayMultiple(Obstacles, "UnzanFist", 12);
			}
			if (stage>4)
			{
				AddToArrayMultiple(Obstacles, "Iku", 3);
			}
			if (level > 30)
			{
				AddToArrayMultiple(Obstacles, "Lily White", 1);
			}
		}
		/*if (RoundType == GameView.TypeofRound.EventPointCollecting)
		{
			//AddToArrayMultiple(Obstacles, "Reimu", 250);
			AddToArrayMultiple(Obstacles, "Reimu", 180);
			epm += 2;
			//epm += 8;
			//maxspawns += Std.int(maxspawns / 2);
			//epm = 22;
			//epm += epm;
		}*/
		if (RoundType == GameView.TypeofRound.EventYuuka)
		{
			AddToArrayMultiple(Obstacles, "Yuuka", 5);
			maxspawns += Std.int(maxspawns / 2);
			epm = 22;
			//epm += epm;
		}
		/*if (GameFlags.get(Main.TruckHoarder))
		{
			game.spawnpaused = true;
			var D:Dynamic = { };
			D.type = "Trophy";
			D.UID = Math.random();
			D.x = 400;
			D.y = -100;
			game.SendEvent("SpawnItem", D);
		}*/
		if (RoundType == GameView.TypeofRound.EventDanmaku)
		{
			game.ufolimit = 10;
			AddToArrayMultiple(Obstacles, "Gap", 60);
			AddToArrayMultiple(Obstacles, "UFO", 32);
			AddToArrayMultiple(Obstacles, "UnzanFist", 12);
			AddToArrayMultiple(Obstacles, "Yuuka", 4);
			AddToArrayMultiple(Obstacles, "Yinyangorb", 7);
			epm *= 1.5;
		}
		if (RoundType == GameView.TypeofRound.EventNue)
		{
			Obstacles[Obstacles.length] = "UFO";
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
		}
		if (RoundType == GameView.TypeofRound.EventYukari)
		{
			Obstacles[Obstacles.length] = "Gap";
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
			epm *= 0.75;
		}
		if (RoundType == GameView.TypeofRound.EventBalloon)
		{
			AddToArrayMultiple(Obstacles, "Balloon", Math.round(Obstacles.length * 2));
			epm *= 2.5;
		}
		if ([GameView.TypeofRound.EventCirno,GameView.TypeofRound.EventFireCirno,GameView.TypeofRound.EventElectricCirno,GameView.TypeofRound.EventCirnoBoss].indexOf(RoundType)>-1)
		{
			AddToArrayMultiple(Obstacles, "Cirno", 8);
			if (RoundType == GameView.TypeofRound.EventCirno)
			{
				AddToArrayMultiple(Obstacles, "GiantSuika", 1);
			}
			AddToArrayMultiple(enemytypes, new Imposter(), 1);
			if (RoundType == GameView.TypeofRound.EventFireCirno)
			{
				epm += 7;
			}
			else
			{
				epm += 2;
			}
			//SpawnTimer = 240 + (maxspawns * 30);
			if (GameFlags.get(Main.EventRoundsOnly))
			{
			if (GameFlags.get(Main.CirnoEvent))
			{
				maxspawns += 9;
			}
			else
			{
				if (!(RoundType == GameView.TypeofRound.EventFireCirno || RoundType == GameView.TypeofRound.EventElectricCirno || RoundType == GameView.TypeofRound.EventCirnoBoss))
				{
					maxspawns = 9;
				}
			}
			}
			//SendEvent("FreezeWorld", null);
		}
		//setup enemytypes.
		
		if (RoundType == GameView.TypeofRound.EventRumia)
			{
				AddToArrayMultiple(enemytypes, new Rumia(), 125);
				AddToArrayMultiple(enemytypes, new Imposter(), 3);
			}
			if (RoundType == GameView.TypeofRound.EventSeija)
			{
				AddToArrayMultiple(enemytypes, new Seija(), 62);
				AddToArrayMultiple(enemytypes, new Imposter(), 3);
			}
		//AddToArrayMultiple(enemytypes, new Hina(), 500);
		//AddToArrayMultiple(enemytypes, new Sakuya(), 500);
		//AddToArrayMultiple(enemytypes, new Youmu(), 500);
		//AddToArrayMultiple(enemytypes, new Aya(), 500);
		//AddToArrayMultiple(enemytypes, new Orin(), 500);
		//AddToArrayMultiple(enemytypes, new Suwako(), 500);
		//AddToArrayMultiple(enemytypes, new Sekibanki(), 500);
		//AddToArrayMultiple(enemytypes, new Alice(), 500);
		//AddToArrayMultiple(enemytypes, new MagiFairy(), 500);
		//AddToArrayMultiple(enemytypes, new Eirin(), 500);
		//AddToArrayMultiple(enemytypes, new Letty(), 500);
		//AddToArrayMultiple(enemytypes, new Yoshika(), 500);
		//AddToArrayMultiple(enemytypes, new Wriggle(), 500);
		//AddToArrayMultiple(enemytypes, new Mamizou(), 500);
		//if (RoundType == GameView.TypeofRound.EventNormal || RoundType == GameView.TypeofRound.EventRumia || RoundType == GameView.TypeofRound.EventSeija || RoundType == GameView.TypeofRound.EventNue || RoundType == GameView.TypeofRound.EventTable || RoundType == GameView.TypeofRound.EventFireCirno || RoundType == GameView.TypeofRound.EventBalloon || RoundType == GameView.TypeofRound.EventElectricCirno || RoundType == GameView.TypeofRound.EventNoWrap || RoundType == GameView.TypeofRound.EventSanaeBoss || RoundType == GameView.TypeofRound.EventParseeBoss || RoundType == GameView.TypeofRound.EventMurasaBoss || RoundType == GameView.TypeofRound.EventScrolling || RoundType == GameView.TypeofRound.EventDescending || RoundType == GameView.TypeofRound.EventYuuka || RoundType == GameView.TypeofRound.EventExplosive || RoundType == GameView.TypeofRound.EventTruck)
		//if (["EventNormal","EventRumia","EventSeija","EventNue","EventTable","EventFireCirno","EventBalloon","EventElectricCirno","EventNoWrap","EventSanaeBoss","EventParseeBoss","EventMurasaBoss","EventScrolling","EventDescending","EventYuuka","EventExplosive","EventTruck"].indexOf(RoundType.getName())>-1)
		if ([GameView.TypeofRound.EventNormal,GameView.TypeofRound.EventRumia,GameView.TypeofRound.EventSeija,GameView.TypeofRound.EventNue,GameView.TypeofRound.EventTable,GameView.TypeofRound.EventFireCirno,GameView.TypeofRound.EventBalloon,GameView.TypeofRound.EventElectricCirno,GameView.TypeofRound.EventNoWrap,GameView.TypeofRound.EventSanaeBoss,GameView.TypeofRound.EventParseeBoss,GameView.TypeofRound.EventMurasaBoss,GameView.TypeofRound.EventScrolling,GameView.TypeofRound.EventDescending,GameView.TypeofRound.EventYuuka,GameView.TypeofRound.EventExplosive,GameView.TypeofRound.EventTruck,GameView.TypeofRound.EventSuwako,GameView.TypeofRound.EventPointCollecting,GameView.TypeofRound.EventMagiFairy,GameView.TypeofRound.EventPatchouli,GameView.TypeofRound.EventElly,GameView.TypeofRound.EventSoccer].indexOf(RoundType)>-1)
		{
			var types = new Array<Array<Dynamic>>();
			//types[types.length] = CreateArrayOfMultiple(new Yuyuko(), 400);
			
			if (generalstage < 2)
			{
				types[types.length] = CreateArrayOfMultiple(new RedFairy(), 60);
			}
			else if (generalstage == 2)
			{
				types[types.length] = CreateArrayOfMultiple(new MoonRabbit(), 55);
			}
			else if (generalstage == 3)
			{
				types[types.length] = CreateArrayOfMultiple(new Kisume(), 45);
				types[types.length] = CreateArrayOfMultiple(new Orin(), 5);
			}
			else
			{
				types[types.length] = CreateArrayOfMultiple(new Mystia(), 34);
			}
			if (level > 3)
			{
				if (generalstage != 1)
				{
					types[types.length] = CreateArrayOfMultiple(new Keine(), 20);
				}
				if (level > 5)
				{
					if (generalstage == 1)
					{
						types[types.length] = CreateArrayOfMultiple(new Meiling(), 6);
					}
					if (level > 8)
					{
						types[types.length] = CreateArrayOfMultiple(new Letty(), 1);
					}
					types[types.length] = CreateArrayOfMultiple(new Hina(), 5);
					types[types.length] = CreateArrayOfMultiple(new Sakuya(), 4);
					if (level > 10)
					{
						types[types.length] = CreateArrayOfMultiple(new Tenshi(), 5);
						types[types.length] = CreateArrayOfMultiple(new Youmu(), 2);
						types[types.length] = CreateArrayOfMultiple(new Wriggle(), 2);
						if (level > 15)
						{
							types[types.length] = CreateArrayOfMultiple(new Utsuho(), 4);
							types[types.length] = CreateArrayOfMultiple(new Aya(), 1);
							types[types.length] = CreateArrayOfMultiple(new Yoshika(), 2);
							if (level > 20)
							{
								types[types.length] = CreateArrayOfMultiple(new Sekibanki(), 5);
								types[types.length] = CreateArrayOfMultiple(new Alice(), 5);
								types[types.length] = CreateArrayOfMultiple(new Mamizou(), 1);
								if (level > 25)
								{
									types[types.length] = CreateArrayOfMultiple(new Imposter(), 1);
									if (generalstage == 5)
									{
										types[types.length] = CreateArrayOfMultiple(new Tewi(), 34);
										types[types.length] = CreateArrayOfMultiple(new Reisen(), 15);
									}
									types[types.length] = CreateArrayOfMultiple(new Eirin(), 5);
									if (level > 30)
									{
										types[types.length] = CreateArrayOfMultiple(new Marisa(), 5);
										if (level > 30)
										{
											if (generalstage == 1)
											{
												types[types.length] = CreateArrayOfMultiple(new Scarlet(), 3);
											}
											if (level > 40)
											{
												types[types.length] = CreateArrayOfMultiple(new Hecatia(), 3);
												if (level > 45)
												{
													if (generalstage == 3)
													{
														types[types.length] = CreateArrayOfMultiple(new Satori(), 3);
													}
													if (level > 50)
													{
														types[types.length] = CreateArrayOfMultiple(new Kogasa(), 1);
														if (level > 55)
														{
															types[types.length] = CreateArrayOfMultiple(new Yuyuko(), 1);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			var i = 0;
			var limit = 3;
			if (lvl > 3)
			{
				limit = 4;
			}
			limit += Std.int((rank+1) / 2);
			while (i < limit)
			{
				var T = types[Std.int(Math.random() * types.length)];
				AddToArrayMultiple(enemytypes, T[0], T.length);
				i++;
			}
			i = 0;
			while (i < types.length)
			{
				var T = types[i];
				AddToArrayMultiple(enemytypes, T[0], T.length);
				i++;
			}
		}
		if (RoundType == GameView.TypeofRound.EventCirno || RoundType == GameView.TypeofRound.EventCirnoBoss)
		{
			AddToArrayMultiple(enemytypes, new Letty(), 3);
			AddToArrayMultiple(enemytypes, new Imposter(), 4);
		}
		if (RoundType == GameView.TypeofRound.EventMagiFairy)
		{
			AddToArrayMultiple(enemytypes, new MagiFairy(), 550);
		}
		if (RoundType == GameView.TypeofRound.EventSoccer)
		{
			AddToArrayMultiple(enemytypes, new Wriggle(), 25);
		}
		if (RoundType == GameView.TypeofRound.EventPatchouli)
		{
			AddToArrayMultiple(enemytypes, new Patchouli(), 450);
		}
		if (RoundType == GameView.TypeofRound.EventElly)
		{
			AddToArrayMultiple(enemytypes, new Elly(), 450);
		}
		if (RoundType == GameView.TypeofRound.EventDanmaku)
		{
			/*if (generalstage < 2)
			{
				AddToArrayMultiple(enemytypes, new RedFairy(), 30);
			}
			else if (generalstage == 2)
			{
				AddToArrayMultiple(enemytypes, new MoonRabbit(), 25);
			}
			else if (generalstage == 3)
			{
				AddToArrayMultiple(enemytypes, new Kisume(), 20);
			}
			else
			{
				AddToArrayMultiple(enemytypes, new Mystia(), 15);
			}*/
			if (generalstage < 2)
			{
				AddToArrayMultiple(enemytypes, new RedFairy(), 20);
			}
			else if (generalstage == 2)
			{
				AddToArrayMultiple(enemytypes, new MoonRabbit(), 17);
			}
			else if (generalstage == 3)
			{
				AddToArrayMultiple(enemytypes, new Kisume(), 13);
			}
			else
			{
				AddToArrayMultiple(enemytypes, new Mystia(), 10);
			}
			AddToArrayMultiple(enemytypes, new Tewi(), 25);
			AddToArrayMultiple(enemytypes, new Sakuya(), 10);
			AddToArrayMultiple(enemytypes, new Utsuho(), 2);
			AddToArrayMultiple(enemytypes, new Kogasa(), 2);
			AddToArrayMultiple(enemytypes, new Marisa(), 3);
			AddToArrayMultiple(enemytypes, new Imposter(), 3);
		}
		if (RoundType == GameView.TypeofRound.EventSuwako)
		{
			AddToArrayMultiple(enemytypes, new Suwako(), 600);
			AddToArrayMultiple(enemytypes, new Wakasagihime(), 400);
			epm *= 0.5;
		}
		if (RoundType == GameView.TypeofRound.EventMarisa)
		{
			AddToArrayMultiple(Obstacles, "Yuuka", 5);
			AddToArrayMultiple(enemytypes, new Marisa(), 600);
		}
		if (RoundType == GameView.TypeofRound.EventNue)
		{
			AddToArrayMultiple(enemytypes, new Nue(), 62);
			AddToArrayMultiple(enemytypes, new Imposter(), 3);
			epm *= 0.5;
			maxspawns = Math.ceil(maxspawns * 0.7);
		}
		if (RoundType == GameView.TypeofRound.EventTable/* || RoundType == GameView.TypeofRound.EventSoccer*/)
		{
			epm *= 0.5;
			maxspawns = Math.ceil(maxspawns * 0.7);
		}
		AddToArrayMultiple(enemytypes, new Imposter(), 2);
		if (RoundType == GameView.TypeofRound.EventCharacters)
		{
			//enemytypes = new Array<Enemy>();
			AddToArrayMultiple(enemytypes, new Imposter(), 50);
		}
		if (GameFlags.get(Main.UltraCommonCharacters))
		{
			enemytypes = new Array<Enemy>();
			AddToArrayMultiple(enemytypes, new Imposter(), 200);
		}
		if (rank > 0)
		{
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
		}
		var C = game.CombinedScoreALL + (level * 3000);
		var limit = 10;
		//while (C >= 35000)
		while (C >= 40000)
		{
			if (limit > 0)
			{
				AddToArrayMultiple(enemytypes, new Imposter(), 1);
				limit--;
			}
			C -= 35000;
		}
		var bosstime = true;
		if (RoundType == GameView.TypeofRound.EventCirnoBoss)
		{
			SpawnList.add(new BossCirno());
		}
		if (RoundType == GameView.TypeofRound.EventYukari)
		{
			SpawnList.add(new BossYukari());
		}
		else if (RoundType == GameView.TypeofRound.EventSanaeBoss)
		{
			SpawnList.add(new BossSanae());
		}
		else if (RoundType == GameView.TypeofRound.EventParseeBoss)
		{
			SpawnList.add(new BossParsee());
		}
		else if (RoundType == GameView.TypeofRound.EventMurasaBoss)
		{
			SpawnList.add(new BossMurasa());
		}
		else
		{
			bosstime = false;
		}
		if (bosstime)
		{
			maxspawns = Std.int(maxspawns * 0.6);
		}
		
		
				
		game.epm = epm + game.epmmodifier;
		game.ept = epm * (GameView.onetickperminutechance2);//the times 2 is for equalling "frame & 2>0" out above
		game.rept = (epm + 3 + (Math.floor(epm) >> 1)) * (GameView.onetickperminutechance2);
		
		
		
		//var SpawnList = game.SpawnList;
		//SpawnList.clear();
		game.spawnrate = spawnrate;
		game.rank = rank;
		game.maxspawns = maxspawns;
		game.enemytypes = enemytypes;
		game.Obstacles = Obstacles;
		
		game.populatespawnlist();
	}
	
	public function populatespawnlist()
	{
		var SpawnList = game.SpawnList;
		var enemytypes = game.enemytypes;
		var maxspawns = game.maxspawns;
		while (game.imposterbonus > 0)
		{
			var enemy = new Imposter();
			enemy.UID = 0;
			SpawnList.add(enemy);
			game.imposterbonus--;
		}
		if (enemytypes == null || enemytypes.length < 1)
		{
			if (enemytypes == null)
			{
				enemytypes = new Array<Enemy>();
			}
			enemytypes[enemytypes.length] = new RedFairy();
		}
		if (enemytypes != null && enemytypes.length > 0)
		{
			var tmp = 0;
			while (tmp < maxspawns)
			{
				var enemy = enemytypes[Math.floor(Math.random() * enemytypes.length)];
				enemy.UID = 0;
				SpawnList.add(enemy);
				tmp++;
				if (game.boss != null)
				{
					tmp++;
				}
			}
		}
	}
	
	public function AddToArrayMultiple(array:Dynamic, value:Dynamic, times:Int)
	{
		var i = 0;
		while (i < times)
		{
			array[array.length] = value;
			i++;
		}
	}
	public function CreateArrayOfMultiple(value:Dynamic, times:Int):Array<Dynamic>
	{
		var array = new Array<Dynamic>();
		var i = 0;
		while (i < times)
		{
			array[array.length] = value;
			i++;
		}
		return array;
	}
	public function update()
	{
		
	}
	
	public function hosterupdate()
	{
		
	}
	//(hoster)do enemyspawns, setting progress, telling game when the level ends etc. tick is called each time the spawntimer elapses.
	public function tick()
	{
		
	}
	public function updateprogressbar():Float
	{
		var prct:Float = 0.5;
		if (game.boss == null)
		{
			if (game.maxspawns == 0 && game.Hoster)
			{
				if (game.gamestarted)
				{
					prct = 1;
				}
				else
				{
					prct = 0;
				}
			}
			else
			{
				if (game.roundstarted || !game.Hoster)
				{
					prct = (game.maxspawns - game.totalenemies) / game.maxspawns;
				}
				else
				{
					prct = 1;
				}
			}
		}
		else
		{
			prct = (game.boss.phase) / game.boss.totalphases;
			var M:Float = game.maxspawns+1;
			var P:Float = (game.maxspawns - (game.totalenemies - 1)) / M;
			var R:Float = 1.0 / game.boss.totalphases;
			//P *= 0.333;
			P *= R;
			//P = Math.min(Math.max(0, P), 0.333);
			P = Math.min(Math.max(0, P), R);
			prct = Math.min(P+prct,1);
		}
		return prct;
	}
	public function gotonextlevel()
	{
		var SpawnList = game.SpawnList;
		//var RoundType = game.RoundType;
		
		//if (count < 1)
		{
			game.ResetSpawnTimer();
			game.SpawnTimer = game.SpawnTimer >> 1;
			if (game.gamestarted)
			{
				game.level += game.gamemode.levelincrement;
			}
			var tmp = 0;
			if (game.Hoster)
			{
				game.powblock.HP = 4;
				game.SendStatus();
				//if (level % 5 == 1)
					
				if (false)
				{
					//reward players with a bomb upon completeing special rounds.(no longer needed since powblock refresh every level now.)
					if (game.RoundType != GameView.TypeofRound.EventNormal)
					{
						var D:Dynamic = { };
						D.type = "Bomb";
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
						////game.spawnedChar = false;
						game.SendEvent("SpawnItem", D);	
					}
				}
			}
			game.enemyspawn = false;
			game.CalculateLevelData();
			var data:Dynamic = { };
			data.level = game.level;
			data.RoundType = game.RoundType.getIndex();
			if (game.level > 1 && game.roundstarted)
			{
				game.SendEvent("NextLevel", data);
			}
		
			game.settotalenemies();
				
			game.SendEvent("TotalEnemies", game.totalenemies);
		}
		/*else if (game.boss != null && count == 1)
		{
			game.boss.outofminions();
		}*/
	}
	public function SetSpawnPosition(object:Dynamic)
	{
		if (Math.random() > 0.5)
		{
			object.x = 800;
			object.Ldir = -1;
		}
		else
		{
			//data.x = -16;
			object.x = -64;
			object.Ldir = 1;
		}
		object.y = -100;
	}
	public function DoSpawn()
	{
		if (game.Sealed > 0/* || game.ufoseal > 0*/)
		{
			return;
		}
		var Q = game.queuedevents;
		if (Q.length > 0)
		{
			//return;
			var i = 0;
			while (i < Q.length)
			{
				if (Q[i].event == "SpawnEnemy")
				{
					return;
				}
				i++;
			}
		}
		var SpawnList = game.SpawnList;
		var RoundType = game.RoundType;
		//var E = SpawnList.pop();
		var E = SpawnList.first();
		game.enemyspawn = true;
		var data:Dynamic = { };
		data.UID = E.UID;
		if (data.UID == 0)
		{
			//if blank enemy(made in spawnlist) then populate id info
			data.UID = Math.random();
		}
		SetSpawnPosition(data);
		/*if (Math.random() > 0.5)
		{
			data.x = 800;
			data.Ldir = -1;
		}
		else
		{
			//data.x = -16;
			data.x = -64;
			data.Ldir = 1;
		}
		data.y = -100;*/
		if (E.hascustomspawn)
		{
			var CS = E.customspawn();
			if (CS.x != null)
			{
				data.x = CS.x;
			}
			if (CS.y != null)
			{
				data.y = CS.y;
			}
			if (CS.Ldir != null)
			{
				data.Ldir = CS.Ldir;
			}
		}
		//data.alive = true;
		//data.visible = true;
		
		//data.Hspeed = 0;
		//data.Vspeed = 0;
		
		data.enraged = E.enraged;
		data.type = E.charname;
		data.rank = E.rank;
		if (E.spawns > 0)
		{
			data.spawns = E.spawns;
		}
		if (E.HP > -1)
		{
			data.HP = E.HP;
		}
		//game.SendQueueEvent("SpawnEnemy", data, 30,true);
		game.SendEvent("SpawnEnemy", data);
	}
}