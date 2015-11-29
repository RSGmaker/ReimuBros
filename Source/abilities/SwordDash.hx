package abilities;

/**
 * ...A Copy of the roukanken as an ability
 * @author RSGmaker
 */
class SwordDash extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Dashes instantly to the edge\nof the screen you're facing\nkills enemies you pass by";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 740;
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
		D.x = -20;
		if (player.Ldir < 0)
		{
			//D.x -= 800;
		}
		///D.y = 32;
		D.x = player.x - 20;
		D.y = player.y + 32;
		if (player.Ldir < 0)
		{
			D.x -= 800;
		}
		//D.user = P.UID;
		D.antiplayer = false;
		D.antienemy = true;
		D.color = 0xFFFFFF;
		//D.user = UID;
		//if (game.Hoster)
		if (player.isme)
		{
			game.SendEvent("LaserBeam", D);
		}
		if (player.Ldir > 0)
		{
			player.x = 770;
		}
		if (player.Ldir < 0)
		{
			player.x = 20;
		}
		if (player.invincibility < 90)
		{
			player.invincibility = 90;
		}
		}
	}
}