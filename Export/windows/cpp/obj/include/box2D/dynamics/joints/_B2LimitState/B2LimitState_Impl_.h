#ifndef INCLUDED_box2D_dynamics_joints__B2LimitState_B2LimitState_Impl_
#define INCLUDED_box2D_dynamics_joints__B2LimitState_B2LimitState_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(box2D,dynamics,joints,_B2LimitState,B2LimitState_Impl_)
namespace box2D{
namespace dynamics{
namespace joints{
namespace _B2LimitState{


class HXCPP_CLASS_ATTRIBUTES  B2LimitState_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2LimitState_Impl__obj OBJ_;
		B2LimitState_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2LimitState_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2LimitState_Impl__obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2LimitState_Impl_"); }

		static int INACTIVE_LIMIT;
		static int AT_LOWER_LIMIT;
		static int AT_UPPER_LIMIT;
		static int EQUAL_LIMITS;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
} // end namespace _B2LimitState

#endif /* INCLUDED_box2D_dynamics_joints__B2LimitState_B2LimitState_Impl_ */ 
