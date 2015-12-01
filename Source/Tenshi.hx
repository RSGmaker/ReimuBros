package;

/**
 * ...
 * @author RSGmaker
 */
class Tenshi extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rock:Animation;
	
	public var rename:String;
	
	public var kicked:Bool;
	
	public function new() 
	{
		rock = new Animation(GameView._this.AL.GetAnimation("keystone"));
		rock.y = 72;
		rock.x = 10;
		addChild(rock);
		super("tenshi");
		rename = "tenshi";
		accel = 0.5;
		deccel = 0.1;
		mxspd = 3;
		Ldir = 1;
		killed = false;
		flipped = -1;
		scaleX = 0.7;
		scaleY = 0.7;
		pointvalue = 200;
		HP = 1;
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 100;
	}
	override public function kick() 
	{
		if (!kicked)
		{
			super.kick();
			var D:Dynamic = { };
			D.UID = UID;
			D.x = x;
			D.y = y;
			D.dir = game.myplayer.Ldir;
			SendCustomEvent(D);
		}
	}
	override public function CustomEvent(data:Dynamic) 
	{
		x = data.x;
		y = data.y;
		Ldir = data.dir;
		kicked = true;
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			//rock.scaleX = HP * 0.7;
			//rock.scaleY = HP * 0.7;
			rock.x = (width / 2) - (rock.width / 2)+6;
		}
		if (flipped>0)
		{
			rock.y = 30;
		}
		else
		{
			rock.y = 72;
		}
		if (HP > 0)
		{
			rename = "happytenshi";
		}
		else
		{
			rename = "tenshi";
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
		if (!kicked)
		{
			y += 15;
			if (y > 600)
			{
				alive = false;
			}
		}
		else
		{
			var dir = Ldir;
			mxspd = 15;
			if (y > 408 && wrapped)
			{
				alive = false;
				visible = false;
			}
			if (Hspeed < mxspd && dir==1)
			{
				Hspeed = mxspd;
			}
			if (Hspeed > -mxspd && dir==-1)
			{
				Hspeed = -mxspd;
			}
			updphysics();
			updateanimation(rename);
			if (bonkedby == game.myplayer)
			{
			var enemy = game.CollisionDetectTouchEnemy(this);
			if (enemy != null && !enemy.killed && enemy.invincibility<=0)
			{
				game.SendEvent("Kill", enemy.UID);
			}
			var danger = game.CollisionDetectTouchDangerous(this);
			var DD:Dynamic = danger;
			if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
			{
				game.SendEvent("Kill", danger.UID);
			}
			}
		}
		
	}
	}
	public override function bump(player:Player)
	{
		if (HP > 0)
		{
			HP--;
			//rock.scaleX = HP * 0.7;
			//rock.scaleY = HP * 0.7;
			rock.x = (width / 2) - (rock.width / 2)+6;
		}
		else
		{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * 7;
			}
			else
			{
				flipped = 30 * 11;
			}
		}
		else
		{
			flipped = 0;
		}
		updateanimation(rename);
		rock.x = (width / 2) - (rock.width / 2)+6;
		}
	}
	
}