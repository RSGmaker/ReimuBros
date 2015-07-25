package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Floating extends PlayerAbility
{

	public function new(player:Player)  
	{
		super(player);
	}
	override public function onbeginframe() 
	{
		super.onbeginframe();
		if ((player.controller[0]) && player.Vspeed > -0 && player.Vspeed < 2.0)
		{
			player.fallaccel = player.fallaccel2;
		}
		else
		{
			player.fallaccel = player.Ofallaccel;
		}
	}
}