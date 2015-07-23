#ifndef INCLUDED_Chen
#define INCLUDED_Chen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Enemy.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Chen)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(MersenneTwister)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Chen_obj : public ::Enemy_obj{
	public:
		typedef ::Enemy_obj super;
		typedef Chen_obj OBJ_;
		Chen_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Chen_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Chen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Chen"); }

		bool ascend;
		int iter;
		::MersenneTwister rng;
		Float rot;
		::String rename;
		int danmaku;
		int reducetime;
		virtual Void enrage( );

		virtual Void update( );

		virtual Void bump( );

};


#endif /* INCLUDED_Chen */ 
