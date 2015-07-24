package;
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
class Player extends Entity
{

	public var accel:Float;
	public var Haccel:Float;
	public var Hdeccel:Float;
	//public var deccel:Float;
	public var mxspd:Float;
	public var controller:Array<Bool>;
	public var charname:String;
	public var lives:Int;
	public var ID:String;
	public var score:Int;
	//each player uses up their score to produce a 1up.
	public var spentscore:Int;
	public var steps:Float;
	//public var invincibility:Int;
	public var playername:String;
	//public var nameplate:TextField;
	public var nameplate:Sprite;
	public var nameplatetext:TextField;
	public var cooldownbar:Shape;
	public var format:TextFormat;
	//the last frame this player has been active
	public var frame:Int;
	//how long this player has been playing
	public var playing:Int;
	private var filterArr:Array<flash.filters.BitmapFilter>;
	//public var myMyon:MyonItem;

	
	public static var characters:Array<String> = ["reimu", "marisa", "patchouli", "remilia", "sanae", "sakuya", "suwako", "yuyuko", "tenshi", "iku", "aya", "alice", "youmu", "shikieiki", "flandre", "satori", "koishi", "momiji", "nitori", "udongein", "komachi", "yuuka", "mokou", "meiling", "parsee", "kokoro", "kogasa", "kasen", "utsuho", "suika", "kaguya", "eirin", "nazrin", "orin", "hina", "byakuren", "chiyuri", "ellen", "elly", "gengetsu", "kana", "kotohime", "elis", "louise", "mai", "meira", "mugetsu", "orange", "rika", "rikako", "sara", "yuki", "yumeko", "yumemi", "akyu", "futo", "kagerou", "keine", "kosuzu", "lunachild", "mamizou", "medicine", "minoriko", "murasa", "seiga", "sekibanki", "shanghai", "shinmyoumaru", "shizuha", "shou", "sunnymilk", "tokiko", "wriggle", "yoshika", "starsaphire", "lily", "letty", "makairesident-a", "makairesident-b", "ayana", "matenshi", "noroiko", "mystia", "lunasa", "lyrica", "merlin", "maribel", "renko", "miko", "reisen", "ruukoto", "tojiko", "toyohime", "yorihime", "wakasagihime", "yatsuhashi", "mima", "konngara","tewi","kanako","ringo","doremy","seiran","sumireko","rin","raiko","shingyoku","hatate","daiyousei","kurumi","yuugi","benben","ichirin","kyouko","yamame","koakuma","shinki","rengeteki","sariel","yukari", "seija", "rumia","cirno","nue","chen","ran"];
	
	public static var Scharacters:Array<String> = ["aya", "alice", "youmu", "cirno", "letty", "yukari", "seija", "mokou", "orin", "yuyuko","lunasa","lyrica","merlin","kaguya","kanako","murasa","koishi","tewi","iku","tenshi","keine","reimu","meiling","sakuya","ran","chen","nue","sanae","marisa","rumia","komachi","wriggle","raiko","yuugi"];
	public static var Description:Array<String> = ["Moves quickly", "Defeating fairies spawns\nShanghai dolls", "Can carry 2 myons\nstart with 1 myon", "doesn't slip on ice", "Chills the world\ndoesn't slip on ice", "Manipulate gaps", "Prevents screen\nflipping", "Turns everything to ash.\nFire proof", "Defeating fairies spawns\nZombie fairies", "Kills mystias on\ncontact", "Alternate music", "Alternate music", "Alternate music", "Invincibility time+", "Extra powblock uses", "Ambush", "Turns invisible by\nstaying still", "Digs down", "Electric proof", "Earthquakes", "EX Form", "Yin-Yang Orbs", "Dash Attack", "-The World-", "Cheeee~n", "Dash Attack", "UFOs won't fire", "Momentum aimed\nshot", "Wide shot", "Has an appetite\nfor enemies", "teleports to your\nmouse's position", "Light dash attack", "flips everything over","Hits 3 blocks at once"];
	
	public static var charorder:Array<String> = ["reimu", "marisa", "rumia", "daiyousei", "cirno", "meiling", "koakuma", "patchouli", "sakuya", "remilia", "flandre", "rin",
	"letty", "chen", "alice", "shanghai"/*,"hourai"*/, "lily", "lyrica", "lunasa", "merlin", "youmu", "yuyuko", "ran", "yukari",
	"suika",
	"wriggle", "mystia", "keine", "tewi", "udongein", "eirin", "kaguya", "mokou",
	"aya", "medicine", "yuuka", "komachi", "shikieiki",
	"shizuha", "minoriko", "hina", "nitori", "momiji", "sanae", "kanako", "suwako",
	"iku", "tenshi", "hatate", "kokoro",
	/*"kisume", */"yamame", "parsee", "yuugi", "satori", "orin", "utsuho", "koishi",
	"nazrin", "kogasa", "ichirin"/*,"unzan"*/, "murasa", "shou", "byakuren", "nue",
	"kyouko", "yoshika", "seiga", "tojiko", "futo", "miko", "mamizou",
	"wakasagihime", "sekibanki", "kagerou", "benben", "yatsuhashi", "seija", "shinmyoumaru", "raiko",
	"sumireko",
	"seiran", "ringo", "doremy",
	"lunachild", "starsaphire", "sunnymilk", "reisen", "toyohime", "yorihime", "kasen", "kosuzu","tokiko","akyu","maribel","renko",
	"shingyoku","elis", "sariel", "mima", "konngara",
	"rika","noroiko", "meira", "matenshi",
	"ellen", "kotohime", "kana", "rikako", "chiyuri", "yumemi", "ruukoto",
	"orange", "kurumi", "elly", "rengeteki"/*, "yuuka"*/, "mugetsu", "gengetsu",
	"sara","louise"/*,"alice"*/,"yuki","mai","ayana","yumeko","shinki","makairesident-a","makairesident-b"];
	//yukari:idk maybe a rare event that has something to do with the chen gaps.
	//rumia rare round event where rumias spawn(they have a large darkness around them making it hard to see, beating the round unlocks rumia for all players)
	//seija rare event only seijas spawn and the view flips during the round.
	//cirno a bunch of cirnos spawn and everything instantly freezes when the event starts.
	//mima everyone has gameovered twice and has been bumped twice. she then has a rare chance to take over the round.
	//nue, only nue can spawn in this round and ufos are constantly spawning, at the end of the round everyone unlocks nue.
	//or on nue, normal enemies spawn and on the kill event for the enemies, instead of dying they turn into a cloud(or a poof) the cloud then spawns a nue.
	//public static var hiddencharacters:Array<String> = ["unused","yukari", "seija", "rumia","cirno","nue","chen","ran"];
	public static function getRandomCharacter():String
	{
		return characters[Math.floor(Math.random() * characters.length)];
	}
	
	//public var killed:Bool;
	public var started:Bool;
	//ignores ice physics
	public var ignoreice:Bool;
	public var baseflags:FlagManager;
	public var flags:FlagManager;
	public var allmyons:Array<MyonItem>;
	
	//faster speed but slightly reduced responsiveness and more floaty
	public static inline var SuperSpeed = 0;
	//start out with a myon and can carry a second one.
	public static inline var DoubleMyon = 1;
	//walk on ice with no penalty
	public static inline var IceAffinity = 2;
	//wrapping around the top row warps you to the bottom
	public static inline var Warping = 3;
	//causes client to ignore "Flip!" events
	public static inline var FlipResistance = 4;
	//sometimes when killing a redfairy a zombie fairy will spawn
	public static inline var SpawnZombieFairies = 5;
	//ignore firey platforms
	public static inline var FireProof = 6;
	//ability to cling to ceilings longer
	public static inline var Floating = 7;
	//kills mystia on contact even if unflipped
	public static inline var EatMystia = 8;
	//invincibility time increased
	public static inline var MoreInvincibility = 9;
	//a 50% chance to not use pow block hp when used
	public static inline var PreservePowBlock = 10;
	//when the player hits a block they teleport ontop of it
	public static inline var Ambush = 11;
	//Turns invisible&invincible if the player sits still long enough
	public static inline var CanHide = 12;
	//pressing down lets you fall through platforms
	public static inline var FallThruPlatforms = 13;
	//Immune to lightning
	public static inline var ElectricProof = 14;
	//ability to hit the entire row of blocks youre standing on
	public static inline var Earthquake = 15;
	//ability to gain super power status and improved stats by transforming into ExKeine
	public static inline var ExKeine = 16;
	//ability to throw a yinyang orb to attack enemies
	public static inline var YinYangOrbs = 17;
	//Accelerate quickly forward with superpower
	public static inline var DashAttack = 18;
	//
	public static inline var ZaWarudo = 19;
	//fires a chen bullet
	public static inline var Cheeen = 20;
	//ufos don't fire bullets
	public static inline var FriendlyUFO = 21;
	
	//public static inline var Drums = 22;
	//a straight moving bullet with vertical momentum
	public static inline var StarBulletG = 22;
	
	//a shotgun shot
	public static inline var StarBulletY = 23;
	
	//kills an enemy instead of killing you...if your cooldown is ready.
	public static inline var EnemyEater = 26;
	//teleports to your mouse
	public static inline var Teleporter = 27;
	//kill enemies by jumping on them(possibly too OP)
	public static inline var JumpMan = 28;
	//a lesser dash attack, can be used more often though
	public static inline var LightDashAttack = 29;
	//hits all block(identical to hitting powblock)
	public static inline var KaPow = 30;
	//mokou's bomb ability, kills everything and chars all blocks. 
	public static inline var WorldScorcher = 31;
	
	public static inline var GapManipulator = 32;
	
	public static inline var WorldFreezer = 33;
	//bumps 3 blocks at a time
	public static inline var HeavyBonk = 34;
	
	
	public var zombiefairychance = 0.04;
	public var zombiefairytype = "zombiefairy";
	public var zombiefairyscale = 1.0;
	public var Ofallaccel = 0.0;
	//fallaccel when floating
	public var fallaccel2 = 0.0;
	public var jumpspd = 0.0;
	
	//when active causes the player to kill anything they touch
	public var superpower:Bool=false;
	
	//used if the character has a unique ability with a cooldown timer
	public var cooldown:Int;
	//used to reset the cooldown timer
	public var maxcooldown:Int;
	//whether or not to tell the player when their cooldown finishes
	public var warncooldown:Bool;
	
	//public var cooldowntext = "READY";
	public var cooldowntext = "Ability ready!";
	
	public static inline var base_deccel = 0.5+0.4;
	public static inline var base_accel = 0.7 + base_deccel;
	public static inline var base_mxspd = 7+1.55;
	public static inline var base_fallaccel = 1.0+0.1;
	public static inline var base_jumpspd = -19-0.5;
	public function new(charname:String,controller:Array<Bool>) 
	{
		super(charname);
		allmyons = new Array<MyonItem>();
		scaleX = 0.85;
		scaleY = 0.85;
		type = "Player";
		this.charname = charname;
		flags = new FlagManager(1);
		//baseflags = new FlagManager(1);
		maxcooldown = 300;
		cooldown = 0;
		useotherhitbox = true;
		warncooldown = false;
		jumpspd = base_jumpspd;
		//feetposition = height;
		//flags.set(SpawnZombieFairies, true);
		switch (charname)
		{
			case "aya":
				flags.set(SuperSpeed, true);
			case "alice":
				zombiefairytype = "shanghai";
				zombiefairyscale = 0.6;
				flags.set(SpawnZombieFairies, true);
				zombiefairychance += 0.06;
			case "youmu":
				flags.set(DoubleMyon, true);
			case "cirno":
				flags.set(IceAffinity, true);
			case "letty":
				flags.set(IceAffinity, true);
				flags.set(WorldFreezer, true);
				warncooldown = true;
				maxcooldown = 3600+1000;
			case "yukari":
				//flags.set(Warping, true);
				flags.set(GapManipulator, true);
			case "seija":
				flags.set(FlipResistance, true);
			case "mokou":
				flags.set(FireProof, true);
				flags.set(WorldScorcher, true);
				warncooldown = true;
				maxcooldown = 3600+1000;
			case "orin":
				flags.set(SpawnZombieFairies, true);
				zombiefairychance += 0.06;
			case "yuyuko":
				flags.set(EatMystia, true);
			case "kaguya":
				flags.set(MoreInvincibility, true);
			case "kanako":
				flags.set(PreservePowBlock, true);
			case "murasa":
				flags.set(Ambush, true);
			case "koishi":
				flags.set(CanHide, true);
				maxcooldown = 25;
				cooldown = 150;
			case "tewi":
				flags.set(FallThruPlatforms, true);
			case "iku":
				flags.set(ElectricProof, true);
			case "tenshi":
				flags.set(Earthquake, true);
				warncooldown = true;
				maxcooldown = 900;
			case "keine":
				flags.set(ExKeine, true);
				warncooldown = true;
				maxcooldown = 1800;
			case "reimu":
				flags.set(YinYangOrbs, true);
				warncooldown = true;
				///maxcooldown = 430;
				maxcooldown = 380;
			case "meiling":
				flags.set(DashAttack, true);
				warncooldown = true;
				maxcooldown = 300;
			case "sakuya":
				flags.set(ZaWarudo, true);
				warncooldown = true;
				//maxcooldown = 4200;
				maxcooldown = 3600;
			case "raiko":
				flags.set(KaPow, true);
				maxcooldown = 3600;
				warncooldown = true;
			case "ran":
				flags.set(Cheeen, true);
				warncooldown = true;
				maxcooldown = 300;
			case "chen":
				flags.set(DashAttack, true);
				warncooldown = true;
				maxcooldown = 300;
			case "sanae":
				flags.set(StarBulletG, true);
				warncooldown = true;
				maxcooldown = 400;
			case "marisa":
				flags.set(StarBulletY, true);
				warncooldown = true;
				//maxcooldown = 720;
				maxcooldown = 660;
			case "rumia":
				flags.set(EnemyEater, true);
				warncooldown = true;
				maxcooldown = 390;
			case "komachi":
				flags.set(Teleporter, true);
				warncooldown = true;
				maxcooldown = 420;
			case "nue":
				flags.set(FriendlyUFO, true);
			case "wriggle":
				//flags.set(JumpMan, true);
				flags.set(LightDashAttack, true);
				warncooldown = true;
				maxcooldown = 180;
			case "yuugi":
				flags.set(HeavyBonk, true);
			case "tojiko":
				feetposition -= 8;
			case "ayana":
				feetposition -= 2;
			case "makairesident-a":
				feetposition -= 2;
			case "makairesident-b":
				feetposition -= 1;
			case "matenshi":
				feetposition -= 1;
			case "noroiko":
				feetposition -= 1;
			default:
		}
		if (cooldown == 0 && maxcooldown > 0)
		{
			cooldown = maxcooldown;
		}
		//if (flags.getactiveflags().length == 0)
		if (flags.isempty())
		{
			flags.set(Floating, true);
		}
		flags.set(SpawnZombieFairies, true);
		//zombiefairychance += 0.5;
		/*if (charname == "raiko")
		{
			flags.set(Drums, true);
		}*/
		if (game.tournament)
		{
			//dissallow abilites in tourneys
			flags.clearall();
		}
		this.controller = controller;
		//accel = 0.5;
		//accel = 0.6;
		deccel = base_deccel;
		//deccel = 0.5;
		accel = base_accel;
		//accel = 0.7+deccel;
		//Haccel = accel * 0.25;
		Haccel = accel * 0.35;
		Hdeccel = deccel * 0.35;
		//deccel = 0.1;
		
		mxspd = base_mxspd;
		fallaccel = base_fallaccel;
		//mxspd = 7;
		//fallaccel = 1.0;
		//if (charname == "aya")
		if (flags.get(SuperSpeed))
		{
			deccel -= 0.1;
			fallaccel -= 0.1;
			//accel += 0.1;
			mxspd += 2;
		}
		/*if (flags.get(EnemyEater))
		{
			deccel += 0.05;
			accel += 0.1;
			mxspd += 1;
		}*/
		if (flags.get(Floating))
		{
			//headbounce = false;
		}
		
		killed = false;
		lives = 3;
		ID = "";
		score = 0;
		steps = 0;
		invincibility = 0;
		//fallaccel = 0.8;
		
		playername = "";
		//nameplate = new TextField();
		nameplate = new Sprite();
		nameplatetext = new TextField();
		cooldownbar = new Shape();
		cooldownbar.y = 5;
		/*cooldownbar.width = 100;
		cooldownbar.height = 16;
		cooldownbar.x = 0;
		cooldownbar.y = 0;*/
		nameplate.addChild(nameplatetext);
		nameplate.addChild(cooldownbar);
		
		//var  AA = new flash.filters.BevelFilter(5, 1, 0x000000, 1, 0xAAAAAA, 0.5, 5, 5, 0.5, 100);
		//var AA = new flash.filters.BevelFilter(4, 45, 0xFFFFFF, 1, 0xCC0000, 1, 10, 10, 2, 3);
		var AA = new flash.filters.DropShadowFilter();
		AA.alpha = 1;
		AA.distance = 3;
		AA.alpha = 25;
		AA.color = 0;
		filterArr = new Array();
		filterArr[0] = AA;
		nameplate.filters = filterArr;
		
		/*var bevel = new flash.filters.BevelFilter(); 
		bevel.distance = 6; 
		//bevel.angle = 45; 
		bevel.angle = 90; 
		bevel.highlightColor = 0xFFFFFF; 
		bevel.highlightAlpha = 0.2; 
		bevel.shadowColor = 0x888888; 
		bevel.shadowAlpha = 0.2; 
		bevel.blurX = 3; 
		bevel.blurY = 3; 
		bevel.strength = 2; 
		//bevel.quality = BitmapFilterQuality.HIGH; 
		//bevel.type = BitmapFilterType.INNER; 
		bevel.knockout = false; 
		filterArr = new Array();
		filterArr[0] = bevel;
		
		cooldownbar.filters = filterArr;*/
		//if (game.myplayer == null)
		{
			var AB = new flash.filters.GlowFilter();
			AB.blurX = 20;
			AB.blurY = 20;
			if (game.myplayer == null)
			{
				AB.color = 0x66AAFF;
			}
			else
			{
				AB.color = 0xFFAA66;
			}
			AB.strength = 1.25;
		
		filterArr = new Array();
		filterArr[0] = AB;
		filters = filterArr;
		}
		
		//nameplate.blendMode = openfl.display.BlendMode.INVERT;
		//nameplate.text = "\nTesting\nsgopvb;v";
		nameplate.x = 100;
		nameplate.y = 100;
		format = new TextFormat();
		format.font = "Arial";
		format.size = 16;
		format.color = 0xFFFFFF;
		nameplatetext.mouseEnabled = false;
		//format.align = flash.text.TextFormatAlign.CENTER;
		nameplatetext.setTextFormat(format);
		game.addChild(nameplate);
		frame = game.frame;
		playing = -1;
		started = false;
		ignoreice = false;
		//if (charname == "cirno" || charname == "letty")
		if (flags.get(IceAffinity))
		{
			ignoreice = true;
		}
		
		Ofallaccel = fallaccel;
		fallaccel2 = fallaccel / 16;
		
		//if (game.myplayer != null)
		/*if (flags.get(CanHide))
		{
			alpha = 0.2;
			scaleX = 2;
		}*/
		//nameplate = new TextField();
		//nameplate.y = 100;
		//this.addChild(nameplate);
		//addChild(nameplate);
		baseflags = flags.clone();
	}
	
	public static var myplayer(get, null):Player;
	public static function get_myplayer(): Player
	{
		return GameView._this.myplayer;
	}
	
	public var isme(get, null):Bool;
	public function get_isme():Bool
	{
		return game.myplayer == this;
	}
	
	public override function update()
	{
		if (!killed && lives>-1)
		{
			if (!started)
			{
				started = true;
			}
			if (invincibility > 1000)
			{
				invincibility = 10001;
			}
			if (myMyon != null && !myMyon.alive)
			{
				myMyon = null;
			}
			var DCL = deccel;
			if (ground != null && ground.icy && !ignoreice)
			{
				deccel = Hdeccel;
			}
			if (flags.get(Floating))
			{
				if ((controller[0]) && Vspeed > -0 && Vspeed < 2.0)
				{
					//fallaccel = Ofallaccel / 16;
					fallaccel = fallaccel2;
				}
				else
				{
					fallaccel = Ofallaccel;
				}
			}
			updphysics();
			if (cooldown > 0)
			{
				cooldown--;
				//scaleX = 1;
				if (flags.get(CanHide) && invincibility<=0)
				{
					if (Hspeed != 0 || Vspeed != 0)
					{
						cooldown = maxcooldown;
					}
					alpha = 1;
				}
				if (superpower && flags.get(ExKeine) && cooldown < 30)
				{
					invincibility = 5;
				}
				if (flags.get(EnemyEater))
				{
					superpower = false;
					if (mxspd <= base_mxspd)
					{
						deccel = base_deccel + 0.05;
						accel = base_accel + 0.1;
						mxspd = base_mxspd + 1;
						fallaccel = base_fallaccel + 0.1;
					}
				}
			}
			else
			{
				cooldown--;
				if (flags.get(CanHide))
				{
					
					if (invincibility < 5)
					{
						invincibility = 5;
					}
					alpha = 0.5;
					//scaleX = 2;
					if (Hspeed != 0 || Vspeed != 0)
					{
						cooldown = maxcooldown;
					}
				}
				if (flags.get(EnemyEater))
				{
					superpower = true;
					cooldowntext = "Hungry...";
					if (mxspd >= base_mxspd)
					{
						deccel = base_deccel - 0.05;
						accel = base_accel - 0.1;
						mxspd = base_mxspd - 1;
						fallaccel = base_fallaccel;
					}
				}
				else if (superpower)
				{
					superpower = false;
					cooldown = maxcooldown;
					if (flags.get(ExKeine))
					{
						maxcooldown = 1800;
						cooldown = maxcooldown;
					charname = "keine";
					//game.SendEvent("ChangeAppearance", "keine");
					accel -= 0.3;
					deccel -= 0.1;
					mxspd -= 5;
					if (Hspeed >= 0)
					{
						ChangeAnimation(charname);
					}
					if (Hspeed < 0)
					{
						ChangeAnimation(charname+"F");
					}
					invincibility = 90;
					}
					if (flags.get(DashAttack))
					{
						//mxspd -= 22;
						mxspd -= 33;
						invincibility = 20;
						Hspeed = Ldir * mxspd;
					}
					if (flags.get(LightDashAttack))
					{
						mxspd -= 22;
						invincibility = 10;
						Hspeed = Ldir * mxspd;
					}
				}
				else if (controller[1]/* && this == game.myplayer*/)
				{
					if (flags.get(Earthquake) && ground!=null && this == game.myplayer)
					{
						cooldown = maxcooldown;
						game.SendEvent("Earthquake", ground.y);
					}
					if (flags.get(DashAttack))
					{
						superpower = true;
						//mxspd += 22;
						mxspd += 33;
						Hspeed = Ldir * mxspd;
						cooldown = 6;
					}
					if (flags.get(LightDashAttack))
					{
						superpower = true;
						mxspd += 22;
						Hspeed = Ldir * mxspd;
						cooldown = 4;
					}
					if (flags.get(Teleporter))
					{
						x = Math.max(Math.min(stage.mouseX-40,800),0);
						y = Math.max(Math.min(stage.mouseY,500),0);
						if (x < 0)
						{
							x = 0;
						}
						cooldown = maxcooldown;
					}
					if (flags.get(ExKeine))
					{
						superpower = true;
						maxcooldown = 360;
						cooldown = maxcooldown;
						//cooldown = 360;
						charname = "exkeine";
						//game.SendEvent("ChangeAppearance", "exkeine");
						accel += 0.3;
						deccel += 0.1;
						mxspd += 5;
						if (Hspeed >= 0)
						{
							ChangeAnimation(charname);
						}
						if (Hspeed < 0)
						{
							ChangeAnimation(charname+"F");
						}
					}
					if (flags.get(YinYangOrbs) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var D:Dynamic = { };
						D.x = x;
						D.y = y + 10;
						//D.UID = UID;
						D.type = "yinyangorb";
						D.scale = 0.4;
						D.dir = Ldir;
						//D.Vspeed = -6;
						D.Vspeed = 2;
						D.HP = 6;
						if (Ldir >= 0)
						{
							D.Hspeed = 10.5;
						}
						else
						{
							D.Hspeed = -10.5;
						}
						D.gravX = 0;
						D.gravY = 0.4;
						D.wrap = true;
						D.bounces = true;
						game.SendEvent("PlayerDanmaku", D);
					}
					if (flags.get(Cheeen) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var D:Dynamic = { };
						D.x = x;
						D.y = y + 30;
						//D.UID = UID;
						D.type = "EChen";
						D.scale = 0.8;
						D.dir = Ldir;
						//D.Vspeed = -6;
						D.Vspeed = 0;
						if (Ldir >= 0)
						{
							D.Hspeed = 10;
						}
						else
						{
							D.Hspeed = -10;
						}
						D.gravX = 0;
						D.gravY = 0;
						D.wrap = false;
						game.SendEvent("PlayerDanmaku", D);
					}
					if (flags.get(StarBulletG) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var D:Dynamic = { };
						D.x = x;
						D.y = y + 0;
						//D.UID = UID;
						D.type = "starbulletg";
						D.scale = 1;
						D.dir = Ldir;
						//D.Vspeed = -6;
						D.Vspeed = Vspeed;
						if (Ldir >= 0)
						{
							D.Hspeed = 10;
						}
						else
						{
							D.Hspeed = -10;
						}
						D.gravX = 0;
						D.gravY = 0;
						D.wrap = false;
						game.SendEvent("PlayerDanmaku", D);
					}
					if (flags.get(StarBulletY) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var spd = 8;
						var D:Dynamic = { };
						D.x = x;
						D.y = y + 30;
						//D.UID = UID;
						D.type = "starbullety";
						//D.scale = 1;
						D.scale = 0.8;
						D.dir = Ldir;
						//D.Vspeed = -6;
						D.Vspeed = 0;
						if (Ldir >= 0)
						{
							D.Hspeed = spd;
						}
						else
						{
							D.Hspeed = -spd;
						}
						D.gravX = 0;
						D.gravY = 0;
						D.wrap = false;
						game.SendEvent("PlayerDanmaku", D);
						var i = 0;
						D.Vspeed = 1;
						while (i < 4)
						{
							D.Vspeed += 1;
							D.Hspeed -= D.dir;
							//D.Vspeed *= 1.25;
							//D.Hspeed *= 0.85;
							//D.Vspeed *= 1.5;
							//D.Hspeed *= 0.7;
							game.SendEvent("PlayerDanmaku", D);
							D.Vspeed *= -1;
							game.SendEvent("PlayerDanmaku", D);
							D.Vspeed *= -1;
							i++;
						}
						/*
						D.Vspeed = 4;
						D.Hspeed *= 0.7;
						game.SendEvent("PlayerDanmaku", D);
						D.Vspeed = -4;
						game.SendEvent("PlayerDanmaku", D);
						
						D.Vspeed = 7;
						D.Hspeed *= 0.7;
						game.SendEvent("PlayerDanmaku", D);
						D.Vspeed = -7;
						game.SendEvent("PlayerDanmaku", D);*/
					}
					//StarBullet
					if (flags.get(ZaWarudo) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var D:Dynamic = { };
						game.SendEvent("ZaWarudo", D);
					}
					if (flags.get(WorldScorcher) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var D:Dynamic = { };
						game.SendKillAll();
						game.SendEvent("CharWorld", D);
						//game.SendEvent("Mokoubomb", D);
					}
					if (flags.get(WorldFreezer) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var D:Dynamic = { };
						game.SendKillAll();
						game.SendEvent("FreezeWorld", D);
						//game.SendEvent("Mokoubomb", D);
					}
					if (flags.get(KaPow) && this == game.myplayer)
					{
						cooldown = maxcooldown;
						var D:Dynamic = { };
						game.SendEvent("POW!", D);
					}
				}
			}
			//if (wrapped && charname == "yukari")
			if (wrapped && flags.get(Warping))
			{
				/*if (y > 480)
				{
					y -= 480;
				}*/
				if (y < 160)
				{
					y += 480;
				}
			}
			deccel = DCL;
			/*if (ground != null && ground.icy)
			{
				deccel = 0.025;
			}
			else
			{
				deccel = 0.1;
			}*/
			if (!catchingup)
			{
			if (invincibility > 0)
			{
				visible = (invincibility & 1 > 0);
				invincibility -= 1;
			}
			else
			{
				visible = true;
			}
			}
			if (rotation != 0)
			{
				this.rotation = 0;
			}
		if (Hspeed < mxspd && controller[3])
		{
			if (ground != null && ground.icy  && !ignoreice)
			{
				//Hspeed += accel * 0.25;
				Hspeed += Haccel;
			}
			else
			{
				Hspeed += accel;
			}
			if (Hspeed > mxspd)
			{
				Hspeed = mxspd;
			}
		}
		if (Hspeed > -mxspd && controller[2])
		{
			if (ground != null && ground.icy  && !ignoreice)
			{
				//Hspeed -= accel * 0.25;
				Hspeed -= Haccel;
			}
			else
			{
				Hspeed -= accel;
			}
			if (Hspeed < -mxspd)
			{
				Hspeed = -mxspd;
			}
		}
		
		if (ground != null && Vspeed == 0)
		{
			if (!catchingup)
			{
		steps += Math.abs(Hspeed);
		if (steps > 35)
		{
			steps -= 35;
			//var S = "step" + Math.ceil(Math.random()*3);
			var S;
			//= Math.ceil(Math.random() * 3);
			//if (flags.get(Drums))
			if (game.GameFlags.get(Main.Drumstep))
			{
				S = "drum" + Math.floor(Math.random()*5);
			}
			else
			{
				S = "step" + Math.ceil(Math.random()*3);
			}
			SoundManager.Play(S);
			if (this.rotation != 0)
			{
				//this.rotationZ = 0;
			}
			else
			{
				y -= 2;
				//Vspeed = 5;
				if (Hspeed > 0)
				{
					//this.rotationZ = 20;
				}
				else
				{
					//this.rotationZ = -20;
				}
			}
		}
		}
		}
		if (Hspeed > 0)
		{
			ChangeAnimation(charname);
		}
		if (Hspeed < 0)
		{
			ChangeAnimation(charname+"F");
		}
		
		if (ground != null)
		{
			if (ground.bonked > -1000)
			{
				Vspeed = -4;
			}
			else
			{
				if ((controller[0]) && Vspeed == 0)
				{
					//Vspeed = -17;
					//Vspeed = -19;
					Vspeed = jumpspd;
				}
			}
			if (ground.dangerous && !flags.get(FireProof))
			{
				if (this == game.myplayer)
				{
					if (invincibility<=0)
					{
						game.SendEvent("PlayerDeath", myMyon != null);
					}
				}
			}
			
		}
		if (headbonk != null && this == game.myplayer && headbonk.bonked==-1000 && (game.RoundType != GameView.TypeofRound.Table || headbonk.type != "Block"))
			{
				//game.SendEvent("Headbonk", game.entities.indexOf(headbonk));
				
				game.SendEvent("Headbonk", headbonk.UID);
				if (flags.get(HeavyBonk))
				{
					var T = game.CollisionDetectPoint(headbonk.x - 32, headbonk.y);
					if (T != null)
					{
						game.SendEvent("Headbonk", T.UID);
					}
					T = game.CollisionDetectPoint(headbonk.x + 32, headbonk.y);
					if (T != null)
					{
						game.SendEvent("Headbonk", T.UID);
					}
				}
				if (flags.get(Ambush))
				{
					Vspeed = 0;
					y = headbonk.y - feetposition;
					if (invincibility < 15)
					{
						invincibility = 15;
					}
				}
				//y = headbonk.y - feetposition;
			}
		if (this == game.myplayer)
		{// + (Math.floor(width) >> 1)
			//CollisionDetectPointDangerous
			//var W = (Math.round(width) >> 1);
			var W = middle;
			var H = (Math.round(feetposition) >> 2);
			var danger = null;
			var enemy = null;
			if (!superpower)
			{
				danger = game.CollisionDetectPointDangerous(x + W, y + (feetposition - H));
				enemy = game.CollisionDetectPointEnemy(x + W, y + (feetposition - H));
			}
			else
			{
				danger = game.CollisionDetectTouchDangerous(this);
				enemy = game.CollisionDetectTouchEnemy(this);
			}
			/*
		var danger = game.CollisionDetectPointDangerous(x + W, y + (feetposition - H));
		var enemy = game.CollisionDetectPointEnemy(x + W, y + (feetposition - H));//game.CollisionDetectTouchEnemy(this);//game.CollisionDetectPointEnemy(x, y + 60);
		

		*/
		var eItem = game.CollisionDetectPointItem(x + W, y + (feetposition - H));//game.CollisionDetectTouchItem(this);//game.CollisionDetectPointItem(x, y + 60);
		/*if (flags.get(Ambush) && headbonk != null && this == game.myplayer && headbonk.bonked==-1000 && (game.RoundType != GameView.TypeofRound.Table || headbonk.type != "Block"))
			{
				//game.SendEvent("Headbonk", game.entities.indexOf(headbonk));
				//game.SendEvent("Headbonk", headbonk.UID);
				Vspeed = 0;
				y = headbonk.y - feetposition;
			}*/
		if (eItem != null && eItem.collectable)
		{
			if (!(flags.get(CanHide) && cooldown <= 0))
			{
				game.SendEvent("Collect", eItem.UID);
			}
		}
		if (danger != null && lives>=0 && game.myplayer == this)
		{
			/*if (enemy.killable)
			{
				game.SendEvent("Kill", enemy.UID);
			}
			else*/
			if (!((enemy == danger && enemy.charname == "Mystia" && flags.get(EatMystia)) || superpower || (flags.get(JumpMan) && y<enemy.y && Vspeed>0)))
			{
				if (invincibility<=0)
				{
					game.SendEvent("PlayerDeath", myMyon != null);
				}
			}
			else
			{
				if ((superpower || (flags.get(JumpMan) && y<enemy.y && Vspeed>0)) && danger != enemy)
				{
					var DD:Dynamic = danger;
					if (danger != null && danger.type == "Enemy" && (DD.charname == "Cirno" || DD.charname == "Iku"))
					{
						game.SendEvent("Kill", danger.UID);
						/*if (flags.get(EnemyEater))
						{
							cooldown = maxcooldown;
						}*/
					}
				}
			}
		}
		if (enemy != null && lives>=0)
		{
			if (enemy.killable)
			{
				game.SendEvent("Kill", enemy.UID);
				/*if (flags.get(EnemyEater))
				{
					cooldown = maxcooldown;
				}*/
				if (enemy.charname == "RedFairy" && flags.get(SpawnZombieFairies) && Math.random()<zombiefairychance)
				{
					var i = 0;
				var count = 0;
				while (i < game.activeItems.length)
				{
					var E = game.activeItems[i];
					if (E.alive && E.subtype == "Myon")
					{
						var D:Dynamic = E;
						if (D.holder == game.myplayer)
						{
							count++;
						}
					}
					i++;
				}
				if (count < 2)
				{
					//collectable = true;
					var D:Dynamic = { };
					D.UID = UID;
					D.type = zombiefairytype;
					D.scale = zombiefairyscale;
					game.SendEvent("AttachZombieFairy", D);
					//game.SendEvent("AttachZombieFairy", UID);
				}
				}
			}
			else
			{
				if ((enemy.charname == "Mystia" && flags.get(EatMystia)) || superpower || (flags.get(JumpMan) && y<enemy.y && Vspeed>0))
				{
					game.SendEvent("Kill", enemy.UID);
					/*if (flags.get(EnemyEater))
					{
						cooldown = maxcooldown;
					}*/
				}
			}
			/*else
			{
				if (enemy.dangerous && invincibility<=0)
				{
					game.SendEvent("PlayerDeath", null);
				}
			}*/
		}
		}
		if (ground != null)
		{
			if (flags.get(FallThruPlatforms) && controller[1] && y<400)
			{
				y += 40;
			}
		}
		}
		else
		{
			if (rotation == 0)
			{
				this.rotation = 90;
				this.x += (Math.floor(height) >> 1);
			}
			if (lives > -1)
			{
			Vspeed += 0.5;
			if (Vspeed > 20)
			{
				Vspeed = 20;
			}
			y += Vspeed;
			if (y > 600 && this == game.myplayer)
			{
				//TO DO: respawn and whatever
				var D:Dynamic = { };
				D.x = 400;
				D.y = 0;
				D.lives = lives - 1;
				//if (charname == "youmu")
				/*if (flags.get(Player.DoubleMyon))
				{
					D.lives--;
				}*/
				game.SendEvent("PlayerRespawn", D);
			}
			}
		}
		//if (visible && game.frame-frame > 600)
		//if (game.frame-frame > 600)
		if (game.myplayer != this)
		{
		//if (game.frame-frame > 60)
		if (game.frame-frame > 600)
		{
			//hide inactive players
			//visible = false;
			//blendMode = flash.display.BlendMode.OVERLAY;
			alpha = 0.5;
			
			blendMode = flash.display.BlendMode.SCREEN;
		}
		else if (blendMode == flash.display.BlendMode.SCREEN)
		{
			alpha = 1;
			blendMode = flash.display.BlendMode.NORMAL;
			//blendMode = flash.display.BlendMode.LIGHTEN;
		}
		
		}
		
		if (((playername != "" && game.online) || (warncooldown/* && cooldown==0*/ && cooldown>-90)) && visible)
		{
			nameplate.visible = true;
			if (playername != "PlayerName")
			{
				nameplatetext.text = "" + playername;
			}
			else
			{
				nameplatetext.text = "???";
			}
			cooldownbar.visible = false;
			if (this == game.myplayer)
			{
				if (warncooldown && cooldown <= 0)
				{
					//cooldownbar.visible = false;
					nameplatetext.text = cooldowntext;
				}
				else if (warncooldown)
				{
					//cooldownbar.alpha = 0.7;
					cooldownbar.alpha = 1;
					cooldownbar.visible = true;
					cooldownbar.graphics.clear();
					
					var G = cooldownbar.graphics;
					
					G.beginFill(0, 0.4);
					//cooldownbar.graphics.drawRect(0, 0, 50, 9);
					G.drawRoundRect(0, 0, 50, 9,5);
					G.endFill();
					
					//nameplatetext.text = "whatwhat?";
					var prct = (maxcooldown - cooldown + 0.001) / maxcooldown;
					//nameplatetext.text = "what:"+prct+"?";
					var C = Math.round(prct * 255);
					var CD = 255 - C;
					var col:UInt = (CD) + (C << 8) + (CD << 16);
					G.beginFill(col, 1);
					//cooldownbar.graphics.beginFill(0xFF0000);
					//cooldownbar.graphics.drawRect(0, 0, 50 * prct, 9);
					G.drawRoundRect(0, 0, 50 * prct, 9,5);
					G.endFill();
					//var col2:UInt = (128 +(CD >> 1)) + ((128 +(C >> 1)) << 8) + ((128 +(CD >> 1)) << 16);
					////var col2:UInt = (192 +(CD >> 2)) + ((192 +(C >> 2)) << 8) + ((192 +(CD >> 2)) << 16);
					//col2 = 0xffffff;
					
					
					var fillType:flash.display.GradientType = flash.display.GradientType.LINEAR;
					var colors:Array<UInt> = [0x777777, 0xffffff];
					var alphas = [0.12, 0.4];
					var ratios = [0x00, 0xFF];
					var matr:flash.geom.Matrix = new flash.geom.Matrix();
					//matr.createGradientBox(50, 9, Math.PI/2, 0, -4.5);
					matr.createGradientBox(50, 9, 1.57079632679, 0, -4.5);
					var spreadMethod:flash.display.SpreadMethod = flash.display.SpreadMethod.REFLECT;
					G.beginGradientFill(fillType, colors, alphas, ratios, matr, spreadMethod);  
	 
					//cooldownbar.graphics.beginGradientFill(flash.display.GradientType.LINEAR, [col, col2, col], [1, 1, 1], [0x00, 0xFF],new flash.geom.Matrix(),flash.display.SpreadMethod.REFLECT);
					G.drawRoundRect(0, 0, 50 * prct, 9,5);
					//cooldownbar.graphics.drawRect(0, 0, 50 * prct, 9);
					G.endFill();
					
					//cooldownbar.graphics.beginFill(0x
					//cooldownbar.graphics.beginFill(0x
					//nameplatetext.text = "what?";
					nameplatetext.text = "            ";
				}
			}
			/*if (warncooldown && cooldown == 0 && this == game.myplayer)
			{
				nameplatetext.text = cooldowntext;
			}
			else if (!(playername != "" && game.online))
			{
				nameplatetext.text = "";
				nameplate.visible = false;
			}*/
			//nameplate.blendMode = flash.display.BlendMode.
			nameplatetext.setTextFormat(format);
			var B = getBounds(game);
			nameplate.x = B.left - (Math.floor(nameplatetext.textWidth) >> 1) + (Math.floor(B.width) >> 1);
			nameplate.y = B.top - 20;
			//game.stage.removeChild(nameplate);
			//game.stage.addChild(nameplate);
			//nameplate.z = -100;
			//nameplate.x = x;
			//nameplate.y = y;
			//nameplate.y = y + height + 10;
			//nameplate.x = x;
			//nameplate.y = y + 100;
		}
		else
		{
			nameplate.visible = false;
		}
		if (/*controller[5]*/true)
		{
			var interact = game.CollisionDetectTouchInteractable(this);
			if (interact != null)
			{
			if (this == game.myplayer)
			{
				nameplatetext.text = "Interact";
				if (interact.interacttext != null)
				{
					nameplatetext.text = interact.interacttext;
				}
				nameplatetext.setTextFormat(format);
				var B = getBounds(game);
				nameplate.x = B.left - (Math.floor(nameplatetext.textWidth) >> 1) + (Math.floor(B.width) >> 1);
				nameplate.y = B.top - 20;
				
				cooldownbar.visible = false;
				nameplatetext.visible = true;
				nameplate.visible = true;
				
			}
			if (controller[4])
			{
				interact.interact(this);
			}
			}
		}
		if (Hspeed > 0)
		{
			Ldir = 1;
		}
		if (Hspeed < 0)
		{
			Ldir = -1;
		}
		//flags = baseflags.clone();
		flags.copy(baseflags);
		allmyons = new Array<MyonItem>();
	}
	//public static inline var PI2 = 1.57079632679;
}