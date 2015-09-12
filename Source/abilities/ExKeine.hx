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
<<<<<<< HEAD
		player.maxcooldown = 5400;
=======
		player.maxcooldown = 1800;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
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
			if (player.superpower && player.cooldown > 1770)
			{
				player.invincibility = 5;
			}
		}
		else
		{
			if (player.superpower)
			{
<<<<<<< HEAD
				player.maxcooldown = 5400;
=======
				player.maxcooldown = 1800;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
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
				player.invincibility = 90;
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
<<<<<<< HEAD
			player.maxcooldown = 720;
			//player.maxcooldown = 1080;
=======
			player.maxcooldown = 360;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
			player.cooldown = 0;
			player.charname = "exkeine";
			player.accel += 0.3;
			player.deccel += 0.1;
			player.mxspd += 5;
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