package abilities;

/**
 * ...
 * @author RSGmaker
 */
class AbsorbDamage extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Gets an extra hit when her\nbar is full";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1950;
		player.warncooldown = true;
		player.cooldowntext = "Extra HP!";
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
	}
	override public function onattacked() 
	{
		super.onattacked();
		if (player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			player.cancel = true;
			player.invincibility = 180;
		}
	}
	override public function onuse() 
	{
		super.onuse();
	}
}