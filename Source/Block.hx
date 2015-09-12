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
	public function Burn()
	{
		if (solid && !charred)
		{
		dangerous = true;
		if (icy || poison)
		{
			icy = false;
			Visual.ChangeAnimation(oanimation);
		}
		respawn = 800;
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
	}
	public function Clean()
	{
		dangerous = false;
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
		}
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
		this.visible = solid;
		Visual.visible = solid;
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
	}
}