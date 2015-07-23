#ifndef INCLUDED_Rumia
#define INCLUDED_Rumia

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Enemy.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(Rumia)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Rumia_obj : public ::Enemy_obj{
	public:
		typedef ::Enemy_obj super;
		typedef Rumia_obj OBJ_;
		Rumia_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Rumia_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Rumia_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Rumia"); }

		Float accel;
		Float mxspd;
		::openfl::_v2::display::Bitmap darkness;
		virtual Void increaserank( );

		virtual Void update( );

		virtual Void bump( );

};


#endif /* INCLUDED_Rumia */ 
