#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactEdge_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactEdge","new",0x2c2a810d,"box2D.dynamics.contacts.B2ContactEdge.new","box2D/dynamics/contacts/B2ContactEdge.hx",34,0xb9f2bd24)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//B2ContactEdge_obj::~B2ContactEdge_obj() { }

Dynamic B2ContactEdge_obj::__CreateEmpty() { return  new B2ContactEdge_obj; }
hx::ObjectPtr< B2ContactEdge_obj > B2ContactEdge_obj::__new()
{  hx::ObjectPtr< B2ContactEdge_obj > result = new B2ContactEdge_obj();
	result->__construct();
	return result;}

Dynamic B2ContactEdge_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactEdge_obj > result = new B2ContactEdge_obj();
	result->__construct();
	return result;}


B2ContactEdge_obj::B2ContactEdge_obj()
{
}

void B2ContactEdge_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactEdge);
	HX_MARK_MEMBER_NAME(other,"other");
	HX_MARK_MEMBER_NAME(contact,"contact");
	HX_MARK_MEMBER_NAME(prev,"prev");
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_END_CLASS();
}

void B2ContactEdge_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(other,"other");
	HX_VISIT_MEMBER_NAME(contact,"contact");
	HX_VISIT_MEMBER_NAME(prev,"prev");
	HX_VISIT_MEMBER_NAME(next,"next");
}

Dynamic B2ContactEdge_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { return prev; }
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"other") ) { return other; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"contact") ) { return contact; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactEdge_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"prev") ) { prev=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"other") ) { other=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"contact") ) { contact=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactEdge_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("other"));
	outFields->push(HX_CSTRING("contact"));
	outFields->push(HX_CSTRING("prev"));
	outFields->push(HX_CSTRING("next"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2ContactEdge_obj,other),HX_CSTRING("other")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2Contact*/ ,(int)offsetof(B2ContactEdge_obj,contact),HX_CSTRING("contact")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactEdge*/ ,(int)offsetof(B2ContactEdge_obj,prev),HX_CSTRING("prev")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactEdge*/ ,(int)offsetof(B2ContactEdge_obj,next),HX_CSTRING("next")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("other"),
	HX_CSTRING("contact"),
	HX_CSTRING("prev"),
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactEdge_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactEdge_obj::__mClass,"__mClass");
};

#endif

Class B2ContactEdge_obj::__mClass;

void B2ContactEdge_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactEdge"), hx::TCanCast< B2ContactEdge_obj> ,sStaticFields,sMemberFields,
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

void B2ContactEdge_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
