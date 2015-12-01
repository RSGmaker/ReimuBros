package;
import openfl.display.Sprite;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class PlayerBullet extends Entity
{
	public var gravX:Float = 0;
	public var gravY:Float = 0;
	public var started:Bool=false;
	public var bounces:Bool = false;
	public var rolls:Bool = false;
	public var topbounce:Bool = false;
	public var bouncedrain:Bool = false;
	public var tossedBy:Player;
	//how many enemies it can hit before dissappearing
	public var HP:Int = 9999999;
	public var allowwrap:Bool = false;
	public var wrapdrain:Bool = true;
	//whether or not if it bumps the enemy instead of attacking them
	public var bumps:Bool = false;
	public var spin:Bool = false;
	public var spinspeed:Float = 0;
	
	//teleports the bullet one row higher.
	public var illusion:Bool = false;
	public var illusiontime:Int = 0;
	public var currentillusiontime:Int = 0;
	public var illusionrate:Float = 0.5;
	public var illusiondir:Int = -1;
	
	//rotates the sprite to match thrown angle
	public var rotated:Bool = false;
	
	//how much damage if any, to bosses.
	///public var bossdamage:Int = 0;
	private var filterArr:Array<flash.filters.BitmapFilter>;
	
	//rolling bullets will partially submerge into the ground.
	public var submerge:Bool;
	
	//how long until bullet dissappears(0=infinite)
	public var timelimit:Int = 0;
	
	public var friction:Float = 0;
	
	public var spiral:Float = 0;
	public var spiralrate:Float = 1;
	
	
	public var maxscale:Float = 0;

	
	public var rotationlayer:Sprite;
	public var emerge:Bool = false;
	public var emergespeed:Int = 13;
	public var piercing:Bool = false;
	
	
	public var PX:Float;
	public var PY:Float;
	public var LX:Float;
	public var LY:Float;
	public function new() 
	{
		super("pbullet");
		type = "PlayerBullet";
		UID = -1;
	}
	override public function CustomEvent(data:Dynamic) 
	{
		super.CustomEvent(data);
		if (data.type == "hit")
		{
			//var E = game.EntityFromUID(data.UID);
			//if (E != null)
			{
				
				game.ProcessEvent("Kill",tossedBy.ID, data.UID);
			}
			HP = data.HP;
		}
	}
	public override function update()
	{
		if (!started)
		{
			if (game.RoundType == GameView.TypeofRound.EventTable)
			{
				ChangeAnimation("table");
				image.image_speed = 1;
			}
			if (spin || emerge || rotated)
			{
				//center image for rotation.
				image.x = -(image.width / 2);
				image.y = -(image.height / 2);
				//maintain visual position
				/*x += -image.x;
				y += -image.y;*/
				//set spin speed/direction
				//if (spin)
				{
				if (Hspeed >= 0)
				{
					spinspeed = 22.5;
				}
				else
				{
					spinspeed = -22.5;
				}
				spinspeed *= image.image_speed;
				}
				rotationlayer = new Sprite();
				rotationlayer.x = -image.x;
				rotationlayer.y = -image.y;
				removeChild(image);
				rotationlayer.addChild(image);
				addChild(rotationlayer);
				if (emerge)
				{
					image.scrollRect = new Rectangle(image.width, 0, 0, image.height);
				}
			}
			started = true;
			
			PX = x;
			PY = y;
			LX = PX;
			LY = PY;
			if (rotated)
			{
				var degradian = Math.atan2(Vspeed, Hspeed);
				rotationlayer.rotation = degradian * ( 180.0 / 3.14);
			}
		}
		if (emerge && timelimit!=1 && image.scrollRect != null && image.scrollRect.x > 0)
		{
			var R = image.scrollRect;
			var S = Math.min(emergespeed, R.x);
			image.scrollRect = new Rectangle(R.x - S, R.y, R.width + S, R.height);
			/*if (image.scrollRect.x <= 0)
			{
				image.scrollRect = null;
			}*/
		}
		if (spin)
		{
			rotationlayer.rotation += spinspeed;
		}
		if (illusion)
		{
			currentillusiontime++;
			if (currentillusiontime > illusiontime)
			{
				alpha -= 0.1;
				if (alpha <= 0)
				{
					y += 160 * illusiondir;
					//x -= Hspeed * (illusiontime / 2.0);
					x -= Hspeed * (illusiontime * illusionrate);
					currentillusiontime = 0;
					illusiondir = -illusiondir;
				}
			}
			else
			{
				if (alpha < 1)
				{
					alpha += 0.1;
					currentillusiontime = 0;
				}
			}
		}
		Hspeed += gravX;
		Vspeed += gravY;
		if (spiral != 0)
		{
			var PF = new flash.geom.Point(Hspeed, Vspeed);
			var degradian = Math.atan2(Vspeed, Hspeed);
			degradian += spiral;
			var length = PF.length;
			Hspeed = Math.cos(degradian) * length;
			Vspeed = Math.sin(degradian) * length;
			if (spiralrate != 1)
			{
				spiral *= spiralrate;
			}
			//rotationlayer.rotation = degradian * ( 180.0 / 3.14);
		}
		if (friction != 0 && (Hspeed != 0 || Vspeed != 0))
		{
			var PF = new flash.geom.Point(Hspeed, Vspeed);
			var length = PF.length;
			if (length > friction)
			{
				length -= friction;
				PF.normalize(length);
				Hspeed = PF.x;
				Vspeed = PF.y;
			}
			else
			{
				Hspeed = 0;
				Vspeed = 0;
			}
		}
		if (timelimit > 0)
		{
			if (timelimit > 1)
			{
				timelimit--;
				if (maxscale > 0 && !emerge)
				{
					if (scaleX < maxscale)
					{
						var X = width;
						var Y = height;
						scaleX += 0.05;
						if (scaleX > maxscale)
						{
							scaleX = maxscale;
						}
						scaleY = scaleX;
						x -= (width - X) / 2;
						y -= (height - Y) / 2;
					}
				}
			}
			else
			{
				if (!emerge)
				{
				var X = width;
				var Y = height;
				scaleX -= 0.05;
				scaleY = scaleX;
				x -= (width - X) / 2;
				y -= (height - Y) / 2;
				if (scaleX <= 0)
				{
					alive = false;
				}
				}
				else
				{
					var R = image.scrollRect;
					var S = Math.min(emergespeed, R.width);
					image.scrollRect = new Rectangle(R.x + S, R.y, R.width - S, R.height);
					if (image.scrollRect.width <= 0)
					{
						alive = false;
						//image.scrollRect = null;
					}
				}
			}
		}
		else if (maxscale > 0)
		{
			if (scaleX < maxscale && !emerge)
			{
				var X = width;
				var Y = height;
				scaleX += 0.05;
				if (scaleX > maxscale)
				{
					scaleX = maxscale;
				}
				scaleY = scaleX;
				x -= (width - X) / 2;
				y -= (height - Y) / 2;
			}
		}
		animate();
		/*x += Hspeed;
		y += Vspeed;*/
		if (LX != x || LY != y)
		{
			PX = x;
			PY = y;
		}
		PX += Hspeed;
		PY += Vspeed;
		
		x = PX;
		y = PY;
		LX = x;
		LY = y;
		if (allowwrap)
		{
			if (x < -width)
		{
			x += 800 + width;
			if (wrapdrain)
			{
				HP--;
			}
		}
		if (x > 800+width)
		{
			x -= 800 + width + width;
			if (wrapdrain)
			{
				HP--;
			}
		}
		
		}
		{
			var AB = new flash.filters.GlowFilter();
			AB.blurX = 20;
			AB.blurY = 20;
			{
				//AB.color = 0xFFAA66;
				AB.color = 0x66AAFF;
			}
			//AB.strength = 1.25;
			AB.strength = 1.5;
		
		filterArr = new Array();
		filterArr[0] = AB;
		filters = filterArr;
		}
		var ok = true;
		if ((x < -256 && gravX<=0) || (y < -256 && gravY<=0) || (x>1056 && gravX>=0) || (y>1056 && gravY>=0))
		{
			alive = false;
			killed = true;
		}
		
		var enemy = game.CollisionDetectTouchEnemy(this);
		var danger = game.CollisionDetectTouchDangerous(this);
		var block = null;
		var B = GetHitbox();
		var H = B.height;
		var W = B.width / 2;
		if (submerge)
		{
			H = H / 2;
			//H += image.y;
		}
		//the glow effect might be padding the bullets.
		//H -= 10;
		H = Std.int(H * 0.9);
		
		if ((bounces || rolls) && Vspeed > 0)
		{
			//block = game.CollisionDetectPoint(x + 24, y + 36);
			//block = game.CollisionDetectPoint(x + 24, y + H);
			block = game.CollisionDetectPoint(B.x + W, B.y + H);
			if (block != null)
			{
				if (rolls)
				{
					Vspeed = 0;
					y = block.y - H;
				}
				else
				{
					Vspeed *= -0.5;
					Vspeed -= 3;
					if (bouncedrain)
					{
						HP--;
					}
				}
			}
		}
		if (topbounce && Vspeed < 0)
		{
			//block = game.CollisionDetectPoint(x + 24, y + 0);
			block = game.CollisionDetectPoint(B.x + W, B.y + 0);
			//if (block != null || y<0)
			if (block != null || y<-100)
			{
				Vspeed *= -0.5;
				Vspeed += 3;
				if (bouncedrain)
				{
					HP--;
				}
			}
		}
		
		if (tossedBy != null)
			{
				if (enemy != null && !enemy.killed && enemy.invincibility<=0)
				{
					if (tossedBy == game.myplayer && !bumps)
					{
						if (!piercing)
						{
							game.SendEvent("Attack", enemy.UID);
						}
						else
						{
							game.SendEvent("Kill", enemy.UID);
						}
					}
					if (bumps)
					{
						if (enemy.flipped <= 0)
						{
							if (tossedBy == game.myplayer)
							{
								var D:Dynamic = { };
								D.UID = enemy.UID;
								D.x = enemy.x;
								D.y = enemy.y;
								D.Hspeed = enemy.Hspeed;
								D.Vspeed = enemy.Vspeed;
								game.SendEvent("Bump", D);
							}
							//enemy.bump();
							HP--;
						}
					}
					else
					{
						HP--;
					}
					//game.SendEvent("Attack", enemy.UID);
					
					
				}
				var DD:Dynamic = danger;
				if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
				{
					if (tossedBy == game.myplayer)
					{
						var D:Dynamic = { };
						D.UID = danger.UID;
						D.type = "hit";
						D.HP = HP - 1;
						SendCustomEvent(D);
						//game.SendEvent("Kill", danger.UID);
					}
					//HP--;
				}
			}
			if (HP <= 0)
			{
				alive = false;
				killed = true;
			}
	}
}