#ifndef INCLUDED_Nue
#define INCLUDED_Nue

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Enemy.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(MersenneTwister)
HX_DECLARE_CLASS0(Nue)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Nue_obj : public ::Enemy_obj{
	public:
		typedef ::Enemy_obj super;
		typedef Nue_obj OBJ_;
		Nue_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Nue_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Nue_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Nue"); }

		Float accel;
		Float mxspd;
		int timer;
		::MersenneTwister rng;
		bool flipping;
		int countdown;
		::String rename;
		bool have;
		bool isChar;
		bool disguised;
		int frames;
		int unlock;
		bool alternate;
		virtual Void enrage( );

		virtual Void update( );

		virtual Void bump( );

};


#endif /* INCLUDED_Nue */ 
