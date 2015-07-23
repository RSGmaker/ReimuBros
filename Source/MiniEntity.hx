package;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
/**
 * ...
 * @author RSGmaker
 */
class MiniEntity extends Sprite
{

	public var Hspeed:Float;
	public var Vspeed:Float;
	public var dangerous:Bool;
	public var pointvalue:Int;
	public var alive:Bool;
	public function new(x:Float,y:Float,bitmap:BitmapData,speed:Float,dangerous:Bool,pointvalue:Int) 
	{
		super();
		this.x = x;
		this.y = y;
		var B = new Bitmap(bitmap);
		addChild(B);
		this.dangerous = dangerous;
		this.pointvalue = pointvalue;
		alive = true;
		Hspeed = 0;
		Vspeed = 0;
		if (x < 0)
		{
			x = -B.width;
			x = -64;
			Hspeed = speed;
		}
		if (y < 0)
		{
			y = -B.height;
			y = -64;
			Vspeed = speed;
		}
		if (x >= 800)
		{
			x = 800;
			Hspeed = -speed;
		}
		if (y >= 600)
		{
			y = 600;
			Vspeed = -speed;
		}
	}
	public function update()
	{
		x += Hspeed;
		y += Vspeed;
		if ((Hspeed < 0 && x < -width) || (Hspeed > 0 && x > 800) || (Vspeed < 0 && y < -height) || (Vspeed > 0 && y > 600))
		{
			alive =  false;
		}
	}
}