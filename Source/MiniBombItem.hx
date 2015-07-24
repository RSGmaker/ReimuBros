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
		
		if (game.powblock.HP > 3)
		{
			player.score+= 500;
		}
		else
		{
			game.powblock.HP++;
		}
		if (game.Hoster)
		{
			game.SendStatus();
		}
		{
			SoundManager.Play("collectcoin");
		}
	}
	
}