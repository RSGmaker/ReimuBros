package;

/**
 * ...
 * @author RSGmaker
 */
class EntityItem extends Entity
{

	public var charname:String;
	public var collectable:Bool;
	public var despawnatbottom:Bool;
	public var custommotion:Bool;
	public function new(ani:String) 
	{
		super(ani);
		charname = ani;
		touchable = true;
		type = "Item";
		deccel = 0.1;
		Ldir = 1;
		collectable = true;
		despawnatbottom = true;
		custommotion = false;
	}
	public function Collect(player:Player)
	{
		alive = false;
	}
	public override function update()
	{
		if (!custommotion)
		{
		if (Hspeed > 0)
		{
			Ldir = 1;
		}
		if (Hspeed < 0)
		{
			Ldir = -1;
		}
		if (Ldir == 1)
		{
			Hspeed = 4;
		}
		if (Ldir == -1)
		{
			Hspeed = -4;
		}
		}
		//Hspeed = 4;
		updphysics();
		if (y > 408 && wrapped && despawnatbottom/* && Ldir != 0*/)
		{
			alive = false;
			visible = false;
		}
		if (ground != null && collectable)
		{
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				if (game.myplayer == ground.bonkedby)
				{
					/*var D:Dynamic = { };
					D.UID = UID;
					D.x = x;
					D.y = y;
					D.Hspeed = -Hspeed;
					D.Vspeed = -14;
					game.SendEvent("Bump", D);*/
					game.SendEvent("Collect", UID);
				}
			}
		}
		//Ldir = 0;
		
	}
	
}