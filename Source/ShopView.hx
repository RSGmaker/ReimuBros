package;
import abilities.AbsorbDamage;
import openfl.display.Bitmap;
import openfl.display.Sprite;
import openfl.events.Event;
import openfl.events.MouseEvent;
import openfl.geom.Rectangle;
import openfl.text.Font;
import openfl.text.TextField;
import openfl.text.TextFieldType;
import openfl.text.TextFormat;

/**
 * ...
 * @author RSGmaker
 */
class ShopView extends Sprite
{
	//consider separating shop and customization into their own sprite classes.
	public var AL:Animationloader;
	public var background:Sprite;
	public var customizetab:MenuButton;
	public var shoptab:MenuButton;
	public var exitbutton:MenuButton;
	public var status:String;
	public var shoppanel:Shop;
	public var custompanel:AvatarEditor;
	
	public var playername:String;
	public var buttons:Sprite;
	
	
	public function new() 
	{
		super();
		playername = "PlayerName";
		//soul = "none";
		//avatardna = "3.39:RSGmaker:100:0:192:324:232:24:0:0:0:1:0:321A00";
		custompanel = new AvatarEditor();
		custompanel.view = this;
		shoppanel = new Shop();
		shoppanel.visible = false;
		
		this.scrollRect = new Rectangle(0, 0, 800, 600);
	}
	public function start() {
		//playername = getdnapart(avatardna, 1);
		AL = Main._this.AL;
		
		
		addChild(shoppanel);
		//custompanel.avatardna = avatardna;
		//custompanel.soul = soul;
		custompanel.visible = true;
		addChild(custompanel);
		//initcustomizepanel();
		custompanel.start();
		//initshoppanel();
		shoppanel.start();
		buttons = new Sprite();
		//background = new Sprite();
		//addChild(background);
		SoundManager.PlayMusic("customize");
		
		customizetab = new MenuButton("Customize");
		customizetab.x = customizetab.outlinesize;
		customizetab.y = 535;
		customizetab.addclick( function( ev ) {
				if (!custompanel.visible)
				{
				shoptab.setcolors();
				customizetab.setcolors(0xFF0000, 0xFFFFFF, 1);
				shoppanel.visible = false;
				custompanel.visible = true;
				SoundManager.StopMusic();
				SoundManager.PlayMusic("customize");
				}
				 } 
				);
		buttons.addChild(customizetab);
		shoptab = new MenuButton("Shop");
		//shoptab.visible = false;
		shoptab.x = 250 + shoptab.outlinesize;
		shoptab.y = 535;
		shoptab.addclick( function( ev ) {
				if (!shoppanel.visible)
				{
				customizetab.setcolors();
				shoptab.setcolors(0xFF0000, 0xFFFFFF, 1);
				custompanel.visible = false;
				shoppanel.visible = true;
				SoundManager.StopMusic();
				SoundManager.PlayMusic("shop");
				}
				 } 
				);
		buttons.addChild(shoptab);
		exitbutton = new MenuButton("Title Screen");
		exitbutton.sound = "cancel";
		exitbutton.x = 550 + exitbutton.outlinesize;
		exitbutton.y = 535;
		exitbutton.addclick( function( ev ) {
				status = "TitleScreen";
				 } 
				);
		buttons.addChild(exitbutton);
		addChild(buttons);
		
		customizetab.setcolors(0xFF0000, 0xFFFFFF, 1);
		
	}
	
	public function this_onEnterFrame()
	{
		if (shoppanel.visible)
		{
			shoppanel.update();
		}
		if (custompanel.visible)
		{
			custompanel.update();
		}
	}
	
	
	
}