#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TOIInput
#include <box2D/collision/B2TOIInput.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
namespace box2D{
namespace collision{

Void B2TOIInput_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2TOIInput","new",0x5d1ec1cb,"box2D.collision.B2TOIInput.new","box2D/collision/B2TOIInput.hx",29,0xa1d7f383)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(31)
	::box2D::collision::B2DistanceProxy _g = ::box2D::collision::B2DistanceProxy_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(31)
	this->proxyA = _g;
	HX_STACK_LINE(32)
	::box2D::collision::B2DistanceProxy _g1 = ::box2D::collision::B2DistanceProxy_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(32)
	this->proxyB = _g1;
	HX_STACK_LINE(33)
	::box2D::common::math::B2Sweep _g2 = ::box2D::common::math::B2Sweep_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(33)
	this->sweepA = _g2;
	HX_STACK_LINE(34)
	::box2D::common::math::B2Sweep _g3 = ::box2D::common::math::B2Sweep_obj::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(34)
	this->sweepB = _g3;
}
;
	return null();
}

//B2TOIInput_obj::~B2TOIInput_obj() { }

Dynamic B2TOIInput_obj::__CreateEmpty() { return  new B2TOIInput_obj; }
hx::ObjectPtr< B2TOIInput_obj > B2TOIInput_obj::__new()
{  hx::ObjectPtr< B2TOIInput_obj > result = new B2TOIInput_obj();
	result->__construct();
	return result;}

Dynamic B2TOIInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2TOIInput_obj > result = new B2TOIInput_obj();
	result->__construct();
	return result;}


B2TOIInput_obj::B2TOIInput_obj()
{
}

void B2TOIInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2TOIInput);
	HX_MARK_MEMBER_NAME(proxyA,"proxyA");
	HX_MARK_MEMBER_NAME(proxyB,"proxyB");
	HX_MARK_MEMBER_NAME(sweepA,"sweepA");
	HX_MARK_MEMBER_NAME(sweepB,"sweepB");
	HX_MARK_MEMBER_NAME(tolerance,"tolerance");
	HX_MARK_END_CLASS();
}

void B2TOIInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(proxyA,"proxyA");
	HX_VISIT_MEMBER_NAME(proxyB,"proxyB");
	HX_VISIT_MEMBER_NAME(sweepA,"sweepA");
	HX_VISIT_MEMBER_NAME(sweepB,"sweepB");
	HX_VISIT_MEMBER_NAME(tolerance,"tolerance");
}

Dynamic B2TOIInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"proxyA") ) { return proxyA; }
		if (HX_FIELD_EQ(inName,"proxyB") ) { return proxyB; }
		if (HX_FIELD_EQ(inName,"sweepA") ) { return sweepA; }
		if (HX_FIELD_EQ(inName,"sweepB") ) { return sweepB; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tolerance") ) { return tolerance; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2TOIInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"proxyA") ) { proxyA=inValue.Cast< ::box2D::collision::B2DistanceProxy >(); return inValue; }
		if (HX_FIELD_EQ(inName,"proxyB") ) { proxyB=inValue.Cast< ::box2D::collision::B2DistanceProxy >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sweepA") ) { sweepA=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sweepB") ) { sweepB=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tolerance") ) { tolerance=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2TOIInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("proxyA"));
	outFields->push(HX_CSTRING("proxyB"));
	outFields->push(HX_CSTRING("sweepA"));
	outFields->push(HX_CSTRING("sweepB"));
	outFields->push(HX_CSTRING("tolerance"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::collision::B2DistanceProxy*/ ,(int)offsetof(B2TOIInput_obj,proxyA),HX_CSTRING("proxyA")},
	{hx::fsObject /*::box2D::collision::B2DistanceProxy*/ ,(int)offsetof(B2TOIInput_obj,proxyB),HX_CSTRING("proxyB")},
	{hx::fsObject /*::box2D::common::math::B2Sweep*/ ,(int)offsetof(B2TOIInput_obj,sweepA),HX_CSTRING("sweepA")},
	{hx::fsObject /*::box2D::common::math::B2Sweep*/ ,(int)offsetof(B2TOIInput_obj,sweepB),HX_CSTRING("sweepB")},
	{hx::fsFloat,(int)offsetof(B2TOIInput_obj,tolerance),HX_CSTRING("tolerance")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("proxyA"),
	HX_CSTRING("proxyB"),
	HX_CSTRING("sweepA"),
	HX_CSTRING("sweepB"),
	HX_CSTRING("tolerance"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2TOIInput_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2TOIInput_obj::__mClass,"__mClass");
};

#endif

Class B2TOIInput_obj::__mClass;

void B2TOIInput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2TOIInput"), hx::TCanCast< B2TOIInput_obj> ,sStaticFields,sMemberFields,
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

void B2TOIInput_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
