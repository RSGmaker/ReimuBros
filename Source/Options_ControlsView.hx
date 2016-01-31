package;
import openfl.display.Sprite;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
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
class Options_ControlsView extends Sprite
{
	//the current button being configured
	public var selection:Int;
	
	public var selected:MenuButton;
	
	public var options:OptionView;
	
	
	public var desc:TextField;
	public var descriptions:Array<String>;
	public function new(opt:OptionView) 
	{
		super();
		descriptions = ["make your character jump","use your character's/item's ability","move left","move right","interact with background object(pickup/drop items)","change your character(pauses in singleplayer)"];
		this.options = opt;
		var V = 0;
		var VB = 70;
		var T = new TextField();
		desc = T;
		T.x = 0;
		T.y = V;
		T.text = "Click a button to rebind the key";
		T.scaleX = 1.5;
		T.scaleY = 1.5;
		T.textColor = 0xFFFFFF;
		T.mouseEnabled = false;
		addChild(T);
		desc.width = desc.textWidth + 8;
		desc.height = desc.textHeight + 8;
		
		V += VB;
		
		T = new TextField();
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
				);
	}
	public function stage_onKeyUp (event:KeyboardEvent):Void {
		if (selection > -1)
		{
			Main._this.savedata.data.controlscheme[selection] = event.keyCode;
			var X = selected.x;
			selected.settext(stringfromcode(event.keyCode)+" ");
			selected.x = X;
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
		desc.text = "Press this button to:" + descriptions[ind];
		desc.textColor = 0xFFFFFF;
		desc.width = desc.textWidth + 8;
		desc.height = desc.textHeight + 8;
		
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