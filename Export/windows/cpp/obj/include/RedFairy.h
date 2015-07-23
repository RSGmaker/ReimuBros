#ifndef INCLUDED_RedFairy
#define INCLUDED_RedFairy

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Enemy.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(RedFairy)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  RedFairy_obj : public ::Enemy_obj{
	public:
		typedef ::Enemy_obj super;
		typedef RedFairy_obj OBJ_;
		RedFairy_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RedFairy_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RedFairy_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("RedFairy"); }

		Float accel;
		Float mxspd;
		virtual Void increaserank( );

		virtual Void update( );

		virtual Void bump( );

};


#endif /* INCLUDED_RedFairy */ 
