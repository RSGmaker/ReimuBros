package;
import openfl.geom.Rectangle;
import openfl.display.BitmapData;

/**
 * ...
 * @author RSGmaker
 */
class Block extends Entity
{
	public var Visual:Entity;
	public var Flames:Entity;
	public var started:Bool;
	public var charred:Bool;
	public var respawn:Int;
	public var poison:Bool;
	public var poisonvisual:PoisonCloud;
	public var hb:Rectangle;
	public var oanimation:Array<BitmapData>;
	public function new(ani:String) 
	{
		super(null);
		this.visible = false;
		poisonvisual = new PoisonCloud();
		poisonvisual.alpha = 0;
		GameView._this.addChild(poisonvisual);
		Visual = new Entity(ani);
		Visual.visible = false;
		addChild(Visual);
		Flames = new Entity("flames");
		Flames.visible = false;
		Flames.image.image_speed = 0.5;
		addChild(Flames);
		type = "Block";
		started = false;
		respawn = -1;
		oanimation = Visual.image.animation;
		
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
			Visual.image.ChangeAnimation(oanimation);
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
			Visual.ChangeAnimation("icyblock");
		}
	}
	public function Freeze()
	{
		if (!icy && !charred)
		{
			dangerous = false;
			icy = true;
			Visual.ChangeAnimation("icyblock");
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
			Visual.image.ChangeAnimation(oanimation);
		}
	}
	public function Clean()
	{
		dangerous = false;
		if (icy || charred || poison)
		{
			icy = false;
			charred = false;
			poison = false;
			Visual.image.ChangeAnimation(oanimation);
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
			Visual.ChangeAnimation("charblock");
			if (solid)
			{
				respawn = -1;
			}
		}
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
		Flames.visible = dangerous;
		Flames.update();
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