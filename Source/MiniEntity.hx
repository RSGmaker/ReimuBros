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
	//slowed
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
	public var bounceheight:Int;
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
	public function update()
	{
		
		x += Hspeed;
		y += Vspeed;
		if ((Hspeed < 0 && x < -width) || (Hspeed > 0 && x > 800) || (Vspeed < 0 && y < -height) || (Vspeed > 0 && y > 600))
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
					if (frame > 30)
					{
						x += (width * scaleX);
						scaleX *= -1;
						Hspeed *= -1.5;
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
				if (frame < 90)
				{
					y-=1;
				}
				else if (frame < 180)
				{
					
				}
				else if (frame < 270)
				{
					y+=1;
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
					frame = Math.floor(600 * Math.random());
				}
				else if (frame < 600)
				{
				}
				else if (frame < 601)
				{
					x -= Hspeed;
					x += ((width * scaleX)/2);
					scaleX *= -1;
				}
				else if (frame < 630)
				{
					x -= Hspeed;
				}
				else if (frame < 631)
				{
					x -= Hspeed;
					x += ((width * scaleX)/2);
					scaleX *= -1;
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
					bounceheight -= 1;
					y -= 0.75;
					if (bounceheight < -1)
					{
						bounced = true;
					}
				}
				else
				{
					bounceheight += 1;
					y += 0.75;
					if (bounceheight > -1)
					{
						bounced = false;
						timetobounce = 9;
					}
				}
				/*if (!bounced)
				{
					bounced = true;
					y -= 2;
				}
				else
				{
					y += 2;
					bounced = false;
					timetobounce = 6;
				}*/
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