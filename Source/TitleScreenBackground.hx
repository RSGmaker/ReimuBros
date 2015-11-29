package;
import openfl.display.PixelSnapping;
import openfl.display.Sprite;
import openfl.display.Bitmap;

/**
 * ...
 * @author RSGmaker
 */
class TitleScreenBackground extends Sprite
{
	public var blocks:Array<Bitmap>;
	public var objects:Array<Bitmap>;
	public var AL:Animationloader;
	public var Background:Bitmap;
	public var Background2:Bitmap;
	
	//public var BGS:Array<Int> = [CharHelper.GetBG("Moriya Shrine Room"), CharHelper.GetBG("Clocktower"), CharHelper.GetBG("The Moon"), CharHelper.GetBG("Underground Cave"), CharHelper.GetBG("Murasa's Ship (2)"), CharHelper.GetBG("Eientei Outside")];
	public var BGS:Array < String> = [];
	public var OBJ:Array<String> = ["Point", "1up", "bomb", "POW", "myon", "trophy", "balloon"];
	public var BGtimer:Int;
	public var frame:Int;
	public function new() 
	{
		AL = Main._this.AL;
		super();
	}
	public function start()
	{
		BGS = BGS.concat(["Reimu's Room", "Reimu's Door Open", "Hakurei Shrine Door", "Hakurei Shrine (IaMP)", "Shrine Tori"]);
		BGS = BGS.concat(["Dirt Road", "SDM gate", "SDM Balcony", "Clocktower", "Clocktower (Sunset)"]);
		BGS = BGS.concat(["Forest Night 2","Some Mountain","Night Mountain","The Moon","The Moon"]);
		BGS = BGS.concat(["Yukari's Gap","Crater","Crater","Underground Mine","Underground Cave"]);
		BGS = BGS.concat(["Mountain Sunset", "Mountain Sunset", "Palanquin Ship", "Murasa's Ship", "Murasa's Ship (2)"]);
		BGS = BGS.concat(["Open Field","Bamboo Forest","Eientei Outside","Eientei Courtyard","Eientei"]);
		blocks = new Array<Bitmap>();
		objects = new Array<Bitmap>();
		Background = new Bitmap();
		Background2 = new Bitmap();
		randomizebackground();
		Background2.bitmapData = AL.GetAnimation("background-" + CharHelper.GetBG("Hakurei Shrine (Border)"))[0];
		//Background2 = new Bitmap(AL.GetAnimation("background-" + BGS[Std.int(BGS.length * Math.random())];
		//Background2.alpha = 0;
		addChild(Background);
		addChild(Background2);
		Background2.alpha = 1;
		spawnplatform(600 - 32);
		spawnplatform(600 - 192);
		spawnplatform(600 - 352);
		spawnplatform(600 - 512);
		
		setformation();
		
		var i = 0;
		while (i < blocks.length)
		{
			var B = blocks[i];
			if (B.x<-32 || B.x>800)
			{
				B.visible = false;
			}
			i++;
		}
		i = 0;
		while (i < 25)
		{
			OBJ.push(OBJ[0]);
			i++;
		}
		
		BGtimer = 16*30;
	}
	public function randomizebackground()
	{
		Background.bitmapData = Background2.bitmapData;
		//Background2.bitmapData = AL.GetAnimation("background-" + BGS[Std.int(BGS.length * Math.random())])[0];
		//Background2.bitmapData = AL.GetAnimation("background-" + Std.int(218 * Math.random()))[0];
		Background2.bitmapData = AL.GetAnimation("background-" + CharHelper.GetBG(BGS[Std.int(BGS.length * Math.random())]))[0];
		Background2.alpha = 0;
		BGtimer = 250 + Std.int(Math.random() * 750);
	}
	public function update()
	{
		Background2.alpha += 0.01;
		var i = 0;
		frame++;
		//if (frame & 1 > 0)
		{
		while (i < blocks.length)
		{
			var B = blocks[i];
			if (B.visible)
			{
			B.y -= 0.25;
			//B.y -= 0.5;
			if (B.y <= -32)
			{
				B.y += 632;
			}
			}
			i++;
		}
		}
		BGtimer--;
		if (BGtimer <= 0)
		{
			randomizebackground();
		}
		//if (Math.random() < 0.03)
		if (Math.random() < 0.04)
		{
			var B = new Bitmap(AL.GetAnimation(OBJ[Std.int(OBJ.length * Math.random())])[0]);
			B.y = -32;
			B.x = (780 * Math.random());
			addChild(B);
			objects.push(B);
		}
		i = 0;
		while (i < objects.length)
		{
			var B = objects[i];
			B.y += 4;
			if (B.y > 600)
			{
				objects.remove(B);
				removeChild(B);
				i--;
			}
			i++;
		}
	}
	
	public function spawnplatform(Y:Float)
	{
		var xx = 0;
		xx -= 128 + 128;
		var BP = AL.GetAnimation("block")[0];
		var L = new Array<Bitmap>();
		
		xx = 0;
		//while (xx < 928+128)
		while (xx < 800)
		{
			var block = new Bitmap(BP,PixelSnapping.NEVER);
			block.x = xx;
			block.y = Y;
			/*block.solid = true;
			//AddObject(block);
			L[L.length] = block;*/
			blocks.push(block);
			addChild(block);
			xx += 32;
		}
		/*xx = 0;
		while (xx < L.length)
		{
			AddObject(L[xx],0);
			xx++;
		}*/
	}
	public function resetblocks()
	{
		var i = 0;
		while (i < blocks.length)
		{
			var B = blocks[i];
			B.visible = true;
			
			if (B.x < 0 || B.x>800)
			{
				B.visible = false;
			}
			i++;
		}
	}
	
	public function setformation()
	{
		resetblocks();
		//if (platformformation == 0)
		{
			setholeinplatform(600 - 192, 256, 512,false);
			//setholeinplatform(600 - 192, 288, 480,false);
			//setholeinplatform(600 - 352, 192, 576,true);
			setholeinplatform(600 - 352, 160-32, 608+32,true);
			//setholeinplatform(600 - 512, 256, 512, false);
			setholeinplatform(600 - 512, 288, 480, false);
			
			//addsectioninplatform(600 - 352, -1000, 96, false);
			//addsectioninplatform(600 - 352, 672, 2000, false);
			
			//1st row
			addsectioninplatform(600 - 192, -1300, -128, true);
			addsectioninplatform(600 - 192, 960, 2000, true);
			//2nd row
			addsectioninplatform(600 - 352, -1300, -32, false);
			addsectioninplatform(600 - 352, 864, 2000, false);
			//3rd row
			addsectioninplatform(600 - 512, -1300, -160, true);
			addsectioninplatform(600 - 512, 992, 2000, true);
			
			
			
			setholeinplatform(600 - 32, 160-32, 608+32,true);
			addsectioninplatform(600 - 32, -1300, -32, false);
			addsectioninplatform(600 - 32, 864, 2000, false);
			
			
			
			/*setplatformasplatform(600 - 192, false);
			setplatformasplatform(600 - 352, false);
			setplatformasplatform(600 - 512, false);*/
			//currentformation = 0;
		}
	}
	
	public function setholeinplatform(Y:Float,minx:Float, maxx:Float, inverse:Bool)
	{
		var entities = blocks;
		var i = 0;
			while (i < entities.length)
			{
				
				var E = entities[i];
				/*var D:Dynamic = E;
				
				if (E.type == "Block")*/
				{
					var B = E;
					//var B:Block = D;
					//D.Defrost();
					if (B.y == Y)
					{
						var ok = (B.x > minx && B.x < maxx);
						if (inverse)
						{
							ok = !ok;
						}
						B.visible = !ok;
					}
				}
				i += 1;
			}
	}
	
	public function addsectioninplatform(Y:Float,minx:Float, maxx:Float, inverse:Bool)
	{
		var entities = blocks;
		var i = 0;
			while (i < entities.length)
			{
				
				var E = entities[i];
				/*var D:Dynamic = E;
				
				if (E.type == "Block")*/
				{
					var B = E;
					///var B:Block = D;
					//D.Defrost();
					if (B.y == Y)
					{
						var ok = (B.x > minx && B.x < maxx);
						
						if (ok)
						{
							if (inverse)
							{
								ok = !ok;
							}
							B.visible = ok;
						}
					}
				}
				i += 1;
			}
	}
}