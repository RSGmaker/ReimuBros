package;

/**
 * ...
 * @author RSGmaker
 */
class Yuuka extends Entity
{
	public var started:Bool;
	public var dir:Int;
	public var Time:Int;
	public var OY:Float;
	public function new() 
	{
		super("evilyuuka");
		Time = 150;
		OY = 0;
		type = "Yuuka";
	}
	override public function update():Void 
	{
		//super.update();
		if (!started)
		{
			started = true;
			OY = y;
			y += 16;
			dir = 1;
			if (x > 400)
			{
				dir = -1;
				ChangeAnimation("evilyuukaF");
			}
			else
			{
				x = -width;
			}
		}
		Time--;
		var spd = 3;
		if (dir == 1)
		{
			if (Time > 0)
			{
				if (rotation < 45)
				{
					rotateentity(rotation + 5);
					x += spd;
				}
			}
			else
			{
				x -= spd;
				if (x < -width)
				{
					if (Time < -150)
					{
						if (GameView._this.Hoster && alive)
						{
							var D:Dynamic = { };
							//D.x = x;
							D.y = OY-56;
							GameView._this.SendEvent("MasterSpark", D);
						}
						alive = false;
					}
				}
			}
		}
		if (dir == -1)
		{
			spd = 7;
			if (Time > 0)
			{
				if (rotation > -45)
				{
					rotateentity(rotation - 5);
					x -= spd;
				}
			}
			else
			{
				x += spd;
				if (x > 800)
				{
					if (Time < -150)
					{
						if (GameView._this.Hoster && alive)
						{
							var D:Dynamic = { };
							//D.x = x;
							D.y = OY-56;
							GameView._this.SendEvent("MasterSpark", D);
						}
						alive = false;
					}
				}
			}
		}
	}
}