package;

/**
 * ...
 * @author RSGmaker
 */
class GiantPointItem extends EntityItem
{

	public function new() 
	{
		super("Point");
		scaleX = 2;
		scaleY = 2;
	}
	public override function Collect(player:Player)
	{
		alive = false;
		player.score += 3000;
		{
			SoundManager.Play("collectcoin");
		}
	}
	
}