package;

import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.PixelSnapping;
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

	public var animation:Array<BitmapData>;
	private var Limage_index:Float;
	public var image_index:Float;
	public var image_speed:Float;
	public function new(ani:Array<BitmapData>) {
		//super(ani[0],PixelSnapping.NEVER,true);
		//super(ani[0],PixelSnapping.NEVER);
		super(ani[0]);
		image_index = 0;
		image_speed = 0;
		Limage_index = -9999999999999999;
		animation = ani;
	}
	public function ChangeAnimation(ani:Array<BitmapData>,reset:Bool=true):Void {
		if (animation != ani)
		{
			if (reset)
			{
				image_index = 0;
				this.bitmapData = ani[0];
			}
			else
			{
				this.bitmapData = ani[Math.floor(image_index) % ani.length];
			}
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