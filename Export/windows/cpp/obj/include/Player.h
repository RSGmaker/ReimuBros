#ifndef INCLUDED_Player
#define INCLUDED_Player

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Entity.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,text,TextField)
HX_DECLARE_CLASS3(openfl,_v2,text,TextFormat)


class HXCPP_CLASS_ATTRIBUTES  Player_obj : public ::Entity_obj{
	public:
		typedef ::Entity_obj super;
		typedef Player_obj OBJ_;
		Player_obj();
		Void __construct(::String charname,Array< bool > controller);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Player_obj > __new(::String charname,Array< bool > controller);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Player_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Player"); }

		Float accel;
		Float Haccel;
		Float Hdeccel;
		Float mxspd;
		Array< bool > controller;
		::String charname;
		int lives;
		::String ID;
		int score;
		int spentscore;
		Float steps;
		int invincibility;
		::String playername;
		::openfl::_v2::text::TextField nameplate;
		::openfl::_v2::text::TextFormat format;
		int frame;
		virtual Void update( );

		static Array< ::String > characters;
		static Array< ::String > hiddencharacters;
		static ::String getRandomCharacter( );
		static Dynamic getRandomCharacter_dyn();

};


#endif /* INCLUDED_Player */ 
