package;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class PowBlock extends Entity
{
	public var HP:Int;
	public function new(ani:String) 
	{
		super(ani);
		solid = true;
		type = "PowBlock";
		HP = 4;
		bonked = -1000;
		UID = -100 - GameView._this.entities.length;
	}
	override public function GetHitbox():Rectangle 
	{
		return new Rectangle(x, y, 64, 32);
	}
	public override function update()
	{
		bonked = -1000;
	}
}