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
		L[L.length] = { type:new abilities.SpawnShanghai(null), names:["alice"] };
		L[L.length] = { type:new abilities.MoreZombieFairies(null), names:["orin"] };
		L[L.length] = { type:new abilities.DoubleMyon(null), names:["youmu"] };
		L[L.length] = { type:new abilities.Floating(null), names:["lunasa", "lyrica", "merlin", "daiyousei", "mystia", "lunachild", "starsaphire", "elis", "kurumi", "gengetsu", "mai", "shinki", "makairesident-a", "lilith"] };
		L[L.length] = { type:new abilities.YinYangOrbs(null), names:["reimu"] };
		L[L.length] = { type:new abilities.IceAffinity(null), names:["cirno", "letty"] };
		L[L.length] = { type:new abilities.WorldFreezer(null), names:["letty"] };
		L[L.length] = { type:new abilities.GapManipulator(null), names:["yukari"] };
		L[L.length] = { type:new abilities.FlipResistance(null), names:["seija"] };
		L[L.length] = { type:new abilities.FireProof(null), names:["mokou"] };
		L[L.length] = { type:new abilities.WorldScorcher(null), names:["mokou"] };
		L[L.length] = { type:new abilities.EatMystia(null), names:["yuyuko"] };
		L[L.length] = { type:new abilities.MoreInvincibility(null), names:["kaguya"] };
		L[L.length] = { type:new abilities.PreservePowBlock(null), names:["kanako"] };
		L[L.length] = { type:new abilities.Ambush(null), names:["murasa"] };
		L[L.length] = { type:new abilities.CanHide(null), names:["koishi"] };
		L[L.length] = { type:new abilities.FallThruPlatforms(null), names:["tewi"] };
		L[L.length] = { type:new abilities.ElectricProof(null), names:["iku"] };
		L[L.length] = { type:new abilities.Earthquake(null), names:["tenshi"] };
		L[L.length] = { type:new abilities.ExKeine(null), names:["keine"] };
		L[L.length] = { type:new abilities.DashAttack(null), names:["meiling", "chen"] };
		L[L.length] = { type:new abilities.ZaWarudo(null), names:["sakuya"] };
		L[L.length] = { type:new abilities.KaPow(null), names:["raiko"] };
		L[L.length] = { type:new abilities.Cheeen(null), names:["ran"] };
		L[L.length] = { type:new abilities.StarBulletG(null), names:["sanae"] };
		L[L.length] = { type:new abilities.StarBulletY(null), names:["marisa"] };
		L[L.length] = { type:new abilities.EnemyEater(null), names:["rumia"] };
		L[L.length] = { type:new abilities.Teleporter(null), names:["komachi"] };
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
		L[L.length] = { type:new abilities.BecomeInvisible(null), names:["sunnymilk", "nitori"] };
		L[L.length] = { type:new abilities.AbsorbDamage(null), names:["byakuren"] };
		L[L.length] = { type:new abilities.MusicSelector(null), names:["lunasa", "lyrica", "merlin"] };
		L[L.length] = { type:new abilities.HeadCannon(null), names:["sekibanki"] };
		L[L.length] = { type:new abilities.ClearSpawnList(null), names:["rin"] };
		L[L.length] = { type:new abilities.RefreshBlocks(null), names:["lily"] };
		L[L.length] = { type:new abilities.MasterSpark(null), names:["yuuka"] };
		L[L.length] = { type:new abilities.AlternateMusic(null), names:["benben", "yatsuhashi"] };
		L[L.length] = { type:new abilities.VampiricTouch(null), names:["remilia"] };
		L[L.length] = { type:new abilities.MoreLives(null), names:["shanghai"] };
		L[L.length] = { type:new abilities.OneWeekGirl(null), names:["patchouli"] };
		L[L.length] = { type:new abilities.StageSeal(null), names:["eirin"] };
		L[L.length] = { type:new abilities.HypnoticBullets(null), names:["satori"] };
		L[L.length] = { type:new abilities.PoisonBlocks(null), names:["medicine"] };
		L[L.length] = { type:new abilities.IceBall(null), names:["cirno"] };
		L[L.length] = { type:new abilities.SummonBlackHole(null), names:["suika"] };
		L[L.length] = { type:new abilities.BoomerangScythe(null), names:["elly"] };
		L[L.length] = { type:new abilities.TreasureHunter(null), names:["nazrin"] };
		
		
		L[L.length] = { type:new abilities.BasicShot(null), names:["benben","yatsuhashi"] };
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
	public function SetAbilities()
	{
		abilities = GetAbilities(player);
	}
	
	
	//static functions
	public static var ListAbilities:Array<Dynamic>;
	public static function GetAbilities(player:Player):Array<PlayerAbility>
	{
		var ret = GetAbilities2(player.charname, player);
		return ret;
	}
	public static function GetAbilities2(name:String,player:Player=null):Array<PlayerAbility>
	{
		if (ListAbilities == null)
		{
			initlist();
		}
		if (name.indexOf("ALT") > -1)
		{
			name = name.substring(0, name.length - 3);
		}
		var ret = new Array<PlayerAbility>();
		var i = 0;
		while (i < ListAbilities.length)
		{
			if (ListAbilities[i].names.indexOf(name)>-1)
			{
				var C = Type.getClass(ListAbilities[i].type);
				 ret[ret.length] = Type.createInstance(C, [player]);
			}
			i++;
		}
		if (ret.length < 1)
		{
			ret[ret.length] = new abilities.BasicShot(null);
		}
		return ret;
	}
}