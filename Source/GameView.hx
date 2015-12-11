package;

import abilities.AbsorbDamage;
import levellogic.ArenaLogic;
import levellogic.ExplosiveLogic;
import levellogic.FreezeLogic;
import levellogic.NoWrap;
import levellogic.PointCollectingLogic;
import levellogic.WaterLogic;
import levellogic.YuukaLogic;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.Assets;
import openfl.geom.Point;
import openfl.geom.Rectangle;
import openfl.geom.Transform;
import openfl.Lib;
import openfl.text.Font;
import openfl.text.TextField;
import openfl.text.TextFormat;
//import openfl.text;
import haxe.ds.Vector;
import openfl.display.Sprite;
import openfl.display.StageAlign;
import openfl.display.StageScaleMode;
import openfl.events.Event;
import openfl.events.KeyboardEvent;
import openfl.events.TouchEvent;
import openfl.events.JoystickEvent;
import openfl.ui.Keyboard;
import haxe.Timer;
import openfl.events.MouseEvent;
import openfl.media.Sound;
import openfl.media.SoundChannel;
import openfl.media.SoundTransform;
/**
 * ...
 * @author RSGmaker
 */

//aka events
enum TypeofRound {
		EventNormal;
		EventNue;
		EventSeija;
		EventCirno;
		EventYukari;
		EventRumia;
		EventTable;
		EventFireCirno;
		EventBalloon;
		EventElectricCirno;
		EventCharacters;
		EventNoWrap;
		EventUnzan;
		EventSanaeBoss;
		EventCirnoBoss;
		EventParseeBoss;
		EventMurasaBoss;
		EventMarisa;
		EventDanmaku;
		EventLava;
		EventDescending;
		EventScrolling;
		EventYuuka;
		EventExplosive;
		EventTruck;
		EventSuwako;
		EventPointCollecting;
		EventMagiFairy;
		EventPatchouli;
		EventElly;
	}
class GameView extends Sprite
{
	public static var _this:                    GameView;
	private var text:String;
	//the text at the top of the screen when playing.
	public var TF:TextField;
	//the combo counter
	public var CTF:TextField;
	//our player's controls
	private var control:Array<Bool>;
	public var myplayer:Player;
	private var direction:Int;
	public var entities:Array<Entity>;
	//loads series of bitmaps.
	public var AL:Animationloader;
	#if flash
	public var NP:NetPlay;
	#end
	//current frame we're on.
	public var frame:Int;
	//whether or not mouse/touch is being pressed.
	public var MSE:Bool;
	public var music:Sound;
	public var musicchannel:SoundChannel;
	//the last time stamp(used to frame skip and frame limit)
	public var ltime:Float;
	//how much time needs to get caught up.
	public var missingTime:Float;
	//list of enemies to spawn/respawn
	public var SpawnList:List<Enemy>;
	//amount of time until the next enemy spawns
	public var SpawnTimer:Int;
	public var activeEnemies:Array<Enemy>;
	public var activeItems:Array<EntityItem>;
	public var activeInteractables:Array<Entity>;
	public var level:Int;
	public var Llevel:Int;
	public var snd_killenemy:Sound;
	public var snd_finalkillenemy:Sound;
	//used in text display, and for multiplayer syncing
	public var totalenemies:Int;
	//whether or not global events are initiated from this client if not, only fire events being posted.
	public var Hoster:Bool;
	public var touched:Bool;
	public var ImposterList:Array<String>;
	public var Players:Map < String, Player>;
	public var Sealed:Int;
	//used when a rainbow ufo spawns, prevents obstacles.
	public var ufoseal:Int;
	public var messages:Array<String>;
	public var messagetime:Int;
	
	public var charselect:CharacterSelect;
	public var collisiondata:Array<Dynamic>;
	public var collisiondangerousdata:Array<Dynamic>;
	//true after first enemy of level spawns.
	public var enemyspawn:Bool;
	public var gamestarted:Bool = false;
	public var progressbar:Sprite;
	public var lastprogress:Float;
	public var leveltitle:TextField;
	public var lifeicon:Bitmap;
	public var ufoicons:Array<Bitmap>;
	public var abilityicon:Bitmap;
	public var currentability:String;
	public var ufolimit:Int;
	public var useablelist:Array<String>;
	
	public var gamemode:GameMode;
	
	//moves all blocks on screen to this offset(used for autoscrolling stages)
	public var scrollX:Float=0;
	public var scrollY:Float=0;
	//last scroll position used to determine if there's been a change.
	public var LscrollX:Float=0;
	public var LscrollY:Float=0;
	
	public var scrollspeedX:Float=0;
	public var scrollspeedY:Float=0;
	
	//whether or not we scroll this frame(we toggle this each frame to reduce the hit to performance)
	public var scrollframe:Bool;
	
	public var currentgeneralstage:Int;
	public var currentstage:Int;
	public var currentstagelevel:Int;
	public var currentranklevel:Int;
	public static var stagesperrank:Int = 6;
	public static var levelsperstage:Int = 5;
	public static var levelsperrank:Int = 6 * 5;
	
	public var allowpowblock:Bool = true;
	public var lastNPerror:String = "";
	
	public var HostPlayer:Player=null;
	
	public var gameoverscreen:Sprite;
	public var gameoverdescription:TextField;
	
	public var levelicon:Bitmap;
	
	public function GetLogic():LevelLogic
	{
		var R = RoundType;
		if (R == TypeofRound.EventLava)
		{
			return new levellogic.LavaLogic();
		}
		else if (R == TypeofRound.EventSuwako)
		{
			return new levellogic.WaterLogic();
		}
		else if (R == TypeofRound.EventCirno || R == TypeofRound.EventFireCirno || R == TypeofRound.EventElectricCirno/* || R == TypeofRound.EventCirnoBoss*/)
		{
			return new levellogic.FreezeLogic();
		}
		else if (R == TypeofRound.EventNoWrap)
		{
			return new levellogic.NoWrap();
		}
		else if (R == TypeofRound.EventTable)
		{
			return new levellogic.Tables();
		}
		else if (R == TypeofRound.EventDescending)
		{
			return new levellogic.DescendingArena();
		}
		else if (R == TypeofRound.EventScrolling)
		{
			return new levellogic.ScrollingArena();
		}
		else if (R == TypeofRound.EventYuuka)
		{
			return new levellogic.YuukaLogic();
		}
		else if (R == TypeofRound.EventExplosive)
		{
			return new levellogic.ExplosiveLogic();
		}
		else if (R == TypeofRound.EventTruck)
		{
			return new levellogic.TruckLogic();
		}
		else if (R == TypeofRound.EventPointCollecting)
		{
			return new levellogic.PointCollectingLogic();
		}
		else if (R == TypeofRound.EventCirnoBoss || R == TypeofRound.EventYukari || R == TypeofRound.EventParseeBoss || R == TypeofRound.EventSanaeBoss || R == TypeofRound.EventMurasaBoss)
		{
			return new levellogic.BossArena();
		}
		return new levellogic.ArenaLogic();
	}
	public function AddWarningSign(X:Float, Y:Float, duration:Int)
	{
		var FA:Array<flash.filters.BitmapFilter> = new Array<flash.filters.BitmapFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 10;
		AB.blurY = 10;
		AB.color = 0xFFFFFF;
		AB.strength = 1;
		FA[FA.length] = AB;
		var P = new Particle("warning");
		P.x = X;
		P.y = Y;
		P.HP = duration;
		P.filters = FA;
		AddObject(P);
	}
	public function autoscroll()
	{
		scrollframe = !scrollframe;
		if (!scrollframe)
		{
			return;
		}
		if (scrollspeedX == 0 && scrollspeedY == 0)
		{
			scrollframe = false;
			return;
		}
		LscrollX = scrollX;
		LscrollY = scrollY;
		scrollX += scrollspeedX;
		scrollY += scrollspeedY;
		/*while (scrollX <= -288)
		{
			scrollX += 1312;
			LscrollX += 1312;
		}
		while (scrollX >= 1344)
		{
			scrollX -= 1312;
			LscrollX -= 1312;
		}*/
		
		
		scrollwrap();
	}
	public function scrollwrap()
	{
		/*while (scrollX <= -288)
		{
			scrollX += 1312;
			LscrollX += 1312;
		}
		while (scrollX >= 1344)
		{
			scrollX -= 1312;
			LscrollX -= 1312;
		}*/
		while (scrollX < 0)
		{
			scrollX += 1312;
			LscrollX += 1312;
		}
		while (scrollX > 1312)
		{
			scrollX -= 1312;
			LscrollX -= 1312;
		}
		/*while (scrollX > 1056)
		{
			scrollX -= 1312;
			LscrollX -= 1312;
		}*/
		
		while (scrollY <= -32)
		{
			scrollY += 632;
			LscrollY += 632;
		}
		while (scrollY >= 600)
		{
			scrollY -= 632;
			LscrollY += 632;
		}
	}
	public function ResetScroll()
	{
		scrollX = 0;
		LscrollX = 0;
		scrollY = 0;
		LscrollY = 0;
		scrollspeedX = 0;
		scrollspeedY = 0;
		var i = 0;
		while (i < entities.length)
		{
			var D:Dynamic = entities[i];
			if (D.type == "Block")
			{
				D.ResetPosition();
			}
			i++;
		}
	}
	public function ResetScrollX()
	{
		scrollX = 0;
		LscrollX = 0;
		scrollspeedX = 0;
		var i = 0;
		while (i < entities.length)
		{
			var D:Dynamic = entities[i];
			if (D.type == "Block")
			{
				D.ResetPositionX();
			}
			i++;
		}
	}
	public function ResetScrollY()
	{
		scrollY = 0;
		LscrollY = 0;
		scrollspeedY = 0;
		var i = 0;
		while (i < entities.length)
		{
			var D:Dynamic = entities[i];
			if (D.type == "Block")
			{
				D.ResetPositionY();
			}
			i++;
		}
	}
	
	
	public function GetPlayers():Array<Player>
	{
		/*var ret = new Array<Player>();
		var A = Players.iterator();
		if (A.hasNext())
		{
			ret[ret.length] = A.next();
		}*/
		
		var PL = new Array<Player>();
		var A = Players.iterator();
		
		while (A.hasNext())
		{
			var E = A.next();
			PL[PL.length] = E;
		}
		PL.sort(sortplayer);
		return PL;
		//ret.sort(sortplayer);
		//return ret;
	}
	public function unlockcharacter(name:String)
	{
		var i = Player.characters.indexOf(name);
		var alt = false;
		var moneyreward = true;
		if (name.indexOf("ALT") > -1)
		{
			alt = true;
			name = name.substr(0, name.length - 3);
			i = Player.characters.indexOf(name);
		}
		/*if (GameFlags.get(Main.AllStar))
		{
			if (useablelist.indexOf(name) < 0)
			{
				useablelist[useablelist.length] = name;
			}
		}*/
		getcharacter(name);
		var savedata = Main._this.savedata;
		if (i > -1)
		{
			//if (name.indexOf("ALT") > -1)
			if (alt)
			{
				//name = name.substr(0, name.length - 3);
				//i = Player.characters.indexOf(name);
				if (!savedata.data.alts[i])
				{
					savedata.data.alts[i] = true;
					var SS = Player.getname(name);
					/*var SS = (name.charAt(0).toUpperCase() + name.substr(1)).split("ALT").join("☆");
					var SA = SS.split("_");
					var i = 0;
					SS = "";
					while (i < SA.length)
					{
						var str = SA[i];
						str = (str.charAt(0).toUpperCase() + str.substr(1));
						if (SS == "")
						{
							SS = str;
						}
						else
						{
							SS = SS + " " + str;
						}
						i++;
					}*/
					ShowMessage("Unlocked " + SS + "☆!");
					//ShowMessage("Unlocked " + name.charAt(0).toUpperCase() + name.substr(1) + "☆!");
					moneyreward = false;
				}
			}
			if (!savedata.data.unlock[i])
			{
				savedata.data.unlock[i] = true;
				/*var SS = (name.charAt(0).toUpperCase() + name.substr(1)).split("ALT").join("☆");
				var SA = SS.split("_");
				var i = 0;
				SS = "";
				while (i < SA.length)
				{
					var str = SA[i];
					str = (str.charAt(0).toUpperCase() + str.substr(1));
					if (SS == "")
					{
						SS = str;
					}
					else
					{
						SS = SS + " " + str;
					}
					i++;
				}*/
				var SS = Player.getname(name);
				ShowMessage("Unlocked " + SS + "!");
				//ShowMessage("Unlocked " + name.charAt(0).toUpperCase() + name.substr(1) + "!");
				moneyreward = false;
			}
		}
		if (moneyreward)
		{
			awardmoney(1);
		}
		//flushing the savedata causes lag, so using it here may not be the best idea.
		//savedata.flush();
	}
	public function awardmoney(amount:Int)
	{
		Main._this.savedata.data.money += amount;
		moneytime = 150;
		//SoundManager.Play("cash");
	}
	//unlocks character for all star mode list.
	public function getcharacter(name:String)
	{
		var alt = false;
		if (name.indexOf("ALT") > -1)
		{
			alt = true;
			name = name.substr(0, name.length - 3);
		}
		if (GameFlags.get(Main.AllStar))
		{
			if (useablelist.indexOf(name) < 0)
			{
				useablelist[useablelist.length] = name;
			}
		}
	}
	public function ShowMessage(message:String)
	{
		if (messages.length == 0)
		{
			messagetime = 500;
		}
		else if (messages.length < 6)
		{
			messagetime += 100;
		}
		messages[messages.length] = message;
	}
	public function sortplayer(A:Player, B:Player)
	{
		if (A.UID < B.UID)
		{
			return -1;
		}
		if (A.UID > B.UID)
		{
			return 1;
		}
		return 0;
	}
	//whether or not our player just pressed a button last frame(used to determine if we need to rush messages to the other players to keep them updated)
	public var ControlEvent:Bool;
	public var Dpad:Bitmap;
	//visual boundries(cleans up areas that are out of bounds)
	private var BGCRight:Bitmap;
	private var BGCLeft:Bitmap;
	private var BGCBottom:Bitmap;
	
	//used for buttons,messages and such.
	public var gui:Sprite;
	
	
	public var powblock:PowBlock;
	public var roundstarted:Bool;
	//the number of enemies spawned for this level
	public var maxspawns:Int;
	public var spawns:Int;
	//the character's name chosen at characterselect
	public var playerspick:String;
	//whether or not to create a netplay object on start();
	public var online:Bool;
	public var gameover:TextField;
	
	public var playername:String;
	//list of players and their scores in multiplayer
	public var scoreboard:TextField;
	public var SC:Sprite;
	public var MSG:Sprite;
	public var MSGText:TextField;
	
	public var Room:String;
	public var status:String;
	//total active ufos
	public var ufos:Int;
	public var HighScore:Int;
	
	public var boss:Boss = null;
	
	public var minipowactive:Bool;
	public var minipowspawns:Int=0;
	public var maxminipowspawns:Int=2;
	
	//current background
	public var Background:Bitmap;
	//last background,used in stage transitioning(the fade in effect)
	public var OBackground:Bitmap;
	//how long until sync can happen(throttled to keep sync spam down);
	public var syncdelay:Int;
	
	//public var gamemode:Int;
	public var GameFlags:FlagManager;
	
	//what event is active
	public var RoundType:TypeofRound;
	public var LRoundType:TypeofRound = null;
	
	public static var onetickperminutechance:Float = 1.0 / (1800.0);
	public static var onetickperminutechance2:Float = onetickperminutechance * 2;
	//events per minute.
	public var epm:Float;
	//events per tick
	public var ept:Float;// ept = epm * onetickperminutechance;
	//rushed events per tick(it uses this value instead of ept, when level is taking too long to complete)
	public var rept:Float;
	//public var PointsToLife:Int=10000;
	//public var PointsToLife:Int=12000;
	//public var PointsToLife:Int=14000;
	
	//public var PointsToLife:Int=15000;
	public var PointsToLife:Int=3750;
	public var CombinedScore:Int = 0;
	//ALL means it even counts score used up on 1ups
	public var CombinedScoreALL:Int = 0;
	public var Obstacles:Array<String>;
	public var enemytypes:Array<Enemy>;
	public var platformformation:Int = 0;
	public var currentformation = -1;
	public var platforms:Array<Array<Block>>;
	
	//every 10000 point spawn a char(offset this by -5000 as a midway bonus to 1up)
	///public var spawnedChar:Bool;
	
	//the current rank
	//every cycle(30 level is one cycle), ranks power up enemies and increase point values.
	public var rank:Int;
	
	public var thegiant:GiantSuika;
	public var trophyactive:Bool;
	public var maxyuuka:Int = 1;
	public var yuukasactive:Int;
	//public var yuukaactive:Bool;
	
	//how many rounds since the last game over.(effects events)
	public var successstreak:Int;
	public var mysuccessstreak:Int;
	public var objectiveprogress:Int;
	
	//if netlog is active we can monitor events 
	public var sentmessagelog:Map<String,Int>;
	public var recievedmessagelog:Map<String,Int>;
	public var netlog:Bool;
	
	public var startinglives:Int;
	public var sessionID:Float;
	
	//tournament data(unused)
	public var epmmodifier:Int;
	public var timelimit:Int;
	public var roundlimit:Int;
	public var elapsedtime:Int;
	public var endongameover:Bool;
	public var tournament:Bool;
	public var paused:Bool = false;
	public var menu:Bool = false;
	public var pausetime:Float = 0;
	
	public var flashcolor:Int;
	public var flashmaxalpha:Float;
	public var flashalpha:Float;
	public var flashrate:Float;
	public var flashalphadirection:Bool;
	
	public var backlayer:Sprite;
	public var entitylayer:Sprite;
	public var frontlayer:Sprite;
	public var gamestage:Sprite;
	public var camera:Sprite;
	
	public var spawnpaused:Bool;
	//number of imposters we should spawn next level
	public var imposterbonus:Int;
	
	//amount of time to display the amount of money you have.
	public var moneytime:Int;
	public var moneyicon:Bitmap;
	
	public var spawnrate:Float = 1.0;
	var ZaWarudo:Sprite = null;
	var ZaWarudoCaster:Player = null;
	
	public var colorflash:Shape;
	
	public var lvllogic:LevelLogic;
	
	public var queuedevents:Array<EventQueue>;
	
	//number of point items spawned since last ufoitem.
	public var points:Int=0;
	
	public function new () {
		super ();
		playername = "";
		Room = "public";
		status = "playing";
		syncdelay = 0;
		rank = 0;
		//gamemode = 0;
		GameFlags = new FlagManager(1);
		netlog = false;
		epmmodifier = 0;
		timelimit = -1;
		roundlimit = -1;
		elapsedtime = -1;
		endongameover = false;
		startinglives = 3;
		tournament = false;
		sessionID = Math.random();
		minipowactive = false;
		ImposterList = new Array<String>();
		//netlog = Main._this.DEBUG;
		messages = new Array<String>();
		entitylayer = new Sprite();
		backlayer = new Sprite();
		gamestage = new Sprite();
		camera = new Sprite();
		queuedevents = new Array<EventQueue>();
	}
	
	public function FlashColor(color:Int,maxalpha:Float,startalpha:Float,rate:Float)
	{
		flashcolor = color;
		flashmaxalpha = maxalpha;
		flashrate = rate;
		flashalpha = startalpha;
		flashalphadirection = true;
		
		colorflash.graphics.clear();
		colorflash.graphics.beginFill(color, 1);
		colorflash.graphics.drawRect(0, 0, 800, 600);
		colorflash.graphics.endFill();
		colorflash.alpha = flashalpha;
	}
	public function unlockpart(type:String, index:Int,displaymsg:Bool=true)
	{
		if (type == "" || type == "random" || type == "Random")
		{
			var S:Array<String> = new Array<String>();
			S.push("Body");
			S.push("Hair");
			S.push("Arms");
			S.push("Mouth");
			S.push("Eyes");
			S.push("Accessory");
			S.push("Hat");
			S.push("Back");
			var D = AvatarEditor.pickpart(S);
			type = D.type;
			index = D.index;
		}
		var ok = AvatarEditor.unlockpart(type, index, true);
		if (ok && displaymsg)
		{
			var D = AvatarEditor.getpart(type);
			
			ShowMessage("Unlocked " + type+":");
			ShowMessage(D.data[index][0]);
		}
	}
	
	/*private function getpartdata(type:String):Dynamic
	{
		var D:Dynamic = { };
		if (type == "body")
		{
			D.data = CharHelper.BodyData;
			D.unlock = Main._this.savedata.data.unlockables_body;
		}
	}*/
	
	public function GetImposterList():Array<String>
	{
		//var stage = Math.floor((level - 1) / 5);

		//var generalstage = stage % 6;
		var stage = currentstage;
		var generalstage = currentgeneralstage;
		var L = new Array<String>();
		if (RoundType == TypeofRound.EventCirno || RoundType == TypeofRound.EventFireCirno || RoundType == TypeofRound.EventElectricCirno || RoundType == TypeofRound.EventCirnoBoss)
		{
			L[L.length] = "cirno";
			L[L.length] = "cirno";
			L[L.length] = "cirno";
			
			L[L.length] = "cirno";
			L[L.length] = "cirno";
			L[L.length] = "cirno";
			
			L[L.length] = "cirno";
			L[L.length] = "cirno";
			L[L.length] = "cirno";
			
			L[L.length] = "letty";
		}
		else if (RoundType == TypeofRound.EventRumia)
		{
			L[L.length] = "rumia";
		}
		else if (RoundType == TypeofRound.EventNue)
		{
			L[L.length] = "nue";
		}
		else if (RoundType == TypeofRound.EventSeija)
		{
			L[L.length] = "seija";
		}
		else if (RoundType == TypeofRound.EventYukari)
		{
			L[L.length] = "chen";
			L[L.length] = "ran";
			/*L[L.length] = "yukari";*/
		}
		else
		{
			var stagebased = true;
			if (stagebased)
			{
			//a very crude system that breaks up unlockable character lists into stages.
			//it doesn't make much sense(and i lazily copied entire character lists from games into the stages)
			L = L.concat(["kasen", "kosuzu", "tokiko", "akyu", "maribel", "renko"]);
			L = L.concat(["aya", "medicine", "yuuka", "komachi", "shikieiki"]);
			
			//shrine
			if (generalstage == 0)
			{
				L = L.concat(["reimu", "marisa", /*"sanae", */"kanako"/*, "suwako"*/, "alice", "shanghai"/*, "suika"*/]);
				L = L.concat(["sara", "louise", "yuki", "mai", "ayana", "yumeko", "shinki", "mika", "senkou", "orange", "kurumi"/*, "elly"*/, "rengeteki"/*, "yuuka"*/, "mugetsu", "gengetsu", "ellen", "kotohime", "kana", "rikako", "chiyuri", "yumemi", "ruukoto", "rika", "noroiko", "meira", "matenshi", "shingyoku", "elis", "sariel", "mima", "konngara"]);
				L = L.concat(["lily_white", "lyrica", "lunasa", "merlin","youmu", "yuyuko"]);
			}
			//sdm
			if (generalstage == 1)
			{
				L = L.concat(["daiyousei", "meiling", "koakuma"/*, "patchouli"*/, "sakuya",/* "remilia", "flandre",*/ "rin"]);
				L = L.concat(["luna_child", "star_sapphire", "sunny_milk"]);
			}
			//space
			if (generalstage == 2)
			{
				L = L.concat(["iku", "tenshi", "hatate", "kokoro"]);
				
				L = L.concat(["sumireko", "seiran", "ringo", "doremy","sagume","clownpiece","junko","hecatia"]);
				
				L = L.concat(["reisen", "toyohime", "yorihime"]);
			}
			//underground
			if (generalstage == 3)
			{
				L = L.concat([/*"kisume", */"yamame", /*"parsee", */"yuugi", /*"satori", "koishi",*/ "orin", "utsuho"]);
				L = L.concat(["shizuha", "minoriko", "hina", "nitori", "momiji"/*, "sanae", "kanako", "suwako"*/]);
			}
			//palanquin ship
			if (generalstage == 4)
			{
				L = L.concat(["nazrin", "kogasa", "ichirin"/*,"unzan"*/, "murasa", "shou", "byakuren"]);
				L = L.concat(["kyouko", "yoshika", "seiga", "tojiko", "futo", "miko"/*, "mamizou"*/]);
			}
			//eintei
			if (generalstage == 5)
			{
				L = L.concat(["wriggle", "mystia", "keine", "tewi", "udongein", "eirin"/*, "kaguya", "mokou"*/]);
				L = L.concat([/*"wakasagihime", */"sekibanki", "kagerou", "benben", "yatsuhashi", "seija", "shinmyoumaru", "raiko"]);
			}
			}
			else
			{
				// a simpler system, where we just remove event unlockables and put the rest in the list.
				L = L.concat(["reimu", "marisa", /*"rumia",*/ "daiyousei", /*"cirno",*/ "meiling", "koakuma", "patchouli", "sakuya", "remilia", "flandre", "rin",
				"letty", /*"chen",*/ "alice", "shanghai"/*,"hourai"*/, "lily_white", "lyrica", "lunasa", "merlin", "youmu", "yuyuko", /*"ran", "yukari",*/
				"suika",
				"wriggle", "mystia", "keine", "tewi", "udongein", "eirin", "kaguya", "mokou",
				"aya", "medicine", "yuuka", "komachi", "shikieiki",
				"shizuha", "minoriko", "hina", "nitori", "momiji", "sanae", "kanako", "suwako",
				"iku", "tenshi", "hatate", "kokoro",
				/*"kisume", */"yamame", "parsee", "yuugi", "satori", "orin", "utsuho", "koishi",
				"nazrin", "kogasa", "ichirin"/*,"unzan"*/, "murasa", "shou", "byakuren", /*"nue",*/
				"kyouko", "yoshika", "seiga", "tojiko", "futo", "miko", "mamizou",
				"wakasagihime", "sekibanki", "kagerou", "benben", "yatsuhashi", /*"seija",*/ "shinmyoumaru", "raiko",
				"sumireko",
				"seiran", "ringo", "doremy",
				"luna_child", "star_sapphire", "sunny_milk", "reisen", "toyohime", "yorihime", "kasen", "kosuzu","tokiko","akyu","maribel","renko",
				"shingyoku","elis", "sariel", "mima", "konngara",
				"rika","noroiko", "meira", "matenshi",
				"ellen", "kotohime", "kana", "rikako", "chiyuri", "yumemi", "ruukoto",
				"orange", "kurumi", "elly", "rengeteki"/*, "yuuka"*/, "mugetsu", "gengetsu",
				"sara", "louise"/*,"alice"*/, "yuki", "mai", "ayana", "yumeko", "shinki", "mika", "senkou"]);
			}
		}
		if (L.length == 0)
		{
			L[L.length] = "reimu";
			L[L.length] = "marisa";
		}
		return L;
	}
	
	//disable/remove things that would leave memory leaks otherwise
	public function end() {
		
		if (musicchannel != null)
		{
			musicchannel.stop();
		}
		Obstacles = new Array<String>();
		removeChildren();
		#if flash
		if (online && NP != null)
		{
			NP.end();
		}
		NP = null;
		#end
		online = false;
		//this.removeEventListener(Event.ENTER_FRAME,this_onEnterFrame,true);
		///////removeEventListener (Event.ENTER_FRAME, this_onEnterFrame);
		removeEventListener( MouseEvent.MOUSE_DOWN, on_mousedown );
		removeEventListener(MouseEvent.MOUSE_UP, on_mouseup); 
		removeEventListener( TouchEvent.TOUCH_BEGIN, on_touchbegin);
		removeEventListener( TouchEvent.TOUCH_END, on_touchend);
		entities = new Array<Entity>();
		//entities = null;
	}
	public function gethighscore():Int
	{
		return Reflect.field(Main._this.savedata.data, "Highscore:" + Main._this.roomprefix);
		//return Main._this.savedata.data["Highscore:" + Main._this.roomprefix];
	}
	public function sethighscore(score:Int)
	{
		Reflect.setField(Main._this.savedata.data, "Highscore:" + Main._this.roomprefix, score);
		//Main._this.savedata.data["Highscore:" + Main._this.roomprefix] = score;
	}
	public function getmaxlevel():Int
	{
		return Reflect.field(Main._this.savedata.data, "maxlevel:" + Main._this.roomprefix);
		//return Main._this.savedata.data["maxlevel:" + Main._this.roomprefix];
	}
	public function setmaxlevel(level:Int)
	{
		//Main._this.savedata.data["maxlevel:" + Main._this.roomprefix] = level;
		Reflect.setField(Main._this.savedata.data, "maxlevel:" + Main._this.roomprefix, level);
		Main._this.savedata.flush();
	}
	public function getbackground(lvl:Int=-1):BitmapData
	{
		//updatelevelinfo();
		if (lvl < 0)
		{
			lvl = level;
		}
		//var L = Math.floor((lvl - 1) / levelsperstage);
	
		var L = 0;
		var BGS;
		if (!GameFlags.get(Main.Adventure))
		{
			L = Math.floor((level-1) / levelsperstage);
			//BGS = [CharHelper.GetBG("Moriya Shrine Room"), CharHelper.GetBG("Clocktower"), CharHelper.GetBG("The Moon"),CharHelper.GetBG("Underground Cave"),CharHelper.GetBG("Murasa's Ship (2)"),CharHelper.GetBG("Eientei Outside")];
			BGS = ["Moriya Shrine Room", "Clocktower", "The Moon","Underground Cave","Murasa's Ship (2)","Eientei Outside"];
			if (L < 0)
			{
				L = 0;
			}
			while (L >= BGS.length)
			{
				L -= BGS.length;
			}
		}
		else
		{
		//var L = Math.floor((level) / 5);
			//var BGS = [57, 129, 89,98,131,185];
		/*var BGS = [CharHelper.GetBG("Moriya Shrine Room"), CharHelper.GetBG("Clocktower"), CharHelper.GetBG("The Moon"),CharHelper.GetBG("Underground Cave"),CharHelper.GetBG("Murasa's Ship (2)"),CharHelper.GetBG("Eientei Outside")];
		if (L < 0)
			{
				L = 0;
			}
			while (L >= BGS.length)
			{
				L -= BGS.length;
			}
			var ind = BGS[L];*/
			L = currentstagelevel;
			BGS = ["Computer Grid", "Computer Grid", "Computer Grid", "Computer Grid", "Computer Grid", "Computer Grid", "Computer Grid", "Computer Grid"];
			//8 level version of adventure mode
			/*if (currentgeneralstage == 0)
			{
				//CharHelper.GetBG("Moriya Shrine Room")
				//BGS = ["Reimu's Room","Reimu's Door Open","Hakurei Shrine (IaMP)","Shrine Tori"];
				BGS = ["Reimu's Room","Reimu's Room","Reimu's Door Open","Hakurei Shrine Door","Hakurei Shrine (IaMP)","Hakurei Shrine (IaMP)","Shrine Tori","Shrine Tori"];
			}
			else if (currentgeneralstage == 1)
			{
				BGS = ["Lakeside (Snowy)", "It's a forest again", "Mansion Path", "SDM gate", "Scarlet Hallway 2", "SDM Balcony", "Clocktower", "Clocktower (Sunset)"];
			}
			else if (currentgeneralstage == 2)
			{
				BGS = ["Forest Night 2","Hakurei Shrine Night","Some Mountain","Night Mountain","The Moon","The Moon","The Moon","Earth from Space"];
			}
			else if (currentgeneralstage == 3)
			{
				BGS = ["Yukari's Gap","Crater","Crater","Hell of Blazing Fires","Hell of Blazing Fires","Underground Mine","Underground Cave","Underground Cave"];
			}
			else if (currentgeneralstage == 4)
			{
				BGS = ["And another forest!", "Mountain Sunset", "Mountain Sunset", "Generic Sky", "The Heavens", "The Heavens", "Murasa's Ship", "Murasa's Ship (2)"];
				//if feriligono lets me embed palanquin ship then i should use this commented out background setup.
				//BGS = ["And another forest!","Mountain Sunset","Generic Sky","The Heavens","Palanquin Ship","Palanquin Ship","Murasa's Ship","Murasa's Ship (2)"];
			}
			else if (currentgeneralstage == 5)
			{
				BGS = ["Open Field","Bamboo Forest","Bamboo Forest","Eientei Outside","Eientei Outside","Eientei Courtyard","Eientei","Eientei"];
			}*/
			//5 level version
			if (currentgeneralstage == 0)
			{
				//CharHelper.GetBG("Moriya Shrine Room")
				BGS = ["Reimu's Room","Reimu's Door Open","Hakurei Shrine Door","Hakurei Shrine (IaMP)","Shrine Tori"];
			}
			else if (currentgeneralstage == 1)
			{
				//BGS = ["Lakeside (Snowy)", "It's a forest again", "Mansion Path", "SDM gate", "Scarlet Hallway 2", "SDM Balcony", "Clocktower", "Clocktower (Sunset)"];
				//BGS = ["Mansion Path", "SDM gate", "SDM Balcony", "Clocktower", "Clocktower (Sunset)"];
				BGS = ["Dirt Road", "SDM gate", "SDM Balcony", "Clocktower", "Clocktower (Sunset)"];
			}
			else if (currentgeneralstage == 2)
			{
				BGS = ["Forest Night 2","Some Mountain","Night Mountain","The Moon","The Moon"];
			}
			else if (currentgeneralstage == 3)
			{
				BGS = ["Yukari's Gap","Crater","Crater","Underground Mine","Underground Cave"];
			}
			else if (currentgeneralstage == 4)
			{
				//BGS = ["And another forest!", "Mountain Sunset", "Mountain Sunset", "Generic Sky", "The Heavens", "The Heavens", "Murasa's Ship", "Murasa's Ship (2)"];
				//if feriligono lets me embed palanquin ship then i should use this commented out background setup.
				//BGS = ["And another forest!","Mountain Sunset","Generic Sky","The Heavens","Palanquin Ship","Palanquin Ship","Murasa's Ship","Murasa's Ship (2)"];
				
				//BGS = ["Mountain Sunset", "Mountain Sunset", "The Heavens", "Murasa's Ship", "Murasa's Ship (2)"];
				BGS = ["Mountain Sunset", "Mountain Sunset", "Palanquin Ship", "Murasa's Ship", "Murasa's Ship (2)"];
			}
			else if (currentgeneralstage == 5)
			{
				BGS = ["Open Field","Bamboo Forest","Eientei Outside","Eientei Courtyard","Eientei"];
			}
			L--;
			if (L < 0)
			{
				L = 0;
			}
		}
			var ind = CharHelper.GetBG(BGS[L]);
			var bd = AL.GetAnimation("background-" + ind)[0];
			return bd;
	}
	//Main._this.savedata.data.maxlevel
	public function updatelevelinfo()
	{
		if (Llevel == level)
		{
			return;
		}
		currentstage  = Math.floor((level - 1) / levelsperstage);//level / levelsperstage;
		rank = Math.floor(currentstage / stagesperrank);
		currentgeneralstage = currentstage % stagesperrank;
		var lvl = ((level - 1) % levelsperstage);
		lvl++;
		currentstagelevel = lvl;
		
		currentranklevel = level-1;
		levelsperrank = stagesperrank * levelsperstage;
		while (currentranklevel >= levelsperrank)
		{
			currentranklevel -= levelsperrank;
		}
		currentranklevel++;
		
		Llevel = level;
		// = Math.floor((level - 1) / 5);
	}
	public function start() {
		level++;
		gamemode = Main._this.gamemode;
		{
			
		SoundManager.PlayJingle("startgame").addEventListener(Event.SOUND_COMPLETE,function(e:Event):Void {PlayMusic(true);});
		}
		
		platforms = new Array<Array<Block>>();
		camera.addChild(gamestage);
		//addChild(gamestage);
		addChild(camera);
		collisiondata = new Array<Dynamic>();
		collisiondangerousdata = new Array<Dynamic>();
		successstreak = 0;
		mysuccessstreak = 0;
		objectiveprogress = 0;
		recievedmessagelog = new Map<String,Int>();
		sentmessagelog = new Map<String,Int>();
		//yuukaactive = false;
		yuukasactive = 0;
		trophyactive = false;
		_this = this;
		RoundType = TypeofRound.EventNormal;
		///spawnedChar = false;
		//OBackground = new Bitmap(AL.GetAnimation("CSBG")[0]);
		var ind = CharHelper.GetBG("Shrine Entrance");
		var bd = AL.GetAnimation("background-" + ind)[0];
		OBackground = new Bitmap(bd);
		Background = new Bitmap(getbackground());
		
		Background.alpha = 0;
		gamestage.addChild(OBackground);
		gamestage.addChild(Background);
		backlayer = new Sprite();
		gamestage.addChild(backlayer);
		entitylayer = new Sprite();
		gamestage.addChild(entitylayer);
		frontlayer = new Sprite();
		gamestage.addChild(frontlayer);
		//HighScore = Main._this.savedata.data.highscore;
		HighScore = gethighscore();
		ufos = 0;
		Players = new Map<String,Player>();
		ControlEvent = false;
		touched = false;
		totalenemies = 0;
		activeEnemies = new Array<Enemy>();
		activeItems = new Array<EntityItem>();
		activeInteractables = new Array<Entity>();
		//SpawnTimer = 60 * 5;
		SpawnTimer = 30 * 6;
		MSE = false;
		
		//level = 0;
		roundstarted = false;
		frame = 0;
		Hoster = true;
		#if flash
		//if netplay is available don't automaticly assume to be the hoster.
		if (online)
		{
			#if flash
		NP = new NetPlay();
		NP.Room = Room;
		NP.start();
		#else
		//only flash can play online
		online = false;
		#end
		}
		#end
		
		
		control = new Array<Bool>();
		control[0] = false;
		control[1] = false;
		control[2] = false;
		control[3] = false;
		control[4] = false;
		entities = new Array<Entity>();
		thegiant = new GiantSuika();
		thegiant.visible = false;
		AddObject(thegiant,0);
		if (AL == null)
		{
			AL = new Animationloader();
		}
		if (playerspick=="")
		{
			playerspick = Player.getRandomCharacter();
		}
		var soul:String = null;
		if (playerspick == "customavatar")
		{
			soul = Main._this.savedata.data.avatarability;
		}
		myplayer = new Player(playerspick, control,soul);
		myplayer.x = 140;
		myplayer.y = (600-32)-myplayer.height;
		myplayer.playername = playername;
		HostPlayer = myplayer;
		
		if (GameFlags.get(Main.KonamiCode))
		{
			startinglives = 30;
			myplayer.lives = 30;
		}
		updatelevelinfo();
		if (GameFlags.get(Main.NormalMode))
		{
			level = levelsperrank;
		}
		if (GameFlags.get(Main.HardMode))
		{
			level = levelsperrank*2;
		}
		if (GameFlags.get(Main.LunaticMode))
		{
			level = levelsperrank*3;
		}
		if (GameFlags.get(Main.ExtraMode))
		{
			level = levelsperrank*4;
		}
		//myplayer will need to be added to the Players list once an id is created.(or maybe just use "0")
		myplayer.ID = "Myself";
		
		spawnplatform(600 - 32);
		spawnplatform(600 - 192);
		spawnplatform(600 - 352);
		spawnplatform(600 - 512);
		
		setformation();
		powblock = new PowBlock("POW");
		powblock.x = 352+16;
		powblock.y = (600-192)-64+16;
		powblock.solid = true;
		AddObject(powblock);
		
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		TF = new TextField();
		TF.setTextFormat(tmp);
		TF.x = 200;
		TF.y = 10;
		TF.width = 50;
		TF.height = 60;
		TF.mouseEnabled = false;
		
		CTF = new TextField();
		CTF.setTextFormat(tmp);
		CTF.x = 700;
		CTF.y = 570;
		CTF.width = 100;
		CTF.height = 30;
		CTF.mouseEnabled = false;
		CTF.visible = false;
		CTF.scaleX = 1.5;
		CTF.scaleY = CTF.scaleX;
		
		var FA:Array<flash.filters.BitmapFilter> = new Array<flash.filters.BitmapFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 5;
		AB.blurY = 5;
		AB.color = 0x000000;
		AB.strength = 3;
		FA[FA.length] = AB;
		CTF.filters = FA;
		
		/*TF.visible = false;
		#if debug
		TF.visible = true;
		#end*/
		
		TF.cacheAsBitmap = true;
		tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 66;
		tmp.color = 0xFF0000;
		gameover = new TextField();
		gameover.x = 200;
		gameover.y = 150;
		gameover.text = "GAME OVER!";
		gameover.setTextFormat(tmp);
		gameover.width = 450;
		gameover.cacheAsBitmap = true;
		gameover.mouseEnabled = false;
		gameover.visible = false;
		//addChild(gameover);
		
		scoreboard = new TextField();
		scoreboard.cacheAsBitmap = true;
		scoreboard.text = "";
		scoreboard.x = 0;
		scoreboard.y = 0;
		//scoreboard.x = 300;
		//scoreboard.y = 10;
		///scoreboard.blendMode = openfl.display.BlendMode.INVERT;
		scoreboard.filters = CTF.filters;
		
		SC = new Sprite();
		SC.x = 300;
		SC.y = 10;
		SC.addChild(scoreboard);
		addChild(SC);
		MSG = new Sprite();
		MSG.cacheAsBitmap = true;
		SC.addChild(MSG);
		MSGText = new TextField();
		MSGText.x = 3;
		MSGText.y = 3;
		MSG.addChild(MSGText);
		MSGText.blendMode = openfl.display.BlendMode.INVERT;
		//addChild(scoreboard);
		
		//the miko sticks in the corners of the screen.
		var B = new Bitmap(AL.GetAnimation("barrier")[0]);
		B.x = -20-40;
		B.y = 430;
		B.cacheAsBitmap = true;
		gamestage.addChild(B);
		
		B = new Bitmap(AL.GetAnimation("barrierF")[0]);
		B.x = 820-160+40;
		B.y = 430;
		B.cacheAsBitmap = true;
		gamestage.addChild(B);
		B = new Bitmap(AL.GetAnimation("barrier")[0]);
		B.x = -20-40;
		B.y = -40;
		B.cacheAsBitmap = true;
		gamestage.addChild(B);
		B = new Bitmap(AL.GetAnimation("barrierF")[0]);
		B.x = 820-160+40;
		B.y = -40;
		B.cacheAsBitmap = true;
		gamestage.addChild(B);
		
		
		direction = 1;
		ZaWarudo = new Sprite();
		ZaWarudo.graphics.beginFill(0xFFFFFF, 1);
		ZaWarudo.graphics.drawRect(0, 0, 800, 600);
		ZaWarudo.graphics.endFill();
		ZaWarudo.blendMode = openfl.display.BlendMode.INVERT;
		ZaWarudo.visible = false;
		addChild(ZaWarudo);
		
		
		AddPlayer(myplayer);
		
		lifeicon = new Bitmap();
		lifeicon.x = 163;
		lifeicon.y = 5;
		lifeicon.scaleX = 0.6;
		lifeicon.scaleY = 0.6;
		//lifeicon.scrollRect = new Rectangle(0, 0, 100, 60);
		
		
		addChild(lifeicon);
		
		ufoicons = new Array<Bitmap>();
		var Y = 574;
		var scl = 0.45;
		var B = new Bitmap();
		B.x = 0;
		B.y = Y;
		B.scaleX = scl;
		B.scaleY = B.scaleX;
		B.cacheAsBitmap = true;
		B.visible = false;
		addChild(B);
		ufoicons.push(B);
		B = new Bitmap();
		B.x = 32;
		B.y = Y;
		B.scaleX = scl;
		B.scaleY = B.scaleX;
		B.cacheAsBitmap = true;
		B.visible = false;
		addChild(B);
		ufoicons.push(B);
		B = new Bitmap();
		B.x = 64;
		B.y = Y;
		B.scaleX = scl;
		B.scaleY = B.scaleX;
		B.cacheAsBitmap = true;
		B.visible = false;
		addChild(B);
		ufoicons.push(B);
		
		abilityicon = new Bitmap();
		abilityicon.x = 133;
		abilityicon.y = 5;
		abilityicon.scaleX = 0.4;
		abilityicon.scaleY = 0.4;
		if (GameFlags.get(Main.Adventure))
		{
			addChild(abilityicon);
		}
		updatelifeicon();
		moneyicon = new Bitmap(AL.GetAnimation("money")[0]);
		moneyicon.x = 175;
		moneyicon.y = 40;
		moneyicon.scaleX = 0.7;
		moneyicon.scaleY = 0.7;
		addChild(moneyicon);
		moneytime = 150;
		//moneyicon.visible = false;
		addChild(TF);
		addChild(CTF);
		
		stage.color = 0x009977;
		stage.scaleMode = StageScaleMode.SHOW_ALL;
		//if (stage.allowsFullScreen)
		{
			//Lib.current.stage.displayState = openfl.display.StageDisplayState.FULL_SCREEN;
		}
		//else if (stage.allowsFullScreenInteractive)
		{
			//Lib.current.stage.displayState = openfl.display.StageDisplayState.FULL_SCREEN;
		}
		
		
		////addEventListener (Event.ENTER_FRAME, this_onEnterFrame);
	addEventListener( MouseEvent.MOUSE_DOWN, on_mousedown );
	addEventListener( MouseEvent.MOUSE_UP, on_mouseup); 
	addEventListener( TouchEvent.TOUCH_BEGIN, on_touchbegin);
	addEventListener( TouchEvent.TOUCH_END, on_touchend);
		#if flash
		stage.align = StageAlign.TOP;
		#else
		stage.align = StageAlign.LEFT;
		//x = 200;
		#end
		
		ltime = Timer.stamp();
		missingTime = 0;
		SpawnList = new List<Enemy>();
		
		gui = new Sprite();
		addChild(gui);
		colorflash = new Shape();
		gui.addChild(colorflash);
		scrollRect = new Rectangle(0, 0, 800, 5000);
		/*BGCRight = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCRight.x = 800;
		BGCRight.y = 0;
		BGCRight.scaleX = 500;
		BGCRight.scaleY = 1000;
		BGCRight.cacheAsBitmap = true;
		//addChild(BGCRight);
		gui.addChild(BGCRight);
		BGCLeft = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCLeft.x = -500;
		BGCLeft.y = 0;
		BGCLeft.scaleX = 500;
		BGCLeft.scaleY = 1000;
		BGCLeft.cacheAsBitmap = true;
		//BGCLeft.z = -10;
		//addChild(BGCLeft);
		gui.addChild(BGCLeft);
		BGCBottom = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCBottom.x = -500;
		BGCBottom.y = 600;
		BGCBottom.scaleX = 1000;
		BGCBottom.scaleY = 500;
		BGCBottom.cacheAsBitmap = true;
		//BGCBottom.z = -10;
		//addChild(BGCBottom);
		gui.addChild(BGCBottom);*/
		///gamestage.scrollRect = new Rectangle(0, -100, 800, 600);
		//camera.scrollRect = new Rectangle(0, 0, 800, 600);
		Dpad = new Bitmap(Assets.getBitmapData("assets/Dpad.png"));
		Dpad.x = 0;
		Dpad.y = 600;
		//addChild(Dpad);
		gui.addChild(Dpad);
		
		var B = new MenuButton("Pause",70);
		B.x += 680;
		B.y = 620;
		B.button.buttonMode = false;
		gui.addChild(B);
		B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					togglemenu();
				 } 
				);
		
		var B = new MenuButton("Interact",70);
		B.x += 680;
		B.y = 880;
		B.button.buttonMode = false;
		gui.addChild(B);
		B.addEventListener( MouseEvent.MOUSE_DOWN, function( ev ) {
					control[4] = true;
				 } 
				);
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					control[4] = false;
				 } 
				);
		
		
		//addChild(colorflash);
		var filterArr:Array<flash.filters.BitmapFilter>;
		//var glow:flash.filters.GlowFilter;
		filterArr = new Array();
		//glow = new flash.filters.GlowFilter();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 20;
		AB.blurY = 20;
			//if (game.myplayer == null)
		{
			AB.color = 0xFFFFFF;
		}
			
		AB.strength = 1.25;
		
		filterArr[filters.length] = AB;
		
		
		progressbar = new Sprite();
		progressbar.mouseEnabled = false;
		progressbar.x = 610;
		progressbar.y = 2;
		progressbar.filters = filterArr;
		
		var AA = new flash.filters.DropShadowFilter();
		AA.alpha = 1;
		AA.distance = 3;
		AA.alpha = 25;
		AA.color = 0;
		filterArr = new Array();
		filterArr[filters.length] = AA;
		
		var flag = new Bitmap(AL.GetAnimation("flag")[0]);
		flag.x = -8;
		levelicon = flag;
		progressbar.addChild(flag);
		leveltitle = new TextField();
		leveltitle.y = 20;
		leveltitle.x = 5;
		leveltitle.y += progressbar.y;
		leveltitle.x += progressbar.x;
		leveltitle.cacheAsBitmap = true;
		leveltitle.mouseEnabled = false;
		leveltitle.textColor = 0xFFFFFF;
		//leveltitle.blendMode = openfl.display.BlendMode.INVERT;
		leveltitle.filters = filterArr;
		//leveltitle.cacheAsBitmap = true;
		//progressbar.addChild(leveltitle);
		gui.addChild(leveltitle);
		//lifeicon = new Bitmap(myplayer.image.bitmapData);
		
		lifeicon.cacheAsBitmap = true;
		gui.addChild(progressbar);
		
		if (GameFlags.get(Main.AllStar))
		{
			useablelist = new Array<String>();
			useablelist[useablelist.length] = playerspick;
		}
		//gui.addChild(lifeicon);
		
		updatelevelinfo();
		
		/*var TP = new TelephonePole();
		//TP.x = 800+250;
		TP.x = 800;
		AddObject(TP);*/
		
		
		gameoverscreen = new Sprite();
		var go = gameoverscreen;
		go.visible = false;
		go.graphics.beginFill(0, 0.3);
		go.graphics.drawRect(0, 0, 800, 600);
		go.graphics.endFill();
		
		var T = new TextField();
		gameoverdescription = T;
		//T.text = "You've run out of continues...";
		T.text = "You've run out of continues...";
		if (!gamemode.cancontinue)
		{
			T.text = "There are no continues in this mode.";
		}
		T.textColor = 0xFFFFFF;
		T.scaleX = 2.5;
		T.scaleY = 2.5;
		T.width = T.textWidth + 8;
		T.height = T.textHeight + 8;
		//T.x = 250;
		T.x = 400 - (T.width / 2);
		T.y = 70;
		T.mouseEnabled = false;
		go.addChild(T);
		var B = new MenuButton("Restart from beginning");
		B.x += 400;
		B.y += 250;
		B.sound = "ok";
		B.addclick(function( ev ) {
					status = "restart";
		});
		go.addChild(B);
		B = new MenuButton("Return to titlescreen");
		B.x += 400;
		B.y += 400;
		B.sound = "cancel";
		B.addclick(function( ev ) {
					status = "quitting";
		});
		
		go.addChild(B);
		
		addChild(go);
		addChild(gameover);
	}
	public function togglemenu()
	{
		if (gameoverscreen.visible)
		{
			status = "restart";
			return;
		}
		menu = !menu;
		
		if (GameFlags.get(Main.AllStar))
		{
			if (menu)
			{
			if (charselect != null)
			{
				gui.removeChild(charselect);
				charselect = null;
			}
			}
			else
			{
				if (myplayer.killed )
				{
					if (useablelist.indexOf(charselect.selected) >= 0)
					{
						
						playerspick = charselect.selected;
						var D:Dynamic = { };
						D.C = playerspick;
						D.A = null;
						SendEvent("ChangeCharacter", D);
						//SendEvent("ChangeCharacter", playerspick);
						var D:Dynamic = { };
						D.x = 400;
						D.y = 0;
						myplayer.cancel = false;
						myplayer.ability.onloselife();
						/*if (!myplayer.cancel)
						{
							myplayer.lives--;
						}*/
						//D.lives = myplayer.lives;
						D.lives = (useablelist.length-1);
						SendEvent("PlayerRespawn", D);
					}
					else
					{
						menu = true;
						SoundManager.Play("bonk");
					}
				}
			}
		}
		/*if (charselect.selected != playerspick)
			{
				playerspick = charselect.selected;
				SendEvent("ChangeCharacter", playerspick);
				//myplayer.init(playerspick);
			}*/
					if (!online)
			{
				//paused = !paused;
				paused = menu;
			}
			//if (!menu)
			if (!GameFlags.get(Main.AllStar))
			{
				Main._this.savedata.data.characterselected = playerspick;
			}
	}
	public function updatelifeicon()
	{
		//var BD = AL.GetAnimation(playerspick)[0];
		var BD = AL.GetAnimation(myplayer.charname)[0];
		if (lifeicon.bitmapData != BD)
		{
			lifeicon.bitmapData = BD;
			lifeicon.scrollRect = new Rectangle(0, 0, 100, BD.height - (BD.height / 4));
			lifeicon.y = (5+10) - (BD.height / 8);
			//lifeicon.x = (TF.x - lifeicon.width)+30;
		}
		if (GameFlags.get(Main.Adventure))
		{
			if (currentability != myplayer.charactersoul && myplayer.charactersoul != "red_fairy")
			{
				currentability = myplayer.charactersoul;
				var C = CharHelper.getCharPreset(currentability);
				if (C != null && C != "")
				{
					abilityicon.bitmapData = AL.GetAnimation(C)[0];
				}
				else
				{
					abilityicon.bitmapData = null;
				}
			}
		}
		var i = 0;
		while (/*i < myplayer.ufos.length && */i < ufoicons.length)
		{
			var B = ufoicons[i];
			var V = (i < myplayer.ufos.length);
			if (B.visible != V && V)
			{
				B.bitmapData = AL.GetAnimation(myplayer.ufos[i] + "ufo")[0];
			}
			B.visible = V;
			i++;
		}
	}
	//sets down platforms and puts holes in the platforms
	public function setformation()
	{
		resetblocks();
		if (platformformation == 0)
		{
			/*
			setholeinplatform(600 - 192, 256, 512,false);
			//setholeinplatform(600 - 192, 288, 480,false);
			//setholeinplatform(600 - 352, 192, 576,true);
			setholeinplatform(600 - 352, 160-32, 608+32,true);
			//setholeinplatform(600 - 512, 256, 512, false);
			setholeinplatform(600 - 512, 288, 480, false);
			
			//addsectioninplatform(600 - 352, -1000, 96, false);
			//addsectioninplatform(600 - 352, 672, 2000, false);
			
			//1st row
			addsectioninplatform(600 - 192, -1300, -128, true);
			addsectioninplatform(600 - 192, 960, 2000, true);
			//2nd row
			addsectioninplatform(600 - 352, -1300, -32, false);
			addsectioninplatform(600 - 352, 864, 2000, false);
			//3rd row
			addsectioninplatform(600 - 512, -1300, -160, true);
			addsectioninplatform(600 - 512, 992, 2000, true);
			
			
			
			
			setplatformasplatform(600 - 192, false);
			setplatformasplatform(600 - 352, false);
			setplatformasplatform(600 - 512, false);*/
			
			setholeinplatform(platforms[1], 256, 512,false);
			setholeinplatform(platforms[2], 160-32, 608+32,true);
			setholeinplatform(platforms[3], 288, 480, false);
			
			/*
			//1st row
			addsectioninplatform(platforms[1], -1300, -128, true);
			addsectioninplatform(platforms[1], 960, 2000, true);
			//2nd row
			addsectioninplatform(platforms[2], -1300, -32, false);
			addsectioninplatform(platforms[2], 864, 2000, false);
			//3rd row
			addsectioninplatform(platforms[3], -1300, -160, true);
			addsectioninplatform(platforms[3], 992, 2000, true);*/
			
			
			
			
			setplatformasplatform(platforms[1], false);
			setplatformasplatform(platforms[2], false);
			setplatformasplatform(platforms[3], false);
		}
		if (platformformation == 1)
		{
			setholeinplatform(platforms[1], -256, 5120, false);
			setholeinplatform(platforms[2], -192, 5760,false);
			setholeinplatform(platforms[3], -256, 5120, false);
		}
		if (platformformation == 2)
		{
			setholeinplatform(platforms[1], 256, 512, false);
			setholeinplatform(platforms[3], 256, 512,false);
			//setholeinplatform(600 - 192, 288, 480,false);
			//setholeinplatform(600 - 352, 192, 576,true);
			setholeinplatform(platforms[2], 160-32, 608+32,true);
			//setholeinplatform(600 - 512, 256, 512, false);
			///setholeinplatform(platforms[3], 288, 480, false);
			
			//setholeinplatform(600 - 32, 288, 480, false);
			setholeinplatform(platforms[0], 160-32, 608+32,true);
			
			
			//addsectioninplatform(600 - 352, -1000, 96, false);
			//addsectioninplatform(600 - 352, 672, 2000, false);
			
			
			setplatformasplatform(platforms[1], false);
			setplatformasplatform(platforms[2], false);
			setplatformasplatform(platforms[3], false);
		}
		if (platformformation == 3)
		{
			
			setholeinplatform(platforms[1], 256, 512, false);
			setholeinplatform(platforms[2], 160-32, 608+32,true);
			setholeinplatform(platforms[3], 288, 480, false);
			
			//1st row
			addsectioninplatform(platforms[1], -1300, -128, true);
			addsectioninplatform(platforms[1], 960, 2000, true);
			//2nd row
			addsectioninplatform(platforms[2], -1300, -32, false);
			addsectioninplatform(platforms[2], 864, 2000, false);
			//3rd row
			addsectioninplatform(platforms[3], -1300, -160, true);
			addsectioninplatform(platforms[3], 992, 2000, true);
			
			
			setplatformasplatform(platforms[1], false);
			setplatformasplatform(platforms[2], false);
			setplatformasplatform(platforms[3], false);
		}
		currentformation = platformformation;
	}
	public function resetblocks()
	{
		var i = 0;
			while (i < entities.length)
			{
				
				var E = entities[i];
				var D:Dynamic = E;
				
				if (E.type == "Block")
				{
					var B:Block = D;
					//D.Defrost();
					B.Clean();
					//if (B.y == Y)
					{
						B.solid = true;
					}
				}
				i += 1;
			}
	}
	public function spawnplatform(Y:Float)
	{
		var xx = 0;
		xx -= 128 + 128;
		var L = new Array<Block>();
		while (xx < 928+128)
		{
			var block = new Block("block");
			block.x = xx;
			block.y = Y;
			block.solid = true;
			//AddObject(block);
			L[L.length] = block;
			xx += 32;
		}
		xx = 0;
		while (xx < L.length)
		{
			AddObject(L[xx],0);
			xx++;
		}
		platforms.push(L);
	}
	public function addsectioninplatform(platform:Array<Block>,minx:Float, maxx:Float, inverse:Bool)
	{
		var i = 0;
			while (i < platform.length)
			{
				
				var E = platform[i];
				var D:Dynamic = E;
				
				if (E.type == "Block")
				{
					var B:Block = D;
					var X = E.x;
					if (B.started)
					{
						X = E.OX;
					}
					//D.Defrost();
					//if (B.y == Y)
					{
						var ok = (X > minx && X < maxx);
						
						if (ok)
						{
							if (inverse)
							{
								ok = !ok;
							}
							B.solid = ok;
						}
					}
				}
				i += 1;
			}
	}
	public function setholeinplatform(platform:Array<Block>,minx:Float, maxx:Float, inverse:Bool)
	{
		var i = 0;
			while (i < platform.length)
			{
				
				var E = platform[i];
				var D:Dynamic = E;
				
				if (E.type == "Block")
				{
					var B:Block = D;
					var X = E.x;
					if (B.started)
					{
						X = E.OX;
					}
					//D.Defrost();
					//if (B.y == Y)
					{
						var ok = (X > minx && X < maxx);
						if (inverse)
						{
							ok = !ok;
						}
						B.solid = !ok;
					}
				}
				i += 1;
			}
	}
	public function setplatformasplatform(platform:Array<Block>,isplatform:Bool)
	{
		var i = 0;
			while (i < platform.length)
			{
				
				var E = platform[i];
				var D:Dynamic = E;
				
				if (E.type == "Block")
				{
					var B:Block = D;
					//if (B.y == Y)
					{
						B.platform = isplatform;
					}
				}
				i += 1;
			}
	}
	public function on_touchend(event:TouchEvent):Void {
		MSE = false; control[0] = false; control[1] = false; control[2] = false; control[3] = false;
	}
	public function on_touchbegin(event:TouchEvent):Void {
		 /*if (!touched)*/{Lib.current.stage.displayState = openfl.display.StageDisplayState.FULL_SCREEN;}MSE = true; touched = true;
	}
	public function on_mousedown(event:MouseEvent):Void {
		MSE = true;
	}
	public function on_mouseup(event:MouseEvent):Void {
		
		/*if (stage.allowsFullScreen)
		{Lib.current.stage.displayState = openfl.display.StageDisplayState.FULL_SCREEN; }*/
		if (!touched) {
			MSE = false; 
			control[0] = false; 
			control[1] = false; 
			control[2] = false; 
			control[3] = false;
			
			}
	}
	//get the our id used in netplay.
	private function GetNetworkID():String
	{
		if (online)
		{
			#if flash
			if (NP != null)
			{
				return NP.NID;
			}
			#end
		}
		else
		{
			return "Myself";
		}
		return "Myself";
	}
	private function UpdateBackground():Void
	{
		OBackground.bitmapData = Background.bitmapData;
		OBackground.visible = true;
		
		Background.bitmapData = getbackground();
		Background.alpha = 0;
	}
	private function PlayMusic(showlevel:Bool):Void
	{
		UpdateBackground();
		//////////////OBackground.bitmapData = Background.bitmapData;
		//////////////OBackground.visible = true;
		/*var L = Math.floor((level - 1) / 5);
		//var BGS = [57, 129, 89,98,131,185];
		if (L < 0)
			{
				L = 0;
			}
			while (L >= 6)
			{
				L -= 6;
			}*/
			updatelevelinfo();
		//var L = currentgeneralstage;
		var L = currentstage;
			/*var A = AL.GetAnimation("BG");
			
			Background.bitmapData = A[L];*/
			
			//Background.bitmapData = AL.GetAnimation("background-89")[0];
			//Background.bitmapData = AL.GetAnimation("background-"+BGS[L])[0];
			//////////////Background.bitmapData = getbackground();
			//////////////Background.alpha = 0;
			
		//L = Math.floor((level - 1) / 5);
		if (showlevel)
		{
			ShowLevel();
		}
		if (GameFlags.get(Main.AltMusic) || (playerspick == "benben" || playerspick == "yatsuhashi"))
		{
			L += 6;
		}
			var A:Array<Int> = [1,2,3,4,5,6,7,8,9,10,11,12];
			if (L < 0)
			{
				L = 0;
			}
			while (L >= A.length)
			{
				L -= A.length;
			}
		if (musicchannel == null || !myplayer.flags.get(Player.MusicSelector))
		{
			if (currentstagelevel < 4/* && GameFlags.get(Main.Adventure)*/ && (level>20 || GameFlags.get(Main.Adventure)))
			{
				musicchannel = SoundManager.PlayMusic("adv" + A[L % 6]);
			}
			else
			{
				musicchannel = SoundManager.PlayMusic("theme" + A[L]);
			}
		}
	}
	public function GetPlayer(ID:String):Player {
		if ((""+ID) == GetNetworkID())
		{
			ID = "Myself";
		}
		return Players[ID];
	}
	
	public function AddPlayer(P:Player) {
		Players[P.ID] = P;
		AddObject(P);
		if (P.playing < 90 && online)
		{
			P.invincibility = 150;
		}
		//attempt to force status update, so new players get info quicker.
		ControlEvent = true;
	}
	//spawn a gap
	public function SendGap()
	{
		if (Hoster)
		{
		var X = 20;
		var Y = 0;
		if (Math.random() > 0.5)
		{
			X = 800 - 20;
		}
		var R = Math.floor(4 * Math.random()) * 160;
		Y += R-32;
		var D:Dynamic = { };
		D.x = X;
		D.y = Y;
		D.UID = Math.random();
		SendEvent("SendGap", D);
		}		
	}
	public function RemovePlayer(P:String) {
		if (P != "Myself")
		{
			var player = Players[P];
			if (player != null)
			{
				player.alive = false;
				if (player.nameplate != null)
				{
					gamestage.removeChild(player.nameplate);
				}
				Players.remove(P);
				RemoveObject(player);
				//entities.remove(player);
				//entitylayer.removeChild(player);
			}
			
		}
	}
	private function AddEntityItem(E:EntityItem,layer:Int = 1) {
		AddObject(E,layer);
		activeItems[activeItems.length] = E;
	}
	private function AddEnemy(E:Enemy,layer:Int = 1) {
		AddObject(E,layer);
		//if (E.respawn)
		{
			activeEnemies[activeEnemies.length] = E;
		}
	}
	public function AddObject(E:Entity,layer:Int = -1) {
		if (E.interactable/* && activeInteractables.indexOf(E >= 0)*/)
		{
			activeInteractables[activeInteractables.length] = E;
		}
		entities[entities.length] = E;
		//addChild(E);
		if (layer == -1)
		{
			layer = E.layer;
		}
		if (layer == 2)
		{
			frontlayer.addChild(E);
		}
		else if (layer == 1)
		{
			entitylayer.addChild(E);
		}
		else if (layer == 0)
		{
			backlayer.addChild(E);
		}
	}
	private function RemoveEntityItem(I:Entity) {
		var D:Dynamic = I;
		RemoveObject(I);
		activeItems.remove(D);
	}
	private function RemoveEnemy(I:Entity) {
		var D:Dynamic = I;
		RemoveObject(I);
		activeEnemies.remove(D);
	}
	private function RemoveObject(I:Entity) {
		if (I.interactable && activeInteractables.indexOf(I) >= 0)
		{
			activeInteractables.remove(I);
		}
		//removeChild(I);
		entities.remove(I);
		if (frontlayer.contains(I))
		{
			frontlayer.removeChild(I);
		}
		else if (entitylayer.contains(I))
		{
			entitylayer.removeChild(I);
		}
		else if (backlayer.contains(I))
		{
			backlayer.removeChild(I);
		}
	}
	//retuns solid object at point
	public function CollisionDetectPoint(X:Float,Y:Float):Entity {
		var i = 0;
		var ret = null;
		var P = new Point(X, Y);
		while (i < collisiondata.length)
		{
			var c = collisiondata[i];
			var e:Entity = c.E;
			if (e.solid && c.B.containsPoint(P))
			{
				return e;
			}
			i++;
		}
		return ret;
	}
	//retuns collectables at point
	public function CollisionDetectPointItem(X:Float,Y:Float):EntityItem {
		var i = 0;
		var P = new Point(X, Y);
		while (i < activeItems.length)
		{
			var E = activeItems[i];
			var ok = true;
			if (Std.is(E, CarryItem))
			{
				var D:Dynamic = E;
				var C:CarryItem = D;
				if (C.holder != null)
				{
					ok = false;
				}
			}
			if (!E.killed && E.alive && ok)
			{
				if (E.GetHitbox().containsPoint(P))
				{
					return E;
				}
			}
			i += 1;
		}
		return null;
	}
	public function CollisionDetectPointPlayer(X:Float,Y:Float):Player {
		var i = 0;
		var PL = new Array<Player>();
		var A = Players.iterator();
		var P = new Point(X, Y);
		while (A.hasNext())
		{
			var E = A.next();
			if (!E.killed)
			{
				if (E.GetHitbox().containsPoint(P))
				{
					return E;
				}
			}
		}
		return null;
	}
	public function CollisionDetectPointEnemy(X:Float,Y:Float):Enemy {
		var i = 0;
		var P = new Point(X, Y);
		while (i < activeEnemies.length)
		{
			var E = activeEnemies[i];
			if (!E.killed)
			{
				if (E.GetHitbox().containsPoint(P))
				{
					return E;
				}
			}
			i += 1;
		}
		return null;
	}
	public function CollisionDetectPointDangerous(X:Float,Y:Float):Entity {
		var i = 0;
		var ret = null;
		var P = new Point(X, Y);
		/*while (i < entities.length)
		{
			var E = entities[i];
			if (E.dangerous && !E.killed && E.type != "Block")
			{
				if (E.GetHitbox().containsPoint(new Point(X,Y)))
				{
					ret = E;
					i = entities.length;
					return E;
				}
			}
			i += 1;
		}*/
		while (i < collisiondangerousdata.length)
		{
			var c = collisiondangerousdata[i];
			var e:Entity = c.E;
			if (e.dangerous && !e.killed && c.B.containsPoint(P))
			{
				return e;
			}
			i++;
		}
		return ret;
	}
	public function CollisionDetectTouchDangerous(target:Entity,hitbox:Bool=false):Entity {
		var i = 0;
		var R = target.getBounds(gamestage);
		if (hitbox)
		{
			R = target.GetHitbox();
		}
		/*while (i < entities.length)
		{
			var E = entities[i];
			
			if (E.dangerous && !E.killed && E.type != "Block")
			{
				if (R.intersects(E.getBounds(this)))
				{
					return E;
				}
			}
			i += 1;
		}*/
		while (i < collisiondangerousdata.length)
		{
			var c = collisiondangerousdata[i];
			var e:Entity = c.E;
			if (e.dangerous && !e.killed && R.intersects(c.B))
			{
				return e;
			}
			i++;
		}
		return null;
	}
	public function CollisionDetectTouchInteractable(target:Entity):Entity {
		var i = 0;
		var R = target.getBounds(gamestage);
		while (i < activeInteractables.length)
		{
			var E = activeInteractables[i];
			
			if (E.interactable && E.alive && E.readyinteract && !E.killed && E.type != "Block")
			{
				if (R.intersects(E.getBounds(gamestage))/*containsPoint(new Point(X,Y))*/)
				{
					return E;
				}
			}
			i += 1;
		}
		//return false;
		return null;
	}
	public function CollisionDetectTouchPlayer(target:Entity,hitbox:Bool=false):Player {
		var i = 0;
		var R = target.getBounds(gamestage);
		if (hitbox)
		{
			R = target.GetHitbox();
		}
		var A = GetPlayers();
		while (i < A.length)
		{
			var E = A[i];
			
			if (!E.killed)
			{
				if (R.intersects(E.getBounds(gamestage)))
				{
					return E;
				}
			}
			i += 1;
		}
		//return false;
		return null;
	}
	public function CollisionDetectTouchEnemy(target:Entity,hitbox:Bool=false):Enemy {
		var i = 0;
		var R = target.getBounds(gamestage);
		if (hitbox)
		{
			R = target.GetHitbox();
		}
		while (i < activeEnemies.length)
		{
			var E = activeEnemies[i];
			
			if (!E.killed)
			{
				if (R.intersects(E.getBounds(gamestage)))
				{
					return E;
				}
			}
			i += 1;
		}
		//return false;
		return null;
	}
	public function CollisionDetectTouchItem(target:Entity):EntityItem {
		var i = 0;
		var R = target.getBounds(gamestage);
		while (i < activeItems.length)
		{
			var E = activeItems[i];
			var ok = true;
			if (Std.is(E, CarryItem))
			{
				var D:Dynamic = E;
				var C:CarryItem = D;
				if (C.holder != null)
				{
					ok = false;
				}
			}
			if (!E.killed && ok)
			{
				if (R.intersects(E.getBounds(gamestage)))
				{
					return E;
				}
			}
			i += 1;
		}
		//return false;
		return null;
	}
	
	public function ismyplayer(E:Entity):Bool {
		if (E == null)
		{
			return false;
		}
		return (E.UID == myplayer.UID);
	}
	//process an event and pass the event along to other players
	public function SendEvent(evt:String, data:Dynamic) {
		var D:Dynamic = { };
		D.evt = evt;
		D.data = data;
		D.ID == GetNetworkID();
		#if flash
		if (online)
		{
			NP.SendData("E", D);
		}
		#end
		if (netlog)
		{
		if (!sentmessagelog.exists(evt))
		{
			sentmessagelog[evt] = 0;
		}
		sentmessagelog[evt]+=1;
		}
		ProcessEvent(D.evt,D.ID, D.data);
	}
	public function SendQueueEvent(evt:String, data:Dynamic, timer:Int,resend_onelapse:Bool=false)
	{
		var D:Dynamic = { };
		D.evt = evt;
		D.data = data;
		D.ID == GetNetworkID();
		D.timer = timer-1;
		#if flash
		if (online)
		{
			NP.SendData("Q", D);
		}
		#end
		if (netlog)
		{
		if (!sentmessagelog.exists(evt))
		{
			sentmessagelog[evt] = 0;
		}
		sentmessagelog[evt]+=1;
		}
		ProcessQueueEvent(evt, D.ID,data, timer,resend_onelapse);
	}
	public function ProcessQueueEvent(evt:String,ID:String, data:Dynamic, timer:Int,resend_onelapse:Bool=false)
	{
		var Q:EventQueue = new EventQueue(evt, data, ID, timer);
		Q.clientside = resend_onelapse;
		queuedevents.push(Q);
	}
	//this massive function handles most major events, doing it this way keeps the clients synced.
	//this could be broken up into smaller functions
	public function ProcessEvent(evt:String, ID:String, data:Dynamic) {
		if (ID == "Unknown" || ID == GetNetworkID() || ID == null)
		{
			ID = "Myself";
		}
		var P = GetPlayer(ID);
		//whether or not this event came from ourselves(used primarily in the case we have to send an event from within another event)
		var me = ismyplayer(P);
		
		if (netlog)
		{
		if (!me)
		{
			if (!recievedmessagelog.exists(evt))
			{
				recievedmessagelog[evt] = 0;
			}
			recievedmessagelog[evt]+=1;
		}
		}
		if (P != null)
		{
			//update the last activity frame to this frame(this is to let this client determine inactive/linkdead players)
			P.frame = frame;
		}
		if (lvllogic != null && lvllogic.OnProcessEvent(evt, P, data))
		{
			return;
		}
		if (evt == "ChangeCharacter")
		{
			if (P.charname != data.C)
			{
				P.charactersoul = data.A;
				P.init(data.C);
			}
		}
		if (evt == "StageSeal")
		{
			Sealed = data.timer;
		}
		if (evt == "DestroyBlock")
		{
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				//if (E.x == data.x && E.y == data.y && E.type == "Block")
				if (E.UID == data.UID && E.type == "Block")
				{
					var D:Dynamic = E;
					D.Destroy(data.Destroy);
					i = entities.length;
				}
				i++;
			}
		}
		if (evt == "PlayerDeath") {
			if (P != null)
			{
				P.cancel = false;
				P.ability.onattacked(!data);
				P.ChangeExpression("Eyes", "24", 45, true);
				P.ChangeExpression("Mouth", "2", 45);
				if (!P.cancel)
				{
				if (data)
				{
					if (P.myMyon != null && P.myMyon.holder == P && P.myMyon.alive)
					{
						if (P.myMyon.HP > 1)
						{
							P.myMyon.HP -= 1;
						}
						else
						{
							P.myMyon.alive = false;
							P.myMyon = null;
						}
					}
					P.invincibility = 90;
				}
				else
				{
					P.killed = true;
					P.Vspeed = -9;
					SoundManager.Play("died");
					
					P.ChangeExpression("Eyes", "8", 150, true);
					P.ChangeExpression("Mouth", "66", 150);
				}
				}
			}
			else
			{
				TF.text = "'No one'\ndied???";
			}
		}
		if (evt == "Attack") {
			var E:Enemy = todyn(EntityFromUID(data));
			if (E.attack(P))
			{
				ProcessEvent("Kill", ID, data);
			}
		}
		if (evt == "Explodify") {
			var E:Enemy = todyn(EntityFromUID(data));
			if (E.attack(P))
			{
				//ProcessEvent("Kill", ID, data);
				ProcessEvent("Remove", ID, data);
			}
		}
		if (evt == "Remove")
		{
			var E = EntityFromUID(data);
			if (E != null)
			{
				E.alive = false;
				E.killed = true;
			}
		}
		if (evt == "Kill" || evt == "Destroy" || evt == "Obliterate") {
			var E = EntityFromUID(data);
			if (E != null && !E.killed)
			{
				if (evt != "Destroy")
				{
					
					E.bonkedby = P;
					P.combo++;
					//P.combotime = 75;
					P.combotime = 90;
					P.ability.onkill(E);
					if (P.combo > 2 && P.isme)
					{
						awardmoney(1);
					}
				}
				if (evt == "Obliterate")
				{
					E.y = 601;
				}
				if (evt == "Kill" && me && E.myMyon != null/* && P.myMyon == null*/)
				{
					
					
					var ok = (P.myMyon == null);
					if (!ok && (myplayer.flags.get(Player.DoubleMyon) || (E.myMyon.dualcarry || P.myMyon.dualcarry)))
					{
						var i = 0;
						var count = 0;
						while (i < activeItems.length)
						{
							var E = activeItems[i];
							if (E.alive && E.subtype == "Myon")
							{
								var D:Dynamic = E;
								if (D.holder == myplayer)
								{
									count++;
								}
							}
							i++;
						}
						if (count < 2)
						{
							ok = true;
						}
					}
					if (ok)
					{
						SendEvent("StealMyon", E.myMyon.UID);
					}
				}
				E.killed = true;
				if (E.type == "Carryitem" || E.type == "Item")
				{
					//items being requested for this want to be removed immediatly
					RemoveEntityItem(E);
					
				}
				var D:Dynamic = E;
				if (/*me && */D.charname == "Cirno")
				{
					if (D.alive)
					{
						D.killed = true;
					}
				}
				if ((me || evt == "Destroy") && D.charname == "Imposter")
				{
					//if an unlockable character(aka imposter) is killed, unlock the character.
					unlockcharacter(D.rename);
				}
				if (totalenemies != 1)
				{
					SoundManager.Play("killenemy");
				}
				else
				{
					var D:Dynamic = E;
					if (E.type == "Enemy" && D.enraged)
					{
						SoundManager.Play("finalkill");
					}
					else
					{
						SoundManager.Play("killenemy");
					}
					//delay end of level music
					SpawnTimer = 60;
				}
				if (!me)
				{
					E.catchup();
				}
				if (P != null && (evt == "Kill" || evt == "Obliterate"))
				{
					if (E.type == "Enemy")
					{
						P.score += D.pointvalue;
					}
				}
				
			}
		}
		if (evt == "SpawnEnemy" || evt == "SpawnItem")
		{
			
			var E = AddEntityFromData(data);
			if (evt == "SpawnEnemy")
			{
				if (E != null)
				{
				if (E.respawn)
				{
					spawns++;
				}
				}
				else
				{
					//need a breakpoint here to investigate.
					E = null;
				}
			}
			if (me)
			{
				if (online)
				{
					#if flash
					NP.Flush();
					#end
				}
				if (SpawnList.length > 0)
				{
					if (SpawnList.first().charname == data.type)
					{
						SpawnList.pop();
					}
				}
			}
		}
		if (evt == "Headbonk")
		{
			var E = EntityFromUID(data);
			if (E != null)
			{
				if (E == powblock)
				{
					if (Hoster && powblock.HP > 0)
					{
						var D:Dynamic = { };
						D.HP = powblock.HP;
						if (!(P.flags.get(Player.PreservePowBlock) && Math.random() > 0.5))
						{
							D.HP = powblock.HP - 1;
						}
						if (gamemode.infinitepowblock)
						{
							D.HP = 4;
						}
						if (me)
						{
							D.ID = GetNetworkID();
						}
						else
						{
							D.ID = ID;
						}
						SendEvent("POW!", D);
					}
				}
				else if (E.type == "MiniPowBlock" && E.alive)
				{
					E.alive = false;
					minipowactive = false;
					if (Hoster)
					{
						var D:Dynamic = { };
						if (me)
						{
							D.ID = GetNetworkID();
						}
						else
						{
							D.ID = ID;
						}
						SendEvent("POW!", D);
					}
				}
				else
				{
					//E.bonked = 10;
					//E.bonked = 16;
					//E.bonkedby = P;
					E.Bonk(P);
				
					SoundManager.Play("bonk");
				}
			}
		}
		if (evt == "TotalEnemies")
		{
			totalenemies = data;
			roundstarted = true;
		}
		if (evt == "NextLevel")
		{
			var R = TypeofRound.createByIndex(data.RoundType);
			
			if (!Hoster)
			{
				maxspawns = 0;
			}
			if (lvllogic != null)
			{
				lvllogic.end();
				lvllogic = null;
			}
			
			boss = null;
			minipowspawns = 0;
			RoundType = R;
			gamestage.x = 0;
			gamestage.y = 0;
			gamestage.scaleX = 1;
			gamestage.scaleY = 1;
			successstreak++;
			mysuccessstreak++;
			objectiveprogress++;
			if (gamemode.rewardrequirement > 0 && objectiveprogress>=gamemode.rewardrequirement)
			{
				objectiveprogress = 0;
				awardmoney(gamemode.reward);
				if (!gamemode.getcleared())
				{
					ShowMessage(gamemode.fullname +" cleared,");
					gamemode.setcleared(true);
				}
				else
				{
					ShowMessage("Objective reached,");
				}
				ShowMessage("awarded:" + gamemode.reward + "Mon!");
				
				//do gamemode unlock here.
				if (gamemode.unlock != "")
				{
					var G = GameMode.GetModeByName(gamemode.unlock);
					if (G != null)
					{
						if (!G.getunlocked())
						{
							G.setunlocked(true);
							var N = G.fullname;
							if (G.category != "")
							{
								N = N + " " + G.category;
							}
							ShowMessage(N + " is now available!");
						}
					}
				}
				Main._this.savedata.flush();
			}
			var T = level % levelsperstage;
			if (mysuccessstreak > 4)
			{
				//var L = level - 1;
				//var stage = Math.floor((L) / 5);

				//var generalstage = stage % 6;
				
				if (T == 1)
				{
					awardmoney((rank + 1) * 3);
					//Main._this.savedata.data.shop_ticks = Main._this.savedata.data.shop_ticks + 2;
					//Main._this.savedata.data.shop_ticks = Main._this.savedata.data.shop_ticks + 3;
				}
			}
			/*if (T == 1)
			{
				Main._this.savedata.data.shop_ticks = Main._this.savedata.data.shop_ticks + 4;
			}*/
			Main._this.savedata.data.shop_ticks = Main._this.savedata.data.shop_ticks + 1;
			if (myplayer.score > HighScore && !Main._this.cheating/* && GameFlags.getactiveflags().length==0*/)
				{
					HighScore = myplayer.score;
					sethighscore(HighScore);
					//Main._this.savedata.data.highscore = HighScore;
				}
			ufos = 0;
			spawns = 0;
			roundstarted = false;
			level = data.level;
			updatelevelinfo();
			if (!online)
			{
				/*if (Main._this.savedata.data.maxlevel < level)
				{
					Main._this.savedata.data.maxlevel = level;
				}*/
				var ml:Int = getmaxlevel();
				if (ml < level)
				{
					setmaxlevel(level);
				}
				/*if (level > levelsperrank && !Main._this.savedata.data.challenges[0])
				{
					ShowMessage("Danmaku challenge");
					ShowMessage("is now available!");
					Main._this.savedata.data.challenges[0] = true;
				}
				if (level > (levelsperrank*2) && !Main._this.savedata.data.challenges[3])
				{
					ShowMessage("All Star Mode");
					ShowMessage("is now available!");
					Main._this.savedata.data.challenges[3] = true;
				}
				if (level > (levelsperrank*3) && !Main._this.savedata.data.challenges[1])
				{
					ShowMessage("Boss Rush challenge");
					ShowMessage("is now available!");
					Main._this.savedata.data.challenges[0] = true;
				}*/
			}
			else
			{
				if (mysuccessstreak>3 && getmaxlevel() < level)
				{
					setmaxlevel(level);
				}
			}
			/*var L = level - 1;
			if (L < 0)
			{
				L = 0;
			}
			rank = Math.floor(L / 30);*/
			updatelevelinfo();
			//ShowLevel();
			//call playmusic() as it will change song if its new
			
			SoundManager.PlayJingle("nextlevel").addEventListener(Event.SOUND_COMPLETE, function(e:Event):Void { PlayMusic(Hoster); } );
			UpdateBackground();
			var i = 0;
			while (i < entities.length)
			{
				
				var E = entities[i];
				var D:Dynamic = E;
				if (E.type == "Block" && RoundType != TypeofRound.EventCirno && RoundType != TypeofRound.EventFireCirno && RoundType != TypeofRound.EventElectricCirno && RoundType != TypeofRound.EventCirnoBoss)
				{
					D.Reset();
				}
				if (E.removeonlevelend)
				{
					if (E.type == "Enemy")
					{
						D.reward = false;
					}
					E.killed = true;
					E.alive = false;
				}
				/*if (E.type == "Enemy")
				{
					D.reward = false;
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Gap")
				{
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Lava")
				{
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Bullet" || E.type == "NoWrap")
				{
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Table")
				{
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Yuuka")
				{
					E.killed = true;
					E.alive = false;
				}*/
				/*if (E.type == "Carryitem" && D.DestroyOnRoundEnd)
				{
					E.killed = true;
					E.alive = false;
				}*/
				
				if (E.type == "MasterSpark")
				{
					D.Size = 0;
					D.Time = - 1000;
				}
				if (E.type == "Lightning")
				{
					D.Time = - 1000;
				}
				i += 1;
			}
			trophyactive = false;
			//yuukaactive = false;
			yuukasactive = 0;
		}
		if (evt == "Bump")
		{
			var E = EntityFromUID(data.UID);
			if (E != null && E.Vspeed>=0)
			{
				E.x = data.x;
				E.y = data.y;
				E.Hspeed = data.Hspeed;
				E.Vspeed = data.Vspeed;
				E.bump(P);
				if (E != P)
				{
					P.ability.onbump(E);
				}
				
				if (!me)
				{
					E.catchup();
				}
			}
		}
		if (evt == "Camera")
		{
			var i = 0;
			FlashColor(0xFFFF77, 0.4, 0, 0.1);
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Bullet" && (RoundType != TypeofRound.EventNoWrap))
				{
					E.killed = true;
					E.alive = false;
					if (Hoster)
					{
						var D:Dynamic = { };
							
						D.type = "Point";
						D.UID = Math.random();
						if (Math.random() > 0.5)
						{
							D.Ldir = -1;
						}
						else
						{
							D.Ldir = 1;
						}
						D.x = E.x;
						D.y = E.y;
						SendEvent("SpawnItem", D);
					}
				}
				if (E.type == "FireBar" || E.type == "Carousel")
				{
					E.killed = true;
					E.alive = false;
					if (Hoster)
					{
						var D:Dynamic = E;
						D.camera();
					}
				}
				i++;
			}
		}
		if (evt == "Fairplay")
		{
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				var D:Dynamic = E;
				/*if ((E.type == "Enemy" && activeEnemies.indexOf(E) < 0) || E.type == "Bullet" || E.type == "MasterSpark")
				{
					
				}*/
				var ok = true;
				if (E.subtype == "UFO")
				{
					D.fuel = 0;
					ok = false;
				}
				if (E.type == "Gap")
				{
					E.killed = true;
					E.alive = false;
					ok = false;
				}
				if (E.type == "Bullet" && (RoundType != TypeofRound.EventNoWrap))
				{
					E.killed = true;
					E.alive = false;
					ok = false;
				}
				if (E.type == "Yuuka")
				{
					E.killed = true;
					E.alive = false;
					ok = false;
				}
				if (E.type == "MasterSpark")
				{
					D.Size = 0;
					D.Time = - 1000;
					ok = false;
				}
				if (E.type == "Lightning")
				{
					D.Time = - 1000;
					ok = false;
				}
				if (E.type == "Enemy" && (activeEnemies.indexOf(D) < 0 || !D.needtokill) && ok)
				{
					D.reward = false;
					E.killed = true;
					E.alive = false;
				}
				i++;
			}
		}
		if (evt == "Mission Failed")
		{
			myplayer.visible = false;
			//myplayer.y = 1000;
			myplayer.hide = true;
			if (Hoster)
			{
				SendEvent("GameOver", null);
			}
			//ProcessEvent("GameOver", "Myself", null);
		}
		if (evt == "PlayerRespawn")
		{
			P.x = data.x;
			P.y = data.y;
			P.lives = data.lives;
			P.Hspeed = 0;
			P.Vspeed = 0;
			P.rotation = 0;
			P.killed = false;
			//P.expressiontime = 0;
			P.ChangeExpression("Eyes", "1", 120, true);
			P.ChangeExpression("Mouth", "66", 120);
			if (P.lives < 0)
				{
					//do game over things
					P.visible = false;
					if (me)
					{
						SendEvent("GameOver", null);
					}
				}
				else
				{
					SoundManager.Play("respawn");
					P.invincibility = 150;
					P.ability.onrespawn();
				}
				if (!me)
				{
					P.catchup();
				}
		}
		if (evt == "GameOver")
		{
			successstreak = 0;
			if (me || !gamemode.cancontinue)
			{
				if (me)
				{
					mysuccessstreak = 0;
				}
				else
				{
					var T = gameoverdescription;
					T.text = P.name +" has game overed.";
					T.textColor = 0xFFFFFF;
					T.width = T.textWidth + 8;
					T.height = T.textHeight + 8;
				}
				SoundManager.PlayJingle("gameover").addEventListener(Event.SOUND_COMPLETE, function(e:Event):Void 
				{
					if (!online && !gamemode.cancontinue)
					{
						//status = "quitting";
						SoundManager.StopMusic();
						paused = true;
						gameoverscreen.visible = true;
						return;
					}
					/*if (online)*/{ SendEvent("Continue", null); }} 
				);
				gameover.visible = true;
				if (myplayer.score > HighScore)
				{
					HighScore = myplayer.score;
					sethighscore(HighScore);
					//Main._this.savedata.data.highscore = HighScore;
				}
			}
		}
		if (evt == "RefreshPowBlock" && allowpowblock)
		{
			powblock.HP = 4;
			powblock.scaleY = 1;
			powblock.solid = true;
			powblock.visible = true;
			if (Hoster)
			{
				ControlEvent = true;
			}
		}
		if (evt == "Continue")
		{
			if (P.isme)
			{
				if (GameFlags.get(Main.AllStar))
				{
					var D:Dynamic = { };
					D.C = "red_fairy";
					D.A = "";
					SendEvent("ChangeCharacter", D);
					//SendEvent("ChangeCharacter", "red_fairy");
					getcharacter("red_fairy");
				}
			}
			P.lives = startinglives;
			P.lifefragments = 0;
			P.ability.oncontinue();
			/*if (level > 0 && level % 5 != 1)
			{
				level--;
			}*/
			if (me)
			{
				//save highscore here
			}
			P.score = 0;
			P.spentscore = 0;
			if (me)
			{
				gameover.visible = false;
			var D:Dynamic = { };
			D.x = 400;
			D.y = 0;
			D.lives = P.lives;
			
			SendEvent("PlayerRespawn", D);
			}
		}
		//sync any general changes going on.
		if (evt == "S")
		{
			HostPlayer = P;
			//"Status" event
			if (data.lvl > level)
			{
				level = data.lvl;
				/*var L = level - 1;
				if (L < 0)
				{
					L = 0;
				}
				rank = Math.floor(L / 30);*/
				updatelevelinfo();
				PlayMusic(true);
				
			}
			scrollX = 0;
			scrollY = 0;
			if (data.sx != null)
			{
			scrollX = data.sx;
			}
			if (data.sy != null)
			{
			scrollY = data.sy;
			}
			scrollspeedX = 0;
			scrollspeedY = 0;
			if (data.Sx != null)
			{
				scrollspeedX = data.Sx;
			}
			if (data.Sy != null)
			{
				scrollspeedY = data.Sy;
			}
			level = data.lvl;
			totalenemies = data.TE;
			if (!Hoster && totalenemies > maxspawns)
			{
				maxspawns = totalenemies;
				//SpawnList.clear();
				//populatespawnlist();
			}
			sessionID = data.SID;
			if (Main._this.lastsession != null && sessionID == Main._this.lastsession.sessionID)
			{
				if (Main._this.lastsession.lives >= 0)
				{
					SendEvent("loadsession", Main._this.lastsession);
				}
				Main._this.lastsession = null;
			}
			var R = TypeofRound.createByIndex(data.RT);
			if (RoundType != R)
			{
				if (lvllogic != null)
				{
					lvllogic.end();
					lvllogic = null;
				}
			}
			/*if (RoundType != R)
			{
				if (R == TypeofRound.EventTable)
				{
					ProcessEvent("Spawntables", "Myself", null);
				}
				if (R == TypeofRound.EventNoWrap)
				{
					ProcessEvent("NoWrap", "Myself", null);
				}
				if (R == TypeofRound.EventCirno || R == TypeofRound.EventFireCirno || R == TypeofRound.EventElectricCirno || R == TypeofRound.EventCirnoBoss)
				{
					ProcessEvent("FreezeWorld", "Myself", null);
				}
			}*/
			RoundType = R;
			///gamemode = data.gamemode;
			var G = data.GF;
			GameFlags = new FlagManager(1);
			GameFlags.data = G;
			if (GameFlags.get(Main.KonamiCode))
			{
				if (frame < 120)
				{
					startinglives = 30;
					myplayer.lives = 30;
				}
			}
			//if (data.HP != powblock.HP)
			if (allowpowblock)
			{
				powblock.HP = data.HP;
				if (powblock.HP == 0)
				{
					powblock.visible = false;
					powblock.solid = false;
				}
				else
				{
					powblock.visible = true;
					powblock.scaleY = (powblock.HP * 0.25);
					powblock.solid = true;
				}
			}
			else
			{
				powblock.visible = false;
				powblock.solid = false;
			}
			if (data.AE != activeEnemies.length && syncdelay<1)
			{
				//ask hoster to resend current enemy states.
				SendEvent("EnemySync", null);
				syncdelay = 60;
			}
			if (data.AI != activeItems.length && syncdelay<1)
			{
				//ask hoster to resend current item states.
				SendEvent("ItemSync", null);
				syncdelay = 60;
			}
		}
		if (evt == "EnemySync" && Hoster && syncdelay<1)
		{
			var i = 0;
			var dat:Dynamic = { };
			//var DD = new Array<Dynamic>();
			var DD = new Array<Float>();
			dat.enemies = DD;
			while (i < activeEnemies.length)
			{
				var E = activeEnemies[i];
				DD[DD.length] = E.UID;
				i += 1;
			}
			SendEvent("EnemyList", dat);
		}
		if (evt == "RequestEnemies" && Hoster)
		{
			var i = 0;
			var dat:Dynamic = { };
			var DD = new Array<Dynamic>();
			//var DD = new Array<Float>();
			dat.enemies = DD;
			var missing:Array<Float> = data;
			//while (i < activeEnemies.length)
			while (i < missing.length)
			{
				//var E = activeEnemies[i];
				var EE:Dynamic = EntityFromUID(missing[i]);
				var E:Enemy = EE;
				//var E = EntityFromUID(missing[i]);
				if (E != null)
				{
				var D:Dynamic = { };
				D.UID = E.UID;
				D.y = E.y;
				D.x = E.x;
				D.Ldir = E.Ldir;
				D.alive = E.alive;
				D.Hspeed = E.Hspeed;
				D.Vspeed = E.Vspeed;
				D.visible = E.visible;
				D.type = E.charname;
				D.rank = E.rank;
				D.spawns = E.spawns;
				DD[DD.length] = D;
				}
				i += 1;
			}
			SendEvent("EnemyReport", dat);
		}
		if ((evt == "EnemyList" || evt=="ItemList") && !Hoster)
		{
			var DD:Array<Float> = null;
			if (evt == "EnemyList")
			{
				DD = data.enemies;
			}
			if (evt == "ItemList")
			{
				DD = data.items;
			}
			var missing:Array<Float> = new Array<Float>();
			var i = 0;
			while (i < DD.length)
			{
				var D = DD[i];
				if (EntityFromUID(D) == null)
				{
					missing[missing.length] = D;
				}
				i++;
			}
			if (missing.length > 0)
			{
				if (evt == "EnemyList")
				{
					SendEvent("RequestEnemies", missing);
				}
				if (evt == "ItemList")
				{
					//DD = data.items;
					SendEvent("RequestItems", missing);
				}
			}
			syncdelay = 60;
		}
		if ((evt == "EnemyReport" || evt == "ItemReport") && !Hoster)
		{
			var DD:Array<Dynamic> = null;
			if (evt == "EnemyReport")
			{
				DD = data.enemies;
			}
			if (evt == "ItemReport")
			{
				DD = data.items;
			}
			var i = 0;
			while (i < DD.length)
			{
				var D = DD[i];
				if (EntityFromUID(D.UID) == null)
				{
					var R = AddEntityFromData(D);
					if (R != null && R.type=="Carryitem")
					{
						//prevent synced carryitems from working...they need extra work to be functional,so this is a ghetto fix to prevent multiple people holding the same item...
						R.holder = entities[0];
						R.visible = false;
					}
				}
				i += 1;
			}
		}
		if (evt == "RequestItems" && Hoster)
		{
			var i = 0;
			var dat:Dynamic = { };
			var DD = new Array<Dynamic>();
			dat.items = DD;
				var missing:Array<Float> = data;
			while (i < missing.length)
			{
				var EE:Dynamic = EntityFromUID(missing[i]);
				var E:EntityItem = EE;
				if (E != null)
				{
				var D:Dynamic = { };
				D.UID = E.UID;
				D.y = E.y;
				D.x = E.x;
				D.Ldir = E.Ldir;
				D.alive = E.alive;
				D.Hspeed = E.Hspeed;
				D.Vspeed = E.Vspeed ;
				D.visible = E.visible;
				D.type = E.charname;
				DD[DD.length] = D;
				}
				i += 1;
			}
			SendEvent("ItemReport", dat);
		}
		if (evt == "ItemSync" && Hoster && syncdelay<1)
		{
			var i = 0;
			var dat:Dynamic = { };
			var DD = new Array<Float>();
			dat.items = DD;
			while (i < activeItems.length)
			{
				var E = activeItems[i];
				DD[DD.length] = E.UID;
				i += 1;
			}
			SendEvent("ItemList", dat);
			syncdelay = 60;
		}
		//pick up item event
		if (evt == "Collect")
		{
			if (P != null)
			{
				
				if (data < 0)
				{
					var D:Dynamic = EntityFromUID( -data);
					if (D != null)
					{
					D.alive = false;
					D.killed = true;
					P.ability.oncollect(D);
					}
				}
				else
				{
					var D:Dynamic = EntityFromUID(data);
					if (D != null && D.alive)
					{
						P.ability.oncollect(D);
						D.Collect(P);
					}
				}
			}
		}
		if (evt == "Take")
		{
			var D:Dynamic = EntityFromUID(data.target);
			D.holder = EntityFromUID(data.UID);
		}
		if (evt == "PoisonPlatform")
		{
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block" && E.y == data)
				{
					var D:Dynamic = E;
					D.Poison();
					//E.bonked = 8;
					//E.bonkedby = GetPlayer(ID);
				}
				i++;
			}
		}
		if (evt == "Earthquake")
		{
			SoundManager.Play("pow");
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block" && E.y == data)
				{
					//E.bonked = 16;
					//E.bonkedby = GetPlayer(ID);
					E.Bonk(GetPlayer(ID));
				}
				i++;
			}
			if (thegiant.active && thegiant.rotation == 0)
			{
				thegiant.tipover();
				if (myplayer == P)
				{
					unlockcharacter(thegiant.unlock);
				}
			}
		}
		if (evt == "BounceEntities")
		{
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				var D:Dynamic = E;
				if (E.type == "Bullet" || E.type=="Enemy")
				{
					E.Hspeed *= -1;
					E.Vspeed *= -1;
					E.Ldir *= -1;
					if (E.subtype == "DanmakuBullet")
					{
						D.currot += 3.14;
					}
					if (E.type == "Bullet")
					{
						D.gravX *= -1;
						D.gravY *= -1;
					}
					//E.bonked = 8;
					//E.bonkedby = GetPlayer(ID);
				}
				if (E.subtype == "UFO")
				{
					D.fuel = 0;
				}
				if (E.type == "MasterSpark")
				{
					if (D.Time > 60)
					{
						SoundManager.Play("killenemy");
						if (Hoster)
						{
							var D:Dynamic = { };
							
							D.type = "GiantPoint";
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
							SendEvent("SpawnItem", D);
						}
					}
					D.Time = 0;
					D.Size = 0;
				}
				i++;
			}
		}
		//pow block used
		if (evt == "POW!")
		{
			if (data.HP != null)
			{
				powblock.HP = data.HP;
			}
			SoundManager.Play("pow");
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block")
				{
					//E.bonked = 16;
					//E.bonkedby = GetPlayer(ID);
					E.Bonk(GetPlayer(ID));
				}
				i++;
			}
			if (powblock.HP == 0 || !allowpowblock)
			{
				powblock.visible = false;
				powblock.solid = false;
			}
			else
			{
				powblock.scaleY = (powblock.HP * 0.25);
				powblock.solid = true;
				powblock.visible = true;
			}
			if (thegiant.active && thegiant.rotation == 0)
			{
				thegiant.tipover();
				if (myplayer == P)
				{
					unlockcharacter(thegiant.unlock);
				}
			}
		}
		if (evt == "Enrage")
		{
			var D:Dynamic = EntityFromUID(data);
			if (D != null && D.type == "Enemy")
			{
				D.enrage();
				D.enraged = true;
				D.enrageable = false;
				if (!Hoster)
				{
					D.catchup();
				}
			}
		}
		if (evt == "SendGap")
		{
			var E = new EntityGap();
			E.x = data.x;
			E.y = data.y;
			E.UID = data.UID;
			AddObject(E);
		}
		if (evt == "Cirnobomb")
		{
			var i = 0;
			var C:Dynamic = EntityFromUID(data.UID);
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block" && E.y == data.y && E.x>=0 && E.x<800 && E.x >= data.minx  && E.x <= data.maxx)
				{
					//E.icy = true;
					var D:Dynamic = E;
					if (C.flaming)
					{
						D.Burn();
					}
					else
					{
						D.Freeze();
					}
				}
				if (E.UID == data.UID)
				{
					E.killed = true;
					E.alive = false;
					if (C.electric && Hoster)
					{
						var D:Dynamic = { };
						D.x = C.x-115;
						SendEvent("LightningStrike", D);
					}
					else if (C.death && Hoster)
					{
						SendEvent("killeveryone", null);
					}
				}
				i += 1;
			}
		}
		if (evt == "killeveryone")
		{
			killeveryone();
		}
		if (evt == "RefreshBlocks")
		{
			var i = 0;
			while (i < entities.length)
			{
				if (entities[i].type == "Block")
				{
					var D:Dynamic = entities[i];
					D.Clean();
					FlashColor(0xFFFFFF, 0.4, 0, 0.1);
				}
				i++;
			}
		}
		if (evt == "ClearSpawnList")
		{
			SpawnList.clear();
		}
		if (evt == "CharWorld")
		{
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block"/* && E.y == data.y && E.x>=0 && E.x<800*/)
				{
					//E.icy = true;
					var D:Dynamic = E;
					D.Char();
				}
				i += 1;
			}
			FlashColor(0xFF0000, 0.4, 0, 0.1);
		}
		if (evt == "UFOStrike" && !myplayer.flags.get(Player.FriendlyUFO))
		{
			
			var E:Dynamic = EntityFromUID(data.UID);
			var S = "";
			if (E.subtype == "UFO")
			{
				S = E.ufotype;
			}
			if (E.subtype == "RainbowUFO")
			{
				S = E.ufotype;
			}
			//var D:UFO = E;
			//trace("UFO strike confirmed!");
			if (S == "Red")
			{
				//trace("Red pattern detected!");
				var O = new Bullet();
				O.x = E.x;
				O.y = E.y;
				O.Hspeed = -2;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = E.x;
				O.y = E.y;
				O.Hspeed = -3;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = E.x;
				O.y = E.y;
				O.Hspeed = 2;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = E.x;
				O.y = E.y;
				O.Hspeed = 3;
				O.Vspeed = 4;
				AddObject(O);
			}
			if (S == "Green")
			{
				//trace("Green pattern detected!");
				var O = new Bullet();
				O.x = E.x-10;
				O.y = E.y;
				O.Hspeed = 0;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = E.x+10;
				O.y = E.y;
				O.Hspeed = 0;
				O.Vspeed = 4;
				AddObject(O);
			}
			if (S == "Blue")
			{
				//trace("Blue pattern detected!");
				var O = new Bullet();
				O.x = E.x;
				O.y = E.y;
				O.Hspeed = 0;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = E.x;
				O.y = E.y;
				O.Hspeed = 2;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = E.x;
				O.y = E.y;
				O.Hspeed = -2;
				O.Vspeed = 4;
				AddObject(O);
			}
		}
		if (evt == "SummonBlackHole")
		{
			var E = new BlackHole();
			E.thrownby = P;
			E.x = data.x;
			E.y = data.y;
			E.Ldir = data.dir;
			AddObject(E);
		}
		if (evt == "SummonRainbowUFO")
		{
			var E = new RainbowUFO();
			E.x = data.UID * 800;
			E.y = -200;
			E.UID = data.UID;
			E.bonuscolor = data.color;
			//ufoseal = 2400;
			ufoseal = 600;
			AddEnemy(E);
			SoundManager.Play("summonufo");
			if (Hoster)
			{
				SendEvent("Fairplay", null);
			}
		}
		if (evt == "PlayerDanmaku")
		{
			//var E:Dynamic = EntityFromUID(data.UID);
			var O = new PlayerBullet();
			O.tossedBy = P;
			/*O.x = data.x;
			O.y = data.y;//+10;
			O.Hspeed = data.Hspeed;
			O.Vspeed = data.Vspeed;
			O.gravX = data.gravX;
			O.gravY = data.gravY;
			O.scaleX = data.scale;
			O.scaleY = data.scale;
			O.tossedBy = P;
			O.bounces = false;
			if (data.bounces != null)
			{
				O.bounces = data.bounces;
			}
			if (data.HP != null)
			{
				O.HP = data.HP;
			}
			if (data.spin != null)
			{
				O.spin = data.spin;
			}
			if (data.topbounce != null)
			{
				O.topbounce = data.topbounce;
			}
			if (data.bouncedrain != null)
			{
				O.bouncedrain = data.bouncedrain;
			}
			if (data.bumps != null)
			{
				O.bumps = data.bumps;
			}
			if (data.rolls != null)
			{
				O.rolls = data.rolls;
			}
			O.image.image_speed = 1;
			if (data.image_speed != null)
			{
				O.image.image_speed = data.image_speed;
			}
			
			
			
			O.allowwrap = data.wrap;*/
			O.image.image_speed = 1;
			CopyBulletData(data, O);
			if (O.Hspeed >= 0 || data.rotated == true)
			{
				O.ChangeAnimation(data.type);
			}
			else
			{
				O.ChangeAnimation(data.type+"F");
			}
			AddObject(O);
		}
		if (evt == "Web")
		{
			var W = new SpiderWeb();
			W.x = data.x;
			W.y = data.y;
			W.duration = data.d;
			W.player = P;
			AddObject(W);
		}
		if (evt == "HeadCannon")
		{
			var O = new SekibankiBullet();
			O.faulty = data.faulty;
			O.explosive = data.explosive;
			O.x = P.x;
			O.y = P.y;//+10;
			O.Hspeed = 0;
			O.Vspeed = 0;
			O.gravX = 0;
			O.gravY = -1;
			O.scaleX = P.scaleX;
			O.scaleY = P.scaleX;
			O.tossedBy = P;
			O.bounces = false;
			/*if (data.bounces != null)
			{
				O.bounces = data.bounces;
			}
			if (data.HP != null)
			{
				O.HP = data.HP;
			}
			if (data.topbounce != null)
			{
				O.topbounce = data.topbounce;
			}
			if (data.bouncedrain != null)
			{
				O.bouncedrain = data.bouncedrain;
			}*/
			
			O.image.image_speed = 1;
			O.allowwrap = data.wrap;
			P.charname = "sekibankiheadless";
			if (P.Ldir>0)
			{
				O.ChangeAnimation("sekibankihead");
				P.ChangeAnimation(P.charname);
			}
			else
			{
				O.ChangeAnimation("sekibankihead" + "F");
				P.ChangeAnimation(P.charname+"F");
			}
			AddObject(O);
			P.cooldown = P.maxcooldown;
			
		}
		//fires a diamond shape of bullets
		if (evt == "ChenDanmaku")
		{
			var E:Dynamic = EntityFromUID(data.UID);
			var D:Enemy = E;
			
			var O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = -2;
				O.Vspeed = 2;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 0;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 2;
				O.Vspeed = 2;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 4;
				O.Vspeed = 0;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = -4;
				O.Vspeed = 0;
				AddObject(O);
				
				//
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = -2;
				O.Vspeed = -2;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 0;
				O.Vspeed = -4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 2;
				O.Vspeed = -2;
				AddObject(O);
				O = new Bullet();
				
				
		}
				
		//it's seija time(screen flip)
		if (evt == "FLIP!")
		{
			if (!myplayer.flags.get(Player.FlipResistance))
			{
			if (Math.random() > 0.5)
			{
				if (gamestage.scaleY == 1)
				{
					gamestage.scaleY = -1;
					gamestage.y = 600;
				}
				else
				{
					gamestage.scaleY = 1;
					gamestage.y = 0;
				}
			}
			else
			{
				if (gamestage.scaleX == 1)
				{
					gamestage.scaleX = -1;
					gamestage.x = 800;
				}
				else
				{
					gamestage.scaleX = 1;
					gamestage.x = 0;
				}
			}
			}
			/**/
		}
		//tewi
		if (evt == "Hammerthrow")
		{
			var E:Dynamic = EntityFromUID(data.UID);
			var D:Tewi = E;
			var O = new Bullet();
			O.x = D.x;
			O.y = D.y;
			if (D.Ldir > 0)
			{
				O.Hspeed = 2;
			}
			else
			{
				O.Hspeed = -2;
			}
			O.image.image_speed = 0.7;
			O.Vspeed = -10;
			if (Math.random() > 0.9)
			{
				O.ChangeAnimation("tableE");
			}
			else
			{
				O.ChangeAnimation("hammerE");
			}
			O.gravY = 0.3;
			AddObject(O);
		}
		if (evt == "Tableflip")
		{
			var E:Dynamic = EntityFromUID(data.UID);
			if (data.TUID != null)
			{
				E.tossedBy = P;
			}
			E.image.image_speed = data.image_speed;
			E.Vspeed = -7;
			E.gravY = 0.8;
			E.dangerous = data.dangerous;
			E.Hspeed = data.Hspeed;
		}
		if (evt == "Spawntables")
		{
			var Tbl = new Table();
			Tbl.x = 140;
			Tbl.y = 375+3;
			Tbl.UID = 1.1;
			AddObject(Tbl);
		
			Tbl = new Table();
			Tbl.x = 660-20;
			Tbl.y = 375+3;
			Tbl.UID = 1.2;
			AddObject(Tbl);
			//
			Tbl = new Table();
			Tbl.x = 140;
			Tbl.y = 375 + 160+3;
			Tbl.UID = 1.3;
			AddObject(Tbl);
		
			Tbl = new Table();
			Tbl.x = 660-20;
			Tbl.y = 375 + 160+3;
			Tbl.UID = 1.4;
			AddObject(Tbl);
			//
			//
			Tbl = new Table();
			Tbl.x = 140;
			Tbl.y = 375 - 320+3;
			Tbl.UID = 1.5;
			AddObject(Tbl);
		
			Tbl = new Table();
			Tbl.x = 660-20;
			Tbl.y = 375 - 320+3;
			Tbl.UID = 1.6;
			AddObject(Tbl);
			RoundType = TypeofRound.EventTable;
		}
		if (evt == "NoWrap")
		{
			var O;
			var X = 0;
			var Y = 0-128;
			while (Y < 600)
			{
				O = new Bullet();
				O.x = X;
				O.y = Y;
				O.ChangeAnimation("skull");
				AddObject(O);
				Y += 32;
			}
			Y = 0-128;
			X = 800 - 32;
			while (Y < 600)
			{
				O = new Bullet();
				O.x = X;
				O.y = Y;
				O.ChangeAnimation("skull");
				O.type = "NoWrap";
				AddObject(O);
				Y += 32;
			}
			RoundType = TypeofRound.EventNoWrap;
		}
		if (evt == "unyucannon")
		{
			var O = new UtsuhoBullet();
			O.x = data.x;
			O.y = data.y;
			O.Hspeed = data.Hspeed;
			O.Vspeed = data.Vspeed;
			if (data.gravX != null)
			{
				O.gravX = data.gravX;
			}
			if (data.gravY != null)
			{
				O.gravY = data.gravY;
			}
			if (data.image_speed != null)
			{
				O.image.image_speed = data.image_speed;
			}
			if (data.image != null)
			{
				O.ChangeAnimation(data.image);
			}
			AddObject(O);
		}
		if (evt == "ShootBullet")
		{
			var O = new Bullet();
			O.x = data.x;
			O.y = data.y;
			O.Hspeed = data.Hspeed;
			O.Vspeed = data.Vspeed;
			if (data.spin != null)
			{
				O.spin = data.spin;
			}
			if (data.gravX != null)
			{
				O.gravX = data.gravX;
			}
			if (data.gravY != null)
			{
				O.gravY = data.gravY;
			}
			if (data.image_speed != null)
			{
				O.image.image_speed = data.image_speed;
			}
			if (data.image != null)
			{
				O.ChangeAnimation(data.image);
			}
			AddObject(O);
		}
		if (evt == "FreezeWorld")
		{
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block")
				{
					var D:Dynamic = E;
					D.DeepFreeze();
				}
				i += 1;
			}
			FlashColor(0x9999FF, 0.4, 0, 0.1);
		}
		if (evt == "Kick")
		{
			#if flash
			if (NP != null && data.player == NP.NID)
			{
				status = "kicked";
			}
			#end
		}
		if (evt == "Quitting")
		{
			#if flash
			if (!me && P != null && NP != null)
			{
				NP.removeplayer(ID);
			}
			if (me && NP != null)
			{
				NP.Flush();
				NP.end();
				NP = null;
			}
			#end
		}
		/*if (evt == "GiantSuikaAttack")
		{
			if (thegiant != null && !thegiant.active)
			{
				//thegiant.activate();
			}
		}*/
		if (evt == "AttachItem")
		{
			var E = EntityFromUID(data.UID);
			if (E != null)
			{
				var D:Dynamic = { };
				D.type = data.item;
				D.UID = data.UID + 10;
				/*if (E.myMyon != null)
				{
					D.UID += 1;
				}*/
				D.x = E.x;
				D.y = E.y;
				if (E.type != "Player")
				{
					D.holder = data.UID;
				}
				{
					ProcessEvent("SpawnItem", "Myself", D);
				}
			}
		}
		if (evt == "AttachMyon" || evt=="AttachZombieFairy")
		{
			var E = EntityFromUID(data.UID);
			if (E != null)
			{
				var D:Dynamic = { };
				D.type = "Myon";
				D.UID = data.UID + 1;
				if (E.myMyon != null)
				{
					D.UID += 1;
				}
				D.x = E.x;
				D.y = E.y;
				if (E.type != "Player")
				{
					D.holder = data.UID;
				}
				{
					ProcessEvent("SpawnItem", "Myself", D);
				}
				if (evt == "AttachZombieFairy")
				{
					var M:Dynamic = EntityFromUID(D.UID);
					var Z:MyonItem = M;
					Z.rename = "zombiefairy";
					if (data.HP != null)
					{
						Z.HP = data.HP;
					}
					if (data.type != null)
					{
						Z.rename = data.type;
						Z.ChangeAnimation(Z.rename);
					}
					else
					{
						Z.ChangeAnimation("zombiefairy");
					}
					if (data.scale != null)
					{
						Z.scaleX = data.scale;
						Z.scaleY = data.scale;
					}
					Z.facedirection = true;
					Z.dualcarry = true;
				}
				if (E.type == "Player")
				{
					if (me)
					{
						SendEvent("Collect", data.UID + 1);
					}
				}
			}
		}
		if (evt == "StealMyon")
		{
			var E = EntityFromUID(data);
			if (E != null)
			{
				var D:Dynamic = E;
				if (D.holder != null)
				{
					D.holder.myMyon = null;
				}
				D.Collect(P);
			}
		}
		if (evt == "SummonYuka")
		{
			{
				//yuukaactive = true;
				
				var Y = new Yuuka();
				Y.x = data.x;
				Y.y = data.y;
				AddObject(Y);
			}
		}
		if (evt == "PlayerMasterSpark")
		{
			var MS = new PlayerMasterSpark();
			MS.y = P.y;
			MS.x = P.x;
			MS.user = P;
			AddObject(MS);
			SoundManager.Play("masterspark");
		}
		if (evt == "MasterSpark")
		{
			var MS = new MasterSpark();
			MS.y = data.y;
			MS.x = 0;
			AddObject(MS);
			SoundManager.Play("masterspark");
		}
		if (evt == "LightningStrike")
		{
			var MS = new Lightning();
			MS.y = -100;
			MS.x = data.x;
			AddObject(MS);
			SoundManager.Play("se_tan01");
		}
		if (evt == "SpawnMiniPowBlock")
		{
			minipowspawns++;
			minipowactive = true;
			var E = new MiniPowBlock();
			E.x = data.x;
			E.y = data.y;
			AddObject(E);
		}
		if (evt == "loadsession")
		{
			P.score = data.score;
			P.spentscore = P.score;
			P.lives = data.lives;
		}
		if (evt == "ZaWarudo")
		{
			SoundManager.Play("zawarudo");
			P.ChangeAnimation("dio"+P.charname);
			P.Hspeed = 0;
			P.Vspeed = 0;
			pausetime = 5.000;
			ltime = Timer.stamp ();
			ZaWarudoCaster = P;
		}
		if (evt == "TelephonePole")
		{
			var TP = new TelephonePole();
			TP.player = P;
			TP.x = data.x;
			AddObject(TP);
		}
		if (evt == "BananaPeel")
		{
			var TP = new BananaPeel();
			TP.player = P;
			TP.x = data.x;
			TP.y = data.y;
			AddObject(TP);
		}
		if (evt == "MiracleMallet")
		{
			var i = 0;
			while (i < activeItems.length)
			{
				var E = activeItems[i];
				if (E.charname == "Mini1up")
				{
					var H = E.height;
					E.scaleX = 1;
					E.scaleY = E.scaleX;
					E.y -= E.height - H;
				}
				i++;
			}
			FlashColor(0xFFCCCC, 0.4, 0, 0.1);
		}
		if (evt == "ManipulateGap")
		{
			var E = EntityFromUID(data.UID);
			if (E != null)
			{
				E.readyinteract = false;
				if (Hoster)
				{
					var R = Math.random();
					var type = "item";
					var item = "1up";
					var HP = 1;
					if (R < 0.8)
					{
						item = "Point";
					}
					else if (R < 0.82)
					{
						item = "GiantPoint";
					}
					else if (R < 0.83 && gamemode.canlivesspawn)
					{
						item = "1up";
					}
					else if (R < 0.89)
					{
						item = "MiniBomb";
					}
					else if (R < 0.91)
					{
						item = "Bomb";
					}
					else if (R < 0.98)
					{
						item = "chen";
						type = "myon";
					}
					else if (R < 1.1)
					{
						item = "ran";
						type = "myon";
						HP = 2;
					}
					if (type == "item")
					{
						var D:Dynamic = { };
						D.type = item;
						D.UID = Math.random();
						if (P.x < E.x)
						{
							D.Ldir = -1;
						}
						else
						{
							D.Ldir = 1;
						}
						D.x = E.x;
						D.y = E.y + 90;
						SendEvent("SpawnItem", D);
					}
					if (type == "myon")
					{
						var D:Dynamic = { };
						D.UID = P.UID;
						D.type = item;
						D.HP = HP;
						D.scale = 0.5;
						SendEvent("AttachZombieFairy", D);
					}
				}
				var G:Dynamic = E;
				G.frames = 180;
			}
		}
		if (evt == "UnzanFist")
		{
			var O = new UnzanFist();
			//O.y = -32;
			//O.y = -100;
			O.y = -200;
			O.x = data.x;
			AddObject(O);
		}
		if (evt == "SpawnHunters")
		{
			var D:Dynamic = { };
			D.type = "kaguya";
			D.UID = Math.random();
			/*if (Math.random() > 0.5)
			{
				D.x = Math.random() * 800;
				D.Ldir = -1;
			}
			else
			{
				D.x = Math.random() * 800;
				D.Ldir = 1;
			}*/
			D.x = 0;
			D.Ldir = 1;
			//D.y = -100;
			D.y = 500;
			D.alive = true;
			D.Hspeed = 0;
			D.Vspeed = 0;
			D.enraged = false;
			D.visible = true;
			D.rank = rank;
			D.spawns = 0;
			SendEvent("SpawnEnemy", D);
			D.x = 800;
			D.Ldir = -1;
			D.type = "mokou";
			D.UID = Math.random();
			SendEvent("SpawnEnemy", D);
		}
		if (evt == "LaserBeam")
		{
			var L = new LaserBeam();
			L.x = data.x;
			L.y = data.y;
			if (data.user != null)
			{
				var D:Dynamic = EntityFromUID(data.user);
				//var P:Player = D;
				L.user = D;
				if (D != null)
				{
				L.offsetX = L.x;
				L.offsetY = L.y;
				L.x += D.x;
				L.y += D.y;
				}
			}
			if (data.player != null)
			{
				var D:Dynamic = EntityFromUID(data.player);
				L.user = D;
				L.following = false;
			}
			if (data.color != null)
			{
				L.lasercolor = data.color;
			}
			if (data.size != null)
			{
				L.scaleY = data.size;
			}
			if (data.time != null)
			{
				L.Time = data.time;
			}
			if (data.piercing != null)
			{
				L.piercing = data.piercing;
			}
			if (data.rotation != null)
			{
				L.rotation = data.rotation;
			}
			L.antiplayer = data.antiplayer;
			L.antienemy = data.antienemy;
			AddObject(L);
		}
		if (evt == "CustomEvent")
		{
			var E = EntityFromUID(data.UID);
			if (E != null && E.alive)
			{
				E.CustomEvent(data.data);
			}
		}
		if (evt == "CustomLVLEvent")
		{
			/*var E = EntityFromUID(data.UID);
			if (E != null && E.alive)
			{
				E.CustomEvent(data.data);
			}*/
			if (lvllogic != null)
			{
				lvllogic.CustomEvent(data.data);
			}
		}
		if (evt == "SummonBlueBird")
		{
			var O = new BlueBird();
			O.player = P;
			O.x = 0;
			O.y = 0;
			AddObject(O);
		}
	}
	public function killeveryone()
	{
		var i = 0;
		while (i < entities.length)
		{
			var E = entities[i];
			if (E.type == "Enemy")
			{
				if (boss != E && E.subtype != "boss" && E.subtype!="yuyuko")
				{
					E.alive = false;
					E.killed = true;
				}
			}
			i++;
		}
		FlashColor(0, 0.4, 0, 0.1);
		
		if (!myplayer.killed && !myplayer.flags.get(Player.DeathResistence))
		{
			myplayer.killed = true;
			myplayer.Vspeed = -9;
			SoundManager.Play("died");
		}
		//SendEvent("PlayerDeath", false);
	}
	public function activategiant()
	{
		//thegiant.activate();
		var D:Dynamic = {};
		D.type = "activate";
		D.unlock = "suika";
		if (RoundType == TypeofRound.EventCirno || RoundType == TypeofRound.EventFireCirno || RoundType == TypeofRound.EventElectricCirno)
		{
			D.unlock = "cirno";
		}
		if (Math.random() < 0.1)
		{
			var S = GetImposterList();
			var U = S[Std.int(Math.random() * S.length)];
			var P = CharHelper.getCharPreset(U);
			if (P != null && P != "")
			{
				D.unlock = U;
			}
		}
		thegiant.SendCustomEvent(D);
	}
	// Event Handlers
	
	public function ZaWarudoKnives(P:Player)
	{
		{
				var i = 0;
				var sp = 5;
				while (i < activeEnemies.length)
				{
					var E = activeEnemies[i];
					if (E.alive && !E.killed)
					{
						var O = new PlayerBullet();
						O.x = E.x;
						O.y = E.y+150;
						O.Hspeed = 0;
						O.Vspeed = -sp;
						O.tossedBy = P;
						O.image.image_speed = 0;
						O.ChangeAnimation("knife");
						O.animate();
						AddObject(O);
						
						O = new PlayerBullet();
						O.x = E.x-120;
						O.y = E.y+120;
						O.Hspeed = sp;
						O.Vspeed = -sp;
						O.tossedBy = P;
						O.image.image_speed = 1;
						O.ChangeAnimation("knife");
						O.animate();
						O.image.image_speed = 0;
						AddObject(O);
						
						O = new PlayerBullet();
						O.x = E.x-150;
						O.y = E.y;
						O.Hspeed = sp;
						O.Vspeed = 0;
						O.tossedBy = P;
						O.image.image_speed = 2;
						O.ChangeAnimation("knife");
						O.animate();
						O.image.image_speed = 0;
						AddObject(O);
						
						O = new PlayerBullet();
						O.x = E.x-120;
						O.y = E.y-120;
						O.Hspeed = sp;
						O.Vspeed = sp;
						O.tossedBy = P;
						O.image.image_speed = 3;
						O.ChangeAnimation("knife");
						O.animate();
						O.image.image_speed = 0;
						AddObject(O);
						
						O = new PlayerBullet();
						O.x = E.x;
						O.y = E.y-150;
						O.Hspeed = 0;
						O.Vspeed = sp;
						O.tossedBy = P;
						O.image.image_speed = 4;
						O.ChangeAnimation("knife");
						O.animate();
						O.image.image_speed = 0;
						AddObject(O);
						
						O = new PlayerBullet();
						O.x = E.x+120;
						O.y = E.y-120;
						O.Hspeed = -sp;
						O.Vspeed = sp;
						O.tossedBy = P;
						O.image.image_speed = 5;
						O.ChangeAnimation("knife");
						O.animate();
						O.image.image_speed = 0;
						AddObject(O);
						
						O = new PlayerBullet();
						O.x = E.x+150;
						O.y = E.y;
						O.Hspeed = -sp;
						O.Vspeed = 0;
						O.tossedBy = P;
						O.image.image_speed = 6;
						O.ChangeAnimation("knife");
						O.animate();
						O.image.image_speed = 0;
						AddObject(O);
						
						O = new PlayerBullet();
						O.x = E.x+120;
						O.y = E.y+120;
						O.Hspeed = -sp;
						O.Vspeed = -sp;
						O.tossedBy = P;
						O.image.image_speed = 7;
						O.ChangeAnimation("knife");
						O.animate();
						O.image.image_speed = 0;
						AddObject(O);
					}
					i++;
				}
			}
	}
	public function CopyBulletData(data:Dynamic, O:Dynamic)
	{
		var B = Std.is(O, PlayerBullet);
		O.x = data.x;
		O.y = data.y;//+10;
		O.Hspeed = data.Hspeed;
		O.Vspeed = data.Vspeed;
		O.gravX = data.gravX;
		O.gravY = data.gravY;
		//if (O.scaleX == null)
		if (!B)
		{
			O.scale = data.scale;
		}
		else
		{
			O.scaleX = data.scale;
			O.scaleY = data.scale;
		}
		O.bounces = false;
		O.type = data.type;
		if (data.wrap != null)
		{
			if (!B)
			{
				O.wrap = data.wrap;
			}
			else
			{
				O.allowwrap = data.wrap;
			}
		}
		if (data.spiral != null)
		{
			O.spiral = data.spiral;
			if (data.spiralrate != null)
			{
				O.spiralrate = data.spiralrate;
			}
		}
		if (data.piercing != null)
		{
			O.piercing = data.piercing;
		}
		if (data.emerge != null)
		{
			O.emerge = data.emerge;
		}
		if (data.maxscale != null)
		{
			O.maxscale = data.maxscale;
		}
		if (data.friction != null)
		{
			O.friction = data.friction;
		}
		if (data.timelimit != null)
		{
			O.timelimit = data.timelimit;
		}
		if (data.rotated != null)
		{
			O.rotated = data.rotated;
		}
		if (data.submerge != null)
		{
			O.submerge = data.submerge;
		}
		if (data.bounces != null)
		{
			O.bounces = data.bounces;
		}
		if (data.HP != null)
		{
			O.HP = data.HP;
		}
		if (data.spin != null)
		{
			O.spin = data.spin;
		}
		if (data.bossdamage != null)
		{
			O.bossdamage = data.bossdamage;
		}
		if (data.topbounce != null)
		{
			O.topbounce = data.topbounce;
		}
		if (data.bouncedrain != null)
		{
			O.bouncedrain = data.bouncedrain;
		}
		if (data.bumps != null)
		{
			O.bumps = data.bumps;
		}
		if (data.rolls != null)
		{
			O.rolls = data.rolls;
		}
		if (data.image_speed != null)
		{
			if (B)
			{
				O.image.image_speed = data.image_speed;
			}
			else
			{
				O.image_speed = data.image_speed;
			}
		}
		if (data.illusion != null)
		{
			O.illusion = data.illusion;
			if (data.illusiontime != null)
			{
				O.illusiontime = data.illusiontime;
			}
			if (data.illusiondir != null)
			{
				O.illusiondir = data.illusiondir;
			}
			if (data.illusionrate != null)
			{
				O.illusionrate = data.illusionrate;
			}
		}
	}
	//clones a "PlayerDanmaku" data and sends it(used for spamming danmaku)
	public function SendPlayerDanmaku(data:Dynamic)
	{
		//var O = new PlayerBullet();
		var O:Dynamic = { };
		CopyBulletData(data, O);
			/*O.x = data.x;
			O.y = data.y;//+10;
			O.Hspeed = data.Hspeed;
			O.Vspeed = data.Vspeed;
			O.gravX = data.gravX;
			O.gravY = data.gravY;
			O.scale = data.scale;
			//O.scaleX = data.scale;
			//O.scaleY = data.scale;
			O.bounces = false;
			O.type = data.type;
			if (data.wrap != null)
			{
				O.wrap = data.wrap;
			}
			if (data.bounces != null)
			{
				O.bounces = data.bounces;
			}
			if (data.HP != null)
			{
				O.HP = data.HP;
			}
			if (data.spin != null)
			{
				O.spin = data.spin;
			}
			if (data.bossdamage != null)
			{
				O.bossdamage = data.bossdamage;
			}
			if (data.topbounce != null)
			{
				O.topbounce = data.topbounce;
			}
			if (data.bouncedrain != null)
			{
				O.bouncedrain = data.bouncedrain;
			}
			if (data.bumps != null)
			{
				O.bumps = data.bumps;
			}
			if (data.rolls != null)
			{
				O.rolls = data.rolls;
			}
			if (data.image_speed != null)
			{
				O.image_speed = data.image_speed;
			}*/
			SendEvent("PlayerDanmaku", O);
	}
	public function stage_onKeyDown (event:KeyboardEvent):Void {
		//TF.text = "test"+event.toString();
		if (event.keyCode == Keyboard.SPACE) {
				//TF.text = "space!";
		}
		switch (event.keyCode) {
			
		/*case Keyboard.Q:
			SendEvent("Quitting", null);
			status = "quitting";*/
		case Keyboard.F1:
			if (Hoster && Main._this.DEBUG)
			{
				SpawnTimer = 1;
				if (SpawnList.length == 0)
				{
					level++;
					if (((level - 1) % 5)+1 == 1)
					{
						updatelevelinfo();
						PlayMusic(Hoster);
						messagetime = 0;
					}
				}
				if (activeEnemies.length > 0)
				{
					SpawnList.clear();
				}
				else if (SpawnList.length>1)
				{
					var E = SpawnList.pop();
					SpawnList.clear();
					SpawnList.add(E);
				}
			}
		case Keyboard.F2:
			if (Hoster && Main._this.DEBUG)
			{
				//SendEvent("GiantSuikaAttack", null);
				activategiant();
			}
		case Keyboard.F3:
			if (Hoster && Main._this.DEBUG)
			{
				SendGap();
				/*var D:Dynamic = { };
				D.type = "UFO";
				D.UID = Math.random();
				if (Math.random() > 0.5)
				{
					D.x = Math.random() * 800;
					D.Ldir = -1;
				}
				else
				{
					D.x = Math.random() * 800;
					D.Ldir = 1;
				}
				D.y = -100;
				D.alive = true;
				D.Hspeed = 0;
				D.Vspeed = 0;
				D.enraged = false;
				D.visible = true;
				D.rank = rank;
				D.spawns = 0;
				ufos++;
				SendEvent("SpawnEnemy", D);*/
			}

		case Keyboard.F4:
			if (Hoster && Main._this.DEBUG)
			{
				if (myplayer.invincibility <= 0)
				{
					myplayer.invincibility = 99999999;
				}
				else
				{
					myplayer.invincibility = 0;
				}
			}
		case Keyboard.F5:
			if (Hoster && Main._this.DEBUG)
			{
				SendYuuka();
			}
		case Keyboard.F6:
			if (Hoster && Main._this.DEBUG)
			{
				myplayer.cooldown = 0;
			}
		case Keyboard.F7:
			if (Hoster && Main._this.DEBUG)
			{
				ept = 0;
				rept = 0;
				//SendYuuka();
				if (false)
				{
				//var B = new BossCirno();
				//var B = new BossYukari();
				
				//var B = new BossSanae();
				//var B = new BossParsee();
				//var B = new BossMurasa();
				
				/*var E:Enemy = null;
				if (Math.random() < 0.3)
				{
					E = new Aya();
				}
				else if (Math.random() < 0.4)
				{
					E = new Youmu();
				}
				else
				{
					E = new Reimu();
				}
				//var B = new Meiling();
				//var B = new Marisa();
				//var B = new Youmu();
				//var B = new Reimu();
				AddEnemy(E);*/
				}
				else 
				{
				var B:PowerupItem = new PowerupItem();
				//B.power = "reimu";
				//var B = new Roukanken();
				//var B = new SanaeStickItem();
				//var B = new Bow();
				//var B = new MiniHakkero();
				//var B = new CameraItem();
				//var B = new SpellCardItem();
				
				B.x = 400;
				B.Ldir = 0;
				AddEntityItem(B);
				}
				//AddObject(B);
			}
		case Keyboard.F8:
			if (Hoster && Main._this.DEBUG)
			{
				if (gamemode.rewardrequirement > 0)
				{
					objectiveprogress = gamemode.rewardrequirement - 1;
				}
			}
		}
		
		
		if (event.keyCode == Main._this.controlscheme[0])
		{
			control[0] = true;
		}
		if (event.keyCode == Main._this.controlscheme[1])
		{
			control[1] = true;
		}
		if (event.keyCode == Main._this.controlscheme[2])
		{
			control[2] = true;
		}
		if (event.keyCode == Main._this.controlscheme[3])
		{
			control[3] = true;
		}
		if (event.keyCode == Main._this.controlscheme[4])
		{
			control[4] = true;
		}
		if (event.keyCode == Main._this.controlscheme[5])
		{
			togglemenu();
		}
		ControlEvent = true;
	}
	public function SendYuuka()
	{
		var D:Dynamic = { };
		D.x = -200;
		if (Math.random() > 0.5)
		{
			D.x = 800;
		}
		D.y = 160;
		if (Math.random() > 0.5)
		{
			D.y += 160;
		}
		if (RoundType == TypeofRound.EventYuuka && Math.random() > 0.5)
		{
			D.y += 160;
		}
		if (RoundType == TypeofRound.EventYuuka && Math.random() > 0.5)
		{
			D.y -= 160;
		}
		//if (yuukaactive)
		if (yuukasactive>= maxyuuka)
		{
			return;
		}
		var i = 0;
		var count = 0;
		while (i < entities.length)
		{
			var E = entities[i];
			var ED:Dynamic = E;
			var Y = E.y + 56;
			//if ((E.type == "Yuuka" && ED.OY == D.y) || (E.type=="MasterSpark" && E.y+56 == D.y))
			if (E.type == "Yuuka" || E.type == "MasterSpark")
			{
				count++;
			if ((E.type == "Yuuka" && ED.OY == D.y) || (E.type=="MasterSpark" && (Y == D.y || Y+160 == D.y || Y-160 == D.y)))
			{
				return;
			}
			}
			i++;
		}
		yuukasactive = count;
		if (count >= maxyuuka)
		{
			return;
		}
		SendEvent("SummonYuka", D);
	}
	//kills all enemies(used for bomb type abilities)
	public function SendKillAll()
	{
		var i = 0;
			{
			while (i < activeEnemies.length)
			{
				var E = activeEnemies[i];
				if (E.alive && !E.killed && E.subtype != "boss")
				{
					SendEvent("Kill", E.UID);
				}
				i++;
			}
			}
	}
	
	
	public function stage_onKeyUp (event:KeyboardEvent):Void {
		
		if (event.keyCode == Main._this.controlscheme[0])
		{
			control[0] = false;
		}
		if (event.keyCode == Main._this.controlscheme[1])
		{
			control[1] = false;
		}
		if (event.keyCode == Main._this.controlscheme[2])
		{
			control[2] = false;
		}
		if (event.keyCode == Main._this.controlscheme[3])
		{
			control[3] = false;
		}
		if (event.keyCode == Main._this.controlscheme[4])
		{
			control[4] = false;
		}
		ControlEvent = true;
	}
	
	
	
	//aka laziness
	public function todyn(Dyn:Dynamic):Dynamic
	{
		return Dyn;
	}
	public function AddEntityFromData(D:Dynamic):Dynamic
	{
		var E:Dynamic = SpawnEntityFromData(D);
		if (E != null)
		{
			if (E.type == "Enemy")
			{
				AddEnemy(E);
			}
			if (E.type == "Item" || E.type=="Carryitem")
			{
				AddEntityItem(E);
			}
			if (!Hoster)
			{
				E.catchup();
			}
		}
		return E;
	}
	public function ResetSpawnTimer()
	{
		SpawnTimer = Std.int((30 * (2 + (Math.random() * 5)))*spawnrate);
	}
	public function SpawnEntityFromData(D:Dynamic):Dynamic
	{
		var E:Dynamic = null;
		
		if (EntityFromUID(D.UID) == null)
		{
			var LE:Array<Dynamic> = [];
			//Enemies
			LE.push( { T:"RedFairy", C:RedFairy } );
			LE.push( { T:"MoonRabbit", C:MoonRabbit } );
			LE.push( { T:"kisume", C:Kisume } );
			LE.push( { T:"Mystia", C:Mystia } );
			LE.push( { T:"Keine", C:Keine } );
			LE.push( { T:"Keineex", C:Keine } );
			
			LE.push( { T:"Chen", C:Chen } );
			LE.push( { T:"UFO", C:UFO } );
			LE.push( { T:"Cirno", C:Cirno } );
			LE.push( { T:"Imposter", C:Imposter } );
			LE.push( { T:"rumia", C:Rumia } );
			LE.push( { T:"seija", C:Seija } );
			LE.push( { T:"Nue", C:Nue } );
			LE.push( { T:"tewi", C:Tewi } );
			//LE.push( { T:"kaguya", C:TwuckHunter } );
			//LE.push( { T:"mokou", C:TwuckHunter } );
			LE.push( { T:"utsuho", C:Utsuho } );
			LE.push( { T:"yuyuko", C:Yuyuko } );
			LE.push( { T:"satori", C:Satori } );
			LE.push( { T:"Scarlet", C:Scarlet } );
			LE.push( { T:"meiling", C:Meiling } );
			LE.push( { T:"Hina", C:Hina } );
			LE.push( { T:"sakuya", C:Sakuya } );
			LE.push( { T:"youmu", C:Youmu } );
			LE.push( { T:"aya", C:Aya } );
			LE.push( { T:"Hecatia", C:Hecatia } );
			LE.push( { T:"bosscirno", C:BossCirno } );
			LE.push( { T:"bossyukari", C:BossYukari } );
			LE.push( { T:"bosssanae", C:BossSanae } );
			LE.push( { T:"bossparsee", C:BossParsee } );
			LE.push( { T:"bossmurasa", C:BossMurasa } );
			LE.push( { T:"tenshi", C:Tenshi } );
			LE.push( { T:"udongein", C:Reisen } );
			LE.push( { T:"kogasa", C:Kogasa } );
			LE.push( { T:"Nazrin", C:Nazrin } );
			LE.push( { T:"Iku", C:Iku } );
			LE.push( { T:"Reimu", C:Reimu } );
			LE.push( { T:"marisa", C:Marisa } );
			LE.push( { T:"Yinyangorb", C:Yinyangorb } );
			LE.push( { T:"Explosives", C:Explosives } );
			LE.push( { T:"Orin", C:Orin } );
			LE.push( { T:"Nitori", C:Nitori } );
			LE.push( { T:"suwako", C:Suwako } );
			LE.push( { T:"wakasagihime", C:Wakasagihime } );
			LE.push( { T:"sekibanki", C:Sekibanki } );
			LE.push( { T:"alice", C:Alice } );
			LE.push( { T:"magifairy", C:MagiFairy } );
			LE.push( { T:"Eirin", C:Eirin } );
			LE.push( { T:"Lily White", C:LilyWhite } );
			LE.push( { T:"patchouli", C:Patchouli } );
			LE.push( { T:"elly", C:Elly } );
			LE.push( { T:"letty", C:Letty } );
			LE.push( { T:"yoshika", C:Yoshika } );
			LE.push( { T:"wriggle", C:Wriggle } );
			LE.push( { T:"Mamizou", C:Mamizou} );
			
			//Items 
			LE.push( { T:"Point", C:PointItem } );
			LE.push( { T:"powerup", C:PowerupItem } );
			LE.push( { T:"GiantPoint", C:GiantPointItem } );
			LE.push( { T:"Trophy", C:TrophyItem } );
			LE.push( { T:"trophy", C:TrophyItem } );
			LE.push( { T:"Balloon", C:BalloonItem } );
			LE.push( { T:"Roukanken", C:Roukanken } );
			LE.push( { T:"Bow", C:Bow } );
			LE.push( { T:"MiniHakkero", C:MiniHakkero } );
			LE.push( { T:"yinyangorbitem", C:YinYangOrbItem } );
			LE.push( { T:"SpellCard", C:SpellCardItem } );
			LE.push( { T:"Boomerang", C:BoomerangItem } );
			LE.push( { T:"Camera", C:CameraItem } );
			LE.push( { T:"SanaeStick", C:SanaeStickItem } );
			LE.push( { T:"Myon", C:MyonItem } );
			LE.push( { T:"myon", C:MyonItem } );
			LE.push( { T:"1up", C:LifeItem } );
			LE.push( { T:"Mini1up", C:MiniLifeItem } );
			LE.push( { T:"UFOItem", C:UFOItem } );
			LE.push( { T:"Bomb", C:BombItem } );
			LE.push( { T:"MiniBomb", C:MiniBombItem } );
			LE.push( { T:"Power", C:PowerItem } );
			var T:String = D.type;
			T = T.toLowerCase();
			var i = 0;
			while (i < LE.length)
			{
				//if (LE[i].T == D.type)
				if (LE[i].T.toLowerCase() == T)
				{
					E = Type.createInstance(LE[i].C, []);
					i = LE.length;
				}
				i++;
			}
			
			if (E != null)
			{
				if (D.type == "Keineex")
				{
					E.ex = true;
				}
				if (D.type == "1up" || D.type == "Point" || D.type == "GiantPoint")
				{
					SoundManager.Play("spawncoin");
				}
				if (D.type == "powerup")
				{
					if (D.soul != null)
					{
						E.power = D.soul;
					}
				}
				if (D.type == "UFOItem")
				{
					SoundManager.Play("ufoitem");
					var U:UFOItem = E;
					if (D.changes == false)
					{
						U.changescolor = false;
					}
					if (D.color != null)
					{
						U.color = D.color;
					}
				}
			}
			else
			{
				if (D.type == "kaguya" || D.type == "mokou")
				{
					E = new TwuckHunter((D.type == "mokou"));
					/*if (D.type == "mokou")
					{
						E = new TwuckHunter(true);
					}
					else
					{
						E = new TwuckHunter(false);
					}*/
				}
			}
			if (E == null)
			{
				trace("Could not spawn entity:" + D.type);
			}
			if (E != null/* && type=="Enemy"*/ && Std.is(E,Enemy))
			{
				E.UID = D.UID;
				E.y = D.y;
				E.x = D.x;
				E.Ldir = D.Ldir;
				
				if (D.Hspeed != null)
				{
					E.Hspeed = D.Hspeed;
					E.Vspeed = D.Vspeed;
				}
				E.enraged = D.enraged;
				E.rank = D.rank;
				if (D.alive != null)
				{
					E.alive = D.alive;
				}
				if (D.visible != null)
				{
					E.visible = D.visible;
				}
				if (D.spawns != null)
				{
					E.spawns = D.spawns + 1;
				}
				else
				{
					E.spawns = 1;
				}
				if (D.HP != null)
				{
					E.HP = D.HP;
				}
				if (D.enraged)
				{
					E.enrage();
				}
			}
			if (E != null/* && type == "Item"*/ && Std.is(E,EntityItem))
			{
				E.UID = D.UID;
				E.x = D.x;
				E.y = D.y;
				E.Ldir = D.Ldir;
				if (D.holder != null)
				{
					var A = EntityFromUID(D.holder);
					E.holder = A;
				}
			}
			if (E != null && D.platform != null)
			{
				var P = EntityFromUID(D.platform);
				if (P != null)
				{
					E.x += P.x;
					E.y += P.y;
					if (E.width > 1)
					{
						E.x += ((P.width / 2) - (E.width / 2));
					}
				}
			}
		}
		return E;
	}
	public static function GetRankTitle(level:Int):String
	{
		var L = level - 1;
		//var C = levelsperstage;
		//var C = 8 * 6;
		var C = levelsperrank;
		var rank = Math.floor(L / C);
		var S = "";
		if (rank == 0)
		{
			S = "Easy";
		}
		if (rank == 1)
		{
			S = "Normal";
		}
		if (rank == 2)
		{
			S = "Hard";
		}
		if (rank == 3)
		{
			S = "Lunatic";
		}
		if (rank == 4)
		{
			S = "Extra:";
		}
		if (rank > 4)
		{
			S = "EX" + (rank - 3)+":";
		}
		return S;
	}
	public static function GetLevelTitle(level:Int, sublevel:Bool=true,difficulty:Bool = true)
	{
		var L = level - 1;
		//var rank = Math.floor(L / 30);
		//var C = 8 * 6;
		var C = levelsperrank;
		var rank = Math.floor(L / C);
		var S = "";
		if (rank == 0)
		{
			S = "Easy:";
		}
		if (rank == 1)
		{
			S = "Normal:";
		}
		if (rank == 2)
		{
			S = "Hard:";
		}
		if (rank == 3)
		{
			S = "Lunatic:";
		}
		if (rank == 4)
		{
			S = "Extra:";
		}
		if (rank > 4)
		{
			S = "EX" + (rank - 3) + ":";
		}
		if (!difficulty)
		{
			S = "";
		}
		var stage = Math.floor((level - 1) / levelsperstage);
		stage = stage % stagesperrank;

		var lvl = ((level - 1) % levelsperstage);
		lvl++;
		var S2 = "";
		if (stage == 0)
		{
			S2 = "Hakurei Shrine";
		}
		if (stage == 1)
		{
			S2 = "Scarlet Mansion";
		}
		if (stage == 2)
		{
			S2 = "Space";
		}
		if (stage == 3)
		{
			S2 = "Underworld";
		}
		if (stage == 4)
		{
			S2 = "Palanquin Ship";
		}
		if (stage == 5)
		{
			S2 = "Eintei";
		}

		if (sublevel)
		{
			if (((level) % levelsperrank) == 9)
			{
				S = S + S2 + "-" + "⑨";
				//S = S + "⑨";
			}
			else
			{
				S = S + S2 + "-" + lvl;
			}
		}
		else
		{
			if (S != "")
			{
			S = S +"\n" + S2;
			}
			else
			{
				S = S2;
			}
		}
		return S;
	}
	public function ShowLevel(displaymessage:Bool=true)
	{
		var S = GetLevelTitle(level,true,false);
		var M = messages.length;
		if (displaymessage)
		{
			if (gamemode.levelincrement == 5)
			{
				ShowMessage(GetLevelTitle(level,false,false));
			}
			else
			{
				ShowMessage(S);
			}
		}
		var mode = "Solo";
		if (online)
		{
			if (Hoster)
			{
				mode = "Hoster";
			}
			else
			{
				mode = "Client";
			}
			if (!NP.running)
			{
				mode = "Error";
			}
			else if (!NP.groupstarted)
			{
				mode = "Waiting for players";
			}
		}
		var R = GetRankTitle(level);
		if (!online || (NP.running && NP.group != null))
		{
			leveltitle.text = Main._this.roomprefix + "-" + R + ":" + mode;
		}
		else
		{
			leveltitle.text = "Not connected...";
		}
		if (online && NP != null && NP.error != "" && NP.error != null)
		{
			leveltitle.text = NP.error;
		}
		leveltitle.width = leveltitle.textWidth + 8;
		leveltitle.height = leveltitle.height + 8;
		var B = leveltitle.getBounds(this);
		if (B.right > 800)
		{
			leveltitle.x += 800 - B.right;
		}
		else
		{
			leveltitle.x = 5 + progressbar.x;
		}
		if (M == 0)
		{
			messagetime = 300;
		}
		
	}
	
	
	public function EntityFromUID(UID:Float):Entity
	{
		var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.UID == UID)
				{
					return E;
				}
				i += 1;
			}
			return null;
	}
	public function this_onEnterFrame (event:Event):Void {
		if (_this != this)
		{
			return;
		}
		if (menu)
		{
			if (charselect == null)
			{
				charselect = new CharacterSelect(playerspick,useablelist,gamemode.forcedcharacter=="");
				var B = new MenuButton("Quit Game");
				B.sound = "cancel";
				B.x += 670;
				B.y += 500;
				//B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				B.addclick(function( ev ) {
					status = "quitting";
					
				 } 
				);
				charselect.addChild(B);
				
				B = new MenuButton("Continue");
				B.x += 670;
				B.y += 12;
				B.addclick(function( ev ) {
					togglemenu();
					
				 } 
				);
				
				if (gamemode.rewardrequirement > 0)
				{
				var TT = new TextField();
				TT.text = "Levels to goal: " + (gamemode.rewardrequirement - objectiveprogress);
				TT.mouseEnabled = false;
				//TT.blendMode = openfl.display.BlendMode.INVERT;
				var FA:Array<flash.filters.BitmapFilter> = new Array<flash.filters.BitmapFilter>();
				var AB = new flash.filters.GlowFilter();
				AB.blurX = 5;
				AB.blurY = 5;
				AB.color = 0x000000;
				AB.strength = 3;
				FA[FA.length] = AB;
				TT.filters = FA;
				//TT.y = 290;
				TT.y = 100;
				TT.scaleX = 2.5;
				TT.scaleY = 2.5;
				TT.textColor = 0xFFFFFF;
				TT.width = TT.textWidth + 8;
				TT.x = 800 - TT.width;
				charselect.addChild(TT);
				}
				charselect.addChild(B);
				gui.addChild(charselect);
			}
		}
		if (!online && paused)
		{
			TF.text = "Paused" + "\nx " + Main._this.savedata.data.money;
			moneyicon.visible = true;
			ltime = Timer.stamp ();
			return;
		}
		if (charselect != null && !menu)
		{
			if (charselect.selected != playerspick)
			{
				playerspick = charselect.selected;
				
				var soul = "";
				if (playerspick == "customavatar" && gamemode.forcedcharacter=="")
				{
					soul = Main._this.savedata.data.avatarability;
				}
				if (GameFlags.get(Main.Adventure))
				{
					soul = myplayer.charactersoul;
				}
				var D:Dynamic = { };
				D.C = playerspick;
				D.A = soul;
				SendEvent("ChangeCharacter", D);
				//myplayer.init(playerspick);
			}
			gui.removeChild(charselect);
			charselect = null;
		}
		if (pausetime>0)
		{
			//F.text = "Time has\nstopped";
			var currentTime = Timer.stamp ();
		var T = currentTime - ltime;
		pausetime -= T;
		ltime = currentTime;
		if (pausetime < 2.7)
		{
			if (!ZaWarudo.visible)
			{
				ZaWarudo.visible = true;
				ZaWarudoKnives(ZaWarudoCaster);
				ZaWarudoCaster = null;
			}
		}
			return;
		}
		if (ZaWarudo.visible)
		{
			ZaWarudo.visible = false;
		}
		/*var currentTime = Timer.stamp ();
		var T = currentTime - ltime;
		missingTime += T;*/
		TF.blendMode = openfl.display.BlendMode.INVERT;
		if (online)
		{
			
			var ok = true;
			if (Hoster)
			{
				var A = Players.iterator();
				if (A.hasNext())
				{
					A.next();
					if (A.hasNext())
					{
						//TF.text = "Host: " + Room + "\nLevel: " + level +"\nLives: " + Math.max(myplayer.lives,0)+"\nEnemies: "+totalenemies;
						ok = false;
					}
				}
			}
			if (ok)
			{
				//TF.text = "Client: " + Room + "\nLevel: " + level +"\nLives: " + Math.max(myplayer.lives,0)+"\nEnemies: "+totalenemies;
			}
			if (netlog && Hoster)
			{
				var A = sentmessagelog.keys();
				trace("sendlog");
				while (A.hasNext())
				{
					var S = A.next();
					trace(S + ":" + sentmessagelog[S]);
				}
				A = recievedmessagelog.keys();
				trace("recievelog");
				while (A.hasNext())
				{
					var S = A.next();
					trace(S + ":" + recievedmessagelog[S]);
				}
			}
		}
		else
		{
			//TF.text = "Level: " + level +"\nLives: " + Math.max(myplayer.lives,0)+"\nEnemies: "+totalenemies;
		}
		if (Main._this.DEBUG && Hoster)
		{
			//TF.text = TF.text + "\nEPM: " + Math.round(epm) + " max: " + maxspawns+"\nspawnrate: "+spawnrate;
		}
		TF.scaleX = 2;
		TF.scaleY = 2;
		var L = myplayer.lives + (myplayer.lifefragments / 4);
		//var str = "x " + Math.max(myplayer.lives, 0);
		var str = "x " + Math.max(L, 0);
		
		if (gamemode.infinitelives)
		{
			str = "x " + "∞";
			if (myplayer.lives < 3)
			{
				myplayer.lives = 3;
			}
		}
		
		if (menu && moneytime < 1)
		{
			moneytime = 1;
		}
		if (moneytime > 0)
		{
			str = str + "\nx " + Main._this.savedata.data.money;
			moneyicon.visible = true;
			moneytime--;
		}
		else
		{
			moneyicon.visible = false;
		}
		if (TF.text != str)
		{
			TF.text = str;
			TF.textColor = 0xFFFFFF;
		}
		if (myplayer.combotime > 0 && myplayer.combo>1)
		{
			CTF.alpha = 1;
			CTF.visible = true;
			CTF.text = "Combo " + myplayer.combo;
			CTF.textColor = 0xFFFFFF;
		}
		else
		{
			CTF.alpha -= 0.1;
			if (CTF.alpha <= 0)
			{
				CTF.visible = false;
			}
		}
		/*if (missingTime > 3)
		{
			missingTime = 0.041;
		}*/
		/*if (missingTime > 0.04)
		{
			gamestage.visible = false;
		}*/
		
		{
		updategame(event);
		missingTime = 0;
		}
		/*if (missingTime > 0.0334)
		{
			updategame(event);
			missingTime -= 0.0334;
		}
		if (missingTime < 0)
		{
			missingTime = 0;
		}
		while (missingTime > 0.04)
		{
			updategame(event);
			missingTime -= 0.0334;
		}*/
		/*if (!gamestage.visible)
		{
			gamestage.visible = true;
		}*/
		var cameraenabled = false;
		if (cameraenabled)
		{
		y = ( -myplayer.y) + 300;
		//dont go past bottom
		if (y < 0)
		{
			y = 0;
		}
		}
		var S = "";
		CombinedScore = 0;
		CombinedScoreALL = 0;
		var hoststart = -1;
		var hostlength = 0;
		var colors:TextColorizer = null;
		if (online)
		{
		var i = 0;
		
		var PL = new Array<Player>();
		var A = Players.iterator();
		var ok = false;
		colors = new TextColorizer(0xFFFFFF);
		
		while (A.hasNext())
		{
			var E = A.next();
			if (E != myplayer)
			{
				if (E.playing < frame)
				{
					ok = true;
				}
			}
			PL[PL.length] = E;
			CombinedScoreALL += E.score;
			CombinedScore += (E.score - E.spentscore);
		}
		if (!Hoster && !ok && PL.length>4)
		{
			status = "roomfull";
			SendEvent("Quitting", null);
		}
		PL.sort(function(a:Dynamic, b:Dynamic):Int{
							if (a.score > b.score) return -1;
							if (a.score < b.score) return 1;
							return 0;
							} );
		while (i < PL.length)
		{
			var E = PL[i];
			var H = false;
			//var C = 0x00FF55;
			var C = 0x00DD55;
			if (!E.inactive)
			{
				var PN = E.playername;
				if (/*!E.isme && */HostPlayer == E)
				{
					/*var symbol = "⌂";
					symbol = "►";
					PN = symbol + PN;*/
					H = true;
				}
				if (H)
				{
					hoststart = S.length;
					hostlength = PN.length;
					C = 0xFFFF77;
				}
			/*if (S == "")
			{
				
				S = PN + ": " + E.score;
			}
			else
			{
				S = S + "\n" + PN + ": " + E.score;
			}*/
			
			colors.appendline(PN, C);
			colors.append(": "+E.score);
			S = "";
			}
			i++;
		}
		
		
		}
		else
		{
			CombinedScore = (myplayer.score - myplayer.spentscore);
			CombinedScoreALL = myplayer.score;
			var HS = HighScore;
			if (myplayer.score > HS)
			{
				HS = myplayer.score;
			}
			//S = myplayer.playername + ": " + myplayer.score + "\nHighscore: " + HighScore;
			S = "Score: " + myplayer.score + "\nHighscore: " + HS;
		}
		var messag = "";
		if (messages.length > 0)
		{
			MSGText.scaleX = 1.5;
			MSGText.scaleY = 1.5;
			messagetime--;
			messag = messages[0];
			var i = 1;
			while (i < 6 && i < messages.length)
			{
				messag = messag + "\n" + messages[i];
				i++;
			}
			if (messagetime < 1)
			{
				//messages.remove(messages[0]);
				var i = 0;
				while (i < 6 && messages.length>0)
				{
					messages.remove(messages[0]);
					i++;
				}
				messagetime = 500;
			}
		}
		else
		{
			SC.scaleX = 1;
			SC.scaleY = 1;
		}
		scoreboard.text = S;
		scoreboard.textColor = 0xFFFFFF;
		/*if (hostlength > 0)
		{
			var temp:TextFormat = new TextFormat();
			temp.color = 0xFFFF77;
			scoreboard.setTextFormat(temp, hoststart, hoststart + hostlength);
		}*/
		if (colors != null)
		{
			colors.apply(scoreboard);
		}
		scoreboard.width = scoreboard.textWidth+4;
		scoreboard.height = scoreboard.textHeight + 4;
		MSGText.text = messag;
		MSG.graphics.clear();
		MSG.x = scoreboard.width;
		if (messages.length > 0)
		{
			MSGText.width = MSGText.textWidth + 4;
			MSGText.height = MSGText.textHeight + 4;
			MSG.graphics.beginFill(0xFFFFFF, 0.7);
			MSG.graphics.drawRect(0, 0, MSGText.width+6, MSGText.height+6);
			MSG.graphics.endFill();
			MSG.graphics.beginFill(0x000044, 0.8);
			MSG.graphics.drawRect(3, 3, MSGText.width, MSGText.height);
			MSG.graphics.endFill();
		}
		frame += 1;
		//this is more efficient out of the update loop(espescially on slower machines)
		
		#if flash
		if (online)
		{
			//if there are no messages just run update character, this will keep a constant stream of messages going allowing newcomers to detect the group better
			var F = 45;
			if (Hoster)
			{
				F = 15;
			}
			if (ControlEvent || (NP.Queue.length == 0 && frame % F == 0) && status != "quitting")
			{
				//made this still the main default blank message as it helps stabalize character movements anyways.
				var D:Dynamic = { };
				D.H = myplayer.Hspeed;
				D.V = myplayer.Vspeed;
				D.x = myplayer.x;
				D.y = myplayer.y;
				//D.visible = myplayer.visible;
				D.cn = myplayer.controller;
				//if (frame % F == 0)
				if (frame % 45 == 0)
				{
					D.ID = myplayer.UID;
					D.ch = myplayer.charname;
					//if (myplayer.charactersoul != "")
					if (myplayer.charname == "customavatar" || GameFlags.get(Main.Adventure))
					{
						D.sl = myplayer.charactersoul;
						if (D.sl == null && GameFlags.get(Main.Adventure))
						{
							D.sl = "";
						}
					}
					if (myplayer.charname == "customavatar")
					{
						
						D.ch = "dna-"+Main._this.savedata.data.avatar;
					}
					D.nm = this.playername;
					D.sc = myplayer.score;
				}
				D.F = frame;
				
				//send a status update message instead if 
			if (NP.Queue.length == 0 && frame % F == 0)
			{
				if (Hoster)
				{
					SendStatus();
				}
			}
			NP.SendData("U", D);
			}
			
			NP.Flush();
			ControlEvent = false;
		}
		
		#end
		removeChild(gui);
		addChild(gui);
		/*removeChild(BGCBottom);
		removeChild(BGCLeft);
		removeChild(BGCRight);
		removeChild(Dpad);
		removeChild(colorflash);
		
		addChild(BGCBottom);
		addChild(BGCLeft);
		addChild(BGCRight);
		addChild(Dpad);
		addChild(colorflash);*/
		/*ltime = currentTime;*/
	}
	public function LoseFocus() {
		if (!online && !paused)
		{
			menu = true;
			paused = menu;
		}
	}
	public function SendStatus() {
		settotalenemies();
		var D:Dynamic = { };
					D.lvl = level;
					D.TE = totalenemies;
					D.AE = (activeEnemies.length);
					D.HP = powblock.HP;
					D.AI = activeItems.length;
					D.RT = RoundType.getIndex();
					D.GF = GameFlags.data;
					D.SID = sessionID;
					if (scrollX != 0)
					{
						D.sx = scrollX;
					}
					if (scrollY != 0)
					{
						D.sy = scrollY;
					}
					if (scrollspeedX != 0)
					{
						D.Sx = scrollspeedX;
					}
					if (scrollspeedY != 0)
					{
						D.Sy = scrollspeedY;
					}
					SendEvent("S", D);
	}
	public function settotalenemies()
	{
		totalenemies = (SpawnList.length);
		totalenemies += getenemycount();
	}
	public function getenemycount():Int
	{
		var ret = 0;
		var i = 0;
			while (i < activeEnemies.length)
			{
				if (activeEnemies[i].needtokill)
				{
					ret++;
				}
				i++;
			}
			return ret;
	}
	private function updateprogressbar()
	{
		if (!progressbar.visible)
		{
			return;
		}
		var RS = roundstarted;
		var prct = 0.5;
		if (lvllogic != null)
		{
			prct = lvllogic.updateprogressbar();
		}
		if (prct < 0)
		{
			prct = 0;
		}
		if (prct > 1)
		{
			prct = 1;
		}
		var G = progressbar.graphics;
		var C = 0x22EE66;
		if (prct > lastprogress)
		{
			C = 0xAAFFCC;
		}
		if (prct >= 1)
		{
			lastprogress = 1;
			C = 0xFFFFFF;
		}
		if (prct != lastprogress)
		{
			if (prct > lastprogress)
			{
				lastprogress += 0.0075;
				if (lastprogress > prct)
				{
					lastprogress = prct;
				}
				prct = lastprogress;
			}
			else
			{
				lastprogress = prct;
			}
		}
		//if (isNaN(prct))
		if (!(prct>=0 && prct<=1))
		{
			prct = 1;
		}
		var X = 100 * prct;
		X = 100 - X;
		G.clear();
		//G.beginFill(0, 0.4);
		//G.beginFill(0x00FFFF, 1);
		G.beginFill(0x000000, 1);
		G.drawRoundRect(12, 5, 106, 15,5);
		G.endFill();
		//G.beginFill(0x99CC22, 1);
		G.beginFill(C, 1);
		G.drawRoundRect(X+15, 8, 100-X, 9,5);
		//G.drawRoundRect(20, 20, X, 9,5);
		G.endFill();
		
		if ([TypeofRound.EventNormal, TypeofRound.EventScrolling, TypeofRound.EventDescending].indexOf(RoundType) > -1)
		{
			levelicon.bitmapData = AL.GetAnimation("flag")[0];
		}
		else
		{
			levelicon.bitmapData = AL.GetAnimation("exclamationmark")[0];
		}
	}
	private function updategame (event:Event):Void {
		/*if (missingTime < 0.01)
		{
			return;
		}*/
		if (Background.alpha < 1)
		{
			Background.alpha += 0.03;
		}
		else
		{
			OBackground.visible = false;
		}
		#if flash
		//if (Hoster)
		if (online && !NP.running && NP.error != lastNPerror)
		{
			ShowMessage(NP.error);
			lastNPerror = NP.error;
		}
		#end
		gui.graphics.clear();
		//gamestage.graphics.clear();
		backlayer.graphics.clear();
		entitylayer.graphics.clear();
		frontlayer.graphics.clear();
		Background.cacheAsBitmap = Background.alpha >= 1;
		/*if (gamestage.scaleY > 0)
		{
			//gamestage.y = Math.min(Math.max(myplayer.y + 300,0),100);
			var Y = Math.min(Math.max(myplayer.y - 200,-100),0);
			gamestage.y = -Y;
			Background.y = Y;
			OBackground.y = Background.y;
		}*/
		//if (scrollY==0)
		{
			var spd = 10;
			var Y = Math.min(Math.max(myplayer.y - 150, -100), 0);
			if (scrollY != 0 || gamestage.scaleY!=1)
			{
				//Y = 600;
				Y = 0;
			}
			if (camera.y != -Y)
			{
				var D = Math.abs(( -camera.y) - Y);
				if (D >= spd && (camera.y != 0 || D>90))
				{
					if (camera.y > -Y)
					{
						camera.y -= spd;
					}
					else
					{
						camera.y += spd;
					}
					//camera.y = -Y;
					Background.y = -camera.y;
					OBackground.y = Background.y;
				}
				else
				{
					if (Y == 0)
					{
						camera.y = 0;
						Background.y = -camera.y;
						OBackground.y = Background.y;
					}
				}
			}
		}
		/*else
		{
			camera.y = 0;
			Background.y = -camera.y;
			OBackground.y = Background.y;
		}*/
		if (platformformation != currentformation)
		{
			setformation();
		}
		if (!online)
		{
			Hoster = true;
		}
		if (syncdelay > 0)
		{
			syncdelay--;
		}
		if (useablelist != null)
		{
			myplayer.lives = (useablelist.length - 1);
			if (myplayer.killed && myplayer.y>600)
			{
				var name = playerspick;
				if (name.indexOf("ALT") > -1)
				{
					//alt = true;
					name = name.substr(0, name.length - 3);
					//i = Player.characters.indexOf(name);
				}
				if (useablelist.indexOf(name) >= 0)
				{
					useablelist.remove(name);
				}
				if (useablelist.length < 1)
				{
					//ProcessEvent("GameOver", "Myself", null);
					SendEvent("GameOver", null);
				}
				else if (!menu)
				{
					togglemenu();
				}
			}
		}
		updatelifeicon();
		updateprogressbar();
		
		if (lvllogic == null)
		{
			lvllogic = GetLogic();
			
		}
		if (lvllogic != null && !lvllogic.started)
		{
			var A = ((lvllogic.horizontalscrolling) || scrollX == 0);
			var B = ((lvllogic.verticalscrolling) || scrollY == 0);
			if (A && B)
			{
			lvllogic.start();
			if (Hoster)
			{
				lvllogic.hosterstart();
			}
			lvllogic.started = true;
			}
			else
			{
				//var D = 3;
				//var D = 4;
				var D = 5;
				if (!lvllogic.horizontalscrolling && scrollX != 0)
				{
					scrollspeedX = 0;
					if (Math.abs(scrollX) <= D)
					{
						scrollX = 0;
					}
					else
					{
						var dist = Math.abs(scrollX);
						var dist2 = Math.abs(scrollX - 1312);
						if (dist2 < dist)
						{
							scrollX -= 1312;
						}
						var A = (scrollX < 0);
						/*if (Math.abs(scrollX) > 500)
						{
							A = !A;
						}*/
						if (A)
						{
							scrollX += D;
						}
						else
						{
							scrollX -= D;
						}
						scrollwrap();
					}
				}
				//D = 1;
				//D = 2;
				D = 3;
				if (!lvllogic.verticalscrolling && scrollY != 0)
				{
					scrollspeedY = 0;
					var B = scrollY;
					/*while (B > 80)
					{
						B -= 160;
					}*/
					while (B > 160)
					{
						B -= 320;
					}
					//if (Math.abs(scrollY) <= D || Math.abs(scrollY-300) <= D)
					if (Math.abs(B) <= D)
					{
						scrollY = 0;
					}
					else
					{
						var A = (scrollY < 0);
						/*if (Math.abs(scrollY) > 300)
						{
							A = !A;
						}*/
						A = false;
						if (A)
						{
							scrollY += D;
						}
						else
						{
							scrollY -= D;
						}
						
						//scrollY = 0;
						scrollwrap();
					}
				}
			}
		}
		if (lvllogic != null && lvllogic.started)
		{
			lvllogic.update();
		}
		autoscroll();
		collisiondata = new Array<Dynamic>();
		collisiondangerousdata = new Array<Dynamic>();
		var col = 0;
		while (col < entities.length)
		{
			var E = entities[col];
			var D:Dynamic = { };
			D.E = E;
			D.B = E.GetHitbox();
			if (E.solid)
			{
				collisiondata[collisiondata.length] = D;
			}
			if (E.dangerous && !E.killed && E.type != "Block")
			{
				collisiondangerousdata[collisiondangerousdata.length] = D;
			}
			col++;
		}
		if (Hoster)
		{
			settotalenemies();
			if (!spawnpaused)
			{
				SpawnTimer -= 1;
				if ((activeEnemies.length < 1 || totalenemies < 1) && spawns>0 && enemyspawn)
				{
					SpawnTimer -= 2;
				}
			}
			if (totalenemies == 1 && Hoster)
			{
				if (activeEnemies.length > 0 && !activeEnemies[0].enraged && activeEnemies[0].needtokill && activeEnemies[0].subtype!="boss" && activeEnemies[0].enrageable)
				{
					SendEvent("Enrage", activeEnemies[0].UID);
				}
			}
			/*if (!spawnedChar && CombinedScore > PointsToLife >> 1)
			{
				if (totalenemies > 0)
				{
					if (totalenemies == 1 && activeEnemies.length == 1 && activeEnemies[0].killed)
					{
						//if last enemy is dying then dont spawn char yet
					}
					else
					{
						imposterbonus++;
						spawnedChar = true;
					}
				}
			}*/
			//check for silly amounts of unspent score.(may stop "quit glitch" from happening)
			if (CombinedScore > PointsToLife+PointsToLife)
			{
				var A = Players.iterator();
				while (A.hasNext())
				{
					var E = A.next();
					//if a single player has tons of unspent score let's assume that's invalid and 0 it out.
					if (PointsToLife+PointsToLife > (E.score - E.spentscore))
					{
					}
					else
					{
						E.spentscore = E.score;
						//prevent rewards from activating this frame
						CombinedScore = 0;
					}
				}
			}
			if (CombinedScore > PointsToLife)
			{
				
				var cost = PointsToLife;
				var A = Players.iterator();
				while (A.hasNext())
				{
					var E = A.next();
					if (cost > (E.score - E.spentscore))
					{
						cost -= (E.score - E.spentscore);
						E.spentscore = E.score;
					}
					else
					{
						E.spentscore += cost;
						cost = 0;
					}
				}
				var D:Dynamic = { };
				//D.type = "1up";
				D.type = "Mini1up";
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
				////spawnedChar = false;
				if (gamemode.canlivesspawn)
				{
					SendEvent("SpawnItem", D);
				}
				else
				{
					imposterbonus++;
				}
				CombinedScore -= PointsToLife;
			}
		}
		if (Sealed > 0)
		{
			Sealed--;
		}
		if (ufoseal > 0)
		{
			ufoseal--;
		}
		var i:Int = 0;
		while (i < entities.length)
		{
			var E = entities[i];
			var X = E.x;
			E.update();
			if (Sealed>0 && E.type == "Enemy" && (E.ground!=null || E.subtype=="mystia") && E.y<440)
			{
				//if (E.x > 800 || E.x < 0)
				//if (E.x > 784 || E.x < 0)
				var ok = false;
				if (E.x<0 && E.Hspeed<0)
				{
					//undo the movement.
					ok = true;
				}
				if (E.x>800 - E.width && E.Hspeed>0)
				{
					//undo the movement.
					ok = true;
				}
				if (E.wrapped)
				{
					ok = true;
					
				}
				if (ok)
				{
					E.x = Math.max(Math.min(X, 800 - E.width), 0);
					E.Hspeed = 0;
				}
			}
			if (!E.alive)
			{
				
				
				if (E.type == "Enemy")
				{
					if (!E.killed)
					{
						if (Hoster)
						{
							var D:Dynamic = E;
							var EE:Enemy = D;
							if (EE.respawn)
							{
								SpawnList.add(EE);
							}
						}
					}
					else
					{
						var EE:Dynamic = E;
						if (Hoster && EE.reward)
						{
							
							var D:Dynamic = { };
							
							D.type = "Point";
							
							if (EE.rewarditem != null)
							{
								//D.type = EE.rewarditem;
								D.type = EntityItem.getitem(EE.rewarditem);
							}
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
							
							var max = 12;
							if (online)
							{
								max -= Math.floor(GetPlayers().length / 2);
							}
							//if (Math.random() < 0.12/* || true*/)
							//if (Math.random() < 0.07/* || true*/)
							if (D.type == "Point")
							{
								if (Math.random() < 0.03)
							{
								D.type = "Power";
							}
							points++;
							if (points>=max && totalenemies > 3 && gamemode.ufoitemsenabled)
							{
								points -= max;
								D.type = "UFOItem";
								D.x = 800 * Math.random();
							}
							}
							D.y = -100;
							SendEvent("SpawnItem", D);
						}
					}
					
				}
				if (E.type == "Enemy")
				{
					var D:Dynamic = E;
					RemoveEnemy(E);
					if (Hoster)
					{
						settotalenemies();
					}
					else if (D.needtokill && D.killed)
					{
						//totalenemies--;
					}
				}
				else if (E.type == "Item")
				{
					RemoveEntityItem(E);
				}
				else
				{
					RemoveObject(E);
				}
			}
			i += 1;
		}
		var i = 0;
		if (MSE)
		{
			if (stage.mouseY < 600 && !menu)
			{
				var C = control.copy();
			control[0] = stage.mouseY < 100;
			control[1] = stage.mouseY > 500;
			control[2] = stage.mouseX < 200;
			control[3] = stage.mouseX > 600;
			if (C[0] != control[0] || C[1] != control[1] || C[2] != control[2] || C[3] != control[3])
					{
						ControlEvent = true;
					}
			}
			else if (stage.mouseY>=600)
			{
				if (Dpad.y + 384 < stage.mouseY)
				{
					Dpad.y = stage.mouseY - 383;
				}
				if (Dpad.y > stage.mouseY)
				{
					Dpad.y = Math.max(stage.mouseY-1,600);
				}
				if (stage.mouseX < 384 && stage.mouseY < Dpad.y+384)
				{
					var X = Math.floor(stage.mouseX) >> 7;
					var Y = Math.floor((stage.mouseY - Dpad.y))>> 7;
					//var X = Math.floor(stage.mouseX / 128);
					//var Y = Math.floor((stage.mouseY - Dpad.y) / 128);
					var C = control.copy();
					control[0] = Y == 0;
					control[1] = Y == 2;
					control[2] = X == 0;
					control[3] = X == 2;
					if (C[0] != control[0] || C[1] != control[1] || C[2] != control[2] || C[3] != control[3])
					{
						ControlEvent = true;
					}
				}
				
			}
		}
		if (flashalpha > 0 || flashalphadirection)
		{
			if (flashalphadirection)
			{
				flashalpha += flashrate;
				if (flashalpha > flashmaxalpha)
				{
					flashalpha = flashmaxalpha;
					flashalphadirection = false;
				}
			}
			else
			{
				flashalpha -= flashrate;
			}
			colorflash.alpha = flashalpha;
		}
		if (Hoster)
		{
			if (lvllogic != null)
			{
				lvllogic.hosterupdate();
			}
			//chances per minute(avg)
			
			//do obstacles
			if (totalenemies > 0 && ept>0 && Obstacles.length>0)
			{
				DoObstacles();
			}
			//replace start music and spawning with events that trigger it instead.
		if (SpawnTimer <= 0)
		{
			if (lvllogic != null && lvllogic.started)
			{
				lvllogic.tick();
			}
		}
		}
		else
		{
			//if not hosting ensure spawnlist has at least something in it, to help against hoster logging out with no enemies left causing game to stop progressing
			if (SpawnList.length == 0)
			{
				var enemy = new RedFairy();
				SpawnList.add(enemy);
			}
		}
		i = 0;
		while (i < queuedevents.length)
		{
			var Q = queuedevents[i];
			Q.update();
			if (!Q.alive)
			{
				queuedevents.remove(Q);
				i--;
			}
			i++;
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
	public function DoObstacles()
	{
		var R = ept;
			if ((spawns > (maxspawns + (maxspawns))) && boss == null)
			{
				R = rept;
			}
			if (Sealed<1 && ufoseal<1 && R>0 && enemyspawn && frame & 2 > 0 && Math.random()<R)
			{
				//var evt = Math.random();
				var E = "";
				if (Obstacles.length > 0)
				{
					E = Obstacles[Math.floor(Obstacles.length * Math.random())];
				}
				#if debug
				if (Math.random() > 0.5)
				{
					//E = "Balloon";
					//E = "Yuuka";
					//E = "Trophy";
					//E = "Yinyangorb";
					//E = "Iku";
					//E = "MiniPowBlock";
					//E = "MrGhosty";
					//E = "Reimu";
					//E = "UnzanFist";
					//E = "UFOItem";
					//E = "Explosives";
					//E = "Lily White";
				}
				#end
				if (E == "Gap")
				{
					SendGap();
				}
				else if (E == "Cirno")
				{
					var D:Dynamic = { };
					D.type = "Cirno";
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
					D.rank = rank;
					D.spawns = 0;
					SendEvent("SpawnEnemy", D);
				}
				else if (ufos<ufolimit && E == "UFO")
				{
					var D:Dynamic = { };
					D.type = "UFO";
					D.UID = Math.random();
					if (Math.random() > 0.5)
					{
						D.x = Math.random() * 800;
						D.Ldir = -1;
					}
					else
					{
						D.x = Math.random() * 800;
						D.Ldir = 1;
					}
					//D.y = -100;
					D.y = -200;
					D.alive = true;
					D.Hspeed = 0;
					D.Vspeed = 0;
					D.enraged = false;
					D.visible = true;
					D.rank = rank;
					D.spawns = 0;
					ufos++;
					SendEvent("SpawnEnemy", D);
				}
				else if (E == "GiantSuika" && thegiant != null && !thegiant.active && scrollspeedX==0 && scrollspeedY == 0)
				{
					//SendEvent("GiantSuikaAttack", null);
					activategiant();
				}
				else if (E == "Trophy" && !trophyactive)
				{
					var D:Dynamic = { };
					D.type = "Trophy";
					D.UID = Math.random();
					D.x = 400;
					D.y = -100;
					SendEvent("SpawnItem", D);
				}
				else if (E == "Balloon")
				{
					var D:Dynamic = { };
					D.type = "Balloon";
					D.UID = Math.random();
					D.x = Math.random() * 800;
					D.y = 600;
					SendEvent("SpawnItem", D);
				}
				else if (E == "Yinyangorb")
				{
					var D:Dynamic = { };
					D.type = "Yinyangorb";
					D.UID = Math.random();
					D.y = -100;
					if (Math.random() > 0.5)
					{
						D.x = 800;
						D.y = -200;
						D.Ldir = -1;
					}
					else
					{
						D.x = -16;
						D.Ldir = 1;
					}
					
					D.alive = true;
					D.Hspeed = 0;
					D.Vspeed = 0;
					D.enraged = false;
					D.visible = true;
					D.rank = rank;
					D.spawns = 0;
					SendEvent("SpawnEnemy", D);
				}
				//else if (E == "Yuuka" && !yuukaactive)
				else if (E == "Yuuka" && yuukasactive<maxyuuka)
				{
					var A = Players.iterator();
					var ok = false;
					while (A.hasNext())
					{
						var P = A.next();
						if (P.y < 400)
						{
							ok = true;
						}
					}
					if (ok)
					{
						SendYuuka();
					}
				}
				else if (E == "Iku")
				{
					var D:Dynamic = { };
					D.type = "Iku";
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
					D.rank = rank;
					D.spawns = 0;
					SendEvent("SpawnEnemy", D);
				}
				/*else if (E == "MiniPowBlock" && !minipowactive && minipowspawns < maxminipowspawns && scrollspeedX == 0 && scrollspeedY == 0 && allowpowblock)
				{
					var D:Dynamic = { };
					var R = Math.random();
					D.x = 400 - 16;
					D.y = 32;
					if (R < 0.5)
					{
						D.y = 160 + 16;
						D.x = 64;
						if (R < 0.25)
						{
							D.x = 800 - 96;
						}
					}
					SendEvent("SpawnMiniPowBlock", D);
				}*/
				else if (E == "MrGhosty")
				{
					var D:Dynamic = { };
					D.y = 580;
					D.x = 800 * Math.random();
					D.Hspeed = 0;
					D.Vspeed = -0.1;
					D.gravX = 0;
					D.gravY = -0.005;
					D.image = "mrghosty";
					SendEvent("ShootBullet", D);
				}
				else if (E == "Reimu")
				{
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
					D.rank = rank;
					D.spawns = 0;
					SendEvent("SpawnEnemy", D);
				}
				else if (E == "UnzanFist")
				{
					var D:Dynamic = { };
					D.x = Math.floor(Math.random() * 750);
					SendEvent("UnzanFist", D);
				}
				else if (E == "UFOItem")
				{
					var D:Dynamic = { };
							
					D.type = "UFOItem";
					D.UID = Math.random();
					D.x = -32;
					D.y = -200;
					//D.platform = E.UID;
					D.Ldir = 1;
					/*if (dir)
					{
						D.Ldir = -1;
					}
					else	
					{
						D.Ldir = 1;
					}*/
					//D.x = E.x;
					//D.y = E.y;
					SendEvent("SpawnItem", D);
				}
				else if (E == "Explosives")
				{
					var D:Dynamic = { };
					D.type = "Explosives";
					D.UID = Math.random();
					D.x = 800 * Math.random();
					D.y = 500 * Math.random();
					D.alive = true;
					D.Hspeed = 0;
					D.Vspeed = 0;
					D.enraged = false;
					D.visible = true;
					D.rank = rank;
					D.spawns = 0;
					SendEvent("SpawnEnemy", D);
				}
				else if (E == "Nitori")
				{
					var D:Dynamic = { };
					D.type = "Nitori";
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
					D.rank = rank;
					D.spawns = 0;
					SendEvent("SpawnEnemy", D);
				}
				else if (E == "Lily White")
				{
					var D:Dynamic = { };
					D.type = "Lily White";
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
					D.rank = rank;
					D.spawns = 0;
					SendEvent("SpawnEnemy", D);
				}
			}
	}
	
	public function CalculateLevelData()
	{
		if (lvllogic != null)
		{
			lvllogic.end();
			lvllogic = null;
		}
		updatelevelinfo();
		
		gamestarted = true;
		boss = null;
		ufolimit = 8;
		
		/*var L = level - 1;
		var stage = Math.floor((L) / 5);

		var generalstage = stage % 6;
		if (L < 0)
		{
			L = 0;
		}
		var lvl = ((level - 1) % 5);
		lvl++;*/
		var L = level - 1;
		var stage = currentstage;
		var generalstage = currentgeneralstage;
		var lvl = currentstagelevel;
		
		//count number of players(since it doesnt have a .length property :/ )
		var A = Players.keys();
		var P = 0;
		while (A.hasNext())
		{
			A.next();
			P+=1;
		}
		var EVT = Math.random();
		/*var LV:Int = level;
		while (LV >= 30)
		{
			LV -= 30;
		}*/
		var LV = currentranklevel;
		//if (level == 9)
		if (LV == 9)
		{
			//double chance of event
			//EVT *= 0.25;
			
			
			//EVT *= 0.1;
			EVT = 0;
		}
		RoundType = TypeofRound.EventNormal;
		//points *= 1.35;
		
		var T = level % levelsperstage;
		
		if (T == 0)
		{
			EVT = 0;
		}
		if (GameFlags.get(Main.EventRoundsOnly))
		{
			EVT = 0;
		}
		if (EVT < 0.05)
		{
			var E:Array<TypeofRound> = new Array<TypeofRound>();
			if (level != 9 || GameFlags.get(Main.EventRoundsOnly))
			{
				var BossRush = GameFlags.get(Main.Bossrush);
				if (!BossRush)
				{
				E[E.length] = TypeofRound.EventRumia;
				E[E.length] = TypeofRound.EventTable;
				if (level >= 9 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventCirno;
				}
				if (generalstage == 1)
				{
					E[E.length] = TypeofRound.EventPatchouli;
				}
				E[E.length] = TypeofRound.EventBalloon;
				if (Math.random() < 0.5)
				{
					E[E.length] = TypeofRound.EventCharacters;
				}
				if (level >= 11 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventNue;
					E[E.length] = TypeofRound.EventElly;
				}
				if (level > 5 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventSeija;
					E[E.length] = TypeofRound.EventMarisa;
				}
				if (level > 15 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventFireCirno;
					E[E.length] = TypeofRound.EventNoWrap;
					E[E.length] = TypeofRound.EventSuwako;
					if (generalstage != 2)
					{
						E[E.length] = TypeofRound.EventExplosive;
					}
					if (generalstage == 3)
					{
						E.push(TypeofRound.EventLava);
					}
				}
				if (level > 20 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventYukari;
					E[E.length] = TypeofRound.EventMagiFairy;
				}
				if (level > 25 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventYuuka;
				}
				if (level > 50 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventElectricCirno;
				}
				}
				else
				{
					E[E.length] = TypeofRound.EventYukari;
				}
				if ((level > 30) || GameFlags.get(Main.EventRoundsOnly) || BossRush)
				{
					if (generalstage == 0 || BossRush)
					{
						E[E.length] = TypeofRound.EventSanaeBoss;
					}
					if (generalstage == 3 || BossRush)
					{
						E[E.length] = TypeofRound.EventParseeBoss;
					}
					if (generalstage == 4 || BossRush)
					{
						E[E.length] = TypeofRound.EventMurasaBoss;
					}
					if (BossRush)
					{
						E[E.length] = TypeofRound.EventCirnoBoss;
					}
				}
			}
			else
			{
				E[E.length] = TypeofRound.EventCirno;
			}
			if (E.length > 1 && LRoundType != null && E.indexOf(LRoundType)>-1)
			{
				E.remove(LRoundType);
			}
			RoundType = E[(Math.floor(Math.random() * E.length))];
			LRoundType = RoundType;
			if (level > 30 && LV == 9 && !GameFlags.get(Main.EventRoundsOnly))
			{
				RoundType = TypeofRound.EventCirnoBoss;
			}
		}
		//RoundType = TypeofRound.EventParseeBoss;
		//RoundType = TypeofRound.EventLava;
		//RoundType = TypeofRound.EventDescending;
		//RoundType = TypeofRound.EventScrolling;
		//RoundType = TypeofRound.EventExplosive;
		//RoundType = TypeofRound.EventMagiFairy;
		//RoundType = TypeofRound.EventPatchouli;
		//RoundType = TypeofRound.EventElly;
		
		var Ev:Array<TypeofRound> = new Array<TypeofRound>();
		
		if (GameFlags.get(Main.TableEvent))
		{
			Ev[Ev.length] = TypeofRound.EventTable;
		}
		if (GameFlags.get(Main.CirnoEvent))
		{
			Ev[Ev.length] = TypeofRound.EventCirno;
		}
		if (GameFlags.get(Main.FireCirno))
		{
			Ev[Ev.length] = TypeofRound.EventFireCirno;
		}
		if (GameFlags.get(Main.ElectricCirno))
		{
			Ev[Ev.length] = TypeofRound.EventElectricCirno;
		}
		if (GameFlags.get(Main.NueEvent))
		{
			Ev[Ev.length] = TypeofRound.EventNue;
		}
		if (GameFlags.get(Main.BalloonEvent))
		{
			Ev[Ev.length] = TypeofRound.EventBalloon;
		}
		if (GameFlags.get(Main.YukariEvent))
		{
			Ev[Ev.length] = TypeofRound.EventYukari;
		}
		if (GameFlags.get(Main.Danmaku))
		{
			Ev[Ev.length] = TypeofRound.EventDanmaku;
		}
		if (GameFlags.get(Main.SanaeBoss))
		{
			Ev[Ev.length] = TypeofRound.EventSanaeBoss;
		}
		if (GameFlags.get(Main.ParseeEvent))
		{
			Ev[Ev.length] = TypeofRound.EventParseeBoss;
		}
		if (GameFlags.get(Main.LavaEvent))
		{
			Ev[Ev.length] = TypeofRound.EventLava;
		}
		if (GameFlags.get(Main.TruckHoarder))
		{
			Ev[Ev.length] = TypeofRound.EventTruck;
		}
		if (GameFlags.get(Main.PointCollecting))
		{
			Ev[Ev.length] = TypeofRound.EventPointCollecting;
		}
		if (GameFlags.get(Main.Explosive))
		{
			Ev[Ev.length] = TypeofRound.EventExplosive;
		}
		if (GameFlags.get(Main.YuukaEvent))
		{
			Ev[Ev.length] = TypeofRound.EventYuuka;
		}
		if (GameFlags.get(Main.SuwakoEvent))
		{
			Ev[Ev.length] = TypeofRound.EventSuwako;
		}
		if (Ev.length > 0)
		{
			RoundType = Ev[Math.floor(Math.random() * Ev.length)];
		}
		if (GameFlags.get(Main.NoEvents))
		{
			RoundType = TypeofRound.EventNormal;
		}
		
		if (RoundType == TypeofRound.EventNormal && GameFlags.get(Main.Adventure))
		{
			//if (Math.random() < 0.6/* || true*/)
			if (/*false && */Math.random() < 0.7/* || true*/)
			{
				RoundType = TypeofRound.EventScrolling;
			}
			else
			{
				RoundType = TypeofRound.EventDescending;
			}
		}
		//RoundType = TypeofRound.EventScrolling;
		//RoundType = TypeofRound.EventYuuka;
		//RoundType = TypeofRound.EventSuwako;
		
		lvllogic = GetLogic();
		lvllogic.CalculateLevelData(level);
		if (true)
		{
			lvllogic = null;
		}
		else
		{
			lvllogic.start();
			lvllogic.hosterstart();
		}
		SpawnTimer = 30;
		/*var L = level - 1;
		var stage = Math.floor((L) / 5);

		var generalstage = stage % 6;
		if (L < 0)
		{
			L = 0;
		}
		spawnrate = 1.0;
		rank = Math.floor(L / 30);
		L -= rank * 13;
		//calculate available budget for this level
		var points:Float = (L + 2);// * 2.0;
		//points *= 1.1;
		//points += ((level-1) % 5);
		var lvl = ((level - 1) % 5);
		lvl++;
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
		var A = Players.keys();
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
		RoundType = TypeofRound.EventNormal;
		enemytypes = new Array<Enemy>();
		//points *= 1.35;
		maxspawns = Math.ceil(points) + (P) + 1;
		
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
		if (EVT < 0.05)
		{
			var E:Array<TypeofRound> = new Array<TypeofRound>();
			if (level != 9 || GameFlags.get(Main.EventRoundsOnly))
			{
				var BossRush = GameFlags.get(Main.Bossrush);
				if (!BossRush)
				{
				E[E.length] = TypeofRound.EventRumia;
				E[E.length] = TypeofRound.EventTable;
				E[E.length] = TypeofRound.EventCirno;
				E[E.length] = TypeofRound.EventBalloon;
				E[E.length] = TypeofRound.EventCharacters;
				if (level >= 11 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventNue;
				}
				if (level > 5 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventSeija;
					E[E.length] = TypeofRound.EventMarisa;
				}
				if (level > 15 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventFireCirno;
					E[E.length] = TypeofRound.EventNoWrap;
				}
				if (level > 20 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventYukari;
				}
				if (level > 50 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.EventElectricCirno;
				}
				}
				else
				{
					E[E.length] = TypeofRound.EventYukari;
				}
				if ((level > 30) || GameFlags.get(Main.EventRoundsOnly) || BossRush)
				{
					if (generalstage == 0 || BossRush)
					{
						E[E.length] = TypeofRound.EventSanaeBoss;
					}
					if (generalstage == 3 || BossRush)
					{
						E[E.length] = TypeofRound.EventParseeBoss;
					}
					if (generalstage == 4 || BossRush)
					{
						E[E.length] = TypeofRound.EventMurasaBoss;
					}
					if (BossRush)
					{
						E[E.length] = TypeofRound.EventCirnoBoss;
					}
				}
			}
			else
			{
				E[E.length] = TypeofRound.EventCirno;
			}
			RoundType = E[(Math.floor(Math.random() * E.length))];
			
			if (level > 30 && LV == 9 && !GameFlags.get(Main.EventRoundsOnly))
			{
				RoundType = TypeofRound.EventCirnoBoss;
			}
		}
		//RoundType = TypeofRound.EventParseeBoss;
		//RoundType = TypeofRound.EventSeija;
		//RoundType = TypeofRound.EventMarisa;
		//RoundType = TypeofRound.EventNoWrap;
		
		
		
		var Ev:Array<TypeofRound> = new Array<TypeofRound>();
		if (GameFlags.get(Main.TableEvent))
		{
			Ev[Ev.length] = TypeofRound.EventTable;
		}
		if (GameFlags.get(Main.CirnoEvent))
		{
			Ev[Ev.length] = TypeofRound.EventCirno;
		}
		if (GameFlags.get(Main.FireCirno))
		{
			Ev[Ev.length] = TypeofRound.EventFireCirno;
		}
		if (GameFlags.get(Main.ElectricCirno))
		{
			Ev[Ev.length] = TypeofRound.EventElectricCirno;
		}
		if (GameFlags.get(Main.NueEvent))
		{
			Ev[Ev.length] = TypeofRound.EventNue;
		}
		if (GameFlags.get(Main.BalloonEvent))
		{
			Ev[Ev.length] = TypeofRound.EventBalloon;
		}
		if (GameFlags.get(Main.YukariEvent))
		{
			Ev[Ev.length] = TypeofRound.EventYukari;
		}
		if (GameFlags.get(Main.Danmaku))
		{
			Ev[Ev.length] = TypeofRound.EventDanmaku;
		}
		if (GameFlags.get(Main.SanaeBoss))
		{
			Ev[Ev.length] = TypeofRound.EventSanaeBoss;
		}
		if (Ev.length > 0)
		{
			RoundType = Ev[Math.floor(Math.random() * Ev.length)];
		}
		if (GameFlags.get(Main.NoEvents))
		{
			RoundType = TypeofRound.EventNormal;
		}
		//setup obstacles.
		
		if (RoundType == TypeofRound.EventNormal || RoundType == TypeofRound.EventRumia || RoundType == TypeofRound.EventTable || RoundType == TypeofRound.EventBalloon || RoundType == TypeofRound.EventCharacters || RoundType == TypeofRound.EventNoWrap)
		{
			if (level > 5)
			{
				//AddToArrayMultiple(Obstacles, "Cirno", 64);
				AddToArrayMultiple(Obstacles, "Cirno", 50);
				AddToArrayMultiple(Obstacles, "MrGhosty", 32);
			}
			AddToArrayMultiple(Obstacles, "Gap", 70);
			//AddToArrayMultiple(Obstacles, "Yinyangorb", 12); 
			AddToArrayMultiple(Obstacles, "Yinyangorb", 14); 
			AddToArrayMultiple(Obstacles, "MiniPowBlock", 2);
			if (level > 10)
			{
				AddToArrayMultiple(Obstacles, "UFO", 32);
			}
			{
				AddToArrayMultiple(Obstacles, "GiantSuika", 2);
				AddToArrayMultiple(Obstacles, "Trophy", 3);
			}
			if (level > 15)
			{
				AddToArrayMultiple(Obstacles, "Yuuka", 5);
			}
			if (level > 20)
			{
				AddToArrayMultiple(Obstacles, "Reimu", 5);
				AddToArrayMultiple(Obstacles, "UnzanFist", 12);
			}
			if (level > 30)
			{
				AddToArrayMultiple(Obstacles, "Iku", 3);
			}
		}
		if (GameFlags.get(Main.TruckHoarder))
		{
			spawnpaused = true;
			var D:Dynamic = { };
			D.type = "Trophy";
			D.UID = Math.random();
			D.x = 400;
			D.y = -100;
			SendEvent("SpawnItem", D);
		}
		if (RoundType == TypeofRound.EventDanmaku)
		{
			ufolimit = 10;
			AddToArrayMultiple(Obstacles, "Gap", 60);
			AddToArrayMultiple(Obstacles, "UFO", 32);
			AddToArrayMultiple(Obstacles, "UnzanFist", 12);
			AddToArrayMultiple(Obstacles, "Yuuka", 4);
			AddToArrayMultiple(Obstacles, "Yinyangorb", 7);
			epm *= 1.5;
		}
		if (RoundType == TypeofRound.EventNue)
		{
			Obstacles[Obstacles.length] = "UFO";
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
		}
		if (RoundType == TypeofRound.EventYukari)
		{
			Obstacles[Obstacles.length] = "Gap";
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
			epm *= 0.75;
		}
		if (RoundType == TypeofRound.EventBalloon)
		{
			AddToArrayMultiple(Obstacles, "Balloon", Math.round(Obstacles.length * 2));
			epm *= 2.5;
		}
		if (RoundType == TypeofRound.EventCirno || RoundType == TypeofRound.EventFireCirno || RoundType == TypeofRound.EventElectricCirno || RoundType == TypeofRound.EventCirnoBoss)
		{
			AddToArrayMultiple(Obstacles, "Cirno", 8);
			if (RoundType == TypeofRound.EventCirno)
			{
				AddToArrayMultiple(Obstacles, "GiantSuika", 1);
			}
			AddToArrayMultiple(enemytypes, new Imposter(), 1);
			if (RoundType == TypeofRound.EventFireCirno)
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
				if (!(RoundType == TypeofRound.EventFireCirno || RoundType == TypeofRound.EventElectricCirno || RoundType == TypeofRound.EventCirnoBoss))
				{
					maxspawns = 9;
				}
			}
			}
			//SendEvent("FreezeWorld", null);
		}
		//setup enemytypes.
		
		if (RoundType == TypeofRound.EventRumia)
			{
				AddToArrayMultiple(enemytypes, new Rumia(), 125);
				AddToArrayMultiple(enemytypes, new Imposter(), 3);
			}
			if (RoundType == TypeofRound.EventSeija)
			{
				AddToArrayMultiple(enemytypes, new Seija(), 62);
				AddToArrayMultiple(enemytypes, new Imposter(), 3);
			}
		if (RoundType == TypeofRound.EventNormal || RoundType == TypeofRound.EventRumia || RoundType == TypeofRound.EventSeija || RoundType == TypeofRound.EventNue || RoundType == TypeofRound.EventTable || RoundType == TypeofRound.EventFireCirno || RoundType == TypeofRound.EventBalloon || RoundType == TypeofRound.EventElectricCirno || RoundType == TypeofRound.EventNoWrap || RoundType == TypeofRound.EventSanaeBoss || RoundType == TypeofRound.EventParseeBoss || RoundType == TypeofRound.EventMurasaBoss)
		{
			var types = new Array<Array<Dynamic>>();
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
					if (level > 10)
					{
						types[types.length] = CreateArrayOfMultiple(new Tenshi(), 5);
						if (level > 15)
						{
							types[types.length] = CreateArrayOfMultiple(new Utsuho(), 4);
							if (level > 25)
							{
								types[types.length] = CreateArrayOfMultiple(new Imposter(), 1);
								if (generalstage == 5)
								{
									types[types.length] = CreateArrayOfMultiple(new Tewi(), 34);
									types[types.length] = CreateArrayOfMultiple(new Reisen(), 15);
								}
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
		if (RoundType == TypeofRound.EventDanmaku)
		{
			if (generalstage < 2)
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
			}
			AddToArrayMultiple(enemytypes, new Tewi(), 25);
			AddToArrayMultiple(enemytypes, new Utsuho(), 2);
			AddToArrayMultiple(enemytypes, new Kogasa(), 2);
			AddToArrayMultiple(enemytypes, new Marisa(), 3);
			AddToArrayMultiple(enemytypes, new Imposter(), 3);
		}
		if (RoundType == TypeofRound.EventMarisa)
		{
			AddToArrayMultiple(Obstacles, "Yuuka", 5);
			AddToArrayMultiple(enemytypes, new Marisa(), 600);
		}
		if (RoundType == TypeofRound.EventNue)
		{
			AddToArrayMultiple(enemytypes, new Nue(), 62);
			AddToArrayMultiple(enemytypes, new Imposter(), 3);
			epm *= 0.5;
			maxspawns = Math.ceil(maxspawns * 0.7);
		}
		if (RoundType == TypeofRound.EventTable)
		{
			epm *= 0.5;
			maxspawns = Math.ceil(maxspawns * 0.7);
		}
		AddToArrayMultiple(enemytypes, new Imposter(), 2);
		if (RoundType == TypeofRound.EventCharacters)
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
		var C = CombinedScoreALL + (level * 3000);
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
		if (RoundType == TypeofRound.EventCirnoBoss)
		{
			SpawnList.add(new BossCirno());
		}
		if (RoundType == TypeofRound.EventYukari)
		{
			SpawnList.add(new BossYukari());
		}
		else if (RoundType == TypeofRound.EventSanaeBoss)
		{
			SpawnList.add(new BossSanae());
		}
		else if (RoundType == TypeofRound.EventParseeBoss)
		{
			SpawnList.add(new BossParsee());
		}
		else if (RoundType == TypeofRound.EventMurasaBoss)
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
		populatespawnlist();
		
				
		epm += epmmodifier;
		ept = epm * (onetickperminutechance2);//the times 2 is for equalling "frame & 2>0" out above
		rept = (epm + 3 + (Math.floor(epm) >> 1)) * (onetickperminutechance2);*/
	}
	public function populatespawnlist()
	{
		if (lvllogic != null)
		{
			lvllogic.populatespawnlist();
		}
		/*while (imposterbonus > 0)
		{
			var enemy = new Imposter();
			enemy.UID = 0;
			SpawnList.add(enemy);
			imposterbonus--;
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
				if (boss != null)
				{
					tmp++;
				}
			}
		}*/
	}
	
}