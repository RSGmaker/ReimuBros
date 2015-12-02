package;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class CarryItem extends EntityItem
{
	public var holder:Entity;
	public var OffsetX:Float;
	public var OffsetY:Float;
	public var centering:Float;
	//public var DestroyOnRoundEnd:Bool;
	//can item drop if you are bumped.
	public var Dropable:Bool;
	//how much time the item has to be unheld before despawning.
	public var maxdespawntime:Int;
	public var despawntime:Int;
	
	//item has a use function.
	public var canuse:Bool=false;
	//number of uses remaining(0 for infinite)
	public var uses:Int = 7;
	public var maxuses:Int = 7;
	//set to false to prevent destroy when used up.
	public var destroywhenempty:Bool = true;
	//set to false to prevent consuming ammo of other items
	public var restock:Bool = true;
	
	//number of frames until the item can be used again.
	public var cooldown:Int;
	public var maxcooldown:Int = 300;
	
	//how long until the item can be picked up.(dropping the item sets this value so you don't pick it up again)
	public var pickupdelay:Int;
	
	public var LWidth:Float = 1;
	
	//0=none
	//1=myon
	//2=equipment
	//3=head
	//4=other
	public var itemtype:Int;
	public function new(ani:String)
	{
		super(ani);
		subtype = ani;
		type = "Carryitem";
		
		OffsetX = 0;
		OffsetY = -height / 2;
		centering = 0;
		//DestroyOnRoundEnd = true;
		removeonlevelend = true;
		Dropable = true;
		//maxdespawntime = 300;
		maxdespawntime = 900;
		despawntime = -1000;
		
		clientcollect = true;
		
		autocollect = false;
		custommotion = true;
		interacttext = "Pick up";
	}
	override public function GetHitbox():Rectangle 
	{
		return new Rectangle(x-16, y, width+32, height);
	}
	override public function CustomEvent(data:Dynamic) 
	{
		//super.CustomEvent(data);
		if (data.type == "Destroy")
		{
			alive = false;
			killed = true;
			if (holder != null)
			{
				if (holder.type == "Player")
				{
					var D:Dynamic = holder;
					var player:Player = D;
					if (player.equipment == this)
					{
						player.equipment = null;
					}
				}
			}
		}
		if (data.type == "Bounce")
		{
			x = data.x;
			y = data.y;
			Hspeed = data.Hspeed;
			Vspeed = data.Vspeed;
		}
		if (data.type == "SetUses")
		{
			uses = data.uses;
		}
		if (data.type == "Attach")
		{
			holder = game.EntityFromUID(data.UID);
			if (holder != null)
			{
				if (holder.type == "Player")
				{
					var D:Dynamic = holder;
					var player:Player = D;
					centering = (player.width / 2) - (width / 2);
					if (maxdespawntime > 0)
					{
						despawntime = maxdespawntime;
						visible = true;
					}
					if (itemtype == 2)
					{
						player.equipment = this;
					}
				}
			}
		}
		if (data.type == "Drop")
		{
			if (holder != null)
			{
				if (holder.type == "Player")
				{
					var D:Dynamic = holder;
					var player:Player = D;
					if (player.equipment == this)
					{
						player.equipment = null;
					}
				}
				holder = null;
			}
		}
	}
	public function Use(player:Player)
	{
		if (uses > 0)
		{
			uses--;
			if (uses <= 0 && destroywhenempty)
			{
				//alive = false;
				var D:Dynamic = { };
				D.type = "Destroy";
				SendCustomEvent(D);
			}
		}
		if (maxcooldown > 0)
		{
			cooldown = maxcooldown;
		}
	}
	override public function Collect(player:Player) 
	{
		collectable = false;
		var ok = true;
		
		
		if (itemtype == 2)
		{
			if (player.equipment != null)
			{
				ok = false;
				//openfl.system.
				//if (GetClass player.equipment)
				if (restock && subtype == player.equipment.subtype)
				{
					var DD:Dynamic = player.equipment;
					var E:CarryItem = DD;
					var needed = E.maxuses - E.uses;
					if (needed > 0)
					{
						
						if (needed >= uses)
						{
							var D:Dynamic = { };
							D.type = "SetUses";
							D.uses = uses + E.uses;
							E.SendCustomEvent(D);
							
							D = { };
							D.type = "Destroy";
							SendCustomEvent(D);
						}
						else
						{
							var D:Dynamic = { };
							D.type = "SetUses";
							D.uses = E.maxuses;
							E.SendCustomEvent(D);
							
							D = { };
							D.type = "SetUses";
							D.uses = uses - needed;
							SendCustomEvent(D);
						}
					}
				}
			}
		}
		if (ok)
		{
			var D:Dynamic = { };
			D.type = "Attach";
			D.UID = player.UID;
			SendCustomEvent(D);
		}
		/*if (ok)
		{
		holder = player;
		centering = (player.width / 2) - (width / 2);
		if (maxdespawntime > 0)
		{
			despawntime = maxdespawntime;
			visible = true;
		}
		if (itemtype == 2)
		{
			player.equipment = this;
		}
		}*/
	}
	override public function update():Void 
	{
		if (despawntime == -1000)
		{
			despawntime = maxdespawntime;
		}
		if (maxcooldown > 0)
		{
			cooldown--;
		}
		if (holder == null)
		{
			collectable = true;
			super.update();
			if (ground != null && (!collectable || !autocollect || !cancollectfrombelow))
			{
				if (ground.bonked > -1000 && Vspeed>=0)
				{
					if (game.myplayer == ground.bonkedby)
					{
						//game.SendEvent("Collect", UID);
						var D:Dynamic = { };
						D.type = "Bounce";
						D.x = x;
						D.y = y;
						D.Hspeed = Hspeed;
						D.Vspeed = -5;
						SendCustomEvent(D);
					}
				}
			}
			if (maxdespawntime > 0)
			{
				despawntime--;
				if (despawntime <= 30 && collectable)
				{
					visible = !visible;
				}
				if (despawntime <= 0)
				{
					alive = false;
				}
			}
		}
		else
		{
			if (holder.type == "Player" && holder.width != LWidth)
			{
				centering = (holder.width / 2) - (width / 2);
				LWidth = holder.width;
			}
			else if (holder.width != LWidth)
			{
				centering = (holder.width / 2) - (width / 2);
				LWidth = holder.width;
			}
			despawntime = maxdespawntime;
			collectable = false;
			if (holder.alive && game.entities.indexOf(holder) >= 0 && (/*holder.type != "Enemy" || */(!holder.killed)))
			{
				if (!(holder.ground != null && (holder.ground.bonked>0)) || (!Dropable))
				{
					x = holder.x + OffsetX+centering;
					y = holder.y + OffsetY;
					
					if (holder.type == "Player")
					{
						var D:Dynamic = holder;
						var P:Player = D;
						if (P.helditems.indexOf(this) < 0)
						{
							P.helditems.push(this);
						}
						if (itemtype == 2)
						{
							P.equipment = this;
						}
					}
				}
				else
				{
					holder = null;
				}
			}
			else
			{
				holder = null;
			}
		}
		if (pickupdelay > 0)
		{
			collectable = false;
			pickupdelay--;
		}
		if (collectable)
		{
			if (itemtype == 2)
			{
				var E = game.myplayer.equipment;
				if (E != null)
				{
					if (E.subtype != subtype)
					{
						collectable = false;
					}
					else
					{
						var D:Dynamic = E;
						var O:CarryItem = D;
						if (O.uses >= O.maxuses)
						{
							collectable = false;
						}
					}
				}
			}
		}
		/*if (itemtype == 2 && holder != null && holder.type == "Player")
		{
			var D:Dynamic = holder;
			
		}*/
		if (canuse && holder == game.myplayer && game.gamestage.scaleY == 1 && game.gamestage.scaleX == 1)
		{
			var G = game.gui.graphics;
			//var G = game.camera.graphics;
			//var G = game.graphics;
			var X = holder.x + game.camera.x;
			var Y = holder.y + game.camera.y;
			//X -= 10;
			//Y += holder.height;
			Y -= 4;
			var C = 0xAAAAFF;
			if (cooldown > 0)
			{
				C = 0xFF5555;
			}
			var i = 0;
			var W = 8;
			X -= W;
			G.beginFill(C, 1);
			while (i < uses)
			{
				i++;
				G.drawRect(X, Y, W, 3);
				X += W+2;
			}
			G.endFill();
		}
		if (!alive && holder != null)
		{
			//assume the round is over and its time to reward player.
			Death();
		}
		if (y > 600)
		{
			alive = false;
		}
	}
	public function Death()
	{
		
	}
}