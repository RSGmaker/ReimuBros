package;

/**
 * ...
 * @author RSGmaker
 */
class BombItem extends EntityItem
{

	public function new() 
	{
		super("bomb");
	}
	public override function Collect(player:Player)
	{
		alive = false;
		
		//player.score += 200;
		player.score += (game.powblock.HP * 500);
		game.powblock.HP = 4;
		if (game.Hoster)
		{
			game.SendStatus();
		}
		//if (player == game.myplayer)
		{
			SoundManager.Play("collectcoin");
		}
	}
}