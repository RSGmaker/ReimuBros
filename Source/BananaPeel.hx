package;

/**
 * ...
 * @author RSGmaker
 */
class BananaPeel extends Entity
{
	public var player:Player;
	public var started:Bool;
	public var time:Int=300;
	public function new() 
	{
		super("bananapeel");
	}
	override public function update():Void 
	{
		super.update();
		if (!started)
		{
			started = true;
		}
		updphysics();
		time--;
		if (time < 30)
		{
			visible = !visible;
			if (time < 1)
			{
				alive = false;
			}
		}
		if (player != null && ground != null && player.isme)
		{
			var enemy = game.CollisionDetectTouchEnemy(this);
			var danger = game.CollisionDetectTouchDangerous(this);
		
			if (enemy != null && !enemy.killed && enemy.invincibility<=0 && enemy.flipped<1)
				{
					//if (player == game.myplayer)
					{
						var D:Dynamic = { };
						D.UID = enemy.UID;
						D.x = enemy.x;
						D.y = enemy.y;
						D.Hspeed = enemy.Hspeed;
						D.Vspeed = enemy.Vspeed-2;
						game.SendEvent("Bump", D);
					}
					//game.SendEvent("Attack", enemy.UID);
					
					
				}
				var DD:Dynamic = danger;
				if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
				{
					//if (player == game.myplayer)
					{
						var D:Dynamic = { };
						D.UID = danger.UID;
						D.type = "hit";
						D.HP = 1;
						SendCustomEvent(D);
						//game.SendEvent("Kill", danger.UID);
					}
					//HP--;
				}
		}
	}
}