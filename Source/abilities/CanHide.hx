package abilities;

/**
 * ...
 * @author RSGmaker
 */
class CanHide extends PlayerAbility
{

	public var charge:Int;
	public function new(player:Player) 
	{
		super(player);
		description = "Turns invisible by standing\nstill";
	}
	override public function init() 
	{
		super.init();
		charge = 150;
		player.flags.set(Player.CanHide, true);
	}
	override public function onframe() 
	{
		super.onframe();
		charge--;
		if (charge > 0)
		{
			if (player.invincibility<=0)
			{
				if (player.Hspeed != 0 || player.Vspeed != 0)
				{
					charge = 30;
				}
				player.alpha = 1;
			}
		}
		else
		{
			if (player.invincibility < 5)
			{
				player.invincibility = 5;
			}
			player.alpha = 0.5;
			if (player.Hspeed != 0 || player.Vspeed != 0)
			{
				charge = 30;
			}
		}
	}
	
}