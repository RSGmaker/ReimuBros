package;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class Carousel extends Entity
{
	public var parts:Array<Bitmap>;
	public var rspd:Float=1.5;
	public function new(ani:String="bullet"/*,length:Int=4*/) 
	{
		super("black");
		
		var bd = game.AL.GetAnimation(ani)[0];
		var i = 0;
		parts = new Array<Bitmap>();
		var dist:Float = Math.max(bd.width, bd.height);
		var X:Float = 0;
		//X += dist;
		dist *= 1.2;
		
		var offset = 200;
		var length = 28;
		X += offset;
		var dir:Float = 0;
		var dirI:Float = (3.14*2) / length;
		
		length = Math.floor((length-1) * 0.8);
		while (i < length)
		{
			var B = new Bitmap(bd);
			//B.y = X;
			B.x = Math.cos(dir) * offset;
			B.y = Math.sin(dir) * offset;
			addChild(B);
			parts.push(B);
			//X += dist;
			dir += dirI;
			i++;
		}
		removeonlevelend = true;
		type = "Carousel";
	}
	public function camera():Void
	{
		var i = 0;
		while (i < parts.length)
		{
			var B = parts[i].getBounds(game.gamestage);
			var D:Dynamic = { };
							
			D.type = "Point";
			D.UID = Math.random();
			if (Math.random() > 0.5)
			{
				D.Ldir = -1;
			}
			else
			{
				D.Ldir = 1;
			}
			D.x = B.x;
			D.y = B.y;
			game.SendEvent("SpawnItem", D);
			i++;
		}
	}
	override public function update():Void 
	{
		//super.update();
		x += Hspeed;
		y += Vspeed;
		rotation += rspd;
		var i = 0;
		var H = (Math.round(feetposition) >> 2);
		var P = game.myplayer;
		var BP = new Rectangle(P.x + P.middle, P.y + (P.feetposition - H),1,1);
		while (i < parts.length)
		{
			parts[i].rotation = -rotation;
			var B = parts[i].getBounds(game.gamestage);
			B = new Rectangle(B.x + 3, B.y + 3, B.width - 6, B.height - 6);
			if (B.intersects(BP) && P.invincibility<1 && !P.superpower && !P.killed)
			{
				game.SendEvent("PlayerDeath", myMyon != null);
			}
			i++;
		}
		if ((x < -200 && Hspeed <= 0) || (x > 1000 && Hspeed >= 0) || (y < -200 && Vspeed <= 0) ||  (y > 800 && Vspeed >= 0))
		{
			alive = false;
		}
	}
}