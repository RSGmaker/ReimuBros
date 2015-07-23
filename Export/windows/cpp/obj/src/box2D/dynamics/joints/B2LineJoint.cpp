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
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJoint
#include <box2D/dynamics/joints/B2LineJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJointDef
#include <box2D/dynamics/joints/B2LineJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2LineJoint_obj::__construct(::box2D::dynamics::joints::B2LineJointDef def)
{
HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","new",0x739cc99c,"box2D.dynamics.joints.B2LineJoint.new","box2D/dynamics/joints/B2LineJoint.hx",297,0x501e3935)
HX_STACK_THIS(this)
HX_STACK_ARG(def,"def")
{
	HX_STACK_LINE(298)
	super::__construct(def);
	HX_STACK_LINE(300)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(300)
	this->m_localAnchor1 = _g;
	HX_STACK_LINE(301)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(301)
	this->m_localAnchor2 = _g1;
	HX_STACK_LINE(302)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(302)
	this->m_localXAxis1 = _g2;
	HX_STACK_LINE(303)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(303)
	this->m_localYAxis1 = _g3;
	HX_STACK_LINE(305)
	::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(305)
	this->m_axis = _g4;
	HX_STACK_LINE(306)
	::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(306)
	this->m_perp = _g5;
	HX_STACK_LINE(308)
	::box2D::common::math::B2Mat22 _g6 = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(308)
	this->m_K = _g6;
	HX_STACK_LINE(309)
	::box2D::common::math::B2Vec2 _g7 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(309)
	this->m_impulse = _g7;
	HX_STACK_LINE(312)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(313)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(314)
	Float tY;		HX_STACK_VAR(tY,"tY");
	HX_STACK_LINE(316)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_STACK_LINE(317)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_STACK_LINE(318)
	this->m_localXAxis1->setV(def->localAxisA);
	HX_STACK_LINE(321)
	this->m_localYAxis1->x = -(this->m_localXAxis1->y);
	HX_STACK_LINE(322)
	this->m_localYAxis1->y = this->m_localXAxis1->x;
	HX_STACK_LINE(324)
	this->m_impulse->setZero();
	HX_STACK_LINE(325)
	this->m_motorMass = 0.0;
	HX_STACK_LINE(326)
	this->m_motorImpulse = 0.0;
	HX_STACK_LINE(328)
	this->m_lowerTranslation = def->lowerTranslation;
	HX_STACK_LINE(329)
	this->m_upperTranslation = def->upperTranslation;
	HX_STACK_LINE(330)
	this->m_maxMotorForce = def->maxMotorForce;
	HX_STACK_LINE(331)
	this->m_motorSpeed = def->motorSpeed;
	HX_STACK_LINE(332)
	this->m_enableLimit = def->enableLimit;
	HX_STACK_LINE(333)
	this->m_enableMotor = def->enableMotor;
	HX_STACK_LINE(334)
	this->m_limitState = (int)0;
	HX_STACK_LINE(336)
	this->m_axis->setZero();
	HX_STACK_LINE(337)
	this->m_perp->setZero();
}
;
	return null();
}

//B2LineJoint_obj::~B2LineJoint_obj() { }

Dynamic B2LineJoint_obj::__CreateEmpty() { return  new B2LineJoint_obj; }
hx::ObjectPtr< B2LineJoint_obj > B2LineJoint_obj::__new(::box2D::dynamics::joints::B2LineJointDef def)
{  hx::ObjectPtr< B2LineJoint_obj > result = new B2LineJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2LineJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2LineJoint_obj > result = new B2LineJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2LineJoint_obj::getAnchorA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getAnchorA",0xd08e587a,"box2D.dynamics.joints.B2LineJoint.getAnchorA","box2D/dynamics/joints/B2LineJoint.hx",102,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(102)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


::box2D::common::math::B2Vec2 B2LineJoint_obj::getAnchorB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getAnchorB",0xd08e587b,"box2D.dynamics.joints.B2LineJoint.getAnchorB","box2D/dynamics/joints/B2LineJoint.hx",106,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(106)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


::box2D::common::math::B2Vec2 B2LineJoint_obj::getReactionForce( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getReactionForce",0x97c77050,"box2D.dynamics.joints.B2LineJoint.getReactionForce","box2D/dynamics/joints/B2LineJoint.hx",112,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(112)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * (((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->x)))),(inv_dt * (((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->y)))));
}


Float B2LineJoint_obj::getReactionTorque( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getReactionTorque",0xcfc490c5,"box2D.dynamics.joints.B2LineJoint.getReactionTorque","box2D/dynamics/joints/B2LineJoint.hx",119,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(119)
	return (inv_dt * this->m_impulse->y);
}


Float B2LineJoint_obj::getJointTranslation( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getJointTranslation",0x344179b9,"box2D.dynamics.joints.B2LineJoint.getJointTranslation","box2D/dynamics/joints/B2LineJoint.hx",125,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(126)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(127)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(129)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(131)
	::box2D::common::math::B2Vec2 p1 = bA->getWorldPoint(this->m_localAnchor1);		HX_STACK_VAR(p1,"p1");
	HX_STACK_LINE(132)
	::box2D::common::math::B2Vec2 p2 = bB->getWorldPoint(this->m_localAnchor2);		HX_STACK_VAR(p2,"p2");
	HX_STACK_LINE(134)
	Float dX = (p2->x - p1->x);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(135)
	Float dY = (p2->y - p1->y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(137)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);		HX_STACK_VAR(axis,"axis");
	HX_STACK_LINE(140)
	Float translation = ((axis->x * dX) + (axis->y * dY));		HX_STACK_VAR(translation,"translation");
	HX_STACK_LINE(141)
	return translation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getJointTranslation,return )

Float B2LineJoint_obj::getJointSpeed( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getJointSpeed",0x23969a4f,"box2D.dynamics.joints.B2LineJoint.getJointSpeed","box2D/dynamics/joints/B2LineJoint.hx",147,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(148)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(149)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(151)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(154)
	tMat = bA->m_xf->R;
	HX_STACK_LINE(155)
	Float r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(r1X,"r1X");
	HX_STACK_LINE(156)
	Float r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(r1Y,"r1Y");
	HX_STACK_LINE(157)
	Float tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(158)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_STACK_LINE(159)
	r1X = tX;
	HX_STACK_LINE(161)
	tMat = bB->m_xf->R;
	HX_STACK_LINE(162)
	Float r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(r2X,"r2X");
	HX_STACK_LINE(163)
	Float r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(r2Y,"r2Y");
	HX_STACK_LINE(164)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_STACK_LINE(165)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_STACK_LINE(166)
	r2X = tX;
	HX_STACK_LINE(169)
	Float p1X = (bA->m_sweep->c->x + r1X);		HX_STACK_VAR(p1X,"p1X");
	HX_STACK_LINE(170)
	Float p1Y = (bA->m_sweep->c->y + r1Y);		HX_STACK_VAR(p1Y,"p1Y");
	HX_STACK_LINE(172)
	Float p2X = (bB->m_sweep->c->x + r2X);		HX_STACK_VAR(p2X,"p2X");
	HX_STACK_LINE(173)
	Float p2Y = (bB->m_sweep->c->y + r2Y);		HX_STACK_VAR(p2Y,"p2Y");
	HX_STACK_LINE(175)
	Float dX = (p2X - p1X);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(176)
	Float dY = (p2Y - p1Y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(178)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);		HX_STACK_VAR(axis,"axis");
	HX_STACK_LINE(180)
	::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;		HX_STACK_VAR(v1,"v1");
	HX_STACK_LINE(181)
	::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;		HX_STACK_VAR(v2,"v2");
	HX_STACK_LINE(182)
	Float w1 = bA->m_angularVelocity;		HX_STACK_VAR(w1,"w1");
	HX_STACK_LINE(183)
	Float w2 = bB->m_angularVelocity;		HX_STACK_VAR(w2,"w2");
	HX_STACK_LINE(188)
	Float speed = (((dX * ((-(w1) * axis->y))) + (dY * ((w1 * axis->x)))) + (((axis->x * ((((v2->x + (-(w2) * r2Y)) - v1->x) - (-(w1) * r1Y)))) + (axis->y * ((((v2->y + (w2 * r2X)) - v1->y) - (w1 * r1X)))))));		HX_STACK_VAR(speed,"speed");
	HX_STACK_LINE(190)
	return speed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getJointSpeed,return )

bool B2LineJoint_obj::isLimitEnabled( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","isLimitEnabled",0x05ea71d4,"box2D.dynamics.joints.B2LineJoint.isLimitEnabled","box2D/dynamics/joints/B2LineJoint.hx",198,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(198)
	return this->m_enableLimit;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,isLimitEnabled,return )

Void B2LineJoint_obj::enableLimit( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","enableLimit",0x7acefaf4,"box2D.dynamics.joints.B2LineJoint.enableLimit","box2D/dynamics/joints/B2LineJoint.hx",204,0x501e3935)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(205)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(206)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(207)
		this->m_enableLimit = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,enableLimit,(void))

Float B2LineJoint_obj::getLowerLimit( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getLowerLimit",0x758d69ec,"box2D.dynamics.joints.B2LineJoint.getLowerLimit","box2D/dynamics/joints/B2LineJoint.hx",214,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(214)
	return this->m_lowerTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getLowerLimit,return )

Float B2LineJoint_obj::getUpperLimit( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getUpperLimit",0x7abbeaeb,"box2D.dynamics.joints.B2LineJoint.getUpperLimit","box2D/dynamics/joints/B2LineJoint.hx",221,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(221)
	return this->m_upperTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getUpperLimit,return )

Void B2LineJoint_obj::setLimits( Float lower,Float upper){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","setLimits",0x84733856,"box2D.dynamics.joints.B2LineJoint.setLimits","box2D/dynamics/joints/B2LineJoint.hx",227,0x501e3935)
		HX_STACK_THIS(this)
		HX_STACK_ARG(lower,"lower")
		HX_STACK_ARG(upper,"upper")
		HX_STACK_LINE(229)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(230)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(231)
		this->m_lowerTranslation = lower;
		HX_STACK_LINE(232)
		this->m_upperTranslation = upper;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2LineJoint_obj,setLimits,(void))

bool B2LineJoint_obj::isMotorEnabled( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","isMotorEnabled",0x0e2d3bda,"box2D.dynamics.joints.B2LineJoint.isMotorEnabled","box2D/dynamics/joints/B2LineJoint.hx",239,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(239)
	return this->m_enableMotor;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,isMotorEnabled,return )

Void B2LineJoint_obj::enableMotor( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","enableMotor",0x12322c2e,"box2D.dynamics.joints.B2LineJoint.enableMotor","box2D/dynamics/joints/B2LineJoint.hx",245,0x501e3935)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(246)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(247)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(248)
		this->m_enableMotor = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,enableMotor,(void))

Void B2LineJoint_obj::setMotorSpeed( Float speed){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","setMotorSpeed",0x7b858950,"box2D.dynamics.joints.B2LineJoint.setMotorSpeed","box2D/dynamics/joints/B2LineJoint.hx",254,0x501e3935)
		HX_STACK_THIS(this)
		HX_STACK_ARG(speed,"speed")
		HX_STACK_LINE(255)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(256)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(257)
		this->m_motorSpeed = speed;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,setMotorSpeed,(void))

Float B2LineJoint_obj::getMotorSpeed( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getMotorSpeed",0x367fa744,"box2D.dynamics.joints.B2LineJoint.getMotorSpeed","box2D/dynamics/joints/B2LineJoint.hx",264,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(264)
	return this->m_motorSpeed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getMotorSpeed,return )

Void B2LineJoint_obj::setMaxMotorForce( Float force){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","setMaxMotorForce",0x87bfd53c,"box2D.dynamics.joints.B2LineJoint.setMaxMotorForce","box2D/dynamics/joints/B2LineJoint.hx",271,0x501e3935)
		HX_STACK_THIS(this)
		HX_STACK_ARG(force,"force")
		HX_STACK_LINE(272)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(273)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(274)
		this->m_maxMotorForce = force;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2LineJoint_obj,setMaxMotorForce,(void))

Float B2LineJoint_obj::getMaxMotorForce( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getMaxMotorForce",0x317de7c8,"box2D.dynamics.joints.B2LineJoint.getMaxMotorForce","box2D/dynamics/joints/B2LineJoint.hx",282,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(282)
	return this->m_maxMotorForce;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getMaxMotorForce,return )

Float B2LineJoint_obj::getMotorForce( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","getMotorForce",0xb9aac1a8,"box2D.dynamics.joints.B2LineJoint.getMotorForce","box2D/dynamics/joints/B2LineJoint.hx",290,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_LINE(290)
	return this->m_motorImpulse;
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJoint_obj,getMotorForce,return )

Void B2LineJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","initVelocityConstraints",0x87187865,"box2D.dynamics.joints.B2LineJoint.initVelocityConstraints","box2D/dynamics/joints/B2LineJoint.hx",340,0x501e3935)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(341)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(342)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(344)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(345)
		Float tX;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(347)
		::box2D::common::math::B2Vec2 _g = bA->getLocalCenter();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(347)
		this->m_localCenterA->setV(_g);
		HX_STACK_LINE(348)
		::box2D::common::math::B2Vec2 _g1 = bB->getLocalCenter();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(348)
		this->m_localCenterB->setV(_g1);
		HX_STACK_LINE(350)
		::box2D::common::math::B2Transform xf1 = bA->getTransform();		HX_STACK_VAR(xf1,"xf1");
		HX_STACK_LINE(351)
		::box2D::common::math::B2Transform xf2 = bB->getTransform();		HX_STACK_VAR(xf2,"xf2");
		HX_STACK_LINE(355)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(356)
		Float r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);		HX_STACK_VAR(r1X,"r1X");
		HX_STACK_LINE(357)
		Float r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);		HX_STACK_VAR(r1Y,"r1Y");
		HX_STACK_LINE(358)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_STACK_LINE(359)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_STACK_LINE(360)
		r1X = tX;
		HX_STACK_LINE(362)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(363)
		Float r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);		HX_STACK_VAR(r2X,"r2X");
		HX_STACK_LINE(364)
		Float r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);		HX_STACK_VAR(r2Y,"r2Y");
		HX_STACK_LINE(365)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_STACK_LINE(366)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_STACK_LINE(367)
		r2X = tX;
		HX_STACK_LINE(370)
		Float dX = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);		HX_STACK_VAR(dX,"dX");
		HX_STACK_LINE(371)
		Float dY = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);		HX_STACK_VAR(dY,"dY");
		HX_STACK_LINE(373)
		this->m_invMassA = bA->m_invMass;
		HX_STACK_LINE(374)
		this->m_invMassB = bB->m_invMass;
		HX_STACK_LINE(375)
		this->m_invIA = bA->m_invI;
		HX_STACK_LINE(376)
		this->m_invIB = bB->m_invI;
		HX_STACK_LINE(379)
		{
			HX_STACK_LINE(380)
			::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Math_obj::mulMV(xf1->R,this->m_localXAxis1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(380)
			this->m_axis->setV(_g2);
			HX_STACK_LINE(382)
			this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
			HX_STACK_LINE(384)
			this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
			HX_STACK_LINE(386)
			this->m_motorMass = (((this->m_invMassA + this->m_invMassB) + ((this->m_invIA * this->m_a1) * this->m_a1)) + ((this->m_invIB * this->m_a2) * this->m_a2));
			HX_STACK_LINE(387)
			if (((this->m_motorMass > 2.2250738585072014e-308))){
				HX_STACK_LINE(387)
				this->m_motorMass = (Float(1.0) / Float(this->m_motorMass));
			}
			else{
				HX_STACK_LINE(387)
				this->m_motorMass = 0.0;
			}
		}
		HX_STACK_LINE(391)
		{
			HX_STACK_LINE(392)
			::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::mulMV(xf1->R,this->m_localYAxis1);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(392)
			this->m_perp->setV(_g3);
			HX_STACK_LINE(394)
			this->m_s1 = ((((dX + r1X)) * this->m_perp->y) - (((dY + r1Y)) * this->m_perp->x));
			HX_STACK_LINE(396)
			this->m_s2 = ((r2X * this->m_perp->y) - (r2Y * this->m_perp->x));
			HX_STACK_LINE(398)
			Float m1 = this->m_invMassA;		HX_STACK_VAR(m1,"m1");
			HX_STACK_LINE(399)
			Float m2 = this->m_invMassB;		HX_STACK_VAR(m2,"m2");
			HX_STACK_LINE(400)
			Float i1 = this->m_invIA;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(401)
			Float i2 = this->m_invIB;		HX_STACK_VAR(i2,"i2");
			HX_STACK_LINE(403)
			this->m_K->col1->x = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
			HX_STACK_LINE(404)
			this->m_K->col1->y = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
			HX_STACK_LINE(405)
			this->m_K->col2->x = this->m_K->col1->y;
			HX_STACK_LINE(406)
			this->m_K->col2->y = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		}
		HX_STACK_LINE(410)
		if ((this->m_enableLimit)){
			HX_STACK_LINE(413)
			Float jointTransition = ((this->m_axis->x * dX) + (this->m_axis->y * dY));		HX_STACK_VAR(jointTransition,"jointTransition");
			HX_STACK_LINE(414)
			Float _g4 = ::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(414)
			if (((_g4 < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
				HX_STACK_LINE(416)
				this->m_limitState = (int)3;
			}
			else{
				HX_STACK_LINE(418)
				if (((jointTransition <= this->m_lowerTranslation))){
					HX_STACK_LINE(420)
					if (((this->m_limitState != (int)1))){
						HX_STACK_LINE(422)
						this->m_limitState = (int)1;
						HX_STACK_LINE(423)
						this->m_impulse->y = 0.0;
					}
				}
				else{
					HX_STACK_LINE(426)
					if (((jointTransition >= this->m_upperTranslation))){
						HX_STACK_LINE(428)
						if (((this->m_limitState != (int)2))){
							HX_STACK_LINE(430)
							this->m_limitState = (int)2;
							HX_STACK_LINE(431)
							this->m_impulse->y = 0.0;
						}
					}
					else{
						HX_STACK_LINE(436)
						this->m_limitState = (int)0;
						HX_STACK_LINE(437)
						this->m_impulse->y = 0.0;
					}
				}
			}
		}
		else{
			HX_STACK_LINE(442)
			this->m_limitState = (int)0;
		}
		HX_STACK_LINE(445)
		if (((this->m_enableMotor == false))){
			HX_STACK_LINE(447)
			this->m_motorImpulse = 0.0;
		}
		HX_STACK_LINE(450)
		if ((step->warmStarting)){
			HX_STACK_LINE(453)
			hx::MultEq(this->m_impulse->x,step->dtRatio);
			HX_STACK_LINE(454)
			hx::MultEq(this->m_impulse->y,step->dtRatio);
			HX_STACK_LINE(455)
			hx::MultEq(this->m_motorImpulse,step->dtRatio);
			HX_STACK_LINE(458)
			Float PX = ((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->x));		HX_STACK_VAR(PX,"PX");
			HX_STACK_LINE(459)
			Float PY = ((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_axis->y));		HX_STACK_VAR(PY,"PY");
			HX_STACK_LINE(460)
			Float L1 = ((this->m_impulse->x * this->m_s1) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_a1));		HX_STACK_VAR(L1,"L1");
			HX_STACK_LINE(461)
			Float L2 = ((this->m_impulse->x * this->m_s2) + (((this->m_motorImpulse + this->m_impulse->y)) * this->m_a2));		HX_STACK_VAR(L2,"L2");
			HX_STACK_LINE(464)
			hx::SubEq(bA->m_linearVelocity->x,(this->m_invMassA * PX));
			HX_STACK_LINE(465)
			hx::SubEq(bA->m_linearVelocity->y,(this->m_invMassA * PY));
			HX_STACK_LINE(467)
			hx::SubEq(bA->m_angularVelocity,(this->m_invIA * L1));
			HX_STACK_LINE(470)
			hx::AddEq(bB->m_linearVelocity->x,(this->m_invMassB * PX));
			HX_STACK_LINE(471)
			hx::AddEq(bB->m_linearVelocity->y,(this->m_invMassB * PY));
			HX_STACK_LINE(473)
			hx::AddEq(bB->m_angularVelocity,(this->m_invIB * L2));
		}
		else{
			HX_STACK_LINE(477)
			this->m_impulse->setZero();
			HX_STACK_LINE(478)
			this->m_motorImpulse = 0.0;
		}
	}
return null();
}


Void B2LineJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","solveVelocityConstraints",0x83142b5e,"box2D.dynamics.joints.B2LineJoint.solveVelocityConstraints","box2D/dynamics/joints/B2LineJoint.hx",482,0x501e3935)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(483)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(484)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(486)
		::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(487)
		Float w1 = bA->m_angularVelocity;		HX_STACK_VAR(w1,"w1");
		HX_STACK_LINE(488)
		::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(489)
		Float w2 = bB->m_angularVelocity;		HX_STACK_VAR(w2,"w2");
		HX_STACK_LINE(491)
		Float PX;		HX_STACK_VAR(PX,"PX");
		HX_STACK_LINE(492)
		Float PY;		HX_STACK_VAR(PY,"PY");
		HX_STACK_LINE(493)
		Float L1;		HX_STACK_VAR(L1,"L1");
		HX_STACK_LINE(494)
		Float L2;		HX_STACK_VAR(L2,"L2");
		HX_STACK_LINE(497)
		if (((bool(this->m_enableMotor) && bool((this->m_limitState != (int)3))))){
			HX_STACK_LINE(500)
			Float Cdot = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));		HX_STACK_VAR(Cdot,"Cdot");
			HX_STACK_LINE(501)
			Float impulse = (this->m_motorMass * ((this->m_motorSpeed - Cdot)));		HX_STACK_VAR(impulse,"impulse");
			HX_STACK_LINE(502)
			Float oldImpulse = this->m_motorImpulse;		HX_STACK_VAR(oldImpulse,"oldImpulse");
			HX_STACK_LINE(503)
			Float maxImpulse = (step->dt * this->m_maxMotorForce);		HX_STACK_VAR(maxImpulse,"maxImpulse");
			HX_STACK_LINE(504)
			Float _g = ::box2D::common::math::B2Math_obj::clamp((this->m_motorImpulse + impulse),-(maxImpulse),maxImpulse);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(504)
			this->m_motorImpulse = _g;
			HX_STACK_LINE(505)
			impulse = (this->m_motorImpulse - oldImpulse);
			HX_STACK_LINE(507)
			PX = (impulse * this->m_axis->x);
			HX_STACK_LINE(508)
			PY = (impulse * this->m_axis->y);
			HX_STACK_LINE(509)
			L1 = (impulse * this->m_a1);
			HX_STACK_LINE(510)
			L2 = (impulse * this->m_a2);
			HX_STACK_LINE(512)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_STACK_LINE(513)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_STACK_LINE(514)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_STACK_LINE(516)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_STACK_LINE(517)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_STACK_LINE(518)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_STACK_LINE(522)
		Float Cdot1 = ((((this->m_perp->x * ((v2->x - v1->x))) + (this->m_perp->y * ((v2->y - v1->y)))) + (this->m_s2 * w2)) - (this->m_s1 * w1));		HX_STACK_VAR(Cdot1,"Cdot1");
		HX_STACK_LINE(524)
		if (((bool(this->m_enableLimit) && bool((this->m_limitState != (int)0))))){
			HX_STACK_LINE(528)
			Float Cdot2 = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));		HX_STACK_VAR(Cdot2,"Cdot2");
			HX_STACK_LINE(530)
			::box2D::common::math::B2Vec2 f1 = this->m_impulse->copy();		HX_STACK_VAR(f1,"f1");
			HX_STACK_LINE(531)
			::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(531)
			::box2D::common::math::B2Vec2 df = this->m_K->solve(_g1,-(Cdot1),-(Cdot2));		HX_STACK_VAR(df,"df");
			HX_STACK_LINE(533)
			this->m_impulse->add(df);
			HX_STACK_LINE(535)
			if (((this->m_limitState == (int)1))){
				HX_STACK_LINE(537)
				Float _g2 = ::box2D::common::math::B2Math_obj::max(this->m_impulse->y,0.0);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(537)
				this->m_impulse->y = _g2;
			}
			else{
				HX_STACK_LINE(539)
				if (((this->m_limitState == (int)2))){
					HX_STACK_LINE(541)
					Float _g3 = ::box2D::common::math::B2Math_obj::min(this->m_impulse->y,0.0);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(541)
					this->m_impulse->y = _g3;
				}
			}
			HX_STACK_LINE(545)
			Float b = (-(Cdot1) - (((this->m_impulse->y - f1->y)) * this->m_K->col2->x));		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(546)
			Float f2r;		HX_STACK_VAR(f2r,"f2r");
			HX_STACK_LINE(547)
			if (((this->m_K->col1->x != 0.0))){
				HX_STACK_LINE(549)
				f2r = ((Float(b) / Float(this->m_K->col1->x)) + f1->x);
			}
			else{
				HX_STACK_LINE(551)
				f2r = f1->x;
			}
			HX_STACK_LINE(553)
			this->m_impulse->x = f2r;
			HX_STACK_LINE(555)
			df->x = (this->m_impulse->x - f1->x);
			HX_STACK_LINE(556)
			df->y = (this->m_impulse->y - f1->y);
			HX_STACK_LINE(558)
			PX = ((df->x * this->m_perp->x) + (df->y * this->m_axis->x));
			HX_STACK_LINE(559)
			PY = ((df->x * this->m_perp->y) + (df->y * this->m_axis->y));
			HX_STACK_LINE(560)
			L1 = ((df->x * this->m_s1) + (df->y * this->m_a1));
			HX_STACK_LINE(561)
			L2 = ((df->x * this->m_s2) + (df->y * this->m_a2));
			HX_STACK_LINE(563)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_STACK_LINE(564)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_STACK_LINE(565)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_STACK_LINE(567)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_STACK_LINE(568)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_STACK_LINE(569)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		else{
			HX_STACK_LINE(574)
			Float df2;		HX_STACK_VAR(df2,"df2");
			HX_STACK_LINE(575)
			if (((this->m_K->col1->x != 0.0))){
				HX_STACK_LINE(577)
				df2 = (Float(-(Cdot1)) / Float(this->m_K->col1->x));
			}
			else{
				HX_STACK_LINE(579)
				df2 = 0.0;
			}
			HX_STACK_LINE(581)
			hx::AddEq(this->m_impulse->x,df2);
			HX_STACK_LINE(583)
			PX = (df2 * this->m_perp->x);
			HX_STACK_LINE(584)
			PY = (df2 * this->m_perp->y);
			HX_STACK_LINE(585)
			L1 = (df2 * this->m_s1);
			HX_STACK_LINE(586)
			L2 = (df2 * this->m_s2);
			HX_STACK_LINE(588)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_STACK_LINE(589)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_STACK_LINE(590)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_STACK_LINE(592)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_STACK_LINE(593)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_STACK_LINE(594)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_STACK_LINE(597)
		bA->m_linearVelocity->setV(v1);
		HX_STACK_LINE(598)
		bA->m_angularVelocity = w1;
		HX_STACK_LINE(599)
		bB->m_linearVelocity->setV(v2);
		HX_STACK_LINE(600)
		bB->m_angularVelocity = w2;
	}
return null();
}


bool B2LineJoint_obj::solvePositionConstraints( Float baumgarte){
	HX_STACK_FRAME("box2D.dynamics.joints.B2LineJoint","solvePositionConstraints",0xbaf04052,"box2D.dynamics.joints.B2LineJoint.solvePositionConstraints","box2D/dynamics/joints/B2LineJoint.hx",604,0x501e3935)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baumgarte,"baumgarte")
	HX_STACK_LINE(608)
	Float limitC;		HX_STACK_VAR(limitC,"limitC");
	HX_STACK_LINE(609)
	Float oldLimitImpulse;		HX_STACK_VAR(oldLimitImpulse,"oldLimitImpulse");
	HX_STACK_LINE(611)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(612)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(614)
	::box2D::common::math::B2Vec2 c1 = bA->m_sweep->c;		HX_STACK_VAR(c1,"c1");
	HX_STACK_LINE(615)
	Float a1 = bA->m_sweep->a;		HX_STACK_VAR(a1,"a1");
	HX_STACK_LINE(617)
	::box2D::common::math::B2Vec2 c2 = bB->m_sweep->c;		HX_STACK_VAR(c2,"c2");
	HX_STACK_LINE(618)
	Float a2 = bB->m_sweep->a;		HX_STACK_VAR(a2,"a2");
	HX_STACK_LINE(620)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(621)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(623)
	Float m1;		HX_STACK_VAR(m1,"m1");
	HX_STACK_LINE(624)
	Float m2;		HX_STACK_VAR(m2,"m2");
	HX_STACK_LINE(625)
	Float i1;		HX_STACK_VAR(i1,"i1");
	HX_STACK_LINE(626)
	Float i2;		HX_STACK_VAR(i2,"i2");
	HX_STACK_LINE(629)
	Float linearError = 0.0;		HX_STACK_VAR(linearError,"linearError");
	HX_STACK_LINE(630)
	Float angularError = 0.0;		HX_STACK_VAR(angularError,"angularError");
	HX_STACK_LINE(631)
	bool active = false;		HX_STACK_VAR(active,"active");
	HX_STACK_LINE(632)
	Float C2 = 0.0;		HX_STACK_VAR(C2,"C2");
	HX_STACK_LINE(634)
	::box2D::common::math::B2Mat22 R1 = ::box2D::common::math::B2Mat22_obj::fromAngle(a1);		HX_STACK_VAR(R1,"R1");
	HX_STACK_LINE(635)
	::box2D::common::math::B2Mat22 R2 = ::box2D::common::math::B2Mat22_obj::fromAngle(a2);		HX_STACK_VAR(R2,"R2");
	HX_STACK_LINE(638)
	tMat = R1;
	HX_STACK_LINE(639)
	Float r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);		HX_STACK_VAR(r1X,"r1X");
	HX_STACK_LINE(640)
	Float r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);		HX_STACK_VAR(r1Y,"r1Y");
	HX_STACK_LINE(641)
	tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
	HX_STACK_LINE(642)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_STACK_LINE(643)
	r1X = tX;
	HX_STACK_LINE(645)
	tMat = R2;
	HX_STACK_LINE(646)
	Float r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);		HX_STACK_VAR(r2X,"r2X");
	HX_STACK_LINE(647)
	Float r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);		HX_STACK_VAR(r2Y,"r2Y");
	HX_STACK_LINE(648)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_STACK_LINE(649)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_STACK_LINE(650)
	r2X = tX;
	HX_STACK_LINE(652)
	Float dX = (((c2->x + r2X) - c1->x) - r1X);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(653)
	Float dY = (((c2->y + r2Y) - c1->y) - r1Y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(655)
	if ((this->m_enableLimit)){
		HX_STACK_LINE(657)
		::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localXAxis1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(657)
		this->m_axis = _g;
		HX_STACK_LINE(660)
		this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
		HX_STACK_LINE(662)
		this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
		HX_STACK_LINE(664)
		Float translation = ((this->m_axis->x * dX) + (this->m_axis->y * dY));		HX_STACK_VAR(translation,"translation");
		HX_STACK_LINE(665)
		Float _g1 = ::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(665)
		if (((_g1 < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
			HX_STACK_LINE(668)
			Float _g2 = ::box2D::common::math::B2Math_obj::clamp(translation,-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),::box2D::common::B2Settings_obj::b2_maxLinearCorrection);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(668)
			C2 = _g2;
			HX_STACK_LINE(669)
			Float _g3 = ::box2D::common::math::B2Math_obj::abs(translation);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(669)
			linearError = _g3;
			HX_STACK_LINE(670)
			active = true;
		}
		else{
			HX_STACK_LINE(672)
			if (((translation <= this->m_lowerTranslation))){
				HX_STACK_LINE(675)
				Float _g4 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_lowerTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(675)
				C2 = _g4;
				HX_STACK_LINE(676)
				linearError = (this->m_lowerTranslation - translation);
				HX_STACK_LINE(677)
				active = true;
			}
			else{
				HX_STACK_LINE(679)
				if (((translation >= this->m_upperTranslation))){
					HX_STACK_LINE(682)
					Float _g5 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_upperTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),0.0,::box2D::common::B2Settings_obj::b2_maxLinearCorrection);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(682)
					C2 = _g5;
					HX_STACK_LINE(683)
					linearError = (translation - this->m_upperTranslation);
					HX_STACK_LINE(684)
					active = true;
				}
			}
		}
	}
	HX_STACK_LINE(688)
	::box2D::common::math::B2Vec2 _g6 = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localYAxis1);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(688)
	this->m_perp = _g6;
	HX_STACK_LINE(691)
	this->m_s1 = ((((dX + r1X)) * this->m_perp->y) - (((dY + r1Y)) * this->m_perp->x));
	HX_STACK_LINE(693)
	this->m_s2 = ((r2X * this->m_perp->y) - (r2Y * this->m_perp->x));
	HX_STACK_LINE(695)
	::box2D::common::math::B2Vec2 impulse = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(impulse,"impulse");
	HX_STACK_LINE(696)
	Float C1 = ((this->m_perp->x * dX) + (this->m_perp->y * dY));		HX_STACK_VAR(C1,"C1");
	HX_STACK_LINE(698)
	Float _g7 = ::box2D::common::math::B2Math_obj::abs(C1);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(698)
	Float _g8 = ::box2D::common::math::B2Math_obj::max(linearError,_g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(698)
	linearError = _g8;
	HX_STACK_LINE(699)
	angularError = 0.0;
	HX_STACK_LINE(701)
	if ((active)){
		HX_STACK_LINE(703)
		m1 = this->m_invMassA;
		HX_STACK_LINE(704)
		m2 = this->m_invMassB;
		HX_STACK_LINE(705)
		i1 = this->m_invIA;
		HX_STACK_LINE(706)
		i2 = this->m_invIB;
		HX_STACK_LINE(708)
		this->m_K->col1->x = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
		HX_STACK_LINE(709)
		this->m_K->col1->y = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
		HX_STACK_LINE(710)
		this->m_K->col2->x = this->m_K->col1->y;
		HX_STACK_LINE(711)
		this->m_K->col2->y = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		HX_STACK_LINE(713)
		this->m_K->solve(impulse,-(C1),-(C2));
	}
	else{
		HX_STACK_LINE(717)
		m1 = this->m_invMassA;
		HX_STACK_LINE(718)
		m2 = this->m_invMassB;
		HX_STACK_LINE(719)
		i1 = this->m_invIA;
		HX_STACK_LINE(720)
		i2 = this->m_invIB;
		HX_STACK_LINE(722)
		Float k11 = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));		HX_STACK_VAR(k11,"k11");
		HX_STACK_LINE(724)
		Float impulse1;		HX_STACK_VAR(impulse1,"impulse1");
		HX_STACK_LINE(725)
		if (((k11 != 0.0))){
			HX_STACK_LINE(727)
			impulse1 = (Float(-(C1)) / Float(k11));
		}
		else{
			HX_STACK_LINE(729)
			impulse1 = 0.0;
		}
		HX_STACK_LINE(731)
		impulse->x = impulse1;
		HX_STACK_LINE(732)
		impulse->y = 0.0;
	}
	HX_STACK_LINE(735)
	Float PX = ((impulse->x * this->m_perp->x) + (impulse->y * this->m_axis->x));		HX_STACK_VAR(PX,"PX");
	HX_STACK_LINE(736)
	Float PY = ((impulse->x * this->m_perp->y) + (impulse->y * this->m_axis->y));		HX_STACK_VAR(PY,"PY");
	HX_STACK_LINE(737)
	Float L1 = ((impulse->x * this->m_s1) + (impulse->y * this->m_a1));		HX_STACK_VAR(L1,"L1");
	HX_STACK_LINE(738)
	Float L2 = ((impulse->x * this->m_s2) + (impulse->y * this->m_a2));		HX_STACK_VAR(L2,"L2");
	HX_STACK_LINE(740)
	hx::SubEq(c1->x,(this->m_invMassA * PX));
	HX_STACK_LINE(741)
	hx::SubEq(c1->y,(this->m_invMassA * PY));
	HX_STACK_LINE(742)
	hx::SubEq(a1,(this->m_invIA * L1));
	HX_STACK_LINE(744)
	hx::AddEq(c2->x,(this->m_invMassB * PX));
	HX_STACK_LINE(745)
	hx::AddEq(c2->y,(this->m_invMassB * PY));
	HX_STACK_LINE(746)
	hx::AddEq(a2,(this->m_invIB * L2));
	HX_STACK_LINE(750)
	bA->m_sweep->a = a1;
	HX_STACK_LINE(752)
	bB->m_sweep->a = a2;
	HX_STACK_LINE(753)
	bA->synchronizeTransform();
	HX_STACK_LINE(754)
	bB->synchronizeTransform();
	HX_STACK_LINE(756)
	return (bool((linearError <= ::box2D::common::B2Settings_obj::b2_linearSlop)) && bool((angularError <= ::box2D::common::B2Settings_obj::b2_angularSlop)));
}



B2LineJoint_obj::B2LineJoint_obj()
{
}

void B2LineJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2LineJoint);
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_localXAxis1,"m_localXAxis1");
	HX_MARK_MEMBER_NAME(m_localYAxis1,"m_localYAxis1");
	HX_MARK_MEMBER_NAME(m_axis,"m_axis");
	HX_MARK_MEMBER_NAME(m_perp,"m_perp");
	HX_MARK_MEMBER_NAME(m_s1,"m_s1");
	HX_MARK_MEMBER_NAME(m_s2,"m_s2");
	HX_MARK_MEMBER_NAME(m_a1,"m_a1");
	HX_MARK_MEMBER_NAME(m_a2,"m_a2");
	HX_MARK_MEMBER_NAME(m_K,"m_K");
	HX_MARK_MEMBER_NAME(m_impulse,"m_impulse");
	HX_MARK_MEMBER_NAME(m_motorMass,"m_motorMass");
	HX_MARK_MEMBER_NAME(m_motorImpulse,"m_motorImpulse");
	HX_MARK_MEMBER_NAME(m_lowerTranslation,"m_lowerTranslation");
	HX_MARK_MEMBER_NAME(m_upperTranslation,"m_upperTranslation");
	HX_MARK_MEMBER_NAME(m_maxMotorForce,"m_maxMotorForce");
	HX_MARK_MEMBER_NAME(m_motorSpeed,"m_motorSpeed");
	HX_MARK_MEMBER_NAME(m_enableLimit,"m_enableLimit");
	HX_MARK_MEMBER_NAME(m_enableMotor,"m_enableMotor");
	HX_MARK_MEMBER_NAME(m_limitState,"m_limitState");
	::box2D::dynamics::joints::B2Joint_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2LineJoint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_VISIT_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_VISIT_MEMBER_NAME(m_localXAxis1,"m_localXAxis1");
	HX_VISIT_MEMBER_NAME(m_localYAxis1,"m_localYAxis1");
	HX_VISIT_MEMBER_NAME(m_axis,"m_axis");
	HX_VISIT_MEMBER_NAME(m_perp,"m_perp");
	HX_VISIT_MEMBER_NAME(m_s1,"m_s1");
	HX_VISIT_MEMBER_NAME(m_s2,"m_s2");
	HX_VISIT_MEMBER_NAME(m_a1,"m_a1");
	HX_VISIT_MEMBER_NAME(m_a2,"m_a2");
	HX_VISIT_MEMBER_NAME(m_K,"m_K");
	HX_VISIT_MEMBER_NAME(m_impulse,"m_impulse");
	HX_VISIT_MEMBER_NAME(m_motorMass,"m_motorMass");
	HX_VISIT_MEMBER_NAME(m_motorImpulse,"m_motorImpulse");
	HX_VISIT_MEMBER_NAME(m_lowerTranslation,"m_lowerTranslation");
	HX_VISIT_MEMBER_NAME(m_upperTranslation,"m_upperTranslation");
	HX_VISIT_MEMBER_NAME(m_maxMotorForce,"m_maxMotorForce");
	HX_VISIT_MEMBER_NAME(m_motorSpeed,"m_motorSpeed");
	HX_VISIT_MEMBER_NAME(m_enableLimit,"m_enableLimit");
	HX_VISIT_MEMBER_NAME(m_enableMotor,"m_enableMotor");
	HX_VISIT_MEMBER_NAME(m_limitState,"m_limitState");
	::box2D::dynamics::joints::B2Joint_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2LineJoint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_K") ) { return m_K; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_s1") ) { return m_s1; }
		if (HX_FIELD_EQ(inName,"m_s2") ) { return m_s2; }
		if (HX_FIELD_EQ(inName,"m_a1") ) { return m_a1; }
		if (HX_FIELD_EQ(inName,"m_a2") ) { return m_a2; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_axis") ) { return m_axis; }
		if (HX_FIELD_EQ(inName,"m_perp") ) { return m_perp; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setLimits") ) { return setLimits_dyn(); }
		if (HX_FIELD_EQ(inName,"m_impulse") ) { return m_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enableLimit") ) { return enableLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"enableMotor") ) { return enableMotor_dyn(); }
		if (HX_FIELD_EQ(inName,"m_motorMass") ) { return m_motorMass; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_motorSpeed") ) { return m_motorSpeed; }
		if (HX_FIELD_EQ(inName,"m_limitState") ) { return m_limitState; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getJointSpeed") ) { return getJointSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getLowerLimit") ) { return getLowerLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"getUpperLimit") ) { return getUpperLimit_dyn(); }
		if (HX_FIELD_EQ(inName,"setMotorSpeed") ) { return setMotorSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getMotorSpeed") ) { return getMotorSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getMotorForce") ) { return getMotorForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_localXAxis1") ) { return m_localXAxis1; }
		if (HX_FIELD_EQ(inName,"m_localYAxis1") ) { return m_localYAxis1; }
		if (HX_FIELD_EQ(inName,"m_enableLimit") ) { return m_enableLimit; }
		if (HX_FIELD_EQ(inName,"m_enableMotor") ) { return m_enableMotor; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isLimitEnabled") ) { return isLimitEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"isMotorEnabled") ) { return isMotorEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { return m_localAnchor1; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { return m_localAnchor2; }
		if (HX_FIELD_EQ(inName,"m_motorImpulse") ) { return m_motorImpulse; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_maxMotorForce") ) { return m_maxMotorForce; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"setMaxMotorForce") ) { return setMaxMotorForce_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxMotorForce") ) { return getMaxMotorForce_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_lowerTranslation") ) { return m_lowerTranslation; }
		if (HX_FIELD_EQ(inName,"m_upperTranslation") ) { return m_upperTranslation; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getJointTranslation") ) { return getJointTranslation_dyn(); }
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

Dynamic B2LineJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_K") ) { m_K=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_s1") ) { m_s1=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_s2") ) { m_s2=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_a1") ) { m_a1=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_a2") ) { m_a2=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_axis") ) { m_axis=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_perp") ) { m_perp=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_motorMass") ) { m_motorMass=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_motorSpeed") ) { m_motorSpeed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_limitState") ) { m_limitState=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_localXAxis1") ) { m_localXAxis1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localYAxis1") ) { m_localYAxis1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_enableLimit") ) { m_enableLimit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_enableMotor") ) { m_enableMotor=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchor1") ) { m_localAnchor1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchor2") ) { m_localAnchor2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_motorImpulse") ) { m_motorImpulse=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_maxMotorForce") ) { m_maxMotorForce=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_lowerTranslation") ) { m_lowerTranslation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_upperTranslation") ) { m_upperTranslation=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2LineJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_localXAxis1"));
	outFields->push(HX_CSTRING("m_localYAxis1"));
	outFields->push(HX_CSTRING("m_axis"));
	outFields->push(HX_CSTRING("m_perp"));
	outFields->push(HX_CSTRING("m_s1"));
	outFields->push(HX_CSTRING("m_s2"));
	outFields->push(HX_CSTRING("m_a1"));
	outFields->push(HX_CSTRING("m_a2"));
	outFields->push(HX_CSTRING("m_K"));
	outFields->push(HX_CSTRING("m_impulse"));
	outFields->push(HX_CSTRING("m_motorMass"));
	outFields->push(HX_CSTRING("m_motorImpulse"));
	outFields->push(HX_CSTRING("m_lowerTranslation"));
	outFields->push(HX_CSTRING("m_upperTranslation"));
	outFields->push(HX_CSTRING("m_maxMotorForce"));
	outFields->push(HX_CSTRING("m_motorSpeed"));
	outFields->push(HX_CSTRING("m_enableLimit"));
	outFields->push(HX_CSTRING("m_enableMotor"));
	outFields->push(HX_CSTRING("m_limitState"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJoint_obj,m_localAnchor1),HX_CSTRING("m_localAnchor1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJoint_obj,m_localAnchor2),HX_CSTRING("m_localAnchor2")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJoint_obj,m_localXAxis1),HX_CSTRING("m_localXAxis1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJoint_obj,m_localYAxis1),HX_CSTRING("m_localYAxis1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJoint_obj,m_axis),HX_CSTRING("m_axis")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJoint_obj,m_perp),HX_CSTRING("m_perp")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_s1),HX_CSTRING("m_s1")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_s2),HX_CSTRING("m_s2")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_a1),HX_CSTRING("m_a1")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_a2),HX_CSTRING("m_a2")},
	{hx::fsObject /*::box2D::common::math::B2Mat22*/ ,(int)offsetof(B2LineJoint_obj,m_K),HX_CSTRING("m_K")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJoint_obj,m_impulse),HX_CSTRING("m_impulse")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_motorMass),HX_CSTRING("m_motorMass")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_motorImpulse),HX_CSTRING("m_motorImpulse")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_lowerTranslation),HX_CSTRING("m_lowerTranslation")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_upperTranslation),HX_CSTRING("m_upperTranslation")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_maxMotorForce),HX_CSTRING("m_maxMotorForce")},
	{hx::fsFloat,(int)offsetof(B2LineJoint_obj,m_motorSpeed),HX_CSTRING("m_motorSpeed")},
	{hx::fsBool,(int)offsetof(B2LineJoint_obj,m_enableLimit),HX_CSTRING("m_enableLimit")},
	{hx::fsBool,(int)offsetof(B2LineJoint_obj,m_enableMotor),HX_CSTRING("m_enableMotor")},
	{hx::fsInt,(int)offsetof(B2LineJoint_obj,m_limitState),HX_CSTRING("m_limitState")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getJointTranslation"),
	HX_CSTRING("getJointSpeed"),
	HX_CSTRING("isLimitEnabled"),
	HX_CSTRING("enableLimit"),
	HX_CSTRING("getLowerLimit"),
	HX_CSTRING("getUpperLimit"),
	HX_CSTRING("setLimits"),
	HX_CSTRING("isMotorEnabled"),
	HX_CSTRING("enableMotor"),
	HX_CSTRING("setMotorSpeed"),
	HX_CSTRING("getMotorSpeed"),
	HX_CSTRING("setMaxMotorForce"),
	HX_CSTRING("getMaxMotorForce"),
	HX_CSTRING("getMotorForce"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_localXAxis1"),
	HX_CSTRING("m_localYAxis1"),
	HX_CSTRING("m_axis"),
	HX_CSTRING("m_perp"),
	HX_CSTRING("m_s1"),
	HX_CSTRING("m_s2"),
	HX_CSTRING("m_a1"),
	HX_CSTRING("m_a2"),
	HX_CSTRING("m_K"),
	HX_CSTRING("m_impulse"),
	HX_CSTRING("m_motorMass"),
	HX_CSTRING("m_motorImpulse"),
	HX_CSTRING("m_lowerTranslation"),
	HX_CSTRING("m_upperTranslation"),
	HX_CSTRING("m_maxMotorForce"),
	HX_CSTRING("m_motorSpeed"),
	HX_CSTRING("m_enableLimit"),
	HX_CSTRING("m_enableMotor"),
	HX_CSTRING("m_limitState"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2LineJoint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2LineJoint_obj::__mClass,"__mClass");
};

#endif

Class B2LineJoint_obj::__mClass;

void B2LineJoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2LineJoint"), hx::TCanCast< B2LineJoint_obj> ,sStaticFields,sMemberFields,
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

void B2LineJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
