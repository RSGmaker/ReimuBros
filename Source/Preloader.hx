package;
//import nme.display.Bitmap;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
//@:bitmap("assets/Sprites/preloader.png") class BackgroundBD extends BitmapData {}
/**
 * ...
 * @author RSGmaker
 */
class Preloader extends NMEPreloader
{
private var background:Bitmap;
	public function new() 
	{
		super();
		//background = new Bitmap(new BackgroundBD(800, 600));
//addChildAt (background, 0);
	}
	//public override function onUpdate(bytesLoaded:Int, bytesTotal:Int)
	/*public override function onUpdate(bytesLoaded:Int, bytesTotal:Int)
	{
		super.onUpdate(bytesLoaded,bytesTotal);
	}*/
}