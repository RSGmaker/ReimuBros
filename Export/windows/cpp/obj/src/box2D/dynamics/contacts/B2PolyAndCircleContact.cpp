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
#ifndef INCLUDED_box2D_collision_shapes_B2PolygonShape
#include <box2D/collision/shapes/B2PolygonShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
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
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PolyAndCircleContact
#include <box2D/dynamics/contacts/B2PolyAndCircleContact.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2PolyAndCircleContact_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndCircleContact","new",0xbf9e0499,"box2D.dynamics.contacts.B2PolyAndCircleContact.new","box2D/dynamics/contacts/B2PolyAndCircleContact.hx",35,0x546566b6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(35)
	super::__construct();
}
;
	return null();
}

//B2PolyAndCircleContact_obj::~B2PolyAndCircleContact_obj() { }

Dynamic B2PolyAndCircleContact_obj::__CreateEmpty() { return  new B2PolyAndCircleContact_obj; }
hx::ObjectPtr< B2PolyAndCircleContact_obj > B2PolyAndCircleContact_obj::__new()
{  hx::ObjectPtr< B2PolyAndCircleContact_obj > result = new B2PolyAndCircleContact_obj();
	result->__construct();
	return result;}

Dynamic B2PolyAndCircleContact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PolyAndCircleContact_obj > result = new B2PolyAndCircleContact_obj();
	result->__construct();
	return result;}

Void B2PolyAndCircleContact_obj::reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndCircleContact","reset",0xb432be48,"box2D.dynamics.contacts.B2PolyAndCircleContact.reset","box2D/dynamics/contacts/B2PolyAndCircleContact.hx",43,0x546566b6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fixtureA,"fixtureA")
		HX_STACK_ARG(fixtureB,"fixtureB")
		HX_STACK_LINE(44)
		this->super::reset(fixtureA,fixtureB);
		HX_STACK_LINE(45)
		int _g = fixtureA->getType();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(45)
		bool _g1 = (_g == (int)2);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(45)
		::box2D::common::B2Settings_obj::b2Assert(_g1);
		HX_STACK_LINE(46)
		int _g2 = fixtureB->getType();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(46)
		bool _g3 = (_g2 == (int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(46)
		::box2D::common::B2Settings_obj::b2Assert(_g3);
	}
return null();
}


Void B2PolyAndCircleContact_obj::evaluate( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndCircleContact","evaluate",0xeee13d80,"box2D.dynamics.contacts.B2PolyAndCircleContact.evaluate","box2D/dynamics/contacts/B2PolyAndCircleContact.hx",50,0x546566b6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(51)
		::box2D::dynamics::B2Body bA = this->m_fixtureA->m_body;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(52)
		::box2D::dynamics::B2Body bB = this->m_fixtureB->m_body;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(55)
		::box2D::collision::shapes::B2PolygonShape _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(55)
		_g = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(this->m_fixtureA->getShape());
		HX_STACK_LINE(56)
		::box2D::collision::shapes::B2CircleShape _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(56)
		_g1 = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(this->m_fixtureB->getShape());
		HX_STACK_LINE(54)
		::box2D::collision::B2Collision_obj::collidePolygonAndCircle(this->m_manifold,_g,bA->m_xf,_g1,bB->m_xf);
	}
return null();
}


::box2D::dynamics::contacts::B2Contact B2PolyAndCircleContact_obj::create( Dynamic allocator){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndCircleContact","create",0x6bcadc63,"box2D.dynamics.contacts.B2PolyAndCircleContact.create","box2D/dynamics/contacts/B2PolyAndCircleContact.hx",38,0x546566b6)
	HX_STACK_ARG(allocator,"allocator")
	HX_STACK_LINE(38)
	return ::box2D::dynamics::contacts::B2PolyAndCircleContact_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2PolyAndCircleContact_obj,create,return )

Void B2PolyAndCircleContact_obj::destroy( ::box2D::dynamics::contacts::B2Contact contact,Dynamic allocator){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndCircleContact","destroy",0xf8d171b3,"box2D.dynamics.contacts.B2PolyAndCircleContact.destroy","box2D/dynamics/contacts/B2PolyAndCircleContact.hx",40,0x546566b6)
		HX_STACK_ARG(contact,"contact")
		HX_STACK_ARG(allocator,"allocator")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolyAndCircleContact_obj,destroy,(void))


B2PolyAndCircleContact_obj::B2PolyAndCircleContact_obj()
{
}

Dynamic B2PolyAndCircleContact_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic B2PolyAndCircleContact_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2PolyAndCircleContact_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(B2PolyAndCircleContact_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PolyAndCircleContact_obj::__mClass,"__mClass");
};

#endif

Class B2PolyAndCircleContact_obj::__mClass;

void B2PolyAndCircleContact_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2PolyAndCircleContact"), hx::TCanCast< B2PolyAndCircleContact_obj> ,sStaticFields,sMemberFields,
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

void B2PolyAndCircleContact_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
