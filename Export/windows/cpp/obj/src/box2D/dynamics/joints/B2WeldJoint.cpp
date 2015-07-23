#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat33
#include <box2D/common/math/B2Mat33.h>
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
#ifndef INCLUDED_box2D_common_math_B2Vec3
#include <box2D/common/math/B2Vec3.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJoint
#include <box2D/dynamics/joints/B2WeldJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJointDef
#include <box2D/dynamics/joints/B2WeldJointDef.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2WeldJoint_obj::__construct(::box2D::dynamics::joints::B2WeldJointDef def)
{
HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","new",0xa9dd294a,"box2D.dynamics.joints.B2WeldJoint.new","box2D/dynamics/joints/B2WeldJoint.hx",73,0xcc57e947)
HX_STACK_THIS(this)
HX_STACK_ARG(def,"def")
{
	HX_STACK_LINE(74)
	super::__construct(def);
	HX_STACK_LINE(76)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(76)
	this->m_localAnchorA = _g;
	HX_STACK_LINE(77)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(77)
	this->m_localAnchorB = _g1;
	HX_STACK_LINE(78)
	::box2D::common::math::B2Vec3 _g2 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(78)
	this->m_impulse = _g2;
	HX_STACK_LINE(79)
	::box2D::common::math::B2Mat33 _g3 = ::box2D::common::math::B2Mat33_obj::__new(null(),null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(79)
	this->m_mass = _g3;
	HX_STACK_LINE(82)
	this->m_localAnchorA->setV(def->localAnchorA);
	HX_STACK_LINE(83)
	this->m_localAnchorB->setV(def->localAnchorB);
	HX_STACK_LINE(84)
	this->m_referenceAngle = def->referenceAngle;
	HX_STACK_LINE(86)
	this->m_impulse->setZero();
	HX_STACK_LINE(87)
	::box2D::common::math::B2Mat33 _g4 = ::box2D::common::math::B2Mat33_obj::__new(null(),null(),null());		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(87)
	this->m_mass = _g4;
}
;
	return null();
}

//B2WeldJoint_obj::~B2WeldJoint_obj() { }

Dynamic B2WeldJoint_obj::__CreateEmpty() { return  new B2WeldJoint_obj; }
hx::ObjectPtr< B2WeldJoint_obj > B2WeldJoint_obj::__new(::box2D::dynamics::joints::B2WeldJointDef def)
{  hx::ObjectPtr< B2WeldJoint_obj > result = new B2WeldJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2WeldJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2WeldJoint_obj > result = new B2WeldJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2WeldJoint_obj::getAnchorA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","getAnchorA",0x7af16a8c,"box2D.dynamics.joints.B2WeldJoint.getAnchorA","box2D/dynamics/joints/B2WeldJoint.hx",51,0xcc57e947)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	return this->m_bodyA->getWorldPoint(this->m_localAnchorA);
}


::box2D::common::math::B2Vec2 B2WeldJoint_obj::getAnchorB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","getAnchorB",0x7af16a8d,"box2D.dynamics.joints.B2WeldJoint.getAnchorB","box2D/dynamics/joints/B2WeldJoint.hx",55,0xcc57e947)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->m_bodyB->getWorldPoint(this->m_localAnchorB);
}


::box2D::common::math::B2Vec2 B2WeldJoint_obj::getReactionForce( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","getReactionForce",0x1d465be2,"box2D.dynamics.joints.B2WeldJoint.getReactionForce","box2D/dynamics/joints/B2WeldJoint.hx",61,0xcc57e947)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(61)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * this->m_impulse->x),(inv_dt * this->m_impulse->y));
}


Float B2WeldJoint_obj::getReactionTorque( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","getReactionTorque",0x1953c4f3,"box2D.dynamics.joints.B2WeldJoint.getReactionTorque","box2D/dynamics/joints/B2WeldJoint.hx",67,0xcc57e947)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(67)
	return (inv_dt * this->m_impulse->z);
}


Void B2WeldJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","initVelocityConstraints",0xbae20313,"box2D.dynamics.joints.B2WeldJoint.initVelocityConstraints","box2D/dynamics/joints/B2WeldJoint.hx",90,0xcc57e947)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(91)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(92)
		Float tX;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(94)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(95)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(99)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(100)
		Float rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(rAX,"rAX");
		HX_STACK_LINE(101)
		Float rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(rAY,"rAY");
		HX_STACK_LINE(102)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_STACK_LINE(103)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_STACK_LINE(104)
		rAX = tX;
		HX_STACK_LINE(106)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(107)
		Float rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(rBX,"rBX");
		HX_STACK_LINE(108)
		Float rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(rBY,"rBY");
		HX_STACK_LINE(109)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_STACK_LINE(110)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_STACK_LINE(111)
		rBX = tX;
		HX_STACK_LINE(122)
		Float mA = bA->m_invMass;		HX_STACK_VAR(mA,"mA");
		HX_STACK_LINE(123)
		Float mB = bB->m_invMass;		HX_STACK_VAR(mB,"mB");
		HX_STACK_LINE(124)
		Float iA = bA->m_invI;		HX_STACK_VAR(iA,"iA");
		HX_STACK_LINE(125)
		Float iB = bB->m_invI;		HX_STACK_VAR(iB,"iB");
		HX_STACK_LINE(127)
		this->m_mass->col1->x = (((mA + mB) + ((rAY * rAY) * iA)) + ((rBY * rBY) * iB));
		HX_STACK_LINE(128)
		this->m_mass->col2->x = (((-(rAY) * rAX) * iA) - ((rBY * rBX) * iB));
		HX_STACK_LINE(129)
		this->m_mass->col3->x = ((-(rAY) * iA) - (rBY * iB));
		HX_STACK_LINE(130)
		this->m_mass->col1->y = this->m_mass->col2->x;
		HX_STACK_LINE(131)
		this->m_mass->col2->y = (((mA + mB) + ((rAX * rAX) * iA)) + ((rBX * rBX) * iB));
		HX_STACK_LINE(132)
		this->m_mass->col3->y = ((rAX * iA) + (rBX * iB));
		HX_STACK_LINE(133)
		this->m_mass->col1->z = this->m_mass->col3->x;
		HX_STACK_LINE(134)
		this->m_mass->col2->z = this->m_mass->col3->y;
		HX_STACK_LINE(135)
		this->m_mass->col3->z = (iA + iB);
		HX_STACK_LINE(137)
		if ((step->warmStarting)){
			HX_STACK_LINE(140)
			hx::MultEq(this->m_impulse->x,step->dtRatio);
			HX_STACK_LINE(141)
			hx::MultEq(this->m_impulse->y,step->dtRatio);
			HX_STACK_LINE(142)
			hx::MultEq(this->m_impulse->z,step->dtRatio);
			HX_STACK_LINE(144)
			hx::SubEq(bA->m_linearVelocity->x,(mA * this->m_impulse->x));
			HX_STACK_LINE(145)
			hx::SubEq(bA->m_linearVelocity->y,(mA * this->m_impulse->y));
			HX_STACK_LINE(146)
			hx::SubEq(bA->m_angularVelocity,(iA * ((((rAX * this->m_impulse->y) - (rAY * this->m_impulse->x)) + this->m_impulse->z))));
			HX_STACK_LINE(148)
			hx::AddEq(bB->m_linearVelocity->x,(mB * this->m_impulse->x));
			HX_STACK_LINE(149)
			hx::AddEq(bB->m_linearVelocity->y,(mB * this->m_impulse->y));
			HX_STACK_LINE(150)
			hx::AddEq(bB->m_angularVelocity,(iB * ((((rBX * this->m_impulse->y) - (rBY * this->m_impulse->x)) + this->m_impulse->z))));
		}
		else{
			HX_STACK_LINE(154)
			this->m_impulse->setZero();
		}
	}
return null();
}


Void B2WeldJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","solveVelocityConstraints",0x9fa3f8f0,"box2D.dynamics.joints.B2WeldJoint.solveVelocityConstraints","box2D/dynamics/joints/B2WeldJoint.hx",161,0xcc57e947)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(163)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(164)
		Float tX;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(166)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(167)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(169)
		::box2D::common::math::B2Vec2 vA = bA->m_linearVelocity;		HX_STACK_VAR(vA,"vA");
		HX_STACK_LINE(170)
		Float wA = bA->m_angularVelocity;		HX_STACK_VAR(wA,"wA");
		HX_STACK_LINE(171)
		::box2D::common::math::B2Vec2 vB = bB->m_linearVelocity;		HX_STACK_VAR(vB,"vB");
		HX_STACK_LINE(172)
		Float wB = bB->m_angularVelocity;		HX_STACK_VAR(wB,"wB");
		HX_STACK_LINE(174)
		Float mA = bA->m_invMass;		HX_STACK_VAR(mA,"mA");
		HX_STACK_LINE(175)
		Float mB = bB->m_invMass;		HX_STACK_VAR(mB,"mB");
		HX_STACK_LINE(176)
		Float iA = bA->m_invI;		HX_STACK_VAR(iA,"iA");
		HX_STACK_LINE(177)
		Float iB = bB->m_invI;		HX_STACK_VAR(iB,"iB");
		HX_STACK_LINE(180)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(181)
		Float rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(rAX,"rAX");
		HX_STACK_LINE(182)
		Float rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(rAY,"rAY");
		HX_STACK_LINE(183)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_STACK_LINE(184)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_STACK_LINE(185)
		rAX = tX;
		HX_STACK_LINE(187)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(188)
		Float rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(rBX,"rBX");
		HX_STACK_LINE(189)
		Float rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(rBY,"rBY");
		HX_STACK_LINE(190)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_STACK_LINE(191)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_STACK_LINE(192)
		rBX = tX;
		HX_STACK_LINE(196)
		Float Cdot1X = (((vB->x - (wB * rBY)) - vA->x) + (wA * rAY));		HX_STACK_VAR(Cdot1X,"Cdot1X");
		HX_STACK_LINE(197)
		Float Cdot1Y = (((vB->y + (wB * rBX)) - vA->y) - (wA * rAX));		HX_STACK_VAR(Cdot1Y,"Cdot1Y");
		HX_STACK_LINE(198)
		Float Cdot2 = (wB - wA);		HX_STACK_VAR(Cdot2,"Cdot2");
		HX_STACK_LINE(199)
		::box2D::common::math::B2Vec3 impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(impulse,"impulse");
		HX_STACK_LINE(200)
		this->m_mass->solve33(impulse,-(Cdot1X),-(Cdot1Y),-(Cdot2));
		HX_STACK_LINE(202)
		this->m_impulse->add(impulse);
		HX_STACK_LINE(204)
		hx::SubEq(vA->x,(mA * impulse->x));
		HX_STACK_LINE(205)
		hx::SubEq(vA->y,(mA * impulse->y));
		HX_STACK_LINE(206)
		hx::SubEq(wA,(iA * ((((rAX * impulse->y) - (rAY * impulse->x)) + impulse->z))));
		HX_STACK_LINE(208)
		hx::AddEq(vB->x,(mB * impulse->x));
		HX_STACK_LINE(209)
		hx::AddEq(vB->y,(mB * impulse->y));
		HX_STACK_LINE(210)
		hx::AddEq(wB,(iB * ((((rBX * impulse->y) - (rBY * impulse->x)) + impulse->z))));
		HX_STACK_LINE(214)
		bA->m_angularVelocity = wA;
		HX_STACK_LINE(216)
		bB->m_angularVelocity = wB;
	}
return null();
}


bool B2WeldJoint_obj::solvePositionConstraints( Float baumgarte){
	HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJoint","solvePositionConstraints",0xd7800de4,"box2D.dynamics.joints.B2WeldJoint.solvePositionConstraints","box2D/dynamics/joints/B2WeldJoint.hx",221,0xcc57e947)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baumgarte,"baumgarte")
	HX_STACK_LINE(223)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(224)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(226)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(227)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(231)
	tMat = bA->m_xf->R;
	HX_STACK_LINE(232)
	Float rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(rAX,"rAX");
	HX_STACK_LINE(233)
	Float rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(rAY,"rAY");
	HX_STACK_LINE(234)
	tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
	HX_STACK_LINE(235)
	rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
	HX_STACK_LINE(236)
	rAX = tX;
	HX_STACK_LINE(238)
	tMat = bB->m_xf->R;
	HX_STACK_LINE(239)
	Float rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(rBX,"rBX");
	HX_STACK_LINE(240)
	Float rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(rBY,"rBY");
	HX_STACK_LINE(241)
	tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
	HX_STACK_LINE(242)
	rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
	HX_STACK_LINE(243)
	rBX = tX;
	HX_STACK_LINE(254)
	Float mA = bA->m_invMass;		HX_STACK_VAR(mA,"mA");
	HX_STACK_LINE(255)
	Float mB = bB->m_invMass;		HX_STACK_VAR(mB,"mB");
	HX_STACK_LINE(256)
	Float iA = bA->m_invI;		HX_STACK_VAR(iA,"iA");
	HX_STACK_LINE(257)
	Float iB = bB->m_invI;		HX_STACK_VAR(iB,"iB");
	HX_STACK_LINE(260)
	Float C1X = (((bB->m_sweep->c->x + rBX) - bA->m_sweep->c->x) - rAX);		HX_STACK_VAR(C1X,"C1X");
	HX_STACK_LINE(261)
	Float C1Y = (((bB->m_sweep->c->y + rBY) - bA->m_sweep->c->y) - rAY);		HX_STACK_VAR(C1Y,"C1Y");
	HX_STACK_LINE(262)
	Float C2 = ((bB->m_sweep->a - bA->m_sweep->a) - this->m_referenceAngle);		HX_STACK_VAR(C2,"C2");
	HX_STACK_LINE(265)
	Float k_allowedStretch = (10.0 * ::box2D::common::B2Settings_obj::b2_linearSlop);		HX_STACK_VAR(k_allowedStretch,"k_allowedStretch");
	HX_STACK_LINE(266)
	Float positionError = ::Math_obj::sqrt(((C1X * C1X) + (C1Y * C1Y)));		HX_STACK_VAR(positionError,"positionError");
	HX_STACK_LINE(267)
	Float angularError = ::box2D::common::math::B2Math_obj::abs(C2);		HX_STACK_VAR(angularError,"angularError");
	HX_STACK_LINE(268)
	if (((positionError > k_allowedStretch))){
		HX_STACK_LINE(270)
		hx::MultEq(iA,1.0);
		HX_STACK_LINE(271)
		hx::MultEq(iB,1.0);
	}
	HX_STACK_LINE(274)
	this->m_mass->col1->x = (((mA + mB) + ((rAY * rAY) * iA)) + ((rBY * rBY) * iB));
	HX_STACK_LINE(275)
	this->m_mass->col2->x = (((-(rAY) * rAX) * iA) - ((rBY * rBX) * iB));
	HX_STACK_LINE(276)
	this->m_mass->col3->x = ((-(rAY) * iA) - (rBY * iB));
	HX_STACK_LINE(277)
	this->m_mass->col1->y = this->m_mass->col2->x;
	HX_STACK_LINE(278)
	this->m_mass->col2->y = (((mA + mB) + ((rAX * rAX) * iA)) + ((rBX * rBX) * iB));
	HX_STACK_LINE(279)
	this->m_mass->col3->y = ((rAX * iA) + (rBX * iB));
	HX_STACK_LINE(280)
	this->m_mass->col1->z = this->m_mass->col3->x;
	HX_STACK_LINE(281)
	this->m_mass->col2->z = this->m_mass->col3->y;
	HX_STACK_LINE(282)
	this->m_mass->col3->z = (iA + iB);
	HX_STACK_LINE(284)
	::box2D::common::math::B2Vec3 impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(impulse,"impulse");
	HX_STACK_LINE(285)
	this->m_mass->solve33(impulse,-(C1X),-(C1Y),-(C2));
	HX_STACK_LINE(288)
	hx::SubEq(bA->m_sweep->c->x,(mA * impulse->x));
	HX_STACK_LINE(289)
	hx::SubEq(bA->m_sweep->c->y,(mA * impulse->y));
	HX_STACK_LINE(290)
	hx::SubEq(bA->m_sweep->a,(iA * ((((rAX * impulse->y) - (rAY * impulse->x)) + impulse->z))));
	HX_STACK_LINE(292)
	hx::AddEq(bB->m_sweep->c->x,(mB * impulse->x));
	HX_STACK_LINE(293)
	hx::AddEq(bB->m_sweep->c->y,(mB * impulse->y));
	HX_STACK_LINE(294)
	hx::AddEq(bB->m_sweep->a,(iB * ((((rBX * impulse->y) - (rBY * impulse->x)) + impulse->z))));
	HX_STACK_LINE(296)
	bA->synchronizeTransform();
	HX_STACK_LINE(297)
	bB->synchronizeTransform();
	HX_STACK_LINE(299)
	return (bool((positionError <= ::box2D::common::B2Settings_obj::b2_linearSlop)) && bool((angularError <= ::box2D::common::B2Settings_obj::b2_angularSlop)));
}



B2WeldJoint_obj::B2WeldJoint_obj()
{
}

void B2WeldJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2WeldJoint);
	HX_MARK_MEMBER_NAME(m_localAnchorA,"m_localAnchorA");
	HX_MARK_MEMBER_NAME(m_localAnchorB,"m_localAnchorB");
	HX_MARK_MEMBER_NAME(m_referenceAngle,"m_referenceAngle");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	::box2D::dynamics::joints::B2Joint_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2WeldJoint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_localAnchorA,"m_localAnchorA");
	HX_VISIT_MEMBER_NAME(m_localAnchorB,"m_localAnchorB");
	HX_VISIT_MEMBER_NAME(m_referenceAngle,"m_referenceAngle");
	HX_VISIT_MEMBER_NAME(m_impulse,"m_impulse");
	HX_VISIT_MEMBER_NAME(m_mass,"m_mass");
	::box2D::dynamics::joints::B2Joint_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2WeldJoint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { return m_localAnchorA; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { return m_localAnchorB; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_referenceAngle") ) { return m_referenceAngle; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
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

Dynamic B2WeldJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< ::box2D::common::math::B2Mat33 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { m_localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { m_localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_referenceAngle") ) { m_referenceAngle=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2WeldJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchorA"));
	outFields->push(HX_CSTRING("m_localAnchorB"));
	outFields->push(HX_CSTRING("m_referenceAngle"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_mass"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2WeldJoint_obj,m_localAnchorA),HX_CSTRING("m_localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2WeldJoint_obj,m_localAnchorB),HX_CSTRING("m_localAnchorB")},
	{hx::fsFloat,(int)offsetof(B2WeldJoint_obj,m_referenceAngle),HX_CSTRING("m_referenceAngle")},
	{hx::fsObject /*::box2D::common::math::B2Vec3*/ ,(int)offsetof(B2WeldJoint_obj,m_impulse),HX_CSTRING("m_impulse")},
	{hx::fsObject /*::box2D::common::math::B2Mat33*/ ,(int)offsetof(B2WeldJoint_obj,m_mass),HX_CSTRING("m_mass")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchorA"),
	HX_CSTRING("m_localAnchorB"),
	HX_CSTRING("m_referenceAngle"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_mass"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2WeldJoint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2WeldJoint_obj::__mClass,"__mClass");
};

#endif

Class B2WeldJoint_obj::__mClass;

void B2WeldJoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2WeldJoint"), hx::TCanCast< B2WeldJoint_obj> ,sStaticFields,sMemberFields,
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

void B2WeldJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
