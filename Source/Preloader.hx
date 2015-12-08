package;
//import nme.display.Bitmap;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.text.TextField;
//@:bitmap("assets/Sprites/preloader.png") class BackgroundBD extends BitmapData {}
@:bitmap("assets/Sprites/balloon0.png") class CBalloonBD extends BitmapData {}
/**
 * ...
 * @author RSGmaker
 */
class Preloader extends NMEPreloader
{
private var background:Bitmap;
public var text:TextField;
public var balloon:Bitmap;
public var balloonBD:BitmapData;
	public function new() 
	{
		super();
		balloonBD = new CBalloonBD(0, 0);
		text = new TextField();
		addChild(text);
		balloon = new Bitmap(balloonBD);
		balloon.x = 400 - (balloon.width / 2);
		balloon.y = 600 - balloon.height;
		addChild(balloon);
		//background = new Bitmap(new BackgroundBD(800, 600));
//addChildAt (background, 0);
	}
	override public function onUpdate(bytesLoaded:Int, bytesTotal:Int):Void 
	{
		//super.onUpdate(bytesLoaded, bytesTotal);
		var total:Float = bytesTotal;
		var rate = bytesLoaded / total;
		var N = Std.int(rate * 100);
		text.text = "Girls are preparing please wait...\n"+N + "%";
		text.width = text.textWidth + 8;
		text.height = text.textHeight + 8;
		graphics.clear();
		graphics.beginFill();
		graphics.drawRect(0, 390, 800 * rate, 10);
		graphics.endFill();
	}
}