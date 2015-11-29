package;

/**
 * ...
 * @author RSGmaker
 */
class MiniLifeItem extends EntityItem
{
	public function new() 
	{
		super("1up");
		charname = "Mini1up";
		scaleX = 0.5;
		scaleY = 0.5;
		if (!game.gamemode.canlivesspawn)
		{
			alive = false;
		}
	}
	public override function Collect(player:Player)
	{
		alive = false;
		if (scaleX >= 1 && scaleY >= 1)
		{
			player.lives++;
			if (player == game.myplayer)
			{
				SoundManager.Play("extend");
			}
			return;
		}
		player.lifefragments++;
		//player.lives++;
		if (player == game.myplayer && player.lifefragments>3)
		{
			player.lifefragments -= 4;
			player.lives++;
			SoundManager.Play("extend");
		}
		else
		{
			SoundManager.Play("collectcoin");
		}
	}
}