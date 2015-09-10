package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SummonBlackHole extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Summons a black hole";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 4000;
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
			var D:Dynamic = { };
			D.x = player.x;
			D.y = player.y + 10;
			D.dir = player.Ldir;
			game.SendEvent("SummonBlackHole", D);
		}
	}
}