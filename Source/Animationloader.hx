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
	public function GetAnimation(path:String):Array<BitmapData> {
		if (Dictionary.exists(path))
		{
			return Dictionary[path];
		}
		else
		{
			//check if we need to edit this image
			if (path.lastIndexOf("E") == path.length-1 || path.lastIndexOf("U") == path.length-1 || path.lastIndexOf("S") == path.length - 1)
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
			if (path.lastIndexOf("F") == path.length-1)
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
			var lst = new Array<BitmapData>();
			var i = 0;
			
			var str = "assets/Sprites/" + path + i + ".png";
			var bd = Assets.getBitmapData (str);
			while (bd != null) {
				lst[lst.length] = bd;
				i += 1;
				str = "assets/Sprites/" + path + i + ".png";
				bd = Assets.getBitmapData (str);
			}
			Dictionary.set(path, lst);
			return lst;
			}
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