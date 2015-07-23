package;

/**
 * ...
 * @author RSGmaker
 */
class Reimu extends Enemy
{
	public var accel:Float;
	
	public var mxspd:Float;
	
	public var target:EntityItem;
	
	public function new() 
	{
		super("reimu");
		//this.charname = "RedFairy";
		//accel = 0.5;
		//accel = 0.1;
		accel = 0.25;
		deccel = 0.1;
		mxspd = 4.5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		pointvalue = 1100;
		needtokill = false;
		//reward = false;
		reward = true;
		rewarditem = "MiniBomb";
	}
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 500;
	}
	
	override public function update():Void 
	{
		//super.update();
		this.scaleX = 0.6;
		this.scaleY = 0.6;
		
	if (!started)
		{
			/*var i = 0;
			while (i < rank)
			{
				accel += 0.1;
				mxspd += 0.5;
				pointvalue += 50;
				i++;
			}*/
			started = true;
		}
		/*accel = 0.5;
		deccel = 0.1;
		mxspd = 4;*/
		if (enraged)
		{
			//accel += 0.2;
			//mxspd += 2;
		}
		if (!killed)
		{
		
			if (target == null)
			{
				var i = 0;
				while (i < game.activeItems.length)
				{
					var E = game.activeItems[i];
					if (E.charname == "Point" && E.alive && !E.killed)
					{
						target = E;
					}
					i++;
				}
			}
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
		if (target != null && Math.abs(target.y - y)<30 && flipped <=0)
		{
		if (x < target.x)
		{
			dir = 1;
		}
		else if (x > target.x)
		{
			dir = -1;
		}
		if (Math.abs(x - target.x) > 400)
		{
			dir *= -1;
		}
		Ldir = dir;
		animate();
		if (game.Hoster && getBounds(game).intersects(target.getBounds(game)))
		{
			game.SendEvent("Collect", -target.UID);
			target = null;
		}
		}
		if (target != null && target.alive == false)
		{
			target = null;
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
		if (ground != null && Vspeed == 0 && flipped <= 0 && target != null && target.y < y)
		{
			if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1), y - (192-96)) == null)
			{
				if (Hspeed > 0)
				{
					if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1) + 96, y - (192 - 96)) != null)
					{
						Vspeed = -15;
					}
				}
				if (Hspeed < 0)
				{
					if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1) - 96, y - (192 - 96)) != null)
					{
						Vspeed = -15;
					}
				}
				//Vspeed = -16;
			}
		}
		updphysics();
		updateanimation();
		
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
			else
			{
				//if ((controller[1]) && Vspeed == 0)
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -4;
					//Vspeed = -13;
				}
			}
			
		}
			//if (y > 408 && wrapped)
			//if (y < 200 && wrapped)
			//if (wrapped && target == null)
			if (target == null && wrapped && (y>408 || y<200))
			{
				alive = false;
				//killed = true;
				//visible = false;
			}
		killable = flipped > 0;
	}
	else
	{
		y += 15;
	if (y > 600)
	{
	alive = false;
	}
	}
	}
	
	public override function bump()
	{
		//Vspeed = -4;
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