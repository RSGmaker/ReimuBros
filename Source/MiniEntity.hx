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
	public var bounce:Bool;
	public var timetobounce:Float;
	public var charname:String;
	public var bounced:Bool;
	public var behavior:Int;
	public var frame:Int;
	public var image:Bitmap;
	public function new(x:Float,y:Float,bitmap:BitmapData,speed:Float,dangerous:Bool,pointvalue:Int) 
	{
		super();
		mouseEnabled = false;
		this.x = x;
		this.y = y;
		var B = new Bitmap(bitmap);
		image = B;
		addChild(B);
		this.dangerous = dangerous;
		this.pointvalue = pointvalue;
		alive = true;
		Hspeed = 0;
		Vspeed = 0;
		behavior = 0;
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
	public function flip()
	{
		image.x += (image.width * image.scaleX);
		image.scaleX *= -1;
	}
	public function update()
	{
		
		x += Hspeed;
		y += Vspeed;
		//if ((Hspeed < 0 && x < -width) || (Hspeed > 0 && x > 800) || (Vspeed < 0 && y < -height) || (Vspeed > 0 && y > 600))
		if ((Hspeed < -100 && x < -width) || (Hspeed > 0 && x > 900) || (Vspeed < -100 && y < -height) || (Vspeed > 0 && y > 700))
		{
			alive =  false;
		}
		if (behavior > 0)
		{
			if (behavior == 1)
			{
				//runs back after walking halfway accross
				if (Math.abs(x - 400) < 10)
				{
					frame++;
					if (frame > 15)
					{
						//x += (width * scaleX);
						//scaleX *= -1;
						flip();
						Hspeed *= -3;
						behavior = 0;
					}
					else
					{
						x -= Hspeed;
					}
				}
				frame--;
			}
			if (behavior == 2)
			{
				//stick head out from donation box
				if (frame == 0)
				{
					Hspeed = 0;
					x = 320 + ((130 - width) * Math.random());
					y = 300;
					scaleX = 1.35;
					scaleY = 1.35;
				}
				if (frame < 45)
				{
					y-=2;
				}
				else if (frame < 90)
				{
					
				}
				else if (frame < 135)
				{
					y+=2;
				}
				else
				{
					alive = false;
				}
			}
			if (behavior == 3)
			{
				//looks back briefly
				if (frame == 0)
				{
					frame = Math.floor(300 * Math.random());
				}
				else if (frame < 300)
				{
				}
				else if (frame < 301)
				{
					x -= Hspeed;
					//x += (width * scaleX);
					//scaleX *= -1;
					flip();
				}
				else if (frame < 315)
				{
					x -= Hspeed;
				}
				else if (frame < 316)
				{
					x -= Hspeed;
					//x += (width * scaleX);
					//scaleX *= -1;
					flip();
				}
			}
			if (behavior == 4)
			{
				//fly
				if (frame == 0)
				{
					var D = 1;
					if (x > 400)
					{
						D = -1;
					}
					rotation = 30 * D;
					y -= 150;
					Hspeed *= 2.5;
					bounce = false;
				}
			}
		}
		if (bounce)
		{
			//timetobounce--;
			timetobounce -= Math.abs(Hspeed);
			if (timetobounce > 0)
			{
				
			}
			else
			{
				if (!bounced)
				{
					bounced = true;
					y -= 1;
				}
				else
				{
					y += 1;
					bounced = false;
					timetobounce = 6;
				}
				/*if (timetobounce == -1)
				{
					y -= 1;
				}
				else if (timetobounce < -1)
				{
					y += 1;
					//timetobounce = 5;
					timetobounce = 4;
				}*/
			}
		}
		frame++;
	}
}