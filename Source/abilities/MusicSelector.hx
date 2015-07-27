package abilities;

/**
 * ...
 * @author RSGmaker
 */
class MusicSelector extends PlayerAbility
{
	public var song:Int;
	public function new(player:Player) 
	{
		super(player);
		
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 10;
		player.warncooldown = true;
		song = 1;
	}
	override public function onframe() 
	{
		super.onframe();
		player.cooldown--;
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0)
		{
			player.cooldown = player.maxcooldown;
			song++;
			if (song > 12)
			{
				song -= 13;
			}
			SoundManager.StopAll();
			if (song < 13 && song>0)
			{
				GameView._this.musicchannel = SoundManager.PlayMusic("theme" +song);
			}
			else if (song == 0)
			{
				GameView._this.musicchannel = SoundManager.PlayMusic("characterselect");
			}
		}
	}
}