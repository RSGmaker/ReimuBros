package;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class PowerupItem extends EntityItem
{
	//the ability to grant.
	public var power:String;
	public var pointvalue:Int = 500;
	public var Dir:Int = 0;
	public var scroll:Int = 1;
	public var started:Bool;
	public var despawntimer:Int;
	public function new() 
	{
		super("powerup");
		scrollRect = new Rectangle(0, 0, 1, 1);
		power = "";
		//despawntimer = 6000;
		despawntimer = 2400;
		cancollectfrombelow = false;
		//power = "reimu";
	}
	override public function GetHitbox():Rectangle 
	{
		//return super.GetHitbox();
		//return new Rectangle(x-32, y, 64, 96);
		
		if (scrollRect == null)
		{
			return new Rectangle(x-32, y, height+8, 96);
		}
		return new Rectangle(x-32, y, scrollRect.height+8, 96);
	}
	public override function Collect(player:Player)
	{
		//if (GetHitbox().intersects(player.hitbox))
		{
		alive = false;
		player.score += pointvalue;
		if (player.isme)
		{
			//SoundManager.Play("collectcoin");
			SoundManager.Play("powerup");
		}
		}
	}
	override public function update() 
	{
		if (!started)
		{
			started = true;
			power = Player.powerups[Std.int(UID * Player.powerups.length)];
			//D.soul = S;
			
			SoundManager.Play("itemspawn");
			if (power != "" && power != "red_fairy")
			{
				Ldir = 0;
				ChangeAnimation(power);
				scaleX = 0.6;
				scaleY = scaleX;
			}
			else
			{
				scaleX = 0.6;
				scaleY = scaleX;
			}
		}
		Dir = Ldir;
		if (scroll < image.height)
		{
			scrollRect = new Rectangle(0, 0, image.width, scroll);
			scroll++;
			Ldir = 0;
		}
		else
		{
			scrollRect = null;
		}
		super.update();
		Ldir = Dir;
		if (y > 408 && wrapped)
		{
			alive = false;
		}
		despawntimer--;
		if (despawntimer < 60)
		{
			visible = !visible;
			if (despawntimer < 0)
			{
				alive = false;
			}
		}
	}
}