package;

/**
 * ...
 * @author RSGmaker
 */
class QuestionBlock extends Entity
{
	public var step:Bool;
	public var empty:Bool;
	public var rename:String;
	public var started:Bool;
	public var OX:Float;
	public var OY:Float;
	public var hasreset:Bool;
	//whether or not the next reset will make this block reappear.
	public var queued:Bool;
	
	//The kind of item the block will release("" for random).
	public var contents:String = "";
	
	//time in between the block refilling itself(0 to disable).
	public var refreshtimer:Int = 0;
	
	private var refresh:Int;
	public function new() 
	{
		super("questionblock");
		rename = "questionblock";
		type = "questionblock";
		solid = true;
		removeonlevelend = true;
		
		
		visible = false;
		solid = false;
		refresh = 0;
	}
	override public function CustomEvent(data:Dynamic) 
	{
		if (data == "empty")
		{
			empty = true;
		}
		if (data == "queue")
		{
			queued = true;
		}
	}
	public static function releasecontents(E:Entity,contents:String="")
	{
		//super.CustomEvent(data);
		var game = E.game;
		var dir = (game.myplayer.x > E.x);
		if (contents != "")
		{
			var D:Dynamic = { };
			D.type = contents;
			D.UID = Math.random();
			D.x = 0;
			D.y = -32;
			D.platform = E.UID;
			if (dir)
			{
				D.Ldir = -1;
			}
			else
			{
				D.Ldir = 1;
			}
			game.SendEvent("SpawnItem", D);
			//ok = true;
			return;
		}
		
		var T = EntityItem.getitem("list:adventure");
		
		{
			var D:Dynamic = { };
			D.type = T;
			D.UID = Math.random();
			D.x = 0;
			D.y = -32;
			D.platform = E.UID;
			if (dir)
			{
				D.Ldir = -1;
			}
			else
			{
				D.Ldir = 1;
			}
			
			if (T == "powerup")
			{
				/*if (true || Math.random() < 0.4)
				{
					var S = Player.characters[Std.int(Math.random() * Player.characters.length)];
					D.soul = S;
				}
				else
				{
					D.soul = "red_fairy";
				}*/
			}
			
			game.SendEvent("SpawnItem", D);
			//ok = true;
			return;
		}
		
		//if (!empty)
		{
			//empty = true;
			//var S = ["Point", "1up"];
			var S = ["Point","Point","powerup"];
			var type = S[Std.int(S.length * Math.random())];
			var ok = false;
			
			if (type == "Point")
			{
				var D:Dynamic = { };
							
				D.type = "Point";
				D.UID = Math.random();
				D.x = 0;
				D.y = -32;
				D.platform = E.UID;
				if (dir)
				{
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				//D.x = E.x;
				//D.y = E.y;
				game.SendEvent("SpawnItem", D);
				ok = true;
			}
			else if (type == "1up" && game.gamemode.canlivesspawn)
			{
				var D:Dynamic = { };
				D.type = "1up";
				D.UID = Math.random();
				D.x = 0;
				D.y = -32;
				D.platform = E.UID;
				if (dir)
				{
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				game.SendEvent("SpawnItem", D);
				ok = true;
			}
			else if (type == "powerup")
			{
				var D:Dynamic = { };
				D.type = "powerup";
				D.UID = Math.random();
				D.x = 0;
				D.y = -32;
				D.platform = E.UID;
				if (dir)
				{
					D.Ldir = -1;
				}
				else
				{
					D.Ldir = 1;
				}
				if (true || Math.random() < 0.4)
				{
					var S = Player.characters[Std.int(Math.random() * Player.characters.length)];
					D.soul = S;
				}
				else
				{
					D.soul = "red_fairy";
				}
				game.SendEvent("SpawnItem", D);
				ok = true;
			}
			////E.bonkedby = null;
			/*else if (type == "myon" && Main._this.canmyonspawn)
			{
				
			}*/
			/*if (ok)
			{
				var D:Dynamic = { };
				SendCustomEvent(D);
			}*/
		}
	}
	override public function update():Void 
	{
		//super.update();
		if (empty)
		{
			rename = "emptyblock";
		}
		else
		{
			rename = "questionblock";
			if (contents != "")
			{
				rename = "exclamationblock";
			}
		}
		if (!started)
		{
			OX = x;
			OY = y;
			started = true;
		}
		if (refreshtimer > 0 && empty)
		{
			refresh++;
			if (refresh >= refreshtimer)
			{
				refresh = 0;
				empty = false;
			}
		}
		ChangeAnimation(rename);
		
		//step = !step;
		/*if (step)
		{
			var X = game.scrollspeedX;
			var Y = game.scrollspeedY;
			x += X;
			y += Y;
			if ((x < -32 && X < 0) || (x > 800 && X > 0) || (y < -32 && Y < 0) || (y > 800 && Y > 0) || (X==0 && Y==0))
			{
				alive = false;
			}
		}*/
		if (game.scrollX != game.LscrollX || game.scrollY != game.LscrollY)
		{
			if (step)
			{
				///hb = null;
				if (game.scrollX != game.LscrollX)
				{
				x = OX + game.scrollX;
				
				//while (x <= -288)
				//while (x < -288)
				var D = 1312;
				var O = -32;
				while (x < O)
				{
					x += D;
				}
				while (x > 1312+O)
				{
					x -= D;
				}
				/*while (x > 1344)
				{
					x -= 1312+96;
				}*/
				}
				if (game.scrollY != game.LscrollY)
				{
					y = OY + game.scrollY;
				while (y <= -32)
				{
					y += 632;
				}
				while (y >= 600)
				{
					y -= 632;
				}
				}
				if (x <= -32 || y >= 600 || y <= -32 || x > 800)
				{
					//Reset();
					if (!hasreset)
					{
						Reset();
						hasreset = true;
					}
				}
				else
				{
					hasreset = false;
				}
				
			}
			//}
		/*if (Vspeed != 0)
		{
			y += Vspeed;
			hb = null;
			//Visual.y += Vspeed;
			if (y <= -32 && Vspeed < 0)
			{
				y += 632;
			}
			else if (y >= 600 && Vspeed > 0)
			{
				y -= 632;
			}
		}
		if (Hspeed != 0)
		{
			x += Hspeed;
			hb = null;
			//Visual.x += Hspeed;
			//if (x <= -32 && Hspeed < 0)
			if (x <= -288 && Hspeed < 0)
			{
				x += 1312;
			}
			else if (x >= 1344 && Hspeed > 0)
			{
				x -= 1312;
			}
		}*/
		
		//}
		step = !step;
		}
		if (bonkedby == game.myplayer && !empty)
		{
			releasecontents(this);
			SendCustomEvent("empty");
		}
		bonkedby = null;
		bonked = -1000;
	}
	override public function Bonk(player:Player) 
	{
		//super.Bonk(player);
		if (!empty)
		{
			releasecontents(this);
			SendCustomEvent("empty");
		}
	}
	
	public function Reset()
	{
		if (queued)
		{
			empty = false;
			visible = true;
			solid = true;
			
			queued = false;
		}
		else
		{
			empty = true;
			visible = false;
			solid = false;
		}
	}
}