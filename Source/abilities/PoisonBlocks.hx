package abilities;

/**
 * ...
 * @author RSGmaker
 */
class PoisonBlocks extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Poisons a row of blocks\nwhich slows enemies";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1000;
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
		if (player.isme && player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			game.SendEvent("PoisonPlatform", player.ground.y);
		}
	}
}