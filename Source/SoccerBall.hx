package;
import openfl.display.Sprite;
import openfl.geom.Point;

/**
 * ...
 * @author RSGmaker
 */
class SoccerBall extends Entity
{
	public var started:Bool;
	public var startx:Float=-1000;
	public var starty:Float=-1000;
	public var gravX:Float = 0;
	public var gravY:Float = 0;
	public var tossedBy:Player;
	public var rotationlayer:Sprite;
	public var allowalternate:Bool;
	public var alternate:Bool;
	public var dangerspeed:Float = 4;
	//public var respawn:Int;
	public function new() 
	{
		super("soccerball");
		started = false;
		dangerous = false;
		type = "soccerball";
		image.image_speed = 0;
		tossedBy = null;
		//respawn = 240;
		
		//interactable = true;
		//interacttext = "Throw";
		removeonlevelend = true;
		gravY = 0.4;
	}
	/*public override function interact(P:Player)
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
	}*/
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		if (data.type == "Kick")
		{
			x = data.x;
			y = data.y;
			Hspeed = data.Hspeed;
			Vspeed = data.Vspeed;
			tossedBy = null;
			dangerous = (data.user == "Enemy");
			if (!dangerous)
			{
				ChangeAnimation("soccerball");
				var P = game.EntityFromUID(data.UID);
				if (P != null && P.type == "Player")
				{
					tossedBy = cast(P);
				}
			}
			else
			{
				ChangeAnimation("soccerballE");
			}
		}
		if (data.type == "Respawn")
		{
			x = data.x;
			y = data.y;
			Hspeed = 0;
			Vspeed = 0;
			dangerous = false;
			ChangeAnimation("soccerball");
			rotationlayer.rotation = 0;
		}
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			if (startx == -1000)
			{
				startx = x;
			}
			if (starty == -1000)
			{
				starty = y;
			}
			image.x = -(image.width / 2);
			image.y = -(image.height / 2);
			
			rotationlayer = new Sprite();
			rotationlayer.x = -image.x;
			rotationlayer.y = -image.y;
			removeChild(image);
			rotationlayer.addChild(image);
			addChild(rotationlayer);
			
		}
		Hspeed += gravX;
		Vspeed += gravY;
		rotationlayer.rotation += (Hspeed*2.5);
		animate();
		x += Hspeed;
		y += Vspeed;
		//alive = true;
		var ok = true;
		if (y < -200 && Vspeed<0)
		{
			Vspeed *= 0.98;
		}
		if (Math.abs(Hspeed) < 1 && (x<10 || x>810))
		{
			//roll into view, if out of view.
			Hspeed *= 1.1;
			if (Hspeed == 0)
			{
				Hspeed = 1;
			}
		}
		if (visible)
		{
		//var enemy = game.CollisionDetectPointEnemy(x + 12, y + 12);
		var enemy = game.CollisionDetectTouchEnemy(this);
		//if (Hspeed == 0 && Vspeed == 0)
		//if ((Math.abs(Hspeed)+Math.abs(Vspeed))<2)
		if ((Math.abs(Hspeed))<dangerspeed)
		{
			//readyinteract = true;
			if (dangerous)
			{
				dangerous = false;
				ChangeAnimation("soccerball");
			}
			if (enemy != null && (enemy.enraged || enemy.charname=="wriggle") && game.Hoster)
			{
				
				/*var D:Dynamic = { };
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
				game.SendEvent("Tableflip", D);*/
				var D:Dynamic = { };
				D.type = "Kick";
				D.x = x;
				D.y = y;
				D.user = "Enemy";
				D.UID = enemy.UID;
				var H = Math.abs(enemy.Hspeed) + 2;
				if (enemy.Ldir != 0)
				{
					H *= enemy.Ldir;
				}
				H *= 0.8;
				D.Hspeed = ((H*3)+Math.abs(enemy.Vspeed));
				D.Vspeed = -Math.abs(H + Math.abs(enemy.Vspeed * 2));
				
				
				SendCustomEvent(D);
			}
			else
			{
				var P = game.myplayer;
				var B = GetHitbox();
				if (B.containsPoint(new Point(P.x + P.middle, P.y + (P.feetposition - 1))))
				{
					var D:Dynamic = { };
					D.type = "Kick";
					D.x = x;
					D.y = y;
					D.user = "Player";
					D.UID = P.UID;
					var H = Math.abs(P.Hspeed) + 2;
					if (P.Ldir != 0)
					{
						H *= P.Ldir;
					}
					H *= 0.8;
					D.Hspeed = ((H*3)+Math.abs(P.Vspeed));
					D.Vspeed = -Math.abs(Math.abs(H)+Math.abs(P.Vspeed*2));
					SendCustomEvent(D);
				}
				//game.CollisionDetectPointItem(x + W, y + (feetposition - 1));
			}
		}
		else if (Math.abs(Hspeed)>(dangerspeed-1))
		{
			readyinteract = false;
			if (tossedBy != null && tossedBy == game.myplayer)
			{
				//var danger = game.CollisionDetectPointDangerous(x + 24, y + 24);
				var danger = game.CollisionDetectTouchDangerous(this);
				if (enemy != null && !enemy.killed && enemy.invincibility<=0)
				{
					if (enemy.charname == "wriggle" && enemy.rotation != 0)
					{
						//wriggle kick COUNTER!
						var D:Dynamic = { };
						D.type = "Kick";
						D.x = x;
						D.y = y;
						D.user = "Enemy";
						D.UID = enemy.UID;
						var H = Math.abs(enemy.Hspeed) + 2;
						if (enemy.Ldir != 0)
						{
							H *= enemy.Ldir;
						}
						H *= 0.8;
						D.Hspeed = ((H*3)+Math.abs(enemy.Vspeed));
						D.Vspeed = -Math.abs(H + Math.abs(enemy.Vspeed * 2));
				
				
						SendCustomEvent(D);
					}
					else
					{
						game.SendEvent("Kill", enemy.UID);
					}
				}
				var DD:Dynamic = danger;
				if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
				{
					game.SendEvent("Kill", danger.UID);
				}
			}
		}
		var G = game.CollisionDetectPoint(x, y + 23 + 1);
		if (G == null && Vspeed<0)
		{
			G = game.CollisionDetectPoint(x, y - 1);
		}
		if (G != null)
		{
			if (Vspeed > 0)
			{
				Vspeed -= 1.5;
				if (Vspeed < 0)
				{
					Vspeed = 0;
				}
			}
			if (Vspeed < 0)
			{
				Vspeed += 1.5;
				if (Vspeed > 0)
				{
					Vspeed = 0;
				}
			}
			Vspeed *= 0.7;
			Vspeed = Math.abs(Vspeed);
			if (y < G.y)
			{
				Vspeed = -Vspeed;
			}
			if (y < G.y && Vspeed>=0)
			{
				y = Math.min(y, G.y - (23));
			}
			
			Hspeed *= 0.98;
		}
		/*if ((x < -32 && gravX<=0) || (y < -32 && gravY<=0) || (x>832 && gravX>=0) || (y>832 && gravY>=0))
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
		}*/
		if (y > 408 && (x < -32 || x>832 || wrapped))
		{
			//send to spawnpoint
			if (game.Hoster)
			{
				var D:Dynamic = { };
				D.type = "Respawn";
				D.x = startx;
				D.y = starty;
				if (allowalternate)
				{
					alternate = !alternate;
					if (alternate)
					{
						D.y += 160;
					}
				}
				SendCustomEvent(D);
			}
		}
		}
		else
		{
			/*if (respawn > 0)
			{
				respawn--;
			}
			else
			{
				visible = true;
			}*/
		}
		wrapped = false;
		if (x < -width && Hspeed<=0)
		{
			wrapped = true;
			x += 800+width;
		}
		if (x > 800+width && Hspeed>=0)
		{
			wrapped = true;
			x -= 800+width+width;
		}
	}
}