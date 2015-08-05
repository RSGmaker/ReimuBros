package danmaku;
import openfl.Lib;
//import haxe.ds.HashMap;
import lime.math.Vector2;
import openfl.geom.Rectangle;
import openfl.geom.Point;
import openfl.display.Sprite;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
//import openfl.Vector;
/**
 * ...
 * @author RSGmaker
 */
class DanmakuEntity extends Entity
{
	//public var sprite:Animation;
	/*public var Hspeed:Float;
	public var Vspeed:Float;
	//public var game:Main;
	public var alive:Bool;
	//whether or not this cqn be stood on
	public var solid:Bool;
	public var dangerous:Bool;
	public var type:String;
	public var subtype:String;
	public var killed:Bool;
	//an ID used to help sync client and server data together
	public var UID:Float;
	//public var Ldir:Int;
	public var wrapped:Bool;
	public var deccel:Float;
	//use this to disable things best not sped up(eg; sound effects)
	public var catchingup:Bool;
	public var hitbox:Rectangle;
	public var image:Animation;*/
	public var frame:Int;
	//public var behavior:Int;
	public var behaviors:Array<Behavior>;
	public var HP:Int;
	//public static var angledata:Map<Float,Vector2>;
	public static var angledata:Array<Vector2>;
	public static var anglekeys:Array<Float>;
	//if touches a dangerous entity with a different team then entity should take damage if applicable.
	public var team:Int;
	//whether or not to check for collisions with dangerous objects and subtract HP when applicable
	public var harmable:Bool;
	//used for behaviors that are queued.
	public var behaviorqueue:Int;
	//a behavior sets this to true if at end of update behaviorqueue should increment by 1.
	public var progressqueue:Bool;
	public var deathoncollision:Bool;
	
	public var visuallyrotates:Bool;
	
	//public var HP:Int;
	public function new(ani:String,unique:Bool=true) 
	{
		solid = false;
		//game = main;
		alive = true;
		super(ani);
		image.x = image.width * -0.5;
		image.y = image.height * -0.5;
		//image = new Animation(GameView._this.AL.GetAnimation(ani));
		//addChild(image);
		
		//super(GameView._this.AL.GetAnimation(ani));
		//fallaccel = 0.5;
		Hspeed = 0;
		Vspeed = 0;
		type = "Unknown";
		subtype = "Unknown";
		if (unique)
		{
			UID = Math.random();
		}
		else
		{
			UID = -1;
		}
		hitbox = null;
		frame = 0;
		//behavior = -1;
		behaviors = new Array<Behavior>();
		HP = 1;
		team = 0;
		harmable = false;
		behaviorqueue = 1;
		deathoncollision = false;
	}
	public function touchingpoint(X:Float, Y:Float):Bool
	{
		return GetHitbox().containsPoint(new Point(X, Y));
	}
	override public function GetHitbox():Rectangle
	{
		if (hitbox == null)
		{
			return getBounds(GameView._this.gamestage);
		}
		else
		{
			var rct = getBounds(GameView._this.gamestage);
			var R = new Rectangle(hitbox.left + rct.left, hitbox.top + rct.top, hitbox.width, hitbox.right);
			return R;
		}
	}
	override public function CollidesWithPoint(X:Float, Y:Float):Bool
	{
		return GetHitbox().containsPoint(new Point(X, Y));
	}
	public function CollidesWithRectangle(R:Rectangle):Bool
	{
		return GetHitbox().intersects(R);
	}
	/*public function touchingdanger():Entity
	{
		var A = GameView._this.teams.keys();
		while (A.hasNext())
		{
			var T = A.next();
			if (T != team || T == 0)
			{
				var TT = GameView._this.teams[T];
		var i = 0;
		//while (i < GameView._this.entities.length)
		while (i < TT.length)
		{
			var E = TT[i];
			if (E != this && E.alive && E.dangerous && (E.team == 0 || E.team != team))
			{
				if (x - 100 < E.x && y-100 < E.y && x + 150 > E.x && y + 150 > E.y)
				{
				if (CollidesWithRectangle(E.GetHitbox()))
				{
					return E;
				}
				}
			}
			i++;
		}
		}
		}
		return null;
	}*/
	public function getangle():Float
	{
		var angle = Math.atan2(Vspeed,Hspeed);
		return angle;
	}
	public function getangletoentity(E:Entity):Float
	{
		var angle = Math.atan2(E.y - y,E.x - x);
		return angle;
	}
	public function getspeed():Float
	{
		//var dX = X1 - X2;
		//var dY = Y1 - Y2;
		/*var dX = -Hspeed;
		var dY = -Vspeed;
		var speed = dX * dX + dY * dY;*/
		return new Vector2(Hspeed, Vspeed).length;
		//var speed = Math.sqrt(Math.pow(Hspeed, 2) + Math.pow(Vspeed, 2));
		//return speed;
	}
	public static function getangledata(angle:Float):Vector2
	{
		if (angledata == null)
		{
			//var A = new Map<Float,Entity>();
			//var A = new Map<Float,Vector2>();
			angledata = new Array<Vector2>();
			anglekeys = new Array<Float>();
		}
		//var ANG = Math.round(angle+angle);
		var ANG = angle % (Math.PI + Math.PI);
		ANG = Math.round(ANG + ANG);
		var I = anglekeys.indexOf(ANG);
		
		if (I >= 0)
		{
			return angledata[I];
		}
		else
		{
			var V = new Vector2(Math.cos(angle), Math.sin(angle));
			/*var V = new Array<Float>();
			V[0] = Math.cos(angle);
			V[1] = Math.sin(angle);*/
			//angledata[angle] = V;
			var ii = anglekeys.length;
			anglekeys[ii] = ANG;
			angledata[ii] = V;
			return V;
		}
	}
	public function changeangle(newangle:Float):Vector2
	{
		//var angle = Math.atan2(Hspeed, Vspeed);
		/*while (newangle > 57.3)
		{
			newangle-= 57.3;
		}
		while (newangle < 0)
		{
			newangle += 57.3;
		}*/
		var speed = getspeed();
		//speed = 8;
		/*var V1 = getangledata(newangle);
		var HSP = V1.x * speed;
		var VSP = V1.y * speed;*/
		var HSP = Math.cos(newangle) * speed;
		var VSP = Math.sin(newangle) * speed;
		
		var V = new Vector2(HSP - Hspeed, VSP - Vspeed);
		Hspeed += V.x;
		Vspeed += V.y;
		if (visuallyrotates)
		{
			//image.rotateentity(newangle);
			rotation = newangle* (180.0 / 3.14);
			//image.rotation = newangle* (180.0 / Math.PI);
		}
		if (Math.abs(V.x) > 3 || Math.abs(V.y) > 3)
		{
			//V = null;
			return null;
		}
		else
		{
			return V;
		}
		
	}
	public function addbehavior(behave:Behavior) {
		behaviors[behaviors.length] = behave.clone();
	}
	public function addbehavior2(behave:Behavior) {
		behaviors[behaviors.length] = behave.clone(false);
	}
	public function addbehaviors(behave:Array<Behavior>) {
		var i = 0;
		while (i < behave.length)
		{
			behaviors[behaviors.length] = behave[i].clone();
			i++;
		}
	}
	public function addbehaviors2(behave:Array<Behavior>) {
		var i = 0;
		while (i < behave.length)
		{
			behaviors[behaviors.length] = behave[i].clone(false);
			i++;
		}
	}
	/*public function dobehavior() {
		switch (behavior)
		{
			case 1:
				if (HP > 0)
				{
					HP--;
				}
				else
				{
					var R = 0.04;
					var S = 1-0.003;
					alive = false;
					var A = GameView._this.AL.GetAnimation("bulletb");
					var i = 0;
					//6.283185
					//the max angle of radian is pi*2(6.283185)
					//t = (pi*2)/8
					var t = 0.785398125;
					var angle = 0.0;
					while (i < 8)
					{
						var B:Bullet = new Bullet();
						B.x = x;
						B.y = y;
						B.Vspeed = -8;
						B.changeangle(angle);
						angle += t;
						//angle += 0.002;
						B.image.ChangeAnimation(A);
						B.rotrate = R;
						B.spiral = S;
						B.rotdelay = 5;
						B.behavior = 2;
						B.HP = 60;
						GameView._this.addEntity(B);
						i++;
					}
				}
			case 2:
				if (HP > 0)
				{
					HP--;
				}
				else if (HP==0)
				{
					var D:Dynamic = this;
					var A = GameView._this.AL.GetAnimation("bulletc");
					D.rotrate *= -1.5;
					//D.rotrate = D.rotrate * -1;
					//D.rotrate = 0;
					//D.Hspeed = 0;
					//D.Vspeed = 0;
					image.ChangeAnimation(A);
					HP = -1;
				}
		}
	}*/
	public override function update():Void {
		x += Hspeed;
		y += Vspeed;
		/*if (x < -width)
		{
			x += 800+width;
		}
		if (x >800+width)
		{
			x -= 800+width;
		}*/
		image.animate();
		/*if (behavior > 0)
		{
			dobehavior();
		}*/
		var i = 0;
		while (i < behaviors.length)
		{
			if (behaviors[i].active)
			{
				behaviors[i].update(this);
			}
			i++;
		}
		if (progressqueue)
		{
			behaviorqueue++;
			progressqueue = false;
		}
		/*if (harmable && frame & 1 >0)
		{
			var E = touchingdanger();
			if (E != null)
			{
				HP--;
				if (type == "Enemy" && HP>0)
				{
					SoundManager.Play("damage.wav");
				}
				if (E.deathoncollision)
				{
					E.alive = false;
				}
			}
		}*/
		frame++;
	}
	
	/*public function nearestplayer():Player
	{
		var i = 0;
		var dist = 999999999.0;
		var ret:Player = null;
		//while (i < GameView._this.entities.length)
		var P = game.GetPlayers();
		while (i < P.length)
		{
			var E:Dynamic = P.players[i];
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
		}
		return ret;
	}*/
	/*public function rotateentity(rot:Float)
	{
		//if (rot != rotation)
		{
		var B = getBounds(GameView._this);
		rotation = rot;
		var B2 = getBounds(GameView._this);
		x += B.left - B2.left;
		y += B.top - B2.top;
		}
	}*/
	override public function updphysics()
	{
		
		/*var dir = Ldir;
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
		if (rotation == 0)
		{
		ground = GameView._this.CollisionDetectPoint(x + (Math.floor(width) >> 1), y + (height + 2));
		}
		else
		{
			var B = getBounds(GameView._this);
			ground = GameView._this.CollisionDetectPoint(B.left + (Math.floor(B.width) >> 1), B.bottom+2);
		}
		if (ground == null)
		{
			//ground = GameView._this.CollisionDetectPoint(x - (Math.floor(width) >> 1), y + height);
			//ground = GameView._this.CollisionDetectPoint(x + (Math.floor(width) >> 1), y + height);
		}
		if (ground != null)
		{
			if (Vspeed > 0)
			{
				bonking = false;
				Vspeed = 0;
				y = ground.y - height;
			}
		}
		headbonk = null;
		if (Vspeed < 0)
		{
			headbonk = GameView._this.CollisionDetectPoint(x + (Math.floor(width) >> 1), y+20);
			//headbonk = GameView._this.CollisionDetectPoint(x + (Math.floor(width) >> 1), y);
			if (headbonk != null && headbonk.platform)
			{
				headbonk = null;
			}
			if (headbonk != null)
			{
				Vspeed += fallaccel;
				Vspeed += fallaccel;
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
		}*/
	}
	override public function catchup():Void {
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
	override public function catchupsmall():Void {
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
	
}