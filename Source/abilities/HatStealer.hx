package abilities;

/**
 * ...
 * @author RSGmaker
 */
class HatStealer extends PlayerAbility
{
	public var hat:String = "";
	public var char:String = "";
	public function new(player:Player) 
	{
		super(player);
		description = "Steals hats from enemies\nwhich grants extra hp";
	}
	override public function init() 
	{
		super.init();
		char = player.charname;
	}
	override public function lostability() 
	{
		super.lostability();
		if (hat != "")
		{
			hat = "";
			player.baseexpression = "";
			//player.expressive = true;
			player.expressiontime = 0;
		}
	}
	override public function onattacked(fatal:Bool) 
	{
		super.onattacked(fatal);
		if (hat != "")
		{
			player.cancel = true;
			hat = "";
			player.invincibility = 180;
			player.expressiontime = 0;
			player.baseexpression = "";
		}
	}
	override public function onkill(E:Entity) 
	{
		super.onkill(E);
		if (hat == "" && Std.is(E,Imposter))
		{
			var D:Dynamic = E;
			var O:Imposter = D;
			var S = CharHelper.getCharPreset(O.rename);
			if (S != null)
			{
				hat = CharHelper.getdnapart(S, AvatarEditor.partlist.indexOf("Hat"));
				if (hat == "0")
				{
					hat = "";
					return;
				}
				S = CharHelper.getCharPreset(player.charname);
				if (S != null)
				{
					player.baseexpression = CharHelper.changednapart(S, AvatarEditor.partlist.indexOf("Hat"), hat);
				}
			}
		}
	}
	override public function onframe() 
	{
		super.onframe();
		/*if (hat != "")
		{
			//player.ChangeExpression("Hat", hat, Std.int(Math.max(1,player.expressiontime)), false, false);
		}*/
	}
}