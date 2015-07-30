package;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.geom.Rectangle;
/**
 * ...
 * @author RSGmaker
 */
class UFO extends Enemy
{

	public var ascend:Bool;
	public var iter:Int;
	public var rng:MersenneTwister;
	public var rot:Float;
	public var rename:String;
	public var ufotype:String;
	public var fuel:Int;
	public static var HB = new Rectangle(9, 9, 10, 10);
	public var reducetime:Int;
	public function new() 
	{
		super("UFO");
		subtype = "UFO";
		deccel = 100;
		Ldir = 1;
		flipped = -1;
		fallaccel = 0;
		
		ascend = true;
		rng = null;
		iter = 30;
		reward = false;
		pointvalue = 400;
		rot = 0;
		image.image_speed = 0.5;
		respawn = false;
		rename = "";
		
		hitbox = HB;
		needtokill = false;
	}
	
	public override function enrage()
	{
		trace("enraged UFO??? wut?");
	}
	public override function update()
	{
		if (rng == null)
		{
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			ascend = rng.twist(seed, 1, 100)[0] > 50;
			var R = rng.twist(seed, 1, 10)[0];
			if (R > 6)
			{
				ufotype = "Red";
			}
			else if (R < 3)
			{
				ufotype = "Green";
			}
			else
			{
				ufotype = "Blue";
			}
			iter = 30 + rng.twist(0, 1, 240)[0];
			fuel = 90 + rng.twist(0, 1, 900 + (rank * 150))[0];
			reducetime = rank * 30;
		}
		rename = ufotype + "ufo";
		animate();
		killed = false;
		dangerous = true;
		killable = false;
		x -= 2;
		if (x < -64)
		{
			x = 900;
		}
		if (fuel > 0)
		{
			fuel--;
		if (y == 10 && x>0 && x<800)
		{
		if (iter > 0)
		{
			iter --;
			if (iter < 12)
			{
				visuallyEnraged = !visuallyEnraged;
			}
			if (iter < 4)
			{
				visuallyEnraged = true;
			}
		}
		else
		{
			{
				iter = 30 + rng.twist(0, 1, 270 - reducetime)[0];
				visuallyEnraged = false;
			}
			if (game.Hoster)
			{
				var D:Dynamic = { };
				D.UID = UID;
				game.SendEvent("UFOStrike", D);
			}
		}
		}
		else
		{
			if (y < 10)
			{
				y++;
			}
		}
		}
		else
		{
			y--;
			visuallyEnraged = false;
			if (y < -200)
			{
				if (alive)
				{
					game.ufos--;
				}
				alive = false;
				killed = true;
			}
		}
		{
			
		updateanimation(rename);
		
		if (ground != null)
		{
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				if (game.myplayer == ground.bonkedby)
				{
				var D:Dynamic = { };
				D.UID = UID;
				D.x = x;
				D.y = y;
				D.Hspeed = Hspeed;
				D.Vspeed = -10;
				game.SendEvent("Bump", D);
				}
			}
			
		}
			if (wrapped)
			{
				//despawn after hitting any edge
				killed = true;
				alive = false;
				visible = false;
			}
	}
	}
	public override function bump()
	{
		alive = false;
		killed = true;
		if (ground != null && ground.bonkedby != null && ground.bonkedby.type=="Player")
		{
			var D:Dynamic = ground.bonkedby;
			D.score += pointvalue;
		}
	}	
}