package;

/**
 * ...
 * @author RSGmaker
 */
class BossParsee extends Boss
{
	public var cooldown:Int = 300;
	public var jealoustime:Int = 300;
	public var jealousX:Float = 0;
	public var jealousY:Float = 0;
	public var jealous:Bool = false;
	public var jealousDir:Int = 0;
	public var jealousTarget:Float = 0;
	public var jealousSpeed:Float = 6.0;
	public var jealousDelay:Int;
	public var jealousMaxDelay:Int = 2;
	public var limit:Int;
	public function new() 
	{
		super("bossparsee", "parsee");
		shottime = cooldown;
	}
	private function greeneyedjealousy()
	{
		var Y = 0;
		var R = Math.floor((3 * Math.random())+1) * 160;
		Y += R;
		jealousTarget = Y;
		jealousX = 20;
		jealousDir = 1;
		if (rng.quick(100)>50)
		{
			jealousX = 800 - jealousX - 80;
			jealousDir = -1;
		}
		//jealousyX = cx;
		jealousY = 0;
		jealousDelay = 0;
		jealous = true;
	}
	override public function dodanmaku() 
	{
		//super.dodanmaku();
		if (shottime > 0)
		{
			shottime--;
			if (shottime <= 0)
			{
				greeneyedjealousy();
				shottime = jealoustime+cooldown;
				limit = jealoustime;
			}
		}
		if (shottime < 25)
		{
			visuallyEnraged = !visuallyEnraged;
		}
		else
		{
			visuallyEnraged = false;
		}
		
	}
	override public function update() 
	{
		super.update();
		limit--;
		if (limit < 1)
		{
			jealous = false;
		}
		if (jealous)
		{
			if (jealousY < jealousTarget)
			{
				jealousY += jealousSpeed;
			}
			else
			{
				jealousX += (jealousSpeed * jealousDir);
			}
			jealousDelay--;
			if (jealousDelay < 1)
			{
				var X = jealousX;
				var Y = jealousY;
				X += rng.quick(600) * 0.1;
				Y += rng.quick(600) * 0.1;
				var P = new ParseeBullet();
				P.HP = limit;
				P.x = X;
				P.y = Y;
				game.AddObject(P);
				jealousDelay = jealousMaxDelay;
			}
		}
	}
}