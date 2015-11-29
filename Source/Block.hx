package;
import abilities.AbsorbDamage;
import openfl.geom.Rectangle;
import openfl.display.BitmapData;

/**
 * ...
 * @author RSGmaker
 */
class Block extends Entity
{
	//public var Visual:Entity;
	//public var Flames:Entity;
	public var Visual:Animation;
	public var Flames:Animation;
	public var started:Bool;
	public var charred:Bool;
	public var respawn:Int;
	public var poison:Bool;
	public var poisonvisual:PoisonCloud;
	public var hb:Rectangle;
	public var oanimation:Array<BitmapData>;
	public var icyanimation:Array<BitmapData>;
	public var charanimation:Array<BitmapData>;
	public var LeftBlock:Block;
	public var RightBlock:Block;
	public var searched:Bool;
	public var OX:Float;
	public var OY:Float;
	public var step:Bool;
	
	//prevents reset spamming in autoscrolling levels
	public var hasreset:Bool;
	
	public function new(ani:String) 
	{
		super(null);
		this.visible = false;
		poisonvisual = new PoisonCloud(this);
		poisonvisual.alpha = 0;
		game.entitylayer.addChild(poisonvisual);
		icyanimation = game.AL.GetAnimation("icyblock");
		charanimation = game.AL.GetAnimation("charblock");
		Visual = new Animation(game.AL.GetAnimation(ani));
		Visual.visible = false;
		addChild(Visual);
		Flames = new Animation(game.AL.GetAnimation("flames"));
		Flames.visible = false;
		Flames.image_speed = 0.5;
		addChild(Flames);
		type = "Block";
		started = false;
		respawn = -1;
		oanimation = Visual.animation;
		
	}
	override public function GetHitbox():Rectangle 
	{
		if (hb == null)
		{
			hb = new Rectangle(x, y, 32, 32);
		}
		return hb;
	}
	public function Poison()
	{
		if (solid && !charred)
		{
			poisonvisual.reset();
			poisonvisual.alpha = 0;
			poison = true;
			respawn = 800;
		}
	}
	public function Burn(time:Int=750)
	{
		if (solid && !charred)
		{
		dangerous = true;
		if (icy || poison)
		{
			icy = false;
			Visual.ChangeAnimation(oanimation);
		}
		respawn = time;
		}
	}
	//freeze even if charred(used at start of cirno event)
	public function DeepFreeze()
	{
		if (!icy)
		{
			dangerous = false;
			icy = true;
			poison = false;
			charred = false;
			Visual.ChangeAnimation(icyanimation);
		}
	}
	public function Freeze()
	{
		if (!icy && !charred)
		{
			dangerous = false;
			icy = true;
			Visual.ChangeAnimation(icyanimation);
			if (solid)
			{
				//respawn = 1500;
			}
		}
	}
	public function Defrost()
	{
		dangerous = false;
		if (icy)
		{
			icy = false;
			Visual.ChangeAnimation(oanimation);
		}
	}
	public function Reset()
	{
		Clean();
		searched = false;
		
		step = false;
		//x = OX;
		//y = OY;
		Vspeed = 0;
		Hspeed = 0;
		hb = null;
	}
	public function ResetPosition()
	{
		
		if (!Math.isNaN(OX) && !Math.isNaN(OY))
		{
		x = OX;
		y = OY;
		}
	}
	public function ResetPositionX()
	{
		
		if (!Math.isNaN(OX))
		{
		x = OX;
		}
	}
	public function ResetPositionY()
	{
		
		if (!Math.isNaN(OY))
		{
		y = OY;
		}
	}
	public function Clean()
	{
		dangerous = false;
		hb = null;
		if (icy || charred || poison)
		{
			icy = false;
			charred = false;
			poison = false;
			Visual.ChangeAnimation(oanimation);
		}
		if (respawn > -1)
		{
			if (!solid)
			{
				solid = true;
			}
			respawn = -1;
		}
	}
	public function Destroy(timetorespawn:Int)
	{
		if (solid)
		{
			solid = false;
			respawn = timetorespawn;
		}
	}
	public function Char()
	{
		if (!charred)
		{
			dangerous = false;
			icy = false;
			charred = true;
			Visual.ChangeAnimation(charanimation);
			if (solid)
			{
				respawn = -1;
			}
		}
	}
	
	//returns a row of blocks,crossgaps: allows it to search an entire row instead of a side,currentsolid:false prevents returning nonsolids,includeinvalid:when true returns blocks not meant to be used(eg;the hidden blocks within the gaps)
	public function getrow(crossgaps:Bool = false, currentlysolid:Bool = false, includeinvalid = false):Array<Block>
	{
		var B = LeftBlock;
		while (B.LeftBlock != null && (!(!B.solid && B.respawn<0) || crossgaps))
		{
			B = B.LeftBlock;
		}
		var L = new Array<Block>();
		L[0] = B;
		while (B.RightBlock != null)
		{
			B = B.RightBlock;
			if (B.solid || (B.respawn<0 && includeinvalid) || (B.respawn>=0 && !currentlysolid))
			L[L.length] = B;
		}
		return L;
	}
	public override function update()
	{
		if (!started)
		{
			Flames.x = -10;
			Flames.y = - 20;
			poisonvisual.x = x;
			poisonvisual.y = y;
			poisonvisual.y -= 64+16;
			poisonvisual.x -= 32 + 16;
			UID = (x + 256) / 32;
			UID += (y / 32) * 1000;
			UID = -UID;
			started = true;
			var B:Dynamic = game.CollisionDetectPoint(x - 16, y);
			LeftBlock = B;
			B = game.CollisionDetectPoint(x + 48, y);
			RightBlock = B;
			
			OX = x;
			OY = y;
			
			this.visible = solid;
			Visual.visible = solid;
		}
		cacheAsBitmap = !dangerous;
		if (respawn > 0)
		{
			respawn--;
		}
		if (respawn == 0)
		{
			Clean();
		}
		if (poison && poisonvisual.alpha<1)
		{
			poisonvisual.alpha += 0.1;
		}
		else if (!poison && poisonvisual.alpha > 0)
		{
			poisonvisual.alpha -= 0.05;
		}
		if (poisonvisual.alpha > 0)
		{
			poisonvisual.update();
		}
		poisonvisual.visible = poisonvisual.alpha > 0;
		Flames.visible = dangerous;
		Flames.animate();
		//Flames.update();
		if (solid)
		{
			if (!visible)
			{
				visible = true;
				alpha = 0;
			}
			if (alpha < 1)
			{
				alpha += 0.1;
			}
			Visual.visible = true;
		}
		else
		{
			if (visible)
			{
				alpha -= 0.1;
				if (alpha <= 0)
				{
					visible = false;
					Visual.visible = false;
				}
			}
		}
		//this.visible = solid;
		//Visual.visible = solid;
		if (!solid)
		{
			Flames.visible = false;
			dangerous = false;
		}
		if (bonked == -1000)
		{
			Visual.y = 0;
		}
		if (bonked > 0)
		{
			Visual.y -= 2.5;
			bonked -= 1;
			Defrost();
		}
		else
		{
			
			if (Visual.y < 0)
			{
				Visual.y += 2.5;
				bonked -= 1;
			}
			else
			{
				Visual.y = 0;
				bonked = -1000;
			}
		}
		//if (Hspeed != 0 || Vspeed != 0)
		if (/*solid && */(game.scrollX != game.LscrollX || game.scrollY != game.LscrollY))
		{
			
			if (step)
			{
				var OB = false;
				if (x<=-32 || x>=800 || y<=-32 || y>=600)
				{
					OB = true;
				}
				hb = null;
				if (game.scrollX != game.LscrollX)
				{
				x = OX + Math.floor(game.scrollX);
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
					y = OY + Math.floor(game.scrollY);
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
				if (OB && solid)
				{
					if (x<=-32 || x>=800 || y<=-32 || y>=600)
					{
						
					}
					else
					{
						visible = true;
						alpha = 1;
					}
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
		
		if (x<=-32 || x>=800 || y<=-32 || y>=600)
		{
			visible = false;
		}
	}
}