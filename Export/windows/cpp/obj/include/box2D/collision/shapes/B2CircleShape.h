#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#define INCLUDED_box2D_collision_shapes_B2CircleShape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/collision/shapes/B2Shape.h>
HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2CircleShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{
namespace shapes{


class HXCPP_CLASS_ATTRIBUTES  B2CircleShape_obj : public ::box2D::collision::shapes::B2Shape_obj{
	public:
		typedef ::box2D::collision::shapes::B2Shape_obj super;
		typedef B2CircleShape_obj OBJ_;
		B2CircleShape_obj();
		Void __construct(hx::Null< Float >  __o_radius);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2CircleShape_obj > __new(hx::Null< Float >  __o_radius);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2CircleShape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2CircleShape"); }

		virtual ::box2D::collision::shapes::B2Shape copy( );

		virtual Void set( ::box2D::collision::shapes::B2Shape other);

		virtual bool testPoint( ::box2D::common::math::B2Transform transform,::box2D::common::math::B2Vec2 p);

		virtual bool rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform);

		virtual Void computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform transform);

		virtual Void computeMass( ::box2D::collision::shapes::B2MassData massData,Float density);

		virtual Float computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,Float offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c);

		virtual ::box2D::common::math::B2Vec2 getLocalPosition( );
		Dynamic getLocalPosition_dyn();

		virtual Void setLocalPosition( ::box2D::common::math::B2Vec2 position);
		Dynamic setLocalPosition_dyn();

		virtual Float getRadius( );
		Dynamic getRadius_dyn();

		virtual Void setRadius( Float radius);
		Dynamic setRadius_dyn();

		::box2D::common::math::B2Vec2 m_p;
};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes

#endif /* INCLUDED_box2D_collision_shapes_B2CircleShape */ 
