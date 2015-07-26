package;
import abilities.DoubleMyon;
import abilities.SpawnShanghai;
import abilities.SuperSpeed;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.media.Sound;
import openfl.Assets;
import openfl.text.TextField;
import openfl.text.TextFormat;

/**
 * ...
 * @author RSGmaker
 */
class PlayerAbility
{
	public var player:Player;
	public var initialized:Bool;
	public var game:GameView;
	//public var cooldown:Int;
	//public var timepowered:Int;
	//public var poweractive:Bool;
	public function new(player:Player) 
	{
		this.player = player;
		game = player.game;
	}
	public function init()
	{
		
	}
	//called when the player loses this ability
	public function lostability()
	{
		
	}
	//called early if alive.
	public function onbeginframe()
	{
		
	}
	//called after movement has processed
	public function onframe()
	{
		
	}
	//called just after onframe if the player has ability pressed
	public function onuse()
	{
		
	}
	
	public function onrespawn()
	{
		
	}
	//when you hit a block
	public function onheadbonk()
	{
		
	}
	
	public function onkill(E:Entity)
	{
		
	}
	
	public function oncollect(E:EntityItem)
	{
		
	}
	//when you bump something
	public function onbump(E:Entity)
	{
		
	}
	//when you are bumped by someone
	public function onbumped(E:Entity)
	{
		
	}
	
	
	//make each characters abilities
}