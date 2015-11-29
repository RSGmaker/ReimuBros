package abilities;

/**
 * ...
 * @author RSGmaker
 */
class EmotionController extends PlayerAbility
{
	public function new(player:Player) 
	{
		super(player);
		description = "Enemies cannot become\nenraged";
	}
	override public function init() 
	{
		super.init();
	}
	override public function onframe() 
	{
		super.onframe();
		var i = 0;
		while (i < game.activeEnemies.length)
		{
			var E = game.activeEnemies[i];
			E.rank = game.rank;
			E.enraged = false;
			E.enrageable = false;
			i++;
		}
	}
}