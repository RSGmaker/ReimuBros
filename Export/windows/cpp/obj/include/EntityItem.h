#ifndef INCLUDED_EntityItem
#define INCLUDED_EntityItem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Entity.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(EntityItem)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  EntityItem_obj : public ::Entity_obj{
	public:
		typedef ::Entity_obj super;
		typedef EntityItem_obj OBJ_;
		EntityItem_obj();
		Void __construct(::String ani);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< EntityItem_obj > __new(::String ani);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~EntityItem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EntityItem"); }

		::String charname;
		virtual Void Collect( ::Player player);
		Dynamic Collect_dyn();

		virtual Void update( );

};


#endif /* INCLUDED_EntityItem */ 
