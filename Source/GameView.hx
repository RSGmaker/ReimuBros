package;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.Assets;
import openfl.geom.Point;
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
		Normal;
		Nue;
		Seija;
		Cirno;
		Yukari;
		Rumia;
		Table;
		FireCirno;
		Balloon;
		ElectricCirno;
		Characters;
		NoWrap;
		Unzan;
	}
class GameView extends Sprite
{
	public static var _this:                    GameView;
	private var text:String;
	//the text at the top of the screen when playing.
	public var TF:TextField;
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
	public var messages:Array<String>;
	public var messagetime:Int;
	
	public var charselect:CharacterSelect;
	public var collisiondata:Array<Dynamic>;
	public var collisiondangerousdata:Array<Dynamic>;
	
	public function GetPlayers():Array<Player>
	{
		var ret = new Array<Player>();
		var A = Players.iterator();
		if (A.hasNext())
		{
			ret[ret.length] = A.next();
		}
		ret.sort(sortplayer);
		return ret;
	}
	public function unlockcharacter(name:String)
	{
		var i = Player.characters.indexOf(name);
		var savedata = Main._this.savedata;
		if (i > -1)
		{
			if (name.indexOf("ALT") > -1)
			{
				name = name.substr(0, name.length - 3);
				i = Player.characters.indexOf(name);
				if (!savedata.data.alts[i])
				{
					savedata.data.alts[i] = true;
					ShowMessage("Unlocked " + name.charAt(0).toUpperCase() + name.substr(1)+"☆!");
				}
			}
			if (!savedata.data.unlock[i])
			{
				savedata.data.unlock[i] = true;
				ShowMessage("Unlocked " + name.charAt(0).toUpperCase() + name.substr(1)+"!");
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
	
	public var Room:String;
	public var status:String;
	//total active ufos
	public var ufos:Int;
	public var HighScore:Int;
	
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
	public var PointsToLife:Int=14000;
	public var CombinedScore:Int = 0;
	//ALL means it even counts score used up on 1ups
	public var CombinedScoreALL:Int = 0;
	public var Obstacles:Array<String>;
	public var platformformation:Int = 0;
	public var currentformation = -1;
	
	//every 10000 point spawn a char(offset this by -5000 as a midway bonus to 1up)
	public var spawnedChar:Bool;
	
	//the current rank
	//every cycle(30 level is one cycle), ranks power up enemies and increase point values.
	public var rank:Int;
	
	public var thegiant:GiantSuika;
	public var trophyactive:Bool;
	public var yuukaactive:Bool;
	
	//how many rounds since the last game over.(effects events)
	public var successstreak:Int;
	
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
	
	
	public var spawnrate:Float = 1.0;
	var ZaWarudo:Sprite = null;
	var ZaWarudoCaster:Player = null;
	
	public var colorflash:Shape;
	
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
	
	public function GetImposterList():Array<String>
	{
		var stage = Math.floor((level - 1) / 5);

		var generalstage = stage % 6;
		var L = new Array<String>();
		if (RoundType == TypeofRound.Cirno || RoundType == TypeofRound.FireCirno || RoundType == TypeofRound.ElectricCirno)
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
		else if (RoundType == TypeofRound.Rumia)
		{
			L[L.length] = "rumia";
		}
		else if (RoundType == TypeofRound.Nue)
		{
			L[L.length] = "nue";
		}
		else if (RoundType == TypeofRound.Seija)
		{
			L[L.length] = "seija";
		}
		else if (RoundType == TypeofRound.Yukari)
		{
			L[L.length] = "chen";
			L[L.length] = "ran";
			L[L.length] = "yukari";
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
				L = L.concat(["reimu", "marisa", "sanae", "kanako", "suwako", "alice", "shanghai"/*, "suika"*/]);
				L = L.concat(["sara", "louise", "yuki", "mai", "ayana", "yumeko", "shinki", "makairesident-a", "lilith", "orange", "kurumi", "elly", "rengeteki"/*, "yuuka"*/, "mugetsu", "gengetsu", "ellen", "kotohime", "kana", "rikako", "chiyuri", "yumemi", "ruukoto", "rika", "noroiko", "meira", "matenshi", "shingyoku", "elis", "sariel", "mima", "konngara"]);
				L = L.concat(["lily", "lyrica", "lunasa", "merlin","youmu", "yuyuko"]);
			}
			//sdm
			if (generalstage == 1)
			{
				L = L.concat(["daiyousei", "meiling", "koakuma", "patchouli", "sakuya",/* "remilia", "flandre",*/ "rin"]);
				L = L.concat(["lunachild", "starsaphire", "sunnymilk"]);
			}
			//space
			if (generalstage == 2)
			{
				L = L.concat(["iku", "tenshi", "hatate", "kokoro"]);
				
				L = L.concat(["sumireko", "seiran", "ringo", "doremy"]);
				
				L = L.concat(["reisen", "toyohime", "yorihime"]);
			}
			//underground
			if (generalstage == 3)
			{
				L = L.concat([/*"kisume", */"yamame", "parsee", "yuugi", /*"satori", "koishi",*/ "orin", "utsuho"]);
				L = L.concat(["shizuha", "minoriko", "hina", "nitori", "momiji"/*, "sanae", "kanako", "suwako"*/]);
			}
			//palanquin ship
			if (generalstage == 4)
			{
				L = L.concat(["nazrin", "kogasa", "ichirin"/*,"unzan"*/, "murasa", "shou", "byakuren"]);
				L = L.concat(["kyouko", "yoshika", "seiga", "tojiko", "futo", "miko", "mamizou"]);
			}
			//eintei
			if (generalstage == 5)
			{
				L = L.concat(["wriggle", "mystia", "keine", "tewi", "udongein", "eirin"/*, "kaguya", "mokou"*/]);
				L = L.concat(["wakasagihime", "sekibanki", "kagerou", "benben", "yatsuhashi", "seija", "shinmyoumaru", "raiko"]);
			}
			}
			else
			{
				// a simpler system, where we just remove event unlockables and put the rest in the list.
				L = L.concat(["reimu", "marisa", /*"rumia",*/ "daiyousei", /*"cirno",*/ "meiling", "koakuma", "patchouli", "sakuya", "remilia", "flandre", "rin",
				"letty", /*"chen",*/ "alice", "shanghai"/*,"hourai"*/, "lily", "lyrica", "lunasa", "merlin", "youmu", "yuyuko", /*"ran", "yukari",*/
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
				"lunachild", "starsaphire", "sunnymilk", "reisen", "toyohime", "yorihime", "kasen", "kosuzu","tokiko","akyu","maribel","renko",
				"shingyoku","elis", "sariel", "mima", "konngara",
				"rika","noroiko", "meira", "matenshi",
				"ellen", "kotohime", "kana", "rikako", "chiyuri", "yumemi", "ruukoto",
				"orange", "kurumi", "elly", "rengeteki"/*, "yuuka"*/, "mugetsu", "gengetsu",
				"sara", "louise"/*,"alice"*/, "yuki", "mai", "ayana", "yumeko", "shinki", "makairesident-a", "lilith"]);
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
		removeEventListener (Event.ENTER_FRAME, this_onEnterFrame);
		removeEventListener( MouseEvent.MOUSE_DOWN, on_mousedown );
		removeEventListener(MouseEvent.MOUSE_UP, on_mouseup); 
		removeEventListener( TouchEvent.TOUCH_BEGIN, on_touchbegin);
		removeEventListener( TouchEvent.TOUCH_END, on_touchend);
		entities = new Array<Entity>();
		//entities = null;
	}
	public function start() {
		
		{
			
		SoundManager.PlayJingle("startgame").addEventListener(Event.SOUND_COMPLETE,function(e:Event):Void {PlayMusic();});
		}
		collisiondata = new Array<Dynamic>();
		collisiondangerousdata = new Array<Dynamic>();
		successstreak = 0;
		recievedmessagelog = new Map<String,Int>();
		sentmessagelog = new Map<String,Int>();
		yuukaactive = false;
		trophyactive = false;
		_this = this;
		RoundType = TypeofRound.Normal;
		spawnedChar = false;
		OBackground = new Bitmap(AL.GetAnimation("CSBG")[0]);
		Background = new Bitmap(AL.GetAnimation("BG")[0]);
		
		
		Background.alpha = 0;
		addChild(OBackground);
		addChild(Background);
		HighScore = Main._this.savedata.data.highscore;
		ufos = 0;
		Players = new Map<String,Player>();
		ControlEvent = false;
		touched = false;
		totalenemies = 0;
		activeEnemies = new Array<Enemy>();
		activeItems = new Array<EntityItem>();
		activeInteractables = new Array<Entity>();
		SpawnTimer = 30 * 5;
		MSE = false;
		
		level = 0;
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
		AddObject(thegiant);
		if (AL == null)
		{
			AL = new Animationloader();
		}
		if (playerspick=="")
		{
			playerspick = Player.getRandomCharacter();
		}
		myplayer = new Player(playerspick, control);
		myplayer.x = 140;
		myplayer.y = (600-32)-myplayer.height;
		myplayer.playername = playername;
		
		if (GameFlags.get(Main.KonamiCode))
		{
			startinglives = 30;
			myplayer.lives = 30;
		}
		if (GameFlags.get(Main.NormalMode))
		{
			level = 30;
		}
		if (GameFlags.get(Main.HardMode))
		{
			level = 60;
		}
		if (GameFlags.get(Main.LunaticMode))
		{
			level = 90;
		}
		if (GameFlags.get(Main.ExtraMode))
		{
			level = 120;
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
		TF.visible = true;
		
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
		gameover.mouseEnabled = false;
		gameover.visible = false;
		addChild(gameover);
		
		scoreboard = new TextField();
		scoreboard.cacheAsBitmap = true;
		scoreboard.text = "";
		scoreboard.x = 3;
		scoreboard.y = 3;
		//scoreboard.x = 300;
		//scoreboard.y = 10;
		scoreboard.blendMode = openfl.display.BlendMode.INVERT;
		
		SC = new Sprite();
		SC.x = 300;
		SC.y = 10;
		SC.addChild(scoreboard);
		addChild(SC);
		
		//addChild(scoreboard);
		
		//the miko sticks in the corners of the screen.
		var B = new Bitmap(AL.GetAnimation("barrier")[0]);
		B.x = -20-40;
		B.y = 430;
		addChild(B);
		
		B = new Bitmap(AL.GetAnimation("barrierF")[0]);
		B.x = 820-160+40;
		B.y = 430;
		addChild(B);
		B = new Bitmap(AL.GetAnimation("barrier")[0]);
		B.x = -20-40;
		B.y = -40;
		addChild(B);
		B = new Bitmap(AL.GetAnimation("barrierF")[0]);
		B.x = 820-160+40;
		B.y = -40;
		addChild(B);
		
		
		direction = 1;
		ZaWarudo = new Sprite();
		ZaWarudo.graphics.beginFill(0xFFFFFF, 1);
		ZaWarudo.graphics.drawRect(0, 0, 800, 600);
		ZaWarudo.graphics.endFill();
		ZaWarudo.blendMode = openfl.display.BlendMode.INVERT;
		ZaWarudo.visible = false;
		addChild(ZaWarudo);
		
		
		AddPlayer(myplayer);
		addChild(TF);
		
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
		
		
		addEventListener (Event.ENTER_FRAME, this_onEnterFrame);
	addEventListener( MouseEvent.MOUSE_DOWN, on_mousedown );
	addEventListener(MouseEvent.MOUSE_UP, on_mouseup); 
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
		
		BGCRight = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCRight.x = 800;
		BGCRight.y = 0;
		BGCRight.scaleX = 500;
		BGCRight.scaleY = 2000;
		//addChild(BGCRight);
		gui.addChild(BGCRight);
		BGCLeft = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCLeft.x = -500;
		BGCLeft.y = 0;
		BGCLeft.scaleX = 500;
		BGCLeft.scaleY = 2000;
		//BGCLeft.z = -10;
		//addChild(BGCLeft);
		gui.addChild(BGCLeft);
		BGCBottom = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCBottom.x = -500;
		BGCBottom.y = 600;
		BGCBottom.scaleX = 1500;
		BGCBottom.scaleY = 1000;
		//BGCBottom.z = -10;
		//addChild(BGCBottom);
		gui.addChild(BGCBottom);
		Dpad = new Bitmap(Assets.getBitmapData("assets/Dpad.png"));
		Dpad.x = 0;
		Dpad.y = 600;
		//addChild(Dpad);
		gui.addChild(Dpad);
		
		colorflash = new Shape();
		//addChild(colorflash);
		gui.addChild(colorflash);
	}
	//sets down platforms and puts holes in the platforms
	public function setformation()
	{
		resetblocks();
		if (platformformation == 0)
		{
			setholeinplatform(600 - 192, 256, 512,false);
			//setholeinplatform(600 - 192, 288, 480,false);
			//setholeinplatform(600 - 352, 192, 576,true);
			setholeinplatform(600 - 352, 160-32, 608+32,true);
			//setholeinplatform(600 - 512, 256, 512, false);
			setholeinplatform(600 - 512, 288, 480, false);
			
			//addsectioninplatform(600 - 352, -1000, 96, false);
			//addsectioninplatform(600 - 352, 672, 2000, false);
			
			
			setplatformasplatform(600 - 192, false);
			setplatformasplatform(600 - 352, false);
			setplatformasplatform(600 - 512, false);
			currentformation = 0;
		}
		if (platformformation == 1)
		{
			setholeinplatform(600 - 192, -256, 5120, false);
			setholeinplatform(600 - 352, -192, 5760,false);
			setholeinplatform(600 - 512, -256, 5120, false);
			currentformation = 1;
		}
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
		xx -= 128+128;
		while (xx < 928+128)
		{
			var block = new Block("block");
			block.x = xx;
			block.y = Y;
			block.solid = true;
			AddObject(block);
			xx += 32;
		}
	}
	public function addsectioninplatform(Y:Float,minx:Float, maxx:Float, inverse:Bool)
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
					if (B.y == Y)
					{
						var ok = (B.x > minx && B.x < maxx);
						
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
	public function setholeinplatform(Y:Float,minx:Float, maxx:Float, inverse:Bool)
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
					if (B.y == Y)
					{
						var ok = (B.x > minx && B.x < maxx);
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
	public function setplatformasplatform(Y:Float,platform:Bool)
	{
		var i = 0;
			while (i < entities.length)
			{
				
				var E = entities[i];
				var D:Dynamic = E;
				
				if (E.type == "Block")
				{
					var B:Block = D;
					if (B.y == Y)
					{
						B.platform = platform;
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
	private function PlayMusic():Void
	{
		OBackground.bitmapData = Background.bitmapData;
		var L = Math.floor((level-1) / 5);
			var A = AL.GetAnimation("BG");
			if (L < 0)
			{
				L = 0;
			}
			while (L >= A.length)
			{
				L -= A.length;
			}
			Background.bitmapData = A[L];
			Background.alpha = 0;
			
		L = Math.floor((level - 1) / 5);
		ShowLevel();
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
			musicchannel = SoundManager.PlayMusic("theme" + A[L]);
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
					removeChild(player.nameplate);
				}
				Players.remove(P);
				entities.remove(player);
				removeChild(player);
			}
			
		}
	}
	private function AddEntityItem(E:EntityItem) {
		AddObject(E);
		activeItems[activeItems.length] = E;
	}
	private function AddEnemy(E:Enemy) {
		AddObject(E);
		if (E.respawn)
		{
			activeEnemies[activeEnemies.length] = E;
		}
	}
	public function AddObject(E:Entity) {
		if (E.interactable/* && activeInteractables.indexOf(E >= 0)*/)
		{
			activeInteractables[activeInteractables.length] = E;
		}
		entities[entities.length] = E;
		addChild(E);
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
		removeChild(I);
		entities.remove(I);
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
			if (!E.killed && E.alive)
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
	public function CollisionDetectTouchDangerous(target:Entity):Entity {
		var i = 0;
		var R = target.getBounds(this);
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
		var R = target.getBounds(this);
		while (i < activeInteractables.length)
		{
			var E = activeInteractables[i];
			
			if (E.interactable && E.alive && E.readyinteract && !E.killed && E.type != "Block")
			{
				if (R.intersects(E.getBounds(this))/*containsPoint(new Point(X,Y))*/)
				{
					return E;
				}
			}
			i += 1;
		}
		//return false;
		return null;
	}
	public function CollisionDetectTouchEnemy(target:Entity):Enemy {
		var i = 0;
		var R = target.getBounds(this);
		while (i < activeEnemies.length)
		{
			var E = activeEnemies[i];
			
			if (!E.killed)
			{
				if (R.intersects(E.getBounds(this)))
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
		var R = target.getBounds(this);
		while (i < activeItems.length)
		{
			var E = activeItems[i];
			
			if (!E.killed)
			{
				if (R.intersects(E.getBounds(this)))
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
			NP.SendData("GameEvent", D);
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
		if (evt == "ChangeCharacter")
		{
			if (P.charname != data)
			{
				P.init(data);
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
				if (E.x == data.x && E.y == data.y && E.type == "Block")
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
				P.ability.onattacked();
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
			if (E.attack())
			{
				ProcessEvent("Kill", ID, data);
			}
		}
		if (evt == "Remove")
		{
			var E = EntityFromUID(data);
			if (E != null)
			{
				E.alive = false;
			}
		}
		if (evt == "Kill" || evt == "Destroy") {
			var E = EntityFromUID(data);
			if (E != null && !E.killed)
			{
				P.ability.onkill(E);
				E.bonkedby = P;
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
				if (me && D.charname == "Imposter")
				{
					//if an unlockable character(aka imposter) is killed, unlock the character.
					unlockcharacter(D.rename);
					/*if (!D.hidden)
					{

					Main._this.savedata.data.unlock[D.unlock] = true;
					if (D.alternate)
					{
						Main._this.savedata.data.alts[D.unlock] = true;
					}
					}
					else
					{
						Main._this.savedata.data.hidden[D.unlock] = true;
					}*/
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
				if (P != null && evt == "Kill")
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
			if (me && online)
			{
				#if flash
				NP.Flush();
				#end
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
					E.bonked = 8;
					E.bonkedby = P;
				
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
			if (RoundType != R)
			{
				if (R == TypeofRound.Table)
				{
					ProcessEvent("Spawntables", "Myself", null);
				}
				if (R == TypeofRound.NoWrap)
				{
					ProcessEvent("NoWrap", "Myself", null);
				}
				if (R == TypeofRound.Cirno || R == TypeofRound.FireCirno || R == TypeofRound.ElectricCirno)
				{
					ProcessEvent("FreezeWorld", "Myself", null);
				}
			}
			minipowspawns = 0;
			RoundType = R;
			this.x = 0;
			this.y = 0;
			this.scaleX = 1;
			this.scaleY = 1;
			successstreak++;
			if (myplayer.score > HighScore && GameFlags.getactiveflags().length==0)
				{
					HighScore = myplayer.score;
					Main._this.savedata.data.highscore = HighScore;
				}
			ufos = 0;
			spawns = 0;
			roundstarted = false;
			level = data.level;
			var L = level - 1;
			if (L < 0)
			{
				L = 0;
			}
			rank = Math.floor(L / 30);
			//ShowLevel();
			//call playmusic() as it will change song if its new
			SoundManager.PlayJingle("nextlevel").addEventListener(Event.SOUND_COMPLETE, function(e:Event):Void { PlayMusic(); } );
			var i = 0;
			while (i < entities.length)
			{
				
				var E = entities[i];
				var D:Dynamic = E;
				if (E.type == "Block" && RoundType != TypeofRound.Cirno && RoundType != TypeofRound.FireCirno && RoundType != TypeofRound.ElectricCirno)
				{
					D.Clean();
				}
				if (E.type == "Enemy")
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
				if (E.type == "Bullet" && (RoundType != TypeofRound.NoWrap))
				{
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Table" && (RoundType != TypeofRound.Table || Hoster))
				{
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Carryitem" && D.DestroyOnRoundEnd)
				{
					E.killed = true;
					E.alive = false;
				}
				if (E.type == "Yuuka")
				{
					E.killed = true;
					E.alive = false;
				}
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
			yuukaactive = false;
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
				if (E != P)
				{
					P.ability.onbump(E);
				}
				E.bump();
				if (!me)
				{
					E.catchup();
				}
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
				if (E.type == "Bullet" && (RoundType != TypeofRound.NoWrap))
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
		if (evt == "PlayerRespawn")
		{
			P.x = data.x;
			P.y = data.y;
			P.lives = data.lives;
			P.Hspeed = 0;
			P.Vspeed = 0;
			P.rotation = 0;
			P.killed = false;
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
			if (me)
			{
				SoundManager.PlayJingle("gameover").addEventListener(Event.SOUND_COMPLETE, function(e:Event):Void {/*if (online)*/{ SendEvent("Continue", null); }} );
				gameover.visible = true;
				if (myplayer.score > HighScore)
				{
					HighScore = myplayer.score;
					Main._this.savedata.data.highscore = HighScore;
				}
			}
		}
		if (evt == "RefreshPowBlock")
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
			P.lives = startinglives;
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
		if (evt == "Status")
		{
			if (data.level > level)
			{
				level = data.level;
				PlayMusic();
			}
			level = data.level;
			totalenemies = data.totalenemies;
			sessionID = data.sessionID;
			if (Main._this.lastsession != null && sessionID == Main._this.lastsession.sessionID)
			{
				if (Main._this.lastsession.lives >= 0)
				{
					SendEvent("loadsession", Main._this.lastsession);
				}
				Main._this.lastsession = null;
			}
			var R = TypeofRound.createByIndex(data.RoundType);
			if (RoundType != R)
			{
				if (R == TypeofRound.Table)
				{
					ProcessEvent("Spawntables", "Myself", null);
				}
				if (R == TypeofRound.NoWrap)
				{
					ProcessEvent("NoWrap", "Myself", null);
				}
				if (R == TypeofRound.Cirno || R == TypeofRound.FireCirno || R == TypeofRound.ElectricCirno)
				{
					ProcessEvent("FreezeWorld", "Myself", null);
				}
			}
			RoundType = R;
			///gamemode = data.gamemode;
			var G = data.GameFlags;
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
			if (data.activeEnemies != activeEnemies.length && syncdelay<1)
			{
				//ask hoster to resend current enemy states.
				SendEvent("EnemySync", null);
				syncdelay = 60;
			}
			if (data.activeItems != activeItems.length && syncdelay<1)
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
				D.Vspeed = E.Vspeed ;
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
					D.alive = false;
					D.killed = true;
					P.ability.oncollect(D);
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
		if (evt == "Earthquake")
		{
			SoundManager.Play("pow");
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block" && E.y == data)
				{
					E.bonked = 8;
					E.bonkedby = GetPlayer(ID);
				}
				i++;
			}
			if (thegiant.active && thegiant.rotation == 0)
			{
				thegiant.tipover();
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
			if (myplayer == P)
			{
				//Main._this.savedata.data.unlock[Player.characters.indexOf("suika")] = true;
				unlockcharacter("suika");
			}
			SoundManager.Play("pow");
			var i = 0;
			while (i < entities.length)
			{
				var E = entities[i];
				if (E.type == "Block")
				{
					E.bonked = 8;
					E.bonkedby = GetPlayer(ID);
				}
				i++;
			}
			if (powblock.HP == 0)
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
			}
		}
		if (evt == "Enrage")
		{
			var D:Dynamic = EntityFromUID(data);
			if (D != null && D.type == "Enemy")
			{
				D.enrage();
				D.enraged = true;
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
				}
				i += 1;
			}
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
			var D:UFO = E;
			//trace("UFO strike confirmed!");
			if (D.ufotype == "Red")
			{
				//trace("Red pattern detected!");
				var O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = -2;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = -3;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 2;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 3;
				O.Vspeed = 4;
				AddObject(O);
			}
			if (D.ufotype == "Green")
			{
				//trace("Green pattern detected!");
				var O = new Bullet();
				O.x = D.x-10;
				O.y = D.y;
				O.Hspeed = 0;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x+10;
				O.y = D.y;
				O.Hspeed = 0;
				O.Vspeed = 4;
				AddObject(O);
			}
			if (D.ufotype == "Blue")
			{
				//trace("Blue pattern detected!");
				var O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 0;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = 2;
				O.Vspeed = 4;
				AddObject(O);
				O = new Bullet();
				O.x = D.x;
				O.y = D.y;
				O.Hspeed = -2;
				O.Vspeed = 4;
				AddObject(O);
			}
		}
		if (evt == "PlayerDanmaku")
		{
			//var E:Dynamic = EntityFromUID(data.UID);
			var O = new PlayerBullet();
			O.x = data.x;
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
			
			
			O.image.image_speed = 1;
			O.allowwrap = data.wrap;
			if (O.Hspeed >= 0)
			{
				O.ChangeAnimation(data.type);
			}
			else
			{
				O.ChangeAnimation(data.type+"F");
			}
			AddObject(O);
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
				if (this.scaleY == 1)
				{
					this.scaleY = -1;
					this.y = 600;
				}
				else
				{
					this.scaleY = 1;
					this.y = 0;
				}
			}
			else
			{
				if (this.scaleX == 1)
				{
					this.scaleX = -1;
					this.x = 800;
				}
				else
				{
					this.scaleX = 1;
					this.x = 0;
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
				O.ChangeAnimation("table");
			}
			else
			{
				O.ChangeAnimation("hammer");
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
			RoundType = TypeofRound.Table;
		}
		if (evt == "NoWrap")
		{
			var O;
			var X = 0;
			var Y = 0;
			while (Y < 600)
			{
				O = new Bullet();
				O.x = X;
				O.y = Y;
				O.ChangeAnimation("skull");
				AddObject(O);
				Y += 32;
			}
			Y = 0;
			X = 800 - 32;
			while (Y < 600)
			{
				O = new Bullet();
				O.x = X;
				O.y = Y;
				O.ChangeAnimation("skull");
				AddObject(O);
				Y += 32;
			}
			RoundType = TypeofRound.NoWrap;
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
		if (evt == "GiantSuikaAttack")
		{
			if (thegiant != null && !thegiant.active)
			{
				thegiant.activate();
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
				yuukaactive = true;
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
			ZaWarudoCaster = P;
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
					else if (R < 0.83)
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
		if (evt == "CustomEvent")
		{
			var E = EntityFromUID(data.UID);
			if (E != null && E.alive)
			{
				E.CustomEvent(data.data);
			}
		}
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
	public function stage_onKeyDown (event:KeyboardEvent):Void {
		//TF.text = "test"+event.toString();
		if (event.keyCode == Keyboard.SPACE) {
				//TF.text = "space!";
		}
		switch (event.keyCode) {
			
		case Keyboard.Q:
			SendEvent("Quitting", null);
			status = "quitting";
		case Keyboard.F1:
			if (Hoster && Main._this.DEBUG)
			{
				SpawnTimer = 1;
				if (SpawnList.length == 0)
				{
					level++;
					if (((level - 1) % 5)+1 == 1)
					{
						PlayMusic();
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
				SendEvent("GiantSuikaAttack", null);
			}
		case Keyboard.F3:
			if (Hoster && Main._this.DEBUG)
			{
				SendGap();
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
				//SendYuuka();
				var B = new Boss();
				AddObject(B);
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
			menu = !menu;
			if (!online)
			{
				//paused = !paused;
				paused = menu;
			}
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
				if (E.alive && !E.killed)
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
		var type = "";
		if (EntityFromUID(D.UID) == null)
		{
					if (D.type == "RedFairy")
					{
						E = new RedFairy();
						type = "Enemy";
					}
					if (D.type == "Mystia")
					{
						E = new Mystia();
						type = "Enemy";
					}
					if (D.type == "Keine")
					{
						E = new Keine();
						type = "Enemy";
					}
					if (D.type == "Keineex")
					{
						E = new Keine();
						type = "Enemy";
						E.ex = true;
					}
					if (D.type == "Chen")
					{
						E = new Chen();
						type = "Enemy";
					}
					if (D.type == "UFO")
					{
						E = new UFO();
						type = "Enemy";
					}
					if (D.type == "Cirno")
					{
						E = new Cirno();
						type = "Enemy";
					}
					if (D.type == "Imposter")
					{
						E = new Imposter();
						type = "Enemy";
					}
					if (D.type == "rumia")
					{
						E = new Rumia();
						type = "Enemy";
					}
					if (D.type == "seija")
					{
						E = new Seija();
						type = "Enemy";
					}
					if (D.type == "Nue")
					{
						E = new Nue();
						type = "Enemy";
					}
					if (D.type == "Nue")
					{
						E = new Nue();
						type = "Enemy";
					}
					if (D.type == "tewi")
					{
						E = new Tewi();
						type = "Enemy";
					}
					if (D.type == "kaguya" || D.type == "mokou")
					{
						if (D.type == "mokou")
						{
							E = new TwuckHunter(true);
						}
						else
						{
							E = new TwuckHunter(false);
						}
						type = "Enemy";
					}
					if (D.type == "utsuho")
					{
						E = new Utsuho();
						type = "Enemy";
					}
					if (D.type == "satori")
					{
						E = new Satori();
						type = "Enemy";
					}
					if (D.type == "Scarlet")
					{
						E = new Scarlet();
						type = "Enemy";
					}
					if (D.type == "meiling")
					{
						E = new Meiling();
						type = "Enemy";
					}
					if (D.type == "udongein")
					{
						E = new Reisen();
						type = "Enemy";
					}
					if (D.type == "kogasa")
					{
						E = new Kogasa();
						type = "Enemy";
					}
					if (D.type == "Nazrin")
					{
						E = new Nazrin();
						type = "Enemy";
					}
					if (D.type == "Iku")
					{
						E = new Iku();
						type = "Enemy";
					}
					if (D.type == "Reimu")
					{
						E = new Reimu();
						type = "Enemy";
					}
					if (D.type == "Yinyangorb")
					{
						E = new Yinyangorb();
						type = "Enemy";
					}
					if (E != null && type=="Enemy")
					{
						E.UID = D.UID;
						E.y = D.y;
						E.x = D.x;
						E.Ldir = D.Ldir;
						E.alive = D.alive;
						E.Hspeed = D.Hspeed;
						E.Vspeed = D.Vspeed;
						E.enraged = D.enraged;
						E.rank = D.rank;
						E.visible = D.visible;
						E.spawns = D.spawns + 1;
						if (D.enraged)
						{
							E.enrage();
						}
					}
					if (D.type == "Point")
					{
						E = new PointItem();
						SoundManager.Play("spawncoin");
						type = "Item";
					}
					if (D.type == "GiantPoint")
					{
						E = new GiantPointItem();
						SoundManager.Play("spawncoin");
						type = "Item";
					}
					if (D.type == "Trophy" || D.type == "trophy")
					{
						E = new TrophyItem();
						type = "Item";
					}
					if (D.type == "Balloon")
					{
						E = new BalloonItem();
						type = "Item";
					}
					if (D.type == "Myon" || D.type == "myon")
					{
						E = new MyonItem();
						type = "Item";
					}
					if (D.type == "1up")
					{
						E = new LifeItem();
						SoundManager.Play("spawncoin");
						type = "Item";
					}
					if (D.type == "Bomb")
					{
						E = new BombItem();
						SoundManager.Play("spawncoin");
						type = "Item";
					}
					if (D.type == "MiniBomb")
					{
						E = new MiniBombItem();
						SoundManager.Play("spawncoin");
						type = "Item";
					}
					if (E != null && type == "Item")
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
		}
		return E;
	}
	public function ShowLevel()
	{
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
		var stage = Math.floor((level - 1) / 5);
		stage = stage % 6;

		var lvl = ((level - 1) % 5);
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
		S = S + S2 + "-" + lvl;
		var M = messages.length;
		ShowMessage(S);
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
	private function this_onEnterFrame (event:Event):Void {
		if (_this != this)
		{
			return;
		}
		if (menu)
		{
			if (charselect == null)
			{
				charselect = new CharacterSelect(playerspick);
				var B = new MenuButton("Quit Game");
				B.x += 670;
				B.y += 500;
				B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "quitting";
					
				 } 
				);
				charselect.addChild(B);
				gui.addChild(charselect);
			}
		}
		if (!online && paused)
		{
			TF.text = "Paused";
			ltime = Timer.stamp ();
			return;
		}
		if (charselect != null && !menu)
		{
			if (charselect.selected != playerspick)
			{
				playerspick = charselect.selected;
				SendEvent("ChangeCharacter", playerspick);
				//myplayer.init(playerspick);
			}
			gui.removeChild(charselect);
			charselect = null;
		}
		if (pausetime>0)
		{
			TF.text = "Time has stopped";
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
		var currentTime = Timer.stamp ();
		var T = currentTime - ltime;
		missingTime += T;
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
						TF.text = "Host: " + Room + "\nLevel: " + level +"\nLives: " + Math.max(myplayer.lives,0)+"\nEnemies: "+totalenemies;
						ok = false;
					}
				}
			}
			if (ok)
			{
				TF.text = "Client: " + Room + "\nLevel: " + level +"\nLives: " + Math.max(myplayer.lives,0)+"\nEnemies: "+totalenemies;
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
			TF.text = "Level: " + level +"\nLives: " + Math.max(myplayer.lives,0)+"\nEnemies: "+totalenemies;
		}
		if (Main._this.DEBUG && Hoster)
		{
			TF.text = TF.text + "\nEPM: " + Math.round(epm) + " max: " + maxspawns+"\nspawnrate: "+spawnrate;
		}
		TF.textColor = 0xFFFFFF;
		if (missingTime > 3 /* && !online*/)
		{
			missingTime = 0.041;
		}
		updategame(event);
		missingTime -= 0.0334;
		if (missingTime < 0)
		{
			missingTime = 0;
		}
		while (missingTime > 0.04)
		{
			updategame(event);
			missingTime -= 0.0334;
		}
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
		if (online)
		{
		var i = 0;
		
		var PL = new Array<Player>();
		var A = Players.iterator();
		var ok = false;
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
			if (S == "")
			{
				S = E.playername + ": " + E.score;
			}
			else
			{
				S = S + "\n" + E.playername + ": " + E.score;
			}
			i++;
		}
		
		
		}
		else
		{
			CombinedScore = (myplayer.score - myplayer.spentscore);
			CombinedScoreALL = myplayer.score;
			S = myplayer.playername + ": " + myplayer.score + "\nHighscore: " + HighScore;
		}
		if (messages.length > 0)
		{
			SC.scaleX = 1.5;
			SC.scaleY = 1.5;
			messagetime--;
			S = messages[0];
			var i = 1;
			while (i < 6 && i < messages.length)
			{
				S = S + "\n" + messages[i];
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
		scoreboard.width = scoreboard.textWidth+4;
		scoreboard.height = scoreboard.textHeight + 4;
		SC.graphics.clear();
		if (messages.length > 0)
		{
		SC.graphics.beginFill(0xFFFFFF, 0.7);
		SC.graphics.drawRect(0, 0, scoreboard.width+6, scoreboard.height+6);
		SC.graphics.endFill();
		SC.graphics.beginFill(0x000044, 0.8);
		SC.graphics.drawRect(3, 3, scoreboard.width, scoreboard.height);
		SC.graphics.endFill();
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
				D.Hsp = myplayer.Hspeed;
				D.Vsp = myplayer.Vspeed;
				D.x = myplayer.x;
				D.y = myplayer.y;
				//D.visible = myplayer.visible;
				D.con = myplayer.controller;
				//if (frame % F == 0)
				if (frame % 45 == 0)
				{
					D.ID = myplayer.UID;
					D.char = myplayer.charname;
					D.name = this.playername;
					D.score = myplayer.score;
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
			NP.SendData("Upd", D);
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
		ltime = currentTime;
	}
	public function SendStatus() {
		var D:Dynamic = { };
					D.level = level;
					D.totalenemies = (activeEnemies.length + SpawnList.length);
					D.activeEnemies = (activeEnemies.length);
					D.HP = powblock.HP;
					D.activeItems = activeItems.length;
					D.RoundType = RoundType.getIndex();
					D.GameFlags = GameFlags.data;
					D.sessionID = sessionID;
					SendEvent("Status", D);
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
	private function updategame (event:Event):Void {
		if (missingTime < 0.01)
		{
			return;
		}
		if (Background.alpha < 1)
		{
			Background.alpha += 0.03;
		}
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
			totalenemies = (SpawnList.length);
			totalenemies += getenemycount();
			SpawnTimer -= 1;
			if (activeEnemies.length < 1 && spawns>0)
			{
				SpawnTimer -= 2;
			}
			if (totalenemies == 1 && Hoster)
			{
				if (activeEnemies.length > 0 && !activeEnemies[0].enraged && activeEnemies[0].needtokill)
				{
					SendEvent("Enrage", activeEnemies[0].UID);
				}
			}
			if (!spawnedChar && CombinedScore > PointsToLife >> 1)
			{
				if (totalenemies > 0)
				{
					if (totalenemies == 1 && activeEnemies.length == 1 && activeEnemies[0].killed)
					{
						//if last enemy is dying then dont spawn char yet
					}
					else
					{
						var enemy = new Imposter();
						enemy.UID = 0;
						SpawnList.add(enemy);
						spawnedChar = true;
					}
				}
			}
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
				D.type = "1up";
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
				spawnedChar = false;
				SendEvent("SpawnItem", D);
				CombinedScore -= PointsToLife;
			}
		}
		if (Sealed > 0)
		{
			Sealed--;
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
					var D:Dynamic = E;
					RemoveEnemy(E);
					if (Hoster)
					{
						totalenemies = (SpawnList.length);
						totalenemies += getenemycount();
					}
					else if (D.needtokill)
					{
						totalenemies--;
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
				
				if (E.type == "Enemy")
				{
					if (!E.killed)
					{
						if (Hoster)
						{
							var D:Dynamic = E;
							var EE:Enemy = D;
							SpawnList.add(EE);
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
								D.type = EE.rewarditem;
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
							D.y = -100;
							SendEvent("SpawnItem", D);
						}
					}
					
				}
			}
			i += 1;
		}
		var i = 0;
		if (MSE)
		{
			if (stage.mouseY < 600)
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
			else
			{
				if (Dpad.y + 384 < stage.mouseY)
				{
					Dpad.y = stage.mouseY - 383;
				}
				if (Dpad.y > stage.mouseY)
				{
					Dpad.y = stage.mouseY-1;
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
			//chances per minute(avg)
			if (totalenemies > 0)
			{
			var R = ept;
			if (spawns > (maxspawns + (maxspawns)))
			{
				R = rept;
			}
			if (Sealed<1 && R>0 && frame & 2 > 0 && Math.random()<R)
			{
				//var evt = Math.random();
				var E = "";
				if (Obstacles.length > 0)
				{
					E = Obstacles[Math.floor(Obstacles.length * Math.random())];
				}
				
				if (true && Math.random() > 0.5)
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
				}
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
				else if (ufos<8 && E == "UFO")
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
					D.y = -100;
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
				else if (E == "GiantSuika" && thegiant != null && !thegiant.active)
				{
					SendEvent("GiantSuikaAttack", null);
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
				else if (E == "Yuuka" && !yuukaactive)
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
				else if (E == "MiniPowBlock" && !minipowactive && minipowspawns < maxminipowspawns)
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
				}
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
			}
			}
			//replace start music and spawning with events that trigger it instead.
		if (SpawnTimer <= 0)
		{
			if (SpawnList.length > 1)
			{
				ResetSpawnTimer();
			}
			
			if (!SpawnList.isEmpty())
			{
				var E = SpawnList.pop();
				var data:Dynamic = { };
				data.UID = E.UID;
				if (data.UID == 0)
				{
					//if blank enemy(made in spawnlist) then populate id info
					data.UID = Math.random();
				}
				if (Math.random() > 0.5)
				{
					data.x = 800;
					data.Ldir = -1;
				}
				else
				{
					data.x = -16;
					data.Ldir = 1;
				}
				data.y = -100;
				data.alive = true;
				data.Hspeed = 0;
				data.Vspeed = 0;
				data.visible = true;
				data.enraged = E.enraged;
				data.type = E.charname;
				data.rank = E.rank;
				data.spawns = E.spawns;
				SendEvent("SpawnEnemy", data);
			}
			else
			{
				if (getenemycount() < 1)
				{
					ResetSpawnTimer();
					SpawnTimer = SpawnTimer >> 1;
				level += 1;
				var tmp = 0;
				if (Hoster)
				{
					//if (level % 5 == 1)
					if (RoundType != TypeofRound.Normal/* && successstreak>0*/)
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
				spawnedChar = false;
				SendEvent("SpawnItem", D);
				
					}
				}
				CalculateLevelData();
				var data:Dynamic = { };
				data.level = level;
				data.RoundType = RoundType.getIndex();
				if (level > 1 && roundstarted)
				{
					SendEvent("NextLevel", data);
				}
				if (RoundType == TypeofRound.Table && Hoster)
				{
					ProcessEvent("Spawntables", "Myself", null);
					//SendEvent("Spawntables", null);
				}
				if (RoundType == TypeofRound.NoWrap && Hoster)
				{
					ProcessEvent("NoWrap", "Myself", null);
					//SendEvent("Spawntables", null);
				}
				
				totalenemies = (SpawnList.length);
				totalenemies += getenemycount();
				
				SendEvent("TotalEnemies", totalenemies);
				}
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
	private function CalculateLevelData()
	{
		var L = level - 1;
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
		epm = 0;
		var R = 0.2 + (Math.random() * 0.2);
		R = R * points;
		var AR = R;
		var tmp = 0.7;
		while (AR > 1)
		{
			spawnrate *= 0.96;
			//spawnrate *= 0.965;
			tmp *= 1.4;
			if (tmp < 1)
			{
				tmp = 1;
			}
			AR -= tmp;
		}
		points -= R;
		//calculate percentage of budget will be spent on events(a.k.a. obstacles).
		R = 0.5 + (Math.random() * 0.2);//; (points * 0.7);
		R = R * points;
		AR = R;
		while (AR > 1)
		{
			epm++;
			tmp = (epm * 0.2);
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
			P++;
		}
		var EVT = Math.random();
		if (level == 9)
		{
			//double chance of event
			//EVT *= 0.25;
			EVT *= 0.1;
		}
		RoundType = TypeofRound.Normal;
		var enemytypes:Array<Enemy> = new Array<Enemy>();
		maxspawns = Math.ceil(points) + (P) + 1;
		
		Obstacles = new Array<String>();
		var T = level % 5;
		if (T == 0/* && successstreak > 2*/)
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
				E[E.length] = TypeofRound.Rumia;
				E[E.length] = TypeofRound.Table;
				E[E.length] = TypeofRound.Cirno;
				E[E.length] = TypeofRound.Balloon;
				E[E.length] = TypeofRound.Characters;
				if (level >= 11 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.Nue;
				}
				if (level > 5 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.Seija;
				}
				if (level > 15 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.FireCirno;
					E[E.length] = TypeofRound.NoWrap;
				}
				if (level > 20 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.Yukari;
				}
				if (level > 50 || GameFlags.get(Main.EventRoundsOnly))
				{
					E[E.length] = TypeofRound.ElectricCirno;
				}
			}
			else
			{
				E[E.length] = TypeofRound.Cirno;
			}
			RoundType = E[(Math.floor(Math.random() * E.length))];
			
		}
		
		
		
		var Ev:Array<TypeofRound> = new Array<TypeofRound>();
		if (GameFlags.get(Main.TableEvent))
		{
			Ev[Ev.length] = TypeofRound.Table;
		}
		if (GameFlags.get(Main.CirnoEvent))
		{
			Ev[Ev.length] = TypeofRound.Cirno;
		}
		if (GameFlags.get(Main.FireCirno))
		{
			Ev[Ev.length] = TypeofRound.FireCirno;
		}
		if (GameFlags.get(Main.ElectricCirno))
		{
			Ev[Ev.length] = TypeofRound.ElectricCirno;
		}
		if (GameFlags.get(Main.NueEvent))
		{
			Ev[Ev.length] = TypeofRound.Nue;
		}
		if (GameFlags.get(Main.BalloonEvent))
		{
			Ev[Ev.length] = TypeofRound.Balloon;
		}
		if (GameFlags.get(Main.YukariEvent))
		{
			Ev[Ev.length] = TypeofRound.Yukari;
		}
		if (Ev.length > 0)
		{
			RoundType = Ev[Math.floor(Math.random() * Ev.length)];
		}
		if (RoundType == TypeofRound.Normal || RoundType == TypeofRound.Rumia || RoundType == TypeofRound.Table || RoundType == TypeofRound.Balloon || RoundType == TypeofRound.Characters || RoundType == TypeofRound.NoWrap)
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
		if (RoundType == TypeofRound.Nue)
		{
			Obstacles[Obstacles.length] = "UFO";
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
		}
		if (RoundType == TypeofRound.Yukari)
		{
			Obstacles[Obstacles.length] = "Gap";
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
		}
		if (RoundType == TypeofRound.Balloon)
		{
			AddToArrayMultiple(Obstacles, "Balloon", Math.round(Obstacles.length * 2));
			epm *= 2.5;
		}
		if (RoundType == TypeofRound.Cirno || RoundType == TypeofRound.FireCirno || RoundType == TypeofRound.ElectricCirno)
		{
			AddToArrayMultiple(Obstacles, "Cirno", 8);
			if (RoundType == TypeofRound.Cirno)
			{
				AddToArrayMultiple(Obstacles, "GiantSuika", 1);
			}
			AddToArrayMultiple(enemytypes, new Imposter(), 1);
			if (RoundType == TypeofRound.FireCirno/* || RoundType == TypeofRound.ElectricCirno*/)
			{
				epm += 7;
			}
			else
			{
				epm += 2;
			}
			SpawnTimer = 120 + (maxspawns * 15);
			if (GameFlags.get(Main.EventRoundsOnly))
			{
			if (GameFlags.get(Main.CirnoEvent))
			{
				maxspawns += 9;
			}
			else
			{
				if (!(RoundType == TypeofRound.FireCirno || RoundType == TypeofRound.ElectricCirno))
				{
					maxspawns = 9;
				}
			}
			}
			SendEvent("FreezeWorld", null);
		}
		
		if (RoundType == TypeofRound.Rumia)
			{
				AddToArrayMultiple(enemytypes, new Rumia(), 100);
				AddToArrayMultiple(enemytypes, new Imposter(), 2);
			}
			if (RoundType == TypeofRound.Seija)
			{
				AddToArrayMultiple(enemytypes, new Seija(), 50);
				AddToArrayMultiple(enemytypes, new Imposter(), 2);
			}
		if (RoundType == TypeofRound.Normal || RoundType == TypeofRound.Rumia || RoundType == TypeofRound.Seija || RoundType == TypeofRound.Nue || RoundType == TypeofRound.Table || RoundType == TypeofRound.FireCirno || RoundType == TypeofRound.Balloon || RoundType == TypeofRound.ElectricCirno)
		{
			AddToArrayMultiple(enemytypes, new RedFairy(), 48);
			if (level > 3)
			{
				AddToArrayMultiple(enemytypes, new Keine(), 16);
			}
			if (level > 5)
			{
				AddToArrayMultiple(enemytypes, new Meiling(), 5);
			}
			if (level > 15)
			{
				AddToArrayMultiple(enemytypes, new Utsuho(), 3);
			}
			AddToArrayMultiple(enemytypes, new Mystia(), 28);
			if (level > 25)
			{
				AddToArrayMultiple(enemytypes, new Tewi(), 30);
				AddToArrayMultiple(enemytypes, new Reisen(), 10);
				AddToArrayMultiple(enemytypes, new Imposter(), 1);
			}
			if (level > 35)
			{
				AddToArrayMultiple(enemytypes, new Scarlet(), 2);
			}
			if (level > 45)
			{
				AddToArrayMultiple(enemytypes, new Satori(), 2);
			}
			if (level > 50)
			{
				AddToArrayMultiple(enemytypes, new Kogasa(), 1);
			}
		}
		if (RoundType == TypeofRound.Nue)
		{
			AddToArrayMultiple(enemytypes, new Nue(), 50);
			AddToArrayMultiple(enemytypes, new Imposter(), 2);
			epm *= 0.5;
			maxspawns = Math.ceil(maxspawns * 0.7);
		}
		if (RoundType == TypeofRound.Table)
		{
			epm *= 0.5;
			maxspawns = Math.ceil(maxspawns * 0.7);
		}
		AddToArrayMultiple(enemytypes, new Imposter(), 2);
		if (GameFlags.get(Main.UltraCommonCharacters) || RoundType == TypeofRound.Characters)
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
		
		var tmp = 0;
		while (tmp < maxspawns)
		{
			var enemy = enemytypes[Math.floor(Math.random() * enemytypes.length)];
			enemy.UID = 0;
			SpawnList.add(enemy);
			tmp++;
		}
		
				
		epm += epmmodifier;
		ept = epm * (onetickperminutechance2);//the times 2 is for equalling "frame & 2>0" out above
		rept = (epm + 3 + (Math.floor(epm) >> 1)) * (onetickperminutechance2);
	}
	
}