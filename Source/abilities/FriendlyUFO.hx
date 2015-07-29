package abilities;

/**
 * ...
 * @author RSGmaker
 */
class FriendlyUFO extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "UFOs won't fire";
	}
	
}