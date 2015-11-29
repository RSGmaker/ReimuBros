package;

/**
 * ...
 * @author RSGmaker
 */
class TelephonePole extends Entity
{
	public var player:Player;
	public var dir:Int = 1;
	public var started:Bool;
	public var spd:Float = 3.0;
	private var filterArr:Array<flash.filters.BitmapFilter>;
	public function new() 
	{
		super("telephonepole");
		image.x = -(image.width / 2);
		image.y = -(image.height-20);
		//y = (image.height - 20);
		y = 600;
		
		filterArr = new Array<flash.filters.BitmapFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 20;
		AB.blurY = 20;
		AB.color = 0xAB1FCA;
		AB.strength = 2;
		filterArr[filterArr.length] = AB;
		filters = filterArr;
	}
	override public function update():Void 
	{
		super.update();
		if (!started)
		{
			started = true;
			if (x < 400)
			{
				dir = 1;
			}
			else
			{
				dir = -1;
			}
			rotation = -30 * dir;
		}
		spd += 0.02;
		rotation += (spd * dir);
		if (Math.abs(Math.abs(rotation) - 180) < 20)
		{
			alive = false;
		}
		
		if (player != null && player.isme)
		{
			var enemy = game.CollisionDetectTouchEnemy(this);
			var danger = game.CollisionDetectTouchDangerous(this);
		
			if (enemy != null && !enemy.killed && enemy.invincibility<=0)
				{
					//if (player == game.myplayer)
					{
						game.SendEvent("Attack", enemy.UID);
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