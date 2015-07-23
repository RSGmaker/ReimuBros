#ifndef INCLUDED_box2D_dynamics_B2Island
#define INCLUDED_box2D_dynamics_B2Island

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactImpulse)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactListener)
HX_DECLARE_CLASS2(box2D,dynamics,B2Island)
HX_DECLARE_CLASS2(box2D,dynamics,B2TimeStep)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraint)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactSolver)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
namespace box2D{
namespace dynamics{


class HXCPP_CLASS_ATTRIBUTES  B2Island_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Island_obj OBJ_;
		B2Island_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Island_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Island_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Island"); }

		virtual Void initialize( int bodyCapacity,int contactCapacity,int jointCapacity,Dynamic allocator,::box2D::dynamics::B2ContactListener listener,::box2D::dynamics::contacts::B2ContactSolver contactSolver);
		Dynamic initialize_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void solve( ::box2D::dynamics::B2TimeStep step,::box2D::common::math::B2Vec2 gravity,bool allowSleep);
		Dynamic solve_dyn();

		virtual Void solveTOI( ::box2D::dynamics::B2TimeStep subStep);
		Dynamic solveTOI_dyn();

		virtual Void report( Array< ::Dynamic > constraints);
		Dynamic report_dyn();

		virtual Void addBody( ::box2D::dynamics::B2Body body);
		Dynamic addBody_dyn();

		virtual Void addContact( ::box2D::dynamics::contacts::B2Contact contact);
		Dynamic addContact_dyn();

		virtual Void addJoint( ::box2D::dynamics::joints::B2Joint joint);
		Dynamic addJoint_dyn();

		Dynamic m_allocator;
		::box2D::dynamics::B2ContactListener m_listener;
		::box2D::dynamics::contacts::B2ContactSolver m_contactSolver;
		Array< ::Dynamic > m_bodies;
		Array< ::Dynamic > m_contacts;
		Array< ::Dynamic > m_joints;
		int m_bodyCount;
		int m_jointCount;
		int m_contactCount;
		int m_bodyCapacity;
		int m_contactCapacity;
		int m_jointCapacity;
		static ::box2D::dynamics::B2ContactImpulse s_impulse;
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2Island */ 
