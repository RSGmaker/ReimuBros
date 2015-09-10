package;

/**
 * ...
 * @author RSGmaker
 */
class GiantSuika extends Entity
{
	//slowed
	public var falling:Bool;
	public var active:Bool;
	public var step:Int;
	public var timetostep:Int;
	public function new()
	{
		super("giantsuika");
	}
	public override function update():Void 
	{
		visible = active;
		if (!active)
		{
			x = -width;
			y = 0;
			rotation = 0;
		}
		else
		{
			if (rotation == 0)
			{
			if (timetostep > 0)
			{
				timetostep--;
				step = 28;
				y = 0;
				if (x > 800)
				{
					active = false;
				}
			}
			else
			{
				if (step > 0)
				{
					x+=4;
					if (step > 12)
					{
						y-=1.5;
					}
					else
					{
						y+=1.5;
					}
					step--;
				}
				else
				{
					timetostep = 240;
					y = 0;
				}
			}
			}
			else
			{
				var Y = y;
				rotateentity(rotation + 2);
				y = Y + 16;
				if (rotation > 90)
				{
					active = false;
					if (game.Hoster)
					{
						var D:Dynamic = { };
							
						D.type = "GiantPoint";
						D.UID = Math.random();
						if (Math.random() > 0.5)
						{
							D.x = 800;
							D.Ldir = -1;
						}
						else
						{
							D.x = -16;
							D.Ldir = 1;
						}
						D.y = -100;
						game.SendEvent("SpawnItem", D);
					}
				}
			}
		}
		
	}
	public function tipover()
	{
		rotateentity(1);
	}
	public function activate()
	{
		active = true;
		rotation = 0;
		y = 0;
		step = 0;
		timetostep = 240;
		if (game.RoundType == GameView.TypeofRound.Cirno)
		{
			ChangeAnimation("giantcirno");
		}
		else
		{
			ChangeAnimation("giantsuika");
		}
		x = -width;
	}
}