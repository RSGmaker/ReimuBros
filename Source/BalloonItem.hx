package;

/**
 * ...
 * @author RSGmaker
 */
class BalloonItem extends EntityItem
{

	public var drift:Int;
	public var dir:Int;
	public var started:Bool;
	public function new() 
	{
		super("balloon");
		charname = "Balloon";
		fallaccel = 0;
		drift = 45;
		dir = 0;
		despawnatbottom = false;
		custommotion = true;
		deccel = 0;
	}
	override public function Collect(player:Player) 
	{
		alive = false;
		player.score += 100 * (GameView._this.rank+1);
		if (player.Vspeed >= 0)
		{
			player.Vspeed -= 12;
		}
		else
		{
			player.Vspeed -= 8;
		}
		SoundManager.Play("collectcoin");
	}
	override public function update() 
	{
		if (!started)
		{
			started = true;
			image.image_speed = Math.round(UID * 4);
			ChangeAnimation("balloon");
			animate();
			image.image_speed = 0;
		}
		if (dir == 0)
		{
			if (UID > 0.5)
			{
				dir = 1;
			}
			else
			{
				dir = -1;
			}
		}
		drift--;
		if (drift < 0)
		{
			dir = -dir;
			drift = 90;
		}
		if (dir > 0)
		{
			if (Hspeed < 2)
			{
				Hspeed += 0.2;
			}
		}
		if (dir < 0)
		{
			if (Hspeed > -2)
			{
				Hspeed -= 0.2;
			}
		}
		y -= 1.5;
		if (y < -(height+100))
		{
			alive = false;
		}
		super.update();
	}
}