package;

/**
 * ...
 * @author RSGmaker
 */
class Yuyuko extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rng:MersenneTwister;
	
	public var timetofire:Int;
	
	public var rename:String;
	
	//public var HP:Int;
	
	public function new() 
	{
		super("yuyuko");
		subtype = "yuyuko";
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		HP = 1;
		pointvalue = 500;
		rename = "yuyuko";
		//rename = "okuu";
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
			//accel += 0.1;
			//mxspd += 0.5;
			pointvalue += 50;
	}
	public override function update()
	{
		if (invincibility > 0)
		{
			invincibility--;
		}
		if (!started)
		{
			started = true;
			rng = new MersenneTwister();
			var seed:UInt = Math.floor((UID * 100000)+spawns);
			rng.twist(seed, 1, 100000);
			
			rng.seed += rng.twist(rng.seed, 1, 700)[0];
			timetofire = 250 + (rng.seed % 700);
		}
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
		doingability = false;
		if (flipped <= 0)
		{
			timetofire--;
			if (timetofire < 300)
			{
				var ok = false;
				if (ground != null && ground.type == "Block")
				{
					var D:Dynamic = ground;
					var B:Block = D;
					//yuyko is only allowed to use her ability when on the end of a ledge(this way players have a chance to stop her)
					ok = (B.LeftBlock != null && !B.LeftBlock.visible) || (B.RightBlock != null && !B.RightBlock.visible);
				}
				if (ok)
				{
				Hspeed = 0;
				//visuallyEnraged = !visuallyEnraged;
				doingability = true;
				if (timetofire < 1)
				{
					if (game.Hoster)
					{
						/*var D:Dynamic = { };
						D.x = x;
						D.y = y-30;
						D.Vspeed = 0;
						D.Hspeed = Ldir * 2;
						game.SendEvent("unyucannon", D);*/
						game.SendEvent("killeveryone", null);
					}
					Ldir = -Ldir;
					rng.seed += rng.twist(rng.seed, 1, 700)[0];
					timetofire = 250 + (rng.seed % 700);
				}
				}
				else
				{
					timetofire = 300;
				}
			}
			else
			{
				visuallyEnraged = false;
			}
		}
		/*if (HP > 1)
		{
			rename = "utsuho";
		}
		else
		{
			rename = "okuu";
		}*/
		updphysics();
		//ChangeAnimation(rename);
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
		rng.seed += rng.twist(rng.seed, 1, 700)[0];
		timetofire = 250 + (rng.seed % 700);
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