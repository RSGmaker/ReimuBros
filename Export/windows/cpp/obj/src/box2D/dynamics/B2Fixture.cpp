#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FilterData
#include <box2D/dynamics/B2FilterData.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FixtureDef
#include <box2D/dynamics/B2FixtureDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
namespace box2D{
namespace dynamics{

Void B2Fixture_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2Fixture","new",0x57ce3b42,"box2D.dynamics.B2Fixture.new","box2D/dynamics/B2Fixture.hx",264,0xdd1b2a4e)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(265)
	::box2D::dynamics::B2FilterData _g = ::box2D::dynamics::B2FilterData_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(265)
	this->m_filter = _g;
	HX_STACK_LINE(266)
	::box2D::collision::B2AABB _g1 = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(266)
	this->m_aabb = _g1;
	HX_STACK_LINE(267)
	this->m_userData = null();
	HX_STACK_LINE(268)
	this->m_body = null();
	HX_STACK_LINE(269)
	this->m_next = null();
	HX_STACK_LINE(271)
	this->m_shape = null();
	HX_STACK_LINE(272)
	this->m_density = 0.0;
	HX_STACK_LINE(274)
	this->m_friction = 0.0;
	HX_STACK_LINE(275)
	this->m_restitution = 0.0;
}
;
	return null();
}

//B2Fixture_obj::~B2Fixture_obj() { }

Dynamic B2Fixture_obj::__CreateEmpty() { return  new B2Fixture_obj; }
hx::ObjectPtr< B2Fixture_obj > B2Fixture_obj::__new()
{  hx::ObjectPtr< B2Fixture_obj > result = new B2Fixture_obj();
	result->__construct();
	return result;}

Dynamic B2Fixture_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Fixture_obj > result = new B2Fixture_obj();
	result->__construct();
	return result;}

int B2Fixture_obj::getType( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getType",0x56122652,"box2D.dynamics.B2Fixture.getType","box2D/dynamics/B2Fixture.hx",51,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	return this->m_shape->getType();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getType,return )

::box2D::collision::shapes::B2Shape B2Fixture_obj::getShape( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getShape",0x5b20d489,"box2D.dynamics.B2Fixture.getShape","box2D/dynamics/B2Fixture.hx",60,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(60)
	return this->m_shape;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getShape,return )

Void B2Fixture_obj::setSensor( bool sensor){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","setSensor",0x935067de,"box2D.dynamics.B2Fixture.setSensor","box2D/dynamics/B2Fixture.hx",67,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(sensor,"sensor")
		HX_STACK_LINE(68)
		if (((this->m_isSensor == sensor))){
			HX_STACK_LINE(69)
			return null();
		}
		HX_STACK_LINE(71)
		this->m_isSensor = sensor;
		HX_STACK_LINE(73)
		if (((this->m_body == null()))){
			HX_STACK_LINE(74)
			return null();
		}
		HX_STACK_LINE(76)
		::box2D::dynamics::contacts::B2ContactEdge edge = this->m_body->getContactList();		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(77)
		while((true)){
			HX_STACK_LINE(77)
			if ((!(((edge != null()))))){
				HX_STACK_LINE(77)
				break;
			}
			HX_STACK_LINE(79)
			::box2D::dynamics::contacts::B2Contact contact = edge->contact;		HX_STACK_VAR(contact,"contact");
			HX_STACK_LINE(80)
			::box2D::dynamics::B2Fixture fixtureA = contact->getFixtureA();		HX_STACK_VAR(fixtureA,"fixtureA");
			HX_STACK_LINE(81)
			::box2D::dynamics::B2Fixture fixtureB = contact->getFixtureB();		HX_STACK_VAR(fixtureB,"fixtureB");
			HX_STACK_LINE(82)
			if (((bool((fixtureA == hx::ObjectPtr<OBJ_>(this))) || bool((fixtureB == hx::ObjectPtr<OBJ_>(this)))))){
				HX_STACK_LINE(83)
				bool _g;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(83)
				if ((!(fixtureA->isSensor()))){
					HX_STACK_LINE(83)
					_g = fixtureB->isSensor();
				}
				else{
					HX_STACK_LINE(83)
					_g = true;
				}
				HX_STACK_LINE(83)
				contact->setSensor(_g);
			}
			HX_STACK_LINE(84)
			edge = edge->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setSensor,(void))

bool B2Fixture_obj::isSensor( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","isSensor",0x4326afa2,"box2D.dynamics.B2Fixture.isSensor","box2D/dynamics/B2Fixture.hx",95,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(95)
	return this->m_isSensor;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,isSensor,return )

Void B2Fixture_obj::setFilterData( ::box2D::dynamics::B2FilterData filter){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","setFilterData",0x00ddb5a6,"box2D.dynamics.B2Fixture.setFilterData","box2D/dynamics/B2Fixture.hx",103,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(filter,"filter")
		HX_STACK_LINE(104)
		::box2D::dynamics::B2FilterData _g = filter->copy();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(104)
		this->m_filter = _g;
		HX_STACK_LINE(106)
		if (((this->m_body != null()))){
			HX_STACK_LINE(107)
			return null();
		}
		HX_STACK_LINE(109)
		::box2D::dynamics::contacts::B2ContactEdge edge = this->m_body->getContactList();		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(110)
		while((true)){
			HX_STACK_LINE(110)
			if ((!(((edge != null()))))){
				HX_STACK_LINE(110)
				break;
			}
			HX_STACK_LINE(112)
			::box2D::dynamics::contacts::B2Contact contact = edge->contact;		HX_STACK_VAR(contact,"contact");
			HX_STACK_LINE(113)
			::box2D::dynamics::B2Fixture fixtureA = contact->getFixtureA();		HX_STACK_VAR(fixtureA,"fixtureA");
			HX_STACK_LINE(114)
			::box2D::dynamics::B2Fixture fixtureB = contact->getFixtureB();		HX_STACK_VAR(fixtureB,"fixtureB");
			HX_STACK_LINE(115)
			if (((bool((fixtureA == hx::ObjectPtr<OBJ_>(this))) || bool((fixtureB == hx::ObjectPtr<OBJ_>(this)))))){
				HX_STACK_LINE(116)
				contact->flagForFiltering();
			}
			HX_STACK_LINE(117)
			edge = edge->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setFilterData,(void))

::box2D::dynamics::B2FilterData B2Fixture_obj::getFilterData( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getFilterData",0xbbd7d39a,"box2D.dynamics.B2Fixture.getFilterData","box2D/dynamics/B2Fixture.hx",126,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(126)
	return this->m_filter->copy();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getFilterData,return )

::box2D::dynamics::B2Body B2Fixture_obj::getBody( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getBody",0x4a24ae3a,"box2D.dynamics.B2Fixture.getBody","box2D/dynamics/B2Fixture.hx",135,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(135)
	return this->m_body;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getBody,return )

::box2D::dynamics::B2Fixture B2Fixture_obj::getNext( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getNext",0x520bb88b,"box2D.dynamics.B2Fixture.getNext","box2D/dynamics/B2Fixture.hx",144,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getNext,return )

Dynamic B2Fixture_obj::getUserData( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getUserData",0xbb2f75ad,"box2D.dynamics.B2Fixture.getUserData","box2D/dynamics/B2Fixture.hx",153,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(153)
	return this->m_userData;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getUserData,return )

Void B2Fixture_obj::SetUserData( Dynamic data){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","SetUserData",0xa9cf1499,"box2D.dynamics.B2Fixture.SetUserData","box2D/dynamics/B2Fixture.hx",161,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(161)
		this->m_userData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,SetUserData,(void))

bool B2Fixture_obj::testPoint( ::box2D::common::math::B2Vec2 p){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","testPoint",0x57aab300,"box2D.dynamics.B2Fixture.testPoint","box2D/dynamics/B2Fixture.hx",170,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(171)
	::box2D::common::math::B2Transform _g = this->m_body->getTransform();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(171)
	return this->m_shape->testPoint(_g,p);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,testPoint,return )

bool B2Fixture_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","rayCast",0x5bc2e1ab,"box2D.dynamics.B2Fixture.rayCast","box2D/dynamics/B2Fixture.hx",180,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(input,"input")
	HX_STACK_LINE(181)
	::box2D::common::math::B2Transform _g = this->m_body->getTransform();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(181)
	return this->m_shape->rayCast(output,input,_g);
}


HX_DEFINE_DYNAMIC_FUNC2(B2Fixture_obj,rayCast,return )

::box2D::collision::shapes::B2MassData B2Fixture_obj::getMassData( ::box2D::collision::shapes::B2MassData massData){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getMassData",0x317f2cd6,"box2D.dynamics.B2Fixture.getMassData","box2D/dynamics/B2Fixture.hx",191,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(massData,"massData")
	HX_STACK_LINE(192)
	if (((massData == null()))){
		HX_STACK_LINE(194)
		::box2D::collision::shapes::B2MassData _g = ::box2D::collision::shapes::B2MassData_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(194)
		massData = _g;
	}
	HX_STACK_LINE(196)
	this->m_shape->computeMass(massData,this->m_density);
	HX_STACK_LINE(197)
	return massData;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,getMassData,return )

Void B2Fixture_obj::setDensity( Float density){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","setDensity",0xe343f9c4,"box2D.dynamics.B2Fixture.setDensity","box2D/dynamics/B2Fixture.hx",207,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(density,"density")
		HX_STACK_LINE(207)
		this->m_density = density;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setDensity,(void))

Float B2Fixture_obj::getDensity( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getDensity",0xdfc65b50,"box2D.dynamics.B2Fixture.getDensity","box2D/dynamics/B2Fixture.hx",215,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(215)
	return this->m_density;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getDensity,return )

Float B2Fixture_obj::getFriction( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getFriction",0x4dd05892,"box2D.dynamics.B2Fixture.getFriction","box2D/dynamics/B2Fixture.hx",223,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(223)
	return this->m_friction;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getFriction,return )

Void B2Fixture_obj::setFriction( Float friction){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","setFriction",0x583d5f9e,"box2D.dynamics.B2Fixture.setFriction","box2D/dynamics/B2Fixture.hx",231,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(friction,"friction")
		HX_STACK_LINE(231)
		this->m_friction = friction;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setFriction,(void))

Float B2Fixture_obj::getRestitution( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getRestitution",0x25141bd2,"box2D.dynamics.B2Fixture.getRestitution","box2D/dynamics/B2Fixture.hx",239,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(239)
	return this->m_restitution;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getRestitution,return )

Void B2Fixture_obj::setRestitution( Float restitution){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","setRestitution",0x45340446,"box2D.dynamics.B2Fixture.setRestitution","box2D/dynamics/B2Fixture.hx",247,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(restitution,"restitution")
		HX_STACK_LINE(247)
		this->m_restitution = restitution;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,setRestitution,(void))

::box2D::collision::B2AABB B2Fixture_obj::getAABB( ){
	HX_STACK_FRAME("box2D.dynamics.B2Fixture","getAABB",0x49587218,"box2D.dynamics.B2Fixture.getAABB","box2D/dynamics/B2Fixture.hx",257,0xdd1b2a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(257)
	return this->m_aabb;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,getAABB,return )

Void B2Fixture_obj::create( ::box2D::dynamics::B2Body body,::box2D::common::math::B2Transform xf,::box2D::dynamics::B2FixtureDef def){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","create",0x32d5755a,"box2D.dynamics.B2Fixture.create","box2D/dynamics/B2Fixture.hx",283,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(body,"body")
		HX_STACK_ARG(xf,"xf")
		HX_STACK_ARG(def,"def")
		HX_STACK_LINE(284)
		this->m_userData = def->userData;
		HX_STACK_LINE(285)
		this->m_friction = def->friction;
		HX_STACK_LINE(286)
		this->m_restitution = def->restitution;
		HX_STACK_LINE(288)
		this->m_body = body;
		HX_STACK_LINE(289)
		this->m_next = null();
		HX_STACK_LINE(291)
		::box2D::dynamics::B2FilterData _g = def->filter->copy();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(291)
		this->m_filter = _g;
		HX_STACK_LINE(293)
		this->m_isSensor = def->isSensor;
		HX_STACK_LINE(295)
		::box2D::collision::shapes::B2Shape _g1 = def->shape->copy();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(295)
		this->m_shape = _g1;
		HX_STACK_LINE(297)
		this->m_density = def->density;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Fixture_obj,create,(void))

Void B2Fixture_obj::destroy( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","destroy",0x5b0cb0dc,"box2D.dynamics.B2Fixture.destroy","box2D/dynamics/B2Fixture.hx",310,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(310)
		this->m_shape = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Fixture_obj,destroy,(void))

Void B2Fixture_obj::createProxy( ::box2D::collision::IBroadPhase broadPhase,::box2D::common::math::B2Transform xf){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","createProxy",0x821e42b4,"box2D.dynamics.B2Fixture.createProxy","box2D/dynamics/B2Fixture.hx",316,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(broadPhase,"broadPhase")
		HX_STACK_ARG(xf,"xf")
		HX_STACK_LINE(320)
		this->m_shape->computeAABB(this->m_aabb,xf);
		HX_STACK_LINE(321)
		Dynamic _g = broadPhase->createProxy(this->m_aabb,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(321)
		this->m_proxy = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Fixture_obj,createProxy,(void))

Void B2Fixture_obj::destroyProxy( ::box2D::collision::IBroadPhase broadPhase){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","destroyProxy",0x3b360ff2,"box2D.dynamics.B2Fixture.destroyProxy","box2D/dynamics/B2Fixture.hx",327,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(broadPhase,"broadPhase")
		HX_STACK_LINE(328)
		if (((this->m_proxy == null()))){
			HX_STACK_LINE(330)
			return null();
		}
		HX_STACK_LINE(334)
		broadPhase->destroyProxy(this->m_proxy);
		HX_STACK_LINE(335)
		this->m_proxy = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Fixture_obj,destroyProxy,(void))

Void B2Fixture_obj::synchronize( ::box2D::collision::IBroadPhase broadPhase,::box2D::common::math::B2Transform transform1,::box2D::common::math::B2Transform transform2){
{
		HX_STACK_FRAME("box2D.dynamics.B2Fixture","synchronize",0xc5548832,"box2D.dynamics.B2Fixture.synchronize","box2D/dynamics/B2Fixture.hx",339,0xdd1b2a4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(broadPhase,"broadPhase")
		HX_STACK_ARG(transform1,"transform1")
		HX_STACK_ARG(transform2,"transform2")
		HX_STACK_LINE(340)
		if (((this->m_proxy == null()))){
			HX_STACK_LINE(341)
			return null();
		}
		HX_STACK_LINE(344)
		::box2D::collision::B2AABB aabb1 = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(aabb1,"aabb1");
		HX_STACK_LINE(345)
		::box2D::collision::B2AABB aabb2 = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(aabb2,"aabb2");
		HX_STACK_LINE(346)
		this->m_shape->computeAABB(aabb1,transform1);
		HX_STACK_LINE(347)
		this->m_shape->computeAABB(aabb2,transform2);
		HX_STACK_LINE(349)
		this->m_aabb->combine(aabb1,aabb2);
		HX_STACK_LINE(350)
		::box2D::common::math::B2Vec2 displacement = ::box2D::common::math::B2Math_obj::subtractVV(transform2->position,transform1->position);		HX_STACK_VAR(displacement,"displacement");
		HX_STACK_LINE(351)
		broadPhase->moveProxy(this->m_proxy,this->m_aabb,displacement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Fixture_obj,synchronize,(void))


B2Fixture_obj::B2Fixture_obj()
{
}

void B2Fixture_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Fixture);
	HX_MARK_MEMBER_NAME(m_massData,"m_massData");
	HX_MARK_MEMBER_NAME(m_aabb,"m_aabb");
	HX_MARK_MEMBER_NAME(m_density,"m_density");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_body,"m_body");
	HX_MARK_MEMBER_NAME(m_shape,"m_shape");
	HX_MARK_MEMBER_NAME(m_friction,"m_friction");
	HX_MARK_MEMBER_NAME(m_restitution,"m_restitution");
	HX_MARK_MEMBER_NAME(m_proxy,"m_proxy");
	HX_MARK_MEMBER_NAME(m_filter,"m_filter");
	HX_MARK_MEMBER_NAME(m_isSensor,"m_isSensor");
	HX_MARK_MEMBER_NAME(m_userData,"m_userData");
	HX_MARK_END_CLASS();
}

void B2Fixture_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_massData,"m_massData");
	HX_VISIT_MEMBER_NAME(m_aabb,"m_aabb");
	HX_VISIT_MEMBER_NAME(m_density,"m_density");
	HX_VISIT_MEMBER_NAME(m_next,"m_next");
	HX_VISIT_MEMBER_NAME(m_body,"m_body");
	HX_VISIT_MEMBER_NAME(m_shape,"m_shape");
	HX_VISIT_MEMBER_NAME(m_friction,"m_friction");
	HX_VISIT_MEMBER_NAME(m_restitution,"m_restitution");
	HX_VISIT_MEMBER_NAME(m_proxy,"m_proxy");
	HX_VISIT_MEMBER_NAME(m_filter,"m_filter");
	HX_VISIT_MEMBER_NAME(m_isSensor,"m_isSensor");
	HX_VISIT_MEMBER_NAME(m_userData,"m_userData");
}

Dynamic B2Fixture_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"m_aabb") ) { return m_aabb; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		if (HX_FIELD_EQ(inName,"m_body") ) { return m_body; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"getBody") ) { return getBody_dyn(); }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"getAABB") ) { return getAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"m_shape") ) { return m_shape; }
		if (HX_FIELD_EQ(inName,"m_proxy") ) { return m_proxy; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getShape") ) { return getShape_dyn(); }
		if (HX_FIELD_EQ(inName,"isSensor") ) { return isSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"m_filter") ) { return m_filter; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setSensor") ) { return setSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"m_density") ) { return m_density; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"setDensity") ) { return setDensity_dyn(); }
		if (HX_FIELD_EQ(inName,"getDensity") ) { return getDensity_dyn(); }
		if (HX_FIELD_EQ(inName,"m_massData") ) { return m_massData; }
		if (HX_FIELD_EQ(inName,"m_friction") ) { return m_friction; }
		if (HX_FIELD_EQ(inName,"m_isSensor") ) { return m_isSensor; }
		if (HX_FIELD_EQ(inName,"m_userData") ) { return m_userData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"SetUserData") ) { return SetUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"getMassData") ) { return getMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"getFriction") ) { return getFriction_dyn(); }
		if (HX_FIELD_EQ(inName,"setFriction") ) { return setFriction_dyn(); }
		if (HX_FIELD_EQ(inName,"createProxy") ) { return createProxy_dyn(); }
		if (HX_FIELD_EQ(inName,"synchronize") ) { return synchronize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"destroyProxy") ) { return destroyProxy_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setFilterData") ) { return setFilterData_dyn(); }
		if (HX_FIELD_EQ(inName,"getFilterData") ) { return getFilterData_dyn(); }
		if (HX_FIELD_EQ(inName,"m_restitution") ) { return m_restitution; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getRestitution") ) { return getRestitution_dyn(); }
		if (HX_FIELD_EQ(inName,"setRestitution") ) { return setRestitution_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Fixture_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_aabb") ) { m_aabb=inValue.Cast< ::box2D::collision::B2AABB >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_body") ) { m_body=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_shape") ) { m_shape=inValue.Cast< ::box2D::collision::shapes::B2Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_proxy") ) { m_proxy=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_filter") ) { m_filter=inValue.Cast< ::box2D::dynamics::B2FilterData >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_density") ) { m_density=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_massData") ) { m_massData=inValue.Cast< ::box2D::collision::shapes::B2MassData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_friction") ) { m_friction=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_isSensor") ) { m_isSensor=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_userData") ) { m_userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_restitution") ) { m_restitution=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Fixture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_massData"));
	outFields->push(HX_CSTRING("m_aabb"));
	outFields->push(HX_CSTRING("m_density"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_body"));
	outFields->push(HX_CSTRING("m_shape"));
	outFields->push(HX_CSTRING("m_friction"));
	outFields->push(HX_CSTRING("m_restitution"));
	outFields->push(HX_CSTRING("m_proxy"));
	outFields->push(HX_CSTRING("m_filter"));
	outFields->push(HX_CSTRING("m_isSensor"));
	outFields->push(HX_CSTRING("m_userData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::collision::shapes::B2MassData*/ ,(int)offsetof(B2Fixture_obj,m_massData),HX_CSTRING("m_massData")},
	{hx::fsObject /*::box2D::collision::B2AABB*/ ,(int)offsetof(B2Fixture_obj,m_aabb),HX_CSTRING("m_aabb")},
	{hx::fsFloat,(int)offsetof(B2Fixture_obj,m_density),HX_CSTRING("m_density")},
	{hx::fsObject /*::box2D::dynamics::B2Fixture*/ ,(int)offsetof(B2Fixture_obj,m_next),HX_CSTRING("m_next")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2Fixture_obj,m_body),HX_CSTRING("m_body")},
	{hx::fsObject /*::box2D::collision::shapes::B2Shape*/ ,(int)offsetof(B2Fixture_obj,m_shape),HX_CSTRING("m_shape")},
	{hx::fsFloat,(int)offsetof(B2Fixture_obj,m_friction),HX_CSTRING("m_friction")},
	{hx::fsFloat,(int)offsetof(B2Fixture_obj,m_restitution),HX_CSTRING("m_restitution")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2Fixture_obj,m_proxy),HX_CSTRING("m_proxy")},
	{hx::fsObject /*::box2D::dynamics::B2FilterData*/ ,(int)offsetof(B2Fixture_obj,m_filter),HX_CSTRING("m_filter")},
	{hx::fsBool,(int)offsetof(B2Fixture_obj,m_isSensor),HX_CSTRING("m_isSensor")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2Fixture_obj,m_userData),HX_CSTRING("m_userData")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	HX_CSTRING("getShape"),
	HX_CSTRING("setSensor"),
	HX_CSTRING("isSensor"),
	HX_CSTRING("setFilterData"),
	HX_CSTRING("getFilterData"),
	HX_CSTRING("getBody"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("SetUserData"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("getMassData"),
	HX_CSTRING("setDensity"),
	HX_CSTRING("getDensity"),
	HX_CSTRING("getFriction"),
	HX_CSTRING("setFriction"),
	HX_CSTRING("getRestitution"),
	HX_CSTRING("setRestitution"),
	HX_CSTRING("getAABB"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("createProxy"),
	HX_CSTRING("destroyProxy"),
	HX_CSTRING("synchronize"),
	HX_CSTRING("m_massData"),
	HX_CSTRING("m_aabb"),
	HX_CSTRING("m_density"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_body"),
	HX_CSTRING("m_shape"),
	HX_CSTRING("m_friction"),
	HX_CSTRING("m_restitution"),
	HX_CSTRING("m_proxy"),
	HX_CSTRING("m_filter"),
	HX_CSTRING("m_isSensor"),
	HX_CSTRING("m_userData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Fixture_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Fixture_obj::__mClass,"__mClass");
};

#endif

Class B2Fixture_obj::__mClass;

void B2Fixture_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2Fixture"), hx::TCanCast< B2Fixture_obj> ,sStaticFields,sMemberFields,
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

void B2Fixture_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
