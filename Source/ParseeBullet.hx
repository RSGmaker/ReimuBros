package;

/**
 * ...
 * @author RSGmaker
 */
class ParseeBullet extends Bullet
{
	private var filterArr:Array<flash.filters.BitmapFilter>;
	private var blur:Array<flash.filters.BlurFilter>;
	private var frames:Int;
	public function new() 
	{
		super();
		ChangeAnimation("parseebullet");
		//dangerous = true;
		//dangerous = false;
		alpha = 0;
		
		
		filterArr = new Array<flash.filters.BitmapFilter>();
		blur = new Array<flash.filters.BlurFilter>();
		var AB = new flash.filters.BlurFilter();
		AB.blurX = 60;
		AB.blurY = 60;
		//AB.color = 0xFF0000;
		//AB.strength = 2;
		filterArr[filterArr.length] = AB;
		blur[blur.length] = AB;
		
		filters = filterArr;
	}
	override public function update() 
	{
		super.update();
		frames++;
		
		if (HP > 30)
		{
			dangerous = true;
			if (blur != null && blur[0].blurX > 1)
			{
				blur[0].blurX -= 2;
				blur[0].blurY -= 2;
				filters = filterArr;
				dangerous = false;
			}
			else if (blur != null)
			{
				blur = null;
				filters = null;
			}
			if (alpha < 1)
			{
				//alpha += 0.034;
				alpha += 0.12;
			}
			else
			{
				alpha = 1;
			}
		}
		else
		{
			dangerous = true;
			//dangerous = (HP >= 30);
			if (HP < 30)
			{
				dangerous = false;
				/*if (frames % 5 == 0)
				{
					blur[0].blurX += 10;
					blur[0].blurY += 10;
					//blur[0].blurX += 2;
					//blur[0].blurY += 2;
					filters = filterArr;
					//alpha -= 0.034+0.034;
				}*/
				alpha -= 0.034;
			}
		}
	}
}