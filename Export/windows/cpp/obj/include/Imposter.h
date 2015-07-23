#ifndef INCLUDED_Imposter
#define INCLUDED_Imposter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Enemy.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(Imposter)
HX_DECLARE_CLASS0(MersenneTwister)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Imposter_obj : public ::Enemy_obj{
	public:
		typedef ::Enemy_obj super;
		typedef Imposter_obj OBJ_;
		Imposter_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Imposter_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Imposter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Imposter"); }

		Float accel;
		Float mxspd;
		::MersenneTwister rng;
		::String rename;
		int frames;
		int unlock;
		bool have;
		bool alternate;
		bool hidden;
		int timer;
		int countdown;
		int mxcountdown;
		int mxtimer;
		virtual Void increaserank( );

		virtual Void update( );

		virtual Void bump( );

};


#endif /* INCLUDED_Imposter */ 
