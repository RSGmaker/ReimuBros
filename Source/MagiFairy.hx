package;
import openfl.display.Shape;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class MagiFairy extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rng:MersenneTwister;
	
	public var recharge:Int;
	
	public var timetofire:Int;
	
	public var shouldfire:Bool;
	
	public var rename:String;
	
	public var rope:Shape;
	
	public var broom:Animation;
	
	public var broombonusspeed:Float = 2.0;
	
	//public var HP:Int;
	
	public function new() 
	{
		super("magifairy");
		broom = new Animation(GameView._this.AL.GetAnimation("broom"));
		broom.y = 38;
		broom.x = -25;
		addChild(broom);
		accel = 0.5;
		deccel = 0.1;
		mxspd = 3.5+broombonusspeed;
		fallaccel = 0.4;
		maxfallspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		//scaleX = 0.7;
		//scaleY = 0.7;
		HP = 2;
		pointvalue = 500;
		rename = "magi_fairy"+"W/Items";
		//rename = CharHelper.changednapart(CharHelper.getCharPreset("magi_fairy"),10,"89");
		//rename = "okuu";
	}
	override public function CustomEvent(data:Dynamic) 
	{
		if (data.type == "shoot")
		{
		shouldfire = true;
		//recharge = 100 + rng.quick(400);
		recharge = 60 + rng.quick(260);
		//timetofire = 45;
		timetofire = 35;
		//super.CustomEvent(data);
		}
		else if (data.type == "weaken")
		{
			if (HP > 1)
			{
				HP = 1;
			}
		}
	}
	override public function attack(player:Player):Bool
	{
		HP--;
		if (HP > 0)
		{
			invincibility = 20;
		}
		return HP < 1;
	}
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 300;
	}
	override public function GetHitbox():Rectangle 
	{
		if (HP < 2)
		{
			return super.GetHitbox();
		}
		var ret = getBounds(game.gamestage);
		ret = new Rectangle(ret.x + 20, ret.y + 7, ret.width - 40, ret.height - 11);
		return ret;
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
			//recharge = 200 + rng.quick(500);
			
			//recharge = 60 + rng.quick(90);
			recharge = 20;
			//timetofire = 250 + (rng.seed % 700);
			
			if (HP > 1)
			{
			rope = new Shape();
			rope.graphics.beginFill(0x000000);
			rope.graphics.drawRect(20, 0, 3, 600);
			rope.graphics.endFill();
			rope.cacheAsBitmap = true;
			game.gamestage.addChild(rope);
			}
			else
			{
				if (broom != null)
				{
					removeChild(broom);
					broom = null;
					mxspd -= broombonusspeed;
				}
			}
		}
		//flipped = 0;
		if (flipped > 0 && HP>1)
		{
			flipped = 0;
			if (!killed)
			{
				SoundManager.Play("killenemy");
			}
			scaleY = -1;
			killed = true;
		}
		if (HP == 1)
		{
			fallaccel = 0.5;
			maxfallspd = 8;
			if (broom != null)
			{
				mxspd -= broombonusspeed;
				var N = "broom";
				if (Ldir < 0)
				{
					N = N + "F";
				}
				var B = broom.getBounds(game.gamestage);
				var P = new Particle(N);
				P.x = B.x;
				P.y = B.y;
				P.Vspeed = 9;
				P.HP = 200;
				//P.filters = FA;
				game.AddObject(P);
				
				removeChild(broom);
				broom = null;
			}
			if (rope != null)
			{
				game.gamestage.removeChild(rope);
				rope = null;
			}
		}
		if (broom != null)
		{
		if (Ldir < 0)
		{
			broom.ChangeAnimation(game.AL.GetAnimation("broomF"));
		}
		else
		{
			broom.ChangeAnimation(game.AL.GetAnimation("broom"));
		}
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
			if (shouldfire && x>-10 && x<770 && ground != null)
			{
			timetofire--;
			if (timetofire < 45)
			{
				Hspeed = 0;
				//visuallyEnraged = !visuallyEnraged;
				doingability = true;
				if (timetofire < 1)
				{
					/*if (game.Hoster)
					{
						var D:Dynamic = { };
						D.x = x;
						D.y = y-30;
						D.Vspeed = 0;
						D.Hspeed = Ldir * 2;
						game.SendEvent("unyucannon", D);
					}*/
					var spd = 7;
					var O = new Bullet();
					O.x = x;
					O.y = y+5;
					O.scaleX = 0.8;
					O.scaleY = O.scaleX;
					O.Hspeed = (spd * Ldir);
					//O.Vspeed = -4.5;
					//O.gravY = 0.13;
					//O.gravY = 0.12;
					//O.Vspeed = -spd;
					O.ChangeAnimation("magibullet");
					O.image.image_speed = 1;
					O.spin = true;
					O.spinspeed = 20.0 * Ldir;
					game.AddObject(O);
					/*if (HP > 1)
					{
						HP = 1;
					}*/
					
					shouldfire = false;
					//Ldir = -Ldir;
					//rng.seed += rng.twist(rng.seed, 1, 700)[0];
					//timetofire = 250 + (rng.seed % 700);
				}
			}
			else
			{
				visuallyEnraged = false;
			}
			}
			else
			{
				visuallyEnraged = false;
				recharge--;
				if (recharge < 1)
				{
				var P = game.myplayer;
				//var X = Math.abs(x - P.x);
				var Y = Math.abs(y - P.y);
				//if (P.ground != null && P.y < y - 64 && X < 200)
				//if (P.ground != null && ground != null && P.ground.y == ground.y)
				if (Y<100 && (y+height+10)>(P.y+P.feetposition))
				{
					if ((Ldir < 0 && P.x < x) || (Ldir > 0 && P.x > x))
					{
						var D:Dynamic = { };
						D.type = "shoot";
						SendCustomEvent(D);
					}
				}
				}
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
		if (rope != null)
		{
			//rope.x = x+0.5;
			//rope.y = y - 599;
			//rope.y = y - 570;
			
			rope.x = x + 20;
			rope.y = y - 550;
		}
		var P = game.myplayer;
		//if (P.y<y && (P.x < x) != (P.x - (P.Hspeed + P.Hspeed) < x + Hspeed+Hspeed))
		//if (!P.killed && P.y < y && x-10<P.x && x+10>P.x)
		if (HP>1 && !P.killed && P.y < y && rope.x-10<P.x && rope.x+10>P.x)
		{
			//game.SendEvent("Kill", UID);
			var D:Dynamic = { };
			D.type = "weaken";
			SendCustomEvent(D);
		}
		if (ground != null && HP < 2)
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
				D.Vspeed = -9;
				game.SendEvent("Bump", D);
				}
			}
			else
			{
				if (flipped>0 && flipped < 90)
				{
					//bounce to indicate about to recover
					Vspeed = -3;
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
	public override function bump(player:Player)
	{
		if (HP == 2 && Vspeed != -10 && player == game.myplayer)
		{
			game.SendEvent("Kill", UID);
			/*if (!killed)
			{
				SoundManager.Play("killenemy");
				killed = true;
			}*/
		}
		recharge = 70 + rng.quick(300);
		timetofire = 35;
		HP--;
		if (HP < 1)
		{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * 11;
			}
			else
			{
				flipped = 30 * 16;
			}
		}
		else
		{
			flipped = 0;
		}
		}
	}
	
}