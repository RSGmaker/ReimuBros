#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Collision
#include <box2D/collision/B2Collision.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2CircleContact
#include <box2D/dynamics/contacts/B2CircleContact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2CircleContact_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2CircleContact","new",0x8be36d80,"box2D.dynamics.contacts.B2CircleContact.new","box2D/dynamics/contacts/B2CircleContact.hx",31,0x0264ea51)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(31)
	super::__construct();
}
;
	return null();
}

//B2CircleContact_obj::~B2CircleContact_obj() { }

Dynamic B2CircleContact_obj::__CreateEmpty() { return  new B2CircleContact_obj; }
hx::ObjectPtr< B2CircleContact_obj > B2CircleContact_obj::__new()
{  hx::ObjectPtr< B2CircleContact_obj > result = new B2CircleContact_obj();
	result->__construct();
	return result;}

Dynamic B2CircleContact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2CircleContact_obj > result = new B2CircleContact_obj();
	result->__construct();
	return result;}

Void B2CircleContact_obj::reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2CircleContact","reset",0x2b516eef,"box2D.dynamics.contacts.B2CircleContact.reset","box2D/dynamics/contacts/B2CircleContact.hx",41,0x0264ea51)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fixtureA,"fixtureA")
		HX_STACK_ARG(fixtureB,"fixtureB")
		HX_STACK_LINE(41)
		this->super::reset(fixtureA,fixtureB);
	}
return null();
}


Void B2CircleContact_obj::evaluate( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2CircleContact","evaluate",0x02732f39,"box2D.dynamics.contacts.B2CircleContact.evaluate","box2D/dynamics/contacts/B2CircleContact.hx",47,0x0264ea51)
		HX_STACK_THIS(this)
		HX_STACK_LINE(48)
		::box2D::dynamics::B2Body bA = this->m_fixtureA->getBody();		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(49)
		::box2D::dynamics::B2Body bB = this->m_fixtureB->getBody();		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(52)
		::box2D::collision::shapes::B2CircleShape _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(52)
		_g = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(this->m_fixtureA->getShape());
		HX_STACK_LINE(53)
		::box2D::collision::shapes::B2CircleShape _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(53)
		_g1 = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(this->m_fixtureB->getShape());
		HX_STACK_LINE(51)
		::box2D::collision::B2Collision_obj::collideCircles(this->m_manifold,_g,bA->m_xf,_g1,bB->m_xf);
	}
return null();
}


::box2D::dynamics::contacts::B2Contact B2CircleContact_obj::create( Dynamic allocator){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2CircleContact","create",0x2f86bddc,"box2D.dynamics.contacts.B2CircleContact.create","box2D/dynamics/contacts/B2CircleContact.hx",34,0x0264ea51)
	HX_STACK_ARG(allocator,"allocator")
	HX_STACK_LINE(34)
	return ::box2D::dynamics::contacts::B2CircleContact_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2CircleContact_obj,create,return )

Void B2CircleContact_obj::destroy( ::box2D::dynamics::contacts::B2Contact contact,Dynamic allocator){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2CircleContact","destroy",0x797ada1a,"box2D.dynamics.contacts.B2CircleContact.destroy","box2D/dynamics/contacts/B2CircleContact.hx",36,0x0264ea51)
		HX_STACK_ARG(contact,"contact")
		HX_STACK_ARG(allocator,"allocator")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2CircleContact_obj,destroy,(void))


B2CircleContact_obj::B2CircleContact_obj()
{
}

Dynamic B2CircleContact_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"evaluate") ) { return evaluate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2CircleContact_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2CircleContact_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("reset"),
	HX_CSTRING("evaluate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2CircleContact_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2CircleContact_obj::__mClass,"__mClass");
};

#endif

Class B2CircleContact_obj::__mClass;

void B2CircleContact_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2CircleContact"), hx::TCanCast< B2CircleContact_obj> ,sStaticFields,sMemberFields,
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

void B2CircleContact_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
