#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraint
#define INCLUDED_box2D_dynamics_contacts_B2ContactConstraint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS2(box2D,collision,B2ManifoldType)
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraint)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraintPoint)
namespace box2D{
namespace dynamics{
namespace contacts{


class HXCPP_CLASS_ATTRIBUTES  B2ContactConstraint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactConstraint_obj OBJ_;
		B2ContactConstraint_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2ContactConstraint_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2ContactConstraint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactConstraint"); }

		Array< ::Dynamic > points;
		::box2D::common::math::B2Vec2 localPlaneNormal;
		::box2D::common::math::B2Vec2 localPoint;
		::box2D::common::math::B2Vec2 normal;
		::box2D::common::math::B2Mat22 normalMass;
		::box2D::common::math::B2Mat22 K;
		::box2D::dynamics::B2Body bodyA;
		::box2D::dynamics::B2Body bodyB;
		::box2D::collision::B2ManifoldType type;
		Float radius;
		Float friction;
		Float restitution;
		int pointCount;
		::box2D::collision::B2Manifold manifold;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2ContactConstraint */ 
