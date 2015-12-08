package abilities;

/**
 * ...
 * @author RSGmaker
 */
class BucketRider extends PlayerAbility
{
	public var bucketform:Bool;
	public var handle:Particle;
	public function new(player:Player) 
	{
		super(player);
		aesthetic = true;
	}
	override public function init() 
	{
		super.init();
		//player.headposition = 100;
		player.feetposition += 7;
		player.hover = true;
		handle = new Particle("kisumehandle");
		game.AddObject(handle);
	}
	override public function lostability() 
	{
		//player.headposition = 0;
		player.feetposition -= 7;
		player.hover = false;
		handle.alive = false;
		handle.HP = 0;
		if (bucketform)
		{
			player.baseexpression = "";
		}
		super.lostability();
	}
	override public function onattacked(fatal:Bool) 
	{
		super.onattacked(fatal);
		if (fatal)
		{
			handle.visible = false;
			handle.HP = 3000;
		}
	}
	override public function onendframe() 
	{
		super.onframe();
		if (player.charname != "kisume" && !bucketform)
		{
			bucketform = true;
			var S = CharHelper.getCharPreset(player.charname);
			if (S != null)
			{
				player.baseexpression = CharHelper.changednapart(S, AvatarEditor.partlist.indexOf("Body"), "133");
			}
			//CharHelper.getdnapart(S, AvatarEditor.partlist.indexOf("Body"));
		}
		handle.HP = 5;
		handle.scaleX = player.scaleX;
		handle.scaleY = player.scaleY;
		handle.x = (player.x + player.middle) - (handle.width * 0.48);
		//handle.y = player.y - (player.height / 8);
		handle.y = player.y - (player.height / 4);
		
		var G = game.entitylayer.graphics;
		var X = player.x + game.camera.x;
		//var Y = player.y + /*player.feetposition + game.camera.y + */player.headposition;
		if (player.alive && !player.killed)
		{
			var Y = handle.y - 599;
			handle.visible = player.visible;
			G.beginFill(0x000000);
			G.drawRect(X+20+3.3, Y, 3, 600);
			G.endFill();
			G.beginFill(0x938A42);
			G.drawRect(X+20+3.3+1, Y, 1, 600);
			G.endFill();
			//938A42
		}
		else
		{
			handle.visible = false;
			handle.HP = 1000;
		}
		if (player.image.scaleY != 1)
		{
			player.image.scaleY = 1;
			player.image.y = 0;
		}
	}
}