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
<<<<<<< HEAD
		player.maxcooldown = 900;
=======
		player.maxcooldown = 300;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
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
				player.mxspd -= 33;
				player.invincibility = 20;
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
			player.mxspd += 33;
			player.Hspeed = player.Ldir * player.mxspd;
			player.cooldown = 6;
			player.warncooldown = false;
		}
	}
}