#ifndef INCLUDED_Block
#define INCLUDED_Block

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Entity.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Block)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Block_obj : public ::Entity_obj{
	public:
		typedef ::Entity_obj super;
		typedef Block_obj OBJ_;
		Block_obj();
		Void __construct(::String ani);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Block_obj > __new(::String ani);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Block_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Block"); }

		::Entity Visual;
		::Entity Flames;
		bool started;
		virtual Void Burn( );
		Dynamic Burn_dyn();

		virtual Void Freeze( );
		Dynamic Freeze_dyn();

		virtual Void Defrost( );
		Dynamic Defrost_dyn();

		virtual Void update( );

};


#endif /* INCLUDED_Block */ 
