package abilities;

/**
 * ...
 * @author RSGmaker
 */
class FallThruPlatforms extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Digs down";
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.ground != null)
		{
			if (player.y<400)
			{
				player.y += 40;
			}
		}
	}
}