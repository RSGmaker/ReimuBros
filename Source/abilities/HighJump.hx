package abilities;

/**
 * ...
 * @author RSGmaker
 */
class HighJump extends PlayerAbility
{

	public function new(player:Player)  
	{
		super(player);
		//description = "Moves quickly\nJumps higher";
		description = "Jumps higher";
	}
	override public function init() 
	{
		super.init();
		/*player.deccel += 0.2;
		player.accel += 0.1;
		
		player.mxspd += 2.5;*/
		
		player.jumpspd -= 7;
		player.fallaccel += 0.4;
		
		/*player.Haccel = player.accel;
		player.Hdeccel = player.deccel;*/
	}
	override public function lostability() 
	{
		super.lostability();
		/*player.mxspd -= 2.5;
		
		player.deccel -= 0.2;
		player.accel -= 0.1;*/
		player.jumpspd += 7;
		player.fallaccel -= 0.4;
		
		/*player.Haccel *= 0.8;
		player.Hdeccel *= 0.8;*/
	}
	override public function onframe() 
	{
		super.onframe();
		if (player.Vspeed < 0 && !player.controller[0])
		{
			player.Vspeed += 0.25;
		}
	}
}