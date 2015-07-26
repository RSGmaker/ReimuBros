package;

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
	public function new(ani:String) 
	{
		super(ani);
		this.visible = false;
		Visual = new Entity(ani);
		GameView._this.addChild(Visual);
		Flames = new Entity("flames");
		Flames.visible = false;
		Flames.image.image_speed = 0.5;
		GameView._this.addChild(Flames);
		type = "Block";
		UID = -100 - GameView._this.entities.length;
		started = false;
		respawn = -1;
	}
	public function Burn()
	{
		if (solid && !charred)
		{
		dangerous = true;
		if (icy)
		{
			icy = false;
			Visual.image.ChangeAnimation(image.animation);
		}
		respawn = 1500;
		}
	}
	//freeze even if charred(used at start of cirno event)
	public function DeepFreeze()
	{
		if (!icy)
		{
			dangerous = false;
			icy = true;
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
			Visual.image.ChangeAnimation(image.animation);
		}
	}
	public function Clean()
	{
		dangerous = false;
		if (icy || charred)
		{
			icy = false;
			charred = false;
			Visual.image.ChangeAnimation(image.animation);
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
			Flames.x = x-10;
			Flames.y = y - 20;
		}
		if (respawn > 0)
		{
			respawn--;
		}
		if (respawn == 0)
		{
			Clean();
		}
		Flames.visible = dangerous;
		Flames.update();
		Visual.visible = solid;
		if (!solid)
		{
			Flames.visible = false;
			dangerous = false;
		}
		Visual.x = x;
		if (bonked == -1000)
		{
			Visual.y = y;
		}
		if (bonked > 0)
		{
			Visual.y -= 2.5;
			bonked -= 1;
			Defrost();
		}
		else
		{
			
			if (Visual.y < y)
			{
				Visual.y += 2.5;
				bonked -= 1;
			}
			else
			{
				Visual.y = y;
				bonked = -1000;
			}
		}
	}
}