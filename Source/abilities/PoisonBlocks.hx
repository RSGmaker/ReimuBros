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
		description = "Spreads poisonous clouds\nwhich slows enemies";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 3000;
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
		if (player.isme && player.cooldown <= 0 && player.ground != null && player.ground.type=="Block")
		{
			player.cooldown = player.maxcooldown;
			game.SendEvent("PoisonPlatform", player.ground.y);
		}
	}
}