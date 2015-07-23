#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJoint
#define INCLUDED_box2D_dynamics_joints_B2DistanceJoint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/dynamics/joints/B2Joint.h>
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2DistanceJoint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2DistanceJointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2DistanceJoint_obj : public ::box2D::dynamics::joints::B2Joint_obj{
	public:
		typedef ::box2D::dynamics::joints::B2Joint_obj super;
		typedef B2DistanceJoint_obj OBJ_;
		B2DistanceJoint_obj();
		Void __construct(::box2D::dynamics::joints::B2DistanceJointDef def);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2DistanceJoint_obj > __new(::box2D::dynamics::joints::B2DistanceJointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2DistanceJoint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DistanceJoint"); }

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );

		virtual ::box2D::common::math::B2Vec2 getReactionForce( Float inv_dt);

		virtual Float getReactionTorque( Float inv_dt);

		virtual Float getLength( );
		Dynamic getLength_dyn();

		virtual Void setLength( Float length);
		Dynamic setLength_dyn();

		virtual Float getFrequency( );
		Dynamic getFrequency_dyn();

		virtual Void setFrequency( Float hz);
		Dynamic setFrequency_dyn();

		virtual Float getDampingRatio( );
		Dynamic getDampingRatio_dyn();

		virtual Void setDampingRatio( Float ratio);
		Dynamic setDampingRatio_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);

		virtual bool solvePositionConstraints( Float baumgarte);

		::box2D::common::math::B2Vec2 m_localAnchor1;
		::box2D::common::math::B2Vec2 m_localAnchor2;
		::box2D::common::math::B2Vec2 m_u;
		Float m_frequencyHz;
		Float m_dampingRatio;
		Float m_gamma;
		Float m_bias;
		Float m_impulse;
		Float m_mass;
		Float m_length;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2DistanceJoint */ 
