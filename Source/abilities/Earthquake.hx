package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Earthquake extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Rocks a row";
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
		player.cooldown--;
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			game.SendEvent("Earthquake", player.ground.y);
		}
	}
}