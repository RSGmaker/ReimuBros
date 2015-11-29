package abilities;

/**
 * ...
 * @author RSGmaker
 */
class VampiricTouch2 extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Gains lives from defeating\nenemies, and point items";
	}
	override public function init() 
	{
		super.init();
		//number of points needed to collect
		//player.maxcooldown = 20;
		
		//player.maxcooldown = 30;
		player.maxcooldown = 50;
		player.cooldown = player.maxcooldown;
		player.warncooldown = true;
	}
	private function doeat()
	{
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
	override public function oncollect(E:EntityItem) 
	{
		super.oncollect(E);
		if (E.charname == "Point")
		{
			doeat();
			if (E.scaleX >= 2)
			{
				//giant point items give more
				doeat();
			}
		}
	}
	override public function onkill(E:Entity) 
	{
		super.onkill(E);
		E.y = 601;
		doeat();
	}
}