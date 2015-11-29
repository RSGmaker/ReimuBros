package abilities;

/**
 * ...
 * @author RSGmaker
 */
class QuickStep extends PlayerAbility
{
	public function new(player:Player)
	{
		super(player);
		description = "Moves a bit quicker";
	}
	override public function init() 
	{
		super.init();
		//player.deccel -= 0.05;
		//player.fallaccel -= 0.05;
		player.mxspd += 1;
		
		player.deccel += 0.2;
		player.accel += 0.1;
		
		player.jumpspd -= 1.5;
		player.fallaccel += 0.035;
	}
	override public function lostability() 
	{
		super.lostability();
		//player.deccel += 0.1;
		//player.fallaccel += 0.1;
		player.mxspd -= 1;
		
		player.deccel -= 0.2;
		player.accel -= 0.1;
		
		player.jumpspd += 1.5;
		player.fallaccel -= 0.035;
	}
}