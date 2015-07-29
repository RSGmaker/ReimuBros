package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Floating extends PlayerAbility
{

	public var duration:Int;
	public function new(player:Player)  
	{
		super(player);
		description = "Can hover briefly";
	}
	override public function onbeginframe() 
	{
		super.onbeginframe();
		if (player.ground != null)
		{
			duration = 90;
		}
		if ((player.controller[0]) && player.Vspeed > -0.01 && player.Vspeed < 2.0 && duration>0)
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