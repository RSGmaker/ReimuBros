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
		
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1300;
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