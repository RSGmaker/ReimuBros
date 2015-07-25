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
		
	}
	override public function onrespawn() 
	{
		super.onrespawn();
		//double the invincibility time
		player.invincibility += player.invincibility;
	}
}