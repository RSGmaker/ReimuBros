package abilities;

/**
 * ...
 * @author RSGmaker
 */
class RepeatShot extends PlayerAbility
{
	public var maxammo:Int = 5;
	public var ammo:Int;
	public function new(player:Player) 
	{
		super(player);
		description = "Can fire bullets multiple\ntimes before recharging";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = Std.int(630*(maxammo*0.6));
		player.warncooldown = true;
	}
	override public function onframe() 
	{
		super.onframe();
		if (ammo < 1)
		{
			player.cooldown--;
			if (player.cooldown <= 0)
			{
				ammo = maxammo;
				player.cooldown = -1000;
				//player.cooldown = player.maxcooldown;
			}
		}
		else
		{
			var G = game.gui.graphics;
			//var G = game.camera.graphics;
			//var G = game.graphics;
			var X = player.x + game.camera.x;
			var Y = player.y + game.camera.y;
			//X -= 10;
			//Y += holder.height;
			Y -= 4;
			var C = 0xAAAAFF;
			/*if (cooldown > 0)
			{
				C = 0xFF5555;
			}*/
			var i = 0;
			var W = 8;
			X -= W;
			G.beginFill(C, 1);
			while (i < ammo)
			{
				i++;
				G.drawRect(X, Y, W, 3);
				X += W+2;
			}
			G.endFill();
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && ammo>0)
		{
			ammo--;
			if (ammo <= 0)
			{
				player.cooldown = player.maxcooldown;
			}
			//player.cooldown = player.maxcooldown;
			var D:Dynamic = { };
			D.x = player.x;
			D.y = player.y + 30;
			D.type = "pbullet";
			D.scale = 0.8;
			D.dir = player.Ldir;
			D.Vspeed = 0;
			if (player.Ldir >= 0)
			{
				D.Hspeed = 10;
			}
			else
			{
				D.Hspeed = -10;
			}
			D.gravX = 0;
			D.gravY = 0;
			D.wrap = false;
			game.SendPlayerDanmaku(D);
			D.Vspeed = 1;
			/*var i = 0;
			while (i < 1)
			{
				D.Vspeed += 1;
				D.Hspeed -= D.dir;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				game.SendPlayerDanmaku(D);
				D.Vspeed *= -1;
				i++;
			}*/
		}
	}
}