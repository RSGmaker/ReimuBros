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
		
		className.set ("assets/Audio/Mp3/adv1.mp3", __ASSET__assets_audio_mp3_adv1_mp3);
		type.set ("assets/Audio/Mp3/adv1.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/adv2.mp3", __ASSET__assets_audio_mp3_adv2_mp3);
		type.set ("assets/Audio/Mp3/adv2.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/adv2intro.mp3", __ASSET__assets_audio_mp3_adv2intro_mp3);
		type.set ("assets/Audio/Mp3/adv2intro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/adv3.mp3", __ASSET__assets_audio_mp3_adv3_mp3);
		type.set ("assets/Audio/Mp3/adv3.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/adv3intro.mp3", __ASSET__assets_audio_mp3_adv3intro_mp3);
		type.set ("assets/Audio/Mp3/adv3intro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/adv4.mp3", __ASSET__assets_audio_mp3_adv4_mp3);
		type.set ("assets/Audio/Mp3/adv4.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/adv5.mp3", __ASSET__assets_audio_mp3_adv5_mp3);
		type.set ("assets/Audio/Mp3/adv5.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/adv6.mp3", __ASSET__assets_audio_mp3_adv6_mp3);
		type.set ("assets/Audio/Mp3/adv6.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/anchor.mp3", __ASSET__assets_audio_mp3_anchor_mp3);
		type.set ("assets/Audio/Mp3/anchor.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/bonk.mp3", __ASSET__assets_audio_mp3_bonk_mp3);
		type.set ("assets/Audio/Mp3/bonk.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/cancel.mp3", __ASSET__assets_audio_mp3_cancel_mp3);
		type.set ("assets/Audio/Mp3/cancel.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/cash.mp3", __ASSET__assets_audio_mp3_cash_mp3);
		type.set ("assets/Audio/Mp3/cash.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/characterselect.mp3", __ASSET__assets_audio_mp3_characterselect_mp3);
		type.set ("assets/Audio/Mp3/characterselect.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/click.mp3", __ASSET__assets_audio_mp3_click_mp3);
		type.set ("assets/Audio/Mp3/click.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/collectcoin.mp3", __ASSET__assets_audio_mp3_collectcoin_mp3);
		type.set ("assets/Audio/Mp3/collectcoin.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/customize.mp3", __ASSET__assets_audio_mp3_customize_mp3);
		type.set ("assets/Audio/Mp3/customize.mp3", AssetType.MUSIC);
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
		className.set ("assets/Audio/Mp3/explode.mp3", __ASSET__assets_audio_mp3_explode_mp3);
		type.set ("assets/Audio/Mp3/explode.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/extend.mp3", __ASSET__assets_audio_mp3_extend_mp3);
		type.set ("assets/Audio/Mp3/extend.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/finalkill.mp3", __ASSET__assets_audio_mp3_finalkill_mp3);
		type.set ("assets/Audio/Mp3/finalkill.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/fireballspawn.mp3", __ASSET__assets_audio_mp3_fireballspawn_mp3);
		type.set ("assets/Audio/Mp3/fireballspawn.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/gameover.mp3", __ASSET__assets_audio_mp3_gameover_mp3);
		type.set ("assets/Audio/Mp3/gameover.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/getbonus.mp3", __ASSET__assets_audio_mp3_getbonus_mp3);
		type.set ("assets/Audio/Mp3/getbonus.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/itemspawn.mp3", __ASSET__assets_audio_mp3_itemspawn_mp3);
		type.set ("assets/Audio/Mp3/itemspawn.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/killenemy.mp3", __ASSET__assets_audio_mp3_killenemy_mp3);
		type.set ("assets/Audio/Mp3/killenemy.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/masterspark.mp3", __ASSET__assets_audio_mp3_masterspark_mp3);
		type.set ("assets/Audio/Mp3/masterspark.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/nextlevel.mp3", __ASSET__assets_audio_mp3_nextlevel_mp3);
		type.set ("assets/Audio/Mp3/nextlevel.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/ok.mp3", __ASSET__assets_audio_mp3_ok_mp3);
		type.set ("assets/Audio/Mp3/ok.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/options.mp3", __ASSET__assets_audio_mp3_options_mp3);
		type.set ("assets/Audio/Mp3/options.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/optionsintro.mp3", __ASSET__assets_audio_mp3_optionsintro_mp3);
		type.set ("assets/Audio/Mp3/optionsintro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/pow.mp3", __ASSET__assets_audio_mp3_pow_mp3);
		type.set ("assets/Audio/Mp3/pow.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/powerdown.mp3", __ASSET__assets_audio_mp3_powerdown_mp3);
		type.set ("assets/Audio/Mp3/powerdown.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/powerup.mp3", __ASSET__assets_audio_mp3_powerup_mp3);
		type.set ("assets/Audio/Mp3/powerup.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/respawn.mp3", __ASSET__assets_audio_mp3_respawn_mp3);
		type.set ("assets/Audio/Mp3/respawn.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/se_tan01.mp3", __ASSET__assets_audio_mp3_se_tan01_mp3);
		type.set ("assets/Audio/Mp3/se_tan01.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/shop.mp3", __ASSET__assets_audio_mp3_shop_mp3);
		type.set ("assets/Audio/Mp3/shop.mp3", AssetType.MUSIC);
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
		className.set ("assets/Audio/Mp3/summonufo.mp3", __ASSET__assets_audio_mp3_summonufo_mp3);
		type.set ("assets/Audio/Mp3/summonufo.mp3", AssetType.MUSIC);
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
		className.set ("assets/Audio/Mp3/titlescreenintro.mp3", __ASSET__assets_audio_mp3_titlescreenintro_mp3);
		type.set ("assets/Audio/Mp3/titlescreenintro.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/ufochange.mp3", __ASSET__assets_audio_mp3_ufochange_mp3);
		type.set ("assets/Audio/Mp3/ufochange.mp3", AssetType.MUSIC);
		className.set ("assets/Audio/Mp3/ufoitem.mp3", __ASSET__assets_audio_mp3_ufoitem_mp3);
		type.set ("assets/Audio/Mp3/ufoitem.mp3", AssetType.MUSIC);
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
		className.set ("assets/Sprites/anchor0.png", __ASSET__assets_sprites_anchor0_png);
		type.set ("assets/Sprites/anchor0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Arrow0.png", __ASSET__assets_sprites_arrow0_png);
		type.set ("assets/Sprites/Arrow0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ayana0.png", __ASSET__assets_sprites_ayana0_png);
		type.set ("assets/Sprites/ayana0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/balloon0.png", __ASSET__assets_sprites_balloon0_png);
		type.set ("assets/Sprites/balloon0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/balloon1.png", __ASSET__assets_sprites_balloon1_png);
		type.set ("assets/Sprites/balloon1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/balloon2.png", __ASSET__assets_sprites_balloon2_png);
		type.set ("assets/Sprites/balloon2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/balloon3.png", __ASSET__assets_sprites_balloon3_png);
		type.set ("assets/Sprites/balloon3.png", AssetType.IMAGE);
		className.set ("assets/Sprites/balloon4.png", __ASSET__assets_sprites_balloon4_png);
		type.set ("assets/Sprites/balloon4.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bananapeel0.png", __ASSET__assets_sprites_bananapeel0_png);
		type.set ("assets/Sprites/bananapeel0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/barrier0.png", __ASSET__assets_sprites_barrier0_png);
		type.set ("assets/Sprites/barrier0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bat0.png", __ASSET__assets_sprites_bat0_png);
		type.set ("assets/Sprites/bat0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bat1.png", __ASSET__assets_sprites_bat1_png);
		type.set ("assets/Sprites/bat1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bhina0.png", __ASSET__assets_sprites_bhina0_png);
		type.set ("assets/Sprites/bhina0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/black0.png", __ASSET__assets_sprites_black0_png);
		type.set ("assets/Sprites/black0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/blackhole0.png", __ASSET__assets_sprites_blackhole0_png);
		type.set ("assets/Sprites/blackhole0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Blackufo0.png", __ASSET__assets_sprites_blackufo0_png);
		type.set ("assets/Sprites/Blackufo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/block0.png", __ASSET__assets_sprites_block0_png);
		type.set ("assets/Sprites/block0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bluebird.png", __ASSET__assets_sprites_bluebird_png);
		type.set ("assets/Sprites/bluebird.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bluelaser0.png", __ASSET__assets_sprites_bluelaser0_png);
		type.set ("assets/Sprites/bluelaser0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Blueufo0.png", __ASSET__assets_sprites_blueufo0_png);
		type.set ("assets/Sprites/Blueufo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bomb0.png", __ASSET__assets_sprites_bomb0_png);
		type.set ("assets/Sprites/bomb0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Boomerang0.png", __ASSET__assets_sprites_boomerang0_png);
		type.set ("assets/Sprites/Boomerang0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Bow0.png", __ASSET__assets_sprites_bow0_png);
		type.set ("assets/Sprites/Bow0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/bullet0.png", __ASSET__assets_sprites_bullet0_png);
		type.set ("assets/Sprites/bullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/camera0.png", __ASSET__assets_sprites_camera0_png);
		type.set ("assets/Sprites/camera0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/charblock0.png", __ASSET__assets_sprites_charblock0_png);
		type.set ("assets/Sprites/charblock0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/chenALT0.png", __ASSET__assets_sprites_chenalt0_png);
		type.set ("assets/Sprites/chenALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/chest.png", __ASSET__assets_sprites_chest_png);
		type.set ("assets/Sprites/chest.png", AssetType.IMAGE);
		className.set ("assets/Sprites/cloud0.png", __ASSET__assets_sprites_cloud0_png);
		type.set ("assets/Sprites/cloud0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/cross0.png", __ASSET__assets_sprites_cross0_png);
		type.set ("assets/Sprites/cross0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/CSBack0.png", __ASSET__assets_sprites_csback0_png);
		type.set ("assets/Sprites/CSBack0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/CSFront0.png", __ASSET__assets_sprites_csfront0_png);
		type.set ("assets/Sprites/CSFront0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/darkness0.png", __ASSET__assets_sprites_darkness0_png);
		type.set ("assets/Sprites/darkness0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/deathcirno0.png", __ASSET__assets_sprites_deathcirno0_png);
		type.set ("assets/Sprites/deathcirno0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/diosakuya0.png", __ASSET__assets_sprites_diosakuya0_png);
		type.set ("assets/Sprites/diosakuya0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/diosakuyaALT0.png", __ASSET__assets_sprites_diosakuyaalt0_png);
		type.set ("assets/Sprites/diosakuyaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/disc0.png", __ASSET__assets_sprites_disc0_png);
		type.set ("assets/Sprites/disc0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/disc1.png", __ASSET__assets_sprites_disc1_png);
		type.set ("assets/Sprites/disc1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/disc2.png", __ASSET__assets_sprites_disc2_png);
		type.set ("assets/Sprites/disc2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/dresser.png", __ASSET__assets_sprites_dresser_png);
		type.set ("assets/Sprites/dresser.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/Emokou0.png", __ASSET__assets_sprites_emokou0_png);
		type.set ("assets/Sprites/Emokou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Emokouflipped0.png", __ASSET__assets_sprites_emokouflipped0_png);
		type.set ("assets/Sprites/Emokouflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/emptyblock0.png", __ASSET__assets_sprites_emptyblock0_png);
		type.set ("assets/Sprites/emptyblock0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EMystia0.png", __ASSET__assets_sprites_emystia0_png);
		type.set ("assets/Sprites/EMystia0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EMystia1.png", __ASSET__assets_sprites_emystia1_png);
		type.set ("assets/Sprites/EMystia1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/EMystiaflipped0.png", __ASSET__assets_sprites_emystiaflipped0_png);
		type.set ("assets/Sprites/EMystiaflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/energywave.png", __ASSET__assets_sprites_energywave_png);
		type.set ("assets/Sprites/energywave.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/exclamationblock.png", __ASSET__assets_sprites_exclamationblock_png);
		type.set ("assets/Sprites/exclamationblock.png", AssetType.IMAGE);
		className.set ("assets/Sprites/exclamationmark.png", __ASSET__assets_sprites_exclamationmark_png);
		type.set ("assets/Sprites/exclamationmark.png", AssetType.IMAGE);
		className.set ("assets/Sprites/exkeine0.png", __ASSET__assets_sprites_exkeine0_png);
		type.set ("assets/Sprites/exkeine0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/explosion0.png", __ASSET__assets_sprites_explosion0_png);
		type.set ("assets/Sprites/explosion0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Explosive0.png", __ASSET__assets_sprites_explosive0_png);
		type.set ("assets/Sprites/Explosive0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/firecirno0.png", __ASSET__assets_sprites_firecirno0_png);
		type.set ("assets/Sprites/firecirno0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flag0.png", __ASSET__assets_sprites_flag0_png);
		type.set ("assets/Sprites/flag0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flames0.png", __ASSET__assets_sprites_flames0_png);
		type.set ("assets/Sprites/flames0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flames1.png", __ASSET__assets_sprites_flames1_png);
		type.set ("assets/Sprites/flames1.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flames2.png", __ASSET__assets_sprites_flames2_png);
		type.set ("assets/Sprites/flames2.png", AssetType.IMAGE);
		className.set ("assets/Sprites/flandreALT0.png", __ASSET__assets_sprites_flandrealt0_png);
		type.set ("assets/Sprites/flandreALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Gap0.png", __ASSET__assets_sprites_gap0_png);
		type.set ("assets/Sprites/Gap0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Greenufo0.png", __ASSET__assets_sprites_greenufo0_png);
		type.set ("assets/Sprites/Greenufo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hairdye0.png", __ASSET__assets_sprites_hairdye0_png);
		type.set ("assets/Sprites/hairdye0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/heartbullet0.png", __ASSET__assets_sprites_heartbullet0_png);
		type.set ("assets/Sprites/heartbullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hecatiae0.png", __ASSET__assets_sprites_hecatiae0_png);
		type.set ("assets/Sprites/hecatiae0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hecatiaeflipped0.png", __ASSET__assets_sprites_hecatiaeflipped0_png);
		type.set ("assets/Sprites/hecatiaeflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/hecatiam0.png", __ASSET__assets_sprites_hecatiam0_png);
		type.set ("assets/Sprites/hecatiam0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/icebullet0.png", __ASSET__assets_sprites_icebullet0_png);
		type.set ("assets/Sprites/icebullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/icecube0.png", __ASSET__assets_sprites_icecube0_png);
		type.set ("assets/Sprites/icecube0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/icyblock0.png", __ASSET__assets_sprites_icyblock0_png);
		type.set ("assets/Sprites/icyblock0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ikuikudance0.png", __ASSET__assets_sprites_ikuikudance0_png);
		type.set ("assets/Sprites/ikuikudance0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/komachiALT0.png", __ASSET__assets_sprites_komachialt0_png);
		type.set ("assets/Sprites/komachiALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lbullet0.png", __ASSET__assets_sprites_lbullet0_png);
		type.set ("assets/Sprites/lbullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lightning0.png", __ASSET__assets_sprites_lightning0_png);
		type.set ("assets/Sprites/lightning0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/lightsword.png", __ASSET__assets_sprites_lightsword_png);
		type.set ("assets/Sprites/lightsword.png", AssetType.IMAGE);
		className.set ("assets/Sprites/logo.png", __ASSET__assets_sprites_logo_png);
		type.set ("assets/Sprites/logo.png", AssetType.IMAGE);
		className.set ("assets/Sprites/matenshi0.png", __ASSET__assets_sprites_matenshi0_png);
		type.set ("assets/Sprites/matenshi0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/meilingsleeping0.png", __ASSET__assets_sprites_meilingsleeping0_png);
		type.set ("assets/Sprites/meilingsleeping0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/meilingsleepingflipped0.png", __ASSET__assets_sprites_meilingsleepingflipped0_png);
		type.set ("assets/Sprites/meilingsleepingflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mika0.png", __ASSET__assets_sprites_mika0_png);
		type.set ("assets/Sprites/mika0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/minihakkero0.png", __ASSET__assets_sprites_minihakkero0_png);
		type.set ("assets/Sprites/minihakkero0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mirror.png", __ASSET__assets_sprites_mirror_png);
		type.set ("assets/Sprites/mirror.png", AssetType.IMAGE);
		className.set ("assets/Sprites/money0.png", __ASSET__assets_sprites_money0_png);
		type.set ("assets/Sprites/money0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/MoonRabbit0.png", __ASSET__assets_sprites_moonrabbit0_png);
		type.set ("assets/Sprites/MoonRabbit0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/MoonRabbitflipped0.png", __ASSET__assets_sprites_moonrabbitflipped0_png);
		type.set ("assets/Sprites/MoonRabbitflipped0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/mrghosty0.png", __ASSET__assets_sprites_mrghosty0_png);
		type.set ("assets/Sprites/mrghosty0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/murasabullet0.png", __ASSET__assets_sprites_murasabullet0_png);
		type.set ("assets/Sprites/murasabullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/myon0.png", __ASSET__assets_sprites_myon0_png);
		type.set ("assets/Sprites/myon0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/noroiko0.png", __ASSET__assets_sprites_noroiko0_png);
		type.set ("assets/Sprites/noroiko0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/notepad0.png", __ASSET__assets_sprites_notepad0_png);
		type.set ("assets/Sprites/notepad0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/parseebullet0.png", __ASSET__assets_sprites_parseebullet0_png);
		type.set ("assets/Sprites/parseebullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/patchouliALT0.png", __ASSET__assets_sprites_patchoulialt0_png);
		type.set ("assets/Sprites/patchouliALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/pbullet0.png", __ASSET__assets_sprites_pbullet0_png);
		type.set ("assets/Sprites/pbullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/pika0.png", __ASSET__assets_sprites_pika0_png);
		type.set ("assets/Sprites/pika0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/pmusicnote0.png", __ASSET__assets_sprites_pmusicnote0_png);
		type.set ("assets/Sprites/pmusicnote0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Point0.png", __ASSET__assets_sprites_point0_png);
		type.set ("assets/Sprites/Point0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/poisoncloud0.png", __ASSET__assets_sprites_poisoncloud0_png);
		type.set ("assets/Sprites/poisoncloud0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/POW0.png", __ASSET__assets_sprites_pow0_png);
		type.set ("assets/Sprites/POW0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/POWalt0.png", __ASSET__assets_sprites_powalt0_png);
		type.set ("assets/Sprites/POWalt0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/powerup0.png", __ASSET__assets_sprites_powerup0_png);
		type.set ("assets/Sprites/powerup0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/preisenbullet0.png", __ASSET__assets_sprites_preisenbullet0_png);
		type.set ("assets/Sprites/preisenbullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/present0.png", __ASSET__assets_sprites_present0_png);
		type.set ("assets/Sprites/present0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/prinny0.png", __ASSET__assets_sprites_prinny0_png);
		type.set ("assets/Sprites/prinny0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/questionblock0.png", __ASSET__assets_sprites_questionblock0_png);
		type.set ("assets/Sprites/questionblock0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/ranALT0.png", __ASSET__assets_sprites_ranalt0_png);
		type.set ("assets/Sprites/ranALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Redufo0.png", __ASSET__assets_sprites_redufo0_png);
		type.set ("assets/Sprites/Redufo0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/remiliaALT0.png", __ASSET__assets_sprites_remiliaalt0_png);
		type.set ("assets/Sprites/remiliaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/rock.png", __ASSET__assets_sprites_rock_png);
		type.set ("assets/Sprites/rock.png", AssetType.IMAGE);
		className.set ("assets/Sprites/Roukanken0.png", __ASSET__assets_sprites_roukanken0_png);
		type.set ("assets/Sprites/Roukanken0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/rumiaALT0.png", __ASSET__assets_sprites_rumiaalt0_png);
		type.set ("assets/Sprites/rumiaALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/SanaeStick0.png", __ASSET__assets_sprites_sanaestick0_png);
		type.set ("assets/Sprites/SanaeStick0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sawblade0.png", __ASSET__assets_sprites_sawblade0_png);
		type.set ("assets/Sprites/sawblade0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/scythe0.png", __ASSET__assets_sprites_scythe0_png);
		type.set ("assets/Sprites/scythe0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sekibankihead0.png", __ASSET__assets_sprites_sekibankihead0_png);
		type.set ("assets/Sprites/sekibankihead0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sekibankiheadless0.png", __ASSET__assets_sprites_sekibankiheadless0_png);
		type.set ("assets/Sprites/sekibankiheadless0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/senkou0.png", __ASSET__assets_sprites_senkou0_png);
		type.set ("assets/Sprites/senkou0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/shingyokuorb0.png", __ASSET__assets_sprites_shingyokuorb0_png);
		type.set ("assets/Sprites/shingyokuorb0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/skull0.png", __ASSET__assets_sprites_skull0_png);
		type.set ("assets/Sprites/skull0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/spectrum0.png", __ASSET__assets_sprites_spectrum0_png);
		type.set ("assets/Sprites/spectrum0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/spellcard0.png", __ASSET__assets_sprites_spellcard0_png);
		type.set ("assets/Sprites/spellcard0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/spiderweb0.png", __ASSET__assets_sprites_spiderweb0_png);
		type.set ("assets/Sprites/spiderweb0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/starbulletg0.png", __ASSET__assets_sprites_starbulletg0_png);
		type.set ("assets/Sprites/starbulletg0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/starbullety0.png", __ASSET__assets_sprites_starbullety0_png);
		type.set ("assets/Sprites/starbullety0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/starorb0.png", __ASSET__assets_sprites_starorb0_png);
		type.set ("assets/Sprites/starorb0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/suwakohat0.png", __ASSET__assets_sprites_suwakohat0_png);
		type.set ("assets/Sprites/suwakohat0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/suwakohoop0.png", __ASSET__assets_sprites_suwakohoop0_png);
		type.set ("assets/Sprites/suwakohoop0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/sword0.png", __ASSET__assets_sprites_sword0_png);
		type.set ("assets/Sprites/sword0.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/teacup0.png", __ASSET__assets_sprites_teacup0_png);
		type.set ("assets/Sprites/teacup0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/telephonepole0.png", __ASSET__assets_sprites_telephonepole0_png);
		type.set ("assets/Sprites/telephonepole0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/train0.png", __ASSET__assets_sprites_train0_png);
		type.set ("assets/Sprites/train0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/trophy0.png", __ASSET__assets_sprites_trophy0_png);
		type.set ("assets/Sprites/trophy0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/truck0.png", __ASSET__assets_sprites_truck0_png);
		type.set ("assets/Sprites/truck0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/unused0.png", __ASSET__assets_sprites_unused0_png);
		type.set ("assets/Sprites/unused0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/unzanfist0.png", __ASSET__assets_sprites_unzanfist0_png);
		type.set ("assets/Sprites/unzanfist0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/utsuhobullet0.png", __ASSET__assets_sprites_utsuhobullet0_png);
		type.set ("assets/Sprites/utsuhobullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/warning0.png", __ASSET__assets_sprites_warning0_png);
		type.set ("assets/Sprites/warning0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/window.png", __ASSET__assets_sprites_window_png);
		type.set ("assets/Sprites/window.png", AssetType.IMAGE);
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
		className.set ("assets/Sprites/youmuALT0.png", __ASSET__assets_sprites_youmualt0_png);
		type.set ("assets/Sprites/youmuALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yukariALT0.png", __ASSET__assets_sprites_yukarialt0_png);
		type.set ("assets/Sprites/yukariALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yukaribullet0.png", __ASSET__assets_sprites_yukaribullet0_png);
		type.set ("assets/Sprites/yukaribullet0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/yuyukoALT0.png", __ASSET__assets_sprites_yuyukoalt0_png);
		type.set ("assets/Sprites/yuyukoALT0.png", AssetType.IMAGE);
		className.set ("assets/Sprites/zombiefairy0.png", __ASSET__assets_sprites_zombiefairy0_png);
		type.set ("assets/Sprites/zombiefairy0.png", AssetType.IMAGE);
		className.set ("libraries/Char/Char.swf", __ASSET__libraries_char_char_swf);
		type.set ("libraries/Char/Char.swf", AssetType.BINARY);
		className.set ("libraries/Char.json", __ASSET__libraries_char_json);
		type.set ("libraries/Char.json", AssetType.TEXT);
		className.set ("libraries/Background/Background.swf", __ASSET__libraries_background_background_swf);
		type.set ("libraries/Background/Background.swf", AssetType.BINARY);
		className.set ("libraries/Background.json", __ASSET__libraries_background_json);
		type.set ("libraries/Background.json", AssetType.TEXT);
		
		
		#elseif html5
		
		var id;
		id = "assets/Audio/Mp3/adv1.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/adv2.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/adv2intro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/adv3.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/adv3intro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/adv4.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/adv5.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/adv6.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/anchor.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/bonk.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/cancel.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/cash.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/characterselect.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/click.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/collectcoin.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/customize.mp3";
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
		id = "assets/Audio/Mp3/explode.mp3";
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
		id = "assets/Audio/Mp3/getbonus.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/itemspawn.mp3";
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
		id = "assets/Audio/Mp3/ok.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/options.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/optionsintro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/pow.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/powerdown.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/powerup.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/respawn.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/se_tan01.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/shop.mp3";
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
		id = "assets/Audio/Mp3/summonufo.mp3";
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
		id = "assets/Audio/Mp3/titlescreenintro.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/ufochange.mp3";
		path.set (id, id);
		
		type.set (id, AssetType.MUSIC);
		id = "assets/Audio/Mp3/ufoitem.mp3";
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
		id = "assets/Sprites/anchor0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Arrow0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ayana0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/balloon0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/balloon1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/balloon2.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/balloon3.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/balloon4.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bananapeel0.png";
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
		id = "assets/Sprites/bhina0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/black0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/blackhole0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Blackufo0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/block0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bluebird.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bluelaser0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Blueufo0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bomb0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Boomerang0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Bow0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/bullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/camera0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/charblock0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/chenALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/chest.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/cloud0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/cross0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/CSBack0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/CSFront0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/darkness0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/deathcirno0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/diosakuya0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/diosakuyaALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/disc0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/disc1.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/disc2.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/dresser.png";
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
		id = "assets/Sprites/Emokou0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Emokouflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/emptyblock0.png";
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
		id = "assets/Sprites/energywave.png";
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
		id = "assets/Sprites/exclamationblock.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/exclamationmark.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/exkeine0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/explosion0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Explosive0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/firecirno0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/flag0.png";
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
		id = "assets/Sprites/flandreALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Gap0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Greenufo0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hairdye0.png";
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
		id = "assets/Sprites/heartbullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hecatiae0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hecatiaeflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/hecatiam0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/icebullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/icecube0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/icyblock0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ikuikudance0.png";
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
		id = "assets/Sprites/komachiALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lbullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lightning0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/lightsword.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/logo.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/matenshi0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/meilingsleeping0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/meilingsleepingflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mika0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/minihakkero0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mirror.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/money0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/MoonRabbit0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/MoonRabbitflipped0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/mrghosty0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/murasabullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/myon0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/noroiko0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/notepad0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/parseebullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/patchouliALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/pbullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/pika0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/pmusicnote0.png";
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
		id = "assets/Sprites/powerup0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/preisenbullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/present0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/prinny0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/questionblock0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/ranALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Redufo0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/remiliaALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rock.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/Roukanken0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/rumiaALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/SanaeStick0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sawblade0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/scythe0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sekibankihead0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sekibankiheadless0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/senkou0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/shingyokuorb0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/skull0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/spectrum0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/spellcard0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/spiderweb0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/starbulletg0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/starbullety0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/starorb0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/suwakohat0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/suwakohoop0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/sword0.png";
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
		id = "assets/Sprites/teacup0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/telephonepole0.png";
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
		id = "assets/Sprites/unused0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/unzanfist0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/utsuhobullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/warning0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/window.png";
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
		id = "assets/Sprites/youmuALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yukariALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yukaribullet0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/yuyukoALT0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "assets/Sprites/zombiefairy0.png";
		path.set (id, id);
		
		type.set (id, AssetType.IMAGE);
		id = "libraries/Char/Char.swf";
		path.set (id, id);
		
		type.set (id, AssetType.BINARY);
		id = "libraries/Char.json";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		id = "libraries/Background/Background.swf";
		path.set (id, id);
		
		type.set (id, AssetType.BINARY);
		id = "libraries/Background.json";
		path.set (id, id);
		
		type.set (id, AssetType.TEXT);
		
		
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
		
		className.set ("assets/Audio/Mp3/adv1.mp3", __ASSET__assets_audio_mp3_adv1_mp3);
		type.set ("assets/Audio/Mp3/adv1.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/adv2.mp3", __ASSET__assets_audio_mp3_adv2_mp3);
		type.set ("assets/Audio/Mp3/adv2.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/adv2intro.mp3", __ASSET__assets_audio_mp3_adv2intro_mp3);
		type.set ("assets/Audio/Mp3/adv2intro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/adv3.mp3", __ASSET__assets_audio_mp3_adv3_mp3);
		type.set ("assets/Audio/Mp3/adv3.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/adv3intro.mp3", __ASSET__assets_audio_mp3_adv3intro_mp3);
		type.set ("assets/Audio/Mp3/adv3intro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/adv4.mp3", __ASSET__assets_audio_mp3_adv4_mp3);
		type.set ("assets/Audio/Mp3/adv4.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/adv5.mp3", __ASSET__assets_audio_mp3_adv5_mp3);
		type.set ("assets/Audio/Mp3/adv5.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/adv6.mp3", __ASSET__assets_audio_mp3_adv6_mp3);
		type.set ("assets/Audio/Mp3/adv6.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/anchor.mp3", __ASSET__assets_audio_mp3_anchor_mp3);
		type.set ("assets/Audio/Mp3/anchor.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/bonk.mp3", __ASSET__assets_audio_mp3_bonk_mp3);
		type.set ("assets/Audio/Mp3/bonk.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/cancel.mp3", __ASSET__assets_audio_mp3_cancel_mp3);
		type.set ("assets/Audio/Mp3/cancel.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/cash.mp3", __ASSET__assets_audio_mp3_cash_mp3);
		type.set ("assets/Audio/Mp3/cash.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/characterselect.mp3", __ASSET__assets_audio_mp3_characterselect_mp3);
		type.set ("assets/Audio/Mp3/characterselect.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/click.mp3", __ASSET__assets_audio_mp3_click_mp3);
		type.set ("assets/Audio/Mp3/click.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/collectcoin.mp3", __ASSET__assets_audio_mp3_collectcoin_mp3);
		type.set ("assets/Audio/Mp3/collectcoin.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/customize.mp3", __ASSET__assets_audio_mp3_customize_mp3);
		type.set ("assets/Audio/Mp3/customize.mp3", AssetType.MUSIC);
		
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
		
		className.set ("assets/Audio/Mp3/explode.mp3", __ASSET__assets_audio_mp3_explode_mp3);
		type.set ("assets/Audio/Mp3/explode.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/extend.mp3", __ASSET__assets_audio_mp3_extend_mp3);
		type.set ("assets/Audio/Mp3/extend.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/finalkill.mp3", __ASSET__assets_audio_mp3_finalkill_mp3);
		type.set ("assets/Audio/Mp3/finalkill.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/fireballspawn.mp3", __ASSET__assets_audio_mp3_fireballspawn_mp3);
		type.set ("assets/Audio/Mp3/fireballspawn.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/gameover.mp3", __ASSET__assets_audio_mp3_gameover_mp3);
		type.set ("assets/Audio/Mp3/gameover.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/getbonus.mp3", __ASSET__assets_audio_mp3_getbonus_mp3);
		type.set ("assets/Audio/Mp3/getbonus.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/itemspawn.mp3", __ASSET__assets_audio_mp3_itemspawn_mp3);
		type.set ("assets/Audio/Mp3/itemspawn.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/killenemy.mp3", __ASSET__assets_audio_mp3_killenemy_mp3);
		type.set ("assets/Audio/Mp3/killenemy.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/masterspark.mp3", __ASSET__assets_audio_mp3_masterspark_mp3);
		type.set ("assets/Audio/Mp3/masterspark.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/nextlevel.mp3", __ASSET__assets_audio_mp3_nextlevel_mp3);
		type.set ("assets/Audio/Mp3/nextlevel.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/ok.mp3", __ASSET__assets_audio_mp3_ok_mp3);
		type.set ("assets/Audio/Mp3/ok.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/options.mp3", __ASSET__assets_audio_mp3_options_mp3);
		type.set ("assets/Audio/Mp3/options.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/optionsintro.mp3", __ASSET__assets_audio_mp3_optionsintro_mp3);
		type.set ("assets/Audio/Mp3/optionsintro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/pow.mp3", __ASSET__assets_audio_mp3_pow_mp3);
		type.set ("assets/Audio/Mp3/pow.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/powerdown.mp3", __ASSET__assets_audio_mp3_powerdown_mp3);
		type.set ("assets/Audio/Mp3/powerdown.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/powerup.mp3", __ASSET__assets_audio_mp3_powerup_mp3);
		type.set ("assets/Audio/Mp3/powerup.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/respawn.mp3", __ASSET__assets_audio_mp3_respawn_mp3);
		type.set ("assets/Audio/Mp3/respawn.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/se_tan01.mp3", __ASSET__assets_audio_mp3_se_tan01_mp3);
		type.set ("assets/Audio/Mp3/se_tan01.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/shop.mp3", __ASSET__assets_audio_mp3_shop_mp3);
		type.set ("assets/Audio/Mp3/shop.mp3", AssetType.MUSIC);
		
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
		
		className.set ("assets/Audio/Mp3/summonufo.mp3", __ASSET__assets_audio_mp3_summonufo_mp3);
		type.set ("assets/Audio/Mp3/summonufo.mp3", AssetType.MUSIC);
		
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
		
		className.set ("assets/Audio/Mp3/titlescreenintro.mp3", __ASSET__assets_audio_mp3_titlescreenintro_mp3);
		type.set ("assets/Audio/Mp3/titlescreenintro.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/ufochange.mp3", __ASSET__assets_audio_mp3_ufochange_mp3);
		type.set ("assets/Audio/Mp3/ufochange.mp3", AssetType.MUSIC);
		
		className.set ("assets/Audio/Mp3/ufoitem.mp3", __ASSET__assets_audio_mp3_ufoitem_mp3);
		type.set ("assets/Audio/Mp3/ufoitem.mp3", AssetType.MUSIC);
		
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
		
		className.set ("assets/Sprites/anchor0.png", __ASSET__assets_sprites_anchor0_png);
		type.set ("assets/Sprites/anchor0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Arrow0.png", __ASSET__assets_sprites_arrow0_png);
		type.set ("assets/Sprites/Arrow0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ayana0.png", __ASSET__assets_sprites_ayana0_png);
		type.set ("assets/Sprites/ayana0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/balloon0.png", __ASSET__assets_sprites_balloon0_png);
		type.set ("assets/Sprites/balloon0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/balloon1.png", __ASSET__assets_sprites_balloon1_png);
		type.set ("assets/Sprites/balloon1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/balloon2.png", __ASSET__assets_sprites_balloon2_png);
		type.set ("assets/Sprites/balloon2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/balloon3.png", __ASSET__assets_sprites_balloon3_png);
		type.set ("assets/Sprites/balloon3.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/balloon4.png", __ASSET__assets_sprites_balloon4_png);
		type.set ("assets/Sprites/balloon4.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bananapeel0.png", __ASSET__assets_sprites_bananapeel0_png);
		type.set ("assets/Sprites/bananapeel0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/barrier0.png", __ASSET__assets_sprites_barrier0_png);
		type.set ("assets/Sprites/barrier0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bat0.png", __ASSET__assets_sprites_bat0_png);
		type.set ("assets/Sprites/bat0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bat1.png", __ASSET__assets_sprites_bat1_png);
		type.set ("assets/Sprites/bat1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bhina0.png", __ASSET__assets_sprites_bhina0_png);
		type.set ("assets/Sprites/bhina0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/black0.png", __ASSET__assets_sprites_black0_png);
		type.set ("assets/Sprites/black0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/blackhole0.png", __ASSET__assets_sprites_blackhole0_png);
		type.set ("assets/Sprites/blackhole0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Blackufo0.png", __ASSET__assets_sprites_blackufo0_png);
		type.set ("assets/Sprites/Blackufo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/block0.png", __ASSET__assets_sprites_block0_png);
		type.set ("assets/Sprites/block0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bluebird.png", __ASSET__assets_sprites_bluebird_png);
		type.set ("assets/Sprites/bluebird.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bluelaser0.png", __ASSET__assets_sprites_bluelaser0_png);
		type.set ("assets/Sprites/bluelaser0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Blueufo0.png", __ASSET__assets_sprites_blueufo0_png);
		type.set ("assets/Sprites/Blueufo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bomb0.png", __ASSET__assets_sprites_bomb0_png);
		type.set ("assets/Sprites/bomb0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Boomerang0.png", __ASSET__assets_sprites_boomerang0_png);
		type.set ("assets/Sprites/Boomerang0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Bow0.png", __ASSET__assets_sprites_bow0_png);
		type.set ("assets/Sprites/Bow0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/bullet0.png", __ASSET__assets_sprites_bullet0_png);
		type.set ("assets/Sprites/bullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/camera0.png", __ASSET__assets_sprites_camera0_png);
		type.set ("assets/Sprites/camera0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/charblock0.png", __ASSET__assets_sprites_charblock0_png);
		type.set ("assets/Sprites/charblock0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/chenALT0.png", __ASSET__assets_sprites_chenalt0_png);
		type.set ("assets/Sprites/chenALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/chest.png", __ASSET__assets_sprites_chest_png);
		type.set ("assets/Sprites/chest.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/cloud0.png", __ASSET__assets_sprites_cloud0_png);
		type.set ("assets/Sprites/cloud0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/cross0.png", __ASSET__assets_sprites_cross0_png);
		type.set ("assets/Sprites/cross0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/CSBack0.png", __ASSET__assets_sprites_csback0_png);
		type.set ("assets/Sprites/CSBack0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/CSFront0.png", __ASSET__assets_sprites_csfront0_png);
		type.set ("assets/Sprites/CSFront0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/darkness0.png", __ASSET__assets_sprites_darkness0_png);
		type.set ("assets/Sprites/darkness0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/deathcirno0.png", __ASSET__assets_sprites_deathcirno0_png);
		type.set ("assets/Sprites/deathcirno0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/diosakuya0.png", __ASSET__assets_sprites_diosakuya0_png);
		type.set ("assets/Sprites/diosakuya0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/diosakuyaALT0.png", __ASSET__assets_sprites_diosakuyaalt0_png);
		type.set ("assets/Sprites/diosakuyaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/disc0.png", __ASSET__assets_sprites_disc0_png);
		type.set ("assets/Sprites/disc0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/disc1.png", __ASSET__assets_sprites_disc1_png);
		type.set ("assets/Sprites/disc1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/disc2.png", __ASSET__assets_sprites_disc2_png);
		type.set ("assets/Sprites/disc2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/dresser.png", __ASSET__assets_sprites_dresser_png);
		type.set ("assets/Sprites/dresser.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/Emokou0.png", __ASSET__assets_sprites_emokou0_png);
		type.set ("assets/Sprites/Emokou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Emokouflipped0.png", __ASSET__assets_sprites_emokouflipped0_png);
		type.set ("assets/Sprites/Emokouflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/emptyblock0.png", __ASSET__assets_sprites_emptyblock0_png);
		type.set ("assets/Sprites/emptyblock0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EMystia0.png", __ASSET__assets_sprites_emystia0_png);
		type.set ("assets/Sprites/EMystia0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EMystia1.png", __ASSET__assets_sprites_emystia1_png);
		type.set ("assets/Sprites/EMystia1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/EMystiaflipped0.png", __ASSET__assets_sprites_emystiaflipped0_png);
		type.set ("assets/Sprites/EMystiaflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/energywave.png", __ASSET__assets_sprites_energywave_png);
		type.set ("assets/Sprites/energywave.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/exclamationblock.png", __ASSET__assets_sprites_exclamationblock_png);
		type.set ("assets/Sprites/exclamationblock.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/exclamationmark.png", __ASSET__assets_sprites_exclamationmark_png);
		type.set ("assets/Sprites/exclamationmark.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/exkeine0.png", __ASSET__assets_sprites_exkeine0_png);
		type.set ("assets/Sprites/exkeine0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/explosion0.png", __ASSET__assets_sprites_explosion0_png);
		type.set ("assets/Sprites/explosion0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Explosive0.png", __ASSET__assets_sprites_explosive0_png);
		type.set ("assets/Sprites/Explosive0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/firecirno0.png", __ASSET__assets_sprites_firecirno0_png);
		type.set ("assets/Sprites/firecirno0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flag0.png", __ASSET__assets_sprites_flag0_png);
		type.set ("assets/Sprites/flag0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flames0.png", __ASSET__assets_sprites_flames0_png);
		type.set ("assets/Sprites/flames0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flames1.png", __ASSET__assets_sprites_flames1_png);
		type.set ("assets/Sprites/flames1.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flames2.png", __ASSET__assets_sprites_flames2_png);
		type.set ("assets/Sprites/flames2.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/flandreALT0.png", __ASSET__assets_sprites_flandrealt0_png);
		type.set ("assets/Sprites/flandreALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Gap0.png", __ASSET__assets_sprites_gap0_png);
		type.set ("assets/Sprites/Gap0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Greenufo0.png", __ASSET__assets_sprites_greenufo0_png);
		type.set ("assets/Sprites/Greenufo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hairdye0.png", __ASSET__assets_sprites_hairdye0_png);
		type.set ("assets/Sprites/hairdye0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/heartbullet0.png", __ASSET__assets_sprites_heartbullet0_png);
		type.set ("assets/Sprites/heartbullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hecatiae0.png", __ASSET__assets_sprites_hecatiae0_png);
		type.set ("assets/Sprites/hecatiae0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hecatiaeflipped0.png", __ASSET__assets_sprites_hecatiaeflipped0_png);
		type.set ("assets/Sprites/hecatiaeflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/hecatiam0.png", __ASSET__assets_sprites_hecatiam0_png);
		type.set ("assets/Sprites/hecatiam0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/icebullet0.png", __ASSET__assets_sprites_icebullet0_png);
		type.set ("assets/Sprites/icebullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/icecube0.png", __ASSET__assets_sprites_icecube0_png);
		type.set ("assets/Sprites/icecube0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/icyblock0.png", __ASSET__assets_sprites_icyblock0_png);
		type.set ("assets/Sprites/icyblock0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ikuikudance0.png", __ASSET__assets_sprites_ikuikudance0_png);
		type.set ("assets/Sprites/ikuikudance0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/komachiALT0.png", __ASSET__assets_sprites_komachialt0_png);
		type.set ("assets/Sprites/komachiALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lbullet0.png", __ASSET__assets_sprites_lbullet0_png);
		type.set ("assets/Sprites/lbullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lightning0.png", __ASSET__assets_sprites_lightning0_png);
		type.set ("assets/Sprites/lightning0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/lightsword.png", __ASSET__assets_sprites_lightsword_png);
		type.set ("assets/Sprites/lightsword.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/logo.png", __ASSET__assets_sprites_logo_png);
		type.set ("assets/Sprites/logo.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/matenshi0.png", __ASSET__assets_sprites_matenshi0_png);
		type.set ("assets/Sprites/matenshi0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/meilingsleeping0.png", __ASSET__assets_sprites_meilingsleeping0_png);
		type.set ("assets/Sprites/meilingsleeping0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/meilingsleepingflipped0.png", __ASSET__assets_sprites_meilingsleepingflipped0_png);
		type.set ("assets/Sprites/meilingsleepingflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mika0.png", __ASSET__assets_sprites_mika0_png);
		type.set ("assets/Sprites/mika0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/minihakkero0.png", __ASSET__assets_sprites_minihakkero0_png);
		type.set ("assets/Sprites/minihakkero0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mirror.png", __ASSET__assets_sprites_mirror_png);
		type.set ("assets/Sprites/mirror.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/money0.png", __ASSET__assets_sprites_money0_png);
		type.set ("assets/Sprites/money0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/MoonRabbit0.png", __ASSET__assets_sprites_moonrabbit0_png);
		type.set ("assets/Sprites/MoonRabbit0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/MoonRabbitflipped0.png", __ASSET__assets_sprites_moonrabbitflipped0_png);
		type.set ("assets/Sprites/MoonRabbitflipped0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/mrghosty0.png", __ASSET__assets_sprites_mrghosty0_png);
		type.set ("assets/Sprites/mrghosty0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/murasabullet0.png", __ASSET__assets_sprites_murasabullet0_png);
		type.set ("assets/Sprites/murasabullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/myon0.png", __ASSET__assets_sprites_myon0_png);
		type.set ("assets/Sprites/myon0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/noroiko0.png", __ASSET__assets_sprites_noroiko0_png);
		type.set ("assets/Sprites/noroiko0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/notepad0.png", __ASSET__assets_sprites_notepad0_png);
		type.set ("assets/Sprites/notepad0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/parseebullet0.png", __ASSET__assets_sprites_parseebullet0_png);
		type.set ("assets/Sprites/parseebullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/patchouliALT0.png", __ASSET__assets_sprites_patchoulialt0_png);
		type.set ("assets/Sprites/patchouliALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/pbullet0.png", __ASSET__assets_sprites_pbullet0_png);
		type.set ("assets/Sprites/pbullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/pika0.png", __ASSET__assets_sprites_pika0_png);
		type.set ("assets/Sprites/pika0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/pmusicnote0.png", __ASSET__assets_sprites_pmusicnote0_png);
		type.set ("assets/Sprites/pmusicnote0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Point0.png", __ASSET__assets_sprites_point0_png);
		type.set ("assets/Sprites/Point0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/poisoncloud0.png", __ASSET__assets_sprites_poisoncloud0_png);
		type.set ("assets/Sprites/poisoncloud0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/POW0.png", __ASSET__assets_sprites_pow0_png);
		type.set ("assets/Sprites/POW0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/POWalt0.png", __ASSET__assets_sprites_powalt0_png);
		type.set ("assets/Sprites/POWalt0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/powerup0.png", __ASSET__assets_sprites_powerup0_png);
		type.set ("assets/Sprites/powerup0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/preisenbullet0.png", __ASSET__assets_sprites_preisenbullet0_png);
		type.set ("assets/Sprites/preisenbullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/present0.png", __ASSET__assets_sprites_present0_png);
		type.set ("assets/Sprites/present0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/prinny0.png", __ASSET__assets_sprites_prinny0_png);
		type.set ("assets/Sprites/prinny0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/questionblock0.png", __ASSET__assets_sprites_questionblock0_png);
		type.set ("assets/Sprites/questionblock0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/ranALT0.png", __ASSET__assets_sprites_ranalt0_png);
		type.set ("assets/Sprites/ranALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Redufo0.png", __ASSET__assets_sprites_redufo0_png);
		type.set ("assets/Sprites/Redufo0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/remiliaALT0.png", __ASSET__assets_sprites_remiliaalt0_png);
		type.set ("assets/Sprites/remiliaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/rock.png", __ASSET__assets_sprites_rock_png);
		type.set ("assets/Sprites/rock.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/Roukanken0.png", __ASSET__assets_sprites_roukanken0_png);
		type.set ("assets/Sprites/Roukanken0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/rumiaALT0.png", __ASSET__assets_sprites_rumiaalt0_png);
		type.set ("assets/Sprites/rumiaALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/SanaeStick0.png", __ASSET__assets_sprites_sanaestick0_png);
		type.set ("assets/Sprites/SanaeStick0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sawblade0.png", __ASSET__assets_sprites_sawblade0_png);
		type.set ("assets/Sprites/sawblade0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/scythe0.png", __ASSET__assets_sprites_scythe0_png);
		type.set ("assets/Sprites/scythe0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sekibankihead0.png", __ASSET__assets_sprites_sekibankihead0_png);
		type.set ("assets/Sprites/sekibankihead0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sekibankiheadless0.png", __ASSET__assets_sprites_sekibankiheadless0_png);
		type.set ("assets/Sprites/sekibankiheadless0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/senkou0.png", __ASSET__assets_sprites_senkou0_png);
		type.set ("assets/Sprites/senkou0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/shingyokuorb0.png", __ASSET__assets_sprites_shingyokuorb0_png);
		type.set ("assets/Sprites/shingyokuorb0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/skull0.png", __ASSET__assets_sprites_skull0_png);
		type.set ("assets/Sprites/skull0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/spectrum0.png", __ASSET__assets_sprites_spectrum0_png);
		type.set ("assets/Sprites/spectrum0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/spellcard0.png", __ASSET__assets_sprites_spellcard0_png);
		type.set ("assets/Sprites/spellcard0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/spiderweb0.png", __ASSET__assets_sprites_spiderweb0_png);
		type.set ("assets/Sprites/spiderweb0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/starbulletg0.png", __ASSET__assets_sprites_starbulletg0_png);
		type.set ("assets/Sprites/starbulletg0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/starbullety0.png", __ASSET__assets_sprites_starbullety0_png);
		type.set ("assets/Sprites/starbullety0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/starorb0.png", __ASSET__assets_sprites_starorb0_png);
		type.set ("assets/Sprites/starorb0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/suwakohat0.png", __ASSET__assets_sprites_suwakohat0_png);
		type.set ("assets/Sprites/suwakohat0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/suwakohoop0.png", __ASSET__assets_sprites_suwakohoop0_png);
		type.set ("assets/Sprites/suwakohoop0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/sword0.png", __ASSET__assets_sprites_sword0_png);
		type.set ("assets/Sprites/sword0.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/teacup0.png", __ASSET__assets_sprites_teacup0_png);
		type.set ("assets/Sprites/teacup0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/telephonepole0.png", __ASSET__assets_sprites_telephonepole0_png);
		type.set ("assets/Sprites/telephonepole0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/train0.png", __ASSET__assets_sprites_train0_png);
		type.set ("assets/Sprites/train0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/trophy0.png", __ASSET__assets_sprites_trophy0_png);
		type.set ("assets/Sprites/trophy0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/truck0.png", __ASSET__assets_sprites_truck0_png);
		type.set ("assets/Sprites/truck0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/unused0.png", __ASSET__assets_sprites_unused0_png);
		type.set ("assets/Sprites/unused0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/unzanfist0.png", __ASSET__assets_sprites_unzanfist0_png);
		type.set ("assets/Sprites/unzanfist0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/utsuhobullet0.png", __ASSET__assets_sprites_utsuhobullet0_png);
		type.set ("assets/Sprites/utsuhobullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/warning0.png", __ASSET__assets_sprites_warning0_png);
		type.set ("assets/Sprites/warning0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/window.png", __ASSET__assets_sprites_window_png);
		type.set ("assets/Sprites/window.png", AssetType.IMAGE);
		
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
		
		className.set ("assets/Sprites/youmuALT0.png", __ASSET__assets_sprites_youmualt0_png);
		type.set ("assets/Sprites/youmuALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yukariALT0.png", __ASSET__assets_sprites_yukarialt0_png);
		type.set ("assets/Sprites/yukariALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yukaribullet0.png", __ASSET__assets_sprites_yukaribullet0_png);
		type.set ("assets/Sprites/yukaribullet0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/yuyukoALT0.png", __ASSET__assets_sprites_yuyukoalt0_png);
		type.set ("assets/Sprites/yuyukoALT0.png", AssetType.IMAGE);
		
		className.set ("assets/Sprites/zombiefairy0.png", __ASSET__assets_sprites_zombiefairy0_png);
		type.set ("assets/Sprites/zombiefairy0.png", AssetType.IMAGE);
		
		className.set ("libraries/Char/Char.swf", __ASSET__libraries_char_char_swf);
		type.set ("libraries/Char/Char.swf", AssetType.BINARY);
		
		className.set ("libraries/Char.json", __ASSET__libraries_char_json);
		type.set ("libraries/Char.json", AssetType.TEXT);
		
		className.set ("libraries/Background/Background.swf", __ASSET__libraries_background_background_swf);
		type.set ("libraries/Background/Background.swf", AssetType.BINARY);
		
		className.set ("libraries/Background.json", __ASSET__libraries_background_json);
		type.set ("libraries/Background.json", AssetType.TEXT);
		
		
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

@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv1_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv2_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv2intro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv3_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv3intro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv4_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv5_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_adv6_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_anchor_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_bonk_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_cancel_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_cash_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_characterselect_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_click_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_collectcoin_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_customize_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_died_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum0_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum1_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum2_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum3_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_drum4_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_explode_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_extend_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_finalkill_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_fireballspawn_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_gameover_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_getbonus_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_itemspawn_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_killenemy_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_masterspark_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_nextlevel_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_ok_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_options_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_optionsintro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_pow_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_powerdown_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_powerup_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_respawn_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_se_tan01_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_shop_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_spawncoin_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_startgame_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_step1_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_step2_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_step3_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_summonufo_mp3 extends flash.media.Sound { }
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
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_titlescreenintro_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_ufochange_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_ufoitem_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_audio_mp3_zawarudo_mp3 extends flash.media.Sound { }
@:keep @:bind #if display private #end class __ASSET__assets_bgcolor_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_black_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_dpad_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_key_txt extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_1up0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_anchor0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_arrow0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ayana0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_balloon0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_balloon1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_balloon2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_balloon3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_balloon4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bananapeel0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_barrier0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bat0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bat1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bhina0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_black0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_blackhole0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_blackufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_block0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bluebird_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bluelaser0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_blueufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bomb0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_boomerang0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bow0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_bullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_camera0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_charblock0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_chenalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_chest_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_cloud0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_cross0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_csback0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_csfront0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_darkness0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_deathcirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_diosakuya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_diosakuyaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_disc0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_disc1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_disc2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_dresser_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekaguya0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekaguyaflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeineex0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ekeineexflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_electriccirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emokou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emokouflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emptyblock0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emystia0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emystia1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_emystiaflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_energywave_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_exclamationblock_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_exclamationmark_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_exkeine0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_explosion0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_explosive0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_firecirno0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flag0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flames2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_flandrealt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_gap0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_greenufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hairdye0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_heartbullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hecatiae0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hecatiaeflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_hecatiam0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_icebullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_icecube0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_icyblock0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ikuikudance0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_keystone0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife1_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife2_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife3_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife4_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife5_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife6_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_knife7_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_komachialt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lbullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lightning0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_lightsword_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_logo_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_matenshi0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meilingsleeping0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_meilingsleepingflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_minihakkero0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mirror_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_money0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_moonrabbit0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_moonrabbitflipped0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_mrghosty0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_murasabullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_myon0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_noroiko0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_notepad0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_parseebullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_patchoulialt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pbullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pika0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pmusicnote0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_point0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_poisoncloud0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_pow0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_powalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_powerup0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_preisenbullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_present0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_prinny0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_questionblock0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_ranalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_redufo0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_remiliaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rock_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_roukanken0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_rumiaalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sanaestick0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sawblade0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_scythe0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sekibankihead0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sekibankiheadless0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_senkou0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_shingyokuorb0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_skull0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_spectrum0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_spellcard0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_spiderweb0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_starbulletg0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_starbullety0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_starorb0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_suwakohat0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_suwakohoop0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_sword0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_teacup0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_telephonepole0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_train0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_trophy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_truck0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_unused0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_unzanfist0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_utsuhobullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_warning0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_window_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
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
@:keep @:bind #if display private #end class __ASSET__assets_sprites_youmualt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yukarialt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yukaribullet0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_yuyukoalt0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__assets_sprites_zombiefairy0_png extends flash.display.BitmapData { public function new () { super (0, 0, true, 0); } }
@:keep @:bind #if display private #end class __ASSET__libraries_char_char_swf extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__libraries_char_json extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__libraries_background_background_swf extends flash.utils.ByteArray { }
@:keep @:bind #if display private #end class __ASSET__libraries_background_json extends flash.utils.ByteArray { }


#elseif html5
































































































































































































































































































































#else



#if (windows || mac || linux)


@:file("Assets/Audio/Mp3/adv1.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv1_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/adv2.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv2_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/adv2intro.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv2intro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/adv3.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv3_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/adv3intro.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv3intro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/adv4.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv4_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/adv5.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv5_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/adv6.mp3") #if display private #end class __ASSET__assets_audio_mp3_adv6_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/anchor.mp3") #if display private #end class __ASSET__assets_audio_mp3_anchor_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/bonk.mp3") #if display private #end class __ASSET__assets_audio_mp3_bonk_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/cancel.mp3") #if display private #end class __ASSET__assets_audio_mp3_cancel_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/cash.mp3") #if display private #end class __ASSET__assets_audio_mp3_cash_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/characterselect.mp3") #if display private #end class __ASSET__assets_audio_mp3_characterselect_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/click.mp3") #if display private #end class __ASSET__assets_audio_mp3_click_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/collectcoin.mp3") #if display private #end class __ASSET__assets_audio_mp3_collectcoin_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/customize.mp3") #if display private #end class __ASSET__assets_audio_mp3_customize_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/died.mp3") #if display private #end class __ASSET__assets_audio_mp3_died_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum0.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum0_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum1.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum1_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum2.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum2_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum3.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum3_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/drum4.mp3") #if display private #end class __ASSET__assets_audio_mp3_drum4_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/explode.mp3") #if display private #end class __ASSET__assets_audio_mp3_explode_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/extend.mp3") #if display private #end class __ASSET__assets_audio_mp3_extend_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/finalkill.mp3") #if display private #end class __ASSET__assets_audio_mp3_finalkill_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/fireballspawn.mp3") #if display private #end class __ASSET__assets_audio_mp3_fireballspawn_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/gameover.mp3") #if display private #end class __ASSET__assets_audio_mp3_gameover_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/getbonus.mp3") #if display private #end class __ASSET__assets_audio_mp3_getbonus_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/itemspawn.mp3") #if display private #end class __ASSET__assets_audio_mp3_itemspawn_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/killenemy.mp3") #if display private #end class __ASSET__assets_audio_mp3_killenemy_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/masterspark.mp3") #if display private #end class __ASSET__assets_audio_mp3_masterspark_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/nextlevel.mp3") #if display private #end class __ASSET__assets_audio_mp3_nextlevel_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/ok.mp3") #if display private #end class __ASSET__assets_audio_mp3_ok_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/options.mp3") #if display private #end class __ASSET__assets_audio_mp3_options_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/optionsintro.mp3") #if display private #end class __ASSET__assets_audio_mp3_optionsintro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/pow.mp3") #if display private #end class __ASSET__assets_audio_mp3_pow_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/powerdown.mp3") #if display private #end class __ASSET__assets_audio_mp3_powerdown_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/powerup.mp3") #if display private #end class __ASSET__assets_audio_mp3_powerup_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/respawn.mp3") #if display private #end class __ASSET__assets_audio_mp3_respawn_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/se_tan01.mp3") #if display private #end class __ASSET__assets_audio_mp3_se_tan01_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/shop.mp3") #if display private #end class __ASSET__assets_audio_mp3_shop_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/spawncoin.mp3") #if display private #end class __ASSET__assets_audio_mp3_spawncoin_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/startgame.mp3") #if display private #end class __ASSET__assets_audio_mp3_startgame_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/step1.mp3") #if display private #end class __ASSET__assets_audio_mp3_step1_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/step2.mp3") #if display private #end class __ASSET__assets_audio_mp3_step2_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/step3.mp3") #if display private #end class __ASSET__assets_audio_mp3_step3_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/summonufo.mp3") #if display private #end class __ASSET__assets_audio_mp3_summonufo_mp3 extends lime.utils.ByteArray {}
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
@:file("Assets/Audio/Mp3/titlescreenintro.mp3") #if display private #end class __ASSET__assets_audio_mp3_titlescreenintro_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/ufochange.mp3") #if display private #end class __ASSET__assets_audio_mp3_ufochange_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/ufoitem.mp3") #if display private #end class __ASSET__assets_audio_mp3_ufoitem_mp3 extends lime.utils.ByteArray {}
@:file("Assets/Audio/Mp3/zawarudo.mp3") #if display private #end class __ASSET__assets_audio_mp3_zawarudo_mp3 extends lime.utils.ByteArray {}
@:image("Assets/bgcolor.png") #if display private #end class __ASSET__assets_bgcolor_png extends lime.graphics.Image {}
@:image("Assets/black.png") #if display private #end class __ASSET__assets_black_png extends lime.graphics.Image {}
@:image("Assets/Dpad.png") #if display private #end class __ASSET__assets_dpad_png extends lime.graphics.Image {}
@:file("Assets/Key.txt") #if display private #end class __ASSET__assets_key_txt extends lime.utils.ByteArray {}
@:image("Assets/Sprites/1up0.png") #if display private #end class __ASSET__assets_sprites_1up0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/anchor0.png") #if display private #end class __ASSET__assets_sprites_anchor0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Arrow0.png") #if display private #end class __ASSET__assets_sprites_arrow0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ayana0.png") #if display private #end class __ASSET__assets_sprites_ayana0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/balloon0.png") #if display private #end class __ASSET__assets_sprites_balloon0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/balloon1.png") #if display private #end class __ASSET__assets_sprites_balloon1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/balloon2.png") #if display private #end class __ASSET__assets_sprites_balloon2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/balloon3.png") #if display private #end class __ASSET__assets_sprites_balloon3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/balloon4.png") #if display private #end class __ASSET__assets_sprites_balloon4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bananapeel0.png") #if display private #end class __ASSET__assets_sprites_bananapeel0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/barrier0.png") #if display private #end class __ASSET__assets_sprites_barrier0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bat0.png") #if display private #end class __ASSET__assets_sprites_bat0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bat1.png") #if display private #end class __ASSET__assets_sprites_bat1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bhina0.png") #if display private #end class __ASSET__assets_sprites_bhina0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/black0.png") #if display private #end class __ASSET__assets_sprites_black0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/blackhole0.png") #if display private #end class __ASSET__assets_sprites_blackhole0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Blackufo0.png") #if display private #end class __ASSET__assets_sprites_blackufo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/block0.png") #if display private #end class __ASSET__assets_sprites_block0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bluebird.png") #if display private #end class __ASSET__assets_sprites_bluebird_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bluelaser0.png") #if display private #end class __ASSET__assets_sprites_bluelaser0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Blueufo0.png") #if display private #end class __ASSET__assets_sprites_blueufo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bomb0.png") #if display private #end class __ASSET__assets_sprites_bomb0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Boomerang0.png") #if display private #end class __ASSET__assets_sprites_boomerang0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Bow0.png") #if display private #end class __ASSET__assets_sprites_bow0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/bullet0.png") #if display private #end class __ASSET__assets_sprites_bullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/camera0.png") #if display private #end class __ASSET__assets_sprites_camera0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/charblock0.png") #if display private #end class __ASSET__assets_sprites_charblock0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/chenALT0.png") #if display private #end class __ASSET__assets_sprites_chenalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/chest.png") #if display private #end class __ASSET__assets_sprites_chest_png extends lime.graphics.Image {}
@:image("Assets/Sprites/cloud0.png") #if display private #end class __ASSET__assets_sprites_cloud0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/cross0.png") #if display private #end class __ASSET__assets_sprites_cross0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/CSBack0.png") #if display private #end class __ASSET__assets_sprites_csback0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/CSFront0.png") #if display private #end class __ASSET__assets_sprites_csfront0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/darkness0.png") #if display private #end class __ASSET__assets_sprites_darkness0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/deathcirno0.png") #if display private #end class __ASSET__assets_sprites_deathcirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/diosakuya0.png") #if display private #end class __ASSET__assets_sprites_diosakuya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/diosakuyaALT0.png") #if display private #end class __ASSET__assets_sprites_diosakuyaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/disc0.png") #if display private #end class __ASSET__assets_sprites_disc0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/disc1.png") #if display private #end class __ASSET__assets_sprites_disc1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/disc2.png") #if display private #end class __ASSET__assets_sprites_disc2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/dresser.png") #if display private #end class __ASSET__assets_sprites_dresser_png extends lime.graphics.Image {}
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
@:image("Assets/Sprites/Ekaguya0.png") #if display private #end class __ASSET__assets_sprites_ekaguya0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Ekaguyaflipped0.png") #if display private #end class __ASSET__assets_sprites_ekaguyaflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EKeine0.png") #if display private #end class __ASSET__assets_sprites_ekeine0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EKeineex0.png") #if display private #end class __ASSET__assets_sprites_ekeineex0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EKeineexflipped0.png") #if display private #end class __ASSET__assets_sprites_ekeineexflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/electriccirno0.png") #if display private #end class __ASSET__assets_sprites_electriccirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Emokou0.png") #if display private #end class __ASSET__assets_sprites_emokou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Emokouflipped0.png") #if display private #end class __ASSET__assets_sprites_emokouflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/emptyblock0.png") #if display private #end class __ASSET__assets_sprites_emptyblock0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EMystia0.png") #if display private #end class __ASSET__assets_sprites_emystia0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EMystia1.png") #if display private #end class __ASSET__assets_sprites_emystia1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/EMystiaflipped0.png") #if display private #end class __ASSET__assets_sprites_emystiaflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/energywave.png") #if display private #end class __ASSET__assets_sprites_energywave_png extends lime.graphics.Image {}
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
@:image("Assets/Sprites/exclamationblock.png") #if display private #end class __ASSET__assets_sprites_exclamationblock_png extends lime.graphics.Image {}
@:image("Assets/Sprites/exclamationmark.png") #if display private #end class __ASSET__assets_sprites_exclamationmark_png extends lime.graphics.Image {}
@:image("Assets/Sprites/exkeine0.png") #if display private #end class __ASSET__assets_sprites_exkeine0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/explosion0.png") #if display private #end class __ASSET__assets_sprites_explosion0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Explosive0.png") #if display private #end class __ASSET__assets_sprites_explosive0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/firecirno0.png") #if display private #end class __ASSET__assets_sprites_firecirno0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flag0.png") #if display private #end class __ASSET__assets_sprites_flag0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flames0.png") #if display private #end class __ASSET__assets_sprites_flames0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flames1.png") #if display private #end class __ASSET__assets_sprites_flames1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flames2.png") #if display private #end class __ASSET__assets_sprites_flames2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/flandreALT0.png") #if display private #end class __ASSET__assets_sprites_flandrealt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Gap0.png") #if display private #end class __ASSET__assets_sprites_gap0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Greenufo0.png") #if display private #end class __ASSET__assets_sprites_greenufo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hairdye0.png") #if display private #end class __ASSET__assets_sprites_hairdye0_png extends lime.graphics.Image {}
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
@:image("Assets/Sprites/heartbullet0.png") #if display private #end class __ASSET__assets_sprites_heartbullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hecatiae0.png") #if display private #end class __ASSET__assets_sprites_hecatiae0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hecatiaeflipped0.png") #if display private #end class __ASSET__assets_sprites_hecatiaeflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/hecatiam0.png") #if display private #end class __ASSET__assets_sprites_hecatiam0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/icebullet0.png") #if display private #end class __ASSET__assets_sprites_icebullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/icecube0.png") #if display private #end class __ASSET__assets_sprites_icecube0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/icyblock0.png") #if display private #end class __ASSET__assets_sprites_icyblock0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ikuikudance0.png") #if display private #end class __ASSET__assets_sprites_ikuikudance0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/keystone0.png") #if display private #end class __ASSET__assets_sprites_keystone0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife0.png") #if display private #end class __ASSET__assets_sprites_knife0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife1.png") #if display private #end class __ASSET__assets_sprites_knife1_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife2.png") #if display private #end class __ASSET__assets_sprites_knife2_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife3.png") #if display private #end class __ASSET__assets_sprites_knife3_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife4.png") #if display private #end class __ASSET__assets_sprites_knife4_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife5.png") #if display private #end class __ASSET__assets_sprites_knife5_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife6.png") #if display private #end class __ASSET__assets_sprites_knife6_png extends lime.graphics.Image {}
@:image("Assets/Sprites/knife7.png") #if display private #end class __ASSET__assets_sprites_knife7_png extends lime.graphics.Image {}
@:image("Assets/Sprites/komachiALT0.png") #if display private #end class __ASSET__assets_sprites_komachialt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lbullet0.png") #if display private #end class __ASSET__assets_sprites_lbullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lightning0.png") #if display private #end class __ASSET__assets_sprites_lightning0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/lightsword.png") #if display private #end class __ASSET__assets_sprites_lightsword_png extends lime.graphics.Image {}
@:image("Assets/Sprites/logo.png") #if display private #end class __ASSET__assets_sprites_logo_png extends lime.graphics.Image {}
@:image("Assets/Sprites/matenshi0.png") #if display private #end class __ASSET__assets_sprites_matenshi0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meilingsleeping0.png") #if display private #end class __ASSET__assets_sprites_meilingsleeping0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/meilingsleepingflipped0.png") #if display private #end class __ASSET__assets_sprites_meilingsleepingflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mika0.png") #if display private #end class __ASSET__assets_sprites_mika0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/minihakkero0.png") #if display private #end class __ASSET__assets_sprites_minihakkero0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mirror.png") #if display private #end class __ASSET__assets_sprites_mirror_png extends lime.graphics.Image {}
@:image("Assets/Sprites/money0.png") #if display private #end class __ASSET__assets_sprites_money0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/MoonRabbit0.png") #if display private #end class __ASSET__assets_sprites_moonrabbit0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/MoonRabbitflipped0.png") #if display private #end class __ASSET__assets_sprites_moonrabbitflipped0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/mrghosty0.png") #if display private #end class __ASSET__assets_sprites_mrghosty0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/murasabullet0.png") #if display private #end class __ASSET__assets_sprites_murasabullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/myon0.png") #if display private #end class __ASSET__assets_sprites_myon0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/noroiko0.png") #if display private #end class __ASSET__assets_sprites_noroiko0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/notepad0.png") #if display private #end class __ASSET__assets_sprites_notepad0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/parseebullet0.png") #if display private #end class __ASSET__assets_sprites_parseebullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/patchouliALT0.png") #if display private #end class __ASSET__assets_sprites_patchoulialt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/pbullet0.png") #if display private #end class __ASSET__assets_sprites_pbullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/pika0.png") #if display private #end class __ASSET__assets_sprites_pika0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/pmusicnote0.png") #if display private #end class __ASSET__assets_sprites_pmusicnote0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Point0.png") #if display private #end class __ASSET__assets_sprites_point0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/poisoncloud0.png") #if display private #end class __ASSET__assets_sprites_poisoncloud0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/POW0.png") #if display private #end class __ASSET__assets_sprites_pow0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/POWalt0.png") #if display private #end class __ASSET__assets_sprites_powalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/powerup0.png") #if display private #end class __ASSET__assets_sprites_powerup0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/preisenbullet0.png") #if display private #end class __ASSET__assets_sprites_preisenbullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/present0.png") #if display private #end class __ASSET__assets_sprites_present0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/prinny0.png") #if display private #end class __ASSET__assets_sprites_prinny0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/questionblock0.png") #if display private #end class __ASSET__assets_sprites_questionblock0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/ranALT0.png") #if display private #end class __ASSET__assets_sprites_ranalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Redufo0.png") #if display private #end class __ASSET__assets_sprites_redufo0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/remiliaALT0.png") #if display private #end class __ASSET__assets_sprites_remiliaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/rock.png") #if display private #end class __ASSET__assets_sprites_rock_png extends lime.graphics.Image {}
@:image("Assets/Sprites/Roukanken0.png") #if display private #end class __ASSET__assets_sprites_roukanken0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/rumiaALT0.png") #if display private #end class __ASSET__assets_sprites_rumiaalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/SanaeStick0.png") #if display private #end class __ASSET__assets_sprites_sanaestick0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sawblade0.png") #if display private #end class __ASSET__assets_sprites_sawblade0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/scythe0.png") #if display private #end class __ASSET__assets_sprites_scythe0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sekibankihead0.png") #if display private #end class __ASSET__assets_sprites_sekibankihead0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sekibankiheadless0.png") #if display private #end class __ASSET__assets_sprites_sekibankiheadless0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/senkou0.png") #if display private #end class __ASSET__assets_sprites_senkou0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/shingyokuorb0.png") #if display private #end class __ASSET__assets_sprites_shingyokuorb0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/skull0.png") #if display private #end class __ASSET__assets_sprites_skull0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/spectrum0.png") #if display private #end class __ASSET__assets_sprites_spectrum0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/spellcard0.png") #if display private #end class __ASSET__assets_sprites_spellcard0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/spiderweb0.png") #if display private #end class __ASSET__assets_sprites_spiderweb0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/starbulletg0.png") #if display private #end class __ASSET__assets_sprites_starbulletg0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/starbullety0.png") #if display private #end class __ASSET__assets_sprites_starbullety0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/starorb0.png") #if display private #end class __ASSET__assets_sprites_starorb0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/suwakohat0.png") #if display private #end class __ASSET__assets_sprites_suwakohat0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/suwakohoop0.png") #if display private #end class __ASSET__assets_sprites_suwakohoop0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/sword0.png") #if display private #end class __ASSET__assets_sprites_sword0_png extends lime.graphics.Image {}
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
@:image("Assets/Sprites/teacup0.png") #if display private #end class __ASSET__assets_sprites_teacup0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/telephonepole0.png") #if display private #end class __ASSET__assets_sprites_telephonepole0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/train0.png") #if display private #end class __ASSET__assets_sprites_train0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/trophy0.png") #if display private #end class __ASSET__assets_sprites_trophy0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/truck0.png") #if display private #end class __ASSET__assets_sprites_truck0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/unused0.png") #if display private #end class __ASSET__assets_sprites_unused0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/unzanfist0.png") #if display private #end class __ASSET__assets_sprites_unzanfist0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/utsuhobullet0.png") #if display private #end class __ASSET__assets_sprites_utsuhobullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/warning0.png") #if display private #end class __ASSET__assets_sprites_warning0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/window.png") #if display private #end class __ASSET__assets_sprites_window_png extends lime.graphics.Image {}
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
@:image("Assets/Sprites/youmuALT0.png") #if display private #end class __ASSET__assets_sprites_youmualt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yukariALT0.png") #if display private #end class __ASSET__assets_sprites_yukarialt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yukaribullet0.png") #if display private #end class __ASSET__assets_sprites_yukaribullet0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/yuyukoALT0.png") #if display private #end class __ASSET__assets_sprites_yuyukoalt0_png extends lime.graphics.Image {}
@:image("Assets/Sprites/zombiefairy0.png") #if display private #end class __ASSET__assets_sprites_zombiefairy0_png extends lime.graphics.Image {}
@:file("Assets/Char.swf") #if display private #end class __ASSET__libraries_char_char_swf extends lime.utils.ByteArray {}
@:file("") #if display private #end class __ASSET__libraries_char_json extends lime.utils.ByteArray {}
@:file("Assets/Background.swf") #if display private #end class __ASSET__libraries_background_background_swf extends lime.utils.ByteArray {}
@:file("") #if display private #end class __ASSET__libraries_background_json extends lime.utils.ByteArray {}



#end

#if openfl

#end

#end
#end

