#ifndef INCLUDED_box2D_collision_B2ContactPoint
#define INCLUDED_box2D_collision_B2ContactPoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ContactID)
HX_DECLARE_CLASS2(box2D,collision,B2ContactPoint)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  B2ContactPoint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactPoint_obj OBJ_;
		B2ContactPoint_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2ContactPoint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2ContactPoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactPoint"); }

		::box2D::collision::shapes::B2Shape shape1;
		::box2D::collision::shapes::B2Shape shape2;
		::box2D::common::math::B2Vec2 position;
		::box2D::common::math::B2Vec2 velocity;
		::box2D::common::math::B2Vec2 normal;
		Float separation;
		Float friction;
		Float restitution;
		::box2D::collision::B2ContactID id;
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2ContactPoint */ 
