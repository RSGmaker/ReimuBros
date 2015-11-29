package;
import openfl.display.Sprite;

/**
 * ...
 * @author RSGmaker
 */
class Bullet extends Entity
{

	public var gravX:Float = 0;
	public var gravY:Float = 0;
	public var started:Bool;
	public var HP:Int = 0;
	public var wraplimit:Int = 1;
	public var PX:Float;
	public var PY:Float;
	public var LX:Float;
	public var LY:Float;
	
	public var rotationlayer:Sprite;
	public var spin:Bool;
	public var spinspeed:Float = 0;
	public function new() 
	{
		super("bullet");
		
		type = "Bullet";
		//if we kept track of these things would probly get messy.
		UID = -1;
		dangerous = true;
		removeonlevelend = true;
	}
	public override function update()
	{
		if (!started)
		{
			if (GameView._this.RoundType == GameView.TypeofRound.EventTable)
			{
				ChangeAnimation("tableE");
				image.image_speed = 1;
			}
			PX = x;
			PY = y;
			LX = PX;
			LY = PY;
			if (spin)
			{
				//center image for rotation.
				image.x = -(image.width / 2);
				image.y = -(image.height / 2);
				//maintain visual position
				/*x += -image.x;
				y += -image.y;*/
				//set spin speed/direction
				if (spinspeed == 0)
				{
				if (Hspeed >= 0)
				{
					spinspeed = 22.5;
				}
				else
				{
					spinspeed = -22.5;
				}
				spinspeed *= image.image_speed;
				}
				rotationlayer = new Sprite();
				rotationlayer.x = -image.x;
				rotationlayer.y = -image.y;
				removeChild(image);
				rotationlayer.addChild(image);
				addChild(rotationlayer);
			}
			started = true;
		}
		if (spin)
		{
			rotationlayer.rotation += spinspeed;
		}

		Hspeed += gravX;
		Vspeed += gravY;
		animate();
		/*x += Hspeed;
		y += Vspeed;*/
		if (LX != x || LY != y)
		{
			PX = x;
			PY = y;
		}
		PX += Hspeed;
		PY += Vspeed;
		
		x = PX;
		y = PY;
		LX = x;
		LY = y;
		var ok = true;
		if (HP > 0)
		{
			HP--;
			if (HP < 1)
			{
				scaleX -= 0.2;
				scaleY -= 0.2;
				if (scaleX <= 0 || scaleY <= 0)
				{
					alive = false;
					killed = true;
				}
				else
				{
					HP++;
				}
			}
		}
		if (wraplimit == -1)
		{
			return;
		}
		if (wraplimit < 2)
		{
		//if ((x < -width && gravX<=0 && Hspeed<=0) || (y < -height && gravY<=0 && Vspeed<=0) || (x>832 && gravX>=0 && Hspeed>=0) || (y>632 && gravY>=0 && Vspeed>=0))
		if ((x < -width && gravX<=0 && Hspeed<=0) || (y < (-height)-100 && gravY<=0 && Vspeed<=0) || (x>832 && gravX>=0 && Hspeed>=0) || (y>632 && gravY>=0 && Vspeed>=0))
		{
			alive = false;
			killed = true;
		}
		}
		else
		{
			if (x < -width && gravX <= 0 && Hspeed <= 0)
			{
				x += 800;
				wraplimit--;
			}
			//if (y < -height && gravY <= 0 && Vspeed <= 0)
			if (y < (-height)-100 && gravY <= 0 && Vspeed <= 0)
			{
				y += 600;
				wraplimit--;
			}
			if (x > 832 && gravX >= 0 && Hspeed >= 0)
			{
				x -= 800;
				wraplimit--;
			}
			if (y > 632 && gravY >= 0 && Vspeed >= 0)
			{
				y -= 600;
				wraplimit--;
			}
		}
	}
}