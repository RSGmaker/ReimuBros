package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Floating extends PlayerAbility
{
	public var active:Bool;
	public var reset:Bool;
	public var duration:Int;
	public function new(player:Player)  
	{
		super(player);
		description = "Hovers briefly";
	}
	override public function lostability() 
	{
		player.fallaccel = player.Ofallaccel;
		super.lostability();
	}
	override public function onbeginframe() 
	{
		super.onbeginframe();
		if (player.ground != null)
		{
			duration = 90;
			reset = true;
			active = false;
		}
		else
		{
			if (!player.controller[0])
			{
				reset = false;
			}
			else if (!reset)
			{
				active = true;
			}
		}
		if ((player.controller[0]) && player.ground == null /*&& player.Vspeed > -0.01 && player.Vspeed < 2.0*/ && duration>0 && active)
		{
			//player.fallaccel = player.fallaccel2;
			player.fallaccel = 0;
			player.Vspeed = 0;
			duration--;
		}
		else
		{
			player.fallaccel = player.Ofallaccel;
		}
	}
}