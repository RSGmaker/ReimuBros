#ifndef INCLUDED_LifeItem
#define INCLUDED_LifeItem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <EntityItem.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(EntityItem)
HX_DECLARE_CLASS0(LifeItem)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  LifeItem_obj : public ::EntityItem_obj{
	public:
		typedef ::EntityItem_obj super;
		typedef LifeItem_obj OBJ_;
		LifeItem_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< LifeItem_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~LifeItem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("LifeItem"); }

		virtual Void Collect( ::Player player);

};


#endif /* INCLUDED_LifeItem */ 
