package;

/**
 * ...
 * @author RSGmaker
 */
class SpiderWeb extends Entity
{
	public var duration:Int = 1200;
	public var player:Player=null;
	public function new() 
	{
		super("spiderweb");
		scaleX = 0.1;
		scaleY = scaleX;
	}
	override public function update():Void 
	{
		super.update();
		duration--;
		if (duration > 0)
		{
			if (scaleX < 1)
			{
				var X = width;
				var Y = height;
				scaleX += 0.1;
				scaleY = scaleX;
				x -= (width - X) / 2;
				y -= (height - Y) / 2;
			}
		}
		else
		{
			if (scaleX > 0)
			{
				var X = width;
				var Y = height;
				scaleX -= 0.1;
				scaleY = scaleX;
				x -= (width - X) / 2;
				y -= (height - Y) / 2;
			}
			else
			{
				alive = false;
			}
		}
		var i = 0;
		var HB = GetHitbox();
		while (i < game.entities.length)
		{
			var E = game.entities[i];
			if (E.dangerous || Std.is(E, Enemy))
			{
				if (HB.intersects(E.GetHitbox()))
				{
					E.Hspeed *= 0.5;
					E.Vspeed *= 0.95;
					if (Std.is(E, Enemy))
					{
						var D:Dynamic = E;
						if (D.flipped > 0 && D.flipped < 90)
						{
							D.flipped++;
							if (D.flipped < 61)
							{
								D.flipped = 61;
							}
						}
					}
				}
			}
			i++;
		}
		
	}
}