package;

/**
 * ...
 * @author RSGmaker
 */
class GiantSuika extends Entity
{

	public var falling:Bool;
	public var active:Bool;
	public var step:Int;
	public var timetostep:Int;
	public var unlock:String;
	public function new()
	{
		super("giantsuika");
		unlock = "suika";
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
				step = 14;
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
					x+=8;
					if (step > 6)
					{
						y-=3;
					}
					else
					{
						y+=3;
					}
					step--;
				}
				else
				{
					timetostep = 120;
					y = 0;
				}
			}
			}
			else
			{
				var Y = y;
				rotateentity(rotation + 4);
				y = Y + 32;
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
		timetostep = 120;
		if (game.RoundType == GameView.TypeofRound.Cirno)
		{
			ChangeAnimation("giantcirno");
			unlock = "cirno";
		}
		else
		{
			ChangeAnimation("giantsuika");
			unlock = "suika";
		}
		x = -width;
	}
}