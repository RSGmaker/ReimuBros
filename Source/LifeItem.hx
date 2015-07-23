package;

/**
 * ...
 * @author RSGmaker
 */
class LifeItem extends EntityItem
{

	public function new() 
	{
		super("1up");
	}
	public override function Collect(player:Player)
	{
		alive = false;
		player.lives++;
		//SoundManager.Play("collectcoin");
		if (player == game.myplayer)
		{
			SoundManager.Play("extend");
		}
	}
}