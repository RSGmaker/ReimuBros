package;

/**
 * ...
 * @author RSGmaker
 */
class UnzanFist extends Bullet
{
	//slowed
	public function new() 
	{
		super();
		ChangeAnimation("unzanfist");
		Vspeed = 0.55;
		gravY = -0.00235;
	}
	override public function update() 
	{
		super.update();
		//if (gravY<0 && y>0)
		if (gravY<0 && y>-80)
		{
			Vspeed = 0;
			gravY = 0.05;
		}
		if (gravY == 0.1 && Vspeed > 3)
		{
			//gravY = 0.23;
			gravY = 0.2;
		}
		if (Vspeed > 16)
		{
			Vspeed = 16;
		}
	}
}