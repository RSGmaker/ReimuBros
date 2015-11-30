package abilities;

/**
 * ...
 * @author RSGmaker
 */
class QuickDash extends PlayerAbility
{
	//time between button pushes to activate
	public var time:Int;
	public var maxtime:Int = 6;
	public var dir:Int = 0;
	//how long until the ability can activate again
	public var delay:Int = 0;
	public var maxdelay:Int = 10;
	//number of frames to dash for.
	public var duration:Int;
	public var maxduration:Int = 4;
	public var speedboost:Float = 33;
	public function new(player:Player) 
	{
		super(player);
		description = "Double tap left or right\nto dash";
	}
	override public function init() 
	{
		super.init();
	}
	override public function onframe() 
	{
		super.onframe();
		if (duration > 0)
		{
			duration--;
			if (duration <= 0)
			{
				player.mxspd -= speedboost;
				player.Hspeed = player.Ldir * player.mxspd;
				delay = maxdelay;
			}
			return;
		}
		if (delay > 0)
		{
			delay--;
			return;
		}
		if (time < maxtime)
		{
			time++;
		}
		else
		{
			dir = 0;
		}
		if (dir != 0)
		{
			if (player.controller[3] && !player.lcontroller[3] && dir == 1)
			{
				//dash right
				player.mxspd += speedboost;
				player.Hspeed = player.mxspd;
				duration = maxduration;
				player.invincibility = Std.int(Math.max(player.invincibility,duration + 1));
			}
			if (player.controller[2] && !player.lcontroller[2] && dir == -1)
			{
				//dash left
				player.mxspd += speedboost;
				player.Hspeed = -player.mxspd;
				duration = maxduration;
				player.invincibility = Std.int(Math.max(player.invincibility,duration + 1));
			}
		}
		if (player.controller[3] != player.controller[2])
		{
			if (player.controller[3] && !player.lcontroller[3])
			{
				dir = 1;
				time = 0;
			}
			if (player.controller[2] && !player.lcontroller[2])
			{
				dir = -1;
				time = 0;
			}
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			var D:Dynamic = { };
			game.SendEvent("ClearSpawnList", D);
		}
	}
}