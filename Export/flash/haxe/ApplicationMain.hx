#if !macro


@:access(lime.Assets)


class ApplicationMain {
	
	
	public static var config:lime.app.Config;
	public static var preloader:openfl.display.Preloader;
	
	
	public static function create ():Void {
		
		var app = new lime.app.Application ();
		app.create (config);
		openfl.Lib.application = app;
		
		#if !flash
		var stage = new openfl.display.Stage (app.window.width, app.window.height, config.background);
		stage.addChild (openfl.Lib.current);
		app.addModule (stage);
		#end
		
		var display = new NMEPreloader ();
		
		preloader = new openfl.display.Preloader (display);
		preloader.onComplete = init;
		preloader.create (config);
		
		#if (js && html5)
		var urls = [];
		var types = [];
		
		
		urls.push ("assets/Audio/Mp3/adv1.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/adv2.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/adv2intro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/adv3.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/adv3intro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/adv4.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/adv5.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/adv6.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/anchor.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/bonk.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/cancel.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/cash.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/characterselect.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/click.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/collectcoin.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/customize.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/died.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/drum0.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/drum1.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/drum2.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/drum3.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/drum4.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/explode.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/extend.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/finalkill.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/fireballspawn.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/gameover.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/getbonus.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/itemspawn.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/killenemy.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/masterspark.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/nextlevel.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/ok.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/options.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/optionsintro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/pow.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/powerdown.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/powerup.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/respawn.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/se_tan01.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/shop.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/spawncoin.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/startgame.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/step1.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/step2.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/step3.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/summonufo.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme1.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme10.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme11.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme12.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme12intro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme2.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme2intro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme3.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme3intro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme4.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme5.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme6.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme7.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme8.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme8intro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/theme9.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/titlescreen.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/titlescreenintro.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/ufochange.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/ufoitem.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/zawarudo.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/bgcolor.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/black.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Dpad.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Key.txt");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("assets/Sprites/1up0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/anchor0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Arrow0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ayana0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/balloon0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/balloon1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/balloon2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/balloon3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/balloon4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bananapeel0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/barrier0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bat0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bat1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bhina0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/black0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/blackhole0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Blackufo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/block0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bluebird.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bluelaser0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Blueufo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bomb0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Boomerang0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Bow0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/broom.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/camera0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/charblock0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/chenALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/chest.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/cloud0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/cross0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/CSBack0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/CSFront0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/darkness0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/deathcirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/diosakuya0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/diosakuyaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/disc0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/disc1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/disc2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/dresser.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen10.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen11.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen12.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen13.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen14.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen15.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen5.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen6.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen7.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen8.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EChen9.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ECirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EHkaguya0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EHmokou0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Ekaguya0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Ekaguyaflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EKeine0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EKeineex0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EKeineexflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/electriccirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Emokou0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Emokouflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/emptyblock0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EMystia0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EMystia1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EMystiaflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/energywave.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan10.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan11.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan12.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan13.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan14.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan15.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan5.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan6.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan7.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan8.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ERan9.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/evilyuuka0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/exclamationblock.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/exclamationmark.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/exkeine0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/explosion0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Explosive0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/firecirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flag0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flames0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flames1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flames2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flandreALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Gap0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Greenufo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hairdye0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer10.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer11.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer12.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer13.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer14.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer15.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer5.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer6.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer7.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer8.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hammer9.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/happytenshi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/heartbullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hecatiae0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hecatiaeflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hecatiam0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/icebullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/icecube0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/icyblock0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ikuikudance0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/keystone0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife5.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife6.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/knife7.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/komachiALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lbullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lightning0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lightsword.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/logo.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/magibullet.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/matenshi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/meilingsleeping0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/meilingsleepingflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mika0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/minihakkero0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mirror.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/money0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/MoonRabbit0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/MoonRabbitflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mrghosty0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/murasabullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/myon0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/noroiko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/notepad0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/parseebullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/patchouliALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/pbullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/pika0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/pmusicnote0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Point0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/poisoncloud0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/POW0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/POWalt0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/powerup0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/preisenbullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/present0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/prinny0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/questionblock0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ranALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Redufo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/remiliaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/rock.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Roukanken0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/rumiaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/SanaeStick0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sawblade0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/scythe0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sekibankihead0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sekibankiheadless0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/senkou0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shingyokuorb0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/skull0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/spectrum0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/spellcard0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/spiderweb0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/starbulletg0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/starbullety0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/starorb0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/suwakohat0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/suwakohoop0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sword0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table10.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table11.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table12.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table13.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table14.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table15.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table5.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table6.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table7.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table8.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/table9.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/teacup0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/telephonepole0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/train0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/trophy0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/truck0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/unused0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/unzanfist0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/utsuhobullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/warning0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/window.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb10.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb11.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb12.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb13.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb14.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb15.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb5.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb6.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb7.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb8.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yinyangorb9.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/youmuALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yukariALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yukaribullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yuyukoALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/zombiefairy0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("libraries/Char/Char.swf");
		types.push (lime.Assets.AssetType.BINARY);
		
		
		urls.push ("libraries/Char.json");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		urls.push ("libraries/Background/Background.swf");
		types.push (lime.Assets.AssetType.BINARY);
		
		
		urls.push ("libraries/Background.json");
		types.push (lime.Assets.AssetType.TEXT);
		
		
		
		if (config.assetsPrefix != null) {
			
			for (i in 0...urls.length) {
				
				if (types[i] != lime.Assets.AssetType.FONT) {
					
					urls[i] = config.assetsPrefix + urls[i];
					
				}
				
			}
			
		}
		
		preloader.load (urls, types);
		#end
		
		var result = app.exec ();
		
		#if (sys && !nodejs && !emscripten)
		Sys.exit (result);
		#end
		
	}
	
	
	public static function init ():Void {
		
		var loaded = 0;
		var total = 0;
		var library_onLoad = function (__) {
			
			loaded++;
			
			if (loaded == total) {
				
				start ();
				
			}
			
		}
		
		preloader = null;
		
		
		total++;
		openfl.Assets.loadLibrary ("Char", library_onLoad);
		
		total++;
		openfl.Assets.loadLibrary ("Background", library_onLoad);
		
		
		if (total == 0) {
			
			start ();
			
		}
		
	}
	
	
	public static function main () {
		
		config = {
			
			antialiasing: Std.int (0),
			background: Std.int (16777215),
			borderless: false,
			company: "RSGmaker",
			depthBuffer: false,
			file: "ReimuBros",
			fps: Std.int (60),
			fullscreen: false,
			hardware: true,
			height: Std.int (600),
			orientation: "",
			packageName: "RSG.Game",
			resizable: true,
			stencilBuffer: true,
			title: "ReimuBros",
			version: "1.7.0",
			vsync: false,
			width: Std.int (800),
			
		}
		
		#if (js && html5)
		#if (munit || utest)
		openfl.Lib.embed (null, 800, 600, "FFFFFF");
		#end
		#else
		create ();
		#end
		
	}
	
	
	public static function start ():Void {
		
		var hasMain = false;
		var entryPoint = Type.resolveClass ("Main");
		
		for (methodName in Type.getClassFields (entryPoint)) {
			
			if (methodName == "main") {
				
				hasMain = true;
				break;
				
			}
			
		}
		
		lime.Assets.initialize ();
		
		if (hasMain) {
			
			Reflect.callMethod (entryPoint, Reflect.field (entryPoint, "main"), []);
			
		} else {
			
			var instance:DocumentClass = Type.createInstance (DocumentClass, []);
			
			/*if (Std.is (instance, openfl.display.DisplayObject)) {
				
				openfl.Lib.current.addChild (cast instance);
				
			}*/
			
		}
		
		openfl.Lib.current.stage.dispatchEvent (new openfl.events.Event (openfl.events.Event.RESIZE, false, false));
		
	}
	
	
	#if neko
	@:noCompletion public static function __init__ () {
		
		var loader = new neko.vm.Loader (untyped $loader);
		loader.addPath (haxe.io.Path.directory (Sys.executablePath ()));
		loader.addPath ("./");
		loader.addPath ("@executable_path/");
		
	}
	#end
	
	
}


@:build(DocumentClass.build())
@:keep class DocumentClass extends Main {}


#else


import haxe.macro.Context;
import haxe.macro.Expr;


class DocumentClass {
	
	
	macro public static function build ():Array<Field> {
		
		var classType = Context.getLocalClass ().get ();
		var searchTypes = classType;
		
		while (searchTypes.superClass != null) {
			
			if (searchTypes.pack.length == 2 && searchTypes.pack[1] == "display" && searchTypes.name == "DisplayObject") {
				
				var fields = Context.getBuildFields ();
				
				var method = macro {
					
					openfl.Lib.current.addChild (this);
					super ();
					dispatchEvent (new openfl.events.Event (openfl.events.Event.ADDED_TO_STAGE, false, false));
					
				}
				
				fields.push ({ name: "new", access: [ APublic ], kind: FFun({ args: [], expr: method, params: [], ret: macro :Void }), pos: Context.currentPos () });
				
				return fields;
				
			}
			
			searchTypes = searchTypes.superClass.t.get ();
			
		}
		
		return null;
		
	}
	
	
}


#end
