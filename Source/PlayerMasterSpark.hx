package;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.geom.ColorTransform;
import openfl.geom.Point;
/**
 * ...
 * @author RSGmaker
 */
class PlayerMasterSpark extends Entity
{

	//public var ray:Sprite;
	public var colorray:Shape;
	public var whiteray:Shape;
	public var hue:Int;
	public var started:Bool;
	public var Size:Float;
	public var Time:Float;
	public var user:Entity;
	public function new() 
	{
		super("black");
		visible = true;
		x = 0;
		//scaleX = 800;
		//scaleY = 160;
		width = 800;
		height = 240;
		//scaleY = 2;
		//ray = new Sprite();
		colorray = new Shape();
		addChild(colorray);
		whiteray = new Shape();
		addChild(whiteray);
		
		//game.addChild(ray);
		hue = 0;
		started = false;
		
		Size = 0.1;
		Time = 210;
		type = "PlayerMasterSpark";
	}
	override public function update():Void 
	{
		width = 800;
		height = 240;
		//scaleY = 2;
		super.update();
		{
		if (!started)
		{
			started = true;
		}
		x = user.x;
		if (user.Ldir > 0)
		{
			x += user.width;
			scaleX = 1;
		}
		if (user.Ldir < 0)
		{
			//x -= 800;
			scaleX = -1;
		}
		//y = user.y-40;
		y = user.y-80;
		//Time--;
		Time-= 0.75;
		scaleY = Size;
		//if (Time > 60)
		//if (Time > 300)
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
			//ray.y = y;
			if (game.thegiant.active && game.thegiant.rotation == 0)
			{
				game.thegiant.tipover();
			}
		}
		else
		{
			//ray.y = y + (80 * (1 - Size));
			y+=(80 * (1 - Size));
		}
		if (Size < 0)
		{
			Size = 0;
			//game.removeChild(ray);
			//ray = null;
			alive = false;
			//game.yuukaactive = false;
		}
		colorray.graphics.clear();
		hue += 10;
		if (hue >= 360)
		{
			hue -= 360;
		}
		var c =  cvn(hue, 0.7, 0.7);
		
		colorray.graphics.beginFill(c[0] <<16 | c[1] <<8 | c[2]);
		colorray.graphics.drawRect(0 + 120, 0, 800 - 120, 240);
		colorray.graphics.endFill();
		colorray.graphics.beginFill(c[0] <<16 | c[1] <<8 | c[2]);
		colorray.graphics.drawCircle(120, 120, 120);
		colorray.graphics.endFill();
		whiteray.graphics.clear();
		whiteray.graphics.beginFill(0xffffff);
		whiteray.graphics.drawRect(0 + 120, 30, 800 - 120, 180);
		whiteray.graphics.endFill();
		
		whiteray.graphics.beginFill(0xffffff);
		whiteray.graphics.drawCircle(120, 120, 90);
		whiteray.graphics.endFill();
		/*colorray.graphics.beginFill(c[0] <<16 | c[1] <<8 | c[2]);
		colorray.graphics.drawRect(0 + 80, 0, 800 - 80, 160);
		colorray.graphics.endFill();
		colorray.graphics.beginFill(c[0] <<16 | c[1] <<8 | c[2]);
		colorray.graphics.drawCircle(80, 80, 80);
		colorray.graphics.endFill();
		whiteray.graphics.clear();
		whiteray.graphics.beginFill(0xffffff);
		whiteray.graphics.drawRect(0 + 80, 20, 800 - 80, 120);
		whiteray.graphics.endFill();
		
		whiteray.graphics.beginFill(0xffffff);
		whiteray.graphics.drawCircle(80, 80, 60);
		whiteray.graphics.endFill();*/
		var B = getBounds(game);
		var P = game.myplayer;
		if (Size >= 1)
		{
		/*if (!P.killed && B.containsPoint(new Point(P.x+20, P.y+40)))
		{
			if (P.invincibility<=0)
			{
				game.SendEvent("PlayerDeath", P.myMyon != null);
			}
		}*/
		//if (game.Hoster)
		if (user == game.myplayer)
		{
			var i = 0;
			while (i <game.activeEnemies.length)
			{
				var E = game.activeEnemies[i];
				if (B.containsPoint(new Point(E.x, E.y)))
				{
					game.SendEvent("Destroy", E.UID);
				}
				i++;
			}
		}
		}
		}
	}
	
	public function cvn(h:Float, s:Float, v:Float):Dynamic
	{
    var r:Float, g:Float, b:Float;
    var i:Int;
    var f:Float, p:Float, q:Float, t:Float;
     
    if (s == 0){
        r = g = b = v;
        return [Math.round(r * 255), Math.round(g * 255), Math.round(b * 255)];
    }
   
    h /= 60;
    i  = Math.floor(h);
    f = h - i;
    p = v *  (1 - s);
    q = v * (1 - s * f);
    t = v * (1 - s * (1 - f));
   
    switch( i ) {
        case 0:
            r = v;
            g = t;
            b = p;
        case 1:
            r = q;
            g = v;
            b = p;
        case 2:
            r = p;
            g = v;
            b = t;
        case 3:
            r = p;
            g = q;
            b = v;
        case 4:
            r = t;
            g = p;
            b = v;
        default:        // case 5:
            r = v;
            g = p;
            b = q;
    }
    return [Math.round(r * 255), Math.round(g * 255), Math.round(b * 255)];
	}

/// <summary>
/// Clamp a value to 0-255
/// </summary>
public function Clamp(i:Int):Int
{
  if (i < 0) return 0;
  if (i > 255) return 255;
  return i;
}
}