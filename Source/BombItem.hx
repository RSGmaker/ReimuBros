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
		charname = "Bomb";
	}
	public override function Collect(player:Player)
	{
		alive = false;
		
		player.score += (game.powblock.HP * 500);
		game.powblock.HP = 4;
		if (game.Hoster)
		{
			game.SendStatus();
		}
		{
			SoundManager.Play("collectcoin");
		}
	}
}