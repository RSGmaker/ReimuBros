package abilities;

/**
 * ...
 * @author RSGmaker
 */
class FallFlip extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Flips red/angry enemies";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 900;
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
			var i = 0;
			while (i < game.activeEnemies.length)
			{
				var E:Enemy = game.activeEnemies[i];
				//var G:Dynamic = E.ground;
				//if (E.flipped < 1 && E.invincibility < 1 && E.ground != null && E.ground.type == "Block" && G.icy)
				var special = false;
				if (Std.is(E, Cirno))
				{
					var D:Dynamic = E;
					var C:Cirno = D;
					if (C.flaming || C.electric)
					{
						special = true;
					}
				}
				if (E.flipped < 1 && E.invincibility < 1 && (E.enraged || E.visuallyEnraged || special))
				{
					//game.SendEvent("Kill", E.UID);
					var D:Dynamic = { };
					D.UID = E.UID;
					D.x = E.x;
					D.y = E.y;
					D.Hspeed = E.Hspeed;
					D.Vspeed = E.Vspeed;
					game.SendEvent("Bump", D);
				}
				i++;
			}
			game.FlashColor(0xFFFF44, 0.4, 0, 0.1);
		}
	}
}