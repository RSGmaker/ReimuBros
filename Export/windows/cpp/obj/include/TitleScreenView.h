#ifndef INCLUDED_TitleScreenView
#define INCLUDED_TitleScreenView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS0(Animationloader)
HX_DECLARE_CLASS0(TitleScreenView)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  TitleScreenView_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef TitleScreenView_obj OBJ_;
		TitleScreenView_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TitleScreenView_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TitleScreenView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TitleScreenView"); }

		::openfl::_v2::display::Bitmap img_titlescreen;
		::Animationloader AL;
		bool menu;
		bool MSE;
		::openfl::_v2::display::Sprite startgame;
		::openfl::_v2::display::Sprite singleplayer;
		::openfl::_v2::display::Sprite options;
		::openfl::_v2::display::Sprite _exit;
		::String status;
		virtual Void start( );
		Dynamic start_dyn();

		virtual Void show_menu( );
		Dynamic show_menu_dyn();

		virtual ::openfl::_v2::display::Sprite AddButton( ::String text);
		Dynamic AddButton_dyn();

};


#endif /* INCLUDED_TitleScreenView */ 
