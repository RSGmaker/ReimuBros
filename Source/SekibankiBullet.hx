package;
import Animation;

/**
 * ...
 * @author RSGmaker
 */
class SekibankiBullet extends PlayerBullet
{
	//slowed
	public var faulty:Bool;
	public var flames:Animation;
	public var dist:Float;
	public var breaking:Bool;
	public var explosive:Bool;
	public var explosion:Animation;
	public function new() 
	{
		super();
		flames = new Animation(game.AL.GetAnimation("flames"));
		flames.scaleY = -0.7;
		//flames.y += flames.height+image.height;
		flames.scaleX = 0.7;
		flames.y += 85;
		
		flames.y -= 7;
		flames.x += 5;
		flames.image_speed = 0.5;
		explosion = new Animation(game.AL.GetAnimation("explosion"));
		dist = 0;
		explosion.visible = false;
		explosion.scaleX = 0.1;
		explosion.scaleY = 0.1;
		addChild(flames);
		addChild(explosion);
	}
	override public function update() 
	{
		if (explosion.visible)
		{
			Hspeed = 0;
			Vspeed = 0;
			gravX = 0;
			gravY = 0;
		}
		super.update();
		flames.animate();
		//explosive = true;
		//faulty = true;
		if (faulty)
		{
			dist += Math.abs(Vspeed);
			if (dist > 200 && gravX == 0)
			{
				gravX = 0.05;
				if (x > 400)
				{
					gravX = -0.05;
				}
			}
			if (dist > 300 && !breaking)
			{
				flames.visible = false;
				gravY *= -0.5;
				Vspeed *= 0.5;
				breaking = true;
				Hspeed *= 3;
			}
			if (breaking && Vspeed != 0)
			{
				if (Hspeed>0)
				{
					rotateentity(rotation + 1.3);
				}
				if (Hspeed < 0)
				{
					rotateentity(rotation - 1.3);
				}
			}
		}
		else if (explosive)
		{
			dist += Math.abs(Vspeed);
			if (dist > 200)
			{
				gravY = 0.00000005;
			}
			if (dist > 4000 && Vspeed<0)
			{
				y = -100;
				Vspeed = 5;
				rotateentity(180);
			}
		}
		if (explosive)
		{
			if (Vspeed > 0)
			{
			var block = game.CollisionDetectPoint(x, y);
			if (block != null)
			{
				gravX = 0;
				gravY = 0;
				Hspeed = 0;
				Vspeed = 0;
				explosion.visible = true;
			}
			}
			if (explosion.visible)
			{
				var X = explosion.width;
				var Y = explosion.height;
				explosion.scaleX += 0.15;
				explosion.scaleY += 0.15;
				explosion.x -= (explosion.width - X) / 2;
				explosion.y -= (explosion.height - Y) / 2;
				if (explosion.scaleX > 1)
				{
					alive = false;
				}
			}
		}
	}
}