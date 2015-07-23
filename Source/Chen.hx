package;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.geom.Rectangle;
//import fl.motion.MatrixTransformer;
/**
 * ...
 * @author RSGmaker
 */
class Chen extends Enemy
{

	public var ascend:Bool;
	public var iter:Int;
	public var rng:MersenneTwister;
	//public var MAT:Matrix;
	public var rot:Float;
	public var rename:String;
	public var danmaku:Int;
	public var reducetime:Int;
	public function new() 
	{
		//super(main, "RedFairy");
		super("Chen");
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
		//iter = 30;
		iter = 15;
		reward = false;
		pointvalue = 400;
		rot = 0;
		//image_speed = 0.5;
		//image_speed = 0.5;
		image.image_speed = 1;
		respawn = false;
		rename = "E" + charname;
		danmaku = -1000;
		needtokill = false;
		
		//hitbox = new Rectangle(width / 4, height / 4, width / 2, height / 2);
		//MAT = this.transform.matrix.clone();
		//MAT = this.transform.matrix.clone();
		//MAT.translate(new Point(-13, -26));
		//MAT.translate( -13, -26);
		//MAT.tx = -13;
		//MAT.ty = -26;
	}
	
	public override function enrage()
	{
		trace("enraged chen??? wut?");
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
			
			if (rng.twist(seed, 1, 10)[0] > 6)
			{
				//ChangeAnimation(game.AL.GetAnimation("Ran"));
				rename = "ERan";
			}
			//chen can never hit you, so im taking off her hitbox.
			//hitbox = new Rectangle(width / 4, height / 4, width / 2, height / 2);
			reducetime = rank * 30;
			if (game.RoundType == GameView.TypeofRound.Yukari)
			{
				reducetime += 200;
			}
			if (game.RoundType == GameView.TypeofRound.Yukari || rank>0)
			{
				danmaku = 15+rng.twist(rng.seed, 1, 540-reducetime)[0];
			}
			if (game.RoundType == GameView.TypeofRound.Table)
			{
				rename = "table";
			}
		}
		rot += 0.25;
		if (danmaku == -1000 && rank > 0)
		{
			danmaku = 15+rng.twist(rng.seed, 1, 540-reducetime)[0];
		}
		if (danmaku > -1000 && game.Hoster)
		{
			if (danmaku < 1)
			{
				var D:Dynamic = { };
				D.UID = UID;
				game.SendEvent("ChenDanmaku", D);
				danmaku = 15+rng.twist(rng.seed, 1, 540-reducetime)[0];
			}
			else
			{
				danmaku -= 1;
			}
		}
		/*if (Ldir > 0)
		{
			rotateentity(rotation + 15);
		}
		else
		{
			rotateentity(rotation - 15);
		}*/
		animate();
		//var M = MAT.clone();
		/*var mat:Matrix= MAT.clone();
		MatrixTransformer.rotateAroundInternalPoint(x+13,
                                     y+26.5,0.1);

		transform.matrix=mat;*/
		//this.transform.matrix.
		//M.translate( -13, -26);
		/*M.tx = -13;
		M.ty = -26;
		M.rotate(rot);
		M.translate(x, y);
		M.tx = x;
		M.ty = y;
		this.transform.matrix = M;
		this.rotationZ = rot;*/
		/*var rect:Rectangle = this.getBounds(game); 
		//var X = M.tx;
		//var Y = M.ty;
		// Translating the desired reference point (in this case, center)
M.translate(-M.tx- ((rect.width/2)),-M.ty - ((rect.height/2))); 

// Rotation (note: the parameter is in radian) 
//M.rotate((90/180)*Math.PI); 
//M.tx = 
M.rotate(rot);

// Translating the object back to the original position.
M.translate(rect.left + (rect.width / 2), rect.top + (rect.height / 2)); */

//M.tx = x;
//M.ty = y;
//this.transform.matrix = M;
		killed = false;
		dangerous = true;
		killable = false;
		x += (4 * Ldir);
		if (ascend)
		{
			y -= 3;
		}
		else
		{
			y += 3;
		}
		iter -= 1;
		if (iter <= 0)
		{
			iter = 30;
			ascend = !ascend;
		}
		//y += 1;
		//if (!killed)
		{
			
		/*var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
		}
		else
		{
			dangerous = true;
		}
		if (Hspeed < mxspd && dir==1 && flipped < 1)
		{
			Hspeed += accel;
			if (Hspeed > mxspd)
			{
				Hspeed = mxspd;
			}
		}
		if (Hspeed > -mxspd && dir==-1 && flipped < 1)
		{
			Hspeed -= accel;
			if (Hspeed < -mxspd)
			{
				Hspeed = -mxspd;
			}
		}*/
		updphysics();
		updateanimation(rename);
		
		if (ground != null)
		{
			//if (ground.bonked > -1000 && game.Hoster && game.myplayer == ground.bonkedby)
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				//if (game.ismyplayer(ground.bonkedby) && game.Hoster)
				if (game.myplayer == ground.bonkedby)
				{
				//Vspeed = -4;
				//flipped = 30 * 10;
				var D:Dynamic = { };
				D.UID = UID;
				D.x = x;
				D.y = y;
				D.Hspeed = Hspeed;
				D.Vspeed = -10;
				//game.SendEvent("Bump", this.UID);
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