#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#include <box2D/collision/shapes/B2EdgeShape.h>
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
#ifndef INCLUDED_box2D_dynamics_contacts_B2PolyAndEdgeContact
#include <box2D/dynamics/contacts/B2PolyAndEdgeContact.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2PolyAndEdgeContact_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndEdgeContact","new",0x572f27cc,"box2D.dynamics.contacts.B2PolyAndEdgeContact.new","box2D/dynamics/contacts/B2PolyAndEdgeContact.hx",36,0x86a2ad23)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(36)
	super::__construct();
}
;
	return null();
}

//B2PolyAndEdgeContact_obj::~B2PolyAndEdgeContact_obj() { }

Dynamic B2PolyAndEdgeContact_obj::__CreateEmpty() { return  new B2PolyAndEdgeContact_obj; }
hx::ObjectPtr< B2PolyAndEdgeContact_obj > B2PolyAndEdgeContact_obj::__new()
{  hx::ObjectPtr< B2PolyAndEdgeContact_obj > result = new B2PolyAndEdgeContact_obj();
	result->__construct();
	return result;}

Dynamic B2PolyAndEdgeContact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PolyAndEdgeContact_obj > result = new B2PolyAndEdgeContact_obj();
	result->__construct();
	return result;}

Void B2PolyAndEdgeContact_obj::reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndEdgeContact","reset",0x2cb9543b,"box2D.dynamics.contacts.B2PolyAndEdgeContact.reset","box2D/dynamics/contacts/B2PolyAndEdgeContact.hx",44,0x86a2ad23)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fixtureA,"fixtureA")
		HX_STACK_ARG(fixtureB,"fixtureB")
		HX_STACK_LINE(45)
		this->super::reset(fixtureA,fixtureB);
		HX_STACK_LINE(46)
		int _g = fixtureA->getType();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(46)
		bool _g1 = (_g == (int)2);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(46)
		::box2D::common::B2Settings_obj::b2Assert(_g1);
		HX_STACK_LINE(47)
		int _g2 = fixtureB->getType();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(47)
		bool _g3 = (_g2 == (int)3);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(47)
		::box2D::common::B2Settings_obj::b2Assert(_g3);
	}
return null();
}


Void B2PolyAndEdgeContact_obj::evaluate( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndEdgeContact","evaluate",0x2b84a16d,"box2D.dynamics.contacts.B2PolyAndEdgeContact.evaluate","box2D/dynamics/contacts/B2PolyAndEdgeContact.hx",51,0x86a2ad23)
		HX_STACK_THIS(this)
		HX_STACK_LINE(52)
		::box2D::dynamics::B2Body bA = this->m_fixtureA->getBody();		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(53)
		::box2D::dynamics::B2Body bB = this->m_fixtureB->getBody();		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(56)
		::box2D::collision::shapes::B2PolygonShape _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(56)
		_g = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(this->m_fixtureA->getShape());
		HX_STACK_LINE(57)
		::box2D::collision::shapes::B2EdgeShape _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(57)
		_g1 = hx::TCast< box2D::collision::shapes::B2EdgeShape >::cast(this->m_fixtureB->getShape());
		HX_STACK_LINE(55)
		this->b2CollidePolyAndEdge(this->m_manifold,_g,bA->m_xf,_g1,bB->m_xf);
	}
return null();
}


Void B2PolyAndEdgeContact_obj::b2CollidePolyAndEdge( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polygon,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Transform xf2){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndEdgeContact","b2CollidePolyAndEdge",0xa601dbae,"box2D.dynamics.contacts.B2PolyAndEdgeContact.b2CollidePolyAndEdge","box2D/dynamics/contacts/B2PolyAndEdgeContact.hx",65,0x86a2ad23)
		HX_STACK_THIS(this)
		HX_STACK_ARG(manifold,"manifold")
		HX_STACK_ARG(polygon,"polygon")
		HX_STACK_ARG(xf1,"xf1")
		HX_STACK_ARG(edge,"edge")
		HX_STACK_ARG(xf2,"xf2")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2PolyAndEdgeContact_obj,b2CollidePolyAndEdge,(void))

::box2D::dynamics::contacts::B2Contact B2PolyAndEdgeContact_obj::create( Dynamic allocator){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndEdgeContact","create",0x69077b10,"box2D.dynamics.contacts.B2PolyAndEdgeContact.create","box2D/dynamics/contacts/B2PolyAndEdgeContact.hx",39,0x86a2ad23)
	HX_STACK_ARG(allocator,"allocator")
	HX_STACK_LINE(39)
	return ::box2D::dynamics::contacts::B2PolyAndEdgeContact_obj::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2PolyAndEdgeContact_obj,create,return )

Void B2PolyAndEdgeContact_obj::destroy( ::box2D::dynamics::contacts::B2Contact contact,Dynamic allocator){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2PolyAndEdgeContact","destroy",0x909faa66,"box2D.dynamics.contacts.B2PolyAndEdgeContact.destroy","box2D/dynamics/contacts/B2PolyAndEdgeContact.hx",41,0x86a2ad23)
		HX_STACK_ARG(contact,"contact")
		HX_STACK_ARG(allocator,"allocator")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolyAndEdgeContact_obj,destroy,(void))


B2PolyAndEdgeContact_obj::B2PolyAndEdgeContact_obj()
{
}

Dynamic B2PolyAndEdgeContact_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 20:
		if (HX_FIELD_EQ(inName,"b2CollidePolyAndEdge") ) { return b2CollidePolyAndEdge_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2PolyAndEdgeContact_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2PolyAndEdgeContact_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("b2CollidePolyAndEdge"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PolyAndEdgeContact_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PolyAndEdgeContact_obj::__mClass,"__mClass");
};

#endif

Class B2PolyAndEdgeContact_obj::__mClass;

void B2PolyAndEdgeContact_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2PolyAndEdgeContact"), hx::TCanCast< B2PolyAndEdgeContact_obj> ,sStaticFields,sMemberFields,
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

void B2PolyAndEdgeContact_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
