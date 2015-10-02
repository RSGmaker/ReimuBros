package;
import abilities.BasicShot;
import abilities.Floating;
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
import openfl.text.TextFieldType;
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
class CharacterSelect extends Sprite
{
	public var AL:Animationloader;
	public var ExitButton:Sprite;
	public var NextButton:Sprite;
	public var PrevButton:Sprite;
	public var Buttons:Array<MenuButton>;
	public var ButtonsPage:Array<Array<MenuButton>>;
	public var ButtonDisplay:Sprite;
	public var selected:String;
	public var currentpage:Int;
	public var refreshing:Bool;
	public var selectedcharacter:TextField;
	private var filterArr:Array<flash.filters.BitmapFilter>;
	
	public var BW:Int = 78;
	public var BH:Float = 0.75;
	public var GUI:Sprite;
	public var charlist:Array<String>;
	public var customavatar:Bool;
	public function new(startingselection:String="reimu",list:Array<String> = null,customavatar:Bool=false) 
	{
		super();
		selected = startingselection;
		charlist = list;
		AL = Main._this.AL;
		ButtonsPage = new Array<Array<MenuButton>>();
		GUI = new Sprite();
		addChild(GUI);
		ButtonDisplay = new Sprite();
		GUI.addChild(ButtonDisplay);
		
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		tmp.color = 0xFFFFFF;
		selectedcharacter = new TextField();
		selectedcharacter.x = 10;
		selectedcharacter.y = 2;
		selectedcharacter.text = "";
		selectedcharacter.width = 290 - selectedcharacter.x;
		selectedcharacter.height = 200;
		selectedcharacter.mouseEnabled = false;
		GUI.addChild(selectedcharacter);
		//makebuttons();
		//refreshbuttons();
		selectedcharacter.setTextFormat(tmp);
		
		var AA = new flash.filters.DropShadowFilter();
		AA.alpha = 1;
		AA.distance = 3;
		AA.alpha = 25;
		AA.color = 0;
		filterArr = new Array();
		filterArr[0] = AA;
		selectedcharacter.filters = filterArr;
		this.customavatar = customavatar;
		
		makebuttons();
		refreshbuttons();
		
		if (ButtonsPage.length > 1 && ButtonsPage[1].length>0)
		{
		
		NextButton = AddButton("→ ");
		
		NextButton.x = 284;
		NextButton.y = 530;
		NextButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					//if (!following)
					{
					currentpage++;
					if (currentpage >= ButtonsPage.length-1)
					{
						currentpage -= ButtonsPage.length-1;
					}
					refreshbuttons();
					}
					
				 } 
				);
				
		PrevButton = AddButton("← ");
		
		PrevButton.x = 144;
		PrevButton.y = 530;
		PrevButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					//if (!following)
					{
					currentpage--;
					if (currentpage < 0)
					{
						currentpage += ButtonsPage.length-1;
					}
					refreshbuttons();
					}
				 } 
				);
		}
		
		
	}
	private function AddButton(text:String):Sprite
	{
		var buttonSprite = new MenuButton(text);
		ButtonDisplay.addChild(buttonSprite);
		return buttonSprite;
	}
	public function refreshdescription()
	{
		//var tf:Dynamic = (B.getChildByName("textField"));
		/*#if html5
			var S = "";
			if (i < charlist.length)
			{
				S = charlist[i];
				
			}
			else
			{
				//S = Player.hiddencharacters[i-Player.characters.length];
			}
			#else
			var S:String = tf.text.toLowerCase();
			#end*/
			var S = selected;
			var disp = S;
			if (S.toLowerCase() == "customavatar")
			{
				S = Main._this.savedata.data.avatarability;
				disp = Main._this.savedata.data.playername;
			}
			
			var dsc = "Can float briefly";
			var AL = PlayerAbilityManager.GetAbilities2(S);
			dsc = "";
			var c = 0;
			//var i = 0;
			while (c < AL.length)
			{
				dsc = dsc + AL[c].description;
				c++;
			}
			var tmp = new TextFormat();
			tmp.font = "Arial";
			tmp.size = 22;
			tmp.color = 0xFFFFFF;
			var SS = (disp.charAt(0).toUpperCase() + disp.substr(1)).split("ALT").join("☆");
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
			}
			//.split("_").join(" ")
			//var basic = S.split("ALT").join("");
			var SC = tmp;

			
			selectedcharacter.text = SS + "\n"+dsc;
			selectedcharacter.setTextFormat(SC);
			
			
	}
	public function refreshbuttons()
	{
		var i = 0;
		
		refreshing = true;
		if (charlist == null)
		{
			charlist = Player.characters;
		}
		
		while (i < Buttons.length)
		{
			var B = Buttons[i];
			B.visible = (ButtonsPage[currentpage].indexOf(B) > -1);
			var tf:Dynamic = (B.getChildByName("textField"));
		#if html5
			var S = "";
			if (i < charlist.length)
			{
				S = charlist[i];
				
			}
			else
			{
				//S = Player.hiddencharacters[i-Player.characters.length];
			}
			#else
			var S:String = tf.text.toLowerCase();
			#end
			
			/*var dsc = "Can float briefly";
			var AL = PlayerAbilityManager.GetAbilities2(S);
			dsc = "";
			var c = 0;
			while (c < AL.length)
			{
				dsc = dsc + AL[c].description;
				if (i > 0)
				{
					dsc = dsc + "\n";
				}
				c++;
			}
			var tmp = new TextFormat();
			tmp.font = "Arial";
			tmp.size = 22;
			tmp.color = 0xFFFFFF;*/
			
			var SS = S.charAt(0).toUpperCase() + S.substr(1);
			var O:Dynamic = (B.getChildByName("selectedshape"));
			var V:Dynamic = (B.getChildByName("selectedshape2"));
			//var SC = tmp;
			if (S == selected)
			{
				//O.visible = true;
				//V.visible = false;
				
				//selectedcharacter.text = SS + "\n"+dsc;
				//selectedcharacter.setTextFormat(SC);
			}
			else
			{
				var II = Player.characters.indexOf(S);
				if (II < 0)
				{
					B.buttonMode = true;
				}
				else if (II >= 0)
				{
					B.buttonMode = Main._this.savedata.data.unlock[II];
				}
				else
				{
					II = -1;
					if (II >= 0)
					{
						B.buttonMode = Main._this.savedata.data.hidden[II];
					}
					else
					{
						B.buttonMode = false;
					}
				}
				
				//O.visible = false;
				if ((S + "ALT") == selected)
				{
					//V.visible = true;
					//selectedcharacter.text = SS+"☆" + "\n" + dsc;
					//selectedcharacter.setTextFormat(SC);
				}
				else
				{
					//V.visible = false;
					var D:Dynamic = B;
					D.setcolors(D.data.innercolor, D.data.outlinecolor,0.65);
				}
			}
			//this_onEnterFrame();
			i += 1;
		}
		refreshdescription();
		refreshing=false;
	}
	private function makebuttons()
	{
		if (charlist == null)
		{
			charlist = Player.characters;
		}
		//if (customavatar && CharHelper.getdnapart(Main._this.savedata.data.avatar,0)!="-1")
		if (customavatar && Main._this.savedata.data.avatar.indexOf("-1")<0)
		{
			charlist = charlist.copy();
			charlist.push("customavatar");
		}
		var X = 0.0;
		//var Y = 76.0;
		var Y = 110.0;
		var S = 3;
		var i = 0;
		var j = 0;
		var ST = 20;
		ST = 0;
		Buttons = new Array<MenuButton>();
		var O = Main._this.savedata.data.unlock;
		var k = 0;
		var page = new Array<MenuButton>();
		var PC = Player.charorder;
		while (i < PC.length)
		{
			X = 5;
			//Y = 76;
			Y = 110;
		page = new Array<MenuButton>();
		ButtonsPage[ButtonsPage.length] = page;
		while (i < PC.length && k<5)
		{
			X = 5;
			while (i < PC.length && j < 5)
			{
				var B = null;
				var ok = false;
				if (PC[i] != "unused")
				{
				if (charlist.indexOf(PC[i]) >= 0)
				{
					if (O[charlist.indexOf(PC[i])] || PC[i] == "customavatar")
					{
						B = AddCharacterButton(PC[i], true);
						ok = true;
					}
				}
				else
				{
					B = null;
					ok = false;
					
					//B = AddCharacterButton(PC[i], false);
					//B = AddCharacterButton(PC[i], true);
					//ok = true;
				}
				}
				else
				{
					B = null;
					ok = false;
				}
				if (ok)
				{
				page[page.length] = B;
				B.x += X;
				B.y += Y;
				B.visible = ButtonsPage.length == 1;
				Buttons[Buttons.length] = B;
				X += BW + S;
				j += 1;
				}
				i += 1;
				
			}
			Y += BW + S+ST;
			k++;
			j = 0;
		}
		k = 0;
		}
		ButtonsPage[ButtonsPage.length] = new Array<MenuButton>();
		i = 0;
		Y = 76;
		Y -= 76 + S + ST;
	}
	private function AddCharacterButton(text:String,unlocked:Bool):MenuButton
	{
		var buttonSprite = new MenuButton(text);
		buttonSprite.manualheight = BW;
		buttonSprite.manualwidth = BW;
		buttonSprite.outlinesize = 5;
		buttonSprite.setanimation(text, BH, BH);
		buttonSprite.textfield.visible = false;
		buttonSprite.button.alpha = 0.65;
		
		//if (unlocked || charlist != Player.characters)
		{
		buttonSprite.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					//var D:Dynamic = buttonSprite;
					var tf = buttonSprite.textfield;
					//var tf:Dynamic = (D.getChildByName("textField"));
					buttonSprite.setcolors(0xFF0000, 0xFFFFFF, 1);
					//var S = gettext(Buttons.indexOf(D)).toLowerCase();
					var ind = Buttons.indexOf(buttonSprite);
					if (buttonSprite.textfield.text == selected)
					{
						var A = Main._this.AL.GetAnimation(selected + "ALT");
						if (A != null && A.length > 0 && (Main._this.savedata.data.alts[ind] || ind>=Player.characters.length))
						{
							selected = selected + "ALT";
							buttonSprite.setcolors(0xFF00FF, 0x0000FF, 1);
							buttonSprite.buttonMode = true;
						}
					}
					else
					{
						selected = buttonSprite.textfield.text;
						var A = Main._this.AL.GetAnimation(selected + "ALT");
						if (A != null && A.length > 0 && (Main._this.savedata.data.alts[ind] || ind>=Player.characters.length))
						{
							buttonSprite.buttonMode = true;
						}
						else
						{
							buttonSprite.buttonMode = false;
						}
					}
					refreshbuttons();
				 } 
				);
				
			var LL = PlayerAbilityManager.GetAbilities2(text);
			var AA = false;
			if (LL.length == 1 && Std.is(LL[0], BasicShot) )
			{
				AA = true;
			}
			if (AA)
			{
				buttonSprite.innercolor = 0x00AA33;
			}
			else
			{
				buttonSprite.innercolor = 0x33AA00;
			}
		if (AA)
		{
			
			buttonSprite.innercolor = 0x11CC55;
		}
		else
		{
			buttonSprite.innercolor = 0x77EE11;
		}
		}
		buttonSprite.data.innercolor = buttonSprite.innercolor;
		buttonSprite.data.outlinecolor = buttonSprite.outlinecolor;
		
		if (text == selected)
		{
			buttonSprite.setcolors(0xFF0000, 0xFFFFFF, 1);
			currentpage = ButtonsPage.length-1;
		}
		if (text + "ALT" == selected)
		{
			buttonSprite.setcolors(0xFF00FF, 0x0000FF, 1);
			currentpage = ButtonsPage.length-1;
		}
		
		buttonSprite.update();
		buttonSprite.x = 0;
		ButtonDisplay.addChild(buttonSprite);
		//GUI.addChild(buttonSprite);
		return buttonSprite;
	}
	
}