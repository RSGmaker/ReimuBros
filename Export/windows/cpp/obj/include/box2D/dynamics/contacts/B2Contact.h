#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#define INCLUDED_box2D_dynamics_contacts_B2Contact

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS2(box2D,collision,B2TOIInput)
HX_DECLARE_CLASS2(box2D,collision,B2WorldManifold)
HX_DECLARE_CLASS3(box2D,common,math,B2Sweep)
HX_DECLARE_CLASS2(box2D,dynamics,B2ContactListener)
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2Contact)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactEdge)
namespace box2D{
namespace dynamics{
namespace contacts{


class HXCPP_CLASS_ATTRIBUTES  B2Contact_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Contact_obj OBJ_;
		B2Contact_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Contact_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Contact_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Contact"); }

		virtual ::box2D::collision::B2Manifold getManifold( );
		Dynamic getManifold_dyn();

		virtual Void getWorldManifold( ::box2D::collision::B2WorldManifold worldManifold);
		Dynamic getWorldManifold_dyn();

		virtual bool isTouching( );
		Dynamic isTouching_dyn();

		virtual bool isContinuous( );
		Dynamic isContinuous_dyn();

		virtual Void setSensor( bool sensor);
		Dynamic setSensor_dyn();

		virtual bool isSensor( );
		Dynamic isSensor_dyn();

		virtual Void setEnabled( bool flag);
		Dynamic setEnabled_dyn();

		virtual bool isEnabled( );
		Dynamic isEnabled_dyn();

		virtual ::box2D::dynamics::contacts::B2Contact getNext( );
		Dynamic getNext_dyn();

		virtual ::box2D::dynamics::B2Fixture getFixtureA( );
		Dynamic getFixtureA_dyn();

		virtual ::box2D::dynamics::B2Fixture getFixtureB( );
		Dynamic getFixtureB_dyn();

		virtual Void flagForFiltering( );
		Dynamic flagForFiltering_dyn();

		virtual Void reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB);
		Dynamic reset_dyn();

		virtual Void update( ::box2D::dynamics::B2ContactListener listener);
		Dynamic update_dyn();

		virtual Void evaluate( );
		Dynamic evaluate_dyn();

		virtual Float computeTOI( ::box2D::common::math::B2Sweep sweepA,::box2D::common::math::B2Sweep sweepB);
		Dynamic computeTOI_dyn();

		int m_flags;
		::box2D::dynamics::contacts::B2Contact m_prev;
		::box2D::dynamics::contacts::B2Contact m_next;
		::box2D::dynamics::contacts::B2ContactEdge m_nodeA;
		::box2D::dynamics::contacts::B2ContactEdge m_nodeB;
		::box2D::dynamics::B2Fixture m_fixtureA;
		::box2D::dynamics::B2Fixture m_fixtureB;
		::box2D::collision::B2Manifold m_manifold;
		::box2D::collision::B2Manifold m_oldManifold;
		Float m_toi;
		static int e_sensorFlag;
		static int e_continuousFlag;
		static int e_islandFlag;
		static int e_toiFlag;
		static int e_touchingFlag;
		static int e_enabledFlag;
		static int e_filterFlag;
		static ::box2D::collision::B2TOIInput s_input;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2Contact */ 
