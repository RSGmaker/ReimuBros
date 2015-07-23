#include <hxcpp.h>

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
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2World
#include <box2D/dynamics/B2World.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJointDef
#include <box2D/dynamics/joints/B2PulleyJointDef.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2PulleyJoint_obj::__construct(::box2D::dynamics::joints::B2PulleyJointDef def)
{
HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","new",0xc626ce77,"box2D.dynamics.joints.B2PulleyJoint.new","box2D/dynamics/joints/B2PulleyJoint.hx",129,0xce8942fa)
HX_STACK_THIS(this)
HX_STACK_ARG(def,"def")
{
	HX_STACK_LINE(132)
	super::__construct(def);
	HX_STACK_LINE(135)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(135)
	this->m_groundAnchor1 = _g;
	HX_STACK_LINE(136)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(136)
	this->m_groundAnchor2 = _g1;
	HX_STACK_LINE(137)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(137)
	this->m_localAnchor1 = _g2;
	HX_STACK_LINE(138)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(138)
	this->m_localAnchor2 = _g3;
	HX_STACK_LINE(140)
	::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(140)
	this->m_u1 = _g4;
	HX_STACK_LINE(141)
	::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(141)
	this->m_u2 = _g5;
	HX_STACK_LINE(144)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(145)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(146)
	Float tY;		HX_STACK_VAR(tY,"tY");
	HX_STACK_LINE(148)
	this->m_ground = this->m_bodyA->m_world->m_groundBody;
	HX_STACK_LINE(150)
	this->m_groundAnchor1->x = (def->groundAnchorA->x - this->m_ground->m_xf->position->x);
	HX_STACK_LINE(151)
	this->m_groundAnchor1->y = (def->groundAnchorA->y - this->m_ground->m_xf->position->y);
	HX_STACK_LINE(153)
	this->m_groundAnchor2->x = (def->groundAnchorB->x - this->m_ground->m_xf->position->x);
	HX_STACK_LINE(154)
	this->m_groundAnchor2->y = (def->groundAnchorB->y - this->m_ground->m_xf->position->y);
	HX_STACK_LINE(156)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_STACK_LINE(158)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_STACK_LINE(161)
	this->m_ratio = def->ratio;
	HX_STACK_LINE(163)
	this->m_constant = (def->lengthA + (this->m_ratio * def->lengthB));
	HX_STACK_LINE(165)
	Float _g6 = ::box2D::common::math::B2Math_obj::min(def->maxLengthA,(this->m_constant - (this->m_ratio * ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength)));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(165)
	this->m_maxLength1 = _g6;
	HX_STACK_LINE(166)
	Float _g7 = ::box2D::common::math::B2Math_obj::min(def->maxLengthB,(Float(((this->m_constant - ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength))) / Float(this->m_ratio)));		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(166)
	this->m_maxLength2 = _g7;
	HX_STACK_LINE(168)
	this->m_impulse = 0.0;
	HX_STACK_LINE(169)
	this->m_limitImpulse1 = 0.0;
	HX_STACK_LINE(170)
	this->m_limitImpulse2 = 0.0;
}
;
	return null();
}

//B2PulleyJoint_obj::~B2PulleyJoint_obj() { }

Dynamic B2PulleyJoint_obj::__CreateEmpty() { return  new B2PulleyJoint_obj; }
hx::ObjectPtr< B2PulleyJoint_obj > B2PulleyJoint_obj::__new(::box2D::dynamics::joints::B2PulleyJointDef def)
{  hx::ObjectPtr< B2PulleyJoint_obj > result = new B2PulleyJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2PulleyJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PulleyJoint_obj > result = new B2PulleyJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getAnchorA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getAnchorA",0xfb3474ff,"box2D.dynamics.joints.B2PulleyJoint.getAnchorA","box2D/dynamics/joints/B2PulleyJoint.hx",43,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(43)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getAnchorB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getAnchorB",0xfb347500,"box2D.dynamics.joints.B2PulleyJoint.getAnchorB","box2D/dynamics/joints/B2PulleyJoint.hx",47,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getReactionForce( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getReactionForce",0x36913e95,"box2D.dynamics.joints.B2PulleyJoint.getReactionForce","box2D/dynamics/joints/B2PulleyJoint.hx",55,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(55)
	return ::box2D::common::math::B2Vec2_obj::__new(((inv_dt * this->m_impulse) * this->m_u2->x),((inv_dt * this->m_impulse) * this->m_u2->y));
}


Float B2PulleyJoint_obj::getReactionTorque( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getReactionTorque",0x218f3ee0,"box2D.dynamics.joints.B2PulleyJoint.getReactionTorque","box2D/dynamics/joints/B2PulleyJoint.hx",62,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(62)
	return 0.0;
}


::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getGroundAnchorA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getGroundAnchorA",0x44e6c978,"box2D.dynamics.joints.B2PulleyJoint.getGroundAnchorA","box2D/dynamics/joints/B2PulleyJoint.hx",69,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(71)
	::box2D::common::math::B2Vec2 a = this->m_ground->m_xf->position->copy();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(72)
	a->add(this->m_groundAnchor1);
	HX_STACK_LINE(73)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getGroundAnchorA,return )

::box2D::common::math::B2Vec2 B2PulleyJoint_obj::getGroundAnchorB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getGroundAnchorB",0x44e6c979,"box2D.dynamics.joints.B2PulleyJoint.getGroundAnchorB","box2D/dynamics/joints/B2PulleyJoint.hx",80,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	::box2D::common::math::B2Vec2 a = this->m_ground->m_xf->position->copy();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(83)
	a->add(this->m_groundAnchor2);
	HX_STACK_LINE(84)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getGroundAnchorB,return )

Float B2PulleyJoint_obj::getLength1( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getLength1",0x802d3d5e,"box2D.dynamics.joints.B2PulleyJoint.getLength1","box2D/dynamics/joints/B2PulleyJoint.hx",91,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(92)
	::box2D::common::math::B2Vec2 p = this->m_bodyA->getWorldPoint(this->m_localAnchor1);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(94)
	Float sX = (this->m_ground->m_xf->position->x + this->m_groundAnchor1->x);		HX_STACK_VAR(sX,"sX");
	HX_STACK_LINE(95)
	Float sY = (this->m_ground->m_xf->position->y + this->m_groundAnchor1->y);		HX_STACK_VAR(sY,"sY");
	HX_STACK_LINE(97)
	Float dX = (p->x - sX);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(98)
	Float dY = (p->y - sY);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(100)
	return ::Math_obj::sqrt(((dX * dX) + (dY * dY)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getLength1,return )

Float B2PulleyJoint_obj::getLength2( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getLength2",0x802d3d5f,"box2D.dynamics.joints.B2PulleyJoint.getLength2","box2D/dynamics/joints/B2PulleyJoint.hx",107,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(108)
	::box2D::common::math::B2Vec2 p = this->m_bodyB->getWorldPoint(this->m_localAnchor2);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(110)
	Float sX = (this->m_ground->m_xf->position->x + this->m_groundAnchor2->x);		HX_STACK_VAR(sX,"sX");
	HX_STACK_LINE(111)
	Float sY = (this->m_ground->m_xf->position->y + this->m_groundAnchor2->y);		HX_STACK_VAR(sY,"sY");
	HX_STACK_LINE(113)
	Float dX = (p->x - sX);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(114)
	Float dY = (p->y - sY);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(116)
	return ::Math_obj::sqrt(((dX * dX) + (dY * dY)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getLength2,return )

Float B2PulleyJoint_obj::getRatio( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","getRatio",0xfcc4d31e,"box2D.dynamics.joints.B2PulleyJoint.getRatio","box2D/dynamics/joints/B2PulleyJoint.hx",123,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_LINE(123)
	return this->m_ratio;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PulleyJoint_obj,getRatio,return )

Void B2PulleyJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","initVelocityConstraints",0x45dd2cc0,"box2D.dynamics.joints.B2PulleyJoint.initVelocityConstraints","box2D/dynamics/joints/B2PulleyJoint.hx",174,0xce8942fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(175)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(176)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(178)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(181)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(182)
		Float r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(r1X,"r1X");
		HX_STACK_LINE(183)
		Float r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(r1Y,"r1Y");
		HX_STACK_LINE(184)
		Float tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(185)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_STACK_LINE(186)
		r1X = tX;
		HX_STACK_LINE(188)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(189)
		Float r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(r2X,"r2X");
		HX_STACK_LINE(190)
		Float r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(r2Y,"r2Y");
		HX_STACK_LINE(191)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_STACK_LINE(192)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_STACK_LINE(193)
		r2X = tX;
		HX_STACK_LINE(196)
		Float p1X = (bA->m_sweep->c->x + r1X);		HX_STACK_VAR(p1X,"p1X");
		HX_STACK_LINE(197)
		Float p1Y = (bA->m_sweep->c->y + r1Y);		HX_STACK_VAR(p1Y,"p1Y");
		HX_STACK_LINE(199)
		Float p2X = (bB->m_sweep->c->x + r2X);		HX_STACK_VAR(p2X,"p2X");
		HX_STACK_LINE(200)
		Float p2Y = (bB->m_sweep->c->y + r2Y);		HX_STACK_VAR(p2Y,"p2Y");
		HX_STACK_LINE(203)
		Float s1X = (this->m_ground->m_xf->position->x + this->m_groundAnchor1->x);		HX_STACK_VAR(s1X,"s1X");
		HX_STACK_LINE(204)
		Float s1Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor1->y);		HX_STACK_VAR(s1Y,"s1Y");
		HX_STACK_LINE(206)
		Float s2X = (this->m_ground->m_xf->position->x + this->m_groundAnchor2->x);		HX_STACK_VAR(s2X,"s2X");
		HX_STACK_LINE(207)
		Float s2Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor2->y);		HX_STACK_VAR(s2Y,"s2Y");
		HX_STACK_LINE(211)
		this->m_u1->set((p1X - s1X),(p1Y - s1Y));
		HX_STACK_LINE(213)
		this->m_u2->set((p2X - s2X),(p2Y - s2Y));
		HX_STACK_LINE(215)
		Float length1 = this->m_u1->length();		HX_STACK_VAR(length1,"length1");
		HX_STACK_LINE(216)
		Float length2 = this->m_u2->length();		HX_STACK_VAR(length2,"length2");
		HX_STACK_LINE(218)
		if (((length1 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_STACK_LINE(221)
			this->m_u1->multiply((Float(1.0) / Float(length1)));
		}
		else{
			HX_STACK_LINE(225)
			this->m_u1->setZero();
		}
		HX_STACK_LINE(228)
		if (((length2 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_STACK_LINE(231)
			this->m_u2->multiply((Float(1.0) / Float(length2)));
		}
		else{
			HX_STACK_LINE(235)
			this->m_u2->setZero();
		}
		HX_STACK_LINE(238)
		Float C = ((this->m_constant - length1) - (this->m_ratio * length2));		HX_STACK_VAR(C,"C");
		HX_STACK_LINE(239)
		if (((C > 0.0))){
			HX_STACK_LINE(241)
			this->m_state = (int)0;
			HX_STACK_LINE(242)
			this->m_impulse = 0.0;
		}
		else{
			HX_STACK_LINE(246)
			this->m_state = (int)2;
		}
		HX_STACK_LINE(249)
		if (((length1 < this->m_maxLength1))){
			HX_STACK_LINE(251)
			this->m_limitState1 = (int)0;
			HX_STACK_LINE(252)
			this->m_limitImpulse1 = 0.0;
		}
		else{
			HX_STACK_LINE(256)
			this->m_limitState1 = (int)2;
		}
		HX_STACK_LINE(259)
		if (((length2 < this->m_maxLength2))){
			HX_STACK_LINE(261)
			this->m_limitState2 = (int)0;
			HX_STACK_LINE(262)
			this->m_limitImpulse2 = 0.0;
		}
		else{
			HX_STACK_LINE(266)
			this->m_limitState2 = (int)2;
		}
		HX_STACK_LINE(271)
		Float cr1u1 = ((r1X * this->m_u1->y) - (r1Y * this->m_u1->x));		HX_STACK_VAR(cr1u1,"cr1u1");
		HX_STACK_LINE(273)
		Float cr2u2 = ((r2X * this->m_u2->y) - (r2Y * this->m_u2->x));		HX_STACK_VAR(cr2u2,"cr2u2");
		HX_STACK_LINE(275)
		this->m_limitMass1 = (bA->m_invMass + ((bA->m_invI * cr1u1) * cr1u1));
		HX_STACK_LINE(276)
		this->m_limitMass2 = (bB->m_invMass + ((bB->m_invI * cr2u2) * cr2u2));
		HX_STACK_LINE(277)
		this->m_pulleyMass = (this->m_limitMass1 + ((this->m_ratio * this->m_ratio) * this->m_limitMass2));
		HX_STACK_LINE(281)
		this->m_limitMass1 = (Float(1.0) / Float(this->m_limitMass1));
		HX_STACK_LINE(282)
		this->m_limitMass2 = (Float(1.0) / Float(this->m_limitMass2));
		HX_STACK_LINE(283)
		this->m_pulleyMass = (Float(1.0) / Float(this->m_pulleyMass));
		HX_STACK_LINE(285)
		if ((step->warmStarting)){
			HX_STACK_LINE(288)
			hx::MultEq(this->m_impulse,step->dtRatio);
			HX_STACK_LINE(289)
			hx::MultEq(this->m_limitImpulse1,step->dtRatio);
			HX_STACK_LINE(290)
			hx::MultEq(this->m_limitImpulse2,step->dtRatio);
			HX_STACK_LINE(294)
			Float P1X = (((-(this->m_impulse) - this->m_limitImpulse1)) * this->m_u1->x);		HX_STACK_VAR(P1X,"P1X");
			HX_STACK_LINE(295)
			Float P1Y = (((-(this->m_impulse) - this->m_limitImpulse1)) * this->m_u1->y);		HX_STACK_VAR(P1Y,"P1Y");
			HX_STACK_LINE(297)
			Float P2X = ((((-(this->m_ratio) * this->m_impulse) - this->m_limitImpulse2)) * this->m_u2->x);		HX_STACK_VAR(P2X,"P2X");
			HX_STACK_LINE(298)
			Float P2Y = ((((-(this->m_ratio) * this->m_impulse) - this->m_limitImpulse2)) * this->m_u2->y);		HX_STACK_VAR(P2Y,"P2Y");
			HX_STACK_LINE(300)
			hx::AddEq(bA->m_linearVelocity->x,(bA->m_invMass * P1X));
			HX_STACK_LINE(301)
			hx::AddEq(bA->m_linearVelocity->y,(bA->m_invMass * P1Y));
			HX_STACK_LINE(303)
			hx::AddEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * P1Y) - (r1Y * P1X)))));
			HX_STACK_LINE(305)
			hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * P2X));
			HX_STACK_LINE(306)
			hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * P2Y));
			HX_STACK_LINE(308)
			hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * P2Y) - (r2Y * P2X)))));
		}
		else{
			HX_STACK_LINE(312)
			this->m_impulse = 0.0;
			HX_STACK_LINE(313)
			this->m_limitImpulse1 = 0.0;
			HX_STACK_LINE(314)
			this->m_limitImpulse2 = 0.0;
		}
	}
return null();
}


Void B2PulleyJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","solveVelocityConstraints",0xb06d46a3,"box2D.dynamics.joints.B2PulleyJoint.solveVelocityConstraints","box2D/dynamics/joints/B2PulleyJoint.hx",319,0xce8942fa)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(322)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(323)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(325)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(328)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(329)
		Float r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(r1X,"r1X");
		HX_STACK_LINE(330)
		Float r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(r1Y,"r1Y");
		HX_STACK_LINE(331)
		Float tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(332)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_STACK_LINE(333)
		r1X = tX;
		HX_STACK_LINE(335)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(336)
		Float r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(r2X,"r2X");
		HX_STACK_LINE(337)
		Float r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(r2Y,"r2Y");
		HX_STACK_LINE(338)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_STACK_LINE(339)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_STACK_LINE(340)
		r2X = tX;
		HX_STACK_LINE(343)
		Float v1X;		HX_STACK_VAR(v1X,"v1X");
		HX_STACK_LINE(344)
		Float v1Y;		HX_STACK_VAR(v1Y,"v1Y");
		HX_STACK_LINE(345)
		Float v2X;		HX_STACK_VAR(v2X,"v2X");
		HX_STACK_LINE(346)
		Float v2Y;		HX_STACK_VAR(v2Y,"v2Y");
		HX_STACK_LINE(347)
		Float P1X;		HX_STACK_VAR(P1X,"P1X");
		HX_STACK_LINE(348)
		Float P1Y;		HX_STACK_VAR(P1Y,"P1Y");
		HX_STACK_LINE(349)
		Float P2X;		HX_STACK_VAR(P2X,"P2X");
		HX_STACK_LINE(350)
		Float P2Y;		HX_STACK_VAR(P2Y,"P2Y");
		HX_STACK_LINE(351)
		Float Cdot;		HX_STACK_VAR(Cdot,"Cdot");
		HX_STACK_LINE(352)
		Float impulse;		HX_STACK_VAR(impulse,"impulse");
		HX_STACK_LINE(353)
		Float oldImpulse;		HX_STACK_VAR(oldImpulse,"oldImpulse");
		HX_STACK_LINE(355)
		if (((this->m_state == (int)2))){
			HX_STACK_LINE(358)
			v1X = (bA->m_linearVelocity->x + (-(bA->m_angularVelocity) * r1Y));
			HX_STACK_LINE(359)
			v1Y = (bA->m_linearVelocity->y + (bA->m_angularVelocity * r1X));
			HX_STACK_LINE(361)
			v2X = (bB->m_linearVelocity->x + (-(bB->m_angularVelocity) * r2Y));
			HX_STACK_LINE(362)
			v2Y = (bB->m_linearVelocity->y + (bB->m_angularVelocity * r2X));
			HX_STACK_LINE(365)
			Cdot = (-((((this->m_u1->x * v1X) + (this->m_u1->y * v1Y)))) - (this->m_ratio * (((this->m_u2->x * v2X) + (this->m_u2->y * v2Y)))));
			HX_STACK_LINE(366)
			impulse = (this->m_pulleyMass * -(Cdot));
			HX_STACK_LINE(367)
			oldImpulse = this->m_impulse;
			HX_STACK_LINE(368)
			Float _g = ::box2D::common::math::B2Math_obj::max(0.0,(this->m_impulse + impulse));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(368)
			this->m_impulse = _g;
			HX_STACK_LINE(369)
			impulse = (this->m_impulse - oldImpulse);
			HX_STACK_LINE(372)
			P1X = (-(impulse) * this->m_u1->x);
			HX_STACK_LINE(373)
			P1Y = (-(impulse) * this->m_u1->y);
			HX_STACK_LINE(375)
			P2X = ((-(this->m_ratio) * impulse) * this->m_u2->x);
			HX_STACK_LINE(376)
			P2Y = ((-(this->m_ratio) * impulse) * this->m_u2->y);
			HX_STACK_LINE(378)
			hx::AddEq(bA->m_linearVelocity->x,(bA->m_invMass * P1X));
			HX_STACK_LINE(379)
			hx::AddEq(bA->m_linearVelocity->y,(bA->m_invMass * P1Y));
			HX_STACK_LINE(381)
			hx::AddEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * P1Y) - (r1Y * P1X)))));
			HX_STACK_LINE(383)
			hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * P2X));
			HX_STACK_LINE(384)
			hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * P2Y));
			HX_STACK_LINE(386)
			hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * P2Y) - (r2Y * P2X)))));
		}
		HX_STACK_LINE(389)
		if (((this->m_limitState1 == (int)2))){
			HX_STACK_LINE(392)
			v1X = (bA->m_linearVelocity->x + (-(bA->m_angularVelocity) * r1Y));
			HX_STACK_LINE(393)
			v1Y = (bA->m_linearVelocity->y + (bA->m_angularVelocity * r1X));
			HX_STACK_LINE(396)
			Cdot = -((((this->m_u1->x * v1X) + (this->m_u1->y * v1Y))));
			HX_STACK_LINE(397)
			impulse = (-(this->m_limitMass1) * Cdot);
			HX_STACK_LINE(398)
			oldImpulse = this->m_limitImpulse1;
			HX_STACK_LINE(399)
			Float _g1 = ::box2D::common::math::B2Math_obj::max(0.0,(this->m_limitImpulse1 + impulse));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(399)
			this->m_limitImpulse1 = _g1;
			HX_STACK_LINE(400)
			impulse = (this->m_limitImpulse1 - oldImpulse);
			HX_STACK_LINE(403)
			P1X = (-(impulse) * this->m_u1->x);
			HX_STACK_LINE(404)
			P1Y = (-(impulse) * this->m_u1->y);
			HX_STACK_LINE(406)
			hx::AddEq(bA->m_linearVelocity->x,(bA->m_invMass * P1X));
			HX_STACK_LINE(407)
			hx::AddEq(bA->m_linearVelocity->y,(bA->m_invMass * P1Y));
			HX_STACK_LINE(409)
			hx::AddEq(bA->m_angularVelocity,(bA->m_invI * (((r1X * P1Y) - (r1Y * P1X)))));
		}
		HX_STACK_LINE(412)
		if (((this->m_limitState2 == (int)2))){
			HX_STACK_LINE(415)
			v2X = (bB->m_linearVelocity->x + (-(bB->m_angularVelocity) * r2Y));
			HX_STACK_LINE(416)
			v2Y = (bB->m_linearVelocity->y + (bB->m_angularVelocity * r2X));
			HX_STACK_LINE(419)
			Cdot = -((((this->m_u2->x * v2X) + (this->m_u2->y * v2Y))));
			HX_STACK_LINE(420)
			impulse = (-(this->m_limitMass2) * Cdot);
			HX_STACK_LINE(421)
			oldImpulse = this->m_limitImpulse2;
			HX_STACK_LINE(422)
			Float _g2 = ::box2D::common::math::B2Math_obj::max(0.0,(this->m_limitImpulse2 + impulse));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(422)
			this->m_limitImpulse2 = _g2;
			HX_STACK_LINE(423)
			impulse = (this->m_limitImpulse2 - oldImpulse);
			HX_STACK_LINE(426)
			P2X = (-(impulse) * this->m_u2->x);
			HX_STACK_LINE(427)
			P2Y = (-(impulse) * this->m_u2->y);
			HX_STACK_LINE(429)
			hx::AddEq(bB->m_linearVelocity->x,(bB->m_invMass * P2X));
			HX_STACK_LINE(430)
			hx::AddEq(bB->m_linearVelocity->y,(bB->m_invMass * P2Y));
			HX_STACK_LINE(432)
			hx::AddEq(bB->m_angularVelocity,(bB->m_invI * (((r2X * P2Y) - (r2Y * P2X)))));
		}
	}
return null();
}


bool B2PulleyJoint_obj::solvePositionConstraints( Float baumgarte){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJoint","solvePositionConstraints",0xe8495b97,"box2D.dynamics.joints.B2PulleyJoint.solvePositionConstraints","box2D/dynamics/joints/B2PulleyJoint.hx",437,0xce8942fa)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baumgarte,"baumgarte")
	HX_STACK_LINE(440)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(441)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(443)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(446)
	Float s1X = (this->m_ground->m_xf->position->x + this->m_groundAnchor1->x);		HX_STACK_VAR(s1X,"s1X");
	HX_STACK_LINE(447)
	Float s1Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor1->y);		HX_STACK_VAR(s1Y,"s1Y");
	HX_STACK_LINE(449)
	Float s2X = (this->m_ground->m_xf->position->x + this->m_groundAnchor2->x);		HX_STACK_VAR(s2X,"s2X");
	HX_STACK_LINE(450)
	Float s2Y = (this->m_ground->m_xf->position->y + this->m_groundAnchor2->y);		HX_STACK_VAR(s2Y,"s2Y");
	HX_STACK_LINE(453)
	Float r1X;		HX_STACK_VAR(r1X,"r1X");
	HX_STACK_LINE(454)
	Float r1Y;		HX_STACK_VAR(r1Y,"r1Y");
	HX_STACK_LINE(455)
	Float r2X;		HX_STACK_VAR(r2X,"r2X");
	HX_STACK_LINE(456)
	Float r2Y;		HX_STACK_VAR(r2Y,"r2Y");
	HX_STACK_LINE(457)
	Float p1X;		HX_STACK_VAR(p1X,"p1X");
	HX_STACK_LINE(458)
	Float p1Y;		HX_STACK_VAR(p1Y,"p1Y");
	HX_STACK_LINE(459)
	Float p2X;		HX_STACK_VAR(p2X,"p2X");
	HX_STACK_LINE(460)
	Float p2Y;		HX_STACK_VAR(p2Y,"p2Y");
	HX_STACK_LINE(461)
	Float length1;		HX_STACK_VAR(length1,"length1");
	HX_STACK_LINE(462)
	Float length2;		HX_STACK_VAR(length2,"length2");
	HX_STACK_LINE(463)
	Float C;		HX_STACK_VAR(C,"C");
	HX_STACK_LINE(464)
	Float impulse;		HX_STACK_VAR(impulse,"impulse");
	HX_STACK_LINE(465)
	Float oldImpulse;		HX_STACK_VAR(oldImpulse,"oldImpulse");
	HX_STACK_LINE(466)
	Float oldLimitPositionImpulse;		HX_STACK_VAR(oldLimitPositionImpulse,"oldLimitPositionImpulse");
	HX_STACK_LINE(468)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(470)
	Float linearError = 0.0;		HX_STACK_VAR(linearError,"linearError");
	HX_STACK_LINE(472)
	if (((this->m_state == (int)2))){
		HX_STACK_LINE(475)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(476)
		r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_STACK_LINE(477)
		r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_STACK_LINE(478)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_STACK_LINE(479)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_STACK_LINE(480)
		r1X = tX;
		HX_STACK_LINE(482)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(483)
		r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_STACK_LINE(484)
		r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_STACK_LINE(485)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_STACK_LINE(486)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_STACK_LINE(487)
		r2X = tX;
		HX_STACK_LINE(490)
		p1X = (bA->m_sweep->c->x + r1X);
		HX_STACK_LINE(491)
		p1Y = (bA->m_sweep->c->y + r1Y);
		HX_STACK_LINE(493)
		p2X = (bB->m_sweep->c->x + r2X);
		HX_STACK_LINE(494)
		p2Y = (bB->m_sweep->c->y + r2Y);
		HX_STACK_LINE(498)
		this->m_u1->set((p1X - s1X),(p1Y - s1Y));
		HX_STACK_LINE(500)
		this->m_u2->set((p2X - s2X),(p2Y - s2Y));
		HX_STACK_LINE(502)
		Float _g = this->m_u1->length();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(502)
		length1 = _g;
		HX_STACK_LINE(503)
		Float _g1 = this->m_u2->length();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(503)
		length2 = _g1;
		HX_STACK_LINE(505)
		if (((length1 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_STACK_LINE(508)
			this->m_u1->multiply((Float(1.0) / Float(length1)));
		}
		else{
			HX_STACK_LINE(512)
			this->m_u1->setZero();
		}
		HX_STACK_LINE(515)
		if (((length2 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_STACK_LINE(518)
			this->m_u2->multiply((Float(1.0) / Float(length2)));
		}
		else{
			HX_STACK_LINE(522)
			this->m_u2->setZero();
		}
		HX_STACK_LINE(525)
		C = ((this->m_constant - length1) - (this->m_ratio * length2));
		HX_STACK_LINE(526)
		Float _g2 = ::box2D::common::math::B2Math_obj::max(linearError,-(C));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(526)
		linearError = _g2;
		HX_STACK_LINE(527)
		Float _g3 = ::box2D::common::math::B2Math_obj::clamp((C + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(527)
		C = _g3;
		HX_STACK_LINE(528)
		impulse = (-(this->m_pulleyMass) * C);
		HX_STACK_LINE(530)
		p1X = (-(impulse) * this->m_u1->x);
		HX_STACK_LINE(531)
		p1Y = (-(impulse) * this->m_u1->y);
		HX_STACK_LINE(532)
		p2X = ((-(this->m_ratio) * impulse) * this->m_u2->x);
		HX_STACK_LINE(533)
		p2Y = ((-(this->m_ratio) * impulse) * this->m_u2->y);
		HX_STACK_LINE(535)
		hx::AddEq(bA->m_sweep->c->x,(bA->m_invMass * p1X));
		HX_STACK_LINE(536)
		hx::AddEq(bA->m_sweep->c->y,(bA->m_invMass * p1Y));
		HX_STACK_LINE(537)
		hx::AddEq(bA->m_sweep->a,(bA->m_invI * (((r1X * p1Y) - (r1Y * p1X)))));
		HX_STACK_LINE(538)
		hx::AddEq(bB->m_sweep->c->x,(bB->m_invMass * p2X));
		HX_STACK_LINE(539)
		hx::AddEq(bB->m_sweep->c->y,(bB->m_invMass * p2Y));
		HX_STACK_LINE(540)
		hx::AddEq(bB->m_sweep->a,(bB->m_invI * (((r2X * p2Y) - (r2Y * p2X)))));
		HX_STACK_LINE(542)
		bA->synchronizeTransform();
		HX_STACK_LINE(543)
		bB->synchronizeTransform();
	}
	HX_STACK_LINE(546)
	if (((this->m_limitState1 == (int)2))){
		HX_STACK_LINE(549)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(550)
		r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);
		HX_STACK_LINE(551)
		r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);
		HX_STACK_LINE(552)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_STACK_LINE(553)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_STACK_LINE(554)
		r1X = tX;
		HX_STACK_LINE(556)
		p1X = (bA->m_sweep->c->x + r1X);
		HX_STACK_LINE(557)
		p1Y = (bA->m_sweep->c->y + r1Y);
		HX_STACK_LINE(560)
		this->m_u1->set((p1X - s1X),(p1Y - s1Y));
		HX_STACK_LINE(562)
		Float _g4 = this->m_u1->length();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(562)
		length1 = _g4;
		HX_STACK_LINE(564)
		if (((length1 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_STACK_LINE(567)
			hx::MultEq(this->m_u1->x,(Float(1.0) / Float(length1)));
			HX_STACK_LINE(568)
			hx::MultEq(this->m_u1->y,(Float(1.0) / Float(length1)));
		}
		else{
			HX_STACK_LINE(572)
			this->m_u1->setZero();
		}
		HX_STACK_LINE(575)
		C = (this->m_maxLength1 - length1);
		HX_STACK_LINE(576)
		Float _g5 = ::box2D::common::math::B2Math_obj::max(linearError,-(C));		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(576)
		linearError = _g5;
		HX_STACK_LINE(577)
		Float _g6 = ::box2D::common::math::B2Math_obj::clamp((C + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(577)
		C = _g6;
		HX_STACK_LINE(578)
		impulse = (-(this->m_limitMass1) * C);
		HX_STACK_LINE(581)
		p1X = (-(impulse) * this->m_u1->x);
		HX_STACK_LINE(582)
		p1Y = (-(impulse) * this->m_u1->y);
		HX_STACK_LINE(584)
		hx::AddEq(bA->m_sweep->c->x,(bA->m_invMass * p1X));
		HX_STACK_LINE(585)
		hx::AddEq(bA->m_sweep->c->y,(bA->m_invMass * p1Y));
		HX_STACK_LINE(587)
		hx::AddEq(bA->m_sweep->a,(bA->m_invI * (((r1X * p1Y) - (r1Y * p1X)))));
		HX_STACK_LINE(589)
		bA->synchronizeTransform();
	}
	HX_STACK_LINE(592)
	if (((this->m_limitState2 == (int)2))){
		HX_STACK_LINE(595)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(596)
		r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);
		HX_STACK_LINE(597)
		r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);
		HX_STACK_LINE(598)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_STACK_LINE(599)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_STACK_LINE(600)
		r2X = tX;
		HX_STACK_LINE(602)
		p2X = (bB->m_sweep->c->x + r2X);
		HX_STACK_LINE(603)
		p2Y = (bB->m_sweep->c->y + r2Y);
		HX_STACK_LINE(606)
		this->m_u2->set((p2X - s2X),(p2Y - s2Y));
		HX_STACK_LINE(608)
		Float _g7 = this->m_u2->length();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(608)
		length2 = _g7;
		HX_STACK_LINE(610)
		if (((length2 > ::box2D::common::B2Settings_obj::b2_linearSlop))){
			HX_STACK_LINE(613)
			hx::MultEq(this->m_u2->x,(Float(1.0) / Float(length2)));
			HX_STACK_LINE(614)
			hx::MultEq(this->m_u2->y,(Float(1.0) / Float(length2)));
		}
		else{
			HX_STACK_LINE(618)
			this->m_u2->setZero();
		}
		HX_STACK_LINE(621)
		C = (this->m_maxLength2 - length2);
		HX_STACK_LINE(622)
		Float _g8 = ::box2D::common::math::B2Math_obj::max(linearError,-(C));		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(622)
		linearError = _g8;
		HX_STACK_LINE(623)
		Float _g9 = ::box2D::common::math::B2Math_obj::clamp((C + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(623)
		C = _g9;
		HX_STACK_LINE(624)
		impulse = (-(this->m_limitMass2) * C);
		HX_STACK_LINE(627)
		p2X = (-(impulse) * this->m_u2->x);
		HX_STACK_LINE(628)
		p2Y = (-(impulse) * this->m_u2->y);
		HX_STACK_LINE(631)
		hx::AddEq(bB->m_sweep->c->x,(bB->m_invMass * p2X));
		HX_STACK_LINE(632)
		hx::AddEq(bB->m_sweep->c->y,(bB->m_invMass * p2Y));
		HX_STACK_LINE(634)
		hx::AddEq(bB->m_sweep->a,(bB->m_invI * (((r2X * p2Y) - (r2Y * p2X)))));
		HX_STACK_LINE(636)
		bB->synchronizeTransform();
	}
	HX_STACK_LINE(639)
	return (linearError < ::box2D::common::B2Settings_obj::b2_linearSlop);
}


Float B2PulleyJoint_obj::b2_minPulleyLength;


B2PulleyJoint_obj::B2PulleyJoint_obj()
{
}

void B2PulleyJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PulleyJoint);
	HX_MARK_MEMBER_NAME(m_ground,"m_ground");
	HX_MARK_MEMBER_NAME(m_groundAnchor1,"m_groundAnchor1");
	HX_MARK_MEMBER_NAME(m_groundAnchor2,"m_groundAnchor2");
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_u1,"m_u1");
	HX_MARK_MEMBER_NAME(m_u2,"m_u2");
	HX_MARK_MEMBER_NAME(m_constant,"m_constant");
	HX_MARK_MEMBER_NAME(m_ratio,"m_ratio");
	HX_MARK_MEMBER_NAME(m_maxLength1,"m_maxLength1");
	HX_MARK_MEMBER_NAME(m_maxLength2,"m_maxLength2");
	HX_MARK_MEMBER_NAME(m_pulleyMass,"m_pulleyMass");
	HX_MARK_MEMBER_NAME(m_limitMass1,"m_limitMass1");
	HX_MARK_MEMBER_NAME(m_limitMass2,"m_limitMass2");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_limitImpulse1,"m_limitImpulse1");
	HX_MARK_MEMBER_NAME(m_limitImpulse2,"m_limitImpulse2");
	HX_MARK_MEMBER_NAME(m_state,"m_state");
	HX_MARK_MEMBER_NAME(m_limitState1,"m_limitState1");
	HX_MARK_MEMBER_NAME(m_limitState2,"m_limitState2");
	::box2D::dynamics::joints::B2Joint_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2PulleyJoint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_ground,"m_ground");
	HX_VISIT_MEMBER_NAME(m_groundAnchor1,"m_groundAnchor1");
	HX_VISIT_MEMBER_NAME(m_groundAnchor2,"m_groundAnchor2");
	HX_VISIT_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_VISIT_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_VISIT_MEMBER_NAME(m_u1,"m_u1");
	HX_VISIT_MEMBER_NAME(m_u2,"m_u2");
	HX_VISIT_MEMBER_NAME(m_constant,"m_constant");
	HX_VISIT_MEMBER_NAME(m_ratio,"m_ratio");
	HX_VISIT_MEMBER_NAME(m_maxLength1,"m_maxLength1");
	HX_VISIT_MEMBER_NAME(m_maxLength2,"m_maxLength2");
	HX_VISIT_MEMBER_NAME(m_pulleyMass,"m_pulleyMass");
	HX_VISIT_MEMBER_NAME(m_limitMass1,"m_limitMass1");
	HX_VISIT_MEMBER_NAME(m_limitMass2,"m_limitMass2");
	HX_VISIT_MEMBER_NAME(m_impulse,"m_impulse");
	HX_VISIT_MEMBER_NAME(m_limitImpulse1,"m_limitImpulse1");
	HX_VISIT_MEMBER_NAME(m_limitImpulse2,"m_limitImpulse2");
	HX_VISIT_MEMBER_NAME(m_state,"m_state");
	HX_VISIT_MEMBER_NAME(m_limitState1,"m_limitState1");
	HX_VISIT_MEMBER_NAME(m_limitState2,"m_limitState2");
	::box2D::dynamics::joints::B2Joint_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2PulleyJoint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_u1") ) { return m_u1; }
		if (HX_FIELD_EQ(inName,"m_u2") ) { return m_u2; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_ratio") ) { return m_ratio; }
		if (HX_FIELD_EQ(inName,"m_state") ) { return m_state; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getRatio") ) { return getRatio_dyn(); }
		if (HX_FIELD_EQ(inName,"m_ground") ) { return m_ground; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength1") ) { return getLength1_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength2") ) { return getLength2_dyn(); }
		if (HX_FIELD_EQ(inName,"m_constant") ) { return m_constant; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_maxLength1") ) { return m_maxLength1; }
		if (HX_FIELD_EQ(inName,"m_maxLength2") ) { return m_maxLength2; }
		if (HX_FIELD_EQ(inName,"m_pulleyMass") ) { return m_pulleyMass; }
		if (HX_FIELD_EQ(inName,"m_limitMass1") ) { return m_limitMass1; }
		if (HX_FIELD_EQ(inName,"m_limitMass2") ) { return m_limitMass2; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_limitState1") ) { return m_limitState1; }
		if (HX_FIELD_EQ(inName,"m_limitState2") ) { return m_limitState2; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { return m_localAnchor1; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { return m_localAnchor2; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_groundAnchor1") ) { return m_groundAnchor1; }
		if (HX_FIELD_EQ(inName,"m_groundAnchor2") ) { return m_groundAnchor2; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse1") ) { return m_limitImpulse1; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse2") ) { return m_limitImpulse2; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"getGroundAnchorA") ) { return getGroundAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getGroundAnchorB") ) { return getGroundAnchorB_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_minPulleyLength") ) { return b2_minPulleyLength; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"initVelocityConstraints") ) { return initVelocityConstraints_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"solveVelocityConstraints") ) { return solveVelocityConstraints_dyn(); }
		if (HX_FIELD_EQ(inName,"solvePositionConstraints") ) { return solvePositionConstraints_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2PulleyJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_u1") ) { m_u1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_u2") ) { m_u2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_ratio") ) { m_ratio=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_state") ) { m_state=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_ground") ) { m_ground=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_constant") ) { m_constant=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_maxLength1") ) { m_maxLength1=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_maxLength2") ) { m_maxLength2=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_pulleyMass") ) { m_pulleyMass=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitMass1") ) { m_limitMass1=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitMass2") ) { m_limitMass2=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_limitState1") ) { m_limitState1=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitState2") ) { m_limitState2=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { m_localAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { m_localAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_groundAnchor1") ) { m_groundAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_groundAnchor2") ) { m_groundAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse1") ) { m_limitImpulse1=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitImpulse2") ) { m_limitImpulse2=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_minPulleyLength") ) { b2_minPulleyLength=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2PulleyJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_ground"));
	outFields->push(HX_CSTRING("m_groundAnchor1"));
	outFields->push(HX_CSTRING("m_groundAnchor2"));
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_u1"));
	outFields->push(HX_CSTRING("m_u2"));
	outFields->push(HX_CSTRING("m_constant"));
	outFields->push(HX_CSTRING("m_ratio"));
	outFields->push(HX_CSTRING("m_maxLength1"));
	outFields->push(HX_CSTRING("m_maxLength2"));
	outFields->push(HX_CSTRING("m_pulleyMass"));
	outFields->push(HX_CSTRING("m_limitMass1"));
	outFields->push(HX_CSTRING("m_limitMass2"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_limitImpulse1"));
	outFields->push(HX_CSTRING("m_limitImpulse2"));
	outFields->push(HX_CSTRING("m_state"));
	outFields->push(HX_CSTRING("m_limitState1"));
	outFields->push(HX_CSTRING("m_limitState2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_minPulleyLength"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2PulleyJoint_obj,m_ground),HX_CSTRING("m_ground")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJoint_obj,m_groundAnchor1),HX_CSTRING("m_groundAnchor1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJoint_obj,m_groundAnchor2),HX_CSTRING("m_groundAnchor2")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJoint_obj,m_localAnchor1),HX_CSTRING("m_localAnchor1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJoint_obj,m_localAnchor2),HX_CSTRING("m_localAnchor2")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJoint_obj,m_u1),HX_CSTRING("m_u1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJoint_obj,m_u2),HX_CSTRING("m_u2")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_constant),HX_CSTRING("m_constant")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_ratio),HX_CSTRING("m_ratio")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_maxLength1),HX_CSTRING("m_maxLength1")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_maxLength2),HX_CSTRING("m_maxLength2")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_pulleyMass),HX_CSTRING("m_pulleyMass")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_limitMass1),HX_CSTRING("m_limitMass1")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_limitMass2),HX_CSTRING("m_limitMass2")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_impulse),HX_CSTRING("m_impulse")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_limitImpulse1),HX_CSTRING("m_limitImpulse1")},
	{hx::fsFloat,(int)offsetof(B2PulleyJoint_obj,m_limitImpulse2),HX_CSTRING("m_limitImpulse2")},
	{hx::fsInt,(int)offsetof(B2PulleyJoint_obj,m_state),HX_CSTRING("m_state")},
	{hx::fsInt,(int)offsetof(B2PulleyJoint_obj,m_limitState1),HX_CSTRING("m_limitState1")},
	{hx::fsInt,(int)offsetof(B2PulleyJoint_obj,m_limitState2),HX_CSTRING("m_limitState2")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getGroundAnchorA"),
	HX_CSTRING("getGroundAnchorB"),
	HX_CSTRING("getLength1"),
	HX_CSTRING("getLength2"),
	HX_CSTRING("getRatio"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_ground"),
	HX_CSTRING("m_groundAnchor1"),
	HX_CSTRING("m_groundAnchor2"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_u1"),
	HX_CSTRING("m_u2"),
	HX_CSTRING("m_constant"),
	HX_CSTRING("m_ratio"),
	HX_CSTRING("m_maxLength1"),
	HX_CSTRING("m_maxLength2"),
	HX_CSTRING("m_pulleyMass"),
	HX_CSTRING("m_limitMass1"),
	HX_CSTRING("m_limitMass2"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_limitImpulse1"),
	HX_CSTRING("m_limitImpulse2"),
	HX_CSTRING("m_state"),
	HX_CSTRING("m_limitState1"),
	HX_CSTRING("m_limitState2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PulleyJoint_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2PulleyJoint_obj::b2_minPulleyLength,"b2_minPulleyLength");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PulleyJoint_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2PulleyJoint_obj::b2_minPulleyLength,"b2_minPulleyLength");
};

#endif

Class B2PulleyJoint_obj::__mClass;

void B2PulleyJoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PulleyJoint"), hx::TCanCast< B2PulleyJoint_obj> ,sStaticFields,sMemberFields,
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

void B2PulleyJoint_obj::__boot()
{
	b2_minPulleyLength= 2.0;
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
