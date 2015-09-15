package;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.geom.ColorTransform;
import openfl.geom.Point;

/**
 * ...
 * @author RSGmaker
 */
class LaserBeam extends Entity
{
	public var ray:Sprite;
	public var colorray:Shape;
	public var whiteray:Shape;
	public var hue:Int;
	public var started:Bool;
	public var Size:Float;
	public var Time:Int;
	public var antiplayer:Bool;
	public var antienemy:Bool;
	public var user:Player;
	public function new() 
	{
		super("black");
		visible = false;
		//x = 0;
		scaleX = 800;
		scaleY = 10;
		
		ray = new Sprite();
		colorray = new Shape();
		ray.addChild(colorray);
		whiteray = new Shape();
		ray.addChild(whiteray);
		
		game.gamestage.addChild(ray);
		hue = 0;
		started = false;
		
		Size = 0.1;
		Time = 10;
		type = "Bullet";
	}
	
	override public function update():Void 
	{
		super.update();
		/*if (ray != null)
		{
		if (!started)
		{
			ray.x = x;
			ray.y = y;
			started = true;
		}
		Time--;
		ray.scaleY = Size;
		if (Time > 60)
		{
			Size+= 0.1;
		}
		else
		{
			Size -= 0.04;
		}
		if (Size > 1)
		{
			Size = 1;
			ray.y = y;
			if (game.thegiant.active && game.thegiant.rotation == 0)
			{
				game.thegiant.tipover();
			}
		}
		else
		{
			ray.y = y + (80 * (1 - Size));
		}
		if (Size < 0)
		{
			Size = 0;
			game.gamestage.removeChild(ray);
			ray = null;
			alive = false;
			game.yuukaactive = false;
		}
		colorray.graphics.clear();
		hue += 10;
		if (hue >= 360)
		{
			hue -= 360;
		}
		var c =  cvn(hue, 0.7, 0.7);*/
		ray.x = x;
		ray.y = y;
		Time--;
		if (Time <= 0)
		{
			game.gamestage.removeChild(ray);
			ray = null;
			alive = false;
		}
		var c = 0xFFFF00;
		colorray.graphics.clear();
		//colorray.graphics.beginFill(c[0] <<16 | c[1] <<8 | c[2]);
		colorray.graphics.beginFill(c);
		colorray.graphics.drawRect(0, 0, 800, 10);
		colorray.graphics.endFill();
		whiteray.graphics.clear();
		whiteray.graphics.beginFill(0xffffff);
		whiteray.graphics.drawRect(0, 2, 800, 6);
		whiteray.graphics.endFill();
		var T:GameView = game;
		var B = getBounds(T.gamestage);
		var P = game.myplayer;
		//if (Size >= 1)
		{
		//if (antiplayer && !P.killed && B.containsPoint(new Point(P.x+20, P.y+40)))
		if (antiplayer && !P.killed && B.intersects(P.getBounds(game)))
		{
			if (P.invincibility<=0)
			{
				game.SendEvent("PlayerDeath", P.myMyon != null);
			}
		}
		if (antienemy && ((game.Hoster && user==null) || (user != null && user.isme)))
		{
			var i = 0;
			while (i <T.activeEnemies.length)
			{
				var E = T.activeEnemies[i];
				//if (B.containsPoint(new Point(E.x, E.y)) && E.invincibility<=0)
				//if (B.containsPoint(new Point(E.x, E.y)) && E.invincibility<=0)
				if (B.intersects(E.GetHitbox()) && E.invincibility<=0)
				{
					game.SendEvent("Kill", E.UID);
				}
				i++;
			}
		}
		}
		
	}
	
}