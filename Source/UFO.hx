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
	//public var MAT:Matrix;
	public var rot:Float;
	public var rename:String;
	public var ufotype:String;
	public var fuel:Int;
	//public static var HB = new Rectangle(7, 7, 14, 14);
	public static var HB = new Rectangle(9, 9, 10, 10);
	public var reducetime:Int;
	public function new() 
	{
		//super(main, "RedFairy");
		super("UFO");
		//this.charname = "RedFairy";
		//accel = 0.5;
		//chen doesnt use hspeed or vspeed system
		deccel = 100;
		//mxspd = 4;
		Ldir = 1;
		flipped = -1;
		fallaccel = 0;
		
		//this will prevent chen from going into the spawnlist
		//killed = true;
		
		ascend = true;
		rng = null;
		iter = 30;
		reward = false;
		pointvalue = 400;
		rot = 0;
		image.image_speed = 0.5;
		respawn = false;
		rename = "";
		
		//hitbox = new Rectangle(width / 4, height / 4, width / 2, height / 2);
		//MAT = this.transform.matrix.clone();
		//MAT = this.transform.matrix.clone();
		//MAT.translate(new Point(-13, -26));
		//MAT.translate( -13, -26);
		//MAT.tx = -13;
		//MAT.ty = -26;
		hitbox = HB;
		needtokill = false;
	}
	
	public override function enrage()
	{
		trace("enraged UFO??? wut?");
		//accel = 0.7;
		//mxspd = 6;
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
				//ChangeAnimation(game.AL.GetAnimation("Ran"));
				ufotype = "Red";
			}
			else if (R < 3)
			{
				//ChangeAnimation(game.AL.GetAnimation("Ran"));
				ufotype = "Green";
			}
			else
			{
				ufotype = "Blue";
			}
			iter = 30 + rng.twist(0, 1, 240)[0];
			fuel = 90 + rng.twist(0, 1, 900 + (rank * 150))[0];
			reducetime = rank * 30;
			//hitbox = new Rectangle(width / 4, height / 4, width / 2, height / 2);
		}
		rename = ufotype + "ufo";
		//rot += 0.25;
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
		}
		else
		{
			/*if (game.RoundType == GameView.TypeofRound.Nue)
			{
				iter = 15 + rng.twist(null, 1, 210)[0];
			}
			else*/
			{
				iter = 30 + rng.twist(0, 1, 270-reducetime)[0];
			}
			if (game.Hoster)
			{
				//trace("Imma' Firing mah lazor!");
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
		/*x += (4 * Ldir);
		if (ascend)
		{
			y -= 2;
		}
		else
		{
			y += 2;
		}
		iter -= 1;
		if (iter <= 0)
		{
			iter = 30;
			ascend = !ascend;
		}*/
		
		//if (!killed)
		{
			
		//updphysics();
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
		//killable = flipped > 0;
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