package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class ScrollingArena extends ArenaLogic
{
	private var timer:Int;
	private var fireballwalltimer:Int;
	private var QBtimer:Int=500;
	private var rnd:MersenneTwister;
	private var spd:Float;
	private var QB:Array<QuestionBlock>;
	public var LY:Float = -100;
	public function new() 
	{
		super();
		//timer = 150;
		timer = 90;
		fireballwalltimer = 0;
		horizontalscrolling = true;
		maxspawn_modifier = 0.8;
		QB = new Array<QuestionBlock>();
	}
	override public function start() 
	{
		//super.start();
		game.ResetScrollY();
		game.powblock.solid = false;
		game.powblock.visible = false;
		game.allowpowblock = false;
		
		rnd = new MersenneTwister();
		rnd.seed = game.level;
		var Y = 464;
		/*game.AddWarningSign(96, Y, 150);
		game.AddWarningSign(370, Y, 150);
		game.AddWarningSign(640, Y, 150);*/
		spd = -2;
		if (Math.random() < 0.5)
		{
			spd = 2;
		}
		if (game.scrollspeedX != spd)
		{
			var T = timer - 30;
			var X = 640;
			if (spd > 0)
			{
				X = 80;
			}
		game.AddWarningSign(X, 0, T);
		game.AddWarningSign(X, 160, T);
		game.AddWarningSign(X, 320, T);
		game.AddWarningSign(X, 480, T);
		}
		game.platformformation = 3;
	}
	
	private function startblockmovement()
	{
		/*var i = 0;
		var Y = -1000.0;
		var step = true;
		var entities = game.entities;
		while (i < entities.length)
		{
			var E = entities[i];
			var D:Dynamic = E;
			if (E.type == "Block")
			{
				if (Y != E.y)
				{
					Y = E.y;
					step = !step;
				}
				E.Hspeed = -2;
				D.step = step;
			}
			i++;
		}*/
		///game.scrollspeedX = spd;
		if (game.Hoster)
		{
			var D:Dynamic = { };
			D.spd = spd;
			D.type = "scroll";
			SendCustomEvent(D);
		}
		
		var B:QuestionBlock = new QuestionBlock();
		B.x = (512 - 128)/* + game.scrollX*/;
		B.UID = -333;
		B.y = 32;
		var Y2 = B.y + 320+24;
		B.x += 640+32+16;
		
		var X = B.x;
		var D = 1312;
		var O = -32;
		while (X < O)
		{
			X += D;
		}
		while (X > 1312+O)
		{
			X -= D;
		}
		B.x = X;
		game.AddObject(B);
		QB.push(B);
		var BB = new QuestionBlock();
		var X2 = B.x + 640 + 0 - 16;
		while (X2 < O)
		{
			X2 += D;
		}
		while (X2 > 1312+O)
		{
			X2 -= D;
		}
		BB.x = X2;
		BB.y = B.y;
		BB.UID = -334;
		game.AddObject(BB);
		QB.push(BB);
		
		BB = new QuestionBlock();
		BB.x = B.x;
		BB.y = Y2;
		BB.UID = -335;
		game.AddObject(BB);
		QB.push(BB);
		
		BB = new QuestionBlock();
		BB.x = X2;
		BB.y = Y2;
		BB.UID = -336;
		game.AddObject(BB);
		QB.push(BB);
		
		//game.scrollspeedX = -3;
		//game.platformformation = 2;
		//game.setformation();
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		if (data.type == "bulletwall")
		{
			var YY = data.Y;
			var Y = -128;
			while (Y < 600)
			{
				//if (!(Y >= YY && Y < YY + 192+96+64))
				var S = game.scrollspeedX / 2;
				var X = 800;
				if (game.scrollspeedX > 0)
				{
					X = -64;
				}
				if (!(Y >= YY && Y < YY + 192+96+32))
				{
				var O = new Bullet();
				O.x = X;

				O.y = Y;
				O.Hspeed = S;
				O.Vspeed = 0;
				game.AddObject(O);
				}
				Y += 32;
			}
		}
		if (data.type == "firebar")
		{
			var O = new FireBar();
			O.x = data.x;
			O.y = data.y;
			O.Hspeed = data.Hspeed;
			O.Vspeed = data.Vspeed;
			O.rspd = data.rspd;
			O.rotation = data.rot;
			game.AddObject(O);
			//game.addChild(O);
		}
		if (data.type == "carousel")
		{
			var O = new Carousel();
			O.x = data.x;
			O.y = data.y;
			O.Hspeed = data.Hspeed;
			O.Vspeed = data.Vspeed;
			O.rspd = data.rspd;
			O.rotation = data.rot;
			game.AddObject(O);
			//game.addChild(O);
		}
		/*else if (data.type == "block")
		{
			var B = new QuestionBlock();
			B.UID = data.UID;
			B.x = data.x;
			B.y = data.y;
			
			var X = B.x + game.scrollX;
			var D = 1312;
			var O = -32;
			while (X < O)
			{
				X += D;
			}
			while (X > 1312+O)
			{
				X -= D;
			}
			B.x = X;
			game.AddObject(B);
		}*/
		else if (data.type == "scroll")
		{
			game.scrollspeedX = data.spd;
		}
	}
	private function generatecarousel():Bool
	{
		var D:Dynamic = { };
		D.type = "carousel";
		var Y = 600 - 512;
		Y += (160 * Std.int(Math.random() * 4));
		
		//Y += 16;
		var X = 800+200;
		if (game.scrollspeedX > 0)
		{
			X = -64-200;
		}
		D.Hspeed = game.scrollspeedX / 2;
		D.x = X;
		D.y = Y;
		D.Vspeed = 0;
		D.rspd = 1.5;
		D.rot = Math.random() * 360;
		if (Math.random() < 0.5)
		{
			D.rspd = -D.rspd;
		}
		var O = game.CollisionDetectPoint(X + 8, Y + 8);
		/*if (O == null)
		{
			O = game.CollisionDetectPoint(X + 8+1312, Y + 8);
		}*/
		//var O = game.CollisionDetectPoint(Math.min(Math.max(X+8,0),790), Y+8);
		///if (O != null && Y != LY)
		{
			//LY = Y;
			SendCustomEvent(D);
			return true;
		}
		return false;
	}
	private function generatebar():Bool
	{
		var D:Dynamic = { };
		D.type = "firebar";
		var Y = 600 - 512;
		Y += (160 * Std.int(Math.random() * 4));
		
		//Y += 16;
		var X = 800;
		if (game.scrollspeedX > 0)
		{
			X = -64;
		}
		D.Hspeed = game.scrollspeedX / 2;
		D.x = X;
		D.y = Y;
		D.Vspeed = 0;
		D.rspd = 2.0;
		D.rot = 0;
		if (Math.random() < 0.5)
		{
			D.rot = 180;
		}
		//D.rot = Math.random() * 360;
		if (Math.random() < 0.5)
		{
			D.rspd = -D.rspd;
		}
		var O = game.CollisionDetectPoint(X + 8, Y + 8);
		if (O == null)
		{
			O = game.CollisionDetectPoint(X + 8+1312, Y + 8);
			
		}
		//var O = game.CollisionDetectPoint(Math.min(Math.max(X+8,0),790), Y+8);
		if (O != null && Y != LY)
		{
			LY = Y;
			SendCustomEvent(D);
			return true;
		}
		return false;
	}
	private function generatewall()
	{
		var YY = (rnd.quick(4) * 60);
		var Y = YY;
		var i = 0;
		
		/*while (Y < YY + 128)
		{
			var O = new Bullet();
			O.x = 800;
			O.y = Y;
			O.Hspeed = -1;
			O.Vspeed = 0;
			game.AddObject(O);
			Y += 32;
		}*/
		//YY -= 64+64;
		YY -= 64+32;
		Y = 0;
		var D:Dynamic = { };
		D.Y = YY;
		D.type = "bulletwall";
		SendCustomEvent(D);
		/*while (Y < 600)
		{
			//if (!(Y >= YY && Y < YY + 192+96+64))
			if (!(Y >= YY && Y < YY + 192+96+32))
			{
			var O = new Bullet();
			O.x = 800;
			O.y = Y;
			O.Hspeed = -1;
			O.Vspeed = 0;
			game.AddObject(O);
			}
			Y += 32;
		}*/
	}
	override public function update() 
	{
		super.update();
		timer--;
		if (timer == 0 && game.Hoster)
		{
			startblockmovement();
		}
		if (game.Hoster)
		{
		if (timer < 0)
		{
			fireballwalltimer--;
			QBtimer--;
			if (fireballwalltimer <= 0)
			{
				//if (Math.random() < 0.5/* && false*/)
				///if (Math.random() < 0.2/* && false*/)
				if (game.ufoseal < 1)
				{
					if (Math.random() < 0.5 && false)
					{
						generatewall();
					}
					else
					{
						if (Math.random() < 0.15)
						{
							generatecarousel();
						}
						else
						{
						var ok = true;
						if (generatebar())
						{
							ok = false;
						}
						if (generatebar())
						{
							ok = false;
						}
						if (ok)
						{
							generatewall();
						}
						LY = -100;
						}
						/*
						var D:Dynamic = { };
						D.type = "firebar";
						var Y = 600 - 512;
						Y += (160 * Std.int(Math.random() * 4));
						
						//Y += 16;
						var X = 800;
						if (game.scrollspeedX > 0)
						{
							X = -64;
						}
						D.Hspeed = game.scrollspeedX / 2;
						D.x = X;
						D.y = Y;
						D.Vspeed = 0;
						D.rspd = 2.0;
						if (Math.random() < 0.5)
						{
							D.rspd = -D.rspd;
						}
						var O = game.CollisionDetectPoint(X + 8, Y + 8);
						if (O == null)
						{
							O = game.CollisionDetectPoint(X + 8+1312, Y + 8);
							
						}
						//var O = game.CollisionDetectPoint(Math.min(Math.max(X+8,0),790), Y+8);
						if (O != null)
						{
							SendCustomEvent(D);
						}
						else
						{
							generatewall();
						}*/
					}
				}
				/*else
				{
					var B = QB[Std.int(QB.length * Math.random())];
					B.SendCustomEvent("queue");
				}*/
				
				//fireballwalltimer = 656 * (rnd.quick(6)+1);
				fireballwalltimer = 656 * (rnd.quick(2) + 1);
				///fireballwalltimer = 656;
				
				///fireballwalltimer = 256;
			}
			if (QBtimer <= 0)
			{
				var B = QB[Std.int(QB.length * Math.random())];
				B.SendCustomEvent("queue");
				QBtimer = 350 * (rnd.quick(3) + 1);
			}
		}
		}
	}
}