#ifndef INCLUDED_box2D_common_B2Color
#define INCLUDED_box2D_common_B2Color

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,common,B2Color)
namespace box2D{
namespace common{


class HXCPP_CLASS_ATTRIBUTES  B2Color_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Color_obj OBJ_;
		B2Color_obj();
		Void __construct(Float rr,Float gg,Float bb);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Color_obj > __new(Float rr,Float gg,Float bb);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Color_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2Color"); }

		virtual Void set( Float rr,Float gg,Float bb);
		Dynamic set_dyn();

		Float r;
		Float g;
		Float b;
		int color;
		virtual Float set_r( Float rr);
		Dynamic set_r_dyn();

		virtual Float set_g( Float gg);
		Dynamic set_g_dyn();

		virtual Float set_b( Float bb);
		Dynamic set_b_dyn();

		virtual int get_color( );
		Dynamic get_color_dyn();

		int _r;
		int _g;
		int _b;
};

} // end namespace box2D
} // end namespace common

#endif /* INCLUDED_box2D_common_B2Color */ 
