package;
import openfl.display.Shape;

/**
 * ...
 * @author RSGmaker
 */
class Kisume extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rope:Shape;
	
	public function new() 
	{
		super("kisume");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		scaleX = 0.7;
		scaleY = 0.7;
		pointvalue = 150;
		flipped = -1;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 100;
	}
	public override function update()
	{
		if (!started)
		{
			/*darkness = new Bitmap(game.AL.GetAnimation("darkness")[0]);
			darkness.scaleX = 2;
			darkness.scaleY = 2;
			darkness.x -= darkness.width / 2;
			darkness.y -= darkness.height / 2;
			darkness.x += x + width / 2;
			darkness.y += y + height / 2;
			game.gamestage.addChild(darkness);*/
			rope = new Shape();
			rope.graphics.beginFill(0x000000);
			rope.graphics.drawRect(20, 0, 3, 600);
			rope.graphics.endFill();
			rope.cacheAsBitmap = true;
			game.gamestage.addChild(rope);
			started = true;
			
		}
		flipped = 0;
		dangerous = !killed;
		if (!killed)
		{
		var dir = Ldir;
		/*if (flipped > 0)
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
		}*/
		if (Hspeed < mxspd && dir==1)
		{
			Hspeed += accel;
			if (Hspeed > mxspd)
			{
				Hspeed = mxspd;
			}
		}
		if (Hspeed > -mxspd && dir==-1)
		{
			Hspeed -= accel;
			if (Hspeed < -mxspd)
			{
				Hspeed = -mxspd;
			}
		}
		updphysics();
		updateanimation();
		if (rope != null)
		{
			rope.x = x+0.5;
			rope.y = y - 599;
		}
		var P = game.myplayer;
		//if (P.y<y && (P.x < x) != (P.x - (P.Hspeed + P.Hspeed) < x + Hspeed+Hspeed))
		if (!P.killed && P.y < y && x-10<P.x && x+10>P.x)
		{
			game.SendEvent("Kill", UID);
		}
		
		if (ground != null)
		{
			/*if (ground.bonked > -1000 && Vspeed>=0)
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
			}*/
			
		}
			if (y > 408 && wrapped)
			{
				alive = false;
				visible = false;
				if (rope != null)
				{
					game.gamestage.removeChild(rope);
					rope = null;
				}
			}
		killable = flipped > 0;
	}
	else
	{
		if (rope != null)
		{
			game.gamestage.removeChild(rope);
			rope = null;
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
		/*if (flipped < 1)
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
		}*/
	}
	
}