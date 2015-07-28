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
		Vspeed = 1.1;
		gravY = -0.0047;
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
		if (gravY == 0.1 && Vspeed > 3)
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