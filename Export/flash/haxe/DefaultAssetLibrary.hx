package;


import haxe.Timer;
import haxe.Unserializer;
import lime.app.Preloader;
import lime.audio.AudioSource;
import lime.audio.openal.AL;
import lime.audio.AudioBuffer;
import lime.graphics.Image;
import lime.system.ThreadPool;
import lime.text.Font;
import lime.utils.ByteArray;
import lime.utils.UInt8Array;
import lime.Assets;

#if sys
import sys.FileSystem;
#end

#if (js && html5)
import lime.net.URLLoader;
import lime.net.URLRequest;
#elseif flash
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
	private var threadPool:ThreadPool;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		#if flash
		
		className.set ("assets/Audio/Mp3/bonk.mp3", __ASSET__assets_audio_mp3_bonk_mp3);
		type.set ("assets/Audio/Mp3/bonk.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/characterselect.mp3", __ASSET__assets_audio_mp3_characterselect_mp3);
		type.set ("assets/Audio/Mp3/characterselect.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/collectcoin.mp3", __ASSET__assets_audio_mp3_collectcoin_mp3);
		type.set ("assets/Audio/Mp3/collectcoin.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/died.mp3", __ASSET__assets_audio_mp3_died_mp3);
		type.set ("assets/Audio/Mp3/died.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/drum0.mp3", __ASSET__assets_audio_mp3_drum0_mp3);
		type.set ("assets/Audio/Mp3/drum0.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/drum1.mp3", __ASSET__assets_audio_mp3_drum1_mp3);
		type.set ("assets/Audio/Mp3/drum1.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/drum2.mp3", __ASSET__assets_audio_mp3_drum2_mp3);
		type.set ("assets/Audio/Mp3/drum2.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/drum3.mp3", __ASSET__assets_audio_mp3_drum3_mp3);
		type.set ("assets/Audio/Mp3/drum3.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/drum4.mp3", __ASSET__assets_audio_mp3_drum4_mp3);
		type.set ("assets/Audio/Mp3/drum4.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/extend.mp3", __ASSET__assets_audio_mp3_extend_mp3);
		type.set ("assets/Audio/Mp3/extend.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/finalkill.mp3", __ASSET__assets_audio_mp3_finalkill_mp3);
		type.set ("assets/Audio/Mp3/finalkill.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/fireballspawn.mp3", __ASSET__assets_audio_mp3_fireballspawn_mp3);
		type.set ("assets/Audio/Mp3/fireballspawn.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/gameover.mp3", __ASSET__assets_audio_mp3_gameover_mp3);
		type.set ("assets/Audio/Mp3/gameover.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/killenemy.mp3", __ASSET__assets_audio_mp3_killenemy_mp3);
		type.set ("assets/Audio/Mp3/killenemy.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/masterspark.mp3", __ASSET__assets_audio_mp3_masterspark_mp3);
		type.set ("assets/Audio/Mp3/masterspark.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/nextlevel.mp3", __ASSET__assets_audio_mp3_nextlevel_mp3);
		type.set ("assets/Audio/Mp3/nextlevel.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/pow.mp3", __ASSET__assets_audio_mp3_pow_mp3);
		type.set ("assets/Audio/Mp3/pow.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/respawn.mp3", __ASSET__assets_audio_mp3_respawn_mp3);
		type.set ("assets/Audio/Mp3/respawn.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/se_tan01.mp3", __ASSET__assets_audio_mp3_se_tan01_mp3);
		type.set ("assets/Audio/Mp3/se_tan01.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/spawncoin.mp3", __ASSET__assets_audio_mp3_spawncoin_mp3);
		type.set ("assets/Audio/Mp3/spawncoin.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/startgame.mp3", __ASSET__assets_audio_mp3_startgame_mp3);
		type.set ("assets/Audio/Mp3/startgame.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/step1.mp3", __ASSET__assets_audio_mp3_step1_mp3);
		type.set ("assets/Audio/Mp3/step1.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/step2.mp3", __ASSET__assets_audio_mp3_step2_mp3);
		type.set ("assets/Audio/Mp3/step2.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/step3.mp3", __ASSET__assets_audio_mp3_step3_mp3);
		type.set ("assets/Audio/Mp3/step3.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme1.mp3", __ASSET__assets_audio_mp3_theme1_mp3);
		type.set ("assets/Audio/Mp3/theme1.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme10.mp3", __ASSET__assets_audio_mp3_theme10_mp3);
		type.set ("assets/Audio/Mp3/theme10.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme11.mp3", __ASSET__assets_audio_mp3_theme11_mp3);
		type.set ("assets/Audio/Mp3/theme11.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme12.mp3", __ASSET__assets_audio_mp3_theme12_mp3);
		type.set ("assets/Audio/Mp3/theme12.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme12intro.mp3", __ASSET__assets_audio_mp3_theme12intro_mp3);
		type.set ("assets/Audio/Mp3/theme12intro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme2.mp3", __ASSET__assets_audio_mp3_theme2_mp3);
		type.set ("assets/Audio/Mp3/theme2.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme2intro.mp3", __ASSET__assets_audio_mp3_theme2intro_mp3);
		type.set ("assets/Audio/Mp3/theme2intro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme3.mp3", __ASSET__assets_audio_mp3_theme3_mp3);
		type.set ("assets/Audio/Mp3/theme3.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme3intro.mp3", __ASSET__assets_audio_mp3_theme3intro_mp3);
		type.set ("assets/Audio/Mp3/theme3intro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme4.mp3", __ASSET__assets_audio_mp3_theme4_mp3);
		type.set ("assets/Audio/Mp3/theme4.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme5.mp3", __ASSET__assets_audio_mp3_theme5_mp3);
		type.set ("assets/Audio/Mp3/theme5.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme6.mp3", __ASSET__assets_audio_mp3_theme6_mp3);
		type.set ("assets/Audio/Mp3/theme6.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme7.mp3", __ASSET__assets_audio_mp3_theme7_mp3);
		type.set ("assets/Audio/Mp3/theme7.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme8.mp3", __ASSET__assets_audio_mp3_theme8_mp3);
		type.set ("assets/Audio/Mp3/theme8.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme8intro.mp3", __ASSET__assets_audio_mp3_theme8intro_mp3);
		type.set ("assets/Audio/Mp3/theme8intro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/theme9.mp3", __ASSET__assets_audio_mp3_theme9_mp3);
		type.set ("assets/Audio/Mp3/theme9.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/titlescreen.mp3", __ASSET__assets_audio_mp3_titlescreen_mp3);
		type.set ("assets/Audio/Mp3/titlescreen.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/zawarudo.mp3", __ASSET__assets_audio_mp3_zawarudo_mp3);
		type.set ("assets/Audio/Mp3/zawarudo.mp3", AssetType.MUSIC);
		className.set ("assets/bgcolor.png", __ASSET__assets_bgcolor_png);
		type.set ("assets/bgcolor.png", AssetType.IMAGE);
		className.set ("assets/black.png", __ASSET__assets_black_png);
		type.set ("assets/black.png", AssetType.IMAGE);
		className.set ("assets/Dpad.png", __ASSET__assets_dpad_png);
		type.set ("assets/Dpad.png", AssetType.IMAGE);
		className.set ("assets/Key.txt", __ASSET__assets_key_txt);
		type.set ("assets/Key.txt", AssetType.TEXT);
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
		className.set ("assets/Sprites/bat0.png", __ASSET__assets_sprites_bat0_png);
		type.set ("assets/Sprites/bat0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bat1.png", __ASSET__assets_sprites_bat1_png);
		type.set ("assets/Sprites/bat1.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/blackhole0.png", __ASSET__assets_sprites_blackhole0_png);
		type.set ("assets/Sprites/blackhole0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/cirnoflipped0.png", __ASSET__assets_sprites_cirnoflipped0_png);
		type.set ("assets/Sprites/cirnoflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/cloud0.png", __ASSET__assets_sprites_cloud0_png);
		type.set ("assets/Sprites/cloud0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/clownpiece0.png", __ASSET__assets_sprites_clownpiece0_png);
		type.set ("assets/Sprites/clownpiece0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/CSBack0.png", __ASSET__assets_sprites_csback0_png);
		type.set ("assets/Sprites/CSBack0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/CSBG0.png", __ASSET__assets_sprites_csbg0_png);
		type.set ("assets/Sprites/CSBG0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/CSFront0.png", __ASSET__assets_sprites_csfront0_png);
		type.set ("assets/Sprites/CSFront0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/daiyousei0.png", __ASSET__assets_sprites_daiyousei0_png);
		type.set ("assets/Sprites/daiyousei0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/darkness0.png", __ASSET__assets_sprites_darkness0_png);
		type.set ("assets/Sprites/darkness0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/diosakuya0.png", __ASSET__assets_sprites_diosakuya0_png);
		type.set ("assets/Sprites/diosakuya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/diosakuyaALT0.png", __ASSET__assets_sprites_diosakuyaalt0_png);
		type.set ("assets/Sprites/diosakuyaALT0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/EHkaguya0.png", __ASSET__assets_sprites_ehkaguya0_png);
		type.set ("assets/Sprites/EHkaguya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EHmokou0.png", __ASSET__assets_sprites_ehmokou0_png);
		type.set ("assets/Sprites/EHmokou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/eirin0.png", __ASSET__assets_sprites_eirin0_png);
		type.set ("assets/Sprites/eirin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Ekaguya0.png", __ASSET__assets_sprites_ekaguya0_png);
		type.set ("assets/Sprites/Ekaguya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Ekaguyaflipped0.png", __ASSET__assets_sprites_ekaguyaflipped0_png);
		type.set ("assets/Sprites/Ekaguyaflipped0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/Emokou0.png", __ASSET__assets_sprites_emokou0_png);
		type.set ("assets/Sprites/Emokou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Emokouflipped0.png", __ASSET__assets_sprites_emokouflipped0_png);
		type.set ("assets/Sprites/Emokouflipped0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/explosion0.png", __ASSET__assets_sprites_explosion0_png);
		type.set ("assets/Sprites/explosion0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/flandreflipped0.png", __ASSET__assets_sprites_flandreflipped0_png);
		type.set ("assets/Sprites/flandreflipped0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/happytenshi0.png", __ASSET__assets_sprites_happytenshi0_png);
		type.set ("assets/Sprites/happytenshi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hatate0.png", __ASSET__assets_sprites_hatate0_png);
		type.set ("assets/Sprites/hatate0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/heartbullet0.png", __ASSET__assets_sprites_heartbullet0_png);
		type.set ("assets/Sprites/heartbullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hecatia0.png", __ASSET__assets_sprites_hecatia0_png);
		type.set ("assets/Sprites/hecatia0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hina0.png", __ASSET__assets_sprites_hina0_png);
		type.set ("assets/Sprites/hina0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/icebullet0.png", __ASSET__assets_sprites_icebullet0_png);
		type.set ("assets/Sprites/icebullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/icecube0.png", __ASSET__assets_sprites_icecube0_png);
		type.set ("assets/Sprites/icecube0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ichirin0.png", __ASSET__assets_sprites_ichirin0_png);
		type.set ("assets/Sprites/ichirin0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/icyblock0.png", __ASSET__assets_sprites_icyblock0_png);
		type.set ("assets/Sprites/icyblock0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/iku0.png", __ASSET__assets_sprites_iku0_png);
		type.set ("assets/Sprites/iku0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ikuikudance0.png", __ASSET__assets_sprites_ikuikudance0_png);
		type.set ("assets/Sprites/ikuikudance0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/junko0.png", __ASSET__assets_sprites_junko0_png);
		type.set ("assets/Sprites/junko0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/keystone0.png", __ASSET__assets_sprites_keystone0_png);
		type.set ("assets/Sprites/keystone0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/lilith0.png", __ASSET__assets_sprites_lilith0_png);
		type.set ("assets/Sprites/lilith0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/meilingflipped0.png", __ASSET__assets_sprites_meilingflipped0_png);
		type.set ("assets/Sprites/meilingflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/meilingsleeping0.png", __ASSET__assets_sprites_meilingsleeping0_png);
		type.set ("assets/Sprites/meilingsleeping0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/meilingsleepingflipped0.png", __ASSET__assets_sprites_meilingsleepingflipped0_png);
		type.set ("assets/Sprites/meilingsleepingflipped0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/okuu0.png", __ASSET__assets_sprites_okuu0_png);
		type.set ("assets/Sprites/okuu0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/okuuflipped0.png", __ASSET__assets_sprites_okuuflipped0_png);
		type.set ("assets/Sprites/okuuflipped0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/poisoncloud0.png", __ASSET__assets_sprites_poisoncloud0_png);
		type.set ("assets/Sprites/poisoncloud0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/redeyedudongein0.png", __ASSET__assets_sprites_redeyedudongein0_png);
		type.set ("assets/Sprites/redeyedudongein0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/remiliaflipped0.png", __ASSET__assets_sprites_remiliaflipped0_png);
		type.set ("assets/Sprites/remiliaflipped0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/sagume0.png", __ASSET__assets_sprites_sagume0_png);
		type.set ("assets/Sprites/sagume0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/scythe0.png", __ASSET__assets_sprites_scythe0_png);
		type.set ("assets/Sprites/scythe0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe1.png", __ASSET__assets_sprites_scythe1_png);
		type.set ("assets/Sprites/scythe1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe10.png", __ASSET__assets_sprites_scythe10_png);
		type.set ("assets/Sprites/scythe10.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe11.png", __ASSET__assets_sprites_scythe11_png);
		type.set ("assets/Sprites/scythe11.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe12.png", __ASSET__assets_sprites_scythe12_png);
		type.set ("assets/Sprites/scythe12.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe13.png", __ASSET__assets_sprites_scythe13_png);
		type.set ("assets/Sprites/scythe13.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe14.png", __ASSET__assets_sprites_scythe14_png);
		type.set ("assets/Sprites/scythe14.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe15.png", __ASSET__assets_sprites_scythe15_png);
		type.set ("assets/Sprites/scythe15.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe2.png", __ASSET__assets_sprites_scythe2_png);
		type.set ("assets/Sprites/scythe2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe3.png", __ASSET__assets_sprites_scythe3_png);
		type.set ("assets/Sprites/scythe3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe4.png", __ASSET__assets_sprites_scythe4_png);
		type.set ("assets/Sprites/scythe4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe5.png", __ASSET__assets_sprites_scythe5_png);
		type.set ("assets/Sprites/scythe5.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe6.png", __ASSET__assets_sprites_scythe6_png);
		type.set ("assets/Sprites/scythe6.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe7.png", __ASSET__assets_sprites_scythe7_png);
		type.set ("assets/Sprites/scythe7.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe8.png", __ASSET__assets_sprites_scythe8_png);
		type.set ("assets/Sprites/scythe8.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe9.png", __ASSET__assets_sprites_scythe9_png);
		type.set ("assets/Sprites/scythe9.png", AssetType.IMAGE);
		className.set ("assets/Sprites/seiga0.png", __ASSET__assets_sprites_seiga0_png);
		type.set ("assets/Sprites/seiga0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/seija0.png", __ASSET__assets_sprites_seija0_png);
		type.set ("assets/Sprites/seija0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/seiran0.png", __ASSET__assets_sprites_seiran0_png);
		type.set ("assets/Sprites/seiran0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sekibanki0.png", __ASSET__assets_sprites_sekibanki0_png);
		type.set ("assets/Sprites/sekibanki0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sekibankihead0.png", __ASSET__assets_sprites_sekibankihead0_png);
		type.set ("assets/Sprites/sekibankihead0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sekibankiheadless0.png", __ASSET__assets_sprites_sekibankiheadless0_png);
		type.set ("assets/Sprites/sekibankiheadless0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/suwakohoop0.png", __ASSET__assets_sprites_suwakohoop0_png);
		type.set ("assets/Sprites/suwakohoop0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/tenshiflipped0.png", __ASSET__assets_sprites_tenshiflipped0_png);
		type.set ("assets/Sprites/tenshiflipped0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/train0.png", __ASSET__assets_sprites_train0_png);
		type.set ("assets/Sprites/train0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/utsuhobullet0.png", __ASSET__assets_sprites_utsuhobullet0_png);
		type.set ("assets/Sprites/utsuhobullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/wakasagihime0.png", __ASSET__assets_sprites_wakasagihime0_png);
		type.set ("assets/Sprites/wakasagihime0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/warning0.png", __ASSET__assets_sprites_warning0_png);
		type.set ("assets/Sprites/warning0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/yukaribullet0.png", __ASSET__assets_sprites_yukaribullet0_png);
		type.set ("assets/Sprites/yukaribullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yukariflipped0.png", __ASSET__assets_sprites_yukariflipped0_png);
		type.set ("assets/Sprites/yukariflipped0.png", AssetType.IMAGE);
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
		id = "assets/Audio/Mp3/bonk.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/characterselect.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/collectcoin.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/died.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/drum0.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/drum1.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/drum2.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/drum3.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/drum4.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/extend.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/finalkill.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/fireballspawn.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/gameover.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/killenemy.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/masterspark.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/nextlevel.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/pow.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/respawn.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/se_tan01.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/spawncoin.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/startgame.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/step1.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/step2.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/step3.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme1.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme10.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme11.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme12.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme12intro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme2.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme2intro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme3.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme3intro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme4.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme5.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme6.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme7.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme8.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme8intro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/theme9.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/titlescreen.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/zawarudo.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/bgcolor.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/black.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Dpad.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Key.txt";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
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
		id = "assets/Sprites/bat0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bat1.png";
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
		id = "assets/Sprites/blackhole0.png";
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
		id = "assets/Sprites/cirnoflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/cloud0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/clownpiece0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/CSBack0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/CSBG0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/CSFront0.png";
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
		id = "assets/Sprites/diosakuyaALT0.png";
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
		id = "assets/Sprites/EHkaguya0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/EHmokou0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/eirin0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Ekaguya0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Ekaguyaflipped0.png";
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
		id = "assets/Sprites/Emokou0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Emokouflipped0.png";
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
		id = "assets/Sprites/explosion0.png";
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
		id = "assets/Sprites/flandreflipped0.png";
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
		id = "assets/Sprites/happytenshi0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hatate0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/heartbullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hecatia0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hina0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/icebullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/icecube0.png";
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
		id = "assets/Sprites/junko0.png";
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
		id = "assets/Sprites/keystone0.png";
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
		id = "assets/Sprites/lilith0.png";
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
		id = "assets/Sprites/meilingflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/meilingsleeping0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/meilingsleepingflipped0.png";
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
		id = "assets/Sprites/okuu0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/okuuflipped0.png";
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
		id = "assets/Sprites/poisoncloud0.png";
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
		id = "assets/Sprites/redeyedudongein0.png";
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
		id = "assets/Sprites/remiliaflipped0.png";
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
		id = "assets/Sprites/sagume0.png";
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
		id = "assets/Sprites/scythe0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe10.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe11.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe12.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe13.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe14.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe15.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe2.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe3.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe4.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe5.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe6.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe7.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe8.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe9.png";
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
		id = "assets/Sprites/sekibankihead0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sekibankiheadless0.png";
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
		id = "assets/Sprites/suwakohoop0.png";
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
		id = "assets/Sprites/tenshiflipped0.png";
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
		id = "assets/Sprites/train0.png";
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
		id = "assets/Sprites/utsuhobullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/wakasagihime0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/warning0.png";
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
		id = "assets/Sprites/yukaribullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yukariflipped0.png";
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
		
		className.set ("assets/Audio/Mp3/bonk.mp3", __ASSET__assets_audio_mp3_bonk_mp3);
		type.set ("assets/Audio/Mp3/bonk.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/characterselect.mp3", __ASSET__assets_audio_mp3_characterselect_mp3);
		type.set ("assets/Audio/Mp3/characterselect.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/collectcoin.mp3", __ASSET__assets_audio_mp3_collectcoin_mp3);
		type.set ("assets/Audio/Mp3/collectcoin.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/died.mp3", __ASSET__assets_audio_mp3_died_mp3);
		type.set ("assets/Audio/Mp3/died.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/drum0.mp3", __ASSET__assets_audio_mp3_drum0_mp3);
		type.set ("assets/Audio/Mp3/drum0.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/drum1.mp3", __ASSET__assets_audio_mp3_drum1_mp3);
		type.set ("assets/Audio/Mp3/drum1.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/drum2.mp3", __ASSET__assets_audio_mp3_drum2_mp3);
		type.set ("assets/Audio/Mp3/drum2.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/drum3.mp3", __ASSET__assets_audio_mp3_drum3_mp3);
		type.set ("assets/Audio/Mp3/drum3.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/drum4.mp3", __ASSET__assets_audio_mp3_drum4_mp3);
		type.set ("assets/Audio/Mp3/drum4.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/extend.mp3", __ASSET__assets_audio_mp3_extend_mp3);
		type.set ("assets/Audio/Mp3/extend.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/finalkill.mp3", __ASSET__assets_audio_mp3_finalkill_mp3);
		type.set ("assets/Audio/Mp3/finalkill.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/fireballspawn.mp3", __ASSET__assets_audio_mp3_fireballspawn_mp3);
		type.set ("assets/Audio/Mp3/fireballspawn.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/gameover.mp3", __ASSET__assets_audio_mp3_gameover_mp3);
		type.set ("assets/Audio/Mp3/gameover.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/killenemy.mp3", __ASSET__assets_audio_mp3_killenemy_mp3);
		type.set ("assets/Audio/Mp3/killenemy.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/masterspark.mp3", __ASSET__assets_audio_mp3_masterspark_mp3);
		type.set ("assets/Audio/Mp3/masterspark.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/nextlevel.mp3", __ASSET__assets_audio_mp3_nextlevel_mp3);
		type.set ("assets/Audio/Mp3/nextlevel.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/pow.mp3", __ASSET__assets_audio_mp3_pow_mp3);
		type.set ("assets/Audio/Mp3/pow.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/respawn.mp3", __ASSET__assets_audio_mp3_respawn_mp3);
		type.set ("assets/Audio/Mp3/respawn.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/se_tan01.mp3", __ASSET__assets_audio_mp3_se_tan01_mp3);
		type.set ("assets/Audio/Mp3/se_tan01.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/spawncoin.mp3", __ASSET__assets_audio_mp3_spawncoin_mp3);
		type.set ("assets/Audio/Mp3/spawncoin.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/startgame.mp3", __ASSET__assets_audio_mp3_startgame_mp3);
		type.set ("assets/Audio/Mp3/startgame.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/step1.mp3", __ASSET__assets_audio_mp3_step1_mp3);
		type.set ("assets/Audio/Mp3/step1.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/step2.mp3", __ASSET__assets_audio_mp3_step2_mp3);
		type.set ("assets/Audio/Mp3/step2.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/step3.mp3", __ASSET__assets_audio_mp3_step3_mp3);
		type.set ("assets/Audio/Mp3/step3.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme1.mp3", __ASSET__assets_audio_mp3_theme1_mp3);
		type.set ("assets/Audio/Mp3/theme1.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme10.mp3", __ASSET__assets_audio_mp3_theme10_mp3);
		type.set ("assets/Audio/Mp3/theme10.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme11.mp3", __ASSET__assets_audio_mp3_theme11_mp3);
		type.set ("assets/Audio/Mp3/theme11.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme12.mp3", __ASSET__assets_audio_mp3_theme12_mp3);
		type.set ("assets/Audio/Mp3/theme12.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme12intro.mp3", __ASSET__assets_audio_mp3_theme12intro_mp3);
		type.set ("assets/Audio/Mp3/theme12intro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme2.mp3", __ASSET__assets_audio_mp3_theme2_mp3);
		type.set ("assets/Audio/Mp3/theme2.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme2intro.mp3", __ASSET__assets_audio_mp3_theme2intro_mp3);
		type.set ("assets/Audio/Mp3/theme2intro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme3.mp3", __ASSET__assets_audio_mp3_theme3_mp3);
		type.set ("assets/Audio/Mp3/theme3.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme3intro.mp3", __ASSET__assets_audio_mp3_theme3intro_mp3);
		type.set ("assets/Audio/Mp3/theme3intro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme4.mp3", __ASSET__assets_audio_mp3_theme4_mp3);
		type.set ("assets/Audio/Mp3/theme4.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme5.mp3", __ASSET__assets_audio_mp3_theme5_mp3);
		type.set ("assets/Audio/Mp3/theme5.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme6.mp3", __ASSET__assets_audio_mp3_theme6_mp3);
		type.set ("assets/Audio/Mp3/theme6.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme7.mp3", __ASSET__assets_audio_mp3_theme7_mp3);
		type.set ("assets/Audio/Mp3/theme7.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme8.mp3", __ASSET__assets_audio_mp3_theme8_mp3);
		type.set ("assets/Audio/Mp3/theme8.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme8intro.mp3", __ASSET__assets_audio_mp3_theme8intro_mp3);
		type.set ("assets/Audio/Mp3/theme8intro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/theme9.mp3", __ASSET__assets_audio_mp3_theme9_mp3);
		type.set ("assets/Audio/Mp3/theme9.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/titlescreen.mp3", __ASSET__assets_audio_mp3_titlescreen_mp3);
		type.set ("assets/Audio/Mp3/titlescreen.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/zawarudo.mp3", __ASSET__assets_audio_mp3_zawarudo_mp3);
		type.set ("assets/Audio/Mp3/zawarudo.mp3", AssetType.MUSIC);
		
		className.set ("assets/bgcolor.png", __ASSET__assets_bgcolor_png);
		type.set ("assets/bgcolor.png", AssetType.IMAGE);
		
		className.set ("assets/black.png", __ASSET__assets_black_png);
		type.set ("assets/black.png", AssetType.IMAGE);
		
		className.set ("assets/Dpad.png", __ASSET__assets_dpad_png);
		type.set ("assets/Dpad.png", AssetType.IMAGE);
		
		className.set ("assets/Key.txt", __ASSET__assets_key_txt);
		type.set ("assets/Key.txt", AssetType.TEXT);
		
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
		
		className.set ("assets/Sprites/bat0.png", __ASSET__assets_sprites_bat0_png);
		type.set ("assets/Sprites/bat0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bat1.png", __ASSET__assets_sprites_bat1_png);
		type.set ("assets/Sprites/bat1.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/blackhole0.png", __ASSET__assets_sprites_blackhole0_png);
		type.set ("assets/Sprites/blackhole0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/cirnoflipped0.png", __ASSET__assets_sprites_cirnoflipped0_png);
		type.set ("assets/Sprites/cirnoflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/cloud0.png", __ASSET__assets_sprites_cloud0_png);
		type.set ("assets/Sprites/cloud0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/clownpiece0.png", __ASSET__assets_sprites_clownpiece0_png);
		type.set ("assets/Sprites/clownpiece0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/CSBack0.png", __ASSET__assets_sprites_csback0_png);
		type.set ("assets/Sprites/CSBack0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/CSBG0.png", __ASSET__assets_sprites_csbg0_png);
		type.set ("assets/Sprites/CSBG0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/CSFront0.png", __ASSET__assets_sprites_csfront0_png);
		type.set ("assets/Sprites/CSFront0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/daiyousei0.png", __ASSET__assets_sprites_daiyousei0_png);
		type.set ("assets/Sprites/daiyousei0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/darkness0.png", __ASSET__assets_sprites_darkness0_png);
		type.set ("assets/Sprites/darkness0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/diosakuya0.png", __ASSET__assets_sprites_diosakuya0_png);
		type.set ("assets/Sprites/diosakuya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/diosakuyaALT0.png", __ASSET__assets_sprites_diosakuyaalt0_png);
		type.set ("assets/Sprites/diosakuyaALT0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/EHkaguya0.png", __ASSET__assets_sprites_ehkaguya0_png);
		type.set ("assets/Sprites/EHkaguya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EHmokou0.png", __ASSET__assets_sprites_ehmokou0_png);
		type.set ("assets/Sprites/EHmokou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/eirin0.png", __ASSET__assets_sprites_eirin0_png);
		type.set ("assets/Sprites/eirin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Ekaguya0.png", __ASSET__assets_sprites_ekaguya0_png);
		type.set ("assets/Sprites/Ekaguya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Ekaguyaflipped0.png", __ASSET__assets_sprites_ekaguyaflipped0_png);
		type.set ("assets/Sprites/Ekaguyaflipped0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/Emokou0.png", __ASSET__assets_sprites_emokou0_png);
		type.set ("assets/Sprites/Emokou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Emokouflipped0.png", __ASSET__assets_sprites_emokouflipped0_png);
		type.set ("assets/Sprites/Emokouflipped0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/explosion0.png", __ASSET__assets_sprites_explosion0_png);
		type.set ("assets/Sprites/explosion0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/flandreflipped0.png", __ASSET__assets_sprites_flandreflipped0_png);
		type.set ("assets/Sprites/flandreflipped0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/happytenshi0.png", __ASSET__assets_sprites_happytenshi0_png);
		type.set ("assets/Sprites/happytenshi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hatate0.png", __ASSET__assets_sprites_hatate0_png);
		type.set ("assets/Sprites/hatate0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/heartbullet0.png", __ASSET__assets_sprites_heartbullet0_png);
		type.set ("assets/Sprites/heartbullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hecatia0.png", __ASSET__assets_sprites_hecatia0_png);
		type.set ("assets/Sprites/hecatia0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hina0.png", __ASSET__assets_sprites_hina0_png);
		type.set ("assets/Sprites/hina0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/icebullet0.png", __ASSET__assets_sprites_icebullet0_png);
		type.set ("assets/Sprites/icebullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/icecube0.png", __ASSET__assets_sprites_icecube0_png);
		type.set ("assets/Sprites/icecube0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ichirin0.png", __ASSET__assets_sprites_ichirin0_png);
		type.set ("assets/Sprites/ichirin0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/icyblock0.png", __ASSET__assets_sprites_icyblock0_png);
		type.set ("assets/Sprites/icyblock0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/iku0.png", __ASSET__assets_sprites_iku0_png);
		type.set ("assets/Sprites/iku0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ikuikudance0.png", __ASSET__assets_sprites_ikuikudance0_png);
		type.set ("assets/Sprites/ikuikudance0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/junko0.png", __ASSET__assets_sprites_junko0_png);
		type.set ("assets/Sprites/junko0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/keystone0.png", __ASSET__assets_sprites_keystone0_png);
		type.set ("assets/Sprites/keystone0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/lilith0.png", __ASSET__assets_sprites_lilith0_png);
		type.set ("assets/Sprites/lilith0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/meilingflipped0.png", __ASSET__assets_sprites_meilingflipped0_png);
		type.set ("assets/Sprites/meilingflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/meilingsleeping0.png", __ASSET__assets_sprites_meilingsleeping0_png);
		type.set ("assets/Sprites/meilingsleeping0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/meilingsleepingflipped0.png", __ASSET__assets_sprites_meilingsleepingflipped0_png);
		type.set ("assets/Sprites/meilingsleepingflipped0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/okuu0.png", __ASSET__assets_sprites_okuu0_png);
		type.set ("assets/Sprites/okuu0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/okuuflipped0.png", __ASSET__assets_sprites_okuuflipped0_png);
		type.set ("assets/Sprites/okuuflipped0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/poisoncloud0.png", __ASSET__assets_sprites_poisoncloud0_png);
		type.set ("assets/Sprites/poisoncloud0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/redeyedudongein0.png", __ASSET__assets_sprites_redeyedudongein0_png);
		type.set ("assets/Sprites/redeyedudongein0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/remiliaflipped0.png", __ASSET__assets_sprites_remiliaflipped0_png);
		type.set ("assets/Sprites/remiliaflipped0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/sagume0.png", __ASSET__assets_sprites_sagume0_png);
		type.set ("assets/Sprites/sagume0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/scythe0.png", __ASSET__assets_sprites_scythe0_png);
		type.set ("assets/Sprites/scythe0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe1.png", __ASSET__assets_sprites_scythe1_png);
		type.set ("assets/Sprites/scythe1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe10.png", __ASSET__assets_sprites_scythe10_png);
		type.set ("assets/Sprites/scythe10.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe11.png", __ASSET__assets_sprites_scythe11_png);
		type.set ("assets/Sprites/scythe11.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe12.png", __ASSET__assets_sprites_scythe12_png);
		type.set ("assets/Sprites/scythe12.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe13.png", __ASSET__assets_sprites_scythe13_png);
		type.set ("assets/Sprites/scythe13.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe14.png", __ASSET__assets_sprites_scythe14_png);
		type.set ("assets/Sprites/scythe14.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe15.png", __ASSET__assets_sprites_scythe15_png);
		type.set ("assets/Sprites/scythe15.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe2.png", __ASSET__assets_sprites_scythe2_png);
		type.set ("assets/Sprites/scythe2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe3.png", __ASSET__assets_sprites_scythe3_png);
		type.set ("assets/Sprites/scythe3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe4.png", __ASSET__assets_sprites_scythe4_png);
		type.set ("assets/Sprites/scythe4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe5.png", __ASSET__assets_sprites_scythe5_png);
		type.set ("assets/Sprites/scythe5.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe6.png", __ASSET__assets_sprites_scythe6_png);
		type.set ("assets/Sprites/scythe6.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe7.png", __ASSET__assets_sprites_scythe7_png);
		type.set ("assets/Sprites/scythe7.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe8.png", __ASSET__assets_sprites_scythe8_png);
		type.set ("assets/Sprites/scythe8.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe9.png", __ASSET__assets_sprites_scythe9_png);
		type.set ("assets/Sprites/scythe9.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/seiga0.png", __ASSET__assets_sprites_seiga0_png);
		type.set ("assets/Sprites/seiga0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/seija0.png", __ASSET__assets_sprites_seija0_png);
		type.set ("assets/Sprites/seija0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/seiran0.png", __ASSET__assets_sprites_seiran0_png);
		type.set ("assets/Sprites/seiran0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sekibanki0.png", __ASSET__assets_sprites_sekibanki0_png);
		type.set ("assets/Sprites/sekibanki0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sekibankihead0.png", __ASSET__assets_sprites_sekibankihead0_png);
		type.set ("assets/Sprites/sekibankihead0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sekibankiheadless0.png", __ASSET__assets_sprites_sekibankiheadless0_png);
		type.set ("assets/Sprites/sekibankiheadless0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/suwakohoop0.png", __ASSET__assets_sprites_suwakohoop0_png);
		type.set ("assets/Sprites/suwakohoop0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/tenshiflipped0.png", __ASSET__assets_sprites_tenshiflipped0_png);
		type.set ("assets/Sprites/tenshiflipped0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/train0.png", __ASSET__assets_sprites_train0_png);
		type.set ("assets/Sprites/train0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/utsuhobullet0.png", __ASSET__assets_sprites_utsuhobullet0_png);
		type.set ("assets/Sprites/utsuhobullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/wakasagihime0.png", __ASSET__assets_sprites_wakasagihime0_png);
		type.set ("assets/Sprites/wakasagihime0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/warning0.png", __ASSET__assets_sprites_warning0_png);
		type.set ("assets/Sprites/warning0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/yukaribullet0.png", __ASSET__assets_sprites_yukaribullet0_png);
		type.set ("assets/Sprites/yukaribullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yukariflipped0.png", __ASSET__assets_sprites_yukariflipped0_png);
		type.set ("assets/Sprites/yukariflipped0.png", AssetType.IMAGE);
		
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
	
	
	private function createThreadPool ():Void {
		
		threadPool = new ThreadPool (0, 2);
		threadPool.doWork.add (function (id, data) {
			
			data.result = data.getMethod (id);
			threadPool.sendComplete (data.handler, data);
			
		});
		threadPool.onComplete.add (function (id, data) {
			
			data.handler (data.result);
			
		});
		
	}
	
	
	public override function exists (id:String, type:String):Bool {
		
		var requestedType = type != null ? cast (type, AssetType) : null;
		var assetType = this.type.get (id);
		
		if (assetType != null) {
			
			if (assetType == requestedType || ((requestedType == SOUND || requestedType == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if (requestedType == BINARY && (assetType == BINARY || assetType == TEXT || assetType == IMAGE)) {
				
				return true;
				
			} else if (requestedType == null || path.exists (id)) {
				
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
		
		if (className.exists(id)) return AudioBuffer.fromBytes (cast (Type.createInstance (className.get (id), []), ByteArray));
		else return AudioBuffer.fromFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if flash
		
		switch (type.get (id)) {
			
			case TEXT, BINARY:
				
				return cast (Type.createInstance (className.get (id), []), ByteArray);
			
			case IMAGE:
				
				var bitmapData = cast (Type.createInstance (className.get (id), []), BitmapData);
				return bitmapData.getPixels (bitmapData.rect);
			
			default:
				
				return null;
			
		}
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);
		
		#elseif html5
		
		var bytes:ByteArray = null;
		var loader = Preloader.loaders.get (path.get (id));
		
		if (loader == null) {
			
			return null;
			
		}
		
		var data = loader.data;
		
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
		
		#if flash
		
		var src = Type.createInstance (className.get (id), []);
		
		var font = new Font (src.fontName);
		font.src = src;
		return font;
		
		#elseif html5
		
		return cast (Type.createInstance (className.get (id), []), Font);
		
		#else
		
		if (className.exists (id)) {
			
			var fontClass = className.get (id);
			return cast (Type.createInstance (fontClass, []), Font);
			
		} else {
			
			return Font.fromFile (path.get (id));
			
		}
		
		#end
		
	}
	
	
	public override function getImage (id:String):Image {
		
		#if flash
		
		return Image.fromBitmapData (cast (Type.createInstance (className.get (id), []), BitmapData));
		
		#elseif html5
		
		return Image.fromImageElement (Preloader.images.get (path.get (id)));
		
		#else
		
		if (className.exists (id)) {
			
			var fontClass = className.get (id);
			return cast (Type.createInstance (fontClass, []), Image);
			
		} else {
			
			return Image.fromFile (path.get (id));
			
		}
		
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
		var loader = Preloader.loaders.get (path.get (id));
		
		if (loader == null) {
			
			return null;
			
		}
		
		var data = loader.data;
		
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
		
		//if (requestedType != AssetType.MUSIC && requestedType != AssetType.SOUND) {
			
			return className.exists (id);
			
		//}
		
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
		
		#elseif html5
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.dataFormat = BINARY;
			loader.onComplete.add (function (_):Void {
				
				handler (loader.data);
				
			});
			
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#else
		
		if (threadPool == null) {
			
			createThreadPool ();
			
		}
		
		threadPool.queue (id, { handler: handler, getMethod: getBytes });
		
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
		
		#elseif html5
		
		if (path.exists (id)) {
			
			var image = new js.html.Image ();
			image.onload = function (_):Void {
				
				handler (Image.fromImageElement (image));
				
			}
			image.src = path.get (id);
			
		} else {
			
			handler (getImage (id));
			
		}
		
		#else
		
		if (threadPool == null) {
			
			createThreadPool ();
			
		}
		
		threadPool.queue (id, { handler: handler, getMethod: getImage });
		
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
			#elseif ios
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
								
								#if ios
								path.set (asset.id, "assets/" + asset.path);
								#else
								path.set (asset.id, asset.path);
								#end
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
		
		#if (flash || html5)
		
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
		
		#if html5
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.onComplete.add (function (_):Void {
				
				handler (loader.data);
				
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


#if !display
#if flash

@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_bonk_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_characterselect_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_collectcoin_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_died_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum0_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum1_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum2_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum3_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum4_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_extend_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_finalkill_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_fireballspawn_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_gameover_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_killenemy_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_masterspark_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_nextlevel_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_pow_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_respawn_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_se_tan01_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_spawncoin_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_startgame_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_step1_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_step2_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_step3_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme1_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme10_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme11_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme12_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme12intro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme2_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme2intro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme3_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme3intro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme4_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme5_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme6_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme7_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme8_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme8intro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_theme9_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_titlescreen_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_zawarudo_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_bgcolor_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_black_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_dpad_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_key_txt extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_1up0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_akyu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_alice0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_alicealt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_aya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ayana0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_balloon0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_barrier0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bat0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bat1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_benben0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bg5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_black0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_blackhole0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_cirnoflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_cloud0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_clownpiece0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_csback0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_csbg0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_csfront0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_daiyousei0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_darkness0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_diosakuya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_diosakuyaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ehkaguya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ehmokou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_eirin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekaguya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekaguyaflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeineex0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeineexflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_electriccirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_elis0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ellen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_elly0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emokou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emokouflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_explosion0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_firecirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flandre0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flandreflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_happytenshi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hatate0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_heartbullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hecatia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hina0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_icebullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_icecube0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ichirin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_icyblock0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_iku0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ikuikudance0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_junko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kagerou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kaguya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kana0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kanako0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_kasen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_keine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_keystone0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lilith0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lily0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_louise0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lunachild0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lunasa0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lyrica0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mai0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_makairesident_a0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mamizou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_maribel0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_marisa0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_marisaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_matenshi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_medicine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meiling0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meilingalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meilingflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meilingsleeping0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meilingsleepingflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_okuu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_okuuflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_options0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_orange0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_orin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_parsee0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_patchouli0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_point0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_poisoncloud0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pow0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_powalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_prinny0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_raiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ran0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redeyedudongein0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redfairy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redfairyflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reimu0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reimualt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reimuflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_reisen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_remilia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_remiliaflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rengeteki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_renko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rikako0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rin0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ringo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rumia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ruukoto0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sagume0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sakuya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sakuyaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sanae0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sanaealt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sara0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sariel0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_satori0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_satoriflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe10_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe11_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe12_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe13_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe14_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe15_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe8_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe9_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_seiga0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_seija0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_seiran0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sekibanki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sekibankihead0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sekibankiheadless0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_suwakohoop0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tenshiflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tewi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tewiflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_titlescreen0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tojiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_tokiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_toyohime0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_train0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_trophy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_truck0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_udongein0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_udongeinflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_unused0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_unzanfist0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_utsuho0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_utsuhobullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_wakasagihime0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_warning0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yukaribullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yukariflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuki0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yumeko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yumemi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuugi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuuka0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuukaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuyuko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_zombiefairy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }


#elseif html5















































































































































































































































































































































































































#else



#if (windows || mac || linux)


@:file("Assets/Audio/Mp3/bonk.mp3") #if display private #end class __ASSET__assets_audio_mp3_bonk_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/characterselect.mp3") #if display private #end class __ASSET__assets_audio_mp3_characterselect_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/collectcoin.mp3") #if display private #end class __ASSET__assets_audio_mp3_collectcoin_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/died.mp3") #if display private #end class __ASSET__assets_audio_mp3_died_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum0.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum0_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum1.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum1_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum2.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum2_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum3.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum3_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum4.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum4_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/extend.mp3") #if display private #end class __ASSET__assets_audio_mp3_extend_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/finalkill.mp3") #if display private #end class __ASSET__assets_audio_mp3_finalkill_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/fireballspawn.mp3") #if display private #end class __ASSET__assets_audio_mp3_fireballspawn_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/gameover.mp3") #if display private #end class __ASSET__assets_audio_mp3_gameover_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/killenemy.mp3") #if display private #end class __ASSET__assets_audio_mp3_killenemy_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/masterspark.mp3") #if display private #end class __ASSET__assets_audio_mp3_masterspark_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/nextlevel.mp3") #if display private #end class __ASSET__assets_audio_mp3_nextlevel_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/pow.mp3") #if display private #end class __ASSET__assets_audio_mp3_pow_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/respawn.mp3") #if display private #end class __ASSET__assets_audio_mp3_respawn_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/se_tan01.mp3") #if display private #end class __ASSET__assets_audio_mp3_se_tan01_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/spawncoin.mp3") #if display private #end class __ASSET__assets_audio_mp3_spawncoin_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/startgame.mp3") #if display private #end class __ASSET__assets_audio_mp3_startgame_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/step1.mp3") #if display private #end class __ASSET__assets_audio_mp3_step1_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/step2.mp3") #if display private #end class __ASSET__assets_audio_mp3_step2_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/step3.mp3") #if display private #end class __ASSET__assets_audio_mp3_step3_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme1.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme1_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme10.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme10_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme11.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme11_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme12.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme12_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme12intro.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme12intro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme2.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme2_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme2intro.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme2intro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme3.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme3_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme3intro.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme3intro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme4.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme4_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme5.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme5_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme6.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme6_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme7.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme7_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme8.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme8_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme8intro.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme8intro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/theme9.mp3") #if display private #end class __ASSET__assets_audio_mp3_theme9_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/titlescreen.mp3") #if display private #end class __ASSET__assets_audio_mp3_titlescreen_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/zawarudo.mp3") #if display private #end class __ASSET__assets_audio_mp3_zawarudo_mp3 extends lime.utils.ByteArray {}
@:image("Assets/bgcolor.png") #if display private #end class __ASSET__assets_bgcolor_png extends lime.graphics.Image {}
@:image("Assets/black.png") #if display private #end class __ASSET__assets_black_png extends lime.graphics.Image {}
@:image("Assets/Dpad.png") #if display private #end class __ASSET__assets_dpad_png extends lime.graphics.Image {}
@:file("Assets/Key.txt") #if display private #end class __ASSET__assets_key_txt extends lime.utils.ByteArray {}
@:image("Assets/Sprites/1up0.png") #if display private #end class __ASSET__assets_sprites_1up0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/akyu0.png") #if display private #end class __ASSET__assets_sprites_akyu0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/alice0.png") #if display private #end class __ASSET__assets_sprites_alice0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/aliceALT0.png") #if display private #end class __ASSET__assets_sprites_alicealt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/aya0.png") #if display private #end class __ASSET__assets_sprites_aya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ayana0.png") #if display private #end class __ASSET__assets_sprites_ayana0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/balloon0.png") #if display private #end class __ASSET__assets_sprites_balloon0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/barrier0.png") #if display private #end class __ASSET__assets_sprites_barrier0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bat0.png") #if display private #end class __ASSET__assets_sprites_bat0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bat1.png") #if display private #end class __ASSET__assets_sprites_bat1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/benben0.png") #if display private #end class __ASSET__assets_sprites_benben0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BG0.png") #if display private #end class __ASSET__assets_sprites_bg0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BG1.png") #if display private #end class __ASSET__assets_sprites_bg1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BG2.png") #if display private #end class __ASSET__assets_sprites_bg2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BG3.png") #if display private #end class __ASSET__assets_sprites_bg3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BG4.png") #if display private #end class __ASSET__assets_sprites_bg4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BG5.png") #if display private #end class __ASSET__assets_sprites_bg5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/black0.png") #if display private #end class __ASSET__assets_sprites_black0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/blackhole0.png") #if display private #end class __ASSET__assets_sprites_blackhole0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/block0.png") #if display private #end class __ASSET__assets_sprites_block0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BlueFairy0.png") #if display private #end class __ASSET__assets_sprites_bluefairy0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/BlueFairyflipped0.png") #if display private #end class __ASSET__assets_sprites_bluefairyflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Blueufo0.png") #if display private #end class __ASSET__assets_sprites_blueufo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bomb0.png") #if display private #end class __ASSET__assets_sprites_bomb0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bullet0.png") #if display private #end class __ASSET__assets_sprites_bullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/byakuren0.png") #if display private #end class __ASSET__assets_sprites_byakuren0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/charblock0.png") #if display private #end class __ASSET__assets_sprites_charblock0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/chen0.png") #if display private #end class __ASSET__assets_sprites_chen0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/chiyuri0.png") #if display private #end class __ASSET__assets_sprites_chiyuri0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/cirno0.png") #if display private #end class __ASSET__assets_sprites_cirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/cirnoflipped0.png") #if display private #end class __ASSET__assets_sprites_cirnoflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/cloud0.png") #if display private #end class __ASSET__assets_sprites_cloud0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/clownpiece0.png") #if display private #end class __ASSET__assets_sprites_clownpiece0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/CSBack0.png") #if display private #end class __ASSET__assets_sprites_csback0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/CSBG0.png") #if display private #end class __ASSET__assets_sprites_csbg0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/CSFront0.png") #if display private #end class __ASSET__assets_sprites_csfront0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/daiyousei0.png") #if display private #end class __ASSET__assets_sprites_daiyousei0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/darkness0.png") #if display private #end class __ASSET__assets_sprites_darkness0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/diosakuya0.png") #if display private #end class __ASSET__assets_sprites_diosakuya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/diosakuyaALT0.png") #if display private #end class __ASSET__assets_sprites_diosakuyaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/doremy0.png") #if display private #end class __ASSET__assets_sprites_doremy0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen0.png") #if display private #end class __ASSET__assets_sprites_echen0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen1.png") #if display private #end class __ASSET__assets_sprites_echen1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen10.png") #if display private #end class __ASSET__assets_sprites_echen10_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen11.png") #if display private #end class __ASSET__assets_sprites_echen11_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen12.png") #if display private #end class __ASSET__assets_sprites_echen12_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen13.png") #if display private #end class __ASSET__assets_sprites_echen13_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen14.png") #if display private #end class __ASSET__assets_sprites_echen14_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen15.png") #if display private #end class __ASSET__assets_sprites_echen15_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen2.png") #if display private #end class __ASSET__assets_sprites_echen2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen3.png") #if display private #end class __ASSET__assets_sprites_echen3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen4.png") #if display private #end class __ASSET__assets_sprites_echen4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen5.png") #if display private #end class __ASSET__assets_sprites_echen5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen6.png") #if display private #end class __ASSET__assets_sprites_echen6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen7.png") #if display private #end class __ASSET__assets_sprites_echen7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen8.png") #if display private #end class __ASSET__assets_sprites_echen8_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EChen9.png") #if display private #end class __ASSET__assets_sprites_echen9_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ECirno0.png") #if display private #end class __ASSET__assets_sprites_ecirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EHkaguya0.png") #if display private #end class __ASSET__assets_sprites_ehkaguya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EHmokou0.png") #if display private #end class __ASSET__assets_sprites_ehmokou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/eirin0.png") #if display private #end class __ASSET__assets_sprites_eirin0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Ekaguya0.png") #if display private #end class __ASSET__assets_sprites_ekaguya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Ekaguyaflipped0.png") #if display private #end class __ASSET__assets_sprites_ekaguyaflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EKeine0.png") #if display private #end class __ASSET__assets_sprites_ekeine0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EKeineex0.png") #if display private #end class __ASSET__assets_sprites_ekeineex0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EKeineexflipped0.png") #if display private #end class __ASSET__assets_sprites_ekeineexflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/electriccirno0.png") #if display private #end class __ASSET__assets_sprites_electriccirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/elis0.png") #if display private #end class __ASSET__assets_sprites_elis0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ellen0.png") #if display private #end class __ASSET__assets_sprites_ellen0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/elly0.png") #if display private #end class __ASSET__assets_sprites_elly0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Emokou0.png") #if display private #end class __ASSET__assets_sprites_emokou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Emokouflipped0.png") #if display private #end class __ASSET__assets_sprites_emokouflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EMystia0.png") #if display private #end class __ASSET__assets_sprites_emystia0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EMystia1.png") #if display private #end class __ASSET__assets_sprites_emystia1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EMystiaflipped0.png") #if display private #end class __ASSET__assets_sprites_emystiaflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan0.png") #if display private #end class __ASSET__assets_sprites_eran0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan1.png") #if display private #end class __ASSET__assets_sprites_eran1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan10.png") #if display private #end class __ASSET__assets_sprites_eran10_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan11.png") #if display private #end class __ASSET__assets_sprites_eran11_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan12.png") #if display private #end class __ASSET__assets_sprites_eran12_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan13.png") #if display private #end class __ASSET__assets_sprites_eran13_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan14.png") #if display private #end class __ASSET__assets_sprites_eran14_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan15.png") #if display private #end class __ASSET__assets_sprites_eran15_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan2.png") #if display private #end class __ASSET__assets_sprites_eran2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan3.png") #if display private #end class __ASSET__assets_sprites_eran3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan4.png") #if display private #end class __ASSET__assets_sprites_eran4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan5.png") #if display private #end class __ASSET__assets_sprites_eran5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan6.png") #if display private #end class __ASSET__assets_sprites_eran6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan7.png") #if display private #end class __ASSET__assets_sprites_eran7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan8.png") #if display private #end class __ASSET__assets_sprites_eran8_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ERan9.png") #if display private #end class __ASSET__assets_sprites_eran9_png extends lime.graphics.Image {}
@:image("Assets/Sprites/evilyuuka0.png") #if display private #end class __ASSET__assets_sprites_evilyuuka0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/exkeine0.png") #if display private #end class __ASSET__assets_sprites_exkeine0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/explosion0.png") #if display private #end class __ASSET__assets_sprites_explosion0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/firecirno0.png") #if display private #end class __ASSET__assets_sprites_firecirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flames0.png") #if display private #end class __ASSET__assets_sprites_flames0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flames1.png") #if display private #end class __ASSET__assets_sprites_flames1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flames2.png") #if display private #end class __ASSET__assets_sprites_flames2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flandre0.png") #if display private #end class __ASSET__assets_sprites_flandre0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flandreflipped0.png") #if display private #end class __ASSET__assets_sprites_flandreflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/futo0.png") #if display private #end class __ASSET__assets_sprites_futo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Gap0.png") #if display private #end class __ASSET__assets_sprites_gap0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/gengetsu0.png") #if display private #end class __ASSET__assets_sprites_gengetsu0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/giantcirno0.png") #if display private #end class __ASSET__assets_sprites_giantcirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/giantsuika0.png") #if display private #end class __ASSET__assets_sprites_giantsuika0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Greenufo0.png") #if display private #end class __ASSET__assets_sprites_greenufo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer0.png") #if display private #end class __ASSET__assets_sprites_hammer0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer1.png") #if display private #end class __ASSET__assets_sprites_hammer1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer10.png") #if display private #end class __ASSET__assets_sprites_hammer10_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer11.png") #if display private #end class __ASSET__assets_sprites_hammer11_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer12.png") #if display private #end class __ASSET__assets_sprites_hammer12_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer13.png") #if display private #end class __ASSET__assets_sprites_hammer13_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer14.png") #if display private #end class __ASSET__assets_sprites_hammer14_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer15.png") #if display private #end class __ASSET__assets_sprites_hammer15_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer2.png") #if display private #end class __ASSET__assets_sprites_hammer2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer3.png") #if display private #end class __ASSET__assets_sprites_hammer3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer4.png") #if display private #end class __ASSET__assets_sprites_hammer4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer5.png") #if display private #end class __ASSET__assets_sprites_hammer5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer6.png") #if display private #end class __ASSET__assets_sprites_hammer6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer7.png") #if display private #end class __ASSET__assets_sprites_hammer7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer8.png") #if display private #end class __ASSET__assets_sprites_hammer8_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hammer9.png") #if display private #end class __ASSET__assets_sprites_hammer9_png extends lime.graphics.Image {}
@:image("Assets/Sprites/happytenshi0.png") #if display private #end class __ASSET__assets_sprites_happytenshi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hatate0.png") #if display private #end class __ASSET__assets_sprites_hatate0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/heartbullet0.png") #if display private #end class __ASSET__assets_sprites_heartbullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hecatia0.png") #if display private #end class __ASSET__assets_sprites_hecatia0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hina0.png") #if display private #end class __ASSET__assets_sprites_hina0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/icebullet0.png") #if display private #end class __ASSET__assets_sprites_icebullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/icecube0.png") #if display private #end class __ASSET__assets_sprites_icecube0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ichirin0.png") #if display private #end class __ASSET__assets_sprites_ichirin0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/icyblock0.png") #if display private #end class __ASSET__assets_sprites_icyblock0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/iku0.png") #if display private #end class __ASSET__assets_sprites_iku0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ikuikudance0.png") #if display private #end class __ASSET__assets_sprites_ikuikudance0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/junko0.png") #if display private #end class __ASSET__assets_sprites_junko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kagerou0.png") #if display private #end class __ASSET__assets_sprites_kagerou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kaguya0.png") #if display private #end class __ASSET__assets_sprites_kaguya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kana0.png") #if display private #end class __ASSET__assets_sprites_kana0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kanako0.png") #if display private #end class __ASSET__assets_sprites_kanako0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kasen0.png") #if display private #end class __ASSET__assets_sprites_kasen0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/keine0.png") #if display private #end class __ASSET__assets_sprites_keine0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/keystone0.png") #if display private #end class __ASSET__assets_sprites_keystone0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife0.png") #if display private #end class __ASSET__assets_sprites_knife0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife1.png") #if display private #end class __ASSET__assets_sprites_knife1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife2.png") #if display private #end class __ASSET__assets_sprites_knife2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife3.png") #if display private #end class __ASSET__assets_sprites_knife3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife4.png") #if display private #end class __ASSET__assets_sprites_knife4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife5.png") #if display private #end class __ASSET__assets_sprites_knife5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife6.png") #if display private #end class __ASSET__assets_sprites_knife6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife7.png") #if display private #end class __ASSET__assets_sprites_knife7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/koakuma0.png") #if display private #end class __ASSET__assets_sprites_koakuma0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kogasa0.png") #if display private #end class __ASSET__assets_sprites_kogasa0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kogasaflipped0.png") #if display private #end class __ASSET__assets_sprites_kogasaflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/koishi0.png") #if display private #end class __ASSET__assets_sprites_koishi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/koishiflipped0.png") #if display private #end class __ASSET__assets_sprites_koishiflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kokoro0.png") #if display private #end class __ASSET__assets_sprites_kokoro0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/komachi0.png") #if display private #end class __ASSET__assets_sprites_komachi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/konngara0.png") #if display private #end class __ASSET__assets_sprites_konngara0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kosuzu0.png") #if display private #end class __ASSET__assets_sprites_kosuzu0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kotohime0.png") #if display private #end class __ASSET__assets_sprites_kotohime0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kurumi0.png") #if display private #end class __ASSET__assets_sprites_kurumi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/kyouko0.png") #if display private #end class __ASSET__assets_sprites_kyouko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/letty0.png") #if display private #end class __ASSET__assets_sprites_letty0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lightning0.png") #if display private #end class __ASSET__assets_sprites_lightning0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lilith0.png") #if display private #end class __ASSET__assets_sprites_lilith0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lily0.png") #if display private #end class __ASSET__assets_sprites_lily0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/louise0.png") #if display private #end class __ASSET__assets_sprites_louise0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lunachild0.png") #if display private #end class __ASSET__assets_sprites_lunachild0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lunasa0.png") #if display private #end class __ASSET__assets_sprites_lunasa0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lyrica0.png") #if display private #end class __ASSET__assets_sprites_lyrica0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mai0.png") #if display private #end class __ASSET__assets_sprites_mai0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/makairesident-a0.png") #if display private #end class __ASSET__assets_sprites_makairesident_a0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mamizou0.png") #if display private #end class __ASSET__assets_sprites_mamizou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/maribel0.png") #if display private #end class __ASSET__assets_sprites_maribel0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/marisa0.png") #if display private #end class __ASSET__assets_sprites_marisa0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/marisaALT0.png") #if display private #end class __ASSET__assets_sprites_marisaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/matenshi0.png") #if display private #end class __ASSET__assets_sprites_matenshi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/medicine0.png") #if display private #end class __ASSET__assets_sprites_medicine0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meiling0.png") #if display private #end class __ASSET__assets_sprites_meiling0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meilingALT0.png") #if display private #end class __ASSET__assets_sprites_meilingalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meilingflipped0.png") #if display private #end class __ASSET__assets_sprites_meilingflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meilingsleeping0.png") #if display private #end class __ASSET__assets_sprites_meilingsleeping0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meilingsleepingflipped0.png") #if display private #end class __ASSET__assets_sprites_meilingsleepingflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meira0.png") #if display private #end class __ASSET__assets_sprites_meira0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/merlin0.png") #if display private #end class __ASSET__assets_sprites_merlin0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/miko0.png") #if display private #end class __ASSET__assets_sprites_miko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mima0.png") #if display private #end class __ASSET__assets_sprites_mima0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mimaALT0.png") #if display private #end class __ASSET__assets_sprites_mimaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/minoriko0.png") #if display private #end class __ASSET__assets_sprites_minoriko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mokou0.png") #if display private #end class __ASSET__assets_sprites_mokou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/momiji0.png") #if display private #end class __ASSET__assets_sprites_momiji0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mrghosty0.png") #if display private #end class __ASSET__assets_sprites_mrghosty0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mugetsu0.png") #if display private #end class __ASSET__assets_sprites_mugetsu0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/murasa0.png") #if display private #end class __ASSET__assets_sprites_murasa0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/myon0.png") #if display private #end class __ASSET__assets_sprites_myon0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mystia0.png") #if display private #end class __ASSET__assets_sprites_mystia0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mystiaALT0.png") #if display private #end class __ASSET__assets_sprites_mystiaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/nazrin0.png") #if display private #end class __ASSET__assets_sprites_nazrin0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/nazrinflipped0.png") #if display private #end class __ASSET__assets_sprites_nazrinflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/nitori0.png") #if display private #end class __ASSET__assets_sprites_nitori0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/noroiko0.png") #if display private #end class __ASSET__assets_sprites_noroiko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/nue0.png") #if display private #end class __ASSET__assets_sprites_nue0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/okuu0.png") #if display private #end class __ASSET__assets_sprites_okuu0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/okuuflipped0.png") #if display private #end class __ASSET__assets_sprites_okuuflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/options0.png") #if display private #end class __ASSET__assets_sprites_options0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/orange0.png") #if display private #end class __ASSET__assets_sprites_orange0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/orin0.png") #if display private #end class __ASSET__assets_sprites_orin0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/parsee0.png") #if display private #end class __ASSET__assets_sprites_parsee0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/patchouli0.png") #if display private #end class __ASSET__assets_sprites_patchouli0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/pika0.png") #if display private #end class __ASSET__assets_sprites_pika0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Point0.png") #if display private #end class __ASSET__assets_sprites_point0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/poisoncloud0.png") #if display private #end class __ASSET__assets_sprites_poisoncloud0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/POW0.png") #if display private #end class __ASSET__assets_sprites_pow0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/POWalt0.png") #if display private #end class __ASSET__assets_sprites_powalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/prinny0.png") #if display private #end class __ASSET__assets_sprites_prinny0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/raiko0.png") #if display private #end class __ASSET__assets_sprites_raiko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ran0.png") #if display private #end class __ASSET__assets_sprites_ran0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/redeyedudongein0.png") #if display private #end class __ASSET__assets_sprites_redeyedudongein0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/RedFairy0.png") #if display private #end class __ASSET__assets_sprites_redfairy0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/RedFairyflipped0.png") #if display private #end class __ASSET__assets_sprites_redfairyflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Redufo0.png") #if display private #end class __ASSET__assets_sprites_redufo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/reimu0.png") #if display private #end class __ASSET__assets_sprites_reimu0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/reimuALT0.png") #if display private #end class __ASSET__assets_sprites_reimualt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/reimuflipped0.png") #if display private #end class __ASSET__assets_sprites_reimuflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/reisen0.png") #if display private #end class __ASSET__assets_sprites_reisen0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/remilia0.png") #if display private #end class __ASSET__assets_sprites_remilia0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/remiliaflipped0.png") #if display private #end class __ASSET__assets_sprites_remiliaflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/rengeteki0.png") #if display private #end class __ASSET__assets_sprites_rengeteki0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/renko0.png") #if display private #end class __ASSET__assets_sprites_renko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/rika0.png") #if display private #end class __ASSET__assets_sprites_rika0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/rikako0.png") #if display private #end class __ASSET__assets_sprites_rikako0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/rin0.png") #if display private #end class __ASSET__assets_sprites_rin0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ringo0.png") #if display private #end class __ASSET__assets_sprites_ringo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/rumia0.png") #if display private #end class __ASSET__assets_sprites_rumia0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ruukoto0.png") #if display private #end class __ASSET__assets_sprites_ruukoto0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sagume0.png") #if display private #end class __ASSET__assets_sprites_sagume0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sakuya0.png") #if display private #end class __ASSET__assets_sprites_sakuya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sakuyaALT0.png") #if display private #end class __ASSET__assets_sprites_sakuyaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sanae0.png") #if display private #end class __ASSET__assets_sprites_sanae0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sanaeALT0.png") #if display private #end class __ASSET__assets_sprites_sanaealt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sara0.png") #if display private #end class __ASSET__assets_sprites_sara0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sariel0.png") #if display private #end class __ASSET__assets_sprites_sariel0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/satori0.png") #if display private #end class __ASSET__assets_sprites_satori0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/satoriflipped0.png") #if display private #end class __ASSET__assets_sprites_satoriflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe0.png") #if display private #end class __ASSET__assets_sprites_scythe0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe1.png") #if display private #end class __ASSET__assets_sprites_scythe1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe10.png") #if display private #end class __ASSET__assets_sprites_scythe10_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe11.png") #if display private #end class __ASSET__assets_sprites_scythe11_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe12.png") #if display private #end class __ASSET__assets_sprites_scythe12_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe13.png") #if display private #end class __ASSET__assets_sprites_scythe13_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe14.png") #if display private #end class __ASSET__assets_sprites_scythe14_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe15.png") #if display private #end class __ASSET__assets_sprites_scythe15_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe2.png") #if display private #end class __ASSET__assets_sprites_scythe2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe3.png") #if display private #end class __ASSET__assets_sprites_scythe3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe4.png") #if display private #end class __ASSET__assets_sprites_scythe4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe5.png") #if display private #end class __ASSET__assets_sprites_scythe5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe6.png") #if display private #end class __ASSET__assets_sprites_scythe6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe7.png") #if display private #end class __ASSET__assets_sprites_scythe7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe8.png") #if display private #end class __ASSET__assets_sprites_scythe8_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe9.png") #if display private #end class __ASSET__assets_sprites_scythe9_png extends lime.graphics.Image {}
@:image("Assets/Sprites/seiga0.png") #if display private #end class __ASSET__assets_sprites_seiga0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/seija0.png") #if display private #end class __ASSET__assets_sprites_seija0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/seiran0.png") #if display private #end class __ASSET__assets_sprites_seiran0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sekibanki0.png") #if display private #end class __ASSET__assets_sprites_sekibanki0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sekibankihead0.png") #if display private #end class __ASSET__assets_sprites_sekibankihead0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sekibankiheadless0.png") #if display private #end class __ASSET__assets_sprites_sekibankiheadless0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shanghai0.png") #if display private #end class __ASSET__assets_sprites_shanghai0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shikieiki0.png") #if display private #end class __ASSET__assets_sprites_shikieiki0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shingyoku0.png") #if display private #end class __ASSET__assets_sprites_shingyoku0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shingyokuALT0.png") #if display private #end class __ASSET__assets_sprites_shingyokualt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shinki0.png") #if display private #end class __ASSET__assets_sprites_shinki0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shinmyoumaru0.png") #if display private #end class __ASSET__assets_sprites_shinmyoumaru0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shizuha0.png") #if display private #end class __ASSET__assets_sprites_shizuha0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shou0.png") #if display private #end class __ASSET__assets_sprites_shou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/skull0.png") #if display private #end class __ASSET__assets_sprites_skull0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/starbulletg0.png") #if display private #end class __ASSET__assets_sprites_starbulletg0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/starbullety0.png") #if display private #end class __ASSET__assets_sprites_starbullety0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/starsaphire0.png") #if display private #end class __ASSET__assets_sprites_starsaphire0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/suika0.png") #if display private #end class __ASSET__assets_sprites_suika0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sumireko0.png") #if display private #end class __ASSET__assets_sprites_sumireko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sunnymilk0.png") #if display private #end class __ASSET__assets_sprites_sunnymilk0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/suwako0.png") #if display private #end class __ASSET__assets_sprites_suwako0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/suwakohoop0.png") #if display private #end class __ASSET__assets_sprites_suwakohoop0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table0.png") #if display private #end class __ASSET__assets_sprites_table0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table1.png") #if display private #end class __ASSET__assets_sprites_table1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table10.png") #if display private #end class __ASSET__assets_sprites_table10_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table11.png") #if display private #end class __ASSET__assets_sprites_table11_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table12.png") #if display private #end class __ASSET__assets_sprites_table12_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table13.png") #if display private #end class __ASSET__assets_sprites_table13_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table14.png") #if display private #end class __ASSET__assets_sprites_table14_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table15.png") #if display private #end class __ASSET__assets_sprites_table15_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table2.png") #if display private #end class __ASSET__assets_sprites_table2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table3.png") #if display private #end class __ASSET__assets_sprites_table3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table4.png") #if display private #end class __ASSET__assets_sprites_table4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table5.png") #if display private #end class __ASSET__assets_sprites_table5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table6.png") #if display private #end class __ASSET__assets_sprites_table6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table7.png") #if display private #end class __ASSET__assets_sprites_table7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table8.png") #if display private #end class __ASSET__assets_sprites_table8_png extends lime.graphics.Image {}
@:image("Assets/Sprites/table9.png") #if display private #end class __ASSET__assets_sprites_table9_png extends lime.graphics.Image {}
@:image("Assets/Sprites/tenshi0.png") #if display private #end class __ASSET__assets_sprites_tenshi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/tenshiflipped0.png") #if display private #end class __ASSET__assets_sprites_tenshiflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/tewi0.png") #if display private #end class __ASSET__assets_sprites_tewi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/tewiflipped0.png") #if display private #end class __ASSET__assets_sprites_tewiflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/titlescreen0.png") #if display private #end class __ASSET__assets_sprites_titlescreen0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/tojiko0.png") #if display private #end class __ASSET__assets_sprites_tojiko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/tokiko0.png") #if display private #end class __ASSET__assets_sprites_tokiko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/toyohime0.png") #if display private #end class __ASSET__assets_sprites_toyohime0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/train0.png") #if display private #end class __ASSET__assets_sprites_train0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/trophy0.png") #if display private #end class __ASSET__assets_sprites_trophy0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/truck0.png") #if display private #end class __ASSET__assets_sprites_truck0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/udongein0.png") #if display private #end class __ASSET__assets_sprites_udongein0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/udongeinflipped0.png") #if display private #end class __ASSET__assets_sprites_udongeinflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/unused0.png") #if display private #end class __ASSET__assets_sprites_unused0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/unzanfist0.png") #if display private #end class __ASSET__assets_sprites_unzanfist0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/utsuho0.png") #if display private #end class __ASSET__assets_sprites_utsuho0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/utsuhobullet0.png") #if display private #end class __ASSET__assets_sprites_utsuhobullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/wakasagihime0.png") #if display private #end class __ASSET__assets_sprites_wakasagihime0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/warning0.png") #if display private #end class __ASSET__assets_sprites_warning0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/wriggle0.png") #if display private #end class __ASSET__assets_sprites_wriggle0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yamame0.png") #if display private #end class __ASSET__assets_sprites_yamame0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yatsuhashi0.png") #if display private #end class __ASSET__assets_sprites_yatsuhashi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb0.png") #if display private #end class __ASSET__assets_sprites_yinyangorb0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb1.png") #if display private #end class __ASSET__assets_sprites_yinyangorb1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb10.png") #if display private #end class __ASSET__assets_sprites_yinyangorb10_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb11.png") #if display private #end class __ASSET__assets_sprites_yinyangorb11_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb12.png") #if display private #end class __ASSET__assets_sprites_yinyangorb12_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb13.png") #if display private #end class __ASSET__assets_sprites_yinyangorb13_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb14.png") #if display private #end class __ASSET__assets_sprites_yinyangorb14_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb15.png") #if display private #end class __ASSET__assets_sprites_yinyangorb15_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb2.png") #if display private #end class __ASSET__assets_sprites_yinyangorb2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb3.png") #if display private #end class __ASSET__assets_sprites_yinyangorb3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb4.png") #if display private #end class __ASSET__assets_sprites_yinyangorb4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb5.png") #if display private #end class __ASSET__assets_sprites_yinyangorb5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb6.png") #if display private #end class __ASSET__assets_sprites_yinyangorb6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb7.png") #if display private #end class __ASSET__assets_sprites_yinyangorb7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb8.png") #if display private #end class __ASSET__assets_sprites_yinyangorb8_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yinyangorb9.png") #if display private #end class __ASSET__assets_sprites_yinyangorb9_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yorihime0.png") #if display private #end class __ASSET__assets_sprites_yorihime0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yoshika0.png") #if display private #end class __ASSET__assets_sprites_yoshika0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/youmu0.png") #if display private #end class __ASSET__assets_sprites_youmu0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yukari0.png") #if display private #end class __ASSET__assets_sprites_yukari0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yukaribullet0.png") #if display private #end class __ASSET__assets_sprites_yukaribullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yukariflipped0.png") #if display private #end class __ASSET__assets_sprites_yukariflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yuki0.png") #if display private #end class __ASSET__assets_sprites_yuki0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yumeko0.png") #if display private #end class __ASSET__assets_sprites_yumeko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yumemi0.png") #if display private #end class __ASSET__assets_sprites_yumemi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yuugi0.png") #if display private #end class __ASSET__assets_sprites_yuugi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yuuka0.png") #if display private #end class __ASSET__assets_sprites_yuuka0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yuukaALT0.png") #if display private #end class __ASSET__assets_sprites_yuukaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yuyuko0.png") #if display private #end class __ASSET__assets_sprites_yuyuko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/zombiefairy0.png") #if display private #end class __ASSET__assets_sprites_zombiefairy0_png extends lime.graphics.Image {}



#end

#if openfl

#end

#end
#end

