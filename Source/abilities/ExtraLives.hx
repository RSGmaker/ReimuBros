package abilities;

/**
 * ...
 * @author RSGmaker
 */
class ExtraLives extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Gain a life for collecting\npoint items";
	}
	override public function init() 
	{
		super.init();
		//number of points needed to collect
		player.maxcooldown = 22;
		player.cooldown = player.maxcooldown;
		player.warncooldown = true;
	}
	override public function oncollect(E:EntityItem) 
	{
		super.oncollect(E);
		if (E.charname == "Point")
		{
			player.cooldown--;
		}
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