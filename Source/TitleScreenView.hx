package;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Sprite;
import openfl.display.Shape;
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
	public var AL:Animationloader;
	public var menu:Bool;
	public var MSE:Bool;
	public var startgame:Sprite;
	public var singleplayer:Sprite;
	public var options:Sprite;
	public var _exit:Sprite;
	public var status:String;
	
	public var statusmsg:Sprite;
	public var lastpage:Int;
	public var currentpage:Int;
	
	public var Description:TextField;
	
	public var pages:Array<Sprite>;
	public function new() 
	{
		super();
		menu = false;
		status = "";
	}
	public function start() {
		
		stage.color = 0x009977;
		this.stage.scaleMode = StageScaleMode.SHOW_ALL;
		this.stage.align = StageAlign.TOP;
		img_titlescreen = new Bitmap(AL.GetAnimation("titlescreen")[0]);
		img_titlescreen.x = 0;
		img_titlescreen.y = 0;
		addChild(img_titlescreen);
		SoundManager.PlayJingle("titlescreen");
		if (Main._this.DEBUG)
		{
			//warn the developer that they are using debug mode(so they won't accidently upload it)
			var tmp = new TextFormat();
			tmp.font = "Arial";
			tmp.size = 44;
			tmp.color = 0xFF0000;
			var warning = new TextField();
			warning.text = "DEBUG MODE ACTIVE!!!";
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
		textField.text = "Coded by:RSGmaker";
		textField.setTextFormat(tmp);
		textField.mouseEnabled = false;
		S.x = 340;
		S.y = 560;
		S.buttonMode = true;
		textField.width = textField.textWidth+16;
		textField.height = textField.textHeight+16;
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
	}
	public function setpage(page:Int)
	{
		pages[page].visible = true;
		pages[currentpage].visible = false;
		lastpage = currentpage;
		currentpage = page;
	}
	public function setdescription(text:String)
	{
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		tmp.color = 0xFFFFFF;
		Description.text = text;
		Description.setTextFormat(tmp);
		Description.x = -Description.textWidth / 2;
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
			var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 24;
		tmp.color = 0xFFFFFF;
		var textField:TextField = new TextField();
		textField.setTextFormat(tmp);
		textField.text = "Version" + Main._this.gameversion;
		textField.setTextFormat(tmp);
		textField.mouseEnabled = false;
		textField.x = 360;
		textField.y = 0;
		
		textField.width = textField.textWidth+16;
		textField.height = textField.textHeight;
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
			main.x = 400;
			main.y = 225;
			addChild(main);
			
			pages = new Array<Sprite>();
			var i = 0;
			while (i < 4)
			{
				pages[i] = new Sprite();
				main.addChild(pages[i]);
				i++;
			}
			/*pages[0] = new Sprite();
			pages[1] = new Sprite();
			main.addChild(pages[0]);
			main.addChild(pages[1]);*/
			
			
			var P = pages[0];
			
			
			var Y = 0;
			var X = 0;
			startgame = AddButton("Play Game",P);
			startgame.y = Y;
			startgame.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				//status = "SinglePlayer";
					setpage(1);
				 } 
				);
			options = AddButton("Options",P);
			Y += 96;
			options.y = Y;
			options.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				status = "Options";
				 } 
				);
			Y += 96;
			var B = AddButton("Manual",P);
			B.y = Y;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				Lib.getURL (new openfl.net.URLRequest ("http://sta.sh/0t7u3ibw7dl"));
				 } 
				);
				
			Y = 0;
			P = pages[1];
			P.visible = false;
			if (Main._this.savedata.data.challenges[3])
			{
				Y -= 96;
			}
			//P.y = -96;
			B = AddButton("Classic Mode", P);
			B.y = Y;
			Y += 96;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				//status = "SinglePlayer";
					Main._this.roomprefix = "Classic";
					Main._this.GameFlags.clearall();
					setdescription("Classic Mode:\nClear levels by defeating enemies.\nHit blocks with enemies on top of them to flip them over,\ntouching a flipped over enemy defeats them.");
					setpage(2);
				 } 
				);
			if (Main._this.savedata.data.challenges[3])
			{
				B = AddButton("All Star Mode", P);
			B.y = Y;
			Y += 96;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					Main._this.roomprefix = "AllStar";
					Main._this.GameFlags.clearall();
					Main._this.GameFlags.set(Main.AllStar, true);
					Main._this.playerspick = "red_fairy";
					Main._this.canselectcharacter = false;
					Main._this.cancontinue = false;
					Main._this.canlivesspawn = false;
					setdescription("All Star Mode:\nThere are no lives in this mode.\nYou can switch to characters unlocked in this play session.\nLosing a life means losing a character.\nRun out of characters and it's game over.");
					setpage(2);
				 } 
				);
			}
			/*B = AddButton("Single Player", P);
			B.y = Y;
			Y += 96;
			B = AddButton("Multiplayer", P);
			B.y = Y;
			Y += 96;*/
			B = AddButton("Challenges", P);
			B.y = Y;
			Y += 96;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					setpage(3);
				 } 
				);
			B = AddButton("Back", P);
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					setpage(0);
				 } 
				);
			B.y = Y;
			Y += 96;
			
			Y = 0;
			P = pages[2];
			P.visible = false;
			var dimmer = new Shape();
			dimmer.graphics.beginFill(0, 0.3);
			dimmer.graphics.drawRect( 0, 0, 800, 600);
			dimmer.graphics.endFill();
			dimmer.x = -main.x;
			dimmer.y = -main.y;
			P.addChild(dimmer);
			
			Description = new TextField();
			Description.y = -200;
			P.addChild(Description);
			
			B = AddButton("Single Player", P);
			B.y = Y;
			Y += 96;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					/*#if flash
					status = "OpenPlay";
					#else
					status = "SinglePlayer";
					#end*/
					status = "SinglePlayer";
				 } 
				);
			B = AddButton("Multiplayer", P);
			B.y = Y;
			Y += 96;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "OpenPlay";
				 } 
				);
			B = AddButton("Back", P);
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				Main._this.resetsettings();
				setpage(lastpage);
				 } 
				);
			B.y = Y;
			Y += 96;
			
			Y = 0;
			P = pages[3];
			P.visible = false;
			
			var T = "Danmaku";
			if (!Main._this.savedata.data.challenges[0])
			{
				T = "???";
			}
			B = AddButton(T, P);
			if (T != "???")
			{
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
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
				B.y = Y;
			Y += 96;
			T = "Boss Rush";
			if (!Main._this.savedata.data.challenges[1])
			{
				T = "???";
			}
			B = AddButton(T, P);
			if (T != "???")
			{
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
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
			B.y = Y;
			Y += 96;
			T = "Truck Hoarder";
			if (!Main._this.savedata.data.challenges[2])
			{
				T = "???";
			}
			B = AddButton(T, P);
			if (T != "???")
			{
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
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
			}
			B.y = Y;
			Y += 96;
			
			B = AddButton("Back", P);
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				setpage(1);
				 } 
				);
			B.y = Y;
			Y += 96;
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
	private function AddButton(text:String,sprite:Sprite):Sprite
	{
		var buttonSprite = new MenuButton(text);
		if (sprite == null)
		{
			sprite = this;
		}
		sprite.addChild(buttonSprite);
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