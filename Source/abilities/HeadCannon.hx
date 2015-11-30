package abilities;

/**
 * ...
 * @author RSGmaker
 */
class HeadCannon extends PlayerAbility
{
	//checking for a sekibanki head would cause sync issues so let's not
	//public var sekibankihead:Entity;
	public function new(player:Player) 
	{
		super(player);
		description = "Shoots upward";
	}
	override public function init() 
	{
		super.init();
		//player.maxcooldown = 340;
		player.maxcooldown = 420;
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
		if (player.cooldown <= 0 && player.charname != "sekibanki")
		{
			player.charname = "sekibanki";
			if (player.Ldir >= 0)
			{
				player.ChangeAnimation(player.charname);
			}
			if (player.Ldir < 0)
			{
				player.ChangeAnimation(player.charname+"F");
			}
		}
		/*if (sekibankihead == null)
		{
			player.cooldown--;
		}
		else if (!sekibankihead.alive)
		{
			sekibankihead = null;
			//reset sekibanki sprite
		}*/
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0/* && sekibankihead == null*/)
		{
			player.cooldown = player.maxcooldown;
			var D:Dynamic = { };
			if (Math.random() < 0.2)
			{
				D.faulty = true;
			}
			else
			{
				D.faulty = false;
			}
			if (Math.random() < 0.2)
			{
				D.explosive = true;
			}
			else
			{
				D.explosive = false;
			}
			game.SendEvent("HeadCannon", D);
		}
	}
}