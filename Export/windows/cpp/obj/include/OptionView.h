#ifndef INCLUDED_OptionView
#define INCLUDED_OptionView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS0(OptionView)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,KeyboardEvent)


class HXCPP_CLASS_ATTRIBUTES  OptionView_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef OptionView_obj OBJ_;
		OptionView_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< OptionView_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~OptionView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("OptionView"); }

		::openfl::_v2::display::Sprite BackButton;
		::String status;
		::openfl::_v2::display::Sprite sndmeter;
		::openfl::_v2::display::Sprite musicmeter;
		int selection;
		virtual Void stage_onKeyUp( ::openfl::_v2::events::KeyboardEvent event);
		Dynamic stage_onKeyUp_dyn();

		virtual ::String stringfromcode( int code);
		Dynamic stringfromcode_dyn();

		virtual ::openfl::_v2::display::Sprite AddButton( ::String text);
		Dynamic AddButton_dyn();

};


#endif /* INCLUDED_OptionView */ 
