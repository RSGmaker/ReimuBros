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
	public var description:String = "";
	///public var type:String = "none";
	public var flags:FlagManager;
	//You have to press ability to activate
	public static inline var Castable = 1;
	//This ability can damage/kill enemies
	public static inline var Offense = 2;
	//This ability is considered a bomb(kill all enemies on screen)
	public static inline var Bomb = 3;
	//This ability has a constant effect
	public static inline var Passive = 4;
	//fires some sort of bullet
	public static inline var Projectile = 5;
	//some sort of close ranged effect
	public static inline var Melee = 6;
	//effect causes a "super power" transformation.
	public static inline var SuperForm = 7;
	//affects mobility in some way.
	public static inline var Movement = 8;
	
	
	public var hascooldown:Bool;
	public var cooldowntimer:Float;
	public var maxcooldown:Float;
	
	public var hastransformation:Bool;
	public var maxtransformation:Float;
	public var transformationtimer:Float;
	
	public var aesthetic:Bool = false;
	//public var cooldown:Int;
	//public var timepowered:Int;
	//public var poweractive:Bool;
	public function new(player:Player) 
	{
		this.player = player;
		if (player != null)
		{
			game = player.game;
		}
		flags = new FlagManager(1);
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
	//called at the end of the update
	public function onendframe()
	{
		
	}
	//called just after onframe if the player has ability pressed, also gets called even if killed.
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
	
	public function onattacked(fatal:Bool)
	{
		
	}
	
	public function oncollect(E:EntityItem)
	{
		
	}
	//when you bump something
	public function onbump(E:Entity)
	{
		
	}
	//when you use an item and it loses 1 uses
	public function onchargeused(E:CarryItem)
	{
		
	}
	//when you are bumped by someone
	public function onbumped(E:Entity)
	{
		
	}
	
	public function oncontinue()
	{
		
	}
	public function onloselife()
	{
		
	}
	
	
	//make each characters abilities
}