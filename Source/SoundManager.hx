package;
import openfl.media.Sound;
import openfl.media.SoundChannel;
import openfl.media.SoundTransform;
import openfl.Assets;
import openfl.events.Event;
import haxe.Timer;
/**
 * ...
 * @author RSGmaker
 */
class SoundManager
{
	private var Dictionary:Map<String,Sound>;
	//public var channels:Array<SoundChannel>;
	public var activeaudio:Array<Dynamic>;
	private var muted:Bool;
	public var music:SoundChannel;
	private var sndvol:Float;
	private var musicvol:Float;
	private var _song:String;
	private var _songposition:Float;
	public var jingle:SoundChannel;
	//public var thejingle:String;
	public static var _this:SoundManager;
	public var nextsong:String;
	public var playingintro:Bool;
	
	public function new() 
	{
		//channels = new Array<SoundChannel>();
		activeaudio = new Array<Dynamic>();
		Dictionary = new Map<String,Sound>();
		muted = false;
		_this = this;
		sndvol = 1.0;
		musicvol = 1.0;
		playingintro = false;
	}
	public static function Play(path:String):SoundChannel {
		return _this._Play(path);
		//return _this._Play(path);
	}
	public function GetSound(path:String):Sound {
		if (Dictionary.exists(path))
		{
			return Dictionary[path];
		}
		else
		{
			#if flash
			var S = Assets.getSound("assets/Audio/Mp3/" + path + ".mp3");
			#else
			//.mp3 is flash only for some reason
			//var S = Assets.getSound("assets/Audio/" + path + ".ogg");
		
			//although sound wont work using mp3 the timing info still applies
			//var S = Assets.getSound("assets/Audio/Mp3/" + path + ".mp3");
			var S = Assets.getSound("assets/Audio/Ogg/" + path + ".OGG");
			//var S = Assets.getSound("assets/Audio/Ogg/" + path + ".mp3.OGG");
			#end
			Dictionary.set(path, S);
			return S;
		}
	}
	public static function PlayJingle(path:String):SoundChannel
	{
		return _this._PlayJingle(path);
	}
	public function _PlayJingle(path:String):SoundChannel
	{
		if (/*thejingle != path || */jingle == null)
		{
		if (music != null)
		{
			/*_songposition = music.position;
			var S = song;
			music.stop();
			music = null;
			_song = S;*/
			music.soundTransform = new SoundTransform(0, 0);
		}
		//thejingle = path;
		var S = _Play(path, 0, 0, musicvol);
		jingle = S;
		S.addEventListener(Event.SOUND_COMPLETE, jingleend);
		return S;
		}
		else
		{
			return jingle;
		}
	}
	public static function PlayMusic(path:String):SoundChannel
	{
		if (_this.jingle != null)
		{
			return null;
			if (_this.nextsong == null)
			{
				_this.nextsong = path;
			}
		}
		if (_this._song != path && !_this.playingintro)
		{
		var A = _this._Play(path + "intro",0,0,_this.musicvol);
		if (A != null)
		{
			_this.playingintro = true;
			if (_this.music != null)
			{
				_this.music.stop();
				_this.music = null;
			}
			A.addEventListener(Event.SOUND_COMPLETE, function(e:Event):Void {
				_this._PlayMusic(path);
				_this.playingintro = false;
			});
			//PlayMusic();
			return A;
		}
		else
		{
			return _this._PlayMusic(path);
		}
		}
		return null;
	}
	public function _PlayMusic(path:String):SoundChannel
	{
		if (_song != path)
		{
		if (music != null)
		{
			music.stop();
			music = null;
		}
		_songposition = -1.0;
		music = _Play(path,0,999999999,musicvol);
		_song = path;
		return music;
		}
		else
		{
			return null;
		}
	}
	public function _Play(path:String,position:Float=0.0,Loops:Int=0,volume:Float=-1000):SoundChannel {
		/*#if flash
		var S = Assets.getSound("assets/Audio/" + path + ".mp3");
		#else
		//.mp3 is flash only for some reason
		//var S = Assets.getSound("assets/Audio/" + path + ".ogg");
		
		//although sound wont work using mp3 the timing info still applies
		var S = Assets.getSound("assets/Audio/" + path + ".mp3");
		#end*/
		var i = 0;
		var C = 0;
		while (i < activeaudio.length)
		{
			var D = activeaudio[i];
			if (D.path == path)
			{
				if (C > 0)
				{
					return null;
				}
				C++;
			}
			i++;
		}
		var S = GetSound(path);
		if (volume == -1000)
		{
			volume = sndvol;
		}
		if (S != null)
		{
			var T:SoundTransform = new SoundTransform(volume, 0);
			if (muted)
			{
				T.volume = 0;
			}
			else
			{
			}
			var C = S.play(position,Loops,T);
			var D:Dynamic = { };
			D.channel = C;
			D.time = Timer.stamp();
			D.path = path;
			activeaudio[activeaudio.length] = D;
			//channels[channels.length] = C;
			C.addEventListener(Event.SOUND_COMPLETE, ended);
			return C;
		}
		return null;
	}//jingleend
	private function jingleend(event:Event) {
		var D:Dynamic = event.target;
		//if (music == null && _song != null)
		if (music != null && !muted)
		{
			music.soundTransform = new SoundTransform(musicvol, 0);
			//music = null;
			//_Play(_song, _songposition);
		}
		/*var i = 0;
		while (i < activeaudio.length)
		{
			if (activeaudio[i].channel == D)
			{
				activeaudio.remove(activeaudio[i]);
				//i--;
				i = activeaudio.length;
			}
			i++;
		}*/
		jingle = null;
		//thejingle = "";
		removeactiveaudio(D);
		//channels.remove(D);
		if (music == null && nextsong != null)
		{
			PlayMusic(nextsong);
			nextsong = null;
		}
	}
	private function removeactiveaudio(C:SoundChannel)
	{
		var i = 0;
		while (i < activeaudio.length)
		{
			if (activeaudio[i].channel == C)
			{
				activeaudio.remove(activeaudio[i]);
				//i--;
				return;
				i = activeaudio.length;
			}
			i++;
		}
	}
	private function ended(event:Event) {
		var D:Dynamic = event.target;
		if (music == D)
		{
			music = null;
			_song = null;
		}
		removeactiveaudio(D);
		//channels.remove(D);
	}
	public static function StopAll() {
		return _this._StopAll();
	}
	public function _StopAll() {
		/*while (channels.length > 0)
		{
			var C = channels[0];
			C.stop();
			if (channels.indexOf(C) > -1)
			{
				channels.remove(C);
			}
		}*/
		while (activeaudio.length > 0)
		{
			var D = activeaudio[0];
			D.channel.stop();
			if (activeaudio.indexOf(D) > -1)
			{
				activeaudio.remove(D);
			}
		}
		music = null;
		_song = null;
		jingle = null;
		playingintro = false;
	}
	public function SetSoundVolume(volume:Float) {
		if (!muted)
		{
		var i = 0;
		if (volume < 0.1)
		{
			volume = 0;
		}
		if (volume > 0.9)
		{
			volume = 1;
		}
		/*while (i < channels.length)
		{
			var C = channels[i];
			if (C != music)
			{
				C.soundTransform = new SoundTransform(volume, 0);
			}
			i += 1;
		}*///activeaudio
		while (i < activeaudio.length)
		{
			var D = activeaudio[i];
			if (D.channel != music && D.channel != jingle)
			{
				D.channel.soundTransform = new SoundTransform(volume, 0);
			}
			i += 1;
		}
		}
		sndvol = volume;
	}
	public function GetMusicVolume():Float {
		return musicvol;
	}
	public function GetSoundVolume():Float {
		return sndvol;
	}
	public function SetMusicVolume(volume:Float) {
		if (!muted)
		{
		var i = 0;
		if (volume < 0.1)
		{
			volume = 0;
		}
		if (volume > 0.9)
		{
			volume = 1;
		}
		/*while (i < channels.length)
		{
			var C = channels[i];
			if (C == music)
			{
				C.soundTransform = new SoundTransform(volume, 0);
			}
			i += 1;
		}*/
		while (i < activeaudio.length)
		{
			var D = activeaudio[i];
			if ((D.channel == music && jingle==null) || D.channel == jingle)
			{
				D.channel.soundTransform = new SoundTransform(volume, 0);
			}
			i += 1;
		}
		}
		musicvol = volume;
	}
	public function Mute() {
		var i = 0;
		muted = true;
		/*while (i < channels.length)
		{
			var C = channels[i];
			//C.soundTransform.volume = 0;
			C.soundTransform = new SoundTransform(0, 0);
			i += 1;
		}*/
		while (i < activeaudio.length)
		{
			var C = activeaudio[i].channel;
			//C.soundTransform.volume = 0;
			C.soundTransform = new SoundTransform(0, 0);
			i += 1;
		}
		
	}
	public function Unmute() {
		var i = 0;
		muted = false;
		while (i < activeaudio.length)
		{
			var C = activeaudio[i].channel;
			//C.soundTransform.volume = 1;
			var V = sndvol;
			if (C == music)
			{
				V = musicvol;
			}
			C.soundTransform = new SoundTransform(V, 0);
			i += 1;
		}
	}
	public function ToggleMute() {
		if (muted)
		{
			Unmute();
		}
		else
		{
			Mute();
		}
	}
	
}