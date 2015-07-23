#ifndef INCLUDED_PowBlock
#define INCLUDED_PowBlock

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Entity.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(PowBlock)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  PowBlock_obj : public ::Entity_obj{
	public:
		typedef ::Entity_obj super;
		typedef PowBlock_obj OBJ_;
		PowBlock_obj();
		Void __construct(::String ani);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PowBlock_obj > __new(::String ani);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PowBlock_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("PowBlock"); }

		int HP;
		virtual Void update( );

};


#endif /* INCLUDED_PowBlock */ 
