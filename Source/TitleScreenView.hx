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
		//SoundManager.Play("titlescreen");
		//play music would make it repeat :/
		//SoundManager.PlayMusic("titlescreen");
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
		//stage.addEventListener( MouseEvent.MOUSE_UP, function( ev ) { if (!touched) {MSE = false; control[0] = false; control[1] = false; control[2] = false; control[3] = false;} } );
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
		//addEventListener (Event.ENTER_FRAME, this_onEnterFrame);
		//useHandCursor = true;
		
		/*var S = new Sprite();
		S.x = 300;
		S.y = 520;
		S.width = 200;
		S.height = 120;
		S.buttonMode = true;
		addChild(S);*/
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
			//
			menu = true;
			//startgame = AddButton("Start Game");
			#if flash
			startgame = AddButton("Multiplayer");
			
			startgame.y = 200+200;
			#else
			startgame = AddButton("Single Player");
			startgame.y = 50+200;
			#end
			startgame.x += 400;
			//startgame.y = 50+200;
			startgame.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					#if flash
					status = "OpenPlay";
					#else
					status = "SinglePlayer";
					#end
					//removeChild(startgame);
				 } 
				);
				//addChild(startgame);
				#if flash
			var PA = AddButton("Play Alone");
			PA.x += 400;
			//PA.y = 200+200;
			PA.y = 50+200;
			PA.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				status = "SinglePlayer";
				 } 
				);
				#end
				
				options = AddButton("Options");
			options.x = 0;
			options.y = 0;
			options.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				status = "Options";
				 } 
				);
				
				var PA = AddButton("Manual");
			PA.x += 700;
			PA.y = 10;
				//addChild(PA);
		}
		else
		{
			//check if clicked in the "coded by rsgmaker" area
			if (mouseY > 520 && mouseX>300 && mouseX<500)
		{
			Lib.getURL (new openfl.net.URLRequest ("http://rsgmaker.deviantart.com/"));
		}
		//check if clicked in the "manual" area(this would've been better as a mouse up listener...)
		if (mouseY < 80 && mouseX>620 && mouseX<801)
		{
			Lib.getURL (new openfl.net.URLRequest ("http://sta.sh/0t7u3ibw7dl"));
		}
		}
	}
	/*private function this_onEnterFrame (event:Event):Void {
		if (!menu && MSE)
		{
			menu = true;
			startgame = AddButton("Start Game");
			startgame.x += 400;
			startgame.y = 50+200;
			startgame.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "OpenPlay";
				 } 
				);
			singleplayer = AddButton("Play Alone");
			singleplayer.x += 400;
			singleplayer.y = 200+200;
			singleplayer.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				status = "SinglePlayer";
				 } 
				);
		}
	}*/
	private function AddButton(text:String):Sprite
	{
		var tmp = new TextFormat();
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
		//rectangleShape.width = textField.textWidth + 8;
		//rectangleShape.height = textField.textHeight + 8;
		//rectangleShape.graphics.beginFill(0xFF0000);
		rectangleShape.graphics.beginFill(0x00AA33);
		rectangleShape.graphics.drawRect(0, 0, textField.textWidth + SZ3, textField.textHeight + SZ3);
		rectangleShape.graphics.endFill();
		rectangleShape.graphics.beginFill(0x11CC55);
		rectangleShape.graphics.drawRect(SZ, SZ, textField.textWidth + SZ, textField.textHeight + SZ);
		rectangleShape.graphics.endFill();

		var buttonSprite:Sprite = new Sprite();
		
		
		buttonSprite.addChild(rectangleShape);
		buttonSprite.addChild(textField);
		addChild(buttonSprite);
		//make the button centered.
		buttonSprite.x -= (textField.width / 2);
		buttonSprite.width = textField.width;
		buttonSprite.height = textField.height;
		//buttonSprite.x -= Math.ceil(textField.getBounds(this).width);
		//buttonSprite.y -= Math.ceil(textField.textHeight + SZ3);
		//var tf:Dynamic = (buttonSprite.getChildByName("textField"));
		//tf.text = "button sprite text";
		buttonSprite.buttonMode = true;
		return buttonSprite;
	}
}