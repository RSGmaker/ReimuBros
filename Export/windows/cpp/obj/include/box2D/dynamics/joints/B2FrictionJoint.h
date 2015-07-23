#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJoint
#define INCLUDED_box2D_dynamics_joints_B2FrictionJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2FrictionJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2FrictionJointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2FrictionJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2FrictionJoint_obj OBJ_;
		B2FrictionJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2FrictionJointDef def);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2FrictionJoint_obj > __new(::box2D::dynamics::joints::B2FrictionJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2FrictionJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2FrictionJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );

		virtual ::box2D::common::math::B2Vec2 getReactionForce( Float inv_dt);

		virtual Float getReactionTorque( Float inv_dt);

		virtual Void setMaxForce( Float force);
		Dynamic setMaxForce_dyn();

		virtual Float getMaxForce( );
		Dynamic getMaxForce_dyn();

		virtual Void setMaxTorque( Float torque);
		Dynamic setMaxTorque_dyn();

		virtual Float getMaxTorque( );
		Dynamic getMaxTorque_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual bool solvePositionConstraints( Float baumgarte);

		::box2D::common::math::B2Vec2 m_localAnchorA;
		::box2D::common::math::B2Vec2 m_localAnchorB;
		::box2D::common::math::B2Mat22 m_linearMass;
		Float m_angularMass;
		::box2D::common::math::B2Vec2 m_linearImpulse;
		Float m_angularImpulse;
		Float m_maxForce;
		Float m_maxTorque;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2FrictionJoint */ 
