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
	//public var img_options:Bitmap;
	public var BG:OptionsBackground;
	public var BackButton:MenuButton;
	public var status:String;
	
	//volume meters
	public var sndmeter:Sprite;
	public var musicmeter:Sprite;
	
	//the current button being configured
	public var selection:Int;
	
	public var selected:MenuButton;
	public var frames:Int;
	
	public var controls:Options_ControlsView;
	public var dimmer:Sprite;
	
	public var backbutton:MenuButton;
	public var controlbutton:MenuButton;
	public function new() 
	{
		super();
		AL = Main._this.AL;
		//var str = "assets/Sprites/options0.png";
		/*var str = "background-" + CharHelper.GetBG("Computer Grid");
		//var bd = Assets.getBitmapData (str);
		var bd = AL.GetAnimation(str)[0];
		img_options = new Bitmap(bd);*/
		BG = new OptionsBackground();
		
		
		selection = -1;
		var rectangleShape:Shape = new Shape();
		rectangleShape.graphics.beginFill(0x000000);
		rectangleShape.graphics.drawRect(0, 0, 800, 600);
		rectangleShape.graphics.endFill();
		addChild(rectangleShape);
		addChild(BG);
		//img_options.alpha = 0.4;
		//addChild(img_options);
		var T:TextField = new TextField();
		T.x = 0;
		T.y = 30;
		T.text = "SoundVolume:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var XX = 120;
		var YY = 20;
		sndmeter = new Sprite();
		sndmeter.x = XX;
		sndmeter.y = YY;
		drawbar(sndmeter.graphics, 0, 0, 200, 50, Main._this.savedata.data.soundvolume);
		addChild(sndmeter);
		var X1 = XX;
		var Y1 = YY;
		sndmeter.buttonMode = true;
		sndmeter.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				var X:Float = ((sndmeter.mouseX) / 200.0);
				SoundManager._this.SetSoundVolume(X);
				X = SoundManager._this.GetSoundVolume();
				sndmeter.graphics.clear();
				Main._this.savedata.data.soundvolume = X;
				drawbar(sndmeter.graphics, 0, 0, 200, 50, Main._this.savedata.data.soundvolume);
				 } 
				);
		T = new TextField();
		T.x = 0;
		//T.y = 100+30;
		T.y = 70+30;
		T.text = "MusicVolume:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
				XX = 120;
		YY = 70+20;
		musicmeter = new Sprite();
		musicmeter.x = XX;
		musicmeter.y = YY;
		drawbar(musicmeter.graphics, 0, 0, 200, 50, Main._this.savedata.data.musicvolume);
		musicmeter.buttonMode = true;
		addChild(musicmeter);
		musicmeter.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				var X:Float = ((musicmeter.mouseX) / 200.0);
				SoundManager._this.SetMusicVolume(X);
				X = SoundManager._this.GetMusicVolume();
				musicmeter.graphics.clear();
				Main._this.savedata.data.musicvolume = X;
				drawbar(musicmeter.graphics, 0, 0, 200, 50, Main._this.savedata.data.musicvolume);
				 } 
				);
		T = new TextField();
		T.x = 0;
		//T.y = 100+30;
		T.y = 70+70+30;
		T.text = "Show tutorial:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var tmp = " ";
		if (Main._this.savedata.data.tutorial)
		{
			tmp = " X";
		}
		var B = AddButton(tmp);
		B.outlinecolor = 0xFFFFFF;
		B.innercolor = 0x000000;
		B.manualwidth = 44;
		B.manualheight = B.manualwidth;
		B.textfield.textColor = 0xFFFFFF;
		B.update();
		//B.x = 120;
		B.x = T.textWidth + 50;
		B.y = T.y-5;
		
		var BTT = B;
		B.addclick( function( ev ) {
				//select(B0, 0);
				tmp = " ";
				Main._this.savedata.data.tutorial = (Main._this.savedata.data.tutorial == false);
				if (Main._this.savedata.data.tutorial)
				{
					tmp = " X";
				}
				BTT.settext(tmp);
				 } 
				);	
				
		var V = 550;
		var VB = 70;
		V -= (VB * 3);
		
		
		/*controls = new Options_ControlsView();
		controls.y = V;
		addChild(controls);*/
		
		/*T = new TextField();
		T.x = 0;
		T.y = V;
		T.text = "Jump:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[0]));
		B.sound = "";
		B.x = 70;
		B.y = V;
		var B0 = B;
		B.addclick( function( ev ) {
				select(B0, 0);
				 } 
				);
				T = new TextField();
				var W = B.width-40;
		T.x = 130+W;
		T.y = V;
		T.text = "Ability:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[1]));
		B.sound = "";
		B.x = 210+W;
		B.y = V;
		V += VB;
		var B1 = B;
		B.addclick( function( ev ) {
				select(B1, 1);
				 } 
				);
				T = new TextField();
		T.x = 0;
		T.y = V;
		T.text = "Left:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[2]));
		B.sound = "";
		B.x = 70;
		B.y = V;
		var B2 = B;
		B.addclick( function( ev ) {
				select(B2, 2);
				 } 
				);
				W = B.width-40;
				T = new TextField();
		T.x = 130+W;
		T.y = V;
		T.text = "Right:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[3]));
		B.sound = "";
		B.x = 210+W;
		B.y = V;
		V += VB;
		var B3 = B;
		B.addclick( function( ev ) {
				select(B3, 3);
				 } 
				);
				T = new TextField();
		T.x = 0;
		T.y = V;
		T.text = "Pause:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[5]));
		B.sound = "";
		B.x = 70;
		B.y = V;

		var B5 = B;
		B.addclick( function( ev ) {
				select(B5, 5);
				 } 
				);
			T = new TextField();
		T.x = 0;
		V += VB;
		T.y = V;
		
		T.text = "Interact:";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		var B = AddButton(stringfromcode(Main._this.savedata.data.controlscheme[4]));
		B.sound = "";
		B.x = 70;
		B.y = V;
		var B4 = B;
		B.addclick( function( ev ) {
				select(B4, 4);
				 } 
				);*/
		status = "";
		BackButton = AddButton("Back");
		BackButton.sound = "cancel";
		BackButton.x = 700;
		BackButton.y = 550;
		BackButton.addclick( function( ev ) {
				status = "Back";
				 } 
				);
				
		var delete:MenuButton = new MenuButton("   Erase\nSave Data", 28, "Arial", 5, 0xCC5511, 0xAA0033);
		delete.x = 650;
		delete.y = 8;
		addChild(delete);
		var deletedimmer = new Sprite();
		dimmer = deletedimmer;
		var G = deletedimmer.graphics;
		//G.beginFill(0, 0.3);
		G.beginFill(0, 0.4);
		G.drawRect(0, 0, 800, 600);
		G.endFill();
		deletedimmer.visible = false;
		addChild(deletedimmer);
		deletedimmer = new Sprite();
		deletedimmer.visible = false;
		addChild(deletedimmer);
		
		var erase = new MenuButton("I'm sure.\n(cannot be undone)", 44, "Arial", 5, 0xCC5511, 0xAA0033);
		var cancel = new MenuButton("Cancel");
		cancel.sound = "cancel";
		erase.sound = "ok";
		erase.x = 400;
		erase.y = 400;
		deletedimmer.addChild(erase);
		erase.addclick( function( ev ) {
			Main._this.savedata.clear();
					//status = "Back";
					cancel.visible = false;
					erase.settext("Save Data has been deleted.\nPlease restart ReimuBros\nto complete the reset.");
					erase.x = 200;
					erase.y = 300;
					
					Main._this.init();
		});
		
		cancel.x = 200;
		cancel.y =  400;
		cancel.addclick( function( ev ) {
			deletedimmer.visible = false;
			dimmer.visible = deletedimmer.visible;
			controlbutton.visible = true;
		});
		
		deletedimmer.addChild(cancel);
		//addChild(delete);
		
		delete.addclick( function( ev ) {
			deletedimmer.visible = true;
			dimmer.visible = deletedimmer.visible;
			controlbutton.visible = false;
			}
				);
				
		var B = AddButton("Controls");
		controlbutton = B;
		B.sound = "";
		B.x = 0;
		B.y = 550;
		B.addclick( function( ev ) {
				//select(B0, 0);
				togglecontrols();
				if (controls != null)
				{
					B.settext("Done");
				}
				else
				{
					B.settext("Controls");
				}
				B.x = 0;
		
		}
				);
		
	}
	public function togglecontrols()
	{
		if (controls == null)
		{
			controls = new Options_ControlsView(this);
			controls.x = 400 - (controls.width / 2);
			controls.y = 300 - (controls.height / 2);
			dimmer.visible = true;
			addChild(controls);
		}
		else
		{
			removeChild(controls);
			controls = null;
			dimmer.visible = false;
		}
	}
	public function drawbar(G:Graphics,x:Float, y:Float, W:Float,H:Float,percent:Float)
	{
		G.beginFill(0x1144BB);
		G.drawRect(x, y, W, H);
		G.endFill();
		x += 2;
		y += 2;
		W -= 4;
		H -= 4;
		G.beginFill(0x333333);
		G.drawRect(x, y, W, H);
		G.endFill();
		
		G.beginFill(0x00aa22);
		G.drawRect(x, y, percent * W, H);
		G.endFill();
		
		var fillType:flash.display.GradientType = flash.display.GradientType.LINEAR;
		//var colors:Array<UInt> = [0x777777, 0xffffff];
		//var colors:Array<UInt> = [0, 0xffffff];
		var colors:Array<UInt> = [0x11CC55, 0xffffff];
		var alphas = [0.06, 0.6];
		var ratios = [0x00, 0xFF];
		var matr:flash.geom.Matrix = new flash.geom.Matrix();
		//matr.createGradientBox(50, 9, 1.57079632679, 0, -4.5);
		matr.createGradientBox(percent * W, H, 1.57079632679, 0, 0);
		var spreadMethod:flash.display.SpreadMethod = flash.display.SpreadMethod.REFLECT;
		G.beginGradientFill(fillType, colors, alphas, ratios, matr, spreadMethod);  
	 
		G.drawRect(x, y, percent * W, H);
		G.endFill();
	}
	public function update()
	{
		frames++;
		///if (frames == 1200)
		//if (frames == 1050)
		{
			//SoundManager.PlayMusic("options");
		}
		if (frames == 1)
		{
			SoundManager.PlayMusic("options");
		}
		BG.update();
	}
	public function stage_onKeyUp (event:KeyboardEvent):Void {
		/*if (selection > -1)
		{
			Main._this.savedata.data.controlscheme[selection] = event.keyCode;
			var X = selected.x;
			selected.settext(stringfromcode(event.keyCode)+" ");
			selected.x = X;
		}*/
		if (controls != null)
		{
			controls.stage_onKeyUp(event);
		}
	}
	public function select(button:MenuButton,ind:Int)
	{
		if (selection != ind)
		{
			SoundManager.Play("click");
		}
		selection = ind;
		if (selected != null)
		{
			selected.setcolors(0x11CC55, 0x00AA33);
		}
		button.setcolors(0xFF0000, 0xFFFFFF);
		selected = button;
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
	private function AddButton(text:String):MenuButton
	{
		var buttonSprite = new MenuButton(text+" ", 32);
		addChild(buttonSprite);
		return buttonSprite;
	}
}