package;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Sprite;
import openfl.Assets;
import openfl.geom.Transform;
import openfl.Lib;
import openfl.net.NetConnection;
import openfl.net.Socket;
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
import openfl.ui.Keyboard;
import haxe.Timer;
import openfl.events.MouseEvent;
import openfl.media.Sound;
import openfl.media.SoundChannel;
import openfl.media.SoundTransform;

//import com.sociodox.theminer.TheMiner;
//import flash.system.Security;
//import flash.ui.GameInput;
//import flash.events.
//import openfl.events.JoystickEvent;
//import flash.events.GameInputEvent;
//import nme.events.JoystickEvent;
//import flash.text.Font;

class Main extends Sprite {
	public var frameskip:Bool;
	public var frameskipenabled:Bool = true;
	
	public var game:GameView;
	public var titlescreen:TitleScreenView;
	public var optionscreen:OptionView;
	public var shopscreen:ShopView;
	public static var _this:Main;
	//this gets shared across all parts of the program.
	public var AL:Animationloader;
	//the current player status, used to determine what view to transition to.
	public var status:String;
	//...yeah it should be called CharacterSelectView ... that isn't consistent, i should fix that...
	public var characterselect:CharacterSelectView;
	public var playerspick:String;
	//whether or not if the player is doing multiplayer
	public var online:Bool;
	public var playername:String;
	public var savedata:openfl.net.SharedObject;
	//public var savedata:flash.net.SharedObject;
	//public var walfassavedata:flash.net.SharedObject;
	public var Room:String;
	//activates debug keys and enhanced level info.
	#if debug
	public var DEBUG:Bool = true;
	#else
	public var DEBUG:Bool = false;
	#end
	//info displayed in titlescreen
	public var gameversion:String = "2.0.0beta";
	public var controlscheme:Array<UInt>;
	//message shown to player should the host of that session make them leave
	public var statusmessage:String = "";
	public var defaultcontrols:Array<UInt> = [Keyboard.UP, Keyboard.DOWN, Keyboard.LEFT, Keyboard.RIGHT, Keyboard.SPACE, Keyboard.ENTER];
	
	public var lastsession:Dynamic;
	public var session:Dynamic;
	
	public var roomprefix:String = "main";
	public var cheating:Bool;
	
	public var gamemode:GameMode;
	
	public var level:Int = 1;
	
	public var customroom:Bool = false;
	
	public var netlobby:NetPlay = null;
	
	public var ltime:Float;
	
	public var missingTime:Float;
	
	//time spent as host.
	public var hosttime:Int = 0;
	//time spent as client.
	public var clienttime:Int = 0;
	
	/*public var level:Int=1;
	public var levelselect:Bool;
	public var levelincrement:Int = 1;
	public var cancontinue:Bool = true;
	public var canselectcharacter:Bool = true;
	public var canlivesspawn:Bool = true;
	public var canmyonspawn:Bool = true;
	public var abilitiesenabled:Bool = true;*/
	
	//cheatcodes&gamemode flags
	
	public static inline var FireCirno = 1;
	//extra lives
	public static inline var KonamiCode = 2;
	//play as prinny
	public static inline var Prinny = 3;
	//causes normal mode music to play during easy mode, and vice versa.
	public static inline var AltMusic = 4;
	public static inline var TableEvent = 5;
	//play as pikemarisa
	public static inline var Pikachu = 6;
	//public static inline var Mima = 7;(mima was originally planned to be an event character)
	
	public static inline var NormalMode = 8;
	public static inline var HardMode = 9;
	public static inline var LunaticMode = 10;
	public static inline var ExtraMode = 11;
	public static inline var CirnoEvent = 12;
	//forces every level to be an event
	public static inline var EventRoundsOnly = 13;
	public static inline var UltraCommonCharacters = 14;
	public static inline var NueEvent = 15;
	public static inline var BalloonEvent = 16;
	public static inline var YukariEvent = 17;
	public static inline var UnlockAllCharacters = 18;
	public static inline var RelockAllCharacters = 19;
	public static inline var ElectricCirno = 20;
	//something silly that changes step sound effects
	public static inline var Drumstep = 21;
	//boss events only
	public static inline var Bossrush = 22;
	//forces danmaku event
	public static inline var Danmaku = 23;
	//forces a truck to spawn each level the truck does not despawn, and enemies will not spawn until you pick it up,if kaguya/mokou take the truck offscreen it results in a game over.
	public static inline var TruckHoarder = 24;
	//prevents events
	public static inline var NoEvents = 25;
	public static inline var UnlockAllChallenges = 26;
	//activates the life system used in all star mode.
	public static inline var AllStar = 27;
	public static inline var SanaeBoss = 28;
	public static inline var UnlockAllOutfits = 29;
	public static inline var LavaEvent = 30;
	//replaces normal levels with sidescrolling ones, also adds the powerup ability(required for powerup items to work) to all characters.
	public static inline var Adventure = 31;
	public static inline var ParseeEvent = 32;
	public static inline var Explosive = 33;
	public static inline var PointCollecting = 34;
	//cheatcodes are stored as md5 hashcodes, so cheatcodes cannot be obtained via hacking, you can press f9 in the character select to convert your player name to an md5 hash requires in game debug mode (Main.DEBUG=true)
	//75efc70c0e990c49b8ee4fbdaca89dae = firecirno
	//6718c4714daa73a63e1e4ea54757449c = upupdowndownleftrightleftrightbastart
	//9e6122001ea0464018c634c285233853 = prinnydood
	//7d51b214e0069ac6361aaaf2034279a6 = sideb
	//2b59c79dfe67f2a5d0f17c646ae894ed = table flipping  -old: 42a9af4784dd07a127e63a9092ab7e1c = walfasstationwagon
	//fa55036379520473353e15548f2a388e = lovecoloredpikachuun
	//69034dbf1b3882954b3a9b8bf9686d1c = mimaconfirmed
	//c16404177908ade1a1f1b0e3f8835ec9 = normalmode
	//6170e8e40fdf20f6fbeefd88815a2086 = hardmode
	//525afc6a26124022359a9ad101e71e99 = lunaticmode
	//5aed71982de151ff05492c9babb533ea = extramode
	//45c48cce2e2d7fbdea1afc51c7c6ad26 = 9
	//1c0108249de204153f4e296913fcacea = averageday
	//09e1ca57cc1c4e73bd7fc9f5642883db = 2husonparade
	//f9df7933994ea2e532cc30a842d36766 = unidentifiedflyingobstruction
	//151115624f4a47252d316c30d1ccbced = balloonsballoonseverywhere
	//4b54a629dbc0c68ab8312740ae3d1e84 = necroflantasia
	//b32092f7b9e04c12abb373a257ba16fe = suddenlyitscrowdedinhere...
	//fda28399f82b488a33807573a2d670c5 = lookatdemtumbleweeds...
	//1b9b7d20ce44ad2f880f677deefd711b = shockingisntit
	//0c22948e07710faa0ad65b83053d77e0 = drumstep
	//0f6a8fa3f3985858ebc1debc5ce61f7e = /bossrush
	//c022be00cb710d03d98d67fb6cbf6d7a = /danmaku
	//42fa0e8cfd0cb2102c7d23ebd7ada199 = /truckhoarder
	//2f4581b3456a9c99e51b0237fe9bde0a = teatime
	//5e19e32cb6c2a71bec4fed4135f2785f = spell card rules what are those?
	//1a723cfc8a28af39a97b5c0f497e52c4 = /allstar
	//b330c71bd2c3ca1f4c6ecea06838ce2f = theticketsarenowriceballs
	//0d32665af25beb996ee1c2b6b33f4d74 = thegap
	//1dceddadb5d8f6174e0a829cdeb56b35 = hellisfloodingagain
	//e77933862aef3c8fd9a60cffde17344e = /adventure
	//c357bef743f927a4baa4806f19868c8f = parseebros
	//170fa0be197479f2e10280f483300cca = /explosive
	//7a16c4a81660276b789cd58d6666315f = /pointcollection
	public static var codes:Array<String> = ["75efc70c0e990c49b8ee4fbdaca89dae", "6718c4714daa73a63e1e4ea54757449c", "9e6122001ea0464018c634c285233853", "7d51b214e0069ac6361aaaf2034279a6", "2b59c79dfe67f2a5d0f17c646ae894ed", "fa55036379520473353e15548f2a388e", "69034dbf1b3882954b3a9b8bf9686d1c","c16404177908ade1a1f1b0e3f8835ec9","6170e8e40fdf20f6fbeefd88815a2086","525afc6a26124022359a9ad101e71e99","5aed71982de151ff05492c9babb533ea","45c48cce2e2d7fbdea1afc51c7c6ad26","1c0108249de204153f4e296913fcacea","09e1ca57cc1c4e73bd7fc9f5642883db","f9df7933994ea2e532cc30a842d36766","151115624f4a47252d316c30d1ccbced","4b54a629dbc0c68ab8312740ae3d1e84","b32092f7b9e04c12abb373a257ba16fe","fda28399f82b488a33807573a2d670c5","1b9b7d20ce44ad2f880f677deefd711b","0c22948e07710faa0ad65b83053d77e0","0f6a8fa3f3985858ebc1debc5ce61f7e","c022be00cb710d03d98d67fb6cbf6d7a","42fa0e8cfd0cb2102c7d23ebd7ada199","2f4581b3456a9c99e51b0237fe9bde0a","5e19e32cb6c2a71bec4fed4135f2785f","1a723cfc8a28af39a97b5c0f497e52c4","b330c71bd2c3ca1f4c6ecea06838ce2f","0d32665af25beb996ee1c2b6b33f4d74","1dceddadb5d8f6174e0a829cdeb56b35","e77933862aef3c8fd9a60cffde17344e","c357bef743f927a4baa4806f19868c8f","170fa0be197479f2e10280f483300cca","7a16c4a81660276b789cd58d6666315f"];
	public var GameFlags:FlagManager;
	public var CheatFlags:FlagManager;
	public function new () {
		super ();
		AL = new Animationloader();
		new SoundManager();
		init();
		stage.addEventListener (Event.ENTER_FRAME, this_onEnterFrame);
		stage.addEventListener (KeyboardEvent.KEY_UP, stage_onKeyUp);
		stage.addEventListener (KeyboardEvent.KEY_DOWN, stage_onKeyDown);
		stage.addEventListener (Event.DEACTIVATE, stage_deactivate);
		
	}
	public function init()
	{
		ltime = Timer.stamp ();
		if (DEBUG)
		{
			//Haxe doesn't support this external files easily.
			//stage.addChild(new TheMiner());  
		}
		stage.quality = flash.display.StageQuality.LOW;
		//stage.quality = flash.display.StageQuality.LOW;
		//stage.quality = flash.display.StageQuality.MEDIUM;
		
		_this = this;
		optionscreen = null;
		
		online = false;
		
		playerspick = "";
		savedata = openfl.net.SharedObject.getLocal("ReimuBrosData", "/", false);
		flash.system.Security.allowDomain('*');
		GameMode.init();
		gamemode = GameMode.GetModeByName("Classic");
		GameFlags = new FlagManager(2);
		CheatFlags = new FlagManager(2);
		var FPS = stage.frameRate;
		playername = savedata.data.playername;
		if (playername == null)
		{
			playername = "PlayerName";
		}
		if (savedata.data.soundvolume == null)
		{
			savedata.data.soundvolume = 1.0;
		}
		if (savedata.data.musicvolume == null)
		{
			savedata.data.musicvolume = 0.7;
		}
		if (savedata.data.maxlevel == null)
		{
			savedata.data.maxlevel = 1;
		}
		if (savedata.data.challenges == null)
		{
			savedata.data.challenges = new Array<Bool>();
		}
		if (savedata.data.avatar == null)
		{
			//savedata.data.avatar = "";
			savedata.data.avatar = "3.39:PlayerName:100:0:-1:-1:-1:-1:0:0:0:0:0:321A00";
		}
		if (savedata.data.avatarabilities == null)
		{
			//savedata.data.avatar = "";
			savedata.data.avatarabilities = false;
		}
		if (savedata.data.unlockables_body == null)
		{
			savedata.data.unlockables_body = new Array<Bool>();
		}
		if (savedata.data.unlockables_hair == null)
		{
			savedata.data.unlockables_hair = new Array<Bool>();
		}
		if (savedata.data.unlockables_arms == null)
		{
			savedata.data.unlockables_arms = new Array<Bool>();
		}
		if (savedata.data.unlockables_shoes == null)
		{
			//shoes will be just a single unlockable since they are not very interesting
			savedata.data.unlockables_shoes = false;
		}
		if (savedata.data.unlockables_haircolor == null)
		{
			savedata.data.unlockables_haircolor = false;
		}
		if (savedata.data.unlockables_hat == null)
		{
			savedata.data.unlockables_hat = new Array<Bool>();
			savedata.data.unlockables_hat[0] = true;
		}
		if (savedata.data.unlockables_eyes == null)
		{
			savedata.data.unlockables_eyes = new Array<Bool>();
			savedata.data.unlockables_eyes[0] = true;
		}
		if (savedata.data.unlockables_mouth == null)
		{
			savedata.data.unlockables_mouth = new Array<Bool>();
			savedata.data.unlockables_mouth[0] = true;
		}
		if (savedata.data.unlockables_accessory == null)
		{
			savedata.data.unlockables_accessory = new Array<Bool>();
			savedata.data.unlockables_accessory[0] = true;
		}
		if (savedata.data.unlockables_back == null)
		{
			savedata.data.unlockables_back = new Array<Bool>();
			savedata.data.unlockables_back[0] = true;
		}
		if (savedata.data.shop_hair == null)
		{
			savedata.data.shop_hair = new Array<Int>();
		}
		if (savedata.data.shop_body == null)
		{
			savedata.data.shop_body = new Array<Int>();
		}
		if (savedata.data.shop_arms == null)
		{
			savedata.data.shop_arms = new Array<Int>();
		}
		if (savedata.data.shop_hats == null)
		{
			savedata.data.shop_hats = new Array<Int>();
		}
		if (savedata.data.shop_eyes == null)
		{
			savedata.data.shop_eyes = new Array<Int>();
		}
		if (savedata.data.shop_mouth == null)
		{
			savedata.data.shop_mouth = new Array<Int>();
		}
		if (savedata.data.shop_accessory == null)
		{
			savedata.data.shop_accessory = new Array<Int>();
		}
		if (savedata.data.shop_back == null)
		{
			savedata.data.shop_back = new Array<Int>();
		}
		if (savedata.data.shop_ticks == null)
		{
			savedata.data.shop_ticks = 5;
		}
		if (savedata.data.shop_inventory == null)
		{
			savedata.data.shop_inventory = new Array<Dynamic>();
		}
		if (savedata.data.money == null)
		{
			savedata.data.money = 0;
		}
		//savedata.data.avatar = "3.39:RSGmaker:100:0:192:324:232:24:0:0:0:1:0:321A00";
		if (savedata.data.avatarability == null)
		{
			savedata.data.avatarability = "none";
		}
		
		if (savedata.data.controlscheme == null)
		{
			controlscheme = new Array<UInt>();
			/*controlscheme[0] = Keyboard.UP;
			controlscheme[1] = Keyboard.DOWN;
			controlscheme[2] = Keyboard.LEFT;
			controlscheme[3] = Keyboard.RIGHT;
			controlscheme[4] = Keyboard.SPACE;
			controlscheme[5] = Keyboard.ENTER;
			savedata.data.controlscheme = controlscheme;*/
		}
		else
		{
			controlscheme = savedata.data.controlscheme;
			
		}
		var i = 0;
		var fix = false;
		while (i < defaultcontrols.length)
		{
			if (controlscheme[i] == 0)
			{
				controlscheme[i] = defaultcontrols[i];
				fix = true;
			}
			i++;
		}
		if (fix)
		{
			savedata.data.controlscheme = controlscheme;
		}
		//savedata.data.controlscheme = null;
		SoundManager._this.SetSoundVolume(savedata.data.soundvolume);
		SoundManager._this.SetMusicVolume(savedata.data.musicvolume);
		//initialize the character unlock data
		if (savedata.data.unlock == null)
		{
			var O = new Array<Bool>();
			var i = 0;
			while (i < Player.characters.length)
			{
				//initiallize the character unlock data as locked except for characters 0 & 1 (reimu and marisa)
				O[i] = (i < 2);
				i++;
			}
			savedata.data.unlock = O;
		}
		//initialize alternate costume unlock data
		if (savedata.data.alts == null)
		{
			var O = new Array<Bool>();
			var i = 0;
			while (i < Player.characters.length)
			{
				O[i] = false;
				i++;
			}
			savedata.data.alts = O;
		}
		if (savedata.data.highscore == null)
		{
			savedata.data.highscore = 0;
		}
		Room = "public1";
		showtitlescreen();
	}
	private function create_unlockedarray(length:Int = 1000, value:Bool=true)
	{
		var ret = new Array<Bool>();
		var i = 0;
		while (i < length)
		{
			ret.push(value);
			i++;
		}
		return ret;
	}
	private function stage_deactivate(event:Event):Void
	{
		if (game != null)
		{
			game.LoseFocus();
		}
	}
	public function resetgamesettings()
	{
		GameFlags.clearall();
		playerspick = savedata.data.characterselected;
		/*canmyonspawn = true;
		abilitiesenabled = true;
		canlivesspawn = true;*/
		GameView.levelsperstage = 5;
		GameView.levelsperrank = GameView.levelsperstage * GameView.stagesperrank;
	}
	//do special key functions, and pass on key info to active view.
	private function stage_onKeyUp (event:KeyboardEvent):Void {
		
		switch (event.keyCode) {
			case Keyboard.M:
				if (characterselect == null && shopscreen == null)
				{
					SoundManager._this.ToggleMute();
				}
			case Keyboard.F9: if (characterselect != null && DEBUG)
			{
				characterselect.Nameinput.text = MD5.hash(characterselect.Nameinput.text);
			}
			/*case Keyboard.Q:
				if (titlescreen != null)
				{
					showtitlescreen();
				}*/
			case Keyboard.LEFTBRACKET:
			{
				if (SoundManager._this.GetMusicVolume() > 0.0)
				{
					SoundManager._this.SetMusicVolume(SoundManager._this.GetMusicVolume() - 0.1);
				}
			}
			case Keyboard.RIGHTBRACKET:
			{
				if (SoundManager._this.GetMusicVolume() < 1.0)
				{
					SoundManager._this.SetMusicVolume(SoundManager._this.GetMusicVolume() + 0.1);
				}
			}
			case Keyboard.MINUS:
			{
				if (SoundManager._this.GetSoundVolume() > 0.0)
				{
					SoundManager._this.SetSoundVolume(SoundManager._this.GetSoundVolume() - 0.1);
				}
			}
			case Keyboard.EQUAL:
			{
				if (SoundManager._this.GetSoundVolume() < 1.0)
				{
					SoundManager._this.SetSoundVolume(SoundManager._this.GetSoundVolume() + 0.1);
				}
			}
		}
		if (game != null)
		{
			game.stage_onKeyUp(event);
		}
		if (optionscreen != null)
		{
			optionscreen.stage_onKeyUp(event);
		}
	}
	private function stage_onKeyDown (event:KeyboardEvent):Void {
		if (game != null && stage.focus == this)
		{
			game.stage_onKeyDown(event);
		}
		if (titlescreen != null)
		{
			if (!titlescreen.menu)
			{
				titlescreen.MSE = true;
				titlescreen.show_menu();
			}
		}
	}
	public function updateflags()
	{
		GameFlags.clearall();
		GameFlags.add(gamemode.GameFlags);
		if (!CheatFlags.isempty())
		{
			cheating = true;
			GameFlags.add(CheatFlags);
		}
		else
		{
			cheating = false;
		}
	}
	public function update(event:Event)
	{
		if (game != null)
		{
			game.this_onEnterFrame(event);
			
			if (online)
			{
				if (customroom && netlobby != null)
				{
					endnetlobby();
				}
				if (game.Hoster)
				{
					hosttime++;
					clienttime = 0;
					if (hosttime > 300 && netlobby == null && !customroom)
					{
						startnetlobby(false);
					}
				}
				else
				{
					clienttime++;
					hosttime = 0;
					if (clienttime > 300 && netlobby != null)
					{
						endnetlobby();
					}
				}
			}
		}
		if (shopscreen != null)
		{
			if (shopscreen.status == "TitleScreen")
			{
				showtitlescreen();
			}
			else
			{
				shopscreen.this_onEnterFrame();
			}
		}
		/*if (frameskipenabled)
		{
			frameskip = !frameskip;
			if (frameskip)
			{
				return;
			}
		}*/
		if (titlescreen != null)
		{
			titlescreen.update();
			if (titlescreen.status != "")
			{
				status = titlescreen.status;
				if (status == "OpenPlay" || status == "SinglePlayer")
				{
					online = false;
					if (status == "OpenPlay")
					{
						online = true;
					}
					//roomprefix = "classicmode";
					updateflags();
					showcharacterselect();
				}
				if (status == "Options")
				{
					showoptions();
				}
				if (status == "Shop")
				{
					showshopscreen();
				}
			}
		}
		else if (characterselect != null)
		{
			characterselect.this_onEnterFrame();
			var S = characterselect.status;
			
			if (netlobby != null && characterselect.frame > 300 && netlobby.group.neighborCount>10)
			{
				endnetlobby();
			}
			if (S == "PlayGame")
			{
				var bannedname = false;
				var code = characterselect.Nameinput.text;
				var C = code;
				if (code.length > 0)
				{
					C = code.toLowerCase().split(" ").join("");
					if (code.charAt(0) == "/")
					{
						bannedname = true;
					}
					if (code == "PlayerName" && online)
					{
						bannedname = true;
					}
				}
				else
				{
					bannedname = true;
				}
				var valid = true;
				var gamecode = -1;
				if (!bannedname)
				{
					
					if (code.length > 0)
					{
						code = C;
						code = MD5.hash(code);
						gamecode = codes.indexOf(code) + 1;
						if (gamecode == UnlockAllCharacters)
						{
							var i = 0;
							while (i < Player.characters.length)
							{
								savedata.data.unlock[i] = true;
								savedata.data.alts[i] = true;
								i++;
							}
							i = 0;
							valid = false;
							//restart character select menu
							showcharacterselect();
						}
						else if (gamecode == RelockAllCharacters)
						{
							var i = 0;
							while (i < Player.characters.length)
							{
								savedata.data.unlock[i] = i < 2;
								savedata.data.alts[i] = false;
								i++;
							}
							i = 0;
							valid = false;
							//restart character select menu
							showcharacterselect();
						}
						else if (gamecode == UnlockAllChallenges)
						{
							var i = 0;
							/*while (i < 4)
							{
								//savedata.data.challenges[i] = true;
								i++;
							}*/
							while (i < GameMode.Modes.length)
							{
								GameMode.Modes[i].setunlocked(true);
								i++;
							}
							i = 0;
							valid = false;
							//restart character select menu
							//showcharacterselect();
							showtitlescreen();
							return;
						}
						else if (gamecode == UnlockAllOutfits)
						{
							savedata.data.unlockables_back = create_unlockedarray();
							savedata.data.unlockables_accessory = create_unlockedarray();
							savedata.data.unlockables_mouth = create_unlockedarray();
							savedata.data.unlockables_eyes = create_unlockedarray();
							savedata.data.unlockables_hat = create_unlockedarray();
							savedata.data.unlockables_shoes = true;
							savedata.data.unlockables_arms = create_unlockedarray();
							savedata.data.unlockables_hair = create_unlockedarray();
							savedata.data.unlockables_body = create_unlockedarray();
							savedata.data.avatarabilities = true;
							savedata.data.unlockables_haircolor = true;
							valid = false;
							showtitlescreen();
							return;
						}
						else
						{
						if (gamecode > 0)
						{
							valid = false;
							characterselect.Nameinput.text = characterselect.playername;
							//GameFlags.set(gamecode, true);
							CheatFlags.set(gamecode, true);
							updateflags();
							//cheating = true;
						}
						}
					}
				}
				customroom = characterselect.custom;
				characterselect.status = "";
				if (valid)
				{
					//if ((online && GameFlags.getactiveflags().length > 0) && !characterselect.custom)
					//if ((online && cheating) && !characterselect.custom)
					if ((online && cheating) && !characterselect.custom)
					{
						//no cheats in multiplayer unless a custom room(custom rooms are checked to see if not a actually a public room)
						valid = false;
					}
					else
					{
						valid = true;
					}
				}
				if (valid && !bannedname)
				{
					playerspick = characterselect.selected;
					if (GameFlags.get(Prinny))
					{
						playerspick = "prinny";
					}
					if (GameFlags.get(Pikachu))
					{
						playerspick = "pika";
					}
					Room = characterselect.Room;
					if (gamemode.forcedcharacter=="")
					{
						savedata.data.characterselected = playerspick;
					}
					level = characterselect.level;
					updateflags();
					showgame();
				}
				else
				{
					if (bannedname)
					{
						characterselect.status = "Error:Name";
					}
					else
					{
						if ((online && !characterselect.custom) && (gamecode < 1))
						{
							characterselect.status = "Error:Cheat";
						}
						else if (gamecode > 0)
						{
							characterselect.status = "Cheat";
						}
					}
				}
			}
			if (S == "TitleScreen")
			{
				showtitlescreen();
			}
		}
		else if (game != null)
		{
			//seems to fix some minor input issues.
			//if (stage.focus != this && (!game.menu || online))
			if (stage.focus != this && !game.paused)
			{
				stage.focus = this;
			}
			
			if (game.status == "quitting")
			{
				showtitlescreen();
			}
			else if (game.status == "kicked")
			{
				statusmessage = "kicked from server.";
				showtitlescreen();
			}
			else if (game.status == "roomfull")
			{
				statusmessage = "room is full.";
				showtitlescreen();
			}
			else if (game.status == "restart")
			{
				showgame();
			}
			else if (game.myplayer != null)
			{
				//if actively playing then lets keep track of their progress so if they rejoin a multiplayer session we can let them resume with their previous stats.
				session = { };
				
				session.level = game.level;
				session.score = game.myplayer.score;
				session.lives = game.myplayer.lives;
				session.online = online;
				//sessionID is used to determine if the multiplayer sessions are the same(so if a player changes rooms they won't resume their stats)
				session.sessionID = game.sessionID;
			}
		}
		else if (optionscreen != null)
		{
			optionscreen.update();
			if (optionscreen.status == "Back")
			{
				showtitlescreen();
			}
			else if (optionscreen.status == "refresh")
			{
				showoptions();
			}
		}
	}
	//check if the view is done interacting with the player, and show the new view eg; character select->main game(aka gameview)
	private function this_onEnterFrame (event:Event):Void {
		var currentTime = Timer.stamp ();
		var T = currentTime - ltime;
		missingTime += T;
		if (missingTime > 3 /* && !online*/)
		{
			missingTime = 0.041;
		}
		if (!(missingTime > 0 || missingTime < 0))
		{
			missingTime = 0;
		}
		var spr:Sprite = null;
		spr = this;
		if (game != null)
		{
			spr = game;
		}
		/*if (characterselect != null)
		{
			spr = characterselect;
		}
		if (titlescreen != null)
		{
			spr = titlescreen;
		}
		if (optionscreen != null)
		{
			spr = optionscreen;
		}
		if (shopscreen != null)
		{
			spr = shopscreen;
		}*/
		ltime = currentTime;
		//visible = false;
		spr.visible = false;
		if (missingTime > 0.0334)
		{
			//updategame(event);
			update(event);
			missingTime -= 0.0334;
		}
		if (missingTime < 0)
		{
			missingTime = 0;
		}
		
		while (missingTime > 0.04)
		{
			update(event);
			missingTime -= 0.0334;
		}
		spr.visible = true;
		//visible = true;
		
	}
	public function changeGameMode(gamemode:GameMode)
	{
		this.gamemode = gamemode;
		updateflags();
	}
	//stops all active views, used to prepare for showing a new one or to restart one.
	private function clear()
	{
		//prepare for new screen.
		///SoundManager.StopAll();
		SoundManager.StopMusic();
		stage.focus = this;
		if (titlescreen != null)
		{
			stage.removeChild(titlescreen);
			titlescreen = null;
		}
		if (game != null)
		{
			game.end();
			stage.removeChild(game);
			GameView._this = null;
			if (session != null && session.online)
			{
				if (session.lives >= 0 && session.level > 1)
				{
					lastsession = session;
				}
				else
				{
					lastsession = null;
				}
				session = null;
			}
			savedata.flush();
			game = null;
		}
		if (characterselect != null)
		{
			stage.removeChild(characterselect);
			var code = characterselect.Nameinput.text;
			if (code.length > 0)
			{
			code = code.toLowerCase().split(" ").join("");
			code = MD5.hash(code);
			if (codes.indexOf(code) + 1 == 0)
			{
				playername = characterselect.Nameinput.text;
				if (playername.length > 25)
				{
					playername = playername.substr(0, 25);
				}
			}
			}
			
			savedata.data.playername = playername;
			Room = characterselect.Room;
			characterselect = null;
		}
		if (optionscreen != null)
		{
			stage.removeChild(optionscreen);
			optionscreen = null;
			savedata.flush();
		}
		if (shopscreen != null)
		{
			stage.removeChild(shopscreen);
			savedata.data.avatar = shopscreen.custompanel.avatardna;
			savedata.data.avatarability = shopscreen.custompanel.soul;
			playername = CharHelper.getdnapart(shopscreen.custompanel.avatardna, 1);
			savedata.data.playername = playername;
			savedata.flush();
			shopscreen = null;
		}
	}
	private function showgame()
	{
		clear();
		game = new GameView();
		game.AL = AL;
		stage.addChild(game);
		game.playerspick = playerspick;
		game.playername = playername;
		game.online = online;
		game.Room = roomprefix + "_" + Room;
		game.GameFlags = GameFlags;
		game.level = level-1;
		game.start();
		
	}
	private function showtitlescreen()
	{
		clear();
		resetsettings();
		if (netlobby != null)
		{
			netlobby.end();
			netlobby = null;
		}
		
		titlescreen = new TitleScreenView();
		titlescreen.AL = AL;
		stage.addChild(titlescreen);
		titlescreen.start();
		status = "titlescreen";
		playerspick = "";
	}
	public function resetsettings()
	{
		GameFlags.clearall();
		CheatFlags.clearall();
		updateflags();
		/*levelselect = true;
		level = 1;
		levelincrement = 1;
		cancontinue = true;
		canselectcharacter = true;
		abilitiesenabled = true;
		canlivesspawn = true;*/
		cheating = false;
	}
	private function showcharacterselect()
	{
		clear();
		characterselect = new CharacterSelectView();
		characterselect.AL = AL;
		stage.addChild(characterselect);
		if (playerspick == "")
		{
			playerspick = savedata.data.characterselected;
		}
		characterselect.playername = savedata.data.playername;
		characterselect.selected = playerspick;
		if (gamemode.forcedcharacter != "")
		{
			characterselect.selected = gamemode.forcedcharacter;
		}
		//characterselect.selected = savedata.data.characterselected;
		characterselect.online = online;
		if (characterselect.selected == null)
		{
			characterselect.selected = "reimu";
		}
		characterselect.start();
		/*if (online)
		{
			netlobby = new NetPlay();
			netlobby.Room = "lobby_"+roomprefix;
			netlobby.start();
			netlobby.SendMessage("ping");
		}*/
		startnetlobby();
	}
	public function endnetlobby()
	{
		if (netlobby != null)
		{
			netlobby.end();
			netlobby = null;
		}
	}
	public function startnetlobby(ping:Bool=true)
	{
		endnetlobby();
		if (online)
		{
			netlobby = new NetPlay();
			netlobby.Room = "lobby_"+roomprefix;
			netlobby.start();
			netlobby.SendMessage("ping");
		}
	}
	private function showshopscreen()
	{
		clear();
		shopscreen = new ShopView();
		var D:String = savedata.data.avatar;
		var S = D.split(":");
		var P:String = ""+savedata.data.playername;
		if (savedata.data.playername == null)
		{
			P = "PlayerName";
		}
		S[1] = "" + P;
		D = S.join(":");
		
		shopscreen.custompanel.avatardna = D;
		//shopscreen.custompanel.avatardna = savedata.data.avatar;
		shopscreen.custompanel.soul = savedata.data.avatarability;
		stage.addChild(shopscreen);
		shopscreen.start();
	}
	
	private function showoptions()
	{
		clear();
		optionscreen = new OptionView();
		optionscreen.AL = AL;
		stage.addChild(optionscreen);
	}
	
}