#ifndef INCLUDED_box2D_common_math_B2Math
#define INCLUDED_box2D_common_math_B2Math

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Math)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  B2Math_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Math_obj OBJ_;
		B2Math_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Math_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Math_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2Math"); }

		static bool isValid( Float x);
		static Dynamic isValid_dyn();

		static Float dot( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic dot_dyn();

		static Float crossVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic crossVV_dyn();

		static ::box2D::common::math::B2Vec2 crossVF( ::box2D::common::math::B2Vec2 a,Float s);
		static Dynamic crossVF_dyn();

		static ::box2D::common::math::B2Vec2 crossFV( Float s,::box2D::common::math::B2Vec2 a);
		static Dynamic crossFV_dyn();

		static ::box2D::common::math::B2Vec2 mulMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v);
		static Dynamic mulMV_dyn();

		static ::box2D::common::math::B2Vec2 mulTMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v);
		static Dynamic mulTMV_dyn();

		static ::box2D::common::math::B2Vec2 mulX( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v);
		static Dynamic mulX_dyn();

		static ::box2D::common::math::B2Vec2 mulXT( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v);
		static Dynamic mulXT_dyn();

		static ::box2D::common::math::B2Vec2 addVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic addVV_dyn();

		static ::box2D::common::math::B2Vec2 subtractVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic subtractVV_dyn();

		static Float distance( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic distance_dyn();

		static Float distanceSquared( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic distanceSquared_dyn();

		static ::box2D::common::math::B2Vec2 mulFV( Float s,::box2D::common::math::B2Vec2 a);
		static Dynamic mulFV_dyn();

		static ::box2D::common::math::B2Mat22 addMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B);
		static Dynamic addMM_dyn();

		static ::box2D::common::math::B2Mat22 mulMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B);
		static Dynamic mulMM_dyn();

		static ::box2D::common::math::B2Mat22 mulTMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B);
		static Dynamic mulTMM_dyn();

		static Float abs( Float a);
		static Dynamic abs_dyn();

		static ::box2D::common::math::B2Vec2 absV( ::box2D::common::math::B2Vec2 a);
		static Dynamic absV_dyn();

		static ::box2D::common::math::B2Mat22 absM( ::box2D::common::math::B2Mat22 A);
		static Dynamic absM_dyn();

		static Float min( Float a,Float b);
		static Dynamic min_dyn();

		static ::box2D::common::math::B2Vec2 minV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic minV_dyn();

		static Float max( Float a,Float b);
		static Dynamic max_dyn();

		static ::box2D::common::math::B2Vec2 maxV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b);
		static Dynamic maxV_dyn();

		static Float clamp( Float a,Float low,Float high);
		static Dynamic clamp_dyn();

		static ::box2D::common::math::B2Vec2 clampV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 low,::box2D::common::math::B2Vec2 high);
		static Dynamic clampV_dyn();

		static Void swap( Dynamic a,Dynamic b);
		static Dynamic swap_dyn();

		static Float random( );
		static Dynamic random_dyn();

		static Float randomRange( Float lo,Float hi);
		static Dynamic randomRange_dyn();

		static int nextPowerOfTwo( int x);
		static Dynamic nextPowerOfTwo_dyn();

		static bool isPowerOfTwo( int x);
		static Dynamic isPowerOfTwo_dyn();

		static ::box2D::common::math::B2Vec2 b2Vec2_zero;
		static ::box2D::common::math::B2Mat22 b2Mat22_identity;
		static ::box2D::common::math::B2Transform b2Transform_identity;
		static Float MIN_VALUE;
		static Float MAX_VALUE;
		static Float get_MIN_VALUE( );
		static Dynamic get_MIN_VALUE_dyn();

		static Float get_MAX_VALUE( );
		static Dynamic get_MAX_VALUE_dyn();

};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Math */ 
