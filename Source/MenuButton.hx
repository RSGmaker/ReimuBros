package;

import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.text.TextField;
import openfl.text.TextFormat;

/**
 * ...
 * @author RSGmaker
 */
class MenuButton extends Sprite
{
	public var textformat:TextFormat;
	public var textfield:TextField;
	public var outline:Shape;
	public var outlinecolor:UInt;
	public var innercolor:UInt;
	public var inner:Shape;
	public var image:Animation;
	public var outlinesize:Int;
	
	public var manualwidth:Int = 0;
	public var manualheight:Int = 0;
	
	public var button:Sprite;
	//lets us put whatever data inside that associates with this button
	public var data:Dynamic;
	public function new(text:String=" ",fontsize:Int=44,fontname:String="Arial",outlinesize:Int=6,innercolor:UInt=0x11CC55,outlinecolor:UInt=0x00AA33) 
	{
		super();
		data = { };
		textformat = new TextFormat();
		textformat.font = fontname;
		textformat.size = fontsize;
		
		textfield = new TextField();
		textfield.text = text;
		textfield.mouseEnabled = false;
		textfield.setTextFormat(textformat);
		textfield.name = "textField";
		
		this.outlinesize = outlinesize;
		this.outlinecolor = outlinecolor;
		this.innercolor = innercolor;
		
		
		outline = new Shape();
		inner = new Shape();
		button = new Sprite();
		
		button.addChild(outline);
		button.addChild(inner);
		addChild(button);
		addChild(textfield);
		
		update();
		
		x = outlinesize;
		x -= (textfield.width / 2);
		
		
		this.buttonMode = true;
	}
	public function settext(text:String)
	{
		textfield.text = text;
		textfield.setTextFormat(textformat);
		update();
	}
	public function setcolors(innercolor:UInt = 0x11CC55, outlinecolor:UInt = 0x00AA33,alpha:Float=-1)
	{
		this.outlinecolor = outlinecolor;
		this.innercolor = innercolor;
		if (alpha >= 0)
		{
			button.alpha = alpha;
		}
		update();
	}
	public function setanimation(image:String,scaleX:Float=1,scaleY:Float=1)
	{
		var ok = false;
		if (this.image == null)
		{
			this.image = new Animation(Main._this.AL.GetAnimation(image));
			ok = true;
		}
		else
		{
			this.image.ChangeAnimation(Main._this.AL.GetAnimation(image));
		}
		var img = this.image;
		img.scaleX = scaleX;
		img.scaleY = scaleY;
		img.x = 0;
		img.y = 0;
		if (manualwidth > 0)
		{
			var W = manualwidth+outlinesize;
			var WH = W / 2;
			
			img.x = WH - (img.width / 2);
			img.y = WH - (img.height / 2);
			img.x -= outlinesize*1.5;
			img.y -= outlinesize*1.5;
		}
		if (ok)
		{
			addChild(this.image);
		}
		update();
	}
	public function update()
	{
		var W = textfield.width;
		
		var SZ = outlinesize;
		var SZ2 = SZ + SZ;
		var SZ3 = SZ + SZ + SZ;
		textfield.setTextFormat(textformat);
		
		textfield.x = 0;
		textfield.y = 0;
		textfield.width = textfield.textWidth + SZ2;
		textfield.height = textfield.textHeight + SZ2;
		
		var width = textfield.textWidth+SZ2;
		var height = textfield.textHeight+SZ2;
		if (manualwidth > 0)
		{
			width = manualwidth;
			height = manualheight;
		}
		
		outline.graphics.clear();
		outline.graphics.beginFill(outlinecolor);
		outline.graphics.drawRect(-SZ, -SZ, width, height);
		outline.graphics.endFill();
		inner.graphics.clear();
		inner.graphics.beginFill(innercolor);
		inner.graphics.drawRect(0, 0, width-SZ2, height-SZ2);
		inner.graphics.endFill();
		
		var fillType:flash.display.GradientType = flash.display.GradientType.LINEAR;
		//var colors:Array<UInt> = [0x777777, 0xffffff];
		//var colors:Array<UInt> = [0, 0xffffff];
		var colors:Array<UInt> = [innercolor, 0xffffff];
		var alphas = [0.06, 0.6];
		var ratios = [0x00, 0xFF];
		var matr:flash.geom.Matrix = new flash.geom.Matrix();
		//matr.createGradientBox(50, 9, 1.57079632679, 0, -4.5);
		matr.createGradientBox(50, height-SZ2, 1.57079632679, 0, height-SZ2);
		var spreadMethod:flash.display.SpreadMethod = flash.display.SpreadMethod.REFLECT;
		inner.graphics.beginGradientFill(fillType, colors, alphas, ratios, matr, spreadMethod);  
	 
		inner.graphics.drawRoundRect(0, 0, width-SZ2, (height-SZ2)*0.65,5);
		inner.graphics.endFill();
		
		if (manualwidth > 0)
		{
			width = manualwidth;
			height = manualheight;
		}
		else
		{
			W = W - textfield.width;
			x -= (W / 2);
			width = textfield.width;
			height = textfield.height;
		}
	}
}