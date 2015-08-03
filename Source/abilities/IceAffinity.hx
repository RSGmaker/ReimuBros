package abilities;

/**
 * ...
 * @author RSGmaker
 */
class IceAffinity extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Doesn't slip on ice";
	}
	override public function init() 
	{
		super.init();
		player.ignoreice = true;
	}
}