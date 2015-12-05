package abilities;
import openfl.display.Shape;

/**
 * ...
 * @author RSGmaker
 */
class OneWeekGirl extends PlayerAbility
{
	//separate cooldown which may make nameplate text display independantly
	public var cooldown:Int;
	public var showtext:Int;
	//does a random event that can doesn't need any syncing
	
	public var speedboost:Int;
	public var pointboost:Int;
	
	public var hp:Int;
	
	//public var shape:Shape;
	//(fire)tuesday:increase maxspeed
	//(water)wednesday:cleans all blocks
	//(wood)thursday:gives 1 life
	//(metal)friday:boosts points from items
	//(earth)saturday:restore the pow block
	//(sun)sunday:(action/offense?)kill all enemies onscreen
	//(moon)monday:grants a myon or an extra hp
	
	//maybe using this ability should cost pow block uses
	public function new(player:Player) 
	{
		super(player);
		description = "Random effects";
	}
	
	override public function init() 
	{
		super.init();
		player.maxcooldown = 4000;
		//player.maxcooldown = 4500;
		//player.maxcooldown = 200;
		cooldown = player.maxcooldown;
		speedboost = -1;
		hp = 0;
		player.warncooldown = true;
		/*shape = new Shape();
		game.gamestage.addChild(shape);*/
		
	}
	override public function lostability() 
	{
		super.lostability();
		//game.gamestage.removeChild(shape);
	}
	override public function onframe() 
	{
		super.onframe();
		cooldown--;
		if (speedboost > -1)
		{
			speedboost--;
			if (speedboost == 0)
			{
				speedboost = -1;
				//remove speedboost
				player.mxspd -= 2;
				player.accel -= 0.3;
				player.deccel -= 0.1;
			}
		}
		if (pointboost > -1)
		{
			pointboost--;
		}
		player.cooldown = cooldown;
		if (showtext >= 0)
		{
			showtext--;
			player.cooldown = -1;
		}
		else
		{
			player.cooldowntext = "Ability ready!";
			player.cooldown = cooldown;
		}
		if (player.isme)
		{
			//shape.x = player.x;
			//shape.y = player.y + player.feetposition;
			//shape.graphics.clear();
			var G = game.gui.graphics;
			var X = player.x + game.camera.x;
			var Y = player.y + player.feetposition + game.camera.y;
			if (speedboost > 0)
			{
				G.beginFill(0xFF0000, 1);
				G.drawRect(X, Y, speedboost >> 6, 3);
				G.endFill();
			}
			if (pointboost > 0)
			{
				G.beginFill(0xAAAAAA, 1);
				G.drawRect(X, Y+5, pointboost >> 6, 3);
				G.endFill();
			}
			var S = hp + player.allmyons.length;
			if (S > 0)
			{
				G.beginFill(0xAAAAFF, 1);
				G.drawRect(X, Y+10, S << 3, 3);
				G.endFill();
			}
		}
	}
	override public function onattacked(fatal:Bool) 
	{
		super.onattacked(fatal);
		if (hp > 0)
		{
			hp--;
			player.cancel = true;
			player.invincibility = 90;
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (cooldown <= 0 && player.isme)
		{
			var R = Math.random();
			cooldown = player.maxcooldown;
			showtext = 90;
			if (R < 0.14)
			{
				player.cooldowntext = "Speed up(fire)";
				if (speedboost < 0)
				{
					player.mxspd += 2;
					player.accel += 0.3;
					player.deccel += 0.1;
					speedboost = player.maxcooldown + (player.maxcooldown >> 1);
				}
			}
			else if (R < 0.28)
			{
				player.cooldowntext = "Clears block effects(water)";
				game.SendEvent("RefreshBlocks", null);
			}
			else if (R < 0.42)
			{
				player.cooldowntext = "Life fragments(wood)";
				//player.lives++;
				player.lifefragments += 2;
				if (player == game.myplayer && player.lifefragments>3)
				{
					player.lifefragments -= 4;
					SoundManager.Play("extend");
				}
			}
			else if (R < 0.57)
			{
				player.cooldowntext = "More score from items(metal)";
				//pointboost = 2400;
				pointboost = player.maxcooldown + (player.maxcooldown >> 1);
			}
			else if (R < 0.71)
			{
				player.cooldowntext = "Restore pow block(earth)";
				game.SendEvent("RefreshPowBlock", null);
			}
			else if (R < 0.85)
			{
				player.cooldowntext = "Kills all enemies(sun)";
				game.SendKillAll();
			}
			else
			{
				//if (hp < 2)
				if (hp < 1)
				{
					hp++;
				}
				else
				{
					cooldown = cooldown >> 1;
				}
				//player.cooldowntext = "Shields:"+hp+"(moon)";
				player.cooldowntext = "Shield:(moon)";
			}
		}
	}
	override public function oncollect(E:EntityItem) 
	{
		super.oncollect(E);
		if (pointboost > 0)
		{
		if (E.charname == "Point")
		{
			if (E.scaleX < 2)
			{
				player.score += 100;
			}
			else
			{
				player.score += 1000;
			}
		}
		if (E.charname == "bomb")
		{
			if (E.scaleX > 0.5)
			{
				player.score+= 500;
			}
			else
			{
				player.score+= 200;
			}
		}
		}
	}
}