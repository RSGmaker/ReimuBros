package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MiracleMallet extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Converts all life fragments\non stage into full 1ups\nand restores the POW Block";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 5000;
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
			game.SendEvent("MiracleMallet", D);
			game.SendEvent("RefreshPowBlock", D);
		}
	}
}