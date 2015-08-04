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
/**
 * ...
 * @author RSGmaker
 */
class PoisonCloud extends Sprite
{
	public var msk:Shape;
	public var texture1:Bitmap;
	public var texture2:Bitmap;
	public var texture1movement:Point;
	public var texture2movement:Point;
	public function new() 
	{
		super();
		var bd = Main._this.AL.GetAnimation("poisoncloud")[0];
		texture1 = new Bitmap(bd);
		texture2 = new Bitmap(bd);
		msk = new Shape();
		var R = 32;
		var mtx:Matrix = new Matrix();
		mtx.createGradientBox(R+R,R+R,0,-R,-R);
		msk.graphics.beginGradientFill(GradientType.RADIAL, [0xDDDDDD, 0xFF6F22], [1,0], [0,255], mtx);
		msk.graphics.drawCircle(64, 64, R);
		msk.graphics.endFill();
		//msk.cacheAsBitmap = true;
		msk.visible = false;
		addChild(msk);
		texture1.mask = msk;
		msk = new Shape();
		msk.graphics.beginGradientFill(GradientType.RADIAL, [0xDDDDDD, 0xFF6F22], [1,0], [0,255], mtx);
		msk.graphics.drawCircle(64, 64, R);
		msk.graphics.endFill();
		//msk.cacheAsBitmap = true;
		texture2.mask = msk;
		texture1.blendMode = BlendMode.LIGHTEN;
		texture2.blendMode = BlendMode.LIGHTEN;
		//texture1.cacheAsBitmap = true;
		//texture2.cacheAsBitmap = true;
		reset();
		msk.visible = false;
		addChild(msk);
		addChild(texture1);
		addChild(texture2);
		
		texture1.alpha = 0.5;
		texture2.alpha = 0.5;
		
	}
	
	public function reset()
	{
		texture1.x = -32;
		texture1.y = -32;
		texture2.x = -32;
		texture2.y = -32;
		
		
		texture1movement = Point.polar(0.5, Math.random() * 6.28);
		texture2movement = Point.polar(0.5, Math.random() * 6.28);
		
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
	/*override */public function update():Void 
	{
		//super.update();
		texture1.x += texture1movement.x;
		texture1.y += texture1movement.y;
		texture2.x += texture2movement.x;
		texture2.y += texture2movement.y;
		
		loop(texture1);
		loop(texture2);
	}
}