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
	public function new()
	{
		super("giantsuika");
	}
	public override function update():Void 
	{
		//super.update();
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
				//rotation += 5;
				//if (rotation > 3.14)
				if (rotation > 90)
				{
					active = false;
					if (game.Hoster)
					{
						var D:Dynamic = { };
							//D.item = "Point";
							
							D.type = "GiantPoint";
							/*if (EE.charname == "Imposter")
							{
								D.type = "1up";
							}*/
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
		//rotation = 1;
		rotateentity(1);
		//rotation = 1;
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
		}
		else
		{
			ChangeAnimation("giantsuika");
		}
		x = -width;
	}
}