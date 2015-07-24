package;

/**
 * ...
 * @author RSGmaker
 */
class PointItem extends EntityItem
{

	public function new() 
	{
		super("Point");
	}
	public override function Collect(player:Player)
	{
		alive = false;
		player.score += 200;
		{
			SoundManager.Play("collectcoin");
		}
	}
}