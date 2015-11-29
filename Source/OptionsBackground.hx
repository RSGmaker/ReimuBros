package;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class OptionsBackground extends Sprite
{
	public var AL:Animationloader;
	public var BG:Bitmap;
	public var entities:Array<MiniEntity>;
	public var timetospawn:Int;
	public var backlayer:Sprite;
	
	public function new() 
	{
		super();
		AL = Main._this.AL;
		var str = "background-" + CharHelper.GetBG("Computer Grid");
		//var bd = Assets.getBitmapData (str);
		var bd = AL.GetAnimation(str)[0];
		BG = new Bitmap(bd);
		BG.alpha = 0.4;
		addChild(BG);
		entities = new Array<MiniEntity>();
		backlayer = new Sprite();
		addChild(backlayer);
		scrollRect = new Rectangle(0, 0, 800, 600);
		
		var i = 0;
		while (i < 450)
		{
			//this_onEnterFrame();
			update();
			i++;
		}
	}
	
	public function update()
	{
		var i = 0;
			while (i < entities.length)
			{
				entities[i].update();
				if (!entities[i].alive/* || entities[i].charname == selected*/)
				{
					var E = entities[i];
					entities.remove(E);
					backlayer.removeChild(E);
					i--;
				}
				i++;
			}
			timetospawn -= 1;
			if (timetospawn < 1)
			{
				//var ind = Math.floor(Player.characters.length * Math.random());
				//var C = Player.characters[ind];
				var L = ["red_fairy", "gold_fairy", "green_fairy", "blue_fairy"];
				var C = L[Std.int(Math.random() * L.length)];
				var j = 0;
				/*while (j < entities.length)
				{
					//check to see if this choice would be a duplicate
					if (entities[j].charname == C)
					{
						//if so lets not add it.
						C = "";
						j = entities.length;
					}
					j++;
				}*/
				if (C!= ""/* && C != selected && Main._this.savedata.data.unlock[ind]*/)
				{
					var E = null;
					//var X = -1;
					var X = -100;
					//determines how far down they are and adjusts their size for better pseudo 3d effect
					var depth = Math.random();
					var CC = C;
					//if (Math.random() < 0.5)
					if (Math.random() < 0.35)
					{
						X = 801;
						CC = C + "F";
					}
					//E = new MiniEntity( X, 124 + (110 * depth), AL.GetAnimation(CC)[0], 0.5 + (Math.random() * 2), false, 0);
					//E = new MiniEntity( X, 124 + (150 * depth), AL.GetAnimation(CC)[0], 0.65 + (Math.random() * 2.5), false, 0);
					E = new MiniEntity( X, 124 + (150 * depth), AL.GetAnimation(CC)[0], 1.2 + (Math.random() * 2.5), false, 0);
					E.charname = C;
					E.scaleX += (depth * 0.4);
					E.scaleY = E.scaleX;
					E.bounce = true;
					//if (Math.random() > 0.5)
					if (Math.random() > 0.30)
					{
						L = ["Point","Point","balloon","balloon", "1up", "myon", "block", "emptyblock", "POW", "table","trophy","teacup","teacup","teacup","questionblock"];
						//L = L.concat(EntityItem.getitemlist("valuable"));
						L = L.concat(L);
						L = L.concat(["Blackufo","Redufo", "Blueufo", "Greenufo","notepad"]);
						L = L.concat(L);
						L = L.concat(["truck", "icyblock", "Gap", "skull", "charblock", "keystone"]);
						var choice = L[Std.int(Math.random() * L.length)];
						var XX = 0;
						var YY = 0;
						var ind = 0;
						var scl:Float = 1;
						var bd = AL.GetAnimation(choice);
						if (choice == "teacup" || choice == "notepad")
						{
							YY -= 12;
							scl = 1.3;
						}
						if (choice == "Gap")
						{
							XX -= 5;
						}
						if (choice == "table")
						{
							YY += 3;
						}
						if (choice == "balloon")
						{
							ind = Std.int(Math.random() * bd.length);
						}
						if (choice == "1up")
						{
							if (Math.random() > 0.1)
							{
								//scl = 0.5;
								scl = 0.7;
								YY -= 4;
							}
						}
						if (choice == "Redufo" || choice == "Blueufo" || choice == "Greenufo")
						{
							if (Math.random() > 0.1)
							{
								//scl = 0.5;
								scl = 0.5;
								YY -= 4;
							}
						}
						if (bd != null && bd.length > 0)
						{
							var O = new Bitmap(bd[ind]);
							//O.y = 22;
							//O.x = 10;
							
							O.scaleX = 0.65*scl;
							O.scaleY = O.scaleX;
							O.y = -O.height;
							O.y += 50;
							O.x = 13;
							O.x += XX;
							O.y += YY;
							E.addChild(O);
						}
					}
					if (Math.random() > 0.5)
					{
						//E.behavior = Math.floor(4 * Math.random());
						E.behavior = Math.floor(5 * Math.random());
						if (E.behavior == 2)
						{
							E.behavior = 0;
						}
					}
					E.y += 250;
					entities.push(E);
					//entities[entities.length] = E;
					if (E != null)
					{
						backlayer.removeChildren(1);
						entities.sort(sortentities);
						var i = 0;
						while (i < entities.length)
						{
							backlayer.addChild(entities[i]);
							i++;
						}
					}
				}
				//timetospawn = Math.floor(30 + (150 * Math.random()));
				timetospawn = Math.floor(20 + (90 * Math.random()));
			}
	}
	
	public function sortentities(A:MiniEntity, B:MiniEntity):Int
	{
		/*if (A.scaleX > 1.3 && !(B.scaleX > 1.3))
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
		}*/
		if (A.rotation != B.rotation)
		{
			if (A.rotation == 0)
			{
				return 1;
			}
			if (B.rotation == 0)
			{
				return -1;
			}
		}
		if (A.image.getBounds(this).bottom < B.getBounds(this).bottom)
		{
			return -1;
		}
		if (A.image.getBounds(this).bottom > B.getBounds(this).bottom)
		{
			return 1;
		}
		
		return 0;
	}
}