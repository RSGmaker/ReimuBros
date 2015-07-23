#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJoint
#define INCLUDED_box2D_dynamics_joints_B2WeldJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Mat33)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec3)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2WeldJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2WeldJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2WeldJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2WeldJoint_obj OBJ_;
		B2WeldJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2WeldJointDef def);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2WeldJoint_obj > __new(::box2D::dynamics::joints::B2WeldJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2WeldJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2WeldJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );

		virtual ::box2D::common::math::B2Vec2 getReactionForce( Float inv_dt);

		virtual Float getReactionTorque( Float inv_dt);

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual bool solvePositionConstraints( Float baumgarte);

		::box2D::common::math::B2Vec2 m_localAnchorA;
		::box2D::common::math::B2Vec2 m_localAnchorB;
		Float m_referenceAngle;
		::box2D::common::math::B2Vec3 m_impulse;
		::box2D::common::math::B2Mat33 m_mass;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2WeldJoint */ 
