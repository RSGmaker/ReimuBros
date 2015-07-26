package;

/**
 * ...
 * @author RSGmaker
 */
class PlayerBullet extends Entity
{
	public var gravX:Float = 0;
	public var gravY:Float = 0;
	public var started:Bool=false;
	public var bounces:Bool = false;
	public var topbounce:Bool = false;
	public var bouncedrain:Bool = false;
	public var tossedBy:Player;
	//how many enemies it can hit before dissappearing
	public var HP:Int = 9999999;
	public var allowwrap:Bool = false;
	public var wrapdrain:Bool = true;
	private var filterArr:Array<flash.filters.BitmapFilter>;
	public function new() 
	{
		super("bullet");
		type = "PlayerBullet";
		UID = -1;
	}
	public override function update()
	{
		if (!started)
		{
			if (game.RoundType == GameView.TypeofRound.Table)
			{
				ChangeAnimation("table");
				image.image_speed = 1;
			}
			started = true;
		}
		Hspeed += gravX;
		Vspeed += gravY;
		animate();
		x += Hspeed;
		y += Vspeed;
		if (allowwrap)
		{
			if (x < -width)
		{
			x += 800 + width;
			if (wrapdrain)
			{
				HP--;
			}
		}
		if (x > 800+width)
		{
			x -= 800 + width + width;
			if (wrapdrain)
			{
				HP--;
			}
		}
		
		}
		{
			var AB = new flash.filters.GlowFilter();
			AB.blurX = 20;
			AB.blurY = 20;
			{
				AB.color = 0xFFAA66;
			}
			AB.strength = 1.25;
		
		filterArr = new Array();
		filterArr[0] = AB;
		filters = filterArr;
		}
		var ok = true;
		if ((x < -256 && gravX<=0) || (y < -256 && gravY<=0) || (x>1056 && gravX>=0) || (y>1056 && gravY>=0))
		{
			alive = false;
			killed = true;
		}
		
		var enemy = game.CollisionDetectTouchEnemy(this);
		var danger = game.CollisionDetectTouchDangerous(this);
		var block = null;
		if (bounces && Vspeed > 0)
		{
			block = game.CollisionDetectPoint(x + 24, y + 36);
			if (block != null)
			{
				Vspeed *= -0.5;
				Vspeed -= 3;
				if (bouncedrain)
				{
					HP--;
				}
			}
		}
		if (topbounce && Vspeed < 0)
		{
			block = game.CollisionDetectPoint(x + 24, y + 0);
			if (block != null || y<0)
			{
				Vspeed *= -0.5;
				Vspeed += 3;
				if (bouncedrain)
				{
					HP--;
				}
			}
		}
		
		if (tossedBy != null && tossedBy == game.myplayer)
			{
				if (enemy != null && !enemy.killed)
				{
					game.SendEvent("Attack", enemy.UID);
					HP--;
				}
				var DD:Dynamic = danger;
				if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku"))
				{
					game.SendEvent("Kill", danger.UID);
					HP--;
				}
			}
			if (HP <= 0)
			{
				alive = false;
				killed = true;
			}
	}
}