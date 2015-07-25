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
