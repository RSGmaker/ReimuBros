#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ManifoldType
#include <box2D/collision/B2ManifoldType.h>
#endif
namespace box2D{
namespace collision{

::box2D::collision::B2ManifoldType B2ManifoldType_obj::CIRCLES;

::box2D::collision::B2ManifoldType B2ManifoldType_obj::FACE_A;

::box2D::collision::B2ManifoldType B2ManifoldType_obj::FACE_B;

HX_DEFINE_CREATE_ENUM(B2ManifoldType_obj)

int B2ManifoldType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("CIRCLES")) return 0;
	if (inName==HX_CSTRING("FACE_A")) return 1;
	if (inName==HX_CSTRING("FACE_B")) return 2;
	return super::__FindIndex(inName);
}

int B2ManifoldType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("CIRCLES")) return 0;
	if (inName==HX_CSTRING("FACE_A")) return 0;
	if (inName==HX_CSTRING("FACE_B")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic B2ManifoldType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("CIRCLES")) return CIRCLES;
	if (inName==HX_CSTRING("FACE_A")) return FACE_A;
	if (inName==HX_CSTRING("FACE_B")) return FACE_B;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("CIRCLES"),
	HX_CSTRING("FACE_A"),
	HX_CSTRING("FACE_B"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ManifoldType_obj::CIRCLES,"CIRCLES");
	HX_MARK_MEMBER_NAME(B2ManifoldType_obj::FACE_A,"FACE_A");
	HX_MARK_MEMBER_NAME(B2ManifoldType_obj::FACE_B,"FACE_B");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ManifoldType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2ManifoldType_obj::CIRCLES,"CIRCLES");
	HX_VISIT_MEMBER_NAME(B2ManifoldType_obj::FACE_A,"FACE_A");
	HX_VISIT_MEMBER_NAME(B2ManifoldType_obj::FACE_B,"FACE_B");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class B2ManifoldType_obj::__mClass;

Dynamic __Create_B2ManifoldType_obj() { return new B2ManifoldType_obj; }

void B2ManifoldType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2ManifoldType"), hx::TCanCast< B2ManifoldType_obj >,sStaticFields,sMemberFields,
	&__Create_B2ManifoldType_obj, &__Create,
	&super::__SGetClass(), &CreateB2ManifoldType_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void B2ManifoldType_obj::__boot()
{
hx::Static(CIRCLES) = hx::CreateEnum< B2ManifoldType_obj >(HX_CSTRING("CIRCLES"),0);
hx::Static(FACE_A) = hx::CreateEnum< B2ManifoldType_obj >(HX_CSTRING("FACE_A"),1);
hx::Static(FACE_B) = hx::CreateEnum< B2ManifoldType_obj >(HX_CSTRING("FACE_B"),2);
}


} // end namespace box2D
} // end namespace collision
