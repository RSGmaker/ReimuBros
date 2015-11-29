package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SummonTelephonePole extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Drops a telephone pole\non your enemies";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1200;
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
			if (player.Ldir > 0)
			{
				D.x = 830;
			}
			else
			{
				D.x = -30;
			}
			game.SendEvent("TelephonePole", D);
		}
	}
}