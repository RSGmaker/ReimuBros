#ifndef INCLUDED_box2D_dynamics_joints__B2JointType_B2JointType_Impl_
#define INCLUDED_box2D_dynamics_joints__B2JointType_B2JointType_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(box2D,dynamics,joints,_B2JointType,B2JointType_Impl_)
namespace box2D{
namespace dynamics{
namespace joints{
namespace _B2JointType{


class HXCPP_CLASS_ATTRIBUTES  B2JointType_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2JointType_Impl__obj OBJ_;
		B2JointType_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2JointType_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2JointType_Impl__obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2JointType_Impl_"); }

		static int UNKNOWN_JOINT;
		static int REVOLUTE_JOINT;
		static int PRISMATIC_JOINT;
		static int DISTANCE_JOINT;
		static int PULLEY_JOINT;
		static int MOUSE_JOINT;
		static int GEAR_JOINT;
		static int LINE_JOINT;
		static int WELD_JOINT;
		static int FRICTION_JOINT;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
} // end namespace _B2JointType

#endif /* INCLUDED_box2D_dynamics_joints__B2JointType_B2JointType_Impl_ */ 
