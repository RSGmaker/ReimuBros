#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#define INCLUDED_box2D_collision_shapes_B2MassData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{
namespace shapes{


class HXCPP_CLASS_ATTRIBUTES  B2MassData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2MassData_obj OBJ_;
		B2MassData_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2MassData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2MassData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2MassData"); }

		Float mass;
		::box2D::common::math::B2Vec2 center;
		Float I;
};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes

#endif /* INCLUDED_box2D_collision_shapes_B2MassData */ 
