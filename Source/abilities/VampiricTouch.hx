package abilities;

/**
 * ...
 * @author RSGmaker
 */
class VampiricTouch extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Gain a life for\ndefeating enemies";
	}
	override public function init() 
	{
		super.init();
		//number of points needed to collect
		player.maxcooldown = 20;
		player.cooldown = player.maxcooldown;
		player.warncooldown = true;
	}
	override public function onkill(E:Entity) 
	{
		super.onkill(E);
		player.cooldown--;
		if (player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			player.lives++;
			if (player == game.myplayer)
			{
				SoundManager.Play("extend");
			}
		}
	}
}