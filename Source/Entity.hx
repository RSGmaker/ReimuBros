package;
import openfl.display.Sprite;
import openfl.geom.Rectangle;
import openfl.geom.Point;
/**
 * ...
 * @author RSGmaker
 */
//class Entity extends Animation
class Entity extends Sprite
{
	//public var sprite:Animation;
	public var Hspeed:Float;
	public var Vspeed:Float;
	//public var game:Main;
	public var alive:Bool;
	//whether or not this cqn be stood on
	public var solid:Bool;
	//whether or not this can be jumped through(only effects solids)
	public var platform:Bool;
	public var bonked:Int;
	public var bonkedby:Entity;
	
	public var dangerous:Bool;
	
	//i had trouble figuring out how to detect what class instances are, so i used type and subtype to get around this issue.
	public var type:String;
	public var subtype:String;
	
	public var killed:Bool;
	//an ID used to help sync client and server data together
	public var UID:Float;
	//last direction, used for visuals and deciding where basic entities move.
	public var Ldir:Int;
	public var ground:Entity;
	public var headbonk:Entity;
	public var wrapped:Bool;
	public var deccel:Float;
	//whether or not this is detectable for touch(touch is whether or not non player entities bounce off eachother)
	public var touchable:Bool;
	//use this to disable things best not sped up(eg; sound effects)
	public var catchingup:Bool;
	public var fallaccel:Float;
	public var bonking:Bool;
	public var hitbox:Rectangle;
	//whether or not if this solid object reduces player's traction(accel is halved basicly)
	public var icy:Bool;
	
	public var useotherhitbox:Bool;
	public var hasotherhitbox:Bool;
	public var feetposition:Float;
	public var middle:Float;
	
	public var myMyon:MyonItem;
	
	public var headbounce:Bool = true;
	
	//can a player do an interaction with this entity(set to false if it NEVER has an interaction)
	public var interactable:Bool = false;
	//if the interactable entity currently can be interacted with.
	public var readyinteract:Bool = false;
	//what the player's nameplate says when touching this interactable entity(when ready).
	public var interacttext:String = null;
	public var image:Animation = null;
	public var game:GameView;
	
	public var invincibility:Int;
	public function ChangeAnimation(ani:String)
	{
		if (image == null)
		{
			image = new Animation(game.AL.GetAnimation(ani));
			addChild(image);
		}
		else
		{
			image.ChangeAnimation(game.AL.GetAnimation(ani));
		}
	}
	public function animate()
	{
		if (image != null)
		{
			image.animate();
		}
	}
	public function new(ani:String) 
	{
		super();
		game = GameView._this;
		invincibility = 0;
		touchable = false;
		solid = false;
		platform = false;
		bonked = -1000;
		//game = main;
		alive = true;
		if (ani != null)
		{
			image = new Animation(game.AL.GetAnimation(ani));
			addChild(image);
		}
		//super(game.AL.GetAnimation(ani));
		//fallaccel = 0.5;
		fallaccel = 0.7;
		Hspeed = 0;
		Vspeed = 0;
		type = "Unknown";
		subtype = "Unknown";
		UID = Math.random();
		bonking = false;
		hitbox = null;
		hasotherhitbox = false;
		useotherhitbox = false;
		middle = 0;
		feetposition = 0;
		
	}
	public function Customevent(data:Dynamic)
	{
		
	}
	public function GetHitbox():Rectangle
	{
		if (hitbox == null)
		{
			return getBounds(game);
		}
		else
		{
			var rct = getBounds(game);
			var R = new Rectangle(hitbox.left + rct.left, hitbox.top + rct.top, hitbox.width, hitbox.right);
			return R;
		}
	}
	public function CollidesWithPoint(X:Float, Y:Float):Bool
	{
		return GetHitbox().containsPoint(new Point(X, Y));
	}
	public function interact(P:Player):Void {
		
	}
	public function update():Void {
		//x += Hspeed;
		//y += Vspeed;
		
		/*if (x < -width)
		{
			x += 800+width;
		}
		if (x >800+width)
		{
			x -= 800+width;
		}*/
		animate();
	}
	public function nearestplayer():Player
	{
		var i = 0;
		var dist = 999999999.0;
		var ret:Player = null;
		//var L = game.GetPlayers();
		var L = game.Players.iterator();
		while (L.hasNext())
		{
			//var E:Dynamic = L[i];
			//if (E.type == "Player")
			{
				//var P:Player = E;
				//var P:Player = L[i];
				var P:Player = L.next();
				var D = Math.abs(x - P.x) + Math.abs(y - P.y);
				if (D < dist)
				{
					ret = P;
					dist = D;
				}
			}
			i++;
		}
		/*while (i < game.entities.length)
		{
			var E:Dynamic = game.entities[i];
			if (E.type == "Player")
			{
				var P:Player = E;
				var D = Math.abs(x - P.x) + Math.abs(y - P.y);
				if (D < dist)
				{
					ret = E;
					dist = D;
				}
			}
			i++;
		}*/
		return ret;
	}
	//execute a rotation with crude stabilizing.(has a bit of jitter)
	public function rotateentity(rot:Float)
	{
		//if (rot != rotation)
		{
		var B = getBounds(game);
		rotation = rot;
		var B2 = getBounds(game);
		x += B.left - B2.left;
		y += B.top - B2.top;
		}
	}
	public function updphysics()
	{
		if (useotherhitbox)
		{
		if (!hasotherhitbox)
		{
			hasotherhitbox = true;
			middle += (Math.floor(width) >> 1);
			feetposition += (height);
		}
		}
		else
		{
			middle = (Math.floor(width) >> 1);
			feetposition = (height);
		}
		var dir = Ldir;
		if (Hspeed > 0)
		{
			dir = 1;
		}
		if (Hspeed < 0)
		{
			dir = -1;
		}
		if (Hspeed > 0)
		{
			Hspeed -= deccel;
			if (Hspeed < 0)
			{
				Hspeed = 0;
			}
		}
		if (Hspeed < 0)
		{
			Hspeed += deccel;
			if (Hspeed > 0)
			{
				Hspeed = 0;
			}
		}
		//if (Vspeed < 10)
		if (Vspeed < 12)
		{
			{
				Vspeed += fallaccel;
			}
			
		}
		//if (rotationZ == 0)
		//var game = game;
		if (rotation == 0)
		{
		ground = game.CollisionDetectPoint(x + middle, y + feetposition+2);
		}
		else
		{
			var B = getBounds(game);
			ground = game.CollisionDetectPoint(B.left + middle, B.bottom+2/* + (height + 2)*/);
		}
		if (ground == null)
		{
			//ground = game.CollisionDetectPoint(x - (Math.floor(width) >> 1), y + height);
			//ground = game.CollisionDetectPoint(x + (Math.floor(width) >> 1), y + height);
		}
		if (ground != null)
		{
			if (Vspeed > 0)
			{
				bonking = false;
				Vspeed = 0;
				y = ground.y - feetposition;
			}
		}
		headbonk = null;
		if (Vspeed < 0)
		{
			headbonk = game.CollisionDetectPoint(x + middle, y+20);
			//headbonk = game.CollisionDetectPoint(x + (Math.floor(width) >> 1), y);
			if (headbonk != null && headbonk.platform)
			{
				headbonk = null;
			}
			if (headbonk != null)
			{
				if (headbounce)
				{
					Vspeed += fallaccel;
					Vspeed += fallaccel;
				}
				if (type != "Player")
				{
					Vspeed = 0;
				}
				if (!bonking)
				{
					bonking = true;
				}
				else
				{
					//prevent headbonk spam
					headbonk = null;
				}
			}
		}
		
		x += Hspeed;
		if ((headbonk==null && !bonking) || Vspeed > 0)
		{
			y += Vspeed;
		}
		wrapped = false;
		if (x < -width)
		{
			wrapped = true;
			x += 800+width;
		}
		if (x > 800+width)
		{
			wrapped = true;
			x -= 800+width+width;
		}
	}
	//obsolete multiplayer sync code(current netplay code is near instant results so we no longer have to account for massive delays)
	public function catchup():Void {
		var i = 0;
		catchingup = true;
		//while (i < 11)
		/*while (i < 4)
		{
			update();
			i += 1;
		}*/
		catchingup = false;
	}
	public function catchupsmall():Void {
		var i = 0;
		catchingup = true;
		//while (i < 5)
		/*while (i < 2)
		{
			update();
			
			i += 1;
		}*/
		catchingup = false;
	}
	public function bump() {
		
	}
	
}