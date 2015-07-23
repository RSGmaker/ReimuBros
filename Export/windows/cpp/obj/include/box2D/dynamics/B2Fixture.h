#ifndef INCLUDED_box2D_dynamics_B2Fixture
#define INCLUDED_box2D_dynamics_B2Fixture

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS2(box2D,collision,IBroadPhase)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS2(box2D,dynamics,B2FilterData)
HX_DECLARE_CLASS2(box2D,dynamics,B2Fixture)
HX_DECLARE_CLASS2(box2D,dynamics,B2FixtureDef)
namespace box2D{
namespace dynamics{


class HXCPP_CLASS_ATTRIBUTES  B2Fixture_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Fixture_obj OBJ_;
		B2Fixture_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Fixture_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Fixture_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2Fixture"); }

		virtual int getType( );
		Dynamic getType_dyn();

		virtual ::box2D::collision::shapes::B2Shape getShape( );
		Dynamic getShape_dyn();

		virtual Void setSensor( bool sensor);
		Dynamic setSensor_dyn();

		virtual bool isSensor( );
		Dynamic isSensor_dyn();

		virtual Void setFilterData( ::box2D::dynamics::B2FilterData filter);
		Dynamic setFilterData_dyn();

		virtual ::box2D::dynamics::B2FilterData getFilterData( );
		Dynamic getFilterData_dyn();

		virtual ::box2D::dynamics::B2Body getBody( );
		Dynamic getBody_dyn();

		virtual ::box2D::dynamics::B2Fixture getNext( );
		Dynamic getNext_dyn();

		virtual Dynamic getUserData( );
		Dynamic getUserData_dyn();

		virtual Void SetUserData( Dynamic data);
		Dynamic SetUserData_dyn();

		virtual bool testPoint( ::box2D::common::math::B2Vec2 p);
		Dynamic testPoint_dyn();

		virtual bool rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input);
		Dynamic rayCast_dyn();

		virtual ::box2D::collision::shapes::B2MassData getMassData( ::box2D::collision::shapes::B2MassData massData);
		Dynamic getMassData_dyn();

		virtual Void setDensity( Float density);
		Dynamic setDensity_dyn();

		virtual Float getDensity( );
		Dynamic getDensity_dyn();

		virtual Float getFriction( );
		Dynamic getFriction_dyn();

		virtual Void setFriction( Float friction);
		Dynamic setFriction_dyn();

		virtual Float getRestitution( );
		Dynamic getRestitution_dyn();

		virtual Void setRestitution( Float restitution);
		Dynamic setRestitution_dyn();

		virtual ::box2D::collision::B2AABB getAABB( );
		Dynamic getAABB_dyn();

		virtual Void create( ::box2D::dynamics::B2Body body,::box2D::common::math::B2Transform xf,::box2D::dynamics::B2FixtureDef def);
		Dynamic create_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void createProxy( ::box2D::collision::IBroadPhase broadPhase,::box2D::common::math::B2Transform xf);
		Dynamic createProxy_dyn();

		virtual Void destroyProxy( ::box2D::collision::IBroadPhase broadPhase);
		Dynamic destroyProxy_dyn();

		virtual Void synchronize( ::box2D::collision::IBroadPhase broadPhase,::box2D::common::math::B2Transform transform1,::box2D::common::math::B2Transform transform2);
		Dynamic synchronize_dyn();

		::box2D::collision::shapes::B2MassData m_massData;
		::box2D::collision::B2AABB m_aabb;
		Float m_density;
		::box2D::dynamics::B2Fixture m_next;
		::box2D::dynamics::B2Body m_body;
		::box2D::collision::shapes::B2Shape m_shape;
		Float m_friction;
		Float m_restitution;
		Dynamic m_proxy;
		::box2D::dynamics::B2FilterData m_filter;
		bool m_isSensor;
		Dynamic m_userData;
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2Fixture */ 
