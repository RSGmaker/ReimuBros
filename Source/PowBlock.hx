package;

/**
 * ...
 * @author RSGmaker
 */
class PowBlock extends Entity
{
	public var HP:Int;
	public function new(ani:String) 
	{
		super(ani);
		/*super(ani);
		this.visible = false;
		Visual = new Entity(ani);
		GameView._this.stage.addChild(Visual);*/
		solid = true;
		type = "PowBlock";
		HP = 4;
		bonked = -1000;
		UID = -100-GameView._this.entities.length;
	}
	public override function update()
	{
		/*if (bonked == -1000)
		{
		}
		if (bonked > 0)
		{
			//Visual.y -= 2;
			bonked -= 1;
			if (bonked == 10)
			{
				
			}
		}
		else
		{
			bonked = -1000;
		}*/
		bonked = -1000;
	}
}