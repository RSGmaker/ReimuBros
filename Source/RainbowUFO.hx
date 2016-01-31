package;
import openfl.display.Bitmap;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class RainbowUFO extends Enemy// extends UFO
{
	public var points:Int;
	public var maxpointsneeded:Int = 7;
	public var pointsneeded:Int;
	public var bonuscolor:String;
	public var progressbar:Sprite;
	public var lastprogress:Float = 0;
	
	public var bullets:Int;
	public var bulletsperpoint:Int = 3;
	public var FA:Array<flash.filters.BitmapFilter>;
	
	public var ascend:Bool;
	public var iter:Int;
	public var rng:MersenneTwister;
	public var rot:Float;
	public var rename:String;
	public var ufotype:String;
	public var fuel:Int;
	public static var HB = new Rectangle(9, 9, 10, 10);
	public var reducetime:Int;
	public var movement:Float;
	public function new() 
	{
		super("UFO");
		subtype = "RainbowUFO";
		points = Math.ceil(maxpointsneeded * 1.6);
		pointsneeded = maxpointsneeded;
		bonuscolor = "None";
		
		///needtokill = true;
		reward = false;
		bullets = 0;
		
		FA = new Array<flash.filters.BitmapFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 12;
		AB.blurY = 12;
		//AB.color = 0xFFFFFF;
		AB.color = 0xFF9999;
		AB.strength = 2.5;
		FA[FA.length] = AB;
		
		image.filters = FA;
		
		Ldir = 1;
		
		movement = 2;
		enrageable = false;
		//filters = FA;
	}
	override public function attack(player:Player):Bool
	{
		//return super.attack();
		return false;
	}
	private function updateprogressbar()
	{
		if (!progressbar.visible)
		{
			return;
		}
		//var RS = roundstarted;
		var prct = 1.0-(pointsneeded / maxpointsneeded);
		/*if (lvllogic != null)
		{
			prct = lvllogic.updateprogressbar();
		}
		if (prct < 0)
		{
			prct = 0;
		}
		if (prct > 1)
		{
			prct = 1;
		}*/
		var G = progressbar.graphics;
		//var C = 0x22EE66;
		var C = 0x2266EE;
		if (prct > lastprogress)
		{
			//C = 0xAAFFCC;
			C = 0xAACCFF;
		}
		if (prct >= 1)
		{
			lastprogress = 1;
			//C = 0xFFFFFF;
			C = 0xAAAAFF;
		}
		if (prct != lastprogress)
		{
			if (prct > lastprogress)
			{
				lastprogress += 0.0075;
				if (lastprogress > prct)
				{
					lastprogress = prct;
				}
				prct = lastprogress;
			}
			else
			{
				lastprogress = prct;
			}
		}
		//if (isNaN(prct))
		if (!(prct>=0 && prct<=1))
		{
			prct = 1;
		}
		var X = 100 * prct;
		X = 100 - X;
		G.clear();
		//G.beginFill(0, 0.4);
		//G.beginFill(0x00FFFF, 1);
		G.beginFill(0x000000, 1);
		//G.drawRoundRect(12, 5, 106, 15,5);
		G.drawRoundRect(0, 5, 106, 15,5);
		G.endFill();
		//G.beginFill(0x99CC22, 1);
		G.beginFill(C, 1);
		G.drawRoundRect(X+3, 8, 100-X, 9,5);
		//G.drawRoundRect(X+15, 8, 100-X, 9,5);
		//G.drawRoundRect(20, 20, X, 9,5);
		G.endFill();
		
	}
	override public function enrage() 
	{
		//super.enrage();
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		alive = false;
		killed = true;
		SoundManager.Play("getbonus");
		if (game.Hoster)
		{
			if (bonuscolor == "None")
			{
				var D:Dynamic = { };
							
				D.type = "Point";
				D.UID = Math.random();
				D.x = x;
				D.y = y+32;
				//D.platform = UID;
				if (Math.random()>0.5)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
				
				//
				var D:Dynamic = { };
							
				D.type = "UFOItem";
				D.UID = Math.random();
				D.x = x;
				D.y = y + 32;
				//D.changes = true;
				//D.color = bonuscolor;
				
				if (Math.random()>0.5)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
			}
			else if (bonuscolor == "Blue")
			{
				var D:Dynamic = { };
							
				D.type = "GiantPoint";
				D.UID = Math.random();
				D.x = x;
				D.y = y+32;
				//D.platform = UID;
				if (Math.random()>0.5)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
				
				D = { };
							
				D.type = "UFOItem";
				D.UID = Math.random();
				D.x = x;
				D.y = y + 32;
				D.changes = false;
				D.color = bonuscolor;
				//D.platform = UID;
				if (Math.random()>0.5)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
			}
			else if (bonuscolor == "Green")
			{
				var L:Array<String> = ["Myon","Camera","MiniHakkero","Spellcard"];
				var D:Dynamic = { };
							
				//D.type = L[Std.int(Math.random() * L.length)];
				
				D.type = EntityItem.getitem("list:ufo");
				D.UID = Math.random();
				D.x = x;
				D.y = y + 32;
				D.changes = false;
				D.color = bonuscolor;
				//D.platform = UID;
				/*if (false)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}*/
				D.Ldir = 0;
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
				
				//////
				D = { };
							
				//D.type = L[Std.int(Math.random() * L.length)];
				
				D.type = EntityItem.getitem("list:ufo");
				D.UID = Math.random();
				D.x = x+48;
				D.y = y + 32;
				D.changes = false;
				D.color = bonuscolor;
				//D.platform = UID;
				/*if (true)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}*/
				D.Ldir = 0;
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
				
				//////
				
				D = { };
							
				D.type = "UFOItem";
				D.UID = Math.random();
				D.x = x;
				D.y = y + 32;
				D.changes = false;
				D.color = bonuscolor;
				//D.platform = UID;
				if (Math.random()>0.5)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
			}
			else if (bonuscolor == "Red")
			{
				var D:Dynamic = { };
							
				D.type = "Mini1up";
				D.UID = Math.random();
				D.x = x;
				D.y = y + 32;
				D.changes = false;
				D.color = bonuscolor;
				//D.platform = UID;
				if (Math.random()>0.5)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
				
				///
				D = { };
							
				D.type = "UFOItem";
				D.UID = Math.random();
				D.x = x;
				D.y = y + 32;
				D.changes = false;
				D.color = bonuscolor;
				//D.platform = UID;
				if (Math.random()>0.5)
				{	
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
			}
		}
	}
	override public function update() 
	{
		invincibility = 100;
		//super.update();
		if (rng == null)
		{
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			ascend = rng.twist(seed, 1, 100)[0] > 50;
			var R = rng.twist(seed, 1, 10)[0];
			if (R > 6)
			{
				ufotype = "Red";
			}
			else if (R < 3)
			{
				ufotype = "Green";
			}
			else
			{
				ufotype = "Blue";
			}
			iter = 60;
			fuel = 2400;
			reducetime = 240;
			if (bonuscolor != "None")
			{
				if (bonuscolor == "Green")
				{
					movement *= 1.35;
					reducetime += 20;
					bulletsperpoint++;
				}
			}
			//iter = 30 + rng.twist(0, 1, 240)[0];
			//fuel = 90 + rng.twist(0, 1, 1500)[0];
			if (game.totalenemies < 3)
			{
				iter -= 15;
			}
			
			progressbar = new Sprite();
			progressbar.x = -11;
			progressbar.y = 50;
			
			var PB = new Bitmap(game.AL.GetAnimation("Point")[0]);
			PB.scaleX = 0.6;
			PB.scaleY = PB.scaleX;
			PB.y = -5;
			PB.x = -5;
			progressbar.addChild(PB);
			addChild(progressbar);
			/*if (game.RoundType == GameView.TypeofRound.EventDanmaku)
			{
				reducetime += 30;
				fuel += 150;
			}*/
			/*if (reducetime > 180)
			{
				reducetime = 180;
			}*/
		}
		if (game.ufoseal < 120)
		{
			game.ufoseal = 120;
		}
		updateprogressbar();
		if (bonuscolor != "None")
		{
			ufotype = bonuscolor;
		}
		if ((fuel & 1) > 0 && bonuscolor=="None")
		{
		if (ufotype == "Red")
		{
			ufotype = "Green";
		}
		else if (ufotype == "Green")
		{
			ufotype = "Blue";
		}
		else
		{
			ufotype = "Red";
		}
		}
		if (movement > 0 && x > 700)
		{
			movement = -movement;
		}
		if (movement < 0 && x <= 0)
		{
			movement = -movement;
		}
		rename = ufotype + "ufo";
		animate();
		killed = false;
		dangerous = false;
		//dangerous = true;
		
		killable = false;
		x += movement;
		/*if (fuel>0 && game.myplayer.GetHitbox().intersects(GetHitbox()))
		{
			SendCustomEvent(null);
		}*/
		if (x < -width && movement<0)
		{
			x = 900;
		}
		if (x > 900 && movement>0)
		{
			x = -width;
		}
		doingability = false;
		if (fuel > 0)
		{
			fuel--;
		if (y == 10 && x>0 && x<800)
		{
			if (pointsneeded < 1)
			{
				if (game.Hoster)
				{
					SendCustomEvent(null);
				}
			}
		if (iter > 0)
		{
			iter --;
			if (iter < 12)
			{
				//visuallyEnraged = !visuallyEnraged;
				doingability = true;
			}
			if (iter < 4)
			{
				visuallyEnraged = true;
			}
		}
		else
		{
			{
				iter = 20 + rng.twist(0, 1, 270 - reducetime)[0];
				visuallyEnraged = false;
				//if (rng.bool())
				if (rng.quick(100)<30)
				{
					movement = -movement;
				}
			}
			if (game.Hoster)
			{
				var BP = bulletsperpoint;
				if (game.totalenemies < 4)
				{
					//if low on enemies, spawn point items sooner.
					BP--;
					/*if (game.totalenemies < 2)
					{
						BP--;
					}*/
				}
				if (/*Math.random() < 0.7 || */points<1 || bullets<BP)
				{
					var D:Dynamic = { };
					D.UID = UID;
					bullets++;
					game.SendEvent("UFOStrike", D);
					
				}
				else
				{
					bullets = 0;
					var D:Dynamic = { };
							
					D.type = "Point";
					D.UID = Math.random();
					D.x = 0;
					D.y = 32;
					D.platform = UID;
					if (Math.random()>0.5)
					{	
						D.Ldir = -1;
					}
					else
					{
						D.Ldir = 1;
					}
					//D.x = E.x;
					//D.y = E.y;
					game.SendEvent("SpawnItem", D);
				}
			}
		}
		}
		else
		{
			if (y < 10)
			{
				y++;
			}
		}
		}
		else
		{
			y--;
			visuallyEnraged = false;
			if (y < -200)
			{
				if (alive)
				{
					game.ufos--;
				}
				alive = false;
				killed = true;
			}
		}
		{
		enraged = false;
		updateanimation(rename);
		enraged = true;
		
		/*if (ground != null)
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
			
		}*/
			/*if (wrapped)
			{
				//despawn after hitting any edge
				killed = true;
				alive = false;
				visible = false;
			}*/
	}
	}
}