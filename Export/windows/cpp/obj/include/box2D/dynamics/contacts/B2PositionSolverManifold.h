#ifndef INCLUDED_box2D_dynamics_contacts_B2PositionSolverManifold
#define INCLUDED_box2D_dynamics_contacts_B2PositionSolverManifold

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2ContactConstraint)
HX_DECLARE_CLASS3(box2D,dynamics,contacts,B2PositionSolverManifold)
namespace box2D{
namespace dynamics{
namespace contacts{


class HXCPP_CLASS_ATTRIBUTES  B2PositionSolverManifold_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2PositionSolverManifold_obj OBJ_;
		B2PositionSolverManifold_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2PositionSolverManifold_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2PositionSolverManifold_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2PositionSolverManifold"); }

		virtual Void initialize( ::box2D::dynamics::contacts::B2ContactConstraint cc);
		Dynamic initialize_dyn();

		::box2D::common::math::B2Vec2 m_normal;
		Array< ::Dynamic > m_points;
		Array< Float > m_separations;
		static ::box2D::common::math::B2Vec2 circlePointA;
		static ::box2D::common::math::B2Vec2 circlePointB;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts

#endif /* INCLUDED_box2D_dynamics_contacts_B2PositionSolverManifold */ 
