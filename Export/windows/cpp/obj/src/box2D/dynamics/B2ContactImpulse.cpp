#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2ContactImpulse
#include <box2D/dynamics/B2ContactImpulse.h>
#endif
namespace box2D{
namespace dynamics{

Void B2ContactImpulse_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2ContactImpulse","new",0x9fc1ea40,"box2D.dynamics.B2ContactImpulse.new","box2D/dynamics/B2ContactImpulse.hx",31,0x57681150)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(33)
	Array< Float > _g = Array_obj< Float >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->normalImpulses = _g;
	HX_STACK_LINE(34)
	Array< Float > _g1 = Array_obj< Float >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->tangentImpulses = _g1;
}
;
	return null();
}

//B2ContactImpulse_obj::~B2ContactImpulse_obj() { }

Dynamic B2ContactImpulse_obj::__CreateEmpty() { return  new B2ContactImpulse_obj; }
hx::ObjectPtr< B2ContactImpulse_obj > B2ContactImpulse_obj::__new()
{  hx::ObjectPtr< B2ContactImpulse_obj > result = new B2ContactImpulse_obj();
	result->__construct();
	return result;}

Dynamic B2ContactImpulse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactImpulse_obj > result = new B2ContactImpulse_obj();
	result->__construct();
	return result;}


B2ContactImpulse_obj::B2ContactImpulse_obj()
{
}

void B2ContactImpulse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactImpulse);
	HX_MARK_MEMBER_NAME(normalImpulses,"normalImpulses");
	HX_MARK_MEMBER_NAME(tangentImpulses,"tangentImpulses");
	HX_MARK_END_CLASS();
}

void B2ContactImpulse_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(normalImpulses,"normalImpulses");
	HX_VISIT_MEMBER_NAME(tangentImpulses,"tangentImpulses");
}

Dynamic B2ContactImpulse_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"normalImpulses") ) { return normalImpulses; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"tangentImpulses") ) { return tangentImpulses; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactImpulse_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"normalImpulses") ) { normalImpulses=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"tangentImpulses") ) { tangentImpulses=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactImpulse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("normalImpulses"));
	outFields->push(HX_CSTRING("tangentImpulses"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(B2ContactImpulse_obj,normalImpulses),HX_CSTRING("normalImpulses")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(B2ContactImpulse_obj,tangentImpulses),HX_CSTRING("tangentImpulses")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("normalImpulses"),
	HX_CSTRING("tangentImpulses"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactImpulse_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactImpulse_obj::__mClass,"__mClass");
};

#endif

Class B2ContactImpulse_obj::__mClass;

void B2ContactImpulse_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2ContactImpulse"), hx::TCanCast< B2ContactImpulse_obj> ,sStaticFields,sMemberFields,
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

void B2ContactImpulse_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
