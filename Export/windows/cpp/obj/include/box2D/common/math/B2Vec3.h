#ifndef INCLUDED_box2D_common_math_B2Vec3
#define INCLUDED_box2D_common_math_B2Vec3

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec3)
namespace box2D{
namespace common{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  B2Vec3_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Vec3_obj OBJ_;
		B2Vec3_obj();
		Void __construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z);

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Vec3_obj > __new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Vec3_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2Vec3"); }

		virtual Void setZero( );
		Dynamic setZero_dyn();

		virtual Void set( Float x,Float y,Float z);
		Dynamic set_dyn();

		virtual Void setV( ::box2D::common::math::B2Vec3 v);
		Dynamic setV_dyn();

		virtual ::box2D::common::math::B2Vec3 getNegative( );
		Dynamic getNegative_dyn();

		virtual Void negativeSelf( );
		Dynamic negativeSelf_dyn();

		virtual ::box2D::common::math::B2Vec3 copy( );
		Dynamic copy_dyn();

		virtual Void add( ::box2D::common::math::B2Vec3 v);
		Dynamic add_dyn();

		virtual Void subtract( ::box2D::common::math::B2Vec3 v);
		Dynamic subtract_dyn();

		virtual Void multiply( Float a);
		Dynamic multiply_dyn();

		Float x;
		Float y;
		Float z;
};

} // end namespace box2D
} // end namespace common
} // end namespace math

#endif /* INCLUDED_box2D_common_math_B2Vec3 */ 
