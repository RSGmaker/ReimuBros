package;
import flash.text.TextField;
import flash.text.TextFormat;

/**
 * ...
 * @author RSGmaker
 */
class TextColorizer
{
	public var text:String;
	public var colordata:Array<Dynamic>;
	public var basecolor:Int;
	public function new(basecolor:Int=-1) 
	{
		text = "";
		colordata = new Array<Dynamic>();
		this.basecolor = basecolor;
	}
	public function appendline(str:String, color:Int = -1)
	{
		if (text != "")
		{
			text = text + "\n";
		}
		append(str, color);
	}
	public function append(str:String, color:Int = -1)
	{
		if (color > -1)
		{
			var start = text.length;
			var length = str.length;
			var D:Dynamic = { };
			D.start = start;
			D.length = length;
			D.color = color;
			colordata.push(D);
		}
		text = text + str;
	}
	public function apply(textfield:TextField)
	{
		if (basecolor == -1)
		{
			basecolor = textfield.textColor;
		}
		textfield.text = text;
		textfield.textColor = basecolor;
		var i = 0;
		while (i < colordata.length)
		{
			var D = colordata[i];
			var temp = new TextFormat();
			temp.color = D.color;
			textfield.setTextFormat(temp, D.start, D.start + D.length);
			i++;
		}
	}
}