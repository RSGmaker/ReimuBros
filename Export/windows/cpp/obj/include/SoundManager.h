#ifndef INCLUDED_SoundManager
#define INCLUDED_SoundManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS0(SoundManager)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,media,Sound)
HX_DECLARE_CLASS3(openfl,_v2,media,SoundChannel)


class HXCPP_CLASS_ATTRIBUTES  SoundManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SoundManager_obj OBJ_;
		SoundManager_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SoundManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SoundManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundManager"); }

		::haxe::ds::StringMap Dictionary;
		Array< ::Dynamic > channels;
		bool muted;
		::openfl::_v2::media::SoundChannel music;
		Float sndvol;
		Float musicvol;
		::String _song;
		Float _songposition;
		virtual ::openfl::_v2::media::Sound GetSound( ::String path);
		Dynamic GetSound_dyn();

		virtual ::openfl::_v2::media::SoundChannel _PlayJingle( ::String path);
		Dynamic _PlayJingle_dyn();

		virtual ::openfl::_v2::media::SoundChannel _PlayMusic( ::String path);
		Dynamic _PlayMusic_dyn();

		virtual ::openfl::_v2::media::SoundChannel _Play( ::String path,hx::Null< Float >  position,hx::Null< int >  Loops,hx::Null< Float >  volume);
		Dynamic _Play_dyn();

		virtual Void jingleend( ::openfl::_v2::events::Event event);
		Dynamic jingleend_dyn();

		virtual Void ended( ::openfl::_v2::events::Event event);
		Dynamic ended_dyn();

		virtual Void _StopAll( );
		Dynamic _StopAll_dyn();

		virtual Void SetSoundVolume( Float volume);
		Dynamic SetSoundVolume_dyn();

		virtual Float GetMusicVolume( );
		Dynamic GetMusicVolume_dyn();

		virtual Float GetSoundVolume( );
		Dynamic GetSoundVolume_dyn();

		virtual Void SetMusicVolume( Float volume);
		Dynamic SetMusicVolume_dyn();

		virtual Void Mute( );
		Dynamic Mute_dyn();

		virtual Void Unmute( );
		Dynamic Unmute_dyn();

		virtual Void ToggleMute( );
		Dynamic ToggleMute_dyn();

		static ::SoundManager _this;
		static ::openfl::_v2::media::SoundChannel Play( ::String path);
		static Dynamic Play_dyn();

		static ::openfl::_v2::media::SoundChannel PlayJingle( ::String path);
		static Dynamic PlayJingle_dyn();

		static ::openfl::_v2::media::SoundChannel PlayMusic( ::String path);
		static Dynamic PlayMusic_dyn();

		static Void StopAll( );
		static Dynamic StopAll_dyn();

};


#endif /* INCLUDED_SoundManager */ 
