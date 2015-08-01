package;

/**
 * ...
 * @author RSGmaker
 */
class UtsuhoBullet extends Bullet
{

	public function new() 
	{
		super();
		ChangeAnimation("utsuhobullet");
	}
	override public function update() 
	{
		if (!started)
		{
			//stops table event from changing the sprite
			started = true;
		}
		super.update();
		var X = Math.floor(x);
		//force number to be a multiple of 32
		//X = X - (X & 31);
		X = (X >> 5) << 5;
		
		var Y = 600 - 32;
		while (Y > y)
		{
			Y -= 160;
		}
		Y += 160;
		if (Y < 500)
		{
		var block = game.CollisionDetectPoint(X+32, Y);
		if (block != null && block.type == "Block")
		{
			var D:Dynamic = block;
			D.Burn();
		}
		}
	}
}