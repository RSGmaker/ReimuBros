package abilities;

/**
 * ...
 * @author RSGmaker
 */
class DestructiveJump extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Jumps with destructive\nforce";
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
		if (player.Vspeed >= 0)
		{
			player.superpower = false;
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0 && player.ground!=null)
		{
			player.cooldown = player.maxcooldown;
			player.superpower = true;
			player.Vspeed = -30;
		}
	}
	override public function onheadbonk() 
	{
		super.onheadbonk();
		if (player.superpower)
		{
			player.superpower = false;
			player.cooldown = player.maxcooldown;
			game.SendEvent("Earthquake", player.headbonk.y);
		}
	}
}