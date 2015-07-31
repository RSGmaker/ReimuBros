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
	public var rot:Float;
	public var rename:String;
	public var danmaku:Int;
	public var reducetime:Int;
	public function new() 
	{
		super("Chen");
		//chen doesnt use hspeed or vspeed system
		deccel = 100;
		//mxspd = 4;
		Ldir = 1;
		flipped = -1;
		fallaccel = 0;
		
		
		ascend = true;
		rng = null;
		//iter = 30;
		iter = 15;
		reward = false;
		pointvalue = 400;
		rot = 0;
		image.image_speed = 1;
		respawn = false;
		rename = "E" + charname;
		danmaku = -1000;
		needtokill = false;
		subtype = "chen";
	}
	
	public override function enrage()
	{
		trace("enraged chen??? wut?");
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
				rename = "ERan";
			}
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
		if (danmaku > -1000/* && game.Hoster*/)
		{
			if (danmaku < 1)
			{
				if (game.Hoster)
				{
					var D:Dynamic = { };
					D.UID = UID;
					game.SendEvent("ChenDanmaku", D);
				}
				visuallyEnraged = false;
				danmaku = 15+rng.twist(rng.seed, 1, 540-reducetime)[0];
			}
			else
			{
				danmaku -= 1;
				if (danmaku < 8)
				{
					visuallyEnraged = !visuallyEnraged;
				}
			}
		}
		animate();
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
		{
			
		
		updphysics();
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