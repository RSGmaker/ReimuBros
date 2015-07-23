#ifndef INCLUDED_Table
#define INCLUDED_Table

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Entity.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS0(Table)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Table_obj : public ::Entity_obj{
	public:
		typedef ::Entity_obj super;
		typedef Table_obj OBJ_;
		Table_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Table_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Table_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Table"); }

		bool started;
		Float startx;
		Float starty;
		Float gravX;
		Float gravY;
		::Player tossedBy;
		int respawn;
		virtual Void update( );

};


#endif /* INCLUDED_Table */ 
