package;
import abilities.AbsorbDamage;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.DisplayObject;
import openfl.display.MovieClip;
import openfl.Assets;
import flash.display.Graphics;
import flash.geom.ColorTransform;
import openfl.display.PixelSnapping;
import openfl.display.Sprite;
import openfl.geom.Matrix;
import openfl.geom.Rectangle;

/**
 * ...
 * @author RSGmaker
 */
class CharHelper
{
	public static var Hairdata:Array<Dynamic>;
	public static var DNAdata:Array<Dynamic>;
	public static var Presets:Map <String, Int>;
	public static var HatsData:Array<Dynamic>;
	public static var BGs:Array<Dynamic>;
	public static var BackData:Array<Dynamic>;
	public static var MouthData:Array<Dynamic>;
	public static var EyesData:Array<Dynamic>;
	public static var ItemsData:Array<Dynamic>;
	public static var AccData:Array<Dynamic>;
	public static var BodyData:Array<Dynamic>;
	public static var ArmsData:Array<Dynamic>;
	public static var ShoesData:Array<Dynamic>;
	private static var spr:Sprite;
	private static var char:MovieClip;
	public var eyes:Int;
	public var mouth:Int;
	public var hat:Int;
	public var item:Int;
	public var wings:Int;
	public var accessory:Int;
	public var head:Int;
	public var body:Int;
	public var arms:Int;
	public var legs:Int;
	public var charname:String;
	public var scale:Float;
	
	public var HairColor:String;
	public var SkinColor:String;
	public var BaseDNA:String;
	public var TempDNA:String;
	public function new() 
	{
		
	}
	public function setdna(dna:String)
	{
	if (Hairdata == null)
	{
		init();
	}
	var T = dna;
    var _loc5 = T.split("-");
	var _sc = "0xFFF1DD";
	var _loc4:Array<String>;
	var _loc6=100.0;
	var _loc7=0.0;
	var _loc8=0.0;
	var _loc9=0.0;
	var _loc10=0.0;
	var _loc11=0.0;
	var _loc14=0.0;
	var _loc15;
	var _loc16:String="???";
	var _loc17:String="000000";
	var _loc18=0.0;
	var _loc19=0.0;
	var _loc20=0.0;
	var _loc21=0.0;
	
    if (_loc5.length > 1 && _loc5[0].toLowerCase() == "dna")
    {
        _loc5.shift();
        _loc15 = _loc5.join("-");
        _loc4 = _loc15.split(":");
        _loc16 = _loc4[1];
        if (_loc4[2] != null)
        {
            _loc6 = Std.parseFloat(_loc4[2]);
        }
        else
        {
            _loc6 = 100;
        } // end else if
        _loc9 = Std.parseFloat(_loc4[3]);
        _loc7 = Std.parseFloat(_loc4[4]);
		
		if (_loc4[14] != null &&_loc4[14] != "")
		{
			_sc = _loc4[14];
		}
		//FFF1DD
        if (Std.parseFloat(_loc4[0]) < 3.230000 && Std.parseFloat(_loc4[0])>=1)
        {
			_loc17 = ""+_loc4[13];
        }
        else
        {
            _loc10 = Std.parseFloat(_loc4[5]);
            _loc17 = ""+_loc4[13];
        } // end else if
        if (Std.parseFloat(_loc4[0]) < 3.200000 && Std.parseFloat(_loc4[0])>=1)
        {
            _loc8 = Std.parseFloat(_loc4[6]) + 1;
            _loc11 = Std.parseFloat(_loc4[7]) + 1;
        }
        else
        {
            _loc8 = Std.parseFloat(_loc4[6]);
            _loc11 = Std.parseFloat(_loc4[7]);
        } // end else if
        _loc20 = Std.parseFloat(_loc4[8]);
        _loc14 = Std.parseFloat(_loc4[9]);
        _loc19 = Std.parseFloat(_loc4[10]);
        _loc18 = Std.parseFloat(_loc4[11]);
        _loc21 = Std.parseFloat(_loc4[12]);
        if (_loc16 == null)
        {
            _loc16 = "Mutant Clone";
            _loc20 = 66;
            _loc14 = 36;
        }
        else
        {
            _loc20 = Std.parseFloat(_loc4[8]);
            _loc14 = Std.parseFloat(_loc4[9]);
        } // end else if
    }
			eyes = Std.int(_loc20);
			mouth = Std.int(_loc14);
			hat = Std.int(_loc9);
			item = Std.int(_loc19);
			wings = Std.int(_loc21);
			accessory = Std.int(_loc18);
			head = Std.int(_loc7);
			body = Std.int(_loc10);
			arms = Std.int(_loc8);
			legs = Std.int(_loc11);
			charname = _loc16;
			scale = _loc6;
	
			HairColor = _loc17;
			SkinColor = _sc;
			BaseDNA = generatedna();
            /*var clip = Assets.getMovieClip ("Char:Char");
			_loc14 -= 1;
			_loc19 -= 1;
			_loc21 -= 1;
			_sc = "0x" + _sc;
			
			_loc18 -= 1;
			
			var hair = Hairdata[Std.int(_loc7)];
			_loc7 = hair[1];
			var hair2 = hair[5];
			
			clip.cacheAsBitmap = true;
			var D:Dynamic = clip;
			D = clip.getChildByName("body");
			D.gotoAndStop(_loc10);
			D = clip.getChildByName("eyes");
			D.gotoAndStop(_loc20);
			D = clip.getChildByName("legs");
			D.gotoAndStop(_loc11);
			D = clip.getChildByName("hat");
			D.visible = _loc9 >= 0;
			D.gotoAndStop(_loc9);
			D = clip.getChildByName("arms");
			D.gotoAndStop(_loc8);
			D = clip.getChildByName("head");
			D.visible = _loc7 >= 0;
			D.gotoAndStop(_loc7);
			D.HairColor.gotoAndStop(_loc7);
			D.eye2.visible = false;
			D = clip.getChildByName("head2");
			D.visible = hair2 >= 0;
			D.gotoAndStop(hair2);
			D.HairColor.gotoAndStop(hair2);
			D.visible = false;
			D = clip.getChildByName("accessory");
			D.gotoAndStop(_loc18);
			D.visible = _loc18 >= 0;
			D = clip.getChildByName("wings");
			D.visible = _loc21 >= 0;
			D.gotoAndStop(_loc21);
			D = clip.getChildByName("mouth");
			D.visible = _loc14 >= 0;
			D.gotoAndStop(_loc14);
			D = clip.getChildByName("item");
			D.visible = _loc19 >= 0;
			D.gotoAndStop(_loc19);
			
			
			var colorHex = "0x" + _loc17;
			D = clip.getChildByName("head");
			ColorPalette(D.HairColor, colorHex);
			ColorPalette(D.SkinColor, _sc);
			D = clip.getChildByName("head2");
			ColorPalette(D.HairColor, colorHex);
			
			D = clip.getChildByName("arms");
			if (D.arm != null)
			{
				ColorPalette(D.arm.SkinColor, _sc);
			}
			clip.scaleX = _loc6 * 0.01;
			clip.scaleY = clip.scaleX;*/
		///return clip;

}
	public function generatedna()
	{
		//Version#:Name:Scale:Hat:Hair:Body:Arm:Shoes:Eyes:Mouth:Item:Accessory:Back:this.HairColor
		var dna = "3.40:" + charname+":" + scale+":" + hat + ":" + head + ":" + body + ":" + arms + ":" + legs + ":" + eyes + ":" + mouth + ":" + item+":" + accessory + ":" + wings + ":" + HairColor + ":" + SkinColor + ":";
		return dna;
	}
	public static function dnafromdata(eyes:Int, mouth:Int, hat:Int, item:Int, wings:Int, accessory:Int, head:Int, body:Int, arms:Int, legs:Int, charname:String,scale:Float, HairColor:String, SkinColor:String)
	{
		//Version#:Name:Scale:Hat:Hair:Body:Arm:Shoes:Eyes:Mouth:Item:Accessory:Back:this.HairColor
		var dna = "3.40:" + charname+":" + scale+":" + hat + ":" + head + ":" + body + ":" + arms + ":" + legs + ":" + eyes + ":" + mouth + ":" + item+":" + accessory + ":" + wings + ":" + HairColor + ":" + SkinColor + ":";
		return dna;
	}
	private static function init()
	{
		inithair();
		initdna();
		initbg();
		inithats();
		initwings();
		initmouth();
		initeyes();
		inititems();
		initacc();
		initbody();
		initarms();
		initshoes();
		//BodyData = new Array<Dynamic>();
	}
	private static function initshoes()
	{
		ShoesData = new Array<Dynamic>();
		ShoesData.push(["none", 0, 0, 0, 0]);
ShoesData.push(["Meiling", 1, 0, 0, 0]);
ShoesData.push(["Reimu", 2, 0, 0, 0]);
ShoesData.push(["Marisa", 3, 0, 0, 0]);
ShoesData.push(["Sakuya", 4, 0, 0, 0]);
ShoesData.push(["Yukari", 5, 0, 0, 0]);
ShoesData.push(["Flandre", 6, 0, 0, 0]);
ShoesData.push(["Yuyuko", 7, 0, 0, 0]);
ShoesData.push(["Kaguya", 8, 0, 0, 0]);
ShoesData.push(["Cirno", 9, 0, 0, 0]);
ShoesData.push(["Eirin", 10, 0, 0, 0]);
ShoesData.push(["Youmu", 11, 0, 0, 0]);
ShoesData.push(["Patchouli", 12, 0, 0, 0]);
ShoesData.push(["Alice", 13, 0, 0, 0]);
ShoesData.push(["Reisen", 14, 0, 0, 0]);
ShoesData.push(["Mokou", 15, 0, 0, 0]);
ShoesData.push(["Mystia", 16, 0, 0, 0]);
ShoesData.push(["Tewi", 17, 0, 0, 0]);
ShoesData.push(["Keine", 18, 0, 0, 0]);
ShoesData.push(["Ran", 19, 0, 0, 0]);
ShoesData.push(["Letty", 20, 0, 0, 0]);
ShoesData.push(["Chen", 21, 0, 0, 0]);
ShoesData.push(["Suika", 22, 0, 0, 0]);
ShoesData.push(["Remilia", 23, 0, 0, 0]);
ShoesData.push(["Lily White", 24, 0, 0, 0]);
ShoesData.push(["Lily Black", 25, 0, 0, 0]);
ShoesData.push(["Komachi", 26, 0, 0, 0]);
ShoesData.push(["Nitori", 27, 0, 0, 0]);
ShoesData.push(["Shikieiki", 28, 0, 0, 0]);
ShoesData.push(["Wriggle", 29, 0, 0, 0]);
ShoesData.push(["Rumia", 30, 0, 0, 0]);
ShoesData.push(["Aya", 31, 0, 0, 0]);
ShoesData.push(["Momiji", 32, 0, 0, 0]);
ShoesData.push(["Koakuma", 33, 0, 0, 0]);
ShoesData.push(["Lunasa", 34, 0, 0, 0]);
ShoesData.push(["Merlin", 35, 0, 0, 0]);
ShoesData.push(["Lyrica", 36, 0, 0, 0]);
ShoesData.push(["Daiyousei", 37, 0, 0, 0]);
ShoesData.push(["Medicine", 38, 0, 0, 0]);
ShoesData.push(["Keine (EX) ", 39, 0, 0, 0]);
ShoesData.push(["Yuka", 40, 0, 0, 0]);
ShoesData.push(["Suwako", 41, 0, 0, 0]);
ShoesData.push(["Hina", 42, 0, 0, 0]);
ShoesData.push(["Sanae", 43, 0, 0, 0]);
ShoesData.push(["Kanako", 44, 0, 0, 0]);
ShoesData.push(["Minoriko", 45, 0, 0, 0]);
ShoesData.push(["Shizuha", 46, 0, 0, 0]);
ShoesData.push(["Shinki", 47, 0, 0, 0]);
ShoesData.push(["Mima", 48, 0, 0, 0]);
ShoesData.push(["Rinnosuke", 49, 0, 0, 0]);
ShoesData.push(["Tokiko", 50, 0, 0, 0]);
ShoesData.push(["Sunny Milk", 51, 0, 0, 0]);
ShoesData.push(["Star Sapphire", 52, 0, 0, 0]);
ShoesData.push(["Luna Child", 53, 0, 0, 0]);
ShoesData.push(["Akyu", 54, 0, 0, 0]);
ShoesData.push(["Renko", 55, 0, 0, 0]);
ShoesData.push(["Maribel", 56, 0, 0, 0]);
ShoesData.push(["Chiyuri", 57, 0, 0, 0]);
ShoesData.push(["Yumemi", 58, 0, 0, 0]);
ShoesData.push(["Reimu (PC-98)", 59, 0, 0, 0]);
ShoesData.push(["Yamame", 60, 0, 0, 0]);
ShoesData.push(["Tenshi", 61, 0, 0, 0]);
ShoesData.push(["Iku", 62, 0, 0, 0]);
ShoesData.push(["Yuugi", 63, 0, 0, 0]);
ShoesData.push(["Parsee", 64, 0, 0, 0]);
ShoesData.push(["Yorihime", 65, 0, 0, 0]);
ShoesData.push(["Toyohime", 66, 0, 0, 0]);
ShoesData.push(["Marisa (PC-98)", 67, 0, 0, 0]);
ShoesData.push(["Youki", 68, 0, 0, 0]);
ShoesData.push(["Alice (PC-98)", 69, 0, 0, 0]);
ShoesData.push(["Kurumi", 70, 0, 0, 0]);
ShoesData.push(["Luize", 71, 0, 0, 0]);
ShoesData.push(["Utsuho", 72, 0, 0, 0]);
ShoesData.push(["Orin", 73, 0, 0, 0]);
ShoesData.push(["Satori", 74, 0, 0, 0]);
ShoesData.push(["Koishi", 75, 0, 0, 0]);
ShoesData.push(["Yumeko", 76, 0, 0, 0]);
ShoesData.push(["Ruukoto", 77, 0, 0, 0]);
ShoesData.push(["Mugetsu", 78, 0, 0, 0]);
ShoesData.push(["VIVIT", 79, 0, 0, 0]);
ShoesData.push(["Gengetsu", 80, 0, 0, 0]);
ShoesData.push(["Sariel", 81, 0, 0, 0]);
ShoesData.push(["Konngara", 82, 0, 0, 0]);
ShoesData.push(["Kotohime", 83, 0, 0, 0]);
ShoesData.push(["Orange", 84, 0, 0, 0]);
ShoesData.push(["Rikako", 85, 0, 0, 0]);
ShoesData.push(["Rika", 86, 0, 0, 0]);
ShoesData.push(["Yuki", 87, 0, 0, 0]);
ShoesData.push(["Mai", 88, 0, 0, 0]);
ShoesData.push(["Ellen", 89, 0, 0, 0]);
ShoesData.push(["Kana", 90, 0, 0, 0]);
ShoesData.push(["Elly", 91, 0, 0, 0]);
ShoesData.push(["Sara", 92, 0, 0, 0]);
ShoesData.push(["Meira", 93, 0, 0, 0]);
ShoesData.push(["Elis", 94, 0, 0, 0]);
ShoesData.push(["Shingyoku F", 95, 0, 0, 0]);
ShoesData.push(["Shingyoku M", 96, 0, 0, 0]);
ShoesData.push(["Yuka (PJ's)", 97, 0, 0, 0]);
ShoesData.push(["Ghost", 98, 0, 0, 0]);
ShoesData.push(["Marisa (SA)", 99, 0, 0, 0]);
ShoesData.push(["Reisen (SWR)", 100, 0, 0, 0]);
ShoesData.push(["Nazrin", 101, 0, 0, 0]);
ShoesData.push(["Kogasa", 102, 0, 0, 0]);
ShoesData.push(["Ichirin", 103, 0, 0, 0]);
ShoesData.push(["Marisa", 104, 0, 0, 0]);
ShoesData.push(["Zombie Fairy", 105, 0, 0, 0]);
ShoesData.push(["Shanghai", 106, 0, 0, 0]);
ShoesData.push(["Rin Satsuki", 107, 0, 0, 0]);
ShoesData.push(["Layla", 108, 0, 0, 0]);
ShoesData.push(["Meimu", 109, 0, 0, 0]);
ShoesData.push(["Stick Legs", 110, 0, 0, 0]);
ShoesData.push(["Sakuya (Magical)", 111, 0, 0, 0]);
ShoesData.push(["Spider", 112, 0, 0, 0]);
ShoesData.push(["Snake", 113, 0, 0, 0]);
ShoesData.push(["Fish", 114, 0, 0, 0]);
ShoesData.push(["Utsuho 2", 115, 0, 0, 0]);
ShoesData.push(["Utsuho 2 Alt", 116, 0, 0, 0]);
ShoesData.push(["Tojiko", 117, 0, 0, 0]);
ShoesData.push(["Futo", 118, 0, 0, 0]);
ShoesData.push(["Kosuzu", 119, 0, 0, 0]);
ShoesData.push(["Wakasagihime", 120, 0, 0, 0]);
ShoesData.push(["Sekibanki", 121, 0, 0, 0]);
ShoesData.push(["Kagerou", 122, 0, 0, 0]);
ShoesData.push(["Kokoro", 123, 0, 0, 0]);
ShoesData.push(["Seija", 124, 0, 0, 0]);
ShoesData.push(["Raiko", 125, 0, 0, 0]);
ShoesData.push(["Clownpiece", 126, 0, 0, 0]);

	}
	private static function initarms()
	{
		ArmsData = new Array<Dynamic>();
		ArmsData.push(["none", 0, 0, 0, 0]);
ArmsData.push(["Meiling", 1, 0, 0, 0]);
ArmsData.push(["Reimu", 2, 0, 0, 0]);
ArmsData.push(["Marisa", 3, 0, 0, 0]);
ArmsData.push(["Sakuya", 4, 0, 0, 0]);
ArmsData.push(["Yukari", 5, 0, 0, 0]);
ArmsData.push(["Flandre", 6, 0, 0, 0]);
ArmsData.push(["Yuyuko", 7, 0, 0, 0]);
ArmsData.push(["Kaguya", 8, 0, 0, 0]);
ArmsData.push(["Cirno", 9, 0, 0, 0]);
ArmsData.push(["Eirin", 10, 0, 0, 0]);
ArmsData.push(["Youmu", 11, 0, 0, 0]);
ArmsData.push(["Patchouli", 12, 0, 0, 0]);
ArmsData.push(["Alice", 13, 0, 0, 0]);
ArmsData.push(["Reisen", 14, 0, 0, 0]);
ArmsData.push(["Mokou", 15, 0, 0, 0]);
ArmsData.push(["Mystia", 16, 0, 0, 0]);
ArmsData.push(["Tewi", 17, 0, 0, 0]);
ArmsData.push(["Keine", 18, 0, 0, 0]);
ArmsData.push(["Ran", 19, 0, 0, 0]);
ArmsData.push(["Letty", 20, 0, 0, 0]);
ArmsData.push(["Chen", 21, 0, 0, 0]);
ArmsData.push(["Suika", 22, 0, 0, 0]);
ArmsData.push(["Remilia", 23, 0, 0, 0]);
ArmsData.push(["Lily White", 24, 0, 0, 0]);
ArmsData.push(["Lily Black", 25, 0, 0, 0]);
ArmsData.push(["Komachi", 26, 0, 0, 0]);
ArmsData.push(["Nitori", 27, 0, 0, 0]);
ArmsData.push(["Shikieiki", 28, 0, 0, 0]);
ArmsData.push(["Wriggle", 29, 0, 0, 0]);
ArmsData.push(["Rumia", 30, 0, 0, 0]);
ArmsData.push(["Aya", 31, 0, 0, 0]);
ArmsData.push(["Momiji", 32, 0, 0, 0]);
ArmsData.push(["Koakuma", 33, 0, 0, 0]);
ArmsData.push(["Lunasa", 34, 0, 0, 0]);
ArmsData.push(["Merlin", 35, 0, 0, 0]);
ArmsData.push(["Lyrica", 36, 0, 0, 0]);
ArmsData.push(["Daiyousei", 37, 0, 0, 0]);
ArmsData.push(["Medicine", 38, 0, 0, 0]);
ArmsData.push(["Keine (EX)", 39, 0, 0, 0]);
ArmsData.push(["Yuka", 40, 0, 0, 0]);
ArmsData.push(["Suwako", 41, 0, 0, 0]);
ArmsData.push(["Hina", 42, 0, 0, 0]);
ArmsData.push(["Sanae", 43, 0, 0, 0]);
ArmsData.push(["Kanako", 44, 0, 0, 0]);
ArmsData.push(["Minoriko", 45, 0, 0, 0]);
ArmsData.push(["Shizuha", 46, 0, 0, 0]);
ArmsData.push(["Shinki", 47, 0, 0, 0]);
ArmsData.push(["Mima", 48, 0, 0, 0]);
ArmsData.push(["Rinnosuke", 49, 0, 0, 0]);
ArmsData.push(["Tokiko", 50, 0, 0, 0]);
ArmsData.push(["Sunny Milk", 51, 0, 0, 0]);
ArmsData.push(["Star Sapphire", 52, 0, 0, 0]);
ArmsData.push(["Luna Child", 53, 0, 0, 0]);
ArmsData.push(["Akyu", 54, 0, 0, 0]);
ArmsData.push(["Renko", 55, 0, 0, 0]);
ArmsData.push(["Maribel", 56, 0, 0, 0]);
ArmsData.push(["Chiyuri", 57, 0, 0, 0]);
ArmsData.push(["Yumemi", 58, 0, 0, 0]);
ArmsData.push(["Reimu (PC-98)", 59, 0, 0, 0]);
ArmsData.push(["Yamame", 60, 0, 0, 0]);
ArmsData.push(["Tenshi", 61, 0, 0, 0]);
ArmsData.push(["Iku", 62, 0, 0, 0]);
ArmsData.push(["Yuugi", 63, 0, 0, 0]);
ArmsData.push(["Parsee", 64, 0, 0, 0]);
ArmsData.push(["Yorihime", 65, 0, 0, 0]);
ArmsData.push(["Toyohime", 66, 0, 0, 0]);
ArmsData.push(["Marisa (PC-98)", 67, 0, 0, 0]);
ArmsData.push(["Youki", 68, 0, 0, 0]);
ArmsData.push(["Alice (PC-98)", 69, 0, 0, 0]);
ArmsData.push(["Kurumi", 70, 0, 0, 0]);
ArmsData.push(["Luize", 71, 0, 0, 0]);
ArmsData.push(["Utsuho", 72, 0, 0, 0]);
ArmsData.push(["Orin", 73, 0, 0, 0]);
ArmsData.push(["Satori", 74, 0, 0, 0]);
ArmsData.push(["Koishi", 75, 0, 0, 0]);
ArmsData.push(["Yumeko", 76, 0, 0, 0]);
ArmsData.push(["Ruukoto", 77, 0, 0, 0]);
ArmsData.push(["Mugetsu", 78, 0, 0, 0]);
ArmsData.push(["VIVIT", 79, 0, 0, 0]);
ArmsData.push(["Gengetsu", 80, 0, 0, 0]);
ArmsData.push(["Sariel", 81, 0, 0, 0]);
ArmsData.push(["Konngara", 82, 0, 0, 0]);
ArmsData.push(["Kotohime", 83, 0, 0, 0]);
ArmsData.push(["Orange", 84, 0, 0, 0]);
ArmsData.push(["Rikako", 85, 0, 0, 0]);
ArmsData.push(["Rika", 86, 0, 0, 0]);
ArmsData.push(["Yuki", 87, 0, 0, 0]);
ArmsData.push(["Mai", 88, 0, 0, 0]);
ArmsData.push(["Ellen", 89, 0, 0, 0]);
ArmsData.push(["Kana", 90, 0, 0, 0]);
ArmsData.push(["Elly", 91, 0, 0, 0]);
ArmsData.push(["Sara", 92, 0, 0, 0]);
ArmsData.push(["Meira", 93, 0, 0, 0]);
ArmsData.push(["Elis", 94, 0, 0, 0]);
ArmsData.push(["Shingyoku F", 95, 0, 0, 0]);
ArmsData.push(["Shingyoku M", 96, 0, 0, 0]);
ArmsData.push(["Yuka (PJ's)", 97, 0, 0, 0]);
ArmsData.push(["Yukari (PCB)", 98, 0, 0, 0]);
ArmsData.push(["Marisa (SA)", 99, 0, 0, 0]);
ArmsData.push(["Reisen (SWR)", 100, 0, 0, 0]);
ArmsData.push(["Nazrin", 101, 0, 0, 0]);
ArmsData.push(["Kogasa", 102, 0, 0, 0]);
ArmsData.push(["Ichirin", 103, 0, 0, 0]);
ArmsData.push(["Marisa (UFO)", 104, 0, 0, 0]);
ArmsData.push(["Zombie Fairy", 105, 0, 0, 0]);
ArmsData.push(["Shanghai", 106, 0, 0, 0]);
ArmsData.push(["Rin Satsuki", 107, 0, 0, 0]);
ArmsData.push(["Layla", 108, 0, 0, 0]);
ArmsData.push(["Meimu", 109, 0, 0, 0]);
ArmsData.push(["Stick Arms", 110, 0, 0, 0]);
ArmsData.push(["Reimu (2)", 111, 0, 0, 0]);
ArmsData.push(["Yukari (IaMP)", 112, 0, 0, 0]);
ArmsData.push(["Flandre (2)", 113, 0, 0, 0]);
ArmsData.push(["Yuyuko (2)", 114, 0, 0, 0]);
ArmsData.push(["Kaguya (2)", 115, 0, 0, 0]);
ArmsData.push(["Eirin (2)", 116, 0, 0, 0]);
ArmsData.push(["Youmu (2)", 117, 0, 0, 0]);
ArmsData.push(["Patchouli (2)", 118, 0, 0, 0]);
ArmsData.push(["Alice (2)", 119, 0, 0, 0]);
ArmsData.push(["Reisen (2)", 120, 0, 0, 0]);
ArmsData.push(["Mokou (2)", 121, 0, 0, 0]);
ArmsData.push(["Mystia (2A)", 122, 0, 0, 0]);
ArmsData.push(["Mystia (2B)", 123, 0, 0, 0]);
ArmsData.push(["Tewi (2)", 124, 0, 0, 0]);
ArmsData.push(["Ran (2)", 125, 0, 0, 0]);
ArmsData.push(["Letty (2)", 126, 0, 0, 0]);
ArmsData.push(["Chen (2)", 127, 0, 0, 0]);
ArmsData.push(["Suika (2)", 128, 0, 0, 0]);
ArmsData.push(["Murasa", 129, 0, 0, 0]);
ArmsData.push(["Shou", 130, 0, 0, 0]);
ArmsData.push(["Byakuren ", 131, 0, 0, 0]);
ArmsData.push(["Byakuren (Alt)", 132, 0, 0, 0]);
ArmsData.push(["Byakuren (Alt2)", 133, 0, 0, 0]);
ArmsData.push(["Raised Arm", 134, 0, 0, 0]);
ArmsData.push(["Nue", 135, 0, 0, 0]);
ArmsData.push(["Remilia (2)", 136, 0, 0, 0]);
ArmsData.push(["Lily White (2)", 137, 0, 0, 0]);
ArmsData.push(["Lily Black (2)", 138, 0, 0, 0]);
ArmsData.push(["Komachi (2)", 139, 0, 0, 0]);
ArmsData.push(["Nitori (2)", 140, 0, 0, 0]);
ArmsData.push(["Shikieiki (2)", 141, 0, 0, 0]);
ArmsData.push(["Wriggle (2)", 142, 0, 0, 0]);
ArmsData.push(["Rumia (2)", 143, 0, 0, 0]);
ArmsData.push(["Outstretched SS", 144, 0, 0, 0]);
ArmsData.push(["Aya (2)", 145, 0, 0, 0]);
ArmsData.push(["Momiji (2)", 146, 0, 0, 0]);
ArmsData.push(["Koakuma (2)", 147, 0, 0, 0]);
ArmsData.push(["Lunasa (2)", 148, 0, 0, 0]);
ArmsData.push(["Merlin (2)", 149, 0, 0, 0]);
ArmsData.push(["Lyrica (2)", 150, 0, 0, 0]);
ArmsData.push(["Sakuya (Magical)", 151, 0, 0, 0]);
ArmsData.push(["Daiyousei (2)", 152, 0, 0, 0]);
ArmsData.push(["Medicine (2)", 153, 0, 0, 0]);
ArmsData.push(["Santa", 154, 0, 0, 0]);
ArmsData.push(["Suwako (2)", 155, 0, 0, 0]);
ArmsData.push(["Hina (2)", 156, 0, 0, 0]);
ArmsData.push(["Sanae (2)", 157, 0, 0, 0]);
ArmsData.push(["Kanako (2)", 158, 0, 0, 0]);
ArmsData.push(["Minoriko (2)", 159, 0, 0, 0]);
ArmsData.push(["Shizuha (2)", 160, 0, 0, 0]);
ArmsData.push(["Shinki (2)", 161, 0, 0, 0]);
ArmsData.push(["Utsuho (Alt)", 162, 0, 0, 0]);
ArmsData.push(["Mima (2)", 163, 0, 0, 0]);
ArmsData.push(["Rinnosuke (2)", 164, 0, 0, 0]);
ArmsData.push(["Rengeteki", 165, 0, 0, 0]);
ArmsData.push(["Rengeteki (Alt)", 166, 0, 0, 0]);
ArmsData.push(["Reimu (P2)", 167, 0, 0, 0]);
ArmsData.push(["Blue Uniform", 168, 0, 0, 0]);
ArmsData.push(["Tokiko (2)", 169, 0, 0, 0]);
ArmsData.push(["Red Trenchcoat", 170, 0, 0, 0]);
ArmsData.push(["Black Coat", 171, 0, 0, 0]);
ArmsData.push(["Sunny Milk (2)", 172, 0, 0, 0]);
ArmsData.push(["Star Sapphire (2)", 173, 0, 0, 0]);
ArmsData.push(["Hatate", 174, 0, 0, 0]);
ArmsData.push(["Luna Child (2)", 175, 0, 0, 0]);
ArmsData.push(["Akyu (2)", 176, 0, 0, 0]);
ArmsData.push(["Brown Trenchcoat", 177, 0, 0, 0]);
ArmsData.push(["Maribel (2)", 178, 0, 0, 0]);
ArmsData.push(["Teacher", 179, 0, 0, 0]);
ArmsData.push(["Yamame (2A)", 180, 0, 0, 0]);
ArmsData.push(["Wooden Gauntlets", 181, 0, 0, 0]);
ArmsData.push(["Yamame (2B)", 182, 0, 0, 0]);
ArmsData.push(["Chiyuri (2)", 183, 0, 0, 0]);
ArmsData.push(["Yumemi (2)", 184, 0, 0, 0]);
ArmsData.push(["Purple Trenchcoat", 185, 0, 0, 0]);
ArmsData.push(["Blue Uniform 2", 186, 0, 0, 0]);
ArmsData.push(["Pink Sleeves", 187, 0, 0, 0]);
ArmsData.push(["Camo (Green)", 188, 0, 0, 0]);
ArmsData.push(["Reimu (PC-98 2)", 189, 0, 0, 0]);
ArmsData.push(["Kimono (Indigo)", 190, 0, 0, 0]);
ArmsData.push(["Camo (Grey)", 191, 0, 0, 0]);
ArmsData.push(["Tenshi (2)", 192, 0, 0, 0]);
ArmsData.push(["Alice (in W)", 193, 0, 0, 0]);
ArmsData.push(["Mystia (Black)", 194, 0, 0, 0]);
ArmsData.push(["Iku (2)", 195, 0, 0, 0]);
ArmsData.push(["Green Trenchcoat", 196, 0, 0, 0]);
ArmsData.push(["Yuugi (2)", 197, 0, 0, 0]);
ArmsData.push(["Reimu (2 Alt)", 198, 0, 0, 0]);
ArmsData.push(["Red+Blue", 199, 0, 0, 0]);
ArmsData.push(["Parsee (2)", 200, 0, 0, 0]);
ArmsData.push(["Utsuho (2A)", 201, 0, 0, 0]);
ArmsData.push(["Utsuho (2B)", 202, 0, 0, 0]);
ArmsData.push(["Orin (2A)", 203, 0, 0, 0]);
ArmsData.push(["Orin (2B)", 204, 0, 0, 0]);
ArmsData.push(["Sleeveless Outstreched", 205, 0, 0, 0]);
ArmsData.push(["Long Outstreched", 206, 0, 0, 0]);
ArmsData.push(["Reimu Outstreched", 207, 0, 0, 0]);
ArmsData.push(["Short Blue", 208, 0, 0, 0]);
ArmsData.push(["Utsuho (2C)", 209, 0, 0, 0]);
ArmsData.push(["Satori (2)", 210, 0, 0, 0]);
ArmsData.push(["Short Black Sleeves", 211, 0, 0, 0]);
ArmsData.push(["Suika (2 Alt)", 212, 0, 0, 0]);
ArmsData.push(["Reimu (PC-98 2 Green)", 213, 0, 0, 0]);
ArmsData.push(["Koishi (2)", 214, 0, 0, 0]);
ArmsData.push(["Kasen", 215, 0, 0, 0]);
ArmsData.push(["Kasen (Alt)", 216, 0, 0, 0]);
ArmsData.push(["Pink Trenchcoat", 217, 0, 0, 0]);
ArmsData.push(["Mitori", 218, 0, 0, 0]);
ArmsData.push(["Kasen (Alt 2)", 219, 0, 0, 0]);
ArmsData.push(["Kasen (Alt 3)", 220, 0, 0, 0]);
ArmsData.push(["Kasen (Alt 4)", 221, 0, 0, 0]);
ArmsData.push(["Sasha", 222, 0, 0, 0]);
ArmsData.push(["Dark Green", 223, 0, 0, 0]);
ArmsData.push(["Yorihime 2A", 224, 0, 0, 0]);
ArmsData.push(["Yorihime 2B", 225, 0, 0, 0]);
ArmsData.push(["Toyohime 2", 226, 0, 0, 0]);
ArmsData.push(["Youki 2", 227, 0, 0, 0]);
ArmsData.push(["Alice (PC-98) 2", 228, 0, 0, 0]);
ArmsData.push(["Kurumi 2", 229, 0, 0, 0]);
ArmsData.push(["Marisa (PC-98) 2", 230, 0, 0, 0]);
ArmsData.push(["Luize 2", 231, 0, 0, 0]);
ArmsData.push(["Yumeko 2", 232, 0, 0, 0]);
ArmsData.push(["Ruukoto 2", 233, 0, 0, 0]);
ArmsData.push(["Mugetsu 2", 234, 0, 0, 0]);
ArmsData.push(["Gengetsu 2", 235, 0, 0, 0]);
ArmsData.push(["Sariel 2", 236, 0, 0, 0]);
ArmsData.push(["Kotohime 2", 237, 0, 0, 0]);
ArmsData.push(["Orange 2", 238, 0, 0, 0]);
ArmsData.push(["Rikako 2", 239, 0, 0, 0]);
ArmsData.push(["Yuki 2", 240, 0, 0, 0]);
ArmsData.push(["VIVIT 2", 241, 0, 0, 0]);
ArmsData.push(["Mai 2", 242, 0, 0, 0]);
ArmsData.push(["Kana 2", 243, 0, 0, 0]);
ArmsData.push(["Kimono (Gold)", 244, 0, 0, 0]);
ArmsData.push(["Elly 2", 245, 0, 0, 0]);
ArmsData.push(["Sara 2", 246, 0, 0, 0]);
ArmsData.push(["Meira 2", 247, 0, 0, 0]);
ArmsData.push(["Elis 2", 248, 0, 0, 0]);
ArmsData.push(["Shingyoku M 2", 249, 0, 0, 0]);
ArmsData.push(["Yuka (PJ's 2)", 250, 0, 0, 0]);
ArmsData.push(["Yukari (PCB 2)", 251, 0, 0, 0]);
ArmsData.push(["Kimono (Purple)", 252, 0, 0, 0]);
ArmsData.push(["Kimono (Maroon)", 253, 0, 0, 0]);
ArmsData.push(["Reimu (White)", 254, 0, 0, 0]);
ArmsData.push(["Ichirin 2", 255, 0, 0, 0]);
ArmsData.push(["Shanghai 2", 256, 0, 0, 0]);
ArmsData.push(["Reimu (Green)", 257, 0, 0, 0]);
ArmsData.push(["Kyouko", 258, 0, 0, 0]);
ArmsData.push(["Yoshika", 259, 0, 0, 0]);
ArmsData.push(["Seiga", 260, 0, 0, 0]);
ArmsData.push(["Tojiko", 261, 0, 0, 0]);
ArmsData.push(["Futo", 262, 0, 0, 0]);
ArmsData.push(["Miko", 263, 0, 0, 0]);
ArmsData.push(["Mamizou", 264, 0, 0, 0]);
ArmsData.push(["Kosuzu", 265, 0, 0, 0]);
ArmsData.push(["Kosuzu (Alt)", 266, 0, 0, 0]);
ArmsData.push(["Wakasagihime", 267, 0, 0, 0]);
ArmsData.push(["Sekibanki", 268, 0, 0, 0]);
ArmsData.push(["Kagerou", 269, 0, 0, 0]);
ArmsData.push(["Kokoro", 270, 0, 0, 0]);
ArmsData.push(["Benben", 271, 0, 0, 0]);
ArmsData.push(["Yatsuhashi", 272, 0, 0, 0]);
ArmsData.push(["Seija", 273, 0, 0, 0]);
ArmsData.push(["Shinmyoumaru", 274, 0, 0, 0]);
ArmsData.push(["Raiko", 275, 0, 0, 0]);
ArmsData.push(["Seiran", 276, 0, 0, 0]);
ArmsData.push(["Ringo", 277, 0, 0, 0]);
ArmsData.push(["Doremy", 278, 0, 0, 0]);
ArmsData.push(["Sagume", 279, 0, 0, 0]);
ArmsData.push(["Clownpiece", 280, 0, 0, 0]);
ArmsData.push(["Junko", 281, 0, 0, 0]);
ArmsData.push(["Hecatia", 282, 0, 0, 0]);

	}
	private static function initbody()
	{
		BodyData = new Array<Dynamic>();
		BodyData.push(["none", 0, 0, 0, 0]);
BodyData.push(["Meiling", 1, 0, 0, 0]);
BodyData.push(["Reimu", 2, 0, 0, 0]);
BodyData.push(["Marisa", 3, 0, 0, 0]);
BodyData.push(["Sakuya", 4, 0, 0, 0]);
BodyData.push(["Yukari", 5, 0, 0, 0]);
BodyData.push(["Flandre", 6, 0, 0, 0]);
BodyData.push(["Yuyuko", 7, 0, 0, 0]);
BodyData.push(["Kaguya", 8, 0, 0, 0]);
BodyData.push(["Cirno", 9, 0, 0, 0]);
BodyData.push(["Eirin", 10, 0, 0, 0]);
BodyData.push(["Youmu", 11, 0, 0, 0]);
BodyData.push(["Patchouli", 12, 0, 0, 0]);
BodyData.push(["Alice", 13, 0, 0, 0]);
BodyData.push(["Reisen", 14, 0, 0, 0]);
BodyData.push(["Mokou", 15, 0, 0, 0]);
BodyData.push(["Mystia", 16, 0, 0, 0]);
BodyData.push(["Tewi", 17, 0, 0, 0]);
BodyData.push(["Keine", 18, 0, 0, 0]);
BodyData.push(["Ran", 19, 0, 0, 0]);
BodyData.push(["Letty", 20, 0, 0, 0]);
BodyData.push(["Chen", 21, 0, 0, 0]);
BodyData.push(["Suika", 22, 0, 0, 0]);
BodyData.push(["Remilia", 23, 0, 0, 0]);
BodyData.push(["Lily White", 24, 0, 0, 0]);
BodyData.push(["Lily Black", 25, 0, 0, 0]);
BodyData.push(["Komachi", 26, 0, 0, 0]);
BodyData.push(["Nitori", 27, 0, 0, 0]);
BodyData.push(["Shikieiki", 28, 0, 0, 0]);
BodyData.push(["Wriggle", 29, 0, 0, 0]);
BodyData.push(["Rumia", 30, 0, 0, 0]);
BodyData.push(["Aya", 31, 0, 0, 0]);
BodyData.push(["Momiji", 32, 0, 0, 0]);
BodyData.push(["Koakuma", 33, 0, 0, 0]);
BodyData.push(["Lunasa", 34, 0, 0, 0]);
BodyData.push(["Merlin", 35, 0, 0, 0]);
BodyData.push(["Lyrica", 36, 0, 0, 0]);
BodyData.push(["Daiyousei", 37, 0, 0, 0]);
BodyData.push(["Medicine", 38, 0, 0, 0]);
BodyData.push(["Keine (EX)", 39, 0, 0, 0]);
BodyData.push(["Yuka", 40, 0, 0, 0]);
BodyData.push(["Suwako", 41, 0, 0, 0]);
BodyData.push(["Hina", 42, 0, 0, 0]);
BodyData.push(["Sanae", 43, 0, 0, 0]);
BodyData.push(["Kanako", 44, 0, 0, 0]);
BodyData.push(["Minoriko", 45, 0, 0, 0]);
BodyData.push(["Shizuha", 46, 0, 0, 0]);
BodyData.push(["Shinki", 47, 0, 0, 0]);
BodyData.push(["Mima", 48, 0, 0, 0]);
BodyData.push(["Rinnosuke", 49, 0, 0, 0]);
BodyData.push(["Tokiko", 50, 0, 0, 0]);
BodyData.push(["Sunny Milk", 51, 0, 0, 0]);
BodyData.push(["Star Sapphire", 52, 0, 0, 0]);
BodyData.push(["Luna Child", 53, 0, 0, 0]);
BodyData.push(["Akyu", 54, 0, 0, 0]);
BodyData.push(["Renko", 55, 0, 0, 0]);
BodyData.push(["Maribel", 56, 0, 0, 0]);
BodyData.push(["Chiyuri", 57, 0, 0, 0]);
BodyData.push(["Yumemi", 58, 0, 0, 0]);
BodyData.push(["Reimu (PC-98)", 59, 0, 0, 0]);
BodyData.push(["Yamame", 60, 0, 0, 0]);
BodyData.push(["Tenshi", 61, 0, 0, 0]);
BodyData.push(["Iku", 62, 0, 0, 0]);
BodyData.push(["Yuugi", 63, 0, 0, 0]);
BodyData.push(["Kisume", 64, 0, -4, -5]);
BodyData.push(["Parsee", 65, 0, 0, 0]);
BodyData.push(["Yorihime", 66, 0, 0, 0]);
BodyData.push(["Toyohime", 67, 0, 0, 0]);
BodyData.push(["Marisa (PC-98)", 68, 0, 0, 0]);
BodyData.push(["Youki", 69, 0, 0, 0]);
BodyData.push(["Alice (PC-98)", 70, 0, 0, 0]);
BodyData.push(["Kurumi", 71, 0, 0, 0]);
BodyData.push(["Luize", 72, 0, 0, 0]);
BodyData.push(["Utsuho", 73, 0, 0, 0]);
BodyData.push(["Orin", 74, 0, 0, 0]);
BodyData.push(["Satori", 75, 0, 0, 0]);
BodyData.push(["Koishi", 76, 0, 0, 0]);
BodyData.push(["Yumeko", 77, 0, 0, 0]);
BodyData.push(["Ruukoto", 78, 0, 0, 0]);
BodyData.push(["Mugetsu", 79, 0, 0, 0]);
BodyData.push(["VIVIT", 80, 0, 0, 0]);
BodyData.push(["Gengetsu", 81, 0, 0, 0]);
BodyData.push(["Sariel", 82, 0, 0, 0]);
BodyData.push(["Konngara", 83, 0, 0, 0]);
BodyData.push(["Kotohime", 84, 0, 0, 0]);
BodyData.push(["Orange", 85, 0, 0, 0]);
BodyData.push(["Rikako", 86, 0, 0, 0]);
BodyData.push(["Rika", 87, 0, 0, 0]);
BodyData.push(["Yuki", 88, 0, 0, 0]);
BodyData.push(["Mai", 89, 0, 0, 0]);
BodyData.push(["Ellen", 90, 0, 0, 0]);
BodyData.push(["Kana", 91, 0, 0, 0]);
BodyData.push(["Elly", 92, 0, 0, 0]);
BodyData.push(["Sara", 93, 0, 0, 0]);
BodyData.push(["Meira", 94, 0, 0, 0]);
BodyData.push(["Elis", 95, 0, 0, 0]);
BodyData.push(["Shingyoku F", 96, 0, 0, 0]);
BodyData.push(["Shingyoku M", 97, 0, 0, 0]);
BodyData.push(["Yuka (PJ's)", 98, 0, 0, 0]);
BodyData.push(["Yukari (PCB)", 99, 0, 0, 0]);
BodyData.push(["Marisa (SA)", 100, 0, 0, 0]);
BodyData.push(["Reisen (SWR)", 101, 0, 0, 0]);
BodyData.push(["Nazrin", 102, 0, 0, 0]);
BodyData.push(["Kogasa", 103, 0, 0, 0]);
BodyData.push(["Ichirin", 104, 0, 0, 0]);
BodyData.push(["Marisa (UFO)", 105, 0, 0, 0]);
BodyData.push(["Zombie Fairy", 106, 0, 0, 0]);
BodyData.push(["Shanghai", 107, 0, 0, 0]);
BodyData.push(["Rin Satsuki", 108, 0, 0, 0]);
BodyData.push(["Layla", 109, 0, 0, 0]);
BodyData.push(["Meimu", 110, 0, 0, 0]);
BodyData.push(["Meiling (2)", 111, 0, 0, 0]);
BodyData.push(["Lie Meiling", 112, 0, 0, 0]);
BodyData.push(["Reimu (2)", 113, 0, 0, 0]);
BodyData.push(["Marisa (PCB)", 114, 0, 0, 0]);
BodyData.push(["Sakuya (2)", 115, 0, 0, 0]);
BodyData.push(["Yukari (IaMP)", 116, 0, 0, 0]);
BodyData.push(["Flandre (2)", 117, 0, 0, 0]);
BodyData.push(["Yuyuko (2)", 118, 0, 0, 0]);
BodyData.push(["Kaguya (2)", 119, 0, 0, 0]);
BodyData.push(["Cirno (2)", 120, 0, 0, 0]);
BodyData.push(["Eirin (2)", 121, 0, 0, 0]);
BodyData.push(["Youmu (2)", 122, 0, 0, 0]);
BodyData.push(["Patchouli (2)", 123, 0, 0, 0]);
BodyData.push(["Alice (2A)", 124, 0, 0, 0]);
BodyData.push(["Alice (2B)", 125, 0, 0, 0]);
BodyData.push(["Reisen (2)", 126, 0, 0, 0]);
BodyData.push(["Mokou (2)", 127, 0, 0, 0]);
BodyData.push(["Mystia (2A)", 128, 0, 0, 0]);
BodyData.push(["Mystia (2B)", 129, 0, 0, 0]);
BodyData.push(["Tewi (2)", 130, 0, 0, 0]);
BodyData.push(["Keine (2)", 131, 0, 0, 0]);
BodyData.push(["Keine (EX2)", 132, 0, 0, 0]);
BodyData.push(["Ran (2)", 133, 0, 0, 0]);
BodyData.push(["Letty (2)", 134, 0, 0, 0]);
BodyData.push(["Chen (2)", 135, 0, 0, 0]);
BodyData.push(["Suika (2)", 136, 0, 0, 0]);
BodyData.push(["Murasa", 137, 0, 0, 0]);
BodyData.push(["Shou", 138, 0, 0, 0]);
BodyData.push(["Byakuren", 139, 0, 0, 0]);
BodyData.push(["Nue", 140, 0, 0, 0]);
BodyData.push(["Remilia (2)", 141, 0, 0, 0]);
BodyData.push(["Lily White (2)", 142, 0, 0, 0]);
BodyData.push(["Lily Black (2)", 143, 0, 0, 0]);
BodyData.push(["Komachi (2)", 144, 0, 0, 0]);
BodyData.push(["Nitori (2)", 145, 0, 0, 0]);
BodyData.push(["Plain Red", 146, 0, 0, 0]);
BodyData.push(["Shikieiki (2)", 147, 0, 0, 0]);
BodyData.push(["Wriggle (2)", 148, 0, 0, 0]);
BodyData.push(["Rumia (2)", 149, 0, 0, 0]);
BodyData.push(["Aya (2A)", 150, 0, 0, 0]);
BodyData.push(["Aya (2B)", 151, 0, 0, 0]);
BodyData.push(["Momiji (2)", 152, 0, 0, 0]);
BodyData.push(["Koakuma (2)", 153, 0, 0, 0]);
BodyData.push(["Marisa (2)", 154, 0, 0, 0]);
BodyData.push(["Lunasa (2)", 155, 0, 0, 0]);
BodyData.push(["Merlin (2)", 156, 0, 0, 0]);
BodyData.push(["Lyrica (2)", 157, 0, 0, 0]);
BodyData.push(["Sakuya (Magical)", 158, 0, 0, 0]);
BodyData.push(["Sanae (Magical)", 159, 0, 0, 0]);
BodyData.push(["Daiyousei (2)", 160, 0, 0, 0]);
BodyData.push(["EXHF", 161, 0, 0, 0]);
BodyData.push(["Medicine (2)", 162, 0, 0, 0]);
BodyData.push(["Yuka (2)", 163, 0, 0, 0]);
BodyData.push(["Santa", 164, 0, 0, 0]);
BodyData.push(["Suwako (2)", 165, 0, 0, 0]);
BodyData.push(["Hina (2)", 166, 0, 0, 0]);
BodyData.push(["Sanae (2)", 167, 0, 0, 0]);
BodyData.push(["Kanako (2)", 168, 0, 0, 0]);
BodyData.push(["Minoriko (2)", 169, 0, 0, 0]);
BodyData.push(["Shizuha (2)", 170, 0, 0, 0]);
BodyData.push(["Shinki (2)", 171, 0, 0, 0]);
BodyData.push(["Mima (2)", 172, 0, 0, 0]);
BodyData.push(["Rinnosuke (2)", 173, 0, 0, 0]);
BodyData.push(["Reimu (2P)", 174, 0, 0, 0]);
BodyData.push(["Mima (HRtP)", 175, 0, 0, 0]);
BodyData.push(["Rengeteki", 176, 0, 0, 0]);
BodyData.push(["Murasa (Alt)", 177, 0, 0, 0]);
BodyData.push(["Blue Uniform", 178, 0, 0, 0]);
BodyData.push(["Tokiko (2)", 179, 0, 0, 0]);
BodyData.push(["Coat (Black)", 180, 0, 0, 0]);
BodyData.push(["Sunny Milk (2)", 181, 0, 0, 0]);
BodyData.push(["Star Sapphire (2)", 182, 0, 0, 0]);
BodyData.push(["Alice (in W)", 183, 0, 0, 0]);
BodyData.push(["Hatate", 184, 0, 0, 0]);
BodyData.push(["Luna Child (2)", 185, 0, 0, 0]);
BodyData.push(["Reimu (EoSD)", 186, 0, 0, 0]);
BodyData.push(["Reimu (PCB)", 187, 0, 0, 0]);
BodyData.push(["Reimu (PoFV)", 188, 0, 0, 0]);
BodyData.push(["Reimu (SA)", 189, 0, 0, 0]);
BodyData.push(["Coat (Brown)", 190, 0, 0, 0]);
BodyData.push(["Maid (Black)", 191, 0, 0, 0]);
BodyData.push(["All White", 192, 0, 0, 0]);
BodyData.push(["Blue Suit", 193, 0, 0, 0]);
BodyData.push(["Akyu (2)", 194, 0, 0, 0]);
BodyData.push(["Coat (Red)", 195, 0, 0, 0]);
BodyData.push(["Renko (2)", 196, 0, 0, 0]);
BodyData.push(["Butler", 197, 0, 0, 0]);
BodyData.push(["Maribel (2)", 198, 0, 0, 0]);
BodyData.push(["Link Tunic", 199, 0, 0, 0]);
BodyData.push(["Teacher", 200, 0, 0, 0]);
BodyData.push(["Maid (Red)", 201, 0, 0, 0]);
BodyData.push(["Yamame (2)", 202, 0, 0, 0]);
BodyData.push(["Chiyuri (2)", 203, 0, 0, 0]);
BodyData.push(["Sukumizu", 204, 0, 0, 0]);
BodyData.push(["Yumemi (2)", 205, 0, 0, 0]);
BodyData.push(["Pink Dress", 206, 0, 0, 0]);
BodyData.push(["Brown Dress", 207, 0, 0, 0]);
BodyData.push(["Mystia (Black)", 208, 0, 0, 0]);
BodyData.push(["Remilia (THVania)", 209, 0, 0, 0]);
BodyData.push(["Red Overalls", 210, 0, 0, 0]);
BodyData.push(["Kimono (Blank)", 211, 0, 0, 0]);
BodyData.push(["Kimono (Pink)", 212, 0, 0, 0]);
BodyData.push(["Cirno (Fire)", 213, 0, 0, 0]);
BodyData.push(["Camo (Green)", 214, 0, 0, 0]);
BodyData.push(["Reisen Suit", 215, 0, 0, 0]);
BodyData.push(["Black Suit", 216, 0, 0, 0]);
BodyData.push(["Reimu (PC-98 2A)", 217, 0, 0, 0]);
BodyData.push(["Reimu (PC-98 2B)", 218, 0, 0, 0]);
BodyData.push(["Kimono (Indigo)", 219, 0, 0, 0]);
BodyData.push(["Camo (Grey)", 220, 0, 0, 0]);
BodyData.push(["Yuka (2 Alt)", 221, 0, 0, 0]);
BodyData.push(["Reimu (PC-98 2C)", 222, 0, 0, 0]);
BodyData.push(["Reimu (PC-98 2 Blue)", 223, 0, 0, 0]);
BodyData.push(["Tenshi (2)", 224, 0, 0, 0]);
BodyData.push(["Maid (Dark Blue)", 225, 0, 0, 0]);
BodyData.push(["Iku (2)", 226, 0, 0, 0]);
BodyData.push(["Wonderland Rabbit", 227, 0, 0, 0]);
BodyData.push(["Black", 228, 0, 0, 0]);
BodyData.push(["Suika (2 Alt)", 229, 0, 0, 0]);
BodyData.push(["Coat (Green)", 230, 0, 0, 0]);
BodyData.push(["Coat (Purple)", 231, 0, 0, 0]);
BodyData.push(["Yuugi (2)", 232, 0, 0, 0]);
BodyData.push(["Kisume (2)", 233, 0, 0, 0]);
BodyData.push(["Reimu Suit", 234, 0, 0, 0]);
BodyData.push(["Red Suit", 235, 0, 0, 0]);
BodyData.push(["China Dress", 236, 0, 0, 0]);
BodyData.push(["Parsee (2)", 237, 0, 0, 0]);
BodyData.push(["Red", 238, 0, 0, 0]);
BodyData.push(["Doctor", 239, 0, 0, 0]);
BodyData.push(["Utsuho (2)", 240, 0, 0, 0]);
BodyData.push(["Coat (Blue)", 241, 0, 0, 0]);
BodyData.push(["Coat (White)", 242, 0, 0, 0]);
BodyData.push(["Casual", 243, 0, 0, 0]);
BodyData.push(["Orin (2)", 244, 0, 0, 0]);
BodyData.push(["Black Robe", 245, 0, 0, 0]);
BodyData.push(["EE5F00", 246, 0, 0, 0]);
BodyData.push(["FFFF1A", 247, 0, 0, 0]);
BodyData.push(["71BB00", 248, 0, 0, 0]);
BodyData.push(["00BB5E", 249, 0, 0, 0]);
BodyData.push(["00A9BB", 250, 0, 0, 0]);
BodyData.push(["1AE9FF", 251, 0, 0, 0]);
BodyData.push(["1A76FF", 252, 0, 0, 0]);
BodyData.push(["91BDFF", 253, 0, 0, 0]);
BodyData.push(["AD77FF", 254, 0, 0, 0]);
BodyData.push(["893CFF", 255, 0, 0, 0]);
BodyData.push(["D83CFF", 256, 0, 0, 0]);
BodyData.push(["9D9D9D", 257, 0, 0, 0]);
BodyData.push(["6A6A6A", 258, 0, 0, 0]);
BodyData.push(["404040", 259, 0, 0, 0]);
BodyData.push(["Utsuho (Alt)", 260, 0, 0, 0]);
BodyData.push(["Blue Overalls", 261, 0, 0, 0]);
BodyData.push(["Satori (2A)", 262, 0, 0, 0]);
BodyData.push(["Satori (2B)", 263, 0, 0, 0]);
BodyData.push(["Reimu (PC-98 2 Green)", 264, 0, 0, 0]);
BodyData.push(["Alice (2B Alt Pose)", 265, 0, 0, 0]);
BodyData.push(["Koishi (2A)", 266, 0, 0, 0]);
BodyData.push(["Koishi (2B)", 267, 0, 0, 0]);
BodyData.push(["9 Jersey", 268, 0, 0, 0]);
BodyData.push(["9 Jersey (Rev)", 269, 0, 0, 0]);
BodyData.push(["Maid (Green)", 270, 0, 0, 0]);
BodyData.push(["Cirno (2 Alt)", 271, 0, 0, 0]);
BodyData.push(["Kasen", 272, 0, 0, 0]);
BodyData.push(["Coat (Pink)", 273, 0, 0, 0]);
BodyData.push(["Black Clothes", 274, 0, 0, 0]);
BodyData.push(["6 Jersey", 275, 0, 0, 0]);
BodyData.push(["6 Jersey (Rev)", 276, 0, 0, 0]);
BodyData.push(["School Uniform", 277, 0, 0, 0]);
BodyData.push(["Alice (2A Alt Pose)", 278, 0, 0, 0]);
BodyData.push(["Casual 2", 279, 0, 0, 0]);
BodyData.push(["Mitori", 280, 0, 0, 0]);
BodyData.push(["Sasha", 281, 0, 0, 0]);
BodyData.push(["Casual 3", 282, 0, 0, 0]);
BodyData.push(["Tennis Outfit 1", 283, 0, 0, 0]);
BodyData.push(["Tennis Outfit 2", 284, 0, 0, 0]);
BodyData.push(["Green Frilly Dress", 285, 0, 0, 0]);
BodyData.push(["Kimono (Maroon)", 286, 0, 0, 0]);
BodyData.push(["Yorihime (2)", 287, 0, 0, 0]);
BodyData.push(["Toyohime (2)", 288, 0, 0, 0]);
BodyData.push(["Youki (2)", 289, 0, 0, 0]);
BodyData.push(["Alice (PC-98)(2)", 290, 0, 0, 0]);
BodyData.push(["Kurumi (2)", 291, 0, 0, 0]);
BodyData.push(["Marisa (PC-98)(2)", 292, 0, 0, 0]);
BodyData.push(["Luize (2A)", 293, 0, 0, 0]);
BodyData.push(["Luize (2B)", 294, 0, 0, 0]);
BodyData.push(["Yumeko (2)", 295, 0, 0, 0]);
BodyData.push(["Ruukoto (2)", 296, 0, 0, 0]);
BodyData.push(["Casual 4", 297, 0, 0, 0]);
BodyData.push(["Mugetsu (2)", 298, 0, 0, 0]);
BodyData.push(["Gengetsu (2)", 299, 0, 0, 0]);
BodyData.push(["Sariel (2)", 300, 0, 0, 0]);
BodyData.push(["Konngara (2)", 301, 0, 0, 0]);
BodyData.push(["Rainbow Shirt", 302, 0, 0, 0]);
BodyData.push(["Kotohime (2)", 303, 0, 0, 0]);
BodyData.push(["Orange (2)", 304, 0, 0, 0]);
BodyData.push(["Rikako (2A)", 305, 0, 0, 0]);
BodyData.push(["Rikako (2B)", 306, 0, 0, 0]);
BodyData.push(["Rika (2)", 307, 0, 0, 0]);
BodyData.push(["Yuki (2)", 308, 0, 0, 0]);
BodyData.push(["VIVIT (2)", 309, 0, 0, 0]);
BodyData.push(["Kimono (Gold)", 310, 0, 0, 0]);
BodyData.push(["Akius Suit", 311, 0, 0, 0]);
BodyData.push(["Mai (2)", 312, 0, 0, 0]);
BodyData.push(["Ellen (2)", 313, 0, 0, 0]);
BodyData.push(["Kana (2)", 314, 0, 0, 0]);
BodyData.push(["Elly (2)", 315, 0, 0, 0]);
BodyData.push(["Sara (2)", 316, 0, 0, 0]);
BodyData.push(["White/black suit", 317, 0, 0, 0]);
BodyData.push(["Football Uniform", 318, 0, 0, 0]);
BodyData.push(["Football Uniform 9", 319, 0, 0, 0]);
BodyData.push(["Football Uniform 9 (rev)", 320, 0, 0, 0]);
BodyData.push(["Meira (2)", 321, 0, 0, 0]);
BodyData.push(["Elis (2)", 322, 0, 0, 0]);
BodyData.push(["Red Mushroom", 323, 0, 0, 0]);
BodyData.push(["Casual 5", 324, 0, 0, 0]);
BodyData.push(["Shingyoku F (2)", 325, 0, 0, 0]);
BodyData.push(["Shingyoku M (2)", 326, 0, 0, 0]);
BodyData.push(["White/Black Suit 2", 327, 0, 0, 0]);
BodyData.push(["White Suit", 328, 0, 0, 0]);
BodyData.push(["Kimono (Purple)", 329, 0, 0, 0]);
BodyData.push(["Yuka (PJ's 2)", 330, 0, 0, 0]);
BodyData.push(["Yukari (PCB 2)", 331, 0, 0, 0]);
BodyData.push(["White Suit 2", 332, 0, 0, 0]);
BodyData.push(["Nazrin (2)", 333, 0, 0, 0]);
BodyData.push(["Kogasa (2)", 334, 0, 0, 0]);
BodyData.push(["Reimu (White)", 335, 0, 0, 0]);
BodyData.push(["Meira (2 Alt)", 336, 0, 0, 0]);
BodyData.push(["Ichirin (2)", 337, 0, 0, 0]);
BodyData.push(["Mummy", 338, 0, 0, 0]);
BodyData.push(["Kimono (Red-White)", 339, 0, 0, 0]);
BodyData.push(["Flame Pants", 340, 0, 0, 0]);
BodyData.push(["Shanghai (2)", 341, 0, 0, 0]);
BodyData.push(["Reimu (Green)", 342, 0, 0, 0]);
BodyData.push(["Kyouko", 343, 0, 0, 0]);
BodyData.push(["Yoshika", 344, 0, 0, 0]);
BodyData.push(["Seiga", 345, 0, 0, 0]);
BodyData.push(["Tojiko", 346, 0, 0, 0]);
BodyData.push(["Futo", 347, 0, 0, 0]);
BodyData.push(["Miko", 348, 0, 0, 0]);
BodyData.push(["Miko (Alt)", 349, 0, 0, 0]);
BodyData.push(["Mamizou", 350, 0, 0, 0]);
BodyData.push(["Kosuzu", 351, 0, 0, 0]);
BodyData.push(["Ichirin (2 Alt)", 352, 0, 0, 0]);
BodyData.push(["Wakasagihime", 353, 0, 0, 0]);
BodyData.push(["Sekibanki", 354, 0, 0, 0]);
BodyData.push(["Kagerou", 355, 0, 0, 0]);
BodyData.push(["Kokoro", 356, 0, 0, 0]);
BodyData.push(["Benben", 357, 0, 0, 0]);
BodyData.push(["Yatsuhashi", 358, 0, 0, 0]);
BodyData.push(["Seija", 359, 0, 0, 0]);
BodyData.push(["Shinmyoumaru", 360, 0, 0, 0]);
BodyData.push(["Raiko", 361, 0, 0, 0]);
BodyData.push(["Seiran", 362, 0, 0, 0]);
BodyData.push(["Ringo", 363, 0, 0, 0]);
BodyData.push(["Doremy", 364, 0, 0, 0]);
BodyData.push(["Sumireko", 365, 0, 0, 0]);
BodyData.push(["Sagume", 366, 0, 0, 0]);
BodyData.push(["Clownpiece", 367, 0, 0, 0]);
BodyData.push(["Junko", 368, 0, 0, 0]);
BodyData.push(["Hecatia", 369, 0, 0, 0]);
	}
	private static function initacc()
	{
		AccData = new Array<Dynamic>();
		AccData.push(["none", 0, 0, 0, 0]);
AccData.push(["Glasses", 1, 0, 0, 0]);
AccData.push(["Monocle", 2, -6, -4, 0]);
AccData.push(["Black Mask", 3, 0, -10, 0]);
AccData.push(["Flu Mask", 4, 0, -6, 0]);
AccData.push(["Amulet", 5, 0, 8, 0]);
AccData.push(["GAR Shades", 6, 0, 0, 0]);
AccData.push(["Sun Glasses", 7, 0, 0, 0]);
AccData.push(["Rectangle Glasses", 8, 0, 0, 0]);
AccData.push(["Blush", 9, -4, -10, 6]);
AccData.push(["3D Glasses", 10, 0, 0, 0]);
AccData.push(["Knife", 11, 0, 22, 0]);
AccData.push(["Moustache", 12, 0, 0, 0]);
AccData.push(["Eye Patch", 13, 0, 3, 0]);
AccData.push(["Cross Scar", 14, 0, 0, 0]);
AccData.push(["Big Glasses 1", 15, 0, 0, 0]);
AccData.push(["Big Glasses 2", 16, 0, 0, 0]);
AccData.push(["Big Glasses 3", 17, 0, 0, 0]);
AccData.push(["Scarf (Pink)", 18, 10, -18, 0]);
AccData.push(["Knight Visor", 19, 5, 2, -5]);
AccData.push(["Melody", 20, -15, 10, -5]);
AccData.push(["Flames", 21, 8, 5, -10]);
AccData.push(["Stylish Glasses", 22, 0, -3, 0]);
AccData.push(["Happiness", 23, -5, 10, -10]);
AccData.push(["Censored", 24, 0, 0, 0]);
AccData.push(["Power Up!", 25, 10, 5, -14]);
AccData.push(["Twirly", 26, -20, 13, 0]);
AccData.push(["Wanted", 27, 11, 5, -13]);
AccData.push(["Eyebrows", 28, 0, 3, 0]);
AccData.push(["Happy Mask", 29, 0, 0, 0]);
AccData.push(["Faceguard", 30, 3, 0, -3]);
AccData.push(["Mole", 31, -5, 0, 0]);
AccData.push(["Cross Bands", 32, 10, 0, 0]);
AccData.push(["Darkness", 33, 10, 5, -15]);
AccData.push(["Crow", 34, 0, 23, 0]);
AccData.push(["Tengu Scarf 1", 35, 4, -13, -5]);
AccData.push(["Tengu Scarf 2", 36, 4, -13, -5]);
AccData.push(["Wolf Ears", 37, 2, 15, -3]);
AccData.push(["Scouter", 38, -7, 3, 0]);
AccData.push(["Gundam", 39, 5, -4, -10]);
AccData.push(["Doll", 40, 7, 23, 0]);
AccData.push(["Camo Make-up", 41, 0, -3, 0]);
AccData.push(["Clever Disguise", 42, 0, 0, 0]);
AccData.push(["Worry Brows", 43, 0, 4, 0]);
AccData.push(["Marisa", 44, -10, 10, -8]);
AccData.push(["Zap!", 45, 10, 5, -14]);
AccData.push(["Basket", 46, 4, -25, 0]);
AccData.push(["Visor", 47, 2, 10, 0]);
AccData.push(["More Glasses", 48, 0, 0, 0]);
AccData.push(["White Beard", 49, 0, -13, 0]);
AccData.push(["Bandit Mask", 50, 0, -11, 0]);
AccData.push(["Sunny", 51, -12, 7, -9]);
AccData.push(["Sweat Drop", 52, 13, 0, 0]);
AccData.push(["Toast", 53, 0, -15, 0]);
AccData.push(["Fish", 54, -3, -17, 0]);
AccData.push(["Rain Cloud", 55, -5, 12, -10]);
AccData.push(["Bandage", 56, 2, 6, 0]);
AccData.push(["Shout", 57, -7, 0, -10]);
AccData.push(["Angry Eyebrows", 58, 0, 3, 0]);
AccData.push(["Youki's Beard", 59, 0, -13, 0]);
AccData.push(["Inner Tube", 60, 0, -30, 2]);
AccData.push(["Satori's 3rd Eye", 61, 8, -2, -10]);
AccData.push(["Police Badge", 62, 0, -10, 0]);
AccData.push(["Letty's Pin", 63, 0, -10, 0]);
AccData.push(["Small Glasses", 64, 0, 0, 0]);
AccData.push(["Red Mark", 65, 0, -10, 0]);
AccData.push(["Koishi's 3rd Eye", 66, 5, -5, -10]);
AccData.push(["Smoke Pipe", 67, -5, 0, -5]);
AccData.push(["Satsuki Beads", 68, 3, 13, -5]);
AccData.push(["Advent Cirno", 69, 3, -11, -7]);
AccData.push(["Cat (Black)", 70, 6, 11, -10]);
AccData.push(["Cat (Yellow)", 71, 6, 11, -10]);
AccData.push(["Cat (White)", 72, 6, 11, -10]);
AccData.push(["Carrot charm", 73, 6, 11, -5]);
AccData.push(["Koishi's 3rd Eye 2", 74, 5, -5, -10]);
AccData.push(["Rose patch (Red)", 75, 5, -5, -5]);
AccData.push(["Rose patch (Purple)", 76, 5, -5, -5]);
AccData.push(["Pink Bow", 77, 5, -5, -5]);
AccData.push(["White Bow", 78, 5, -5, -5]);
AccData.push(["Scarf (Pink 2)", 79, 5, -5, -5]);
AccData.push(["Dog Leash", 80, 5, -5, -5]);
AccData.push(["Momiji Ears", 81, 5, 10, -5]);
AccData.push(["Ahoge", 82, 5, 10, -5]);
AccData.push(["Antennae Hair", 83, 5, 10, -5]);
AccData.push(["Cigarette", 84, 5, -5, -5]);
AccData.push(["Cigar", 85, 5, -5, -5]);
AccData.push(["Elf Ears", 86, 5, -2, -5]);
AccData.push(["Trenchcoat (Red)", 87, 5, -10, -5]);
AccData.push(["Aviator Shades", 88, 5, -2, -5]);
AccData.push(["Red Armband", 89, 5, -5, -5]);
AccData.push(["Headband+Mantle", 90, 5, -5, -5]);
AccData.push(["Anger Vein", 91, 5, 3, -5]);
AccData.push(["Wooden Armor", 92, 5, -14, -5]);
AccData.push(["Rectangle Glasses 2", 93, 5, -5, -5]);
AccData.push(["Eyepatch Flipped", 94, 5, 5, -5]);
AccData.push(["Trenchcoat (Purple)", 95, 5, -10, -5]);
AccData.push(["Handkerchief", 96, 5, -14, -5]);
AccData.push(["Kitsune Mask", 97, 5, -5, -5]);
AccData.push(["Evil Moustache", 98, 5, -4, -5]);
AccData.push(["Tewi Ears", 99, 5, 10, -5]);
AccData.push(["Reisen Ears", 100, 5, 10, -5]);
AccData.push(["Antennae", 101, 5, 10, -5]);
AccData.push(["Scarf (Red)", 102, 5, -14, -5]);
AccData.push(["Red Belt", 103, 5, -10, -5]);
AccData.push(["Red Scarf+Belt", 104, 5, -14, -5]);
AccData.push(["Collar", 105, 5, -5, -5]);
AccData.push(["Tewi Ears 2", 106, 5, 10, -5]);
AccData.push(["Reisen Ears 2", 107, 5, 10, -5]);
AccData.push(["Reisen II Ears 2", 108, 5, 10, -5]);
AccData.push(["Reisen II Ears", 109, 5, 10, -5]);
AccData.push(["Stubble", 110, 5, -5, -5]);
AccData.push(["Trenchcoat (Black)", 111, 5, -8, -5]);
AccData.push(["Jacket (Blue)", 112, 5, -14, -5]);
AccData.push(["Messenger Bag", 113, 5, -15, -5]);
AccData.push(["White Mask", 114, 5, -1, -5]);
AccData.push(["Robot Ears", 115, 5, -1, -5]);
AccData.push(["Scarf (Orange)", 116, 5, -5, -5]);
AccData.push(["Muzzle", 117, 5, -5, -5]);
AccData.push(["Mario Moustache", 118, 5, -5, -5]);
AccData.push(["Mario Moustache 2", 119, 5, -5, -5]);
AccData.push(["Night Vision 1", 120, 5, -2, -5]);
AccData.push(["Night Vision 2", 121, 5, 5, -5]);
AccData.push(["Satori's 3rd Eye 2", 122, 8, -2, -10]);
AccData.push(["Face Blush", 123, 8, -2, -10]);
AccData.push(["Aya Scarf+Ears", 124, 8, -2, -10]);
AccData.push(["Koishi's 3rd Eye 2", 125, 8, -2, -10]);
AccData.push(["Star Necklace", 126, 8, -5, -3]);
AccData.push(["Trenchcoat (White)", 127, 5, -8, -5]);
AccData.push(["Scarf (Green)", 128, 5, -5, -5]);
AccData.push(["Scarf (White)", 129, 5, -5, -5]);
AccData.push(["Aya Scarf", 130, 8, -2, -10]);
AccData.push(["Koishi's 3rd Eye 2 Open", 131, 8, -2, -10]);
AccData.push(["Shutter Shades", 132, 8, -2, -1]);
AccData.push(["Dawn Scarf", 133, 8, -2, -1]);
AccData.push(["Blue Scarf", 134, 8, -2, -1]);
AccData.push(["Pink Glasses", 135, 8, -2, -1]);
AccData.push(["Square Glasses", 136, 8, -2, -1]);
AccData.push(["Argyle Vest", 137, 8, -2, -1]);
AccData.push(["Youki's Beard 2", 138, 0, -13, 0]);
AccData.push(["Circular Glasses", 139, 0, 0, 0]);
AccData.push(["White-Rimmed Shades", 140, 0, 0, 0]);
AccData.push(["Monocle+Stache", 141, 0, 0, 0]);
AccData.push(["Monocle 2", 142, 0, 0, 0]);
AccData.push(["Tewi Ears+Tail (Black)", 143, 0, 5, 0]);
AccData.push(["Red Mark 2", 144, 0, -10, 0]);
AccData.push(["Ran's Ears", 145, 0, 15, 0]);
AccData.push(["Reisen Ears+Tail (Black)", 146, 0, 15, 0]);
AccData.push(["Red-white scarf", 147, 0, -10, 0]);
AccData.push(["Taped Mouth", 148, 0, -10, 0]);
AccData.push(["Advent Cirno (Rev)", 149, 0, -16, 0]);
AccData.push(["Tengu Mask", 150, 0, -5, -2]);
AccData.push(["Satori's 3rd Eye 2 Closed", 151, 8, -2, -10]);
AccData.push(["Yoshika Arms", 152, 0, -10, 0]);
AccData.push(["Yoshika Seal", 153, 0, 3, 0]);
AccData.push(["Miko's Sword", 154, 0, 3, 0]);
AccData.push(["Glasses (Mamizou)", 155, 0, 3, 0]);
AccData.push(["Sekibanki Cape", 156, 0, 3, 0]);
AccData.push(["Sumireko Cape", 157, 0, 3, 0]);
AccData.push(["Sumireko Cape + Glasses", 158, 0, 3, 0]);
	}
	private static function inititems()
	{
		ItemsData = new Array<Dynamic>();
		ItemsData.push(["none", 0, -20, 0, 0]);
ItemsData.push(["Miko Stick", 1, -20, 0, 0]);
ItemsData.push(["Broom", 2, 0, 0, -10]);
ItemsData.push(["Knife", 3, -20, 0, 0]);
ItemsData.push(["Gap", 4, 0, 0, 0]);
ItemsData.push(["Levatein", 5, 0, 0, 0]);
ItemsData.push(["MEAT", 6, -20, 0, 2]);
ItemsData.push(["Popsicle", 7, -20, 0, 2]);
ItemsData.push(["Pet Frog", 8, -20, -18, 0]);
ItemsData.push(["Bow", 9, 0, -2, -3]);
ItemsData.push(["Youmu Set", 10, 6, 10, -13]);
ItemsData.push(["Book", 11, -15, -15, 10]);
ItemsData.push(["Alice's Grimoire", 12, -15, -15, 10]);
ItemsData.push(["Mallet", 13, -6, 0, -5]);
ItemsData.push(["Cleaver", 14, -20, 0, 1]);
ItemsData.push(["Cell Phone", 15, -20, -10, 10]);
ItemsData.push(["Arm Cannon", 16, -20, -10, 10]);
ItemsData.push(["Pink Gloves", 17, 0, -10, 10]);
ItemsData.push(["Bunny Doll", 18, -13, -10, 1]);
ItemsData.push(["Plunger", 19, -20, 0, 0]);
ItemsData.push(["Magic Staff", 20, -13, 0, -5]);
ItemsData.push(["Sword & Shield", 21, 0, 7, -9]);
ItemsData.push(["Amulet", 22, -8, -8, 0]);
ItemsData.push(["Meat Cleaver", 23, -20, -2, 0]);
ItemsData.push(["Kite", 24, -20, 33, -5]);
ItemsData.push(["Water Gun", 25, -7, -3, -5]);
ItemsData.push(["Fork and Knife", 26, 0, -2, 0]);
ItemsData.push(["Dual Fans", 27, 0, -10, -5]);
ItemsData.push(["Mic", 28, -5, 0, 0]);
ItemsData.push(["Carrot", 29, -10, 0, 0]);
ItemsData.push(["Carrot Stick", 30, -13, 8, -5]);
ItemsData.push(["Fried Eggs", 31, -17, 3, -3]);
ItemsData.push(["Baseball Bat", 32, -22, 0, -2]);
ItemsData.push(["Truck", 33, -10, -8, 0]);
ItemsData.push(["Flames of Fury!!", 34, 0, 0, 0]);
ItemsData.push(["W-Melon Blade", 35, -8, 7, -8]);
ItemsData.push(["Suika Shackles", 36, 0, -4, 0]);
ItemsData.push(["Suika's Gourd", 37, -10, -10, 0]);
ItemsData.push(["Beer", 38, -10, -10, 0]);
ItemsData.push(["Gungnir", 39, -10, 0, -10]);
ItemsData.push(["Parasol", 40, -6, 2, -10]);
ItemsData.push(["Scythe", 41, 0, 3, -10]);
ItemsData.push(["Wrench", 42, 1, -2, -3]);
ItemsData.push(["Judgement Stick", 43, -5, -7, 0]);
ItemsData.push(["Fishing Pole", 44, -17, 8, -5]);
ItemsData.push(["Flashlight", 45, -10, 12, -15]);
ItemsData.push(["Camera", 46, -10, -5, 0]);
ItemsData.push(["Leaf Fan", 47, -10, -5, 0]);
ItemsData.push(["Momiji's Gear", 48, 0, 2, -5]);
ItemsData.push(["Tea", 49, -10, 0, 0]);
ItemsData.push(["Violin", 50, -25, 0, 0]);
ItemsData.push(["Trumpet", 51, -25, 3, 0]);
ItemsData.push(["Keyboard", 52, -25, 0, 0]);
ItemsData.push(["Flower", 53, -15, 0, 0]);
ItemsData.push(["Boxing Gloves", 54, 0, 0, 0]);
ItemsData.push(["Suzuran", 55, -15, 0, 0]);
ItemsData.push(["Another flower", 56, -5, -2, -5]);
ItemsData.push(["Sunflower", 57, -5, 3, -8]);
ItemsData.push(["Leek", 58, -18, 0, 0]);
ItemsData.push(["Sub Sandwich", 59, -15, -8, 0]);
ItemsData.push(["Spatula", 60, -15, -8, 0]);
ItemsData.push(["Crescent Staff", 61, -4, 5, -10]);
ItemsData.push(["Warhead", 62, 0, 3, -10]);
ItemsData.push(["Water Buckets", 63, 0, -8, 0]);
ItemsData.push(["Thick Book", 64, -8, -5, 0]);
ItemsData.push(["Milk", 65, -6, -5, 0]);
ItemsData.push(["Ice Cream", 66, -8, 2, 0]);
ItemsData.push(["Banana", 67, -8, -5, 0]);
ItemsData.push(["Paintbrush", 68, -5, 2, -8]);
ItemsData.push(["Scroll", 69, -2, -3, -10]);
ItemsData.push(["Dual Swords", 70, 6, 10, -13]);
ItemsData.push(["Chair", 71, -5, 0, -10]);
ItemsData.push(["Cross", 72, 0, 3, -10]);
ItemsData.push(["Staff", 73, 0, 3, -10]);
ItemsData.push(["Sanae's Stick", 74, -13, 0, 0]);
ItemsData.push(["Youmu's Sword", 75, -16, 5, -5]);
ItemsData.push(["Dark Sword", 76, -16, 5, -5]);
ItemsData.push(["Tenshi's Sword", 77, -16, 5, -5]);
ItemsData.push(["Whip", 78, -16, 0, -5]);
ItemsData.push(["Kendama", 79, -16, 0, 0]);
ItemsData.push(["Sparkler", 80, -16, 0, 0]);
ItemsData.push(["Bowl O' Sake", 81, -16, 0, 0]);
ItemsData.push(["Sariel's Staff", 82, -16, 0, 0]);
ItemsData.push(["Konngara's Sword", 83, -16, 0, 0]);
ItemsData.push(["Nightstick", 84, -16, 0, 0]);
ItemsData.push(["Mini-Hakkero", 85, -16, 0, 5]);
ItemsData.push(["Orange's Baton", 86, -16, 0, 5]);
ItemsData.push(["Test Tubes", 87, -16, 0, 5]);
ItemsData.push(["Christmas Blade", 88, -16, 0, -5]);
ItemsData.push(["NEET-hime Staff", 89, -16, 0, -5]);
ItemsData.push(["Meira's Sword", 90, -16, 0, -5]);
ItemsData.push(["Star Wand", 91, -16, 0, -4]);
ItemsData.push(["Yuka's Watch", 92, -16, 0, -4]);
ItemsData.push(["Weather Vanes", 93, -16, 0, -4]);
ItemsData.push(["Kogasa Umbrella", 94, -16, 0, -4]);
ItemsData.push(["Ichirin's Ring", 95, -16, 0, 0]);
ItemsData.push(["Marisa's Wand", 96, -16, 0, 0]);
ItemsData.push(["Erhu", 97, -16, 0, 0]);
ItemsData.push(["Claws", 98, 5, 0, 0]);
ItemsData.push(["Halberd", 99, -20, 0, 0]);
ItemsData.push(["Dipper", 100, -16, 0, 0]);
ItemsData.push(["Pagoda+Spear", 101, 5, 5, -10]);
ItemsData.push(["Jeweled Pagoda", 102, 2, 0, 0]);
ItemsData.push(["Nue's Trident 1", 103, -16, 0, 0]);
ItemsData.push(["Nue's Trident 2", 104, -13, 0, 0]);
ItemsData.push(["Scythe 2", 105, -13, 0, -10]);
ItemsData.push(["Lightsaber (Green)", 106, -24, 0, 0]);
ItemsData.push(["Lightsaber (Red)", 107, -24, 0, 0]);
ItemsData.push(["Momiji's Gear 2", 108, 0, 2, -5]);
ItemsData.push(["Knife 2", 109, -13, 0, 0]);
ItemsData.push(["Sakuya Staff", 110, -16, 0, 0]);
ItemsData.push(["Sanae Staff", 111, -16, 0, 0]);
ItemsData.push(["Broom 2", 112, 0, 2, -5]);
ItemsData.push(["Ice Sword", 113, -16, 0, 0]);
ItemsData.push(["Parasol Closed", 114, -10, 2, -5]);
ItemsData.push(["Shortsword", 115, -13, 0, 0]);
ItemsData.push(["Two-handed Sword", 116, -16, 2, -5]);
ItemsData.push(["Duster", 117, -16, 0, 0]);
ItemsData.push(["Miko Stick 2", 118, -16, 2, -5]);
ItemsData.push(["Youmu Set 2", 119, -10, 2, -5]);
ItemsData.push(["Spellcard", 120, -16, 2, -5]);
ItemsData.push(["Whip", 121, -16, 2, -5]);
ItemsData.push(["Hatate's Phone", 122, 0, 2, -5]);
ItemsData.push(["Scimitar", 123, -16, 2, -5]);
ItemsData.push(["Gun", 124, -16, 2, -5]);
ItemsData.push(["Spiked Club", 125, -16, 0, 0]);
ItemsData.push(["Syringe", 126, -16, 2, 0]);
ItemsData.push(["Chainsaw", 127, -16, 0, -3]);
ItemsData.push(["Sickle", 128, -16, 0, 0]);
ItemsData.push(["Butterfly Knife", 129, -10, 2, -5]);
ItemsData.push(["Revolver", 130, -16, 2, -5]);
ItemsData.push(["Flaming Sword", 131, -16, 5, -5]);
ItemsData.push(["Metal Fan", 132, -16, 2, -5]);
ItemsData.push(["Parasol 2", 133, -10, 2, -10]);
ItemsData.push(["Bunny Guns", 134, -16, 2, -5]);
ItemsData.push(["Spear", 135, -16, 2, -5]);
ItemsData.push(["Alice's Grimoire 2", 136, -16, 2, -5]);
ItemsData.push(["Handgun+Sword 1", 137, -16, 2, -5]);
ItemsData.push(["Handgun+Sword 2", 138, -16, 2, -5]);
ItemsData.push(["Dual Handguns", 139, -16, 2, -5]);
ItemsData.push(["Handgun", 140, -16, 2, -5]);
ItemsData.push(["Mega Buster", 141, -10, 2, -5]);
ItemsData.push(["Pom-poms", 142, -16, 2, -5]);
ItemsData.push(["Yorihime's Sword", 143, -16, 2, -5]);
ItemsData.push(["Toyohime's Fans", 144, -16, 2, -5]);
ItemsData.push(["Wristwatch (Red)", 145, 0, 2, 1]);
ItemsData.push(["Wristwatch (Blue)", 146, 0, 2, 1]);
ItemsData.push(["Third Leg (Right)", 147, 0, 2, -5]);
ItemsData.push(["Third Leg (Left)", 148, 0, 2, -5]);
ItemsData.push(["Third Leg (Both)", 149, 0, 2, -5]);
ItemsData.push(["Mega Buster (Dual)", 150, 0, 2, -5]);
ItemsData.push(["Road Sign", 151, -5, 2, -8]);
ItemsData.push(["Sanae's Stick 2", 152, -5, 2, -8]);
ItemsData.push(["Sword of some sort", 153, -5, 2, -8]);
ItemsData.push(["Kogasa Umbrella 2", 154, -16, 0, -4]);
ItemsData.push(["Miko's Shaku", 155, 0, 2, 1]);
ItemsData.push(["Miracle Mallet", 156, 0, 2, 1]);
ItemsData.push(["Drumsticks", 157, 0, 2, 1]);
ItemsData.push(["Bloody Mallet", 158, 0, 2, 1]);
ItemsData.push(["Doremy's Things", 159, 0, 2, 1]);
	}
	private static function initeyes()
	{
		EyesData = new Array<Dynamic>();
		EyesData.push(["Eye 1", 1, 0, 0, 0, 0]);
EyesData.push(["Eye 2", 2, 0, 0, 0, 0]);
EyesData.push(["Eye 3", 3, 0, 0, 0, 0]);
EyesData.push(["Eye 4", 4, 0, 0, 0, 0]);
EyesData.push(["Eye 5", 5, 0, 0, 0, 0]);
EyesData.push(["Eye 6", 6, 0, 0, 0, 0]);
EyesData.push(["Eye 7", 7, 0, 0, 0, 0]);
EyesData.push(["Eye 8", 8, 0, 0, 0, 0]);
EyesData.push(["Eye 9", 9, 0, 0, 0, 0]);
EyesData.push(["Eye 10", 10, 0, 0, 0, 0]);
EyesData.push(["Eye 11", 11, 0, 0, 0, 0]);
EyesData.push(["Eye 12", 12, 0, 0, 0, 0]);
EyesData.push(["Eye 13", 13, 0, 0, 0, 0]);
EyesData.push(["Eye 14", 14, 0, 0, 0, 0]);
EyesData.push(["Eye 15", 15, 0, 0, 0, 0]);
EyesData.push(["Eye 16", 16, 0, 0, 0, 0]);
EyesData.push(["Eye 17", 17, 0, 0, 0, 0]);
EyesData.push(["Eye 18", 18, 0, 0, 0, 0]);
EyesData.push(["Eye 19", 19, 0, 0, 0, 0]);
EyesData.push(["Eye 20", 20, 0, 0, 0, 0]);
EyesData.push(["Eye 21", 21, 0, 0, 0, 0]);
EyesData.push(["Eye 22", 22, 0, 0, 0, 0]);
EyesData.push(["Eye 23", 23, 0, 0, 0, 0]);
EyesData.push(["Eye 24", 24, 0, 0, 0, 0]);
EyesData.push(["Eye 25", 25, 0, 0, 0, 0]);
EyesData.push(["Eye 26", 26, 0, 7, 0, 1]);
EyesData.push(["Eye 27", 27, 0, 0, 0, 0]);
EyesData.push(["Eye 28", 28, 0, 0, 0, 0]);
EyesData.push(["Eye 29", 29, 0, 0, 0, 0]);
EyesData.push(["Eye 30", 30, 0, 0, 0, 0]);
EyesData.push(["Eye 31", 31, 0, 0, 0, 0]);
EyesData.push(["Eye 32", 32, 0, 0, 0, 0]);
EyesData.push(["Eye 33", 33, 0, 0, 0, 0]);
EyesData.push(["Eye 34", 34, 0, 0, 0, 0]);
EyesData.push(["Eye 35", 35, 0, 0, 0, 0]);
EyesData.push(["Eye 36", 36, 0, 0, 0, 0]);
EyesData.push(["Eye 37", 37, 0, 0, 0, 0]);
EyesData.push(["Eye 38", 38, 0, 0, 0, 0]);
EyesData.push(["Eye 39", 39, 0, 0, 0, 0]);
EyesData.push(["Eye 40", 40, 0, 0, 0, 0]);
EyesData.push(["Eye 41", 41, 0, 0, 0, 0]);
EyesData.push(["Eye 42", 42, 0, 0, 0, 0]);
EyesData.push(["Eye 43", 43, 0, 0, 0, 0]);
EyesData.push(["Eye 44", 44, 0, 0, 0, 0]);
EyesData.push(["Eye 45", 45, 0, 0, 0, 0]);
EyesData.push(["Eye 46", 46, 0, 0, 0, 0]);
EyesData.push(["Eye 47", 47, 0, 0, 0, 0]);
EyesData.push(["Eye 48", 48, 0, 0, 0, 0]);
EyesData.push(["Eye 49", 49, 0, 0, 0, 0]);
EyesData.push(["Eye 50", 50, 0, 0, 0, 0]);
EyesData.push(["Eye 51", 51, 0, 0, 0, 0]);
EyesData.push(["Eye 52", 52, 0, 0, 0, 0]);
EyesData.push(["Eye 53", 53, 0, 0, 0, 0]);
EyesData.push(["Eye 54", 54, 0, 0, 0, 0]);
EyesData.push(["Eye 55", 55, 0, 0, 0, 0]);
EyesData.push(["Eye 56", 56, 0, 0, 0, 0]);
EyesData.push(["Eye 57", 57, 0, 0, 0, 0]);
EyesData.push(["Eye 58", 58, 0, 0, 0, 0]);
EyesData.push(["Eye 59", 59, 0, 0, 0, 0]);
EyesData.push(["Eye 60", 60, 0, 0, 0, 0]);
EyesData.push(["Eye 61", 61, 0, 0, 0, 0]);
EyesData.push(["Eye 62", 62, 0, 0, 0, 0]);
EyesData.push(["Eye 63", 63, 0, 0, 0, 0]);
EyesData.push(["Eye 64", 64, 0, 0, 0, 0]);
EyesData.push(["Eye 65", 65, 0, 0, 0, 0]);
EyesData.push(["Eye 66", 66, 0, 0, 0, 0]);
EyesData.push(["Eye 67", 67, 0, 0, 0, 0]);
EyesData.push(["Eye 68", 68, 0, 0, 0, 0]);
EyesData.push(["Eye 69", 69, 0, 7, 0, 2]);
EyesData.push(["Eye 70", 70, 0, 7, 0, 3]);
EyesData.push(["Eye 71", 71, 0, 0, 0, 0]);
EyesData.push(["Eye 72", 72, 0, 7, 0, 4]);
EyesData.push(["Eye 73", 73, 0, 0, 0, 0]);
EyesData.push(["Eye 74", 74, 0, 0, 0, 0]);
EyesData.push(["Eye 75", 75, 0, 0, 0, 0]);
EyesData.push(["Eye 76", 76, 0, 0, 0, 0]);
EyesData.push(["Eye 77", 77, 0, 0, 0, 0]);
EyesData.push(["Eye 78", 78, 0, 0, 0, 0]);
EyesData.push(["Eye 79", 79, 0, 0, 0, 0]);
EyesData.push(["Eye 80", 80, 0, 0, 0, 0]);
EyesData.push(["Eye 81", 81, 0, 0, 0, 0]);
EyesData.push(["Eye 82", 82, 0, 0, 0, 0]);
EyesData.push(["Eye 83", 83, 0, 0, 0, 0]);
EyesData.push(["Eye 84", 84, 0, 0, 0, 0]);
EyesData.push(["Eye 85", 85, 0, 0, 0, 0]);
EyesData.push(["Eye 86", 86, 0, 0, 0, 0]);
EyesData.push(["Eye 87", 87, 0, 7, 0, 5]);
EyesData.push(["Eye 88", 88, 0, 0, 0, 0]);
EyesData.push(["Eye 89", 89, 0, 7, 0, 0]);
EyesData.push(["Eye 90", 90, 0, 7, 0, 0]);
EyesData.push(["Eye 91", 91, 0, 7, 0, 0]);
EyesData.push(["Eye 92", 92, 0, 7, 0, 0]);
EyesData.push(["Eye 93", 93, 0, 7, 0, 0]);
EyesData.push(["Eye 94", 94, 0, 7, 0, 0]);
EyesData.push(["Eye 95", 95, 0, 7, 0, 0]);
EyesData.push(["Eye 96", 96, 0, 7, 0, 0]);
EyesData.push(["Eye 97", 97, 0, 7, 0, 0]);
EyesData.push(["Eye 98", 98, 0, 7, 0, 6]);
EyesData.push(["Eye 99", 99, 0, 7, 0, 0]);
EyesData.push(["Eye 100", 100, 0, 7, 0, 0]);
EyesData.push(["Eye 101", 101, 0, 7, 0, 0]);
EyesData.push(["Eye 102", 102, 0, 7, 0, 0]);
EyesData.push(["Eye 103", 103, 0, 7, 0, 0]);
EyesData.push(["Eye 104", 104, 0, 7, 0, 0]);
EyesData.push(["Eye 105", 105, 0, 7, 0, 0]);
EyesData.push(["Eye 106", 106, 0, 7, 0, 0]);
EyesData.push(["Eye 107", 107, 0, 7, 0, 0]);
EyesData.push(["Eye 108", 108, 0, 7, 0, 0]);
EyesData.push(["Eye 109", 109, 0, 7, 0, 7]);
EyesData.push(["Eye 110", 110, 0, 7, 0, 0]);
EyesData.push(["Eye 111", 111, 0, 7, 0, 0]);
EyesData.push(["Eye 112", 112, 0, 7, 0, 0]);
EyesData.push(["Eye 113", 113, 0, 7, 0, 2]);
EyesData.push(["Eye 114", 114, 0, 7, 0, 0]);
EyesData.push(["Eye 115", 115, 0, 7, 0, 0]);
EyesData.push(["Eye 116", 116, 0, 7, 0, 0]);
EyesData.push(["Eye 117", 117, 0, 7, 0, 0]);
EyesData.push(["Eye 118", 118, 0, 7, 0, 0]);
EyesData.push(["Eye 119", 119, 0, 7, 0, 0]);
EyesData.push(["Eye 120", 120, 0, 7, 0, 0]);
EyesData.push(["Eye 121", 121, 0, 7, 0, 0]);
EyesData.push(["Eye 122", 122, 0, 7, 0, 0]);
EyesData.push(["Eye 123", 123, 0, 7, 0, 0]);
EyesData.push(["Eye 124", 124, 0, 7, 0, 0]);
EyesData.push(["Eye 125", 125, 0, 7, 0, 0]);
EyesData.push(["Eye 126", 126, 0, 7, 0, 0]);
EyesData.push(["Eye 127", 127, 0, 7, 0, 0]);
EyesData.push(["Eye 128", 128, 0, 7, 0, 0]);
EyesData.push(["Eye 129 (None)", 129, 0, 7, 0, 0]);
EyesData.push(["Eye 130", 130, 0, 7, 0, 0]);
EyesData.push(["Eye 131", 131, 0, 7, 0, 0]);
EyesData.push(["Eye 132", 132, 0, 7, 0, 0]);
EyesData.push(["Eye 133", 133, 0, 7, 0, 0]);
	}
	private static function initmouth()
	{
		MouthData = new Array<Dynamic>();
		MouthData.push(["none", 0, 0, 0, 0]);
MouthData.push(["Mouth 1", 1, 0, 0, 0]);
MouthData.push(["Mouth 2", 2, 0, 0, 0]);
MouthData.push(["Mouth 3", 3, 0, 0, 0]);
MouthData.push(["Mouth 4", 4, 0, 0, 0]);
MouthData.push(["Mouth 5", 5, 0, 0, 0]);
MouthData.push(["Mouth 6", 6, 0, 0, 0]);
MouthData.push(["Mouth 7", 7, 0, 0, 0]);
MouthData.push(["Mouth 8", 8, 0, 0, 0]);
MouthData.push(["Mouth 9", 9, 0, 0, 0]);
MouthData.push(["Mouth 10", 10, 0, 0, 0]);
MouthData.push(["Mouth 11", 11, 0, 0, 0]);
MouthData.push(["Mouth 12", 12, 0, 0, 0]);
MouthData.push(["Mouth 13", 13, 0, 0, 0]);
MouthData.push(["Mouth 14", 14, 0, 0, 0]);
MouthData.push(["Mouth 15", 15, 0, 0, 0]);
MouthData.push(["Mouth 16", 16, 0, 0, 0]);
MouthData.push(["Mouth 17", 17, 0, 0, 0]);
MouthData.push(["Mouth 18", 18, 0, 0, 0]);
MouthData.push(["Mouth 19", 19, 0, 0, 0]);
MouthData.push(["Mouth 20", 20, 0, 0, 0]);
MouthData.push(["Mouth 21", 21, 0, 0, 0]);
MouthData.push(["Mouth 22", 22, 0, 0, 0]);
MouthData.push(["Mouth 23", 23, 0, 0, 0]);
MouthData.push(["Mouth 24", 24, 0, 0, 0]);
MouthData.push(["Mouth 25", 25, 0, 0, 0]);
MouthData.push(["Mouth 26", 26, 0, 0, 0]);
MouthData.push(["Mouth 27", 27, 0, 0, 0]);
MouthData.push(["Mouth 28", 28, 0, 0, 0]);
MouthData.push(["Mouth 29", 29, 0, 0, 0]);
MouthData.push(["Mouth 30", 30, 0, 0, 0]);
MouthData.push(["Mouth 31", 31, 0, 0, 0]);
MouthData.push(["Mouth 32", 32, 0, 0, 0]);
MouthData.push(["Mouth 33", 33, 0, 0, 0]);
MouthData.push(["Mouth 34", 34, 0, 0, 0]);
MouthData.push(["Mouth 35", 35, 0, 0, 0]);
MouthData.push(["Mouth 36", 36, 0, 0, 0]);
MouthData.push(["Mouth 37", 37, 0, 0, 0]);
MouthData.push(["Mouth 38", 38, 0, 0, 0]);
MouthData.push(["Mouth 39", 39, 0, 0, 0]);
MouthData.push(["Mouth 40", 40, 0, 0, 0]);
MouthData.push(["Mouth 41", 41, 0, 0, 0]);
MouthData.push(["Mouth 42", 42, 0, 0, 0]);
MouthData.push(["Mouth 43", 43, 0, 0, 0]);
MouthData.push(["Mouth 44", 44, 0, 0, 0]);
MouthData.push(["Mouth 45", 45, 0, 0, 0]);
MouthData.push(["Mouth 46", 46, 0, 0, 0]);
MouthData.push(["Mouth 47", 47, 0, 0, 0]);
MouthData.push(["Mouth 48", 48, 0, 0, 0]);
MouthData.push(["Mouth 49", 49, 0, 0, 0]);
MouthData.push(["Mouth 50", 50, 0, 0, 0]);
MouthData.push(["Mouth 51", 51, 0, 0, 0]);
MouthData.push(["Mouth 52", 52, 0, 0, 0]);
MouthData.push(["Mouth 53", 53, 0, 0, 0]);
MouthData.push(["Mouth 54", 54, 0, 0, 0]);
MouthData.push(["Mouth 55", 55, 0, 0, 0]);
MouthData.push(["Mouth 56", 56, 0, 0, 0]);
MouthData.push(["Mouth 57", 57, 0, 0, 0]);
MouthData.push(["Mouth 58", 58, 0, 0, 0]);
MouthData.push(["Mouth 59", 59, 0, 0, 0]);
MouthData.push(["Mouth 60", 60, 0, 0, 0]);
MouthData.push(["Mouth 61", 61, 0, 0, 0]);
MouthData.push(["Mouth 62", 62, 0, 0, 0]);
MouthData.push(["Mouth 63", 63, 0, 0, 0]);
MouthData.push(["Mouth 64", 64, 0, 0, 0]);
MouthData.push(["Mouth 65", 65, 0, 0, 0]);
MouthData.push(["Mouth 66", 66, 0, 0, 0]);
MouthData.push(["Mouth 67", 67, 0, 0, 0]);
MouthData.push(["Mouth 68", 68, 0, 0, 0]);
MouthData.push(["Mouth 69", 69, 0, 0, 0]);
MouthData.push(["Mouth 70", 70, 0, 0, 0]);
MouthData.push(["Mouth 71", 71, 0, 0, 0]);
MouthData.push(["Mouth 72", 72, 0, 0, 0]);
MouthData.push(["Mouth 73", 73, 0, 0, 0]);
MouthData.push(["Mouth 74", 74, 0, 0, 0]);
MouthData.push(["Mouth 75", 75, 0, 0, 0]);
MouthData.push(["Mouth 76", 76, 0, 0, 0]);
MouthData.push(["Mouth 77", 77, 0, 0, 0]);
MouthData.push(["Mouth 78", 78, 0, 0, 0]);
MouthData.push(["Mouth 79", 79, 0, 0, 0]);
MouthData.push(["Mouth 80", 80, 0, 0, 0]);
MouthData.push(["Mouth 81", 81, 0, 0, 0]);
MouthData.push(["Mouth 82", 82, 0, 0, 0]);
MouthData.push(["Mouth 83", 83, 0, 0, 0]);
MouthData.push(["Mouth 84", 84, 0, 0, 0]);
MouthData.push(["Mouth 85", 85, 0, 0, 0]);
	}
	private static function initwings()
	{
		BackData = new Array<Dynamic>();
		BackData.push(["none", 0, 0, 0, 0]);
BackData.push(["Flandre's Wings", 1, 0, 0, 0]);
BackData.push(["Ice Fairy Wings", 2, 0, -10, 0]);
BackData.push(["Dark Wings", 3, 0, 0, 0]);
BackData.push(["Night Bird Wings", 4, 0, 0, 0]);
BackData.push(["Blue Bird Wings", 5, 0, 0, 0]);
BackData.push(["Pixie Wings", 6, 0, -10, 0]);
BackData.push(["Phoenix Wings", 7, 0, 0, 0]);
BackData.push(["Pink Cape", 8, 2, -10, 0]);
BackData.push(["Nine Tails", 9, 0, -10, 0]);
BackData.push(["Chen's Tails", 10, -5, -46, 10]);
BackData.push(["Remilia's Wings", 11, -5, -10, 0]);
BackData.push(["Lily Wings", 12, -3, -10, 0]);
BackData.push(["Backpack", 13, 4, -12, 2]);
BackData.push(["Wriggle Cape", 14, 4, -12, 0]);
BackData.push(["Tengu Wings", 15, 0, 0, 0]);
BackData.push(["Wolf Tail", 16, 0, -46, 10]);
BackData.push(["Devil Set", 17, 0, -10, 0]);
BackData.push(["Golden Wings", 18, 0, -5, 0]);
BackData.push(["EX-Keine's Tail", 19, -5, -85, 20]);
BackData.push(["Sacred Ring", 20, 5, 10, -5]);
BackData.push(["Shinki's Wings", 21, 7, 8, -5]);
BackData.push(["Tokiko's Wings", 22, 0, 0, 0]);
BackData.push(["Sunny Wings", 23, 3, -5, -2]);
BackData.push(["Starry Wings", 24, 3, -5, -2]);
BackData.push(["Lunar Wings", 25, 3, -5, -2]);
BackData.push(["Myon", 26, -10, 14, 0]);
BackData.push(["The Gap", 27, 0, 10, -5]);
BackData.push(["Yuyuko's Fan", 28, 0, 10, -5]);
BackData.push(["Gravity Well", 29, -10, 2, -2]);
BackData.push(["Hang Rope", 30, 0, -30, 2]);
BackData.push(["Evil Eye Sigma", 31, 15, 20, -5]);
BackData.push(["Iku's Shawl", 32, 5, 10, -5]);
BackData.push(["Kurumi's Wings", 33, 5, 10, -5]);
BackData.push(["Utsuho's Wings", 34, 5, 10, -7]);
BackData.push(["Orin's Tails", 35, -5, -46, 10]);
BackData.push(["Heart With Eye", 36, 10, 10, 5]);
BackData.push(["Gengetsu's Wings", 37, 5, 10, 0]);
BackData.push(["Sariel's Wings", 38, 5, 10, 0]);
BackData.push(["Mai's Wings", 39, 5, 10, 0]);
BackData.push(["Mima's Wings", 40, 5, 10, 0]);
BackData.push(["Elis' Wings", 41, 5, 10, 0]);
BackData.push(["Rope+Onbashiras", 42, 5, 10, 0]);
BackData.push(["Mouse Tail", 43, 5, 10, 0]);
BackData.push(["Z. Fairy Wings", 44, 5, 10, 0]);
BackData.push(["Flandre Wings 2", 45, 5, 10, 0]);
BackData.push(["Turtle Shell", 46, 5, 10, 0]);
BackData.push(["Ice Fairy Wings 2", 47, 5, 10, 0]);
BackData.push(["Phoenix Wings 2", 48, 5, 10, 0]);
BackData.push(["Mystia Wings", 49, 5, 10, 0]);
BackData.push(["Mystia Wings 2", 50, 5, 10, 0]);
BackData.push(["Rabbit Tail", 51, 5, 10, 0]);
BackData.push(["EX-Keine's Tail 2", 52, -5, -8, 0]);
BackData.push(["Ran Tails", 53, -5, -8, 0]);
BackData.push(["Transparent Cape", 54, -5, -8, 0]);
BackData.push(["Chen Tails 2", 55, -5, -8, 0]);
BackData.push(["Anchor", 56, -5, -8, 0]);
BackData.push(["Shou's Cloth", 57, -5, -8, 0]);
BackData.push(["Nue's Wings", 58, -5, -8, 0]);
BackData.push(["Remilia's Wings 2", 59, -5, -8, 0]);
BackData.push(["Lily's Wings 2", 60, -5, -8, 0]);
BackData.push(["Backpack 2", 61, -5, -8, 0]);
BackData.push(["Byakuren's Cape", 62, -5, -8, 0]);
BackData.push(["Wriggle Cape 2", 63, -5, -8, 0]);
BackData.push(["EX-Rumia Wings", 64, -5, -8, 0]);
BackData.push(["Wolf Tail 2", 65, -5, -8, 4]);
BackData.push(["Devil Set 2", 66, -5, -8, 4]);
BackData.push(["Sword", 67, -5, -8, 4]);
BackData.push(["Swords", 68, -5, -8, 4]);
BackData.push(["Wolf Tail 2A", 69, -5, -8, 4]);
BackData.push(["Golden Wings 2", 70, 0, -5, 0]);
BackData.push(["Tied Bow", 71, 0, -5, 0]);
BackData.push(["Yuka's Wings", 72, 0, -5, 0]);
BackData.push(["Sacred Ring 2", 73, 5, 10, -5]);
BackData.push(["Rope+Onbashiras 2", 74, 5, 10, 0]);
BackData.push(["Angel's Wings", 75, 0, -5, 0]);
BackData.push(["Angel's Wing", 76, 5, 10, -5]);
BackData.push(["Ice Fairy Wings 3", 77, 5, -5, 0]);
BackData.push(["Shinki's Wings 2", 78, 7, 8, -5]);
BackData.push(["Shinki's Wings White", 79, 7, 8, -5]);
BackData.push(["Mima's Wings 2A", 80, 5, -5, 0]);
BackData.push(["Mima's Wings 2B", 81, 5, -5, 0]);
BackData.push(["Rengeteki Wings", 82, 5, 10, -3]);
BackData.push(["Tokiko's Wings 2", 83, 5, -5, 0]);
BackData.push(["Rengeteki Wings 2", 84, 5, 10, -3]);
BackData.push(["Sunny Wings", 85, 5, -5, 0]);
BackData.push(["Star Wings", 86, 5, -5, 0]);
BackData.push(["Butterfly", 87, 5, -5, 0]);
BackData.push(["Butterfly (Pink)", 88, 5, -5, 0]);
BackData.push(["Butterfly (Yellow)", 89, 5, -5, 0]);
BackData.push(["Butterfly (Green)", 90, 5, -5, 0]);
BackData.push(["Butterfly (Blue)", 91, 5, -5, 0]);
BackData.push(["Luna Wings", 92, 5, -5, 0]);
BackData.push(["Nue's Wings 2", 93, 5, -3, -3]);
BackData.push(["Ragged Cape", 94, 5, -5, 0]);
BackData.push(["Ragged Cape w/ Tail", 95, 5, -5, 0]);
BackData.push(["Yumemi's Cape", 96, 5, -7, 0]);
BackData.push(["4 Bat Wings", 97, 5, -3, -3]);
BackData.push(["Pig Tail", 98, 5, -5, 0]);
BackData.push(["Fox Tail", 99, 5, -5, 0]);
BackData.push(["Fire Wings", 100, 5, -7, 0]);
BackData.push(["Jetpack", 101, 5, -7, 0]);
BackData.push(["Nazrin (Alt)", 102, 5, -7, 0]);
BackData.push(["4 Bat Wings (Alt)", 103, 5, -7, 0]);
BackData.push(["4 Angel Wings", 104, 5, -7, 0]);
BackData.push(["Iku's Shawl 2", 105, 5, 10, -5]);
BackData.push(["Kisume's Rope", 106, 5, 10, -5]);
BackData.push(["Tengu Wings 2", 107, 5, 10, -5]);
BackData.push(["Mystia Wings Blue", 108, 5, 10, -5]);
BackData.push(["Mystia Wings 2 Blue", 109, 5, 10, -5]);
BackData.push(["Utsuho's Wings 2", 110, 5, 10, -5]);
BackData.push(["Orin's Tails 2", 111, 5, 10, -5]);
BackData.push(["Tiger Tail", 112, 5, 10, -5]);
BackData.push(["Nail", 113, 5, 10, -5]);
BackData.push(["Mitori's Sign", 114, 5, 10, -5]);
BackData.push(["Utsuho's Wings 2 Alt", 115, 5, 10, -5]);
BackData.push(["Starry Cape", 116, 5, 10, -5]);
BackData.push(["Wings With Circles", 117, 5, 10, -5]);
BackData.push(["Kurumi's Wings 2", 118, 5, 10, -5]);
BackData.push(["Gengetsu's Wings 2", 119, 5, 10, -5]);
BackData.push(["Sariel's Wings 2", 120, 5, 10, -5]);
BackData.push(["Dragon Tail (Blue)", 121, 5, 10, -5]);
BackData.push(["Mai's Wings 2", 122, 5, 10, -5]);
BackData.push(["Elly's Cape", 123, 5, 10, -5]);
BackData.push(["Rabbit Tail (Black)", 124, 5, 10, -5]);
BackData.push(["Small Bat Wings", 125, 5, 10, -5]);
BackData.push(["Blue Dragon", 126, 5, 10, -5]);
BackData.push(["Blue Dragon Wings", 127, 5, 10, -5]);
BackData.push(["Green Dragon Wings", 128, 5, 10, -5]);
BackData.push(["Green Dragon", 129, 5, 10, -5]);
BackData.push(["Green Dragon Tail", 130, 5, 10, -5]);
BackData.push(["Black Dragon Wings", 131, 5, 10, -5]);
BackData.push(["Seiga Cloth", 132, 5, 10, -5]);
BackData.push(["Mamizou Tail", 133, 5, 10, -5]);
BackData.push(["Miko's Cape", 134, 5, 10, -5]);
BackData.push(["Shinmyoumaru Effects", 135, 5, 10, -5]);
BackData.push(["Raiko Drums", 136, 5, 10, -5]);
BackData.push(["Doremy Tail", 137, 5, 10, -5]);
BackData.push(["Sumireko Cape", 138, 5, 10, -5]);
BackData.push(["Sagume's Wing", 139, 5, 10, -5]);
BackData.push(["Junko Energy", 140, 5, 10, -5]);
BackData.push(["Clownpiece's Wing", 300, 5, 10, -5]);
	}
	public static function GetBG(name:String):Int
	{
		if (Hairdata == null)
		{
			init();
		}
		var i = 0;
		while (i < BGs.length)
		{
			if (BGs[i][0] == name)
			{
				return BGs[i][1];
			}
			i++;
		}
		return 0;
	}
	private static function inithats()
	{
		HatsData = new Array<Dynamic>();
		HatsData.push(["none", 0, 0, 0, 0]);
HatsData.push(["China Hat", 1, 0, 0, 0]);
HatsData.push(["Red Ribbon", 2, 0, 0, 0]);
HatsData.push(["Witch Hat", 3, 0, 0, 0]);
HatsData.push(["Sakuya Band", 4, 0, 0, 0]);
HatsData.push(["Yukari Cap", 5, 0, 0, 0]);
HatsData.push(["Flandre Cap", 6, 0, 0, 0]);
HatsData.push(["Yuyuko Cap", 7, 0, 0, 0]);
HatsData.push(["Headphones", 8, 0, -20, -5]);
HatsData.push(["Blue Ribbon", 9, 0, 0, 0]);
HatsData.push(["Eirin Hat", 10, 0, 0, 0]);
HatsData.push(["Youmu Band", 11, 0, 0, 0]);
HatsData.push(["Patchy Cap", 12, 0, 0, 0]);
HatsData.push(["Hairband", 13, 0, 0, 0]);
HatsData.push(["Reisen's Ears", 14, 0, 0, 0]);
HatsData.push(["Mokou's Bow", 15, 0, 0, 0]);
HatsData.push(["Sparrow Cap", 16, 0, 0, 0]);
HatsData.push(["Bunny Ears", 17, 0, 0, 0]);
HatsData.push(["Bento Hat", 18, 0, 0, 0]);
HatsData.push(["Ran's Cap", 19, 0, 0, 0]);
HatsData.push(["Letty's Cap", 20, 0, 0, 0]);
HatsData.push(["Chen's Cap", 21, 0, 0, 0]);
HatsData.push(["Suika's Horns", 22, 0, 0, 0]);
HatsData.push(["Remilia's Cap", 23, 0, 0, 0]);
HatsData.push(["Lily White's Cap", 24, 0, 0, 0]);
HatsData.push(["Lily Black's Cap", 25, 0, 0, 0]);
HatsData.push(["Hair Beads", 26, 0, 0, 0]);
HatsData.push(["Kappa Cap", 27, 0, 0, 0]);
HatsData.push(["Judgement Helm", 28, 0, 0, 0]);
HatsData.push(["Bug Feelers", 29, 0, 0, 0]);
HatsData.push(["Rumia's Amulet", 30, 0, 0, 0]);
HatsData.push(["Tengu Hat", 31, 0, 0, 0]);
HatsData.push(["Mini Tengu Hat", 32, 0, 0, 0]);
HatsData.push(["Devil Wings", 33, 0, 0, 0]);
HatsData.push(["Lunasa's Hat", 34, 0, 0, 0]);
HatsData.push(["Merlin's Hat", 35, 0, 0, 0]);
HatsData.push(["Lyrica's Hat", 36, 0, 0, 0]);
HatsData.push(["Yellow Ribbon", 37, 0, 0, 0]);
HatsData.push(["Medicine's Knot", 38, 0, 0, 0]);
HatsData.push(["EX-Keine's Horns", 39, 0, 0, 0]);
HatsData.push(["Top Hat", 40, 0, 0, 0]);
HatsData.push(["The Frog God", 41, 0, 0, 0]);
HatsData.push(["Hina Ribbon", 42, 0, 0, 0]);
HatsData.push(["Frog Clip", 43, 0, 0, 0]);
HatsData.push(["Rope Bandana", 44, 0, 0, 0]);
HatsData.push(["Harvest Cap", 45, 0, 0, 0]);
HatsData.push(["Maple Leaves", 46, 0, 0, 0]);
HatsData.push(["Shinki's Beads", 47, 0, 0, 0]);
HatsData.push(["Mima Cap", 48, 0, 0, 0]);
HatsData.push(["Safety Hat", 49, 0, 0, 0]);
HatsData.push(["Tokiko's Clip", 50, 0, 0, 0]);
HatsData.push(["Sunny Band", 51, 0, 0, 0]);
HatsData.push(["Star Ribbon", 52, 0, 0, 0]);
HatsData.push(["Luna Cap", 53, 0, 0, 0]);
HatsData.push(["Flower Clip", 54, 0, 0, 0]);
HatsData.push(["Fedora", 55, 0, 0, 0]);
HatsData.push(["Maribel's Cap", 56, 0, 0, 0]);
HatsData.push(["Sailor Hat", 57, 0, 0, 0]);
HatsData.push(["Summer Hat", 58, 0, 0, 0]);
HatsData.push(["Old Red Ribbon", 59, 0, 0, 0]);
HatsData.push(["Black Ribbon", 60, 0, 0, 0]);
HatsData.push(["Peach Hat", 61, 0, 0, 0]);
HatsData.push(["Iku's Hat", 62, 0, 0, 0]);
HatsData.push(["Yuugi's Horn", 63, 0, 0, 0]);
HatsData.push(["Kisume's Beads", 64, 0, 0, 0]);
HatsData.push(["Headset", 65, 0, -20, -5]);
HatsData.push(["Orange Band", 66, 0, 0, 0]);
HatsData.push(["Toyohime's Hat", 67, 0, 0, 0]);
HatsData.push(["PC-98 Witch Hat", 68, 0, 0, 0]);
HatsData.push(["Chef's Hat", 69, 0, 0, 0]);
HatsData.push(["Alice Bow (PC-98)", 70, 0, 0, 0]);
HatsData.push(["Kurumi's Bow", 71, 0, 0, 0]);
HatsData.push(["Luize's Hat", 72, 0, 0, 0]);
HatsData.push(["Utsuho's Bow", 73, 0, 0, 0]);
HatsData.push(["Orin's Cat Ears", 74, 0, 0, 0]);
HatsData.push(["Satori Band", 75, 0, 0, 0]);
HatsData.push(["Koishi's Hat", 76, 0, 0, 0]);
HatsData.push(["Yumeko Band", 77, 0, 0, 0]);
HatsData.push(["Ruukoto Band", 78, 0, 0, 0]);
HatsData.push(["Mugetsu Band", 79, 0, 0, 0]);
HatsData.push(["VIVIT Band", 80, 0, 0, 0]);
HatsData.push(["Gengetsu's Bow", 81, 0, 0, 0]);
HatsData.push(["Halo", 82, 0, 0, 0]);
HatsData.push(["Konngara's Horn", 83, 0, 0, 0]);
HatsData.push(["Police Cap", 84, 0, 0, 0]);
HatsData.push(["Orange's Hat", 85, 0, 0, 0]);
HatsData.push(["Rikako Band", 86, 0, 0, 0]);
HatsData.push(["Rika's Hat", 87, 0, 0, 0]);
HatsData.push(["Yuki's Hat", 88, 0, 0, 0]);
HatsData.push(["Mai's Bow", 89, 0, 0, 0]);
HatsData.push(["Ellen's Band", 90, 0, 0, 0]);
HatsData.push(["Kana's Hat", 91, 0, 0, 0]);
HatsData.push(["Elly's Hat", 92, 0, 0, 0]);
HatsData.push(["Orange Planet", 93, 0, 0, 0]);
HatsData.push(["Meira's Band", 94, 0, 0, 0]);
HatsData.push(["Elis' Bow", 95, 0, 0, 0]);
HatsData.push(["Shingyoku F", 96, 0, 0, 0]);
HatsData.push(["Shingyoku M", 97, 0, 0, 0]);
HatsData.push(["Yuka (PJ's)", 98, 0, 0, 0]);
HatsData.push(["Yukari Cap 2", 99, 0, 0, 0]);
HatsData.push(["Marisa Hat (SA)", 100, 0, 0, 0]);
HatsData.push(["MoonRabbit Helm", 101, 0, 0, 0]);
HatsData.push(["Mouse Ears", 102, 0, 0, 0]);
HatsData.push(["ZUN Hat", 103, 0, 0, 0]);
HatsData.push(["Ichirin's Veil", 104, 0, 0, 0]);
HatsData.push(["Marisa Hat (UFO)", 105, 0, 0, 0]);
HatsData.push(["Zombie Halo", 106, 0, 0, 0]);
HatsData.push(["Shanghai Bow", 107, 0, 0, 0]);
HatsData.push(["Motorcycle Helm", 108, 0, 0, 0]);
HatsData.push(["Meimu Bow", 109, 0, 0, 0]);
HatsData.push(["China Hat (2)", 110, 0, 0, 0]);
HatsData.push(["Lie Meiling", 111, 0, 0, 0]);
HatsData.push(["Reimu Ribbon", 112, 0, 0, 0]);
HatsData.push(["Marisa (PCB)", 113, 0, 0, 0]);
HatsData.push(["Sakuya Band 2", 114, 0, 0, 0]);
HatsData.push(["Flandre Hat 2", 115, 0, 0, 0]);
HatsData.push(["Yuyuko Hat 2", 116, 0, 0, 0]);
HatsData.push(["Cirno Bow (Blue)", 117, 0, 0, 0]);
HatsData.push(["Cirno Bow (Green)", 118, 0, 0, 0]);
HatsData.push(["Cirno Simple Bow", 119, 0, 0, 0]);
HatsData.push(["Cirno Bonnet", 120, 0, 0, 0]);
HatsData.push(["Eirin Hat 2", 121, 0, 0, 0]);
HatsData.push(["Virt.Reality Helm", 122, 0, 0, 0]);
HatsData.push(["Youmu Band 2", 123, 0, 0, 0]);
HatsData.push(["Patchy Cap 2", 124, 0, 0, 0]);
HatsData.push(["Alice Band 2", 125, 0, 0, 0]);
HatsData.push(["Reisen Ears 2", 126, 0, 0, 0]);
HatsData.push(["Mokou's Bow 2", 127, 0, 0, 0]);
HatsData.push(["Mystia Cap 2", 128, 0, 0, 0]);
HatsData.push(["Bandana", 129, 0, 0, 0]);
HatsData.push(["Tewi Ears 2", 130, 0, 0, 0]);
HatsData.push(["Bento Hat 2", 131, 0, 0, 0]);
HatsData.push(["EX Keine Horns", 132, 0, 0, 0]);
HatsData.push(["Ran Hat 2", 133, 0, 0, 0]);
HatsData.push(["Letty Hat 2", 134, 0, 0, 0]);
HatsData.push(["Chen Hat 2", 135, 0, 0, 0]);
HatsData.push(["Suika Horns 2", 136, 0, 0, 0]);
HatsData.push(["Murasa's Cap", 137, 0, 0, 0]);
HatsData.push(["Shou's Ornament", 138, 0, 0, 0]);
HatsData.push(["Remilia's Hat 2", 139, 0, 0, 0]);
HatsData.push(["Lily White Hat 2", 140, 0, 0, 0]);
HatsData.push(["Lily Black Hat 2", 141, 0, 0, 0]);
HatsData.push(["Komachi Beads 2", 142, 0, 0, 0]);
HatsData.push(["Kappa Cap 2", 143, 0, 0, 0]);
HatsData.push(["Judgement Helm 2", 144, 0, 0, 0]);
HatsData.push(["Antennae", 145, 0, 0, 0]);
HatsData.push(["Rumia's Amulet 2", 146, 0, 0, 0]);
HatsData.push(["Tengu Hat 2A", 147, 0, 0, 0]);
HatsData.push(["Tengu Hat 2B", 148, 0, 0, 0]);
HatsData.push(["Momiji Hat+Ears", 149, 0, 0, 0]);
HatsData.push(["Devil Wings 2", 150, 0, 0, 0]);
HatsData.push(["Witch Hat 2", 151, 0, 0, 0]);
HatsData.push(["Lunasa's Hat 2", 152, 0, 0, 0]);
HatsData.push(["Merlin's Hat 2", 153, 0, 0, 0]);
HatsData.push(["Lyrica's Hat 2", 154, 0, 0, 0]);
HatsData.push(["Sanae (Magical)", 155, 0, 0, 0]);
HatsData.push(["Yellow Ribbon 2", 156, 0, 0, 0]);
HatsData.push(["Medicine's Knot 2", 157, 0, 0, 0]);
HatsData.push(["Santa Hat", 158, 0, 0, 0]);
HatsData.push(["The Frog God 2", 159, 0, 0, 0]);
HatsData.push(["Hina Ribbon 2A", 160, 0, 0, 0]);
HatsData.push(["Frog Clip 2", 161, 0, 0, 0]);
HatsData.push(["Gas Mask", 162, 0, 0, 0]);
HatsData.push(["Rope Bandana 2", 163, 0, 0, 0]);
HatsData.push(["Hina Ribbon 2B", 164, 0, 0, 0]);
HatsData.push(["Green Bandana", 165, 0, 0, 0]);
HatsData.push(["Balaclava", 166, 0, 0, 0]);
HatsData.push(["Harvest Cap 2", 167, 0, 0, 0]);
HatsData.push(["InuSakuya", 168, 0, 0, 0]);
HatsData.push(["Maple Leaves 2", 169, 0, 0, 0]);
HatsData.push(["Black Band", 170, 0, 0, 0]);
HatsData.push(["Shinki's Beads 2", 171, 0, 0, 0]);
HatsData.push(["Darth Vader Helm", 172, 0, 0, 0]);
HatsData.push(["Mima Cap 2", 173, 0, 0, 0]);
HatsData.push(["Mima Cap 2 (Mima)", 174, 0, 0, 0]);
HatsData.push(["Dunce Cap", 175, 0, 0, 0]);
HatsData.push(["MGS Cyborg-Ninja", 176, 0, 0, 0]);
HatsData.push(["MGS Cyborg-Ninja 2", 177, 0, 0, 0]);
HatsData.push(["Reimu Ribbon 2P", 178, 0, 0, 0]);
HatsData.push(["Straw Hat", 179, 0, 0, 0]);
HatsData.push(["Ushanka", 180, 0, 0, 0]);
HatsData.push(["Rengeteki Bow", 181, 0, 0, 0]);
HatsData.push(["Panda Beanie", 182, 0, 0, 0]);
HatsData.push(["Football Helmet", 183, 0, 0, 0]);
HatsData.push(["Wedding Veil", 184, 0, 0, 0]);
HatsData.push(["Motorcycle Helm 2", 185, 0, 0, 0]);
HatsData.push(["Ran's Ears", 186, 0, 0, 0]);
HatsData.push(["Chen's Ears", 187, 0, 0, 0]);
HatsData.push(["Tokiko's Clip 2", 188, 0, 0, 0]);
HatsData.push(["Sunny Band 2", 189, 0, 0, 0]);
HatsData.push(["Momiji Ears", 190, 0, 0, 0]);
HatsData.push(["Mettaur (Yellow)", 191, 0, 0, 0]);
HatsData.push(["Mettaur (Blue)", 192, 0, 0, 0]);
HatsData.push(["Mettaur (Red)", 193, 0, 0, 0]);
HatsData.push(["Miner's Helm", 194, 0, 0, 0]);
HatsData.push(["Star Ribbon 2", 195, 0, 0, 0]);
HatsData.push(["Trilby Hat (Black)", 196, 0, 0, 0]);
HatsData.push(["Trilby Hat (Brown)", 197, 0, 0, 0]);
HatsData.push(["Ram horns", 198, 0, 0, 0]);
HatsData.push(["Hatate Tokin", 199, 0, 0, 0]);
HatsData.push(["Luna Cap 2", 200, 0, 0, 0]);
HatsData.push(["Jason Mask", 201, 0, 0, 0]);
HatsData.push(["Cabbie Hat", 202, 0, 0, 0]);
HatsData.push(["Baseball Cap", 203, 0, 0, 0]);
HatsData.push(["Red Bandana", 204, 0, 0, 0]);
HatsData.push(["Bowler Hat", 205, 0, 0, 0]);
HatsData.push(["Tied Headband", 206, 0, 0, 0]);
HatsData.push(["Paper Bag", 207, 0, 0, 0]);
HatsData.push(["Flower Clip 2", 208, 0, 0, 0]);
HatsData.push(["Bandana+Patch", 209, 0, 0, 0]);
HatsData.push(["Fedora 2", 210, 0, 0, 0]);
HatsData.push(["Maribel's Cap 2", 211, 0, 0, 0]);
HatsData.push(["Moonrabbit helm 2", 212, 0, 0, 0]);
HatsData.push(["Link Hat", 213, 0, 0, 0]);
HatsData.push(["Kotone Hat", 214, 0, 0, 0]);
HatsData.push(["Black Ribbon 2", 215, 0, 0, 0]);
HatsData.push(["Sailor Hat 2", 216, 0, 0, 0]);
HatsData.push(["Mystia (Black)", 217, 0, 0, 0]);
HatsData.push(["Butterfly Crown", 218, 0, 0, 0]);
HatsData.push(["Keine (Alt)", 219, 0, 0, 0]);
HatsData.push(["Kitsune Mask", 220, 0, 0, 0]);
HatsData.push(["Tall Hat", 221, 0, 0, 0]);
HatsData.push(["Ghost Triangle", 222, 0, 0, 0]);
HatsData.push(["Cirno (Fire)", 223, 0, 0, 0]);
HatsData.push(["Pirate", 224, 0, 0, 0]);
HatsData.push(["Beret (Black)", 225, 0, 0, 0]);
HatsData.push(["Beret (Green)", 226, 0, 0, 0]);
HatsData.push(["Army Helm (Camo)", 227, 0, 0, 0]);
HatsData.push(["Army Helm (Grey)", 228, 0, 0, 0]);
HatsData.push(["Old Red Ribbon 2", 229, 0, 0, 0]);
HatsData.push(["Butterfly Crown 2", 230, 0, 0, 0]);
HatsData.push(["Suika Horns (Alt)", 231, 0, 0, 0]);
HatsData.push(["Tie (Red)", 232, 0, 0, 0]);
HatsData.push(["Crown", 233, 0, 0, 0]);
HatsData.push(["Lampshade", 234, 0, 0, 0]);
HatsData.push(["Tied Headband (Yellow)", 235, 0, 0, 0]);
HatsData.push(["Peach Hat 2", 236, 0, 0, 0]);
HatsData.push(["Mushroom Cap", 237, 0, 0, 0]);
HatsData.push(["Reimu (2 Alt)", 238, 0, 0, 0]);
HatsData.push(["White Band", 239, 0, 0, 0]);
HatsData.push(["Yellow Band", 240, 0, 0, 0]);
HatsData.push(["Snorkel", 241, 0, 0, 0]);
HatsData.push(["Knight Helm", 242, 0, 0, 0]);
HatsData.push(["Reisen II Ears", 243, 0, 0, 0]);
HatsData.push(["Iku's Hat", 244, 0, 0, 0]);
HatsData.push(["Mima Bandana", 245, 0, 0, 0]);
HatsData.push(["Mima Bandana 2", 246, 0, 0, 0]);
HatsData.push(["Aviator Hat", 247, 0, 0, 0]);
HatsData.push(["Towel", 248, 0, 0, 0]);
HatsData.push(["Tie (Yellow)", 249, 0, 0, 0]);
HatsData.push(["Yuugi's Horn 2", 250, 0, 0, 0]);
HatsData.push(["Red Mushroom Cap", 251, 0, 0, 0]);
HatsData.push(["Red Mushroom", 252, 0, 0, 0]);
HatsData.push(["Aviator Goggles", 253, 0, 0, 0]);
HatsData.push(["Mario", 254, 0, 0, 0]);
HatsData.push(["Luigi", 255, 0, 0, 0]);
HatsData.push(["Utsuho's Bow 2", 256, 0, 0, 0]);
HatsData.push(["Megaman Helmet", 257, 0, 0, 0]);
HatsData.push(["Orin's Cat Ears 2", 258, 0, 0, 0]);
HatsData.push(["Jester Hat", 259, 0, 0, 0]);
HatsData.push(["Black Hood", 260, 0, 0, 0]);
HatsData.push(["Tiger Ears", 261, 0, 0, 0]);
HatsData.push(["Baseball Cap (Green)", 262, 0, 0, 0]);
HatsData.push(["Baseball Cap (Orange)", 263, 0, 0, 0]);
HatsData.push(["Baseball Cap (Red)", 264, 0, 0, 0]);
HatsData.push(["Satori Band 2", 265, 0, 0, 0]);
HatsData.push(["Toeto", 266, 0, 0, 0]);
HatsData.push(["Shou's Ornament 2", 267, 0, 0, 0]);
HatsData.push(["Old Green Ribbon", 268, 0, 0, 0]);
HatsData.push(["Baseball Cap Back", 269, 0, 0, 0]);
HatsData.push(["Koishi's Hat 2", 270, 0, 0, 0]);
HatsData.push(["Fez", 271, 0, 0, 0]);
HatsData.push(["Samus", 272, 0, 0, 0]);
HatsData.push(["Hair buns", 273, 0, 0, 0]);
HatsData.push(["Puyo Hat", 274, 0, 0, 0]);
HatsData.push(["Four Horns", 275, 0, 0, 0]);
HatsData.push(["Cabbie Hat (Blue)", 276, 0, 0, 0]);
HatsData.push(["Mitori's Hat", 277, 0, 0, 0]);
HatsData.push(["Lan Headband", 278, 0, 0, 0]);
HatsData.push(["Sombrero", 279, 0, 0, 0]);
HatsData.push(["Box Hat", 280, 0, 0, 0]);
HatsData.push(["Fedora (no bow)", 281, 0, 0, 0]);
HatsData.push(["Beret (Brown)", 282, 0, 0, 0]);
HatsData.push(["Cabbie Hat (Brown)", 283, 0, 0, 0]);
HatsData.push(["Orange Band 2", 284, 0, 0, 0]);
HatsData.push(["Toyohime's Hat 2", 285, 0, 0, 0]);
HatsData.push(["Alice Bow (PC-98) 2", 286, 0, 0, 0]);
HatsData.push(["Kurumi's Bow 2", 287, 0, 0, 0]);
HatsData.push(["PC-98 Witch Hat 2", 288, 0, 0, 0]);
HatsData.push(["Luize's Hat 2", 289, 0, 0, 0]);
HatsData.push(["Yumeko Band 2", 290, 0, 0, 0]);
HatsData.push(["Ruukoto Band 2", 291, 0, 0, 0]);
HatsData.push(["Party Hat", 292, 0, 0, 0]);
HatsData.push(["Mugetsu Band 2", 293, 0, 0, 0]);
HatsData.push(["Gengetsu's Bow 2", 294, 0, 0, 0]);
HatsData.push(["Konngara's Horn 2", 295, 0, 0, 0]);
HatsData.push(["Top Hat (Pink)", 296, 0, 0, 0]);
HatsData.push(["Bow (Purple)", 297, 0, 0, 0]);
HatsData.push(["Bow (Yellow)", 298, 0, 0, 0]);
HatsData.push(["Orange's Hat 2", 299, 0, 0, 0]);
HatsData.push(["Rikako Band 2", 300, 0, 0, 0]);
HatsData.push(["Top Hat w/ Horns", 301, 0, 0, 0]);
HatsData.push(["Rika's Hat 2", 302, 0, 0, 0]);
HatsData.push(["Yuki's Hat 2", 303, 0, 0, 0]);
HatsData.push(["VIVIT Band 2", 304, 0, 0, 0]);
HatsData.push(["Suika Horns (Alt2)", 305, 0, 0, 0]);
HatsData.push(["Mai's Bow 2", 306, 0, 0, 0]);
HatsData.push(["Ellen's Band 2", 307, 0, 0, 0]);
HatsData.push(["Kana's Hat 2", 308, 0, 0, 0]);
HatsData.push(["Elly's Hat 2", 309, 0, 0, 0]);
HatsData.push(["Rabbit Ears (Black)", 310, 0, 0, 0]);
HatsData.push(["Cabbie Hat (Red)", 311, 0, 0, 0]);
HatsData.push(["Headphones (Red-White)", 312, 0, 0, 0]);
HatsData.push(["Meira's Band 2", 313, 0, 0, 0]);
HatsData.push(["Elis' Bow 2", 314, 0, 0, 0]);
HatsData.push(["Trilby Hat (White)", 315, 0, 0, 0]);
HatsData.push(["Reisen Ears (black)", 316, 0, 0, 0]);
HatsData.push(["Shingyoku F 2", 317, 0, 0, 0]);
HatsData.push(["Shingyoku M 2", 318, 0, 0, 0]);
HatsData.push(["Yuka (PJ's) 2", 319, 0, 0, 0]);
HatsData.push(["Yukari Cap 3", 320, 0, 0, 0]);
HatsData.push(["Mouse Ears 2", 321, 0, 0, 0]);
HatsData.push(["Reimu Ribbon (White)", 322, 0, 0, 0]);
HatsData.push(["Reimu Ribbon (White 2)", 323, 0, 0, 0]);
HatsData.push(["Ichirin's Veil 2", 324, 0, 0, 0]);
HatsData.push(["Tengu Mask", 325, 0, 0, 0]);
HatsData.push(["Shanghai Bow 2", 326, 0, 0, 0]);
HatsData.push(["Reimu Ribbon (Green)", 327, 0, 0, 0]);
HatsData.push(["Kyouko Ears 1", 328, 0, 0, 0]);
HatsData.push(["Kyouko Ears 2", 329, 0, 0, 0]);
HatsData.push(["Yoshika Hat", 330, 0, 0, 0]);
HatsData.push(["Yoshika Hat+", 331, 0, 5, 0]);
HatsData.push(["Yoshika Seal", 332, 0, -10, 0]);
HatsData.push(["Seiga Hair Stick", 333, 0, 5, 0]);
HatsData.push(["Seiga Hair Stick 2", 334, 0, 5, 0]);
HatsData.push(["Tojiko Hat", 335, 0, 5, 0]);
HatsData.push(["Futo Hat", 336, 0, 5, 0]);
HatsData.push(["Miko Headphones", 337, 0, 5, 0]);
HatsData.push(["Mamizou", 338, 0, 5, 0]);
HatsData.push(["Mamizou Ears", 339, 0, 5, 0]);
HatsData.push(["Mamizou Leaf", 340, 0, 5, 0]);
HatsData.push(["Kosuzu's Bells", 341, 0, 5, 0]);
HatsData.push(["Wakasagihime Ears", 342, 0, 5, 0]);
HatsData.push(["Sekibanki Bow", 343, 0, 5, 0]);
HatsData.push(["Kagerou Ears", 344, 0, 5, 0]);
HatsData.push(["Kokoro's Mask", 345, 0, 5, 0]);
HatsData.push(["Mamizou Leaf 2", 346, 0, 5, 0]);
HatsData.push(["Benben's Flower", 347, 0, 5, 0]);
HatsData.push(["Yatsuhashi's Band", 348, 0, 5, 0]);
HatsData.push(["Seija Horns", 349, 0, 5, 0]);
HatsData.push(["Shinmyoumaru Hat", 350, 0, 5, 0]);
HatsData.push(["Seiran Ears", 351, 0, 5, 0]);
HatsData.push(["Ringo Hat (No Ears)", 352, 0, 5, 0]);
HatsData.push(["Ringo Hat", 353, 0, 5, 0]);
HatsData.push(["Doremy Hat", 354, 0, 5, 0]);
HatsData.push(["Clownpiece Hat", 355, 0, 5, 0]);
HatsData.push(["Junko Hat", 356, 0, 5, 0]);
HatsData.push(["Hecatia Hat", 357, 0, 5, 0]);
HatsData.push(["Hecatia Hat(Orbless)", 500, 0, 5, 0]);
	}
	private static function initbg()
	{
		BGs = new Array<Dynamic>();
		BGs.push(["Scarlet Mansion", 1]);
BGs.push(["Flandre's Room", 2]);
BGs.push(["Yukari's Bedroom", 3]);
BGs.push(["Yukari's House", 4]);
BGs.push(["Yukari's Yard", 5]);
BGs.push(["Scarlet Library", 6]);
BGs.push(["Night Mountain", 7]);
BGs.push(["Magic Forest", 8]);
BGs.push(["Marisa's House", 9]);
BGs.push(["Hakurei Shrine", 10]);
BGs.push(["Alice's Room", 11]);
BGs.push(["Alice's House", 12]);
BGs.push(["Yuyuko's Hallway", 13]);
BGs.push(["Yuyuko's Kitchen", 14]);
BGs.push(["Sakura Tree 1", 15]);
BGs.push(["Sakura Tree 2", 16]);
BGs.push(["Shrine Day", 25]);
BGs.push(["Shrine Night", 17]);
BGs.push(["Bamboo Forest", 18]);
BGs.push(["K-1 Classroom 1", 19]);
BGs.push(["K-1 Classroom 2", 20]);
BGs.push(["K-1 Classroom 3", 21]);
BGs.push(["K-1 Classroom 4", 22]);
BGs.push(["Snow Field", 23]);
BGs.push(["Bar", 24]);
BGs.push(["Reimu Burger Register", 26]);
BGs.push(["Reimu Burger Kitchen", 27]);
BGs.push(["Reimu Burger Diner", 28]);
BGs.push(["Reimu Burger Dead End", 30]);
BGs.push(["Reimu Burger Hallway", 31]);
BGs.push(["Cruise Ship Entrance", 32]);
BGs.push(["Cruise Ship Room", 33]);
BGs.push(["Cruise Ship Deck", 34]);
BGs.push(["The Dock", 35]);
BGs.push(["More Forest", 36]);
BGs.push(["Bamboo Forest Zoom!", 37]);
BGs.push(["Desktop", 38]);
BGs.push(["Random Color", 39]);
BGs.push(["Fusion Lab", 40]);
BGs.push(["Open Field", 41]);
BGs.push(["Open Field Dusk", 42]);
BGs.push(["Aya's House", 43]);
BGs.push(["Random Field", 44]);
BGs.push(["Scarlet X-Mas Tree", 45]);
BGs.push(["Reimu's Room", 46]);
BGs.push(["Reimu Burger X-Mas", 47]);
BGs.push(["Reimu's X-Mas Room", 48]);
BGs.push(["Empty Room", 49]);
BGs.push(["Sketchy Room", 50]);
BGs.push(["Sketchy Boxing Ring", 51]);
BGs.push(["Sketchy Field", 52]);
BGs.push(["Sketchy Snowfield", 53]);
BGs.push(["Sketchy BG", 54]);
BGs.push(["Sketchy Reimu's Room", 55]);
BGs.push(["Moriya Shrine Steps", 56]);
BGs.push(["Moriya Shrine Room", 57]);
BGs.push(["Moriya Shrine Yard", 58]);
BGs.push(["Moriya Shrine Opening", 59]);
BGs.push(["Moriya Shrine Room", 60]);
BGs.push(["It's a forest again", 61]);
BGs.push(["And another forest!", 62]);
BGs.push(["End of Gensokyo", 63]);
BGs.push(["Yuka Fight!!", 64]);
BGs.push(["Reimu's Door", 65]);
BGs.push(["Reimu's Door Open", 75]);
BGs.push(["Moriya Shrine Door", 66]);
BGs.push(["Alice in the Forest", 67]);
BGs.push(["Boxing Ring", 68]);
BGs.push(["Island", 69]);
BGs.push(["Saigyou Ayakashi", 70]);
BGs.push(["Imageboard", 71]);
BGs.push(["Yard with Chairs", 72]);
BGs.push(["Moriya Kotatsu", 73]);
BGs.push(["Hakurei Shrine Door", 74]);
BGs.push(["Death by Yuyuko", 76]);
BGs.push(["Reimu Burger Outside", 77]);
BGs.push(["MikoMart Outside", 78]);
BGs.push(["MikoMart Inside", 79]);
BGs.push(["MikoMart Outside 2", 80]);
BGs.push(["Reimu's Room Again", 81]);
BGs.push(["Shrine Exterior", 82]);
BGs.push(["Hakugyokurou", 83]);
BGs.push(["Some Mountain", 84]);
BGs.push(["Generic Sky", 85]);
BGs.push(["Mansion Gates", 86]);
BGs.push(["Mansion Path", 87]);
BGs.push(["Scarlet Hallway", 88]);
BGs.push(["The Moon", 89]);
BGs.push(["Beach", 90]);
BGs.push(["School Hallway", 91]);
BGs.push(["Mini-Stage", 92]);
BGs.push(["Pond", 93]);
BGs.push(["Another Field", 94]);
BGs.push(["Marisa's House 2", 95]);
BGs.push(["Nuclear Sector", 96]);
BGs.push(["Graveyard", 97]);
BGs.push(["Underground Cave", 98]);
BGs.push(["M. Shrine (No Signs)", 99]);
BGs.push(["M. Shrine (Snow)", 100]);
BGs.push(["River", 101]);
BGs.push(["Dark Room", 102]);
BGs.push(["City Street", 103]);
BGs.push(["Eientei", 104]);
BGs.push(["Green Tatami", 105]);
BGs.push(["Kourindou", 106]);
BGs.push(["Nines", 107]);
BGs.push(["Hearts", 108]);
BGs.push(["The Heavens", 109]);
BGs.push(["Trees n' Grass", 110]);
BGs.push(["Basement Sideview", 111]);
BGs.push(["K-1 Classroom 5", 112]);
BGs.push(["K-1 Classroom 6", 113]);
BGs.push(["Scarlet Library 2", 114]);
BGs.push(["Scarlet Lib. Door", 115]);
BGs.push(["S.Ayakashi (Dead)", 116]);
BGs.push(["Onbashiras (Night)", 117]);
BGs.push(["Mountain Silhouette", 118]);
BGs.push(["S.Ayakashi (Dead2)", 119]);
BGs.push(["Onbashiras (Day)", 120]);
BGs.push(["Snowy", 121]);
BGs.push(["Autumn 1", 122]);
BGs.push(["General classroom", 123]);
BGs.push(["Lakeside", 124]);
BGs.push(["Lakeside (Snowy)", 125]);
BGs.push(["Cartoony Background", 126]);
BGs.push(["Makai", 127]);
BGs.push(["Houkai", 128]);
BGs.push(["Clocktower", 129]);
BGs.push(["Murasa's Ship", 130]);
BGs.push(["Murasa's Ship (2)", 131]);
BGs.push(["Geyser", 132]);
BGs.push(["Geyser (2)", 133]);
BGs.push(["Autumn 2", 134]);
BGs.push(["Mountain Sunset", 135]);
BGs.push(["Hakurei Shrine (IaMP)", 136]);
BGs.push(["Hakurei Shrine Night", 137]);
BGs.push(["Shrine Tori", 138]);
BGs.push(["Shrine Tori 2", 139]);
BGs.push(["SDM outside", 140]);
BGs.push(["Frozen Lake", 141]);
BGs.push(["Prismriver Fight", 142]);
BGs.push(["SDM gate", 143]);
BGs.push(["SDM Side", 144]);
BGs.push(["Utsuho Stage", 145]);
BGs.push(["Mountain Steps", 146]);
BGs.push(["Crater", 147]);
BGs.push(["Nameless Hill", 148]);
BGs.push(["Nameless Hill 2", 149]);
BGs.push(["Marisa's House 3", 150]);
BGs.push(["Sunset Branches", 151]);
BGs.push(["Yin-Yang Lift", 152]);
BGs.push(["Destroyed Shrine 1", 153]);
BGs.push(["Destroyed Shrine 2", 154]);
BGs.push(["Sunflower Field", 155]);
BGs.push(["Alice's House 2", 156]);
BGs.push(["SDM Balcony", 157]);
BGs.push(["Waterfall", 158]);
BGs.push(["Outer Space 1", 159]);
BGs.push(["Outer Space 2", 160]);
BGs.push(["Spaceship Inside 1", 161]);
BGs.push(["Spaceship Inside 2", 162]);
BGs.push(["Red Moon", 163]);
BGs.push(["Lake Suwa", 164]);
BGs.push(["SDM Throne Room", 165]);
BGs.push(["Hakurei Shrine (Border)", 166]);
BGs.push(["Scarlet Hallway 2", 167]);
BGs.push(["Eientei Hallway", 168]);
BGs.push(["Moon Corridor", 169]);
BGs.push(["Gothic Cemetery", 170]);
BGs.push(["Mountain Waterfall", 171]);
BGs.push(["Courtroom", 172]);
BGs.push(["Hell of Blazing Fires", 173]);
BGs.push(["Kourindou Outside", 174]);
BGs.push(["Zen Garden Night", 175]);
BGs.push(["Zen Garden Day", 176]);
BGs.push(["Zen Garden Snow", 177]);
BGs.push(["Scarlet Bedroom", 178]);
BGs.push(["Swirly Vortex", 179]);
BGs.push(["Yukari's Gap", 180]);
BGs.push(["Tennis Court", 181]);
BGs.push(["Cathedral", 182]);
BGs.push(["Underground Mine", 183]);
BGs.push(["Computer Grid", 184]);
BGs.push(["Eientei Outside", 185]);
BGs.push(["Eientei Courtyard", 186]);
BGs.push(["Waterfall (Spring)", 187]);
BGs.push(["Alice's Room 2", 188]);
BGs.push(["Lunar Capital", 189]);
BGs.push(["Stairs", 190]);
BGs.push(["Newspaper Template", 191]);
BGs.push(["Under the Sea", 192]);
BGs.push(["Shrine Entrance", 193]);
BGs.push(["Street Intersection", 194]);
BGs.push(["Dancefloor", 195]);
BGs.push(["TV Static", 196]);
BGs.push(["Ship Deck", 197]);
BGs.push(["Gaia Library", 198]);
BGs.push(["SDM Library", 199]);
BGs.push(["Mushroom Forest", 200]);
BGs.push(["Ruined Red Shrine", 201]);
BGs.push(["Human Village", 202]);
BGs.push(["Bar 2", 203]);
BGs.push(["Cathedral Ruins", 204]);
BGs.push(["Forest Night 1", 205]);
BGs.push(["Forest Night 2", 206]);
BGs.push(["Lunar Capital Interior", 207]);
BGs.push(["Basketball Court", 208]);
BGs.push(["Spider Web", 209]);
BGs.push(["Field (Day)", 210]);
BGs.push(["Field (Sunset)", 211]);
BGs.push(["Field (Night)", 212]);
BGs.push(["Clocktower (Sunset)", 213]);
BGs.push(["Clocktower (Night)", 214]);
BGs.push(["Earth from Space", 215]);
BGs.push(["Cathedral (Red)", 216]);
BGs.push(["Ten Desires Stage 4", 217]);
BGs.push(["Myouren Temple Path", 218]);
BGs.push(["Kishinjou Hallway", 219,"Feraligono"]);
BGs.push(["Palanquin Ship", 220, "Feraligono"]);
BGs.push(["Dirt Road", 221,"RSGmaker"]);
BGs.push("random");
	}
	private static function initdna()
	{
		DNAdata = new Array<Dynamic>();
		Presets = new Map<String,Int>();
		addDNA("3.39:Akyu (2):100:208:179:194:176:54:0:0:0:0:0:984499","Akyu (2)");
addDNA("3.39:Akyu:100:54:53:54:54:54:0:0:69:0:0:C073C0","Akyu");
addDNA("3.39:Alice (2A):100:125:124:124:119:13:0:0:0:0:0:FFFF80","Alice (2A)");
addDNA("3.39:Alice (2B):100:125:125:125:119:13:0:0:0:0:0:FFFF80", "Alice (2B)");
addDNA("3.39:AliceALT (2):100:286:222:290:228:69:0:0:0:0:0:FEFE54","AliceALT (2)");
//addDNA("3.39:Alice (PC-98)(2):100:286:222:290:228:69:0:0:0:0:0:FEFE54","Alice (PC-98)(2)");
addDNA("3.39:Alice (PC-98):100:70:69:70:69:69:0:0:0:0:0:FEFE54","Alice (PC-98)");
addDNA("3.39:Alice:100:13:12:13:13:13:0:0:12:0:0:FFFF80","Alice");
addDNA("3.39:Aya (2A):100:147:150:150:145:31:0:0:0:0:0:373737","Aya (2A)");
addDNA("3.39:Aya (2B):100:148:150:151:145:31:0:0:0:0:0:373737","Aya (2B)");
addDNA("3.39:Aya:100:31:30:31:31:31:0:0:47:36:15:332B1A","Aya");
addDNA("3.39:Benben:100:347:273:357:271:46:0:0:0:0:0:ABA1CA","Benben");
addDNA("3.39:Byakuren:100:0:138:139:131:14:0:0:0:0:62:C0994C","Byakuren");
addDNA("3.39:Chen (2):100:135:134:135:127:21:26:13:0:0:55:994D00","Chen (2)");
addDNA("3.39:Chen:100:21:20:21:21:21:6:4:0:0:10:994D00","Chen");
addDNA("3.39:Chiyuri (2):100:216:186:203:183:57:0:0:0:0:0:FEFD81","Chiyuri (2)");
addDNA("3.39:Chiyuri:100:57:56:57:57:57:0:0:0:0:0:FEF4AB","Chiyuri");
addDNA("3.39:Cirno (2A):100:117:119:120:3:9:0:51:0:0:47:49CAE9","Cirno (2A)");
addDNA("3.39:Cirno (2B):100:117:120:120:3:9:0:51:0:0:47:49CAE9","Cirno (2B)");
//addDNA("3.39:Cirno (Fire):100:223:189:213:3:6:0:51:0:0:100:CC0000","Cirno (Fire)");
addDNA("3.39:CirnoALT:100:223:189:213:3:6:0:51:0:0:100:CC0000","CirnoALT");
addDNA("3.39:Cirno:100:9:8:9:9:9:0:1:0:0:2:49CAE9","Cirno");
addDNA("3.39:Daiyousei (2):100:156:157:160:152:37:0:0:0:0:70:A4F4B4","Daiyousei (2)");
addDNA("3.39:Daiyousei:100:37:36:37:37:37:0:0:0:0:18:A4F4B4","Daiyousei");
addDNA("3.39:Doremy:100:354:281:364:278:119:0:0:159:0:137:3343CC","Doremy");
addDNA("3.39:Eirin (2):100:121:121:121:116:10:0:0:0:0:0:F2F2F2","Eirin (2)");
addDNA("3.39:Eirin:100:10:9:10:10:10:0:0:0:0:0:F2F2F2","Eirin");
addDNA("3.39:Elis (2):100:314:251:322:248:94:0:0:91:144:41:EEED09","Elis (2)");
addDNA("3.39:Elis:100:95:94:95:94:94:0:0:91:65:41:EEED09","Elis");
addDNA("3.39:Ellen (2):100:307:246:313:183:89:0:0:0:0:0:FEFD92","Ellen (2)");
addDNA("3.39:Ellen:100:90:89:90:89:89:0:0:0:0:0:FEFD92","Ellen");
addDNA("3.39:Elly (2):100:309:248:315:245:91:0:0:0:0:123:FFFF88","Elly (2)");
addDNA("3.39:Elly:100:92:91:92:91:91:0:0:0:0:0:FFFF88","Elly");
addDNA("3.39:Flandre (2):100:115:116:117:113:6:0:51:0:0:45:FEFDA3","Flandre (2)");
addDNA("3.39:Flandre:100:6:5:6:6:6:0:1:5:0:1:FFFF80","Flandre");
addDNA("3.39:Futo:100:336:265:347:262:118:0:0:0:0:0:A8A8A8","Futo");
addDNA("3.39:Gengetsu (2):100:294:230:299:235:80:0:0:0:0:119:FFFF5E","Gengetsu (2)");
addDNA("3.39:Gengetsu:100:81:80:81:80:80:0:0:0:0:37:FFFF5E","Gengetsu");
addDNA("3.39:Hatate:100:199:177:184:174:31:0:0:0:0:0:40351E","Hatate");
addDNA("3.39:Hina (2A):100:160:161:166:156:42:0:0:0:0:0:87E791","Hina (2A)");
addDNA("3.39:Hina (2B):100:164:161:166:156:42:0:0:0:0:0:87E791","Hina (2B)");
addDNA("3.39:Hina:100:42:41:42:42:42:0:0:0:0:0:87E791","Hina");
addDNA("3.39:Ichirin (2):100:324:259:337:255:103:0:0:95:0:0:B8BCE0", "Ichirin (2)");
addDNA("3.39:IchirinALT (2 Alt):100:324:259:352:255:103:0:0:95:0:0:B8BCE0", "IchirinALT");
addDNA("3.39:Ichirin:100:104:103:104:103:103:0:0:95:0:0:B8BCE0","Ichirin");
addDNA("3.39:Iku (2):100:244:201:226:195:62:0:0:0:0:105:8C75EA","Iku (2)");
addDNA("3.39:Iku:100:62:61:62:62:62:0:0:0:0:32:8C75EA","Iku");
addDNA("3.39:Kagerou:100:344:271:355:269:122:0:0:0:0:0:3C0000","Kagerou");
addDNA("3.39:Kaguya (2):100:0:118:119:115:8:0:0:0:0:0:444444","Kaguya (2)");
addDNA("3.39:Kaguya:100:0:7:8:8:8:0:0:0:0:0:444444","Kaguya");
addDNA("3.39:Kana (2):100:308:247:314:243:90:0:0:0:0:0:FFFFA2","Kana (2)");
addDNA("3.39:Kana:100:91:90:91:90:90:0:0:0:0:0:FFFFA2","Kana");
addDNA("3.39:Kanako (2):100:163:163:168:158:44:0:0:0:0:73:6767E4","Kanako (2)");
addDNA("3.39:Kanako:100:44:43:44:44:44:0:0:0:0:20:6767E4","Kanako");
addDNA("3.39:Kasen:100:273:214:272:215:58:0:0:0:0:0:DA5899","Kasen");
addDNA("3.39:Keine (2):100:131:130:131:117:18:0:0:0:0:0:A0ADDE","Keine (2)");
addDNA("3.39:Keine (EX):100:39:38:39:39:39:0:0:0:0:19:D2D2DC","Keine (EX)");
addDNA("3.39:Keine (EX2):100:132:131:132:117:39:0:0:0:0:52:89E063","Keine (EX2)");
addDNA("3.39:Keine:100:18:17:18:18:18:0:0:0:0:0:D2D2DC","Keine");
addDNA("3.39:Kisume (2A):100:64:205:233:0:0:0:0:0:0:106:20AD79","Kisume (2A)");
addDNA("3.39:Kisume (2B):100:64:206:233:0:0:0:0:0:0:106:20AD79","Kisume (2B)");
addDNA("3.39:Kisume:100:64:63:64:0:0:0:0:0:0:0:20AD79","Kisume");
addDNA("3.39:Koakuma (2):100:150:152:153:147:33:0:0:0:0:66:9C1F1F","Koakuma (2)");
addDNA("3.39:Koakuma:100:33:32:33:33:33:0:0:0:0:17:9C1F1F","Koakuma");
addDNA("3.39:Kogasa (2):100:0:257:334:248:102:81:0:154:0:0:6AA8AE","Kogasa (2)");
addDNA("3.39:Kogasa:100:0:102:103:102:102:81:0:94:0:0:6AA8AE","Kogasa");
addDNA("3.39:Koishi (2A):100:270:212:266:214:75:0:0:0:0:0:DFFDE1","Koishi (2A)");
addDNA("3.39:Koishi (2B):100:270:212:267:214:75:0:0:0:125:0:DFFDE1","Koishi (2B)");
addDNA("3.39:Koishi:100:76:75:76:75:75:0:23:0:66:36:DDFFE7","Koishi");
addDNA("3.39:Kokoro:100:345:272:356:270:123:0:0:0:0:0:F0B9CA", "Kokoro");
addDNA("3.39:Komachi (2):100:142:143:144:139:26:0:0:0:0:0:CB4545","Komachi (2)");
//addDNA("3.39:Komachi (2):100:142:143:144:139:26:40:22:0:0:0:CB4545","Komachi (2)");
addDNA("3.39:Komachi:100:26:25:26:26:26:40:22:41:0:0:CB4545","Komachi");
addDNA("3.39:Konngara (2A):100:295:233:301:130:82:0:0:83:0:0:3C3C3C","Konngara (2A)");
addDNA("3.39:Konngara (2B):100:295:234:301:130:82:0:0:83:0:0:3C3C3C","Konngara (2B)");
addDNA("3.39:Konngara:100:83:82:83:82:82:0:0:83:0:0:3C3C3C","Konngara");
addDNA("3.39:Kosuzu:100:341:268:351:265:119:0:0:0::0:E7776B","Kosuzu");
addDNA("3.39:Kotohime (2):100:0:236:303:237:83:0:0:0:0:0:BF0000","Kotohime (2)");
addDNA("3.39:Kotohime:100:0:83:84:83:83:0:0:0:0:0:BF0000","Kotohime");
addDNA("3.39:Kurumi (2):100:287:223:291:229:70:0:0:0:0:118:FFFF77","Kurumi (2)");
addDNA("3.39:Kurumi:100:71:70:71:70:70:0:0:0:0:33:FFFF77","Kurumi");
addDNA("3.39:Kyouko:100:329:261:343:258:25:0:0:0:0:0:007075","Kyouko");
addDNA("3.39:Layla:100:0:108:109:108:108:31:11:0:0:0:51B087","Layla");
addDNA("3.39:Letty (2):100:134:133:134:126:20:0:11:0:0:54:F3E8FD","Letty (2)");
addDNA("3.39:Letty:100:20:19:20:20:20:0:0:0:63:0:E1D5FF", "Letty");
addDNA("3.39:MeilingALT:100:111:111:112:209:5:0:0:0:0:0:373737","MeilingALT");
//addDNA("3.39:Lie Meiling:100:111:111:112:209:5:0:0:0:0:0:373737","Lie Meiling");
addDNA("3.39:Lily_WhiteALT:100:141:142:143:138:25:0:0:0:0:60:F3BB69","Lily_WhiteALT");
//addDNA("3.39:Lily Black (2):100:141:142:143:138:25:0:0:0:0:60:F3BB69","Lily Black (2)");
addDNA("3.39:Lily Black:100:25:24:25:25:25:0:0:0:0:12:F3BB69","Lily Black");
//addDNA("3.39:Lily White (2):100:140:141:142:137:24:0:0:0:0:60:FEFDA3","Lily White (2)");
addDNA("3.39:Lily_White (2):100:140:141:142:137:24:0:0:0:0:60:FEFDA3","Lily_White (2)");
addDNA("3.39:Lily White:100:24:23:24:24:24:0:0:0:0:12:FEFDA3", "Lily White");
addDNA("3.39:Louise:100:289:225:293:231:71:0:0:0:0:0:FEFDAB","Louise");
//addDNA("3.39:Luize (2A):100:289:225:293:231:71:0:0:0:0:0:FEFDAB","Luize (2A)");
addDNA("3.39:Luize (2B):100:289:225:294:231:71:0:0:0:0:0:FEFDAB","Luize (2B)");
addDNA("3.39:Luize:100:72:71:72:71:71:31:39:0:0:0:FEFDAB", "Luize");
addDNA("3.39:Luna_Child (2):100:200:178:185:175:53:0:0:0:0:92:FFFF5E","Luna_Child (2)");
//addDNA("3.39:Luna Child (2):100:200:178:185:175:53:0:0:0:0:92:FFFF5E","Luna Child (2)");
addDNA("3.39:Luna Child:100:53:52:53:53:53:0:0:0:0:25:ECEB57","Luna Child");
addDNA("3.39:Lunasa (2):100:152:154:155:148:34:0:0:0:0:0:FEF4A3","Lunasa (2)");
addDNA("3.39:Lunasa:100:34:33:34:34:34:0:0:50:0:0:FEF4A3","Lunasa");
addDNA("3.39:Lyrica (2):100:154:156:157:150:36:0:0:0:0:0:8F7B67","Lyrica (2)");
addDNA("3.39:Lyrica:100:36:35:36:36:36:0:0:52:0:0:A3827E","Lyrica");
addDNA("3.39:Mai (2):100:306:245:312:242:88:0:0:0:0:122:ABABFE","Mai (2)");
addDNA("3.39:Mai:100:89:88:89:88:88:0:0:0:0:39:ABABFE","Mai");
addDNA("3.39:Mamizou:100:338:267:350:264:46:0:0:0:155:133:8A5D5D","Mamizou");
addDNA("3.39:Maribel (2):100:211:183:198:178:56:0:0:0:0:0:FFF177","Maribel (2)");
addDNA("3.39:Maribel:100:56:55:56:56:56:0:0:0:0:0:FFF177","Maribel");
addDNA("3.39:Marisa (2):100:151:153:154:117:3:0:0:0:0:0:FEFE78", "Marisa (2)");
addDNA("3.39:MarisaALT (2):100:288:224:292:230:67:0:0:0:0:0:FEFE54","MarisaALT (2)");
//addDNA("3.39:Marisa (PC-98)(2):100:288:224:292:230:67:0:0:0:0:0:FEFE54","Marisa (PC-98)(2)");
addDNA("3.39:Marisa (PC-98):100:68:67:68:67:67:0:0:0:0:0:FEFE54","Marisa (PC-98)");
addDNA("3.39:Marisa (PCB):100:113:113:114:99:3:0:11:0:0:0:FEFD92","Marisa (PCB)");
addDNA("3.39:Marisa (SA):100:100:99:100:99:99:0:11:0:0:0:F5E981","Marisa (SA)");
addDNA("3.39:Marisa (UFO):100:105:104:105:104:104:0:11:96:0:0:FFF600","Marisa (UFO)");
addDNA("3.39:Marisa:100:3:2:3:3:3:0:0:2:0:0:FFFF6F","Marisa");
addDNA("3.39:Medicine (2):100:157:158:162:153:38:0:0:0:40:71:FFF9A4","Medicine (2)");
addDNA("3.39:Medicine:100:38:37:38:38:38:0:0:0:40:0:FFF9A4","Medicine");
addDNA("3.39:Meiling (2):100:110:110:111:209:1:0:0:0:0:0:EB585A","Meiling (2)");
addDNA("3.39:Meiling:100:1:0:1:1:1:0:0:0:0:0:EB585A","Meiling");
addDNA("3.39:Meimu:100:109:109:110:109:109:0:0:0:0:0:DAC2F6","Meimu");
addDNA("3.39:Meira (2):100:313:250:321:247:93:0:0:90:0:0:B835B9","Meira (2)");
addDNA("3.39:Meira:100:94:93:94:93:93:0:0:90:0:0:B835B9","Meira");
addDNA("3.39:Merlin (2):100:153:155:156:149:35:0:0:0:0:0:DDF2FF","Merlin (2)");
addDNA("3.39:Merlin:100:35:34:35:35:35:0:0:51:0:0:DDF2FF","Merlin");
addDNA("3.39:Miko (Alt):100:337:266:349:263:41:0:0:0:154:0:C3B594","Miko (Alt)");
addDNA("3.39:Miko:100:337:266:348:263:41:0:0:0:0:0:C3B594","Miko");
addDNA("3.39:Mima (2):100:174:168:172:163:98:0:0:0:0:0:48771A", "Mima (2)");
addDNA("3.39:MimaALT:100:246:168:175:163:98:0:0:0:0:0:48771A","MimaALT");
//addDNA("3.39:Mima (HRtP):100:246:168:175:163:98:0:0:0:0:0:48771A","Mima (HRtP)");
addDNA("3.39:Mima:100:48:47:48:48:98:0:0:0:0:0:48771A","Mima");
addDNA("3.39:Minoriko (2):100:167:165:169:159:45:0:0:0:0:0:FFCC57","Minoriko (2)");
addDNA("3.39:Minoriko:100:45:44:45:45:45:0:0:0:0:0:FFCC57","Minoriko");
addDNA("3.39:Mitori:100:277:216:280:218:6:0:0:151:0:114:EF8F8F","Mitori");
//addDNA("3.39:Mokou (2):100:127:127:127:121:15:0:0:0:0:48:D9DEE1","Mokou (2)");
addDNA("3.39:Mokou (2):100:127:127:127:121:15:0:0:0:0:0:D9DEE1","Mokou (2)");
addDNA("3.39:Mokou:100:15:14:15:15:15:0:0:0:0:7:EEEEEE","Mokou");
addDNA("3.39:Momiji (2):100:149:151:152:146:32:0:0:108:0:65:FBFBFB","Momiji (2)");
addDNA("3.39:Momiji:100:32:31:32:32:32:0:0:48:37:16:FBFBFB","Momiji");
addDNA("3.39:Mugetsu (2):100:293:229:298:234:78:0:0:0:0:0:FEFD89","Mugetsu (2)");
addDNA("3.39:Mugetsu:100:79:78:79:78:78:0:0:0:0:0:FEFD89","Mugetsu");
addDNA("3.39:Murasa:100:137:136:137:129:14:0:0:100:0:56:262626","Murasa");
addDNA("3.39:Mystia (2A):100:128:128:128:122:16:0:0:0:0:50:F19FAD", "Mystia (2A)");
addDNA("3.39:MystiaALT (2B):100:129:128:129:123:16:31:11:0:0:49:F19FAD","MystiaALT (2B)");
//addDNA("3.39:Mystia (2B):100:129:128:129:123:16:31:11:0:0:49:F19FAD","Mystia (2B)");
addDNA("3.39:Mystia:100:16:15:16:16:16:0:0:0:0:4:F19FAD","Mystia");
addDNA("3.39:Nazrin (2):100:321:256:333:226:101:0:0:0:0:43:969696","Nazrin (2)");
addDNA("3.39:Nazrin:100:102:101:102:101:101:0:11:93:0:43:969696","Nazrin");
addDNA("3.39:Nitori (2):100:143:144:145:140:27:0:0:0:0:61:4B95F6","Nitori (2)");
addDNA("3.39:Nitori:100:27:26:27:27:27:0:0:42:0:13:4B95F6","Nitori");
addDNA("3.39:Nue:100:0:139:140:135:14:0:0:104:0:58:333333","Nue");
addDNA("3.39:Orange (2A):100:299:237:304:238:84:0:0:86:0:0:EB585A","Orange (2A)");
addDNA("3.39:Orange (2B):100:299:238:304:238:84:0:0:86:0:0:EB585A","Orange (2B)");
addDNA("3.39:Orange:100:85:84:85:84:84:0:0:86:0:0:EB585A","Orange");
addDNA("3.39:Orin (2):100:258:209:244:203:73:0:0:0:0:111:D76464","Orin (2)");
addDNA("3.39:Orin:100:74:73:74:73:73:0:0:0:0:35:D76464","Orin");
addDNA("3.39:Parsee (2):100:0:207:237:200:64:0:0:0:0:0:F9E586","Parsee (2)");
addDNA("3.39:Parsee:100:0:64:65:64:64:0:0:0:0:0:F9E586","Parsee");
addDNA("3.39:Patchouli (2):100:124:123:123:118:12:0:0:0:0:0:AB80BF","Patchouli (2)");
addDNA("3.39:Patchouli:100:12:11:12:12:12:0:0:11:0:0:AB80BF","Patchouli");
addDNA("3.39:Raiko:100:0:278:361:275:125:0:0:157:0:136:C04545","Raiko");
addDNA("3.39:Ran (2):100:133:132:133:125:19:0:0:0:0:53:FEE170","Ran (2)");
addDNA("3.39:Ran:100:19:18:19:19:19:0:0:0:0:9:FEE170","Ran");
addDNA("3.39:Reimu (2 Blue):100:112:112:113:111:2:0:0:0:0:0:283960","Reimu (2 Blue)");
addDNA("3.39:Reimu (2 Brown):100:112:145:113:111:2:0:0:0:0:0:6F4722","Reimu (2 Brown)");
addDNA("3.39:Reimu (EoSD):100:112:169:186:111:2:0:0:0:0:0:283960","Reimu (EoSD)");
addDNA("3.39:Reimu (PC-98 2 Green):100:268:190:264:213:39:0:0:0:0:0:890099", "Reimu (PC-98 2 Green)");
addDNA("3.39:ReimuALT (2):100:229:190:217:189:59:0:0:0:0:0:890099","ReimuALT (2)");
//addDNA("3.39:Reimu (PC-98 2):100:229:190:217:189:59:0:0:0:0:0:890099","Reimu (PC-98 2)");
addDNA("3.39:Reimu (PC-98):100:59:58:59:59:59:0:0:0:0:0:890099","Reimu (PC-98)");
addDNA("3.39:Reimu (PCB):100:112:169:187:111:2:0:0:0:0:0:???","Reimu (PCB)");
addDNA("3.39:Reimu (PoFV):100:112:145:188:111:2:0:0:0:0:0:6F4722","Reimu (PoFV)");
addDNA("3.39:Reimu (SA):100:112:169:189:111:2:0:0:0:0:0:283960","Reimu (SA)");
addDNA("3.39:Reimu:100:2:1:2:2:2:0:0:1:0:0:283960", "Reimu");
addDNA("3.39:Reisen:100:101:100:126:14:14:0:0:0:0:51:BFB4D3","Reisen");
//addDNA("3.39:Reisen (2):100:126:126:126:120:14:0:0:0:0:51:CB93E3","Reisen (2)");
addDNA("3.39:Reisen (SWR):100:14:126:101:100:100:0:0:0:0:51:CB93E3","Reisen (SWR)");
addDNA("3.39:Reisen II:100:101:100:126:14:14:0:0:0:0:51:BFB4D3","Reisen II");
addDNA("3.39:Reisen:100:14:13:14:14:14:0:0:0:0:51:E788FF","Reisen");
addDNA("3.39:Remilia (2):100:139:140:141:136:23:0:0:0:0:59:80A2D5","Remilia (2)");
addDNA("3.39:Remilia:100:23:22:23:23:23:0:0:39:0:11:80A2D5", "Remilia");
addDNA("3.39:Rengeteki:100:181:172:176:165:68:0:0:0:0:82:D156D0","Rengeteki");
//addDNA("3.39:Rengeteki:100:181:172:176:166:68:0:0:0:0:82:D156D0","Rengeteki");
addDNA("3.39:Renko (2):100:210:181:196:175:55:0:0:0:0:0:634D2E","Renko (2)");
addDNA("3.39:Renko:100:55:54:55:55:55:0:0:0:0:0:947252","Renko");
addDNA("3.39:Rika (2A):100:302:241:307:226:86:0:0:0:0:0:7A380E","Rika (2A)");
addDNA("3.39:Rika (2B):100:302:242:307:226:86:0:0:0:0:0:7A380E","Rika (2B)");
addDNA("3.39:Rika:100:87:86:87:86:86:0:0:42:0:31:7A380E","Rika");
addDNA("3.39:Rikako (2A):100:300:239:305:239:85:0:0:0:139:0:980198","Rikako (2A)");
addDNA("3.39:Rikako (2B):100:300:239:306:239:85:0:0:0:139:0:980198","Rikako (2B)");
addDNA("3.39:Rikako:100:86:85:86:85:85:0:0:87:64:0:980198","Rikako");
//addDNA("3.39:Rin Satsuki:100:59:107:108:107:107:0:11:97:68:0:F5FABA", "Rin Satsuki");
addDNA("3.39:Rin:100:59:107:108:107:107:0:11:97:68:0:F5FABA","Rin");
addDNA("3.39:Ringo:100:353:280:363:277:102:0:0:0:0:0:B2A249","Ringo");
addDNA("3.39:Rinnosuke (2):100:0:170:173:164:49:0:0:0:64:0:FBFBFB","Rinnosuke (2)");
addDNA("3.39:Rinnosuke:100:0:48:49:49:49:0:0:0:1:0:FBFBFB", "Rinnosuke");
addDNA("3.39:ERumia (2):100:146:149:149:143:30:31:13:0:0:0:FEF39A", "ERumia (2)");
addDNA("3.39:Rumia (2):100:146:149:149:126:30:31:13:0:33:0:FEF39A","Rumia (2)");
addDNA("3.39:Rumia:100:30:29:30:30:30:0:0:0:33:0:FEF39A","Rumia");
addDNA("3.39:Ruukoto (2):100:291:227:296:233:77:0:0:0:0:0:70FE70","Ruukoto (2)");
addDNA("3.39:Ruukoto:100:78:77:78:77:77:31:11:0:0:0:70FE70","Ruukoto");
addDNA("3.39:Sakuya (2):100:114:114:115:89:90:0:0:0:0:0:E6E6E6", "Sakuya (2)");
addDNA("3.39:SakuyaALT:100:168:114:115:89:90:0:0:0:0:0:E6E6E6","SakuyaALT");
//addDNA("3.39:Sakuya (Inu):100:168:114:115:89:90:0:0:0:0:0:E6E6E6","Sakuya (Inu)");
addDNA("3.39:Sakuya (Magical):100:114:114:158:151:111:0:0:0:0:0:E6E6E6","Sakuya (Magical)");
addDNA("3.39:Sakuya:100:4:3:4:4:4:0:0:3:0:0:E6E6E6","Sakuya");
addDNA("3.39:Sanae (2):100:161:162:167:157:43:0:0:0:0:0:98F898", "Sanae (2)");
addDNA("3.39:SanaeALT:100:155:162:159:157:43:0:0:111:0:0:98F898","SanaeALT");
//addDNA("3.39:Sanae (Magical):100:155:162:159:157:43:0:0:111:0:0:98F898","Sanae (Magical)");
addDNA("3.39:Sanae:100:43:42:43:43:43:0:0:74:0:0:98F898","Sanae");
addDNA("3.39:Sara (2):100:0:249:316:246:92:0:0:0:0:0:EFABBA","Sara (2)");
addDNA("3.39:Sara:100:0:92:93:92:92:0:0:0:0:0:EFABBA","Sara");
addDNA("3.39:Sariel (2A):100:0:231:300:236:81:0:0:82:0:120:DDDDFF","Sariel (2A)");
addDNA("3.39:Sariel (2B):100:0:232:300:236:81:0:0:82:0:120:DDDDFF","Sariel (2B)");
addDNA("3.39:Sariel:100:0:81:82:81:81:0:0:82:0:38:DDDDFF","Sariel");
addDNA("3.39:Sasha:100:0:217:281:222:102:0:0:0:0:0:7EC3FA","Sasha");
addDNA("3.39:Satori (2A):100:265:210:262:210:74:0:0:0:0:0:E3BBFF","Satori (2A)");
addDNA("3.39:Satori (2B):100:265:210:263:210:74:0:0:0:122:0:E3BBFF","Satori (2B)");
addDNA("3.39:Satori:100:75:74:75:74:74:73:40:0:61:0:E3BBFF","Satori");
addDNA("3.39:Seiga:100:334:263:345:260:25:0:0:0:0:132:3D6EA1","Seiga");
addDNA("3.39:Seija:100:349:275:359:273:35:0:0:0:0:0:BB0000","Seija");
addDNA("3.39:Seiran:100:351:279:362:276:24:0:0:158:0:0:549DE7","Seiran");
addDNA("3.39:Sekibanki:100:343:270:354:268:121:0:0:0:156:0:EC0202", "Sekibanki");
addDNA("3.39:Sekibankinohead:100:0:240:354:268:121:128:0:0:156:0:C0FFEE","Sekibankinohead");
addDNA("3.39:Shanghai (2):100:326:260:341:256:106:0:0:0:0:0:FFFF80","Shanghai (2)");
addDNA("3.39:Shanghai:100:107:106:107:106:106:0:0:0:0:23:FFFF80", "Shanghai");
addDNA("3.39:Shingyoku (2):100:317:252:325:226:95:0:0:0:0:0:D22D2D","Shingyoku (2)");
//addDNA("3.39:Shingyoku F (2):100:317:252:325:226:95:0:0:0:0:0:D22D2D","Shingyoku F (2)");
addDNA("3.39:Shingyoku F:100:96:95:96:95:95:0:0:0:0:0:D22D2D", "Shingyoku F");
addDNA("3.39:ShingyokuALT (2):100:318:253:326:249:96:0:0:0:0:0:393939","ShingyokuALT (2)");
//addDNA("3.39:Shingyoku M (2):100:318:253:326:249:96:0:0:0:0:0:393939","Shingyoku M (2)");
addDNA("3.39:Shingyoku M:100:97:96:97:96:96:0:0:0:0:0:393939","Shingyoku M");
addDNA("3.39:Shinki (2):100:171:167:171:161:47:0:0:0:0:78:EDEAFB","Shinki (2)");
addDNA("3.39:Shinki:100:47:46:47:47:47:0:0:0:0:21:EDEAFB","Shinki");
addDNA("3.39:Shinmyoumaru:100:350:277:360:274:45:0:0:156:0:135:8D8AB0","Shinmyoumaru");
addDNA("3.39:Shizuha (2):100:169:166:170:160:46:0:0:0:0:0:FFF06F","Shizuha (2)");
addDNA("3.39:Shizuha:100:46:45:46:46:46:0:0:0:0:0:FFF06F","Shizuha");
addDNA("3.39:Shou:100:138:137:138:130:14:0:11:101:0:57:FBFF6C","Shou");
addDNA("3.39:Shikieiki (2):100:144:146:147:141:28:0:0:0:0:0:BBD5C5","Shikieiki (2)");
addDNA("3.39:Shikieiki:100:28:27:28:28:28:0:0:43:0:0:BBD5C5", "Shikieiki");
addDNA("3.39:Star_Sapphire (2A):100:195:175:182:173:52:0:0:0:0:86:444444","Star_Sapphire (2A)");
//addDNA("3.39:Star Sapphire (2A):100:195:175:182:173:52:0:0:0:0:86:444444","Star Sapphire (2A)");
addDNA("3.39:Star Sapphire (2B):100:195:176:182:173:52:0:0:0:0:86:444444","Star Sapphire (2B)");
addDNA("3.39:Star Sapphire:100:52:51:52:52:52:0:0:0:0:24:444444","Star Sapphire");
addDNA("3.39:Suika (2):100:136:135:136:128:22:23:8:0:0:0:FEB74E","Suika (2)");
addDNA("3.39:Suika:100:22:21:22:22:22:31:13:36:0:0:FEB74E","Suika");
addDNA("3.39:Sumireko:100:210:282:365:250:124:0:0:0:158:138:634D2E", "Sumireko");
addDNA("3.39:Sunny_Milk (2):100:189:174:181:172:51:0:0:0:0:85:F7ED8C","Sunny_Milk (2)");
//addDNA("3.39:Sunny Milk (2):100:189:174:181:172:51:0:0:0:0:85:F7ED8C","Sunny Milk (2)");
addDNA("3.39:Sunny Milk:100:51:50:51:51:51:0:0:0:0:23:F7ED8C","Sunny Milk");
addDNA("3.39:Suwako (2):100:159:160:165:155:41:0:0:0:0:0:FEF7BC","Suwako (2)");
addDNA("3.39:Suwako:100:41:40:41:41:41:0:0:0:0:0:FAFFC4","Suwako");
addDNA("3.39:Tenshi (2A):100:236:196:224:192:61:0:0:0:0:0:2987C5","Tenshi (2A)");
addDNA("3.39:Tenshi (2B):100:236:202:224:192:61:0:0:0:0:0:2987C5","Tenshi (2B)");
addDNA("3.39:Tenshi:100:61:60:61:61:61:0:0:0:0:0:2987C5","Tenshi");
addDNA("3.39:Tewi (2):100:130:129:130:124:17:0:51:0:73:51:333333","Tewi (2)");
addDNA("3.39:Tewi:100:17:16:17:17:17:0:0:0:0:51:333333","Tewi");
addDNA("3.39:Tojiko:100:335:264:346:261:117:0:0:0:0:0:C5D1AF","Tojiko");
addDNA("3.39:Tokiko (2):100:188:173:179:169:50:0:0:0:0:83:B4CBFE","Tokiko (2)");
addDNA("3.39:Tokiko:100:50:49:50:50:50:0:0:0:0:22:EEEEEE","Tokiko");
addDNA("3.39:Toyohime (2):100:285:220:288:226:66:0:0:144:0:0:FEEDB9","Toyohime (2)");
addDNA("3.39:Toyohime:100:67:66:67:66:66:0:0:0:0:0:FEEDB9", "Toyohime");
addDNA("3.39:redeyedudongein:100:126:126:126:120:14:105:0:0:0:51:CB93E3", "redeyedudongein");
//
addDNA("3.39:Udongein (2):100:126:126:126:120:14:0:0:0:0:51:CB93E3", "Udongein (2)");
addDNA("3.39:Okuu (2):100:256:208:240:201:115:0:0:0:0:0:3C3C3C","Okuu (2)");
addDNA("3.39:Utsuho (2):100:256:208:240:201:115:0:0:0:0:110:3C3C3C","Utsuho (2)");
addDNA("3.39:Utsuho:100:73:72:73:72:72:0:0:0:0:34:3C3C3C","Utsuho");
addDNA("3.39:VIVIT (2):100:304:244:309:241:79:0:0:0:0:0:ED5F5F","VIVIT (2)");
addDNA("3.39:VIVIT:100:80:79:80:79:79:0:0:0:0:0:ED5F5F","VIVIT");
addDNA("3.39:Wakasagihime:100:342:269:353:267:120:0:0:0:0:0:01597E", "Wakasagihime");
addDNA("3.39:Wriggle (2):100:145:148:148:126:29:0:0:0:0:63:497255","Wriggle (2)");
addDNA("3.39:Wriggle:100:29:28:29:29:29:0:0:0:0:14:497255","Wriggle");
addDNA("3.39:Yatsuhashi:100:348:274:358:272:123:0:0:0:0:0:7E604E", "Yatsuhashi");
addDNA("3.39:Yamame (2):100:215:185:202:180:60:0:0:0:0:0:FEF1C4","Yamame (2)");
//addDNA("3.39:Yamame (2):100:215:185:202:182:60:0:0:0:0:0:FEF1C4","Yamame (2)");
addDNA("3.39:Yamame:100:60:59:60:60:60:0:0:0:0:30:FEF1C4","Yamame");
addDNA("3.39:Yorihime (2):100:284:219:287:224:65:0:0:143:0:0:D6CBDE","Yorihime (2)");
addDNA("3.39:Yorihime:100:66:65:66:65:65:0:0:0:0:0:D6CBDE","Yorihime");
addDNA("3.39:Yoshika:100:331:262:344:0:53:0:0:0:152:0:5E6283","Yoshika");
addDNA("3.39:Youki (2):100:0:221:289:227:68:0:0:0:138:0:F7F7F7","Youki (2)");
addDNA("3.39:Youki:100:0:68:69:68:68:0:0:0:59:0:F7F7F7", "Youki");
addDNA("3.39:Youmumyon:100:123:122:122:117:3:0:0:0:0:26:F2F2F2","Youmumyon");
addDNA("3.39:Youmu (2):100:123:122:122:117:3:0:0:0:0:0:F2F2F2","Youmu (2)");
addDNA("3.39:Youmu:100:11:10:11:11:11:0:11:10:0:0:F2F2F2", "Youmu");
addDNA("3.39:Yuuka (2):100:0:159:163:142:40:0:0:0:0:0:309C30","Yuuka (2)");
//addDNA("3.39:Yuka (2):100:0:159:163:142:40:0:0:0:0:0:309C30","Yuka (2)");
addDNA("3.39:YuukaALT:100:319:254:330:250:97:0:0:0:0:0:23AB23","YuukaALT");
//addDNA("3.39:Yuka (PJ's 2):100:319:254:330:250:97:0:0:0:0:0:23AB23","Yuka (PJ's 2)");
addDNA("3.39:Yuka (PJ's):100:98:97:98:97:97:0:0:0:0:0:23AB23","Yuka (PJ's)");
addDNA("3.39:Yuka:100:0:39:40:40:40:0:0:57:0:0:309C30","Yuka");
addDNA("3.39:Yukari (2):100:320:258:116:112:5:0:0:0:0:0:FFFF80","Yukari (2)");
addDNA("3.39:Yukari (IaMP):100:99:115:116:112:5:0:11:0:0:0:FFFF80", "Yukari (IaMP)");
addDNA("3.39:YukariALT:100:320:255:331:251:5:0:0:0:0:0:FFFF80","YukariALT");
//addDNA("3.39:Yukari (PCB 2):100:320:255:331:251:5:0:0:0:0:0:FFFF80","Yukari (PCB 2)");
addDNA("3.39:Yukari (PCB):100:99:98:99:98:5:0:0:0:0:0:FFFF80","Yukari (PCB)");
addDNA("3.39:Yukari:100:5:4:5:5:5:0:0:4:0:27:FFFF80","Yukari");
addDNA("3.39:Yuki (2):100:303:243:308:240:87:0:0:0:0:0:FEFE54","Yuki (2)");
addDNA("3.39:Yuki:100:88:87:88:87:87:0:0:0:0:0:FEFE54","Yuki");
addDNA("3.39:Yumeko (2):100:290:226:295:232:76:0:0:0:0:0:FEFE70","Yumeko (2)");
addDNA("3.39:Yumeko:100:77:76:77:76:76:0:0:3:0:0:FEFE70","Yumeko");
addDNA("3.39:Yumemi (2):100:0:187:205:184:58:0:0:0:0:96:AA2B2B","Yumemi (2)");
addDNA("3.39:Yumemi:100:0:57:58:58:58:0:0:0:0:0:934242","Yumemi");
addDNA("3.39:Yuugi (2):100:250:204:232:197:63:0:0:0:0:0:EFDDAF","Yuugi (2)");
addDNA("3.39:Yuugi:100:63:62:63:63:63:0:0:81:0:0:EFDDAF","Yuugi");
addDNA("3.39:Yuyuko (2):100:116:117:118:114:9:0:11:0:0:0:FF9999","Yuyuko (2)");
addDNA("3.39:Yuyuko:100:7:6:7:7:7:0:0:27:0:28:FF9999","Yuyuko");
addDNA("3.39:Zombie Fairy:100:106:105:106:105:105:85:0:0:0:44:D9DDFF", "Zombie Fairy");

addDNA("3.39:Sagume:100:0:283:366:279:124:0:0:0:0:139:D3D5D8", "Sagume");
addDNA("3.39:Clownpiece:100:355:284:367:280:126:0:0:0:0:141:EBB902", "Clownpiece");
addDNA("3.39:Junko:100:356:285:368:281:125:0:0:0:0:140:F6A500", "Junko");
addDNA("3.39:Hecatia:100:357:286:369:282:45:0:0:0:0:0:A10000", "Hecatia");

addDNA("3.39:Blue Fairy:63:0:185:298:209:46:0:0:0:0:86:F3F3FF", "Blue_Fairy");
addDNA("3.39:Gold Fairy:63:0:185:176:209:46:0:0:0:0:86:FFFFF3", "Gold_Fairy");
addDNA("3.39:Green Fairy:63:0:185:270:209:46:0:0:0:0:86:F3FFF3", "Green_Fairy");
addDNA("3.39:Red Fairy:63:0:185:201:209:46:0:0:0:0:86:FFF3F3", "Red_Fairy");
//addDNA("3.39:Magi Fairy:63:158:158:238:154:20:0:0:0:0:86:FFF3F3", "Magi_Fairy");
addDNA("3.39:Magi Fairy:63:158:158:238:154:20:0:0:89:15:86:FFF3F3", "Magi_Fairy");

addDNA("3.39:MoonRabbit:100:130:181:215:120:17:0:0:0:0:51:FCE24E", "MoonRabbit");
	}
	private static function addDNA(dna:String,presetname:String)
	{
		var i = DNAdata.length;
		DNAdata[i] = [dna, presetname];
		var s = presetname.toLowerCase();
		if (s.indexOf(" (") > -1)
		{
			s = s.split(" (")[0];
		}
		if (Presets[s] == null)
		{
			Presets.set(s, i);
		}
	}
	private static function inithair()
	{
		Hairdata = new Array<Dynamic>();
		
		addHair(["Meiling", 1, 0, 0, 0, 2, "EB585A"]);
addHair(["Reimu", 2, 0, 0, 0, 0, "283960"]);
addHair(["Marisa", 3, 0, 0, 0, 0, "FFFF6F"]);
addHair(["Sakuya", 4, 0, 0, 0, 0, "E6E6E6"]);
addHair(["Yukari", 5, 0, 0, 0, 0, "FFFF80"]);
addHair(["Flandre", 6, 0, 0, 0, 0, "FFFF80"]);
addHair(["Yuyuko", 7, 0, 0, 0, 0, "FF9999"]);
addHair(["Kaguya", 8, 0, 0, 0, 0, "444444"]);
addHair(["Cirno", 9, 0, 0, 0, 0, "49CAE9"]);
addHair(["Eirin", 10, 0, 0, 0, 0, "F2F2F2"]);
addHair(["Youmu", 11, 0, 0, 0, 0, "F2F2F2"]);
addHair(["Patchouli", 12, 0, 0, 0, 0, "AB80BF"]);
addHair(["Alice", 13, 0, 0, 0, 0, "FFFF80"]);
addHair(["Reisen", 14, 0, 0, 0, 0, "E788FF"]);
addHair(["Mokou", 15, 0, 0, 0, 0, "EEEEEE"]);
addHair(["Mystia", 16, 0, 0, 0, 0, "F19FAD"]);
addHair(["Tewi", 17, 0, 0, 0, 0, "333333"]);
addHair(["Keine", 18, 0, 0, 0, 0, "D2D2DC"]);
addHair(["Ran", 19, 0, 0, 0, 0, "FEE170"]);
addHair(["Letty", 20, 0, 0, 0, 0, "E1D5FF"]);
addHair(["Chen", 21, 0, 0, 0, 0, "994D00"]);
addHair(["Suika", 22, 0, 0, 0, 0, "FEB74E"]);
addHair(["Remilia", 23, 0, 0, 0, 0, "80A2D5"]);
addHair(["Lily White", 24, 0, 0, 0, 0, "FEFDA3"]);
addHair(["Lily Black", 25, 0, 0, 0, 0, "F3BB69"]);
addHair(["Komachi", 26, 0, 0, 0, 0, "CB4545"]);
addHair(["Nitori", 27, 0, 0, 0, 0, "4B95F6"]);
addHair(["Shikieiki", 28, 0, 0, 0, 0, "BBD5C5"]);
addHair(["Wriggle", 29, 0, 0, 0, 0, "497255"]);
addHair(["Rumia", 30, 0, 0, 0, 0, "FEF39A"]);
addHair(["Aya", 31, 0, 0, 0, 0, "332B1A"]);
addHair(["Momiji", 32, 0, 0, 0, 0, "FBFBFB"]);
addHair(["Koakuma", 33, 0, 0, 0, 0, "9C1F1F"]);
addHair(["Lunasa", 34, 0, 0, 0, 0, "FEF4A3"]);
addHair(["Merlin", 35, 0, 0, 0, 0, "DDF2FF"]);
addHair(["Lyrica", 36, 0, 0, 0, 0, "A3827E"]);
addHair(["Daiyousei", 37, 0, 0, 0, 0, "A4F4B4"]);
addHair(["Medicine", 38, 0, 0, 0, 0, "FFF9A4"]);
addHair(["Keine (EX)", 39, 0, 0, 0, 0, "D2D2DC"]);
addHair(["Yuka", 40, 0, 0, 0, 0, "309C30"]);
addHair(["Suwako", 41, 0, 0, 0, 0, "FAFFC4"]);
addHair(["Hina", 42, 0, 0, 0, 1, "87E791"]);
addHair(["Sanae", 43, 0, 0, 0, 0, "98F898"]);
addHair(["Kanako", 44, 0, 0, 0, 0, "6767E4"]);
addHair(["Minoriko", 45, 0, 0, 0, 0, "FFCC57"]);
addHair(["Shizuha", 46, 0, 0, 0, 0, "FFF06F"]);
addHair(["Shinki", 47, 0, 0, 0, 0, "EDEAFB"]);
addHair(["Mima", 48, 0, 0, 0, 0, "48771A"]);
addHair(["Rinnosuke", 49, 0, 0, 0, 0, "FBFBFB"]);
addHair(["Tokiko", 50, 0, 0, 0, 0, "EEEEEE"]);
addHair(["Sunny Milk", 51, 0, 0, 0, 0, "F7ED8C"]);
addHair(["Star Sapphire", 52, 0, 0, 0, 0, "444444"]);
addHair(["Luna Child", 53, 0, 0, 0, 0, "ECEB57"]);
addHair(["Akyu", 54, 0, 0, 0, 0, "C073C0"]);
addHair(["Renko", 55, 0, 0, 0, 0, "947252"]);
addHair(["Maribel", 56, 0, 0, 0, 0, "FFF177"]);
addHair(["Chiyuri", 57, 0, 0, 0, 0, "FEF4AB"]);
addHair(["Yumemi", 58, 0, 0, 0, 0, "934242"]);
addHair(["Reimu (PC-98)", 59, 0, 0, 0, 0, "890099"]);
addHair(["Yamame", 60, 0, 0, 0, 0, "FEF1C4"]);
addHair(["Tenshi", 61, 0, 0, 0, 0, "2987C5"]);
addHair(["Iku", 62, 0, 0, 0, 0, "8C75EA"]);
addHair(["Yuugi", 63, 0, 0, 0, 0, "EFDDAF"]);
addHair(["Kisume", 64, 0, 0, 0, 0, "20AD79"]);
addHair(["Parsee", 65, 0, 0, 0, 0, "F9E586"]);
addHair(["Yorihime", 66, 0, 0, 0, 0, "D6CBDE"]);
addHair(["Toyohime", 67, 0, 0, 0, 0, "FEEDB9"]);
addHair(["Marisa (PC-98)", 68, 0, 0, 0, 0, "FEFE54"]);
addHair(["Youki", 69, 0, 0, 0, 0, "F7F7F7"]);
addHair(["Alice (PC-98)", 70, 0, 0, 0, 0, "FEFE54"]);
addHair(["Kurumi", 71, 0, 0, 0, 0, "FFFF77"]);
addHair(["Luize", 72, 0, 0, 0, 0, "FEFDAB"]);
addHair(["Utsuho", 73, 0, 0, 0, 0, "3C3C3C"]);
addHair(["Orin", 74, 0, 0, 0, 0, "D76464"]);
addHair(["Satori", 75, 0, 0, 0, 0, "E3BBFF"]);
addHair(["Koishi", 76, 0, 0, 0, 0, "DDFFE7"]);
addHair(["Yumeko", 77, 0, 0, 0, 0, "FEFE70"]);
addHair(["Ruukoto", 78, 0, 0, 0, 0, "70FE70"]);
addHair(["Mugetsu", 79, 0, 0, 0, 0, "FEFD89"]);
addHair(["VIVIT", 80, 0, 0, 0, 0, "ED5F5F"]);
addHair(["Gengetsu", 81, 0, 0, 0, 0, "FFFF5E"]);
addHair(["Sariel", 82, 0, 0, 0, 0, "DDDDFF"]);
addHair(["Konngara", 83, 0, 0, 0, 0, "3C3C3C"]);
addHair(["Kotohime", 84, 0, 0, 0, 3, "BF0000"]);
addHair(["Orange", 85, 0, 0, 0, 0, "EB585A"]);
addHair(["Rikako", 86, 0, 0, 0, 0, "980198"]);
addHair(["Rika", 87, 0, 0, 0, 0, "7A380E"]);
addHair(["Yuki", 88, 0, 0, 0, 0, "FEFE54"]);
addHair(["Mai", 89, 0, 0, 0, 0, "ABABFE"]);
addHair(["Ellen", 90, 0, 0, 0, 0, "FEFD92"]);
addHair(["Kana", 91, 0, 0, 0, 0, "FFFFA2"]);
addHair(["Elly", 92, 0, 0, 0, 0, "FFFF88"]);
addHair(["Sara", 93, 0, 0, 0, 0, "EFABBA"]);
addHair(["Meira", 94, 0, 0, 0, 0, "B835B9"]);
addHair(["Elis", 95, 0, 0, 0, 0, "EEED09"]);
addHair(["Shingyoku F", 96, 0, 0, 0, 0, "D22D2D"]);
addHair(["Shingyoku M", 97, 0, 0, 0, 0, "393939"]);
addHair(["Yuka (PJ's)", 98, 0, 0, 0, 0, "23AB23"]);
addHair(["Yukari (PCB)", 99, 0, 0, 0, 0, "FFFF80"]);
addHair(["Marisa (SA)", 100, 0, 0, 0, 0, "F5E981"]);
addHair(["Reisen II", 101, 0, 0, 0, 0, "BFB4D3"]);
addHair(["Nazrin", 102, 0, 0, 0, 0, "969696"]);
addHair(["Kogasa", 103, 0, 0, 0, 0, "6AA8AE"]);
addHair(["Ichirin", 104, 0, 0, 0, 0, "B8BCE0"]);
addHair(["Marisa (UFO)", 105, 0, 0, 0, 0, "FFF600"]);
addHair(["Zombie Fairy", 106, 0, 0, 0, 0, "D9DDFF"]);
addHair(["Shanghai", 107, 0, 0, 0, 0, "FFFF80"]);
addHair(["Rin Satsuki", 108, 0, 0, 0, 0, "F5FABA"]);
addHair(["Layla", 109, 0, 0, 0, 0, "51B087"]);
addHair(["Meimu", 110, 0, 0, 0, 4, "DAC2F6"]);
addHair(["Meiling (2)", 111, 0, 0, 0, 5, "EB585A"]);
addHair(["Lie Meiling", 111, 0, 0, 0, 5, "373737"]);
addHair(["Reimu (2 Blue)", 112, 0, 0, 0, 0, "283960"]);
addHair(["Marisa (PCB)", 113, 0, 0, 0, 0, "FEFD92"]);
addHair(["Sakuya (2)", 114, 0, 0, 0, 6, "E6E6E6"]);
addHair(["Yukari (IaMP)", 115, 0, 0, 0, 7, "FFFF80"]);
addHair(["Flandre (2)", 116, 0, 0, 0, 0, "FEFDA3"]);
addHair(["Yuyuko (2)", 117, 0, 0, 0, 0, "FF9999"]);
addHair(["Kaguya (2)", 118, 0, 0, 0, 0, "444444"]);
addHair(["Cirno (2A)", 119, 0, 0, 0, 0, "49CAE9"]);
addHair(["Cirno (2B)", 120, 0, 0, 0, 0, "49CAE9"]);
addHair(["Eirin (2)", 121, 0, 0, 0, 0, "F2F2F2"]);
addHair(["Youmu (2)", 122, 0, 0, 0, 0, "F2F2F2"]);
addHair(["Patchouli (2)", 123, 0, 0, 0, 8, "AB80BF"]);
addHair(["Alice (2A)", 124, 0, 0, 0, 0, "FFFF80"]);
addHair(["Alice (2B)", 125, 0, 0, 0, 0, "FFFF80"]);
addHair(["Reisen (2)", 126, 0, 0, 0, 9, "CB93E3"]);
addHair(["Mokou (2)", 127, 0, 0, 0, 0, "D9DEE1"]);
addHair(["Mystia (2)", 128, 0, 0, 0, 0, "F19FAD"]);
addHair(["Tewi (2)", 129, 0, 0, 0, 0, "333333"]);
addHair(["Keine (2)", 130, 0, 0, 0, 10, "A0ADDE"]);
addHair(["Keine (EX2)", 130, 0, 0, 0, 10, "89E063"]);
addHair(["Ran (2)", 131, 0, 0, 0, 0, "FEE170"]);
addHair(["Letty (2)", 132, 0, 0, 0, 0, "F3E8FD"]);
addHair(["Chen (2)", 133, 0, 0, 0, 0, "994D00"]);
addHair(["Suika (2)", 134, 0, 0, 0, 0, "FEB74E"]);
addHair(["Murasa", 135, 0, 0, 0, 0, "262626"]);
addHair(["Shou", 136, 0, 0, 0, 0, "FBFF6C"]);
addHair(["Byakuren", 137, 0, 0, 0, 0, "C0994C"]);
addHair(["Nue", 138, 0, 0, 0, 0, "333333"]);
addHair(["Remilia (2)", 139, 0, 0, 0, 0, "80A2D5"]);
addHair(["Lily White (2)", 140, 0, 0, 0, 0, "FEFDA3"]);
addHair(["Lily Black (2)", 140, 0, 0, 0, 0, "F3BB69"]);
addHair(["Komachi (2)", 141, 0, 0, 0, 0, "CB4545"]);
addHair(["Nitori (2)", 142, 0, 0, 0, 0, "4B95F6"]);
addHair(["Reimu (2 Brown)", 112, 0, 0, 0, 0, "6F4722"]);
addHair(["Shikieiki (2)", 143, 0, 0, 0, 0, "BBD5C5"]);
addHair(["Byakuren (No Gr.)", 144, 0, 0, 0, 0, "C0994C"]);
addHair(["Wriggle (2)", 145, 0, 0, 0, 0, "497255"]);
addHair(["Rumia (2)", 146, 0, 0, 0, 0, "FEF39A"]);
addHair(["Aya (2)", 147, 0, 0, 0, 0, "373737"]);
addHair(["Momiji (2)", 148, 0, 0, 0, 0, "FBFBFB"]);
addHair(["Koakuma (2)", 149, 0, 0, 0, 0, "9C1F1F"]);
addHair(["Marisa (2)", 150, 0, 0, 0, 0, "FEFE78"]);
addHair(["Lunasa (2)", 151, 0, 0, 0, 0, "FEF4A3"]);
addHair(["Merlin (2)", 152, 0, 0, 0, 0, "DDF2FF"]);
addHair(["Lyrica (2)", 153, 0, 0, 0, 0, "8F7B67"]);
addHair(["Daiyousei (2)", 154, 0, 0, 0, 0, "A4F4B4"]);
addHair(["Medicine (2)", 155, 0, 0, 0, 0, "FFF9A4"]);
addHair(["Yuka (2)", 156, 0, 0, 0, 0, "309C30"]);
addHair(["Suwako (2)", 157, 0, 0, 0, 0, "FEF7BC"]);
addHair(["Hina (2)", 158, 0, 0, 0, 11, "87E791"]);
addHair(["Sanae (2)", 159, 0, 0, 0, 0, "98F898"]);
addHair(["Kanako (2)", 160, 0, 0, 0, 0, "6767E4"]);
addHair(["None", 161, 0, 0, 0, 0, "FFFFFF"]);
addHair(["Minoriko (2)", 162, 0, 0, 0, 0, "FFCC57"]);
addHair(["Shizuha (2)", 163, 0, 0, 0, 0, "FFF06F"]);
addHair(["Shinki (2)", 164, 0, 0, 0, 0, "EDEAFB"]);
addHair(["Mima (2)", 165, 0, 0, 0, 0, "48771A"]);
addHair(["Reimu (2 Short)", 166, 0, 0, 0, 0, "283960"]);
addHair(["Rinnosuke (2)", 167, 0, 0, 0, 0, "FBFBFB"]);
addHair(["Shinki (2 Alt)", 168, 0, 0, 0, 0, "EDEAFB"]);
addHair(["Rengeteki", 169, 0, 0, 0, 0, "D156D0"]);
addHair(["Tokiko (2)", 170, 0, 0, 0, 0, "B4CBFE"]);
addHair(["Sunny Milk (2)", 171, 0, 0, 0, 0, "F7ED8C"]);
addHair(["Star Sapphire (2A)", 172, 0, 0, 0, 12, "444444"]);
addHair(["Star Sapphire (2B)", 173, 0, 0, 0, 12, "444444"]);
addHair(["Hatate", 174, 0, 0, 0, 0, "40351E"]);
addHair(["Luna Child (2)", 175, 0, 0, 0, 0, "FFFF5E"]);
addHair(["Akyu (2)", 176, 0, 0, 0, 0, "984499"]);
addHair(["Rinnosuke (2 Alt)", 177, 0, 0, 0, 0, "FBFBFB"]);
addHair(["Renko (2)", 178, 0, 0, 0, 0, "634D2E"]);
addHair(["Marisa (SoEW)", 179, 0, 0, 0, 0, "A22222"]);
addHair(["Maribel (2)", 180, 0, 0, 0, 0, "FFF177"]);
addHair(["Sanae (No Snake)", 181, 0, 0, 0, 0, "98F898"]);
addHair(["Yamame (2)", 182, 0, 0, 0, 0, "FEF1C4"]);
addHair(["Chiyuri (2)", 183, 0, 0, 0, 0, "FEFD81"]);
addHair(["Yumemi (2)", 184, 0, 0, 0, 0, "AA2B2B"]);
addHair(["Reimu (2 Alt)", 185, 0, 0, 0, 0, "283960"]);
addHair(["Cirno (2 Fire)", 119, 0, 0, 0, 0, "CC0000"]);
addHair(["Reimu (PC-98 2)", 186, 0, 0, 0, 13, "890099"]);
addHair(["Keine (2 Alt)", 187, 0, 0, 0, 0, "EAEAEA"]);
addHair(["Shou (Alt)", 188, 0, 0, 0, 0, "FBFF6C"]);
addHair(["Zombie Fairy (Alt)", 189, 0, 0, 0, 0, "D9DDFF"]);
addHair(["Flat", 190, 0, 0, 0, 0, "333333"]);
addHair(["Spiky", 191, 0, 0, 0, 0, "333333"]);
addHair(["Tenshi (2A)", 192, 0, 0, 0, 0, "2987C5"]);
addHair(["Reimu (2 None)", 193, 0, 0, 0, 0, "283960"]);
addHair(["Reimu (2 Short None)", 194, 0, 0, 0, 0, "283960"]);
addHair(["Reimu (2 Alt None)", 195, 0, 0, 0, 0, "283960"]);
addHair(["Fauxhawk", 196, 0, 0, 0, 0, "333333"]);
addHair(["Iku (2)", 197, 0, 0, 0, 0, "8C75EA"]);
addHair(["Tenshi (2B)", 198, 0, 0, 0, 0, "2987C5"]);
addHair(["Sakuya (Inu)", 199, 0, 0, 0, 6, "E6E6E6"]);
addHair(["Yuugi (2)", 200, 0, 0, 0, 0, "EFDDAF"]);
addHair(["Kisume (2A)", 201, 0, 0, 0, 0, "20AD79"]);
addHair(["Kisume (2B)", 202, 0, 0, 0, 0, "20AD79"]);
addHair(["Parsee (2)", 203, 0, 0, 0, 0, "F9E586"]);
addHair(["Utsuho (2)", 204, 0, 0, 0, 0, "3C3C3C"]);
addHair(["Orin (2)", 205, 0, 0, 0, 0, "D76464"]);
addHair(["Satori (2)", 206, 0, 0, 0, 0, "E3BBFF"]);
addHair(["Sin Sack", 207, 0, 0, 0, 0, "C0FFEE"]);
addHair(["Koishi (2)", 208, 0, 0, 0, 0, "DFFDE1"]);
addHair(["Mohawk", 209, 0, 0, 0, 0, "298975"]);
addHair(["Kasen", 210, 0, 0, 0, 0, "DA5899"]);
addHair(["Pigtail", 211, 0, 0, 0, 0, "B30000"]);
addHair(["Mitori", 212, 0, 0, 0, 0, "EF8F8F"]);
addHair(["Sasha", 213, 0, 0, 0, 0, "7EC3FA"]);
addHair(["Sakuya (Inu Alt)", 214, 0, 0, 0, 0, "E6E6E6"]);
addHair(["Yorihime (2)", 215, 0, 0, 0, 0, "D6CBDE"]);
addHair(["Toyohime (2)", 216, 0, 0, 0, 0, "FEEDB9"]);
addHair(["Youki (2)", 217, 0, 0, 0, 0, "F7F7F7"]);
addHair(["Alice (PC-98)(2)", 218, 0, 0, 0, 0, "FEFE54"]);
addHair(["Kurumi (2)", 219, 0, 0, 0, 0, "FFFF77"]);
addHair(["Marisa (PC-98)(2)", 220, 0, 0, 0, 0, "FEFE54"]);
addHair(["Luize (2)", 221, 0, 0, 0, 0, "FEFDAB"]);
addHair(["Yumeko (2)", 222, 0, 0, 0, 0, "FEFE70"]);
addHair(["Ruukoto (2)", 223, 0, 0, 0, 0, "70FE70"]);
addHair(["Sasha (Alt)", 224, 0, 0, 0, 0, "7EC3FA"]);
addHair(["Mugetsu (2)", 225, 0, 0, 0, 0, "FEFD89"]);
addHair(["Gengetsu (2)", 226, 0, 0, 0, 0, "FFFF5E"]);
addHair(["Sariel (2A)", 227, 0, 0, 0, 0, "DDDDFF"]);
addHair(["Sariel (2B)", 228, 0, 0, 0, 0, "DDDDFF"]);
addHair(["Konngara (2A)", 229, 0, 0, 0, 0, "3C3C3C"]);
addHair(["Konngara (2B)", 230, 0, 0, 0, 0, "3C3C3C"]);
addHair(["Konngara (2C)", 231, 0, 0, 0, 0, "3C3C3C"]);
addHair(["Kotohime (2)", 232, 0, 0, 0, 14, "BF0000"]);
addHair(["Orange (2A)", 233, 0, 0, 0, 0, "EB585A"]);
addHair(["Orange (2B)", 234, 0, 0, 0, 0, "EB585A"]);
addHair(["Rikako (2)", 235, 0, 0, 0, 0, "980198"]);
addHair(["Headless", 236, 0, 0, 0, 0, "C0FFEE"]);
addHair(["Rika (2A)", 237, 0, 0, 0, 0, "7A380E"]);
addHair(["Rika (2B)", 238, 0, 0, 0, 0, "7A380E"]);
addHair(["Yuki (2)", 239, 0, 0, 0, 0, "FEFE54"]);
addHair(["VIVIT (2)", 240, 0, 0, 0, 0, "ED5F5F"]);
addHair(["Mai (2)", 241, 0, 0, 0, 0, "ABABFE"]);
addHair(["Ellen (2)", 242, 0, 0, 0, 0, "FEFD92"]);
addHair(["Kana (2)", 243, 0, 0, 0, 0, "FFFFA2"]);
addHair(["Elly (2)", 244, 0, 0, 0, 0, "FFFF88"]);
addHair(["Sara (2)", 245, 0, 0, 0, 0, "EFABBA"]);
addHair(["Meira (2)", 246, 0, 0, 0, 0, "B835B9"]);
addHair(["Elis (2)", 247, 0, 0, 0, 0, "EEED09"]);
addHair(["Shingyoku F (2)", 248, 0, 0, 0, 0, "D22D2D"]);
addHair(["Shingyoku M (2)", 249, 0, 0, 0, 0, "393939"]);
addHair(["Yuka (PJ's 2)", 250, 0, 0, 0, 0, "23AB23"]);
addHair(["Yukari (PCB 2)", 251, 0, 0, 0, 0, "FFFF80"]);
addHair(["Nazrin (2)", 252, 0, 0, 0, 0, "969696"]);
addHair(["Kogasa (2)", 253, 0, 0, 0, 0, "6AA8AE"]);
addHair(["Yukari (2)", 254, 0, 0, 0, 7, "FFFF80"]);
addHair(["Ichirin (2)", 255, 0, 0, 0, 0, "B8BCE0"]);
addHair(["Shanghai (2)", 256, 0, 0, 0, 0, "FFFF80"]);
addHair(["Kyouko", 257, 0, 0, 0, 0, "007075"]);
addHair(["Yoshika", 258, 0, 0, 0, 0, "5E6283"]);
addHair(["Seiga", 259, 0, 0, 0, 0, "3D6EA1"]);
addHair(["Tojiko", 260, 0, 0, 0, 0, "C5D1AF"]);
addHair(["Futo", 261, 0, 0, 0, 0, "A8A8A8"]);
addHair(["Miko", 262, 0, 0, 0, 0, "C3B594"]);
addHair(["Mamizou", 263, 0, 0, 0, 0, "8A5D5D"]);
addHair(["Kosuzu", 264, 0, 0, 0, 0, "E7776B"]);
addHair(["Wakasagihime", 265, 0, 0, 0, 0, "01597E"]);
addHair(["Sekibanki", 266, 0, 0, 0, 0, "EC0202"]);
addHair(["Kagerou", 267, 0, 0, 0, 0, "3C0000"]);
addHair(["Kokoro", 268, 0, 0, 0, 0, "F0B9CA"]);
addHair(["Benben", 269, 0, 0, 0, 0, "ABA1CA"]);
addHair(["Yatsuhashi", 270, 0, 0, 0, 0, "7E604E"]);
addHair(["Seija", 271, 0, 0, 0, 0, "BB0000"]);
addHair(["Seija (Alt)", 272, 0, 0, 0, 0, "262626"]);
addHair(["Shinmyoumaru", 273, 0, 0, 0, 0, "8D8AB0"]);
addHair(["Raiko", 274, 0, 0, 0, 0, "C04545"]);
addHair(["Seiran", 275, 0, 0, 0, 0, "549DE7"]);
addHair(["Ringo", 276, 0, 0, 0, 0, "B2A249"]);
addHair(["Doremy", 277, 0, 0, 0, 0, "3343CC"]);
addHair(["Sumireko", 278, 0, 0, 0, 0, "634D2E"]);
addHair(["Sagume", 279, 0, 0, 0, 0, "D3D5D8"]);
addHair(["Clownpiece", 280, 0, 0, 0, 0, "EBB902"]);
addHair(["Junko", 281, 0, 0, 0, 0, "F6A500"]);
addHair(["Hecatia", 282, 0, 0, 0, 0, "A10000"]);
	}
	private static function addHair(data:Array<Dynamic>)
	{
		Hairdata.push(data);
	}
	public static function getCharPreset(name:String):String
	{
		if (Hairdata == null)
	{
		init();
	}
	if (name.indexOf("background-") == 0)
	{
		return null;
	}
		var i = 0;
		var items = false;
		if (name.indexOf("W/Items") > -1)
		{
			name = name.split("W/Items").join("");
			items = true;
		}
		name = name.toLowerCase();
		var ind = Presets[name];
		var dna = null;
		if (ind != null)
		{
			dna = "dna-" + DNAdata[ind][0];
			if (!items)
			{
				dna = changednapart(dna, 10, "0");
			}
			return dna;
		}
		return null;
		//name.split(" (2)").join("");
		while (i < DNAdata.length)
		{
			//if (DNAdata[i][1].toLowerCase().split(" (2)").join("") == name)
			var ostr = DNAdata[i][1];
			var str:String = ostr.toLowerCase();
			if (str.indexOf(" (") >= 0)
			{
				str = str.split(" (")[0];
			}
			//if (str.split(" (2)").join("") == name)
			if (str == name)
			{
				//return "dna-" + DNAdata[i][0];
				dna = "dna-" + DNAdata[i][0];
				//Version#:Name:Scale:Hat:Hair:Body:Arm:Shoes:Eyes:Mouth:Item:Accessory:Back:this.HairColor
				//remove items
				if (str == name)
				{
				dna = changednapart(dna, 10, "0");
				}
				return dna;
			}
			i++;
		}
		return dna;
	}
	public static function changednascale(dna:String, scale:Float):String
	{
		var S = dna.split(":");
		S[2] = "" + scale;
		return S.join(":");
	}
	public static function changednapart(dna:String,index:Int, value:String):String
	{
		var S = dna.split(":");
		S[index] = "" + value;
		return S.join(":");
	}
	public static function getdnapart(dna:String,index:Int):String
	{
		var S = dna.split(":");
		return S[index];
	}
	public static var optimize:Bool = true;
	//makes makecharimage's results have smoothened lines
	public static var smoothen:Bool = true;
	public static function makeCharImage(T:String,smooth:Dynamic=null):BitmapData
	{
		//optimization allows the reusing of assets, but flash seems to have issues with cropping them.
		//var optimize:Bool = true;
		if (smooth == null)
		{
			smooth = smoothen;
		}
		var ok = false;
		if (spr == null || optimize)
		{
			spr = new Sprite();
			ok = true;
		}
		if (!optimize)
		{
			char = null;
			ok = true;
		}
			char = makeChar(T, char);
			var CHR = char;
			/*CHR.scaleX *= 0.24;
			CHR.scaleY = CHR.scaleX;*/
			//CHR.scaleX *= 0.24;
			if (smooth)
			{
				//CHR.scaleX *= 4;
				CHR.scaleX *= 0.96;
			}
			else
			{
				CHR.scaleX *= 0.24;
			}
			CHR.scaleY = CHR.scaleX;
			if (ok)
			{
				spr.removeChildren();
				spr.addChild(CHR);
			}
			//var R = CHR.getBounds(spr);
			//if (ok)
			{
			//CHR.x = -R.x;
			//CHR.y = -R.y;
			
			//CHR.x = 10;
			//CHR.y = 50;
			if (optimize && false)
			{
			CHR.x = CHR.width - Std.int(CHR.width / 1.8);
			CHR.y = CHR.height - (CHR.height / 4.05);
			}
			else
			{
				var R = CHR.getBounds(spr);
				CHR.x = -R.x;
				CHR.y = -R.y;
			}
			}
			var bounds = getVisibleBounds(spr);
			//if (ok)
			{
				CHR.x -= bounds.x;
				CHR.y -= bounds.y;
			}
			var D:Dynamic = CHR.getChildByName("head");
			D = D.SkinColor;
			var B = D.getBounds(spr);
			/////var W = B.x - 97.65;
			var W = ((B.x+(B.width/2)) / bounds.width);
			
			W = bounds.width * (W - 0.5314496314496315);
			//W = bounds.width * (W - 0.54);
			W += W;
			//var W = B.x - 38.3;
			/*if (B.width <= 0)
			{
				W = 0;
				
			}*/
			//var W = (CHR.x - 97.65)/* / 2*/;
			//var W = (CHR.x - 97.65) / 2;
			/*if (W < 0)
			{
				W = 0;
			}*/
			if (W < 0)
			{
				W = -W;
				CHR.x += W;
				
				
				//W = 0;
			}
			if (!(W > 0) && !(W < 0))
			{
				W = 0;
			}
			//W = 0;
			///CHR.x -= (W/2);
			//CHR.x += W;
			//W = 0;
			var bitmapData:BitmapData = new BitmapData(Std.int(Math.max(bounds.width+W,1)), Std.int(Math.max(bounds.height,1)),true, 0x00000000);
			bitmapData.draw(spr);
			//bitmapData.draw(spr, null, null, null, null, true);
			CHR.x = 0;
			CHR.y = 0;
			if (smooth)
			{
			var T = new Bitmap(bitmapData, PixelSnapping.NEVER, true);
			T.scaleX = 0.25;
			T.scaleY = T.scaleX;
			var S = new Sprite();
			S.addChild(T);
			//var m:Matrix = new Matrix();
			//m.scale(0.25, 0.25);
			var ret:BitmapData = new BitmapData(Std.int(Math.max(S.width, 1)), Std.int(Math.max(S.height, 1)), true, 0x00000000);
			//ret.draw(S);
			ret.draw(S);
			//ret.draw(S, m, null, null, null, true);
			return ret;
			}
			return bitmapData;
			
	}
	public static function getVisibleBounds(source:DisplayObject):Rectangle
   {
       // Updated 11-18-2010;
       // Thanks to Mark in the comments for this addition;
       var matrix:Matrix = new Matrix();
       matrix.tx = -source.getBounds(null).x;
       matrix.ty = -source.getBounds(null).y;
 
       var data:BitmapData = new BitmapData(Std.int(source.width), Std.int(source.height), true, 0x00000000);
       data.draw(source, matrix);
       var bounds : Rectangle = data.getColorBoundsRect(0xFFFFFFFF, 0x000000, false);
       data.dispose();
       return bounds;
   }
	public static function makeChar(T:String,char:MovieClip=null):MovieClip
{
	if (Hairdata == null)
	{
		init();
	}
    var _loc5 = T.split("-");
	var _sc = "0xFFF1DD";
	var _loc4:Array<String>;
	var _loc6=100.0;
	var _loc7=0.0;
	var _loc8=0.0;
	var _loc9=0.0;
	var _loc10=0.0;
	var _loc11=0.0;
	var _loc14=0.0;
	var _loc15;
	var _loc16:String;
	var _loc17:String="000000";
	var _loc18=0.0;
	var _loc19=0.0;
	var _loc20=0.0;
	var _loc21=0.0;
	
    if (_loc5.length > 1 && _loc5[0].toLowerCase() == "dna")
    {
        _loc5.shift();
        _loc15 = _loc5.join("-");
        _loc4 = _loc15.split(":");
        _loc16 = _loc4[1];
        if (_loc4[2] != null)
        {
            _loc6 = Std.parseFloat(_loc4[2]);
        }
        else
        {
            _loc6 = 100;
        } // end else if
        _loc9 = Std.parseFloat(_loc4[3]);
        _loc7 = Std.parseFloat(_loc4[4]);
		
		if (_loc4[14] != null)
		{
			_sc = "0x"+_loc4[14];
		}
		//FFF1DD
        if (Std.parseFloat(_loc4[0]) < 3.230000 && Std.parseFloat(_loc4[0])>=1)
        {
            _loc10 = Std.parseFloat(_loc4[5]) + 1;
            //var _loc17 = GameData.Parts.Hair[_loc7][6];
			_loc17 = ""+_loc4[13];
			//_loc17 = Std.parseInt(Hairdata[Std.int(_loc7)][6]);
        }
        else
        {
            _loc10 = Std.parseFloat(_loc4[5]);
            _loc17 = ""+_loc4[13];
        } // end else if
        if (Std.parseFloat(_loc4[0]) < 3.200000 && Std.parseFloat(_loc4[0])>=1)
        {
            _loc8 = Std.parseFloat(_loc4[6]) + 1;
            _loc11 = Std.parseFloat(_loc4[7]) + 1;
        }
        else
        {
            _loc8 = Std.parseFloat(_loc4[6]);
            _loc11 = Std.parseFloat(_loc4[7]);
        } // end else if
        _loc20 = Std.parseFloat(_loc4[8]);
        _loc14 = Std.parseFloat(_loc4[9]);
        _loc19 = Std.parseFloat(_loc4[10]);
        _loc18 = Std.parseFloat(_loc4[11]);
        _loc21 = Std.parseFloat(_loc4[12]);
        ///var _loc12 = stage["Clone Capsule"]._x;
        ///var _loc13 = stage["Clone Capsule"]._y;
        if (_loc16 == null)
        {
            _loc16 = "Mutant Clone";
            _loc20 = 66;
            _loc14 = 36;
        }
        else
        {
            _loc20 = Std.parseFloat(_loc4[8]);
            _loc14 = Std.parseFloat(_loc4[9]);
        } // end else if
    }
            var clip = char;
			if (clip == null)
			{
				clip=Assets.getMovieClip ("Char:Char");
			}
			//clip.x = 400;
			//clip.y = 300;
			//addChild (clip);
			//_loc7 += 2;
			///_loc9 -= 1;
			//_loc14 -= 1;
			//_loc19 -= 1;
			//_loc21 -= 1;
			_loc14 = MouthData[Std.int(_loc14)][1];
			_loc19 = ItemsData[Std.int(_loc19)][1];
			_loc18 = AccData[Std.int(_loc18)][1];
			var eyes = EyesData[Std.int(_loc20)];
			_loc20 = eyes[1];
			var eyes2:Int = Std.int(eyes[5]);
			//_loc21 = HatsData[Std.int(_loc21)][1];
			_loc21 = BackData[Std.int(_loc21)][1];
			
						
			//_loc14-=1;
			
			//_loc18 -= 1;
			
			var hat = HatsData[Std.int(_loc9)][1];
			
			//_loc7 = 136;
			//_loc7 += 1;
			var hair:Dynamic = Hairdata[Std.int(_loc7)];
			var hair2 = -1;
			if (hair != null)
			{
				_loc7 = hair[1];
				hair2 = hair[5];
			}
			
			clip.cacheAsBitmap = true;
			var D:Dynamic = clip;
			D = clip.getChildByName("body");
			D.gotoAndStop(_loc10);
			D.visible = _loc10 > 0;
			D = clip.getChildByName("eyes");
			D.gotoAndStop(_loc20);
			D = clip.getChildByName("legs");
			D.gotoAndStop(_loc11);
			D.visible = _loc11 > 0;
			D = clip.getChildByName("hat");
			D.visible = _loc9 > 0;
			D.gotoAndStop(hat);
			D = clip.getChildByName("arms");
			D.gotoAndStop(_loc8);
			D.visible = _loc8 > 0;
			D = clip.getChildByName("head");
			if (hair != null)
			{
				D.visible = _loc7 >= 0 && _loc7 != 236;
				D.gotoAndStop(_loc7);
				D.HairColor.gotoAndStop(_loc7);
				var i = 0;
					while (i < D.numChildren)
					{
						var C = D.getChildAt(i);
						if (/*C != D.eye2 && */C!=null)
						{
							C.visible = true;
						}
						i++;
					}
			}
			else
			{
				D.visible = false;
				D.gotoAndStop(161);
				D.HairColor.gotoAndStop(161);
				//D.gotoAndStop(2);
				//D.HairColor.gotoAndStop(2);
			}
			D.eye2.visible = false;
			//D.eye2.visible = eyes2 > 0;
			//D.eye2.gotoAndStop(eyes2);
			
			//D.visible = true;
			if (eyes2 > 0)
			{
				D.eye2.visible = true;
				D.eye2.gotoAndStop(eyes2);
				//D.eye2.gotoAndStop(2);
				if (!D.visible)
				{
					D.visible = true;
					//var M:MovieClip = D;
					var i = 0;
					while (i < D.numChildren)
					{
						var C = D.getChildAt(i);
						if (C != D.eye2 && C!=null)
						{
							C.visible = false;
						}
						i++;
					}
				}
			}
			//D.eye2._visible = true;
            //D.eye2.gotoAndStop(GameData.Parts[A][N][5]);
			D = clip.getChildByName("head2");
			if (hair != null)
			{
				D.visible = hair2 > 0 && _loc7 != 236;
				D.gotoAndStop(hair2);
				D.HairColor.gotoAndStop(hair2);
			}
			else
			{
				D.visible = false;
			}
			//D.visible = false;
			D = clip.getChildByName("accessory");
			
			D.visible = _loc18 > 0;
			if (D.visible)
			{
				D.gotoAndStop(_loc18);
			}
			D = clip.getChildByName("wings");
			D.visible = _loc21 > 0;
			D.gotoAndStop(_loc21);
			D = clip.getChildByName("mouth");
			D.visible = _loc14 > 0;
			D.gotoAndStop(_loc14);
			D = clip.getChildByName("item");
			D.visible = _loc19 > 0;
			D.gotoAndStop(_loc19);
			
			
			var colorHex = "0x" + _loc17;
			D = clip.getChildByName("head");
			ColorPalette(D.HairColor, colorHex);
			////ColorPalette(D.SkinColor, _sc);
			D = clip.getChildByName("head2");
			ColorPalette(D.HairColor, colorHex);
			
			D = clip.getChildByName("arms");
			//ColorPalette(stage[_loc1].head.SkinColor, _sc);
			//ColorPalette(stage[_loc1].arms.arm.SkinColor, _sc);
			if (D.arm != null)
			{
				////ColorPalette(D.arm.SkinColor, _sc);
			}
			/*else
			{
				
				ColorPalette(D.getChildAt(1), _sc);
			}*/
			clip.scaleX = _loc6 * 0.01;
			clip.scaleY = clip.scaleX;
			/*if (false)
			{
            var bitmapData:BitmapData = new BitmapData(Std.int(clip.width), Std.int(clip.height),true, 0x00000000);
			bitmapData.draw(clip);
			removeChild(clip);
			var bitmap:Bitmap = new Bitmap(bitmapData);
			bitmap.x = 400;
			bitmap.y = 300;
			addChild(bitmap);
		}*/
		return clip;

        //});
    /*GameData.Characters[_loc1] = new Object();
    RootPartSwap(stage[_loc1].eyes, "Eyes", String(_loc20));
    RootPartSwap(stage[_loc1].mouth, "Mouth", String(_loc14));
    RootPartSwap(stage[_loc1].hat, "Hats", String(_loc9));
    RootPartSwap(stage[_loc1].item, "Items", String(_loc19));
    RootPartSwap(stage[_loc1].wings, "Back", String(_loc21));
    RootPartSwap(stage[_loc1].accessory, "Acc", String(_loc18));
    RootPartSwap(stage[_loc1].head, "Hair", String(_loc7));
    RootPartSwap(stage[_loc1].body, "Body", String(_loc10));
    RootPartSwap(stage[_loc1].arms, "Arms", String(_loc8));
    RootPartSwap(stage[_loc1].legs, "Shoes", String(_loc11));*/
    /*GameData.Characters[_loc1].Name = _loc16;
    GameData.Characters[_loc1].Scale = _loc6;
    GameData.Characters[_loc1].Locks = new Object();
    GameData.Characters[_loc1].Locks.Mouth = false;
    GameData.Characters[_loc1].Locks.Eyes = false;
    GameData.Characters[_loc1].Locks.Hair = false;
    GameData.Characters[_loc1].Locks.Body = false;
    GameData.Characters[_loc1].Locks.Arms = false;
    GameData.Characters[_loc1].Locks.Shoes = false;
    GameData.Characters[_loc1].Locks.Back = false;
    GameData.Characters[_loc1].Locks.Accessory = false;
    GameData.Characters[_loc1].Locks.Items = false;
    GameData.Characters[_loc1].Locks.Hats = false;
    colorHex = "0x" + _loc17;
    GameData.Characters[_loc1].HairColor = colorHex;
	GameData.Characters[_loc1].SkinColor = _sc;
    ColorPalette(stage[_loc1].head.HairColor, colorHex);
    ColorPalette(stage[_loc1].head2.HairColor, colorHex);
	ColorPalette(stage[_loc1].head.SkinColor, _sc);
	ColorPalette(stage[_loc1].arms.arm.SkinColor, _sc);
    stage[_loc1].Pin = false;
    stage[_loc1]._x = _loc12;
    stage[_loc1]._y = _loc13;
    stage[_loc1]._xscale = _loc6;
    stage[_loc1]._yscale = _loc6;
    if (T == "Capsule Clone")
    {
        stage[_loc1].XFace = GameData.Toys["Clone Capsule"].Target.XFace;
        stage[_loc1].YFace = GameData.Toys["Clone Capsule"].Target.YFace;
        stage[_loc1]._xscale = stage[_loc1]._xscale * stage[_loc1].XFace;
        stage[_loc1]._yscale = stage[_loc1]._yscale * stage[_loc1].YFace;
    }
    else
    {
        stage[_loc1].XFace = 1;
        stage[_loc1].YFace = 1;
    } // end else if
    AddClickHandler(stage[_loc1], "Character");
    return (stage[_loc1]);*/
} // End of the function
	static function ColorPalette(MC:DisplayObject, Hexa:Dynamic)
{
	if (MC != null && Hexa != null)
{
	var CT:ColorTransform = new ColorTransform();
	CT.color = Std.parseInt(Hexa);
	MC.transform.colorTransform = CT;
}
    //var _loc1 = new Color(MC);
    //_loc1.setRGB(Hexa);
    //MC.RGB = Hexa;
}
	
}