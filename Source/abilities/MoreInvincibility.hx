package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MoreInvincibility extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description =  "Twice the invincibility time\nafter getting hit";
	}
	override public function onrespawn() 
	{
		super.onrespawn();
		//double the invincibility time
		player.invincibility += player.invincibility;
	}
}