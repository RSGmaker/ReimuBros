package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SymmetryLaser extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Hitting a block summons a\nlaser beam";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 240;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
	}
	override public function onheadbonk() 
	{
		//super.onheadbonk();
		if (player.isme && player.headbonk != null && player.headbonk.type == "Block" && player.cooldown<= 0)
		{
			player.cooldown = player.maxcooldown;
			var D:Dynamic = { };
			/*D.x = -player.middle;
			D.y = (player.height - 20);
			D.user = player.UID;*/
			D.size = 30;
			D.x = (800 - player.x) - (D.size / 2);
			D.y = 0;
			D.player = player.UID;
			D.rotation = 90;
			D.antiplayer = false;
			D.antienemy = true;
			D.piercing = false;
			game.SendEvent("LaserBeam",D);
		}
	}
	override public function onuse() 
	{
		return;
		//super.onuse();
		/*if (player.isme && player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			
		}*/
	}
}