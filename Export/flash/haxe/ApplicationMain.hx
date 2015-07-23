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
		
		var display = new Preloader ();
		
		preloader = new openfl.display.Preloader (display);
		preloader.onComplete = init;
		preloader.create (config);
		
		#if (js && html5)
		var urls = [];
		var types = [];
		
		
		urls.push ("assets/Audio/Mp3/bonk.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/characterselect.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/collectcoin.mp3");
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
		
		
		urls.push ("assets/Audio/Mp3/extend.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/finalkill.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/fireballspawn.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/gameover.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/killenemy.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/masterspark.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/nextlevel.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/pow.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/respawn.mp3");
		types.push (lime.Assets.AssetType.MUSIC);
		
		
		urls.push ("assets/Audio/Mp3/se_tan01.mp3");
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
		
		
		urls.push ("assets/Audio/Mp3/theme3.mp3");
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
		
		
		urls.push ("assets/bgcolor.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/black.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Dpad.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/1up0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/akyu0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/alice0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/aliceALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/aya0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ayana0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/balloon0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/barrier0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/benben0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BG0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BG1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BG2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BG3.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BG4.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BG5.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/black0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/block0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BlueFairy0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/BlueFairyflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Blueufo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bomb0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/bullet0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/byakuren0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/charblock0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/chen0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/chiyuri0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/cirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/CSBG0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/daiyousei0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/darkness0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/diosakuya0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/doremy0.png");
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
		
		
		urls.push ("assets/Sprites/eirin0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EKeine0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EKeineex0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EKeineexflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/electriccirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/elis0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ellen0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/elly0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EMystia0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EMystia1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/EMystiaflipped0.png");
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
		
		
		urls.push ("assets/Sprites/exkeine0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/firecirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flames0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flames1.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flames2.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/flandre0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/futo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Gap0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/gengetsu0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/giantcirno0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/giantsuika0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Greenufo0.png");
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
		
		
		urls.push ("assets/Sprites/hatate0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/hina0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ichirin0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/icyblock0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/iku0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ikuikudance0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kagerou0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kaguya0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kana0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kanako0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kasen0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/keine0.png");
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
		
		
		urls.push ("assets/Sprites/koakuma0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kogasa0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kogasaflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/koishi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/koishiflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kokoro0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/komachi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/konngara0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kosuzu0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kotohime0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kurumi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/kyouko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/letty0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lightning0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lily0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/louise0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lunachild0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lunasa0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/lyrica0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mai0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/makairesident-a0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/makairesident-b0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mamizou0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/maribel0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/marisa0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/marisaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/matenshi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/medicine0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/meiling0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/meilingALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/meira0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/merlin0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/miko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mima0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mimaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/minoriko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mokou0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/momiji0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mrghosty0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mugetsu0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/murasa0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/myon0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mystia0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/mystiaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/nazrin0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/nazrinflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/nitori0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/noroiko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/nue0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/options0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/orange0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/orin0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/parsee0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/patchouli0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/pika0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Point0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/POW0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/POWalt0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/prinny0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/raiko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ran0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/RedFairy0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/RedFairyflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/Redufo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/reimu0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/reimuALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/reimuflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/reisen0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/remilia0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/rengeteki0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/renko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/rika0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/rikako0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/rin0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ringo0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/rumia0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/ruukoto0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sakuya0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sakuyaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sanae0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sanaeALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sara0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sariel0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/satori0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/satoriflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/seiga0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/seija0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/seiran0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sekibanki0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shanghai0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shikieiki0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shingyoku0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shingyokuALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shinki0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shinmyoumaru0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shizuha0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/shou0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/skull0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/starbulletg0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/starbullety0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/starsaphire0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/suika0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sumireko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/sunnymilk0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/suwako0.png");
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
		
		
		urls.push ("assets/Sprites/tenshi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/tewi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/tewiflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/titlescreen0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/tojiko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/tokiko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/toyohime0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/trophy0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/truck0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/udongein0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/udongeinflipped0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/unused0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/unzanfist0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/utsuho0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/wakasagihime0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/wriggle0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yamame0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yatsuhashi0.png");
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
		
		
		urls.push ("assets/Sprites/yorihime0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yoshika0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/youmu0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yukari0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yuki0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yumeko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yumemi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yuugi0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yuuka0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yuukaALT0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/yuyuko0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		urls.push ("assets/Sprites/zombiefairy0.png");
		types.push (lime.Assets.AssetType.IMAGE);
		
		
		
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
			fps: Std.int (30),
			fullscreen: false,
			hardware: true,
			height: Std.int (600),
			orientation: "",
			packageName: "RSG.Game",
			resizable: true,
			stencilBuffer: true,
			title: "ReimuBros",
			version: "1.5.0",
			vsync: true,
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
