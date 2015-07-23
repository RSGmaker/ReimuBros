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
//import com.adobe.crypto.MD5;
/**
 * ...
 * @author RSGmaker
 */
class CharacterSelect extends Sprite
{
	public var AL:Animationloader;
	public var Lselected:String;
	public var selected:String;
	//the character buttons
	public var Buttons:Array<Sprite>;
	//the list of pages of characters(this is what the arrow buttons cycle trhough)
	public var ButtonsPage:Array<Array<Sprite>>;
	public var Nameinput:TextField;
	public var StartButton:Sprite;
	public var ExitButton:Sprite;
	public var NextButton:Sprite;
	public var PrevButton:Sprite;
	//main reads this to determine what we're doing
	public var status:String;
	public var playername:String;
	public var online:Bool;
	public var Room:String;
	public var CustomRoom:TextField;
	//character name and ability display text
	public var selectedcharacter:TextField;
	public var currentpage:Int;
	public var custom:Bool;
	public var charpreview:Bitmap;
	public var char:Sprite;
	
	
	///mini game variables
	
	//whether or not the character sprite is following the mouse
	public var following:Bool;
	public var travel:Float;
	public var Vspeed:Float;
	public var Hspeed:Float;
	//public var points:Array<Sprite>;
	//public var obstacles:Array<Sprite>;
	public var entities:Array<MiniEntity>;
	public var warningtext:TextField;
	public var pointcounter:TextField;
	public var highestpointcounter:TextField;
	public var timer:Int;
	public var gamespeed:Float;
	public var points:Int;
	public var GUI:Sprite;
	public var startminigamebutton:Sprite;
	public var minigamestarted:Bool;
	public var highscore:Int;
	public var newscore:Bool;
	
	public function new() 
	{
		super();
		selected = "reimu";
		status = "";
		playername = "PlayerName";
		online = false;
		Room = "public1";
		currentpage = 0;
		custom = false;
		Lselected = "";
		travel = 0;
		following = false;
		Vspeed = 0;
		Hspeed = 0;
		timer = 60;
		gamespeed = 2;
		points = 0;
		minigamestarted = false;
		highscore = 0;
		newscore = false;
	}
	public function start() {
		//points = new Array<Sprite>();
		//obstacles = new Array<Sprite>();
		
		GUI = new Sprite();
		entities = new Array<MiniEntity>();
		
		highscore = Main._this.savedata.data.minigamehighscore;
		
		var bg = new Bitmap(AL.GetAnimation("CSBG")[0]);
		bg.x = 0;
		bg.y = 0;
		addChild(bg);
		addChild(GUI);
		pointcounter = new TextField();
		pointcounter.width = 280;
		pointcounter.height = 30;
		//Nameinput.width = Nameinput.height = 200;
		//Nameinput.x = Nameinput.y = 50;
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		tmp.color = 0xFFFFFF;
		warningtext = new TextField();
		warningtext.visible = false;
		warningtext.text = "Click on your character again to return.";
		warningtext.y = 550;
		warningtext.x = 200;
		warningtext.width = 500;
		warningtext.mouseEnabled = false;
		warningtext.setTextFormat(tmp);
		
		addChild(warningtext);
		pointcounter.x = 10;
		pointcounter.y = 12;
		pointcounter.text = "Points:"+0;
		pointcounter.setTextFormat(tmp);
		pointcounter.visible = false;
		addChild(pointcounter);
		
		
		highestpointcounter = new TextField();
		highestpointcounter.width = 280;
		highestpointcounter.height = 30;
		//Nameinput.width = Nameinput.height = 200;
		//Nameinput.x = Nameinput.y = 50;
		
		highestpointcounter.x = 340;
		highestpointcounter.y = 12;
		highestpointcounter.text = "HighScore:"+highscore;
		highestpointcounter.setTextFormat(tmp);
		highestpointcounter.visible = false;
		addChild(highestpointcounter);
		
		startminigamebutton = AddButton("Start");
		startminigamebutton.x += 400;
		startminigamebutton.y = 140;
		startminigamebutton.visible = false;
		startminigamebutton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					minigamestarted = true;
					startminigamebutton.visible = false;
					highestpointcounter.visible = true;
					//warningtext.visible = false;
				 } 
				);
		addChild(startminigamebutton);
		
		
		char = new Sprite();
		charpreview = new Bitmap();
		//charpreview.x = 440;
		//charpreview.y = 300;
		char.x = 440;
		char.y = 300;
		charpreview.scaleX = 1.5;
		charpreview.scaleY = 1.5;
		char.buttonMode = true;
		char.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					if (Vspeed == 0)
					{
					if (newscore)
						{
							Main._this.savedata.data.minigamehighscore = points;
							Main._this.savedata.flush();
							newscore = false;
						}
					following = !following;
					Lselected = "";
					Hspeed = 0;
					Vspeed = 0;
					travel = 0;
					var i = 0;
					while (i < entities.length)
					{
						removeChild(entities[i]);
						i++;
					}
					entities = new Array<MiniEntity>();
					points = 0;
					timer = 60;
					
					if (following)
					{
						currentpage = ButtonsPage.length - 1;
						//NextButton.visible = false;
						//PrevButton.visible = false;
						GUI.visible = false;
						pointcounter.visible = true;
						//selectedcharacter.visible = false;
						minigamestarted = false;
						startminigamebutton.visible = true;
						highestpointcounter.visible = false;
						warningtext.visible = true;
					}
					else
					{
						currentpage = 0;
						//NextButton.visible = true;
						//PrevButton.visible = true;
						pointcounter.visible = false;
						GUI.visible = true;
						minigamestarted = false;
						startminigamebutton.visible = false;
						highestpointcounter.visible = false;
						warningtext.visible = false;
						//selectedcharacter.visible = true;
					}
					refreshbuttons();
					}
					//char.buttonMode = false;
				 } 
				);
		char.addChild(charpreview);
		addChild(char);
		
		
		ButtonsPage = new Array<Array<Sprite>>();
		stage.color = 0x000000;
		this.stage.scaleMode = StageScaleMode.SHOW_ALL;
		this.stage.align = StageAlign.TOP;
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		tmp.color = 0xFFFFFF;
		selectedcharacter = new TextField();
		selectedcharacter.x = 10;
		selectedcharacter.y = 2;
		selectedcharacter.text = "";
		//selectedcharacter.width = 800;
		selectedcharacter.width = 250-selectedcharacter.x;
		selectedcharacter.mouseEnabled = false;
		GUI.addChild(selectedcharacter);
		makebuttons();
		/*var i = 0;
		while (i < ButtonsPage.length)
		{
			var j = 0;
			while (j < ButtonsPage.length)
			{
				var B = ButtonsPage[j];
				
				j++;
			}
			i++;
		}*/
		refreshbuttons();
		selectedcharacter.setTextFormat(tmp);
		
		SoundManager.PlayMusic("characterselect");
		//if (ButtonsPage.length > 1)
		if (ButtonsPage.length > 1 && ButtonsPage[1].length>0)
		{
		
		NextButton = AddButton("→");
		
		NextButton.x = 384;
		NextButton.y = 530;
		NextButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					//status = "TitleScreen";
					//ExitButton.x -= 10;
					if (!following)
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
				
		PrevButton = AddButton("←");
		
		PrevButton.x = 244;
		PrevButton.y = 530;
		PrevButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					//status = "TitleScreen";
					//ExitButton.x -= 10;
					if (!following)
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
		
		
		ExitButton = AddButton("Title Screen");
		
		ExitButton.x = 554;
		ExitButton.y = 530;
		ExitButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "TitleScreen";
					ExitButton.x -= 10;
				 } 
				);
				if (!online)
				{
					StartButton = AddButton("Start Game");
					StartButton.x = 554;
					StartButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "PlayGame";
					StartButton.x -= 10;
				 });
				}
				else
				{
					var B = AddButton("Room#1");
					B.x = 554;
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "PlayGame";
					//StartButton.x -= 10;
					Room = "public1";});
					
					B = AddButton("Room#2");
					B.x = 554;
					B.y = 100;
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
						Room = "public2";
					status = "PlayGame";
					//StartButton.x -= 10;
					 } );
					
					B = AddButton("Room#3");
					B.x = 554;
					B.y = 200;
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
						Room = "public3";
					status = "PlayGame";
					//StartButton.x -= 10;
					});
					CustomRoom = new TextField();
					CustomRoom.width = 200;
					CustomRoom.height = 30;
					var tmp = new TextFormat();
					tmp.font = "Arial";
					tmp.size = 18;
					CustomRoom.x =554;
					CustomRoom.y = 400;
					CustomRoom.text = "CustomRoom";
					CustomRoom.border = true;
					CustomRoom.background = true;
					CustomRoom.setTextFormat(tmp);
					CustomRoom.wordWrap = true; 
					CustomRoom.type = TextFieldType.INPUT;//flash.text.TextFieldType.INPUT;
					CustomRoom.borderColor = 0x0000FF;
					CustomRoom.backgroundColor = 0xFFFFFF;
					GUI.addChild(CustomRoom);
					B = AddButton("Custom");
					B.x = 554;
					B.y = 450;
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
						Room = CustomRoom.text;
						if (Room != "public1" && Room != "public2" && Room != "public3" && Room != "CustomRoom")
						{
							custom = true;
						}
					status = "PlayGame";
					//StartButton.x -= 10;
					});
				}
				
		
		Nameinput = new TextField();
		Nameinput.width = 280;
		Nameinput.height = 30;
		//Nameinput.width = Nameinput.height = 200;
		//Nameinput.x = Nameinput.y = 50;
		tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		//tmp.color = 0xFFFFFF;
		//Nameinput.x = 180;
		Nameinput.x = 250;
		Nameinput.y = 25;
		//Nameinput.width = (442 - (Nameinput.x));
		Nameinput.width = (512 - (Nameinput.x));
		if (playername == null || playername == "")
		{
			playername = "PlayerName";
		}
		Nameinput.text = playername;
		Nameinput.border = true;
		Nameinput.background = true;
		Nameinput.setTextFormat(tmp);
		Nameinput.wordWrap = true;
		Nameinput.type = TextFieldType.INPUT;//flash.text.TextFieldType.INPUT;
		Nameinput.borderColor = 0x0000FF;
		Nameinput.backgroundColor = 0xFFFFFF;
		//Nameinput.needsSoftKeyboard = true;
		//Nameinput.addEventListener( TouchEvent.TOUCH_BEGIN, function( ev ) { requestSoftKeyboard(); } );
		GUI.addChild(Nameinput);
		//stage.addEventListener (KeyboardEvent.KEY_DOWN, stage_onKeyDown);
		//stage.addEventListener (TouchEvent.TOUCH_BEGIN,);
		//stage.addEventListener( TouchEvent.TOUCH_BEGIN, function( ev ) { /*if (!touched)*/{Lib.current.stage.displayState = openfl.display.StageDisplayState.FULL_SCREEN;}MSE = true; touched = true; } );
	}
	private function stage_onKeyDown (event:KeyboardEvent):Void {
		//TF.text = "test"+event.toString();
		var A = Nameinput.getTextFormat();
		if (event.keyCode == Keyboard.BACKSPACE) {
				//TF.text = "space!";
				Nameinput.text = Nameinput.text.substr(0, Nameinput.text.length - 1);
		}
		else
		{
			Nameinput.text = Nameinput.text + String.fromCharCode(event.charCode);
		}
		Nameinput.setTextFormat(A);
	}
	
	private function refreshbuttons()
	{
		var i = 0;
		//Buttons = new Array<Sprite>();
		
		while (i < Buttons.length)
		{
			var B = Buttons[i];
			B.visible = (ButtonsPage[currentpage].indexOf(B) > -1);
			var tf:Dynamic = (B.getChildByName("textField"));
			#if html5
			var S = "";
			if (i < Player.characters.length)
			{
				S = Player.characters[i];
				
			}
			else
			{
				S = Player.hiddencharacters[i-Player.characters.length];
			}
			#else
			var S:String = tf.text.toLowerCase();
			#end
			var dsc = "Can float briefly";
			var SP = Player.Scharacters.indexOf(S);
			if (SP >= 0)
			{
				dsc = Player.Description[SP];
			}
			var SS = S.charAt(0).toUpperCase() + S.substr(1);
			var O:Dynamic = (B.getChildByName("selectedshape"));
			var V:Dynamic = (B.getChildByName("selectedshape2"));
			//visible = true;
			var SC = selectedcharacter.getTextFormat();
			if (S == selected)
			{
				O.visible = true;
				V.visible = false;
				
				selectedcharacter.text = SS + "\n"+dsc;
				selectedcharacter.setTextFormat(SC);
			}
			else
			{
				var II = Player.characters.indexOf(S);
				if (II >= 0)
				{
					B.buttonMode = Main._this.savedata.data.unlock[II];
				}
				else
				{
					//II = Player.hiddencharacters.indexOf(S);
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
				
				O.visible = false;
				if ((S + "ALT") == selected)
				{
					V.visible = true;
					selectedcharacter.text = SS+"☆";
					selectedcharacter.setTextFormat(SC);
				}
				else
				{
					V.visible = false;
				}
			}
			//B.x += X;
			//B.y += Y;
			//Buttons[i] = B;
			//X += B.width + S;
			this_onEnterFrame();
			i += 1;
		}
		/*charpreview.bitmapData = AL.GetAnimation(selected)[0];
		charpreview.x = 495 - (charpreview.width / 2);
		charpreview.y = 500 - charpreview.height;*/
	}
	public function this_onEnterFrame ():Void {
		if (Lselected != selected)
		{
			charpreview.bitmapData = AL.GetAnimation(selected)[0];
			if (!following)
			{
				char.x = 495 - (charpreview.width / 2);
				char.y = 500 - charpreview.height;
			}
			Lselected = selected;
		}
		
		if (!following)
		{
			char.buttonMode = true;
		if (mouseX < 495)
		{
			charpreview.bitmapData = AL.GetAnimation(selected+"F")[0];
		}
		else
		{
			charpreview.bitmapData = AL.GetAnimation(selected)[0];
		}
		}
		else
		{
			char.buttonMode = Vspeed == 0;
			//var PX = char.x - (charpreview.width / 2);
			var PX = char.x + (charpreview.width / 2);
			//if (mouseX < PX)
			if (Hspeed<0)
		{
			charpreview.bitmapData = AL.GetAnimation(selected+"F")[0];
		}
		if (Hspeed>0)
		{
			charpreview.bitmapData = AL.GetAnimation(selected)[0];
		}
		timer--;
		if (timer < 0 && minigamestarted)
		{
			var T:Float = 60;
			//var P = 5;
			//var P:Float = 4;
			
			var P:Float = 3;
			while (P < points)
			{
				P *= 1.35;
				T *= 0.95;
			}
			/*if (points > 10)
			{
				T = 55;
			}
			if (points > 20)
			{
				T -= 50;
			}
			if (points > 50)
			{
				T -= 5;
			}
			if (points > 100)
			{
				T -= 5;
			}
			if (points > 200)
			{
				T -= 5;
			}*/
			timer = Math.ceil(T);
			//timer = 60;
			/*var S = new Sprite();
			var B = new Bitmap(AL.GetAnimation("Point")[0]);
			S.addChild(B);
			S.x = 800;
			S.y = 460;
			addChild(S);*/
			//points[points.length] = S;
			var X = -1.0;
			var Y = -1.0;
			var R = Math.random();
			//R = 0.76;
			if (R < 0.25)
			{
				X = -1;
				Y = 180 + (280 * Math.random());
			}
			else if (R < 0.5)
			{
				X = 801;
				Y = 180 + (280 * Math.random());
			}
			else if (R < 0.75)
			{
				X = 30 + (740 * Math.random());
				Y = -1;
			}
			else
			{
				X = 30 + (740 * Math.random());
				Y = 601;
			}
			var pts = 1;
			var danger = false;
			var ani = AL.GetAnimation("Point")[0];
			if (points > 49)
			{
				if (Math.random() < 0.15)
				{
					pts = 0;
					danger = true;
					ani = AL.GetAnimation("bullet")[0];
				}
			}
			var E = new MiniEntity(X, Y, ani, gamespeed, danger, pts);
			entities[entities.length] = E;
			addChild(E);
		}
		var i = 0;
		while (i < entities.length)
		{
			var E = entities[i];
			//E.x -= gamespeed;
			E.update();
			//if (E.x < -E.width)
			var ok = !E.alive;
			if (!ok)
			{
				if (char.getBounds(this).intersects(E.getBounds(this)))
				{
					ok = true;
					
					if (E.dangerous)
					{
						//points = 0;
						if (newscore)
						{
							Main._this.savedata.data.minigamehighscore = points;
							Main._this.savedata.flush();
							newscore = false;
						}
						points = Math.floor(points * 0.9);
					}
					else
					{
						if (E.pointvalue > 0)
						{
							points += E.pointvalue;
							SoundManager.Play("collectcoin");
							if (points > highscore)
							{
								highscore = points;
								newscore = true;
							}
						}
					}
				}
			}
			if (ok)
			{
				entities.remove(E);
				removeChild(E);
				i--;
			}
			i++;
			
		}
		//gamespeed = 2 + (points * 0.017);
		gamespeed = 2 + (points * 0.02);
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		tmp.color = 0xFFFFFF;
		
		pointcounter.text = "Points:"+points;
		pointcounter.setTextFormat(tmp);
		highestpointcounter.text = "HighScore:"+highscore;
		highestpointcounter.setTextFormat(tmp);
		
			var OPX = PX;
			var G = 500 - charpreview.height;
			if (Vspeed == 0 && char.y+5 >= G && mouseY < 250)
			{
				Vspeed = -20;
			}
			Vspeed += 0.8;
			char.y += Vspeed;
			if (char.y >= G)
			{
				Vspeed = 0;
				char.y = G;
			}
			var spd = 8;
			
			if (PX < mouseX)
			{
				if (PX + spd > mouseX)
				{
					PX = mouseX;
					Hspeed = 0;
				}
				else
				{
					//PX += spd;
					Hspeed += 0.7;
					if (Hspeed > spd)
					{
						Hspeed = spd;
					}
				}
			}
			if (PX > mouseX)
			{
				if (PX - spd < mouseX)
				{
					PX = mouseX;
					Hspeed = 0;
				}
				else
				{
					//PX -= spd;
					Hspeed -= 0.7;
					if (Hspeed < -spd)
					{
						Hspeed = -spd;
					}
				}
			}
			PX += Hspeed;
			char.x = PX - (charpreview.width / 2);
			if (char.y == G)
			{
				travel += Math.abs(OPX - PX);
				if (travel > 10 && Vspeed==0)
				{
					//travel -= 5;
					travel = 0;
					Vspeed = -2.5;
					if (minigamestarted)
					{
						var S = "step" + Math.ceil(Math.random()*3);
						SoundManager.Play(S);
					}
				}
			}
		}
	}
	private function gettext(i:Int):String
	{
		#if html5
		var S = "";
		if (i < Player.characters.length)
		{
			S = Player.characters[i];
		}
		else
		{
			S = Player.hiddencharacters[i-Player.characters.length];
		}
		return S.charAt(0).toUpperCase() + S.substr(1);
		#else
		var tf:Dynamic = (Buttons[i].getChildByName("textField"));
		return tf.text.toLowerCase();
		#end
		//var SS = S.charAt(0).toUpperCase() + S.substr(1);
	}
	private function makebuttons()
	{
		var X = 0.0;
		var Y = 76.0;
		var S = 3;
		var i = 0;
		var j = 0;
		var ST = 20;
		ST = 0;
		Buttons = new Array<Sprite>();
		//Main._this.savedata.data.unlock = null;
		var O = Main._this.savedata.data.unlock;
		//ButtonsPage
		var k = 0;
		var page = new Array<Sprite>();
		//var PC = Player.characters.copy();
		//PC = PC.concat(Player.hiddencharacters);
		var PC = Player.charorder;
		while (i < PC.length)
		{
			X = 0;
			Y = 76;
		page = new Array<Sprite>();
		ButtonsPage[ButtonsPage.length] = page;
		while (i < PC.length && k<5)
		{
			X = 0;
			while (i < PC.length && j < 5)
			{
				var B = null;
				var ok = false;
				if (PC[i] != "unused")
				{
				if (Player.characters.indexOf(PC[i]) >= 0)
				{
					if (O[Player.characters.indexOf(PC[i])])
					{
						//B = AddCharacterButton(PC[i], O[Player.characters.indexOf(PC[i])]);
						B = AddCharacterButton(PC[i], true);
						ok = true;
					}
				}
				/*else if (Player.hiddencharacters.indexOf(PC[i]) >= 0)
				{
					if (Main._this.savedata.data.hidden[Player.hiddencharacters.indexOf(PC[i])])
					{
						//B = AddCharacterButton(PC[i], Main._this.savedata.data.hidden[Player.hiddencharacters.indexOf(PC[i])]);
						B = AddCharacterButton(PC[i], true);
						ok = true;
					}
				}*/
				else
				{
					B = null;
					ok = false;
					
					B = AddCharacterButton(PC[i], false);
					ok = true;
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
				//var B = AddCharacterButton(Player.characters[i],true);
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
		ButtonsPage[ButtonsPage.length] = new Array<Sprite>();
		//O = Main._this.savedata.data.hidden;
		i = 0;
		//X = 500;
		Y = 76;
		Y -= 76 + S + ST;
	}
	private function Omakebuttons()
	{
		var X = 0.0;
		var Y = 76.0;
		var S = 3;
		var i = 0;
		var j = 0;
		var ST = 20;
		ST = 0;
		Buttons = new Array<Sprite>();
		//Main._this.savedata.data.unlock = null;
		var O = Main._this.savedata.data.unlock;
		//ButtonsPage
		var k = 0;
		var page = new Array<Sprite>();
		var PC = Player.characters.copy();
		//PC = PC.concat(Player.hiddencharacters);
		while (i < PC.length)
		{
			X = 0;
			Y = 76;
		page = new Array<Sprite>();
		ButtonsPage[ButtonsPage.length] = page;
		while (i < PC.length && k<5)
		{
			X = 0;
			while (i < PC.length && j < 5)
			{
				var B;
				var ok = false;
				if (Player.charorder.indexOf(PC[i]) < 0)
				{
					var SS = PC[i];
					B = null;
				}
				if (i < Player.characters.length)
				{
					B = AddCharacterButton(PC[i], O[i]);
					ok = true;
				}
				else
				{
					if (Main._this.savedata.data.hidden[i - Player.characters.length])
					{
						B = AddCharacterButton(PC[i], true);
						ok = true;
					}
					else
					{
						B = null;
						ok = false;
					}
				}
				if (ok)
				{
				page[page.length] = B;
				//var B = AddCharacterButton(Player.characters[i],true);
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
		ButtonsPage[ButtonsPage.length] = new Array<Sprite>();
		//O = Main._this.savedata.data.hidden;
		i = 0;
		//X = 500;
		Y = 76;
		Y -= 76 + S + ST;
	}
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
		GUI.addChild(buttonSprite);
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
	public var BW:Int = 86;
	public var BH:Float = 0.86;
	private function AddCharacterButton(text:String,unlocked:Bool):Sprite
	{
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 20;
		tmp.color = 0xFFFFFF;
		var textField:TextField = new TextField();
		textField.name = "textField";
		var W = BW;
		var WH = W / 2;
		
		textField.y = W;
		//textField.textColor = 0xFFFFFF;
		if (unlocked)
		{
		textField.text = text.charAt(0).toUpperCase() + text.substr(1);
		}
		else
		{
			tmp.size = 12;
			textField.text = "Not Unlocked";
		}
		textField.setTextFormat(tmp);
		textField.x = WH - (textField.textWidth / 2);
		textField.mouseEnabled = false;
		var SZ = 5;
		var SZ2 = SZ + SZ;
		var SZ3 = SZ + SZ + SZ;
		var bitmap:Bitmap = new Bitmap(AL.GetAnimation(text)[0]);
		bitmap.scaleX = BH;
		bitmap.scaleY = BH;
		var buttonSprite:Sprite = new Sprite();
		var rectangleShape:Shape = new Shape();
		bitmap.x = SZ;
		bitmap.y = SZ;
		
		bitmap.x = WH - (bitmap.width / 2);
		bitmap.y = WH - (bitmap.height / 2);
		rectangleShape.alpha = 0.65;
		if (unlocked)
		{
			var AA = (Player.Scharacters.indexOf(text) < 0);
			if (AA)
			{
				rectangleShape.graphics.beginFill(0x00AA33);
			}
			else
			{
				rectangleShape.graphics.beginFill(0x33AA00);
			}
		rectangleShape.graphics.drawRect(0, 0, W, W);
		rectangleShape.graphics.endFill();
		if (AA)
		{
			rectangleShape.graphics.beginFill(0x11CC55);
		}
		else
		{
			rectangleShape.graphics.beginFill(0x77EE11);
		}
		rectangleShape.graphics.drawRect(SZ, SZ, W - SZ2, W - SZ2);
		rectangleShape.graphics.endFill();
		}
		else
		{
			rectangleShape.graphics.beginFill(0xFF0000);
			rectangleShape.graphics.drawRect(0, 0, W, W);
			rectangleShape.graphics.endFill();
			rectangleShape.graphics.beginFill(0x000000);
			rectangleShape.graphics.drawRect(SZ, SZ, W - SZ2, W - SZ2);
			rectangleShape.graphics.endFill();
			rectangleShape.alpha *= 0.5;
		}
		
		
		var rectangleShape2:Shape = new Shape();
		rectangleShape2.name = "selectedshape";
		rectangleShape2.graphics.beginFill(0xFFFFFF);
		rectangleShape2.graphics.drawRect(0, 0, W, W);
		rectangleShape2.graphics.endFill();
		rectangleShape2.graphics.beginFill(0xFF0000);
		rectangleShape2.graphics.drawRect(SZ, SZ, W - SZ2, W - SZ2);
		rectangleShape2.graphics.endFill();
		rectangleShape2.visible = false;
		//rectangleShape2.alpha = 0.7;
		
		var rectangleShape3:Shape = new Shape();
		rectangleShape3.name = "selectedshape2";
		rectangleShape3.graphics.beginFill(0x0000FF);
		rectangleShape3.graphics.drawRect(0, 0, W, W);
		rectangleShape3.graphics.endFill();
		rectangleShape3.graphics.beginFill(0xFF00FF);
		rectangleShape3.graphics.drawRect(SZ, SZ, W - SZ2, W - SZ2);
		rectangleShape3.graphics.endFill();
		rectangleShape3.visible = false;
		//rectangleShape3.alpha = 0.7;
		textField.visible = false;
		buttonSprite.addChild(textField);
		buttonSprite.addChild(rectangleShape);
		buttonSprite.addChild(rectangleShape2);
		buttonSprite.addChild(rectangleShape3);
		if (text == selected)
		{
			rectangleShape2.visible = true;
			currentpage = ButtonsPage.length-1;
		}
		if (text + "ALT" == selected)
		{
			rectangleShape3.visible = true;
			currentpage = ButtonsPage.length-1;
		}
		if (unlocked)
		{
			buttonSprite.addChild(bitmap);
		}
		GUI.addChild(buttonSprite);
		if (unlocked)
		{
		buttonSprite.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					var D:Dynamic = ev.target;
					var tf:Dynamic = (D.getChildByName("textField"));
					//if (selected == tf.text.toLowerCase())
					var S = gettext(Buttons.indexOf(D)).toLowerCase();
					if (S == selected)
					{
						var A = Main._this.AL.GetAnimation(selected + "ALT");
						if (A != null && A.length > 0 && (Main._this.savedata.data.alts[Buttons.indexOf(D)] || Buttons.indexOf(D)>=Player.characters.length))
						{
							selected = selected + "ALT";
							D.buttonMode = true;
						}
					}
					else
					{
						selected = S;
						var A = Main._this.AL.GetAnimation(selected + "ALT");
						if (A != null && A.length > 0 && (Main._this.savedata.data.alts[Buttons.indexOf(D)] || Buttons.indexOf(D)>=Player.characters.length))
						{
							D.buttonMode = true;
						}
						else
						{
							D.buttonMode = false;
						}
					}
					/*var O:Dynamic = (D.getChildByName("selectedshape"));
					O.visible = true;*/
					refreshbuttons();
				 } 
				);
		}
		buttonSprite.buttonMode = unlocked;
		return buttonSprite;
	}
}