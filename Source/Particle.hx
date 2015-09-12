package;

/**
 * ...
 * @author RSGmaker
 */
class Particle extends Entity
{
	public var gravX:Float = 0;
	public var gravY:Float = 0;
	public var scaleRate:Float = 0;
	public var alphaRate:Float = 0;
	public var HP:Int = 120;
	public function new(ani:String) 
	{
		super(ani);
		type = "Particle";
	}
	override public function update():Void 
	{
		super.update();
		Hspeed += gravX;
		Vspeed += gravY;
		animate();
		x += Hspeed;
		y += Vspeed;
		alpha += alphaRate;
		if (scaleRate != 0)
		{
			var X = width;
			var Y = height;
			scaleX += scaleRate;
			scaleY += scaleRate;
			x -= (width - X) / 2;
			y -= (height - Y) / 2;
		}
		HP--;
		if (HP < 1)
		{
			alive = false;
			killed = true;
		}
	}
}