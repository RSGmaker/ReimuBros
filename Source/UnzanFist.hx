package;

/**
 * ...
 * @author RSGmaker
 */
class UnzanFist extends Bullet
{

	public function new() 
	{
		super();
		ChangeAnimation("unzanfist");
<<<<<<< HEAD
		Vspeed = 0.55;
		//gravY = -0.00235;
		gravY = -0.0012;
=======
		Vspeed = 1.1;
		gravY = -0.0047;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
	}
	override public function update() 
	{
		super.update();
		//if (gravY<0 && y>0)
		if (gravY<0 && y>-80)
		{
			Vspeed = 0;
			gravY = 0.1;
		}
		if (gravY == 0.1 && Vspeed > 1.5)
		{
			//gravY = 0.23;
			gravY = 0.4;
		}
		if (Vspeed > 32)
		{
			Vspeed = 32;
		}
	}
}