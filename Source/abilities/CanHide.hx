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
		description = "Turns invisible by\nstaying still";
	}
	override public function init() 
	{
		super.init();
		charge = 150;
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
					charge = 25;
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
				charge = 25;
			}
		}
	}
	
}