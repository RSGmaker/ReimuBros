package;


import haxe.Timer;
import haxe.Unserializer;
import lime.app.Preloader;
import lime.audio.openal.AL;
import lime.audio.AudioBuffer;
import lime.graphics.Font;
import lime.graphics.Image;
import lime.utils.ByteArray;
import lime.utils.UInt8Array;
import lime.Assets;

#if (sys || nodejs)
import sys.FileSystem;
#end

#if flash
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Loader;
import flash.events.Event;
import flash.media.Sound;
import flash.net.URLLoader;
import flash.net.URLRequest;
#end


class DefaultAssetLibrary extends AssetLibrary {
	
	
	public var className (default, null) = new Map <String, Dynamic> ();
	public var path (default, null) = new Map <String, String> ();
	public var type (default, null) = new Map <String, AssetType> ();
	
	private var lastModified:Float;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		#if flash
		
		className.set ("assets/Audio/Ogg/bonk.OGG", __ASSET__assets_audio_ogg_bonk_ogg);
		type.set ("assets/Audio/Ogg/bonk.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/characterselect.OGG", __ASSET__assets_audio_ogg_characterselect_ogg);
		type.set ("assets/Audio/Ogg/characterselect.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/collectcoin.OGG", __ASSET__assets_audio_ogg_collectcoin_ogg);
		type.set ("assets/Audio/Ogg/collectcoin.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/died.OGG", __ASSET__assets_audio_ogg_died_ogg);
		type.set ("assets/Audio/Ogg/died.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/extend.OGG", __ASSET__assets_audio_ogg_extend_ogg);
		type.set ("assets/Audio/Ogg/extend.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/finalkill.OGG", __ASSET__assets_audio_ogg_finalkill_ogg);
		type.set ("assets/Audio/Ogg/finalkill.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/fireballspawn.OGG", __ASSET__assets_audio_ogg_fireballspawn_ogg);
		type.set ("assets/Audio/Ogg/fireballspawn.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/gameover.OGG", __ASSET__assets_audio_ogg_gameover_ogg);
		type.set ("assets/Audio/Ogg/gameover.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/killenemy.OGG", __ASSET__assets_audio_ogg_killenemy_ogg);
		type.set ("assets/Audio/Ogg/killenemy.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/masterspark.OGG", __ASSET__assets_audio_ogg_masterspark_ogg);
		type.set ("assets/Audio/Ogg/masterspark.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/nextlevel.OGG", __ASSET__assets_audio_ogg_nextlevel_ogg);
		type.set ("assets/Audio/Ogg/nextlevel.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/pow.OGG", __ASSET__assets_audio_ogg_pow_ogg);
		type.set ("assets/Audio/Ogg/pow.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/respawn.OGG", __ASSET__assets_audio_ogg_respawn_ogg);
		type.set ("assets/Audio/Ogg/respawn.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/spawncoin.OGG", __ASSET__assets_audio_ogg_spawncoin_ogg);
		type.set ("assets/Audio/Ogg/spawncoin.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/startgame.OGG", __ASSET__assets_audio_ogg_startgame_ogg);
		type.set ("assets/Audio/Ogg/startgame.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/step1.OGG", __ASSET__assets_audio_ogg_step1_ogg);
		type.set ("assets/Audio/Ogg/step1.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/step2.OGG", __ASSET__assets_audio_ogg_step2_ogg);
		type.set ("assets/Audio/Ogg/step2.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/step3.OGG", __ASSET__assets_audio_ogg_step3_ogg);
		type.set ("assets/Audio/Ogg/step3.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme1.OGG", __ASSET__assets_audio_ogg_theme1_ogg);
		type.set ("assets/Audio/Ogg/theme1.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme10.OGG", __ASSET__assets_audio_ogg_theme10_ogg);
		type.set ("assets/Audio/Ogg/theme10.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme11.OGG", __ASSET__assets_audio_ogg_theme11_ogg);
		type.set ("assets/Audio/Ogg/theme11.OGG", AssetType.MUSIC);
		className.set ("assets/Audio/Ogg/theme12.OGG", __ASSET__assets_audio_ogg_theme12_ogg);
		type.set ("assets/Audio/Ogg/theme12.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme12intro.OGG", __ASSET__assets_audio_ogg_theme12intro_ogg);
		type.set ("assets/Audio/Ogg/theme12intro.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme2.OGG", __ASSET__assets_audio_ogg_theme2_ogg);
		type.set ("assets/Audio/Ogg/theme2.OGG", AssetType.MUSIC);
		className.set ("assets/Audio/Ogg/theme3.OGG", __ASSET__assets_audio_ogg_theme3_ogg);
		type.set ("assets/Audio/Ogg/theme3.OGG", AssetType.MUSIC);
		className.set ("assets/Audio/Ogg/theme4.OGG", __ASSET__assets_audio_ogg_theme4_ogg);
		type.set ("assets/Audio/Ogg/theme4.OGG", AssetType.MUSIC);
		className.set ("assets/Audio/Ogg/theme5.OGG", __ASSET__assets_audio_ogg_theme5_ogg);
		type.set ("assets/Audio/Ogg/theme5.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme6.OGG", __ASSET__assets_audio_ogg_theme6_ogg);
		type.set ("assets/Audio/Ogg/theme6.OGG", AssetType.MUSIC);
		className.set ("assets/Audio/Ogg/theme7.OGG", __ASSET__assets_audio_ogg_theme7_ogg);
		type.set ("assets/Audio/Ogg/theme7.OGG", AssetType.MUSIC);
		className.set ("assets/Audio/Ogg/theme8.OGG", __ASSET__assets_audio_ogg_theme8_ogg);
		type.set ("assets/Audio/Ogg/theme8.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme8intro.OGG", __ASSET__assets_audio_ogg_theme8intro_ogg);
		type.set ("assets/Audio/Ogg/theme8intro.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/theme9.OGG", __ASSET__assets_audio_ogg_theme9_ogg);
		type.set ("assets/Audio/Ogg/theme9.OGG", AssetType.SOUND);
		className.set ("assets/Audio/Ogg/titlescreen.OGG", __ASSET__assets_audio_ogg_titlescreen_ogg);
		type.set ("assets/Audio/Ogg/titlescreen.OGG", AssetType.SOUND);
		className.set ("assets/bgcolor.png", __ASSET__assets_bgcolor_png);
		type.set ("assets/bgcolor.png", AssetType.IMAGE);
		className.set ("assets/black.png", __ASSET__assets_black_png);
		type.set ("assets/black.png", AssetType.IMAGE);
		className.set ("assets/Dpad.png", __ASSET__assets_dpad_png);
		type.set ("assets/Dpad.png", AssetType.IMAGE);
		className.set ("assets/Sprites/1up0.png", __ASSET__assets_sprites_1up0_png);
		type.set ("assets/Sprites/1up0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/akyu0.png", __ASSET__assets_sprites_akyu0_png);
		type.set ("assets/Sprites/akyu0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/alice0.png", __ASSET__assets_sprites_alice0_png);
		type.set ("assets/Sprites/alice0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/aliceALT0.png", __ASSET__assets_sprites_alicealt0_png);
		type.set ("assets/Sprites/aliceALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/aya0.png", __ASSET__assets_sprites_aya0_png);
		type.set ("assets/Sprites/aya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ayana0.png", __ASSET__assets_sprites_ayana0_png);
		type.set ("assets/Sprites/ayana0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/balloon0.png", __ASSET__assets_sprites_balloon0_png);
		type.set ("assets/Sprites/balloon0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/barrier0.png", __ASSET__assets_sprites_barrier0_png);
		type.set ("assets/Sprites/barrier0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/benben0.png", __ASSET__assets_sprites_benben0_png);
		type.set ("assets/Sprites/benben0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BG0.png", __ASSET__assets_sprites_bg0_png);
		type.set ("assets/Sprites/BG0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BG1.png", __ASSET__assets_sprites_bg1_png);
		type.set ("assets/Sprites/BG1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BG2.png", __ASSET__assets_sprites_bg2_png);
		type.set ("assets/Sprites/BG2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BG3.png", __ASSET__assets_sprites_bg3_png);
		type.set ("assets/Sprites/BG3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BG4.png", __ASSET__assets_sprites_bg4_png);
		type.set ("assets/Sprites/BG4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BG5.png", __ASSET__assets_sprites_bg5_png);
		type.set ("assets/Sprites/BG5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/black0.png", __ASSET__assets_sprites_black0_png);
		type.set ("assets/Sprites/black0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/block0.png", __ASSET__assets_sprites_block0_png);
		type.set ("assets/Sprites/block0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BlueFairy0.png", __ASSET__assets_sprites_bluefairy0_png);
		type.set ("assets/Sprites/BlueFairy0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/BlueFairyflipped0.png", __ASSET__assets_sprites_bluefairyflipped0_png);
		type.set ("assets/Sprites/BlueFairyflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Blueufo0.png", __ASSET__assets_sprites_blueufo0_png);
		type.set ("assets/Sprites/Blueufo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bomb0.png", __ASSET__assets_sprites_bomb0_png);
		type.set ("assets/Sprites/bomb0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bullet0.png", __ASSET__assets_sprites_bullet0_png);
		type.set ("assets/Sprites/bullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/byakuren0.png", __ASSET__assets_sprites_byakuren0_png);
		type.set ("assets/Sprites/byakuren0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/charblock0.png", __ASSET__assets_sprites_charblock0_png);
		type.set ("assets/Sprites/charblock0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/chen0.png", __ASSET__assets_sprites_chen0_png);
		type.set ("assets/Sprites/chen0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/chiyuri0.png", __ASSET__assets_sprites_chiyuri0_png);
		type.set ("assets/Sprites/chiyuri0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/cirno0.png", __ASSET__assets_sprites_cirno0_png);
		type.set ("assets/Sprites/cirno0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/CSBG0.png", __ASSET__assets_sprites_csbg0_png);
		type.set ("assets/Sprites/CSBG0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/daiyousei0.png", __ASSET__assets_sprites_daiyousei0_png);
		type.set ("assets/Sprites/daiyousei0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/darkness0.png", __ASSET__assets_sprites_darkness0_png);
		type.set ("assets/Sprites/darkness0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/diosakuya0.png", __ASSET__assets_sprites_diosakuya0_png);
		type.set ("assets/Sprites/diosakuya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/doremy0.png", __ASSET__assets_sprites_doremy0_png);
		type.set ("assets/Sprites/doremy0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen0.png", __ASSET__assets_sprites_echen0_png);
		type.set ("assets/Sprites/EChen0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen1.png", __ASSET__assets_sprites_echen1_png);
		type.set ("assets/Sprites/EChen1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen10.png", __ASSET__assets_sprites_echen10_png);
		type.set ("assets/Sprites/EChen10.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen11.png", __ASSET__assets_sprites_echen11_png);
		type.set ("assets/Sprites/EChen11.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen12.png", __ASSET__assets_sprites_echen12_png);
		type.set ("assets/Sprites/EChen12.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen13.png", __ASSET__assets_sprites_echen13_png);
		type.set ("assets/Sprites/EChen13.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen14.png", __ASSET__assets_sprites_echen14_png);
		type.set ("assets/Sprites/EChen14.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen15.png", __ASSET__assets_sprites_echen15_png);
		type.set ("assets/Sprites/EChen15.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen2.png", __ASSET__assets_sprites_echen2_png);
		type.set ("assets/Sprites/EChen2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen3.png", __ASSET__assets_sprites_echen3_png);
		type.set ("assets/Sprites/EChen3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen4.png", __ASSET__assets_sprites_echen4_png);
		type.set ("assets/Sprites/EChen4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen5.png", __ASSET__assets_sprites_echen5_png);
		type.set ("assets/Sprites/EChen5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen6.png", __ASSET__assets_sprites_echen6_png);
		type.set ("assets/Sprites/EChen6.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen7.png", __ASSET__assets_sprites_echen7_png);
		type.set ("assets/Sprites/EChen7.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen8.png", __ASSET__assets_sprites_echen8_png);
		type.set ("assets/Sprites/EChen8.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EChen9.png", __ASSET__assets_sprites_echen9_png);
		type.set ("assets/Sprites/EChen9.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ECirno0.png", __ASSET__assets_sprites_ecirno0_png);
		type.set ("assets/Sprites/ECirno0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/eirin0.png", __ASSET__assets_sprites_eirin0_png);
		type.set ("assets/Sprites/eirin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EKeine0.png", __ASSET__assets_sprites_ekeine0_png);
		type.set ("assets/Sprites/EKeine0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EKeineex0.png", __ASSET__assets_sprites_ekeineex0_png);
		type.set ("assets/Sprites/EKeineex0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EKeineexflipped0.png", __ASSET__assets_sprites_ekeineexflipped0_png);
		type.set ("assets/Sprites/EKeineexflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/electriccirno0.png", __ASSET__assets_sprites_electriccirno0_png);
		type.set ("assets/Sprites/electriccirno0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/elis0.png", __ASSET__assets_sprites_elis0_png);
		type.set ("assets/Sprites/elis0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ellen0.png", __ASSET__assets_sprites_ellen0_png);
		type.set ("assets/Sprites/ellen0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/elly0.png", __ASSET__assets_sprites_elly0_png);
		type.set ("assets/Sprites/elly0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EMystia0.png", __ASSET__assets_sprites_emystia0_png);
		type.set ("assets/Sprites/EMystia0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EMystia1.png", __ASSET__assets_sprites_emystia1_png);
		type.set ("assets/Sprites/EMystia1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EMystiaflipped0.png", __ASSET__assets_sprites_emystiaflipped0_png);
		type.set ("assets/Sprites/EMystiaflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan0.png", __ASSET__assets_sprites_eran0_png);
		type.set ("assets/Sprites/ERan0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan1.png", __ASSET__assets_sprites_eran1_png);
		type.set ("assets/Sprites/ERan1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan10.png", __ASSET__assets_sprites_eran10_png);
		type.set ("assets/Sprites/ERan10.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan11.png", __ASSET__assets_sprites_eran11_png);
		type.set ("assets/Sprites/ERan11.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan12.png", __ASSET__assets_sprites_eran12_png);
		type.set ("assets/Sprites/ERan12.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan13.png", __ASSET__assets_sprites_eran13_png);
		type.set ("assets/Sprites/ERan13.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan14.png", __ASSET__assets_sprites_eran14_png);
		type.set ("assets/Sprites/ERan14.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan15.png", __ASSET__assets_sprites_eran15_png);
		type.set ("assets/Sprites/ERan15.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan2.png", __ASSET__assets_sprites_eran2_png);
		type.set ("assets/Sprites/ERan2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan3.png", __ASSET__assets_sprites_eran3_png);
		type.set ("assets/Sprites/ERan3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan4.png", __ASSET__assets_sprites_eran4_png);
		type.set ("assets/Sprites/ERan4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan5.png", __ASSET__assets_sprites_eran5_png);
		type.set ("assets/Sprites/ERan5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan6.png", __ASSET__assets_sprites_eran6_png);
		type.set ("assets/Sprites/ERan6.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan7.png", __ASSET__assets_sprites_eran7_png);
		type.set ("assets/Sprites/ERan7.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan8.png", __ASSET__assets_sprites_eran8_png);
		type.set ("assets/Sprites/ERan8.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ERan9.png", __ASSET__assets_sprites_eran9_png);
		type.set ("assets/Sprites/ERan9.png", AssetType.IMAGE);
		className.set ("assets/Sprites/evilyuuka0.png", __ASSET__assets_sprites_evilyuuka0_png);
		type.set ("assets/Sprites/evilyuuka0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/exkeine0.png", __ASSET__assets_sprites_exkeine0_png);
		type.set ("assets/Sprites/exkeine0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/firecirno0.png", __ASSET__assets_sprites_firecirno0_png);
		type.set ("assets/Sprites/firecirno0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flames0.png", __ASSET__assets_sprites_flames0_png);
		type.set ("assets/Sprites/flames0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flames1.png", __ASSET__assets_sprites_flames1_png);
		type.set ("assets/Sprites/flames1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flames2.png", __ASSET__assets_sprites_flames2_png);
		type.set ("assets/Sprites/flames2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flandre0.png", __ASSET__assets_sprites_flandre0_png);
		type.set ("assets/Sprites/flandre0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/futo0.png", __ASSET__assets_sprites_futo0_png);
		type.set ("assets/Sprites/futo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Gap0.png", __ASSET__assets_sprites_gap0_png);
		type.set ("assets/Sprites/Gap0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/gengetsu0.png", __ASSET__assets_sprites_gengetsu0_png);
		type.set ("assets/Sprites/gengetsu0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/giantcirno0.png", __ASSET__assets_sprites_giantcirno0_png);
		type.set ("assets/Sprites/giantcirno0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/giantsuika0.png", __ASSET__assets_sprites_giantsuika0_png);
		type.set ("assets/Sprites/giantsuika0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Greenufo0.png", __ASSET__assets_sprites_greenufo0_png);
		type.set ("assets/Sprites/Greenufo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer0.png", __ASSET__assets_sprites_hammer0_png);
		type.set ("assets/Sprites/hammer0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer1.png", __ASSET__assets_sprites_hammer1_png);
		type.set ("assets/Sprites/hammer1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer10.png", __ASSET__assets_sprites_hammer10_png);
		type.set ("assets/Sprites/hammer10.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer11.png", __ASSET__assets_sprites_hammer11_png);
		type.set ("assets/Sprites/hammer11.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer12.png", __ASSET__assets_sprites_hammer12_png);
		type.set ("assets/Sprites/hammer12.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer13.png", __ASSET__assets_sprites_hammer13_png);
		type.set ("assets/Sprites/hammer13.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer14.png", __ASSET__assets_sprites_hammer14_png);
		type.set ("assets/Sprites/hammer14.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer15.png", __ASSET__assets_sprites_hammer15_png);
		type.set ("assets/Sprites/hammer15.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer2.png", __ASSET__assets_sprites_hammer2_png);
		type.set ("assets/Sprites/hammer2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer3.png", __ASSET__assets_sprites_hammer3_png);
		type.set ("assets/Sprites/hammer3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer4.png", __ASSET__assets_sprites_hammer4_png);
		type.set ("assets/Sprites/hammer4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer5.png", __ASSET__assets_sprites_hammer5_png);
		type.set ("assets/Sprites/hammer5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer6.png", __ASSET__assets_sprites_hammer6_png);
		type.set ("assets/Sprites/hammer6.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer7.png", __ASSET__assets_sprites_hammer7_png);
		type.set ("assets/Sprites/hammer7.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer8.png", __ASSET__assets_sprites_hammer8_png);
		type.set ("assets/Sprites/hammer8.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hammer9.png", __ASSET__assets_sprites_hammer9_png);
		type.set ("assets/Sprites/hammer9.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hatate0.png", __ASSET__assets_sprites_hatate0_png);
		type.set ("assets/Sprites/hatate0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hina0.png", __ASSET__assets_sprites_hina0_png);
		type.set ("assets/Sprites/hina0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ichirin0.png", __ASSET__assets_sprites_ichirin0_png);
		type.set ("assets/Sprites/ichirin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/icyblock0.png", __ASSET__assets_sprites_icyblock0_png);
		type.set ("assets/Sprites/icyblock0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/iku0.png", __ASSET__assets_sprites_iku0_png);
		type.set ("assets/Sprites/iku0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ikuikudance0.png", __ASSET__assets_sprites_ikuikudance0_png);
		type.set ("assets/Sprites/ikuikudance0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kagerou0.png", __ASSET__assets_sprites_kagerou0_png);
		type.set ("assets/Sprites/kagerou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kaguya0.png", __ASSET__assets_sprites_kaguya0_png);
		type.set ("assets/Sprites/kaguya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kana0.png", __ASSET__assets_sprites_kana0_png);
		type.set ("assets/Sprites/kana0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kanako0.png", __ASSET__assets_sprites_kanako0_png);
		type.set ("assets/Sprites/kanako0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kasen0.png", __ASSET__assets_sprites_kasen0_png);
		type.set ("assets/Sprites/kasen0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/keine0.png", __ASSET__assets_sprites_keine0_png);
		type.set ("assets/Sprites/keine0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife0.png", __ASSET__assets_sprites_knife0_png);
		type.set ("assets/Sprites/knife0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife1.png", __ASSET__assets_sprites_knife1_png);
		type.set ("assets/Sprites/knife1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife2.png", __ASSET__assets_sprites_knife2_png);
		type.set ("assets/Sprites/knife2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife3.png", __ASSET__assets_sprites_knife3_png);
		type.set ("assets/Sprites/knife3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife4.png", __ASSET__assets_sprites_knife4_png);
		type.set ("assets/Sprites/knife4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife5.png", __ASSET__assets_sprites_knife5_png);
		type.set ("assets/Sprites/knife5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife6.png", __ASSET__assets_sprites_knife6_png);
		type.set ("assets/Sprites/knife6.png", AssetType.IMAGE);
		className.set ("assets/Sprites/knife7.png", __ASSET__assets_sprites_knife7_png);
		type.set ("assets/Sprites/knife7.png", AssetType.IMAGE);
		className.set ("assets/Sprites/koakuma0.png", __ASSET__assets_sprites_koakuma0_png);
		type.set ("assets/Sprites/koakuma0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kogasa0.png", __ASSET__assets_sprites_kogasa0_png);
		type.set ("assets/Sprites/kogasa0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kogasaflipped0.png", __ASSET__assets_sprites_kogasaflipped0_png);
		type.set ("assets/Sprites/kogasaflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/koishi0.png", __ASSET__assets_sprites_koishi0_png);
		type.set ("assets/Sprites/koishi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/koishiflipped0.png", __ASSET__assets_sprites_koishiflipped0_png);
		type.set ("assets/Sprites/koishiflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kokoro0.png", __ASSET__assets_sprites_kokoro0_png);
		type.set ("assets/Sprites/kokoro0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/komachi0.png", __ASSET__assets_sprites_komachi0_png);
		type.set ("assets/Sprites/komachi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/konngara0.png", __ASSET__assets_sprites_konngara0_png);
		type.set ("assets/Sprites/konngara0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kosuzu0.png", __ASSET__assets_sprites_kosuzu0_png);
		type.set ("assets/Sprites/kosuzu0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kotohime0.png", __ASSET__assets_sprites_kotohime0_png);
		type.set ("assets/Sprites/kotohime0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kurumi0.png", __ASSET__assets_sprites_kurumi0_png);
		type.set ("assets/Sprites/kurumi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/kyouko0.png", __ASSET__assets_sprites_kyouko0_png);
		type.set ("assets/Sprites/kyouko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/letty0.png", __ASSET__assets_sprites_letty0_png);
		type.set ("assets/Sprites/letty0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lightning0.png", __ASSET__assets_sprites_lightning0_png);
		type.set ("assets/Sprites/lightning0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lily0.png", __ASSET__assets_sprites_lily0_png);
		type.set ("assets/Sprites/lily0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/louise0.png", __ASSET__assets_sprites_louise0_png);
		type.set ("assets/Sprites/louise0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lunachild0.png", __ASSET__assets_sprites_lunachild0_png);
		type.set ("assets/Sprites/lunachild0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lunasa0.png", __ASSET__assets_sprites_lunasa0_png);
		type.set ("assets/Sprites/lunasa0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lyrica0.png", __ASSET__assets_sprites_lyrica0_png);
		type.set ("assets/Sprites/lyrica0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mai0.png", __ASSET__assets_sprites_mai0_png);
		type.set ("assets/Sprites/mai0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/makairesident-a0.png", __ASSET__assets_sprites_makairesident_a0_png);
		type.set ("assets/Sprites/makairesident-a0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/makairesident-b0.png", __ASSET__assets_sprites_makairesident_b0_png);
		type.set ("assets/Sprites/makairesident-b0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mamizou0.png", __ASSET__assets_sprites_mamizou0_png);
		type.set ("assets/Sprites/mamizou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/maribel0.png", __ASSET__assets_sprites_maribel0_png);
		type.set ("assets/Sprites/maribel0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/marisa0.png", __ASSET__assets_sprites_marisa0_png);
		type.set ("assets/Sprites/marisa0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/marisaALT0.png", __ASSET__assets_sprites_marisaalt0_png);
		type.set ("assets/Sprites/marisaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/matenshi0.png", __ASSET__assets_sprites_matenshi0_png);
		type.set ("assets/Sprites/matenshi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/medicine0.png", __ASSET__assets_sprites_medicine0_png);
		type.set ("assets/Sprites/medicine0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/meiling0.png", __ASSET__assets_sprites_meiling0_png);
		type.set ("assets/Sprites/meiling0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/meilingALT0.png", __ASSET__assets_sprites_meilingalt0_png);
		type.set ("assets/Sprites/meilingALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/meira0.png", __ASSET__assets_sprites_meira0_png);
		type.set ("assets/Sprites/meira0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/merlin0.png", __ASSET__assets_sprites_merlin0_png);
		type.set ("assets/Sprites/merlin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/miko0.png", __ASSET__assets_sprites_miko0_png);
		type.set ("assets/Sprites/miko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mima0.png", __ASSET__assets_sprites_mima0_png);
		type.set ("assets/Sprites/mima0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mimaALT0.png", __ASSET__assets_sprites_mimaalt0_png);
		type.set ("assets/Sprites/mimaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/minoriko0.png", __ASSET__assets_sprites_minoriko0_png);
		type.set ("assets/Sprites/minoriko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mokou0.png", __ASSET__assets_sprites_mokou0_png);
		type.set ("assets/Sprites/mokou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/momiji0.png", __ASSET__assets_sprites_momiji0_png);
		type.set ("assets/Sprites/momiji0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mrghosty0.png", __ASSET__assets_sprites_mrghosty0_png);
		type.set ("assets/Sprites/mrghosty0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mugetsu0.png", __ASSET__assets_sprites_mugetsu0_png);
		type.set ("assets/Sprites/mugetsu0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/murasa0.png", __ASSET__assets_sprites_murasa0_png);
		type.set ("assets/Sprites/murasa0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/myon0.png", __ASSET__assets_sprites_myon0_png);
		type.set ("assets/Sprites/myon0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mystia0.png", __ASSET__assets_sprites_mystia0_png);
		type.set ("assets/Sprites/mystia0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mystiaALT0.png", __ASSET__assets_sprites_mystiaalt0_png);
		type.set ("assets/Sprites/mystiaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/nazrin0.png", __ASSET__assets_sprites_nazrin0_png);
		type.set ("assets/Sprites/nazrin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/nazrinflipped0.png", __ASSET__assets_sprites_nazrinflipped0_png);
		type.set ("assets/Sprites/nazrinflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/nitori0.png", __ASSET__assets_sprites_nitori0_png);
		type.set ("assets/Sprites/nitori0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/noroiko0.png", __ASSET__assets_sprites_noroiko0_png);
		type.set ("assets/Sprites/noroiko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/nue0.png", __ASSET__assets_sprites_nue0_png);
		type.set ("assets/Sprites/nue0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/options0.png", __ASSET__assets_sprites_options0_png);
		type.set ("assets/Sprites/options0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/orange0.png", __ASSET__assets_sprites_orange0_png);
		type.set ("assets/Sprites/orange0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/orin0.png", __ASSET__assets_sprites_orin0_png);
		type.set ("assets/Sprites/orin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/parsee0.png", __ASSET__assets_sprites_parsee0_png);
		type.set ("assets/Sprites/parsee0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/patchouli0.png", __ASSET__assets_sprites_patchouli0_png);
		type.set ("assets/Sprites/patchouli0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/pika0.png", __ASSET__assets_sprites_pika0_png);
		type.set ("assets/Sprites/pika0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Point0.png", __ASSET__assets_sprites_point0_png);
		type.set ("assets/Sprites/Point0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/POW0.png", __ASSET__assets_sprites_pow0_png);
		type.set ("assets/Sprites/POW0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/POWalt0.png", __ASSET__assets_sprites_powalt0_png);
		type.set ("assets/Sprites/POWalt0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/prinny0.png", __ASSET__assets_sprites_prinny0_png);
		type.set ("assets/Sprites/prinny0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/raiko0.png", __ASSET__assets_sprites_raiko0_png);
		type.set ("assets/Sprites/raiko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ran0.png", __ASSET__assets_sprites_ran0_png);
		type.set ("assets/Sprites/ran0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/RedFairy0.png", __ASSET__assets_sprites_redfairy0_png);
		type.set ("assets/Sprites/RedFairy0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/RedFairyflipped0.png", __ASSET__assets_sprites_redfairyflipped0_png);
		type.set ("assets/Sprites/RedFairyflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Redufo0.png", __ASSET__assets_sprites_redufo0_png);
		type.set ("assets/Sprites/Redufo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/reimu0.png", __ASSET__assets_sprites_reimu0_png);
		type.set ("assets/Sprites/reimu0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/reimuALT0.png", __ASSET__assets_sprites_reimualt0_png);
		type.set ("assets/Sprites/reimuALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/reimuflipped0.png", __ASSET__assets_sprites_reimuflipped0_png);
		type.set ("assets/Sprites/reimuflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/reisen0.png", __ASSET__assets_sprites_reisen0_png);
		type.set ("assets/Sprites/reisen0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/remilia0.png", __ASSET__assets_sprites_remilia0_png);
		type.set ("assets/Sprites/remilia0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/rengeteki0.png", __ASSET__assets_sprites_rengeteki0_png);
		type.set ("assets/Sprites/rengeteki0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/renko0.png", __ASSET__assets_sprites_renko0_png);
		type.set ("assets/Sprites/renko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/rika0.png", __ASSET__assets_sprites_rika0_png);
		type.set ("assets/Sprites/rika0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/rikako0.png", __ASSET__assets_sprites_rikako0_png);
		type.set ("assets/Sprites/rikako0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/rin0.png", __ASSET__assets_sprites_rin0_png);
		type.set ("assets/Sprites/rin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ringo0.png", __ASSET__assets_sprites_ringo0_png);
		type.set ("assets/Sprites/ringo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/rumia0.png", __ASSET__assets_sprites_rumia0_png);
		type.set ("assets/Sprites/rumia0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ruukoto0.png", __ASSET__assets_sprites_ruukoto0_png);
		type.set ("assets/Sprites/ruukoto0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sakuya0.png", __ASSET__assets_sprites_sakuya0_png);
		type.set ("assets/Sprites/sakuya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sakuyaALT0.png", __ASSET__assets_sprites_sakuyaalt0_png);
		type.set ("assets/Sprites/sakuyaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sanae0.png", __ASSET__assets_sprites_sanae0_png);
		type.set ("assets/Sprites/sanae0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sanaeALT0.png", __ASSET__assets_sprites_sanaealt0_png);
		type.set ("assets/Sprites/sanaeALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sara0.png", __ASSET__assets_sprites_sara0_png);
		type.set ("assets/Sprites/sara0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sariel0.png", __ASSET__assets_sprites_sariel0_png);
		type.set ("assets/Sprites/sariel0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/satori0.png", __ASSET__assets_sprites_satori0_png);
		type.set ("assets/Sprites/satori0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/satoriflipped0.png", __ASSET__assets_sprites_satoriflipped0_png);
		type.set ("assets/Sprites/satoriflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/seiga0.png", __ASSET__assets_sprites_seiga0_png);
		type.set ("assets/Sprites/seiga0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/seija0.png", __ASSET__assets_sprites_seija0_png);
		type.set ("assets/Sprites/seija0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/seiran0.png", __ASSET__assets_sprites_seiran0_png);
		type.set ("assets/Sprites/seiran0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sekibanki0.png", __ASSET__assets_sprites_sekibanki0_png);
		type.set ("assets/Sprites/sekibanki0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shanghai0.png", __ASSET__assets_sprites_shanghai0_png);
		type.set ("assets/Sprites/shanghai0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shikieiki0.png", __ASSET__assets_sprites_shikieiki0_png);
		type.set ("assets/Sprites/shikieiki0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shingyoku0.png", __ASSET__assets_sprites_shingyoku0_png);
		type.set ("assets/Sprites/shingyoku0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shingyokuALT0.png", __ASSET__assets_sprites_shingyokualt0_png);
		type.set ("assets/Sprites/shingyokuALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shinki0.png", __ASSET__assets_sprites_shinki0_png);
		type.set ("assets/Sprites/shinki0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shinmyoumaru0.png", __ASSET__assets_sprites_shinmyoumaru0_png);
		type.set ("assets/Sprites/shinmyoumaru0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shizuha0.png", __ASSET__assets_sprites_shizuha0_png);
		type.set ("assets/Sprites/shizuha0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shou0.png", __ASSET__assets_sprites_shou0_png);
		type.set ("assets/Sprites/shou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/skull0.png", __ASSET__assets_sprites_skull0_png);
		type.set ("assets/Sprites/skull0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/starbulletg0.png", __ASSET__assets_sprites_starbulletg0_png);
		type.set ("assets/Sprites/starbulletg0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/starbullety0.png", __ASSET__assets_sprites_starbullety0_png);
		type.set ("assets/Sprites/starbullety0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/starsaphire0.png", __ASSET__assets_sprites_starsaphire0_png);
		type.set ("assets/Sprites/starsaphire0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/suika0.png", __ASSET__assets_sprites_suika0_png);
		type.set ("assets/Sprites/suika0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sumireko0.png", __ASSET__assets_sprites_sumireko0_png);
		type.set ("assets/Sprites/sumireko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sunnymilk0.png", __ASSET__assets_sprites_sunnymilk0_png);
		type.set ("assets/Sprites/sunnymilk0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/suwako0.png", __ASSET__assets_sprites_suwako0_png);
		type.set ("assets/Sprites/suwako0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table0.png", __ASSET__assets_sprites_table0_png);
		type.set ("assets/Sprites/table0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table1.png", __ASSET__assets_sprites_table1_png);
		type.set ("assets/Sprites/table1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table10.png", __ASSET__assets_sprites_table10_png);
		type.set ("assets/Sprites/table10.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table11.png", __ASSET__assets_sprites_table11_png);
		type.set ("assets/Sprites/table11.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table12.png", __ASSET__assets_sprites_table12_png);
		type.set ("assets/Sprites/table12.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table13.png", __ASSET__assets_sprites_table13_png);
		type.set ("assets/Sprites/table13.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table14.png", __ASSET__assets_sprites_table14_png);
		type.set ("assets/Sprites/table14.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table15.png", __ASSET__assets_sprites_table15_png);
		type.set ("assets/Sprites/table15.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table2.png", __ASSET__assets_sprites_table2_png);
		type.set ("assets/Sprites/table2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table3.png", __ASSET__assets_sprites_table3_png);
		type.set ("assets/Sprites/table3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table4.png", __ASSET__assets_sprites_table4_png);
		type.set ("assets/Sprites/table4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table5.png", __ASSET__assets_sprites_table5_png);
		type.set ("assets/Sprites/table5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table6.png", __ASSET__assets_sprites_table6_png);
		type.set ("assets/Sprites/table6.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table7.png", __ASSET__assets_sprites_table7_png);
		type.set ("assets/Sprites/table7.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table8.png", __ASSET__assets_sprites_table8_png);
		type.set ("assets/Sprites/table8.png", AssetType.IMAGE);
		className.set ("assets/Sprites/table9.png", __ASSET__assets_sprites_table9_png);
		type.set ("assets/Sprites/table9.png", AssetType.IMAGE);
		className.set ("assets/Sprites/tenshi0.png", __ASSET__assets_sprites_tenshi0_png);
		type.set ("assets/Sprites/tenshi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/tewi0.png", __ASSET__assets_sprites_tewi0_png);
		type.set ("assets/Sprites/tewi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/tewiflipped0.png", __ASSET__assets_sprites_tewiflipped0_png);
		type.set ("assets/Sprites/tewiflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/titlescreen0.png", __ASSET__assets_sprites_titlescreen0_png);
		type.set ("assets/Sprites/titlescreen0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/tojiko0.png", __ASSET__assets_sprites_tojiko0_png);
		type.set ("assets/Sprites/tojiko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/tokiko0.png", __ASSET__assets_sprites_tokiko0_png);
		type.set ("assets/Sprites/tokiko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/toyohime0.png", __ASSET__assets_sprites_toyohime0_png);
		type.set ("assets/Sprites/toyohime0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/trophy0.png", __ASSET__assets_sprites_trophy0_png);
		type.set ("assets/Sprites/trophy0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/truck0.png", __ASSET__assets_sprites_truck0_png);
		type.set ("assets/Sprites/truck0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/udongein0.png", __ASSET__assets_sprites_udongein0_png);
		type.set ("assets/Sprites/udongein0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/udongeinflipped0.png", __ASSET__assets_sprites_udongeinflipped0_png);
		type.set ("assets/Sprites/udongeinflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/unused0.png", __ASSET__assets_sprites_unused0_png);
		type.set ("assets/Sprites/unused0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/unzanfist0.png", __ASSET__assets_sprites_unzanfist0_png);
		type.set ("assets/Sprites/unzanfist0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/utsuho0.png", __ASSET__assets_sprites_utsuho0_png);
		type.set ("assets/Sprites/utsuho0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/wakasagihime0.png", __ASSET__assets_sprites_wakasagihime0_png);
		type.set ("assets/Sprites/wakasagihime0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/wriggle0.png", __ASSET__assets_sprites_wriggle0_png);
		type.set ("assets/Sprites/wriggle0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yamame0.png", __ASSET__assets_sprites_yamame0_png);
		type.set ("assets/Sprites/yamame0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yatsuhashi0.png", __ASSET__assets_sprites_yatsuhashi0_png);
		type.set ("assets/Sprites/yatsuhashi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb0.png", __ASSET__assets_sprites_yinyangorb0_png);
		type.set ("assets/Sprites/yinyangorb0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb1.png", __ASSET__assets_sprites_yinyangorb1_png);
		type.set ("assets/Sprites/yinyangorb1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb10.png", __ASSET__assets_sprites_yinyangorb10_png);
		type.set ("assets/Sprites/yinyangorb10.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb11.png", __ASSET__assets_sprites_yinyangorb11_png);
		type.set ("assets/Sprites/yinyangorb11.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb12.png", __ASSET__assets_sprites_yinyangorb12_png);
		type.set ("assets/Sprites/yinyangorb12.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb13.png", __ASSET__assets_sprites_yinyangorb13_png);
		type.set ("assets/Sprites/yinyangorb13.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb14.png", __ASSET__assets_sprites_yinyangorb14_png);
		type.set ("assets/Sprites/yinyangorb14.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb15.png", __ASSET__assets_sprites_yinyangorb15_png);
		type.set ("assets/Sprites/yinyangorb15.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb2.png", __ASSET__assets_sprites_yinyangorb2_png);
		type.set ("assets/Sprites/yinyangorb2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb3.png", __ASSET__assets_sprites_yinyangorb3_png);
		type.set ("assets/Sprites/yinyangorb3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb4.png", __ASSET__assets_sprites_yinyangorb4_png);
		type.set ("assets/Sprites/yinyangorb4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb5.png", __ASSET__assets_sprites_yinyangorb5_png);
		type.set ("assets/Sprites/yinyangorb5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb6.png", __ASSET__assets_sprites_yinyangorb6_png);
		type.set ("assets/Sprites/yinyangorb6.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb7.png", __ASSET__assets_sprites_yinyangorb7_png);
		type.set ("assets/Sprites/yinyangorb7.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb8.png", __ASSET__assets_sprites_yinyangorb8_png);
		type.set ("assets/Sprites/yinyangorb8.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yinyangorb9.png", __ASSET__assets_sprites_yinyangorb9_png);
		type.set ("assets/Sprites/yinyangorb9.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yorihime0.png", __ASSET__assets_sprites_yorihime0_png);
		type.set ("assets/Sprites/yorihime0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yoshika0.png", __ASSET__assets_sprites_yoshika0_png);
		type.set ("assets/Sprites/yoshika0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/youmu0.png", __ASSET__assets_sprites_youmu0_png);
		type.set ("assets/Sprites/youmu0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yukari0.png", __ASSET__assets_sprites_yukari0_png);
		type.set ("assets/Sprites/yukari0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yuki0.png", __ASSET__assets_sprites_yuki0_png);
		type.set ("assets/Sprites/yuki0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yumeko0.png", __ASSET__assets_sprites_yumeko0_png);
		type.set ("assets/Sprites/yumeko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yumemi0.png", __ASSET__assets_sprites_yumemi0_png);
		type.set ("assets/Sprites/yumemi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yuugi0.png", __ASSET__assets_sprites_yuugi0_png);
		type.set ("assets/Sprites/yuugi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yuuka0.png", __ASSET__assets_sprites_yuuka0_png);
		type.set ("assets/Sprites/yuuka0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yuukaALT0.png", __ASSET__assets_sprites_yuukaalt0_png);
		type.set ("assets/Sprites/yuukaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yuyuko0.png", __ASSET__assets_sprites_yuyuko0_png);
		type.set ("assets/Sprites/yuyuko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/zombiefairy0.png", __ASSET__assets_sprites_zombiefairy0_png);
		type.set ("assets/Sprites/zombiefairy0.png", AssetType.IMAGE);
		
		
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
		id = "assets/Audio/Ogg/extend.OGG";
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
		id = "assets/Audio/Ogg/masterspark.OGG";
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
		id = "assets/Sprites/ayana0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/balloon0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/barrier0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/benben0.png";
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
		id = "assets/Sprites/black0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/block0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BlueFairy0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/BlueFairyflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Blueufo0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bomb0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/byakuren0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/charblock0.png";
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
		id = "assets/Sprites/CSBG0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/daiyousei0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/darkness0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/diosakuya0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/doremy0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen10.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen11.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen12.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen13.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen14.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen15.png";
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
		id = "assets/Sprites/EChen8.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EChen9.png";
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
		id = "assets/Sprites/electriccirno0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/elis0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ellen0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/elly0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EMystia0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EMystia1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EMystiaflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan10.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan11.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan12.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan13.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan14.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan15.png";
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
		id = "assets/Sprites/ERan8.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ERan9.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/evilyuuka0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/exkeine0.png";
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
		id = "assets/Sprites/giantcirno0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/giantsuika0.png";
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
		id = "assets/Sprites/hammer10.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer11.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer12.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer13.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer14.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer15.png";
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
		id = "assets/Sprites/hammer8.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hammer9.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hatate0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hina0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ichirin0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/icyblock0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/iku0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ikuikudance0.png";
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
		id = "assets/Sprites/kanako0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kasen0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/keine0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife2.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife3.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife4.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife5.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife6.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/knife7.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/koakuma0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kogasa0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kogasaflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/koishi0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/koishiflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/kokoro0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/komachi0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/konngara0.png";
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
		id = "assets/Sprites/kyouko0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/letty0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lightning0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lily0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/louise0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lunachild0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lunasa0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lyrica0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mai0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/makairesident-a0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/makairesident-b0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mamizou0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/maribel0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/marisa0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/marisaALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/matenshi0.png";
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
		id = "assets/Sprites/merlin0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/miko0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mima0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mimaALT0.png";
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
		id = "assets/Sprites/mrghosty0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mugetsu0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/murasa0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/myon0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mystia0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mystiaALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/nazrin0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/nazrinflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/nitori0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/noroiko0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/nue0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/options0.png";
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
		id = "assets/Sprites/POWalt0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/prinny0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/raiko0.png";
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
		id = "assets/Sprites/reimuflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/reisen0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/remilia0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rengeteki0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/renko0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rika0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rikako0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rin0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ringo0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rumia0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ruukoto0.png";
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
		id = "assets/Sprites/sara0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sariel0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/satori0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/satoriflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/seiga0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/seija0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/seiran0.png";
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
		id = "assets/Sprites/shingyoku0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shingyokuALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shinki0.png";
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
		id = "assets/Sprites/skull0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/starbulletg0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/starbullety0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/starsaphire0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/suika0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sumireko0.png";
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
		id = "assets/Sprites/table10.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table11.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table12.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table13.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table14.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table15.png";
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
		id = "assets/Sprites/table8.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/table9.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tenshi0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tewi0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tewiflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/titlescreen0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tojiko0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/tokiko0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/toyohime0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/trophy0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/truck0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/udongein0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/udongeinflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/unused0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/unzanfist0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/utsuho0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/wakasagihime0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/wriggle0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yamame0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yatsuhashi0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb10.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb11.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb12.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb13.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb14.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb15.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb2.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb3.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb4.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb5.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb6.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb7.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb8.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yinyangorb9.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yorihime0.png";
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
		id = "assets/Sprites/yuugi0.png";
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
		id = "assets/Sprites/zombiefairy0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		
		
		var assetsPrefix = ApplicationMain.config.assetsPrefix;
		if (assetsPrefix != null) {
			for (k in path.keys()) {
				path.set(k, assetsPrefix + path[k]);
			}
		}
		
		#else
		
		#if openfl
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		#end
		
		#if (windows || mac || linux)
		
		var useManifest = false;
		
		className.set ("assets/Audio/Ogg/bonk.OGG", __ASSET__assets_audio_ogg_bonk_ogg);
		type.set ("assets/Audio/Ogg/bonk.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/characterselect.OGG", __ASSET__assets_audio_ogg_characterselect_ogg);
		type.set ("assets/Audio/Ogg/characterselect.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/collectcoin.OGG", __ASSET__assets_audio_ogg_collectcoin_ogg);
		type.set ("assets/Audio/Ogg/collectcoin.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/died.OGG", __ASSET__assets_audio_ogg_died_ogg);
		type.set ("assets/Audio/Ogg/died.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/extend.OGG", __ASSET__assets_audio_ogg_extend_ogg);
		type.set ("assets/Audio/Ogg/extend.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/finalkill.OGG", __ASSET__assets_audio_ogg_finalkill_ogg);
		type.set ("assets/Audio/Ogg/finalkill.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/fireballspawn.OGG", __ASSET__assets_audio_ogg_fireballspawn_ogg);
		type.set ("assets/Audio/Ogg/fireballspawn.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/gameover.OGG", __ASSET__assets_audio_ogg_gameover_ogg);
		type.set ("assets/Audio/Ogg/gameover.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/killenemy.OGG", __ASSET__assets_audio_ogg_killenemy_ogg);
		type.set ("assets/Audio/Ogg/killenemy.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/masterspark.OGG", __ASSET__assets_audio_ogg_masterspark_ogg);
		type.set ("assets/Audio/Ogg/masterspark.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/nextlevel.OGG", __ASSET__assets_audio_ogg_nextlevel_ogg);
		type.set ("assets/Audio/Ogg/nextlevel.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/pow.OGG", __ASSET__assets_audio_ogg_pow_ogg);
		type.set ("assets/Audio/Ogg/pow.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/respawn.OGG", __ASSET__assets_audio_ogg_respawn_ogg);
		type.set ("assets/Audio/Ogg/respawn.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/spawncoin.OGG", __ASSET__assets_audio_ogg_spawncoin_ogg);
		type.set ("assets/Audio/Ogg/spawncoin.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/startgame.OGG", __ASSET__assets_audio_ogg_startgame_ogg);
		type.set ("assets/Audio/Ogg/startgame.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/step1.OGG", __ASSET__assets_audio_ogg_step1_ogg);
		type.set ("assets/Audio/Ogg/step1.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/step2.OGG", __ASSET__assets_audio_ogg_step2_ogg);
		type.set ("assets/Audio/Ogg/step2.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/step3.OGG", __ASSET__assets_audio_ogg_step3_ogg);
		type.set ("assets/Audio/Ogg/step3.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme1.OGG", __ASSET__assets_audio_ogg_theme1_ogg);
		type.set ("assets/Audio/Ogg/theme1.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme10.OGG", __ASSET__assets_audio_ogg_theme10_ogg);
		type.set ("assets/Audio/Ogg/theme10.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme11.OGG", __ASSET__assets_audio_ogg_theme11_ogg);
		type.set ("assets/Audio/Ogg/theme11.OGG", AssetType.MUSIC);
		
		className.set ("assets/Audio/Ogg/theme12.OGG", __ASSET__assets_audio_ogg_theme12_ogg);
		type.set ("assets/Audio/Ogg/theme12.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme12intro.OGG", __ASSET__assets_audio_ogg_theme12intro_ogg);
		type.set ("assets/Audio/Ogg/theme12intro.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme2.OGG", __ASSET__assets_audio_ogg_theme2_ogg);
		type.set ("assets/Audio/Ogg/theme2.OGG", AssetType.MUSIC);
		
		className.set ("assets/Audio/Ogg/theme3.OGG", __ASSET__assets_audio_ogg_theme3_ogg);
		type.set ("assets/Audio/Ogg/theme3.OGG", AssetType.MUSIC);
		
		className.set ("assets/Audio/Ogg/theme4.OGG", __ASSET__assets_audio_ogg_theme4_ogg);
		type.set ("assets/Audio/Ogg/theme4.OGG", AssetType.MUSIC);
		
		className.set ("assets/Audio/Ogg/theme5.OGG", __ASSET__assets_audio_ogg_theme5_ogg);
		type.set ("assets/Audio/Ogg/theme5.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme6.OGG", __ASSET__assets_audio_ogg_theme6_ogg);
		type.set ("assets/Audio/Ogg/theme6.OGG", AssetType.MUSIC);
		
		className.set ("assets/Audio/Ogg/theme7.OGG", __ASSET__assets_audio_ogg_theme7_ogg);
		type.set ("assets/Audio/Ogg/theme7.OGG", AssetType.MUSIC);
		
		className.set ("assets/Audio/Ogg/theme8.OGG", __ASSET__assets_audio_ogg_theme8_ogg);
		type.set ("assets/Audio/Ogg/theme8.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme8intro.OGG", __ASSET__assets_audio_ogg_theme8intro_ogg);
		type.set ("assets/Audio/Ogg/theme8intro.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/theme9.OGG", __ASSET__assets_audio_ogg_theme9_ogg);
		type.set ("assets/Audio/Ogg/theme9.OGG", AssetType.SOUND);
		
		className.set ("assets/Audio/Ogg/titlescreen.OGG", __ASSET__assets_audio_ogg_titlescreen_ogg);
		type.set ("assets/Audio/Ogg/titlescreen.OGG", AssetType.SOUND);
		
		className.set ("assets/bgcolor.png", __ASSET__assets_bgcolor_png);
		type.set ("assets/bgcolor.png", AssetType.IMAGE);
		
		className.set ("assets/black.png", __ASSET__assets_black_png);
		type.set ("assets/black.png", AssetType.IMAGE);
		
		className.set ("assets/Dpad.png", __ASSET__assets_dpad_png);
		type.set ("assets/Dpad.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/1up0.png", __ASSET__assets_sprites_1up0_png);
		type.set ("assets/Sprites/1up0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/akyu0.png", __ASSET__assets_sprites_akyu0_png);
		type.set ("assets/Sprites/akyu0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/alice0.png", __ASSET__assets_sprites_alice0_png);
		type.set ("assets/Sprites/alice0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/aliceALT0.png", __ASSET__assets_sprites_alicealt0_png);
		type.set ("assets/Sprites/aliceALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/aya0.png", __ASSET__assets_sprites_aya0_png);
		type.set ("assets/Sprites/aya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ayana0.png", __ASSET__assets_sprites_ayana0_png);
		type.set ("assets/Sprites/ayana0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/balloon0.png", __ASSET__assets_sprites_balloon0_png);
		type.set ("assets/Sprites/balloon0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/barrier0.png", __ASSET__assets_sprites_barrier0_png);
		type.set ("assets/Sprites/barrier0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/benben0.png", __ASSET__assets_sprites_benben0_png);
		type.set ("assets/Sprites/benben0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BG0.png", __ASSET__assets_sprites_bg0_png);
		type.set ("assets/Sprites/BG0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BG1.png", __ASSET__assets_sprites_bg1_png);
		type.set ("assets/Sprites/BG1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BG2.png", __ASSET__assets_sprites_bg2_png);
		type.set ("assets/Sprites/BG2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BG3.png", __ASSET__assets_sprites_bg3_png);
		type.set ("assets/Sprites/BG3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BG4.png", __ASSET__assets_sprites_bg4_png);
		type.set ("assets/Sprites/BG4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BG5.png", __ASSET__assets_sprites_bg5_png);
		type.set ("assets/Sprites/BG5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/black0.png", __ASSET__assets_sprites_black0_png);
		type.set ("assets/Sprites/black0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/block0.png", __ASSET__assets_sprites_block0_png);
		type.set ("assets/Sprites/block0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BlueFairy0.png", __ASSET__assets_sprites_bluefairy0_png);
		type.set ("assets/Sprites/BlueFairy0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/BlueFairyflipped0.png", __ASSET__assets_sprites_bluefairyflipped0_png);
		type.set ("assets/Sprites/BlueFairyflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Blueufo0.png", __ASSET__assets_sprites_blueufo0_png);
		type.set ("assets/Sprites/Blueufo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bomb0.png", __ASSET__assets_sprites_bomb0_png);
		type.set ("assets/Sprites/bomb0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bullet0.png", __ASSET__assets_sprites_bullet0_png);
		type.set ("assets/Sprites/bullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/byakuren0.png", __ASSET__assets_sprites_byakuren0_png);
		type.set ("assets/Sprites/byakuren0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/charblock0.png", __ASSET__assets_sprites_charblock0_png);
		type.set ("assets/Sprites/charblock0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/chen0.png", __ASSET__assets_sprites_chen0_png);
		type.set ("assets/Sprites/chen0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/chiyuri0.png", __ASSET__assets_sprites_chiyuri0_png);
		type.set ("assets/Sprites/chiyuri0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/cirno0.png", __ASSET__assets_sprites_cirno0_png);
		type.set ("assets/Sprites/cirno0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/CSBG0.png", __ASSET__assets_sprites_csbg0_png);
		type.set ("assets/Sprites/CSBG0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/daiyousei0.png", __ASSET__assets_sprites_daiyousei0_png);
		type.set ("assets/Sprites/daiyousei0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/darkness0.png", __ASSET__assets_sprites_darkness0_png);
		type.set ("assets/Sprites/darkness0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/diosakuya0.png", __ASSET__assets_sprites_diosakuya0_png);
		type.set ("assets/Sprites/diosakuya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/doremy0.png", __ASSET__assets_sprites_doremy0_png);
		type.set ("assets/Sprites/doremy0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen0.png", __ASSET__assets_sprites_echen0_png);
		type.set ("assets/Sprites/EChen0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen1.png", __ASSET__assets_sprites_echen1_png);
		type.set ("assets/Sprites/EChen1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen10.png", __ASSET__assets_sprites_echen10_png);
		type.set ("assets/Sprites/EChen10.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen11.png", __ASSET__assets_sprites_echen11_png);
		type.set ("assets/Sprites/EChen11.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen12.png", __ASSET__assets_sprites_echen12_png);
		type.set ("assets/Sprites/EChen12.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen13.png", __ASSET__assets_sprites_echen13_png);
		type.set ("assets/Sprites/EChen13.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen14.png", __ASSET__assets_sprites_echen14_png);
		type.set ("assets/Sprites/EChen14.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen15.png", __ASSET__assets_sprites_echen15_png);
		type.set ("assets/Sprites/EChen15.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen2.png", __ASSET__assets_sprites_echen2_png);
		type.set ("assets/Sprites/EChen2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen3.png", __ASSET__assets_sprites_echen3_png);
		type.set ("assets/Sprites/EChen3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen4.png", __ASSET__assets_sprites_echen4_png);
		type.set ("assets/Sprites/EChen4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen5.png", __ASSET__assets_sprites_echen5_png);
		type.set ("assets/Sprites/EChen5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen6.png", __ASSET__assets_sprites_echen6_png);
		type.set ("assets/Sprites/EChen6.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen7.png", __ASSET__assets_sprites_echen7_png);
		type.set ("assets/Sprites/EChen7.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen8.png", __ASSET__assets_sprites_echen8_png);
		type.set ("assets/Sprites/EChen8.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EChen9.png", __ASSET__assets_sprites_echen9_png);
		type.set ("assets/Sprites/EChen9.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ECirno0.png", __ASSET__assets_sprites_ecirno0_png);
		type.set ("assets/Sprites/ECirno0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/eirin0.png", __ASSET__assets_sprites_eirin0_png);
		type.set ("assets/Sprites/eirin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EKeine0.png", __ASSET__assets_sprites_ekeine0_png);
		type.set ("assets/Sprites/EKeine0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EKeineex0.png", __ASSET__assets_sprites_ekeineex0_png);
		type.set ("assets/Sprites/EKeineex0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EKeineexflipped0.png", __ASSET__assets_sprites_ekeineexflipped0_png);
		type.set ("assets/Sprites/EKeineexflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/electriccirno0.png", __ASSET__assets_sprites_electriccirno0_png);
		type.set ("assets/Sprites/electriccirno0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/elis0.png", __ASSET__assets_sprites_elis0_png);
		type.set ("assets/Sprites/elis0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ellen0.png", __ASSET__assets_sprites_ellen0_png);
		type.set ("assets/Sprites/ellen0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/elly0.png", __ASSET__assets_sprites_elly0_png);
		type.set ("assets/Sprites/elly0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EMystia0.png", __ASSET__assets_sprites_emystia0_png);
		type.set ("assets/Sprites/EMystia0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EMystia1.png", __ASSET__assets_sprites_emystia1_png);
		type.set ("assets/Sprites/EMystia1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EMystiaflipped0.png", __ASSET__assets_sprites_emystiaflipped0_png);
		type.set ("assets/Sprites/EMystiaflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan0.png", __ASSET__assets_sprites_eran0_png);
		type.set ("assets/Sprites/ERan0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan1.png", __ASSET__assets_sprites_eran1_png);
		type.set ("assets/Sprites/ERan1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan10.png", __ASSET__assets_sprites_eran10_png);
		type.set ("assets/Sprites/ERan10.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan11.png", __ASSET__assets_sprites_eran11_png);
		type.set ("assets/Sprites/ERan11.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan12.png", __ASSET__assets_sprites_eran12_png);
		type.set ("assets/Sprites/ERan12.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan13.png", __ASSET__assets_sprites_eran13_png);
		type.set ("assets/Sprites/ERan13.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan14.png", __ASSET__assets_sprites_eran14_png);
		type.set ("assets/Sprites/ERan14.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan15.png", __ASSET__assets_sprites_eran15_png);
		type.set ("assets/Sprites/ERan15.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan2.png", __ASSET__assets_sprites_eran2_png);
		type.set ("assets/Sprites/ERan2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan3.png", __ASSET__assets_sprites_eran3_png);
		type.set ("assets/Sprites/ERan3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan4.png", __ASSET__assets_sprites_eran4_png);
		type.set ("assets/Sprites/ERan4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan5.png", __ASSET__assets_sprites_eran5_png);
		type.set ("assets/Sprites/ERan5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan6.png", __ASSET__assets_sprites_eran6_png);
		type.set ("assets/Sprites/ERan6.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan7.png", __ASSET__assets_sprites_eran7_png);
		type.set ("assets/Sprites/ERan7.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan8.png", __ASSET__assets_sprites_eran8_png);
		type.set ("assets/Sprites/ERan8.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ERan9.png", __ASSET__assets_sprites_eran9_png);
		type.set ("assets/Sprites/ERan9.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/evilyuuka0.png", __ASSET__assets_sprites_evilyuuka0_png);
		type.set ("assets/Sprites/evilyuuka0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/exkeine0.png", __ASSET__assets_sprites_exkeine0_png);
		type.set ("assets/Sprites/exkeine0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/firecirno0.png", __ASSET__assets_sprites_firecirno0_png);
		type.set ("assets/Sprites/firecirno0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flames0.png", __ASSET__assets_sprites_flames0_png);
		type.set ("assets/Sprites/flames0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flames1.png", __ASSET__assets_sprites_flames1_png);
		type.set ("assets/Sprites/flames1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flames2.png", __ASSET__assets_sprites_flames2_png);
		type.set ("assets/Sprites/flames2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flandre0.png", __ASSET__assets_sprites_flandre0_png);
		type.set ("assets/Sprites/flandre0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/futo0.png", __ASSET__assets_sprites_futo0_png);
		type.set ("assets/Sprites/futo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Gap0.png", __ASSET__assets_sprites_gap0_png);
		type.set ("assets/Sprites/Gap0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/gengetsu0.png", __ASSET__assets_sprites_gengetsu0_png);
		type.set ("assets/Sprites/gengetsu0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/giantcirno0.png", __ASSET__assets_sprites_giantcirno0_png);
		type.set ("assets/Sprites/giantcirno0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/giantsuika0.png", __ASSET__assets_sprites_giantsuika0_png);
		type.set ("assets/Sprites/giantsuika0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Greenufo0.png", __ASSET__assets_sprites_greenufo0_png);
		type.set ("assets/Sprites/Greenufo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer0.png", __ASSET__assets_sprites_hammer0_png);
		type.set ("assets/Sprites/hammer0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer1.png", __ASSET__assets_sprites_hammer1_png);
		type.set ("assets/Sprites/hammer1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer10.png", __ASSET__assets_sprites_hammer10_png);
		type.set ("assets/Sprites/hammer10.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer11.png", __ASSET__assets_sprites_hammer11_png);
		type.set ("assets/Sprites/hammer11.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer12.png", __ASSET__assets_sprites_hammer12_png);
		type.set ("assets/Sprites/hammer12.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer13.png", __ASSET__assets_sprites_hammer13_png);
		type.set ("assets/Sprites/hammer13.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer14.png", __ASSET__assets_sprites_hammer14_png);
		type.set ("assets/Sprites/hammer14.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer15.png", __ASSET__assets_sprites_hammer15_png);
		type.set ("assets/Sprites/hammer15.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer2.png", __ASSET__assets_sprites_hammer2_png);
		type.set ("assets/Sprites/hammer2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer3.png", __ASSET__assets_sprites_hammer3_png);
		type.set ("assets/Sprites/hammer3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer4.png", __ASSET__assets_sprites_hammer4_png);
		type.set ("assets/Sprites/hammer4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer5.png", __ASSET__assets_sprites_hammer5_png);
		type.set ("assets/Sprites/hammer5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer6.png", __ASSET__assets_sprites_hammer6_png);
		type.set ("assets/Sprites/hammer6.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer7.png", __ASSET__assets_sprites_hammer7_png);
		type.set ("assets/Sprites/hammer7.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer8.png", __ASSET__assets_sprites_hammer8_png);
		type.set ("assets/Sprites/hammer8.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hammer9.png", __ASSET__assets_sprites_hammer9_png);
		type.set ("assets/Sprites/hammer9.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hatate0.png", __ASSET__assets_sprites_hatate0_png);
		type.set ("assets/Sprites/hatate0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hina0.png", __ASSET__assets_sprites_hina0_png);
		type.set ("assets/Sprites/hina0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ichirin0.png", __ASSET__assets_sprites_ichirin0_png);
		type.set ("assets/Sprites/ichirin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/icyblock0.png", __ASSET__assets_sprites_icyblock0_png);
		type.set ("assets/Sprites/icyblock0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/iku0.png", __ASSET__assets_sprites_iku0_png);
		type.set ("assets/Sprites/iku0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ikuikudance0.png", __ASSET__assets_sprites_ikuikudance0_png);
		type.set ("assets/Sprites/ikuikudance0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kagerou0.png", __ASSET__assets_sprites_kagerou0_png);
		type.set ("assets/Sprites/kagerou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kaguya0.png", __ASSET__assets_sprites_kaguya0_png);
		type.set ("assets/Sprites/kaguya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kana0.png", __ASSET__assets_sprites_kana0_png);
		type.set ("assets/Sprites/kana0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kanako0.png", __ASSET__assets_sprites_kanako0_png);
		type.set ("assets/Sprites/kanako0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kasen0.png", __ASSET__assets_sprites_kasen0_png);
		type.set ("assets/Sprites/kasen0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/keine0.png", __ASSET__assets_sprites_keine0_png);
		type.set ("assets/Sprites/keine0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife0.png", __ASSET__assets_sprites_knife0_png);
		type.set ("assets/Sprites/knife0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife1.png", __ASSET__assets_sprites_knife1_png);
		type.set ("assets/Sprites/knife1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife2.png", __ASSET__assets_sprites_knife2_png);
		type.set ("assets/Sprites/knife2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife3.png", __ASSET__assets_sprites_knife3_png);
		type.set ("assets/Sprites/knife3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife4.png", __ASSET__assets_sprites_knife4_png);
		type.set ("assets/Sprites/knife4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife5.png", __ASSET__assets_sprites_knife5_png);
		type.set ("assets/Sprites/knife5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife6.png", __ASSET__assets_sprites_knife6_png);
		type.set ("assets/Sprites/knife6.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/knife7.png", __ASSET__assets_sprites_knife7_png);
		type.set ("assets/Sprites/knife7.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/koakuma0.png", __ASSET__assets_sprites_koakuma0_png);
		type.set ("assets/Sprites/koakuma0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kogasa0.png", __ASSET__assets_sprites_kogasa0_png);
		type.set ("assets/Sprites/kogasa0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kogasaflipped0.png", __ASSET__assets_sprites_kogasaflipped0_png);
		type.set ("assets/Sprites/kogasaflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/koishi0.png", __ASSET__assets_sprites_koishi0_png);
		type.set ("assets/Sprites/koishi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/koishiflipped0.png", __ASSET__assets_sprites_koishiflipped0_png);
		type.set ("assets/Sprites/koishiflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kokoro0.png", __ASSET__assets_sprites_kokoro0_png);
		type.set ("assets/Sprites/kokoro0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/komachi0.png", __ASSET__assets_sprites_komachi0_png);
		type.set ("assets/Sprites/komachi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/konngara0.png", __ASSET__assets_sprites_konngara0_png);
		type.set ("assets/Sprites/konngara0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kosuzu0.png", __ASSET__assets_sprites_kosuzu0_png);
		type.set ("assets/Sprites/kosuzu0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kotohime0.png", __ASSET__assets_sprites_kotohime0_png);
		type.set ("assets/Sprites/kotohime0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kurumi0.png", __ASSET__assets_sprites_kurumi0_png);
		type.set ("assets/Sprites/kurumi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/kyouko0.png", __ASSET__assets_sprites_kyouko0_png);
		type.set ("assets/Sprites/kyouko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/letty0.png", __ASSET__assets_sprites_letty0_png);
		type.set ("assets/Sprites/letty0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lightning0.png", __ASSET__assets_sprites_lightning0_png);
		type.set ("assets/Sprites/lightning0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lily0.png", __ASSET__assets_sprites_lily0_png);
		type.set ("assets/Sprites/lily0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/louise0.png", __ASSET__assets_sprites_louise0_png);
		type.set ("assets/Sprites/louise0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lunachild0.png", __ASSET__assets_sprites_lunachild0_png);
		type.set ("assets/Sprites/lunachild0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lunasa0.png", __ASSET__assets_sprites_lunasa0_png);
		type.set ("assets/Sprites/lunasa0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lyrica0.png", __ASSET__assets_sprites_lyrica0_png);
		type.set ("assets/Sprites/lyrica0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mai0.png", __ASSET__assets_sprites_mai0_png);
		type.set ("assets/Sprites/mai0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/makairesident-a0.png", __ASSET__assets_sprites_makairesident_a0_png);
		type.set ("assets/Sprites/makairesident-a0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/makairesident-b0.png", __ASSET__assets_sprites_makairesident_b0_png);
		type.set ("assets/Sprites/makairesident-b0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mamizou0.png", __ASSET__assets_sprites_mamizou0_png);
		type.set ("assets/Sprites/mamizou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/maribel0.png", __ASSET__assets_sprites_maribel0_png);
		type.set ("assets/Sprites/maribel0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/marisa0.png", __ASSET__assets_sprites_marisa0_png);
		type.set ("assets/Sprites/marisa0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/marisaALT0.png", __ASSET__assets_sprites_marisaalt0_png);
		type.set ("assets/Sprites/marisaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/matenshi0.png", __ASSET__assets_sprites_matenshi0_png);
		type.set ("assets/Sprites/matenshi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/medicine0.png", __ASSET__assets_sprites_medicine0_png);
		type.set ("assets/Sprites/medicine0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/meiling0.png", __ASSET__assets_sprites_meiling0_png);
		type.set ("assets/Sprites/meiling0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/meilingALT0.png", __ASSET__assets_sprites_meilingalt0_png);
		type.set ("assets/Sprites/meilingALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/meira0.png", __ASSET__assets_sprites_meira0_png);
		type.set ("assets/Sprites/meira0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/merlin0.png", __ASSET__assets_sprites_merlin0_png);
		type.set ("assets/Sprites/merlin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/miko0.png", __ASSET__assets_sprites_miko0_png);
		type.set ("assets/Sprites/miko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mima0.png", __ASSET__assets_sprites_mima0_png);
		type.set ("assets/Sprites/mima0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mimaALT0.png", __ASSET__assets_sprites_mimaalt0_png);
		type.set ("assets/Sprites/mimaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/minoriko0.png", __ASSET__assets_sprites_minoriko0_png);
		type.set ("assets/Sprites/minoriko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mokou0.png", __ASSET__assets_sprites_mokou0_png);
		type.set ("assets/Sprites/mokou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/momiji0.png", __ASSET__assets_sprites_momiji0_png);
		type.set ("assets/Sprites/momiji0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mrghosty0.png", __ASSET__assets_sprites_mrghosty0_png);
		type.set ("assets/Sprites/mrghosty0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mugetsu0.png", __ASSET__assets_sprites_mugetsu0_png);
		type.set ("assets/Sprites/mugetsu0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/murasa0.png", __ASSET__assets_sprites_murasa0_png);
		type.set ("assets/Sprites/murasa0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/myon0.png", __ASSET__assets_sprites_myon0_png);
		type.set ("assets/Sprites/myon0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mystia0.png", __ASSET__assets_sprites_mystia0_png);
		type.set ("assets/Sprites/mystia0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mystiaALT0.png", __ASSET__assets_sprites_mystiaalt0_png);
		type.set ("assets/Sprites/mystiaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/nazrin0.png", __ASSET__assets_sprites_nazrin0_png);
		type.set ("assets/Sprites/nazrin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/nazrinflipped0.png", __ASSET__assets_sprites_nazrinflipped0_png);
		type.set ("assets/Sprites/nazrinflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/nitori0.png", __ASSET__assets_sprites_nitori0_png);
		type.set ("assets/Sprites/nitori0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/noroiko0.png", __ASSET__assets_sprites_noroiko0_png);
		type.set ("assets/Sprites/noroiko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/nue0.png", __ASSET__assets_sprites_nue0_png);
		type.set ("assets/Sprites/nue0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/options0.png", __ASSET__assets_sprites_options0_png);
		type.set ("assets/Sprites/options0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/orange0.png", __ASSET__assets_sprites_orange0_png);
		type.set ("assets/Sprites/orange0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/orin0.png", __ASSET__assets_sprites_orin0_png);
		type.set ("assets/Sprites/orin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/parsee0.png", __ASSET__assets_sprites_parsee0_png);
		type.set ("assets/Sprites/parsee0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/patchouli0.png", __ASSET__assets_sprites_patchouli0_png);
		type.set ("assets/Sprites/patchouli0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/pika0.png", __ASSET__assets_sprites_pika0_png);
		type.set ("assets/Sprites/pika0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Point0.png", __ASSET__assets_sprites_point0_png);
		type.set ("assets/Sprites/Point0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/POW0.png", __ASSET__assets_sprites_pow0_png);
		type.set ("assets/Sprites/POW0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/POWalt0.png", __ASSET__assets_sprites_powalt0_png);
		type.set ("assets/Sprites/POWalt0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/prinny0.png", __ASSET__assets_sprites_prinny0_png);
		type.set ("assets/Sprites/prinny0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/raiko0.png", __ASSET__assets_sprites_raiko0_png);
		type.set ("assets/Sprites/raiko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ran0.png", __ASSET__assets_sprites_ran0_png);
		type.set ("assets/Sprites/ran0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/RedFairy0.png", __ASSET__assets_sprites_redfairy0_png);
		type.set ("assets/Sprites/RedFairy0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/RedFairyflipped0.png", __ASSET__assets_sprites_redfairyflipped0_png);
		type.set ("assets/Sprites/RedFairyflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Redufo0.png", __ASSET__assets_sprites_redufo0_png);
		type.set ("assets/Sprites/Redufo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/reimu0.png", __ASSET__assets_sprites_reimu0_png);
		type.set ("assets/Sprites/reimu0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/reimuALT0.png", __ASSET__assets_sprites_reimualt0_png);
		type.set ("assets/Sprites/reimuALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/reimuflipped0.png", __ASSET__assets_sprites_reimuflipped0_png);
		type.set ("assets/Sprites/reimuflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/reisen0.png", __ASSET__assets_sprites_reisen0_png);
		type.set ("assets/Sprites/reisen0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/remilia0.png", __ASSET__assets_sprites_remilia0_png);
		type.set ("assets/Sprites/remilia0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/rengeteki0.png", __ASSET__assets_sprites_rengeteki0_png);
		type.set ("assets/Sprites/rengeteki0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/renko0.png", __ASSET__assets_sprites_renko0_png);
		type.set ("assets/Sprites/renko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/rika0.png", __ASSET__assets_sprites_rika0_png);
		type.set ("assets/Sprites/rika0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/rikako0.png", __ASSET__assets_sprites_rikako0_png);
		type.set ("assets/Sprites/rikako0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/rin0.png", __ASSET__assets_sprites_rin0_png);
		type.set ("assets/Sprites/rin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ringo0.png", __ASSET__assets_sprites_ringo0_png);
		type.set ("assets/Sprites/ringo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/rumia0.png", __ASSET__assets_sprites_rumia0_png);
		type.set ("assets/Sprites/rumia0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ruukoto0.png", __ASSET__assets_sprites_ruukoto0_png);
		type.set ("assets/Sprites/ruukoto0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sakuya0.png", __ASSET__assets_sprites_sakuya0_png);
		type.set ("assets/Sprites/sakuya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sakuyaALT0.png", __ASSET__assets_sprites_sakuyaalt0_png);
		type.set ("assets/Sprites/sakuyaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sanae0.png", __ASSET__assets_sprites_sanae0_png);
		type.set ("assets/Sprites/sanae0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sanaeALT0.png", __ASSET__assets_sprites_sanaealt0_png);
		type.set ("assets/Sprites/sanaeALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sara0.png", __ASSET__assets_sprites_sara0_png);
		type.set ("assets/Sprites/sara0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sariel0.png", __ASSET__assets_sprites_sariel0_png);
		type.set ("assets/Sprites/sariel0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/satori0.png", __ASSET__assets_sprites_satori0_png);
		type.set ("assets/Sprites/satori0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/satoriflipped0.png", __ASSET__assets_sprites_satoriflipped0_png);
		type.set ("assets/Sprites/satoriflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/seiga0.png", __ASSET__assets_sprites_seiga0_png);
		type.set ("assets/Sprites/seiga0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/seija0.png", __ASSET__assets_sprites_seija0_png);
		type.set ("assets/Sprites/seija0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/seiran0.png", __ASSET__assets_sprites_seiran0_png);
		type.set ("assets/Sprites/seiran0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sekibanki0.png", __ASSET__assets_sprites_sekibanki0_png);
		type.set ("assets/Sprites/sekibanki0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shanghai0.png", __ASSET__assets_sprites_shanghai0_png);
		type.set ("assets/Sprites/shanghai0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shikieiki0.png", __ASSET__assets_sprites_shikieiki0_png);
		type.set ("assets/Sprites/shikieiki0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shingyoku0.png", __ASSET__assets_sprites_shingyoku0_png);
		type.set ("assets/Sprites/shingyoku0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shingyokuALT0.png", __ASSET__assets_sprites_shingyokualt0_png);
		type.set ("assets/Sprites/shingyokuALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shinki0.png", __ASSET__assets_sprites_shinki0_png);
		type.set ("assets/Sprites/shinki0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shinmyoumaru0.png", __ASSET__assets_sprites_shinmyoumaru0_png);
		type.set ("assets/Sprites/shinmyoumaru0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shizuha0.png", __ASSET__assets_sprites_shizuha0_png);
		type.set ("assets/Sprites/shizuha0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shou0.png", __ASSET__assets_sprites_shou0_png);
		type.set ("assets/Sprites/shou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/skull0.png", __ASSET__assets_sprites_skull0_png);
		type.set ("assets/Sprites/skull0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/starbulletg0.png", __ASSET__assets_sprites_starbulletg0_png);
		type.set ("assets/Sprites/starbulletg0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/starbullety0.png", __ASSET__assets_sprites_starbullety0_png);
		type.set ("assets/Sprites/starbullety0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/starsaphire0.png", __ASSET__assets_sprites_starsaphire0_png);
		type.set ("assets/Sprites/starsaphire0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/suika0.png", __ASSET__assets_sprites_suika0_png);
		type.set ("assets/Sprites/suika0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sumireko0.png", __ASSET__assets_sprites_sumireko0_png);
		type.set ("assets/Sprites/sumireko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sunnymilk0.png", __ASSET__assets_sprites_sunnymilk0_png);
		type.set ("assets/Sprites/sunnymilk0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/suwako0.png", __ASSET__assets_sprites_suwako0_png);
		type.set ("assets/Sprites/suwako0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table0.png", __ASSET__assets_sprites_table0_png);
		type.set ("assets/Sprites/table0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table1.png", __ASSET__assets_sprites_table1_png);
		type.set ("assets/Sprites/table1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table10.png", __ASSET__assets_sprites_table10_png);
		type.set ("assets/Sprites/table10.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table11.png", __ASSET__assets_sprites_table11_png);
		type.set ("assets/Sprites/table11.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table12.png", __ASSET__assets_sprites_table12_png);
		type.set ("assets/Sprites/table12.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table13.png", __ASSET__assets_sprites_table13_png);
		type.set ("assets/Sprites/table13.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table14.png", __ASSET__assets_sprites_table14_png);
		type.set ("assets/Sprites/table14.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table15.png", __ASSET__assets_sprites_table15_png);
		type.set ("assets/Sprites/table15.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table2.png", __ASSET__assets_sprites_table2_png);
		type.set ("assets/Sprites/table2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table3.png", __ASSET__assets_sprites_table3_png);
		type.set ("assets/Sprites/table3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table4.png", __ASSET__assets_sprites_table4_png);
		type.set ("assets/Sprites/table4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table5.png", __ASSET__assets_sprites_table5_png);
		type.set ("assets/Sprites/table5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table6.png", __ASSET__assets_sprites_table6_png);
		type.set ("assets/Sprites/table6.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table7.png", __ASSET__assets_sprites_table7_png);
		type.set ("assets/Sprites/table7.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table8.png", __ASSET__assets_sprites_table8_png);
		type.set ("assets/Sprites/table8.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/table9.png", __ASSET__assets_sprites_table9_png);
		type.set ("assets/Sprites/table9.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/tenshi0.png", __ASSET__assets_sprites_tenshi0_png);
		type.set ("assets/Sprites/tenshi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/tewi0.png", __ASSET__assets_sprites_tewi0_png);
		type.set ("assets/Sprites/tewi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/tewiflipped0.png", __ASSET__assets_sprites_tewiflipped0_png);
		type.set ("assets/Sprites/tewiflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/titlescreen0.png", __ASSET__assets_sprites_titlescreen0_png);
		type.set ("assets/Sprites/titlescreen0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/tojiko0.png", __ASSET__assets_sprites_tojiko0_png);
		type.set ("assets/Sprites/tojiko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/tokiko0.png", __ASSET__assets_sprites_tokiko0_png);
		type.set ("assets/Sprites/tokiko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/toyohime0.png", __ASSET__assets_sprites_toyohime0_png);
		type.set ("assets/Sprites/toyohime0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/trophy0.png", __ASSET__assets_sprites_trophy0_png);
		type.set ("assets/Sprites/trophy0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/truck0.png", __ASSET__assets_sprites_truck0_png);
		type.set ("assets/Sprites/truck0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/udongein0.png", __ASSET__assets_sprites_udongein0_png);
		type.set ("assets/Sprites/udongein0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/udongeinflipped0.png", __ASSET__assets_sprites_udongeinflipped0_png);
		type.set ("assets/Sprites/udongeinflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/unused0.png", __ASSET__assets_sprites_unused0_png);
		type.set ("assets/Sprites/unused0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/unzanfist0.png", __ASSET__assets_sprites_unzanfist0_png);
		type.set ("assets/Sprites/unzanfist0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/utsuho0.png", __ASSET__assets_sprites_utsuho0_png);
		type.set ("assets/Sprites/utsuho0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/wakasagihime0.png", __ASSET__assets_sprites_wakasagihime0_png);
		type.set ("assets/Sprites/wakasagihime0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/wriggle0.png", __ASSET__assets_sprites_wriggle0_png);
		type.set ("assets/Sprites/wriggle0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yamame0.png", __ASSET__assets_sprites_yamame0_png);
		type.set ("assets/Sprites/yamame0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yatsuhashi0.png", __ASSET__assets_sprites_yatsuhashi0_png);
		type.set ("assets/Sprites/yatsuhashi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb0.png", __ASSET__assets_sprites_yinyangorb0_png);
		type.set ("assets/Sprites/yinyangorb0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb1.png", __ASSET__assets_sprites_yinyangorb1_png);
		type.set ("assets/Sprites/yinyangorb1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb10.png", __ASSET__assets_sprites_yinyangorb10_png);
		type.set ("assets/Sprites/yinyangorb10.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb11.png", __ASSET__assets_sprites_yinyangorb11_png);
		type.set ("assets/Sprites/yinyangorb11.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb12.png", __ASSET__assets_sprites_yinyangorb12_png);
		type.set ("assets/Sprites/yinyangorb12.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb13.png", __ASSET__assets_sprites_yinyangorb13_png);
		type.set ("assets/Sprites/yinyangorb13.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb14.png", __ASSET__assets_sprites_yinyangorb14_png);
		type.set ("assets/Sprites/yinyangorb14.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb15.png", __ASSET__assets_sprites_yinyangorb15_png);
		type.set ("assets/Sprites/yinyangorb15.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb2.png", __ASSET__assets_sprites_yinyangorb2_png);
		type.set ("assets/Sprites/yinyangorb2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb3.png", __ASSET__assets_sprites_yinyangorb3_png);
		type.set ("assets/Sprites/yinyangorb3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb4.png", __ASSET__assets_sprites_yinyangorb4_png);
		type.set ("assets/Sprites/yinyangorb4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb5.png", __ASSET__assets_sprites_yinyangorb5_png);
		type.set ("assets/Sprites/yinyangorb5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb6.png", __ASSET__assets_sprites_yinyangorb6_png);
		type.set ("assets/Sprites/yinyangorb6.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb7.png", __ASSET__assets_sprites_yinyangorb7_png);
		type.set ("assets/Sprites/yinyangorb7.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb8.png", __ASSET__assets_sprites_yinyangorb8_png);
		type.set ("assets/Sprites/yinyangorb8.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yinyangorb9.png", __ASSET__assets_sprites_yinyangorb9_png);
		type.set ("assets/Sprites/yinyangorb9.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yorihime0.png", __ASSET__assets_sprites_yorihime0_png);
		type.set ("assets/Sprites/yorihime0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yoshika0.png", __ASSET__assets_sprites_yoshika0_png);
		type.set ("assets/Sprites/yoshika0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/youmu0.png", __ASSET__assets_sprites_youmu0_png);
		type.set ("assets/Sprites/youmu0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yukari0.png", __ASSET__assets_sprites_yukari0_png);
		type.set ("assets/Sprites/yukari0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yuki0.png", __ASSET__assets_sprites_yuki0_png);
		type.set ("assets/Sprites/yuki0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yumeko0.png", __ASSET__assets_sprites_yumeko0_png);
		type.set ("assets/Sprites/yumeko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yumemi0.png", __ASSET__assets_sprites_yumemi0_png);
		type.set ("assets/Sprites/yumemi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yuugi0.png", __ASSET__assets_sprites_yuugi0_png);
		type.set ("assets/Sprites/yuugi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yuuka0.png", __ASSET__assets_sprites_yuuka0_png);
		type.set ("assets/Sprites/yuuka0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yuukaALT0.png", __ASSET__assets_sprites_yuukaalt0_png);
		type.set ("assets/Sprites/yuukaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yuyuko0.png", __ASSET__assets_sprites_yuyuko0_png);
		type.set ("assets/Sprites/yuyuko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/zombiefairy0.png", __ASSET__assets_sprites_zombiefairy0_png);
		type.set ("assets/Sprites/zombiefairy0.png", AssetType.IMAGE);
		
		
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
	
	
	public override function exists (id:String, type:String):Bool {
		
		var requestedType = type != null ? cast (type, AssetType) : null;
		var assetType = this.type.get (id);
		
		if (assetType != null) {
			
			if (assetType == requestedType || ((requestedType == SOUND || requestedType == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if ((assetType == BINARY || assetType == TEXT) && requestedType == BINARY) {
				
				return true;
				
			} else if (path.exists (id)) {
				
				return true;
				
			}
			
			#else
			
			if (requestedType == BINARY || requestedType == null || (assetType == BINARY && requestedType == TEXT)) {
				
				return true;
				
			}
			
			#end
			
		}
		
		return false;
		
	}
	
	
	public override function getAudioBuffer (id:String):AudioBuffer {
		
		#if flash
		
		var buffer = new AudioBuffer ();
		buffer.src = cast (Type.createInstance (className.get (id), []), Sound);
		return buffer;
		
		#elseif html5
		
		return null;
		//return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		return AudioBuffer.fromFile (path.get (id));
		//if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		//else return new Sound (new URLRequest (path.get (id)), null, type.get (id) == MUSIC);
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if flash
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);
		
		#elseif html5
		
		var bytes:ByteArray = null;
		var data = Preloader.loaders.get (path.get (id)).data;
		
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
	
	
	public override function getFont (id:String):Dynamic /*Font*/ {
		
		// TODO: Complete Lime Font API
		
		#if openfl
		#if (flash || js)
		
		return cast (Type.createInstance (className.get (id), []), openfl.text.Font);
		
		#else
		
		if (className.exists (id)) {
			
			var fontClass = className.get (id);
			openfl.text.Font.registerFont (fontClass);
			return cast (Type.createInstance (fontClass, []), openfl.text.Font);
			
		} else {
			
			return new openfl.text.Font (path.get (id));
			
		}
		
		#end
		#end
		
		return null;
		
	}
	
	
	public override function getImage (id:String):Image {
		
		#if flash
		
		return Image.fromBitmapData (cast (Type.createInstance (className.get (id), []), BitmapData));
		
		#elseif html5
		
		return Image.fromImageElement (Preloader.images.get (path.get (id)));
		
		#else
		
		return Image.fromFile (path.get (id));
		
		#end
		
	}
	
	
	/*public override function getMusic (id:String):Dynamic {
		
		#if flash
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif openfl_html5
		
		//var sound = new Sound ();
		//sound.__buffer = true;
		//sound.load (new URLRequest (path.get (id)));
		//return sound;
		return null;
		
		#elseif html5
		
		return null;
		//return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		return null;
		//if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		//else return new Sound (new URLRequest (path.get (id)), null, true);
		
		#end
		
	}*/
	
	
	public override function getPath (id:String):String {
		
		//#if ios
		
		//return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		//#else
		
		return path.get (id);
		
		//#end
		
	}
	
	
	public override function getText (id:String):String {
		
		#if html5
		
		var bytes:ByteArray = null;
		var data = Preloader.loaders.get (path.get (id)).data;
		
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
	
	
	public override function isLocal (id:String, type:String):Bool {
		
		var requestedType = type != null ? cast (type, AssetType) : null;
		
		#if flash
		
		if (requestedType != AssetType.MUSIC && requestedType != AssetType.SOUND) {
			
			return className.exists (id);
			
		}
		
		#end
		
		return true;
		
	}
	
	
	public override function list (type:String):Array<String> {
		
		var requestedType = type != null ? cast (type, AssetType) : null;
		var items = [];
		
		for (id in this.type.keys ()) {
			
			if (requestedType == null || exists (id, type)) {
				
				items.push (id);
				
			}
			
		}
		
		return items;
		
	}
	
	
	public override function loadAudioBuffer (id:String, handler:AudioBuffer -> Void):Void {
		
		#if (flash)
		if (path.exists (id)) {
			
			var soundLoader = new Sound ();
			soundLoader.addEventListener (Event.COMPLETE, function (event) {
				
				var audioBuffer:AudioBuffer = new AudioBuffer();
				audioBuffer.src = event.currentTarget;
				handler (audioBuffer);
				
			});
			soundLoader.load (new URLRequest (path.get (id)));
			
		} else {
			handler (getAudioBuffer (id));
			
		}
		#else
		handler (getAudioBuffer (id));
		
		#end
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		#if flash
		
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
	
	
	public override function loadImage (id:String, handler:Image -> Void):Void {
		
		#if flash
		
		if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bitmapData = cast (event.currentTarget.content, Bitmap).bitmapData;
				handler (Image.fromBitmapData (bitmapData));
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getImage (id));
			
		}
		
		#else
		
		handler (getImage (id));
		
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
			#elseif (mac && java)
			var bytes = ByteArray.readFile ("../Resources/manifest");
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
								type.set (asset.id, cast (asset.type, AssetType));
								
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
	
	
	/*public override function loadMusic (id:String, handler:Dynamic -> Void):Void {
		
		#if (flash || js)
		
		//if (path.exists (id)) {
			
		//	var loader = new Loader ();
		//	loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
		//		handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
		//	});
		//	loader.load (new URLRequest (path.get (id)));
			
		//} else {
			
			handler (getMusic (id));
			
		//}
		
		#else
		
		handler (getMusic (id));
		
		#end
		
	}*/
	
	
	public override function loadText (id:String, handler:String -> Void):Void {
		
		//#if html5
		
		/*if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (event.currentTarget.data);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getText (id));
			
		}*/
		
		//#else
		
		var callback = function (bytes:ByteArray):Void {
			
			if (bytes == null) {
				
				handler (null);
				
			} else {
				
				handler (bytes.readUTFBytes (bytes.length));
				
			}
			
		}
		
		loadBytes (id, callback);
		
		//#end
		
	}
	
	
}


#if !display
#if flash

@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_bonk_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_characterselect_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_collectcoin_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_died_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_extend_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_finalkill_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_fireballspawn_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_gameover_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_killenemy_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_masterspark_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_nextlevel_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_pow_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_respawn_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_spawncoin_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_startgame_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_step1_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_step2_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_step3_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme1_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme10_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme11_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme12_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme12intro_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme2_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme3_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme4_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme5_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme6_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme7_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme8_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme8intro_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_theme9_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_ogg_titlescreen_ogg extends null { }
@:keep @:bind #if display private #end class __ASSET__assets_bgcolor_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_black_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_dpad_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_1up0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_akyu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_alice0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_alicealt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_aya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ayana0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_balloon0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_barrier0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_benben0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_black0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_block0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bluefairy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bluefairyflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_blueufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bomb0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_byakuren0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_charblock0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_chen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_chiyuri0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_cirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_csbg0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_daiyousei0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_darkness0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_diosakuya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_doremy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen10_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen11_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen12_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen13_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen14_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen15_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen8_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_echen9_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ecirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eirin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeineex0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeineexflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_electriccirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_elis0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ellen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_elly0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emystia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emystia1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emystiaflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran10_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran11_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran12_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran13_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran14_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran15_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran8_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eran9_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_evilyuuka0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_exkeine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_firecirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flandre0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_futo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_gap0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_gengetsu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_giantcirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_giantsuika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_greenufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer10_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer11_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer12_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer13_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer14_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer15_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer8_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hammer9_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hatate0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hina0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ichirin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_icyblock0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_iku0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ikuikudance0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kagerou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kaguya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kana0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kanako0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kasen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_keine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_koakuma0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kogasa0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kogasaflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_koishi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_koishiflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kokoro0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_komachi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_konngara0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kosuzu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kotohime0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kurumi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kyouko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_letty0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lightning0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lily0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_louise0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lunachild0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lunasa0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lyrica0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mai0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_makairesident_a0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_makairesident_b0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mamizou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_maribel0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_marisa0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_marisaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_matenshi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_medicine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meiling0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meilingalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meira0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_merlin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_miko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mima0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mimaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_minoriko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mokou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_momiji0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mrghosty0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mugetsu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_murasa0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_myon0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mystia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mystiaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_nazrin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_nazrinflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_nitori0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_noroiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_nue0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_options0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_orange0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_orin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_parsee0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_patchouli0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_point0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pow0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_powalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_prinny0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_raiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ran0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redfairy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redfairyflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reimu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reimualt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reimuflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reisen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_remilia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rengeteki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_renko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rikako0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ringo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rumia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ruukoto0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sakuya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sakuyaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sanae0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sanaealt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sara0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sariel0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_satori0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_satoriflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_seiga0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_seija0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_seiran0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sekibanki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shanghai0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shikieiki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shingyoku0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shingyokualt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shinki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shinmyoumaru0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shizuha0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_skull0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_starbulletg0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_starbullety0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_starsaphire0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_suika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sumireko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sunnymilk0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_suwako0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table10_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table11_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table12_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table13_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table14_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table15_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table8_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_table9_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tenshi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tewi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tewiflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_titlescreen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tojiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tokiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_toyohime0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_trophy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_truck0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_udongein0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_udongeinflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_unused0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_unzanfist0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_utsuho0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_wakasagihime0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_wriggle0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yamame0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yatsuhashi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb10_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb11_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb12_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb13_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb14_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb15_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb8_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yinyangorb9_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yorihime0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yoshika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_youmu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yukari0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yumeko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yumemi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuugi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuuka0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuukaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuyuko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_zombiefairy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }


#elseif html5

#if openfl









































































































































































































































































































































#end

#else

#if openfl

#end

#if (windows || mac || linux)


@:sound("Assets/Audio/Ogg/bonk.OGG") class __ASSET__assets_audio_ogg_bonk_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/characterselect.OGG") class __ASSET__assets_audio_ogg_characterselect_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/collectcoin.OGG") class __ASSET__assets_audio_ogg_collectcoin_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/died.OGG") class __ASSET__assets_audio_ogg_died_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/extend.OGG") class __ASSET__assets_audio_ogg_extend_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/finalkill.OGG") class __ASSET__assets_audio_ogg_finalkill_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/fireballspawn.OGG") class __ASSET__assets_audio_ogg_fireballspawn_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/gameover.OGG") class __ASSET__assets_audio_ogg_gameover_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/killenemy.OGG") class __ASSET__assets_audio_ogg_killenemy_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/masterspark.OGG") class __ASSET__assets_audio_ogg_masterspark_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/nextlevel.OGG") class __ASSET__assets_audio_ogg_nextlevel_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/pow.OGG") class __ASSET__assets_audio_ogg_pow_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/respawn.OGG") class __ASSET__assets_audio_ogg_respawn_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/spawncoin.OGG") class __ASSET__assets_audio_ogg_spawncoin_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/startgame.OGG") class __ASSET__assets_audio_ogg_startgame_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/step1.OGG") class __ASSET__assets_audio_ogg_step1_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/step2.OGG") class __ASSET__assets_audio_ogg_step2_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/step3.OGG") class __ASSET__assets_audio_ogg_step3_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme1.OGG") class __ASSET__assets_audio_ogg_theme1_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme10.OGG") class __ASSET__assets_audio_ogg_theme10_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme11.OGG") class __ASSET__assets_audio_ogg_theme11_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme12.OGG") class __ASSET__assets_audio_ogg_theme12_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme12intro.OGG") class __ASSET__assets_audio_ogg_theme12intro_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme2.OGG") class __ASSET__assets_audio_ogg_theme2_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme3.OGG") class __ASSET__assets_audio_ogg_theme3_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme4.OGG") class __ASSET__assets_audio_ogg_theme4_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme5.OGG") class __ASSET__assets_audio_ogg_theme5_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme6.OGG") class __ASSET__assets_audio_ogg_theme6_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme7.OGG") class __ASSET__assets_audio_ogg_theme7_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme8.OGG") class __ASSET__assets_audio_ogg_theme8_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme8intro.OGG") class __ASSET__assets_audio_ogg_theme8intro_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/theme9.OGG") class __ASSET__assets_audio_ogg_theme9_ogg extends lime.audio.AudioSource {}
@:sound("Assets/Audio/Ogg/titlescreen.OGG") class __ASSET__assets_audio_ogg_titlescreen_ogg extends lime.audio.AudioSource {}
@:bitmap("Assets/bgcolor.png") class __ASSET__assets_bgcolor_png extends lime.graphics.Image {}
@:bitmap("Assets/black.png") class __ASSET__assets_black_png extends lime.graphics.Image {}
@:bitmap("Assets/Dpad.png") class __ASSET__assets_dpad_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/1up0.png") class __ASSET__assets_sprites_1up0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/akyu0.png") class __ASSET__assets_sprites_akyu0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/alice0.png") class __ASSET__assets_sprites_alice0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/aliceALT0.png") class __ASSET__assets_sprites_alicealt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/aya0.png") class __ASSET__assets_sprites_aya0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ayana0.png") class __ASSET__assets_sprites_ayana0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/balloon0.png") class __ASSET__assets_sprites_balloon0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/barrier0.png") class __ASSET__assets_sprites_barrier0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/benben0.png") class __ASSET__assets_sprites_benben0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BG0.png") class __ASSET__assets_sprites_bg0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BG1.png") class __ASSET__assets_sprites_bg1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BG2.png") class __ASSET__assets_sprites_bg2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BG3.png") class __ASSET__assets_sprites_bg3_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BG4.png") class __ASSET__assets_sprites_bg4_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BG5.png") class __ASSET__assets_sprites_bg5_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/black0.png") class __ASSET__assets_sprites_black0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/block0.png") class __ASSET__assets_sprites_block0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BlueFairy0.png") class __ASSET__assets_sprites_bluefairy0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/BlueFairyflipped0.png") class __ASSET__assets_sprites_bluefairyflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/Blueufo0.png") class __ASSET__assets_sprites_blueufo0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/bomb0.png") class __ASSET__assets_sprites_bomb0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/bullet0.png") class __ASSET__assets_sprites_bullet0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/byakuren0.png") class __ASSET__assets_sprites_byakuren0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/charblock0.png") class __ASSET__assets_sprites_charblock0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/chen0.png") class __ASSET__assets_sprites_chen0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/chiyuri0.png") class __ASSET__assets_sprites_chiyuri0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/cirno0.png") class __ASSET__assets_sprites_cirno0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/CSBG0.png") class __ASSET__assets_sprites_csbg0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/daiyousei0.png") class __ASSET__assets_sprites_daiyousei0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/darkness0.png") class __ASSET__assets_sprites_darkness0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/diosakuya0.png") class __ASSET__assets_sprites_diosakuya0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/doremy0.png") class __ASSET__assets_sprites_doremy0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen0.png") class __ASSET__assets_sprites_echen0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen1.png") class __ASSET__assets_sprites_echen1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen10.png") class __ASSET__assets_sprites_echen10_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen11.png") class __ASSET__assets_sprites_echen11_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen12.png") class __ASSET__assets_sprites_echen12_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen13.png") class __ASSET__assets_sprites_echen13_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen14.png") class __ASSET__assets_sprites_echen14_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen15.png") class __ASSET__assets_sprites_echen15_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen2.png") class __ASSET__assets_sprites_echen2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen3.png") class __ASSET__assets_sprites_echen3_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen4.png") class __ASSET__assets_sprites_echen4_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen5.png") class __ASSET__assets_sprites_echen5_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen6.png") class __ASSET__assets_sprites_echen6_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen7.png") class __ASSET__assets_sprites_echen7_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen8.png") class __ASSET__assets_sprites_echen8_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EChen9.png") class __ASSET__assets_sprites_echen9_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ECirno0.png") class __ASSET__assets_sprites_ecirno0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/eirin0.png") class __ASSET__assets_sprites_eirin0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EKeine0.png") class __ASSET__assets_sprites_ekeine0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EKeineex0.png") class __ASSET__assets_sprites_ekeineex0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EKeineexflipped0.png") class __ASSET__assets_sprites_ekeineexflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/electriccirno0.png") class __ASSET__assets_sprites_electriccirno0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/elis0.png") class __ASSET__assets_sprites_elis0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ellen0.png") class __ASSET__assets_sprites_ellen0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/elly0.png") class __ASSET__assets_sprites_elly0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EMystia0.png") class __ASSET__assets_sprites_emystia0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EMystia1.png") class __ASSET__assets_sprites_emystia1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/EMystiaflipped0.png") class __ASSET__assets_sprites_emystiaflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan0.png") class __ASSET__assets_sprites_eran0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan1.png") class __ASSET__assets_sprites_eran1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan10.png") class __ASSET__assets_sprites_eran10_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan11.png") class __ASSET__assets_sprites_eran11_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan12.png") class __ASSET__assets_sprites_eran12_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan13.png") class __ASSET__assets_sprites_eran13_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan14.png") class __ASSET__assets_sprites_eran14_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan15.png") class __ASSET__assets_sprites_eran15_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan2.png") class __ASSET__assets_sprites_eran2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan3.png") class __ASSET__assets_sprites_eran3_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan4.png") class __ASSET__assets_sprites_eran4_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan5.png") class __ASSET__assets_sprites_eran5_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan6.png") class __ASSET__assets_sprites_eran6_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan7.png") class __ASSET__assets_sprites_eran7_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan8.png") class __ASSET__assets_sprites_eran8_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ERan9.png") class __ASSET__assets_sprites_eran9_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/evilyuuka0.png") class __ASSET__assets_sprites_evilyuuka0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/exkeine0.png") class __ASSET__assets_sprites_exkeine0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/firecirno0.png") class __ASSET__assets_sprites_firecirno0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/flames0.png") class __ASSET__assets_sprites_flames0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/flames1.png") class __ASSET__assets_sprites_flames1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/flames2.png") class __ASSET__assets_sprites_flames2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/flandre0.png") class __ASSET__assets_sprites_flandre0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/futo0.png") class __ASSET__assets_sprites_futo0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/Gap0.png") class __ASSET__assets_sprites_gap0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/gengetsu0.png") class __ASSET__assets_sprites_gengetsu0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/giantcirno0.png") class __ASSET__assets_sprites_giantcirno0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/giantsuika0.png") class __ASSET__assets_sprites_giantsuika0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/Greenufo0.png") class __ASSET__assets_sprites_greenufo0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer0.png") class __ASSET__assets_sprites_hammer0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer1.png") class __ASSET__assets_sprites_hammer1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer10.png") class __ASSET__assets_sprites_hammer10_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer11.png") class __ASSET__assets_sprites_hammer11_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer12.png") class __ASSET__assets_sprites_hammer12_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer13.png") class __ASSET__assets_sprites_hammer13_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer14.png") class __ASSET__assets_sprites_hammer14_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer15.png") class __ASSET__assets_sprites_hammer15_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer2.png") class __ASSET__assets_sprites_hammer2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer3.png") class __ASSET__assets_sprites_hammer3_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer4.png") class __ASSET__assets_sprites_hammer4_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer5.png") class __ASSET__assets_sprites_hammer5_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer6.png") class __ASSET__assets_sprites_hammer6_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer7.png") class __ASSET__assets_sprites_hammer7_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer8.png") class __ASSET__assets_sprites_hammer8_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hammer9.png") class __ASSET__assets_sprites_hammer9_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hatate0.png") class __ASSET__assets_sprites_hatate0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/hina0.png") class __ASSET__assets_sprites_hina0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ichirin0.png") class __ASSET__assets_sprites_ichirin0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/icyblock0.png") class __ASSET__assets_sprites_icyblock0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/iku0.png") class __ASSET__assets_sprites_iku0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ikuikudance0.png") class __ASSET__assets_sprites_ikuikudance0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kagerou0.png") class __ASSET__assets_sprites_kagerou0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kaguya0.png") class __ASSET__assets_sprites_kaguya0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kana0.png") class __ASSET__assets_sprites_kana0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kanako0.png") class __ASSET__assets_sprites_kanako0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kasen0.png") class __ASSET__assets_sprites_kasen0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/keine0.png") class __ASSET__assets_sprites_keine0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife0.png") class __ASSET__assets_sprites_knife0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife1.png") class __ASSET__assets_sprites_knife1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife2.png") class __ASSET__assets_sprites_knife2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife3.png") class __ASSET__assets_sprites_knife3_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife4.png") class __ASSET__assets_sprites_knife4_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife5.png") class __ASSET__assets_sprites_knife5_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife6.png") class __ASSET__assets_sprites_knife6_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/knife7.png") class __ASSET__assets_sprites_knife7_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/koakuma0.png") class __ASSET__assets_sprites_koakuma0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kogasa0.png") class __ASSET__assets_sprites_kogasa0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kogasaflipped0.png") class __ASSET__assets_sprites_kogasaflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/koishi0.png") class __ASSET__assets_sprites_koishi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/koishiflipped0.png") class __ASSET__assets_sprites_koishiflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kokoro0.png") class __ASSET__assets_sprites_kokoro0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/komachi0.png") class __ASSET__assets_sprites_komachi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/konngara0.png") class __ASSET__assets_sprites_konngara0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kosuzu0.png") class __ASSET__assets_sprites_kosuzu0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kotohime0.png") class __ASSET__assets_sprites_kotohime0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kurumi0.png") class __ASSET__assets_sprites_kurumi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/kyouko0.png") class __ASSET__assets_sprites_kyouko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/letty0.png") class __ASSET__assets_sprites_letty0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/lightning0.png") class __ASSET__assets_sprites_lightning0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/lily0.png") class __ASSET__assets_sprites_lily0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/louise0.png") class __ASSET__assets_sprites_louise0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/lunachild0.png") class __ASSET__assets_sprites_lunachild0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/lunasa0.png") class __ASSET__assets_sprites_lunasa0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/lyrica0.png") class __ASSET__assets_sprites_lyrica0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mai0.png") class __ASSET__assets_sprites_mai0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/makairesident-a0.png") class __ASSET__assets_sprites_makairesident_a0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/makairesident-b0.png") class __ASSET__assets_sprites_makairesident_b0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mamizou0.png") class __ASSET__assets_sprites_mamizou0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/maribel0.png") class __ASSET__assets_sprites_maribel0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/marisa0.png") class __ASSET__assets_sprites_marisa0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/marisaALT0.png") class __ASSET__assets_sprites_marisaalt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/matenshi0.png") class __ASSET__assets_sprites_matenshi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/medicine0.png") class __ASSET__assets_sprites_medicine0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/meiling0.png") class __ASSET__assets_sprites_meiling0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/meilingALT0.png") class __ASSET__assets_sprites_meilingalt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/meira0.png") class __ASSET__assets_sprites_meira0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/merlin0.png") class __ASSET__assets_sprites_merlin0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/miko0.png") class __ASSET__assets_sprites_miko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mima0.png") class __ASSET__assets_sprites_mima0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mimaALT0.png") class __ASSET__assets_sprites_mimaalt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/minoriko0.png") class __ASSET__assets_sprites_minoriko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mokou0.png") class __ASSET__assets_sprites_mokou0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/momiji0.png") class __ASSET__assets_sprites_momiji0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mrghosty0.png") class __ASSET__assets_sprites_mrghosty0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mugetsu0.png") class __ASSET__assets_sprites_mugetsu0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/murasa0.png") class __ASSET__assets_sprites_murasa0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/myon0.png") class __ASSET__assets_sprites_myon0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mystia0.png") class __ASSET__assets_sprites_mystia0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/mystiaALT0.png") class __ASSET__assets_sprites_mystiaalt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/nazrin0.png") class __ASSET__assets_sprites_nazrin0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/nazrinflipped0.png") class __ASSET__assets_sprites_nazrinflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/nitori0.png") class __ASSET__assets_sprites_nitori0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/noroiko0.png") class __ASSET__assets_sprites_noroiko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/nue0.png") class __ASSET__assets_sprites_nue0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/options0.png") class __ASSET__assets_sprites_options0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/orange0.png") class __ASSET__assets_sprites_orange0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/orin0.png") class __ASSET__assets_sprites_orin0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/parsee0.png") class __ASSET__assets_sprites_parsee0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/patchouli0.png") class __ASSET__assets_sprites_patchouli0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/pika0.png") class __ASSET__assets_sprites_pika0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/Point0.png") class __ASSET__assets_sprites_point0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/POW0.png") class __ASSET__assets_sprites_pow0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/POWalt0.png") class __ASSET__assets_sprites_powalt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/prinny0.png") class __ASSET__assets_sprites_prinny0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/raiko0.png") class __ASSET__assets_sprites_raiko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ran0.png") class __ASSET__assets_sprites_ran0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/RedFairy0.png") class __ASSET__assets_sprites_redfairy0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/RedFairyflipped0.png") class __ASSET__assets_sprites_redfairyflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/Redufo0.png") class __ASSET__assets_sprites_redufo0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/reimu0.png") class __ASSET__assets_sprites_reimu0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/reimuALT0.png") class __ASSET__assets_sprites_reimualt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/reimuflipped0.png") class __ASSET__assets_sprites_reimuflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/reisen0.png") class __ASSET__assets_sprites_reisen0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/remilia0.png") class __ASSET__assets_sprites_remilia0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/rengeteki0.png") class __ASSET__assets_sprites_rengeteki0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/renko0.png") class __ASSET__assets_sprites_renko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/rika0.png") class __ASSET__assets_sprites_rika0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/rikako0.png") class __ASSET__assets_sprites_rikako0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/rin0.png") class __ASSET__assets_sprites_rin0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ringo0.png") class __ASSET__assets_sprites_ringo0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/rumia0.png") class __ASSET__assets_sprites_rumia0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/ruukoto0.png") class __ASSET__assets_sprites_ruukoto0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sakuya0.png") class __ASSET__assets_sprites_sakuya0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sakuyaALT0.png") class __ASSET__assets_sprites_sakuyaalt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sanae0.png") class __ASSET__assets_sprites_sanae0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sanaeALT0.png") class __ASSET__assets_sprites_sanaealt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sara0.png") class __ASSET__assets_sprites_sara0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sariel0.png") class __ASSET__assets_sprites_sariel0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/satori0.png") class __ASSET__assets_sprites_satori0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/satoriflipped0.png") class __ASSET__assets_sprites_satoriflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/seiga0.png") class __ASSET__assets_sprites_seiga0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/seija0.png") class __ASSET__assets_sprites_seija0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/seiran0.png") class __ASSET__assets_sprites_seiran0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sekibanki0.png") class __ASSET__assets_sprites_sekibanki0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shanghai0.png") class __ASSET__assets_sprites_shanghai0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shikieiki0.png") class __ASSET__assets_sprites_shikieiki0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shingyoku0.png") class __ASSET__assets_sprites_shingyoku0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shingyokuALT0.png") class __ASSET__assets_sprites_shingyokualt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shinki0.png") class __ASSET__assets_sprites_shinki0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shinmyoumaru0.png") class __ASSET__assets_sprites_shinmyoumaru0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shizuha0.png") class __ASSET__assets_sprites_shizuha0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/shou0.png") class __ASSET__assets_sprites_shou0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/skull0.png") class __ASSET__assets_sprites_skull0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/starbulletg0.png") class __ASSET__assets_sprites_starbulletg0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/starbullety0.png") class __ASSET__assets_sprites_starbullety0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/starsaphire0.png") class __ASSET__assets_sprites_starsaphire0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/suika0.png") class __ASSET__assets_sprites_suika0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sumireko0.png") class __ASSET__assets_sprites_sumireko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/sunnymilk0.png") class __ASSET__assets_sprites_sunnymilk0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/suwako0.png") class __ASSET__assets_sprites_suwako0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table0.png") class __ASSET__assets_sprites_table0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table1.png") class __ASSET__assets_sprites_table1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table10.png") class __ASSET__assets_sprites_table10_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table11.png") class __ASSET__assets_sprites_table11_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table12.png") class __ASSET__assets_sprites_table12_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table13.png") class __ASSET__assets_sprites_table13_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table14.png") class __ASSET__assets_sprites_table14_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table15.png") class __ASSET__assets_sprites_table15_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table2.png") class __ASSET__assets_sprites_table2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table3.png") class __ASSET__assets_sprites_table3_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table4.png") class __ASSET__assets_sprites_table4_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table5.png") class __ASSET__assets_sprites_table5_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table6.png") class __ASSET__assets_sprites_table6_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table7.png") class __ASSET__assets_sprites_table7_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table8.png") class __ASSET__assets_sprites_table8_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/table9.png") class __ASSET__assets_sprites_table9_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/tenshi0.png") class __ASSET__assets_sprites_tenshi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/tewi0.png") class __ASSET__assets_sprites_tewi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/tewiflipped0.png") class __ASSET__assets_sprites_tewiflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/titlescreen0.png") class __ASSET__assets_sprites_titlescreen0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/tojiko0.png") class __ASSET__assets_sprites_tojiko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/tokiko0.png") class __ASSET__assets_sprites_tokiko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/toyohime0.png") class __ASSET__assets_sprites_toyohime0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/trophy0.png") class __ASSET__assets_sprites_trophy0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/truck0.png") class __ASSET__assets_sprites_truck0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/udongein0.png") class __ASSET__assets_sprites_udongein0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/udongeinflipped0.png") class __ASSET__assets_sprites_udongeinflipped0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/unused0.png") class __ASSET__assets_sprites_unused0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/unzanfist0.png") class __ASSET__assets_sprites_unzanfist0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/utsuho0.png") class __ASSET__assets_sprites_utsuho0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/wakasagihime0.png") class __ASSET__assets_sprites_wakasagihime0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/wriggle0.png") class __ASSET__assets_sprites_wriggle0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yamame0.png") class __ASSET__assets_sprites_yamame0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yatsuhashi0.png") class __ASSET__assets_sprites_yatsuhashi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb0.png") class __ASSET__assets_sprites_yinyangorb0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb1.png") class __ASSET__assets_sprites_yinyangorb1_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb10.png") class __ASSET__assets_sprites_yinyangorb10_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb11.png") class __ASSET__assets_sprites_yinyangorb11_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb12.png") class __ASSET__assets_sprites_yinyangorb12_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb13.png") class __ASSET__assets_sprites_yinyangorb13_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb14.png") class __ASSET__assets_sprites_yinyangorb14_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb15.png") class __ASSET__assets_sprites_yinyangorb15_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb2.png") class __ASSET__assets_sprites_yinyangorb2_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb3.png") class __ASSET__assets_sprites_yinyangorb3_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb4.png") class __ASSET__assets_sprites_yinyangorb4_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb5.png") class __ASSET__assets_sprites_yinyangorb5_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb6.png") class __ASSET__assets_sprites_yinyangorb6_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb7.png") class __ASSET__assets_sprites_yinyangorb7_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb8.png") class __ASSET__assets_sprites_yinyangorb8_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yinyangorb9.png") class __ASSET__assets_sprites_yinyangorb9_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yorihime0.png") class __ASSET__assets_sprites_yorihime0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yoshika0.png") class __ASSET__assets_sprites_yoshika0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/youmu0.png") class __ASSET__assets_sprites_youmu0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yukari0.png") class __ASSET__assets_sprites_yukari0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yuki0.png") class __ASSET__assets_sprites_yuki0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yumeko0.png") class __ASSET__assets_sprites_yumeko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yumemi0.png") class __ASSET__assets_sprites_yumemi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yuugi0.png") class __ASSET__assets_sprites_yuugi0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yuuka0.png") class __ASSET__assets_sprites_yuuka0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yuukaALT0.png") class __ASSET__assets_sprites_yuukaalt0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/yuyuko0.png") class __ASSET__assets_sprites_yuyuko0_png extends lime.graphics.Image {}
@:bitmap("Assets/Sprites/zombiefairy0.png") class __ASSET__assets_sprites_zombiefairy0_png extends lime.graphics.Image {}



#end

#end
#end

