package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MasterSpark extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Fires a Master Spark which\nis charged by killing\nenemies";
	}
	override public function init() 
	{
		super.init();
		//player.maxcooldown = 6000;
		//player.maxcooldown = 25;
		player.maxcooldown = 35;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		//player.cooldown--;
	}
	override public function onkill(E:Entity) 
	{
		super.onkill(E);
		//player.cooldown -= 150;
		player.cooldown--;
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			game.SendEvent("PlayerMasterSpark", null);
		}
	}
}