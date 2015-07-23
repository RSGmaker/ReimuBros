package;


import haxe.Timer;
import haxe.Unserializer;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.MovieClip;
import openfl.events.Event;
import openfl.text.Font;
import openfl.media.Sound;
import openfl.net.URLRequest;
import openfl.utils.ByteArray;
import openfl.Assets;

#if (flash || js)
import openfl.display.Loader;
import openfl.events.Event;
import openfl.net.URLLoader;
#end

#if sys
import sys.FileSystem;
#end

#if ios
import openfl._v2.utils.SystemPath;
#end


@:access(openfl.media.Sound)
class DefaultAssetLibrary extends AssetLibrary {
	
	
	public var className (default, null) = new Map <String, Dynamic> ();
	public var path (default, null) = new Map <String, String> ();
	public var type (default, null) = new Map <String, AssetType> ();
	
	private var lastModified:Float;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		#if flash
		
		path.set ("assets/Audio/Ogg/bonk.OGG", "assets/Audio/Ogg/bonk.OGG");
		type.set ("assets/Audio/Ogg/bonk.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/characterselect.OGG", "assets/Audio/Ogg/characterselect.OGG");
		type.set ("assets/Audio/Ogg/characterselect.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/collectcoin.OGG", "assets/Audio/Ogg/collectcoin.OGG");
		type.set ("assets/Audio/Ogg/collectcoin.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/died.OGG", "assets/Audio/Ogg/died.OGG");
		type.set ("assets/Audio/Ogg/died.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/finalkill.OGG", "assets/Audio/Ogg/finalkill.OGG");
		type.set ("assets/Audio/Ogg/finalkill.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/fireballspawn.OGG", "assets/Audio/Ogg/fireballspawn.OGG");
		type.set ("assets/Audio/Ogg/fireballspawn.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/gameover.OGG", "assets/Audio/Ogg/gameover.OGG");
		type.set ("assets/Audio/Ogg/gameover.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/killenemy.OGG", "assets/Audio/Ogg/killenemy.OGG");
		type.set ("assets/Audio/Ogg/killenemy.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/nextlevel.OGG", "assets/Audio/Ogg/nextlevel.OGG");
		type.set ("assets/Audio/Ogg/nextlevel.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/pow.OGG", "assets/Audio/Ogg/pow.OGG");
		type.set ("assets/Audio/Ogg/pow.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/respawn.OGG", "assets/Audio/Ogg/respawn.OGG");
		type.set ("assets/Audio/Ogg/respawn.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/spawncoin.OGG", "assets/Audio/Ogg/spawncoin.OGG");
		type.set ("assets/Audio/Ogg/spawncoin.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/startgame.OGG", "assets/Audio/Ogg/startgame.OGG");
		type.set ("assets/Audio/Ogg/startgame.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/step1.OGG", "assets/Audio/Ogg/step1.OGG");
		type.set ("assets/Audio/Ogg/step1.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/step2.OGG", "assets/Audio/Ogg/step2.OGG");
		type.set ("assets/Audio/Ogg/step2.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/step3.OGG", "assets/Audio/Ogg/step3.OGG");
		type.set ("assets/Audio/Ogg/step3.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme1.OGG", "assets/Audio/Ogg/theme1.OGG");
		type.set ("assets/Audio/Ogg/theme1.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme10.OGG", "assets/Audio/Ogg/theme10.OGG");
		type.set ("assets/Audio/Ogg/theme10.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme11.OGG", "assets/Audio/Ogg/theme11.OGG");
		type.set ("assets/Audio/Ogg/theme11.OGG", AssetType.MUSIC);
		path.set ("assets/Audio/Ogg/theme12.OGG", "assets/Audio/Ogg/theme12.OGG");
		type.set ("assets/Audio/Ogg/theme12.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme12intro.OGG", "assets/Audio/Ogg/theme12intro.OGG");
		type.set ("assets/Audio/Ogg/theme12intro.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme2.OGG", "assets/Audio/Ogg/theme2.OGG");
		type.set ("assets/Audio/Ogg/theme2.OGG", AssetType.MUSIC);
		path.set ("assets/Audio/Ogg/theme3.OGG", "assets/Audio/Ogg/theme3.OGG");
		type.set ("assets/Audio/Ogg/theme3.OGG", AssetType.MUSIC);
		path.set ("assets/Audio/Ogg/theme4.OGG", "assets/Audio/Ogg/theme4.OGG");
		type.set ("assets/Audio/Ogg/theme4.OGG", AssetType.MUSIC);
		path.set ("assets/Audio/Ogg/theme5.OGG", "assets/Audio/Ogg/theme5.OGG");
		type.set ("assets/Audio/Ogg/theme5.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme6.OGG", "assets/Audio/Ogg/theme6.OGG");
		type.set ("assets/Audio/Ogg/theme6.OGG", AssetType.MUSIC);
		path.set ("assets/Audio/Ogg/theme7.OGG", "assets/Audio/Ogg/theme7.OGG");
		type.set ("assets/Audio/Ogg/theme7.OGG", AssetType.MUSIC);
		path.set ("assets/Audio/Ogg/theme8.OGG", "assets/Audio/Ogg/theme8.OGG");
		type.set ("assets/Audio/Ogg/theme8.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme8intro.OGG", "assets/Audio/Ogg/theme8intro.OGG");
		type.set ("assets/Audio/Ogg/theme8intro.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/theme9.OGG", "assets/Audio/Ogg/theme9.OGG");
		type.set ("assets/Audio/Ogg/theme9.OGG", AssetType.SOUND);
		path.set ("assets/Audio/Ogg/titlescreen.OGG", "assets/Audio/Ogg/titlescreen.OGG");
		type.set ("assets/Audio/Ogg/titlescreen.OGG", AssetType.SOUND);
		path.set ("assets/bgcolor.png", "assets/bgcolor.png");
		type.set ("assets/bgcolor.png", AssetType.IMAGE);
		path.set ("assets/black.png", "assets/black.png");
		type.set ("assets/black.png", AssetType.IMAGE);
		path.set ("assets/Dpad.png", "assets/Dpad.png");
		type.set ("assets/Dpad.png", AssetType.IMAGE);
		path.set ("assets/Sprites/1up0.png", "assets/Sprites/1up0.png");
		type.set ("assets/Sprites/1up0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/akyu0.png", "assets/Sprites/akyu0.png");
		type.set ("assets/Sprites/akyu0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/alice0.png", "assets/Sprites/alice0.png");
		type.set ("assets/Sprites/alice0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/aliceALT0.png", "assets/Sprites/aliceALT0.png");
		type.set ("assets/Sprites/aliceALT0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/aya0.png", "assets/Sprites/aya0.png");
		type.set ("assets/Sprites/aya0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/barrier0.png", "assets/Sprites/barrier0.png");
		type.set ("assets/Sprites/barrier0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/BG0.png", "assets/Sprites/BG0.png");
		type.set ("assets/Sprites/BG0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/BG1.png", "assets/Sprites/BG1.png");
		type.set ("assets/Sprites/BG1.png", AssetType.IMAGE);
		path.set ("assets/Sprites/BG2.png", "assets/Sprites/BG2.png");
		type.set ("assets/Sprites/BG2.png", AssetType.IMAGE);
		path.set ("assets/Sprites/BG3.png", "assets/Sprites/BG3.png");
		type.set ("assets/Sprites/BG3.png", AssetType.IMAGE);
		path.set ("assets/Sprites/BG4.png", "assets/Sprites/BG4.png");
		type.set ("assets/Sprites/BG4.png", AssetType.IMAGE);
		path.set ("assets/Sprites/BG5.png", "assets/Sprites/BG5.png");
		type.set ("assets/Sprites/BG5.png", AssetType.IMAGE);
		path.set ("assets/Sprites/block0.png", "assets/Sprites/block0.png");
		type.set ("assets/Sprites/block0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Blueufo0.png", "assets/Sprites/Blueufo0.png");
		type.set ("assets/Sprites/Blueufo0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/bullet0.png", "assets/Sprites/bullet0.png");
		type.set ("assets/Sprites/bullet0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/byakuren0.png", "assets/Sprites/byakuren0.png");
		type.set ("assets/Sprites/byakuren0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/chen0.png", "assets/Sprites/chen0.png");
		type.set ("assets/Sprites/chen0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/chiyuri0.png", "assets/Sprites/chiyuri0.png");
		type.set ("assets/Sprites/chiyuri0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/cirno0.png", "assets/Sprites/cirno0.png");
		type.set ("assets/Sprites/cirno0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/darkness0.png", "assets/Sprites/darkness0.png");
		type.set ("assets/Sprites/darkness0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen0.png", "assets/Sprites/EChen0.png");
		type.set ("assets/Sprites/EChen0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen1.png", "assets/Sprites/EChen1.png");
		type.set ("assets/Sprites/EChen1.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen2.png", "assets/Sprites/EChen2.png");
		type.set ("assets/Sprites/EChen2.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen3.png", "assets/Sprites/EChen3.png");
		type.set ("assets/Sprites/EChen3.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen4.png", "assets/Sprites/EChen4.png");
		type.set ("assets/Sprites/EChen4.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen5.png", "assets/Sprites/EChen5.png");
		type.set ("assets/Sprites/EChen5.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen6.png", "assets/Sprites/EChen6.png");
		type.set ("assets/Sprites/EChen6.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EChen7.png", "assets/Sprites/EChen7.png");
		type.set ("assets/Sprites/EChen7.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ECirno0.png", "assets/Sprites/ECirno0.png");
		type.set ("assets/Sprites/ECirno0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/eirin0.png", "assets/Sprites/eirin0.png");
		type.set ("assets/Sprites/eirin0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EKeine0.png", "assets/Sprites/EKeine0.png");
		type.set ("assets/Sprites/EKeine0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EKeineex0.png", "assets/Sprites/EKeineex0.png");
		type.set ("assets/Sprites/EKeineex0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/EKeineexflipped0.png", "assets/Sprites/EKeineexflipped0.png");
		type.set ("assets/Sprites/EKeineexflipped0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ellen0.png", "assets/Sprites/ellen0.png");
		type.set ("assets/Sprites/ellen0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/elly0.png", "assets/Sprites/elly0.png");
		type.set ("assets/Sprites/elly0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan0.png", "assets/Sprites/ERan0.png");
		type.set ("assets/Sprites/ERan0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan1.png", "assets/Sprites/ERan1.png");
		type.set ("assets/Sprites/ERan1.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan2.png", "assets/Sprites/ERan2.png");
		type.set ("assets/Sprites/ERan2.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan3.png", "assets/Sprites/ERan3.png");
		type.set ("assets/Sprites/ERan3.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan4.png", "assets/Sprites/ERan4.png");
		type.set ("assets/Sprites/ERan4.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan5.png", "assets/Sprites/ERan5.png");
		type.set ("assets/Sprites/ERan5.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan6.png", "assets/Sprites/ERan6.png");
		type.set ("assets/Sprites/ERan6.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ERan7.png", "assets/Sprites/ERan7.png");
		type.set ("assets/Sprites/ERan7.png", AssetType.IMAGE);
		path.set ("assets/Sprites/firecirno0.png", "assets/Sprites/firecirno0.png");
		type.set ("assets/Sprites/firecirno0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/flames0.png", "assets/Sprites/flames0.png");
		type.set ("assets/Sprites/flames0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/flames1.png", "assets/Sprites/flames1.png");
		type.set ("assets/Sprites/flames1.png", AssetType.IMAGE);
		path.set ("assets/Sprites/flames2.png", "assets/Sprites/flames2.png");
		type.set ("assets/Sprites/flames2.png", AssetType.IMAGE);
		path.set ("assets/Sprites/flandre0.png", "assets/Sprites/flandre0.png");
		type.set ("assets/Sprites/flandre0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/futo0.png", "assets/Sprites/futo0.png");
		type.set ("assets/Sprites/futo0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Gap0.png", "assets/Sprites/Gap0.png");
		type.set ("assets/Sprites/Gap0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/gengetsu0.png", "assets/Sprites/gengetsu0.png");
		type.set ("assets/Sprites/gengetsu0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Greenufo0.png", "assets/Sprites/Greenufo0.png");
		type.set ("assets/Sprites/Greenufo0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer0.png", "assets/Sprites/hammer0.png");
		type.set ("assets/Sprites/hammer0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer1.png", "assets/Sprites/hammer1.png");
		type.set ("assets/Sprites/hammer1.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer2.png", "assets/Sprites/hammer2.png");
		type.set ("assets/Sprites/hammer2.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer3.png", "assets/Sprites/hammer3.png");
		type.set ("assets/Sprites/hammer3.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer4.png", "assets/Sprites/hammer4.png");
		type.set ("assets/Sprites/hammer4.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer5.png", "assets/Sprites/hammer5.png");
		type.set ("assets/Sprites/hammer5.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer6.png", "assets/Sprites/hammer6.png");
		type.set ("assets/Sprites/hammer6.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hammer7.png", "assets/Sprites/hammer7.png");
		type.set ("assets/Sprites/hammer7.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hatate0.png", "assets/Sprites/hatate0.png");
		type.set ("assets/Sprites/hatate0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/hina0.png", "assets/Sprites/hina0.png");
		type.set ("assets/Sprites/hina0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/icyblock0.png", "assets/Sprites/icyblock0.png");
		type.set ("assets/Sprites/icyblock0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/iku0.png", "assets/Sprites/iku0.png");
		type.set ("assets/Sprites/iku0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kagerou0.png", "assets/Sprites/kagerou0.png");
		type.set ("assets/Sprites/kagerou0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kaguya0.png", "assets/Sprites/kaguya0.png");
		type.set ("assets/Sprites/kaguya0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kana0.png", "assets/Sprites/kana0.png");
		type.set ("assets/Sprites/kana0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kasen0.png", "assets/Sprites/kasen0.png");
		type.set ("assets/Sprites/kasen0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/keine0.png", "assets/Sprites/keine0.png");
		type.set ("assets/Sprites/keine0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kogasa0.png", "assets/Sprites/kogasa0.png");
		type.set ("assets/Sprites/kogasa0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/koishi0.png", "assets/Sprites/koishi0.png");
		type.set ("assets/Sprites/koishi0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kokoro0.png", "assets/Sprites/kokoro0.png");
		type.set ("assets/Sprites/kokoro0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/komachi0.png", "assets/Sprites/komachi0.png");
		type.set ("assets/Sprites/komachi0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kosuzu0.png", "assets/Sprites/kosuzu0.png");
		type.set ("assets/Sprites/kosuzu0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kotohime0.png", "assets/Sprites/kotohime0.png");
		type.set ("assets/Sprites/kotohime0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/kurumi0.png", "assets/Sprites/kurumi0.png");
		type.set ("assets/Sprites/kurumi0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/letty0.png", "assets/Sprites/letty0.png");
		type.set ("assets/Sprites/letty0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/lily0.png", "assets/Sprites/lily0.png");
		type.set ("assets/Sprites/lily0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/luize0.png", "assets/Sprites/luize0.png");
		type.set ("assets/Sprites/luize0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/lunachild0.png", "assets/Sprites/lunachild0.png");
		type.set ("assets/Sprites/lunachild0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/mai0.png", "assets/Sprites/mai0.png");
		type.set ("assets/Sprites/mai0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/mamizou0.png", "assets/Sprites/mamizou0.png");
		type.set ("assets/Sprites/mamizou0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/marisa0.png", "assets/Sprites/marisa0.png");
		type.set ("assets/Sprites/marisa0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/marisaALT0.png", "assets/Sprites/marisaALT0.png");
		type.set ("assets/Sprites/marisaALT0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/medicine0.png", "assets/Sprites/medicine0.png");
		type.set ("assets/Sprites/medicine0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/meiling0.png", "assets/Sprites/meiling0.png");
		type.set ("assets/Sprites/meiling0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/meilingALT0.png", "assets/Sprites/meilingALT0.png");
		type.set ("assets/Sprites/meilingALT0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/meira0.png", "assets/Sprites/meira0.png");
		type.set ("assets/Sprites/meira0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/mima0.png", "assets/Sprites/mima0.png");
		type.set ("assets/Sprites/mima0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/minoriko0.png", "assets/Sprites/minoriko0.png");
		type.set ("assets/Sprites/minoriko0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/mokou0.png", "assets/Sprites/mokou0.png");
		type.set ("assets/Sprites/mokou0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/momiji0.png", "assets/Sprites/momiji0.png");
		type.set ("assets/Sprites/momiji0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/mugetsu0.png", "assets/Sprites/mugetsu0.png");
		type.set ("assets/Sprites/mugetsu0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/murasa0.png", "assets/Sprites/murasa0.png");
		type.set ("assets/Sprites/murasa0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Mystia0.png", "assets/Sprites/Mystia0.png");
		type.set ("assets/Sprites/Mystia0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Mystia1.png", "assets/Sprites/Mystia1.png");
		type.set ("assets/Sprites/Mystia1.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Mystiaflipped0.png", "assets/Sprites/Mystiaflipped0.png");
		type.set ("assets/Sprites/Mystiaflipped0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/nazrin0.png", "assets/Sprites/nazrin0.png");
		type.set ("assets/Sprites/nazrin0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/nitori0.png", "assets/Sprites/nitori0.png");
		type.set ("assets/Sprites/nitori0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/nue0.png", "assets/Sprites/nue0.png");
		type.set ("assets/Sprites/nue0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/orange0.png", "assets/Sprites/orange0.png");
		type.set ("assets/Sprites/orange0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/orin0.png", "assets/Sprites/orin0.png");
		type.set ("assets/Sprites/orin0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/parsee0.png", "assets/Sprites/parsee0.png");
		type.set ("assets/Sprites/parsee0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/patchouli0.png", "assets/Sprites/patchouli0.png");
		type.set ("assets/Sprites/patchouli0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/pika0.png", "assets/Sprites/pika0.png");
		type.set ("assets/Sprites/pika0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Point0.png", "assets/Sprites/Point0.png");
		type.set ("assets/Sprites/Point0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/POW0.png", "assets/Sprites/POW0.png");
		type.set ("assets/Sprites/POW0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/prinny0.png", "assets/Sprites/prinny0.png");
		type.set ("assets/Sprites/prinny0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/ran0.png", "assets/Sprites/ran0.png");
		type.set ("assets/Sprites/ran0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/RedFairy0.png", "assets/Sprites/RedFairy0.png");
		type.set ("assets/Sprites/RedFairy0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/RedFairyflipped0.png", "assets/Sprites/RedFairyflipped0.png");
		type.set ("assets/Sprites/RedFairyflipped0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/Redufo0.png", "assets/Sprites/Redufo0.png");
		type.set ("assets/Sprites/Redufo0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/reimu0.png", "assets/Sprites/reimu0.png");
		type.set ("assets/Sprites/reimu0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/reimuALT0.png", "assets/Sprites/reimuALT0.png");
		type.set ("assets/Sprites/reimuALT0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/reisen0.png", "assets/Sprites/reisen0.png");
		type.set ("assets/Sprites/reisen0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/remilia0.png", "assets/Sprites/remilia0.png");
		type.set ("assets/Sprites/remilia0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/rika0.png", "assets/Sprites/rika0.png");
		type.set ("assets/Sprites/rika0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/rikako0.png", "assets/Sprites/rikako0.png");
		type.set ("assets/Sprites/rikako0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/rumia0.png", "assets/Sprites/rumia0.png");
		type.set ("assets/Sprites/rumia0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/sakuya0.png", "assets/Sprites/sakuya0.png");
		type.set ("assets/Sprites/sakuya0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/sakuyaALT0.png", "assets/Sprites/sakuyaALT0.png");
		type.set ("assets/Sprites/sakuyaALT0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/sanae0.png", "assets/Sprites/sanae0.png");
		type.set ("assets/Sprites/sanae0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/sanaeALT0.png", "assets/Sprites/sanaeALT0.png");
		type.set ("assets/Sprites/sanaeALT0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/sarah0.png", "assets/Sprites/sarah0.png");
		type.set ("assets/Sprites/sarah0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/satori0.png", "assets/Sprites/satori0.png");
		type.set ("assets/Sprites/satori0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/seiga0.png", "assets/Sprites/seiga0.png");
		type.set ("assets/Sprites/seiga0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/seija0.png", "assets/Sprites/seija0.png");
		type.set ("assets/Sprites/seija0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/sekibanki0.png", "assets/Sprites/sekibanki0.png");
		type.set ("assets/Sprites/sekibanki0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/shanghai0.png", "assets/Sprites/shanghai0.png");
		type.set ("assets/Sprites/shanghai0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/shikieiki0.png", "assets/Sprites/shikieiki0.png");
		type.set ("assets/Sprites/shikieiki0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/shinmyoumaru0.png", "assets/Sprites/shinmyoumaru0.png");
		type.set ("assets/Sprites/shinmyoumaru0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/shizuha0.png", "assets/Sprites/shizuha0.png");
		type.set ("assets/Sprites/shizuha0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/shou0.png", "assets/Sprites/shou0.png");
		type.set ("assets/Sprites/shou0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/starsaphire0.png", "assets/Sprites/starsaphire0.png");
		type.set ("assets/Sprites/starsaphire0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/suika0.png", "assets/Sprites/suika0.png");
		type.set ("assets/Sprites/suika0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/sunnymilk0.png", "assets/Sprites/sunnymilk0.png");
		type.set ("assets/Sprites/sunnymilk0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/suwako0.png", "assets/Sprites/suwako0.png");
		type.set ("assets/Sprites/suwako0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table0.png", "assets/Sprites/table0.png");
		type.set ("assets/Sprites/table0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table1.png", "assets/Sprites/table1.png");
		type.set ("assets/Sprites/table1.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table2.png", "assets/Sprites/table2.png");
		type.set ("assets/Sprites/table2.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table3.png", "assets/Sprites/table3.png");
		type.set ("assets/Sprites/table3.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table4.png", "assets/Sprites/table4.png");
		type.set ("assets/Sprites/table4.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table5.png", "assets/Sprites/table5.png");
		type.set ("assets/Sprites/table5.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table6.png", "assets/Sprites/table6.png");
		type.set ("assets/Sprites/table6.png", AssetType.IMAGE);
		path.set ("assets/Sprites/table7.png", "assets/Sprites/table7.png");
		type.set ("assets/Sprites/table7.png", AssetType.IMAGE);
		path.set ("assets/Sprites/tenshi0.png", "assets/Sprites/tenshi0.png");
		type.set ("assets/Sprites/tenshi0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/tewi0.png", "assets/Sprites/tewi0.png");
		type.set ("assets/Sprites/tewi0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/titlescreen0.png", "assets/Sprites/titlescreen0.png");
		type.set ("assets/Sprites/titlescreen0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/tokiko0.png", "assets/Sprites/tokiko0.png");
		type.set ("assets/Sprites/tokiko0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/utsuho0.png", "assets/Sprites/utsuho0.png");
		type.set ("assets/Sprites/utsuho0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/wriggle0.png", "assets/Sprites/wriggle0.png");
		type.set ("assets/Sprites/wriggle0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yoshika0.png", "assets/Sprites/yoshika0.png");
		type.set ("assets/Sprites/yoshika0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/youmu0.png", "assets/Sprites/youmu0.png");
		type.set ("assets/Sprites/youmu0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yukari0.png", "assets/Sprites/yukari0.png");
		type.set ("assets/Sprites/yukari0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yuki0.png", "assets/Sprites/yuki0.png");
		type.set ("assets/Sprites/yuki0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yumeko0.png", "assets/Sprites/yumeko0.png");
		type.set ("assets/Sprites/yumeko0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yumemi0.png", "assets/Sprites/yumemi0.png");
		type.set ("assets/Sprites/yumemi0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yuuka0.png", "assets/Sprites/yuuka0.png");
		type.set ("assets/Sprites/yuuka0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yuukaALT0.png", "assets/Sprites/yuukaALT0.png");
		type.set ("assets/Sprites/yuukaALT0.png", AssetType.IMAGE);
		path.set ("assets/Sprites/yuyuko0.png", "assets/Sprites/yuyuko0.png");
		type.set ("assets/Sprites/yuyuko0.png", AssetType.IMAGE);
		
		
		#elseif html5
		
		var id;
		id = "assets/Audio/Ogg/bonk.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/characterselect.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/collectcoin.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/died.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/finalkill.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/fireballspawn.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/gameover.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/killenemy.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/nextlevel.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/pow.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/respawn.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/spawncoin.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/startgame.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/step1.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/step2.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/step3.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme1.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme10.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme11.OGG";
		path.set (id, id);
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Ogg/theme12.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme12intro.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme2.OGG";
		path.set (id, id);
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Ogg/theme3.OGG";
		path.set (id, id);
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Ogg/theme4.OGG";
		path.set (id, id);
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Ogg/theme5.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme6.OGG";
		path.set (id, id);
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Ogg/theme7.OGG";
		path.set (id, id);
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Ogg/theme8.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme8intro.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/theme9.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/Audio/Ogg/titlescreen.OGG";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/bgcolor.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/black.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Dpad.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/1up0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/akyu0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/alice0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/aliceALT0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/aya0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/barrier0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BG0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BG1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BG2.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BG3.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BG4.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BG5.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/block0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Blueufo0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bullet0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/byakuren0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/chen0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/chiyuri0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/cirno0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/darkness0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen2.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen3.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen4.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen5.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen6.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen7.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ECirno0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/eirin0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EKeine0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EKeineex0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EKeineexflipped0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ellen0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/elly0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan2.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan3.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan4.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan5.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan6.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan7.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/firecirno0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/flames0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/flames1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/flames2.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/flandre0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/futo0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Gap0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/gengetsu0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Greenufo0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer2.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer3.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer4.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer5.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer6.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer7.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hatate0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hina0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/icyblock0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/iku0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kagerou0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kaguya0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kana0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kasen0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/keine0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kogasa0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/koishi0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kokoro0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/komachi0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kosuzu0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kotohime0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kurumi0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/letty0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lily0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/luize0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lunachild0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mai0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mamizou0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/marisa0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/marisaALT0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/medicine0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/meiling0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/meilingALT0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/meira0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mima0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/minoriko0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mokou0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/momiji0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mugetsu0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/murasa0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Mystia0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Mystia1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Mystiaflipped0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/nazrin0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/nitori0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/nue0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/orange0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/orin0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/parsee0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/patchouli0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/pika0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Point0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/POW0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/prinny0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ran0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/RedFairy0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/RedFairyflipped0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Redufo0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/reimu0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/reimuALT0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/reisen0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/remilia0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rika0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rikako0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rumia0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sakuya0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sakuyaALT0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sanae0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sanaeALT0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sarah0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/satori0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/seiga0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/seija0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sekibanki0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shanghai0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shikieiki0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shinmyoumaru0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shizuha0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shou0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/starsaphire0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/suika0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sunnymilk0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/suwako0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table2.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table3.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table4.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table5.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table6.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table7.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tenshi0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tewi0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/titlescreen0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tokiko0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/utsuho0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/wriggle0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yoshika0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/youmu0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yukari0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yuki0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yumeko0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yumemi0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yuuka0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yuukaALT0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yuyuko0.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		
		
		#else
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		#if (windows || mac || linux)
		
		var useManifest = false;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		
		
		if (useManifest) {
			
			loadManifest ();
			
			if (Sys.args ().indexOf ("-livereload") > -1) {
				
				var path = FileSystem.fullPath ("manifest");
				lastModified = FileSystem.stat (path).mtime.getTime ();
				
				timer = new Timer (2000);
				timer.run = function () {
					
					var modified = FileSystem.stat (path).mtime.getTime ();
					
					if (modified > lastModified) {
						
						lastModified = modified;
						loadManifest ();
						
						if (eventCallback != null) {
							
							eventCallback (this, "change");
							
						}
						
					}
					
				}
				
			}
			
		}
		
		#else
		
		loadManifest ();
		
		#end
		#end
		
	}
	
	
	public override function exists (id:String, type:AssetType):Bool {
		
		var assetType = this.type.get (id);
		
		#if pixi
		
		if (assetType == IMAGE) {
			
			return true;
			
		} else {
			
			return false;
			
		}
		
		#end
		
		if (assetType != null) {
			
			if (assetType == type || ((type == SOUND || type == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if ((assetType == BINARY || assetType == TEXT) && type == BINARY) {
				
				return true;
				
			} else if (path.exists (id)) {
				
				return true;
				
			}
			
			#else
			
			if (type == BINARY || type == null || (assetType == BINARY && type == TEXT)) {
				
				return true;
				
			}
			
			#end
			
		}
		
		return false;
		
	}
	
	
	public override function getBitmapData (id:String):BitmapData {
		
		#if pixi
		
		return BitmapData.fromImage (path.get (id));
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), BitmapData);
		
		#elseif openfl_html5
		
		return BitmapData.fromImage (ApplicationMain.images.get (path.get (id)));
		
		#elseif js
		
		return cast (ApplicationMain.loaders.get (path.get (id)).contentLoaderInfo.content, Bitmap).bitmapData;
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), BitmapData);
		else return BitmapData.load (path.get (id));
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if (flash)
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);

		#elseif (js || openfl_html5 || pixi)
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			bytes = new ByteArray ();
			bytes.writeUTFBytes (data);
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}

		if (bytes != null) {
			
			bytes.position = 0;
			return bytes;
			
		} else {
			
			return null;
		}
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), ByteArray);
		else return ByteArray.readFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getFont (id:String):Font {
		
		#if pixi
		
		return null;
		
		#elseif (flash || js)
		
		return cast (Type.createInstance (className.get (id), []), Font);
		
		#else
		
		if (className.exists(id)) {
			var fontClass = className.get(id);
			Font.registerFont(fontClass);
			return cast (Type.createInstance (fontClass, []), Font);
		} else return new Font (path.get (id));
		
		#end
		
	}
	
	
	public override function getMusic (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif openfl_html5
		
		var sound = new Sound ();
		sound.__buffer = true;
		sound.load (new URLRequest (path.get (id)));
		return sound; 
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, true);
		
		#end
		
	}
	
	
	public override function getPath (id:String):String {
		
		#if ios
		
		return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		#else
		
		return path.get (id);
		
		#end
		
	}
	
	
	public override function getSound (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, type.get (id) == MUSIC);
		
		#end
		
	}
	
	
	public override function getText (id:String):String {
		
		#if js
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			return cast data;
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}
		
		if (bytes != null) {
			
			bytes.position = 0;
			return bytes.readUTFBytes (bytes.length);
			
		} else {
			
			return null;
		}
		
		#else
		
		var bytes = getBytes (id);
		
		if (bytes == null) {
			
			return null;
			
		} else {
			
			return bytes.readUTFBytes (bytes.length);
			
		}
		
		#end
		
	}
	
	
	public override function isLocal (id:String, type:AssetType):Bool {
		
		#if flash
		
		if (type != AssetType.MUSIC && type != AssetType.SOUND) {
			
			return className.exists (id);
			
		}
		
		#end
		
		return true;
		
	}
	
	
	public override function list (type:AssetType):Array<String> {
		
		var items = [];
		
		for (id in this.type.keys ()) {
			
			if (type == null || exists (id, type)) {
				
				items.push (id);
				
			}
			
		}
		
		return items;
		
	}
	
	
	public override function loadBitmapData (id:String, handler:BitmapData -> Void):Void {
		
		#if pixi
		
		handler (getBitmapData (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBitmapData (id));
			
		}
		
		#else
		
		handler (getBitmapData (id));
		
		#end
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		#if pixi
		
		handler (getBytes (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bytes = new ByteArray ();
				bytes.writeUTFBytes (event.currentTarget.data);
				bytes.position = 0;
				
				handler (bytes);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#else
		
		handler (getBytes (id));
		
		#end
		
	}
	
	
	public override function loadFont (id:String, handler:Font -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getFont (id));
			
		//}
		
		#else
		
		handler (getFont (id));
		
		#end
		
	}
	
	
	#if (!flash && !html5)
	private function loadManifest ():Void {
		
		try {
			
			#if blackberry
			var bytes = ByteArray.readFile ("app/native/manifest");
			#elseif tizen
			var bytes = ByteArray.readFile ("../res/manifest");
			#elseif emscripten
			var bytes = ByteArray.readFile ("assets/manifest");
			#else
			var bytes = ByteArray.readFile ("manifest");
			#end
			
			if (bytes != null) {
				
				bytes.position = 0;
				
				if (bytes.length > 0) {
					
					var data = bytes.readUTFBytes (bytes.length);
					
					if (data != null && data.length > 0) {
						
						var manifest:Array<Dynamic> = Unserializer.run (data);
						
						for (asset in manifest) {
							
							if (!className.exists (asset.id)) {
								
								path.set (asset.id, asset.path);
								type.set (asset.id, Type.createEnum (AssetType, asset.type));
								
							}
							
						}
						
					}
					
				}
				
			} else {
				
				trace ("Warning: Could not load asset manifest (bytes was null)");
				
			}
		
		} catch (e:Dynamic) {
			
			trace ('Warning: Could not load asset manifest (${e})');
			
		}
		
	}
	#end
	
	
	public override function loadMusic (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getMusic (id));
			
		//}
		
		#else
		
		handler (getMusic (id));
		
		#end
		
	}
	
	
	public override function loadSound (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getSound (id));
			
		//}
		
		#else
		
		handler (getSound (id));
		
		#end
		
	}
	
	
	public override function loadText (id:String, handler:String -> Void):Void {
		
		#if js
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (event.currentTarget.data);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getText (id));
			
		}
		
		#else
		
		var callback = function (bytes:ByteArray):Void {
			
			if (bytes == null) {
				
				handler (null);
				
			} else {
				
				handler (bytes.readUTFBytes (bytes.length));
				
			}
			
		}
		
		loadBytes (id, callback);
		
		#end
		
	}
	
	
}


#if pixi
#elseif flash





































































































































































































#elseif html5





































































































































































































#else

#if (windows || mac || linux)







#else




#end

#end
