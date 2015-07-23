package;

/**
 * ...
 * @author RSGmaker
 */
class MiniBombItem extends EntityItem
{

	public function new() 
	{
		super("bomb");
		scaleX = 0.5;
		scaleY = 0.5;
	}
	public override function Collect(player:Player)
	{
		alive = false;
		
		//player.score += 200;
		if (game.powblock.HP > 3)
		{
			player.score+= 500;
		}
		else
		{
			game.powblock.HP++;
		}
		//player.score += (game.powblock.HP * 500);
		//game.powblock.HP = 4;
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