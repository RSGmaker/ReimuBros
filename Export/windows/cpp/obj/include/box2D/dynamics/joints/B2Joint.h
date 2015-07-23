#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#define INCLUDED_box2D_dynamics_joints_B2Joint

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointEdge)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2Joint_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Joint_obj OBJ_;
		B2Joint_obj();
		Void __construct(::box2D::dynamics::joints::B2JointDef def);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Joint_obj > __new(::box2D::dynamics::joints::B2JointDef def);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Joint_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Joint"); }

		virtual int getType( );
		Dynamic getType_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorA( );
		Dynamic getAnchorA_dyn();

		virtual ::box2D::common::math::B2Vec2 getAnchorB( );
		Dynamic getAnchorB_dyn();

		virtual ::box2D::common::math::B2Vec2 getReactionForce( Float inv_dt);
		Dynamic getReactionForce_dyn();

		virtual Float getReactionTorque( Float inv_dt);
		Dynamic getReactionTorque_dyn();

		virtual ::box2D::dynamics::B2Body getBodyA( );
		Dynamic getBodyA_dyn();

		virtual ::box2D::dynamics::B2Body getBodyB( );
		Dynamic getBodyB_dyn();

		virtual ::box2D::dynamics::joints::B2Joint getNext( );
		Dynamic getNext_dyn();

		virtual Dynamic getUserData( );
		Dynamic getUserData_dyn();

		virtual Void setUserData( Dynamic data);
		Dynamic setUserData_dyn();

		virtual bool isActive( );
		Dynamic isActive_dyn();

		virtual Void initVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic initVelocityConstraints_dyn();

		virtual Void solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveVelocityConstraints_dyn();

		virtual Void finalizeVelocityConstraints( );
		Dynamic finalizeVelocityConstraints_dyn();

		virtual bool solvePositionConstraints( Float baumgarte);
		Dynamic solvePositionConstraints_dyn();

		int m_type;
		::box2D::dynamics::joints::B2Joint m_prev;
		::box2D::dynamics::joints::B2Joint m_next;
		::box2D::dynamics::joints::B2JointEdge m_edgeA;
		::box2D::dynamics::joints::B2JointEdge m_edgeB;
		::box2D::dynamics::B2Body m_bodyA;
		::box2D::dynamics::B2Body m_bodyB;
		bool m_islandFlag;
		bool m_collideConnected;
		Dynamic m_userData;
		::box2D::common::math::B2Vec2 m_localCenterA;
		::box2D::common::math::B2Vec2 m_localCenterB;
		Float m_invMassA;
		Float m_invMassB;
		Float m_invIA;
		Float m_invIB;
		static ::box2D::dynamics::joints::B2Joint create( ::box2D::dynamics::joints::B2JointDef def,Dynamic allocator);
		static Dynamic create_dyn();

		static Void destroy( ::box2D::dynamics::joints::B2Joint joint,Dynamic allocator);
		static Dynamic destroy_dyn();

};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2Joint */ 
