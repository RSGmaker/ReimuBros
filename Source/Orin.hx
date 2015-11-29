package;

/**
 * ...
 * @author RSGmaker
 */
class Orin extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public var spawnedfairy:Bool = false;
	
	public function new() 
	{
		super("Orin");
		HP = 1;
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "orin";
		pointvalue = 400;
	}
	
	override public function attack():Bool 
	{
		HP--;
		if (HP > 0)
		{
			invincibility = 10;
		}
		return HP < 1;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 200;
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		spawnedfairy = true;
		HP = 2;
		pointvalue += 300;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			if (spawns > 0)
			{
				//spawnedfairy = true;
			}
			if (game.Hoster && HP > 1 && game.gamemode.canmyonspawn)
			{
				var D:Dynamic = { };
				D.UID = UID;
				game.SendEvent("AttachZombieFairy", D);
				spawnedfairy = true;
			}
			rewarditem = "Point";
		}
		if (!killed)
		{
			
		/*if (HP == 3)
		{
			rename = "hecatia";
		}
		else if (HP == 2)
		{
			rename = "hecatiam";
		}
		else if (HP < 2)
		{
			rename = "hecatiae";
		}*/
		
		if (game.Hoster && flipped<1)
		{
			var i = 0;
			var A = game.activeEnemies;
			var HB = GetHitbox();
			while (i < A.length)
			{
				var E = A[i];
				if (!E.killed && E.flipped > 0 && E.invincibility < 1 && E != this)
				{
					var B = E.GetHitbox();
					if (B.intersects(HB))
					{
						game.SendEvent("Destroy", E.UID);
						if (!spawnedfairy)
						{
							/*spawnedfairy = true;
							var D:Dynamic = { };
							D.UID = UID;
							game.SendEvent("AttachZombieFairy", D);
							HP = 2;
							pointvalue += 300;*/
							if (game.gamemode.canmyonspawn)
							{
							var D:Dynamic = { };
							D.UID = UID;
							game.SendEvent("AttachZombieFairy", D);
							SendCustomEvent(null);
							}
							else
							{
								rewarditem = "Mini1up";
							}
						}
					}
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
		this.scaleX = 0.7;
		this.scaleY = 0.7;
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
				if (spawnedfairy)
				{
					HP = 2;
				}
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
		HP--;
		if (HP < 1)
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