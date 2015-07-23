#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DistanceOutput
#include <box2D/collision/B2DistanceOutput.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2DistanceOutput_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2DistanceOutput","new",0x65975805,"box2D.collision.B2DistanceOutput.new","box2D/collision/B2DistanceOutput.hx",28,0xf7153509)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(30)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->pointA = _g;
	HX_STACK_LINE(31)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(31)
	this->pointB = _g1;
}
;
	return null();
}

//B2DistanceOutput_obj::~B2DistanceOutput_obj() { }

Dynamic B2DistanceOutput_obj::__CreateEmpty() { return  new B2DistanceOutput_obj; }
hx::ObjectPtr< B2DistanceOutput_obj > B2DistanceOutput_obj::__new()
{  hx::ObjectPtr< B2DistanceOutput_obj > result = new B2DistanceOutput_obj();
	result->__construct();
	return result;}

Dynamic B2DistanceOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DistanceOutput_obj > result = new B2DistanceOutput_obj();
	result->__construct();
	return result;}


B2DistanceOutput_obj::B2DistanceOutput_obj()
{
}

void B2DistanceOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DistanceOutput);
	HX_MARK_MEMBER_NAME(pointA,"pointA");
	HX_MARK_MEMBER_NAME(pointB,"pointB");
	HX_MARK_MEMBER_NAME(distance,"distance");
	HX_MARK_MEMBER_NAME(iterations,"iterations");
	HX_MARK_END_CLASS();
}

void B2DistanceOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pointA,"pointA");
	HX_VISIT_MEMBER_NAME(pointB,"pointB");
	HX_VISIT_MEMBER_NAME(distance,"distance");
	HX_VISIT_MEMBER_NAME(iterations,"iterations");
}

Dynamic B2DistanceOutput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pointA") ) { return pointA; }
		if (HX_FIELD_EQ(inName,"pointB") ) { return pointB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"iterations") ) { return iterations; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2DistanceOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"pointA") ) { pointA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pointB") ) { pointB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { distance=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"iterations") ) { iterations=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2DistanceOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pointA"));
	outFields->push(HX_CSTRING("pointB"));
	outFields->push(HX_CSTRING("distance"));
	outFields->push(HX_CSTRING("iterations"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2DistanceOutput_obj,pointA),HX_CSTRING("pointA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2DistanceOutput_obj,pointB),HX_CSTRING("pointB")},
	{hx::fsFloat,(int)offsetof(B2DistanceOutput_obj,distance),HX_CSTRING("distance")},
	{hx::fsInt,(int)offsetof(B2DistanceOutput_obj,iterations),HX_CSTRING("iterations")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("pointA"),
	HX_CSTRING("pointB"),
	HX_CSTRING("distance"),
	HX_CSTRING("iterations"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DistanceOutput_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2DistanceOutput_obj::__mClass,"__mClass");
};

#endif

Class B2DistanceOutput_obj::__mClass;

void B2DistanceOutput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DistanceOutput"), hx::TCanCast< B2DistanceOutput_obj> ,sStaticFields,sMemberFields,
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

void B2DistanceOutput_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
