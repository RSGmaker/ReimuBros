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
		//if (player == GameView._this.myplayer)
		{
			SoundManager.Play("collectcoin");
		}
	}
}