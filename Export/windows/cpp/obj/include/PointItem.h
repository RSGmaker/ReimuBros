#ifndef INCLUDED_PointItem
#define INCLUDED_PointItem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <EntityItem.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(EntityItem)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS0(PointItem)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  PointItem_obj : public ::EntityItem_obj{
	public:
		typedef ::EntityItem_obj super;
		typedef PointItem_obj OBJ_;
		PointItem_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PointItem_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PointItem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("PointItem"); }

		virtual Void Collect( ::Player player);

};


#endif /* INCLUDED_PointItem */ 
