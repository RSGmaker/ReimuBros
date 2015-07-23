#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2OBB
#include <box2D/collision/B2OBB.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2OBB_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2OBB","new",0xde5be544,"box2D.collision.B2OBB.new","box2D/collision/B2OBB.hx",32,0x25e7ebee)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(34)
	::box2D::common::math::B2Mat22 _g = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	this->R = _g;
	HX_STACK_LINE(35)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(35)
	this->center = _g1;
	HX_STACK_LINE(36)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(36)
	this->extents = _g2;
}
;
	return null();
}

//B2OBB_obj::~B2OBB_obj() { }

Dynamic B2OBB_obj::__CreateEmpty() { return  new B2OBB_obj; }
hx::ObjectPtr< B2OBB_obj > B2OBB_obj::__new()
{  hx::ObjectPtr< B2OBB_obj > result = new B2OBB_obj();
	result->__construct();
	return result;}

Dynamic B2OBB_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2OBB_obj > result = new B2OBB_obj();
	result->__construct();
	return result;}


B2OBB_obj::B2OBB_obj()
{
}

void B2OBB_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2OBB);
	HX_MARK_MEMBER_NAME(R,"R");
	HX_MARK_MEMBER_NAME(center,"center");
	HX_MARK_MEMBER_NAME(extents,"extents");
	HX_MARK_END_CLASS();
}

void B2OBB_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(R,"R");
	HX_VISIT_MEMBER_NAME(center,"center");
	HX_VISIT_MEMBER_NAME(extents,"extents");
}

Dynamic B2OBB_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"R") ) { return R; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { return center; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"extents") ) { return extents; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2OBB_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"R") ) { R=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { center=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"extents") ) { extents=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2OBB_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("R"));
	outFields->push(HX_CSTRING("center"));
	outFields->push(HX_CSTRING("extents"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Mat22*/ ,(int)offsetof(B2OBB_obj,R),HX_CSTRING("R")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2OBB_obj,center),HX_CSTRING("center")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2OBB_obj,extents),HX_CSTRING("extents")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("R"),
	HX_CSTRING("center"),
	HX_CSTRING("extents"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2OBB_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2OBB_obj::__mClass,"__mClass");
};

#endif

Class B2OBB_obj::__mClass;

void B2OBB_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2OBB"), hx::TCanCast< B2OBB_obj> ,sStaticFields,sMemberFields,
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

void B2OBB_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
