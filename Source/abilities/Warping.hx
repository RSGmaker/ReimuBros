package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Warping extends PlayerAbility
{

	//currently unused
	public function new(player:Player) 
	{
		super(player);
		description = "Top row warp";
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