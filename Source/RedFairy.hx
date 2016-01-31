package;
import openfl.geom.Rectangle;
import openfl.text.TextField;

/**
 * ...
 * @author RSGmaker
 */
class RedFairy extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	public var rename:String;
	
	public var recovery:Int = 4;
	
	public var tutorial:TextField;
	public var tframe:Int = 0;
	
	public function new() 
	{
		super("RedFairy");
		accel = 0.5;
		deccel = 0.1;
		mxspd = 4;
		Ldir = 1;
		killed = false;
		flipped = -1;
		rename = "red_fairy";
	}
	
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 50;
	}
	override public function GetHitbox():Rectangle 
	{
		//return super.GetHitbox();
		return image.getBounds(game.gamestage);
	}
	public override function update()
	{
		if (!started)
		{
			started = true;
			//UID = UID * 0.09;
			UID = UID * 0.7;
			if (UID < 0.4 && game.level>1)
			{
				if (UID < 0.1)
				{
					if (UID < 0.01/* && spawns<1*/)
					{
						rename = "gold_fairy";
						recovery -= 1;
						accel += 0.2;
						mxspd += 1;
						pointvalue += 200;
					}
					else
					{
						rename = "green_fairy";
						recovery -= 1;
						pointvalue += 100;
					}
				}
				else
				{
					rename = "blue_fairy";
					accel += 0.1;
					mxspd += 0.5;
					pointvalue += 50;
					recovery += 1;
				}
			}
			if (game.IsTutorialLevel())
			{
				mxspd -= 1;
				tutorial = new TextField();
				tutorial.scaleX = 2;
				tutorial.scaleY = 2;
				tutorial.visible = false;
				tutorial.mouseEnabled = false;
				var AB = new flash.filters.GlowFilter();
				AB.blurX = 25;
				AB.blurY = 25;
				//AB.color = 0x66AAFF;
				AB.color = 0x3377CC;
			
				AB.strength = 3.25;
					
				var AA = new flash.filters.DropShadowFilter();
				AA.alpha = 1;
				AA.distance = 3;
				AA.alpha = 25;
				AA.color = 0;
			
				var filterArr:Array<flash.filters.BitmapFilter> = new Array();
				filterArr[0] = AA;
				filterArr[1] = AB;
				tutorial.filters = filterArr;
				//tutorial.text = "Hit blocks underneath enemies";
				tutorial.text = "▲";
				tutorial.textColor = 0xFFFFFF;
				tutorial.y = 50+32;
				//tutorial.y = (-tutorial.height)-6;
				
				if (Main._this.savedata.data.tutorial == true)
				{
					addChild(tutorial);
				}
				else
				{
					tutorial = null;
				}
				
			}
		}
		if (tutorial != null)
		{
			tutorial.visible = false;
		}
		if (!killed)
		{
		var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
			if (flipped == 0)
			{
				flipped = -1;
				powerup();
			}
		}
		else
		{
			dangerous = true;
		}
		if (Hspeed < mxspd && dir==1 && flipped < 1)
		{
			Hspeed += accel;
			if (Hspeed > mxspd)
			{
				Hspeed = mxspd;
			}
		}
		if (Hspeed > -mxspd && dir==-1 && flipped < 1)
		{
			Hspeed -= accel;
			if (Hspeed < -mxspd)
			{
				Hspeed = -mxspd;
			}
		}
		updphysics();
		updateanimation(rename);
		if (tutorial != null)
		{
			if (killed)
			{
				tutorial.visible = false;
			}
			else
			{
			if (flipped > 0)
			{
				//tutorial.text = "Touch flipped enemy";
				tutorial.text = "Touch\n   ▼";
				tutorial.textColor = 0xFFFFFF;
				tutorial.scaleX = 1.5;
				tutorial.scaleY = tutorial.scaleX;
				//tutorial.y = -16;
				tutorial.y = -30;
				tutorial.visible = true;
			}
			else if (ground != null)
			{
				tutorial.text = "  ▲\nJump";
				tutorial.textColor = 0xFFFFFF;
				tutorial.y = image.height + 32;
				tutorial.scaleX = 1.5;
				tutorial.scaleY = tutorial.scaleX;
				tutorial.visible = true;
				/*tframe++;
				tutorial.visible = (tframe % 4)>1;*/
				//tutorial.visible = !tutorial.visible;
			}
			else
			{
				tutorial.visible = false;
			}
			tutorial.width = tutorial.textWidth + 8;
			tutorial.height = tutorial.textHeight + 8;
			tutorial.x = (image.width/2) - (tutorial.width *0.45);
			}
		hasotherhitbox = true;
		useotherhitbox = true;
		feetposition = image.height;
		middle = (Math.floor(image.width) >> 1);
		}
		
		if (ground != null)
		{
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				if (game.myplayer == ground.bonkedby)
				{
				var D:Dynamic = { };
				D.UID = UID;
				D.x = x;
				D.y = y;
				D.Hspeed = Hspeed;
				D.Vspeed = -10;
				game.SendEvent("Bump", D);
				}
			}
			else
			{
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -4;
				}
			}
			
		}
			if (y > 408 && wrapped)
			{
				alive = false;
				visible = false;
			}
		killable = flipped > 0;
	}
	else
	{
		y += 15;
	if (y > 600)
	{
	alive = false;
	}
	}
	/*if (!alive)
	{
		if (tutorial != null)
		{
			
		}
	}*/
	}
	public override function bump(player:Player)
	{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * recovery;
			}
			else
			{
				flipped = 30 * (recovery+2);
			}
		}
		else
		{
			flipped = 0;
		}
	}
	
}