package;

/**
 * ...
 * @author RSGmaker
 */
class Table extends Entity
{
	public var started:Bool;
	public var startx:Float;
	public var starty:Float;
	public var gravX:Float = 0;
	public var gravY:Float = 0;
	public var tossedBy:Player;
	public var respawn:Int;
	public function new() 
	{
		super("table");
		started = false;
		dangerous = false;
		type = "Table";
		image.image_speed = 0;
		tossedBy = null;
		respawn = 240;
		interactable = true;
		interacttext = "Throw";
	}
	public override function interact(P:Player)
	{
		if (visible && Hspeed == 0 && Vspeed == 0 && game.myplayer == P)
		{
			var D:Dynamic = { };
			D.UID = UID;
			D.dangerous = false;
			D.TUID = P.UID;
			if (P.Ldir < 0)
			{
				D.Hspeed = -10;
				D.image_speed = 1;
			}
			else
			{
				D.Hspeed = 10;
				D.image_speed = -1;
			}
			game.SendEvent("Tableflip", D);
		}
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			startx = x;
			starty = y;
		}
		Hspeed += gravX;
		Vspeed += gravY;
		animate();
		x += Hspeed;
		y += Vspeed;
		//alive = true;
		var ok = true;
		
		if (visible)
		{
		var enemy = game.CollisionDetectPointEnemy(x + 24, y + 24);
		if (Hspeed == 0 && Vspeed == 0)
		{
			readyinteract = true;
			if (enemy != null && enemy.enraged && game.Hoster)
			{
				
				var D:Dynamic = { };
				D.UID = UID;
				D.dangerous = true;
				D.TUID = null;
				if (enemy.Hspeed < 0)
				{
					D.Hspeed = -10;
					D.image_speed = 1;
				}
				else
				{
					D.Hspeed = 10;
					D.image_speed = -1;
				}
				game.SendEvent("Tableflip", D);
			}
		}
		else
		{
			readyinteract = false;
			if (tossedBy != null && tossedBy == game.myplayer)
			{
				//var danger = game.CollisionDetectPointDangerous(x + 24, y + 24);
				var danger = game.CollisionDetectTouchDangerous(this);
				if (enemy != null && !enemy.killed && enemy.invincibility<=0)
				{
					game.SendEvent("Kill", enemy.UID);
				}
				var DD:Dynamic = danger;
				if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
				{
					game.SendEvent("Kill", danger.UID);
				}
			}
		}
		if ((x < -32 && gravX<=0) || (y < -32 && gravY<=0) || (x>832 && gravX>=0) || (y>832 && gravY>=0))
		{
			visible = false;
			dangerous = false;
			tossedBy = null;
			Hspeed = 0;
			Vspeed = 0;
			image.image_index = -0.1;
			image.image_speed = 0.1;
			animate();
			image.image_speed = 0;
			gravX = 0;
			gravY = 0;
			x = startx;
			y = starty;
			respawn = 240;
		}
		}
		else
		{
			if (respawn > 0)
			{
				respawn--;
			}
			else
			{
				visible = true;
			}
		}
	}
}