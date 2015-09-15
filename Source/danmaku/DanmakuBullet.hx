package danmaku;
import lime.math.Vector2;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class DanmakuBullet extends DanmakuEntity
{
	public var gravX:Float;
	public var gravY:Float;
	public var rotrate:Float;
	public var currot:Float;
	public var speedrate:Float;
	public var LHSP:Float;
	public var LVSP:Float;
	public var spiral:Float;
	public var cheat:Vector2;
	public var cheattime:Int;
	public var rotdelay:Int;
	//if bullet scores points, the points should go to this player.
	public var shotby:Entity;
	public var timelimit:Int;
	
	
	public function new(ani:String="bullet") 
	{
		//super(ani, false);
		super(ani);
		type = "Bullet";
		subtype = "DanmakuBullet";
		gravX = 0;
		gravY = 0;
		LHSP = 0;
		LVSP = 0;
		currot = 0;
		rotrate = 0;
		spiral = 0;
		cheat = null;
		cheattime = 0;
		rotdelay = 0;
		shotby = null;
		//deathoncollision = true;

		dangerous = true;
		//speedrate = 1;
	}
	override public function update():Void 
	{
		frame++;
		var C = currot;
		var WW:Int = Std.int(width);
		var HH:Int = Std.int(height);
		hitbox = new Rectangle(WW >> 2, HH >> 2, WW >> 1, HH >> 1);
		super.update();
		if (frame == 1)
		{
			currot = getangle();
			//speedrate = getspeed();
			/*currot = Math.atan2(Hspeed, Vspeed);
			//speedrate = Math.max(Math.abs(Hspeed),Math.abs(Vspeed));
			speedrate = (Math.abs(Hspeed) + Math.abs(Vspeed)) * 0.7;*/
		}
		if (timelimit > 0)
		{
			timelimit--;
			if (timelimit < 1)
			{
				alive = false;
				killed = true;
			}
		}
		if (rotrate != 0)
		{
			
			//if (cheat != null)
			if (rotdelay > 0)
			{
				rotdelay--;
			}
			else
			{
			if (cheattime>0 && cheat != null)
			{
				Hspeed += cheat.x;
				Vspeed += cheat.y;
				//cheat = null;
				cheattime--;
			}
			else
			{
				//currot += rotrate+rotrate+rotrate;
				currot += rotrate+rotrate;
				//rotrate -= spiral+spiral+spiral;
				rotrate *= spiral;
				cheat = changeangle(currot);
				cheattime = 1;
				///cheattime = 2;
				//Hspeed += cheat.x;
				//Vspeed += cheat.y;
				//cheat = null;
			}
			}
			/*var HH = Math.cos(currot) * speedrate;
			var VV = Math.sin(currot) * speedrate;
			//var HH = Math.cos(currot);
			//var VV = Math.sin(currot);
			Hspeed += (HH - LHSP);
			Vspeed += (VV - LVSP);
			//Hspeed = (HH - LHSP);
			//Vspeed = (VV - LVSP);
			LVSP = VV;
			LHSP = HH;*/
		}
		Hspeed += gravX;
		Vspeed += gravY;
		
		if ((x < -32 && gravX <= 0) || (y < -32 && gravY <= 0) || (x > 1056 && gravX >= 0) || (y > 752 && gravY >= 0))
		{
			if (HP <= 0)
			{
				alive = false;
			}
			else
			{
				HP--;
			}
		}
		/*if (visuallyrotates && currot != C)
		{
			rotateentity(currot);
		}*/
	}
}