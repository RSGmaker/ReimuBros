#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactImpulse
#include <box2D/dynamics/B2ContactImpulse.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
namespace box2D{
namespace dynamics{

Void B2ContactListener_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2ContactListener","new",0xf649c72d,"box2D.dynamics.B2ContactListener.new","box2D/dynamics/B2ContactListener.hx",40,0xeea1a4c3)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//B2ContactListener_obj::~B2ContactListener_obj() { }

Dynamic B2ContactListener_obj::__CreateEmpty() { return  new B2ContactListener_obj; }
hx::ObjectPtr< B2ContactListener_obj > B2ContactListener_obj::__new()
{  hx::ObjectPtr< B2ContactListener_obj > result = new B2ContactListener_obj();
	result->__construct();
	return result;}

Dynamic B2ContactListener_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactListener_obj > result = new B2ContactListener_obj();
	result->__construct();
	return result;}

Void B2ContactListener_obj::beginContact( ::box2D::dynamics::contacts::B2Contact contact){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactListener","beginContact",0x0eb2870a,"box2D.dynamics.B2ContactListener.beginContact","box2D/dynamics/B2ContactListener.hx",49,0xeea1a4c3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(contact,"contact")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactListener_obj,beginContact,(void))

Void B2ContactListener_obj::endContact( ::box2D::dynamics::contacts::B2Contact contact){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactListener","endContact",0xe950ccd8,"box2D.dynamics.B2ContactListener.endContact","box2D/dynamics/B2ContactListener.hx",54,0xeea1a4c3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(contact,"contact")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactListener_obj,endContact,(void))

Void B2ContactListener_obj::preSolve( ::box2D::dynamics::contacts::B2Contact contact,::box2D::collision::B2Manifold oldManifold){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactListener","preSolve",0x1476b26f,"box2D.dynamics.B2ContactListener.preSolve","box2D/dynamics/B2ContactListener.hx",68,0xeea1a4c3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(contact,"contact")
		HX_STACK_ARG(oldManifold,"oldManifold")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactListener_obj,preSolve,(void))

Void B2ContactListener_obj::postSolve( ::box2D::dynamics::contacts::B2Contact contact,::box2D::dynamics::B2ContactImpulse impulse){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactListener","postSolve",0x827d5d8c,"box2D.dynamics.B2ContactListener.postSolve","box2D/dynamics/B2ContactListener.hx",78,0xeea1a4c3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(contact,"contact")
		HX_STACK_ARG(impulse,"impulse")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactListener_obj,postSolve,(void))

::box2D::dynamics::B2ContactListener B2ContactListener_obj::b2_defaultListener;


B2ContactListener_obj::B2ContactListener_obj()
{
}

Dynamic B2ContactListener_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"preSolve") ) { return preSolve_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"postSolve") ) { return postSolve_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"endContact") ) { return endContact_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"beginContact") ) { return beginContact_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_defaultListener") ) { return b2_defaultListener; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactListener_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"b2_defaultListener") ) { b2_defaultListener=inValue.Cast< ::box2D::dynamics::B2ContactListener >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactListener_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_defaultListener"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("beginContact"),
	HX_CSTRING("endContact"),
	HX_CSTRING("preSolve"),
	HX_CSTRING("postSolve"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactListener_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2ContactListener_obj::b2_defaultListener,"b2_defaultListener");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactListener_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2ContactListener_obj::b2_defaultListener,"b2_defaultListener");
};

#endif

Class B2ContactListener_obj::__mClass;

void B2ContactListener_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2ContactListener"), hx::TCanCast< B2ContactListener_obj> ,sStaticFields,sMemberFields,
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

void B2ContactListener_obj::__boot()
{
	b2_defaultListener= ::box2D::dynamics::B2ContactListener_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
