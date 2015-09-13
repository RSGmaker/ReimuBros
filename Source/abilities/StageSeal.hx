package abilities;

/**
 * ...
 * @author RSGmaker
 */
class StageSeal extends PlayerAbility
{
	public var active:Bool;
	public function new(player:Player) 
	{
		super(player);
		description = "Seals the stage, preventing\nenemies from walking\noffstage";
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
		if (!active)
		{
			player.cooldown--;
		}
		else
		{
			player.cooldown++;
			if (player.cooldown >= player.maxcooldown)
			{
				player.maxcooldown = 2000;
				player.cooldown = player.maxcooldown;
				active = false;
			}
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0 && !active)
		{
			//player.cooldown = player.maxcooldown;
			player.maxcooldown = 1000;
			active = true;
			player.cooldown = 0;
			var D:Dynamic = { };
			D.timer = player.maxcooldown;
			game.SendEvent("StageSeal", D);
		}
	}
}