#ifndef INCLUDED_box2D_common_math_B2Mat22
#define INCLUDED_box2D_common_math_B2Mat22

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  B2Mat22_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Mat22_obj OBJ_;
		B2Mat22_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Mat22_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Mat22_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Mat22"); }

		virtual Void set( Float angle);
		Dynamic set_dyn();

		virtual Void setVV( ::box2D::common::math::B2Vec2 c1,::box2D::common::math::B2Vec2 c2);
		Dynamic setVV_dyn();

		virtual ::box2D::common::math::B2Mat22 copy( );
		Dynamic copy_dyn();

		virtual Void setM( ::box2D::common::math::B2Mat22 m);
		Dynamic setM_dyn();

		virtual Void addM( ::box2D::common::math::B2Mat22 m);
		Dynamic addM_dyn();

		virtual Void setIdentity( );
		Dynamic setIdentity_dyn();

		virtual Void setZero( );
		Dynamic setZero_dyn();

		virtual Float getAngle( );
		Dynamic getAngle_dyn();

		virtual ::box2D::common::math::B2Mat22 getInverse( ::box2D::common::math::B2Mat22 out);
		Dynamic getInverse_dyn();

		virtual ::box2D::common::math::B2Vec2 solve( ::box2D::common::math::B2Vec2 out,Float bX,Float bY);
		Dynamic solve_dyn();

		virtual Void abs( );
		Dynamic abs_dyn();

		::box2D::common::math::B2Vec2 col1;
		::box2D::common::math::B2Vec2 col2;
		static ::box2D::common::math::B2Mat22 fromAngle( Float angle);
		static Dynamic fromAngle_dyn();

		static ::box2D::common::math::B2Mat22 fromVV( ::box2D::common::math::B2Vec2 c1,::box2D::common::math::B2Vec2 c2);
		static Dynamic fromVV_dyn();

};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Mat22 */ 
