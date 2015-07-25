package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Warping extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		
	}
	override public function onframe() 
	{
		super.onframe();
		if (player.wrapped)
		{
			if (player.y < 160)
			{
				player.y += 480;
			}
		}
	}
}