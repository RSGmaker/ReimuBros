package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Multiform extends PlayerAbility
{
	public var expressions:Bool = true;
	public function new(player:Player) 
	{
		super(player);
		description = "Changes appearence upon\nlosing a life";
	}
	override public function lostability() 
	{
		super.lostability();
		player.expressive = true;
	}
	override public function onframe() 
	{
		super.onframe();
		if (!expressions)
		{
			player.expressiontime = 0;
		}
	}
	override public function onloselife() 
	{
		super.onloselife();
		player.expressiontime = 0;
		if (player.charname == "hecatia")
		{
			player.charname = "hecatiam";
			expressions = false;
		}
		else if (player.charname == "hecatiam")
		{
			player.charname = "hecatiae";
			expressions = false;
		}
		else
		{
			player.charname = "hecatia";
			expressions = true;
		}
		player.expression = "";
		player.baseexpression = "";
		player.expressive = expressions;
	}
}