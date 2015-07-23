package;
import openfl.display.Bitmap;

/**
 * ...
 * @author RSGmaker
 */
class Rumia extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	public var darkness:Bitmap;
	//public var started:Bool;
	public function new() 
	{
		super("rumia");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		started = false;
		pointvalue = 500;
		this.scaleX = 0.8;
		this.scaleY = 0.8;
		
		//this.addChild(darkness);
	}
	/*public override function enrage()
	{
		accel += 0.2;
		mxspd += 2;
	}*/
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
	}
	public override function update()
	{
		if (!started)
		{
			darkness = new Bitmap(game.AL.GetAnimation("darkness")[0]);
			darkness.scaleX = 2;
			darkness.scaleY = 2;
			darkness.x -= darkness.width / 2;
			darkness.y -= darkness.height / 2;
			darkness.x += x + width / 2;
			darkness.y += y + height / 2;
			//darkness.blendMode = flash.display.BlendMode.MULTIPLY;
			//darkness.blendMode = flash.display.BlendMode.INVERT;
			game.addChild(darkness);
			started = true;
			/*var i = 0;
			while (i < rank)
			{
				accel += 0.1;
				mxspd += 0.5;
				i++;
			}*/
			
		}
		if (darkness != null && enraged)
		{
			if (darkness.scaleX == 2)
			{
			darkness.scaleX = 8;
			darkness.scaleY = 8;
			darkness.x -= darkness.width / 2;
			darkness.y -= darkness.height / 2;
			darkness.x += x + width / 2;
			darkness.y += y + height / 2;
			}
		}
		//y += 1;
		
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
		var F = flipped;
		var LX = x;
		var LY = y;
		flipped = 0;
		updphysics();
		updateanimation();
		flipped = F;
		if (darkness != null)
		{
			darkness.x += (x - LX);
			darkness.y += (y - LY);
		}
		if (flipped > 0)
		{
			this.rotation = 90;
		}
		else
		{
			this.rotation = 0;
		}
		/*if (flipped>0)
		{
			scaleY = -1;
		}
		else
		{
			scaleY = 1;
		}*/
		
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
			if (y > 408 && wrapped)
			{
				alive = false;
				visible = false;
				if (darkness != null)
		{
			game.removeChild(darkness);
			darkness = null;
		}
			}
		killable = flipped > 0;
	}
	else
	{
		if (darkness != null)
		{
			game.removeChild(darkness);
			darkness = null;
		}
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