package;

/**
 * ...
 * @author RSGmaker
 */
class Scarlet extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	public var who:String;
	public var transformed:Bool = true;
	public var target:Player;
	
	public function new() 
	{
		super("Scarlet");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 6;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "bat";
		image.image_speed = 0.2;
		scaleX = 0.7;
		scaleY = 0.7;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 50;
	}
	/*function distance(p1,p2)
	{
		var dist,dx,dy:Float;
		dx = p2.x-p1.x;
		dy = p2.y-p1.y;
		dist = Math.sqrt(dx*dx + dy*dy);
		//trace(dist);
	}*/
	override public function attack():Bool 
	{
		return !transformed;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			if (UID < 0.5)
			{
				who = "remilia";
			}
			else
			{
				who = "flandre";
				mxspd-=2.5;
			}
			var A = game.GetPlayers();
			target = A[Std.int(99999 * UID) % A.length];
		}
		if (!killed)
		{
			if (transformed) 
			{
				if (!target.alive)
				{
					var A = game.GetPlayers();
					target = A[Std.int((99993 * UID)) % A.length];
				}
				else
				{
					var P:flash.geom.Point = new flash.geom.Point(target.x - x, target.y - y);
					P.normalize(3);
					x += P.x;
					y += P.y;
					if (Math.abs(target.y - y) < 60/* && target.y < y*/)
					{
						if (Math.abs(target.x - x) < 200)
						{
							if (x < target.x)
							{
								Ldir = 1;
							}
							if (x > target.x)
							{
								Ldir = -1;
							}
							if (who == "remilia")
							{
								Hspeed *= (Ldir * (mxspd / 2));
							}
							rename = who;
							transformed = false;
						}
					}
				}
				animate();
				updateanimation(rename);
			}
			else
			{
		var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
			if (flipped == 0)
			{
				flipped = -1;
				powerup();
			}
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
		}
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
			else
			{
				if (ground.type == "Block" && who=="flandre" && flipped<=0 && ground.y < 500 && !ground.dangerous)
				{
					var E:Dynamic = ground;
					E.Burn();
					//E.respawn = (E.respawn >> 2) - (E.respawn >> 3);
					//E.respawn = (E.respawn >> 3);
					E.respawn = (E.respawn >> 2);
				}
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -4;
				}
			}
			
		}
			if (y > 408 && wrapped)
			{
				alive = false;
				visible = false;
			}
		killable = flipped > 0;
		}
	}
	else
	{
		y += 15;
	if (y > 600)
	{
	alive = false;
	}
	}
	if (!alive && game.myplayer == bonkedby)
	{
		game.unlockcharacter(who);
	}
	}
	public override function bump()
	{
		if (!transformed)
		{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * 4;
			}
			else
			{
				flipped = 30 * 7;
			}
		}
		else
		{
			flipped = 0;
		}
		}
	}
	
}