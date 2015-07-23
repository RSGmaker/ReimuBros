#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactRegister
#include <box2D/dynamics/contacts/B2ContactRegister.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactRegister_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactRegister","new",0x7b657133,"box2D.dynamics.contacts.B2ContactRegister.new","box2D/dynamics/contacts/B2ContactRegister.hx",25,0x9dd3b83e)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(32)
	this->poolCount = (int)0;
}
;
	return null();
}

//B2ContactRegister_obj::~B2ContactRegister_obj() { }

Dynamic B2ContactRegister_obj::__CreateEmpty() { return  new B2ContactRegister_obj; }
hx::ObjectPtr< B2ContactRegister_obj > B2ContactRegister_obj::__new()
{  hx::ObjectPtr< B2ContactRegister_obj > result = new B2ContactRegister_obj();
	result->__construct();
	return result;}

Dynamic B2ContactRegister_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactRegister_obj > result = new B2ContactRegister_obj();
	result->__construct();
	return result;}


B2ContactRegister_obj::B2ContactRegister_obj()
{
}

void B2ContactRegister_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactRegister);
	HX_MARK_MEMBER_NAME(createFcn,"createFcn");
	HX_MARK_MEMBER_NAME(destroyFcn,"destroyFcn");
	HX_MARK_MEMBER_NAME(primary,"primary");
	HX_MARK_MEMBER_NAME(pool,"pool");
	HX_MARK_MEMBER_NAME(poolCount,"poolCount");
	HX_MARK_END_CLASS();
}

void B2ContactRegister_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(createFcn,"createFcn");
	HX_VISIT_MEMBER_NAME(destroyFcn,"destroyFcn");
	HX_VISIT_MEMBER_NAME(primary,"primary");
	HX_VISIT_MEMBER_NAME(pool,"pool");
	HX_VISIT_MEMBER_NAME(poolCount,"poolCount");
}

Dynamic B2ContactRegister_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { return pool; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"primary") ) { return primary; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"createFcn") ) { return createFcn; }
		if (HX_FIELD_EQ(inName,"poolCount") ) { return poolCount; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"destroyFcn") ) { return destroyFcn; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactRegister_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"pool") ) { pool=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"primary") ) { primary=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"createFcn") ) { createFcn=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"poolCount") ) { poolCount=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"destroyFcn") ) { destroyFcn=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactRegister_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("createFcn"));
	outFields->push(HX_CSTRING("destroyFcn"));
	outFields->push(HX_CSTRING("primary"));
	outFields->push(HX_CSTRING("pool"));
	outFields->push(HX_CSTRING("poolCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2ContactRegister_obj,createFcn),HX_CSTRING("createFcn")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2ContactRegister_obj,destroyFcn),HX_CSTRING("destroyFcn")},
	{hx::fsBool,(int)offsetof(B2ContactRegister_obj,primary),HX_CSTRING("primary")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2Contact*/ ,(int)offsetof(B2ContactRegister_obj,pool),HX_CSTRING("pool")},
	{hx::fsInt,(int)offsetof(B2ContactRegister_obj,poolCount),HX_CSTRING("poolCount")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("createFcn"),
	HX_CSTRING("destroyFcn"),
	HX_CSTRING("primary"),
	HX_CSTRING("pool"),
	HX_CSTRING("poolCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactRegister_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactRegister_obj::__mClass,"__mClass");
};

#endif

Class B2ContactRegister_obj::__mClass;

void B2ContactRegister_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactRegister"), hx::TCanCast< B2ContactRegister_obj> ,sStaticFields,sMemberFields,
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

void B2ContactRegister_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
