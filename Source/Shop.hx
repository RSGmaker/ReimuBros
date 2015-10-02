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
class Shop extends Sprite
{
	public var AL:Animationloader;
	public var DNA:String = "3.39:faceman:100:0:240:0:0:0:128:0:0:0:0:C0FFEE";
	public var shopkeeperDNA:String;
	public var shopkeeper:Sprite;
	public var shopkeeperimage:Bitmap;
	public var inventorypanel:Sprite;
	public var preview:MenuButton;
	public var purchase:MenuButton;
	public var speechbubble:Sprite;
	public var speechtext:TextField;
	public var say:String;
	public var talkdelay:Int;
	public var maxtalkdelay = 0;
	public var tformat:TextFormat;
	public var moneyicon:Bitmap;
	public var moneycounter:TextField;
	public var inventory:Array<Dynamic>;
	
	public var selectedpiece:MenuButton;
	public var lselectedpiece:MenuButton;
	public var selectedindex:Int = -1;
	public var idletalkdelay:Int = 1500;
	public var idletalkmaxdelay:Int = 1500;
	//public var idletalk:Array<String> = ["Click any item you'd like and click \"purchase\".","I get new items in stock each time you complete enough levels.","Purchasing items also helps me get new items in stock."];
	public var idletalk:Array<String> = ["Choose any item you'd like and [Purchase] it.", "Be sure to check back later, I may have some new items in stock."];
	public var rares:Array<Dynamic>;
	public function new() 
	{
		super();
		AL = Main._this.AL;
	}
	public function initrares()
	{
		rares = new Array<Dynamic>();
		//index,shopkeepertext,image,price,availability,rarity
		rares.push([rares.length, "Would you be interested in this: \"Ability Copier\"?","satori", 100,Main._this.savedata.data.avatarabilities!=true,50]);
	}
	
	public function dotick()
	{
		//var T = ["Hat", "Hair", "Body", "Arms", "Eyes", "Mouth", "Prop", "Accessory", "Back",other];
		//var type = 
		if (inventory.length > 39)
		{
			var R = Math.floor(Math.random() * inventory.length);
			inventory.remove(inventory[R]);
		}
		var S:Array<String> = new Array<String>();
		S.push("Body");
		S.push("Hair");
		S.push("Arms");
		S.push("Mouth");
		S.push("Eyes");
		S.push("Accessory");
		S.push("Hat");
		S.push("Back");
		var D:Dynamic = AvatarEditor.pickpart(S);
		//if (Math.random() > 0)
		{
			var T = rares[Std.int(Math.floor(Math.random() * rares.length))];
			var rarity = T[5];
			var ok:Bool = Math.floor(Math.random() * rarity) < 1;
			var ok2:Dynamic = T[4];
			if (ok2 && ok)
			{
				D = { };
				D.type = "Rare";
				var Cast:Dynamic = T[0];
				var I:Int = Cast;
				D.index = I;
			}
		}
		if (D != null)
		{
			inventory.push(D);
		}
		Main._this.savedata.data.shop_inventory = inventory;
	}
	public function getprice(item:Dynamic):Int
	{
		//public static var partlist:Array<String> = ["Version", "Name", "Scale", "Hat", "Hair", "Body", "Arms", "Shoes", "Eyes", "Mouth", "Prop", "Accessory", "Back", "Hair Color", "Skin Color"];
		var parttype:String = item.type;
		if (parttype == "Hat")
		{
			return 15;
		}
		if (parttype == "Accessory" || parttype == "Body")
		{
			return 12;
		}
		if (parttype == "Back" || parttype=="Prop" || parttype == "Hair")
		{
			return 9;
		}
		if (parttype == "Eyes" || parttype == "Mouth" || parttype == "Arms")
		{
			return 6;
		}
		if (parttype == "Rare")
		{
			return rares[item.index][3];
		}
		return 0;
	}
	public function cleaninventory()
	{
		var i = 0;
		while (i < inventory.length)
		{
			var data = inventory[i];
			var ind = AvatarEditor.partlist.indexOf(data.type);
			var part = data.index;
			var price = getprice(data);
			var unlock = AvatarEditor.getpart(data.type).unlock;
			if (unlock != null)
			{
				if (unlock[part])
				{
					//we already have this so remove it
					inventory.remove(data);
					Main._this.savedata.data.shop_inventory = inventory;
					i--;
				}
				else
				{
					
				}
			}
			else
			{
				/*var j = i + 1;
					while (j < inventory.length)
					{
						if (data.type == inventory[j].type && data.index == inventory[j].index)
						{
							//this is already listed so lets remove it
							j = inventory.length+1;
							inventory.remove(data);
							Main._this.savedata.data.shop_inventory = inventory;
							i--;
						}
						j++;
					}*/
			}
			var j = i + 1;
					while (j < inventory.length)
					{
						if (data.type == inventory[j].type && data.index == inventory[j].index)
						{
							//this is already listed so lets remove it
							j = inventory.length+1;
							inventory.remove(data);
							Main._this.savedata.data.shop_inventory = inventory;
							i--;
						}
						j++;
					}
			i++;
		}
	}
	public function refreshinventory()
	{
		inventorypanel.removeChildren();
		cleaninventory();
		var i = 0;
		var X = 0;
		var Y = 0;
		var W = 76;
		var H = 76;
		var seperator = 16;
		
		while (i < inventory.length)
		{
			var data = inventory[i];
			var ind = 0;
			
			var part:Int = data.index;
			var price = getprice(data);
			var img = "";
			if (data.type != "Rare")
			{
				//price = getprice(data.type);
				ind = AvatarEditor.partlist.indexOf(data.type);
				img = "dna-" + CharHelper.changednapart(DNA, ind, "" + part);
			}
			else
			{
				if (data.type == "Rare")
				{
					//price = rares[part][3];
					img = rares[Std.int(part)][2];
				}
			}
			var M = new MenuButton();
			M.manualwidth = W-2;
			M.manualheight = H - 2;
			M.setbitmapdata(AL.getBitmapData(img)[0]);
			M.x = X;
			M.y = Y;
			M.update();
			if (data.type == "Rare")
			{
				M.setcolors(0xCCCC11, 0xAAAA00);
			}
			var B = new Bitmap(moneyicon.bitmapData);
			B.scaleX = 0.35;
			B.scaleY = 0.35;
			B.x = 11;
			B.y = H-17;
			M.addChild(B);
			var T = new TextField();
			T.textColor = 0xFFFFFF;
			T.text = "" + price;
			T.width = T.textWidth + 8;
			T.height = T.textHeight + 8;
			T.scaleX = 2.5;
			T.scaleY = 2.5;
			T.x = B.x + 12;
			T.y = B.y-8;
			T.mouseEnabled = false;
			M.addChild(T);
			inventorypanel.addChild(M);
			
			var ii = i;
			M.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				selectedpiece = M;
				selectpiece(ii);
				//setdescription(desc);
				 } 
				);
			
			
			i++;
			X += W;
			//if (X + W > 600)
			if (X + W > 800)
			{
				X = 0;
				Y += H+seperator;
			}
		}
	}
	private function selectpiece(index:Int)
	{
		if (lselectedpiece != null)
		{
			lselectedpiece.setcolors();
		}
		selectedpiece.setcolors(0xFF0000, 0xFFFFFF);
		selectedindex = index;
		var data = inventory[index];
		var ind = AvatarEditor.partlist.indexOf(data.type);
		var part = data.index;
		var price = getprice(data);
		var name = "";
		if (data.type != "Rare")
		{
			name = AvatarEditor.getpart(data.type).data[part][0];
			talk("Do you want the " + data.type.toLowerCase()+": \n\"" + name+"\"?\nIt's yours for only "+price+" gems.");
		}
		else
		{
			talk(rares[part][1]);
		}
		
		
		
		//setavatardna(changednapart(avatardna, customindex, "" + index));
		lselectedpiece = selectedpiece;
	}
	public function purchaseitem()
	{
		if (inventory.length < 1)
		{
			return;
		}
		if (selectedindex >= 0)
		{
			var data = inventory[selectedindex];
			var ind = AvatarEditor.partlist.indexOf(data.type);
			var part = data.index;
			var price = getprice(data);
			var DAT = AvatarEditor.getpart(data.type);
			
			if (Main._this.savedata.data.money >= price)
			{
				if (DAT.unlock != null)
				{
					var name = DAT.data[part][0];
					DAT.unlock[part] = true;
					Main._this.savedata.data.money = Main._this.savedata.data.money - price;
					moneycounter.text = ":" + Main._this.savedata.data.money;
					
					Main._this.savedata.data.shop_ticks = Main._this.savedata.data.shop_ticks + 0.5;
					talk("Thank you for your purchase.");
					SoundManager.Play("cash");
					refreshinventory();
					selectedindex = -1;
				}
				else
				{
					if (data.type == "Rare")
					{
						if (data.index == 0)
						{
							//ability copier
							Main._this.savedata.data.avatarabilities = true;
							Main._this.savedata.data.money = Main._this.savedata.data.money - price;
							moneycounter.text = ":" + Main._this.savedata.data.money;
							inventory.remove(inventory[selectedindex]);
							Main._this.savedata.data.shop_inventory = inventory;
					
							Main._this.savedata.data.shop_ticks = Main._this.savedata.data.shop_ticks + 1;
							talk("Thank you for your purchase.");
							SoundManager.Play("cash");
							refreshinventory();
							selectedindex = -1;
						}
					}
					else
					{
						talk("Not implemented...");
					}
				}
				
			}
			else
			{
				talk("You don't have enough gems.");
				var dna = shopkeeperDNA;
				dna = CharHelper.changednapart(dna, AvatarEditor.partlist.indexOf("Eyes"), "93");
				dna = CharHelper.changednapart(dna, AvatarEditor.partlist.indexOf("Mouth"), "2");
				shopkeeperimage.bitmapData = AL.getBitmapData(dna)[0];
				//return ret;
			}
		}
		else
		{
			talk(idletalk[0]);
		}
		//selectedindex = -1;
	}
	public static function randomtalkingface(dna:String):String
	{
		var eyes:Array<Int> = [1, 2, 6, 11, 12, 94/*, 96*//*, 114*/];
		var mouths:Array<Int> = [1, 2, 3, 4, 7, 8, 10, 11, 12, 51, 54, 71];
		var ret = dna;
		var eye:String = "" + (eyes[Std.int(Math.floor(Math.random() * eyes.length))]-1);
		var mouth:String = "" + mouths[Std.int(Math.floor(Math.random() * mouths.length))];
		ret = CharHelper.changednapart(ret, AvatarEditor.partlist.indexOf("Eyes"), eye);
		ret = CharHelper.changednapart(ret, AvatarEditor.partlist.indexOf("Mouth"), mouth);
		return ret;
	}
	public function start()
	{
		if (rares == null)
		{
			initrares();
		}
		inventory = Main._this.savedata.data.shop_inventory;
		var i = 0;
		shopkeeperDNA = CharHelper.changednascale(CharHelper.getCharPreset("Alice"),130);
		var bg = new Bitmap(AL.GetAnimation("background-" + CharHelper.GetBG("Kourindou"))[0]);
		addChild(bg);
		inventorypanel = new Sprite();
		inventorypanel.x = 10;
		inventorypanel.y = 106;
		addChild(inventorypanel);
		/*preview = new MenuButton("",1,"Arial",4,0,1);
		preview.manualheight = 150;
		preview.manualwidth = 200;
		preview.x = 600;
		preview.y = 10;
		
		preview.update();
		preview.button.alpha = 0.6;
		preview.buttonMode = false;
		addChild(preview);*/
		purchase = new MenuButton("Purchase");
		purchase.x = 600;
		//purchase.y = 160;
		purchase.y = 10;
		purchase.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				purchaseitem();
				//setdescription(desc);
				 } 
				);
		addChild(purchase);
		shopkeeper = new Sprite();
		shopkeeperimage = new Bitmap(AL.getBitmapData(CharHelper.changednapart(shopkeeperDNA, 9, "1"))[0]);
		shopkeeperimage.x = -(shopkeeperimage.width / 2);
		shopkeeperimage.y = -(shopkeeperimage.height / 2);
		shopkeeper.addChild(shopkeeperimage);
		shopkeeper.x = 50;
		shopkeeper.y = 50;
		addChild(shopkeeper);
		speechbubble = new Sprite();
		var G = speechbubble.graphics;
		G.beginFill(0xFFFFFF);
		G.drawRoundRect(16, 0, 300, 75, 50, 60);
		G.endFill();
		G.beginFill(0xFFFFFF);
		G.moveTo(0, 36);
		G.curveTo(12, 36, 36, 5);
		//G.curveTo(36, 30, 10, 50);
		//G.lineTo(36,30);
		G.lineTo(36,54);
		G.lineTo(0, 36);
		G.endFill();
		
		var filterArr:Array<flash.filters.BitmapFilter> = new Array<flash.filters.BitmapFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 10;
		AB.blurY = 10;
		AB.color = 0x000000;
		AB.strength = 5;
		filterArr[filterArr.length] = AB;
		speechbubble.filters = filterArr;
		speechtext = new TextField();
		speechtext.x = 26;
		speechtext.y = 2;
		speechtext.thickness = 10;
		
		//speechtext.text = "Welcome to my shop!";
		//say = "Welcome to my shop!";
		talk("Welcome to my shop!");
		speechtext.width = 280;
		speechtext.height = 75;
		speechtext.wordWrap = true;
		speechtext.mouseEnabled = false;
		
		speechbubble.x = 80;
		speechbubble.y = 15;
		speechbubble.addChild(speechtext);
		addChild(speechbubble);
		tformat = new TextFormat();
		tformat.size = 20;
		
		moneyicon = new Bitmap(AL.getBitmapData("money")[0]);
		moneyicon.x = 400;
		moneyicon.y = 7;
		
		addChild(moneyicon);
		moneycounter = new TextField();
		moneycounter.scaleX = 4;
		moneycounter.scaleY = 4;
		moneycounter.x = moneyicon.x + 25;
		moneycounter.y = moneyicon.y;
		moneycounter.mouseEnabled = false;
		moneycounter.text = ":" + Main._this.savedata.data.money;
		
		filterArr = new Array<flash.filters.BitmapFilter>();
		AB = new flash.filters.GlowFilter();
		AB.blurX = 10;
		AB.blurY = 10;
		AB.color = 0x000000;
		AB.strength = 5;
		filterArr[filterArr.length] = AB;
		speechbubble.filters = filterArr;
		
		AB = new flash.filters.GlowFilter();
		AB.blurX = 25;
		AB.blurY = 25;
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
		moneycounter.textColor = 0xFFFFFF;
		moneycounter.filters = filterArr;
		addChild(moneycounter);
		
		var f = Math.min(Main._this.savedata.data.shop_ticks, 40);
		i = Std.int(Math.floor(f));
		while (i >= 1)
		{
			dotick();
			i-=1;
		}
		Main._this.savedata.data.shop_ticks = Main._this.savedata.data.shop_ticks - Math.floor(Main._this.savedata.data.shop_ticks);
		refreshinventory();
		if (inventory.length < 1)
		{
			talk("Welcome, I'm sorry but I'm out of stock right now.");
		}
		
		if (Main._this.DEBUG)
		{
			var B:MenuButton = new MenuButton("Cheat:Money");
			B.x = 600;
			B.y = 400;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				Main._this.savedata.data.money = Main._this.savedata.data.money + 10;
				moneycounter.text = ":" + Main._this.savedata.data.money;
				//setdescription(desc);
				 } 
				);
			addChild(B);
			var B:MenuButton = new MenuButton("Cheat:Tick");
			B.x = 600;
			B.y = 300;
			B.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
				dotick();
				refreshinventory();
				//setdescription(desc);
				 } 
				);
			addChild(B);
		}
	}
	public function talk(text:String)
	{
		speechtext.text = "";
		say = text;
		talkdelay = 10;
		
		var dna = randomtalkingface(shopkeeperDNA);
		shopkeeperimage.bitmapData = AL.getBitmapData(dna)[0];
		idletalkdelay = idletalkmaxdelay;
	}
	public function update()
	{
		if (talkdelay < 1)
		{
			if (say != speechtext.text)
			{
				speechtext.text = say.substr(0, speechtext.text.length + 1);
				speechtext.setTextFormat(tformat);
				talkdelay = maxtalkdelay;
			}
		}
		else
		{
			talkdelay--;
		}
		if (inventory.length > 0)
		{
		if (idletalkdelay < 1)
		{
			var T = idletalk[Std.int(Math.floor(Math.random() * idletalk.length))];
			if (speechtext.text != T)
			{
				talk(T);
				idletalkdelay = idletalkmaxdelay;
			}
		}
		else
		{
			idletalkdelay--;
		}
		}
	}
	
}