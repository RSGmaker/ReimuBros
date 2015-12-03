package;
import abilities.PowerupAbility;

/**
 * ...
 * @author RSGmaker
 */
class PlayerAbilityManager
{

	public var abilities:Array<PlayerAbility>;
	public var player:Player;
	public function new(player:Player) 
	{
		abilities = new Array<PlayerAbility>();
		this.player = player;
		if (ListAbilities == null)
		{
			initlist();
		}
	}
	public static function initlist()
	{
		ListAbilities = new Array<Dynamic>();
		var L = ListAbilities;
		L[L.length] = { type:new abilities.SuperSpeed(null), names:["aya"] };
		//L[L.length] = { type:new abilities.SpawnShanghai(null), names:["alice"] };
		L[L.length] = { type:new abilities.MoreZombieFairies(null), names:["orin"] };
		L[L.length] = { type:new abilities.DoubleMyon(null), names:["youmu"] };
		L[L.length] = { type:new abilities.Floating(null), names:["lunasa", "lyrica", "merlin", "daiyousei",/* "mystia", */"luna_child", "star_sapphire",/* "elis", "kurumi", */"gengetsu", "mika", "senkou",/*"clownpiece",*/"matenshi","rengeteki"] };
		L[L.length] = { type:new abilities.YinYangOrbs(null), names:["reimu"] };
		L[L.length] = { type:new abilities.IceAffinity(null), names:["cirno", "letty","cirnoALT"] };
		L[L.length] = { type:new abilities.WorldFreezer(null), names:["letty"] };
		L[L.length] = { type:new abilities.GapManipulator(null), names:["yukari"] };
		L[L.length] = { type:new abilities.FlipResistance(null), names:["seija"] };
		L[L.length] = { type:new abilities.FireProof(null), names:["mokou","cirnoALT"] };
		L[L.length] = { type:new abilities.WorldScorcher(null), names:["mokou","yuki"] };
		L[L.length] = { type:new abilities.EatMystia(null), names:["yuyuko"] };
		L[L.length] = { type:new abilities.MoreInvincibility(null), names:["kaguya"] };
		L[L.length] = { type:new abilities.PreservePowBlock(null), names:["kanako"] };
		L[L.length] = { type:new abilities.Ambush(null), names:["murasa"] };
		L[L.length] = { type:new abilities.CanHide(null), names:["koishi"] };
		//L[L.length] = { type:new abilities.FallThruPlatforms(null), names:["tewi"] };
		
		L[L.length] = { type:new abilities.ElectricProof(null), names:["iku","tojiko"] };
		L[L.length] = { type:new abilities.Earthquake(null), names:["tenshi"] };
		L[L.length] = { type:new abilities.ExKeine(null), names:["keine"] };
		L[L.length] = { type:new abilities.DashAttack(null), names:["meiling", "chen"/*, "momiji"*/,"orange"] };
		L[L.length] = { type:new abilities.ZaWarudo(null), names:["sakuya"] };
		L[L.length] = { type:new abilities.KaPow(null), names:["raiko"] };
		L[L.length] = { type:new abilities.Cheeen(null), names:["ran"] };
		L[L.length] = { type:new abilities.StarBulletG(null), names:["sanae"] };
		L[L.length] = { type:new abilities.StarBulletY(null), names:["marisa","mima"] };
		L[L.length] = { type:new abilities.EnemyEater(null), names:["rumia"] };
		L[L.length] = { type:new abilities.Teleporter(null), names:["komachi","vivit"] };
		L[L.length] = { type:new abilities.FriendlyUFO(null), names:["nue"] };
		L[L.length] = { type:new abilities.LightDashAttack(null), names:["wriggle"] };
		L[L.length] = { type:new abilities.HeavyBonk(null), names:["yuugi"] };
		L[L.length] = { type:new abilities.Warping(null), names:[""] };
		L[L.length] = { type:new abilities.DestructiveJump(null), names:["flandre"] };
		L[L.length] = { type:new abilities.ExtraLives(null), names:["ringo"] };
		L[L.length] = { type:new abilities.BounceEntities(null), names:["kyouko"] };
		//L[L.length] = { type:new abilities.TileDanmaku(null), names:["elly"] };
		L[L.length] = { type:new abilities.InstantCollect(null), names:["shou"] };
		L[L.length] = { type:new abilities.AngelOfDeath(null), names:["sariel"] };
		L[L.length] = { type:new abilities.Fairplay(null), names:["shikieiki"] };
		L[L.length] = { type:new abilities.SuwakoHoop(null), names:["suwako"] };
		L[L.length] = { type:new abilities.ExtraPoints(null), names:["minoriko"] };
		L[L.length] = { type:new abilities.BecomeInvisible(null), names:["sunny_milk", "nitori"] };
		L[L.length] = { type:new abilities.AbsorbDamage(null), names:["byakuren"] };
		L[L.length] = { type:new abilities.MusicSelector(null), names:["lunasa", "lyrica", "merlin"] };
		L[L.length] = { type:new abilities.HeadCannon(null), names:["sekibanki"] };
		L[L.length] = { type:new abilities.ClearSpawnList(null), names:["rin"] };
		L[L.length] = { type:new abilities.RefreshBlocks(null), names:["lily_white","junko"] };
		L[L.length] = { type:new abilities.MasterSpark(null), names:["yuuka"] };
		L[L.length] = { type:new abilities.AlternateMusic(null), names:["benben", "yatsuhashi"] };
		L[L.length] = { type:new abilities.VampiricTouch(null), names:["remilia", "elis", "kurumi"] };
		L[L.length] = { type:new abilities.MoreLives(null), names:["shanghai"] };
		L[L.length] = { type:new abilities.OneWeekGirl(null), names:["patchouli"] };
		L[L.length] = { type:new abilities.StageSeal(null), names:["eirin"] };
		L[L.length] = { type:new abilities.HypnoticBullets(null), names:["satori"] };
		L[L.length] = { type:new abilities.PoisonBlocks(null), names:["medicine"] };
		L[L.length] = { type:new abilities.IceBall(null), names:["cirno","mai"] };
		L[L.length] = { type:new abilities.SummonBlackHole(null), names:["suika"] };
		L[L.length] = { type:new abilities.BoomerangScythe(null), names:["elly"] };
		L[L.length] = { type:new abilities.TreasureHunter(null), names:["nazrin"] };
		L[L.length] = { type:new abilities.Expressionless(null), names:["kokoro"] };
		L[L.length] = { type:new abilities.HatStealer(null), names:["parsee"] };
		L[L.length] = { type:new abilities.DeathResist(null), names:["hina", "yuyuko"] };
		L[L.length] = { type:new abilities.QuickAccel(null), names:["hina", "kagerou", "remilia","yuki"] };
		L[L.length] = { type:new abilities.MegaLaser(null), names:["utsuho","ruukoto"] };
		L[L.length] = { type:new abilities.DollMaker(null), names:["alice"] };
		L[L.length] = { type:new abilities.QuickStep(null), names:["hatate", "momiji", "orin","tokiko"] };
		L[L.length] = { type:new abilities.WeakShot(null), names:["hatate", "iku","akyu","nue","kurumi","maribel","kosuzu","kasen","shinki","sara","kokoro"] };
		L[L.length] = { type:new abilities.LesserDashAttack(null), names:["momiji", "kagerou","konngara"] };
		L[L.length] = { type:new abilities.BasicWideShot(null), names:["seiran"] };
		L[L.length] = { type:new abilities.KaPowSlow(null), names:["seija","tojiko"] };
		L[L.length] = { type:new abilities.MiracleMallet(null), names:["shinmyoumaru"] };
		L[L.length] = { type:new abilities.KogasaBoo(null), names:["kogasa"] };
		L[L.length] = { type:new abilities.IllusionBullet(null), names:["udongein"] };
		//L[L.length] = { type:new abilities.MoneyThief(null), names:["tewi"] };
		L[L.length] = { type:new abilities.GapMaker(null), names:["seiga"] };
		L[L.length] = { type:new abilities.VampiricTouch2(null), names:["yoshika"] };
		L[L.length] = { type:new abilities.Nightmare(null), names:["doremy"] };
		L[L.length] = { type:new abilities.SlipUp(null), names:["sagume"] };
		L[L.length] = { type:new abilities.SummonTelephonePole(null), names:["sumireko"] };
		L[L.length] = { type:new abilities.BananaLitterer(null), names:["tewi"] };
		L[L.length] = { type:new abilities.LongerCombos(null), names:["akyu","sara"] };
		L[L.length] = { type:new abilities.HeavyHitter(null), names:["ichirin","konngara","wakasagihime"] };
		L[L.length] = { type:new abilities.AmmoSaver(null), names:["tokiko","kosuzu"] };
		L[L.length] = { type:new abilities.Fabricator(null), names:["mamizou"] };
		L[L.length] = { type:new abilities.LesserFloating(null), names:["elis", "mystia","mai","shinki","clownpiece"] };
		L[L.length] = { type:new abilities.WeakHypnoticBullet(null), names:["mystia"] };
		L[L.length] = { type:new abilities.SwordBullets(null), names:["yumeko"] };
		L[L.length] = { type:new abilities.WebPlacer(null), names:["yamame"] };
		L[L.length] = { type:new abilities.CoverShot(null), names:["koakuma"] };
		L[L.length] = { type:new abilities.FallFlip(null), names:["shizuha"] };
		L[L.length] = { type:new abilities.FallPainter(null), names:["shizuha"] };
		L[L.length] = { type:new abilities.Multiform(null), names:["hecatia"] };
		L[L.length] = { type:new abilities.Sawblade(null), names:["rikako"] };
		L[L.length] = { type:new abilities.DiscLauncher(null), names:["futo"] };
		L[L.length] = { type:new abilities.SpiralOrbs(null), names:["ellen"] };
		L[L.length] = { type:new abilities.RepeatShot(null), names:["rika"] };
		L[L.length] = { type:new abilities.TileDanmaku(null), names:["renko"] };
		L[L.length] = { type:new abilities.Warping(null), names:["maribel"] };
		L[L.length] = { type:new abilities.LargeYinYangOrbs(null), names:["shingyoku"] };
		L[L.length] = { type:new abilities.BriefInvisibility(null), names:["reisen"] };
		L[L.length] = { type:new abilities.CrossPlacer(null), names:["yumemi"] };
		L[L.length] = { type:new abilities.WaterAffinity(null), names:["wakasagihime"] };
		L[L.length] = { type:new abilities.HighJump(null), names:["wakasagihime"] };
		L[L.length] = { type:new abilities.BladeStrike(null), names:["miko","yorihime"] };
		L[L.length] = { type:new abilities.QuickDash(null), names:["kasen","toyohime"] };
		L[L.length] = { type:new abilities.SlowBomb(null), names:["toyohime"] };
		L[L.length] = { type:new abilities.SwordDash(null), names:["meira"] };
		L[L.length] = { type:new abilities.WeakLaser(null), names:["louise","clownpiece"] };
		L[L.length] = { type:new abilities.DownwardShot(null), names:["mugetsu"] };
		L[L.length] = { type:new abilities.SymmetryLaser(null), names:["chiyuri"] };
		L[L.length] = { type:new abilities.EnergyWave(null), names:["kotohime"] };
		L[L.length] = { type:new abilities.SummonBlueBird(null), names:["kana"] };
		L[L.length] = { type:new abilities.EmotionController(null), names:["kokoro"] };
		L[L.length] = { type:new abilities.NoCooldown(null), names:["vivit"] };
		
		
		L[L.length] = { type:new abilities.NoAbility(null), names:["red_fairy","none","customavatar"] };
		L[L.length] = { type:new abilities.BasicShot(null), names:["benben", "yatsuhashi", "hecatia"] };
	}
	public function getdescription(checkgamemode:Bool=true):String
	{
		return getdescriptionfromlist(abilities,checkgamemode);
	}
	public static function getdescriptionfromlist(PA:Array<PlayerAbility>,checkgamemode:Bool=true):String
	{
		var ret = "";
		var i = 0;
		while (i < PA.length)
		{
			var A = PA[i];
			if (A.description != "")
			{
			if (ret != "")
			{
				ret = ret + "\n";
			}
			ret = ret + A.description;
			}
			i++;
		}
		if (!Main._this.gamemode.abilitiesenabled && checkgamemode)
		{
			ret = "(Abilities are disabled.)";
		}
		return ret;
	}
	public function init()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].player = player;
			abilities[i].game = GameView._this;
			abilities[i].init();
			i++;
		}
	}
	public function onbeginframe()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onbeginframe();
			i++;
		}
	}
	public function onframe()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onframe();
			i++;
		}
	}
	public function onuse()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onuse();
			i++;
		}
	}
	public function onrespawn()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onrespawn();
			i++;
		}
	}
	public function onheadbonk()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onheadbonk();
			i++;
		}
	}
	
	public function onkill(E:Entity)
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onkill(E);
			i++;
		}
	}
	public function onchargeused(E:CarryItem)
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onchargeused(E);
			i++;
		}
	}
	public function onattacked(fatal:Bool)
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onattacked(fatal);
			i++;
		}
	}
	public function oncollect(E:EntityItem)
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].oncollect(E);
			i++;
		}
	}
	public function onbump(E:Entity)
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onbump(E);
			i++;
		}
	}
	public function onbumped(E:Entity)
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onbumped(E);
			i++;
		}
	}
	public function onloselife()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onloselife();
			i++;
		}
	}
	public function lostability()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].lostability();
			i++;
		}
	}
	
	
	public function oncontinue()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].oncontinue();
			i++;
		}
	}
	public function SetAbilities(force:Bool=false)
	{
		if (!force)
		{
			if (player.charactersoul != null && player.charactersoul != "")
			{
				force = true;
			}
		}
		if (Main._this.gamemode.abilitiesenabled || force)
		{
			abilities = GetAbilities(player);
		}
		else
		{
			abilities = new Array<PlayerAbility>();
		}
		if (Main._this.GameFlags.get(Main.Adventure))
		{
			var P = new PowerupAbility(player);
			abilities.push(P);
		}
	}
	
	
	//static functions
	public static var ListAbilities:Array<Dynamic>;
	public static function GetAbilities(player:Player):Array<PlayerAbility>
	{
		var ret = GetAbilities2(player.getabilityalias(), player);
		return ret;
	}
	public static function GetAbilities2(name:String,player:Player=null):Array<PlayerAbility>
	{
		if (ListAbilities == null)
		{
			initlist();
		}
		var alt:Bool = false;
		if (name.indexOf("ALT") > -1)
		{
			//name = name.substring(0, name.length - 3);
			alt = true;
		}
		var ret = new Array<PlayerAbility>();
		var i = 0;
		while (i < ListAbilities.length)
		{
			if (ListAbilities[i].names.indexOf(name)>-1)
			{
				var C = Type.getClass(ListAbilities[i].type);
				ret.push(Type.createInstance(C, [player]));
				//ret[ret.length] = Type.createInstance(C, [player]);
			}
			i++;
		}
		if (ret.length < 1)
		{
			if (alt)
			{
				name = name.substring(0, name.length - 3);
				var i = 0;
				while (i < ListAbilities.length)
				{
					if (ListAbilities[i].names.indexOf(name)>-1)
					{
						var C = Type.getClass(ListAbilities[i].type);
						ret.push(Type.createInstance(C, [player]));
						//ret[ret.length] = Type.createInstance(C, [player]);
					}
					i++;
				}
			}
			if (ret.length < 1)
			{
				ret[ret.length] = new abilities.BasicShot(null);
			}
		}
		return ret;
	}
}