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
		description = "Turns invisible by staying\nstill";
	}
	override public function init() 
	{
		super.init();
		charge = 300;
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
					charge = 50;
				}
				player.alpha = 1;
			}
		}
		else
		{
			if (player.invincibility < 10)
			{
				player.invincibility = 10;
			}
			player.alpha = 0.5;
			if (player.Hspeed != 0 || player.Vspeed != 0)
			{
				charge = 50;
			}
		}
	}
	
}