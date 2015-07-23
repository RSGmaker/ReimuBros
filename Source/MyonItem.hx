package;

/**
 * ...
 * @author RSGmaker
 */
class MyonItem extends CarryItem
{
	public var rename:String;
	public var facedirection:Bool;
	public var dualcarry:Bool;
	public var HP:Int;
	public var flags:FlagManager;
	public function new() 
	{
		super("myon");
		DestroyOnRoundEnd = false;
		OffsetX = 40;
		//OffsetY = 5;
		Dropable = false;
		subtype = "Myon";
		rename = "myon";
		facedirection = false;
		dualcarry = false;
		HP = 1;
		//flags = new FlagManager(1);
		//flags.set(Player.EatMystia, true);
	}
	override public function Collect(player:Player) 
	{
		//if (player.myMyon == null || player.charname == "youmu")
		if (player.myMyon == null || dualcarries())
		{
			holder = player;
			if (player.myMyon != null && player.myMyon.OffsetX>0)
			{
				OffsetX = -40;
				ChangeAnimation(rename+"F");
				//holder = player;
			}
			super.Collect(player);
			//player.myMyon = this;
		}
	}
	public function dualcarries():Bool
	{
		return game.myplayer.flags.get(Player.DoubleMyon) || dualcarry || (game.myplayer.myMyon != null && game.myplayer.myMyon.dualcarry);
	}
	override public function update():Void 
	{
		super.update();
		//if (collectable && game.myplayer.myMyon != null && !(game.myplayer.flags.get(Player.DoubleMyon) && !(dualcarry || (game.myplayer.myMyon != null && game.myplayer.myMyon.dualcarry))))
		if (!dualcarries() && collectable && game.myplayer.myMyon != null)
		{
			//prevent collect spam by players who cant even pick them up.
			collectable = false;
		}
		else if (collectable)
		{
			//if (game.myplayer.flags.get(Player.DoubleMyon) || (dualcarry || (game.myplayer.myMyon != null && game.myplayer.myMyon.dualcarry)))
			if (dualcarries())
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
					collectable = true;
				}
				else
				{
					collectable = false;
				}
			}
		}
		if (holder != null && (holder.killed || !holder.alive))
		{
			alive = false;
		}
		else if (holder != null)
		{
			//if (holder.myMyon != this && holder.myMyon !=)
			holder.myMyon = this;
			Ldir = holder.Ldir;
			if (holder.type == "Player")
			{
				var D:Dynamic = holder;
				D.allmyons[D.allmyons.length] = this;
				if (flags != null)
				{
					D.flags.add(flags);
				}
			}
			if (facedirection)
			{
			if (Ldir > 0)
			{
				ChangeAnimation(rename);
				//OffsetX = Math.abs(OffsetX);
			}
			if (Ldir < 0)
			{
				ChangeAnimation(rename+"F");
				//OffsetX = -Math.abs(OffsetX);
			}
			}
		}
	}
	public override function Death() 
	{
		//super.Death();
		if (holder.type == "Player")
		{
			var D:Dynamic = holder;
			if (D.myMyon == this)
			{
				D.myMyon = null;
			}
		}
		if (holder.myMyon == this)
		{
			holder.myMyon = null;
		}
	}
}