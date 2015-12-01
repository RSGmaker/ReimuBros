package;
import abilities.AbsorbDamage;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.geom.Rectangle;
import openfl.text.Font;
import openfl.text.TextField;
import openfl.text.TextFieldType;
import openfl.text.TextFormat;

/**
 * ...
 * @author RSGmaker
 */
class AvatarEditor extends Sprite
{
	public var AL:Animationloader;
	public var background:Sprite;
	public var Nameinput:TextField;
	public var Description:TextField;
	private var avatarpreview:MenuButton;
	public var avatardna:String;
	public var custompages:Array<Sprite>;
	
	//current thing being editted.
	public var custompiece:String;
	public var customindex:Int;
	//current page
	public var custompage:Sprite;
	public var customdisplay:TextField;
	public var dnadisplay:TextField;
	public var outerpiececontainer:Sprite;
	public var piececontainer:Sprite;
	public var pieces:Array<MenuButton>;
	public var selectedpiece:MenuButton;
	public var lselectedpiece:MenuButton;
	public var spectrum:Sprite;
	public var scrollbar:Sprite;
	public var soul:String;
	private var dimmer:Sprite;
	private var soulselect:CharacterSelect;
	private var scrolling:Bool;
	//Version#:Name:Scale:Hat:Hair:Body:Arm:Shoes:Eyes:Mouth:Item:Accessory:Back:this.HairColor
	public static var partlist:Array<String> = ["Version", "Name", "Scale", "Hat", "Hair", "Body", "Arms", "Shoes", "Eyes", "Mouth", "Prop", "Accessory", "Back", "Hair Color", "Skin Color"];
	public var playername:String;
	public var view:ShopView;
	
	//public var generatelimit:Int = 20;
	public var generatelimit:Int = 14;
	public var generateindex:Int;
	public var generateX:Float;
	public var generateY:Float;
	public var generatedone:Bool=true;
	//public var parent:ShopView;
	public function new() 
	{
		//playername = "PlayerName";
		super();
		soul = "none";
		avatardna = "3.39:RSGmaker:100:0:192:324:232:24:0:0:0:1:0:321A00";
		AL = Main._this.AL;
		
		if (CharHelper.optimize)
		{
			generatelimit *= 2;
		}
	}
	public static function pickpart(type:Array<String>):Dynamic
	{
		if (type.length == 0)
		{
			return null;
		}
		var T = type[Math.floor(Math.random() * type.length)];
		var A:Array<Int> = new Array<Int>();
		var D:Dynamic = AvatarEditor.getpart(T);
		var parts = AvatarEditor.getlist(T, false);
		if (parts.length < 1)
		{
			type = type.copy();
			type.remove(T);
			return pickpart(type);
		}
		else
		{
			var ret:Dynamic = { };
			ret.type = T;
			ret.index = parts[Math.floor(Math.random() * parts.length)];
			return ret;
		}
		return null;
	}
	private function changednascale(dna:String, scale:Float):String
	{
		var S = dna.split(":");
		S[2] = "" + scale;
		return S.join(":");
	}
	private function changednapart(dna:String,index:Int, value:String):String
	{
		var S = dna.split(":");
		S[index] = "" + value;
		return S.join(":");
	}
	
	private function getdnapart(dna:String,index:Int):String
	{
		var S = dna.split(":");
		return S[index];
	}
	private function selectcustomization(type:String)
	{
		if (type != "Ability")
		{
			custompages[0].visible = false;
			custompages[1].visible = true;
			custompiece = type;
			setdescription(custompiece+":");
			customindex = partlist.indexOf(custompiece);
			
			generateX = 3;
			generateY = 3;
			generateindex = 0;
			generatedone = false;
			piececontainer.removeChildren();
			generatepieces();
			outerpiececontainer.scrollRect = new Rectangle(0, 0, outerpiececontainer.scrollRect.width, outerpiececontainer.scrollRect.height);
			updatescrollbar();
		}
		else
		{
			if (view != null)
			{
				view.buttons.visible = false;
			}
			custompages[0].visible = false;
			custompages[2].visible = true;
			soulselect.selected = soul;
			soulselect.refreshbuttons();
		}
		
	}
	private function setdescription(text:String)
	{
		customdisplay.text = text;
		customdisplay.textColor = 0xFFFFFF;
		customdisplay.width = customdisplay.textWidth + 8;
		customdisplay.scaleX = 3.5;
		customdisplay.scaleY = 3.5;
		customdisplay.mouseEnabled = false;
	}
	public static function unlockpart(type:String, ind:Int, unlock:Bool = true):Bool
	{
		var DAT = null;
		var U:Array<Bool> = null;
		var type = "Part";
		var index = partlist.indexOf(type);
		var ret = false;
		if (index == 3)
		{
			DAT = CharHelper.HatsData;
			ret = Main._this.savedata.data.unlockables_hat[ind] != unlock;
			Main._this.savedata.data.unlockables_hat[ind] = unlock;
		}
		else if (index == 4)
		{
			DAT = CharHelper.Hairdata;
			ret = Main._this.savedata.data.unlockables_hair[ind] != unlock;
			Main._this.savedata.data.unlockables_hair[ind] = unlock;
		}
		else if (index == 5)
		{
			DAT = CharHelper.BodyData;
			ret = Main._this.savedata.data.unlockables_body[ind] != unlock;
			Main._this.savedata.data.unlockables_body[ind] = unlock;
		}
		else if (index == 6)
		{
			DAT = CharHelper.ArmsData;
			ret = Main._this.savedata.data.unlockables_arms[ind] != unlock;
			Main._this.savedata.data.unlockables_arms[ind] = unlock;
		}
		else if (index == 7)
		{
			/*DAT = CharHelper.ShoesData;
			if (!Main._this.savedata.data.unlockables_shoes)
			{
				U = new Array<Bool>();
				U[0] = true;
			}*/
			
		}
		else if (index == 8)
		{
			DAT = CharHelper.EyesData;
			ret = Main._this.savedata.data.unlockables_eyes[ind] != unlock;
			Main._this.savedata.data.unlockables_eyes[ind] = unlock;
		}
		else if (index == 9)
		{
			DAT = CharHelper.MouthData;
			ret = Main._this.savedata.data.unlockables_mouth[ind] != unlock;
			Main._this.savedata.data.unlockables_mouth[ind] = unlock;
		}
		else if (index == 10)
		{
			DAT = CharHelper.ItemsData;
			new Array<Bool>();
		}
		else if (index == 11)
		{
			DAT = CharHelper.AccData;
			ret = Main._this.savedata.data.unlockables_accessory[ind] != unlock;
			Main._this.savedata.data.unlockables_accessory[ind] = unlock;
		}
		else if (index == 12)
		{
			DAT = CharHelper.BackData;
			ret = Main._this.savedata.data.unlockables_back[ind] != unlock;
			Main._this.savedata.data.unlockables_back[ind] = unlock;
		}
		else if (index == 13 || index == 14)
		{
			type = "Color";
		}
		return ret;
	}
	public static function getlist(type:String,available:Bool):Array<Int>
	{
		var D = getpart(type);
		var ret = new Array<Int>();
		var i = 0;
		var U:Array<Bool> = D.unlock;
		var data:Array<Dynamic> = D.data;
		while (i < data.length)
		{
			if ((U[i]==true)==available)
			{
				ret.push(i);
			}
			i++;
		}
		
		return ret;
	}
	public static function getpart(type:String):Dynamic
	{
		var DAT:Array<Dynamic> = null;
		var U:Array<Bool> = null;
		
		var index = partlist.indexOf(type);
		var type = "Part";
		if (index == 3)
		{
			DAT = CharHelper.HatsData;
			U = Main._this.savedata.data.unlockables_hat;
		}
		else if (index == 4)
		{
			DAT = CharHelper.Hairdata;
			U = Main._this.savedata.data.unlockables_hair;
		}
		else if (index == 5)
		{
			DAT = CharHelper.BodyData;
			U = Main._this.savedata.data.unlockables_body;
		}
		else if (index == 6)
		{
			DAT = CharHelper.ArmsData;
			U = Main._this.savedata.data.unlockables_arms;
		}
		else if (index == 7)
		{
			DAT = CharHelper.ShoesData;
			if (!Main._this.savedata.data.unlockables_shoes)
			{
				U = new Array<Bool>();
				U[13] = true;
			}
			
		}
		else if (index == 8)
		{
			DAT = CharHelper.EyesData;
			U = Main._this.savedata.data.unlockables_eyes;
		}
		else if (index == 9)
		{
			DAT = CharHelper.MouthData;
			U = Main._this.savedata.data.unlockables_mouth;
		}
		else if (index == 10)
		{
			DAT = CharHelper.ItemsData;
			U = new Array<Bool>();
		}
		else if (index == 11)
		{
			DAT = CharHelper.AccData;
			U = Main._this.savedata.data.unlockables_accessory;
		}
		else if (index == 12)
		{
			DAT = CharHelper.BackData;
			U = Main._this.savedata.data.unlockables_back;
		}
		else if (index == 13 || index == 14)
		{
			type = "Color";
		}
		var D:Dynamic = { };
		D.data = DAT;
		D.unlock = U;
		D.type = type;
		return D;
	}
	private function generatepieces()
	{
		if (generatedone)
		{
			return;
		}
		//Version#:Name:Scale:Hat:Hair:Body:Arm:Shoes:Eyes:Mouth:Item:Accessory:Back:this.HairColor
		///piececontainer.removeChildren();
		var index = customindex;
		var DAT:Array<Dynamic> = null;
		var U:Array<Bool> = null;
		var type = "Part";
		/*if (index == 3)
		{
			DAT = CharHelper.HatsData;
			U = Main._this.savedata.data.unlockables_hat;
		}
		else if (index == 4)
		{
			DAT = CharHelper.Hairdata;
			U = Main._this.savedata.data.unlockables_hair;
		}
		else if (index == 5)
		{
			DAT = CharHelper.BodyData;
			U = Main._this.savedata.data.unlockables_body;
		}
		else if (index == 6)
		{
			DAT = CharHelper.ArmsData;
			U = Main._this.savedata.data.unlockables_arms;
		}
		else if (index == 7)
		{
			DAT = CharHelper.ShoesData;
			if (!Main._this.savedata.data.unlockables_shoes)
			{
				U = new Array<Bool>();
				U[0] = true;
			}
			
		}
		else if (index == 8)
		{
			DAT = CharHelper.EyesData;
			U = Main._this.savedata.data.unlockables_eyes;
		}
		else if (index == 9)
		{
			DAT = CharHelper.MouthData;
			U = Main._this.savedata.data.unlockables_mouth;
		}
		else if (index == 10)
		{
			DAT = CharHelper.ItemsData;
			U = new Array<Bool>();
		}
		else if (index == 11)
		{
			DAT = CharHelper.AccData;
			U = Main._this.savedata.data.unlockables_accessory;
		}
		else if (index == 12)
		{
			DAT = CharHelper.BackData;
			U = Main._this.savedata.data.unlockables_back;
		}
		else if (index == 13 || index == 14)
		{
			type = "Color";
		}*/
		var D:Dynamic = getpart(custompiece);
		type = D.type;
		DAT = D.data;
		U = D.unlock;
		
		
		var DNA = "3.4:faceman:100:0:240:0:0:0:128:0:0:0:0:C0FFEE:FFF1DD";
		DNA = avatardna;
		var i = generateindex;
		var limit = generatelimit;
		//var X = 3;
		//var Y = 3;
		var X = generateX;
		var Y = generateY;
		
		var W = 76;
		var H = 76;
		DNA = changednascale(DNA, 83);
		var uncolorhair:Bool = !Main._this.savedata.data.unlockables_haircolor && index == partlist.indexOf("Hair");
		
		if (DAT != null)
		{
			piececontainer.visible = false;
			var total = DAT.length;
			var ind = getdnapart(DNA, index);
		while (i < total && limit>=0)
		{
			if (U == null || U[i])
			{
			var M = new MenuButton("", 8, "Arial", 3);
			M.sound = "";
			var data = DAT[i];
			M.manualwidth = W-2;
			M.manualheight = H - 2;
			var TD = changednapart(DNA, index, "" + i);
			if (uncolorhair)
			{
				//if you don't have hair dye then force the default color.
				TD = changednapart(TD, partlist.indexOf("Hair Color"), "" + CharHelper.Hairdata[i][6]);
					//setavatardna(changednapart(avatardna, partlist.indexOf("Hair Color"), "" + CharHelper.Hairdata[index][6]));
			}
			Main._this.stage.quality = flash.display.StageQuality.MEDIUM;
			M.setbitmapdata(CharHelper.makeCharImage("dna-" + TD,false));
			Main._this.stage.quality = flash.display.StageQuality.LOW;
			//M.setbitmapdata(AL.getBitmapData("dna-" + TD)[0]);
			M.x = X;
			M.y = Y;
			var desc = data[0];
			if ((""+i) == ind)
			{
				M.setcolors(0xFF0000, 0xFFFFFF);
				lselectedpiece = M;
				selectedpiece = M;
			}
			var ii = i;
			M.addclick( function( ev ) {
				selectedpiece = M;
				selectpiece(ii);
				setdescription(desc);
				 } 
				);
			M.update();
			piececontainer.addChild(M);
			X += W;
			if (X > 500)
			{
				X = 3;
				Y += H;
			}
			}
			i++;
			limit--;
		}
		piececontainer.visible = true;
		generatedone = i >= total;
		}
		else
		{
			if (type == "Color")
			{
				spectrum = new Sprite();
				spectrum.x = 25;
				spectrum.y = 60;
				piececontainer.addChild(spectrum);
				var B = new Bitmap(AL.GetAnimation("spectrum")[0]);
				spectrum.addChild(B);
				spectrum.buttonMode = true;
				spectrum.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
					
					var C = StringTools.hex(B.bitmapData.getPixel(Std.int(B.mouseX), Std.int(B.mouseY)),6);
					//if (index == 13)
					{
						setavatardna(changednapart(avatardna, customindex, "" + C));
						//avatardna = changednapart(avatardna, customindex, "" + C);
						//avatarpreview.setbitmapdata(AL.getBitmapData("dna-" + changednascale(avatardna, 200))[0]);
					}
				 } 
				);
				generatedone = true;
			}
			generatedone = true;
		}
		
		scrollbar.visible = (type == "Part");
		
		//if (generatedone)
		{
			updatescrollbar();
		}
		outerpiececontainer.graphics.clear();
		if (scrollbar.visible)
		{
			outerpiececontainer.graphics.beginFill(0x000000, 0.4);
			outerpiececontainer.graphics.drawRect(0, 0, outerpiececontainer.width, piececontainer.height);
			outerpiececontainer.graphics.endFill();
		}
		generateX = X;
		generateY = Y;
		generateindex = i;
		
		//generatedone = i >= total;
	}
	private function selectpiece(index:Int)
	{
		if (lselectedpiece != null)
		{
			lselectedpiece.setcolors();
		}
		selectedpiece.setcolors(0xFF0000, 0xFFFFFF);
		setavatardna(changednapart(avatardna, customindex, "" + index));
		if (!Main._this.savedata.data.unlockables_haircolor)
		{
			//if you don't have hair dye then force the default color.
			if (customindex == partlist.indexOf("Hair"))
			{
				setavatardna(changednapart(avatardna, partlist.indexOf("Hair Color"), "" + CharHelper.Hairdata[index][6]));
			}
		}
		//avatardna = changednapart(avatardna, customindex, "" + index);
		//avatarpreview.setbitmapdata(AL.getBitmapData("dna-" + changednascale(avatardna, 200))[0]);
		lselectedpiece = selectedpiece;
	}
	private function setavatardna(dna:String)
	{
		avatardna = dna;
		dnadisplay.text = dna;
		/*Main._this.stage.quality = flash.display.StageQuality.BEST;
		avatarpreview.setbitmapdata(CharHelper.makeCharImage(data,false));
		Main._this.stage.quality = flash.display.StageQuality.LOW;*/
		avatarpreview.setbitmapdata(AL.getBitmapData("dna-" + changednascale(avatardna, 200))[0]);
	}
	public function start()
	{
		var bg = new Bitmap(AL.GetAnimation("background-" + CharHelper.GetBG("Empty Room"))[0]);
		addChild(bg);
		var mirror = new Bitmap(AL.GetAnimation("mirror")[0]);
		mirror.y = 170;
		mirror.x = 160;
		addChild(mirror);
		var dresser = new Bitmap(AL.GetAnimation("dresser")[0]);
		dresser.y = 280;
		dresser.x = 410;
		addChild(dresser);
		var chest = new Bitmap(AL.GetAnimation("chest")[0]);
		chest.y = 260;
		chest.x = 650;
		addChild(chest);
		/*var window = new Bitmap(AL.GetAnimation("window")[0]);
		window.y = 200;
		window.x = 650;
		addChild(window);*/
		//background.addChild(bg);
		var filterArr:Array<flash.filters.BitmapFilter>;
		filterArr = new Array();
		var AA = new flash.filters.DropShadowFilter();
		AA.alpha = 1;
		AA.distance = 5;
		AA.alpha = 25;
		AA.color = 0;
		filterArr = new Array();
		filterArr[filters.length] = AA;
		
		
		avatarpreview = new MenuButton("");
		avatarpreview.mouseEnabled = false;
		avatarpreview.buttonMode = false;
		avatarpreview.button.buttonMode = false;
		avatarpreview.sound = "";
		avatarpreview.manualheight = 200;
		avatarpreview.manualwidth = 200;
		avatarpreview.setcolors(0x444444, 0x00BBDD);
		avatarpreview.y = 70;
		avatarpreview.x = 10;
		avatarpreview.setbitmapdata(AL.getBitmapData("dna-" + changednascale(avatardna, 200))[0]);
		avatarpreview.update();
		avatarpreview.buttonMode = false;
		addChild(avatarpreview);
		
		Nameinput = new TextField();
		Nameinput.width = 280;
		Nameinput.height = 30;
		Nameinput.maxChars = 40;
		var tmp = new TextFormat();
		tmp.font = "Arial";
		tmp.size = 22;
		Nameinput.x = 4;
		Nameinput.y = avatarpreview.y+200;
		//Nameinput.width = (512 - (Nameinput.x));
		Nameinput.width = (200);
		/*if (playername == null || playername == "")
		{
			playername = "PlayerName";
		}*/
		//Nameinput.text = playername;
		Nameinput.text = CharHelper.getdnapart(avatardna, 1);
		Nameinput.border = true;
		Nameinput.background = true;
		Nameinput.setTextFormat(tmp);
		Nameinput.wordWrap = true;
		Nameinput.type = TextFieldType.INPUT;
		Nameinput.borderColor = 0x0000FF;
		Nameinput.backgroundColor = 0xFFFFFF;
		Nameinput.addEventListener( Event.CHANGE, function( ev ) {
				//selectcustomization("Eyes");
				setavatardna(changednapart(avatardna, 1, Nameinput.text));
				 } 
				);
		addChild(Nameinput);
		Description = new TextField();
		Description.x = Nameinput.x;
		Description.y = Nameinput.y + 32+32;
		Description.text = "Ability:" + Player.getname(soul);
		Description.mouseEnabled = false;
		Description.textColor = 0xFFFFFF;
		Description.scaleX = 2;
		Description.scaleY = 2;
		Description.filters = filterArr;
		
		addChild(Description);
		dnadisplay = new TextField();
		dnadisplay.x = Nameinput.x;
		dnadisplay.y = Nameinput.y + 32;
		dnadisplay.text = "Ability:" + Player.getname(soul);
		//dnadisplay.mouseEnabled = false;
		dnadisplay.textColor = 0xFFFFFF;
		dnadisplay.scaleX = 2;
		dnadisplay.scaleY = 2;
		dnadisplay.filters = filterArr;
		dnadisplay.height = 32;
		dnadisplay.width = 100;
		addChild(dnadisplay);
		custompages = new Array<Sprite>();
		var P:Sprite = new Sprite();
		custompages.push(P);
		var size = 44;
		var X = 375.0;
		var Y = 30.0;
		var W = 12;
		var H = 22;
		//var B = new MenuButton("Eyes", size,"Arial",5,0x1155CC,0x0033AA);
		var innercolor = 0x2277EE;
		var outercolor = 0x1155CC;
		var B = new MenuButton("Eyes", size,"Arial",5,innercolor,outercolor);
		//X += B.textfield.textWidth+W;
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Eyes");
				 } 
				);
		B = new MenuButton("Mouth",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Mouth");
				 } 
				);
		B = new MenuButton("Hair",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Hair");
				 } 
				);
		B = new MenuButton("Hat",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Hat");
				 } 
				);
		B = new MenuButton("Accessory",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Accessory");
				 } 
				);
		B = new MenuButton("Body",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Body");
				 } 
				);
		X += 250;
		Y = 30;
		B = new MenuButton("Arms",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Arms");
				 } 
				);
		B = new MenuButton("Shoes",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Shoes");
				 } 
				);
		B = new MenuButton("Back",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Back");
				 } 
				);
		/*B = new MenuButton("Prop",size);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.addclick( function( ev ) {
				selectcustomization("Prop");
				 } 
				);*/
		B = new MenuButton("Hair Color",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.sound = "";
		B.addclick( function( ev ) {
			if (Main._this.savedata.data.unlockables_haircolor)
				{
					SoundManager.Play("click");
					selectcustomization("Hair Color");
				}
				else
				{
					SoundManager.Play("bonk");
				}
				
				 } 
				);
		if (!Main._this.savedata.data.unlockables_haircolor)
		{
			//B.setcolors(0xAAAAAA, 0x888888);
			B.changecolorscheme(1, 0xAAAAAA, 0x888888);
			B.usecolorscheme(1);
		}
		B = new MenuButton("Skin Color",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		
		//P.addChild(B);
		//Y += B.textfield.textHeight + H;
		B.update();
		B.addclick( function( ev ) {
				selectcustomization("Skin Color");
				 } 
				);
		B = new MenuButton("Ability",size,"Arial",5,innercolor,outercolor);
		B.x += X;
		B.y = Y;
		P.addChild(B);
		B.update();
		Y += B.textfield.textHeight + H;
		B.sound = "";
		B.addclick( function( ev ) {
				if (Main._this.savedata.data.avatarabilities)
				{
					SoundManager.Play("click");
					selectcustomization("Ability");
				}
				else
				{
					SoundManager.Play("bonk");
				}
				 } 
				);
		if (!Main._this.savedata.data.avatarabilities)
		{
			//B.setcolors(0xAAAAAA, 0x888888);
			B.changecolorscheme(1, 0xAAAAAA, 0x888888);
			B.usecolorscheme(1);
		}
		addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				scrolling = false;
				 } 
				);
		addChild(P);
		P = new Sprite();
		P.visible = false;
		B = new MenuButton("Back to selection", size);
		B.sound = "cancel";
		B.x = 450;
		B.y = 10;
		B.addclick( function( ev ) {
				custompages[1].visible = false;
				custompages[0].visible = true;
				 } 
				);
		P.addChild(B);
		customdisplay = new TextField();
		customdisplay.x = -4;
		customdisplay.y = -8;
		customdisplay.filters = filterArr;
		P.addChild(customdisplay);
		
		outerpiececontainer = new Sprite();
		piececontainer = new Sprite();
		outerpiececontainer.x = 220;
		outerpiececontainer.y = 70;
		outerpiececontainer.addChild(piececontainer);
		P.addChild(outerpiececontainer);
		outerpiececontainer.scrollRect = new Rectangle(0, 0, 550, 450);
		scrollbar = new Sprite();
		scrollbar.buttonMode = true;
		scrollbar.x = 750;
		scrollbar.y = outerpiececontainer.y;
		scrollbar.addEventListener( MouseEvent.MOUSE_DOWN, function( ev ) {
			scrolling = true;
		});
		outerpiececontainer.addEventListener( MouseEvent.MOUSE_WHEEL, function( evt ) {
			if (scrollbar.visible)
			{
			var Y = Math.min(Math.max(outerpiececontainer.scrollRect.y-(evt.delta*76), 0), piececontainer.height - outerpiececontainer.scrollRect.height);
					outerpiececontainer.scrollRect = new Rectangle(0, Y, outerpiececontainer.scrollRect.width, outerpiececontainer.scrollRect.height);
					updatescrollbar();
			}
		});
		scrollbar.addEventListener( MouseEvent.MOUSE_WHEEL, function( evt ) {
			if (scrollbar.visible)
			{
			var Y = Math.min(Math.max(outerpiececontainer.scrollRect.y-(evt.delta*76), 0), piececontainer.height - outerpiececontainer.scrollRect.height);
					outerpiececontainer.scrollRect = new Rectangle(0, Y, outerpiececontainer.scrollRect.width, outerpiececontainer.scrollRect.height);
					updatescrollbar();
			}
		});
		scrollbar.addEventListener( MouseEvent.MOUSE_MOVE, function( ev ) {
					//var Y = scrollbar.mouseY / piececontainer.height;
					if (scrollbar.visible && scrolling)
					{
					var Y = mouseY - scrollbar.y;
					Y -= 40;
					Y *= (piececontainer.height / 450);
					//Y -= (outerpiececontainer.scrollRect.height - (piececontainer.height / 6))/2;
					Y = Math.min(Math.max(Y, 0), piececontainer.height - outerpiececontainer.scrollRect.height);
					//var Y = Math.min(Math.max((scrollbar.mouseY - 20)*7, 0), piececontainer.height - outerpiececontainer.scrollRect.height);
					outerpiececontainer.scrollRect = new Rectangle(0, Y, outerpiececontainer.scrollRect.width, outerpiececontainer.scrollRect.height);
					updatescrollbar();
					}
				 } 
				);
		updatescrollbar();
		P.addChild(scrollbar);
		custompages.push(P);
		addChild(P);
		
		P = new Sprite();
		P.visible = false;
		dimmer = new Sprite();
		dimmer.graphics.beginFill(0, 0.4);
		dimmer.graphics.drawRect(0, 0, 800, 600);
		dimmer.graphics.endFill();
		P.addChild(dimmer);
		B = new MenuButton("Cancel", size);
		B.sound = "cancel";
		B.x = 620;
		B.y = 100;
		B.addclick( function( ev ) {
				custompages[2].visible = false;
				custompages[0].visible = true;
				if (view != null)
				{
					view.buttons.visible = true;
				}
				 } 
				);
		P.addChild(B);
		B = new MenuButton("Select", size);
		B.sound = "ok";
		B.x = 620;
		B.y = 170;
		B.addclick( function( ev ) {
				soul = soulselect.selected;
				Description.text = "Ability:" + Player.getname(soul);
				custompages[2].visible = false;
				custompages[0].visible = true;
				if (view != null)
				{
					view.buttons.visible = true;
				}
				 } 
				);
		P.addChild(B);
		soulselect = new CharacterSelect(soul);
		soulselect.checkgamemode = false;
		soulselect.ButtonDisplay.x = 130;
		//soulselect.y = -30;
		//soulselect.x = 100;
		P.addChild(soulselect);
		custompages.push(P);
		addChild(P);
		
		/*avatarpreview = new Bitmap(AL.getBitmapData("dna-" + changednascale(avatardna,200))[0]);
		avatarpreview.y = 10;
		avatarpreview.x = 30;
		AP.addChild(avatarpreview);*/
		setavatardna(avatardna);
	}
	public function update()
	{
		if (!generatedone)
		{
			generatepieces();
		}
	}
	private function updatescrollbar()
	{
		var S = scrollbar;
		var G = S.graphics;
		var HH = piececontainer.height;
		if (HH == 0)
		{
			return;
		}
		else if (HH < outerpiececontainer.scrollRect.height)
		{
			scrollbar.visible = false;
			return;
		}
		scrollbar.visible = true;
		/*if (HH < 1)
		{
			if (HH > 0)
			{
				
			}
			else
			{
				HH = 0;
			}
		}
		else
		{
			HH = 1;
		}*/
		var H = outerpiececontainer.scrollRect.height / HH;
		var Y = outerpiececontainer.scrollRect.y / HH;
		G.clear();
		G.beginFill(0xAAAAAA);
		//G.drawRect(0, 0, 32, outerpiececontainer.scrollRect.height);
		G.drawRoundRect(0, 0, 32, outerpiececontainer.scrollRect.height, 30);
		G.endFill();
		G.beginFill(0xFFFFFF);
		G.drawRoundRect(0, Y * outerpiececontainer.scrollRect.height, 32, H * outerpiececontainer.scrollRect.height,30);
		G.endFill();
		
	}
}