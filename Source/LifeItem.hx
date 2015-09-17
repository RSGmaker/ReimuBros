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
		if (!Main._this.canlivesspawn)
		{
			alive = false;
		}
	}
	public override function Collect(player:Player)
	{
		alive = false;
		player.lives++;
		if (player == game.myplayer)
		{
			SoundManager.Play("extend");
		}
	}
}