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
//import com.adobe.crypto.MD5;
/**
 * ...
 * @author RSGmaker
 */
class CharacterSelectView extends Sprite
{
	/*
	public var NextButton:Sprite;
	public var PrevButton:Sprite;
	public var Buttons:Array<Sprite>;
	public var ButtonsPage:Array<Array<Sprite>>;
	public var currentpage:Int;
	public var selected:String;*/
	public var ExitButton:Sprite;
	
	public var AL:Animationloader;
	public var Lselected:String;
	public var selected:String;
	
	//the character buttons
	
	//the list of pages of characters(this is what the arrow buttons cycle trhough)
	
	public var Nameinput:TextField;
	public var StartButton:Sprite;
	
	//main reads this to determine what we're doing
	public var status:String;
	public var playername:String;
	public var online:Bool;
	public var Room:String;
	public var CustomRoom:TextField;
	//character name and ability display text
	//public var selectedcharacter:TextField;
	public var custom:Bool;
	public var charpreview:Bitmap;
	public var char:Sprite;
	
	//this is where the back image and background characters go on
	public var backlayer:Sprite;
	public var backlayerentities:Array<MiniEntity>;
	public var timetospawn:Int;
	
	private var filterArr:Array<flash.filters.BitmapFilter>;
	
	
	///mini game variables
	
	//whether or not the character sprite is following the mouse
	public var following:Bool;
	public var travel:Float;
	public var Vspeed:Float;
	public var Hspeed:Float;
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
	
	public var level:Int;
	public var leveltitle:TextField;
	
	//visual boundries(cleans up areas that are out of bounds)
	private var BGCRight:Bitmap;
	private var BGCLeft:Bitmap;
	private var BGCBottom:Bitmap;
	
	public var refreshing:Bool;
	
	public var select:CharacterSelect;
	
	public var format:TextFormat;
	
	public function new() 
	{
		super();
		selected = "reimu";
		status = "";
		playername = "PlayerName";
		online = false;
		Room = "public1";
		//currentpage = 0;
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
		refreshing = false;
		level = 1;
	}
	public function start() {
		
		GUI = new Sprite();
		entities = new Array<MiniEntity>();
		select = new CharacterSelect(selected);
		select.refreshbuttons();
		selected = "";
		GUI.addChild(select);
		highscore = Main._this.savedata.data.minigamehighscore;
		backlayer = new Sprite();
		backlayerentities = new Array<MiniEntity>();
		var bg = new Bitmap(AL.GetAnimation("CSBack")[0]);
		backlayer.addChild(bg);
		addChild(backlayer);
		//var bg = new Bitmap(AL.GetAnimation("CSBG")[0]);
		bg = new Bitmap(AL.GetAnimation("CSFront")[0]);
		bg.x = 0;
		bg.y = 0;
		addChild(bg);
		addChild(GUI);
		pointcounter = new TextField();
		pointcounter.width = 280;
		pointcounter.height = 30;
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		tmp.color = 0xFFFFFF;
		//format = tmp;
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
		
		highestpointcounter.x = 340;
		highestpointcounter.y = 12;
		highestpointcounter.text = "HighScore:"+highscore;
		highestpointcounter.setTextFormat(tmp);
		highestpointcounter.visible = false;
		addChild(highestpointcounter);
		
		startminigamebutton = AddButton("Start ");
		startminigamebutton.x += 400;
		startminigamebutton.y = 140;
		startminigamebutton.visible = false;
		startminigamebutton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					minigamestarted = true;
					startminigamebutton.visible = false;
					highestpointcounter.visible = true;
				 } 
				);
		addChild(startminigamebutton);
		
		
		char = new Sprite();
		charpreview = new Bitmap();
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
						//currentpage = ButtonsPage.length - 1;
						select.currentpage = select.ButtonsPage.length - 1;
						GUI.visible = false;
						pointcounter.visible = true;
						minigamestarted = false;
						startminigamebutton.visible = true;
						highestpointcounter.visible = false;
						warningtext.visible = true;
					}
					else
					{
						//currentpage = 0;
						select.currentpage = 0;
						pointcounter.visible = false;
						GUI.visible = true;
						minigamestarted = false;
						startminigamebutton.visible = false;
						highestpointcounter.visible = false;
						warningtext.visible = false;
					}
					}
				 } 
				);
		char.addChild(charpreview);
		addChild(char);
		
		
		//ButtonsPage = new Array<Array<Sprite>>();
		stage.color = 0x000000;
		this.stage.scaleMode = StageScaleMode.SHOW_ALL;
		this.stage.align = StageAlign.TOP;
		
		SoundManager.PlayMusic("characterselect");
		
		
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
					tmp = new TextFormat();
					tmp.font = "Arial";
					tmp.size = 32;
					tmp.color = 0xFFFFFF;
		
					StartButton = AddButton("Start Game");
					StartButton.x = 554;
					StartButton.y = 6;
					
					leveltitle = new TextField();
					leveltitle.mouseEnabled = false;
					leveltitle.text = GameView.GetLevelTitle(level, false);
					leveltitle.x = 540;
					leveltitle.y = 100;
					leveltitle.backgroundColor = 0xFFFFFF;
					//leveltitle.background = true;
					leveltitle.setTextFormat(tmp);
					//leveltitle.autoSize = true;
					leveltitle.width = 260;
					leveltitle.wordWrap = true;
					var AB = new flash.filters.GlowFilter();
					AB.blurX = 35;
					AB.blurY = 35;
					//AB.color = 0x66AAFF;
					AB.color = 0x3377CC;
			
					AB.strength = 3.25;
					
					var AA = new flash.filters.DropShadowFilter();
					AA.alpha = 1;
					AA.distance = 3;
					AA.alpha = 25;
					AA.color = 0;
			
					filterArr = new Array();
					filterArr[0] = AA;
					filterArr[1] = AB;
					leveltitle.filters = filterArr;
					addChild(leveltitle);
					
					var B = AddButton("+ ");
					var B2 = AddButton(" - ");
					B.x = 700;
					B.y = 190;
					if (Main._this.savedata.data.maxlevel < 6)
					{
						B.visible = false;
					}
					addChild(B);
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
						if (level + 5 <= Main._this.savedata.data.maxlevel)
						{
							level += 5;
							var tmp = leveltitle.getTextFormat();
							leveltitle.text = GameView.GetLevelTitle(level, false);
							leveltitle.setTextFormat(tmp);
							B2.visible = true;
							if (!(level + 5 <= Main._this.savedata.data.maxlevel))
							{
								B.visible = false;
							}
						}
						else
						{
							SoundManager.Play("bonk");
						}
				 });
				 
					B2.x = 550;
					B2.y = 190;
					B2.visible = false;
					addChild(B2);
					B2.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
						if (level > 1)
						{
					level -= 5;
					var tmp = leveltitle.getTextFormat();
					leveltitle.text = GameView.GetLevelTitle(level, false);
					leveltitle.setTextFormat(tmp);
					B.visible = true;
					if (!(level > 1))
					{
						B2.visible = false;
					}
						}
						else
						{
							SoundManager.Play("bonk");
						}
				 });
				 
					
					StartButton.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "PlayGame";
					StartButton.x -= 10;
					var T = select.selectedcharacter.getTextFormat();
					select.selectedcharacter.text = "Cheat code toggled!\nyou may enter more codes\nor start the game";
					select.selectedcharacter.setTextFormat(T);
				 });
				}
				else
				{
					var B = AddButton("Room#1");
					B.x = 554;
					B.y = 6;
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					status = "PlayGame";
					Room = "public1";});
					
					B = AddButton("Room#2");
					B.x = 554;
					B.y = 106;
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
						Room = "public2";
					status = "PlayGame";
					 } );
					
					B = AddButton("Room#3");
					B.x = 554;
					B.y = 206;
					B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
						Room = "public3";
					status = "PlayGame";
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
		tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		Nameinput.x = 300;
		Nameinput.y = 25;
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
		Nameinput.type = TextFieldType.INPUT;
		Nameinput.borderColor = 0x0000FF;
		Nameinput.backgroundColor = 0xFFFFFF;
		GUI.addChild(Nameinput);
		
		BGCRight = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCRight.x = 800;
		BGCRight.y = 0;
		BGCRight.scaleX = 500;
		BGCRight.scaleY = 2000;
		addChild(BGCRight);
		BGCLeft = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCLeft.x = -500;
		BGCLeft.y = 0;
		BGCLeft.scaleX = 500;
		BGCLeft.scaleY = 2000;
		//BGCLeft.z = -10;
		addChild(BGCLeft);
		BGCBottom = new Bitmap(Assets.getBitmapData("assets/bgcolor.png"));
		BGCBottom.x = -500;
		BGCBottom.y = 600;
		BGCBottom.scaleX = 1500;
		BGCBottom.scaleY = 1000;
		//BGCBottom.z = -10;
		addChild(BGCBottom);
		
		//simulate some time so background characters will appear immediatly
		var i = 0;
		while (i < 450)
		{
			this_onEnterFrame();
			i++;
		}
	}
	private function stage_onKeyDown (event:KeyboardEvent):Void {
		var A = Nameinput.getTextFormat();
		if (event.keyCode == Keyboard.BACKSPACE) {
				Nameinput.text = Nameinput.text.substr(0, Nameinput.text.length - 1);
		}
		else
		{
			Nameinput.text = Nameinput.text + String.fromCharCode(event.charCode);
		}
		Nameinput.setTextFormat(A);
	}
	
	public function this_onEnterFrame ():Void {
		if (selected != select.selected && select.selected != null)
		{
			selected = select.selected;
		}
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
		
		//backlayer stuff
		if (!refreshing)
		{
			var i = 0;
			while (i < backlayerentities.length)
			{
				backlayerentities[i].update();
				if (!backlayerentities[i].alive || backlayerentities[i].charname == selected)
				{
					var E = backlayerentities[i];
					backlayerentities.remove(E);
					backlayer.removeChild(E);
					i--;
				}
				i++;
			}
			timetospawn -= 1;
			if (timetospawn < 1)
			{
				var ind = Math.floor(Player.characters.length * Math.random());
				var C = Player.characters[ind];
				var j = 0;
				while (j < backlayerentities.length)
				{
					//check to see if this choice would be a duplicate
					if (backlayerentities[j].charname == C)
					{
						//if so lets not add it.
						C = "";
						j = backlayerentities.length;
					}
					j++;
				}
				if (C!= "" && C != selected && Main._this.savedata.data.unlock[ind])
				{
					var E = null;
					var X = -1;
					//determines how far down they are and adjusts their size for better pseudo 3d effect
					var depth = Math.random();
					var CC = C;
					if (Math.random() < 0.5)
					{
						X = 801;
						CC = C + "F";
					}
					E = new MiniEntity( X, 124 + (110 * depth), AL.GetAnimation(CC)[0], 0.5 + (Math.random() * 2), false, 0);
					E.charname = C;
					E.scaleX += (depth * 0.3);
					E.scaleY = E.scaleX;
					E.bounce = true;
					if (Math.random() > 0.5)
					{
						E.behavior = Math.floor(4 * Math.random());
					}
					backlayerentities[backlayerentities.length] = E;
					if (E != null)
					{
						backlayer.removeChildren(1);
						backlayerentities.sort(sortentities);
						var i = 0;
						while (i < backlayerentities.length)
						{
							backlayer.addChild(backlayerentities[i]);
							i++;
						}
					}
				}
				timetospawn = Math.floor(30 + (150 * Math.random()));
			}
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
		else if (!refreshing)
		{
			updateminigame();
		}
		if (BGCBottom != null)
		{
		//force always on top.
		removeChild(BGCBottom);
		removeChild(BGCLeft);
		removeChild(BGCRight);
		
		addChild(BGCBottom);
		addChild(BGCLeft);
		addChild(BGCRight);
		}
	}
	
	public function sortentities(A:MiniEntity, B:MiniEntity):Int
	{
		if (A.scaleX > 1.3 && !(B.scaleX > 1.3))
		{
			return -1;
		}
		if (B.scaleX > 1.3 && !(A.scaleX > 1.3))
		{
			return 1;
		}
		if (A.getBounds(this).bottom < B.getBounds(this).bottom)
		{
			return -1;
		}
		if (A.getBounds(this).bottom > B.getBounds(this).bottom)
		{
			return 1;
		}
		return 0;
	}
	
	public function updateminigame()
	{
		var MX = mouseX;
		var MY = mouseY;
		if (MX < 0)
		{
			MX = 0;
		}
		if (MX > 800)
		{
			MX = 800;
		}
		char.buttonMode = Vspeed == 0;
			var PX = char.x + (charpreview.width / 2);
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
			
			var P:Float = 3;
			while (P < points)
			{
				P *= 1.35;
				T *= 0.95;
			}
			timer = Math.ceil(T);
			var X = -1.0;
			var Y = -1.0;
			var R = Math.random();
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
			E.update();
			var ok = !E.alive;
			if (!ok)
			{
				if (char.getBounds(this).intersects(E.getBounds(this)))
				{
					ok = true;
					
					if (E.dangerous)
					{
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
			if (Vspeed == 0 && char.y+5 >= G && MY < 250)
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
			
			if (PX < MX)
			{
				if (PX + spd > MX)
				{
					PX = MX;
					Hspeed = 0;
				}
				else
				{
					Hspeed += 0.7;
					if (Hspeed > spd)
					{
						Hspeed = spd;
					}
				}
			}
			if (PX > MX)
			{
				if (PX - spd < MX)
				{
					PX = MX;
					Hspeed = 0;
				}
				else
				{
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
	private function AddButton(text:String):Sprite
	{
		var buttonSprite = new MenuButton(text);
		GUI.addChild(buttonSprite);
		return buttonSprite;
	}
}