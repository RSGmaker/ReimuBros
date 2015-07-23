#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJoint
#define INCLUDED_box2D_dynamics_joints_B2RevoluteJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Mat33)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec3)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2RevoluteJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2RevoluteJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2RevoluteJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2RevoluteJoint_obj OBJ_;
		B2RevoluteJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2RevoluteJointDef def);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2RevoluteJoint_obj > __new(::box2D::dynamics::joints::B2RevoluteJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2RevoluteJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2RevoluteJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );

		virtual ::box2D::common::math::B2Vec2 getReactionForce( Float inv_dt);

		virtual Float getReactionTorque( Float inv_dt);

		virtual Float getJointAngle( );
		Dynamic getJointAngle_dyn();

		virtual Float getJointSpeed( );
		Dynamic getJointSpeed_dyn();

		virtual bool isLimitEnabled( );
		Dynamic isLimitEnabled_dyn();

		virtual Void enableLimit( bool flag);
		Dynamic enableLimit_dyn();

		virtual Float getLowerLimit( );
		Dynamic getLowerLimit_dyn();

		virtual Float getUpperLimit( );
		Dynamic getUpperLimit_dyn();

		virtual Void setLimits( Float lower,Float upper);
		Dynamic setLimits_dyn();

		virtual bool isMotorEnabled( );
		Dynamic isMotorEnabled_dyn();

		virtual Void enableMotor( bool flag);
		Dynamic enableMotor_dyn();

		virtual Void setMotorSpeed( Float speed);
		Dynamic setMotorSpeed_dyn();

		virtual Float getMotorSpeed( );
		Dynamic getMotorSpeed_dyn();

		virtual Void setMaxMotorTorque( Float torque);
		Dynamic setMaxMotorTorque_dyn();

		virtual Float getMotorTorque( );
		Dynamic getMotorTorque_dyn();

		::box2D::common::math::B2Mat22 K;
		::box2D::common::math::B2Mat22 K1;
		::box2D::common::math::B2Mat22 K2;
		::box2D::common::math::B2Mat22 K3;
		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		::box2D::common::math::B2Vec3 impulse3;
		::box2D::common::math::B2Vec2 impulse2;
		::box2D::common::math::B2Vec2 reduced;
		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual bool solvePositionConstraints( Float baumgarte);

		::box2D::common::math::B2Vec2 m_localAnchor1;
		::box2D::common::math::B2Vec2 m_localAnchor2;
		::box2D::common::math::B2Vec3 m_impulse;
		Float m_motorImpulse;
		::box2D::common::math::B2Mat33 m_mass;
		Float m_motorMass;
		bool m_enableMotor;
		Float m_maxMotorTorque;
		Float m_motorSpeed;
		bool m_enableLimit;
		Float m_referenceAngle;
		Float m_lowerAngle;
		Float m_upperAngle;
		int m_limitState;
		static ::box2D::common::math::B2Vec2 tImpulse;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2RevoluteJoint */ 
