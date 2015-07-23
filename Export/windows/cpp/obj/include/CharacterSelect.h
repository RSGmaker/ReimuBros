#ifndef INCLUDED_CharacterSelect
#define INCLUDED_CharacterSelect

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS0(Animationloader)
HX_DECLARE_CLASS0(CharacterSelect)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,KeyboardEvent)
HX_DECLARE_CLASS3(openfl,_v2,text,TextField)


class HXCPP_CLASS_ATTRIBUTES  CharacterSelect_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef CharacterSelect_obj OBJ_;
		CharacterSelect_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CharacterSelect_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CharacterSelect_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CharacterSelect"); }

		::Animationloader AL;
		::String selected;
		Array< ::Dynamic > Buttons;
		Array< ::Dynamic > ButtonsPage;
		::openfl::_v2::text::TextField Nameinput;
		::openfl::_v2::display::Sprite StartButton;
		::openfl::_v2::display::Sprite ExitButton;
		::openfl::_v2::display::Sprite NextButton;
		::openfl::_v2::display::Sprite PrevButton;
		::String status;
		::String playername;
		bool online;
		::String Room;
		::openfl::_v2::text::TextField CustomRoom;
		::openfl::_v2::text::TextField selectedcharacter;
		int currentpage;
		bool custom;
		virtual Void start( );
		Dynamic start_dyn();

		virtual Void stage_onKeyDown( ::openfl::_v2::events::KeyboardEvent event);
		Dynamic stage_onKeyDown_dyn();

		virtual Void refreshbuttons( );
		Dynamic refreshbuttons_dyn();

		virtual ::String gettext( int i);
		Dynamic gettext_dyn();

		virtual Void makebuttons( );
		Dynamic makebuttons_dyn();

		virtual ::openfl::_v2::display::Sprite AddButton( ::String text);
		Dynamic AddButton_dyn();

		int BW;
		Float BH;
		virtual ::openfl::_v2::display::Sprite AddCharacterButton( ::String text,bool unlocked);
		Dynamic AddCharacterButton_dyn();

};


#endif /* INCLUDED_CharacterSelect */ 
