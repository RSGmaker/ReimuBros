package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BriefInvisibility extends PlayerAbility
{
	public var active:Bool;
	public function new(player:Player) 
	{
		super(player);
		description = "Turns invisible briefly";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 900;
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
			player.maxcooldown = 600;
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
			player.maxcooldown = 150;
			player.invincibility = 5;
		}
	}
}