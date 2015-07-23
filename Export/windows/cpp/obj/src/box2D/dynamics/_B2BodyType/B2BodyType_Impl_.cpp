#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics__B2BodyType_B2BodyType_Impl_
#include <box2D/dynamics/_B2BodyType/B2BodyType_Impl_.h>
#endif
namespace box2D{
namespace dynamics{
namespace _B2BodyType{

Void B2BodyType_Impl__obj::__construct()
{
	return null();
}

//B2BodyType_Impl__obj::~B2BodyType_Impl__obj() { }

Dynamic B2BodyType_Impl__obj::__CreateEmpty() { return  new B2BodyType_Impl__obj; }
hx::ObjectPtr< B2BodyType_Impl__obj > B2BodyType_Impl__obj::__new()
{  hx::ObjectPtr< B2BodyType_Impl__obj > result = new B2BodyType_Impl__obj();
	result->__construct();
	return result;}

Dynamic B2BodyType_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2BodyType_Impl__obj > result = new B2BodyType_Impl__obj();
	result->__construct();
	return result;}

int B2BodyType_Impl__obj::STATIC_BODY;

int B2BodyType_Impl__obj::KINEMATIC_BODY;

int B2BodyType_Impl__obj::DYNAMIC_BODY;


B2BodyType_Impl__obj::B2BodyType_Impl__obj()
{
}

Dynamic B2BodyType_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic B2BodyType_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2BodyType_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("STATIC_BODY"),
	HX_CSTRING("KINEMATIC_BODY"),
	HX_CSTRING("DYNAMIC_BODY"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2BodyType_Impl__obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2BodyType_Impl__obj::STATIC_BODY,"STATIC_BODY");
	HX_MARK_MEMBER_NAME(B2BodyType_Impl__obj::KINEMATIC_BODY,"KINEMATIC_BODY");
	HX_MARK_MEMBER_NAME(B2BodyType_Impl__obj::DYNAMIC_BODY,"DYNAMIC_BODY");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2BodyType_Impl__obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2BodyType_Impl__obj::STATIC_BODY,"STATIC_BODY");
	HX_VISIT_MEMBER_NAME(B2BodyType_Impl__obj::KINEMATIC_BODY,"KINEMATIC_BODY");
	HX_VISIT_MEMBER_NAME(B2BodyType_Impl__obj::DYNAMIC_BODY,"DYNAMIC_BODY");
};

#endif

Class B2BodyType_Impl__obj::__mClass;

void B2BodyType_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics._B2BodyType.B2BodyType_Impl_"), hx::TCanCast< B2BodyType_Impl__obj> ,sStaticFields,sMemberFields,
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

void B2BodyType_Impl__obj::__boot()
{
	STATIC_BODY= (int)0;
	KINEMATIC_BODY= (int)1;
	DYNAMIC_BODY= (int)2;
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace _B2BodyType
