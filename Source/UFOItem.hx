package;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class UFOItem extends EntityItem
{
	public var fuel:Int;
	public var flicker:Int;
	public var maxflicker:Int;
	public var flickerreset:Int;
	//public var changetimer:Int;
	public var color:String="";
	public var movement:Float;
	public var started:Bool;
	public var changescolor:Bool = true;
	public var hoverheight:Float = 20;
	public var FA:Array<flash.filters.BitmapFilter>;
	public function new() 
	{
		super("UFOItem");
		movement = 2.3;
		scaleX = 0.5;
		scaleY = scaleX;
		
		FA = new Array<flash.filters.BitmapFilter>();
		var AB = new flash.filters.GlowFilter();
		AB.blurX = 12;
		AB.blurY = 12;
		AB.color = 0xFFFFFF;
		AB.strength = 2.5;
		FA[FA.length] = AB;
		hitbox = new Rectangle( -10, 0, 39 + 20, 25 + 10);
	}
	override public function Collect(player:Player) 
	{
		alive = false;
		//player.score += 200;
		if (player.isme)
		{
			SoundManager.Play("collectcoin");
			//SoundManager.Play("ufocollect");
		}
		if (player.isme)
		{
			player.ufos.push(color);
			
			if (player.ufos.length > 2)
			{
				var bonus:Bool = ((player.ufos[0] == player.ufos[1]) && (player.ufos[1] == player.ufos[2]));
				var D:Dynamic = { };
				var col:String = "None";
				D.UID = Math.random();
				if (bonus)
				{
					col = player.ufos[0];
				}
				while (player.ufos.length > 0)
				{
					player.ufos.pop();
				}
				D.color = col;
				game.SendEvent("SummonRainbowUFO", D);
				//player.message = "UFO:" + col;
				//player.messagetime = 150;
			}
		}
	}
	override public function update() 
	{
		if (!started)
		{
			if (color == "")
			{
			if (UID <= 0.33)
			{
				//color = 1;
				color = "Red";
			}
			else if (UID <= 0.66)
			{
				//color = 2;
				color = "Green";
			}
			else
			{
				//color = 3;
				color = "Blue";
			}
			}
			flickerreset = 100;
			
			fuel = 780;
			maxflicker = flickerreset;
			flicker = maxflicker;
			//changetimer = 120;
			started = true;
		}
		ChangeAnimation(color + "ufo");
		//updateanimation(color + "ufo");
		x += movement;
		if (x < -width && movement<0)
		{
			x = 900;
		}
		if (x > 900 && movement>0)
		{
			x = -width;
		}
		fuel--;
		if (fuel > 0)
		{
			//if (y < -95)
			//if (y < -50)
			//if (y < -30)
			if (y < hoverheight)
			{
				y += 1;
			}
			else
			{
				y = Math.max(hoverheight, y - 1);
			}
		}
		else
		{
			y--;
			if (y < -200)
			{
				alive = false;
			}
		}
		flicker--;
		if (flicker < 8 && changescolor && fuel>0)
		{
			
			//do glow effect
			if (flicker < 1)
			{
				//maxflicker -= 15;
				maxflicker = Std.int((maxflicker * 0.8) - 5);
				if (maxflicker <= 7)
				{
					if (flicker < -3)
					{
					maxflicker = flickerreset;
					if (color == "Red")
					{
						color = "Green";
					}
					else if (color == "Green")
					{
						color = "Blue";
					}
					else
					{
						color = "Red";
					}
					//play color change sound effect.
					SoundManager.Play("ufochange");
					
					filters = null;
					flicker = maxflicker;
					}
					else
					{
						if (filters != FA)
						{
							filters = FA;
						}
						else
						{
							filters = null;
						}
					}
				}
				else
				{
					filters = null;
					flicker = maxflicker;
				}
			}
			else
			{
				filters = FA;
			}
		}
	}
}