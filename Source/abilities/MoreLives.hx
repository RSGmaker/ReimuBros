package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MoreLives extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Start with more lives";
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
}