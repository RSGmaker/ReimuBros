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
	//slowed
	public var ascend:Bool;
	public var iter:Int;
	public var rng:MersenneTwister;
	public var rot:Float;
	public var rename:String;
	public var ufotype:String;
	public var fuel:Int;
	public static var HB = new Rectangle(9, 9, 10, 10);
	public var reducetime:Int;
	public var movement:Int;
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
		iter = 60;
		reward = false;
		pointvalue = 400;
		rot = 0;
		image.image_speed = 0.5;
		respawn = false;
		rename = "";
		
		hitbox = HB;
		needtokill = false;
		movement = -1;
	}
	
	override public function attack():Bool 
	{
		//return super.attack();
		fuel = 0;
		return false;
	}
	
	public override function enrage()
	{
		trace("enraged UFO??? wut?");
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		fuel = 0;
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
			iter = 60 + rng.twist(0, 1, 480)[0];
			fuel = 180 + rng.twist(0, 1, 1800 + (rank * 300))[0];
			reducetime = rank * 30;
		}
		rename = ufotype + "ufo";
		animate();
		killed = false;
		dangerous = true;
		killable = false;
		x += movement;
		if (fuel>0 && game.myplayer.GetHitbox().intersects(GetHitbox()))
		{
			SendCustomEvent(null);
		}
		if (x < -width && movement<0)
		{
			x = 900;
		}
		if (x > 900 && movement>0)
		{
			x = -width;
		}
		if (fuel > 0)
		{
			fuel--;
		if (y == 10 && x>0 && x<800)
		{
		if (iter > 0)
		{
			iter --;
			if (iter < 24)
			{
				visuallyEnraged = !visuallyEnraged;
			}
			if (iter < 8)
			{
				visuallyEnraged = true;
			}
		}
		else
		{
			{
				iter = 60 + rng.twist(0, 1, 540 - reducetime)[0];
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
				y+=0.5;
			}
		}
		}
		else
		{
			y-=0.5;
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
				D.Vspeed = -5;
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