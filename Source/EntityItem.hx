package;

/**
 * ...
 * @author RSGmaker
 */
class EntityItem extends Entity
{
	private static var tools:Array<String> = ["Camera"];
	private static var weapons:Array<String> = ["yinyangorbitem", "MiniHakkero", "SpellCard","SanaeStick","Boomerang","Roukanken","Bow"];
	private static var treasures:Array<String> = ["trophy"/*,"Point"*/];
	public var charname:String;
	public var collectable:Bool;
	//if false, the player must press interact to collect.(interacttext is shown when touching player)
	public var autocollect:Bool = true;
	//whether collect is called client-side.
	public var clientcollect:Bool;
	public var despawnatbottom:Bool;
	public var custommotion:Bool;
	public var cancollectfrombelow:Bool;
	public static function getitemlist(type:String):Array<String>
	{
		var ret:Array<String> = [];
		var weapon = false;
		var tool = false;
		var defense = false;
		//fills out 2/3 of the list with points.
		var pointpad = false;
		var point = false;
		var treasure = false;
		var defense = false;
		var powerpad = false;
		switch (type)
		{
			case "weapons":
				weapon = true;
			case "tools":
				tool = true;
			case "treasure":
				treasure = true;
			case "defense":
				defense = true;
			case "equipment":
				weapon = true;
				tool = true;
			case "general":
				weapon = true;
				tool = true;
				treasure = true;
				pointpad = true;
				defense = true;
			case "adventure":
				weapon = true;
				tool = true;
				treasure = true;
				pointpad = true;
				defense = true;
				powerpad = true;
			case "useful":
				weapon = true;
				tool = true;
				treasure = true;
				defense = true;
			case "valuable":
				weapon = true;
				tool = true;
				treasure = true;
			case "ufo":
				weapon = true;
				tool = true;
				defense = true;
				powerpad = true;
		}
		
		if (weapon)
		{
			ret = ret.concat(weapons);
		}
		if (tool)
		{
			ret = ret.concat(tools);
		}
		if (treasure)
		{
			ret = ret.concat(treasures);
		}
		if (defense)
		{
			if (GameView._this.GameFlags.get(Main.Adventure))
			{
				ret.push("powerup");
			}
			else
			{
				ret.push("myon");
			}
		}
		if (powerpad)
		{
			var i = 0;
			var l:Int = Std.int(ret.length);
			while (i < l)
			{
				if (GameView._this.GameFlags.get(Main.Adventure))
				{
					ret.push("powerup");
				}
				else
				{
					ret.push("myon");
				}
				i++;
			}
		}
		if (pointpad)
		{
			var i = 0;
			var m = 2;
			if (powerpad)
			{
				m = 1;
			}
			var l:Int = Std.int(ret.length * m);
			while (i < l)
			{
				ret.push("Point");
				i++;
			}
		}
		if (ret.length < 1)
		{
			return null;
		}
		return ret;
	}
	public static function getitem(type:String, random:Float=-1):String
	{
		if (type.indexOf("list:") != 0)
		{
			return type;
		}
		type = type.split(":")[1];
		if (random == -1)
		{
			random = Math.random();
		}
		var L = getitemlist(type);
		if (L == null)
		{
			return null;
		}
		return L[Std.int(random * L.length)];
	}
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
		cancollectfrombelow = true;
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
		updphysics();
		if (y > 408 && wrapped && despawnatbottom)
		{
			alive = false;
			visible = false;
		}
		if (ground != null && collectable && autocollect)
		{
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				if (game.myplayer == ground.bonkedby && cancollectfrombelow)
				{
					game.SendEvent("Collect", UID);
				}
			}
		}
		
	}
	
}