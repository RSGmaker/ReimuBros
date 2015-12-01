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
	public var ran:Bool = false;
	public var spd:Float = 4;
	public var aspd:Float = 3;
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
	
	override public function attack(player:Player):Bool
	{
		//return super.attack();
		alive = false;
		killed = true;
		{
			var D:Dynamic = game.myplayer;
			D.score += pointvalue;
		}
		return true;
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
			
			//if (rng.twist(seed, 1, 10)[0] > 6)
			if (UID>0.6)
			{
				rename = "ERan";
				ran = true;
			}
			else
			{
				scaleX = 0.8;
				scaleY = 0.8;
				spd = 4.5;
				aspd = 3.35;
			}
			//reducetime = rank * 30;
			reducetime = rank * 20;
			if (game.RoundType == GameView.TypeofRound.EventYukari || game.RoundType == GameView.TypeofRound.EventDanmaku)
			{
				reducetime += 150;
			}
			if (game.RoundType == GameView.TypeofRound.EventYukari || rank>0 || game.RoundType == GameView.TypeofRound.EventDanmaku)
			{
				//danmaku = 15+rng.twist(rng.seed, 1, 540-reducetime)[0];
				////danmaku = 15+rng.twist(rng.seed, 1, 740-reducetime)[0];
			}
			danmaku = 15+rng.twist(rng.seed, 1, 740-reducetime)[0];
			if (game.RoundType == GameView.TypeofRound.EventTable)
			{
				rename = "table";
			}
		}
		rot += 0.25;
		doingability = false;
		if (ran)
		{
		if (danmaku == -1000/* && rank > 0*/)
		{
			danmaku = 15+rng.twist(rng.seed, 1, 740-reducetime)[0];
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
				danmaku = 15+rng.twist(rng.seed, 1, 740-reducetime)[0];
			}
			else
			{
				danmaku -= 1;
				if (danmaku < 8)
				{
					//visuallyEnraged = !visuallyEnraged;
					doingability = true;
				}
			}
		}
		}
		animate();
		dangerous = true;
		killable = false;
		x += (spd * Ldir);
		if (ascend)
		{
			y -= aspd;
		}
		else
		{
			y += aspd;
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
	if (killed)
	{
		alive = false;
	}
	}
	public override function bump(player:Player)
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