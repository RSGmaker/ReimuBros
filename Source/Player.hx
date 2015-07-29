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
	public var note:Int = 0;
	public var midi:Array<Int> = null;
	public var tempo:Int = 40;
	//a temp variable abilities can use to cancel events.
	public var cancel:Bool;
	private var filterArr:Array<flash.filters.BitmapFilter>;
	//public var myMyon:MyonItem;

	
	public static var characters:Array<String> = ["reimu", "marisa", "patchouli", "remilia", "sanae", "sakuya", "suwako", "yuyuko", "tenshi", "iku", "aya", "alice", "youmu", "shikieiki", "flandre", "satori", "koishi", "momiji", "nitori", "udongein", "komachi", "yuuka", "mokou", "meiling", "parsee", "kokoro", "kogasa", "kasen", "utsuho", "suika", "kaguya", "eirin", "nazrin", "orin", "hina", "byakuren", "chiyuri", "ellen", "elly", "gengetsu", "kana", "kotohime", "elis", "louise", "mai", "meira", "mugetsu", "orange", "rika", "rikako", "sara", "yuki", "yumeko", "yumemi", "akyu", "futo", "kagerou", "keine", "kosuzu", "lunachild", "mamizou", "medicine", "minoriko", "murasa", "seiga", "sekibanki", "shanghai", "shinmyoumaru", "shizuha", "shou", "sunnymilk", "tokiko", "wriggle", "yoshika", "starsaphire", "lily", "letty", "makairesident-a", "makairesident-b", "ayana", "matenshi", "noroiko", "mystia", "lunasa", "lyrica", "merlin", "maribel", "renko", "miko", "reisen", "ruukoto", "tojiko", "toyohime", "yorihime", "wakasagihime", "yatsuhashi", "mima", "konngara","tewi","kanako","ringo","doremy","seiran","sumireko","rin","raiko","shingyoku","hatate","daiyousei","kurumi","yuugi","benben","ichirin","kyouko","yamame","koakuma","shinki","rengeteki","sariel","yukari", "seija", "rumia","cirno","nue","chen","ran"];
	
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
	
	//manages PlayerAbilities
	//public var abilities:Array<PlayerAbility>;
	public var ability:PlayerAbilityManager;
	//public var killed:Bool;
	public var started:Bool;
	//ignores ice physics
	public var ignoreice:Bool;
	public var baseflags:FlagManager;
	public var flags:FlagManager;
	public var allmyons:Array<MyonItem>;
	
	public static var HammerSong:Array<Int> = [1, 0, 1, 1, 1, 0, 1,0, 2, 0, 1, 0, 2, 0, 1, 0,
							2, 0, 2, 2, 2, 0, 2, 0, 3, 0, 2, 0, 3, 0, 2, 0];
	
	public static var StarSong:Array<Int> = [3, 0, 3, 0, 3, 3, 0, 3, 0, 3, 0, 3, 3, 0, 3, 0,
						2, 0, 2, 0, 2, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0];
	
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
	
	public static inline var SpawnShanghai = 35;
	
	public static inline var MoreZombieFairies = 36;
	
	public static inline var DestructiveJump = 37;
	
	public static inline var ExtraLives = 38;
	
	public static inline var BounceEntities = 39;
	
	public static inline var TileDanmaku = 40;
	
	public static inline var InstantCollect = 41;
	
	public static inline var AngelOfDeath = 42;
	
	public static inline var Fairplay = 43;
	
	public static inline var SuwakoHoop = 44;
	
	public static inline var ExtraPoints = 45;
	
	public static inline var BecomeInvisible = 46;
	
	public static inline var AbsorbDamage = 47;
	
	public static inline var MusicSelector = 48;
	
	public static inline var HeadCannon = 49;
	
	public static inline var BasicShot = 50;
	
	
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
	//public static inline var base_mxspd = 7+1.55;
	public static inline var base_mxspd = 7+1.55-0.9;
	public static inline var base_fallaccel = 1.0+0.1;
	public static inline var base_jumpspd = -19 - 0.5;
	
	public var evt_onframe:Dynamic;
	public function new(charname:String,controller:Array<Bool>) 
	{
		super(charname);
		allmyons = new Array<MyonItem>();
		scaleX = 0.85;
		scaleY = 0.85;
		type = "Player";
		this.charname = charname;
		flags = new FlagManager(1);
		maxcooldown = 300;
		cooldown = 0;
		useotherhitbox = true;
		warncooldown = false;
		jumpspd = base_jumpspd;
		this.controller = controller;
		deccel = base_deccel;
		accel = base_accel;
		Haccel = accel * 0.35;
		Hdeccel = deccel * 0.35;
		
		
		mxspd = base_mxspd;
		fallaccel = base_fallaccel;
		ability = new PlayerAbilityManager(this);
		ability.SetAbilities();
		switch (charname)
		{
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
		
		
		killed = false;
		lives = 3;
		ID = "";
		score = 0;
		steps = 0;
		invincibility = 0;
		
		playername = "";
		nameplate = new Sprite();
		nameplatetext = new TextField();
		cooldownbar = new Shape();
		cooldownbar.y = 5;
		nameplate.addChild(nameplatetext);
		nameplate.addChild(cooldownbar);
		
		var AA = new flash.filters.DropShadowFilter();
		AA.alpha = 1;
		AA.distance = 3;
		AA.alpha = 25;
		AA.color = 0;
		filterArr = new Array();
		filterArr[0] = AA;
		nameplate.filters = filterArr;
		
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
		
		nameplate.x = 100;
		nameplate.y = 100;
		format = new TextFormat();
		format.font = "Arial";
		format.size = 16;
		format.color = 0xFFFFFF;
		nameplatetext.mouseEnabled = false;
		nameplatetext.setTextFormat(format);
		game.addChild(nameplate);
		frame = game.frame;
		playing = -1;
		started = false;
		ignoreice = false;
		
		
		Ofallaccel = fallaccel;
		fallaccel2 = fallaccel / 16;
		
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
				ability.init();
				if (cooldown == 0)
				{
					cooldown = maxcooldown;
				}
			}
			ability.onbeginframe();
			
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
			updphysics();
			ability.onframe();
			if (controller[1])
			{
				ability.onuse();
			}
			deccel = DCL;
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
		if (steps > tempo)
		{
			//superpower = true;
			steps -= tempo;
			var S;
			if (midi == null)
			{
				if (superpower)
				{
					//tempo = 40;
					tempo = Math.floor(mxspd * 3);
					midi = HammerSong;
				}
				else if (invincibility>0)
				{
					//tempo = 50;
					tempo = Math.floor(mxspd * 3);
					midi = StarSong;
				}
			}
			else
			{
				if (midi == HammerSong && !superpower)
				{
					midi = null;
				}
				else if (midi == StarSong && invincibility<=0)
				{
					midi = null;
				}
			}
			//if (!superpower)
			if (midi == null)
			{
				tempo = 40;
				note = 0;
				//midi = null;
			if (game.GameFlags.get(Main.Drumstep))
			{
				S = "drum" + Math.floor(Math.random()*5);
			}
			else
			{
				S = "step" + Math.ceil(Math.random()*3);
			}
			}
			else
			{
				/*var modo:Array<Int> = [1, 0, 1, 1, 1, 0, 1,0, 2, 0, 1, 0, 2, 0, 1, 0,
				2, 0, 2, 2, 2, 0, 2, 0, 3, 0, 2, 0, 3, 0, 2, 0];*/
				if (midi == null)
				{
					if (UID < 0.5 || true)
					{
						tempo = 40;
						//hammer
						midi = [1, 0, 1, 1, 1, 0, 1,0, 2, 0, 1, 0, 2, 0, 1, 0,
							2, 0, 2, 2, 2, 0, 2, 0, 3, 0, 2, 0, 3, 0, 2, 0];
					}
					else
					{
						tempo = 50;
						//star
						midi = [3, 0, 3, 0, 3, 3, 0, 3, 0, 3, 0, 3, 3, 0, 3, 0,
						2, 0, 2, 0, 2, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 0];
						
						/*midi = [1, 0, 1, 2, 1, 2, 1, 0, 2,
						2, 0, 2, 3, 2, 3, 2, 0, 3];*/
					}
				}
				if (midi[note] > 0)
				{
					S = "step" + midi[note];
				}
				else
				{
					S = "";
					//S = "drum0";
				}
				note++;
				if (note >= midi.length)
				{
					note = 0;
				}
			}
			if (S != "")
			{
				SoundManager.Play(S);
			}
			if (this.rotation != 0)
			{
			}
			else
			{
				y -= 2;
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
				ability.onbumped(ground.bonkedby);
			}
			else
			{
				if ((controller[0]) && Vspeed == 0)
				{
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
				
				game.SendEvent("Headbonk", headbonk.UID);
				ability.onheadbonk();
			}
		if (this == game.myplayer)
		{
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
		var eItem = game.CollisionDetectPointItem(x + W, y + (feetposition - H));
		if (eItem != null && eItem.collectable)
		{
			if (!(flags.get(CanHide) && cooldown <= 0))
			{
				game.SendEvent("Collect", eItem.UID);
			}
		}
		if (danger != null && lives>=0 && game.myplayer == this)
		{
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
					}
				}
			}
		}
		if (enemy != null && lives>=0)
		{
			if (enemy.killable)
			{
				game.SendEvent("Kill", enemy.UID);
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
					var D:Dynamic = { };
					D.UID = UID;
					D.type = zombiefairytype;
					D.scale = zombiefairyscale;
					game.SendEvent("AttachZombieFairy", D);
				}
				}
			}
			else
			{
				if ((enemy.charname == "Mystia" && flags.get(EatMystia)) || superpower || (flags.get(JumpMan) && y<enemy.y && Vspeed>0))
				{
					game.SendEvent("Kill", enemy.UID);
				}
			}
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
				var D:Dynamic = { };
				D.x = 400;
				D.y = 0;
				D.lives = lives - 1;
				game.SendEvent("PlayerRespawn", D);
			}
			}
		}
		if (game.myplayer != this)
		{
		if (game.frame-frame > 600)
		{
			//hide inactive players
			alpha = 0.5;
			
			blendMode = flash.display.BlendMode.SCREEN;
		}
		else if (blendMode == flash.display.BlendMode.SCREEN)
		{
			alpha = 1;
			blendMode = flash.display.BlendMode.NORMAL;
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
					nameplatetext.text = cooldowntext;
				}
				else if (warncooldown)
				{
					cooldownbar.alpha = 1;
					cooldownbar.visible = true;
					cooldownbar.graphics.clear();
					
					var G = cooldownbar.graphics;
					
					G.beginFill(0, 0.4);
					G.drawRoundRect(0, 0, 50, 9,5);
					G.endFill();
					
					var prct = (maxcooldown - cooldown + 0.001) / maxcooldown;
					var C = Math.round(prct * 255);
					var CD = 255 - C;
					var col:UInt = 255;
					if (prct < 0.5)
					{
						//red to yellow transition
						col= (0) + ((C << 1) << 8) + (255 << 16);
					}
					else
					{
						//remove half of progress from transitioning variables so this transition starts from 0(yellow) properly.
						CD = CD << 1;
						C = (C - 128) << 1;
						//yellow to green transition
						col= (0) + (255 << 8) + (CD << 16);
					}
					G.beginFill(col, 1);
					G.drawRoundRect(0, 0, 50 * prct, 9,5);
					G.endFill();
					
					
					var fillType:flash.display.GradientType = flash.display.GradientType.LINEAR;
					var colors:Array<UInt> = [0x777777, 0xffffff];
					var alphas = [0.12, 0.4];
					var ratios = [0x00, 0xFF];
					var matr:flash.geom.Matrix = new flash.geom.Matrix();
					matr.createGradientBox(50, 9, 1.57079632679, 0, -4.5);
					var spreadMethod:flash.display.SpreadMethod = flash.display.SpreadMethod.REFLECT;
					G.beginGradientFill(fillType, colors, alphas, ratios, matr, spreadMethod);  
	 
					G.drawRoundRect(0, 0, 50 * prct, 9,5);
					G.endFill();
					
					nameplatetext.text = "            ";
				}
			}
			nameplatetext.setTextFormat(format);
			var B = getBounds(game);
			nameplate.x = B.left - (Math.floor(nameplatetext.textWidth) >> 1) + (Math.floor(B.width) >> 1);
			nameplate.y = B.top - 20;
		}
		else
		{
			nameplate.visible = false;
		}
		if (true)
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
		flags.copy(baseflags);
		allmyons = new Array<MyonItem>();
	}
}