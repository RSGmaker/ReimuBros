package;

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
	}
	public function init()
	{
		var i = 0;
		while (i < abilities.length)
		{
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
	public function onattacked()
	{
		var i = 0;
		while (i < abilities.length)
		{
			abilities[i].onattacked();
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
	public function SetAbilities()
	{
		SetFlags(player);
		abilities = GetAbilities(player);
	}
	
	//static functions
	//set all the players ability flags
	public static function SetFlags(player:Player)
	{
		player.flags = GetFlags(player.charname);
	}
	public static function GetFlags(charname:String):FlagManager
	{
		//if (!GameView._this.tournament)
		var flags = new FlagManager(1);
		{
			//var charname = player.charname;
			//var flags = player.flags;
			if (charname.indexOf("ALT")>-1)
			{
				charname = charname.substr(0, charname.length - 3);
			}
			switch (charname)
		{
			case "aya":
				flags.set(Player.SuperSpeed, true);
			case "alice":
				flags.set(Player.SpawnShanghai, true);
			case "youmu":
				flags.set(Player.DoubleMyon, true);
			case "cirno":
				flags.set(Player.IceAffinity, true);
			case "letty":
				flags.set(Player.IceAffinity, true);
				flags.set(Player.WorldFreezer, true);
			case "yukari":
				flags.set(Player.GapManipulator, true);
			case "seija":
				flags.set(Player.FlipResistance, true);
			case "mokou":
				flags.set(Player.FireProof, true);
				flags.set(Player.WorldScorcher, true);
			case "orin":
				flags.set(Player.MoreZombieFairies, true);
			case "yuyuko":
				flags.set(Player.EatMystia, true);
			case "kaguya":
				flags.set(Player.MoreInvincibility, true);
			case "kanako":
				flags.set(Player.PreservePowBlock, true);
			case "murasa":
				flags.set(Player.Ambush, true);
			case "koishi":
				flags.set(Player.CanHide, true);
			case "tewi":
				flags.set(Player.FallThruPlatforms, true);
			case "iku":
				flags.set(Player.ElectricProof, true);
			case "tenshi":
				flags.set(Player.Earthquake, true);
			case "flandre":
				flags.set(Player.DestructiveJump, true);
			case "keine":
				flags.set(Player.ExKeine, true);
			case "reimu":
				flags.set(Player.YinYangOrbs, true);
			case "meiling":
				flags.set(Player.DashAttack, true);
			case "sakuya":
				flags.set(Player.ZaWarudo, true);
			case "raiko":
				flags.set(Player.KaPow, true);
			case "ran":
				flags.set(Player.Cheeen, true);
			case "chen":
				flags.set(Player.DashAttack, true);
			case "sanae":
				flags.set(Player.StarBulletG, true);
			case "marisa":
				flags.set(Player.StarBulletY, true);
			case "rumia":
				flags.set(Player.EnemyEater, true);
			case "komachi":
				flags.set(Player.Teleporter, true);
			case "nue":
				flags.set(Player.FriendlyUFO, true);
			case "wriggle":
				flags.set(Player.LightDashAttack, true);
			case "yuugi":
				flags.set(Player.HeavyBonk, true);
			case "ringo":
				flags.set(Player.ExtraLives, true);
			case "kyouko":
				flags.set(Player.BounceEntities, true);
			case "elly":
				flags.set(Player.TileDanmaku, true);
			case "shou":
				flags.set(Player.InstantCollect, true);
			case "sariel":
				flags.set(Player.AngelOfDeath, true);
			case "shikieiki":
				flags.set(Player.Fairplay, true);
			case "suwako":
				flags.set(Player.SuwakoHoop, true);
			case "minoriko":
				flags.set(Player.ExtraPoints, true);
			case "sunnymilk":
				flags.set(Player.BecomeInvisible, true);
			case "nitori":
				flags.set(Player.BecomeInvisible, true);
			case "byakuren":
				flags.set(Player.AbsorbDamage, true);
			case "lunasa":
				flags.set(Player.MusicSelector, true);
				flags.set(Player.Floating, true);
			case "lyrica":
				flags.set(Player.MusicSelector, true);
				flags.set(Player.Floating, true);
			case "merlin":
				flags.set(Player.MusicSelector, true);
				flags.set(Player.Floating, true);
			case "sekibanki":
				flags.set(Player.HeadCannon, true);
			case "daiyousei":
				flags.set(Player.Floating, true);
			case "mystia":
				flags.set(Player.Floating, true);
			case "lunachild":
				flags.set(Player.Floating, true);
			case "starsaphire":
				flags.set(Player.Floating, true);
			case "elis":
				flags.set(Player.Floating, true);
			case "kurumi":
				flags.set(Player.Floating, true);
			case "gengetsu":
				flags.set(Player.Floating, true);
			case "mai":
				flags.set(Player.Floating, true);
			case "shinki":
				flags.set(Player.Floating, true);
			case "makairesident-a":
				flags.set(Player.Floating, true);
			case "makairesident-b":
				flags.set(Player.Floating, true);
			default:
		}
		/*if (cooldown == 0 && maxcooldown > 0)
		{
			cooldown = maxcooldown;
		}*/
		if (flags.isempty())
		{
			//flags.set(Player.Floating, true);
			flags.set(Player.BasicShot, true);
		}
		flags.set(Player.SpawnZombieFairies, true);
		}
		return flags;
	}
	//public static var       Flags:Array<Int> = [   Player.SuperSpeed,   Player.SpawnShanghai,   Player.MoreZombieFairies,   Player.DoubleMyon,   Player.Floating,   Player.YinYangOrbs,   Player.IceAffinity,   Player.WorldFreezer,   Player.GapManipulator,   Player.FlipResistance];
	//public static var Abilities:Array<Class> = [abilities.SuperSpeed,abilities.SpawnShanghai,abilities.MoreZombieFairies,abilities.DoubleMyon,abilities.Floating,abilities.YinYangOrbs,abilities.IceAffinity,abilities.WorldFreezer,abilities.GapManipulator,abilities.FlipResistance];
	public static function GetAbilities(player:Player):Array<PlayerAbility>
	{
		return GetAbilityList(player.flags,player);
	}
	public static function GetAbilityList(flags:FlagManager,player:Player=null):Array<PlayerAbility>
	{
		var ret = new Array<PlayerAbility>();
		//var flags = player.flags;
		if (flags.get(Player.SuperSpeed))
		{
			ret[ret.length] = new abilities.SuperSpeed(player);
		}
		if (flags.get(Player.SpawnShanghai))
		{
			ret[ret.length] = new abilities.SpawnShanghai(player);
		}
		if (flags.get(Player.MoreZombieFairies))
		{
			ret[ret.length] = new abilities.MoreZombieFairies(player);
		}
		if (flags.get(Player.DoubleMyon))
		{
			ret[ret.length] = new abilities.DoubleMyon(player);
		}
		if (flags.get(Player.Floating))
		{
			ret[ret.length] = new abilities.Floating(player);
		}
		if (flags.get(Player.YinYangOrbs))
		{
			ret[ret.length] = new abilities.YinYangOrbs(player);
		}
		if (flags.get(Player.IceAffinity))
		{
			ret[ret.length] = new abilities.IceAffinity(player);
		}
		if (flags.get(Player.WorldFreezer))
		{
			ret[ret.length] = new abilities.WorldFreezer(player);
		}
		if (flags.get(Player.GapManipulator))
		{
			ret[ret.length] = new abilities.GapManipulator(player);
		}
		if (flags.get(Player.FlipResistance))
		{
			ret[ret.length] = new abilities.FlipResistance(player);
		}
		if (flags.get(Player.FireProof))
		{
			ret[ret.length] = new abilities.FireProof(player);
		}
		if (flags.get(Player.WorldScorcher))
		{
			ret[ret.length] = new abilities.WorldScorcher(player);
		}
		if (flags.get(Player.EatMystia))
		{
			ret[ret.length] = new abilities.EatMystia(player);
		}
		if (flags.get(Player.MoreInvincibility))
		{
			ret[ret.length] = new abilities.MoreInvincibility(player);
		}
		if (flags.get(Player.PreservePowBlock))
		{
			ret[ret.length] = new abilities.PreservePowBlock(player);
		}
		if (flags.get(Player.Ambush))
		{
			ret[ret.length] = new abilities.Ambush(player);
		}
		if (flags.get(Player.CanHide))
		{
			ret[ret.length] = new abilities.CanHide(player);
		}
		if (flags.get(Player.FallThruPlatforms))
		{
			ret[ret.length] = new abilities.FallThruPlatforms(player);
		}
		if (flags.get(Player.ElectricProof))
		{
			ret[ret.length] = new abilities.ElectricProof(player);
		}
		if (flags.get(Player.Earthquake))
		{
			ret[ret.length] = new abilities.Earthquake(player);
		}
		if (flags.get(Player.ExKeine))
		{
			ret[ret.length] = new abilities.ExKeine(player);
		}
		if (flags.get(Player.DashAttack))
		{
			ret[ret.length] = new abilities.DashAttack(player);
		}
		if (flags.get(Player.ZaWarudo))
		{
			ret[ret.length] = new abilities.ZaWarudo(player);
		}
		if (flags.get(Player.KaPow))
		{
			ret[ret.length] = new abilities.KaPow(player);
		}
		if (flags.get(Player.Cheeen))
		{
			ret[ret.length] = new abilities.Cheeen(player);
		}
		if (flags.get(Player.StarBulletG))
		{
			ret[ret.length] = new abilities.StarBulletG(player);
		}
		if (flags.get(Player.StarBulletY))
		{
			ret[ret.length] = new abilities.StarBulletY(player);
		}
		if (flags.get(Player.EnemyEater))
		{
			ret[ret.length] = new abilities.EnemyEater(player);
		}
		if (flags.get(Player.Teleporter))
		{
			ret[ret.length] = new abilities.Teleporter(player);
		}
		if (flags.get(Player.FriendlyUFO))
		{
			ret[ret.length] = new abilities.FriendlyUFO(player);
		}
		if (flags.get(Player.LightDashAttack))
		{
			ret[ret.length] = new abilities.LightDashAttack(player);
		}
		if (flags.get(Player.HeavyBonk))
		{
			ret[ret.length] = new abilities.HeavyBonk(player);
		}
		if (flags.get(Player.Warping))
		{
			ret[ret.length] = new abilities.Warping(player);
		}
		if (flags.get(Player.DestructiveJump))
		{
			ret[ret.length] = new abilities.DestructiveJump(player);
		}
		if (flags.get(Player.ExtraLives))
		{
			ret[ret.length] = new abilities.ExtraLives(player);
		}
		if (flags.get(Player.BounceEntities))
		{
			ret[ret.length] = new abilities.BounceEntities(player);
		}
		if (flags.get(Player.TileDanmaku))
		{
			ret[ret.length] = new abilities.TileDanmaku(player);
		}
		if (flags.get(Player.InstantCollect))
		{
			ret[ret.length] = new abilities.InstantCollect(player);
		}
		if (flags.get(Player.AngelOfDeath))
		{
			ret[ret.length] = new abilities.AngelOfDeath(player);
		}
		if (flags.get(Player.Fairplay))
		{
			ret[ret.length] = new abilities.Fairplay(player);
		}
		if (flags.get(Player.SuwakoHoop))
		{
			ret[ret.length] = new abilities.SuwakoHoop(player);
		}
		if (flags.get(Player.ExtraPoints))
		{
			ret[ret.length] = new abilities.ExtraPoints(player);
		}
		if (flags.get(Player.BecomeInvisible))
		{
			ret[ret.length] = new abilities.BecomeInvisible(player);
		}
		if (flags.get(Player.AbsorbDamage))
		{
			ret[ret.length] = new abilities.AbsorbDamage(player);
		}
		if (flags.get(Player.MusicSelector))
		{
			ret[ret.length] = new abilities.MusicSelector(player);
		}
		if (flags.get(Player.HeadCannon))
		{
			ret[ret.length] = new abilities.HeadCannon(player);
		}
		if (flags.get(Player.BasicShot))
		{
			ret[ret.length] = new abilities.BasicShot(player);
		}
		return ret;
	}
}