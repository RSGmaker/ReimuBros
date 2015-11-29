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
		removeonlevelend = false;
		OffsetX = 40;
		//OffsetY = 5;
		Dropable = false;
		subtype = "Myon";
		rename = "myon";
		facedirection = false;
		dualcarry = false;
		HP = 1;
		autocollect = true;
	}
	override public function Collect(player:Player) 
	{
		if (player.myMyon == null || dualcarries())
		{
			holder = player;
			if (player.myMyon != null && player.myMyon.OffsetX>0)
			{
				OffsetX = -40;
				ChangeAnimation(rename+"F");
			}
			super.Collect(player);
		}
	}
	public function dualcarries():Bool
	{
		return game.myplayer.flags.get(Player.DoubleMyon) || dualcarry || (game.myplayer.myMyon != null && game.myplayer.myMyon.dualcarry);
	}
	override public function update():Void 
	{
		super.update();
		if (!dualcarries() && collectable && game.myplayer.myMyon != null)
		{
			//prevent collect spam by players who cant even pick them up.
			collectable = false;
		}
		else if (collectable)
		{
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
			}
			if (Ldir < 0)
			{
				ChangeAnimation(rename+"F");
			}
			}
		}
	}
	public override function Death() 
	{
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