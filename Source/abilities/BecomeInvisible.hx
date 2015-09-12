package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BecomeInvisible extends PlayerAbility
{
	public var active:Bool;
	public function new(player:Player) 
	{
		super(player);
		description = "Turns invisible";
	}
	override public function init() 
	{
		super.init();
<<<<<<< HEAD
		player.maxcooldown = 2700;
=======
		player.maxcooldown = 900;
>>>>>>> parent of 6ed4253... Updated framerate to 60 fps
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		if (!active)
		{
			player.cooldown--;
		}
		else
		{
			player.cooldown++;
			if (player.invincibility < 5)
			{
				player.invincibility = 5;
			}
		}
		if (active && player.cooldown >= player.maxcooldown)
		{
			player.maxcooldown = 900;
			player.cooldown = player.maxcooldown;
			active = false;
			player.alpha = 1;
			if (player.invincibility < 30)
			{
				player.invincibility = 30;
			}
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (!active && player.cooldown <= 0)
		{
			player.cooldown = 0;
			player.alpha = 0.5;
			active = true;
			player.maxcooldown = 300;
			player.invincibility = 5;
		}
	}
}