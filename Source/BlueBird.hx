package;

/**
 * ...
 * @author RSGmaker
 */
class BlueBird extends Entity
{
	public var player:Player;
	public var interval:Int;
	public var maxinterval:Int=15;
	public function new() 
	{
		super("bluebird");
		interval = maxinterval;
	}
	override public function update():Void 
	{
		//super.update();
		x += 6;
		interval--;
		if (interval <= 0)
		{
			interval = maxinterval;
			var sp = 6;
			var O = new PlayerBullet();
			O.x = x;
			O.y = y;
			O.Hspeed = 0;
			O.Vspeed = sp;
			O.tossedBy = player;
			O.image.image_speed = 0;
			O.ChangeAnimation("pbullet");
			game.AddObject(O);
		}
		if (x > 800)
		{
			alive = false;
		}
	}
}