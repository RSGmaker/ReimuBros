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
		description = "Gains a life every 25\npoint items";
	}
	override public function init() 
	{
		super.init();
		//number of points needed to collect
		//player.maxcooldown = 22;
		player.maxcooldown = 25;
		player.cooldown = player.maxcooldown;
		player.warncooldown = true;
	}
	override public function oncollect(E:EntityItem) 
	{
		super.oncollect(E);
		if (E.charname == "Point")
		{
			player.cooldown--;
			if (E.scaleX >= 2)
			{
				//giant point items give more
				player.cooldown-=2;
			}
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