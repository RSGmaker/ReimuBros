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
		player.maxcooldown = 2700;
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
			if (player.invincibility < 10)
			{
				player.invincibility = 10;
			}
		}
		if (active && player.cooldown >= player.maxcooldown)
		{
			player.maxcooldown = 1800;
			player.cooldown = player.maxcooldown;
			active = false;
			player.alpha = 1;
			if (player.invincibility < 60)
			{
				player.invincibility = 60;
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
			player.maxcooldown = 600;
			player.invincibility = 10;
		}
	}
}