package;

/**
 * ...
 * @author RSGmaker
 */
class Explosives extends Enemy
{
	public var flash:Bool = false;
	public var timer:Int = 45;
	public var explosion:Animation;
	public var explosionsize:Float = 1.0;
	public function new() 
	{
		super("Explosive");
		image.scaleX = 0.6;
		image.scaleY = image.scaleX;
		charname = "Explosives";
		//type = "Explosives";
		explosion = new Animation(game.AL.GetAnimation("explosion"));
		explosion.visible = false;
		explosion.scaleX = 0.1;
		explosion.scaleY = 0.1;
		addChild(explosion);
		removeonlevelend = true;
		dangerous = false;
		needtokill = false;
		respawn = false;
		reward = false;
		
		alpha = 0;
	}
	override public function update():Void 
	{
		invincibility = 30;
		
		if (alpha < 1)
		{
			Hspeed = 0;
			Vspeed = 0;
			alpha += 0.15;
			return;
		}
		else
		{
			alpha = 1;
		}
		Ldir = 0;
		Hspeed = 0;
		//super.update();
		
		updphysics();
		
		if (ground != null || dangerous)
		{
			timer--;
		}
		
		if (timer < 30 && (ground != null || dangerous))
		{
			flash = !flash;
			var C = "Explosive";
			if (flash)
			{
				C = C + "E";
			}
			visuallyEnraged = flash;
			//ChangeAnimation(C);
			//updateanimation(C);
			ChangeAnimation(C,false);
			if (timer < 0)
			{
				if (!dangerous)
				{
					SoundManager.Play("explode");
					image.visible = false;
					explosion.visible = true;
					dangerous = true;
					fallaccel = 0;
				}
				else
				{
					var X = explosion.width;
					var Y = explosion.height;
					explosion.scaleX += 0.15;
					explosion.scaleY += 0.15;
					explosion.x -= (explosion.width - X) / 2;
					explosion.y -= (explosion.height - Y) / 2;
					if (explosion.scaleX > explosionsize)
					{
						alive = false;
						killed = true;
					}
					
					var enemy = game.CollisionDetectTouchEnemy(this);
					var danger = game.CollisionDetectTouchDangerous(this);
					if (enemy != null && !enemy.killed && enemy.invincibility<=0)
				{
					if (game.Hoster)
					{
						game.SendEvent("Explodify", enemy.UID);
					}
					//game.SendEvent("Attack", enemy.UID);
					
					
				}
				var DD:Dynamic = danger;
				if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
				{
					if (game.Hoster)
					{
						/*var D:Dynamic = { };
						D.UID = danger.UID;
						D.type = "hit";
						D.HP = HP - 1;
						SendCustomEvent(D);*/
						game.SendEvent("Obliterate", danger.UID);
						//game.SendEvent("Kill", danger.UID);
					}
					//HP--;
				}
				
				}
			}
		}
	}
}