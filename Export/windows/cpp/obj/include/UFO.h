#ifndef INCLUDED_UFO
#define INCLUDED_UFO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Enemy.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(MersenneTwister)
HX_DECLARE_CLASS0(UFO)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,geom,Rectangle)


class HXCPP_CLASS_ATTRIBUTES  UFO_obj : public ::Enemy_obj{
	public:
		typedef ::Enemy_obj super;
		typedef UFO_obj OBJ_;
		UFO_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< UFO_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~UFO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("UFO"); }

		bool ascend;
		int iter;
		::MersenneTwister rng;
		Float rot;
		::String rename;
		::String ufotype;
		int fuel;
		int reducetime;
		virtual Void enrage( );

		virtual Void update( );

		virtual Void bump( );

		static ::openfl::_v2::geom::Rectangle HB;
};


#endif /* INCLUDED_UFO */ 
