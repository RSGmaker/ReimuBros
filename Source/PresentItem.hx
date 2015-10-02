package;

/**
 * ...
 * @author RSGmaker
 */
class PresentItem extends EntityItem
{
	public function new() 
	{
		super("present");
	}
	public override function Collect(player:Player)
	{
		alive = false;
		player.score += 500;
		//player.score += 3000;
		if (player.isme)
		{
			SoundManager.Play("collectcoin");
			game.unlockpart("", 0, true);
		}
	}
}