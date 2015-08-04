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
		if (player.isme && game.frame==0)
		{
		var D:Dynamic = { };
					D.UID = player.UID;
					game.SendEvent("AttachMyon", D);
		}
		player.flags.set(Player.DoubleMyon, true);
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
		player.flags.set(Player.DoubleMyon, false);
	}
}
