package;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.geom.ColorTransform;
import openfl.geom.Point;
/**
 * ...
 * @author RSGmaker
 */
class MasterSpark extends Entity
{

	public var ray:Sprite;
	public var colorray:Shape;
	public var whiteray:Shape;
	public var hue:Int;
	public var started:Bool;
	public var Size:Float;
	public var Time:Int;
	public function new() 
	{
		super("black");
		visible = false;
		x = 0;
		scaleX = 800;
		scaleY = 160;
		
		ray = new Sprite();
		colorray = new Shape();
		ray.addChild(colorray);
		whiteray = new Shape();
		ray.addChild(whiteray);
		
		game.addChild(ray);
		hue = 0;
		started = false;
		
		Size = 0.1;
		Time = 210;
		type = "MasterSpark";
		//width = 800;
	}
	override public function update():Void 
	{
		super.update();
		if (ray != null)
		{
		if (!started)
		{
			/*whiteray.x = x;
			whiteray.y = y;
			colorray.x = x;
			colorray.y = y;*/
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
			game.removeChild(ray);
			ray = null;
			alive = false;
			game.yuukaactive = false;
		}
		colorray.graphics.clear();
		//colorray.graphics.beginFill(0x00AA33);
		//var D = HsvToRgb(hue, 220, 240);
		hue += 10;
		if (hue >= 360)
		{
			hue -= 360;
		}
		//var color = D.r + (D.g << 8) + (D.b << 16);
		//var c = hslToRgb(hue, 220, 180);
		///var c =  cvn((hue / 255.0), 0.6, 0.6);
		var c =  cvn(hue, 0.7, 0.7);
		//canvas.setPixel(xp, yp, c[0] <<16 | c[1] <<8 | c[2]);

		//var t:ColorTransform = new ColorTransform(1.0, 1.0, 1.0, 1.0, c[0], c[1], c[2]);
		//colorray.graphics.beginFill(t.color);
		
		colorray.graphics.beginFill(c[0] <<16 | c[1] <<8 | c[2]);
		colorray.graphics.drawRect(0, 0, 800, 160);
		colorray.graphics.endFill();
		whiteray.graphics.clear();
		whiteray.graphics.beginFill(0xffffff);
		whiteray.graphics.drawRect(0, 20, 800, 120);
		whiteray.graphics.endFill();
		var T:GameView = game;
		var B = getBounds(T);
		var P = game.myplayer;
		//if (!P.killed && P.GetHitbox().intersects(B))
		if (Size >= 1)
		{
		if (!P.killed && B.containsPoint(new Point(P.x+20, P.y+40)))
		{
			if (P.invincibility<=0)
			{
				game.SendEvent("PlayerDeath", P.myMyon != null);
			}
			/*else
			{
				if (P.flags.get(Player.CanHide) && P.cooldown == 0)
				{
					P.invincibility = 0;
					P.cooldown = P.maxcooldown;
					game.SendEvent("PlayerDeath", P.myMyon != null);
				}
			}*/
		}
		if (game.Hoster)
		{
			var i = 0;
			while (i <T.activeEnemies.length)
			{
				var E = T.activeEnemies[i];
				if (B.containsPoint(new Point(E.x, E.y)))
				{
					game.SendEvent("Destroy", E.UID);
				}
				i++;
			}
			
			/*var A = Players.iterator();
			while (A.hasNext())
			{
				var E:Player = A.next();
				if (!E.killed)
				{
					
				}
			}*/
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

	/*function hslToRgb(h, s, l){
    var r, g, b;

    if(s == 0){
        r = g = b = l; // achromatic
    }else{
        function hue2rgb(p:Float, q:Float, t:Float):Float{
            if(t < 0) t += 1;
            if(t > 1) t -= 1;
            if(t < 1/6) return p + (q - p) * 6 * t;
            if(t < 1/2) return q;
            if(t < 2/3) return p + (q - p) * (2/3 - t) * 6;
            return p;
        }

        var q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        var p = 2 * l - q;
        r = hue2rgb(p, q, h + 1/3);
        g = hue2rgb(p, q, h);
        b = hue2rgb(p, q, h - 1/3);
    }

    return [(r * 255), (g * 255), (b * 255)];
	//return Math.floor(r / 255) + (Math.floor(g / 255) << 8) + (Math.floor(b / 255) << 16);
}*/
	
	/// <summary>
/// Convert HSV to RGB
/// h is from 0-360
/// s,v values are 0-1
/// r,g,b values are 0-255
/// Based upon http://ilab.usc.edu/wiki/index.php/HSV_And_H2SV_Color_Space#HSV_Transformation_C_.2F_C.2B.2B_Code_2
/// </summary>
/*public function HsvToRgb(h:Float, S:Float, V:Float):Dynamic
{
  // ######################################################################
  // T. Nathan Mundhenk
  // mundhenk@usc.edu
  // C/C++ Macro HSV to RGB

  var H:Float = h;
  while (H < 0) { H += 360; };
  while (H >= 360) { H -= 360; };
  //double R, G, B;
  var R:Float;
  var G:Float;
  var B:Float;
  if (V <= 0)
    { R = G = B = 0; }
  else if (S <= 0)
  {
    R = G = B = V;
  }
  else
  {
    var hf:Float = H / 60.0;
    var i:Int = Math.floor(hf);
    var f:Float = hf - i;
    var pv:Float = V * (1 - S);
    var qv:Float = V * (1 - S * f);
    var tv:Float = V * (1 - S * (1 - f));
    switch (i)
    {

      // Red is the dominant color

      case 0:
        R = V;
        G = tv;
        B = pv;

      // Green is the dominant color

      case 1:
        R = qv;
        G = V;
        B = pv;
      case 2:
        R = pv;
        G = V;
        B = tv;

      // Blue is the dominant color

      case 3:
        R = pv;
        G = qv;
        B = V;
      case 4:
        R = tv;
        G = pv;
        B = V;

      // Red is the dominant color

      case 5:
        R = V;
        G = pv;
        B = qv;

      // Just in case we overshoot on our math by a little, we put these here. Since its a switch it won't slow us down at all to put these here.

      case 6:
        R = V;
        G = tv;
        B = pv;
      case -1:
        R = V;
        G = pv;
        B = qv;

      // The color is not defined, we should throw an error.

      default:
        //LFATAL("i Value error in Pixel conversion, Value is %d", i);
        R = G = B = V; // Just pretend its black/white
    }
  }
  var D:Dynamic = { };
  D.r = Clamp(Math.floor(R * 255.0));
  D.g = Clamp(Math.floor(G * 255.0));
  D.b = Clamp(Math.floor(B * 255.0));
  return D;
}*/

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