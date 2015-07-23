#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS0(Animationloader)
HX_DECLARE_CLASS0(CharacterSelect)
HX_DECLARE_CLASS0(GameView)
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS0(OptionView)
HX_DECLARE_CLASS0(TitleScreenView)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,KeyboardEvent)
HX_DECLARE_CLASS3(openfl,_v2,net,SharedObject)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		::GameView game;
		::TitleScreenView titlescreen;
		::OptionView optionscreen;
		::Animationloader AL;
		::String status;
		::CharacterSelect characterselect;
		::String playerspick;
		bool online;
		::String playername;
		::openfl::_v2::net::SharedObject savedata;
		::String Room;
		bool DEBUG;
		Array< int > controlscheme;
		int gamemode;
		virtual Void stage_onKeyUp( ::openfl::_v2::events::KeyboardEvent event);
		Dynamic stage_onKeyUp_dyn();

		virtual Void stage_onKeyDown( ::openfl::_v2::events::KeyboardEvent event);
		Dynamic stage_onKeyDown_dyn();

		virtual Void this_onEnterFrame( ::openfl::_v2::events::Event event);
		Dynamic this_onEnterFrame_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void showgame( );
		Dynamic showgame_dyn();

		virtual Void showtitlescreen( );
		Dynamic showtitlescreen_dyn();

		virtual Void showcharacterselect( );
		Dynamic showcharacterselect_dyn();

		virtual Void showoptions( );
		Dynamic showoptions_dyn();

		static ::Main _this;
		static Array< ::String > codes;
};


#endif /* INCLUDED_Main */ 
