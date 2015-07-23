#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#include <box2D/collision/shapes/B2EdgeShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
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
#ifndef INCLUDED_box2D_dynamics_B2BodyDef
#include <box2D/dynamics/B2BodyDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactManager
#include <box2D/dynamics/B2ContactManager.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2FixtureDef
#include <box2D/dynamics/B2FixtureDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#include <box2D/dynamics/controllers/B2ControllerEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointEdge
#include <box2D/dynamics/joints/B2JointEdge.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace dynamics{

Void B2Body_obj::__construct(::box2D::dynamics::B2BodyDef bd,::box2D::dynamics::B2World world)
{
HX_STACK_FRAME("box2D.dynamics.B2Body","new",0xd7ec542d,"box2D.dynamics.B2Body.new","box2D/dynamics/B2Body.hx",1159,0x26bd9c03)
HX_STACK_THIS(this)
HX_STACK_ARG(bd,"bd")
HX_STACK_ARG(world,"world")
{
	HX_STACK_LINE(1161)
	::box2D::common::math::B2Transform _g = ::box2D::common::math::B2Transform_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1161)
	this->m_xf = _g;
	HX_STACK_LINE(1162)
	::box2D::common::math::B2Sweep _g1 = ::box2D::common::math::B2Sweep_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(1162)
	this->m_sweep = _g1;
	HX_STACK_LINE(1163)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(1163)
	this->m_linearVelocity = _g2;
	HX_STACK_LINE(1164)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(1164)
	this->m_force = _g3;
	HX_STACK_LINE(1176)
	this->m_flags = (int)0;
	HX_STACK_LINE(1178)
	if ((bd->bullet)){
		HX_STACK_LINE(1180)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_bulletFlag);
	}
	HX_STACK_LINE(1182)
	if ((bd->fixedRotation)){
		HX_STACK_LINE(1184)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
	}
	HX_STACK_LINE(1186)
	if ((bd->allowSleep)){
		HX_STACK_LINE(1188)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
	}
	HX_STACK_LINE(1190)
	if ((bd->awake)){
		HX_STACK_LINE(1192)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_awakeFlag);
	}
	HX_STACK_LINE(1194)
	if ((bd->active)){
		HX_STACK_LINE(1196)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_activeFlag);
	}
	HX_STACK_LINE(1199)
	this->m_world = world;
	HX_STACK_LINE(1201)
	this->m_xf->position->setV(bd->position);
	HX_STACK_LINE(1202)
	this->m_xf->R->set(bd->angle);
	HX_STACK_LINE(1204)
	this->m_sweep->localCenter->setZero();
	HX_STACK_LINE(1205)
	this->m_sweep->t0 = 1.0;
	HX_STACK_LINE(1206)
	Float _g4 = this->m_sweep->a = bd->angle;		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(1206)
	this->m_sweep->a0 = _g4;
	HX_STACK_LINE(1210)
	::box2D::common::math::B2Mat22 tMat = this->m_xf->R;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(1211)
	::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;		HX_STACK_VAR(tVec,"tVec");
	HX_STACK_LINE(1213)
	this->m_sweep->c->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
	HX_STACK_LINE(1215)
	this->m_sweep->c->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
	HX_STACK_LINE(1217)
	hx::AddEq(this->m_sweep->c->x,this->m_xf->position->x);
	HX_STACK_LINE(1218)
	hx::AddEq(this->m_sweep->c->y,this->m_xf->position->y);
	HX_STACK_LINE(1220)
	this->m_sweep->c0->setV(this->m_sweep->c);
	HX_STACK_LINE(1222)
	this->m_jointList = null();
	HX_STACK_LINE(1223)
	this->m_controllerList = null();
	HX_STACK_LINE(1224)
	this->m_contactList = null();
	HX_STACK_LINE(1225)
	this->m_controllerCount = (int)0;
	HX_STACK_LINE(1226)
	this->m_prev = null();
	HX_STACK_LINE(1227)
	this->m_next = null();
	HX_STACK_LINE(1229)
	this->m_linearVelocity->setV(bd->linearVelocity);
	HX_STACK_LINE(1230)
	this->m_angularVelocity = bd->angularVelocity;
	HX_STACK_LINE(1232)
	this->m_linearDamping = bd->linearDamping;
	HX_STACK_LINE(1233)
	this->m_angularDamping = bd->angularDamping;
	HX_STACK_LINE(1235)
	this->m_force->set(0.0,0.0);
	HX_STACK_LINE(1236)
	this->m_torque = 0.0;
	HX_STACK_LINE(1238)
	this->m_sleepTime = 0.0;
	HX_STACK_LINE(1240)
	this->m_type = bd->type;
	HX_STACK_LINE(1242)
	if (((this->m_type == (int)2))){
		HX_STACK_LINE(1244)
		this->m_mass = 1.0;
		HX_STACK_LINE(1245)
		this->m_invMass = 1.0;
	}
	else{
		HX_STACK_LINE(1249)
		this->m_mass = 0.0;
		HX_STACK_LINE(1250)
		this->m_invMass = 0.0;
	}
	HX_STACK_LINE(1253)
	this->m_I = 0.0;
	HX_STACK_LINE(1254)
	this->m_invI = 0.0;
	HX_STACK_LINE(1256)
	this->m_inertiaScale = bd->inertiaScale;
	HX_STACK_LINE(1258)
	this->m_userData = bd->userData;
	HX_STACK_LINE(1260)
	this->m_fixtureList = null();
	HX_STACK_LINE(1261)
	this->m_fixtureCount = (int)0;
}
;
	return null();
}

//B2Body_obj::~B2Body_obj() { }

Dynamic B2Body_obj::__CreateEmpty() { return  new B2Body_obj; }
hx::ObjectPtr< B2Body_obj > B2Body_obj::__new(::box2D::dynamics::B2BodyDef bd,::box2D::dynamics::B2World world)
{  hx::ObjectPtr< B2Body_obj > result = new B2Body_obj();
	result->__construct(bd,world);
	return result;}

Dynamic B2Body_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Body_obj > result = new B2Body_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Float B2Body_obj::connectEdges( ::box2D::collision::shapes::B2EdgeShape s1,::box2D::collision::shapes::B2EdgeShape s2,Float angle1){
	HX_STACK_FRAME("box2D.dynamics.B2Body","connectEdges",0x21bb4bdf,"box2D.dynamics.B2Body.connectEdges","box2D/dynamics/B2Body.hx",46,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(s1,"s1")
	HX_STACK_ARG(s2,"s2")
	HX_STACK_ARG(angle1,"angle1")
	HX_STACK_LINE(47)
	Float angle2 = ::Math_obj::atan2(s2->getDirectionVector()->y,s2->getDirectionVector()->x);		HX_STACK_VAR(angle2,"angle2");
	HX_STACK_LINE(48)
	Float coreOffset = ::Math_obj::tan((((angle2 - angle1)) * 0.5));		HX_STACK_VAR(coreOffset,"coreOffset");
	HX_STACK_LINE(49)
	::box2D::common::math::B2Vec2 _g = s2->getDirectionVector();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(49)
	::box2D::common::math::B2Vec2 core = ::box2D::common::math::B2Math_obj::mulFV(coreOffset,_g);		HX_STACK_VAR(core,"core");
	HX_STACK_LINE(50)
	::box2D::common::math::B2Vec2 _g1 = s2->getNormalVector();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(50)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Math_obj::subtractVV(core,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(50)
	core = _g2;
	HX_STACK_LINE(51)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::mulFV(::box2D::common::B2Settings_obj::b2_toiSlop,core);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(51)
	core = _g3;
	HX_STACK_LINE(52)
	::box2D::common::math::B2Vec2 _g4 = s2->getVertex1();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(52)
	::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Math_obj::addVV(core,_g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(52)
	core = _g5;
	HX_STACK_LINE(53)
	::box2D::common::math::B2Vec2 _g6 = s1->getDirectionVector();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(53)
	::box2D::common::math::B2Vec2 _g7 = s2->getDirectionVector();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(53)
	::box2D::common::math::B2Vec2 cornerDir = ::box2D::common::math::B2Math_obj::addVV(_g6,_g7);		HX_STACK_VAR(cornerDir,"cornerDir");
	HX_STACK_LINE(54)
	cornerDir->normalize();
	HX_STACK_LINE(55)
	::box2D::common::math::B2Vec2 _g8 = s1->getDirectionVector();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(55)
	::box2D::common::math::B2Vec2 _g9 = s2->getNormalVector();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(55)
	Float _g10 = ::box2D::common::math::B2Math_obj::dot(_g8,_g9);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(55)
	bool convex = (_g10 > 0.0);		HX_STACK_VAR(convex,"convex");
	HX_STACK_LINE(56)
	s1->setNextEdge(s2,core,cornerDir,convex);
	HX_STACK_LINE(57)
	s2->setPrevEdge(s1,core,cornerDir,convex);
	HX_STACK_LINE(58)
	return angle2;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Body_obj,connectEdges,return )

::box2D::dynamics::B2Fixture B2Body_obj::createFixture( ::box2D::dynamics::B2FixtureDef def){
	HX_STACK_FRAME("box2D.dynamics.B2Body","createFixture",0x22faba3a,"box2D.dynamics.B2Body.createFixture","box2D/dynamics/B2Body.hx",70,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(def,"def")
	HX_STACK_LINE(72)
	bool _g = this->m_world->isLocked();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(72)
	if (((_g == true))){
		HX_STACK_LINE(74)
		return null();
	}
	HX_STACK_LINE(124)
	::box2D::dynamics::B2Fixture fixture = ::box2D::dynamics::B2Fixture_obj::__new();		HX_STACK_VAR(fixture,"fixture");
	HX_STACK_LINE(125)
	fixture->create(hx::ObjectPtr<OBJ_>(this),this->m_xf,def);
	HX_STACK_LINE(128)
	if (((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_activeFlag))) != (int)0))){
		HX_STACK_LINE(130)
		::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;		HX_STACK_VAR(broadPhase,"broadPhase");
		HX_STACK_LINE(131)
		fixture->createProxy(broadPhase,this->m_xf);
	}
	HX_STACK_LINE(134)
	fixture->m_next = this->m_fixtureList;
	HX_STACK_LINE(135)
	this->m_fixtureList = fixture;
	HX_STACK_LINE(136)
	++(this->m_fixtureCount);
	HX_STACK_LINE(138)
	fixture->m_body = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(141)
	if (((fixture->m_density > 0.0))){
		HX_STACK_LINE(143)
		this->resetMassData();
	}
	HX_STACK_LINE(148)
	hx::OrEq(this->m_world->m_flags,::box2D::dynamics::B2World_obj::e_newFixture);
	HX_STACK_LINE(150)
	return fixture;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,createFixture,return )

::box2D::dynamics::B2Fixture B2Body_obj::createFixture2( ::box2D::collision::shapes::B2Shape shape,hx::Null< Float >  __o_density){
Float density = __o_density.Default(0.0);
	HX_STACK_FRAME("box2D.dynamics.B2Body","createFixture2",0x786838b8,"box2D.dynamics.B2Body.createFixture2","box2D/dynamics/B2Body.hx",163,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(shape,"shape")
	HX_STACK_ARG(density,"density")
{
		HX_STACK_LINE(164)
		::box2D::dynamics::B2FixtureDef def = ::box2D::dynamics::B2FixtureDef_obj::__new();		HX_STACK_VAR(def,"def");
		HX_STACK_LINE(165)
		def->shape = shape;
		HX_STACK_LINE(166)
		def->density = density;
		HX_STACK_LINE(168)
		return this->createFixture(def);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,createFixture2,return )

Void B2Body_obj::DestroyFixture( ::box2D::dynamics::B2Fixture fixture){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","DestroyFixture",0x43ae6362,"box2D.dynamics.B2Body.DestroyFixture","box2D/dynamics/B2Body.hx",180,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fixture,"fixture")
		HX_STACK_LINE(182)
		bool _g = this->m_world->isLocked();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(182)
		if (((_g == true))){
			HX_STACK_LINE(184)
			return null();
		}
		HX_STACK_LINE(189)
		::box2D::dynamics::B2Fixture node = this->m_fixtureList;		HX_STACK_VAR(node,"node");
		HX_STACK_LINE(190)
		::box2D::dynamics::B2Fixture ppF = null();		HX_STACK_VAR(ppF,"ppF");
		HX_STACK_LINE(191)
		bool found = false;		HX_STACK_VAR(found,"found");
		HX_STACK_LINE(192)
		while((true)){
			HX_STACK_LINE(192)
			if ((!(((node != null()))))){
				HX_STACK_LINE(192)
				break;
			}
			HX_STACK_LINE(194)
			if (((node == fixture))){
				HX_STACK_LINE(196)
				if (((ppF != null()))){
					HX_STACK_LINE(197)
					ppF->m_next = fixture->m_next;
				}
				else{
					HX_STACK_LINE(199)
					this->m_fixtureList = fixture->m_next;
				}
				HX_STACK_LINE(201)
				found = true;
				HX_STACK_LINE(202)
				break;
			}
			HX_STACK_LINE(205)
			ppF = node;
			HX_STACK_LINE(206)
			node = node->m_next;
		}
		HX_STACK_LINE(213)
		::box2D::dynamics::contacts::B2ContactEdge edge = this->m_contactList;		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(214)
		while((true)){
			HX_STACK_LINE(214)
			if ((!(((edge != null()))))){
				HX_STACK_LINE(214)
				break;
			}
			HX_STACK_LINE(216)
			::box2D::dynamics::contacts::B2Contact c = edge->contact;		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(217)
			edge = edge->next;
			HX_STACK_LINE(219)
			::box2D::dynamics::B2Fixture fixtureA = c->getFixtureA();		HX_STACK_VAR(fixtureA,"fixtureA");
			HX_STACK_LINE(220)
			::box2D::dynamics::B2Fixture fixtureB = c->getFixtureB();		HX_STACK_VAR(fixtureB,"fixtureB");
			HX_STACK_LINE(221)
			if (((bool((fixture == fixtureA)) || bool((fixture == fixtureB))))){
				HX_STACK_LINE(225)
				this->m_world->m_contactManager->destroy(c);
			}
		}
		HX_STACK_LINE(230)
		if (((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_activeFlag))) != (int)0))){
			HX_STACK_LINE(232)
			::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;		HX_STACK_VAR(broadPhase,"broadPhase");
			HX_STACK_LINE(233)
			fixture->destroyProxy(broadPhase);
		}
		else{
		}
		HX_STACK_LINE(240)
		fixture->destroy();
		HX_STACK_LINE(241)
		fixture->m_body = null();
		HX_STACK_LINE(242)
		fixture->m_next = null();
		HX_STACK_LINE(244)
		--(this->m_fixtureCount);
		HX_STACK_LINE(247)
		this->resetMassData();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,DestroyFixture,(void))

Void B2Body_obj::setPositionAndAngle( ::box2D::common::math::B2Vec2 position,Float angle){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setPositionAndAngle",0xadd1c4d4,"box2D.dynamics.B2Body.setPositionAndAngle","box2D/dynamics/B2Body.hx",257,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(position,"position")
		HX_STACK_ARG(angle,"angle")
		HX_STACK_LINE(259)
		::box2D::dynamics::B2Fixture f;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(262)
		bool _g = this->m_world->isLocked();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(262)
		if (((_g == true))){
			HX_STACK_LINE(264)
			return null();
		}
		HX_STACK_LINE(267)
		this->m_xf->R->set(angle);
		HX_STACK_LINE(268)
		this->m_xf->position->setV(position);
		HX_STACK_LINE(272)
		::box2D::common::math::B2Mat22 tMat = this->m_xf->R;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(273)
		::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(275)
		this->m_sweep->c->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
		HX_STACK_LINE(277)
		this->m_sweep->c->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
		HX_STACK_LINE(279)
		hx::AddEq(this->m_sweep->c->x,this->m_xf->position->x);
		HX_STACK_LINE(280)
		hx::AddEq(this->m_sweep->c->y,this->m_xf->position->y);
		HX_STACK_LINE(282)
		this->m_sweep->c0->setV(this->m_sweep->c);
		HX_STACK_LINE(284)
		Float _g1 = this->m_sweep->a = angle;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(284)
		this->m_sweep->a0 = _g1;
		HX_STACK_LINE(286)
		::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;		HX_STACK_VAR(broadPhase,"broadPhase");
		HX_STACK_LINE(287)
		f = this->m_fixtureList;
		HX_STACK_LINE(288)
		while((true)){
			HX_STACK_LINE(288)
			if ((!(((f != null()))))){
				HX_STACK_LINE(288)
				break;
			}
			HX_STACK_LINE(290)
			f->synchronize(broadPhase,this->m_xf,this->m_xf);
			HX_STACK_LINE(291)
			f = f->m_next;
		}
		HX_STACK_LINE(293)
		this->m_world->m_contactManager->findNewContacts();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,setPositionAndAngle,(void))

Void B2Body_obj::setTransform( ::box2D::common::math::B2Transform xf){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setTransform",0xf64407fd,"box2D.dynamics.B2Body.setTransform","box2D/dynamics/B2Body.hx",304,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(xf,"xf")
		HX_STACK_LINE(305)
		Float _g = xf->getAngle();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(305)
		this->setPositionAndAngle(xf->position,_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setTransform,(void))

::box2D::common::math::B2Transform B2Body_obj::getTransform( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getTransform",0xe14ae489,"box2D.dynamics.B2Body.getTransform","box2D/dynamics/B2Body.hx",313,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(313)
	return this->m_xf;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getTransform,return )

::box2D::common::math::B2Vec2 B2Body_obj::getPosition( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getPosition",0x9492fc2c,"box2D.dynamics.B2Body.getPosition","box2D/dynamics/B2Body.hx",321,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(321)
	return this->m_xf->position;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getPosition,return )

Void B2Body_obj::setPosition( ::box2D::common::math::B2Vec2 position){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setPosition",0x9f000338,"box2D.dynamics.B2Body.setPosition","box2D/dynamics/B2Body.hx",329,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(position,"position")
		HX_STACK_LINE(330)
		Float _g = this->getAngle();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(330)
		this->setPositionAndAngle(position,_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setPosition,(void))

Float B2Body_obj::getAngle( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getAngle",0xdb8ee870,"box2D.dynamics.B2Body.getAngle","box2D/dynamics/B2Body.hx",338,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(338)
	return this->m_sweep->a;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getAngle,return )

Void B2Body_obj::setAngle( Float angle){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setAngle",0x89ec41e4,"box2D.dynamics.B2Body.setAngle","box2D/dynamics/B2Body.hx",346,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(angle,"angle")
		HX_STACK_LINE(347)
		::box2D::common::math::B2Vec2 _g = this->getPosition();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(347)
		this->setPositionAndAngle(_g,angle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAngle,(void))

::box2D::common::math::B2Vec2 B2Body_obj::getWorldCenter( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getWorldCenter",0x93b23224,"box2D.dynamics.B2Body.getWorldCenter","box2D/dynamics/B2Body.hx",355,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(355)
	return this->m_sweep->c;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getWorldCenter,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLocalCenter( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getLocalCenter",0x857f3dfd,"box2D.dynamics.B2Body.getLocalCenter","box2D/dynamics/B2Body.hx",362,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(362)
	return this->m_sweep->localCenter;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getLocalCenter,return )

Void B2Body_obj::setLinearVelocity( ::box2D::common::math::B2Vec2 v){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setLinearVelocity",0x313434f1,"box2D.dynamics.B2Body.setLinearVelocity","box2D/dynamics/B2Body.hx",369,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(370)
		if (((this->m_type == (int)0))){
			HX_STACK_LINE(372)
			return null();
		}
		HX_STACK_LINE(374)
		this->m_linearVelocity->setV(v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setLinearVelocity,(void))

::box2D::common::math::B2Vec2 B2Body_obj::getLinearVelocity( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getLinearVelocity",0x0dc65ce5,"box2D.dynamics.B2Body.getLinearVelocity","box2D/dynamics/B2Body.hx",382,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(382)
	return this->m_linearVelocity;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getLinearVelocity,return )

Void B2Body_obj::setAngularVelocity( Float omega){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setAngularVelocity",0x8276bc70,"box2D.dynamics.B2Body.setAngularVelocity","box2D/dynamics/B2Body.hx",389,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(omega,"omega")
		HX_STACK_LINE(390)
		if (((this->m_type == (int)0))){
			HX_STACK_LINE(392)
			return null();
		}
		HX_STACK_LINE(394)
		this->m_angularVelocity = omega;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAngularVelocity,(void))

Float B2Body_obj::getAngularVelocity( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getAngularVelocity",0xa5c789fc,"box2D.dynamics.B2Body.getAngularVelocity","box2D/dynamics/B2Body.hx",402,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(402)
	return this->m_angularVelocity;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getAngularVelocity,return )

::box2D::dynamics::B2BodyDef B2Body_obj::getDefinition( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getDefinition",0x911657d6,"box2D.dynamics.B2Body.getDefinition","box2D/dynamics/B2Body.hx",410,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(411)
	::box2D::dynamics::B2BodyDef bd = ::box2D::dynamics::B2BodyDef_obj::__new();		HX_STACK_VAR(bd,"bd");
	HX_STACK_LINE(412)
	int _g = this->getType();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(412)
	bd->type = _g;
	HX_STACK_LINE(413)
	bd->allowSleep = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == ::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
	HX_STACK_LINE(414)
	Float _g1 = this->getAngle();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(414)
	bd->angle = _g1;
	HX_STACK_LINE(415)
	bd->angularDamping = this->m_angularDamping;
	HX_STACK_LINE(416)
	bd->angularVelocity = this->m_angularVelocity;
	HX_STACK_LINE(417)
	bd->fixedRotation = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == ::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
	HX_STACK_LINE(418)
	bd->bullet = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_bulletFlag))) == ::box2D::dynamics::B2Body_obj::e_bulletFlag);
	HX_STACK_LINE(419)
	bd->awake = (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_awakeFlag))) == ::box2D::dynamics::B2Body_obj::e_awakeFlag);
	HX_STACK_LINE(420)
	bd->linearDamping = this->m_linearDamping;
	HX_STACK_LINE(421)
	::box2D::common::math::B2Vec2 _g2 = this->getLinearVelocity();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(421)
	bd->linearVelocity->setV(_g2);
	HX_STACK_LINE(422)
	::box2D::common::math::B2Vec2 _g3 = this->getPosition();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(422)
	bd->position = _g3;
	HX_STACK_LINE(423)
	Dynamic _g4 = this->getUserData();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(423)
	bd->userData = _g4;
	HX_STACK_LINE(424)
	return bd;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getDefinition,return )

Void B2Body_obj::applyForce( ::box2D::common::math::B2Vec2 force,::box2D::common::math::B2Vec2 point){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","applyForce",0x19196d70,"box2D.dynamics.B2Body.applyForce","box2D/dynamics/B2Body.hx",434,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(force,"force")
		HX_STACK_ARG(point,"point")
		HX_STACK_LINE(435)
		if (((this->m_type != (int)2))){
			HX_STACK_LINE(437)
			return null();
		}
		HX_STACK_LINE(440)
		bool _g = this->isAwake();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(440)
		if (((_g == false))){
			HX_STACK_LINE(442)
			this->setAwake(true);
		}
		HX_STACK_LINE(446)
		hx::AddEq(this->m_force->x,force->x);
		HX_STACK_LINE(447)
		hx::AddEq(this->m_force->y,force->y);
		HX_STACK_LINE(449)
		hx::AddEq(this->m_torque,((((point->x - this->m_sweep->c->x)) * force->y) - (((point->y - this->m_sweep->c->y)) * force->x)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,applyForce,(void))

Void B2Body_obj::applyTorque( Float torque){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","applyTorque",0x76300fa5,"box2D.dynamics.B2Body.applyTorque","box2D/dynamics/B2Body.hx",458,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(torque,"torque")
		HX_STACK_LINE(459)
		if (((this->m_type != (int)2))){
			HX_STACK_LINE(461)
			return null();
		}
		HX_STACK_LINE(464)
		bool _g = this->isAwake();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(464)
		if (((_g == false))){
			HX_STACK_LINE(466)
			this->setAwake(true);
		}
		HX_STACK_LINE(468)
		hx::AddEq(this->m_torque,torque);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,applyTorque,(void))

Void B2Body_obj::applyImpulse( ::box2D::common::math::B2Vec2 impulse,::box2D::common::math::B2Vec2 point){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","applyImpulse",0x398bb77a,"box2D.dynamics.B2Body.applyImpulse","box2D/dynamics/B2Body.hx",478,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(impulse,"impulse")
		HX_STACK_ARG(point,"point")
		HX_STACK_LINE(479)
		if (((this->m_type != (int)2))){
			HX_STACK_LINE(481)
			return null();
		}
		HX_STACK_LINE(484)
		bool _g = this->isAwake();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(484)
		if (((_g == false))){
			HX_STACK_LINE(486)
			this->setAwake(true);
		}
		HX_STACK_LINE(489)
		hx::AddEq(this->m_linearVelocity->x,(this->m_invMass * impulse->x));
		HX_STACK_LINE(490)
		hx::AddEq(this->m_linearVelocity->y,(this->m_invMass * impulse->y));
		HX_STACK_LINE(492)
		hx::AddEq(this->m_angularVelocity,(this->m_invI * (((((point->x - this->m_sweep->c->x)) * impulse->y) - (((point->y - this->m_sweep->c->y)) * impulse->x)))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Body_obj,applyImpulse,(void))

::box2D::dynamics::B2Body B2Body_obj::split( Dynamic callbackMethod){
	HX_STACK_FRAME("box2D.dynamics.B2Body","split",0xd309bbe7,"box2D.dynamics.B2Body.split","box2D/dynamics/B2Body.hx",503,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(callbackMethod,"callbackMethod")
	HX_STACK_LINE(504)
	::box2D::common::math::B2Vec2 linearVelocity = this->getLinearVelocity()->copy();		HX_STACK_VAR(linearVelocity,"linearVelocity");
	HX_STACK_LINE(505)
	Float angularVelocity = this->getAngularVelocity();		HX_STACK_VAR(angularVelocity,"angularVelocity");
	HX_STACK_LINE(506)
	::box2D::common::math::B2Vec2 center = this->getWorldCenter();		HX_STACK_VAR(center,"center");
	HX_STACK_LINE(507)
	::box2D::dynamics::B2Body body1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(body1,"body1");
	HX_STACK_LINE(508)
	::box2D::dynamics::B2BodyDef _g = this->getDefinition();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(508)
	::box2D::dynamics::B2Body body2 = this->m_world->createBody(_g);		HX_STACK_VAR(body2,"body2");
	HX_STACK_LINE(510)
	::box2D::dynamics::B2Fixture prev = null();		HX_STACK_VAR(prev,"prev");
	HX_STACK_LINE(511)
	::box2D::dynamics::B2Fixture f = body1->m_fixtureList;		HX_STACK_VAR(f,"f");
	HX_STACK_LINE(512)
	while((true)){
		HX_STACK_LINE(512)
		if ((!(((f != null()))))){
			HX_STACK_LINE(512)
			break;
		}
		HX_STACK_LINE(514)
		if ((callbackMethod(f).Cast< bool >())){
			HX_STACK_LINE(516)
			::box2D::dynamics::B2Fixture next = f->m_next;		HX_STACK_VAR(next,"next");
			HX_STACK_LINE(518)
			if (((prev != null()))){
				HX_STACK_LINE(520)
				prev->m_next = next;
			}
			else{
				HX_STACK_LINE(522)
				body1->m_fixtureList = next;
			}
			HX_STACK_LINE(524)
			(body1->m_fixtureCount)--;
			HX_STACK_LINE(527)
			f->m_next = body2->m_fixtureList;
			HX_STACK_LINE(528)
			body2->m_fixtureList = f;
			HX_STACK_LINE(529)
			(body2->m_fixtureCount)++;
			HX_STACK_LINE(531)
			f->m_body = body2;
			HX_STACK_LINE(533)
			f = next;
		}
		else{
			HX_STACK_LINE(535)
			prev = f;
			HX_STACK_LINE(536)
			f = f->m_next;
		}
	}
	HX_STACK_LINE(540)
	body1->resetMassData();
	HX_STACK_LINE(541)
	body2->resetMassData();
	HX_STACK_LINE(544)
	::box2D::common::math::B2Vec2 center1 = body1->getWorldCenter();		HX_STACK_VAR(center1,"center1");
	HX_STACK_LINE(545)
	::box2D::common::math::B2Vec2 center2 = body2->getWorldCenter();		HX_STACK_VAR(center2,"center2");
	HX_STACK_LINE(549)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Math_obj::subtractVV(center1,center);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(548)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Math_obj::crossFV(angularVelocity,_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(547)
	::box2D::common::math::B2Vec2 velocity1 = ::box2D::common::math::B2Math_obj::addVV(linearVelocity,_g2);		HX_STACK_VAR(velocity1,"velocity1");
	HX_STACK_LINE(553)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::subtractVV(center2,center);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(552)
	::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Math_obj::crossFV(angularVelocity,_g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(551)
	::box2D::common::math::B2Vec2 velocity2 = ::box2D::common::math::B2Math_obj::addVV(linearVelocity,_g4);		HX_STACK_VAR(velocity2,"velocity2");
	HX_STACK_LINE(555)
	body1->setLinearVelocity(velocity1);
	HX_STACK_LINE(556)
	body2->setLinearVelocity(velocity2);
	HX_STACK_LINE(557)
	body1->setAngularVelocity(angularVelocity);
	HX_STACK_LINE(558)
	body2->setAngularVelocity(angularVelocity);
	HX_STACK_LINE(560)
	body1->synchronizeFixtures();
	HX_STACK_LINE(561)
	body2->synchronizeFixtures();
	HX_STACK_LINE(563)
	return body2;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,split,return )

Void B2Body_obj::merge( ::box2D::dynamics::B2Body other){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","merge",0x576173c5,"box2D.dynamics.B2Body.merge","box2D/dynamics/B2Body.hx",572,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(other,"other")
		HX_STACK_LINE(573)
		::box2D::dynamics::B2Fixture f;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(574)
		f = other->m_fixtureList;
		HX_STACK_LINE(577)
		::box2D::dynamics::B2Body body1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(body1,"body1");
		HX_STACK_LINE(578)
		::box2D::dynamics::B2Body body2 = other;		HX_STACK_VAR(body2,"body2");
		HX_STACK_LINE(580)
		while((true)){
			HX_STACK_LINE(580)
			if ((!(((f != null()))))){
				HX_STACK_LINE(580)
				break;
			}
			HX_STACK_LINE(582)
			::box2D::dynamics::B2Fixture next = f->m_next;		HX_STACK_VAR(next,"next");
			HX_STACK_LINE(585)
			(other->m_fixtureCount)--;
			HX_STACK_LINE(588)
			f->m_next = this->m_fixtureList;
			HX_STACK_LINE(589)
			this->m_fixtureList = f;
			HX_STACK_LINE(590)
			(this->m_fixtureCount)++;
			HX_STACK_LINE(592)
			f->m_body = body2;
			HX_STACK_LINE(594)
			f = next;
		}
		HX_STACK_LINE(596)
		body1->m_fixtureCount = (int)0;
		HX_STACK_LINE(599)
		::box2D::common::math::B2Vec2 center1 = body1->getWorldCenter();		HX_STACK_VAR(center1,"center1");
		HX_STACK_LINE(600)
		::box2D::common::math::B2Vec2 center2 = body2->getWorldCenter();		HX_STACK_VAR(center2,"center2");
		HX_STACK_LINE(602)
		::box2D::common::math::B2Vec2 velocity1 = body1->getLinearVelocity()->copy();		HX_STACK_VAR(velocity1,"velocity1");
		HX_STACK_LINE(603)
		::box2D::common::math::B2Vec2 velocity2 = body2->getLinearVelocity()->copy();		HX_STACK_VAR(velocity2,"velocity2");
		HX_STACK_LINE(605)
		Float angular1 = body1->getAngularVelocity();		HX_STACK_VAR(angular1,"angular1");
		HX_STACK_LINE(606)
		Float angular = body2->getAngularVelocity();		HX_STACK_VAR(angular,"angular");
		HX_STACK_LINE(610)
		body1->resetMassData();
		HX_STACK_LINE(612)
		this->synchronizeFixtures();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,merge,(void))

Float B2Body_obj::getMass( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getMass",0x2593def7,"box2D.dynamics.B2Body.getMass","box2D/dynamics/B2Body.hx",620,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(620)
	return this->m_mass;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getMass,return )

Float B2Body_obj::getInertia( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getInertia",0x354f76d7,"box2D.dynamics.B2Body.getInertia","box2D/dynamics/B2Body.hx",628,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(628)
	return this->m_I;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getInertia,return )

Void B2Body_obj::getMassData( ::box2D::collision::shapes::B2MassData data){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","getMassData",0x4510a8c1,"box2D.dynamics.B2Body.getMassData","box2D/dynamics/B2Body.hx",635,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(636)
		data->mass = this->m_mass;
		HX_STACK_LINE(637)
		data->I = this->m_I;
		HX_STACK_LINE(638)
		data->center->setV(this->m_sweep->localCenter);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getMassData,(void))

Void B2Body_obj::setMassData( ::box2D::collision::shapes::B2MassData massData){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setMassData",0x4f7dafcd,"box2D.dynamics.B2Body.setMassData","box2D/dynamics/B2Body.hx",650,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(massData,"massData")
		HX_STACK_LINE(651)
		bool _g = this->m_world->isLocked();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(651)
		bool _g1 = (_g == false);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(651)
		::box2D::common::B2Settings_obj::b2Assert(_g1);
		HX_STACK_LINE(652)
		bool _g2 = this->m_world->isLocked();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(652)
		if (((_g2 == true))){
			HX_STACK_LINE(654)
			return null();
		}
		HX_STACK_LINE(657)
		if (((this->m_type != (int)2))){
			HX_STACK_LINE(659)
			return null();
		}
		HX_STACK_LINE(662)
		this->m_invMass = 0.0;
		HX_STACK_LINE(663)
		this->m_I = 0.0;
		HX_STACK_LINE(664)
		this->m_invI = 0.0;
		HX_STACK_LINE(666)
		this->m_mass = massData->mass;
		HX_STACK_LINE(669)
		if (((this->m_mass <= 0.0))){
			HX_STACK_LINE(671)
			this->m_mass = 1.0;
		}
		HX_STACK_LINE(673)
		this->m_invMass = (Float(1.0) / Float(this->m_mass));
		HX_STACK_LINE(675)
		if (((bool((massData->I > 0.0)) && bool((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == (int)0))))){
			HX_STACK_LINE(678)
			this->m_I = (massData->I - (this->m_mass * (((massData->center->x * massData->center->x) + (massData->center->y * massData->center->y)))));
			HX_STACK_LINE(679)
			this->m_invI = (Float(1.0) / Float(this->m_I));
		}
		HX_STACK_LINE(683)
		::box2D::common::math::B2Vec2 oldCenter = this->m_sweep->c->copy();		HX_STACK_VAR(oldCenter,"oldCenter");
		HX_STACK_LINE(684)
		this->m_sweep->localCenter->setV(massData->center);
		HX_STACK_LINE(685)
		::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::mulX(this->m_xf,this->m_sweep->localCenter);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(685)
		this->m_sweep->c0->setV(_g3);
		HX_STACK_LINE(686)
		this->m_sweep->c->setV(this->m_sweep->c0);
		HX_STACK_LINE(690)
		hx::AddEq(this->m_linearVelocity->x,(this->m_angularVelocity * -(((this->m_sweep->c->y - oldCenter->y)))));
		HX_STACK_LINE(691)
		hx::AddEq(this->m_linearVelocity->y,(this->m_angularVelocity * ((this->m_sweep->c->x - oldCenter->x))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setMassData,(void))

Void B2Body_obj::resetMassData( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","resetMassData",0xf4ad603a,"box2D.dynamics.B2Body.resetMassData","box2D/dynamics/B2Body.hx",701,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_LINE(703)
		this->m_mass = 0.0;
		HX_STACK_LINE(704)
		this->m_invMass = 0.0;
		HX_STACK_LINE(705)
		this->m_I = 0.0;
		HX_STACK_LINE(706)
		this->m_invI = 0.0;
		HX_STACK_LINE(707)
		this->m_sweep->localCenter->setZero();
		HX_STACK_LINE(710)
		if (((bool((this->m_type == (int)0)) || bool((this->m_type == (int)1))))){
			HX_STACK_LINE(712)
			return null();
		}
		HX_STACK_LINE(717)
		::box2D::common::math::B2Vec2 center = ::box2D::common::math::B2Vec2_obj::make((int)0,(int)0);		HX_STACK_VAR(center,"center");
		HX_STACK_LINE(719)
		::box2D::dynamics::B2Fixture f = this->m_fixtureList;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(721)
		while((true)){
			HX_STACK_LINE(721)
			if ((!(((f != null()))))){
				HX_STACK_LINE(721)
				break;
			}
			HX_STACK_LINE(723)
			if (((f->m_density == 0.0))){
				HX_STACK_LINE(725)
				f = f->m_next;
				HX_STACK_LINE(726)
				continue;
			}
			HX_STACK_LINE(729)
			::box2D::collision::shapes::B2MassData massData = f->getMassData(null());		HX_STACK_VAR(massData,"massData");
			HX_STACK_LINE(730)
			hx::AddEq(this->m_mass,massData->mass);
			HX_STACK_LINE(731)
			hx::AddEq(center->x,(massData->center->x * massData->mass));
			HX_STACK_LINE(732)
			hx::AddEq(center->y,(massData->center->y * massData->mass));
			HX_STACK_LINE(733)
			hx::AddEq(this->m_I,massData->I);
			HX_STACK_LINE(735)
			f = f->m_next;
		}
		HX_STACK_LINE(739)
		if (((this->m_mass > 0.0))){
			HX_STACK_LINE(741)
			this->m_invMass = (Float(1.0) / Float(this->m_mass));
			HX_STACK_LINE(742)
			hx::MultEq(center->x,this->m_invMass);
			HX_STACK_LINE(743)
			hx::MultEq(center->y,this->m_invMass);
		}
		else{
			HX_STACK_LINE(748)
			this->m_mass = 1.0;
			HX_STACK_LINE(749)
			this->m_invMass = 1.0;
		}
		HX_STACK_LINE(752)
		if (((bool((this->m_I > 0.0)) && bool((((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == (int)0))))){
			HX_STACK_LINE(755)
			hx::SubEq(this->m_I,(this->m_mass * (((center->x * center->x) + (center->y * center->y)))));
			HX_STACK_LINE(756)
			hx::MultEq(this->m_I,this->m_inertiaScale);
			HX_STACK_LINE(757)
			::box2D::common::B2Settings_obj::b2Assert((this->m_I > (int)0));
			HX_STACK_LINE(758)
			this->m_invI = (Float(1.0) / Float(this->m_I));
		}
		else{
			HX_STACK_LINE(760)
			this->m_I = 0.0;
			HX_STACK_LINE(761)
			this->m_invI = 0.0;
		}
		HX_STACK_LINE(765)
		::box2D::common::math::B2Vec2 oldCenter = this->m_sweep->c->copy();		HX_STACK_VAR(oldCenter,"oldCenter");
		HX_STACK_LINE(766)
		this->m_sweep->localCenter->setV(center);
		HX_STACK_LINE(767)
		::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::mulX(this->m_xf,this->m_sweep->localCenter);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(767)
		this->m_sweep->c0->setV(_g);
		HX_STACK_LINE(768)
		this->m_sweep->c->setV(this->m_sweep->c0);
		HX_STACK_LINE(772)
		hx::AddEq(this->m_linearVelocity->x,(this->m_angularVelocity * -(((this->m_sweep->c->y - oldCenter->y)))));
		HX_STACK_LINE(773)
		hx::AddEq(this->m_linearVelocity->y,(this->m_angularVelocity * ((this->m_sweep->c->x - oldCenter->x))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,resetMassData,(void))

::box2D::common::math::B2Vec2 B2Body_obj::getWorldPoint( ::box2D::common::math::B2Vec2 localPoint){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getWorldPoint",0xd744e6e1,"box2D.dynamics.B2Body.getWorldPoint","box2D/dynamics/B2Body.hx",782,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(localPoint,"localPoint")
	HX_STACK_LINE(784)
	::box2D::common::math::B2Mat22 A = this->m_xf->R;		HX_STACK_VAR(A,"A");
	HX_STACK_LINE(785)
	::box2D::common::math::B2Vec2 u = ::box2D::common::math::B2Vec2_obj::__new(((A->col1->x * localPoint->x) + (A->col2->x * localPoint->y)),((A->col1->y * localPoint->x) + (A->col2->y * localPoint->y)));		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(787)
	hx::AddEq(u->x,this->m_xf->position->x);
	HX_STACK_LINE(788)
	hx::AddEq(u->y,this->m_xf->position->y);
	HX_STACK_LINE(789)
	return u;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getWorldPoint,return )

::box2D::common::math::B2Vec2 B2Body_obj::getWorldVector( ::box2D::common::math::B2Vec2 localVector){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getWorldVector",0x2534bd12,"box2D.dynamics.B2Body.getWorldVector","box2D/dynamics/B2Body.hx",798,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(localVector,"localVector")
	HX_STACK_LINE(798)
	return ::box2D::common::math::B2Math_obj::mulMV(this->m_xf->R,localVector);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getWorldVector,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLocalPoint( ::box2D::common::math::B2Vec2 worldPoint){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getLocalPoint",0xa38bd928,"box2D.dynamics.B2Body.getLocalPoint","box2D/dynamics/B2Body.hx",807,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(worldPoint,"worldPoint")
	HX_STACK_LINE(807)
	return ::box2D::common::math::B2Math_obj::mulXT(this->m_xf,worldPoint);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLocalPoint,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLocalVector( ::box2D::common::math::B2Vec2 worldVector){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getLocalVector",0x1701c8eb,"box2D.dynamics.B2Body.getLocalVector","box2D/dynamics/B2Body.hx",816,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(worldVector,"worldVector")
	HX_STACK_LINE(816)
	return ::box2D::common::math::B2Math_obj::mulTMV(this->m_xf->R,worldVector);
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLocalVector,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLinearVelocityFromWorldPoint( ::box2D::common::math::B2Vec2 worldPoint){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getLinearVelocityFromWorldPoint",0xe3838e6d,"box2D.dynamics.B2Body.getLinearVelocityFromWorldPoint","box2D/dynamics/B2Body.hx",827,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(worldPoint,"worldPoint")
	HX_STACK_LINE(827)
	return ::box2D::common::math::B2Vec2_obj::__new((this->m_linearVelocity->x - (this->m_angularVelocity * ((worldPoint->y - this->m_sweep->c->y)))),(this->m_linearVelocity->y + (this->m_angularVelocity * ((worldPoint->x - this->m_sweep->c->x)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLinearVelocityFromWorldPoint,return )

::box2D::common::math::B2Vec2 B2Body_obj::getLinearVelocityFromLocalPoint( ::box2D::common::math::B2Vec2 localPoint){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getLinearVelocityFromLocalPoint",0xafca80b4,"box2D.dynamics.B2Body.getLinearVelocityFromLocalPoint","box2D/dynamics/B2Body.hx",837,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(localPoint,"localPoint")
	HX_STACK_LINE(839)
	::box2D::common::math::B2Mat22 A = this->m_xf->R;		HX_STACK_VAR(A,"A");
	HX_STACK_LINE(840)
	::box2D::common::math::B2Vec2 worldPoint = ::box2D::common::math::B2Vec2_obj::__new(((A->col1->x * localPoint->x) + (A->col2->x * localPoint->y)),((A->col1->y * localPoint->x) + (A->col2->y * localPoint->y)));		HX_STACK_VAR(worldPoint,"worldPoint");
	HX_STACK_LINE(842)
	hx::AddEq(worldPoint->x,this->m_xf->position->x);
	HX_STACK_LINE(843)
	hx::AddEq(worldPoint->y,this->m_xf->position->y);
	HX_STACK_LINE(844)
	return ::box2D::common::math::B2Vec2_obj::__new((this->m_linearVelocity->x - (this->m_angularVelocity * ((worldPoint->y - this->m_sweep->c->y)))),(this->m_linearVelocity->y + (this->m_angularVelocity * ((worldPoint->x - this->m_sweep->c->x)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,getLinearVelocityFromLocalPoint,return )

Float B2Body_obj::getLinearDamping( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getLinearDamping",0x32f0a6fa,"box2D.dynamics.B2Body.getLinearDamping","box2D/dynamics/B2Body.hx",853,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(853)
	return this->m_linearDamping;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getLinearDamping,return )

Void B2Body_obj::setLinearDamping( Float linearDamping){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setLinearDamping",0x8932946e,"box2D.dynamics.B2Body.setLinearDamping","box2D/dynamics/B2Body.hx",861,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(linearDamping,"linearDamping")
		HX_STACK_LINE(861)
		this->m_linearDamping = linearDamping;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setLinearDamping,(void))

Float B2Body_obj::getAngularDamping( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getAngularDamping",0xf109e9c3,"box2D.dynamics.B2Body.getAngularDamping","box2D/dynamics/B2Body.hx",869,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(869)
	return this->m_angularDamping;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getAngularDamping,return )

Void B2Body_obj::setAngularDamping( Float angularDamping){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setAngularDamping",0x1477c1cf,"box2D.dynamics.B2Body.setAngularDamping","box2D/dynamics/B2Body.hx",877,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(angularDamping,"angularDamping")
		HX_STACK_LINE(877)
		this->m_angularDamping = angularDamping;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAngularDamping,(void))

Void B2Body_obj::setType( int type){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setType",0x1d4821c9,"box2D.dynamics.B2Body.setType","box2D/dynamics/B2Body.hx",885,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(type,"type")
		HX_STACK_LINE(886)
		if (((this->m_type == type))){
			HX_STACK_LINE(888)
			return null();
		}
		HX_STACK_LINE(891)
		this->m_type = type;
		HX_STACK_LINE(893)
		this->resetMassData();
		HX_STACK_LINE(895)
		if (((this->m_type == (int)0))){
			HX_STACK_LINE(897)
			this->m_linearVelocity->setZero();
			HX_STACK_LINE(898)
			this->m_angularVelocity = 0.0;
		}
		HX_STACK_LINE(901)
		this->setAwake(true);
		HX_STACK_LINE(903)
		this->m_force->setZero();
		HX_STACK_LINE(904)
		this->m_torque = 0.0;
		HX_STACK_LINE(907)
		::box2D::dynamics::contacts::B2ContactEdge ce = this->m_contactList;		HX_STACK_VAR(ce,"ce");
		HX_STACK_LINE(908)
		while((true)){
			HX_STACK_LINE(908)
			if ((!(((ce != null()))))){
				HX_STACK_LINE(908)
				break;
			}
			HX_STACK_LINE(910)
			ce->contact->flagForFiltering();
			HX_STACK_LINE(911)
			ce = ce->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setType,(void))

int B2Body_obj::getType( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getType",0x2a4690bd,"box2D.dynamics.B2Body.getType","box2D/dynamics/B2Body.hx",921,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(921)
	return this->m_type;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getType,return )

Void B2Body_obj::setBullet( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setBullet",0x9644e311,"box2D.dynamics.B2Body.setBullet","box2D/dynamics/B2Body.hx",928,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(928)
		if ((flag)){
			HX_STACK_LINE(930)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_bulletFlag);
		}
		else{
			HX_STACK_LINE(934)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_bulletFlag));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setBullet,(void))

bool B2Body_obj::isBullet( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","isBullet",0x85cfc2df,"box2D.dynamics.B2Body.isBullet","box2D/dynamics/B2Body.hx",942,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(942)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_bulletFlag))) == ::box2D::dynamics::B2Body_obj::e_bulletFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isBullet,return )

Void B2Body_obj::setSleepingAllowed( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setSleepingAllowed",0xca77898e,"box2D.dynamics.B2Body.setSleepingAllowed","box2D/dynamics/B2Body.hx",950,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(950)
		if ((flag)){
			HX_STACK_LINE(952)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
		}
		else{
			HX_STACK_LINE(956)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_allowSleepFlag));
			HX_STACK_LINE(957)
			this->setAwake(true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setSleepingAllowed,(void))

Void B2Body_obj::setAwake( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setAwake",0x8fda9f16,"box2D.dynamics.B2Body.setAwake","box2D/dynamics/B2Body.hx",966,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(966)
		if ((flag)){
			HX_STACK_LINE(968)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_awakeFlag);
			HX_STACK_LINE(969)
			this->m_sleepTime = 0.0;
		}
		else{
			HX_STACK_LINE(973)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_awakeFlag));
			HX_STACK_LINE(974)
			this->m_sleepTime = 0.0;
			HX_STACK_LINE(975)
			this->m_linearVelocity->setZero();
			HX_STACK_LINE(976)
			this->m_angularVelocity = 0.0;
			HX_STACK_LINE(977)
			this->m_force->setZero();
			HX_STACK_LINE(978)
			this->m_torque = 0.0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setAwake,(void))

bool B2Body_obj::isAwake( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","isAwake",0xd0113308,"box2D.dynamics.B2Body.isAwake","box2D/dynamics/B2Body.hx",987,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(987)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_awakeFlag))) == ::box2D::dynamics::B2Body_obj::e_awakeFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isAwake,return )

Void B2Body_obj::setFixedRotation( bool fixed){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setFixedRotation",0xf09e7de3,"box2D.dynamics.B2Body.setFixedRotation","box2D/dynamics/B2Body.hx",995,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fixed,"fixed")
		HX_STACK_LINE(996)
		if ((fixed)){
			HX_STACK_LINE(998)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
		}
		else{
			HX_STACK_LINE(1002)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag));
		}
		HX_STACK_LINE(1005)
		this->resetMassData();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setFixedRotation,(void))

bool B2Body_obj::isFixedRotation( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","isFixedRotation",0x5e5553d5,"box2D.dynamics.B2Body.isFixedRotation","box2D/dynamics/B2Body.hx",1014,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1014)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_fixedRotationFlag))) == ::box2D::dynamics::B2Body_obj::e_fixedRotationFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isFixedRotation,return )

Void B2Body_obj::setActive( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setActive",0xd7fa9295,"box2D.dynamics.B2Body.setActive","box2D/dynamics/B2Body.hx",1031,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(1032)
		bool _g = this->isActive();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1032)
		if (((flag == _g))){
			HX_STACK_LINE(1034)
			return null();
		}
		HX_STACK_LINE(1037)
		::box2D::collision::IBroadPhase broadPhase;		HX_STACK_VAR(broadPhase,"broadPhase");
		HX_STACK_LINE(1038)
		::box2D::dynamics::B2Fixture f;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(1039)
		if ((flag)){
			HX_STACK_LINE(1041)
			hx::OrEq(this->m_flags,::box2D::dynamics::B2Body_obj::e_activeFlag);
			HX_STACK_LINE(1044)
			broadPhase = this->m_world->m_contactManager->m_broadPhase;
			HX_STACK_LINE(1045)
			f = this->m_fixtureList;
			HX_STACK_LINE(1046)
			while((true)){
				HX_STACK_LINE(1046)
				if ((!(((f != null()))))){
					HX_STACK_LINE(1046)
					break;
				}
				HX_STACK_LINE(1048)
				f->createProxy(broadPhase,this->m_xf);
				HX_STACK_LINE(1049)
				f = f->m_next;
			}
		}
		else{
			HX_STACK_LINE(1055)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_activeFlag));
			HX_STACK_LINE(1058)
			broadPhase = this->m_world->m_contactManager->m_broadPhase;
			HX_STACK_LINE(1059)
			f = this->m_fixtureList;
			HX_STACK_LINE(1060)
			while((true)){
				HX_STACK_LINE(1060)
				if ((!(((f != null()))))){
					HX_STACK_LINE(1060)
					break;
				}
				HX_STACK_LINE(1062)
				f->destroyProxy(broadPhase);
				HX_STACK_LINE(1063)
				f = f->m_next;
			}
			HX_STACK_LINE(1067)
			::box2D::dynamics::contacts::B2ContactEdge ce = this->m_contactList;		HX_STACK_VAR(ce,"ce");
			HX_STACK_LINE(1068)
			while((true)){
				HX_STACK_LINE(1068)
				if ((!(((ce != null()))))){
					HX_STACK_LINE(1068)
					break;
				}
				HX_STACK_LINE(1070)
				::box2D::dynamics::contacts::B2ContactEdge ce0 = ce;		HX_STACK_VAR(ce0,"ce0");
				HX_STACK_LINE(1071)
				ce = ce->next;
				HX_STACK_LINE(1072)
				this->m_world->m_contactManager->destroy(ce0->contact);
			}
			HX_STACK_LINE(1074)
			this->m_contactList = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setActive,(void))

bool B2Body_obj::isActive( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","isActive",0xc7857263,"box2D.dynamics.B2Body.isActive","box2D/dynamics/B2Body.hx",1083,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1083)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_activeFlag))) == ::box2D::dynamics::B2Body_obj::e_activeFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isActive,return )

bool B2Body_obj::isSleepingAllowed( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","isSleepingAllowed",0x34054000,"box2D.dynamics.B2Body.isSleepingAllowed","box2D/dynamics/B2Body.hx",1091,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1091)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == ::box2D::dynamics::B2Body_obj::e_allowSleepFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,isSleepingAllowed,return )

::box2D::dynamics::B2Fixture B2Body_obj::getFixtureList( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getFixtureList",0xb59b9524,"box2D.dynamics.B2Body.getFixtureList","box2D/dynamics/B2Body.hx",1098,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1098)
	return this->m_fixtureList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getFixtureList,return )

::box2D::dynamics::joints::B2JointEdge B2Body_obj::getJointList( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getJointList",0xc723a5e5,"box2D.dynamics.B2Body.getJointList","box2D/dynamics/B2Body.hx",1105,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1105)
	return this->m_jointList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getJointList,return )

::box2D::dynamics::controllers::B2ControllerEdge B2Body_obj::getControllerList( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getControllerList",0x9d43bedd,"box2D.dynamics.B2Body.getControllerList","box2D/dynamics/B2Body.hx",1112,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1112)
	return this->m_controllerList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getControllerList,return )

::box2D::dynamics::contacts::B2ContactEdge B2Body_obj::getContactList( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getContactList",0xdb4c0b7b,"box2D.dynamics.B2Body.getContactList","box2D/dynamics/B2Body.hx",1119,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1119)
	return this->m_contactList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getContactList,return )

::box2D::dynamics::B2Body B2Body_obj::getNext( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getNext",0x264022f6,"box2D.dynamics.B2Body.getNext","box2D/dynamics/B2Body.hx",1126,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1126)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getNext,return )

Dynamic B2Body_obj::getUserData( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getUserData",0xcec0f198,"box2D.dynamics.B2Body.getUserData","box2D/dynamics/B2Body.hx",1133,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1133)
	return this->m_userData;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getUserData,return )

Void B2Body_obj::setUserData( Dynamic data){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","setUserData",0xd92df8a4,"box2D.dynamics.B2Body.setUserData","box2D/dynamics/B2Body.hx",1141,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(1141)
		this->m_userData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,setUserData,(void))

::box2D::dynamics::B2World B2Body_obj::getWorld( ){
	HX_STACK_FRAME("box2D.dynamics.B2Body","getWorld",0x87113aef,"box2D.dynamics.B2Body.getWorld","box2D/dynamics/B2Body.hx",1149,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1149)
	return this->m_world;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,getWorld,return )

Void B2Body_obj::synchronizeFixtures( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","synchronizeFixtures",0x9ef739c7,"box2D.dynamics.B2Body.synchronizeFixtures","box2D/dynamics/B2Body.hx",1270,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1272)
		::box2D::common::math::B2Transform xf1 = ::box2D::dynamics::B2Body_obj::s_xf1;		HX_STACK_VAR(xf1,"xf1");
		HX_STACK_LINE(1273)
		xf1->R->set(this->m_sweep->a0);
		HX_STACK_LINE(1275)
		::box2D::common::math::B2Mat22 tMat = xf1->R;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(1276)
		::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(1277)
		xf1->position->x = (this->m_sweep->c0->x - (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_STACK_LINE(1278)
		xf1->position->y = (this->m_sweep->c0->y - (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_STACK_LINE(1280)
		::box2D::dynamics::B2Fixture f;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(1281)
		::box2D::collision::IBroadPhase broadPhase = this->m_world->m_contactManager->m_broadPhase;		HX_STACK_VAR(broadPhase,"broadPhase");
		HX_STACK_LINE(1282)
		f = this->m_fixtureList;
		HX_STACK_LINE(1283)
		while((true)){
			HX_STACK_LINE(1283)
			if ((!(((f != null()))))){
				HX_STACK_LINE(1283)
				break;
			}
			HX_STACK_LINE(1285)
			f->synchronize(broadPhase,xf1,this->m_xf);
			HX_STACK_LINE(1286)
			f = f->m_next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,synchronizeFixtures,(void))

Void B2Body_obj::synchronizeTransform( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","synchronizeTransform",0xb40f1d8f,"box2D.dynamics.B2Body.synchronizeTransform","box2D/dynamics/B2Body.hx",1290,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_LINE(1291)
		this->m_xf->R->set(this->m_sweep->a);
		HX_STACK_LINE(1293)
		::box2D::common::math::B2Mat22 tMat = this->m_xf->R;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(1294)
		::box2D::common::math::B2Vec2 tVec = this->m_sweep->localCenter;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(1295)
		this->m_xf->position->x = (this->m_sweep->c->x - (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_STACK_LINE(1296)
		this->m_xf->position->y = (this->m_sweep->c->y - (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Body_obj,synchronizeTransform,(void))

bool B2Body_obj::shouldCollide( ::box2D::dynamics::B2Body other){
	HX_STACK_FRAME("box2D.dynamics.B2Body","shouldCollide",0x268e1198,"box2D.dynamics.B2Body.shouldCollide","box2D/dynamics/B2Body.hx",1301,0x26bd9c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(1303)
	if (((bool((this->m_type != (int)2)) && bool((other->m_type != (int)2))))){
		HX_STACK_LINE(1305)
		return false;
	}
	HX_STACK_LINE(1308)
	::box2D::dynamics::joints::B2JointEdge jn = this->m_jointList;		HX_STACK_VAR(jn,"jn");
	HX_STACK_LINE(1309)
	while((true)){
		HX_STACK_LINE(1309)
		if ((!(((jn != null()))))){
			HX_STACK_LINE(1309)
			break;
		}
		HX_STACK_LINE(1311)
		if (((jn->other == other))){
			HX_STACK_LINE(1312)
			if (((jn->joint->m_collideConnected == false))){
				HX_STACK_LINE(1314)
				return false;
			}
		}
		HX_STACK_LINE(1316)
		jn = jn->next;
	}
	HX_STACK_LINE(1319)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,shouldCollide,return )

Void B2Body_obj::advance( Float t){
{
		HX_STACK_FRAME("box2D.dynamics.B2Body","advance",0xf9c6f6cf,"box2D.dynamics.B2Body.advance","box2D/dynamics/B2Body.hx",1322,0x26bd9c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(1324)
		this->m_sweep->advance(t);
		HX_STACK_LINE(1325)
		this->m_sweep->c->setV(this->m_sweep->c0);
		HX_STACK_LINE(1326)
		this->m_sweep->a = this->m_sweep->a0;
		HX_STACK_LINE(1327)
		this->synchronizeTransform();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Body_obj,advance,(void))

::box2D::common::math::B2Transform B2Body_obj::s_xf1;

int B2Body_obj::e_islandFlag;

int B2Body_obj::e_awakeFlag;

int B2Body_obj::e_allowSleepFlag;

int B2Body_obj::e_bulletFlag;

int B2Body_obj::e_fixedRotationFlag;

int B2Body_obj::e_activeFlag;

int B2Body_obj::b2_staticBody;

int B2Body_obj::b2_kinematicBody;

int B2Body_obj::b2_dynamicBody;


B2Body_obj::B2Body_obj()
{
}

void B2Body_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Body);
	HX_MARK_MEMBER_NAME(m_flags,"m_flags");
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_islandIndex,"m_islandIndex");
	HX_MARK_MEMBER_NAME(m_xf,"m_xf");
	HX_MARK_MEMBER_NAME(m_sweep,"m_sweep");
	HX_MARK_MEMBER_NAME(m_linearVelocity,"m_linearVelocity");
	HX_MARK_MEMBER_NAME(m_angularVelocity,"m_angularVelocity");
	HX_MARK_MEMBER_NAME(m_force,"m_force");
	HX_MARK_MEMBER_NAME(m_torque,"m_torque");
	HX_MARK_MEMBER_NAME(m_world,"m_world");
	HX_MARK_MEMBER_NAME(m_prev,"m_prev");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_fixtureList,"m_fixtureList");
	HX_MARK_MEMBER_NAME(m_fixtureCount,"m_fixtureCount");
	HX_MARK_MEMBER_NAME(m_controllerList,"m_controllerList");
	HX_MARK_MEMBER_NAME(m_controllerCount,"m_controllerCount");
	HX_MARK_MEMBER_NAME(m_jointList,"m_jointList");
	HX_MARK_MEMBER_NAME(m_contactList,"m_contactList");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	HX_MARK_MEMBER_NAME(m_invMass,"m_invMass");
	HX_MARK_MEMBER_NAME(m_I,"m_I");
	HX_MARK_MEMBER_NAME(m_invI,"m_invI");
	HX_MARK_MEMBER_NAME(m_inertiaScale,"m_inertiaScale");
	HX_MARK_MEMBER_NAME(m_linearDamping,"m_linearDamping");
	HX_MARK_MEMBER_NAME(m_angularDamping,"m_angularDamping");
	HX_MARK_MEMBER_NAME(m_sleepTime,"m_sleepTime");
	HX_MARK_MEMBER_NAME(m_userData,"m_userData");
	HX_MARK_END_CLASS();
}

void B2Body_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_flags,"m_flags");
	HX_VISIT_MEMBER_NAME(m_type,"m_type");
	HX_VISIT_MEMBER_NAME(m_islandIndex,"m_islandIndex");
	HX_VISIT_MEMBER_NAME(m_xf,"m_xf");
	HX_VISIT_MEMBER_NAME(m_sweep,"m_sweep");
	HX_VISIT_MEMBER_NAME(m_linearVelocity,"m_linearVelocity");
	HX_VISIT_MEMBER_NAME(m_angularVelocity,"m_angularVelocity");
	HX_VISIT_MEMBER_NAME(m_force,"m_force");
	HX_VISIT_MEMBER_NAME(m_torque,"m_torque");
	HX_VISIT_MEMBER_NAME(m_world,"m_world");
	HX_VISIT_MEMBER_NAME(m_prev,"m_prev");
	HX_VISIT_MEMBER_NAME(m_next,"m_next");
	HX_VISIT_MEMBER_NAME(m_fixtureList,"m_fixtureList");
	HX_VISIT_MEMBER_NAME(m_fixtureCount,"m_fixtureCount");
	HX_VISIT_MEMBER_NAME(m_controllerList,"m_controllerList");
	HX_VISIT_MEMBER_NAME(m_controllerCount,"m_controllerCount");
	HX_VISIT_MEMBER_NAME(m_jointList,"m_jointList");
	HX_VISIT_MEMBER_NAME(m_contactList,"m_contactList");
	HX_VISIT_MEMBER_NAME(m_mass,"m_mass");
	HX_VISIT_MEMBER_NAME(m_invMass,"m_invMass");
	HX_VISIT_MEMBER_NAME(m_I,"m_I");
	HX_VISIT_MEMBER_NAME(m_invI,"m_invI");
	HX_VISIT_MEMBER_NAME(m_inertiaScale,"m_inertiaScale");
	HX_VISIT_MEMBER_NAME(m_linearDamping,"m_linearDamping");
	HX_VISIT_MEMBER_NAME(m_angularDamping,"m_angularDamping");
	HX_VISIT_MEMBER_NAME(m_sleepTime,"m_sleepTime");
	HX_VISIT_MEMBER_NAME(m_userData,"m_userData");
}

Dynamic B2Body_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_I") ) { return m_I; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_xf") ) { return m_xf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"s_xf1") ) { return s_xf1; }
		if (HX_FIELD_EQ(inName,"split") ) { return split_dyn(); }
		if (HX_FIELD_EQ(inName,"merge") ) { return merge_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { return m_prev; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		if (HX_FIELD_EQ(inName,"m_invI") ) { return m_invI; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getMass") ) { return getMass_dyn(); }
		if (HX_FIELD_EQ(inName,"setType") ) { return setType_dyn(); }
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"isAwake") ) { return isAwake_dyn(); }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"advance") ) { return advance_dyn(); }
		if (HX_FIELD_EQ(inName,"m_flags") ) { return m_flags; }
		if (HX_FIELD_EQ(inName,"m_sweep") ) { return m_sweep; }
		if (HX_FIELD_EQ(inName,"m_force") ) { return m_force; }
		if (HX_FIELD_EQ(inName,"m_world") ) { return m_world; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAngle") ) { return getAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"setAngle") ) { return setAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"isBullet") ) { return isBullet_dyn(); }
		if (HX_FIELD_EQ(inName,"setAwake") ) { return setAwake_dyn(); }
		if (HX_FIELD_EQ(inName,"isActive") ) { return isActive_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorld") ) { return getWorld_dyn(); }
		if (HX_FIELD_EQ(inName,"m_torque") ) { return m_torque; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setBullet") ) { return setBullet_dyn(); }
		if (HX_FIELD_EQ(inName,"setActive") ) { return setActive_dyn(); }
		if (HX_FIELD_EQ(inName,"m_invMass") ) { return m_invMass; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"applyForce") ) { return applyForce_dyn(); }
		if (HX_FIELD_EQ(inName,"getInertia") ) { return getInertia_dyn(); }
		if (HX_FIELD_EQ(inName,"m_userData") ) { return m_userData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"e_awakeFlag") ) { return e_awakeFlag; }
		if (HX_FIELD_EQ(inName,"getPosition") ) { return getPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"setPosition") ) { return setPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"applyTorque") ) { return applyTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"getMassData") ) { return getMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"setMassData") ) { return setMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"setUserData") ) { return setUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { return m_jointList; }
		if (HX_FIELD_EQ(inName,"m_sleepTime") ) { return m_sleepTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { return e_islandFlag; }
		if (HX_FIELD_EQ(inName,"e_bulletFlag") ) { return e_bulletFlag; }
		if (HX_FIELD_EQ(inName,"e_activeFlag") ) { return e_activeFlag; }
		if (HX_FIELD_EQ(inName,"connectEdges") ) { return connectEdges_dyn(); }
		if (HX_FIELD_EQ(inName,"setTransform") ) { return setTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getTransform") ) { return getTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"applyImpulse") ) { return applyImpulse_dyn(); }
		if (HX_FIELD_EQ(inName,"getJointList") ) { return getJointList_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_staticBody") ) { return b2_staticBody; }
		if (HX_FIELD_EQ(inName,"createFixture") ) { return createFixture_dyn(); }
		if (HX_FIELD_EQ(inName,"getDefinition") ) { return getDefinition_dyn(); }
		if (HX_FIELD_EQ(inName,"resetMassData") ) { return resetMassData_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorldPoint") ) { return getWorldPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getLocalPoint") ) { return getLocalPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"shouldCollide") ) { return shouldCollide_dyn(); }
		if (HX_FIELD_EQ(inName,"m_islandIndex") ) { return m_islandIndex; }
		if (HX_FIELD_EQ(inName,"m_fixtureList") ) { return m_fixtureList; }
		if (HX_FIELD_EQ(inName,"m_contactList") ) { return m_contactList; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_dynamicBody") ) { return b2_dynamicBody; }
		if (HX_FIELD_EQ(inName,"createFixture2") ) { return createFixture2_dyn(); }
		if (HX_FIELD_EQ(inName,"DestroyFixture") ) { return DestroyFixture_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorldCenter") ) { return getWorldCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"getLocalCenter") ) { return getLocalCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"getWorldVector") ) { return getWorldVector_dyn(); }
		if (HX_FIELD_EQ(inName,"getLocalVector") ) { return getLocalVector_dyn(); }
		if (HX_FIELD_EQ(inName,"getFixtureList") ) { return getFixtureList_dyn(); }
		if (HX_FIELD_EQ(inName,"getContactList") ) { return getContactList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_fixtureCount") ) { return m_fixtureCount; }
		if (HX_FIELD_EQ(inName,"m_inertiaScale") ) { return m_inertiaScale; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isFixedRotation") ) { return isFixedRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"m_linearDamping") ) { return m_linearDamping; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_allowSleepFlag") ) { return e_allowSleepFlag; }
		if (HX_FIELD_EQ(inName,"b2_kinematicBody") ) { return b2_kinematicBody; }
		if (HX_FIELD_EQ(inName,"getLinearDamping") ) { return getLinearDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"setLinearDamping") ) { return setLinearDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"setFixedRotation") ) { return setFixedRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"m_linearVelocity") ) { return m_linearVelocity; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { return m_controllerList; }
		if (HX_FIELD_EQ(inName,"m_angularDamping") ) { return m_angularDamping; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"setLinearVelocity") ) { return setLinearVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"getLinearVelocity") ) { return getLinearVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"getAngularDamping") ) { return getAngularDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"setAngularDamping") ) { return setAngularDamping_dyn(); }
		if (HX_FIELD_EQ(inName,"isSleepingAllowed") ) { return isSleepingAllowed_dyn(); }
		if (HX_FIELD_EQ(inName,"getControllerList") ) { return getControllerList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_angularVelocity") ) { return m_angularVelocity; }
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { return m_controllerCount; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setAngularVelocity") ) { return setAngularVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"getAngularVelocity") ) { return getAngularVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"setSleepingAllowed") ) { return setSleepingAllowed_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"e_fixedRotationFlag") ) { return e_fixedRotationFlag; }
		if (HX_FIELD_EQ(inName,"setPositionAndAngle") ) { return setPositionAndAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"synchronizeFixtures") ) { return synchronizeFixtures_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"synchronizeTransform") ) { return synchronizeTransform_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"getLinearVelocityFromWorldPoint") ) { return getLinearVelocityFromWorldPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getLinearVelocityFromLocalPoint") ) { return getLinearVelocityFromLocalPoint_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Body_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_I") ) { m_I=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_xf") ) { m_xf=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"s_xf1") ) { s_xf1=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { m_prev=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invI") ) { m_invI=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_flags") ) { m_flags=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_sweep") ) { m_sweep=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_force") ) { m_force=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_world") ) { m_world=inValue.Cast< ::box2D::dynamics::B2World >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_torque") ) { m_torque=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_invMass") ) { m_invMass=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_userData") ) { m_userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"e_awakeFlag") ) { e_awakeFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { m_jointList=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_sleepTime") ) { m_sleepTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { e_islandFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_bulletFlag") ) { e_bulletFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_activeFlag") ) { e_activeFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_staticBody") ) { b2_staticBody=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_islandIndex") ) { m_islandIndex=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fixtureList") ) { m_fixtureList=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_contactList") ) { m_contactList=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_dynamicBody") ) { b2_dynamicBody=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fixtureCount") ) { m_fixtureCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_inertiaScale") ) { m_inertiaScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_linearDamping") ) { m_linearDamping=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_allowSleepFlag") ) { e_allowSleepFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_kinematicBody") ) { b2_kinematicBody=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_linearVelocity") ) { m_linearVelocity=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { m_controllerList=inValue.Cast< ::box2D::dynamics::controllers::B2ControllerEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_angularDamping") ) { m_angularDamping=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_angularVelocity") ) { m_angularVelocity=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { m_controllerCount=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"e_fixedRotationFlag") ) { e_fixedRotationFlag=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Body_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_flags"));
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_islandIndex"));
	outFields->push(HX_CSTRING("m_xf"));
	outFields->push(HX_CSTRING("m_sweep"));
	outFields->push(HX_CSTRING("m_linearVelocity"));
	outFields->push(HX_CSTRING("m_angularVelocity"));
	outFields->push(HX_CSTRING("m_force"));
	outFields->push(HX_CSTRING("m_torque"));
	outFields->push(HX_CSTRING("m_world"));
	outFields->push(HX_CSTRING("m_prev"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_fixtureList"));
	outFields->push(HX_CSTRING("m_fixtureCount"));
	outFields->push(HX_CSTRING("m_controllerList"));
	outFields->push(HX_CSTRING("m_controllerCount"));
	outFields->push(HX_CSTRING("m_jointList"));
	outFields->push(HX_CSTRING("m_contactList"));
	outFields->push(HX_CSTRING("m_mass"));
	outFields->push(HX_CSTRING("m_invMass"));
	outFields->push(HX_CSTRING("m_I"));
	outFields->push(HX_CSTRING("m_invI"));
	outFields->push(HX_CSTRING("m_inertiaScale"));
	outFields->push(HX_CSTRING("m_linearDamping"));
	outFields->push(HX_CSTRING("m_angularDamping"));
	outFields->push(HX_CSTRING("m_sleepTime"));
	outFields->push(HX_CSTRING("m_userData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_xf1"),
	HX_CSTRING("e_islandFlag"),
	HX_CSTRING("e_awakeFlag"),
	HX_CSTRING("e_allowSleepFlag"),
	HX_CSTRING("e_bulletFlag"),
	HX_CSTRING("e_fixedRotationFlag"),
	HX_CSTRING("e_activeFlag"),
	HX_CSTRING("b2_staticBody"),
	HX_CSTRING("b2_kinematicBody"),
	HX_CSTRING("b2_dynamicBody"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2Body_obj,m_flags),HX_CSTRING("m_flags")},
	{hx::fsInt,(int)offsetof(B2Body_obj,m_type),HX_CSTRING("m_type")},
	{hx::fsInt,(int)offsetof(B2Body_obj,m_islandIndex),HX_CSTRING("m_islandIndex")},
	{hx::fsObject /*::box2D::common::math::B2Transform*/ ,(int)offsetof(B2Body_obj,m_xf),HX_CSTRING("m_xf")},
	{hx::fsObject /*::box2D::common::math::B2Sweep*/ ,(int)offsetof(B2Body_obj,m_sweep),HX_CSTRING("m_sweep")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Body_obj,m_linearVelocity),HX_CSTRING("m_linearVelocity")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_angularVelocity),HX_CSTRING("m_angularVelocity")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Body_obj,m_force),HX_CSTRING("m_force")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_torque),HX_CSTRING("m_torque")},
	{hx::fsObject /*::box2D::dynamics::B2World*/ ,(int)offsetof(B2Body_obj,m_world),HX_CSTRING("m_world")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2Body_obj,m_prev),HX_CSTRING("m_prev")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2Body_obj,m_next),HX_CSTRING("m_next")},
	{hx::fsObject /*::box2D::dynamics::B2Fixture*/ ,(int)offsetof(B2Body_obj,m_fixtureList),HX_CSTRING("m_fixtureList")},
	{hx::fsInt,(int)offsetof(B2Body_obj,m_fixtureCount),HX_CSTRING("m_fixtureCount")},
	{hx::fsObject /*::box2D::dynamics::controllers::B2ControllerEdge*/ ,(int)offsetof(B2Body_obj,m_controllerList),HX_CSTRING("m_controllerList")},
	{hx::fsInt,(int)offsetof(B2Body_obj,m_controllerCount),HX_CSTRING("m_controllerCount")},
	{hx::fsObject /*::box2D::dynamics::joints::B2JointEdge*/ ,(int)offsetof(B2Body_obj,m_jointList),HX_CSTRING("m_jointList")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactEdge*/ ,(int)offsetof(B2Body_obj,m_contactList),HX_CSTRING("m_contactList")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_mass),HX_CSTRING("m_mass")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_invMass),HX_CSTRING("m_invMass")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_I),HX_CSTRING("m_I")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_invI),HX_CSTRING("m_invI")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_inertiaScale),HX_CSTRING("m_inertiaScale")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_linearDamping),HX_CSTRING("m_linearDamping")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_angularDamping),HX_CSTRING("m_angularDamping")},
	{hx::fsFloat,(int)offsetof(B2Body_obj,m_sleepTime),HX_CSTRING("m_sleepTime")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2Body_obj,m_userData),HX_CSTRING("m_userData")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("connectEdges"),
	HX_CSTRING("createFixture"),
	HX_CSTRING("createFixture2"),
	HX_CSTRING("DestroyFixture"),
	HX_CSTRING("setPositionAndAngle"),
	HX_CSTRING("setTransform"),
	HX_CSTRING("getTransform"),
	HX_CSTRING("getPosition"),
	HX_CSTRING("setPosition"),
	HX_CSTRING("getAngle"),
	HX_CSTRING("setAngle"),
	HX_CSTRING("getWorldCenter"),
	HX_CSTRING("getLocalCenter"),
	HX_CSTRING("setLinearVelocity"),
	HX_CSTRING("getLinearVelocity"),
	HX_CSTRING("setAngularVelocity"),
	HX_CSTRING("getAngularVelocity"),
	HX_CSTRING("getDefinition"),
	HX_CSTRING("applyForce"),
	HX_CSTRING("applyTorque"),
	HX_CSTRING("applyImpulse"),
	HX_CSTRING("split"),
	HX_CSTRING("merge"),
	HX_CSTRING("getMass"),
	HX_CSTRING("getInertia"),
	HX_CSTRING("getMassData"),
	HX_CSTRING("setMassData"),
	HX_CSTRING("resetMassData"),
	HX_CSTRING("getWorldPoint"),
	HX_CSTRING("getWorldVector"),
	HX_CSTRING("getLocalPoint"),
	HX_CSTRING("getLocalVector"),
	HX_CSTRING("getLinearVelocityFromWorldPoint"),
	HX_CSTRING("getLinearVelocityFromLocalPoint"),
	HX_CSTRING("getLinearDamping"),
	HX_CSTRING("setLinearDamping"),
	HX_CSTRING("getAngularDamping"),
	HX_CSTRING("setAngularDamping"),
	HX_CSTRING("setType"),
	HX_CSTRING("getType"),
	HX_CSTRING("setBullet"),
	HX_CSTRING("isBullet"),
	HX_CSTRING("setSleepingAllowed"),
	HX_CSTRING("setAwake"),
	HX_CSTRING("isAwake"),
	HX_CSTRING("setFixedRotation"),
	HX_CSTRING("isFixedRotation"),
	HX_CSTRING("setActive"),
	HX_CSTRING("isActive"),
	HX_CSTRING("isSleepingAllowed"),
	HX_CSTRING("getFixtureList"),
	HX_CSTRING("getJointList"),
	HX_CSTRING("getControllerList"),
	HX_CSTRING("getContactList"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("setUserData"),
	HX_CSTRING("getWorld"),
	HX_CSTRING("synchronizeFixtures"),
	HX_CSTRING("synchronizeTransform"),
	HX_CSTRING("shouldCollide"),
	HX_CSTRING("advance"),
	HX_CSTRING("m_flags"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_islandIndex"),
	HX_CSTRING("m_xf"),
	HX_CSTRING("m_sweep"),
	HX_CSTRING("m_linearVelocity"),
	HX_CSTRING("m_angularVelocity"),
	HX_CSTRING("m_force"),
	HX_CSTRING("m_torque"),
	HX_CSTRING("m_world"),
	HX_CSTRING("m_prev"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_fixtureList"),
	HX_CSTRING("m_fixtureCount"),
	HX_CSTRING("m_controllerList"),
	HX_CSTRING("m_controllerCount"),
	HX_CSTRING("m_jointList"),
	HX_CSTRING("m_contactList"),
	HX_CSTRING("m_mass"),
	HX_CSTRING("m_invMass"),
	HX_CSTRING("m_I"),
	HX_CSTRING("m_invI"),
	HX_CSTRING("m_inertiaScale"),
	HX_CSTRING("m_linearDamping"),
	HX_CSTRING("m_angularDamping"),
	HX_CSTRING("m_sleepTime"),
	HX_CSTRING("m_userData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Body_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Body_obj::s_xf1,"s_xf1");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_islandFlag,"e_islandFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_awakeFlag,"e_awakeFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_allowSleepFlag,"e_allowSleepFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_bulletFlag,"e_bulletFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_fixedRotationFlag,"e_fixedRotationFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::e_activeFlag,"e_activeFlag");
	HX_MARK_MEMBER_NAME(B2Body_obj::b2_staticBody,"b2_staticBody");
	HX_MARK_MEMBER_NAME(B2Body_obj::b2_kinematicBody,"b2_kinematicBody");
	HX_MARK_MEMBER_NAME(B2Body_obj::b2_dynamicBody,"b2_dynamicBody");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Body_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Body_obj::s_xf1,"s_xf1");
	HX_VISIT_MEMBER_NAME(B2Body_obj::e_islandFlag,"e_islandFlag");
	HX_VISIT_MEMBER_NAME(B2Body_obj::e_awakeFlag,"e_awakeFlag");
	HX_VISIT_MEMBER_NAME(B2Body_obj::e_allowSleepFlag,"e_allowSleepFlag");
	HX_VISIT_MEMBER_NAME(B2Body_obj::e_bulletFlag,"e_bulletFlag");
	HX_VISIT_MEMBER_NAME(B2Body_obj::e_fixedRotationFlag,"e_fixedRotationFlag");
	HX_VISIT_MEMBER_NAME(B2Body_obj::e_activeFlag,"e_activeFlag");
	HX_VISIT_MEMBER_NAME(B2Body_obj::b2_staticBody,"b2_staticBody");
	HX_VISIT_MEMBER_NAME(B2Body_obj::b2_kinematicBody,"b2_kinematicBody");
	HX_VISIT_MEMBER_NAME(B2Body_obj::b2_dynamicBody,"b2_dynamicBody");
};

#endif

Class B2Body_obj::__mClass;

void B2Body_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2Body"), hx::TCanCast< B2Body_obj> ,sStaticFields,sMemberFields,
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

void B2Body_obj::__boot()
{
	s_xf1= ::box2D::common::math::B2Transform_obj::__new(null(),null());
	e_islandFlag= (int)1;
	e_awakeFlag= (int)2;
	e_allowSleepFlag= (int)4;
	e_bulletFlag= (int)8;
	e_fixedRotationFlag= (int)16;
	e_activeFlag= (int)32;
	b2_staticBody= (int)0;
	b2_kinematicBody= (int)1;
	b2_dynamicBody= (int)2;
}

} // end namespace box2D
} // end namespace dynamics
