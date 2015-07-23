#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2RayCastOutput_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2RayCastOutput","new",0x68b6623f,"box2D.collision.B2RayCastOutput.new","box2D/collision/B2RayCastOutput.hx",29,0x6c0f4dd3)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(31)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(31)
	this->normal = _g;
}
;
	return null();
}

//B2RayCastOutput_obj::~B2RayCastOutput_obj() { }

Dynamic B2RayCastOutput_obj::__CreateEmpty() { return  new B2RayCastOutput_obj; }
hx::ObjectPtr< B2RayCastOutput_obj > B2RayCastOutput_obj::__new()
{  hx::ObjectPtr< B2RayCastOutput_obj > result = new B2RayCastOutput_obj();
	result->__construct();
	return result;}

Dynamic B2RayCastOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2RayCastOutput_obj > result = new B2RayCastOutput_obj();
	result->__construct();
	return result;}


B2RayCastOutput_obj::B2RayCastOutput_obj()
{
}

void B2RayCastOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2RayCastOutput);
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_MEMBER_NAME(fraction,"fraction");
	HX_MARK_END_CLASS();
}

void B2RayCastOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(normal,"normal");
	HX_VISIT_MEMBER_NAME(fraction,"fraction");
}

Dynamic B2RayCastOutput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fraction") ) { return fraction; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2RayCastOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fraction") ) { fraction=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2RayCastOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("fraction"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2RayCastOutput_obj,normal),HX_CSTRING("normal")},
	{hx::fsFloat,(int)offsetof(B2RayCastOutput_obj,fraction),HX_CSTRING("fraction")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("fraction"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2RayCastOutput_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2RayCastOutput_obj::__mClass,"__mClass");
};

#endif

Class B2RayCastOutput_obj::__mClass;

void B2RayCastOutput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2RayCastOutput"), hx::TCanCast< B2RayCastOutput_obj> ,sStaticFields,sMemberFields,
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

void B2RayCastOutput_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
