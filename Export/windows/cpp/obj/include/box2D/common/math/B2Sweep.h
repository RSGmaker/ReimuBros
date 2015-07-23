#ifndef INCLUDED_box2D_common_math_B2Sweep
#define INCLUDED_box2D_common_math_B2Sweep

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Sweep)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  B2Sweep_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Sweep_obj OBJ_;
		B2Sweep_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Sweep_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Sweep_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Sweep"); }

		virtual Void set( ::box2D::common::math::B2Sweep other);
		Dynamic set_dyn();

		virtual ::box2D::common::math::B2Sweep copy( );
		Dynamic copy_dyn();

		virtual Void getTransform( ::box2D::common::math::B2Transform xf,Float alpha);
		Dynamic getTransform_dyn();

		virtual Void advance( Float t);
		Dynamic advance_dyn();

		::box2D::common::math::B2Vec2 localCenter;
		::box2D::common::math::B2Vec2 c0;
		::box2D::common::math::B2Vec2 c;
		Float a0;
		Float a;
		Float t0;
};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Sweep */ 
