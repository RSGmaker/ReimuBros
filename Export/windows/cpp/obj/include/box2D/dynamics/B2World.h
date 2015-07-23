#ifndef INCLUDED_box2D_dynamics_B2World
#define INCLUDED_box2D_dynamics_B2World

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,IBroadPhase)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS2(box2D,common,B2Color)
HX_DECLARE_CLASS3(box2D,common,math,B2Sweep)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2BodyDef)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactFilter)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactListener)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactManager)
HX_DECLARE_CLASS2(box2D,dynamics,B2DebugDraw)
HX_DECLARE_CLASS2(box2D,dynamics,B2DestructionListener)
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS2(box2D,dynamics,B2Island)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS2(box2D,dynamics,B2World)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactSolver)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2Controller)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointDef)
namespace box2D{
namespace dynamics{


class HXCPP_CLASS_ATTRIBUTES  B2World_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2World_obj OBJ_;
		B2World_obj();
		Void __construct(::box2D::common::math::B2Vec2 gravity,bool doSleep);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2World_obj > __new(::box2D::common::math::B2Vec2 gravity,bool doSleep);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2World_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2World"); }

		virtual Void setDestructionListener( ::box2D::dynamics::B2DestructionListener listener);
		Dynamic setDestructionListener_dyn();

		virtual Void setContactFilter( ::box2D::dynamics::B2ContactFilter filter);
		Dynamic setContactFilter_dyn();

		virtual Void setContactListener( ::box2D::dynamics::B2ContactListener listener);
		Dynamic setContactListener_dyn();

		virtual Void setDebugDraw( ::box2D::dynamics::B2DebugDraw debugDraw);
		Dynamic setDebugDraw_dyn();

		virtual Void setBroadPhase( ::box2D::collision::IBroadPhase broadPhase);
		Dynamic setBroadPhase_dyn();

		virtual Void validate( );
		Dynamic validate_dyn();

		virtual int getProxyCount( );
		Dynamic getProxyCount_dyn();

		virtual ::box2D::dynamics::B2Body createBody( ::box2D::dynamics::B2BodyDef def);
		Dynamic createBody_dyn();

		virtual Void destroyBody( ::box2D::dynamics::B2Body b);
		Dynamic destroyBody_dyn();

		virtual ::box2D::dynamics::joints::B2Joint createJoint( ::box2D::dynamics::joints::B2JointDef def);
		Dynamic createJoint_dyn();

		virtual Void destroyJoint( ::box2D::dynamics::joints::B2Joint j);
		Dynamic destroyJoint_dyn();

		virtual ::box2D::dynamics::controllers::B2Controller addController( ::box2D::dynamics::controllers::B2Controller c);
		Dynamic addController_dyn();

		virtual Void removeController( ::box2D::dynamics::controllers::B2Controller c);
		Dynamic removeController_dyn();

		virtual ::box2D::dynamics::controllers::B2Controller createController( ::box2D::dynamics::controllers::B2Controller controller);
		Dynamic createController_dyn();

		virtual Void destroyController( ::box2D::dynamics::controllers::B2Controller controller);
		Dynamic destroyController_dyn();

		virtual Void setWarmStarting( bool flag);
		Dynamic setWarmStarting_dyn();

		virtual Void setContinuousPhysics( bool flag);
		Dynamic setContinuousPhysics_dyn();

		virtual int getBodyCount( );
		Dynamic getBodyCount_dyn();

		virtual int getJointCount( );
		Dynamic getJointCount_dyn();

		virtual int getContactCount( );
		Dynamic getContactCount_dyn();

		virtual Void setGravity( ::box2D::common::math::B2Vec2 gravity);
		Dynamic setGravity_dyn();

		virtual ::box2D::common::math::B2Vec2 getGravity( );
		Dynamic getGravity_dyn();

		virtual ::box2D::dynamics::B2Body getGroundBody( );
		Dynamic getGroundBody_dyn();

		virtual Void step( Float dt,int velocityIterations,int positionIterations);
		Dynamic step_dyn();

		virtual Void clearForces( );
		Dynamic clearForces_dyn();

		virtual Void drawDebugData( );
		Dynamic drawDebugData_dyn();

		virtual Void queryAABB( Dynamic callbackMethod,::box2D::collision::B2AABB aabb);
		Dynamic queryAABB_dyn();

		virtual Void queryShape( Dynamic callbackMethod,::box2D::collision::shapes::B2Shape shape,::box2D::common::math::B2Transform transform);
		Dynamic queryShape_dyn();

		virtual Void queryPoint( Dynamic callbackMethod,::box2D::common::math::B2Vec2 p);
		Dynamic queryPoint_dyn();

		virtual Void rayCast( Dynamic callbackMethod,::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2);
		Dynamic rayCast_dyn();

		virtual ::box2D::dynamics::B2Fixture rayCastOne( ::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2);
		Dynamic rayCastOne_dyn();

		virtual Array< ::Dynamic > rayCastAll( ::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2);
		Dynamic rayCastAll_dyn();

		virtual ::box2D::dynamics::B2Body getBodyList( );
		Dynamic getBodyList_dyn();

		virtual ::box2D::dynamics::joints::B2Joint getJointList( );
		Dynamic getJointList_dyn();

		virtual ::box2D::dynamics::contacts::B2Contact getContactList( );
		Dynamic getContactList_dyn();

		virtual bool isLocked( );
		Dynamic isLocked_dyn();

		Array< ::Dynamic > s_stack;
		virtual Void solve( ::box2D::dynamics::B2TimeStep step);
		Dynamic solve_dyn();

		virtual Void solveTOI( ::box2D::dynamics::B2TimeStep step);
		Dynamic solveTOI_dyn();

		virtual Void drawJoint( ::box2D::dynamics::joints::B2Joint joint);
		Dynamic drawJoint_dyn();

		virtual Void drawShape( ::box2D::collision::shapes::B2Shape shape,::box2D::common::math::B2Transform xf,::box2D::common::B2Color color);
		Dynamic drawShape_dyn();

		int m_flags;
		::box2D::dynamics::B2ContactManager m_contactManager;
		::box2D::dynamics::contacts::B2ContactSolver m_contactSolver;
		::box2D::dynamics::B2Island m_island;
		::box2D::dynamics::B2Body m_bodyList;
		::box2D::dynamics::joints::B2Joint m_jointList;
		::box2D::dynamics::contacts::B2Contact m_contactList;
		int m_bodyCount;
		int m_contactCount;
		int m_jointCount;
		::box2D::dynamics::controllers::B2Controller m_controllerList;
		int m_controllerCount;
		::box2D::common::math::B2Vec2 m_gravity;
		bool m_allowSleep;
		::box2D::dynamics::B2Body m_groundBody;
		::box2D::dynamics::B2DestructionListener m_destructionListener;
		::box2D::dynamics::B2DebugDraw m_debugDraw;
		Float m_inv_dt0;
		static ::box2D::dynamics::B2TimeStep s_timestep2;
		static ::box2D::common::math::B2Transform s_xf;
		static ::box2D::common::math::B2Sweep s_backupA;
		static ::box2D::common::math::B2Sweep s_backupB;
		static ::box2D::dynamics::B2TimeStep s_timestep;
		static Array< ::Dynamic > s_queue;
		static ::box2D::common::B2Color s_jointColor;
		static bool m_warmStarting;
		static bool m_continuousPhysics;
		static int e_newFixture;
		static int e_locked;
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2World */ 
