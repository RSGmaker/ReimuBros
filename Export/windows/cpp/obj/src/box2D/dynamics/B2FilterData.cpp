#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2FilterData
#include <box2D/dynamics/B2FilterData.h>
#endif
namespace box2D{
namespace dynamics{

Void B2FilterData_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2FilterData","new",0xe06b204d,"box2D.dynamics.B2FilterData.new","box2D/dynamics/B2FilterData.hx",31,0xa4738be3)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(33)
	this->categoryBits = (int)1;
	HX_STACK_LINE(34)
	this->maskBits = (int)65535;
	HX_STACK_LINE(35)
	this->groupIndex = (int)0;
}
;
	return null();
}

//B2FilterData_obj::~B2FilterData_obj() { }

Dynamic B2FilterData_obj::__CreateEmpty() { return  new B2FilterData_obj; }
hx::ObjectPtr< B2FilterData_obj > B2FilterData_obj::__new()
{  hx::ObjectPtr< B2FilterData_obj > result = new B2FilterData_obj();
	result->__construct();
	return result;}

Dynamic B2FilterData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2FilterData_obj > result = new B2FilterData_obj();
	result->__construct();
	return result;}

::box2D::dynamics::B2FilterData B2FilterData_obj::copy( ){
	HX_STACK_FRAME("box2D.dynamics.B2FilterData","copy",0x76135b28,"box2D.dynamics.B2FilterData.copy","box2D/dynamics/B2FilterData.hx",39,0xa4738be3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	::box2D::dynamics::B2FilterData copy = ::box2D::dynamics::B2FilterData_obj::__new();		HX_STACK_VAR(copy,"copy");
	HX_STACK_LINE(41)
	copy->categoryBits = this->categoryBits;
	HX_STACK_LINE(42)
	copy->maskBits = this->maskBits;
	HX_STACK_LINE(43)
	copy->groupIndex = this->groupIndex;
	HX_STACK_LINE(44)
	return copy;
}


HX_DEFINE_DYNAMIC_FUNC0(B2FilterData_obj,copy,return )


B2FilterData_obj::B2FilterData_obj()
{
}

Dynamic B2FilterData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maskBits") ) { return maskBits; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"groupIndex") ) { return groupIndex; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"categoryBits") ) { return categoryBits; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2FilterData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"maskBits") ) { maskBits=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"groupIndex") ) { groupIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"categoryBits") ) { categoryBits=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2FilterData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("categoryBits"));
	outFields->push(HX_CSTRING("maskBits"));
	outFields->push(HX_CSTRING("groupIndex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2FilterData_obj,categoryBits),HX_CSTRING("categoryBits")},
	{hx::fsInt,(int)offsetof(B2FilterData_obj,maskBits),HX_CSTRING("maskBits")},
	{hx::fsInt,(int)offsetof(B2FilterData_obj,groupIndex),HX_CSTRING("groupIndex")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("copy"),
	HX_CSTRING("categoryBits"),
	HX_CSTRING("maskBits"),
	HX_CSTRING("groupIndex"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2FilterData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2FilterData_obj::__mClass,"__mClass");
};

#endif

Class B2FilterData_obj::__mClass;

void B2FilterData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2FilterData"), hx::TCanCast< B2FilterData_obj> ,sStaticFields,sMemberFields,
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

void B2FilterData_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
