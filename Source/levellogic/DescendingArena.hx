package levellogic;

/**
 * ...
 * @author RSGmaker
 */
class DescendingArena extends ArenaLogic
{
	private var timer:Int;
	
	private var blocktimer:Int;
	private var rnd:MersenneTwister;
	private var spd:Float;
	private var QB:Array<QuestionBlock>;
	public function new() 
	{
		super();
		timer = 150;
		verticalscrolling = true;
		maxspawn_modifier = 0.7;
		blocktimer = 0;
		QB = new Array<QuestionBlock>();
	}
	override public function start() 
	{
		rnd = new MersenneTwister();
		rnd.seed = game.level;
		//super.start();
		game.ResetScrollX();
		game.powblock.solid = false;
		game.powblock.visible = false;
		game.allowpowblock = false;
		var Y = 464;
		spd = 0.5;
		if (Math.random() < 0.5)
		{
			spd = -0.5;
			Y = 32;
		}
		if (game.scrollspeedY != spd)
		{
			var T = timer - 30;
		game.AddWarningSign(96, Y, T);
		game.AddWarningSign(370, Y, T);
		game.AddWarningSign(640, Y, T);
		}
		
		
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
				E.Vspeed = 0.5;
				D.step = step;
			}
			i++;
		}*/
		//game.scrollspeedY = 0.5;
		if (game.Hoster)
		{
			var D:Dynamic = { };
			D.spd = spd;
			D.type = "scroll";
			SendCustomEvent(D);
		}
		
		game.platformformation = 2;
		game.setformation();
		
		generateblocks();
	}
	private function generateblocks()
	{
		
		var X1 = 64/* + game.scrollX*/;
		var D = 1312;
		var O = -32;
		while (X1 < O)
		{
			X1 += D;
		}
		while (X1 > 1312+O)
		{
			X1 -= D;
		}
		var X2 = 704/* + game.scrollX*/;
		while (X2 < O)
		{
			X2 += D;
		}
		while (X2 > D+O)
		{
			X2 -= D;
		}
		
		D = 632;
		var Y1 = 32/* + game.scrollY*/;
		while (Y1 < O)
		{
			Y1 += D;
		}
		while (Y1 > D+O)
		{
			Y1 -= D;
		}
		var Y2 = 32+192/* + game.scrollY*/;
		while (Y2 < O)
		{
			Y2 += D;
		}
		while (Y2 > D+O)
		{
			Y2 -= D;
		}
		
		var B:QuestionBlock = new QuestionBlock();
		B.x = X1;
		B.y = Y1;
		B.UID = -333;
		/*QB.push(B);
		game.AddObject(B);*/
		B = new QuestionBlock();
		B.x = X2;
		B.y = Y1;
		B.UID = -334;
		/*QB.push(B);
		game.AddObject(B);*/
		B = new QuestionBlock();
		B.x = X1;
		B.y = Y2;
		B.UID = -335;
		QB.push(B);
		game.AddObject(B);
		B = new QuestionBlock();
		B.x = X2;
		B.y = Y2;
		B.UID = -336;
		QB.push(B);
		game.AddObject(B);
		
		/*var B:QuestionBlock = new QuestionBlock();
		B.x = (512 - 128);
		B.UID = -333;
		B.y = 32;
		var Y2 = B.y + 320+24;
		B.x += 640+32+16;
		
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
		QB.push(B);
		var BB = new QuestionBlock();
		var X2 = B.x +640 + 0 - 16;
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
		QB.push(BB);*/
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		/*if (data.type == "bulletwall")
		{
			var YY = data.Y;
			var Y = 0;
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
		}*/
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
		/*else */if (data.type == "scroll")
		{
			game.scrollspeedY = data.spd;
		}
	}
	override public function update() 
	{
		super.update();
		timer--;
		if (timer == 0)
		{
			startblockmovement();
		}
		if (game.Hoster)
		{
		if (timer < 0)
		{
			blocktimer--;
			if (blocktimer <= 0)
			{
				if (Math.random() < 0.5/* && false*/)
				{
					//generatewall();
				}
				else
				{
					/*var D:Dynamic = { };
					D.y = 32;
					D.x = (512 - 128);
					if (game.scrollX < 656-288)
					{
						D.x += 640+0-16;
					}
					if (Math.random() < 0.5)
					{
						D.y += 320+24;
					}
					D.x += 640+32+16;
					D.UID = Math.random();
					D.type = "block";
					SendCustomEvent(D);*/
					var B = QB[Std.int(QB.length * Math.random())];
					B.SendCustomEvent("queue");
				}
				
				//fireballwalltimer = 656 * (rnd.quick(6)+1);
				blocktimer = 500 * (rnd.quick(2) + 1);
				blocktimer = 500;
			}
		}
		}
	}
}