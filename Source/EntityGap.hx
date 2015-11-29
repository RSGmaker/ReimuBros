package;

/**
 * ...
 * @author RSGmaker
 */
class EntityGap extends Entity
{

	public var frames:Int;
	public var SY:Float;
	public function new() 
	{
		super("Gap");
		type = "Gap";
		deccel = 0.1;
		frames = 0;
		scaleY = 0;
		SY = 0.01666666666666666666666666666667;
		if (Player.myplayer.flags.get(Player.GapManipulator))
		{
			interactable = true;
			readyinteract = true;
			interacttext = "Manipulate";
		}
		removeonlevelend = true;
	}
	override public function interact(P:Player):Void 
	{
		if (P.isme)
		{
			var D:Dynamic = { };
			D.UID = UID;
			game.SendEvent("ManipulateGap", D);
		}
	}
	public override function update()
	{
		Ldir = 1;
		if (x > 400)
		{
			Ldir = -1;
		}
		if (frames < 60)
		{
			scaleY += SY;
		}
		if (frames == 150)
		{
			SoundManager.Play("fireballspawn");
			readyinteract = false;
			if (y > 300 && UID > 0.5 && game.RoundType != GameView.TypeofRound.EventYukari && game.RoundType != GameView.TypeofRound.EventDanmaku)
			{
				if (game.Hoster)
				{
					var D:Dynamic = { };
					D.type = "Nazrin";
					D.UID = Math.random();
					D.y = y+32;
					D.x = x;
					D.Ldir = Ldir;
					D.alive = true;
					D.Hspeed = 0;
					D.Vspeed = 0;
					D.enraged = false;
					D.visible = true;
					D.rank = game.rank;
					D.spawns = 0;
					game.SendEvent("SpawnEnemy", D);
				}
			}
			else
			{
			
			if (game.Hoster)
			{
			var D:Dynamic = { };
			D.type = "Chen";
			D.UID = Math.random();
			if ((game.rank < 1) && !(game.RoundType == GameView.TypeofRound.EventYukari || game.RoundType == GameView.TypeofRound.EventDanmaku))
			{
				D.UID *= 0.5;
			}
			D.y = y+32;
			D.x = x;
			D.Ldir = Ldir;
			D.alive = true;
			D.Hspeed = 0;
			D.Vspeed = 0;
			D.enraged = false;
			D.visible = true;
			game.SendEvent("SpawnEnemy", D);
			}
			}
		}
		if (frames > 180)
		{
			scaleY -= (SY + SY);
			if (scaleY <= 0)
			{
				alive = false;
			}
		}
		frames += 1;
	}
}