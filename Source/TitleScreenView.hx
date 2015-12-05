package;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Sprite;
import openfl.display.Shape;
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
class TitleScreenView extends Sprite
{

	public var img_titlescreen:Bitmap;
	public var background:TitleScreenBackground;
	public var AL:Animationloader;
	public var menu:Bool;
	public var MSE:Bool;
	public var startgame:MenuButton;
	public var singleplayer:Sprite;
	public var options:MenuButton;
	public var _exit:Sprite;
	public var status:String;
	
	public var statusmsg:Sprite;
	public var lastpage:Int;
	public var currentpage:Int;
	
	public var Description:TextField;
	
	public var Logo:Bitmap;
	
	public var clickmessage:TextField;
	public var clickpulse:Bool;
	
	//public var pages:Array<Sprite>;
	public var pages:Array<Menu>;
	
	public var MP:MenuButton;
	
	public var preloadindex:Int = 0;
	public function new() 
	{
		super();
		menu = false;
		status = "";
		scrollRect = new Rectangle(0, 0, 800, 600);
	}
	public function update() {
	background.update();
	if (clickmessage.visible)
	{
		if (clickpulse)
		{
			clickmessage.alpha += 0.015;
			if (clickmessage.alpha >= 1)
			{
				clickpulse = false;
			}
		}
		else
		{
			clickmessage.alpha -= 0.015;
			if (clickmessage.alpha <= 0)
			{
				clickpulse = true;
			}
		}
	}
	if (preloadindex < Player.characters.length)
	{
		var B = AL.GetAnimation(Player.characters[preloadindex]);
		B = AL.GetAnimation(Player.characters[preloadindex]+"ALT");
		preloadindex++;
	}
	}
	public function start() {
		
		stage.color = 0x009977;
		this.stage.scaleMode = StageScaleMode.SHOW_ALL;
		this.stage.align = StageAlign.TOP;
		img_titlescreen = new Bitmap(AL.GetAnimation("titlescreen")[0]);
		img_titlescreen.x = 0;
		img_titlescreen.y = 0;
		///addChild(img_titlescreen);
		background = new TitleScreenBackground();
		addChild(background);
		background.start();
		//SoundManager.PlayJingle("titlescreen");
		SoundManager.PlayMusic("titlescreen");
		if (Main._this.DEBUG)
		{
			//warn the developer that they are using debug mode(so they won't accidently upload it)
			var tmp = new TextFormat();
			tmp.font = "Arial";
			tmp.size = 44;
			tmp.color = 0xFF0000;
			var warning = new TextField();
			warning.text = "DEBUG MODE ACTIVE!!!";
			warning.mouseEnabled = false;
			warning.setTextFormat(tmp);
			warning.width = warning.textWidth;
			warning.y = 500;
			warning.x = 50;
			addChild(warning);
		}
		addEventListener( MouseEvent.MOUSE_UP, function( ev ) { MSE = true; show_menu(); } );
		addEventListener (KeyboardEvent.KEY_UP, function( ev ) { MSE = true; show_menu(); } );
		
		var S = new Sprite();
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 18;
		tmp.color = 0x000000;
		var textField:TextField = new TextField();
		textField.setTextFormat(tmp);
		textField.text = "Coded by: RSGmaker";
		textField.setTextFormat(tmp);
		textField.mouseEnabled = false;
		S.x = 340;
		S.y = 560;
		S.buttonMode = true;
		textField.width = textField.textWidth+16;
		textField.height = textField.textHeight + 16;
		var AB = new flash.filters.GlowFilter();
					AB.blurX = 35;
					AB.blurY = 35;
					//AB.color = 0x66AAFF;
					AB.color = 0x3377CC;
			
					AB.strength = 3.25;
					var FA = new Array<flash.filters.BitmapFilter>();
					FA.push(AB);
					textField.filters = FA;
		S.addChild(textField);
		addChild(S);
		statusmsg = null;
		//if player was forced out of a game, display any relevant messages that are set.
		var SS = Main._this.statusmessage;
		if (SS != "")
		{
			var B = new Sprite();
			var BB = new Shape();
			BB.graphics.beginFill(0x000000);
			BB.graphics.drawRect(0, 0, 800, 200);
			BB.graphics.endFill();
			B.addChild(BB);
			var BBB = new TextField();
			BBB.text = SS;
			BBB.textColor = 0xffffff;
			BBB.width = 800;
			BBB.height = 200;
			B.x = 0;
			B.y = 100;
			B.addChild(BBB);
			addChild(B);
			statusmsg = B;
		}
		Logo = new Bitmap(Assets.getBitmapData("assets/Sprites/logo.png"));
		addChild(Logo);
		clickmessage = new TextField();
		clickmessage.x = 270;
		clickmessage.y = 250;
		clickmessage.text = "Click to start";
		clickmessage.mouseEnabled = false;
		clickmessage.scaleX = 4;
		clickmessage.scaleY = clickmessage.scaleX;
		clickmessage.textColor = 0xFFFFFF;
		clickmessage.filters = FA;
		clickmessage.alpha = 0;
		addChild(clickmessage);
	}
	public function setpage(page:Int)
	{
		pages[page].visible = true;
		pages[currentpage].visible = false;
		lastpage = currentpage;
		currentpage = page;
		var i = 0;
		/*if (!Main._this.cancontinue)
		{
			i = 1;
		}*/
		MP.usecolorscheme(i);
	}
	public function setdescription(text:String)
	{
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		tmp.color = 0xFFFFFF;
		Description.width = 2000;
		Description.wordWrap = false;
		Description.text = text;
		Description.setTextFormat(tmp);
		if (Description.textWidth >= 800)
		{
			Description.width = 800;
			Description.wordWrap = true;
		}
		else
		{
			Description.wordWrap = false;
		}
		Description.text = text;
		Description.setTextFormat(tmp);
		Description.x = -Description.textWidth / 2;
		Description.x += 400;
		Description.width = Description.textWidth + 8;
		Description.height = Description.textHeight + 8;
		
	}
	public function show_menu()
	{
		
		if (!menu && MSE)
		{
			if (statusmsg != null)
			{
				removeChild(statusmsg);
				statusmsg = null;
			}
			clickmessage.visible = false;
			var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 24;
		tmp.color = 0xFFFFFF;
		var textField:TextField = new TextField();
		textField.setTextFormat(tmp);
		textField.text = "Version" + Main._this.gameversion;
		textField.setTextFormat(tmp);
		textField.mouseEnabled = false;
		//textField.x = 360;
		//textField.y = 0;
		textField.x = 600;
		textField.y = 140;
		
		textField.width = textField.textWidth+16;
		textField.height = textField.textHeight;
		/*var clip = Assets.getMovieClip ("create:Character");
            addChild (clip);*/
			/*Assets.loadLibrary ("Char", function (_) {
            var clip = Assets.getMovieClip ("Char:Char");
			clip.x = 400;
			clip.y = 300;
			addChild (clip);
			clip.cacheAsBitmap = true;
			var D:Dynamic = clip;
			D = clip.getChildByName("body");
			D.gotoAndStop(10);
			D = clip.getChildByName("eyes");
			D.gotoAndStop(0);
			D = clip.getChildByName("legs");
			D.gotoAndStop(0);
			D = clip.getChildByName("hat");
			D.gotoAndStop(50);
			D = clip.getChildByName("arms");
			D.gotoAndStop(20);
			D = clip.getChildByName("head");
			D.gotoAndStop(15);
			D.HairColor.gotoAndStop(15);
			D.eye2.visible = false;
			//D.eye2._visible = true;
            //D.eye2.gotoAndStop(GameData.Parts[A][N][5]);
			D = clip.getChildByName("head2");
			D.gotoAndStop(15);
			D.HairColor.gotoAndStop(15);
			D.HairColor.gotoAndStop(15);
			D = clip.getChildByName("accessory");
			D.gotoAndStop(65);
			D = clip.getChildByName("wings");
			D.gotoAndStop(37);
			D = clip.getChildByName("mouth");
			D.gotoAndStop(1);
			D = clip.getChildByName("item");
			D.gotoAndStop(2);
			if (false)
			{
            var bitmapData:BitmapData = new BitmapData(Std.int(clip.width), Std.int(clip.height),true, 0x00000000);
			bitmapData.draw(clip);
			removeChild(clip);
			var bitmap:Bitmap = new Bitmap(bitmapData);
			bitmap.x = 400;
			bitmap.y = 300;
			addChild(bitmap);
		}

        });*/
			
		addChild(textField);
		
			menu = true;
			/*#if flash
			startgame = AddButton("Multiplayer");
			
			startgame.y = 200+200;
			#else
			startgame = AddButton("Single Player");
			startgame.y = 50+200;
			#end
			startgame.x += 400;
			startgame.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					#if flash
					status = "OpenPlay";
					#else
					status = "SinglePlayer";
					#end
				 } 
				);
				#if flash
			var PA = AddButton("Play Alone");
			PA.x += 400;
			PA.y = 50+200;
			PA.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				status = "SinglePlayer";
				 } 
				);
				#end
				
				options = AddButton("Options");
			options.x = 6;
			options.y = 6;
			options.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				status = "Options";
				 } 
				);
				
				var PA = AddButton("Manual");
			PA.x += 700;
			PA.y = 10;*/
			var main = new Sprite();
			main.x = 0;
			main.y = 150;
			//main.x = 400;
			//main.y = 225+25;
			addChild(main);
			
			//pages = new Array<Sprite>();
			pages = new Array<Menu>();
			var i = 0;
			while (i < 4)
			{
				pages[i] = new Menu();
				pages[i].menuoffsetx = -100;
				pages[i].menuwidth = 800 - (main.x * 2);
				pages[i].menuwidth -= (pages[i].menuoffsetx * 2);
				//pages[i].y = 200;
				//pages[i].menuheight = 600 - main.y;
				pages[i].menuheight = 520 - main.y;
				main.addChild(pages[i]);
				i++;
			}
			/*pages[0] = new Sprite();
			pages[1] = new Sprite();
			main.addChild(pages[0]);
			main.addChild(pages[1]);*/
			
			
			var P = pages[0];
			
			
			startgame = AddButton("Play Game",P);
			startgame.addclick(function( ev ) {
				//status = "SinglePlayer";
					setpage(1);
				 } 
				);
			options = AddButton("Options", P);
			options.sound = "ok";
			options.addclick(function( ev ) {
				status = "Options";
				 } 
				);
			var B = AddButton("Manual", P);
			B.sound = "ok";
			B.addclick(function( ev ) {
				Lib.getURL (new openfl.net.URLRequest ("http://sta.sh/0t7u3ibw7dl"));
				 } 
				);
				
				//if (Main._this.savedata.data.avatar != "")
				//if (CharHelper.getdnapart(Main._this.savedata.data.avatar,0)!="-1")
				{
			B = AddButton("Customize", P);
			B.sound = "ok";
			B.addclick(function( ev ) {
				status = "Shop";
				 } 
				);
				}
				
			P.finish(4);
			var seperation = 160;
			P = pages[1];
			P.visible = false;
			/*B = AddButton("Classic Mode", P);
			B.addclick(function( ev ) {
				//status = "SinglePlayer";
					Main._this.roomprefix = "Classic";
					Main._this.resetgamesettings();
					//setdescription("Classic Mode:Clear levels by defeating enemies.Hit blocks with enemies on top of them to flip them over,touching a flipped over enemy defeats them.");
					setdescription("Classic Mode:\nClear levels by defeating enemies.\nHit blocks with enemies on top of them to flip them over,\ntouching a flipped over enemy defeats them.");
					setpage(2);
				 } 
				);
				B = AddButton("Adventure Mode", P);
			B.addclick(function( ev ) {
					Main._this.roomprefix = "Adventure";
					Main._this.resetgamesettings();
					Main._this.GameFlags.set(Main.Adventure, true);
					Main._this.abilitiesenabled = false;
					Main._this.canmyonspawn = false;
					///GameView.levelsperstage = 6;
					//Main._this.playerspick = "red_fairy";
					//Main._this.canselectcharacter = false;
					//Main._this.cancontinue = false;
					//Main._this.canlivesspawn = false;
					setdescription("Adventure Mode:\nTravel through Gensokyo.\nCharacter abilities are replaced with powerup items.");
					setpage(2);
				 } 
				);
			if (Main._this.savedata.data.challenges[3])
			{
				B = AddButton("All Star Mode", P);
			B.addclick(function( ev ) {
					Main._this.roomprefix = "AllStar";
					Main._this.resetgamesettings();
					Main._this.GameFlags.set(Main.AllStar, true);
					Main._this.playerspick = "red_fairy";
					Main._this.canselectcharacter = false;
					Main._this.cancontinue = false;
					Main._this.canlivesspawn = false;
					setdescription("All Star Mode:\nThere are no lives in this mode.\nYou can switch to characters unlocked in this play session.\nLosing a life means losing a character.\nRun out of characters and it's game over.\nFurthermore, continues are not available.");
					setpage(2);
				 } 
				);
			}*/
			{
				var i = 0;
				var C:Array<GameMode> = GameMode.Categories[""];
				while (i < C.length)
				{
					var G = C[i];
					AddGameMode(G, P);
					i++;
				}
			}
			var showchallenges = false;
			{
				var i = 0;
				var C:Array<GameMode> = GameMode.Categories["Challenge"];
				while (i < C.length)
				{
					var G = C[i];
					if (G.getunlocked())
					{
						showchallenges = true;
					}
					//AddGameMode(G, P);
					i++;
				}
			}
			if (showchallenges)
			{
			B = AddButton("Challenges", P);
			B.addclick(function( ev ) {
					setpage(3);
				 } 
				);
			}
			else
			{
				B = AddButton("Locked", P);
				B.sound = "bonk";
			}
			B = AddButton("Back", P);
			B.sound = "cancel";
			B.addclick(function( ev ) {
					setpage(0);
				 } 
				);
			P.finish(4);
			P = pages[2];
			P.visible = false;
			var dimmer = new Shape();
			//dimmer.graphics.beginFill(0, 0.3);
			dimmer.graphics.beginFill(0, 0.4);
			dimmer.graphics.drawRect( 0, 0, 800, 600);
			dimmer.graphics.endFill();
			dimmer.x = -main.x;
			dimmer.y = -main.y;
			P.addChild(dimmer);
			
			Description = new TextField();
			//Description.wordWrap = true;
			
			Description.mouseEnabled = false;
			P.addChild(Description);
			Description.y = (-Description.getBounds(this).y)+20;
			
			B = AddButton("Single Player", P);
			B.sound = "ok";
			B.addclick(function( ev ) {
					status = "SinglePlayer";
				 } 
				);
			B = AddButton("Multiplayer", P);
			B.changecolorscheme(1, 0xAAAAAA, 0x888888);
			MP = B;
			B.sound = "";
			B.addclick(function( ev ) {
					//if (Main._this.cancontinue)
					{
						status = "OpenPlay";
						SoundManager.Play("ok");
					}
					/*else
					{
						SoundManager.Play("bonk");
					}*/
				 } 
				);
			B = AddButton("Back", P);
			B.sound = "cancel";
			B.addclick(function( ev ) {
				Main._this.resetsettings();
				setpage(lastpage);
				 } 
				);
			P.finish(4);
			P = pages[3];
			P.visible = false;
			{
				var i = 0;
				var C:Array<GameMode> = GameMode.Categories["Challenge"];
				while (i < C.length)
				{
					var G = C[i];
					AddGameMode(G, P);
					i++;
				}
			}
			/*var T = "Danmaku";
			if (!Main._this.savedata.data.challenges[0])
			{
				T = "???";
			}
			B = AddButton(T, P);
			if (T != "???")
			{
			//B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
			B.addclick(function( ev ) {
				Main._this.roomprefix = "Danmaku";
				Main._this.GameFlags.clearall();
				Main._this.GameFlags.set(Main.Danmaku, true);
				Main._this.GameFlags.set(Main.EventRoundsOnly, true);
				Main._this.levelselect = false;
				Main._this.level = 35;
				Main._this.levelincrement = 5;
				Main._this.cancontinue = false;
				setdescription("Danmaku:\nDifficulty ramps up quickly in this mode.\nEnemy bullets are everywhere in this mode.");
				setpage(2);
				 } 
				);
			}
			T = "Boss Rush";
			if (!Main._this.savedata.data.challenges[1])
			{
				T = "???";
			}
			B = AddButton(T, P);
			if (T != "???")
			{
			B.addclick(function( ev ) {
				Main._this.roomprefix = "Boss Rush";
				Main._this.GameFlags.clearall();
				Main._this.GameFlags.set(Main.Bossrush, true);
				Main._this.GameFlags.set(Main.EventRoundsOnly, true);
				Main._this.levelselect = false;
				Main._this.level = 35;
				Main._this.levelincrement = 5;
				Main._this.cancontinue = false;
				setdescription("Boss Rush:\nEvery level is a boss event.\nSurvive as many as you can.");
				setpage(2);
				 } 
				);
			}
			T = "Truck Hoarder";
			if (!Main._this.savedata.data.challenges[2])
			{
				T = "???";
			}
			B = AddButton(T, P);
			if (T != "???")
			{
			B.addclick(function( ev ) {
				Main._this.roomprefix = "Truck Hoarder";
				Main._this.GameFlags.clearall();
				Main._this.GameFlags.set(Main.TruckHoarder, true);
				Main._this.GameFlags.set(Main.NoEvents, true);
				Main._this.levelselect = false;
				Main._this.level = 56;
				Main._this.levelincrement = 1;
				Main._this.cancontinue = false;
				setdescription("Truck Hoarder:\nIn this mode you have to beat each level while protecting a toy truck.");
				setpage(2);
				 } 
				);
			}*/
			
			B = AddButton("Back", P);
			B.sound = "cancel";
			B.addclick(function( ev ) {
				setpage(1);
				 } 
				);
			P.finish(4);
		}
		else
		{
			//check if clicked in the "coded by rsgmaker" area
			if (mouseY > 520 && mouseX>300 && mouseX<500 && currentpage == 0)
		{
			Lib.getURL (new openfl.net.URLRequest ("http://rsgmaker.deviantart.com/"));
		}
		//check if clicked in the "manual" area(this would've been better as a mouse up listener...)
		if (mouseY < 80 && mouseX>620 && mouseX<801)
		{
			//Lib.getURL (new openfl.net.URLRequest ("http://sta.sh/0t7u3ibw7dl"));
		}
		}
	}
	private function AddGameMode(gamemode:GameMode, menu:Menu)
	{
		var unlocked = gamemode.getunlocked();
		/*var unlocked:Bool = true;
		if (gamemode.preunlocked)
		{
			unlocked = true;
		}*/
		var text = gamemode.fullname;
		if (!unlocked)
		{
			text = "Locked";
			if (gamemode.hidden)
			{
				return;
			}
		}
		var B = AddButton(text, menu);
		if (!unlocked)
		{
			B.sound = "bonk";
			return;
		}
		B.addclick(function( ev ) {
					Main._this.roomprefix = gamemode.name;
					Main._this.resetgamesettings();
					
					Main._this.changeGameMode(gamemode);
					//Main._this.gamemode = gamemode;
					//Main._this.updateflags();
					
					//Main._this.GameFlags.set(Main.AllStar, true);
					//Main._this.playerspick = "red_fairy";
					//Main._this.canselectcharacter = false;
					//Main._this.cancontinue = false;
					//Main._this.canlivesspawn = false;
					//setdescription("All Star Mode:\nThere are no lives in this mode.\nYou can switch to characters unlocked in this play session.\nLosing a life means losing a character.\nRun out of characters and it's game over.\nFurthermore, continues are not available.");
					var nm = gamemode.fullname;
					if (!gamemode.getcleared())
					{
						nm = nm + " (not yet cleared)";
					}
					else
					{
						nm = nm + " (cleared!)";
					}
					var D = nm+":\n" + gamemode.description;
					if (gamemode.reward > 0 && gamemode.rewardrequirement > 0)
					{
						D = D + "\n\nGoal: Clear " + gamemode.rewardrequirement + " levels";
						if (gamemode.cancontinue)
						{
							//D = D + " without getting a game over";
							D = D + " (Resets on game over)";
						}
						D = D + ".\nReward: " + gamemode.reward + "Mon";
					}
					setdescription(D);
					setpage(2);
				 } 
				);
		/*B = AddButton("All Star Mode", P);
			B.addclick(function( ev ) {
					Main._this.roomprefix = "AllStar";
					Main._this.resetgamesettings();
					Main._this.GameFlags.set(Main.AllStar, true);
					Main._this.playerspick = "red_fairy";
					Main._this.canselectcharacter = false;
					Main._this.cancontinue = false;
					Main._this.canlivesspawn = false;
					setdescription("All Star Mode:\nThere are no lives in this mode.\nYou can switch to characters unlocked in this play session.\nLosing a life means losing a character.\nRun out of characters and it's game over.\nFurthermore, continues are not available.");
					setpage(2);
				 } 
				);*/
	}
	private function AddButton(text:String,sprite:Menu):MenuButton
	{
		var buttonSprite = new MenuButton(text);
		if (sprite == null)
		{
			//sprite = this;
			this.addChild(buttonSprite);
			return buttonSprite;
		}
		sprite.addbutton(buttonSprite);
		//sprite.addChild(buttonSprite);
		/*var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 44;
		var textField:TextField = new TextField();
		textField.name = "textField";
		textField.setTextFormat(tmp);
		textField.width = 500;
		textField.height = 500;
		textField.text = text;
		textField.setTextFormat(tmp);
		textField.mouseEnabled = false;
		var SZ = 6;
		var SZ2 = SZ + SZ;
		var SZ3 = SZ + SZ + SZ;
		textField.x = SZ;
		textField.y = SZ;
		textField.width = textField.textWidth+SZ2;
		textField.height = textField.textHeight+SZ2;
		
		var rectangleShape:Shape = new Shape();
		rectangleShape.graphics.beginFill(0x00AA33);
		rectangleShape.graphics.drawRect(0, 0, textField.textWidth + SZ, textField.textHeight + SZ2);
		rectangleShape.graphics.endFill();
		rectangleShape.graphics.beginFill(0x11CC55);
		rectangleShape.graphics.drawRect(SZ, SZ, textField.textWidth-SZ, textField.textHeight);
		rectangleShape.graphics.endFill();

		var buttonSprite:Sprite = new Sprite();
		
		
		buttonSprite.addChild(rectangleShape);
		buttonSprite.addChild(textField);
		addChild(buttonSprite);
		buttonSprite.x -= (textField.width / 2);
		buttonSprite.width = textField.width;
		buttonSprite.height = textField.height;
		buttonSprite.buttonMode = true;*/
		return buttonSprite;
	}
}