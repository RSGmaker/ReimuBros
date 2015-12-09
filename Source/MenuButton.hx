package;

import openfl.display.BitmapData;
import openfl.display.Shape;
import openfl.display.Sprite;
import openfl.geom.Rectangle;
import openfl.text.TextField;
import openfl.text.TextFormat;
import openfl.events.MouseEvent;

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
	
	public var colorschemes:Array<UInt>;
	public var currentscheme:Int = -1;
	
	public var sound:String = "click";
	
	public var button:Sprite;
	
	//lets us put whatever data inside that associates with this button
	public var data:Dynamic;
	public var display:Sprite;
	public var hitbox:Sprite;
	public var elavation:Bool;
	public function new(text:String=" ",fontsize:Int=44,fontname:String="Arial",outlinesize:Int=5,innercolor:UInt=0x11CC55,outlinecolor:UInt=0x00AA33,elavation:Bool=true) 
	{
		super();
		this.elavation = elavation;
		data = { };
		colorschemes = new Array<UInt>();
		addcolorscheme(innercolor, outlinecolor);
		addcolorscheme(0xFF0000, 0xFFFFFF);
		textformat = new TextFormat();
		textformat.font = fontname;
		textformat.size = fontsize;
		
		textfield = new TextField();
		textfield.text = text;
		textfield.mouseEnabled = false;
		textfield.setTextFormat(textformat);
		textfield.name = "textField";
		
		textfield.mouseEnabled = false;
		
		this.outlinesize = outlinesize;
		this.outlinecolor = outlinecolor;
		this.innercolor = innercolor;
		currentscheme = 0;
		
		
		outline = new Shape();
		inner = new Shape();
		button = new Sprite();
		display = new Sprite();
		hitbox = new Sprite();
		hitbox.visible = false;
		display.mouseEnabled = false;
		
		
		
		button.addChild(outline);
		button.addChild(inner);
		addChild(button);
		display.addChild(textfield);
		addChild(display);
		update();
		
		x = outlinesize;
		x -= (textfield.width / 2);
		
		
		//this.buttonMode = true;
		button.buttonMode = true;
		
		//this.addEventListener( MouseEvent.MOUSE_UP, function( ev ) {
		this.addEventListener( MouseEvent.CLICK, function( ev ) {
					if (sound != "" && sound != null)
					{
						SoundManager.Play(sound);
					}
				 } 
				);
	}
	public function addclick(func:Dynamic)
	{
		this.addEventListener(MouseEvent.CLICK,func);
	}
	public function addcolorscheme(innercolor:UInt, outlinecolor:UInt)
	{
		colorschemes.push(innercolor);
		colorschemes.push(outlinecolor);
	}
	public function changecolorscheme(scheme:Int,innercolor:UInt, outlinecolor:UInt)
	{
		var ind = scheme * 2;
		colorschemes[ind] = innercolor;
		colorschemes[ind + 1] = outlinecolor;
		if (currentscheme == scheme)
		{
			usecolorscheme(scheme);
		}
	}
	public function usecolorscheme(scheme:Int)
	{
		var ind = scheme * 2;
		setcolors(colorschemes[ind], colorschemes[ind + 1]);
		currentscheme = scheme;
	}
	public function press()
	{
		usecolorscheme(1);
	}
	public function depress()
	{
		usecolorscheme(0);
	}
	public function settext(text:String)
	{
		textfield.text = text;
		textfield.setTextFormat(textformat);
		update();
	}
	public function setcolors(innercolor:UInt = 0x11CC55, outlinecolor:UInt = 0x00AA33,alpha:Float=-1)
	{
		currentscheme = -1;
		this.outlinecolor = outlinecolor;
		this.innercolor = innercolor;
		if (alpha >= 0)
		{
			button.alpha = alpha;
		}
		update();
	}
	public function setbitmapdata(image:BitmapData,scaleX:Float=1,scaleY:Float=1)
	{
		var ok = false;
		if (this.image == null)
		{
			this.image = new Animation([image]);
			ok = true;
		}
		else
		{
			this.image.ChangeAnimation([image]);
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
			img.x -= outlinesize;
			img.y -= outlinesize;
		}
		if (ok)
		{
			addChild(this.image);
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
			img.x -= outlinesize;
			img.y -= outlinesize;
		}
		if (ok)
		{
			display.addChild(this.image);
		}
		update();
	}
	public function update()
	{
		var W = textfield.width;
		
		var SZ = outlinesize;
		var SZ2 = SZ + SZ;
		var SZ3 = SZ + SZ + SZ;
		
		var WShadow = SZ / 2;
		var HShadow = SZ * 0.75;
		if (!elavation)
		{
			WShadow = 0;
			HShadow = 0;
		}
		textfield.setTextFormat(textformat);
		
		textfield.x = SZ-(WShadow / 2);
		textfield.y = SZ-(HShadow / 2);
		textfield.width = textfield.textWidth + SZ2+8;
		textfield.height = textfield.textHeight + SZ2;
		
		/*var width = textfield.textWidth+SZ2;
		var height = textfield.textHeight+SZ2;*/
		var width = textfield.textWidth+SZ3;
		var height = textfield.textHeight+SZ3;
		if (manualwidth > 0)
		{
			width = manualwidth;
			height = manualheight;
		}
		
		outline.graphics.clear();
		//weird border logic
		/*outline.graphics.beginFill(outlinecolor);
		//outline.graphics.drawRect(-SZ, -SZ, width, height);
		outline.graphics.drawRoundRect(-SZ, -SZ, width, height,5);
		outline.graphics.endFill();
		inner.graphics.clear();
		inner.graphics.beginFill(innercolor);
		//inner.graphics.drawRect(0, 0, width-SZ2, height-SZ2);
		inner.graphics.drawRoundRect(0, 0, width-SZ2, height-SZ2,5);
		inner.graphics.endFill();*/
		var OC = Std.int((outlinecolor & 255) / 2) + (Std.int(((outlinecolor >> 8) & 255) / 2) << 8) + (Std.int(((outlinecolor >> 16) & 255) / 2) << 16);
		//outline.graphics.beginFill(cast(Std.int(outlinecolor/2)));
		outline.graphics.beginFill(OC);
		outline.graphics.drawRoundRect(0, 0, width, height,5);
		outline.graphics.endFill();
		//non negative border logic.
		outline.graphics.beginFill(outlinecolor);
		//outline.graphics.drawRect(-SZ, -SZ, width, height);
		//outline.graphics.drawRoundRect(0, 0, width-2, height-4,5);
		outline.graphics.drawRoundRect(0, 0, width-WShadow, height-HShadow,5);
		outline.graphics.endFill();
		
		inner.graphics.clear();
		inner.graphics.beginFill(innercolor);
		//inner.graphics.drawRoundRect(SZ, SZ, width-SZ2, height-SZ2,5);
		//inner.graphics.drawRoundRect(SZ, SZ, (width-SZ2)-1, (height-SZ2)-2,5);
		inner.graphics.drawRoundRect(SZ, SZ, (width-SZ2)-(WShadow/2), (height-SZ2)-(HShadow/2),5);
		inner.graphics.endFill();
		
		var fillType:flash.display.GradientType = flash.display.GradientType.LINEAR;
		//var colors:Array<UInt> = [0x777777, 0xffffff];
		//var colors:Array<UInt> = [0, 0xffffff];
		var colors:Array<UInt> = [innercolor, 0xffffff];
		//var alphas = [0.06, 0.6];
		var alphas = [0.06, 0.65];
		var ratios = [0x00, 0xFF];
		var matr:flash.geom.Matrix = new flash.geom.Matrix();
		//matr.createGradientBox(50, 9, 1.57079632679, 0, -4.5);
		//matr.createGradientBox(50, height-SZ2, 1.57079632679, 0, height-SZ2);
		matr.createGradientBox(50, height-SZ2, 1.57079632679, 0, height-SZ);
		var spreadMethod:flash.display.SpreadMethod = flash.display.SpreadMethod.REFLECT;
		inner.graphics.beginGradientFill(fillType, colors, alphas, ratios, matr, spreadMethod);  
	 
		//inner.graphics.drawRoundRect(0, 0, width-SZ2, (height-SZ2)*0.65,5);
		inner.graphics.drawRoundRect(SZ, SZ, width-SZ2, (height-SZ2)*0.65,5);
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
		button.scrollRect = new Rectangle(0, 0, width+SZ, height+SZ);
		display.scrollRect = new Rectangle(SZ, SZ, width - SZ2, height - SZ2);
		display.x = SZ;
		display.y = SZ;
		
		hitbox.graphics.clear();
		hitbox.graphics.beginFill(0xFFFFFF);
		hitbox.graphics.drawRect(0, 0, width, height);
		hitbox.graphics.endFill();
		this.hitArea = hitbox;
		
	}
}