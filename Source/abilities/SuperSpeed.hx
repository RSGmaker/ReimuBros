package abilities;

/**
 * ...
 * @author RSGmaker
 */
class SuperSpeed extends PlayerAbility
{

	public function new(player:Player)  
	{
		super(player);
		//description = "Moves quickly\nJumps higher";
		description = "Moves very fast\nhandles great in mid-air";
	}
	override public function init() 
	{
		super.init();
		player.deccel += 0.2;
		player.accel += 0.1;
		//player.deccel -= 0.1;
		
		player.mxspd += 2.5;
		
		//player.fallaccel -= 0.1;
		player.jumpspd -= 4;
		player.fallaccel += 0.5;
		
		player.Haccel = player.accel;
		player.Hdeccel = player.deccel;
	}
	override public function lostability() 
	{
		super.lostability();
		//player.deccel += 0.1;
		//player.fallaccel += 0.1;
		player.mxspd -= 2.5;
		
		player.deccel -= 0.2;
		player.accel -= 0.1;
		player.jumpspd += 4;
		player.fallaccel -= 0.5;
		
		player.Haccel *= 0.8;
		player.Hdeccel *= 0.8;
	}
}