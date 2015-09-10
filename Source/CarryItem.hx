package;

/**
 * ...
 * @author RSGmaker
 */
class CarryItem extends EntityItem
{
	//slowed
	public var holder:Entity;
	public var OffsetX:Float;
	public var OffsetY:Float;
	public var centering:Float;
	public var DestroyOnRoundEnd:Bool;
	public var Dropable:Bool;
	public var maxdespawntime:Int;
	public var despawntime:Int;
	public function new(ani:String)
	{
		super(ani);
		type = "Carryitem";
		OffsetX = 0;
		OffsetY = -height / 2;
		centering = 0;
		DestroyOnRoundEnd = true;
		Dropable = true;
		maxdespawntime = 600;
		despawntime = -1000;
	}
	override public function Collect(player:Player) 
	{
		collectable = false;
		holder = player;
		centering = (player.width / 2) - (width / 2);
		if (maxdespawntime > 0)
		{
			despawntime = maxdespawntime;
			visible = true;
		}
	}
	override public function update():Void 
	{
		if (despawntime == -1000)
		{
			despawntime = maxdespawntime;
		}
		
		if (holder == null)
		{
			collectable = true;
			super.update();
			if (maxdespawntime > 0)
			{
				despawntime--;
				if (despawntime <= 30 && collectable)
				{
					visible = !visible;
				}
				if (despawntime <= 0)
				{
					alive = false;
				}
			}
		}
		else
		{
			despawntime = maxdespawntime;
			collectable = false;
			if (holder.alive && game.entities.indexOf(holder) >= 0 && (/*holder.type != "Enemy" || */(!holder.killed)))
			{
				if (!(holder.ground != null && (holder.ground.bonked>0)) || (!Dropable))
				{
					x = holder.x + OffsetX+centering;
					y = holder.y + OffsetY;
				}
				else
				{
					holder = null;
				}
			}
			else
			{
				holder = null;
			}
		}
		if (!alive && holder != null)
		{
			//assume the round is over and its time to reward player.
			Death();
		}
		if (y > 600)
		{
			alive = false;
		}
	}
	public function Death()
	{
		
	}
}