package;

/**
 * ...
 * @author RSGmaker
 */
class Bullet extends Entity
{

	public var gravX:Float = 0;
	public var gravY:Float = 0;
	public var started:Bool;
	public function new() 
	{
		super("bullet");
		
		dangerous = true;
		type = "Bullet";
		//if we kept track of these things would probly get messy.
		UID = -1;
	}
	public override function update()
	{
		if (!started)
		{
			if (GameView._this.RoundType == GameView.TypeofRound.Table)
			{
				ChangeAnimation("table");
				image.image_speed = 0.5;
			}
			started = true;
		}
		Hspeed += gravX;
		Vspeed += gravY;
		animate();
		x += Hspeed;
		y += Vspeed;
		var ok = true;
		if ((x < -width && gravX<=0 && Hspeed<=0) || (y < -height && gravY<=0 && Vspeed<=0) || (x>832 && gravX>=0 && Hspeed>=0) || (y>832 && gravY>=0 && Vspeed>=0))
		{
			alive = false;
			killed = true;
		}
	}
}