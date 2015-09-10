package;
import openfl.display.Bitmap;
import openfl.display.DisplayObject;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.Assets;
import openfl.geom.Matrix;
import openfl.geom.Point;
import openfl.display.BlendMode;
import openfl.display.GradientType;
import openfl.display.Graphics;
/**
 * ...
 * @author RSGmaker
 */
class PoisonCloud extends Sprite
{
	//slowed
	public var msk:Shape;
	public var msk2:Shape;
	public var texture1:Bitmap;
	public var texture2:Bitmap;
	public var texture1movement:Point;
	public var texture2movement:Point;
	public var block:Block;
	public var left:Bool;
	public var right:Bool;
	public var R:Float;
	private var filterArr:Array<flash.filters.BitmapFilter>;
	public function new(block:Block) 
	{
		super();
		this.block = block;
		var bd = Main._this.AL.GetAnimation("poisoncloud")[0];
		texture1 = new Bitmap(bd);
		texture2 = new Bitmap(bd);
		msk = new Shape();
		R = 32;
		var mtx:Matrix = new Matrix();
		//mtx.createGradientBox(R+R,R+R,0,-R,-R);
		/*msk.graphics.beginGradientFill(GradientType.RADIAL, [0xDDDDDD, 0xFF6F22], [1,0], [0,255], mtx);
		msk.graphics.drawCircle(64, 64, R);
		msk.graphics.endFill();*/
		//msk.cacheAsBitmap = true;
		msk.visible = false;
		addChild(msk);
		texture1.mask = msk;
		msk2 = new Shape();
		/*msk2.graphics.beginGradientFill(GradientType.RADIAL, [0xDDDDDD, 0xFF6F22], [1,0], [0,255], mtx);
		msk2.graphics.drawCircle(64, 64, R);
		msk2.graphics.endFill();*/
		//msk.cacheAsBitmap = true;
		texture2.mask = msk2;
		//texture1.blendMode = BlendMode.LIGHTEN;
		texture2.blendMode = BlendMode.LIGHTEN;
		
		//texture1.cacheAsBitmap = true;
		//texture2.cacheAsBitmap = true;
		reset();
		msk2.visible = false;
		addChild(msk2);
		addChild(texture1);
		addChild(texture2);
		
		texture1.alpha = 0.5;
		texture2.alpha = 0.5;
		redomasking();
		/*
		var blur = new flash.filters.BlurFilter(8, 8, 1);
		filterArr = new Array<flash.filters.BitmapFilter>();
		filterArr[0] = blur;
		filters = filterArr;
		*/
	}
	
	public function reset()
	{
		texture1.x = -32;
		texture1.y = -32;
		texture2.x = -32;
		texture2.y = -32;
		
		
		texture1movement = Point.polar(0.25, Math.random() * 6.28);
		texture2movement = Point.polar(0.25, Math.random() * 6.28);
		
	}
	public function loop(texture:DisplayObject)
	{
		if (texture.x <= -96)
		{
			texture.x += 64;
		}
		if (texture.y <= -96)
		{
			texture.y += 64;
		}
		if (texture.x >= 32)
		{
			texture.x -= 64;
		}
		if (texture.y >= 32)
		{
			texture.y -= 64;
		}
	}
	public function _redomasking(mask:Shape)
	{
		mask.graphics.clear();
		if (!left || !right)
		{
		//mask.graphics.beginGradientFill(GradientType.RADIAL, [0xDDDDDD, 0xFF6F22], [1,0], [0,255], mtx);
		mask.graphics.beginFill(0xFFFFFF);
		if (!left && !right)
		{
			mask.graphics.drawCircle(64, 64, R);
		}
		else
		{
			if (!left)
			{
				halfCircle(mask.graphics, 64, 64, R,true);
			}
			else
			{
				halfCircle(mask.graphics, 64, 64, R,false);
			}
		}
		mask.graphics.endFill();
		}
		if (left && right)
		{
			mask.graphics.beginFill(0xFFFFFF);
			//mask.graphics.drawRect(R+16, R, R, R + R);
			mask.graphics.drawRect(R, R, R+32, R + R);
			mask.graphics.endFill();
		}
		else
		{
		if (left)
		{
			mask.graphics.beginFill(0xFFFFFF);
			//mask.graphics.drawRect(R+16, R, 16, R + R);
			mask.graphics.drawRect(R, R, 32, R + R);
			mask.graphics.endFill();
		}
		if (right)
		{
			mask.graphics.beginFill(0xFFFFFF);
			//mask.graphics.drawRect(R+R, R, 16, R + R);
			mask.graphics.drawRect(R+R, R, 32, R + R);
			mask.graphics.endFill();
		}
		}
	}
	
function halfCircle(g:Graphics, x:Float,y:Float,r:Float,left:Bool) {
    var c1:Float=r * (1.41421356237 - 1);
    var c2:Float = r * 1.41421356237 / 2;
	g.moveTo(x, y + r);
	if (!left)
	{
		g.curveTo(x+c1,y+r,x+c2,y+c2);
		g.curveTo(x+r,y+c1,x+r,y);
		g.curveTo(x+r,y-c1,x+c2,y-c2);
		g.curveTo(x + c1, y - r, x, y - r);
	}
	else
	{
		g.curveTo(x-c1,y+r,x-c2,y+c2);
		g.curveTo(x-r,y+c1,x-r,y);
		g.curveTo(x-r,y-c1,x-c2,y-c2);
		g.curveTo(x - c1, y - r, x, y - r);
	}
    /*g.moveTo(x+r,y);
    g.curveTo(x+r,y+c1,x+c2,y+c2);
    g.curveTo(x+c1,y+r,x,y+r);
    g.curveTo(x-c1,y+r,x-c2,y+c2);
    g.curveTo(x-r,y+c1,x-r,y);*/
    // comment in for full circle
    /*g.curveTo(x-r,y-c1,x-c2,y-c2);
    g.curveTo(x-c1,y-r,x,y-r);
    g.curveTo(x+c1,y-r,x+c2,y-c2);
    g.curveTo(x+r,y-c1,x+r,y);*/
};

	public function redomasking()
	{
		_redomasking(msk);
		_redomasking(msk2);
		if (left && right)
		{
			//texture1.alpha = 0.75;
			//texture2.alpha = 0.75;
			texture1.alpha = 0.3525;
			texture2.alpha = 0.3525;
		}
		else
		{
			texture1.alpha = 0.5;
			texture2.alpha = 0.5;
			//texture1.alpha = 0.3525;
			//texture2.alpha = 0.3525;
		}
	}
	/*override */public function update():Void 
	{
		var L = (block.LeftBlock != null && block.LeftBlock.solid);
		var R = (block.RightBlock != null && block.RightBlock.solid);
		if (L != left || R != right)
		{
			left = L;
			right = R;
			redomasking();
		}
		//super.update();
		texture1.x += texture1movement.x;
		texture1.y += texture1movement.y;
		texture2.x += texture2movement.x;
		texture2.y += texture2movement.y;
		
		loop(texture1);
		loop(texture2);
	}
}