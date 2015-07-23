#ifndef INCLUDED_box2D_collision_B2OBB
#define INCLUDED_box2D_collision_B2OBB

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2OBB)
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  B2OBB_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2OBB_obj OBJ_;
		B2OBB_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2OBB_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2OBB_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2OBB"); }

		::box2D::common::math::B2Mat22 R;
		::box2D::common::math::B2Vec2 center;
		::box2D::common::math::B2Vec2 extents;
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2OBB */ 
