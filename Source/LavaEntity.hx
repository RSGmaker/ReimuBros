package;
import openfl.display.Shape;
import openfl.display.Sprite;

/**
 * ...
 * @author RSGmaker
 */
class LavaEntity extends Entity
{
	//pulsetimer
	public var pulse:Int;
	public var surface:Sprite;
	public function new() 
	{
		//super("black");
		super(null);
		width = 800;
		height = 300;
		dangerous = true;
		type = "Lava";
		removeonlevelend = true;
		//image.visible = false;
		makesurface();
		//var G = graphics;
	}
	private function makesurface()
	{
		surface = new Sprite();
		var G = surface.graphics;
		//G.lineStyle(2, 0xFFAA00);
		//G.lineStyle(1, 0xFFFF00);
		///G.lineStyle(1, 0xFFDD66);
		//G.beginFill(0xFFFF00);
		var X = 0.0;
		/*while (X < 832)
		{
			G.moveTo(X, 0);
			G.lineTo(X - 12, 6);
			X += 8;
		}*/
		/*while (X < 832)
		{
			var Y = 0.0;
			//X += Math.random() * 5;
			var XX = X;
			Y = -2 + (Math.random() * 6);
			
			G.moveTo(XX, Y);
			G.lineTo(XX - 5 - (Math.random() * 5),Y);
			XX += -2 + (Math.random() * 5);
			Y = -2 + (Math.random() * 6);
			G.moveTo(XX, Y);
			G.lineTo(XX - 5 - (Math.random() * 5),Y);
			
			X += 3 + (Math.random() * 7);
			
		}*/
		var C = 0xCCFF00;
		G.beginFill(C, 0.3);
		G.drawRect(0, 0, 832, 7);
		G.endFill();
		G.beginFill(C, 0.3);
		G.drawRect(0, 0, 832, 5);
		G.endFill();
		G.beginFill(C, 0.3);
		G.drawRect(0, 0, 832, 2);
		G.endFill();
		/*G.beginFill(0xFFFFFF, 0.5);
		G.drawRect(0, 0, 832, 2);
		G.endFill();*/
		//G.endFill();
		addChild(surface);
	}
	override public function update():Void 
	{
		width = 832;
		height = 300;
		var G = graphics;
		G.clear();
		var F:Float = pulse*0.01;
		if (F > 1)
		{
			F = 2 - F;
		}
		F = 0.5 + (F * 0.5);
		var C = Std.int(255 * F);
		var CC = Std.int(C * 0.1);
		C = (C << 16) + ((CC) << 8);
		//C = 0xFF0000;
		G.beginFill(C);
		G.drawRect(0, 0, 832, 300);
		G.endFill();
		/*C = Std.int(255 * F);
		C = ((255 - C) << 8) + (C << 16);
		G.beginFill(C, 0.4);
		G.drawRect(0, 0, 800, 10);
		G.endFill();*/
		//if (y > 400)
		
		//if (y > 424)
		if (y > 324)
		{
			y -= 1;
		}
		pulse++;
		if (pulse > 200)
		{
			pulse = 0;
		}
		if (game.Hoster)
		{
			var i = 0;
			updatekills();
		}
		//super.update();
	}
	
	public function updatekills()
	{
		//var enemy = game.CollisionDetectPointEnemy(x + 24, y + 24);
		var enemy = game.CollisionDetectTouchEnemy(this);
		var danger = game.CollisionDetectTouchDangerous(this);
		if (enemy != null && !enemy.killed && enemy.invincibility<=0)
		{
			game.SendEvent("Destroy", enemy.UID);
		}
		var DD:Dynamic = danger;
		if (danger != null && danger.type=="Enemy" && (DD.charname == "Cirno" || DD.charname=="Iku") && danger.invincibility<=0)
		{
			game.SendEvent("Destroy", danger.UID);
		}
	}
}