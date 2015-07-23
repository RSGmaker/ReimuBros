#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_joints__B2JointType_B2JointType_Impl_
#include <box2D/dynamics/joints/_B2JointType/B2JointType_Impl_.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{
namespace _B2JointType{

Void B2JointType_Impl__obj::__construct()
{
	return null();
}

//B2JointType_Impl__obj::~B2JointType_Impl__obj() { }

Dynamic B2JointType_Impl__obj::__CreateEmpty() { return  new B2JointType_Impl__obj; }
hx::ObjectPtr< B2JointType_Impl__obj > B2JointType_Impl__obj::__new()
{  hx::ObjectPtr< B2JointType_Impl__obj > result = new B2JointType_Impl__obj();
	result->__construct();
	return result;}

Dynamic B2JointType_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2JointType_Impl__obj > result = new B2JointType_Impl__obj();
	result->__construct();
	return result;}

int B2JointType_Impl__obj::UNKNOWN_JOINT;

int B2JointType_Impl__obj::REVOLUTE_JOINT;

int B2JointType_Impl__obj::PRISMATIC_JOINT;

int B2JointType_Impl__obj::DISTANCE_JOINT;

int B2JointType_Impl__obj::PULLEY_JOINT;

int B2JointType_Impl__obj::MOUSE_JOINT;

int B2JointType_Impl__obj::GEAR_JOINT;

int B2JointType_Impl__obj::LINE_JOINT;

int B2JointType_Impl__obj::WELD_JOINT;

int B2JointType_Impl__obj::FRICTION_JOINT;


B2JointType_Impl__obj::B2JointType_Impl__obj()
{
}

Dynamic B2JointType_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic B2JointType_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2JointType_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("UNKNOWN_JOINT"),
	HX_CSTRING("REVOLUTE_JOINT"),
	HX_CSTRING("PRISMATIC_JOINT"),
	HX_CSTRING("DISTANCE_JOINT"),
	HX_CSTRING("PULLEY_JOINT"),
	HX_CSTRING("MOUSE_JOINT"),
	HX_CSTRING("GEAR_JOINT"),
	HX_CSTRING("LINE_JOINT"),
	HX_CSTRING("WELD_JOINT"),
	HX_CSTRING("FRICTION_JOINT"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::UNKNOWN_JOINT,"UNKNOWN_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::REVOLUTE_JOINT,"REVOLUTE_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::PRISMATIC_JOINT,"PRISMATIC_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::DISTANCE_JOINT,"DISTANCE_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::PULLEY_JOINT,"PULLEY_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::MOUSE_JOINT,"MOUSE_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::GEAR_JOINT,"GEAR_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::LINE_JOINT,"LINE_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::WELD_JOINT,"WELD_JOINT");
	HX_MARK_MEMBER_NAME(B2JointType_Impl__obj::FRICTION_JOINT,"FRICTION_JOINT");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::UNKNOWN_JOINT,"UNKNOWN_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::REVOLUTE_JOINT,"REVOLUTE_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::PRISMATIC_JOINT,"PRISMATIC_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::DISTANCE_JOINT,"DISTANCE_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::PULLEY_JOINT,"PULLEY_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::MOUSE_JOINT,"MOUSE_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::GEAR_JOINT,"GEAR_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::LINE_JOINT,"LINE_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::WELD_JOINT,"WELD_JOINT");
	HX_VISIT_MEMBER_NAME(B2JointType_Impl__obj::FRICTION_JOINT,"FRICTION_JOINT");
};

#endif

Class B2JointType_Impl__obj::__mClass;

void B2JointType_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints._B2JointType.B2JointType_Impl_"), hx::TCanCast< B2JointType_Impl__obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void B2JointType_Impl__obj::__boot()
{
	UNKNOWN_JOINT= (int)0;
	REVOLUTE_JOINT= (int)1;
	PRISMATIC_JOINT= (int)2;
	DISTANCE_JOINT= (int)3;
	PULLEY_JOINT= (int)4;
	MOUSE_JOINT= (int)5;
	GEAR_JOINT= (int)6;
	LINE_JOINT= (int)7;
	WELD_JOINT= (int)8;
	FRICTION_JOINT= (int)9;
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
} // end namespace _B2JointType
