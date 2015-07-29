package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Ambush extends PlayerAbility
{

	public function new(player:Player) 
	{
		super(player);
		description = "Ambush";
	}
	override public function onheadbonk() 
	{
		super.onheadbonk();
		player.Vspeed = 0;
		player.y = player.headbonk.y - player.feetposition;
		if (player.invincibility < 15)
		{
			player.invincibility = 15;
		}
	}
	
}