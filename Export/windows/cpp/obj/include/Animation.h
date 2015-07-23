#ifndef INCLUDED_Animation
#define INCLUDED_Animation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Bitmap.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,BitmapData)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Animation_obj : public ::openfl::_v2::display::Bitmap_obj{
	public:
		typedef ::openfl::_v2::display::Bitmap_obj super;
		typedef Animation_obj OBJ_;
		Animation_obj();
		Void __construct(Array< ::Dynamic > ani);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Animation_obj > __new(Array< ::Dynamic > ani);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Animation_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Animation"); }

		Array< ::Dynamic > animation;
		Float Limage_index;
		Float image_index;
		Float image_speed;
		virtual Void ChangeAnimation( Array< ::Dynamic > ani);
		Dynamic ChangeAnimation_dyn();

		virtual Void animate( );
		Dynamic animate_dyn();

};


#endif /* INCLUDED_Animation */ 
