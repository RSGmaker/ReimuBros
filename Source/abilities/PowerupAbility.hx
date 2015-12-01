package abilities;

/**
 * ...
 * @author RSGmaker
 */
class PowerupAbility extends PlayerAbility
{
	public var HP:Int;
	public var maxHP:Int = 1;
	
	public var soul:String = "";
	public var started:Bool = false;
	public var lastmessage:String = "";
	public function new(player:Player) 
	{
		super(player);
		//this ability is for adventure more, this text might not be visible to the user.
		description = "Can be powered up.";
	}
	override public function init() 
	{
		if (started)
		{
			return;
		}
		started = true;
		super.init();
		HP = 0;
		
		//player.scaleX = 0.7;
		//player.scaleY = player.scaleX;
		////////////////////////////player.ofeetposition *= 1.1;
		/*updateHP();
		player.scaleX = player.scaleX + 0.01;
		updateHP();*/
		/////player.feetposition *= 1.2;
		/*player.maxcooldown = 1950;
		player.warncooldown = true;
		player.cooldowntext = "Extra HP!";*/
	}
	public function updateHP()
	{
		if (HP < 1)
		{
			/*player.scaleX = 0.4;
			player.scaleY = player.scaleX;*/
			player.setscale(0.7);
			//player.scaleX = 0.7;
			//player.scaleY = player.scaleX;
		}
		else
		{
			player.setscale(0.85);
			//player.scaleX = 0.85;
			//player.scaleY = player.scaleX;
		}
	}
	override public function onframe() 
	{
		if (soul != null && soul != "")
		{
			if (HP == 0)
			{
				//may fix multiplayer issues.
				HP = 1;
			}
		}
		else if (HP == 1)
		{
			HP = 0;
		}
		soul = player.charactersoul;
		updateHP();
		super.onframe();
	}
	//copied from treasure hunter code
	override public function onheadbonk() 
	{
		super.onheadbonk();
		//
		//if (game.Hoster)
		if (player.isme)
		{
			var headbonk:Dynamic = player.headbonk;
			if (headbonk != null && headbonk.type == "Block")
			{
				var B:Block = headbonk;
				//if (!B.searched && !game.trophyactive && Math.random()>0.98)
				if (!B.searched && !game.trophyactive && Math.random()>0.97)
				{
					/*var D:Dynamic = { };
					//var items:Array<String> = ["Trophy","MiniHakkero", "Camera","SpellCard"];
					var items:Array<String> = ["powerup"];
					//D.type = "Trophy";
					D.type = items[Std.int(Math.random() * items.length)];
					D.UID = Math.random();
					D.x = B.x;
					D.y = B.y - 64;
					if (Math.random()<0.5)
					{
						D.Ldir = -1;
					}
					else
					{
						D.Ldir = 1;
					}
					game.SendEvent("SpawnItem", D);
					//prevent auto collect
					B.bonkedby = null;*/
					QuestionBlock.releasecontents(B);
				}
				B.searched = true;
			}
		}
	}
	public function powerdown()
	{
		SoundManager.Play("powerdown");
		HP = 0;
		updateHP();
		player.ability.lostability();
		removeabilities();
		player.charactersoul = "";
		player.warncooldown = false;
		//player.ability.SetAbilities();
		//var P = PlayerAbilityManager.GetAbilities2(soul);
	}
	private function removeabilities()
	{
		var A = player.ability.abilities;
		var i = 0;
		while (i < A.length)
		{
			if (A[i] != this)
			{
				A.remove(A[i]);
				i--;
			}
			i++;
		}
	}
	public function changeabilities(soul:String)
	{
		if (this.soul == soul)
		{
			return;
		}
		player.maxcooldown = 300;
		player.cooldown = 0;
		player.cooldowntext = "Ability ready!";
		
		//player.useotherhitbox = true;
		player.warncooldown = false;
		
		this.soul = soul;
		player.ability.lostability();
		removeabilities();
		player.charactersoul = soul;
		player.ability.SetAbilities(true);
		player.ability.init();
		
		var S = player.ability.getdescription(false);
		S = S.split(description).join("").split("\n\n").join("\n");
		if (S != "No ability\n")
		{
			lastmessage = S;
			player.message = S;
			player.messagetime = 150;
		}
		//player.cooldowntext = S;
	}
	override public function oncollect(E:EntityItem) 
	{
		if (E.charname == "powerup")
		{
			var D:Dynamic = E;
			var P:PowerupItem = D;
			//play powerup sound effect.
			if (HP < maxHP)
			{
				if (HP == 0)
				{
					//collecting power ups, already plays this sound.
					//SoundManager.Play("powerup");
				}
				HP++;
				updateHP();
				//player.setscale(0.7);
			}
			if (P.power != null && P.power != "" && P.power != soul)
			{
				//soul = P.power;
				if ((soul == null || soul == "") || P.power != "red_fairy")
				{
					changeabilities(P.power);
				}
			}
		}
		//super.oncollect(E);
	}
	override public function onattacked(fatal:Bool) 
	{
		//super.onattacked();
		if (HP > 0)
		{
			player.cooldown = player.maxcooldown;
			player.cancel = true;
			player.invincibility = 180;
			if (player.message == lastmessage && player.messagetime>0)
			{
				player.message = "";
				player.messagetime = 0;
				lastmessage = "";
			}
			HP--;
			if (HP == 0)
			{
				//play powerdown sound effect
				//SoundManager.Play("powerdown");
				powerdown();
			}
			updateHP();
		}
	}
}