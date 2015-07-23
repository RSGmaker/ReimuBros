#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#include <box2D/collision/shapes/B2EdgeShape.h>
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
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2EdgeAndCircleContact
#include <box2D/dynamics/contacts/B2EdgeAndCircleContact.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2EdgeAndCircleContact_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2EdgeAndCircleContact","new",0x9fe64d0a,"box2D.dynamics.contacts.B2EdgeAndCircleContact.new","box2D/dynamics/contacts/B2EdgeAndCircleContact.hx",34,0xeaa3b765)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(34)
	super::__construct();
}
;
	return null();
}

//B2EdgeAndCircleContact_obj::~B2EdgeAndCircleContact_obj() { }

Dynamic B2EdgeAndCircleContact_obj::__CreateEmpty() { return  new B2EdgeAndCircleContact_obj; }
hx::ObjectPtr< B2EdgeAndCircleContact_obj > B2EdgeAndCircleContact_obj::__new()
{  hx::ObjectPtr< B2EdgeAndCircleContact_obj > result = new B2EdgeAndCircleContact_obj();
	result->__construct();
	return result;}

Dynamic B2EdgeAndCircleContact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2EdgeAndCircleContact_obj > result = new B2EdgeAndCircleContact_obj();
	result->__construct();
	return result;}

Void B2EdgeAndCircleContact_obj::reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2EdgeAndCircleContact","reset",0x6d72c4f9,"box2D.dynamics.contacts.B2EdgeAndCircleContact.reset","box2D/dynamics/contacts/B2EdgeAndCircleContact.hx",44,0xeaa3b765)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fixtureA,"fixtureA")
		HX_STACK_ARG(fixtureB,"fixtureB")
		HX_STACK_LINE(44)
		this->super::reset(fixtureA,fixtureB);
	}
return null();
}


Void B2EdgeAndCircleContact_obj::evaluate( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2EdgeAndCircleContact","evaluate",0xe9e7bb6f,"box2D.dynamics.contacts.B2EdgeAndCircleContact.evaluate","box2D/dynamics/contacts/B2EdgeAndCircleContact.hx",50,0xeaa3b765)
		HX_STACK_THIS(this)
		HX_STACK_LINE(51)
		::box2D::dynamics::B2Body bA = this->m_fixtureA->getBody();		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(52)
		::box2D::dynamics::B2Body bB = this->m_fixtureB->getBody();		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(54)
		::box2D::collision::shapes::B2EdgeShape _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(54)
		_g = hx::TCast< box2D::collision::shapes::B2EdgeShape >::cast(this->m_fixtureA->getShape());
		HX_STACK_LINE(55)
		::box2D::collision::shapes::B2CircleShape _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(55)
		_g1 = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(this->m_fixtureB->getShape());
		HX_STACK_LINE(53)
		this->b2CollideEdgeAndCircle(this->m_manifold,_g,bA->m_xf,_g1,bB->m_xf);
	}
return null();
}


Void B2EdgeAndCircleContact_obj::b2CollideEdgeAndCircle( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle,::box2D::common::math::B2Transform xf2){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2EdgeAndCircleContact","b2CollideEdgeAndCircle",0x0bac4d32,"box2D.dynamics.contacts.B2EdgeAndCircleContact.b2CollideEdgeAndCircle","box2D/dynamics/contacts/B2EdgeAndCircleContact.hx",63,0xeaa3b765)
		HX_STACK_THIS(this)
		HX_STACK_ARG(manifold,"manifold")
		HX_STACK_ARG(edge,"edge")
		HX_STACK_ARG(xf1,"xf1")
		HX_STACK_ARG(circle,"circle")
		HX_STACK_ARG(xf2,"xf2")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2EdgeAndCircleContact_obj,b2CollideEdgeAndCircle,(void))

::box2D::dynamics::contacts::B2Contact B2EdgeAndCircleContact_obj::create( Dynamic allocator){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2EdgeAndCircleContact","create",0xca90b092,"box2D.dynamics.contacts.B2EdgeAndCircleContact.create","box2D/dynamics/contacts/B2EdgeAndCircleContact.hx",37,0xeaa3b765)
	HX_STACK_ARG(allocator,"allocator")
	HX_STACK_LINE(37)
	return ::box2D::dynamics::contacts::B2EdgeAndCircleContact_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2EdgeAndCircleContact_obj,create,return )

Void B2EdgeAndCircleContact_obj::destroy( ::box2D::dynamics::contacts::B2Contact contact,Dynamic allocator){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2EdgeAndCircleContact","destroy",0x872546a4,"box2D.dynamics.contacts.B2EdgeAndCircleContact.destroy","box2D/dynamics/contacts/B2EdgeAndCircleContact.hx",39,0xeaa3b765)
		HX_STACK_ARG(contact,"contact")
		HX_STACK_ARG(allocator,"allocator")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2EdgeAndCircleContact_obj,destroy,(void))


B2EdgeAndCircleContact_obj::B2EdgeAndCircleContact_obj()
{
}

Dynamic B2EdgeAndCircleContact_obj::__Field(const ::String &inName,bool inCallProp)
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
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"b2CollideEdgeAndCircle") ) { return b2CollideEdgeAndCircle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2EdgeAndCircleContact_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2EdgeAndCircleContact_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("b2CollideEdgeAndCircle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2EdgeAndCircleContact_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2EdgeAndCircleContact_obj::__mClass,"__mClass");
};

#endif

Class B2EdgeAndCircleContact_obj::__mClass;

void B2EdgeAndCircleContact_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2EdgeAndCircleContact"), hx::TCanCast< B2EdgeAndCircleContact_obj> ,sStaticFields,sMemberFields,
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

void B2EdgeAndCircleContact_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
