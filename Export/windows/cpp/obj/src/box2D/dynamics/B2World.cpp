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
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
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
#ifndef INCLUDED_box2D_common_B2Color
#include <box2D/common/B2Color.h>
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
#ifndef INCLUDED_box2D_dynamics_B2ContactFilter
#include <box2D/dynamics/B2ContactFilter.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactManager
#include <box2D/dynamics/B2ContactManager.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2DebugDraw
#include <box2D/dynamics/B2DebugDraw.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2DestructionListener
#include <box2D/dynamics/B2DestructionListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Island
#include <box2D/dynamics/B2Island.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
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
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactSolver
#include <box2D/dynamics/contacts/B2ContactSolver.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2Controller
#include <box2D/dynamics/controllers/B2Controller.h>
#endif
#ifndef INCLUDED_box2D_dynamics_controllers_B2ControllerEdge
#include <box2D/dynamics/controllers/B2ControllerEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointEdge
#include <box2D/dynamics/joints/B2JointEdge.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
namespace box2D{
namespace dynamics{

Void B2World_obj::__construct(::box2D::common::math::B2Vec2 gravity,bool doSleep)
{
HX_STACK_FRAME("box2D.dynamics.B2World","new",0x65902e8b,"box2D.dynamics.B2World.new","box2D/dynamics/B2World.hx",60,0xb09d3b25)
HX_STACK_THIS(this)
HX_STACK_ARG(gravity,"gravity")
HX_STACK_ARG(doSleep,"doSleep")
{
	HX_STACK_LINE(62)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(62)
	this->s_stack = _g;
	HX_STACK_LINE(63)
	::box2D::dynamics::B2ContactManager _g1 = ::box2D::dynamics::B2ContactManager_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(63)
	this->m_contactManager = _g1;
	HX_STACK_LINE(64)
	::box2D::dynamics::contacts::B2ContactSolver _g2 = ::box2D::dynamics::contacts::B2ContactSolver_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(64)
	this->m_contactSolver = _g2;
	HX_STACK_LINE(65)
	::box2D::dynamics::B2Island _g3 = ::box2D::dynamics::B2Island_obj::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(65)
	this->m_island = _g3;
	HX_STACK_LINE(67)
	this->m_destructionListener = null();
	HX_STACK_LINE(68)
	this->m_debugDraw = null();
	HX_STACK_LINE(70)
	this->m_bodyList = null();
	HX_STACK_LINE(71)
	this->m_contactList = null();
	HX_STACK_LINE(72)
	this->m_jointList = null();
	HX_STACK_LINE(73)
	this->m_controllerList = null();
	HX_STACK_LINE(75)
	this->m_bodyCount = (int)0;
	HX_STACK_LINE(76)
	this->m_contactCount = (int)0;
	HX_STACK_LINE(77)
	this->m_jointCount = (int)0;
	HX_STACK_LINE(78)
	this->m_controllerCount = (int)0;
	HX_STACK_LINE(80)
	::box2D::dynamics::B2World_obj::m_warmStarting = true;
	HX_STACK_LINE(81)
	::box2D::dynamics::B2World_obj::m_continuousPhysics = true;
	HX_STACK_LINE(83)
	this->m_allowSleep = doSleep;
	HX_STACK_LINE(84)
	this->m_gravity = gravity;
	HX_STACK_LINE(86)
	this->m_inv_dt0 = 0.0;
	HX_STACK_LINE(88)
	this->m_flags = (int)0;
	HX_STACK_LINE(90)
	this->m_contactManager->m_world = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(92)
	::box2D::dynamics::B2BodyDef bd = ::box2D::dynamics::B2BodyDef_obj::__new();		HX_STACK_VAR(bd,"bd");
	HX_STACK_LINE(93)
	::box2D::dynamics::B2Body _g4 = this->createBody(bd);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(93)
	this->m_groundBody = _g4;
}
;
	return null();
}

//B2World_obj::~B2World_obj() { }

Dynamic B2World_obj::__CreateEmpty() { return  new B2World_obj; }
hx::ObjectPtr< B2World_obj > B2World_obj::__new(::box2D::common::math::B2Vec2 gravity,bool doSleep)
{  hx::ObjectPtr< B2World_obj > result = new B2World_obj();
	result->__construct(gravity,doSleep);
	return result;}

Dynamic B2World_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2World_obj > result = new B2World_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void B2World_obj::setDestructionListener( ::box2D::dynamics::B2DestructionListener listener){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setDestructionListener",0xd9d957b9,"box2D.dynamics.B2World.setDestructionListener","box2D/dynamics/B2World.hx",105,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(listener,"listener")
		HX_STACK_LINE(105)
		this->m_destructionListener = listener;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setDestructionListener,(void))

Void B2World_obj::setContactFilter( ::box2D::dynamics::B2ContactFilter filter){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setContactFilter",0xb7a0406b,"box2D.dynamics.B2World.setContactFilter","box2D/dynamics/B2World.hx",113,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(filter,"filter")
		HX_STACK_LINE(113)
		this->m_contactManager->m_contactFilter = filter;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setContactFilter,(void))

Void B2World_obj::setContactListener( ::box2D::dynamics::B2ContactListener listener){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setContactListener",0x342cf3e7,"box2D.dynamics.B2World.setContactListener","box2D/dynamics/B2World.hx",120,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(listener,"listener")
		HX_STACK_LINE(120)
		this->m_contactManager->m_contactListener = listener;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setContactListener,(void))

Void B2World_obj::setDebugDraw( ::box2D::dynamics::B2DebugDraw debugDraw){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setDebugDraw",0x01d5946a,"box2D.dynamics.B2World.setDebugDraw","box2D/dynamics/B2World.hx",129,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(debugDraw,"debugDraw")
		HX_STACK_LINE(129)
		this->m_debugDraw = debugDraw;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setDebugDraw,(void))

Void B2World_obj::setBroadPhase( ::box2D::collision::IBroadPhase broadPhase){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setBroadPhase",0x25bcedc6,"box2D.dynamics.B2World.setBroadPhase","box2D/dynamics/B2World.hx",138,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(broadPhase,"broadPhase")
		HX_STACK_LINE(139)
		::box2D::collision::IBroadPhase oldBroadPhase = this->m_contactManager->m_broadPhase;		HX_STACK_VAR(oldBroadPhase,"oldBroadPhase");
		HX_STACK_LINE(140)
		this->m_contactManager->m_broadPhase = broadPhase;
		HX_STACK_LINE(141)
		::box2D::dynamics::B2Body b = this->m_bodyList;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(142)
		while((true)){
			HX_STACK_LINE(142)
			if ((!(((b != null()))))){
				HX_STACK_LINE(142)
				break;
			}
			HX_STACK_LINE(144)
			::box2D::dynamics::B2Fixture f = b->m_fixtureList;		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(145)
			while((true)){
				HX_STACK_LINE(145)
				if ((!(((f != null()))))){
					HX_STACK_LINE(145)
					break;
				}
				HX_STACK_LINE(147)
				::box2D::collision::B2AABB _g = oldBroadPhase->getFatAABB(f->m_proxy);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(147)
				Dynamic _g1 = broadPhase->createProxy(_g,f);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(147)
				f->m_proxy = _g1;
				HX_STACK_LINE(148)
				f = f->m_next;
			}
			HX_STACK_LINE(150)
			b = b->m_next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setBroadPhase,(void))

Void B2World_obj::validate( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","validate",0xe36b368b,"box2D.dynamics.B2World.validate","box2D/dynamics/B2World.hx",159,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_LINE(159)
		this->m_contactManager->m_broadPhase->validate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,validate,(void))

int B2World_obj::getProxyCount( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getProxyCount",0x0f2ff5a2,"box2D.dynamics.B2World.getProxyCount","box2D/dynamics/B2World.hx",167,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(167)
	return this->m_contactManager->m_broadPhase->getProxyCount();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getProxyCount,return )

::box2D::dynamics::B2Body B2World_obj::createBody( ::box2D::dynamics::B2BodyDef def){
	HX_STACK_FRAME("box2D.dynamics.B2World","createBody",0x6f4dc8f3,"box2D.dynamics.B2World.createBody","box2D/dynamics/B2World.hx",175,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_ARG(def,"def")
	HX_STACK_LINE(178)
	bool _g = this->isLocked();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(178)
	if (((_g == true))){
		HX_STACK_LINE(180)
		return null();
	}
	HX_STACK_LINE(184)
	::box2D::dynamics::B2Body b = ::box2D::dynamics::B2Body_obj::__new(def,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(187)
	b->m_prev = null();
	HX_STACK_LINE(188)
	b->m_next = this->m_bodyList;
	HX_STACK_LINE(189)
	if (((this->m_bodyList != null()))){
		HX_STACK_LINE(191)
		this->m_bodyList->m_prev = b;
	}
	HX_STACK_LINE(193)
	this->m_bodyList = b;
	HX_STACK_LINE(194)
	++(this->m_bodyCount);
	HX_STACK_LINE(196)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,createBody,return )

Void B2World_obj::destroyBody( ::box2D::dynamics::B2Body b){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","destroyBody",0xb384d9e7,"box2D.dynamics.B2World.destroyBody","box2D/dynamics/B2World.hx",206,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(210)
		bool _g = this->isLocked();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(210)
		if (((_g == true))){
			HX_STACK_LINE(212)
			return null();
		}
		HX_STACK_LINE(216)
		::box2D::dynamics::joints::B2JointEdge jn = b->m_jointList;		HX_STACK_VAR(jn,"jn");
		HX_STACK_LINE(217)
		while((true)){
			HX_STACK_LINE(217)
			if ((!(((jn != null()))))){
				HX_STACK_LINE(217)
				break;
			}
			HX_STACK_LINE(219)
			::box2D::dynamics::joints::B2JointEdge jn0 = jn;		HX_STACK_VAR(jn0,"jn0");
			HX_STACK_LINE(220)
			jn = jn->next;
			HX_STACK_LINE(222)
			if (((this->m_destructionListener != null()))){
				HX_STACK_LINE(224)
				this->m_destructionListener->sayGoodbyeJoint(jn0->joint);
			}
			HX_STACK_LINE(227)
			this->destroyJoint(jn0->joint);
		}
		HX_STACK_LINE(231)
		::box2D::dynamics::controllers::B2ControllerEdge coe = b->m_controllerList;		HX_STACK_VAR(coe,"coe");
		HX_STACK_LINE(232)
		while((true)){
			HX_STACK_LINE(232)
			if ((!(((coe != null()))))){
				HX_STACK_LINE(232)
				break;
			}
			HX_STACK_LINE(234)
			::box2D::dynamics::controllers::B2ControllerEdge coe0 = coe;		HX_STACK_VAR(coe0,"coe0");
			HX_STACK_LINE(235)
			coe = coe->nextController;
			HX_STACK_LINE(236)
			coe0->controller->removeBody(b);
		}
		HX_STACK_LINE(240)
		::box2D::dynamics::contacts::B2ContactEdge ce = b->m_contactList;		HX_STACK_VAR(ce,"ce");
		HX_STACK_LINE(241)
		while((true)){
			HX_STACK_LINE(241)
			if ((!(((ce != null()))))){
				HX_STACK_LINE(241)
				break;
			}
			HX_STACK_LINE(243)
			::box2D::dynamics::contacts::B2ContactEdge ce0 = ce;		HX_STACK_VAR(ce0,"ce0");
			HX_STACK_LINE(244)
			ce = ce->next;
			HX_STACK_LINE(245)
			this->m_contactManager->destroy(ce0->contact);
		}
		HX_STACK_LINE(247)
		b->m_contactList = null();
		HX_STACK_LINE(251)
		::box2D::dynamics::B2Fixture f = b->m_fixtureList;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(252)
		while((true)){
			HX_STACK_LINE(252)
			if ((!(((f != null()))))){
				HX_STACK_LINE(252)
				break;
			}
			HX_STACK_LINE(254)
			::box2D::dynamics::B2Fixture f0 = f;		HX_STACK_VAR(f0,"f0");
			HX_STACK_LINE(255)
			f = f->m_next;
			HX_STACK_LINE(257)
			if (((this->m_destructionListener != null()))){
				HX_STACK_LINE(259)
				this->m_destructionListener->sayGoodbyeFixture(f0);
			}
			HX_STACK_LINE(262)
			f0->destroyProxy(this->m_contactManager->m_broadPhase);
			HX_STACK_LINE(263)
			f0->destroy();
		}
		HX_STACK_LINE(268)
		b->m_fixtureList = null();
		HX_STACK_LINE(269)
		b->m_fixtureCount = (int)0;
		HX_STACK_LINE(272)
		if (((b->m_prev != null()))){
			HX_STACK_LINE(274)
			b->m_prev->m_next = b->m_next;
		}
		HX_STACK_LINE(277)
		if (((b->m_next != null()))){
			HX_STACK_LINE(279)
			b->m_next->m_prev = b->m_prev;
		}
		HX_STACK_LINE(282)
		if (((b == this->m_bodyList))){
			HX_STACK_LINE(284)
			this->m_bodyList = b->m_next;
		}
		HX_STACK_LINE(287)
		--(this->m_bodyCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,destroyBody,(void))

::box2D::dynamics::joints::B2Joint B2World_obj::createJoint( ::box2D::dynamics::joints::B2JointDef def){
	HX_STACK_FRAME("box2D.dynamics.B2World","createJoint",0x8ffa71d9,"box2D.dynamics.B2World.createJoint","box2D/dynamics/B2World.hx",298,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_ARG(def,"def")
	HX_STACK_LINE(302)
	::box2D::dynamics::joints::B2Joint j = ::box2D::dynamics::joints::B2Joint_obj::create(def,null());		HX_STACK_VAR(j,"j");
	HX_STACK_LINE(305)
	j->m_prev = null();
	HX_STACK_LINE(306)
	j->m_next = this->m_jointList;
	HX_STACK_LINE(307)
	if (((this->m_jointList != null()))){
		HX_STACK_LINE(309)
		this->m_jointList->m_prev = j;
	}
	HX_STACK_LINE(311)
	this->m_jointList = j;
	HX_STACK_LINE(312)
	++(this->m_jointCount);
	HX_STACK_LINE(315)
	j->m_edgeA->joint = j;
	HX_STACK_LINE(316)
	j->m_edgeA->other = j->m_bodyB;
	HX_STACK_LINE(317)
	j->m_edgeA->prev = null();
	HX_STACK_LINE(318)
	j->m_edgeA->next = j->m_bodyA->m_jointList;
	HX_STACK_LINE(319)
	if (((j->m_bodyA->m_jointList != null()))){
		HX_STACK_LINE(319)
		j->m_bodyA->m_jointList->prev = j->m_edgeA;
	}
	HX_STACK_LINE(320)
	j->m_bodyA->m_jointList = j->m_edgeA;
	HX_STACK_LINE(322)
	j->m_edgeB->joint = j;
	HX_STACK_LINE(323)
	j->m_edgeB->other = j->m_bodyA;
	HX_STACK_LINE(324)
	j->m_edgeB->prev = null();
	HX_STACK_LINE(325)
	j->m_edgeB->next = j->m_bodyB->m_jointList;
	HX_STACK_LINE(326)
	if (((j->m_bodyB->m_jointList != null()))){
		HX_STACK_LINE(326)
		j->m_bodyB->m_jointList->prev = j->m_edgeB;
	}
	HX_STACK_LINE(327)
	j->m_bodyB->m_jointList = j->m_edgeB;
	HX_STACK_LINE(329)
	::box2D::dynamics::B2Body bodyA = def->bodyA;		HX_STACK_VAR(bodyA,"bodyA");
	HX_STACK_LINE(330)
	::box2D::dynamics::B2Body bodyB = def->bodyB;		HX_STACK_VAR(bodyB,"bodyB");
	HX_STACK_LINE(333)
	if (((def->collideConnected == false))){
		HX_STACK_LINE(335)
		::box2D::dynamics::contacts::B2ContactEdge edge = bodyB->getContactList();		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(336)
		while((true)){
			HX_STACK_LINE(336)
			if ((!(((edge != null()))))){
				HX_STACK_LINE(336)
				break;
			}
			HX_STACK_LINE(338)
			if (((edge->other == bodyA))){
				HX_STACK_LINE(342)
				edge->contact->flagForFiltering();
			}
			HX_STACK_LINE(345)
			edge = edge->next;
		}
	}
	HX_STACK_LINE(351)
	return j;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,createJoint,return )

Void B2World_obj::destroyJoint( ::box2D::dynamics::joints::B2Joint j){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","destroyJoint",0xfbf23665,"box2D.dynamics.B2World.destroyJoint","box2D/dynamics/B2World.hx",359,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(j,"j")
		HX_STACK_LINE(363)
		bool collideConnected = j->m_collideConnected;		HX_STACK_VAR(collideConnected,"collideConnected");
		HX_STACK_LINE(366)
		if (((j->m_prev != null()))){
			HX_STACK_LINE(368)
			j->m_prev->m_next = j->m_next;
		}
		HX_STACK_LINE(371)
		if (((j->m_next != null()))){
			HX_STACK_LINE(373)
			j->m_next->m_prev = j->m_prev;
		}
		HX_STACK_LINE(376)
		if (((j == this->m_jointList))){
			HX_STACK_LINE(378)
			this->m_jointList = j->m_next;
		}
		HX_STACK_LINE(382)
		::box2D::dynamics::B2Body bodyA = j->m_bodyA;		HX_STACK_VAR(bodyA,"bodyA");
		HX_STACK_LINE(383)
		::box2D::dynamics::B2Body bodyB = j->m_bodyB;		HX_STACK_VAR(bodyB,"bodyB");
		HX_STACK_LINE(386)
		bodyA->setAwake(true);
		HX_STACK_LINE(387)
		bodyB->setAwake(true);
		HX_STACK_LINE(390)
		if (((j->m_edgeA->prev != null()))){
			HX_STACK_LINE(392)
			j->m_edgeA->prev->next = j->m_edgeA->next;
		}
		HX_STACK_LINE(395)
		if (((j->m_edgeA->next != null()))){
			HX_STACK_LINE(397)
			j->m_edgeA->next->prev = j->m_edgeA->prev;
		}
		HX_STACK_LINE(400)
		if (((j->m_edgeA == bodyA->m_jointList))){
			HX_STACK_LINE(402)
			bodyA->m_jointList = j->m_edgeA->next;
		}
		HX_STACK_LINE(405)
		j->m_edgeA->prev = null();
		HX_STACK_LINE(406)
		j->m_edgeA->next = null();
		HX_STACK_LINE(409)
		if (((j->m_edgeB->prev != null()))){
			HX_STACK_LINE(411)
			j->m_edgeB->prev->next = j->m_edgeB->next;
		}
		HX_STACK_LINE(414)
		if (((j->m_edgeB->next != null()))){
			HX_STACK_LINE(416)
			j->m_edgeB->next->prev = j->m_edgeB->prev;
		}
		HX_STACK_LINE(419)
		if (((j->m_edgeB == bodyB->m_jointList))){
			HX_STACK_LINE(421)
			bodyB->m_jointList = j->m_edgeB->next;
		}
		HX_STACK_LINE(424)
		j->m_edgeB->prev = null();
		HX_STACK_LINE(425)
		j->m_edgeB->next = null();
		HX_STACK_LINE(427)
		::box2D::dynamics::joints::B2Joint_obj::destroy(j,null());
		HX_STACK_LINE(430)
		--(this->m_jointCount);
		HX_STACK_LINE(433)
		if (((collideConnected == false))){
			HX_STACK_LINE(435)
			::box2D::dynamics::contacts::B2ContactEdge edge = bodyB->getContactList();		HX_STACK_VAR(edge,"edge");
			HX_STACK_LINE(436)
			while((true)){
				HX_STACK_LINE(436)
				if ((!(((edge != null()))))){
					HX_STACK_LINE(436)
					break;
				}
				HX_STACK_LINE(438)
				if (((edge->other == bodyA))){
					HX_STACK_LINE(442)
					edge->contact->flagForFiltering();
				}
				HX_STACK_LINE(445)
				edge = edge->next;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,destroyJoint,(void))

::box2D::dynamics::controllers::B2Controller B2World_obj::addController( ::box2D::dynamics::controllers::B2Controller c){
	HX_STACK_FRAME("box2D.dynamics.B2World","addController",0x8801c408,"box2D.dynamics.B2World.addController","box2D/dynamics/B2World.hx",455,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(456)
	c->m_next = this->m_controllerList;
	HX_STACK_LINE(457)
	c->m_prev = null();
	HX_STACK_LINE(458)
	this->m_controllerList = c;
	HX_STACK_LINE(460)
	c->m_world = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(462)
	(this->m_controllerCount)++;
	HX_STACK_LINE(464)
	return c;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,addController,return )

Void B2World_obj::removeController( ::box2D::dynamics::controllers::B2Controller c){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","removeController",0x1b6598f5,"box2D.dynamics.B2World.removeController","box2D/dynamics/B2World.hx",468,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(470)
		if (((c->m_prev != null()))){
			HX_STACK_LINE(471)
			c->m_prev->m_next = c->m_next;
		}
		HX_STACK_LINE(472)
		if (((c->m_next != null()))){
			HX_STACK_LINE(473)
			c->m_next->m_prev = c->m_prev;
		}
		HX_STACK_LINE(474)
		if (((this->m_controllerList == c))){
			HX_STACK_LINE(475)
			this->m_controllerList = c->m_next;
		}
		HX_STACK_LINE(477)
		(this->m_controllerCount)--;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,removeController,(void))

::box2D::dynamics::controllers::B2Controller B2World_obj::createController( ::box2D::dynamics::controllers::B2Controller controller){
	HX_STACK_FRAME("box2D.dynamics.B2World","createController",0x96e9f9ad,"box2D.dynamics.B2World.createController","box2D/dynamics/B2World.hx",481,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_ARG(controller,"controller")
	HX_STACK_LINE(482)
	if (((controller->m_world != hx::ObjectPtr<OBJ_>(this)))){
		HX_STACK_LINE(483)
		HX_STACK_DO_THROW(HX_CSTRING("Controller can only be a member of one world"));
	}
	HX_STACK_LINE(486)
	controller->m_next = this->m_controllerList;
	HX_STACK_LINE(487)
	controller->m_prev = null();
	HX_STACK_LINE(488)
	if (((this->m_controllerList != null()))){
		HX_STACK_LINE(489)
		this->m_controllerList->m_prev = controller;
	}
	HX_STACK_LINE(490)
	this->m_controllerList = controller;
	HX_STACK_LINE(491)
	++(this->m_controllerCount);
	HX_STACK_LINE(493)
	controller->m_world = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(495)
	return controller;
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,createController,return )

Void B2World_obj::destroyController( ::box2D::dynamics::controllers::B2Controller controller){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","destroyController",0x584239a1,"box2D.dynamics.B2World.destroyController","box2D/dynamics/B2World.hx",499,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(controller,"controller")
		HX_STACK_LINE(501)
		controller->clear();
		HX_STACK_LINE(502)
		if (((controller->m_next != null()))){
			HX_STACK_LINE(503)
			controller->m_next->m_prev = controller->m_prev;
		}
		HX_STACK_LINE(504)
		if (((controller->m_prev != null()))){
			HX_STACK_LINE(505)
			controller->m_prev->m_next = controller->m_next;
		}
		HX_STACK_LINE(506)
		if (((controller == this->m_controllerList))){
			HX_STACK_LINE(507)
			this->m_controllerList = controller->m_next;
		}
		HX_STACK_LINE(508)
		--(this->m_controllerCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,destroyController,(void))

Void B2World_obj::setWarmStarting( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setWarmStarting",0xc5efb292,"box2D.dynamics.B2World.setWarmStarting","box2D/dynamics/B2World.hx",514,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(514)
		::box2D::dynamics::B2World_obj::m_warmStarting = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setWarmStarting,(void))

Void B2World_obj::setContinuousPhysics( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setContinuousPhysics",0xb88a9aeb,"box2D.dynamics.B2World.setContinuousPhysics","box2D/dynamics/B2World.hx",519,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(519)
		::box2D::dynamics::B2World_obj::m_continuousPhysics = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setContinuousPhysics,(void))

int B2World_obj::getBodyCount( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getBodyCount",0xd18c0fcc,"box2D.dynamics.B2World.getBodyCount","box2D/dynamics/B2World.hx",526,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(526)
	return this->m_bodyCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getBodyCount,return )

int B2World_obj::getJointCount( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getJointCount",0x1dcecd46,"box2D.dynamics.B2World.getJointCount","box2D/dynamics/B2World.hx",534,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(534)
	return this->m_jointCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getJointCount,return )

int B2World_obj::getContactCount( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getContactCount",0x5a4c7e70,"box2D.dynamics.B2World.getContactCount","box2D/dynamics/B2World.hx",542,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(542)
	return this->m_contactCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getContactCount,return )

Void B2World_obj::setGravity( ::box2D::common::math::B2Vec2 gravity){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","setGravity",0xe6832001,"box2D.dynamics.B2World.setGravity","box2D/dynamics/B2World.hx",550,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(gravity,"gravity")
		HX_STACK_LINE(550)
		this->m_gravity = gravity;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,setGravity,(void))

::box2D::common::math::B2Vec2 B2World_obj::getGravity( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getGravity",0xe305818d,"box2D.dynamics.B2World.getGravity","box2D/dynamics/B2World.hx",557,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(557)
	return this->m_gravity;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getGravity,return )

::box2D::dynamics::B2Body B2World_obj::getGroundBody( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getGroundBody",0x4c5a56ea,"box2D.dynamics.B2World.getGroundBody","box2D/dynamics/B2World.hx",565,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(565)
	return this->m_groundBody;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getGroundBody,return )

Void B2World_obj::step( Float dt,int velocityIterations,int positionIterations){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","step",0x7bf1eec1,"box2D.dynamics.B2World.step","box2D/dynamics/B2World.hx",576,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(dt,"dt")
		HX_STACK_ARG(velocityIterations,"velocityIterations")
		HX_STACK_ARG(positionIterations,"positionIterations")
		HX_STACK_LINE(577)
		if (((((int(this->m_flags) & int(::box2D::dynamics::B2World_obj::e_newFixture))) != (int)0))){
			HX_STACK_LINE(579)
			this->m_contactManager->findNewContacts();
			HX_STACK_LINE(580)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2World_obj::e_newFixture));
		}
		HX_STACK_LINE(583)
		hx::OrEq(this->m_flags,::box2D::dynamics::B2World_obj::e_locked);
		HX_STACK_LINE(585)
		::box2D::dynamics::B2TimeStep step = ::box2D::dynamics::B2World_obj::s_timestep2;		HX_STACK_VAR(step,"step");
		HX_STACK_LINE(586)
		step->dt = dt;
		HX_STACK_LINE(587)
		step->velocityIterations = velocityIterations;
		HX_STACK_LINE(588)
		step->positionIterations = positionIterations;
		HX_STACK_LINE(589)
		if (((dt > 0.0))){
			HX_STACK_LINE(591)
			step->inv_dt = (Float(1.0) / Float(dt));
		}
		else{
			HX_STACK_LINE(595)
			step->inv_dt = 0.0;
		}
		HX_STACK_LINE(598)
		step->dtRatio = (this->m_inv_dt0 * dt);
		HX_STACK_LINE(600)
		step->warmStarting = ::box2D::dynamics::B2World_obj::m_warmStarting;
		HX_STACK_LINE(603)
		this->m_contactManager->collide();
		HX_STACK_LINE(606)
		if (((step->dt > 0.0))){
			HX_STACK_LINE(608)
			this->solve(step);
		}
		HX_STACK_LINE(612)
		if (((bool(::box2D::dynamics::B2World_obj::m_continuousPhysics) && bool((step->dt > 0.0))))){
			HX_STACK_LINE(614)
			this->solveTOI(step);
		}
		HX_STACK_LINE(617)
		if (((step->dt > 0.0))){
			HX_STACK_LINE(619)
			this->m_inv_dt0 = step->inv_dt;
		}
		HX_STACK_LINE(621)
		hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::B2World_obj::e_locked));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,step,(void))

Void B2World_obj::clearForces( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","clearForces",0xa5cb0ac0,"box2D.dynamics.B2World.clearForces","box2D/dynamics/B2World.hx",629,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_LINE(630)
		::box2D::dynamics::B2Body body = this->m_bodyList;		HX_STACK_VAR(body,"body");
		HX_STACK_LINE(631)
		while((true)){
			HX_STACK_LINE(631)
			if ((!(((body != null()))))){
				HX_STACK_LINE(631)
				break;
			}
			HX_STACK_LINE(633)
			body->m_force->setZero();
			HX_STACK_LINE(634)
			body->m_torque = 0.0;
			HX_STACK_LINE(635)
			body = body->m_next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,clearForces,(void))

Void B2World_obj::drawDebugData( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","drawDebugData",0x9dcfef64,"box2D.dynamics.B2World.drawDebugData","box2D/dynamics/B2World.hx",643,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_LINE(645)
		if (((this->m_debugDraw == null()))){
			HX_STACK_LINE(647)
			return null();
		}
		HX_STACK_LINE(650)
		this->m_debugDraw->m_sprite->get_graphics()->clear();
		HX_STACK_LINE(652)
		int flags = this->m_debugDraw->getFlags();		HX_STACK_VAR(flags,"flags");
		HX_STACK_LINE(654)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(655)
		::box2D::dynamics::B2Body b;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(656)
		::box2D::dynamics::B2Fixture f;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(657)
		::box2D::collision::shapes::B2Shape s;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(658)
		::box2D::dynamics::joints::B2Joint j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(659)
		::box2D::collision::IBroadPhase bp;		HX_STACK_VAR(bp,"bp");
		HX_STACK_LINE(660)
		::box2D::common::math::B2Vec2 invQ = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(invQ,"invQ");
		HX_STACK_LINE(661)
		::box2D::common::math::B2Vec2 x1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(662)
		::box2D::common::math::B2Vec2 x2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(663)
		::box2D::common::math::B2Transform xf;		HX_STACK_VAR(xf,"xf");
		HX_STACK_LINE(664)
		::box2D::collision::B2AABB b1 = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(665)
		::box2D::collision::B2AABB b2 = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(666)
		::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(666)
		::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(666)
		::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(666)
		::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(666)
		Array< ::Dynamic > vs = Array_obj< ::Dynamic >::__new().Add(_g).Add(_g1).Add(_g2).Add(_g3);		HX_STACK_VAR(vs,"vs");
		HX_STACK_LINE(669)
		::box2D::common::B2Color color = ::box2D::common::B2Color_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(671)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_shapeBit))) != (int)0))){
			HX_STACK_LINE(673)
			b = this->m_bodyList;
			HX_STACK_LINE(674)
			while((true)){
				HX_STACK_LINE(674)
				if ((!(((b != null()))))){
					HX_STACK_LINE(674)
					break;
				}
				HX_STACK_LINE(676)
				xf = b->m_xf;
				HX_STACK_LINE(677)
				::box2D::dynamics::B2Fixture _g4 = b->getFixtureList();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(677)
				f = _g4;
				HX_STACK_LINE(678)
				while((true)){
					HX_STACK_LINE(678)
					if ((!(((f != null()))))){
						HX_STACK_LINE(678)
						break;
					}
					HX_STACK_LINE(680)
					::box2D::collision::shapes::B2Shape _g5 = f->getShape();		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(680)
					s = _g5;
					HX_STACK_LINE(681)
					bool _g6 = b->isActive();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(681)
					if (((_g6 == false))){
						HX_STACK_LINE(683)
						color->set(0.5,0.5,0.3);
						HX_STACK_LINE(684)
						this->drawShape(s,xf,color);
					}
					else{
						HX_STACK_LINE(686)
						int _g7 = b->getType();		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(686)
						if (((_g7 == (int)0))){
							HX_STACK_LINE(688)
							color->set(0.5,0.9,0.5);
							HX_STACK_LINE(689)
							this->drawShape(s,xf,color);
						}
						else{
							HX_STACK_LINE(691)
							int _g8 = b->getType();		HX_STACK_VAR(_g8,"_g8");
							HX_STACK_LINE(691)
							if (((_g8 == (int)1))){
								HX_STACK_LINE(693)
								color->set(0.5,0.5,0.9);
								HX_STACK_LINE(694)
								this->drawShape(s,xf,color);
							}
							else{
								HX_STACK_LINE(696)
								bool _g9 = b->isAwake();		HX_STACK_VAR(_g9,"_g9");
								HX_STACK_LINE(696)
								if (((_g9 == false))){
									HX_STACK_LINE(698)
									color->set(0.6,0.6,0.6);
									HX_STACK_LINE(699)
									this->drawShape(s,xf,color);
								}
								else{
									HX_STACK_LINE(703)
									color->set(0.9,0.7,0.7);
									HX_STACK_LINE(704)
									this->drawShape(s,xf,color);
								}
							}
						}
					}
					HX_STACK_LINE(706)
					f = f->m_next;
				}
				HX_STACK_LINE(708)
				b = b->m_next;
			}
		}
		HX_STACK_LINE(712)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_jointBit))) != (int)0))){
			HX_STACK_LINE(714)
			j = this->m_jointList;
			HX_STACK_LINE(715)
			while((true)){
				HX_STACK_LINE(715)
				if ((!(((j != null()))))){
					HX_STACK_LINE(715)
					break;
				}
				HX_STACK_LINE(717)
				this->drawJoint(j);
				HX_STACK_LINE(718)
				j = j->m_next;
			}
		}
		HX_STACK_LINE(722)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_controllerBit))) != (int)0))){
			HX_STACK_LINE(724)
			::box2D::dynamics::controllers::B2Controller c = this->m_controllerList;		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(725)
			while((true)){
				HX_STACK_LINE(725)
				if ((!(((c != null()))))){
					HX_STACK_LINE(725)
					break;
				}
				HX_STACK_LINE(727)
				c->draw(this->m_debugDraw);
				HX_STACK_LINE(728)
				c = c->m_next;
			}
		}
		HX_STACK_LINE(732)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_pairBit))) != (int)0))){
			HX_STACK_LINE(734)
			color->set(0.3,0.9,0.9);
			HX_STACK_LINE(735)
			::box2D::dynamics::contacts::B2Contact contact = this->m_contactManager->m_contactList;		HX_STACK_VAR(contact,"contact");
			HX_STACK_LINE(736)
			while((true)){
				HX_STACK_LINE(736)
				if ((!(((contact != null()))))){
					HX_STACK_LINE(736)
					break;
				}
				HX_STACK_LINE(738)
				::box2D::dynamics::B2Fixture fixtureA = contact->getFixtureA();		HX_STACK_VAR(fixtureA,"fixtureA");
				HX_STACK_LINE(739)
				::box2D::dynamics::B2Fixture fixtureB = contact->getFixtureB();		HX_STACK_VAR(fixtureB,"fixtureB");
				HX_STACK_LINE(741)
				::box2D::common::math::B2Vec2 cA = fixtureA->getAABB()->getCenter();		HX_STACK_VAR(cA,"cA");
				HX_STACK_LINE(742)
				::box2D::common::math::B2Vec2 cB = fixtureB->getAABB()->getCenter();		HX_STACK_VAR(cB,"cB");
				HX_STACK_LINE(744)
				this->m_debugDraw->drawSegment(cA,cB,color);
				HX_STACK_LINE(745)
				::box2D::dynamics::contacts::B2Contact _g10 = contact->getNext();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(745)
				contact = _g10;
			}
		}
		HX_STACK_LINE(749)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_aabbBit))) != (int)0))){
			HX_STACK_LINE(751)
			bp = this->m_contactManager->m_broadPhase;
			HX_STACK_LINE(753)
			::box2D::common::math::B2Vec2 _g11 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(753)
			::box2D::common::math::B2Vec2 _g12 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(753)
			::box2D::common::math::B2Vec2 _g13 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(753)
			::box2D::common::math::B2Vec2 _g14 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(753)
			Array< ::Dynamic > _g15 = Array_obj< ::Dynamic >::__new().Add(_g11).Add(_g12).Add(_g13).Add(_g14);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(753)
			vs = _g15;
			HX_STACK_LINE(755)
			b = this->m_bodyList;
			HX_STACK_LINE(756)
			while((true)){
				HX_STACK_LINE(756)
				if ((!(((b != null()))))){
					HX_STACK_LINE(756)
					break;
				}
				HX_STACK_LINE(758)
				bool _g16 = b->isActive();		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(758)
				if (((_g16 == false))){
					HX_STACK_LINE(760)
					::box2D::dynamics::B2Body _g17 = b->getNext();		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(760)
					b = _g17;
					HX_STACK_LINE(761)
					continue;
				}
				HX_STACK_LINE(763)
				::box2D::dynamics::B2Fixture _g18 = b->getFixtureList();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(763)
				f = _g18;
				HX_STACK_LINE(764)
				while((true)){
					HX_STACK_LINE(764)
					if ((!(((f != null()))))){
						HX_STACK_LINE(764)
						break;
					}
					HX_STACK_LINE(766)
					::box2D::collision::B2AABB aabb = bp->getFatAABB(f->m_proxy);		HX_STACK_VAR(aabb,"aabb");
					HX_STACK_LINE(767)
					vs->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->set(aabb->lowerBound->x,aabb->lowerBound->y);
					HX_STACK_LINE(768)
					vs->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->set(aabb->upperBound->x,aabb->lowerBound->y);
					HX_STACK_LINE(769)
					vs->__get((int)2).StaticCast< ::box2D::common::math::B2Vec2 >()->set(aabb->upperBound->x,aabb->upperBound->y);
					HX_STACK_LINE(770)
					vs->__get((int)3).StaticCast< ::box2D::common::math::B2Vec2 >()->set(aabb->lowerBound->x,aabb->upperBound->y);
					HX_STACK_LINE(772)
					this->m_debugDraw->drawPolygon(vs,(int)4,color);
					HX_STACK_LINE(773)
					::box2D::dynamics::B2Fixture _g19 = f->getNext();		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(773)
					f = _g19;
				}
				HX_STACK_LINE(775)
				::box2D::dynamics::B2Body _g20 = b->getNext();		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(775)
				b = _g20;
			}
		}
		HX_STACK_LINE(779)
		if (((((int(flags) & int(::box2D::dynamics::B2DebugDraw_obj::e_centerOfMassBit))) != (int)0))){
			HX_STACK_LINE(781)
			b = this->m_bodyList;
			HX_STACK_LINE(782)
			while((true)){
				HX_STACK_LINE(782)
				if ((!(((b != null()))))){
					HX_STACK_LINE(782)
					break;
				}
				HX_STACK_LINE(784)
				xf = ::box2D::dynamics::B2World_obj::s_xf;
				HX_STACK_LINE(785)
				xf->R = b->m_xf->R;
				HX_STACK_LINE(786)
				::box2D::common::math::B2Vec2 _g21 = b->getWorldCenter();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(786)
				xf->position = _g21;
				HX_STACK_LINE(787)
				this->m_debugDraw->drawTransform(xf);
				HX_STACK_LINE(788)
				b = b->m_next;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,drawDebugData,(void))

Void B2World_obj::queryAABB( Dynamic callbackMethod,::box2D::collision::B2AABB aabb){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","queryAABB",0xebdaea13,"box2D.dynamics.B2World.queryAABB","box2D/dynamics/B2World.hx",801,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(callbackMethod,"callbackMethod")
		HX_STACK_ARG(aabb,"aabb")
		HX_STACK_LINE(801)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));		HX_STACK_VAR(callbackMethod1,"callbackMethod1");
		HX_STACK_LINE(803)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);		HX_STACK_VAR(broadPhase,"broadPhase");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Dynamic,callbackMethod1,Array< ::box2D::collision::IBroadPhase >,broadPhase)
		bool run(Dynamic proxy){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","box2D/dynamics/B2World.hx",805,0xb09d3b25)
			HX_STACK_ARG(proxy,"proxy")
			{
				HX_STACK_LINE(806)
				Dynamic _g = broadPhase->__get((int)0)->getUserData(proxy);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(806)
				return callbackMethod1->__GetItem((int)0)(_g);
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(804)
		Dynamic worldQueryWrapper =  Dynamic(new _Function_1_1(callbackMethod1,broadPhase));		HX_STACK_VAR(worldQueryWrapper,"worldQueryWrapper");
		HX_STACK_LINE(808)
		broadPhase->__get((int)0)->query(worldQueryWrapper,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,queryAABB,(void))

Void B2World_obj::queryShape( Dynamic callbackMethod,::box2D::collision::shapes::B2Shape shape,::box2D::common::math::B2Transform transform){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","queryShape",0xeac7582e,"box2D.dynamics.B2World.queryShape","box2D/dynamics/B2World.hx",818,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(callbackMethod,"callbackMethod")
		HX_STACK_ARG(shape,"shape")
		HX_STACK_ARG(transform,"transform")
		HX_STACK_LINE(818)
		Array< ::Dynamic > transform1 = Array_obj< ::Dynamic >::__new().Add(transform);		HX_STACK_VAR(transform1,"transform1");
		HX_STACK_LINE(818)
		Array< ::Dynamic > shape1 = Array_obj< ::Dynamic >::__new().Add(shape);		HX_STACK_VAR(shape1,"shape1");
		HX_STACK_LINE(818)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));		HX_STACK_VAR(callbackMethod1,"callbackMethod1");
		HX_STACK_LINE(820)
		if (((transform1->__get((int)0).StaticCast< ::box2D::common::math::B2Transform >() == null()))){
			HX_STACK_LINE(822)
			::box2D::common::math::B2Transform _g = ::box2D::common::math::B2Transform_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(822)
			transform1[(int)0] = _g;
			HX_STACK_LINE(823)
			transform1->__get((int)0).StaticCast< ::box2D::common::math::B2Transform >()->setIdentity();
		}
		HX_STACK_LINE(825)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);		HX_STACK_VAR(broadPhase,"broadPhase");

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,shape1,Dynamic,callbackMethod1,Array< ::Dynamic >,transform1,Array< ::box2D::collision::IBroadPhase >,broadPhase)
		bool run(Dynamic proxy){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","box2D/dynamics/B2World.hx",827,0xb09d3b25)
			HX_STACK_ARG(proxy,"proxy")
			{
				HX_STACK_LINE(828)
				::box2D::dynamics::B2Fixture fixture;		HX_STACK_VAR(fixture,"fixture");
				HX_STACK_LINE(828)
				fixture = hx::TCast< box2D::dynamics::B2Fixture >::cast(broadPhase->__get((int)0)->getUserData(proxy));
				HX_STACK_LINE(829)
				::box2D::collision::shapes::B2Shape _g1 = fixture->getShape();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(829)
				::box2D::common::math::B2Transform _g2 = fixture->getBody()->getTransform();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(829)
				if ((::box2D::collision::shapes::B2Shape_obj::testOverlap(shape1->__get((int)0).StaticCast< ::box2D::collision::shapes::B2Shape >(),transform1->__get((int)0).StaticCast< ::box2D::common::math::B2Transform >(),_g1,_g2))){
					HX_STACK_LINE(830)
					return callbackMethod1->__GetItem((int)0)(fixture);
				}
				HX_STACK_LINE(831)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(826)
		Dynamic worldQueryWrapper =  Dynamic(new _Function_1_1(shape1,callbackMethod1,transform1,broadPhase));		HX_STACK_VAR(worldQueryWrapper,"worldQueryWrapper");
		HX_STACK_LINE(833)
		::box2D::collision::B2AABB aabb = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(aabb,"aabb");
		HX_STACK_LINE(834)
		shape1->__get((int)0).StaticCast< ::box2D::collision::shapes::B2Shape >()->computeAABB(aabb,transform1->__get((int)0).StaticCast< ::box2D::common::math::B2Transform >());
		HX_STACK_LINE(835)
		broadPhase->__get((int)0)->query(worldQueryWrapper,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,queryShape,(void))

Void B2World_obj::queryPoint( Dynamic callbackMethod,::box2D::common::math::B2Vec2 p){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","queryPoint",0x353a295d,"box2D.dynamics.B2World.queryPoint","box2D/dynamics/B2World.hx",845,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(callbackMethod,"callbackMethod")
		HX_STACK_ARG(p,"p")
		HX_STACK_LINE(845)
		Array< ::Dynamic > p1 = Array_obj< ::Dynamic >::__new().Add(p);		HX_STACK_VAR(p1,"p1");
		HX_STACK_LINE(845)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));		HX_STACK_VAR(callbackMethod1,"callbackMethod1");
		HX_STACK_LINE(847)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);		HX_STACK_VAR(broadPhase,"broadPhase");

		HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_1,Dynamic,callbackMethod1,Array< ::Dynamic >,p1,Array< ::box2D::collision::IBroadPhase >,broadPhase)
		bool run(Dynamic proxy){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","box2D/dynamics/B2World.hx",849,0xb09d3b25)
			HX_STACK_ARG(proxy,"proxy")
			{
				HX_STACK_LINE(850)
				::box2D::dynamics::B2Fixture fixture;		HX_STACK_VAR(fixture,"fixture");
				HX_STACK_LINE(850)
				fixture = hx::TCast< box2D::dynamics::B2Fixture >::cast(broadPhase->__get((int)0)->getUserData(proxy));
				HX_STACK_LINE(851)
				if ((fixture->testPoint(p1->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()))){
					HX_STACK_LINE(852)
					return callbackMethod1->__GetItem((int)0)(fixture);
				}
				HX_STACK_LINE(853)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(848)
		Dynamic worldQueryWrapper =  Dynamic(new _Function_1_1(callbackMethod1,p1,broadPhase));		HX_STACK_VAR(worldQueryWrapper,"worldQueryWrapper");
		HX_STACK_LINE(856)
		::box2D::collision::B2AABB aabb = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(aabb,"aabb");
		HX_STACK_LINE(857)
		aabb->lowerBound->set((p1->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x - ::box2D::common::B2Settings_obj::b2_linearSlop),(p1->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y - ::box2D::common::B2Settings_obj::b2_linearSlop));
		HX_STACK_LINE(858)
		aabb->upperBound->set((p1->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x + ::box2D::common::B2Settings_obj::b2_linearSlop),(p1->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y + ::box2D::common::B2Settings_obj::b2_linearSlop));
		HX_STACK_LINE(859)
		broadPhase->__get((int)0)->query(worldQueryWrapper,aabb);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,queryPoint,(void))

Void B2World_obj::rayCast( Dynamic callbackMethod,::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","rayCast",0x453aad74,"box2D.dynamics.B2World.rayCast","box2D/dynamics/B2World.hx",880,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(callbackMethod,"callbackMethod")
		HX_STACK_ARG(point1,"point1")
		HX_STACK_ARG(point2,"point2")
		HX_STACK_LINE(880)
		Array< ::Dynamic > point21 = Array_obj< ::Dynamic >::__new().Add(point2);		HX_STACK_VAR(point21,"point21");
		HX_STACK_LINE(880)
		Array< ::Dynamic > point11 = Array_obj< ::Dynamic >::__new().Add(point1);		HX_STACK_VAR(point11,"point11");
		HX_STACK_LINE(880)
		Dynamic callbackMethod1 = Dynamic( Array_obj<Dynamic>::__new().Add(callbackMethod));		HX_STACK_VAR(callbackMethod1,"callbackMethod1");
		HX_STACK_LINE(882)
		Array< ::box2D::collision::IBroadPhase > broadPhase = Array_obj< ::box2D::collision::IBroadPhase >::__new().Add(this->m_contactManager->m_broadPhase);		HX_STACK_VAR(broadPhase,"broadPhase");
		HX_STACK_LINE(883)
		Array< ::Dynamic > output = Array_obj< ::Dynamic >::__new().Add(::box2D::collision::B2RayCastOutput_obj::__new());		HX_STACK_VAR(output,"output");

		HX_BEGIN_LOCAL_FUNC_S5(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,point11,Dynamic,callbackMethod1,Array< ::Dynamic >,point21,Array< ::Dynamic >,output,Array< ::box2D::collision::IBroadPhase >,broadPhase)
		Float run(::box2D::collision::B2RayCastInput input,Dynamic proxy){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","box2D/dynamics/B2World.hx",885,0xb09d3b25)
			HX_STACK_ARG(input,"input")
			HX_STACK_ARG(proxy,"proxy")
			{
				HX_STACK_LINE(886)
				Dynamic userData = broadPhase->__get((int)0)->getUserData(proxy);		HX_STACK_VAR(userData,"userData");
				HX_STACK_LINE(887)
				::box2D::dynamics::B2Fixture fixture;		HX_STACK_VAR(fixture,"fixture");
				HX_STACK_LINE(887)
				fixture = hx::TCast< box2D::dynamics::B2Fixture >::cast(userData);
				HX_STACK_LINE(888)
				bool hit = fixture->rayCast(output->__get((int)0).StaticCast< ::box2D::collision::B2RayCastOutput >(),input);		HX_STACK_VAR(hit,"hit");
				HX_STACK_LINE(889)
				if ((hit)){
					HX_STACK_LINE(891)
					Float fraction = output->__get((int)0).StaticCast< ::box2D::collision::B2RayCastOutput >()->fraction;		HX_STACK_VAR(fraction,"fraction");
					HX_STACK_LINE(892)
					::box2D::common::math::B2Vec2 point = ::box2D::common::math::B2Vec2_obj::__new(((((1.0 - fraction)) * point11->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x) + (fraction * point21->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x)),((((1.0 - fraction)) * point11->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y) + (fraction * point21->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y)));		HX_STACK_VAR(point,"point");
					HX_STACK_LINE(895)
					return callbackMethod1->__GetItem((int)0)(fixture,point,output->__get((int)0).StaticCast< ::box2D::collision::B2RayCastOutput >()->normal,fraction);
				}
				HX_STACK_LINE(897)
				return input->maxFraction;
			}
			return null();
		}
		HX_END_LOCAL_FUNC2(return)

		HX_STACK_LINE(884)
		Dynamic rayCastWrapper =  Dynamic(new _Function_1_1(point11,callbackMethod1,point21,output,broadPhase));		HX_STACK_VAR(rayCastWrapper,"rayCastWrapper");
		HX_STACK_LINE(899)
		::box2D::collision::B2RayCastInput input = ::box2D::collision::B2RayCastInput_obj::__new(point11->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >(),point21->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >(),null());		HX_STACK_VAR(input,"input");
		HX_STACK_LINE(900)
		broadPhase->__get((int)0)->rayCast(rayCastWrapper,input);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,rayCast,(void))

::box2D::dynamics::B2Fixture B2World_obj::rayCastOne( ::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2){
	HX_STACK_FRAME("box2D.dynamics.B2World","rayCastOne",0xe1d88552,"box2D.dynamics.B2World.rayCastOne","box2D/dynamics/B2World.hx",904,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point1,"point1")
	HX_STACK_ARG(point2,"point2")
	HX_STACK_LINE(905)
	Array< ::Dynamic > result = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(result,"result");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,result)
	Float run(::box2D::dynamics::B2Fixture fixture,::box2D::common::math::B2Vec2 point,::box2D::common::math::B2Vec2 normal,Float fraction){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","box2D/dynamics/B2World.hx",907,0xb09d3b25)
		HX_STACK_ARG(fixture,"fixture")
		HX_STACK_ARG(point,"point")
		HX_STACK_ARG(normal,"normal")
		HX_STACK_ARG(fraction,"fraction")
		{
			HX_STACK_LINE(908)
			result[(int)0] = fixture;
			HX_STACK_LINE(909)
			return fraction;
		}
		return null();
	}
	HX_END_LOCAL_FUNC4(return)

	HX_STACK_LINE(906)
	Dynamic rayCastOneWrapper =  Dynamic(new _Function_1_1(result));		HX_STACK_VAR(rayCastOneWrapper,"rayCastOneWrapper");
	HX_STACK_LINE(911)
	this->rayCast(rayCastOneWrapper,point1,point2);
	HX_STACK_LINE(912)
	return result->__get((int)0).StaticCast< ::box2D::dynamics::B2Fixture >();
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,rayCastOne,return )

Array< ::Dynamic > B2World_obj::rayCastAll( ::box2D::common::math::B2Vec2 point1,::box2D::common::math::B2Vec2 point2){
	HX_STACK_FRAME("box2D.dynamics.B2World","rayCastAll",0xe1cde40d,"box2D.dynamics.B2World.rayCastAll","box2D/dynamics/B2World.hx",916,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_ARG(point1,"point1")
	HX_STACK_ARG(point2,"point2")
	HX_STACK_LINE(917)
	Array< ::Dynamic > result = Array_obj< ::Dynamic >::__new().Add(Array_obj< ::Dynamic >::__new());		HX_STACK_VAR(result,"result");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,result)
	Float run(::box2D::dynamics::B2Fixture fixture,::box2D::common::math::B2Vec2 point,::box2D::common::math::B2Vec2 normal,Float fraction){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","box2D/dynamics/B2World.hx",919,0xb09d3b25)
		HX_STACK_ARG(fixture,"fixture")
		HX_STACK_ARG(point,"point")
		HX_STACK_ARG(normal,"normal")
		HX_STACK_ARG(fraction,"fraction")
		{
			HX_STACK_LINE(920)
			result->__get((int)0).StaticCast< Array< ::Dynamic > >()[result->__get((int)0).StaticCast< Array< ::Dynamic > >()->length] = fixture;
			HX_STACK_LINE(921)
			return (int)1;
		}
		return null();
	}
	HX_END_LOCAL_FUNC4(return)

	HX_STACK_LINE(918)
	Dynamic rayCastAllWrapper =  Dynamic(new _Function_1_1(result));		HX_STACK_VAR(rayCastAllWrapper,"rayCastAllWrapper");
	HX_STACK_LINE(923)
	this->rayCast(rayCastAllWrapper,point1,point2);
	HX_STACK_LINE(924)
	return result->__get((int)0).StaticCast< Array< ::Dynamic > >();
}


HX_DEFINE_DYNAMIC_FUNC2(B2World_obj,rayCastAll,return )

::box2D::dynamics::B2Body B2World_obj::getBodyList( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getBodyList",0x01218001,"box2D.dynamics.B2World.getBodyList","box2D/dynamics/B2World.hx",933,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(933)
	return this->m_bodyList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getBodyList,return )

::box2D::dynamics::joints::B2Joint B2World_obj::getJointList( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getJointList",0xf28c8fc7,"box2D.dynamics.B2World.getJointList","box2D/dynamics/B2World.hx",942,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(942)
	return this->m_jointList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getJointList,return )

::box2D::dynamics::contacts::B2Contact B2World_obj::getContactList( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","getContactList",0x622cb1dd,"box2D.dynamics.B2World.getContactList","box2D/dynamics/B2World.hx",953,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(953)
	return this->m_contactList;
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,getContactList,return )

bool B2World_obj::isLocked( ){
	HX_STACK_FRAME("box2D.dynamics.B2World","isLocked",0x90b80689,"box2D.dynamics.B2World.isLocked","box2D/dynamics/B2World.hx",961,0xb09d3b25)
	HX_STACK_THIS(this)
	HX_STACK_LINE(961)
	return (((int(this->m_flags) & int(::box2D::dynamics::B2World_obj::e_locked))) > (int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(B2World_obj,isLocked,return )

Void B2World_obj::solve( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","solve",0xf4763e6a,"box2D.dynamics.B2World.solve","box2D/dynamics/B2World.hx",969,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(970)
		::box2D::dynamics::B2Body b;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(973)
		::box2D::dynamics::controllers::B2Controller controller = this->m_controllerList;		HX_STACK_VAR(controller,"controller");
		HX_STACK_LINE(974)
		while((true)){
			HX_STACK_LINE(974)
			if ((!(((controller != null()))))){
				HX_STACK_LINE(974)
				break;
			}
			HX_STACK_LINE(976)
			controller->step(step);
			HX_STACK_LINE(977)
			controller = controller->m_next;
		}
		HX_STACK_LINE(981)
		::box2D::dynamics::B2Island island = this->m_island;		HX_STACK_VAR(island,"island");
		HX_STACK_LINE(982)
		island->initialize(this->m_bodyCount,this->m_contactCount,this->m_jointCount,null(),this->m_contactManager->m_contactListener,this->m_contactSolver);
		HX_STACK_LINE(985)
		b = this->m_bodyList;
		HX_STACK_LINE(986)
		while((true)){
			HX_STACK_LINE(986)
			if ((!(((b != null()))))){
				HX_STACK_LINE(986)
				break;
			}
			HX_STACK_LINE(988)
			hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
			HX_STACK_LINE(989)
			b = b->m_next;
		}
		HX_STACK_LINE(991)
		::box2D::dynamics::contacts::B2Contact c = this->m_contactList;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(992)
		while((true)){
			HX_STACK_LINE(992)
			if ((!(((c != null()))))){
				HX_STACK_LINE(992)
				break;
			}
			HX_STACK_LINE(994)
			hx::AndEq(c->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag));
			HX_STACK_LINE(995)
			c = c->m_next;
		}
		HX_STACK_LINE(997)
		::box2D::dynamics::joints::B2Joint j = this->m_jointList;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(998)
		while((true)){
			HX_STACK_LINE(998)
			if ((!(((j != null()))))){
				HX_STACK_LINE(998)
				break;
			}
			HX_STACK_LINE(1000)
			j->m_islandFlag = false;
			HX_STACK_LINE(1001)
			j = j->m_next;
		}
		HX_STACK_LINE(1005)
		int stackSize = this->m_bodyCount;		HX_STACK_VAR(stackSize,"stackSize");
		HX_STACK_LINE(1007)
		Array< ::Dynamic > stack = this->s_stack;		HX_STACK_VAR(stack,"stack");
		HX_STACK_LINE(1008)
		::box2D::dynamics::B2Body seed = this->m_bodyList;		HX_STACK_VAR(seed,"seed");
		HX_STACK_LINE(1009)
		while((true)){
			HX_STACK_LINE(1009)
			if ((!(((seed != null()))))){
				HX_STACK_LINE(1009)
				break;
			}
			HX_STACK_LINE(1011)
			if (((((int(seed->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
				HX_STACK_LINE(1013)
				seed = seed->m_next;
				HX_STACK_LINE(1014)
				continue;
			}
			HX_STACK_LINE(1017)
			bool _g = seed->isAwake();		HX_STACK_VAR(_g,"_g");
			struct _Function_2_1{
				inline static bool Block( ::box2D::dynamics::B2Body &seed){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1017,0xb09d3b25)
					{
						HX_STACK_LINE(1017)
						bool _g1 = seed->isActive();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(1017)
						return (_g1 == false);
					}
					return null();
				}
			};
			HX_STACK_LINE(1017)
			if (((  ((!(((_g == false))))) ? bool(_Function_2_1::Block(seed)) : bool(true) ))){
				HX_STACK_LINE(1019)
				seed = seed->m_next;
				HX_STACK_LINE(1020)
				continue;
			}
			HX_STACK_LINE(1024)
			int _g2 = seed->getType();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1024)
			if (((_g2 == (int)0))){
				HX_STACK_LINE(1026)
				seed = seed->m_next;
				HX_STACK_LINE(1027)
				continue;
			}
			HX_STACK_LINE(1031)
			island->clear();
			HX_STACK_LINE(1032)
			int stackCount = (int)0;		HX_STACK_VAR(stackCount,"stackCount");
			HX_STACK_LINE(1033)
			int _g3 = (stackCount)++;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(1033)
			stack[_g3] = seed;
			HX_STACK_LINE(1034)
			hx::OrEq(seed->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
			HX_STACK_LINE(1037)
			while((true)){
				HX_STACK_LINE(1037)
				if ((!(((stackCount > (int)0))))){
					HX_STACK_LINE(1037)
					break;
				}
				HX_STACK_LINE(1040)
				int _g4 = --(stackCount);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(1040)
				::box2D::dynamics::B2Body _g5 = stack->__get(_g4).StaticCast< ::box2D::dynamics::B2Body >();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(1040)
				b = _g5;
				HX_STACK_LINE(1042)
				island->addBody(b);
				HX_STACK_LINE(1045)
				bool _g6 = b->isAwake();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(1045)
				if (((_g6 == false))){
					HX_STACK_LINE(1047)
					b->setAwake(true);
				}
				HX_STACK_LINE(1052)
				int _g7 = b->getType();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(1052)
				if (((_g7 == (int)0))){
					HX_STACK_LINE(1054)
					continue;
				}
				HX_STACK_LINE(1057)
				::box2D::dynamics::B2Body other;		HX_STACK_VAR(other,"other");
				HX_STACK_LINE(1059)
				::box2D::dynamics::contacts::B2ContactEdge ce = b->m_contactList;		HX_STACK_VAR(ce,"ce");
				HX_STACK_LINE(1060)
				while((true)){
					HX_STACK_LINE(1060)
					if ((!(((ce != null()))))){
						HX_STACK_LINE(1060)
						break;
					}
					HX_STACK_LINE(1063)
					if (((((int(ce->contact->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag))) != (int)0))){
						HX_STACK_LINE(1065)
						ce = ce->next;
						HX_STACK_LINE(1066)
						continue;
					}
					HX_STACK_LINE(1070)
					bool _g8 = ce->contact->isSensor();		HX_STACK_VAR(_g8,"_g8");
					struct _Function_4_1{
						inline static bool Block( ::box2D::dynamics::contacts::B2ContactEdge &ce){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1071,0xb09d3b25)
							{
								HX_STACK_LINE(1071)
								bool _g9 = ce->contact->isEnabled();		HX_STACK_VAR(_g9,"_g9");
								HX_STACK_LINE(1071)
								return (_g9 == false);
							}
							return null();
						}
					};
					struct _Function_4_2{
						inline static bool Block( ::box2D::dynamics::contacts::B2ContactEdge &ce){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1072,0xb09d3b25)
							{
								HX_STACK_LINE(1072)
								bool _g10 = ce->contact->isTouching();		HX_STACK_VAR(_g10,"_g10");
								HX_STACK_LINE(1072)
								return (_g10 == false);
							}
							return null();
						}
					};
					HX_STACK_LINE(1070)
					if (((  ((!(((  ((!(((_g8 == true))))) ? bool(_Function_4_1::Block(ce)) : bool(true) ))))) ? bool(_Function_4_2::Block(ce)) : bool(true) ))){
						HX_STACK_LINE(1074)
						ce = ce->next;
						HX_STACK_LINE(1075)
						continue;
					}
					HX_STACK_LINE(1078)
					island->addContact(ce->contact);
					HX_STACK_LINE(1079)
					hx::OrEq(ce->contact->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag);
					HX_STACK_LINE(1082)
					other = ce->other;
					HX_STACK_LINE(1085)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_STACK_LINE(1087)
						ce = ce->next;
						HX_STACK_LINE(1088)
						continue;
					}
					HX_STACK_LINE(1092)
					int _g11 = (stackCount)++;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(1092)
					stack[_g11] = other;
					HX_STACK_LINE(1093)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_STACK_LINE(1094)
					ce = ce->next;
				}
				HX_STACK_LINE(1098)
				::box2D::dynamics::joints::B2JointEdge jn = b->m_jointList;		HX_STACK_VAR(jn,"jn");
				HX_STACK_LINE(1099)
				while((true)){
					HX_STACK_LINE(1099)
					if ((!(((jn != null()))))){
						HX_STACK_LINE(1099)
						break;
					}
					HX_STACK_LINE(1101)
					if (((jn->joint->m_islandFlag == true))){
						HX_STACK_LINE(1103)
						jn = jn->next;
						HX_STACK_LINE(1104)
						continue;
					}
					HX_STACK_LINE(1107)
					other = jn->other;
					HX_STACK_LINE(1110)
					bool _g12 = other->isActive();		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(1110)
					if (((_g12 == false))){
						HX_STACK_LINE(1112)
						jn = jn->next;
						HX_STACK_LINE(1113)
						continue;
					}
					HX_STACK_LINE(1116)
					island->addJoint(jn->joint);
					HX_STACK_LINE(1117)
					jn->joint->m_islandFlag = true;
					HX_STACK_LINE(1119)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_STACK_LINE(1121)
						jn = jn->next;
						HX_STACK_LINE(1122)
						continue;
					}
					HX_STACK_LINE(1126)
					int _g13 = (stackCount)++;		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(1126)
					stack[_g13] = other;
					HX_STACK_LINE(1127)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_STACK_LINE(1128)
					jn = jn->next;
				}
			}
			HX_STACK_LINE(1131)
			island->solve(step,this->m_gravity,this->m_allowSleep);
			HX_STACK_LINE(1134)
			{
				HX_STACK_LINE(1134)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1134)
				int _g4 = island->m_bodyCount;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(1134)
				while((true)){
					HX_STACK_LINE(1134)
					if ((!(((_g1 < _g4))))){
						HX_STACK_LINE(1134)
						break;
					}
					HX_STACK_LINE(1134)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(1137)
					b = island->m_bodies->__get(i).StaticCast< ::box2D::dynamics::B2Body >();
					HX_STACK_LINE(1138)
					int _g14 = b->getType();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(1138)
					if (((_g14 == (int)0))){
						HX_STACK_LINE(1140)
						hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
					}
				}
			}
			HX_STACK_LINE(1143)
			seed = seed->m_next;
		}
		HX_STACK_LINE(1147)
		{
			HX_STACK_LINE(1147)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1147)
			int _g = stack->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1147)
			while((true)){
				HX_STACK_LINE(1147)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(1147)
					break;
				}
				HX_STACK_LINE(1147)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1149)
				if (((stack->__get(i).StaticCast< ::box2D::dynamics::B2Body >() == null()))){
					HX_STACK_LINE(1149)
					break;
				}
				HX_STACK_LINE(1150)
				stack[i] = null();
			}
		}
		HX_STACK_LINE(1154)
		b = this->m_bodyList;
		HX_STACK_LINE(1155)
		while((true)){
			HX_STACK_LINE(1155)
			if ((!(((b != null()))))){
				HX_STACK_LINE(1155)
				break;
			}
			HX_STACK_LINE(1157)
			bool _g15 = b->isAwake();		HX_STACK_VAR(_g15,"_g15");
			struct _Function_2_1{
				inline static bool Block( ::box2D::dynamics::B2Body &b){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1157,0xb09d3b25)
					{
						HX_STACK_LINE(1157)
						bool _g16 = b->isActive();		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(1157)
						return (_g16 == false);
					}
					return null();
				}
			};
			HX_STACK_LINE(1157)
			if (((  ((!(((_g15 == false))))) ? bool(_Function_2_1::Block(b)) : bool(true) ))){
				HX_STACK_LINE(1159)
				b = b->m_next;
				HX_STACK_LINE(1160)
				continue;
			}
			HX_STACK_LINE(1163)
			int _g17 = b->getType();		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(1163)
			if (((_g17 == (int)0))){
				HX_STACK_LINE(1165)
				b = b->m_next;
				HX_STACK_LINE(1166)
				continue;
			}
			HX_STACK_LINE(1170)
			b->synchronizeFixtures();
			HX_STACK_LINE(1171)
			b = b->m_next;
		}
		HX_STACK_LINE(1175)
		this->m_contactManager->findNewContacts();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,solve,(void))

Void B2World_obj::solveTOI( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","solveTOI",0xfad52244,"box2D.dynamics.B2World.solveTOI","box2D/dynamics/B2World.hx",1184,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(1186)
		::box2D::dynamics::B2Body b;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(1187)
		::box2D::dynamics::B2Fixture fA;		HX_STACK_VAR(fA,"fA");
		HX_STACK_LINE(1188)
		::box2D::dynamics::B2Fixture fB;		HX_STACK_VAR(fB,"fB");
		HX_STACK_LINE(1189)
		::box2D::dynamics::B2Body bA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(1190)
		::box2D::dynamics::B2Body bB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(1191)
		::box2D::dynamics::contacts::B2ContactEdge cEdge;		HX_STACK_VAR(cEdge,"cEdge");
		HX_STACK_LINE(1192)
		::box2D::dynamics::joints::B2Joint j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(1195)
		::box2D::dynamics::B2Island island = this->m_island;		HX_STACK_VAR(island,"island");
		HX_STACK_LINE(1196)
		island->initialize(this->m_bodyCount,::box2D::common::B2Settings_obj::b2_maxTOIContactsPerIsland,::box2D::common::B2Settings_obj::b2_maxTOIJointsPerIsland,null(),this->m_contactManager->m_contactListener,this->m_contactSolver);
		HX_STACK_LINE(1207)
		Array< ::Dynamic > queue = ::box2D::dynamics::B2World_obj::s_queue;		HX_STACK_VAR(queue,"queue");
		HX_STACK_LINE(1209)
		b = this->m_bodyList;
		HX_STACK_LINE(1210)
		while((true)){
			HX_STACK_LINE(1210)
			if ((!(((b != null()))))){
				HX_STACK_LINE(1210)
				break;
			}
			HX_STACK_LINE(1212)
			hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
			HX_STACK_LINE(1213)
			b->m_sweep->t0 = 0.0;
			HX_STACK_LINE(1214)
			b = b->m_next;
		}
		HX_STACK_LINE(1217)
		::box2D::dynamics::contacts::B2Contact c = this->m_contactList;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(1218)
		while((true)){
			HX_STACK_LINE(1218)
			if ((!(((c != null()))))){
				HX_STACK_LINE(1218)
				break;
			}
			HX_STACK_LINE(1221)
			hx::AndEq(c->m_flags,~(int)(((int(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag) | int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag)))));
			HX_STACK_LINE(1222)
			c = c->m_next;
		}
		HX_STACK_LINE(1225)
		j = this->m_jointList;
		HX_STACK_LINE(1226)
		while((true)){
			HX_STACK_LINE(1226)
			if ((!(((j != null()))))){
				HX_STACK_LINE(1226)
				break;
			}
			HX_STACK_LINE(1228)
			j->m_islandFlag = false;
			HX_STACK_LINE(1229)
			j = j->m_next;
		}
		HX_STACK_LINE(1235)
		while((true)){
			HX_STACK_LINE(1238)
			::box2D::dynamics::contacts::B2Contact minContact = null();		HX_STACK_VAR(minContact,"minContact");
			HX_STACK_LINE(1239)
			Float minTOI = 1.0;		HX_STACK_VAR(minTOI,"minTOI");
			HX_STACK_LINE(1241)
			c = this->m_contactList;
			HX_STACK_LINE(1242)
			while((true)){
				HX_STACK_LINE(1242)
				if ((!(((c != null()))))){
					HX_STACK_LINE(1242)
					break;
				}
				HX_STACK_LINE(1245)
				bool _g = c->isSensor();		HX_STACK_VAR(_g,"_g");
				struct _Function_3_1{
					inline static bool Block( ::box2D::dynamics::contacts::B2Contact &c){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1246,0xb09d3b25)
						{
							HX_STACK_LINE(1246)
							bool _g1 = c->isEnabled();		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(1246)
							return (_g1 == false);
						}
						return null();
					}
				};
				struct _Function_3_2{
					inline static bool Block( ::box2D::dynamics::contacts::B2Contact &c){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1247,0xb09d3b25)
						{
							HX_STACK_LINE(1247)
							bool _g2 = c->isContinuous();		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(1247)
							return (_g2 == false);
						}
						return null();
					}
				};
				HX_STACK_LINE(1245)
				if (((  ((!(((  ((!(((_g == true))))) ? bool(_Function_3_1::Block(c)) : bool(true) ))))) ? bool(_Function_3_2::Block(c)) : bool(true) ))){
					HX_STACK_LINE(1249)
					c = c->m_next;
					HX_STACK_LINE(1250)
					continue;
				}
				HX_STACK_LINE(1255)
				Float toi = 1.0;		HX_STACK_VAR(toi,"toi");
				HX_STACK_LINE(1256)
				if (((((int(c->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag))) != (int)0))){
					HX_STACK_LINE(1259)
					toi = c->m_toi;
				}
				else{
					HX_STACK_LINE(1264)
					fA = c->m_fixtureA;
					HX_STACK_LINE(1265)
					fB = c->m_fixtureB;
					HX_STACK_LINE(1266)
					bA = fA->m_body;
					HX_STACK_LINE(1267)
					bB = fB->m_body;
					HX_STACK_LINE(1269)
					int _g3 = bA->getType();		HX_STACK_VAR(_g3,"_g3");
					struct _Function_4_1{
						inline static bool Block( ::box2D::dynamics::B2Body &bA){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1269,0xb09d3b25)
							{
								HX_STACK_LINE(1269)
								bool _g4 = bA->isAwake();		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(1269)
								return (_g4 == false);
							}
							return null();
						}
					};
					struct _Function_4_2{
						inline static bool Block( ::box2D::dynamics::B2Body &bB){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1270,0xb09d3b25)
							{
								HX_STACK_LINE(1270)
								int _g5 = bB->getType();		HX_STACK_VAR(_g5,"_g5");
								struct _Function_5_1{
									inline static bool Block( ::box2D::dynamics::B2Body &bB){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1270,0xb09d3b25)
										{
											HX_STACK_LINE(1270)
											bool _g6 = bB->isAwake();		HX_STACK_VAR(_g6,"_g6");
											HX_STACK_LINE(1270)
											return (_g6 == false);
										}
										return null();
									}
								};
								HX_STACK_LINE(1270)
								return (  ((!(((_g5 != (int)2))))) ? bool(_Function_5_1::Block(bB)) : bool(true) );
							}
							return null();
						}
					};
					HX_STACK_LINE(1269)
					if (((  (((  ((!(((_g3 != (int)2))))) ? bool(_Function_4_1::Block(bA)) : bool(true) ))) ? bool(_Function_4_2::Block(bB)) : bool(false) ))){
						HX_STACK_LINE(1272)
						c = c->m_next;
						HX_STACK_LINE(1273)
						continue;
					}
					HX_STACK_LINE(1277)
					Float t0 = bA->m_sweep->t0;		HX_STACK_VAR(t0,"t0");
					HX_STACK_LINE(1279)
					if (((bA->m_sweep->t0 < bB->m_sweep->t0))){
						HX_STACK_LINE(1281)
						t0 = bB->m_sweep->t0;
						HX_STACK_LINE(1282)
						bA->m_sweep->advance(t0);
					}
					else{
						HX_STACK_LINE(1284)
						if (((bB->m_sweep->t0 < bA->m_sweep->t0))){
							HX_STACK_LINE(1286)
							t0 = bA->m_sweep->t0;
							HX_STACK_LINE(1287)
							bB->m_sweep->advance(t0);
						}
					}
					HX_STACK_LINE(1293)
					Float _g7 = c->computeTOI(bA->m_sweep,bB->m_sweep);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(1293)
					toi = _g7;
					HX_STACK_LINE(1294)
					::box2D::common::B2Settings_obj::b2Assert((bool((0.0 <= toi)) && bool((toi <= 1.0))));
					HX_STACK_LINE(1297)
					if (((bool((toi > 0.0)) && bool((toi < 1.0))))){
						HX_STACK_LINE(1301)
						toi = ((((1.0 - toi)) * t0) + toi);
						HX_STACK_LINE(1302)
						if (((toi > (int)1))){
							HX_STACK_LINE(1302)
							toi = (int)1;
						}
					}
					HX_STACK_LINE(1306)
					c->m_toi = toi;
					HX_STACK_LINE(1307)
					hx::OrEq(c->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag);
				}
				HX_STACK_LINE(1310)
				if (((bool((2.2250738585072014e-308 < toi)) && bool((toi < minTOI))))){
					HX_STACK_LINE(1313)
					minContact = c;
					HX_STACK_LINE(1314)
					minTOI = toi;
				}
				HX_STACK_LINE(1317)
				c = c->m_next;
			}
			HX_STACK_LINE(1320)
			if (((bool((minContact == null())) || bool((1. < minTOI))))){
				HX_STACK_LINE(1323)
				break;
			}
			HX_STACK_LINE(1327)
			fA = minContact->m_fixtureA;
			HX_STACK_LINE(1328)
			fB = minContact->m_fixtureB;
			HX_STACK_LINE(1329)
			bA = fA->m_body;
			HX_STACK_LINE(1330)
			bB = fB->m_body;
			HX_STACK_LINE(1331)
			::box2D::dynamics::B2World_obj::s_backupA->set(bA->m_sweep);
			HX_STACK_LINE(1332)
			::box2D::dynamics::B2World_obj::s_backupB->set(bB->m_sweep);
			HX_STACK_LINE(1333)
			bA->advance(minTOI);
			HX_STACK_LINE(1334)
			bB->advance(minTOI);
			HX_STACK_LINE(1337)
			minContact->update(this->m_contactManager->m_contactListener);
			HX_STACK_LINE(1338)
			hx::AndEq(minContact->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag));
			HX_STACK_LINE(1341)
			bool _g8 = minContact->isSensor();		HX_STACK_VAR(_g8,"_g8");
			struct _Function_2_1{
				inline static bool Block( ::box2D::dynamics::contacts::B2Contact &minContact){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1342,0xb09d3b25)
					{
						HX_STACK_LINE(1342)
						bool _g9 = minContact->isEnabled();		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(1342)
						return (_g9 == false);
					}
					return null();
				}
			};
			HX_STACK_LINE(1341)
			if (((  ((!(((_g8 == true))))) ? bool(_Function_2_1::Block(minContact)) : bool(true) ))){
				HX_STACK_LINE(1345)
				bA->m_sweep->set(::box2D::dynamics::B2World_obj::s_backupA);
				HX_STACK_LINE(1346)
				bB->m_sweep->set(::box2D::dynamics::B2World_obj::s_backupB);
				HX_STACK_LINE(1347)
				bA->synchronizeTransform();
				HX_STACK_LINE(1348)
				bB->synchronizeTransform();
				HX_STACK_LINE(1349)
				continue;
			}
			HX_STACK_LINE(1353)
			bool _g10 = minContact->isTouching();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(1353)
			if (((_g10 == false))){
				HX_STACK_LINE(1356)
				continue;
			}
			HX_STACK_LINE(1360)
			::box2D::dynamics::B2Body seed = bA;		HX_STACK_VAR(seed,"seed");
			HX_STACK_LINE(1361)
			int _g11 = seed->getType();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1361)
			if (((_g11 != (int)2))){
				HX_STACK_LINE(1363)
				seed = bB;
			}
			HX_STACK_LINE(1367)
			island->clear();
			HX_STACK_LINE(1368)
			int queueStart = (int)0;		HX_STACK_VAR(queueStart,"queueStart");
			HX_STACK_LINE(1369)
			int queueSize = (int)0;		HX_STACK_VAR(queueSize,"queueSize");
			HX_STACK_LINE(1370)
			int _g12 = (queueSize)++;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(1370)
			int _g13 = (queueStart + _g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(1370)
			queue[_g13] = seed;
			HX_STACK_LINE(1371)
			hx::OrEq(seed->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
			HX_STACK_LINE(1374)
			while((true)){
				HX_STACK_LINE(1374)
				if ((!(((queueSize > (int)0))))){
					HX_STACK_LINE(1374)
					break;
				}
				HX_STACK_LINE(1377)
				int _g14 = (queueStart)++;		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(1377)
				::box2D::dynamics::B2Body _g15 = queue->__get(_g14).StaticCast< ::box2D::dynamics::B2Body >();		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(1377)
				b = _g15;
				HX_STACK_LINE(1378)
				--(queueSize);
				HX_STACK_LINE(1380)
				island->addBody(b);
				HX_STACK_LINE(1383)
				bool _g16 = b->isAwake();		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(1383)
				if (((_g16 == false))){
					HX_STACK_LINE(1385)
					b->setAwake(true);
				}
				HX_STACK_LINE(1390)
				int _g17 = b->getType();		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(1390)
				if (((_g17 != (int)2))){
					HX_STACK_LINE(1392)
					continue;
				}
				HX_STACK_LINE(1396)
				cEdge = b->m_contactList;
				HX_STACK_LINE(1397)
				::box2D::dynamics::B2Body other;		HX_STACK_VAR(other,"other");
				HX_STACK_LINE(1398)
				while((true)){
					HX_STACK_LINE(1398)
					if ((!(((cEdge != null()))))){
						HX_STACK_LINE(1398)
						break;
					}
					HX_STACK_LINE(1401)
					if (((island->m_contactCount == island->m_contactCapacity))){
						HX_STACK_LINE(1403)
						cEdge = cEdge->next;
						HX_STACK_LINE(1404)
						break;
					}
					HX_STACK_LINE(1408)
					if (((((int(cEdge->contact->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag))) != (int)0))){
						HX_STACK_LINE(1410)
						cEdge = cEdge->next;
						HX_STACK_LINE(1411)
						continue;
					}
					HX_STACK_LINE(1415)
					bool _g18 = cEdge->contact->isSensor();		HX_STACK_VAR(_g18,"_g18");
					struct _Function_4_1{
						inline static bool Block( ::box2D::dynamics::contacts::B2ContactEdge &cEdge){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1416,0xb09d3b25)
							{
								HX_STACK_LINE(1416)
								bool _g19 = cEdge->contact->isEnabled();		HX_STACK_VAR(_g19,"_g19");
								HX_STACK_LINE(1416)
								return (_g19 == false);
							}
							return null();
						}
					};
					struct _Function_4_2{
						inline static bool Block( ::box2D::dynamics::contacts::B2ContactEdge &cEdge){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2World.hx",1417,0xb09d3b25)
							{
								HX_STACK_LINE(1417)
								bool _g20 = cEdge->contact->isTouching();		HX_STACK_VAR(_g20,"_g20");
								HX_STACK_LINE(1417)
								return (_g20 == false);
							}
							return null();
						}
					};
					HX_STACK_LINE(1415)
					if (((  ((!(((  ((!(((_g18 == true))))) ? bool(_Function_4_1::Block(cEdge)) : bool(true) ))))) ? bool(_Function_4_2::Block(cEdge)) : bool(true) ))){
						HX_STACK_LINE(1419)
						cEdge = cEdge->next;
						HX_STACK_LINE(1420)
						continue;
					}
					HX_STACK_LINE(1423)
					island->addContact(cEdge->contact);
					HX_STACK_LINE(1424)
					hx::OrEq(cEdge->contact->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag);
					HX_STACK_LINE(1427)
					other = cEdge->other;
					HX_STACK_LINE(1430)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_STACK_LINE(1432)
						cEdge = cEdge->next;
						HX_STACK_LINE(1433)
						continue;
					}
					HX_STACK_LINE(1437)
					int _g21 = other->getType();		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(1437)
					if (((_g21 != (int)0))){
						HX_STACK_LINE(1439)
						other->advance(minTOI);
						HX_STACK_LINE(1440)
						other->setAwake(true);
					}
					HX_STACK_LINE(1444)
					queue[(queueStart + queueSize)] = other;
					HX_STACK_LINE(1445)
					++(queueSize);
					HX_STACK_LINE(1446)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_STACK_LINE(1447)
					cEdge = cEdge->next;
				}
				HX_STACK_LINE(1450)
				::box2D::dynamics::joints::B2JointEdge jEdge = b->m_jointList;		HX_STACK_VAR(jEdge,"jEdge");
				HX_STACK_LINE(1451)
				while((true)){
					HX_STACK_LINE(1451)
					if ((!(((jEdge != null()))))){
						HX_STACK_LINE(1451)
						break;
					}
					HX_STACK_LINE(1453)
					if (((island->m_jointCount == island->m_jointCapacity))){
						HX_STACK_LINE(1454)
						jEdge = jEdge->next;
						HX_STACK_LINE(1455)
						continue;
					}
					HX_STACK_LINE(1458)
					if (((jEdge->joint->m_islandFlag == true))){
						HX_STACK_LINE(1459)
						jEdge = jEdge->next;
						HX_STACK_LINE(1460)
						continue;
					}
					HX_STACK_LINE(1463)
					other = jEdge->other;
					HX_STACK_LINE(1464)
					bool _g22 = other->isActive();		HX_STACK_VAR(_g22,"_g22");
					HX_STACK_LINE(1464)
					if (((_g22 == false))){
						HX_STACK_LINE(1466)
						jEdge = jEdge->next;
						HX_STACK_LINE(1467)
						continue;
					}
					HX_STACK_LINE(1470)
					island->addJoint(jEdge->joint);
					HX_STACK_LINE(1471)
					jEdge->joint->m_islandFlag = true;
					HX_STACK_LINE(1473)
					if (((((int(other->m_flags) & int(::box2D::dynamics::B2Body_obj::e_islandFlag))) != (int)0))){
						HX_STACK_LINE(1474)
						jEdge = jEdge->next;
						HX_STACK_LINE(1475)
						continue;
					}
					HX_STACK_LINE(1479)
					int _g23 = other->getType();		HX_STACK_VAR(_g23,"_g23");
					HX_STACK_LINE(1479)
					if (((_g23 != (int)0))){
						HX_STACK_LINE(1481)
						other->advance(minTOI);
						HX_STACK_LINE(1482)
						other->setAwake(true);
					}
					HX_STACK_LINE(1486)
					queue[(queueStart + queueSize)] = other;
					HX_STACK_LINE(1487)
					++(queueSize);
					HX_STACK_LINE(1488)
					hx::OrEq(other->m_flags,::box2D::dynamics::B2Body_obj::e_islandFlag);
					HX_STACK_LINE(1489)
					jEdge = jEdge->next;
				}
			}
			HX_STACK_LINE(1493)
			::box2D::dynamics::B2TimeStep subStep = ::box2D::dynamics::B2World_obj::s_timestep;		HX_STACK_VAR(subStep,"subStep");
			HX_STACK_LINE(1494)
			subStep->warmStarting = false;
			HX_STACK_LINE(1495)
			subStep->dt = (((1.0 - minTOI)) * step->dt);
			HX_STACK_LINE(1496)
			subStep->inv_dt = (Float(1.0) / Float(subStep->dt));
			HX_STACK_LINE(1497)
			subStep->dtRatio = 0.0;
			HX_STACK_LINE(1498)
			subStep->velocityIterations = step->velocityIterations;
			HX_STACK_LINE(1499)
			subStep->positionIterations = step->positionIterations;
			HX_STACK_LINE(1501)
			island->solveTOI(subStep);
			HX_STACK_LINE(1503)
			int i;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1505)
			{
				HX_STACK_LINE(1505)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1505)
				int _g = island->m_bodyCount;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1505)
				while((true)){
					HX_STACK_LINE(1505)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(1505)
						break;
					}
					HX_STACK_LINE(1505)
					int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(1508)
					b = island->m_bodies->__get(i1).StaticCast< ::box2D::dynamics::B2Body >();
					HX_STACK_LINE(1509)
					hx::AndEq(b->m_flags,~(int)(::box2D::dynamics::B2Body_obj::e_islandFlag));
					HX_STACK_LINE(1511)
					bool _g24 = b->isAwake();		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(1511)
					if (((_g24 == false))){
						HX_STACK_LINE(1513)
						continue;
					}
					HX_STACK_LINE(1516)
					int _g25 = b->getType();		HX_STACK_VAR(_g25,"_g25");
					HX_STACK_LINE(1516)
					if (((_g25 != (int)2))){
						HX_STACK_LINE(1518)
						continue;
					}
					HX_STACK_LINE(1522)
					b->synchronizeFixtures();
					HX_STACK_LINE(1526)
					cEdge = b->m_contactList;
					HX_STACK_LINE(1527)
					while((true)){
						HX_STACK_LINE(1527)
						if ((!(((cEdge != null()))))){
							HX_STACK_LINE(1527)
							break;
						}
						HX_STACK_LINE(1529)
						hx::AndEq(cEdge->contact->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag));
						HX_STACK_LINE(1530)
						cEdge = cEdge->next;
					}
				}
			}
			HX_STACK_LINE(1534)
			{
				HX_STACK_LINE(1534)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1534)
				int _g = island->m_contactCount;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1534)
				while((true)){
					HX_STACK_LINE(1534)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(1534)
						break;
					}
					HX_STACK_LINE(1534)
					int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(1537)
					c = island->m_contacts->__get(i1).StaticCast< ::box2D::dynamics::contacts::B2Contact >();
					HX_STACK_LINE(1538)
					hx::AndEq(c->m_flags,~(int)(((int(::box2D::dynamics::contacts::B2Contact_obj::e_toiFlag) | int(::box2D::dynamics::contacts::B2Contact_obj::e_islandFlag)))));
				}
			}
			HX_STACK_LINE(1541)
			{
				HX_STACK_LINE(1541)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1541)
				int _g = island->m_jointCount;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(1541)
				while((true)){
					HX_STACK_LINE(1541)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(1541)
						break;
					}
					HX_STACK_LINE(1541)
					int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(1544)
					j = island->m_joints->__get(i1).StaticCast< ::box2D::dynamics::joints::B2Joint >();
					HX_STACK_LINE(1545)
					j->m_islandFlag = false;
				}
			}
			HX_STACK_LINE(1550)
			this->m_contactManager->findNewContacts();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,solveTOI,(void))

Void B2World_obj::drawJoint( ::box2D::dynamics::joints::B2Joint joint){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","drawJoint",0xf2253f11,"box2D.dynamics.B2World.drawJoint","box2D/dynamics/B2World.hx",1558,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(joint,"joint")
		HX_STACK_LINE(1560)
		::box2D::dynamics::B2Body b1 = joint->getBodyA();		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(1561)
		::box2D::dynamics::B2Body b2 = joint->getBodyB();		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(1562)
		::box2D::common::math::B2Transform xf1 = b1->m_xf;		HX_STACK_VAR(xf1,"xf1");
		HX_STACK_LINE(1563)
		::box2D::common::math::B2Transform xf2 = b2->m_xf;		HX_STACK_VAR(xf2,"xf2");
		HX_STACK_LINE(1564)
		::box2D::common::math::B2Vec2 x1 = xf1->position;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(1565)
		::box2D::common::math::B2Vec2 x2 = xf2->position;		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(1566)
		::box2D::common::math::B2Vec2 p1 = joint->getAnchorA();		HX_STACK_VAR(p1,"p1");
		HX_STACK_LINE(1567)
		::box2D::common::math::B2Vec2 p2 = joint->getAnchorB();		HX_STACK_VAR(p2,"p2");
		HX_STACK_LINE(1570)
		::box2D::common::B2Color color = ::box2D::dynamics::B2World_obj::s_jointColor;		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(1572)
		{
			HX_STACK_LINE(1572)
			int _g = joint->m_type;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1572)
			switch( (int)(_g)){
				case (int)3: {
					HX_STACK_LINE(1575)
					this->m_debugDraw->drawSegment(p1,p2,color);
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(1579)
					::box2D::dynamics::joints::B2PulleyJoint pulley;		HX_STACK_VAR(pulley,"pulley");
					HX_STACK_LINE(1579)
					pulley = hx::TCast< box2D::dynamics::joints::B2PulleyJoint >::cast(joint);
					HX_STACK_LINE(1580)
					::box2D::common::math::B2Vec2 s1 = pulley->getGroundAnchorA();		HX_STACK_VAR(s1,"s1");
					HX_STACK_LINE(1581)
					::box2D::common::math::B2Vec2 s2 = pulley->getGroundAnchorB();		HX_STACK_VAR(s2,"s2");
					HX_STACK_LINE(1582)
					this->m_debugDraw->drawSegment(s1,p1,color);
					HX_STACK_LINE(1583)
					this->m_debugDraw->drawSegment(s2,p2,color);
					HX_STACK_LINE(1584)
					this->m_debugDraw->drawSegment(s1,s2,color);
				}
				;break;
				case (int)5: {
					HX_STACK_LINE(1588)
					this->m_debugDraw->drawSegment(p1,p2,color);
				}
				;break;
				default: {
					HX_STACK_LINE(1591)
					if (((b1 != this->m_groundBody))){
						HX_STACK_LINE(1592)
						this->m_debugDraw->drawSegment(x1,p1,color);
					}
					HX_STACK_LINE(1593)
					this->m_debugDraw->drawSegment(p1,p2,color);
					HX_STACK_LINE(1594)
					if (((b2 != this->m_groundBody))){
						HX_STACK_LINE(1595)
						this->m_debugDraw->drawSegment(x2,p2,color);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2World_obj,drawJoint,(void))

Void B2World_obj::drawShape( ::box2D::collision::shapes::B2Shape shape,::box2D::common::math::B2Transform xf,::box2D::common::B2Color color){
{
		HX_STACK_FRAME("box2D.dynamics.B2World","drawShape",0x1c19e8e8,"box2D.dynamics.B2World.drawShape","box2D/dynamics/B2World.hx",1601,0xb09d3b25)
		HX_STACK_THIS(this)
		HX_STACK_ARG(shape,"shape")
		HX_STACK_ARG(xf,"xf")
		HX_STACK_ARG(color,"color")
		HX_STACK_LINE(1601)
		int _g = shape->m_type;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(1601)
		switch( (int)(_g)){
			case (int)1: {
				HX_STACK_LINE(1605)
				::box2D::collision::shapes::B2CircleShape circle;		HX_STACK_VAR(circle,"circle");
				HX_STACK_LINE(1605)
				circle = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(shape);
				HX_STACK_LINE(1607)
				::box2D::common::math::B2Vec2 center = ::box2D::common::math::B2Math_obj::mulX(xf,circle->m_p);		HX_STACK_VAR(center,"center");
				HX_STACK_LINE(1608)
				Float radius = circle->m_radius;		HX_STACK_VAR(radius,"radius");
				HX_STACK_LINE(1609)
				::box2D::common::math::B2Vec2 axis = xf->R->col1;		HX_STACK_VAR(axis,"axis");
				HX_STACK_LINE(1611)
				this->m_debugDraw->drawSolidCircle(center,radius,axis,color);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(1616)
				int i;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1617)
				::box2D::collision::shapes::B2PolygonShape poly;		HX_STACK_VAR(poly,"poly");
				HX_STACK_LINE(1617)
				poly = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(shape);
				HX_STACK_LINE(1618)
				int vertexCount = poly->getVertexCount();		HX_STACK_VAR(vertexCount,"vertexCount");
				HX_STACK_LINE(1619)
				Array< ::Dynamic > localVertices = poly->getVertices();		HX_STACK_VAR(localVertices,"localVertices");
				HX_STACK_LINE(1621)
				Array< ::Dynamic > vertices = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(vertices,"vertices");
				HX_STACK_LINE(1623)
				{
					HX_STACK_LINE(1623)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(1623)
					while((true)){
						HX_STACK_LINE(1623)
						if ((!(((_g1 < vertexCount))))){
							HX_STACK_LINE(1623)
							break;
						}
						HX_STACK_LINE(1623)
						int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(1625)
						vertices[i1] = ::box2D::common::math::B2Math_obj::mulX(xf,localVertices->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >());
					}
				}
				HX_STACK_LINE(1628)
				this->m_debugDraw->drawSolidPolygon(vertices,vertexCount,color);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(1633)
				::box2D::collision::shapes::B2EdgeShape edge;		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(1633)
				edge = hx::TCast< box2D::collision::shapes::B2EdgeShape >::cast(shape);
				HX_STACK_LINE(1635)
				::box2D::common::math::B2Vec2 _g1 = edge->getVertex1();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(1635)
				::box2D::common::math::B2Vec2 _g11 = ::box2D::common::math::B2Math_obj::mulX(xf,_g1);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(1635)
				::box2D::common::math::B2Vec2 _g2 = edge->getVertex2();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1635)
				::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::mulX(xf,_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(1635)
				this->m_debugDraw->drawSegment(_g11,_g3,color);
			}
			;break;
			default: {
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2World_obj,drawShape,(void))

::box2D::dynamics::B2TimeStep B2World_obj::s_timestep2;

::box2D::common::math::B2Transform B2World_obj::s_xf;

::box2D::common::math::B2Sweep B2World_obj::s_backupA;

::box2D::common::math::B2Sweep B2World_obj::s_backupB;

::box2D::dynamics::B2TimeStep B2World_obj::s_timestep;

Array< ::Dynamic > B2World_obj::s_queue;

::box2D::common::B2Color B2World_obj::s_jointColor;

bool B2World_obj::m_warmStarting;

bool B2World_obj::m_continuousPhysics;

int B2World_obj::e_newFixture;

int B2World_obj::e_locked;


B2World_obj::B2World_obj()
{
}

void B2World_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2World);
	HX_MARK_MEMBER_NAME(s_stack,"s_stack");
	HX_MARK_MEMBER_NAME(m_flags,"m_flags");
	HX_MARK_MEMBER_NAME(m_contactManager,"m_contactManager");
	HX_MARK_MEMBER_NAME(m_contactSolver,"m_contactSolver");
	HX_MARK_MEMBER_NAME(m_island,"m_island");
	HX_MARK_MEMBER_NAME(m_bodyList,"m_bodyList");
	HX_MARK_MEMBER_NAME(m_jointList,"m_jointList");
	HX_MARK_MEMBER_NAME(m_contactList,"m_contactList");
	HX_MARK_MEMBER_NAME(m_bodyCount,"m_bodyCount");
	HX_MARK_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_MARK_MEMBER_NAME(m_jointCount,"m_jointCount");
	HX_MARK_MEMBER_NAME(m_controllerList,"m_controllerList");
	HX_MARK_MEMBER_NAME(m_controllerCount,"m_controllerCount");
	HX_MARK_MEMBER_NAME(m_gravity,"m_gravity");
	HX_MARK_MEMBER_NAME(m_allowSleep,"m_allowSleep");
	HX_MARK_MEMBER_NAME(m_groundBody,"m_groundBody");
	HX_MARK_MEMBER_NAME(m_destructionListener,"m_destructionListener");
	HX_MARK_MEMBER_NAME(m_debugDraw,"m_debugDraw");
	HX_MARK_MEMBER_NAME(m_inv_dt0,"m_inv_dt0");
	HX_MARK_END_CLASS();
}

void B2World_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(s_stack,"s_stack");
	HX_VISIT_MEMBER_NAME(m_flags,"m_flags");
	HX_VISIT_MEMBER_NAME(m_contactManager,"m_contactManager");
	HX_VISIT_MEMBER_NAME(m_contactSolver,"m_contactSolver");
	HX_VISIT_MEMBER_NAME(m_island,"m_island");
	HX_VISIT_MEMBER_NAME(m_bodyList,"m_bodyList");
	HX_VISIT_MEMBER_NAME(m_jointList,"m_jointList");
	HX_VISIT_MEMBER_NAME(m_contactList,"m_contactList");
	HX_VISIT_MEMBER_NAME(m_bodyCount,"m_bodyCount");
	HX_VISIT_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_VISIT_MEMBER_NAME(m_jointCount,"m_jointCount");
	HX_VISIT_MEMBER_NAME(m_controllerList,"m_controllerList");
	HX_VISIT_MEMBER_NAME(m_controllerCount,"m_controllerCount");
	HX_VISIT_MEMBER_NAME(m_gravity,"m_gravity");
	HX_VISIT_MEMBER_NAME(m_allowSleep,"m_allowSleep");
	HX_VISIT_MEMBER_NAME(m_groundBody,"m_groundBody");
	HX_VISIT_MEMBER_NAME(m_destructionListener,"m_destructionListener");
	HX_VISIT_MEMBER_NAME(m_debugDraw,"m_debugDraw");
	HX_VISIT_MEMBER_NAME(m_inv_dt0,"m_inv_dt0");
}

Dynamic B2World_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"s_xf") ) { return s_xf; }
		if (HX_FIELD_EQ(inName,"step") ) { return step_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"solve") ) { return solve_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_queue") ) { return s_queue; }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"s_stack") ) { return s_stack; }
		if (HX_FIELD_EQ(inName,"m_flags") ) { return m_flags; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"e_locked") ) { return e_locked; }
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		if (HX_FIELD_EQ(inName,"isLocked") ) { return isLocked_dyn(); }
		if (HX_FIELD_EQ(inName,"solveTOI") ) { return solveTOI_dyn(); }
		if (HX_FIELD_EQ(inName,"m_island") ) { return m_island; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_backupA") ) { return s_backupA; }
		if (HX_FIELD_EQ(inName,"s_backupB") ) { return s_backupB; }
		if (HX_FIELD_EQ(inName,"queryAABB") ) { return queryAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"drawJoint") ) { return drawJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"drawShape") ) { return drawShape_dyn(); }
		if (HX_FIELD_EQ(inName,"m_gravity") ) { return m_gravity; }
		if (HX_FIELD_EQ(inName,"m_inv_dt0") ) { return m_inv_dt0; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_timestep") ) { return s_timestep; }
		if (HX_FIELD_EQ(inName,"createBody") ) { return createBody_dyn(); }
		if (HX_FIELD_EQ(inName,"setGravity") ) { return setGravity_dyn(); }
		if (HX_FIELD_EQ(inName,"getGravity") ) { return getGravity_dyn(); }
		if (HX_FIELD_EQ(inName,"queryShape") ) { return queryShape_dyn(); }
		if (HX_FIELD_EQ(inName,"queryPoint") ) { return queryPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCastOne") ) { return rayCastOne_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCastAll") ) { return rayCastAll_dyn(); }
		if (HX_FIELD_EQ(inName,"m_bodyList") ) { return m_bodyList; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"s_timestep2") ) { return s_timestep2; }
		if (HX_FIELD_EQ(inName,"destroyBody") ) { return destroyBody_dyn(); }
		if (HX_FIELD_EQ(inName,"createJoint") ) { return createJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"clearForces") ) { return clearForces_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyList") ) { return getBodyList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { return m_jointList; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { return m_bodyCount; }
		if (HX_FIELD_EQ(inName,"m_debugDraw") ) { return m_debugDraw; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_jointColor") ) { return s_jointColor; }
		if (HX_FIELD_EQ(inName,"e_newFixture") ) { return e_newFixture; }
		if (HX_FIELD_EQ(inName,"setDebugDraw") ) { return setDebugDraw_dyn(); }
		if (HX_FIELD_EQ(inName,"destroyJoint") ) { return destroyJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyCount") ) { return getBodyCount_dyn(); }
		if (HX_FIELD_EQ(inName,"getJointList") ) { return getJointList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { return m_jointCount; }
		if (HX_FIELD_EQ(inName,"m_allowSleep") ) { return m_allowSleep; }
		if (HX_FIELD_EQ(inName,"m_groundBody") ) { return m_groundBody; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"setBroadPhase") ) { return setBroadPhase_dyn(); }
		if (HX_FIELD_EQ(inName,"getProxyCount") ) { return getProxyCount_dyn(); }
		if (HX_FIELD_EQ(inName,"addController") ) { return addController_dyn(); }
		if (HX_FIELD_EQ(inName,"getJointCount") ) { return getJointCount_dyn(); }
		if (HX_FIELD_EQ(inName,"getGroundBody") ) { return getGroundBody_dyn(); }
		if (HX_FIELD_EQ(inName,"drawDebugData") ) { return drawDebugData_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactList") ) { return m_contactList; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_warmStarting") ) { return m_warmStarting; }
		if (HX_FIELD_EQ(inName,"getContactList") ) { return getContactList_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { return m_contactCount; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"setWarmStarting") ) { return setWarmStarting_dyn(); }
		if (HX_FIELD_EQ(inName,"getContactCount") ) { return getContactCount_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { return m_contactSolver; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setContactFilter") ) { return setContactFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"removeController") ) { return removeController_dyn(); }
		if (HX_FIELD_EQ(inName,"createController") ) { return createController_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactManager") ) { return m_contactManager; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { return m_controllerList; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"destroyController") ) { return destroyController_dyn(); }
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { return m_controllerCount; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setContactListener") ) { return setContactListener_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"m_continuousPhysics") ) { return m_continuousPhysics; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"setContinuousPhysics") ) { return setContinuousPhysics_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"m_destructionListener") ) { return m_destructionListener; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"setDestructionListener") ) { return setDestructionListener_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2World_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"s_xf") ) { s_xf=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_queue") ) { s_queue=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_stack") ) { s_stack=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_flags") ) { m_flags=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"e_locked") ) { e_locked=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_island") ) { m_island=inValue.Cast< ::box2D::dynamics::B2Island >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_backupA") ) { s_backupA=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_backupB") ) { s_backupB=inValue.Cast< ::box2D::common::math::B2Sweep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_gravity") ) { m_gravity=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_inv_dt0") ) { m_inv_dt0=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_timestep") ) { s_timestep=inValue.Cast< ::box2D::dynamics::B2TimeStep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyList") ) { m_bodyList=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"s_timestep2") ) { s_timestep2=inValue.Cast< ::box2D::dynamics::B2TimeStep >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointList") ) { m_jointList=inValue.Cast< ::box2D::dynamics::joints::B2Joint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { m_bodyCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_debugDraw") ) { m_debugDraw=inValue.Cast< ::box2D::dynamics::B2DebugDraw >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_jointColor") ) { s_jointColor=inValue.Cast< ::box2D::common::B2Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_newFixture") ) { e_newFixture=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { m_jointCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_allowSleep") ) { m_allowSleep=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_groundBody") ) { m_groundBody=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_contactList") ) { m_contactList=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_warmStarting") ) { m_warmStarting=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { m_contactCount=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { m_contactSolver=inValue.Cast< ::box2D::dynamics::contacts::B2ContactSolver >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_contactManager") ) { m_contactManager=inValue.Cast< ::box2D::dynamics::B2ContactManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_controllerList") ) { m_controllerList=inValue.Cast< ::box2D::dynamics::controllers::B2Controller >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_controllerCount") ) { m_controllerCount=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"m_continuousPhysics") ) { m_continuousPhysics=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"m_destructionListener") ) { m_destructionListener=inValue.Cast< ::box2D::dynamics::B2DestructionListener >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2World_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("s_stack"));
	outFields->push(HX_CSTRING("m_flags"));
	outFields->push(HX_CSTRING("m_contactManager"));
	outFields->push(HX_CSTRING("m_contactSolver"));
	outFields->push(HX_CSTRING("m_island"));
	outFields->push(HX_CSTRING("m_bodyList"));
	outFields->push(HX_CSTRING("m_jointList"));
	outFields->push(HX_CSTRING("m_contactList"));
	outFields->push(HX_CSTRING("m_bodyCount"));
	outFields->push(HX_CSTRING("m_contactCount"));
	outFields->push(HX_CSTRING("m_jointCount"));
	outFields->push(HX_CSTRING("m_controllerList"));
	outFields->push(HX_CSTRING("m_controllerCount"));
	outFields->push(HX_CSTRING("m_gravity"));
	outFields->push(HX_CSTRING("m_allowSleep"));
	outFields->push(HX_CSTRING("m_groundBody"));
	outFields->push(HX_CSTRING("m_destructionListener"));
	outFields->push(HX_CSTRING("m_debugDraw"));
	outFields->push(HX_CSTRING("m_inv_dt0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_timestep2"),
	HX_CSTRING("s_xf"),
	HX_CSTRING("s_backupA"),
	HX_CSTRING("s_backupB"),
	HX_CSTRING("s_timestep"),
	HX_CSTRING("s_queue"),
	HX_CSTRING("s_jointColor"),
	HX_CSTRING("m_warmStarting"),
	HX_CSTRING("m_continuousPhysics"),
	HX_CSTRING("e_newFixture"),
	HX_CSTRING("e_locked"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2World_obj,s_stack),HX_CSTRING("s_stack")},
	{hx::fsInt,(int)offsetof(B2World_obj,m_flags),HX_CSTRING("m_flags")},
	{hx::fsObject /*::box2D::dynamics::B2ContactManager*/ ,(int)offsetof(B2World_obj,m_contactManager),HX_CSTRING("m_contactManager")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactSolver*/ ,(int)offsetof(B2World_obj,m_contactSolver),HX_CSTRING("m_contactSolver")},
	{hx::fsObject /*::box2D::dynamics::B2Island*/ ,(int)offsetof(B2World_obj,m_island),HX_CSTRING("m_island")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2World_obj,m_bodyList),HX_CSTRING("m_bodyList")},
	{hx::fsObject /*::box2D::dynamics::joints::B2Joint*/ ,(int)offsetof(B2World_obj,m_jointList),HX_CSTRING("m_jointList")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2Contact*/ ,(int)offsetof(B2World_obj,m_contactList),HX_CSTRING("m_contactList")},
	{hx::fsInt,(int)offsetof(B2World_obj,m_bodyCount),HX_CSTRING("m_bodyCount")},
	{hx::fsInt,(int)offsetof(B2World_obj,m_contactCount),HX_CSTRING("m_contactCount")},
	{hx::fsInt,(int)offsetof(B2World_obj,m_jointCount),HX_CSTRING("m_jointCount")},
	{hx::fsObject /*::box2D::dynamics::controllers::B2Controller*/ ,(int)offsetof(B2World_obj,m_controllerList),HX_CSTRING("m_controllerList")},
	{hx::fsInt,(int)offsetof(B2World_obj,m_controllerCount),HX_CSTRING("m_controllerCount")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2World_obj,m_gravity),HX_CSTRING("m_gravity")},
	{hx::fsBool,(int)offsetof(B2World_obj,m_allowSleep),HX_CSTRING("m_allowSleep")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2World_obj,m_groundBody),HX_CSTRING("m_groundBody")},
	{hx::fsObject /*::box2D::dynamics::B2DestructionListener*/ ,(int)offsetof(B2World_obj,m_destructionListener),HX_CSTRING("m_destructionListener")},
	{hx::fsObject /*::box2D::dynamics::B2DebugDraw*/ ,(int)offsetof(B2World_obj,m_debugDraw),HX_CSTRING("m_debugDraw")},
	{hx::fsFloat,(int)offsetof(B2World_obj,m_inv_dt0),HX_CSTRING("m_inv_dt0")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("setDestructionListener"),
	HX_CSTRING("setContactFilter"),
	HX_CSTRING("setContactListener"),
	HX_CSTRING("setDebugDraw"),
	HX_CSTRING("setBroadPhase"),
	HX_CSTRING("validate"),
	HX_CSTRING("getProxyCount"),
	HX_CSTRING("createBody"),
	HX_CSTRING("destroyBody"),
	HX_CSTRING("createJoint"),
	HX_CSTRING("destroyJoint"),
	HX_CSTRING("addController"),
	HX_CSTRING("removeController"),
	HX_CSTRING("createController"),
	HX_CSTRING("destroyController"),
	HX_CSTRING("setWarmStarting"),
	HX_CSTRING("setContinuousPhysics"),
	HX_CSTRING("getBodyCount"),
	HX_CSTRING("getJointCount"),
	HX_CSTRING("getContactCount"),
	HX_CSTRING("setGravity"),
	HX_CSTRING("getGravity"),
	HX_CSTRING("getGroundBody"),
	HX_CSTRING("step"),
	HX_CSTRING("clearForces"),
	HX_CSTRING("drawDebugData"),
	HX_CSTRING("queryAABB"),
	HX_CSTRING("queryShape"),
	HX_CSTRING("queryPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("rayCastOne"),
	HX_CSTRING("rayCastAll"),
	HX_CSTRING("getBodyList"),
	HX_CSTRING("getJointList"),
	HX_CSTRING("getContactList"),
	HX_CSTRING("isLocked"),
	HX_CSTRING("s_stack"),
	HX_CSTRING("solve"),
	HX_CSTRING("solveTOI"),
	HX_CSTRING("drawJoint"),
	HX_CSTRING("drawShape"),
	HX_CSTRING("m_flags"),
	HX_CSTRING("m_contactManager"),
	HX_CSTRING("m_contactSolver"),
	HX_CSTRING("m_island"),
	HX_CSTRING("m_bodyList"),
	HX_CSTRING("m_jointList"),
	HX_CSTRING("m_contactList"),
	HX_CSTRING("m_bodyCount"),
	HX_CSTRING("m_contactCount"),
	HX_CSTRING("m_jointCount"),
	HX_CSTRING("m_controllerList"),
	HX_CSTRING("m_controllerCount"),
	HX_CSTRING("m_gravity"),
	HX_CSTRING("m_allowSleep"),
	HX_CSTRING("m_groundBody"),
	HX_CSTRING("m_destructionListener"),
	HX_CSTRING("m_debugDraw"),
	HX_CSTRING("m_inv_dt0"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2World_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2World_obj::s_timestep2,"s_timestep2");
	HX_MARK_MEMBER_NAME(B2World_obj::s_xf,"s_xf");
	HX_MARK_MEMBER_NAME(B2World_obj::s_backupA,"s_backupA");
	HX_MARK_MEMBER_NAME(B2World_obj::s_backupB,"s_backupB");
	HX_MARK_MEMBER_NAME(B2World_obj::s_timestep,"s_timestep");
	HX_MARK_MEMBER_NAME(B2World_obj::s_queue,"s_queue");
	HX_MARK_MEMBER_NAME(B2World_obj::s_jointColor,"s_jointColor");
	HX_MARK_MEMBER_NAME(B2World_obj::m_warmStarting,"m_warmStarting");
	HX_MARK_MEMBER_NAME(B2World_obj::m_continuousPhysics,"m_continuousPhysics");
	HX_MARK_MEMBER_NAME(B2World_obj::e_newFixture,"e_newFixture");
	HX_MARK_MEMBER_NAME(B2World_obj::e_locked,"e_locked");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2World_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2World_obj::s_timestep2,"s_timestep2");
	HX_VISIT_MEMBER_NAME(B2World_obj::s_xf,"s_xf");
	HX_VISIT_MEMBER_NAME(B2World_obj::s_backupA,"s_backupA");
	HX_VISIT_MEMBER_NAME(B2World_obj::s_backupB,"s_backupB");
	HX_VISIT_MEMBER_NAME(B2World_obj::s_timestep,"s_timestep");
	HX_VISIT_MEMBER_NAME(B2World_obj::s_queue,"s_queue");
	HX_VISIT_MEMBER_NAME(B2World_obj::s_jointColor,"s_jointColor");
	HX_VISIT_MEMBER_NAME(B2World_obj::m_warmStarting,"m_warmStarting");
	HX_VISIT_MEMBER_NAME(B2World_obj::m_continuousPhysics,"m_continuousPhysics");
	HX_VISIT_MEMBER_NAME(B2World_obj::e_newFixture,"e_newFixture");
	HX_VISIT_MEMBER_NAME(B2World_obj::e_locked,"e_locked");
};

#endif

Class B2World_obj::__mClass;

void B2World_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2World"), hx::TCanCast< B2World_obj> ,sStaticFields,sMemberFields,
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

void B2World_obj::__boot()
{
	s_timestep2= ::box2D::dynamics::B2TimeStep_obj::__new();
	s_xf= ::box2D::common::math::B2Transform_obj::__new(null(),null());
	s_backupA= ::box2D::common::math::B2Sweep_obj::__new();
	s_backupB= ::box2D::common::math::B2Sweep_obj::__new();
	s_timestep= ::box2D::dynamics::B2TimeStep_obj::__new();
	s_queue= Array_obj< ::Dynamic >::__new();
	s_jointColor= ::box2D::common::B2Color_obj::__new(0.5,0.8,0.8);
	e_newFixture= (int)1;
	e_locked= (int)2;
}

} // end namespace box2D
} // end namespace dynamics
