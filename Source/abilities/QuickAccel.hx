package abilities;

/**
 * ...
 * @author RSGmaker
 */
class QuickAccel extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Turns around quickly";
	}
	override public function init() 
	{
		super.init();
		player.deccel += 0.4;
		player.accel += 0.2;
		//player.fallaccel -= 0.1;
		//player.mxspd += 2;
	}
	override public function lostability() 
	{
		super.lostability();
		player.deccel -= 0.4;
		player.accel -= 0.2;
		//player.fallaccel += 0.1;
		//player.mxspd -= 2;
	}
}