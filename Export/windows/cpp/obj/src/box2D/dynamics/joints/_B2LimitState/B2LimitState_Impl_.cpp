#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_joints__B2LimitState_B2LimitState_Impl_
#include <box2D/dynamics/joints/_B2LimitState/B2LimitState_Impl_.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{
namespace _B2LimitState{

Void B2LimitState_Impl__obj::__construct()
{
	return null();
}

//B2LimitState_Impl__obj::~B2LimitState_Impl__obj() { }

Dynamic B2LimitState_Impl__obj::__CreateEmpty() { return  new B2LimitState_Impl__obj; }
hx::ObjectPtr< B2LimitState_Impl__obj > B2LimitState_Impl__obj::__new()
{  hx::ObjectPtr< B2LimitState_Impl__obj > result = new B2LimitState_Impl__obj();
	result->__construct();
	return result;}

Dynamic B2LimitState_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2LimitState_Impl__obj > result = new B2LimitState_Impl__obj();
	result->__construct();
	return result;}

int B2LimitState_Impl__obj::INACTIVE_LIMIT;

int B2LimitState_Impl__obj::AT_LOWER_LIMIT;

int B2LimitState_Impl__obj::AT_UPPER_LIMIT;

int B2LimitState_Impl__obj::EQUAL_LIMITS;


B2LimitState_Impl__obj::B2LimitState_Impl__obj()
{
}

Dynamic B2LimitState_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic B2LimitState_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2LimitState_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("INACTIVE_LIMIT"),
	HX_CSTRING("AT_LOWER_LIMIT"),
	HX_CSTRING("AT_UPPER_LIMIT"),
	HX_CSTRING("EQUAL_LIMITS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2LimitState_Impl__obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2LimitState_Impl__obj::INACTIVE_LIMIT,"INACTIVE_LIMIT");
	HX_MARK_MEMBER_NAME(B2LimitState_Impl__obj::AT_LOWER_LIMIT,"AT_LOWER_LIMIT");
	HX_MARK_MEMBER_NAME(B2LimitState_Impl__obj::AT_UPPER_LIMIT,"AT_UPPER_LIMIT");
	HX_MARK_MEMBER_NAME(B2LimitState_Impl__obj::EQUAL_LIMITS,"EQUAL_LIMITS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2LimitState_Impl__obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2LimitState_Impl__obj::INACTIVE_LIMIT,"INACTIVE_LIMIT");
	HX_VISIT_MEMBER_NAME(B2LimitState_Impl__obj::AT_LOWER_LIMIT,"AT_LOWER_LIMIT");
	HX_VISIT_MEMBER_NAME(B2LimitState_Impl__obj::AT_UPPER_LIMIT,"AT_UPPER_LIMIT");
	HX_VISIT_MEMBER_NAME(B2LimitState_Impl__obj::EQUAL_LIMITS,"EQUAL_LIMITS");
};

#endif

Class B2LimitState_Impl__obj::__mClass;

void B2LimitState_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints._B2LimitState.B2LimitState_Impl_"), hx::TCanCast< B2LimitState_Impl__obj> ,sStaticFields,sMemberFields,
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

void B2LimitState_Impl__obj::__boot()
{
	INACTIVE_LIMIT= (int)0;
	AT_LOWER_LIMIT= (int)1;
	AT_UPPER_LIMIT= (int)2;
	EQUAL_LIMITS= (int)3;
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
} // end namespace _B2LimitState
