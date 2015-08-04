package abilities;

/**
 * ...
 * @author RSGmaker
 */
class ExtraPoints extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Point items and leftover\nPOW block uses give 50%\nmore score";
	}
	override public function oncollect(E:EntityItem) 
	{
		super.oncollect(E);
		if (E.charname == "Point")
		{
			if (E.scaleX < 2)
			{
				player.score += 100;
			}
			else
			{
				player.score += 1000;
			}
		}
		if (E.charname == "bomb")
		{
			if (E.scaleX > 0.5)
			{
				player.score+= 500;
			}
			else
			{
				player.score+= 200;
			}
		}
	}
}