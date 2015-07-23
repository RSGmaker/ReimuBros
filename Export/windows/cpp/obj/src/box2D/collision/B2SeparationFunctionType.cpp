#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2SeparationFunctionType
#include <box2D/collision/B2SeparationFunctionType.h>
#endif
namespace box2D{
namespace collision{

::box2D::collision::B2SeparationFunctionType B2SeparationFunctionType_obj::FACE_A;

::box2D::collision::B2SeparationFunctionType B2SeparationFunctionType_obj::FACE_B;

::box2D::collision::B2SeparationFunctionType B2SeparationFunctionType_obj::POINTS;

HX_DEFINE_CREATE_ENUM(B2SeparationFunctionType_obj)

int B2SeparationFunctionType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("FACE_A")) return 1;
	if (inName==HX_CSTRING("FACE_B")) return 2;
	if (inName==HX_CSTRING("POINTS")) return 0;
	return super::__FindIndex(inName);
}

int B2SeparationFunctionType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("FACE_A")) return 0;
	if (inName==HX_CSTRING("FACE_B")) return 0;
	if (inName==HX_CSTRING("POINTS")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic B2SeparationFunctionType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("FACE_A")) return FACE_A;
	if (inName==HX_CSTRING("FACE_B")) return FACE_B;
	if (inName==HX_CSTRING("POINTS")) return POINTS;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("POINTS"),
	HX_CSTRING("FACE_A"),
	HX_CSTRING("FACE_B"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2SeparationFunctionType_obj::FACE_A,"FACE_A");
	HX_MARK_MEMBER_NAME(B2SeparationFunctionType_obj::FACE_B,"FACE_B");
	HX_MARK_MEMBER_NAME(B2SeparationFunctionType_obj::POINTS,"POINTS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2SeparationFunctionType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2SeparationFunctionType_obj::FACE_A,"FACE_A");
	HX_VISIT_MEMBER_NAME(B2SeparationFunctionType_obj::FACE_B,"FACE_B");
	HX_VISIT_MEMBER_NAME(B2SeparationFunctionType_obj::POINTS,"POINTS");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class B2SeparationFunctionType_obj::__mClass;

Dynamic __Create_B2SeparationFunctionType_obj() { return new B2SeparationFunctionType_obj; }

void B2SeparationFunctionType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2SeparationFunctionType"), hx::TCanCast< B2SeparationFunctionType_obj >,sStaticFields,sMemberFields,
	&__Create_B2SeparationFunctionType_obj, &__Create,
	&super::__SGetClass(), &CreateB2SeparationFunctionType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void B2SeparationFunctionType_obj::__boot()
{
hx::Static(FACE_A) = hx::CreateEnum< B2SeparationFunctionType_obj >(HX_CSTRING("FACE_A"),1);
hx::Static(FACE_B) = hx::CreateEnum< B2SeparationFunctionType_obj >(HX_CSTRING("FACE_B"),2);
hx::Static(POINTS) = hx::CreateEnum< B2SeparationFunctionType_obj >(HX_CSTRING("POINTS"),0);
}


} // end namespace box2D
} // end namespace collision
