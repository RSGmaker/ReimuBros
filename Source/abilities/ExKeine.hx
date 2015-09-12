package abilities;

/**
 * ...
 * @author RSGmaker
 */
class ExKeine extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Temporary invincibility";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 5400;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		if (!player.superpower)
		{
			player.cooldown--;
		}
		else
		{
			player.cooldown++;
		}
		
		if (player.cooldown < player.maxcooldown)
		{
			if (player.superpower && player.cooldown > 3540)
			{
				player.invincibility = 10;
			}
		}
		else
		{
			if (player.superpower)
			{
				player.maxcooldown = 5400;
				player.cooldown = player.maxcooldown;
				player.charname = "keine";
				player.accel -= 0.15;
				player.deccel -= 0.05;
				player.mxspd -= 2.5;
				if (player.Hspeed >= 0)
				{
					player.ChangeAnimation(player.charname);
				}
				if (player.Hspeed < 0)
				{
					player.ChangeAnimation(player.charname+"F");
				}
				player.invincibility = 180;
				player.superpower = false;
			}
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.cooldown <= 0 && !player.superpower)
		{
			player.superpower = true;
			player.maxcooldown = 720;
			//player.maxcooldown = 1080;
			player.cooldown = 0;
			player.charname = "exkeine";
			player.accel += 0.15;
			player.deccel += 0.05;
			player.mxspd += 2.5;
			if (player.Hspeed >= 0)
			{
				player.ChangeAnimation(player.charname);
			}
			if (player.Hspeed < 0)
			{
				player.ChangeAnimation(player.charname+"F");
			}
		}
	}
}