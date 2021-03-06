package;
import openfl.display.Sprite;
import openfl.geom.Matrix;
import openfl.geom.Rectangle;
import openfl.geom.Point;
import openfl.display.BitmapData;
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
	public var headposition:Float=0;
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
	public var removeonlevelend:Bool = false;
	
	public var invincibility:Int;
	public var lani:String = "!undefined";
	public var maxfallspd:Float = 12;
	//default layer to put this entity on
	public var layer:Int = 1;
	public function ChangeAnimation(ani:String,reset:Bool=true,StoreImages:Bool=true)
	{
		if (ani == lani)
		{
			return;
		}
		if (image == null)
		{
			//image = new Animation(game.AL.GetAnimation(ani));
			if (StoreImages)
			{
				image = new Animation(game.AL.GetAnimation(ani));
			}
			else
			{
				image = new Animation(getbitmapdata(ani, StoreImages));
			}
			addChild(image);
			lani = ani;
		}
		else
		{
			if (StoreImages)
			{
				image.ChangeAnimation(game.AL.GetAnimation(ani), reset);
			}
			else
			{
				image.ChangeAnimation(getbitmapdata(ani, StoreImages), reset);
			}
			lani = ani;
		}
	}
	private function getbitmapdata(ani:String,StoreImages:Bool=true):Array<BitmapData>
	{
		if (StoreImages)
		{
			return game.AL.GetAnimation(ani);
		}
		else
		{
			return game.AL.getBitmapData(ani);
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
		alive = true;
		if (ani != null)
		{
			image = new Animation(game.AL.GetAnimation(ani));
			addChild(image);
		}
		fallaccel = 0.7;
		Hspeed = 0;
		Vspeed = 0;
		type = "Unknown";
		subtype = "Unknown";
		UID = Math.random();
		bonking = false;
		hitbox = null;
		hasotherhitbox = false;
		middle = 0;
		feetposition = 0;
		
		mouseEnabled = false;
	}
	//called when this client receives a custom event for this entity
	public function CustomEvent(data:Dynamic)
	{
		
	}
	//send a custom event for this entity to all players
	public function SendCustomEvent(data:Dynamic)
	{
		var D:Dynamic = { };
		D.UID = UID;
		D.data = data;
		game.SendEvent("CustomEvent", D);
	}
	public function Bonk(player:Player)
	{
		//bonked = 16;
		bonked = 6;
		bonkedby = player;
	}
	public function GetHitbox():Rectangle
	{
		if (hitbox == null)
		{
			return getBounds(game.gamestage);
		}
		else
		{
			var rct = getBounds(game.gamestage);
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
		animate();
	}
	public function nearestplayer():Player
	{
		var i = 0;
		var dist = 999999999.0;
		var ret:Player = null;
		var L = game.Players.iterator();
		while (L.hasNext())
		{
			{
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
		return ret;
	}
	//execute a rotation with crude stabilizing.(has a bit of jitter)
	public function rotatesprite(sprite:Sprite,rot:Float)
	{
		{
		var B = sprite.getBounds(game.gamestage);
		sprite.rotation = rot;
		var B2 = sprite.getBounds(game.gamestage);
		sprite.x += B.left - B2.left;
		sprite.y += B.top - B2.top;
		}
		/*var matrix:Matrix = transform.matrix;
		var rect:Rectangle = getBounds(parent);

		matrix.translate(-(rect.left + (rect.width / 2)), -(rect.top + (rect.height / 2)));
		matrix.rotate((rot / 180) * Math.PI);
		matrix.translate(rect.left + (rect.width / 2), rect.top + (rect.height / 2));
		transform.matrix = matrix;

		rotation = Math.round(rotation);*/
	}
	//execute a rotation with crude stabilizing.(has a bit of jitter)
	public function rotateentity(rot:Float)
	{
		rotatesprite(this, rot);
		/*{
		var B = getBounds(game.gamestage);
		rotation = rot;
		var B2 = getBounds(game.gamestage);
		x += B.left - B2.left;
		y += B.top - B2.top;
		}*/
		/*var matrix:Matrix = transform.matrix;
		var rect:Rectangle = getBounds(parent);

		matrix.translate(-(rect.left + (rect.width / 2)), -(rect.top + (rect.height / 2)));
		matrix.rotate((rot / 180) * Math.PI);
		matrix.translate(rect.left + (rect.width / 2), rect.top + (rect.height / 2));
		transform.matrix = matrix;

		rotation = Math.round(rotation);*/
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
		if (Vspeed < maxfallspd)
		{
			{
				Vspeed += fallaccel;
			}
			
		}
		//var G = ground;
		if (rotation == 0)
		{
		ground = game.CollisionDetectPoint(x + middle, y + feetposition+2);
		}
		else
		{
			var B = getBounds(game.gamestage);
			ground = game.CollisionDetectPoint(B.left + middle, B.bottom+2/* + (height + 2)*/);
		}
		
		/*if (Math.abs(scaleY) != Math.abs(scaleX))
		{
			if (Math.abs(scaleY) < Math.abs(scaleX))
			{
				var b = (scaleY < 0);
				scaleY = Math.abs(scaleY)+0.05;
				if (Math.abs(scaleY) > Math.abs(scaleX))
				{
					scaleY = Math.abs(scaleX);
				}
				
				if (b)
				{
					scaleY = -scaleY;
				}
			}
			else
			{
				var b = (scaleY < 0);
				scaleY = Math.abs(scaleY)-0.05;
				if (Math.abs(scaleY) < Math.abs(scaleX))
				{
					scaleY = Math.abs(scaleX);
				}
				
				if (b)
				{
					scaleY = -scaleY;
				}
			}
		}
		if (G == null && G != ground)
		{
			//do landing sound effect.
			scaleY *= 0.8;
		}*/
		
		if (game.scrollframe)
			{
				x += game.scrollspeedX;
				y += game.scrollspeedY;
			}
		if (ground != null)
		{
			if (Vspeed > 0)
			{
				bonking = false;
				Vspeed = 0;
				if (Math.abs(y - (ground.y - feetposition)) < 100)
				{
					y = ground.y - feetposition;
				}
			}
			var D:Dynamic = ground;
			if (type != "Player" && ground.type == "Block" && D.poison)
			{
				Hspeed *= 0.80;
			}
			
			
		}
		
		headbonk = null;
		if (Vspeed < 0)
		{
			//headbonk = game.CollisionDetectPoint(x + middle, y+20);
			headbonk = game.CollisionDetectPoint(x + middle, y+20+headposition);
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
		wrapped = false;
		if (x < -width && Hspeed<=0)
		{
			wrapped = true;
			x += 800+width;
		}
		//if (x > 800+width && Hspeed>=0)
		if (x > 800 && Hspeed>=0)
		{
			wrapped = true;
			//x -= 800+width+width;
			x -= 800+width;
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
	public function bump(player:Player) {
		
	}
	
}