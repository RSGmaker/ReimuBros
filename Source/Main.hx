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
//import flash.system.Security;
//import flash.ui.GameInput;
//import flash.events.
//import openfl.events.JoystickEvent;
//import flash.events.GameInputEvent;
//import nme.events.JoystickEvent;
//import flash.text.Font;

class Main extends Sprite {
	public var game:GameView;
	public var titlescreen:TitleScreenView;
	public var optionscreen:OptionView;
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
	public var DEBUG:Bool = true;
	//info displayed in titlescreen
	public var gameversion:String = "1.6.0";
	public var controlscheme:Array<UInt>;
	//message shown to player should the host of that session make them leave
	public var statusmessage:String = "";
	
	public var lastsession:Dynamic;
	public var session:Dynamic;
	//cheatcode flags
	public static inline var FireCirno = 1;
	public static inline var KonamiCode = 2;
	public static inline var Prinny = 3;
	public static inline var AltMusic = 4;
	public static inline var TableEvent = 5;
	public static inline var Pikachu = 6;
	//public static inline var Mima = 7;(mima was originally planned to be an event character)
	public static inline var NormalMode = 8;
	public static inline var HardMode = 9;
	public static inline var LunaticMode = 10;
	public static inline var ExtraMode = 11;
	public static inline var CirnoEvent = 12;
	public static inline var EventRoundsOnly = 13;
	public static inline var UltraCommonCharacters = 14;
	public static inline var NueEvent = 15;
	public static inline var BalloonEvent = 16;
	public static inline var YukariEvent = 17;
	public static inline var UnlockAllCharacters = 18;
	public static inline var RelockAllCharacters = 19;
	public static inline var ElectricCirno = 20;
	public static inline var Drumstep = 21;
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
	public static var codes:Array<String> = ["75efc70c0e990c49b8ee4fbdaca89dae", "6718c4714daa73a63e1e4ea54757449c", "9e6122001ea0464018c634c285233853", "7d51b214e0069ac6361aaaf2034279a6", "2b59c79dfe67f2a5d0f17c646ae894ed", "fa55036379520473353e15548f2a388e", "69034dbf1b3882954b3a9b8bf9686d1c","c16404177908ade1a1f1b0e3f8835ec9","6170e8e40fdf20f6fbeefd88815a2086","525afc6a26124022359a9ad101e71e99","5aed71982de151ff05492c9babb533ea","45c48cce2e2d7fbdea1afc51c7c6ad26","1c0108249de204153f4e296913fcacea","09e1ca57cc1c4e73bd7fc9f5642883db","f9df7933994ea2e532cc30a842d36766","151115624f4a47252d316c30d1ccbced","4b54a629dbc0c68ab8312740ae3d1e84","b32092f7b9e04c12abb373a257ba16fe","fda28399f82b488a33807573a2d670c5","1b9b7d20ce44ad2f880f677deefd711b","0c22948e07710faa0ad65b83053d77e0"];
	public var GameFlags:FlagManager;
	public function new () {
		super ();
		stage.quality = flash.display.StageQuality.LOW;
		AL = new Animationloader();
		_this = this;
		optionscreen = null;
		new SoundManager();
		online = false;
		playerspick = "";
		savedata = openfl.net.SharedObject.getLocal("ReimuBrosData", "/", false);
		flash.system.Security.allowDomain('*');
		GameFlags = new FlagManager(2);
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
			savedata.data.musicvolume = 1.0;
		}
		if (savedata.data.controlscheme == null)
		{
			controlscheme = new Array<UInt>();
			controlscheme[0] = Keyboard.UP;
			controlscheme[1] = Keyboard.DOWN;
			controlscheme[2] = Keyboard.LEFT;
			controlscheme[3] = Keyboard.RIGHT;
			controlscheme[4] = Keyboard.SPACE;
			controlscheme[5] = Keyboard.ENTER;
			savedata.data.controlscheme = controlscheme;
		}
		else
		{
			controlscheme = savedata.data.controlscheme;
		}
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
		stage.addEventListener (Event.ENTER_FRAME, this_onEnterFrame);
		stage.addEventListener (KeyboardEvent.KEY_UP, stage_onKeyUp);
		stage.addEventListener (KeyboardEvent.KEY_DOWN, stage_onKeyDown);
		showtitlescreen();
	}
	//do special key functions, and pass on key info to active view.
	private function stage_onKeyUp (event:KeyboardEvent):Void {
		
		switch (event.keyCode) {
			case Keyboard.M:
				if (characterselect == null)
				{
					SoundManager._this.ToggleMute();
				}
			case Keyboard.F9: if (characterselect != null && DEBUG)
			{
				characterselect.Nameinput.text = MD5.hash(characterselect.Nameinput.text);
			}
			case Keyboard.Q:
				if (titlescreen != null)
				{
					showtitlescreen();
				}
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
		if (game != null)
		{
			game.stage_onKeyDown(event);
		}
	}
	//check if the view is done interacting with the player, and show the new view eg; character select->main game(aka gameview)
	private function this_onEnterFrame (event:Event):Void {
		
		if (titlescreen != null)
		{
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
					showcharacterselect();
				}
				if (status == "Options")
				{
					showoptions();
				}
			}
		}
		else if (characterselect != null)
		{
			characterselect.this_onEnterFrame();
			var S = characterselect.status;
			if (S == "PlayGame")
			{
				var code = characterselect.Nameinput.text;
				var valid = true;
				{
					
					if (code.length > 0)
					{
						code = code.toLowerCase().split(" ").join("");
						code = MD5.hash(code);
						var gamecode = codes.indexOf(code) + 1;
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
						else
						{
						if (gamecode > 0)
						{
							valid = false;
							characterselect.Nameinput.text = characterselect.playername;
							GameFlags.set(gamecode, true);
						}
						}
					}
				}
				characterselect.status = "";
				if (valid)
				{
					if ((online && GameFlags.getactiveflags().length > 0) && !characterselect.custom)
					{
						//no cheats in multiplayer unless a custom room(custom rooms are checked to see if not a actually a public room)
						valid = false;
					}
					else
					{
						valid = true;
					}
				}
				if (valid)
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
					savedata.data.characterselected = playerspick;
					showgame();
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
			stage.focus = this;
			
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
	//stops all active views, used to prepare for showing a new one or to restart one.
	private function clear()
	{
		//prepare for new screen.
		SoundManager.StopAll();
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
			if (session != null)
			{
				if (session.lives >= 0)
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
		game.Room = Room;
		game.GameFlags = GameFlags;
		game.start();
	}
	private function showtitlescreen()
	{
		clear();
		titlescreen = new TitleScreenView();
		titlescreen.AL = AL;
		stage.addChild(titlescreen);
		titlescreen.start();
		status = "titlescreen";
	}
	private function showcharacterselect()
	{
		clear();
		characterselect = new CharacterSelectView();
		characterselect.AL = AL;
		stage.addChild(characterselect);
		characterselect.playername = savedata.data.playername;
		characterselect.selected = savedata.data.characterselected;
		characterselect.online = online;
		if (characterselect.selected == null)
		{
			characterselect.selected = "reimu";
		}
		characterselect.start();
	}
	
	private function showoptions()
	{
		clear();
		optionscreen = new OptionView();
		optionscreen.AL = AL;
		stage.addChild(optionscreen);
	}
	
}