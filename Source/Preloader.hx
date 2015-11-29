package;
//import nme.display.Bitmap;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.text.TextField;
//@:bitmap("assets/Sprites/preloader.png") class BackgroundBD extends BitmapData {}
/**
 * ...
 * @author RSGmaker
 */
class Preloader extends NMEPreloader
{
private var background:Bitmap;
public var text:TextField;
	public function new() 
	{
		super();
		text = new TextField();
		addChild(text);
		//background = new Bitmap(new BackgroundBD(800, 600));
//addChildAt (background, 0);
	}
	override public function onUpdate(bytesLoaded:Int, bytesTotal:Int):Void 
	{
		super.onUpdate(bytesLoaded, bytesTotal);
		var total:Float = bytesTotal;
		var rate = bytesLoaded / total;
		var N = Std.int(rate * 100);
		text.text = "Girls are preparing please wait...\n"+N + "%";
		text.width = text.textWidth + 8;
		text.height = text.textHeight + 8;
	}
	//public override function onUpdate(bytesLoaded:Int, bytesTotal:Int)
	/*public override function onUpdate(bytesLoaded:Int, bytesTotal:Int)
	{
		super.onUpdate(bytesLoaded,bytesTotal);
	}*/
}