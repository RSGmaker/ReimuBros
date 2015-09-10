package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BounceEntities extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Bounces projectiles and\nenemies";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1800;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0 && player.ground!=null)
		{
			player.cooldown = player.maxcooldown;
			var D:Dynamic = { };
			game.SendEvent("BounceEntities", D);
		}
	}
}