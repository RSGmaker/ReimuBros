#ifndef INCLUDED_box2D_dynamics_joints_B2JointEdge
#define INCLUDED_box2D_dynamics_joints_B2JointEdge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2Joint)
HX_DECLARE_CLASS3(box2D,dynamics,joints,B2JointEdge)
namespace box2D{
namespace dynamics{
namespace joints{


class HXCPP_CLASS_ATTRIBUTES  B2JointEdge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2JointEdge_obj OBJ_;
		B2JointEdge_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2JointEdge_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2JointEdge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2JointEdge"); }

		::box2D::dynamics::B2Body other;
		::box2D::dynamics::joints::B2Joint joint;
		::box2D::dynamics::joints::B2JointEdge prev;
		::box2D::dynamics::joints::B2JointEdge next;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints

#endif /* INCLUDED_box2D_dynamics_joints_B2JointEdge */ 
