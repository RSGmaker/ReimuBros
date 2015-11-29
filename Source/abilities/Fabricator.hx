package abilities;

/**
 * ...
 * @author RSGmaker
 */
class Fabricator extends PlayerAbility
{
	public var item:CarryItem = null;
	public function new(player:Player) 
	{
		super(player);
		description = "Creates a random weapon";
	}
	override public function init() 
	{
		super.init();
		player.maxcooldown = 1400;
		player.warncooldown = true;
	}
	override public function onattacked(fatal:Bool) 
	{
		super.onattacked(fatal);
		if (fatal)
		{
			var D:Dynamic = { };
			D.type = "Destroy";
			item.SendCustomEvent(D);
		}
	}
	override public function lostability() 
	{
		super.lostability();
		if (item != null && item.alive)
		{
			var D:Dynamic = { };
			D.type = "Destroy";
			item.SendCustomEvent(D);
		}
	}
	override public function onframe() 
	{
		super.onframe();
		if (item == null)
		{
			player.cooldown--;
		}
		if (item != null && item.alive)
		{
			if (item.holder != player)
			{
				var D:Dynamic = { };
				D.type = "Destroy";
				item.SendCustomEvent(D);
			}
		}
		else
		{
			item = null;
		}
	}
	override public function onuse() 
	{
		super.onuse();
		if (player.isme && player.cooldown <= 0 && player.equipment==null)
		{
			player.cooldown = player.maxcooldown;
			var T = EntityItem.getitem("list:weapons");
			var D:Dynamic = { };
			D.type = T;
			D.UID = Math.random();
			D.x = player.x;
			D.y = player.y;
			//D.platform = E.UID;
			if (Math.random()<0.5)
			{
				D.Ldir = -1;
			}
			else
			{
				D.Ldir = 1;
			}
			
			game.SendEvent("SpawnItem", D);
			
			var E:Dynamic = game.EntityFromUID(D.UID);
			item = E;
			if (!item.clientcollect)
			{
				game.SendEvent("Collect", item.UID);
			}
			else
			{
				item.Collect(player);
			}
			item.uses = Math.floor(item.uses / 2);
		}
	}
}