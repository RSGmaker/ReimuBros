package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MoreLives extends PlayerAbility
{
	var toggle:Bool;
	public function new(player:Player) 
	{
		super(player);
<<<<<<< HEAD
		description = "Starts with double the lives";
		toggle = false;
=======
		description = "Each life is worth two";
>>>>>>> origin/master
	}
	override public function init() 
	{
		super.init();
		player.lives += 3;
	}
	override public function oncontinue() 
	{
		super.oncontinue();
		player.lives += 3;
	}
	override public function onloselife()
	{
		if (toggle)
		{
			player.cancel = true;
		}
		toggle = !toggle;
	}
}