package;
import openfl.display.Bitmap;

/**
 * ...
 * @author RSGmaker
 */
class Mamizou extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	public var timer:Int;
	public var rng:MersenneTwister;
	public var flipping:Bool;
	public var countdown:Int;
	public var rename:String;
	public var have:Bool;
	public var isChar:Bool;
	public var disguised:Bool;
	public var frames:Int;
	public var unlock:Int;
	public var alternate:Bool;
	public var tail:Bitmap;
	public function new() 
	{
		super("Mamizou");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		HP = 0;
		rename = "reimu";
		frames = 0;
		alternate = false;
		isChar = false;
		disguised = false;
		tail = null;
		tail = new Bitmap(game.AL.GetAnimation("mamizoutail")[0]);
		tail.scaleX = 0.7;
		tail.scaleY = tail.scaleX;
		tail.visible = false;
		/*addChild(tail);
		if (image != null)
		{
			removeChild(image);
			addChild(image);
		}*/
		
		useotherhitbox = true;
	}
	
	public override function enrage()
	{
	}
	public override function update()
	{
		if (rng == null)
		{
			rng = new MersenneTwister();
			rng.seed = Math.floor(UID * 100000);
			if (rng.twist(rng.seed, 1, 100)[0] < 50)
			{
			unlock = rng.twist(rng.seed, 1, Player.characters.length)[0];
			
			rename = Player.characters[unlock];
			if (rng.twist(rng.seed, 1, 100)[0] < 30)
			{
				var A = game.AL.GetAnimation(rename+"ALT");
				if (A != null && A.length > 0)
				{
					rename = rename+"ALT";
					alternate = true;
				}
			}
			have = Main._this.savedata.data.unlock[unlock];
			if (!have && alternate)
			{
				have = Main._this.savedata.data.alts[unlock];
			}
			isChar = true;
			//this.scaleX = 0.8;
			//this.scaleY = 0.8;
			}
			else
			{
				isChar = false;
				if (rng.twist(rng.seed, 1, 100)[0] < 60)
				{
					rename = "Point";
				}
				else
				{
					rename = "1up";
					this.scaleX = 0.5;
					this.scaleY = 0.5;
					tail.scaleX = 1.5;
					tail.scaleY = tail.scaleX;
				}
			}
			disguised = true;
		}
		
		frames++;
		var S = rename;
		if (isChar)
		{
		if (frames & 1 > 0 && !have)
		{
			S = S + "U";
		}
		if (have)
		{
			S = S + "U";
		}
			this.scaleX = 0.8;
			this.scaleY = 0.8;
		}
		enraged = false;
		
		if (!killed)
		{
		var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
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
		flipped = 0;
		var H = feetposition;
		updphysics();
		updateanimation(S);
		
		
		var B = image.getBounds(game);
		feetposition = B.height;
		middle = B.width / 2;
		if (hasotherhitbox)
		{
			y += H - feetposition;
		}
		hasotherhitbox = true;
		if (!disguised)
		{
			if (tail.visible)
			{
				tail.visible = false;
				removeChild(tail);
			}
		}
		else
		{
			if (!tail.visible)
			{
				tail.visible = true;
				addChild(tail);
				if (image != null)
				{
					removeChild(image);
					addChild(image);
				}
			}
		}
		
		if (tail.visible)
		{
			tail.y = image.height - tail.height;
			tail.x = -tail.width / 2;
			if (isChar)
			{
				tail.x += (image.width / 2);
				tail.y -= (image.height * 0.1);
			}
			if (Ldir < 0)
			{
				if (isChar)
				{
					//tail.x += (image.width / 2) * scaleX;
					tail.x += tail.x;
				}
				else
				{
					tail.x += image.width;
				}
				tail.bitmapData = game.AL.GetAnimation("mamizoutailF")[0];
			}
			else
			{
				tail.bitmapData = game.AL.GetAnimation("mamizoutail")[0];
			}
		}
		flipped = F;
		if (flipped > 0)
		{
			this.rotation = 90;
		}
		else
		{
			this.rotation = 0;
		}
		
		if (ground != null)
		{
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				if (game.myplayer == ground.bonkedby)
				{
				var D:Dynamic = { };
				D.UID = UID;
				D.x = x;
				D.y = y-(height/2);
				D.Hspeed = Hspeed * 0.5;
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
					HP = 0;
				}
			}
			
		}
			if ((y > 408 && wrapped) || y>800)
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
	if (!alive && game.myplayer == bonkedby)
	{
		game.unlockcharacter("mamizou");
	}
	}
	public override function bump(player:Player)
	{
		if (disguised)
		{
			rename = "mamizou";
			disguised = false;
			isChar = false;
			this.scaleX = 0.8;
			this.scaleY = 0.8;
		}
		else
		{
		if (HP > 0)
		{
			HP--;
		}
		else
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
			HP = 0;
		}
		}
		}
	}
	
}