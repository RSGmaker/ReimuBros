package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SummonBlueBird extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Summons a blue bird which\nfires bullets from above";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1500;
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
			game.SendEvent("SummonBlueBird", null);
		}
	}
}