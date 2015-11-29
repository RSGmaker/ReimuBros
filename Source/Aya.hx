package;

/**
 * ...
 * @author RSGmaker
 */
class Aya extends Enemy
{
	
	public var accel:Float;
	
	public var mxspd:Float;
	//public var dissappearing:Bool;
	public var rename:String;
	public function new() 
	{
		super("aya");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		HP = 1;
		//dissappearing = false;
		pointvalue = 500;
		rename = "aya";
	}
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 100;
	}
	override public function attack():Bool 
	{
		/*if (dissappearing)
		{
			return false;
		}
		if (HP > 1)
		{
			HP--;
			dissappearing = true;
			Vspeed = 0;
			alpha = 0.6;
			return false;
		}*/
		invincibility = 6;
		return false;
		return true;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			//var items:Array<String> = ["Camera"];
			var D:Dynamic = { };
			D.UID = UID;
			D.item = "Camera";
			//D.item = items[rng.quick(items.length)];
			game.SendEvent("AttachItem", D);
		}
		/*if (!dissappearing)
		{
			if (alpha < 1)
			{
				alpha += 0.15;
			}
		}
		if (dissappearing)
		{
			if (alpha > 0)
			{
				alpha -= 0.15;
			}
			if (alpha <= 0)
			{
				x += Ldir * 96;
				dissappearing = false;
			}
		}*/
		if (invincibility > 0)
		{
			x += Hspeed;
			//y += Vspeed;
			
			x += Hspeed;
			//y += Vspeed;
			
			x += Hspeed;
			//y += Vspeed;
			
			x += Hspeed;
			invincibility--;
		}
		
		/*var A = game.Players.iterator();
		var ok = false;
		if (HP > 1)
		{
		while (A.hasNext())
		{
			var E = A.next();
			if (E.alive && !E.killed)
			{
				if (Math.abs(E.y - y) < 50 && E.y < y)
				{
					if (Ldir < 0)
					{
						if (Math.abs((E.x+96) - x) < 32)
						{
							dissappearing = true;
							alpha = 0.6;
							HP--;
						}
					}
					else
					{
						if (Math.abs((E.x-96) - x) < 32)
						{
							dissappearing = true;
							alpha = 0.6;
							HP--;
						}
					}
				}
			}
		}
		}*/
		/*if (HP > 1)
		{
			rename = "redeyedudongein";
		}
		else
		{
			rename = "udongein";
		}*/
		
		if (!killed)
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
	public override function bump()
	{
		if (invincibility>0)
		{
			Vspeed = 0;
			return;
		}
		if (HP > 1)
		{
			HP--;
			//dissappearing = true;
			Vspeed = 0;
			//alpha = 0.6;
			return;
		}
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