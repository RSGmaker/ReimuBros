package;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
//import flash.display.BitmapData;

import openfl.display.Sprite;
import openfl.Assets;
import openfl.geom.Transform;
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
/**
 * ...
 * @author RSGmaker
 */
class Animation extends Bitmap
{

	//private var animation:List<BitmapData>;
	public var animation:Array<BitmapData>;
	private var Limage_index:Float;
	public var image_index:Float;
	public var image_speed:Float;
	public function new(ani:Array<BitmapData>) {
		super(ani[0]);
		//super(Assets.getBitmapData ("assets/reimu0.png"));
		//this.bitmapData = ani.first();
		image_index = 0;
		image_speed = 0;
		Limage_index = -9999999999999999;
		animation = ani;
	}
	public function ChangeAnimation(ani:Array<BitmapData>):Void {
		if (animation != ani)
		{
			this.bitmapData = ani[0];
			image_index = 0;
			//image_speed = 0;
			animation = ani;
		}
	}
	public function animate()
	{
		if (animation.length == 0)
		{
			return;
		}
		//var oldindex = Math.floor(image_index);
		var oldindex = Math.floor(Limage_index);
		image_index += image_speed;
		while (image_index < 0)
		{
			image_index += animation.length;
		}
		while (image_index >= animation.length)
		{
			image_index -= animation.length;
		}
		var index = Math.floor(image_index);
		if (index != oldindex)
		{
			this.bitmapData = animation[index];
		}
		Limage_index = image_index;
	}
}