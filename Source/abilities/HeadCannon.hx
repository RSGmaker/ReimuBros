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
		
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 340;
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
			game.SendEvent("HeadCannon", D);
			/*var D:Dynamic = { };
			D.x = player.x;
			D.y = player.y + 10;
			D.type = "yinyangorb";
			D.scale = 0.4;
			D.dir = player.Ldir;
			D.Vspeed = 2;
			D.HP = 6;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 10.5;
			}
			else
			{
				D.Hspeed = -10.5;
			}
			D.gravX = 0;
			D.gravY = 0.4;
			D.wrap = true;
			D.bounces = true;
			game.SendEvent("PlayerDanmaku", D);*/
		}
	}
}