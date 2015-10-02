package;

//import lime.math.ColorMatrix;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Graphics;
import openfl.display.Sprite;
import openfl.Assets;
import openfl.filters.ColorMatrixFilter;
import openfl.geom.ColorTransform;
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
import openfl.ui.Keyboard;
import haxe.ds.ObjectMap;
import flash.display.DisplayObject;
   import flash.display.BitmapData;
   import flash.geom.Rectangle;
   import flash.geom.Matrix;
//import flash.geom;
/**
 * ...
 * @author RSGmaker
 */
class Animationloader
{

	private var Dictionary:Map<String,Array<BitmapData>>;
	public function new() {
		Dictionary = new Map<String,Array<BitmapData>>();
		
	}
	   
	public static function getVisibleBounds(source:DisplayObject):Rectangle
   {
       // Updated 11-18-2010;
       // Thanks to Mark in the comments for this addition;
       var matrix:Matrix = new Matrix();
       matrix.tx = -source.getBounds(null).x;
       matrix.ty = -source.getBounds(null).y;
 
       var data:BitmapData = new BitmapData(Std.int(source.width), Std.int(source.height), true, 0x00000000);
       data.draw(source, matrix);
       var bounds : Rectangle = data.getColorBoundsRect(0xFFFFFFFF, 0x000000, false);
       data.dispose();
       return bounds;
   }
	public function GetAnimation(path:String):Array<BitmapData> {
		var DNA = null;
		if (path == "customavatar")
		{
			path = "dna-"+Main._this.savedata.data.avatar;
		}
		if (Dictionary.exists(path))
		{
			return Dictionary[path];
		}
		else
		{
			DNA = CharHelper.getCharPreset(path);
			if (DNA != null)
			{
				//path = DNA;
			}
		}
		if (Dictionary.exists(path))
		{
			return Dictionary[path];
		}
		else
		{
			var P = path;
			
			if (P.indexOf("dna-") >= 0)
			{
				var index = path.lastIndexOf(":")+7;
				P = path.substr(0, index) +"::0"+ path.substr(index, path.length - index);
			}
			//check if we need to edit this image
			if (DNA == null && (P.lastIndexOf("E") == P.length-1 || P.lastIndexOf("U") == P.length-1 || P.lastIndexOf("S") == P.length - 1))
			{
				//recolor the image
				var color:UInt = 0xff0000;
				var value:Float = 40;
				var red:UInt = 0;
				var green:UInt = 0;
				var blue:UInt = 0;
				if (path.lastIndexOf("E") == path.length - 1)
				{
					red = 255;
				}
				else if (path.lastIndexOf("U") == path.length - 1)
				{
					blue = 255;
				}
				else if (path.lastIndexOf("S") == path.length - 1)
				{
					green = 255;
				}

				var mul:Float=value/100;

				var ctMul:Float=(1-mul);

				var ctRedOff:Float=Math.round(mul*red);

				var ctGreenOff:Float=Math.round(mul*green);

				var ctBlueOff:Float=Math.round(mul*blue);

				var ct=new ColorTransform(ctMul,ctMul,ctMul,1,ctRedOff,ctGreenOff,ctBlueOff,0);
				
				var P = path.substring(0, path.length - 1);
				var lst = new Array<BitmapData>();
				var O = GetAnimation(P);
				var i = 0;
				while (i < O.length)
				{
					var OO = O[i].clone();
					OO.colorTransform(O[i].rect, ct);
					lst[lst.length] = OO;
					i += 1;
				}
				Dictionary.set(path, lst);
				return lst;
			}
			if (P.lastIndexOf("F") == P.length-1)
			{
				//flip the image
				var P = path.substring(0, path.length - 1);
				var lst = new Array<BitmapData>();
				var O = GetAnimation(P);
				var i = 0;
				while (i < O.length)
				{
					lst[lst.length] = flipBitmapData(O[i], "x");
					i += 1;
				}
				Dictionary.set(path, lst);
				return lst;
			}
			else
			{
			var P = path;
			if (DNA != null)
			{
				P = DNA;
			}
			var lst = getBitmapData(P);
			Dictionary.set(path, lst);
			return lst;
			}
		}
	}
	public function getBitmapData(data:String):Array<BitmapData>
	{
		var i = 0;
		var lst = new Array<BitmapData>();
		if (data.indexOf("dna-") < 0)
		{
			if (data.indexOf("background-") < 0)
			{
		var str = "assets/Sprites/" + data + i + ".png";
			var bd = Assets.getBitmapData (str);
			while (bd != null) {
				lst[lst.length] = bd;
				i += 1;
				str = "assets/Sprites/" + data + i + ".png";
				bd = Assets.getBitmapData (str);
			}
			return lst;
			}
			else
			{
				var spr:Sprite = new Sprite();
				//var CHR = CharHelper.makeChar(data);
				var clip = Assets.getMovieClip ("Background:");
				var CHR = clip;
				var dst = Std.parseInt(data.split("-")[1]);
				var D:Dynamic = clip.getChildAt(0);
				D.gotoAndStop(dst);
				
				//var CHR = new Background;
				CHR.scaleX = 1.5;
				CHR.scaleY = 1.5;
				CHR.y = -2;
			spr.addChild(CHR);
			/*var R = CHR.getBounds(spr);
			CHR.x = -R.x;
			CHR.y = -R.y;*/
			//var bitmapData:BitmapData = new BitmapData(Std.int(R.width), Std.int(R.height),true, 0x00000000);
			//var bitmapData:BitmapData = new BitmapData(Std.int(CHR.width), Std.int(CHR.height),true, 0x00000000);
			var bitmapData:BitmapData = new BitmapData(Std.int(800), Std.int(600),true, 0x00000000);
			//bitmapData.draw(spr);
			bitmapData.draw(spr);
			lst[lst.length] = bitmapData;
			return lst;
			}
		}
		else
		{
			/*if (data.indexOf("-1") > -1)
			{
				lst[lst.length] =new BitmapData(1, 1, true, 0);
				return lst;
			}*/
			var spr:Sprite = new Sprite();
			var CHR = CharHelper.makeChar(data);
			CHR.scaleX *= 0.24;
			CHR.scaleY *= 0.24;
			spr.addChild(CHR);
			var R = CHR.getBounds(spr);
			CHR.x = -R.x;
			CHR.y = -R.y;
			var bounds = getVisibleBounds(spr);
			CHR.x -= bounds.x;
			CHR.y -= bounds.y;
			//var bitmapData:BitmapData = new BitmapData(Std.int((R.width * 0.75)), Std.int(R.height),true, 0x00000000);
			//var bitmapData:BitmapData = new BitmapData(Std.int((R.right + CHR.x)), Std.int(R.height),true, 0x00000000);
			var bitmapData:BitmapData = new BitmapData(Std.int(bounds.width), Std.int(bounds.height),true, 0x00000000);
			bitmapData.draw(spr);
			lst[lst.length] = bitmapData;
			return lst;
		}
		
	}
	function flipBitmapData(original:BitmapData, axis:String = "x"):BitmapData
{
     var flipped:BitmapData = new BitmapData(original.width, original.height, true, 0);
     var matrix:openfl.geom.Matrix;
     if(axis == "x"){
          matrix = new openfl.geom.Matrix( -1, 0, 0, 1, original.width, 0);
     } else {
          matrix = new openfl.geom.Matrix( 1, 0, 0, -1, 0, original.height);
     }
     flipped.draw(original, matrix, null, null, null, true);
     return flipped;
}
	
}