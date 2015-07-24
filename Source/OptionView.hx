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
class OptionView extends Sprite
{

	public var AL:Animationloader;
	public var img_options:Bitmap;
	public var BackButton:Sprite;
	public var status:String;
	
	//volume meters
	public var sndmeter:Sprite;
	public var musicmeter:Sprite;
	
	//the current button being configured
	public var selection:Int;
	public function new() 
	{
		super();
		var str = "assets/Sprites/options0.png";
		var bd = Assets.getBitmapData (str);
		img_options = new Bitmap(bd);
		
		selection = -1;
		var rectangleShape:Shape = new Shape();
		rectangleShape.graphics.beginFill(0x000000);
		rectangleShape.graphics.drawRect(0, 0, 800, 600);
		rectangleShape.graphics.endFill();
		addChild(rectangleShape);
		img_options.alpha = 0.4;
		addChild(img_options);
		var T:TextField = new TextField();
		T.x = 0;
		T.y = 30;
		T.text = "SoundVolume:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		addChild(T);
		var XX = 120;
		var YY = 20;
		sndmeter = new Sprite();
		sndmeter.graphics.beginFill(0x333333);
		sndmeter.graphics.drawRect(XX, YY, 200, 50);
		sndmeter.graphics.endFill();
		
		sndmeter.graphics.beginFill(0x00aa22);
		sndmeter.graphics.drawRect(XX, YY, Main._this.savedata.data.soundvolume * 200, 50);
		sndmeter.graphics.endFill();
		addChild(sndmeter);
		var X1 = XX;
		var Y1 = YY;
		sndmeter.buttonMode = true;
		sndmeter.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				var X:Float = ((sndmeter.mouseX - X1) / 200.0);
				SoundManager._this.SetSoundVolume(X);
				X = SoundManager._this.GetSoundVolume();
				sndmeter.graphics.clear();
				Main._this.savedata.data.soundvolume = X;
				sndmeter.graphics.beginFill(0x333333);
				sndmeter.graphics.drawRect(X1, Y1, 200, 50);
				sndmeter.graphics.endFill();
		
				sndmeter.graphics.beginFill(0x00aa22);
				sndmeter.graphics.drawRect(X1, Y1, X * 200, 50);
				sndmeter.graphics.endFill();
				 } 
				);
				T = new TextField();
		T.x = 0;
		T.y = 100+30;
		T.text = "MusicVolume:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		addChild(T);
				XX = 120;
		YY = 120;
		musicmeter = new Sprite();
		musicmeter.graphics.beginFill(0x333333);
		musicmeter.graphics.drawRect(XX, YY, 200, 50);
		musicmeter.graphics.endFill();
		
		musicmeter.graphics.beginFill(0x00aa22);
		musicmeter.graphics.drawRect(XX, YY, Main._this.savedata.data.musicvolume * 200, 50);
		musicmeter.graphics.endFill();
		musicmeter.buttonMode = true;
		addChild(musicmeter);
		musicmeter.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				var X:Float = ((musicmeter.mouseX - XX) / 200.0);
				SoundManager._this.SetMusicVolume(X);
				X = SoundManager._this.GetMusicVolume();
				musicmeter.graphics.clear();
				Main._this.savedata.data.musicvolume = X;
				musicmeter.graphics.beginFill(0x333333);
				musicmeter.graphics.drawRect(XX, YY, 200, 50);
				musicmeter.graphics.endFill();
		
				musicmeter.graphics.beginFill(0x00aa22);
				musicmeter.graphics.drawRect(XX, YY, X * 200, 50);
				musicmeter.graphics.endFill();
				 } 
				);
		T = new TextField();
		T.x = 0;
		T.y = 250;
		T.text = "Jump:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[0]));
		B.x = 70;
		B.y = 250;
		B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				selection = 0;
				 } 
				);
				T = new TextField();
				var W = B.width-40;
		T.x = 130+W;
		T.y = 250;
		T.text = "Ability:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[1]));
		B.x = 210+W;
		B.y = 250;
		B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				selection = 1;
				 } 
				);
				T = new TextField();
		T.x = 0;
		T.y = 350;
		T.text = "Left:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[2]));
		B.x = 70;
		B.y = 350;
		B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				selection = 2;
				 } 
				);
				W = B.width-40;
				T = new TextField();
		T.x = 130+W;
		T.y = 350;
		T.text = "Right:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[3]));
		B.x = 210+W;
		B.y = 350;
		B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				selection = 3;
				 } 
				);
				T = new TextField();
		T.x = 0;
		T.y = 450;
		T.text = "Pause:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[5]));
		B.x = 70;
		B.y = 450;
		B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				selection = 5;
				 } 
				);
			T = new TextField();
		T.x = 0;
		T.y = 550;
		T.text = "Interact:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[4]));
		B.x = 70;
		B.y = 550;
		B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				selection = 4;
				 } 
				);
		status = "";
		BackButton = AddButton("Back");
		BackButton.x = 700;
		BackButton.y = 550;
		BackButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				status = "Back";
				 } 
				);
	}
	public function stage_onKeyUp (event:KeyboardEvent):Void {
		if (selection > -1)
		{
			Main._this.savedata.data.controlscheme[selection] = event.keyCode;
			status = "refresh";
		}
	}
	//convert keycodes to string
	public function stringfromcode(code:UInt):String
	{
		if (code == Keyboard.LEFT)
		{
			return "Left";
		}
		if (code == Keyboard.RIGHT)
		{
			return "Right";
		}
		if (code == Keyboard.UP)
		{
			return "Up";
		}
		if (code == Keyboard.DOWN)
		{
			return "Down";
		}
		if (code == Keyboard.ENTER)
		{
			return "Enter";
		}
		if (code == Keyboard.SPACE)
		{
			return "Space";
		}
		var ret = String.fromCharCode(code);
		if (ret == "")
		{
			ret = "NULL";
		}
		return ret;
	}
	private function AddButton(text:String):Sprite
	{
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 32;
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
		rectangleShape.graphics.drawRect(0, 0, textField.textWidth + SZ3, textField.textHeight + SZ3);
		rectangleShape.graphics.endFill();
		rectangleShape.graphics.beginFill(0x11CC55);
		rectangleShape.graphics.drawRect(SZ, SZ, textField.textWidth + SZ, textField.textHeight + SZ);
		rectangleShape.graphics.endFill();

		var buttonSprite:Sprite = new Sprite();
		
		buttonSprite.addChild(rectangleShape);
		buttonSprite.addChild(textField);
		addChild(buttonSprite);
		buttonSprite.x -= (textField.width / 2);
		buttonSprite.width = textField.width;
		buttonSprite.height = textField.height;
		buttonSprite.buttonMode = true;
		return buttonSprite;
	}
}