#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2ContactFilter
#include <box2D/dynamics/B2ContactFilter.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FilterData
#include <box2D/dynamics/B2FilterData.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
namespace box2D{
namespace dynamics{

Void B2ContactFilter_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2ContactFilter","new",0x01c788b1,"box2D.dynamics.B2ContactFilter.new","box2D/dynamics/B2ContactFilter.hx",28,0x577fc7bf)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//B2ContactFilter_obj::~B2ContactFilter_obj() { }

Dynamic B2ContactFilter_obj::__CreateEmpty() { return  new B2ContactFilter_obj; }
hx::ObjectPtr< B2ContactFilter_obj > B2ContactFilter_obj::__new()
{  hx::ObjectPtr< B2ContactFilter_obj > result = new B2ContactFilter_obj();
	result->__construct();
	return result;}

Dynamic B2ContactFilter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactFilter_obj > result = new B2ContactFilter_obj();
	result->__construct();
	return result;}

bool B2ContactFilter_obj::shouldCollide( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
	HX_STACK_FRAME("box2D.dynamics.B2ContactFilter","shouldCollide",0xf0a1931c,"box2D.dynamics.B2ContactFilter.shouldCollide","box2D/dynamics/B2ContactFilter.hx",36,0x577fc7bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(fixtureA,"fixtureA")
	HX_STACK_ARG(fixtureB,"fixtureB")
	HX_STACK_LINE(37)
	::box2D::dynamics::B2FilterData filter1 = fixtureA->getFilterData();		HX_STACK_VAR(filter1,"filter1");
	HX_STACK_LINE(38)
	::box2D::dynamics::B2FilterData filter2 = fixtureB->getFilterData();		HX_STACK_VAR(filter2,"filter2");
	HX_STACK_LINE(40)
	if (((bool((filter1->groupIndex == filter2->groupIndex)) && bool((filter1->groupIndex != (int)0))))){
		HX_STACK_LINE(42)
		return (filter1->groupIndex > (int)0);
	}
	HX_STACK_LINE(45)
	bool collide = (bool((((int(filter1->maskBits) & int(filter2->categoryBits))) != (int)0)) && bool((((int(filter1->categoryBits) & int(filter2->maskBits))) != (int)0)));		HX_STACK_VAR(collide,"collide");
	HX_STACK_LINE(46)
	return collide;
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactFilter_obj,shouldCollide,return )

bool B2ContactFilter_obj::rayCollide( Dynamic userData,::box2D::dynamics::B2Fixture fixture){
	HX_STACK_FRAME("box2D.dynamics.B2ContactFilter","rayCollide",0x10185683,"box2D.dynamics.B2ContactFilter.rayCollide","box2D/dynamics/B2ContactFilter.hx",58,0x577fc7bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(userData,"userData")
	HX_STACK_ARG(fixture,"fixture")
	HX_STACK_LINE(59)
	if (((userData == null()))){
		HX_STACK_LINE(60)
		return true;
	}
	HX_STACK_LINE(61)
	::box2D::dynamics::B2Fixture _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(61)
	_g = hx::TCast< box2D::dynamics::B2Fixture >::cast(userData);
	HX_STACK_LINE(61)
	return this->shouldCollide(_g,fixture);
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactFilter_obj,rayCollide,return )

::box2D::dynamics::B2ContactFilter B2ContactFilter_obj::b2_defaultFilter;


B2ContactFilter_obj::B2ContactFilter_obj()
{
}

Dynamic B2ContactFilter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"rayCollide") ) { return rayCollide_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"shouldCollide") ) { return shouldCollide_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2_defaultFilter") ) { return b2_defaultFilter; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactFilter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"b2_defaultFilter") ) { b2_defaultFilter=inValue.Cast< ::box2D::dynamics::B2ContactFilter >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactFilter_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_defaultFilter"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("shouldCollide"),
	HX_CSTRING("rayCollide"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactFilter_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2ContactFilter_obj::b2_defaultFilter,"b2_defaultFilter");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactFilter_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2ContactFilter_obj::b2_defaultFilter,"b2_defaultFilter");
};

#endif

Class B2ContactFilter_obj::__mClass;

void B2ContactFilter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2ContactFilter"), hx::TCanCast< B2ContactFilter_obj> ,sStaticFields,sMemberFields,
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

void B2ContactFilter_obj::__boot()
{
	b2_defaultFilter= ::box2D::dynamics::B2ContactFilter_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
