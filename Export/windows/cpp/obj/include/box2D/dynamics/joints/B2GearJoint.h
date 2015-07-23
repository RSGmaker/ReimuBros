#ifndef INCLUDED_box2D_dynamics_joints_B2GearJoint
#define INCLUDED_box2D_dynamics_joints_B2GearJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2GearJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2GearJointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Jacobian)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2PrismaticJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2RevoluteJoint)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2GearJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2GearJoint_obj OBJ_;
		B2GearJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2GearJointDef def);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2GearJoint_obj > __new(::box2D::dynamics::joints::B2GearJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2GearJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2GearJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );

		virtual ::box2D::common::math::B2Vec2 getReactionForce( Float inv_dt);

		virtual Float getReactionTorque( Float inv_dt);

		virtual Float getRatio( );
		Dynamic getRatio_dyn();

		virtual Void setRatio( Float ratio);
		Dynamic setRatio_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual bool solvePositionConstraints( Float baumgarte);

		::box2D::dynamics::B2Body m_ground1;
		::box2D::dynamics::B2Body m_ground2;
		::box2D::dynamics::joints::B2RevoluteJoint m_revolute1;
		::box2D::dynamics::joints::B2PrismaticJoint m_prismatic1;
		::box2D::dynamics::joints::B2RevoluteJoint m_revolute2;
		::box2D::dynamics::joints::B2PrismaticJoint m_prismatic2;
		::box2D::common::math::B2Vec2 m_groundAnchor1;
		::box2D::common::math::B2Vec2 m_groundAnchor2;
		::box2D::common::math::B2Vec2 m_localAnchor1;
		::box2D::common::math::B2Vec2 m_localAnchor2;
		::box2D::dynamics::joints::B2Jacobian m_J;
		Float m_constant;
		Float m_ratio;
		Float m_mass;
		Float m_impulse;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2GearJoint */ 
