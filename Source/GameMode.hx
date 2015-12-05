package;

/**
 * ...
 * @author RSGmaker
 */
class GameMode
{
	//displayed when player clicks the button associated with this game mode.
	public var description:String;
	//displayed on buttons in titlescreen, and before the description.
	public var fullname:String;
	//shortened name(displayed below progress bar, also used to store save data, and multiplayer room names)
	public var name:String;
	public var category:String;
	//if true, this mode doesn't need to be unlocked to play it.
	public var preunlocked:Bool;
	
	//What gameflags will be transferred over to main.gameflags, when this gamemode is chosen.
	public var GameFlags:FlagManager;
	//when false characters will have their abilities removed.
	public var abilitiesenabled:Bool;
	//determines if myons/zombiefairies spawn in this mode(yukari/alice's ability are the few exceptions).
	public var canmyonspawn:Bool;
	//if not blank, it forces the player to play as that character.
	public var forcedcharacter:String;
	//if false, when the player gameovers, they have to completely restart or quit(in multiplayer EVERYONE is penalized).
	public var cancontinue:Bool;
	//self explanitory, if false players cannot get lives outside of abilities.
	public var canlivesspawn:Bool;
	//number of money given to player for completing the challenge.
	public var reward:Int;
	//number of levels required for the reward to be given.
	public var rewardrequirement:Int;
	//the gamemode to unlock after reward has been reached.
	public var unlock:String="";
	//if false,prevents player from changing the level they start at.
	public var levelselect:Bool;
	//the level the gamemode starts at.
	public var level:Int;
	//number of levels to add after completing one.(used to make game progress faster)
	public var levelincrement:Int;
	//if true, the button is hidden until the gamemode has been unlocked.
	public var hidden:Bool;
	//if true, player lives don't decrement upon respawn.
	public var infinitelives:Bool;
	//if true, powblock doesn't shrink after use.
	public var infinitepowblock:Bool;
	//if false, the ufo items won't spawn
	public var ufoitemsenabled:Bool;
	
	//list of all gamemodes
	public static var Modes:Array<GameMode>;
	//list of gamemodes by category
	public static var Categories:Map<String,Array<GameMode>>;
	public static function init()
	{
		CheckUnlockData();
		Modes = new Array<GameMode>();
		var M = Modes;
		
		var G:GameMode = new GameMode();
		G.name = "Classic";
		G.fullname = "Classic Mode";
		G.description = "Clear levels by defeating enemies.\nHit blocks with enemies on top of them to flip them over;\ntouching a flipped-over enemy defeats them.";
		G.preunlocked = true;
		G.reward = 30;
		G.rewardrequirement = 30;
		G.unlock = "AllStar";
		M.push(G);
		
		G = new GameMode();
		G.name = "Adventure";
		G.fullname = "Adventure Mode";
		G.GameFlags.set(Main.Adventure, true);
		G.abilitiesenabled = false;
		G.canmyonspawn = false;
		G.preunlocked = true;
		G.reward = 30;
		G.rewardrequirement = 20;
		G.unlock = "AllStar";
		//G.description = "Travel through Gensokyo.\nCharacter abilities are replaced with powerup items.";
		G.description = "Levels aren't stationary as you're used to in this mode.\nYou also don't have standard abilities in this mode. Instead, you can look for powerupas which are found in special blocks.";
		M.push(G);
		
		G = new GameMode();
		G.name = "AllStar";
		G.fullname = "All Star Mode";
		G.GameFlags.set(Main.AllStar, true);
		G.reward = 20;
		G.rewardrequirement = 20;
		G.unlock = "Danmaku";
		G.forcedcharacter = "red_fairy";
		G.cancontinue = false;
		G.canlivesspawn = false;
		//G.hidden = true;
		G.description = "There are no lives in this mode.\nYou can switch to characters unlocked in this play session.\nLosing a life means losing a character.\nIf you run out of characters, it's game over.";
		M.push(G);
		
		//challenges
		G = new GameMode();
		G.name = "Danmaku";
		G.fullname = "Danmaku";
		G.category = "Challenge";
		G.reward = 20;
		//G.rewardrequirement = 15;
		G.rewardrequirement = 12;
		G.unlock = "Explosive";
		G.GameFlags.set(Main.Danmaku, true);
		G.GameFlags.set(Main.EventRoundsOnly, true);
		G.levelselect = false;
		G.level = 35;
		G.levelincrement = 5;
		G.cancontinue = false;
		G.description = "Difficulty ramps up quickly in this mode.";
		M.push(G);
		
		G = new GameMode();
		G.name = "Explosive";
		G.fullname = "Explosive";
		G.category = "Challenge";
		G.reward = 20;
		G.rewardrequirement = 6;
		G.unlock = "Point Collection";
		G.GameFlags.set(Main.Explosive, true);
		G.GameFlags.set(Main.EventRoundsOnly, true);
		G.levelselect = false;
		//G.level = 65;
		//G.level = 5;
		G.level = 125;
		G.levelincrement = 5;
		//G.levelincrement = 35;
		G.cancontinue = false;
		//G.description = "Bombs rain down, which both speeds up progress, and keeps you on your toes.";
		//G.description = "Tons of enemies, tons of bombs, what could go wrong?";
		G.description = "Tons of enemies, tons of bombs, what could go wrong?";
		M.push(G);
		
		G = new GameMode();
		G.name = "Point Collection";
		G.fullname = "Point Collection";
		G.category = "Challenge";
		G.reward = 20;
		G.rewardrequirement = 5;
		G.unlock = "Boss Rush";
		G.infinitelives = true;
		G.canlivesspawn = false;
		G.infinitepowblock = true;
		G.ufoitemsenabled = false;
		G.GameFlags.set(Main.PointCollecting, true);
		G.GameFlags.set(Main.EventRoundsOnly, true);
		G.levelselect = false;
		//G.level = 65;
		//G.level = 5;
		G.level = 21;
		G.levelincrement = 1;
		//G.levelincrement = 35;
		G.cancontinue = false;
		//G.description = "Bombs rain down, which both speeds up progress, and keeps you on your toes.";
		//G.description = "Tons of enemies, tons of bombs, what could go wrong?";
		//G.description = "In order to progress you must collect point items.\nReimus are known for stealing point items,\nwatch out as they will reduce your progress.\ngetting 100% clears the level, whilst 0% results in a game over.";
		//G.description = "In order to progress you must collect items.\nReimus are known for stealing point items,\nwatch out as they will reduce your progress.\nwatch out as enemies will spawn without limit,\nand getting a progress of 0% results in a game over.";
		//G.description = "In order to progress you must collect items.\nReimus spawn from below to get your point items,\nif they take any you'll be penalized on your progress.\nwatch out as enemies will spawn without limit,\nand getting a progress of 0% results in a game over.";
		G.description = "You must collect items in order to progress.\nReimus spawn from below, and you're penalized if they collect point items.\nEnemies spawn infinitely, reaching a progress of 0% results in a game over.\nHowever, you have infinite lives and POW Block uses.";
		M.push(G);
		
		G = new GameMode();
		G.name = "Boss Rush";
		G.fullname = "Boss Rush";
		G.category = "Challenge";
		G.reward = 20;
		G.rewardrequirement = 4;
		G.unlock = "Truck Hoarder";
		G.GameFlags.set(Main.Bossrush, true);
		G.GameFlags.set(Main.EventRoundsOnly, true);
		G.levelselect = false;
		G.level = 35;
		G.canlivesspawn = false;
		G.canmyonspawn = false;
		G.levelincrement = 5;
		G.cancontinue = false;
		//G.description = "Every level is a boss event.\nSurvive as many as you can.";
		G.description = "Every level is a boss.\nResources are scarce.\nSurvive as best you can.";
		M.push(G);
		
		G = new GameMode();
		G.name = "Truck Hoarder";
		G.fullname = "Truck Hoarder";
		G.category = "Challenge";
		G.infinitelives = true;
		G.canlivesspawn = false;
		G.ufoitemsenabled = false;
		G.reward = 20;
		G.rewardrequirement = 3;
		//G.unlock = "Truck Hoarder";
		G.GameFlags.set(Main.TruckHoarder, true);
		//G.GameFlags.set(Main.NoEvents, true);
		G.levelselect = false;
		G.level = 56;
		G.cancontinue = false;
		G.description = "Protect the truck.";
		M.push(G);
		
		
		
		
		
		
		SortCategories();
	}
	private static function CheckUnlockData()
	{
		var data = Main._this.savedata.data;
		var gm = data.gmunlock;
		if (gm == null)
		{
			var D:Dynamic = { };
			data.gmunlock = D;
		}
		var gmc = data.gmclear;
		if (gmc == null)
		{
			var D:Dynamic = { };
			data.gmclear = D;
		}
	}
	public static function GetModeByName(name:String):GameMode
	{
		var i = 0;
		while (i < Modes.length)
		{
			if (Modes[i].name == name)
			{
				return Modes[i];
			}
			i++;
		}
		return null;
	}
	private static function SortCategories()
	{
		var M = Modes;
		Categories = new Map<String,Array<GameMode>>();
		var C = Categories;
		var i = 0;
		while (i < M.length)
		{
			var G:GameMode = M[i];
			if (!C.exists(G.category))
			{
				C.set(G.category, new Array<GameMode>());
			}
			C[G.category].push(G);
			i++;
		}
	}
	public function getunlocked():Bool
	{
		if (preunlocked)
		{
			return true;
		}
		var data = Main._this.savedata.data;
		var gm = data.gmunlock;
		var unlocked = Reflect.field(gm, name);
		return (unlocked == true);
	}
	public function setunlocked(unlock:Bool)
	{
		var data = Main._this.savedata.data;
		var gm = data.gmunlock;
		Reflect.setField(gm, name, unlock);
	}
	public function getcleared():Bool
	{
		var data = Main._this.savedata.data;
		var gm = data.gmclear;
		var cleared = Reflect.field(gm, name);
		return (cleared == true);
	}
	public function setcleared(cleared:Bool)
	{
		var data = Main._this.savedata.data;
		var gm = data.gmclear;
		Reflect.setField(gm, name, cleared);
	}
	public function new() 
	{
		name = "Unknown";
		fullname = "Unknown Mode";
		description = "Description not found.";
		category = "";
		GameFlags = new FlagManager(1);
		abilitiesenabled = true;
		canmyonspawn = true;
		forcedcharacter = "";
		cancontinue = true;
		canlivesspawn = true;
		reward = 0;
		rewardrequirement = 0;
		preunlocked = false;
		level = 1;
		levelincrement = 1;
		levelselect = true;
		hidden = false;
		infinitelives = false;
		infinitepowblock = false;
		ufoitemsenabled = true;
	}
	
}