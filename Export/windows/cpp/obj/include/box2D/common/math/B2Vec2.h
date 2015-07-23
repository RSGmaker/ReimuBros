#ifndef INCLUDED_box2D_common_math_B2Vec2
#define INCLUDED_box2D_common_math_B2Vec2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace common{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  B2Vec2_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Vec2_obj OBJ_;
		B2Vec2_obj();
		Void __construct(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Vec2_obj > __new(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Vec2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2Vec2"); }

		virtual Void setZero( );
		Dynamic setZero_dyn();

		virtual Void set( hx::Null< Float >  x_,hx::Null< Float >  y_);
		Dynamic set_dyn();

		virtual Void setV( ::box2D::common::math::B2Vec2 v);
		Dynamic setV_dyn();

		virtual ::box2D::common::math::B2Vec2 getNegative( );
		Dynamic getNegative_dyn();

		virtual Void negativeSelf( );
		Dynamic negativeSelf_dyn();

		virtual ::box2D::common::math::B2Vec2 copy( );
		Dynamic copy_dyn();

		virtual Void add( ::box2D::common::math::B2Vec2 v);
		Dynamic add_dyn();

		virtual Void subtract( ::box2D::common::math::B2Vec2 v);
		Dynamic subtract_dyn();

		virtual Void multiply( Float a);
		Dynamic multiply_dyn();

		virtual Void mulM( ::box2D::common::math::B2Mat22 A);
		Dynamic mulM_dyn();

		virtual Void mulTM( ::box2D::common::math::B2Mat22 A);
		Dynamic mulTM_dyn();

		virtual Void crossVF( Float s);
		Dynamic crossVF_dyn();

		virtual Void crossFV( Float s);
		Dynamic crossFV_dyn();

		virtual Void minV( ::box2D::common::math::B2Vec2 b);
		Dynamic minV_dyn();

		virtual Void maxV( ::box2D::common::math::B2Vec2 b);
		Dynamic maxV_dyn();

		virtual Void abs( );
		Dynamic abs_dyn();

		virtual Float length( );
		Dynamic length_dyn();

		virtual Float lengthSquared( );
		Dynamic lengthSquared_dyn();

		virtual Float normalize( );
		Dynamic normalize_dyn();

		virtual bool isValid( );
		Dynamic isValid_dyn();

		Float x;
		Float y;
		static ::box2D::common::math::B2Vec2 make( Float x_,Float y_);
		static Dynamic make_dyn();

};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Vec2 */ 
