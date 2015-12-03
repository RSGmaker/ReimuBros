package;
import abilities.AbsorbDamage;

/**
 * ...
 * @author RSGmaker
 */
class Eirin extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public var cooldown:Int;
	
	
	public function new() 
	{
		super("Eirin");
		HP = 1;
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "eirin";
		pointvalue = 300;
	}
	
	override public function attack(player:Player):Bool
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
		var D:Dynamic = game.EntityFromUID(data.UID);
		if (Std.is(D, Enemy))
		{
			var E:Enemy = D;
			if (E.flipped > 0)
			{
				E.flipped = 1;
			}
			if (E.enrageable && !E.enraged)
			{
				E.enrage();
			}
		}
		cooldown = 450;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			rewarditem = "Point";
		}
		
		if (!killed)
		{
			cooldown--;
		
		if (game.Hoster && flipped<1 && cooldown<=0)
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
						var D:Dynamic = { };
						D.UID = E.UID;
						SendCustomEvent(D);
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
	public override function bump(player:Player)
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