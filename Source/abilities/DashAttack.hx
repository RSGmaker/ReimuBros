package abilities;

/**
 * ...
 * @author RSGmaker
 */
class DashAttack extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Dash attack";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 600;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
		
		if (player.cooldown > 0)
		{
		}
		else
		{
			if (player.superpower)
			{
				player.cooldown = player.maxcooldown;
				player.superpower = false;
				player.warncooldown = true;
				player.mxspd -= 16.5;
				player.invincibility = 40;
				player.Hspeed = player.Ldir * player.mxspd;
			}
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.cooldown <= 0 && !player.superpower)
		{
			player.superpower = true;
			player.mxspd += 16.5;
			player.Hspeed = player.Ldir * player.mxspd;
			player.cooldown = 12;
			player.warncooldown = false;
		}
	}
}