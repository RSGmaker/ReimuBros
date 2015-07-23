#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#define INCLUDED_box2D_dynamics_controllers_B2ControllerEdge

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2Body)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2Controller)
HX_DECLARE_CLASS3(box2D,dynamics,controllers,B2ControllerEdge)
namespace box2D{
namespace dynamics{
namespace controllers{


class HXCPP_CLASS_ATTRIBUTES  B2ControllerEdge_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ControllerEdge_obj OBJ_;
		B2ControllerEdge_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2ControllerEdge_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2ControllerEdge_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ControllerEdge"); }

		::box2D::dynamics::controllers::B2Controller controller;
		::box2D::dynamics::B2Body body;
		::box2D::dynamics::controllers::B2ControllerEdge prevBody;
		::box2D::dynamics::controllers::B2ControllerEdge nextBody;
		::box2D::dynamics::controllers::B2ControllerEdge prevController;
		::box2D::dynamics::controllers::B2ControllerEdge nextController;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace controllers

#endif /* INCLUDED_box2D_dynamics_controllers_B2ControllerEdge */ 
