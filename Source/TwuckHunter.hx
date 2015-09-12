package;

/**
 * ...
 * @author RSGmaker
 */
class TwuckHunter extends Enemy
{
	//slowed
	public var accel:Float;
	
	public var mxspd:Float;
	
	public var target:EntityItem;
	
	public var rename:String;
	
	public var mokou:Bool;
	
	
	public function new(mokou:Bool) 
	{
		if (!mokou)
		{
			super("kaguya");
			rename = "Ekaguya";
		}
		else
		{
			super("mokou");
			mokou = true;
			rename = "Emokou";
		}
		accel = 0.120;
		deccel = 0.04;
		mxspd = 2;
		Ldir = 1;
		killed = false;
		flipped = -1;
		pointvalue = 1100;
		needtokill = false;
		reward = false;
		//rewarditem = "MiniBomb";
		
		respawn = false;
		
	}
	public override function increaserank()
	{
			accel += 0.05;
			mxspd += 0.25;
			pointvalue += 500;
	}
	
	override public function update():Void 
	{
		
		invincibility = 100;
		var hastwuck = false;
		if (!started)
		{
			this.scaleX = 0.75;
			this.scaleY = 0.75;
			started = true;
			//if (Ldir == -1)
			if (mokou)
			{
				//mokou = true;
			}
			else
			{
				mxspd += 0.25;
			}
		}
		if (!killed)
		{
		
			if (target == null)
			{
				var i = 0;
				while (i < game.activeItems.length)
				{
					var E = game.activeItems[i];
					if (E.charname == "trophy" && E.alive && !E.killed)
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
				//powerup();
			}
		}
		else
		{
			dangerous = true;
		}
		if (target != null)
		{
			var D:Dynamic = target;
			if (!target.alive)
			{
				target = null;
			}
			else if (D.holder == this)
			{
				dir = -1;
				Ldir = -1;
				if (mokou)
				{
					dir = 1;
					Ldir = 1;
				}
				hastwuck = true;
			}
		}
		if (target != null && Math.abs(target.y - (y+10))<40 && flipped <=0)
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
		var D:Dynamic = target;
		if (!hastwuck && game.Hoster && getBounds(game.gamestage).intersects(target.getBounds(game.gamestage)) && D.holder==null/* Math.abs(x - target.x) < 800 && Math.abs((y+10) - target.y) < 600*/)
		{
			//game.SendEvent("Collect", -target.UID);
			D = { };
			D.UID = UID;
			D.target = target.UID;
			game.SendEvent("Take", D);
			//target = null;
		}
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
		if (!hastwuck && ground != null && Vspeed == 0 && flipped <= 0 && target != null && target.y < y-60)
		{
			if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1), y - (192-96)) == null)
			{
				if (Hspeed > 0)
				{
					if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1) + 96, y - (192 - 96)) != null)
					{
						Vspeed = -9;
					}
				}
				if (Hspeed < 0)
				{
					if (game.CollisionDetectPoint(x + (Math.floor(width) >> 1) - 96, y - (192 - 96)) != null)
					{
						Vspeed = -9;
					}
				}
			}
			else
			{
				//intercept jumping players
				if (Math.abs(x - target.x) < 20 && target.y > y-110)
				{
					Vspeed = -9;
				}
			}
		}
		if (hastwuck && flipped <= 0)
		{
			rename = "EH"+charname;
		}
		else
		{
			rename = "E" + charname;
			if (hastwuck)
			{
				var D:Dynamic = target;
				D.holder = null;
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
				D.Vspeed = -5;
				game.SendEvent("Bump", D);
				}
			}
			else
			{
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -2;
				}
			}
			
		}
			if ((target == null || hastwuck) && wrapped && (y>408 || y<200))
			{
				alive = false;
				killed = true;
				if (game.Hoster && target != null)
				{
					game.SendEvent("Remove", target.UID);
				}
			}
		//killable = flipped > 0;
	}
	else
	{
		y += 7.5;
	if (y > 600)
	{
	alive = false;
	killed = true;
	if (game.Hoster && target != null)
				{
					game.SendEvent("Remove", target.UID);
				}
	}
	}
	}
	
	public override function bump()
	{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 60 * 4;
			}
			else
			{
				flipped = 60 * 7;
			}
			if (mokou)
			{
				flipped -= 90;
			}
		}
		else
		{
			flipped = 0;
		}
	}
}