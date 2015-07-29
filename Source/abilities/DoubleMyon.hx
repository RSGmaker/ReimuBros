package abilities;

/**
 * ...
 * @author RSGmaker
 */
class DoubleMyon extends PlayerAbility
{

	public function new(player:Player)  
	{
		super(player);
		description = "Can carry 2 myons\nstart with 1 myon";
	}
	override public function init() 
	{
		super.init();
		if (player.isme)
		{
		var D:Dynamic = { };
					D.UID = player.UID;
					game.SendEvent("AttachMyon", D);
		}
	}
	override public function onrespawn() 
	{
		super.onrespawn();
		if (player.isme)
		{
		var D:Dynamic = { };
					D.UID = player.UID;
					game.SendEvent("AttachMyon", D);
		}
	}
	override public function lostability() 
	{
		super.lostability();
	}
}
