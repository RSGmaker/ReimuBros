package abilities;

/**
 * ...
 * @author RSGmaker
 */
class EnemyEater extends PlayerAbility
{
	public var hunger:Int;
	public var maxhunger:Int;
	public function new(player:Player) 
	{
		super(player);
		description = "Gets a speed boost from\neating enemies\nKills by touch while hungry";
	}
	override public function init() 
	{
		super.init();
		//player.maxcooldown = 390;
		maxhunger = 780;
		hunger = maxhunger;
	}
	override public function onframe() 
	{
		super.onframe();
		hunger--;
		if (hunger > 0)
		{
			player.superpower = false;
			player.warncooldown = true;
			player.maxcooldown = maxhunger;
			player.cooldown = maxhunger - hunger;
			if (player.mxspd <= Player.base_mxspd)
			{
				player.deccel = Player.base_deccel + 0.025;
				player.accel = Player.base_accel + 0.05;
				player.mxspd = Player.base_mxspd + 0.5;
				player.fallaccel = Player.base_fallaccel + 0.05;
			}
		}
		else
		{
			player.superpower = true;
			player.cooldown = 0;
			player.warncooldown = true;
			player.cooldowntext = "Hungry...";
			if (player.mxspd >= Player.base_mxspd)
			{
				player.deccel = Player.base_deccel - 0.025;
				player.accel = Player.base_accel - 0.05;
				player.mxspd = Player.base_mxspd - 0.5;
				player.fallaccel = Player.base_fallaccel;
			}
		}
	}
	override public function onkill(E:Entity) 
	{
		super.onkill(E);
		hunger = maxhunger;
		E.y = 601;
	}
}