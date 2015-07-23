#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJoint
#define INCLUDED_box2D_dynamics_joints_B2PrismaticJoint

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
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PrismaticJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PrismaticJointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2PrismaticJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2PrismaticJoint_obj OBJ_;
		B2PrismaticJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2PrismaticJointDef def);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2PrismaticJoint_obj > __new(::box2D::dynamics::joints::B2PrismaticJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2PrismaticJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2PrismaticJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );

		virtual ::box2D::common::math::B2Vec2 getReactionForce( Float inv_dt);

		virtual Float getReactionTorque( Float inv_dt);

		virtual Float getJointTranslation( );
		Dynamic getJointTranslation_dyn();

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

		virtual Void setMaxMotorForce( Float force);
		Dynamic setMaxMotorForce_dyn();

		virtual Float getMotorForce( );
		Dynamic getMotorForce_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual bool solvePositionConstraints( Float baumgarte);

		::box2D::common::math::B2Vec2 m_localAnchor1;
		::box2D::common::math::B2Vec2 m_localAnchor2;
		::box2D::common::math::B2Vec2 m_localXAxis1;
		::box2D::common::math::B2Vec2 m_localYAxis1;
		Float m_refAngle;
		::box2D::common::math::B2Vec2 m_axis;
		::box2D::common::math::B2Vec2 m_perp;
		Float m_s1;
		Float m_s2;
		Float m_a1;
		Float m_a2;
		::box2D::common::math::B2Mat33 m_K;
		::box2D::common::math::B2Vec3 m_impulse;
		Float m_motorMass;
		Float m_motorImpulse;
		Float m_lowerTranslation;
		Float m_upperTranslation;
		Float m_maxMotorForce;
		Float m_motorSpeed;
		bool m_enableLimit;
		bool m_enableMotor;
		int m_limitState;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2PrismaticJoint */ 
