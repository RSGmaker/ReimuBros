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
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJoint
#include <box2D/dynamics/joints/B2PrismaticJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJointDef
#include <box2D/dynamics/joints/B2PrismaticJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2PrismaticJoint_obj::__construct(::box2D::dynamics::joints::B2PrismaticJointDef def)
{
HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","new",0xd116935a,"box2D.dynamics.joints.B2PrismaticJoint.new","box2D/dynamics/joints/B2PrismaticJoint.hx",296,0x93be09d5)
HX_STACK_THIS(this)
HX_STACK_ARG(def,"def")
{
	HX_STACK_LINE(297)
	super::__construct(def);
	HX_STACK_LINE(299)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(299)
	this->m_localAnchor1 = _g;
	HX_STACK_LINE(300)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(300)
	this->m_localAnchor2 = _g1;
	HX_STACK_LINE(301)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(301)
	this->m_localXAxis1 = _g2;
	HX_STACK_LINE(302)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(302)
	this->m_localYAxis1 = _g3;
	HX_STACK_LINE(303)
	::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(303)
	this->m_axis = _g4;
	HX_STACK_LINE(304)
	::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(304)
	this->m_perp = _g5;
	HX_STACK_LINE(305)
	::box2D::common::math::B2Mat33 _g6 = ::box2D::common::math::B2Mat33_obj::__new(null(),null(),null());		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(305)
	this->m_K = _g6;
	HX_STACK_LINE(306)
	::box2D::common::math::B2Vec3 _g7 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(306)
	this->m_impulse = _g7;
	HX_STACK_LINE(309)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(310)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(311)
	Float tY;		HX_STACK_VAR(tY,"tY");
	HX_STACK_LINE(313)
	this->m_localAnchor1->setV(def->localAnchorA);
	HX_STACK_LINE(314)
	this->m_localAnchor2->setV(def->localAnchorB);
	HX_STACK_LINE(315)
	this->m_localXAxis1->setV(def->localAxisA);
	HX_STACK_LINE(318)
	this->m_localYAxis1->x = -(this->m_localXAxis1->y);
	HX_STACK_LINE(319)
	this->m_localYAxis1->y = this->m_localXAxis1->x;
	HX_STACK_LINE(321)
	this->m_refAngle = def->referenceAngle;
	HX_STACK_LINE(323)
	this->m_impulse->setZero();
	HX_STACK_LINE(324)
	this->m_motorMass = 0.0;
	HX_STACK_LINE(325)
	this->m_motorImpulse = 0.0;
	HX_STACK_LINE(327)
	this->m_lowerTranslation = def->lowerTranslation;
	HX_STACK_LINE(328)
	this->m_upperTranslation = def->upperTranslation;
	HX_STACK_LINE(329)
	this->m_maxMotorForce = def->maxMotorForce;
	HX_STACK_LINE(330)
	this->m_motorSpeed = def->motorSpeed;
	HX_STACK_LINE(331)
	this->m_enableLimit = def->enableLimit;
	HX_STACK_LINE(332)
	this->m_enableMotor = def->enableMotor;
	HX_STACK_LINE(333)
	this->m_limitState = (int)0;
	HX_STACK_LINE(335)
	this->m_axis->setZero();
	HX_STACK_LINE(336)
	this->m_perp->setZero();
}
;
	return null();
}

//B2PrismaticJoint_obj::~B2PrismaticJoint_obj() { }

Dynamic B2PrismaticJoint_obj::__CreateEmpty() { return  new B2PrismaticJoint_obj; }
hx::ObjectPtr< B2PrismaticJoint_obj > B2PrismaticJoint_obj::__new(::box2D::dynamics::joints::B2PrismaticJointDef def)
{  hx::ObjectPtr< B2PrismaticJoint_obj > result = new B2PrismaticJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2PrismaticJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PrismaticJoint_obj > result = new B2PrismaticJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2PrismaticJoint_obj::getAnchorA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getAnchorA",0x1340627c,"box2D.dynamics.joints.B2PrismaticJoint.getAnchorA","box2D/dynamics/joints/B2PrismaticJoint.hx",110,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(110)
	return this->m_bodyA->getWorldPoint(this->m_localAnchor1);
}


::box2D::common::math::B2Vec2 B2PrismaticJoint_obj::getAnchorB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getAnchorB",0x1340627d,"box2D.dynamics.joints.B2PrismaticJoint.getAnchorB","box2D/dynamics/joints/B2PrismaticJoint.hx",114,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(114)
	return this->m_bodyB->getWorldPoint(this->m_localAnchor2);
}


::box2D::common::math::B2Vec2 B2PrismaticJoint_obj::getReactionForce( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getReactionForce",0x15c7e7d2,"box2D.dynamics.joints.B2PrismaticJoint.getReactionForce","box2D/dynamics/joints/B2PrismaticJoint.hx",120,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(120)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * (((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->x)))),(inv_dt * (((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->y)))));
}


Float B2PrismaticJoint_obj::getReactionTorque( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getReactionTorque",0x922cab03,"box2D.dynamics.joints.B2PrismaticJoint.getReactionTorque","box2D/dynamics/joints/B2PrismaticJoint.hx",127,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(127)
	return (inv_dt * this->m_impulse->y);
}


Float B2PrismaticJoint_obj::getJointTranslation( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getJointTranslation",0x74931f77,"box2D.dynamics.joints.B2PrismaticJoint.getJointTranslation","box2D/dynamics/joints/B2PrismaticJoint.hx",133,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(134)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(135)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(137)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(139)
	::box2D::common::math::B2Vec2 p1 = bA->getWorldPoint(this->m_localAnchor1);		HX_STACK_VAR(p1,"p1");
	HX_STACK_LINE(140)
	::box2D::common::math::B2Vec2 p2 = bB->getWorldPoint(this->m_localAnchor2);		HX_STACK_VAR(p2,"p2");
	HX_STACK_LINE(142)
	Float dX = (p2->x - p1->x);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(143)
	Float dY = (p2->y - p1->y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(145)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);		HX_STACK_VAR(axis,"axis");
	HX_STACK_LINE(148)
	Float translation = ((axis->x * dX) + (axis->y * dY));		HX_STACK_VAR(translation,"translation");
	HX_STACK_LINE(149)
	return translation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getJointTranslation,return )

Float B2PrismaticJoint_obj::getJointSpeed( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getJointSpeed",0xb9993d8d,"box2D.dynamics.joints.B2PrismaticJoint.getJointSpeed","box2D/dynamics/joints/B2PrismaticJoint.hx",155,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(156)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(157)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(159)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(162)
	tMat = bA->m_xf->R;
	HX_STACK_LINE(163)
	Float r1X = (this->m_localAnchor1->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(r1X,"r1X");
	HX_STACK_LINE(164)
	Float r1Y = (this->m_localAnchor1->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(r1Y,"r1Y");
	HX_STACK_LINE(165)
	Float tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(166)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_STACK_LINE(167)
	r1X = tX;
	HX_STACK_LINE(169)
	tMat = bB->m_xf->R;
	HX_STACK_LINE(170)
	Float r2X = (this->m_localAnchor2->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(r2X,"r2X");
	HX_STACK_LINE(171)
	Float r2Y = (this->m_localAnchor2->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(r2Y,"r2Y");
	HX_STACK_LINE(172)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_STACK_LINE(173)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_STACK_LINE(174)
	r2X = tX;
	HX_STACK_LINE(177)
	Float p1X = (bA->m_sweep->c->x + r1X);		HX_STACK_VAR(p1X,"p1X");
	HX_STACK_LINE(178)
	Float p1Y = (bA->m_sweep->c->y + r1Y);		HX_STACK_VAR(p1Y,"p1Y");
	HX_STACK_LINE(180)
	Float p2X = (bB->m_sweep->c->x + r2X);		HX_STACK_VAR(p2X,"p2X");
	HX_STACK_LINE(181)
	Float p2Y = (bB->m_sweep->c->y + r2Y);		HX_STACK_VAR(p2Y,"p2Y");
	HX_STACK_LINE(183)
	Float dX = (p2X - p1X);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(184)
	Float dY = (p2Y - p1Y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(186)
	::box2D::common::math::B2Vec2 axis = bA->getWorldVector(this->m_localXAxis1);		HX_STACK_VAR(axis,"axis");
	HX_STACK_LINE(188)
	::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;		HX_STACK_VAR(v1,"v1");
	HX_STACK_LINE(189)
	::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;		HX_STACK_VAR(v2,"v2");
	HX_STACK_LINE(190)
	Float w1 = bA->m_angularVelocity;		HX_STACK_VAR(w1,"w1");
	HX_STACK_LINE(191)
	Float w2 = bB->m_angularVelocity;		HX_STACK_VAR(w2,"w2");
	HX_STACK_LINE(196)
	Float speed = (((dX * ((-(w1) * axis->y))) + (dY * ((w1 * axis->x)))) + (((axis->x * ((((v2->x + (-(w2) * r2Y)) - v1->x) - (-(w1) * r1Y)))) + (axis->y * ((((v2->y + (w2 * r2X)) - v1->y) - (w1 * r1X)))))));		HX_STACK_VAR(speed,"speed");
	HX_STACK_LINE(198)
	return speed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getJointSpeed,return )

bool B2PrismaticJoint_obj::isLimitEnabled( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","isLimitEnabled",0xb236a4d6,"box2D.dynamics.joints.B2PrismaticJoint.isLimitEnabled","box2D/dynamics/joints/B2PrismaticJoint.hx",206,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(206)
	return this->m_enableLimit;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,isLimitEnabled,return )

Void B2PrismaticJoint_obj::enableLimit( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","enableLimit",0x93e5b2b2,"box2D.dynamics.joints.B2PrismaticJoint.enableLimit","box2D/dynamics/joints/B2PrismaticJoint.hx",212,0x93be09d5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(213)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(214)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(215)
		this->m_enableLimit = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,enableLimit,(void))

Float B2PrismaticJoint_obj::getLowerLimit( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getLowerLimit",0x0b900d2a,"box2D.dynamics.joints.B2PrismaticJoint.getLowerLimit","box2D/dynamics/joints/B2PrismaticJoint.hx",222,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(222)
	return this->m_lowerTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getLowerLimit,return )

Float B2PrismaticJoint_obj::getUpperLimit( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getUpperLimit",0x10be8e29,"box2D.dynamics.joints.B2PrismaticJoint.getUpperLimit","box2D/dynamics/joints/B2PrismaticJoint.hx",229,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(229)
	return this->m_upperTranslation;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getUpperLimit,return )

Void B2PrismaticJoint_obj::setLimits( Float lower,Float upper){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","setLimits",0xf9d7e494,"box2D.dynamics.joints.B2PrismaticJoint.setLimits","box2D/dynamics/joints/B2PrismaticJoint.hx",235,0x93be09d5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(lower,"lower")
		HX_STACK_ARG(upper,"upper")
		HX_STACK_LINE(237)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(238)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(239)
		this->m_lowerTranslation = lower;
		HX_STACK_LINE(240)
		this->m_upperTranslation = upper;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PrismaticJoint_obj,setLimits,(void))

bool B2PrismaticJoint_obj::isMotorEnabled( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","isMotorEnabled",0xba796edc,"box2D.dynamics.joints.B2PrismaticJoint.isMotorEnabled","box2D/dynamics/joints/B2PrismaticJoint.hx",247,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(247)
	return this->m_enableMotor;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,isMotorEnabled,return )

Void B2PrismaticJoint_obj::enableMotor( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","enableMotor",0x2b48e3ec,"box2D.dynamics.joints.B2PrismaticJoint.enableMotor","box2D/dynamics/joints/B2PrismaticJoint.hx",253,0x93be09d5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(254)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(255)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(256)
		this->m_enableMotor = flag;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,enableMotor,(void))

Void B2PrismaticJoint_obj::setMotorSpeed( Float speed){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","setMotorSpeed",0x11882c8e,"box2D.dynamics.joints.B2PrismaticJoint.setMotorSpeed","box2D/dynamics/joints/B2PrismaticJoint.hx",262,0x93be09d5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(speed,"speed")
		HX_STACK_LINE(263)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(264)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(265)
		this->m_motorSpeed = speed;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,setMotorSpeed,(void))

Float B2PrismaticJoint_obj::getMotorSpeed( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getMotorSpeed",0xcc824a82,"box2D.dynamics.joints.B2PrismaticJoint.getMotorSpeed","box2D/dynamics/joints/B2PrismaticJoint.hx",272,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(272)
	return this->m_motorSpeed;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getMotorSpeed,return )

Void B2PrismaticJoint_obj::setMaxMotorForce( Float force){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","setMaxMotorForce",0x05c04cbe,"box2D.dynamics.joints.B2PrismaticJoint.setMaxMotorForce","box2D/dynamics/joints/B2PrismaticJoint.hx",279,0x93be09d5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(force,"force")
		HX_STACK_LINE(280)
		this->m_bodyA->setAwake(true);
		HX_STACK_LINE(281)
		this->m_bodyB->setAwake(true);
		HX_STACK_LINE(282)
		this->m_maxMotorForce = force;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PrismaticJoint_obj,setMaxMotorForce,(void))

Float B2PrismaticJoint_obj::getMotorForce( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","getMotorForce",0x4fad64e6,"box2D.dynamics.joints.B2PrismaticJoint.getMotorForce","box2D/dynamics/joints/B2PrismaticJoint.hx",289,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(289)
	return this->m_motorImpulse;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PrismaticJoint_obj,getMotorForce,return )

Void B2PrismaticJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","initVelocityConstraints",0x47c2d523,"box2D.dynamics.joints.B2PrismaticJoint.initVelocityConstraints","box2D/dynamics/joints/B2PrismaticJoint.hx",339,0x93be09d5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(340)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(341)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(343)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(344)
		Float tX;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(346)
		::box2D::common::math::B2Vec2 _g = bA->getLocalCenter();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(346)
		this->m_localCenterA->setV(_g);
		HX_STACK_LINE(347)
		::box2D::common::math::B2Vec2 _g1 = bB->getLocalCenter();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(347)
		this->m_localCenterB->setV(_g1);
		HX_STACK_LINE(349)
		::box2D::common::math::B2Transform xf1 = bA->getTransform();		HX_STACK_VAR(xf1,"xf1");
		HX_STACK_LINE(350)
		::box2D::common::math::B2Transform xf2 = bB->getTransform();		HX_STACK_VAR(xf2,"xf2");
		HX_STACK_LINE(354)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(355)
		Float r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);		HX_STACK_VAR(r1X,"r1X");
		HX_STACK_LINE(356)
		Float r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);		HX_STACK_VAR(r1Y,"r1Y");
		HX_STACK_LINE(357)
		tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
		HX_STACK_LINE(358)
		r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
		HX_STACK_LINE(359)
		r1X = tX;
		HX_STACK_LINE(361)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(362)
		Float r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);		HX_STACK_VAR(r2X,"r2X");
		HX_STACK_LINE(363)
		Float r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);		HX_STACK_VAR(r2Y,"r2Y");
		HX_STACK_LINE(364)
		tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
		HX_STACK_LINE(365)
		r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
		HX_STACK_LINE(366)
		r2X = tX;
		HX_STACK_LINE(369)
		Float dX = (((bB->m_sweep->c->x + r2X) - bA->m_sweep->c->x) - r1X);		HX_STACK_VAR(dX,"dX");
		HX_STACK_LINE(370)
		Float dY = (((bB->m_sweep->c->y + r2Y) - bA->m_sweep->c->y) - r1Y);		HX_STACK_VAR(dY,"dY");
		HX_STACK_LINE(372)
		this->m_invMassA = bA->m_invMass;
		HX_STACK_LINE(373)
		this->m_invMassB = bB->m_invMass;
		HX_STACK_LINE(374)
		this->m_invIA = bA->m_invI;
		HX_STACK_LINE(375)
		this->m_invIB = bB->m_invI;
		HX_STACK_LINE(378)
		{
			HX_STACK_LINE(379)
			::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Math_obj::mulMV(xf1->R,this->m_localXAxis1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(379)
			this->m_axis->setV(_g2);
			HX_STACK_LINE(381)
			this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
			HX_STACK_LINE(383)
			this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
			HX_STACK_LINE(385)
			this->m_motorMass = (((this->m_invMassA + this->m_invMassB) + ((this->m_invIA * this->m_a1) * this->m_a1)) + ((this->m_invIB * this->m_a2) * this->m_a2));
			HX_STACK_LINE(386)
			if (((this->m_motorMass > 2.2250738585072014e-308))){
				HX_STACK_LINE(387)
				this->m_motorMass = (Float(1.0) / Float(this->m_motorMass));
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
			this->m_K->col1->y = ((i1 * this->m_s1) + (i2 * this->m_s2));
			HX_STACK_LINE(405)
			this->m_K->col1->z = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
			HX_STACK_LINE(406)
			this->m_K->col2->x = this->m_K->col1->y;
			HX_STACK_LINE(407)
			this->m_K->col2->y = (i1 + i2);
			HX_STACK_LINE(408)
			this->m_K->col2->z = ((i1 * this->m_a1) + (i2 * this->m_a2));
			HX_STACK_LINE(409)
			this->m_K->col3->x = this->m_K->col1->z;
			HX_STACK_LINE(410)
			this->m_K->col3->y = this->m_K->col2->z;
			HX_STACK_LINE(411)
			this->m_K->col3->z = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		}
		HX_STACK_LINE(415)
		if ((this->m_enableLimit)){
			HX_STACK_LINE(418)
			Float jointTransition = ((this->m_axis->x * dX) + (this->m_axis->y * dY));		HX_STACK_VAR(jointTransition,"jointTransition");
			HX_STACK_LINE(419)
			Float _g4 = ::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(419)
			if (((_g4 < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
				HX_STACK_LINE(421)
				this->m_limitState = (int)3;
			}
			else{
				HX_STACK_LINE(423)
				if (((jointTransition <= this->m_lowerTranslation))){
					HX_STACK_LINE(425)
					if (((this->m_limitState != (int)1))){
						HX_STACK_LINE(427)
						this->m_limitState = (int)1;
						HX_STACK_LINE(428)
						this->m_impulse->z = 0.0;
					}
				}
				else{
					HX_STACK_LINE(431)
					if (((jointTransition >= this->m_upperTranslation))){
						HX_STACK_LINE(433)
						if (((this->m_limitState != (int)2))){
							HX_STACK_LINE(435)
							this->m_limitState = (int)2;
							HX_STACK_LINE(436)
							this->m_impulse->z = 0.0;
						}
					}
					else{
						HX_STACK_LINE(441)
						this->m_limitState = (int)0;
						HX_STACK_LINE(442)
						this->m_impulse->z = 0.0;
					}
				}
			}
		}
		else{
			HX_STACK_LINE(447)
			this->m_limitState = (int)0;
		}
		HX_STACK_LINE(450)
		if (((this->m_enableMotor == false))){
			HX_STACK_LINE(452)
			this->m_motorImpulse = 0.0;
		}
		HX_STACK_LINE(455)
		if ((step->warmStarting)){
			HX_STACK_LINE(458)
			hx::MultEq(this->m_impulse->x,step->dtRatio);
			HX_STACK_LINE(459)
			hx::MultEq(this->m_impulse->y,step->dtRatio);
			HX_STACK_LINE(460)
			hx::MultEq(this->m_motorImpulse,step->dtRatio);
			HX_STACK_LINE(463)
			Float PX = ((this->m_impulse->x * this->m_perp->x) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->x));		HX_STACK_VAR(PX,"PX");
			HX_STACK_LINE(464)
			Float PY = ((this->m_impulse->x * this->m_perp->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_axis->y));		HX_STACK_VAR(PY,"PY");
			HX_STACK_LINE(465)
			Float L1 = (((this->m_impulse->x * this->m_s1) + this->m_impulse->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_a1));		HX_STACK_VAR(L1,"L1");
			HX_STACK_LINE(466)
			Float L2 = (((this->m_impulse->x * this->m_s2) + this->m_impulse->y) + (((this->m_motorImpulse + this->m_impulse->z)) * this->m_a2));		HX_STACK_VAR(L2,"L2");
			HX_STACK_LINE(469)
			hx::SubEq(bA->m_linearVelocity->x,(this->m_invMassA * PX));
			HX_STACK_LINE(470)
			hx::SubEq(bA->m_linearVelocity->y,(this->m_invMassA * PY));
			HX_STACK_LINE(472)
			hx::SubEq(bA->m_angularVelocity,(this->m_invIA * L1));
			HX_STACK_LINE(475)
			hx::AddEq(bB->m_linearVelocity->x,(this->m_invMassB * PX));
			HX_STACK_LINE(476)
			hx::AddEq(bB->m_linearVelocity->y,(this->m_invMassB * PY));
			HX_STACK_LINE(478)
			hx::AddEq(bB->m_angularVelocity,(this->m_invIB * L2));
		}
		else{
			HX_STACK_LINE(482)
			this->m_impulse->setZero();
			HX_STACK_LINE(483)
			this->m_motorImpulse = 0.0;
		}
	}
return null();
}


Void B2PrismaticJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","solveVelocityConstraints",0x577af4e0,"box2D.dynamics.joints.B2PrismaticJoint.solveVelocityConstraints","box2D/dynamics/joints/B2PrismaticJoint.hx",487,0x93be09d5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(488)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(489)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(491)
		::box2D::common::math::B2Vec2 v1 = bA->m_linearVelocity;		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(492)
		Float w1 = bA->m_angularVelocity;		HX_STACK_VAR(w1,"w1");
		HX_STACK_LINE(493)
		::box2D::common::math::B2Vec2 v2 = bB->m_linearVelocity;		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(494)
		Float w2 = bB->m_angularVelocity;		HX_STACK_VAR(w2,"w2");
		HX_STACK_LINE(496)
		Float PX;		HX_STACK_VAR(PX,"PX");
		HX_STACK_LINE(497)
		Float PY;		HX_STACK_VAR(PY,"PY");
		HX_STACK_LINE(498)
		Float L1;		HX_STACK_VAR(L1,"L1");
		HX_STACK_LINE(499)
		Float L2;		HX_STACK_VAR(L2,"L2");
		HX_STACK_LINE(502)
		if (((bool(this->m_enableMotor) && bool((this->m_limitState != (int)3))))){
			HX_STACK_LINE(505)
			Float Cdot = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));		HX_STACK_VAR(Cdot,"Cdot");
			HX_STACK_LINE(506)
			Float impulse = (this->m_motorMass * ((this->m_motorSpeed - Cdot)));		HX_STACK_VAR(impulse,"impulse");
			HX_STACK_LINE(507)
			Float oldImpulse = this->m_motorImpulse;		HX_STACK_VAR(oldImpulse,"oldImpulse");
			HX_STACK_LINE(508)
			Float maxImpulse = (step->dt * this->m_maxMotorForce);		HX_STACK_VAR(maxImpulse,"maxImpulse");
			HX_STACK_LINE(509)
			Float _g = ::box2D::common::math::B2Math_obj::clamp((this->m_motorImpulse + impulse),-(maxImpulse),maxImpulse);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(509)
			this->m_motorImpulse = _g;
			HX_STACK_LINE(510)
			impulse = (this->m_motorImpulse - oldImpulse);
			HX_STACK_LINE(512)
			PX = (impulse * this->m_axis->x);
			HX_STACK_LINE(513)
			PY = (impulse * this->m_axis->y);
			HX_STACK_LINE(514)
			L1 = (impulse * this->m_a1);
			HX_STACK_LINE(515)
			L2 = (impulse * this->m_a2);
			HX_STACK_LINE(517)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_STACK_LINE(518)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_STACK_LINE(519)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_STACK_LINE(521)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_STACK_LINE(522)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_STACK_LINE(523)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_STACK_LINE(527)
		Float Cdot1X = ((((this->m_perp->x * ((v2->x - v1->x))) + (this->m_perp->y * ((v2->y - v1->y)))) + (this->m_s2 * w2)) - (this->m_s1 * w1));		HX_STACK_VAR(Cdot1X,"Cdot1X");
		HX_STACK_LINE(528)
		Float Cdot1Y = (w2 - w1);		HX_STACK_VAR(Cdot1Y,"Cdot1Y");
		HX_STACK_LINE(530)
		if (((bool(this->m_enableLimit) && bool((this->m_limitState != (int)0))))){
			HX_STACK_LINE(534)
			Float Cdot2 = ((((this->m_axis->x * ((v2->x - v1->x))) + (this->m_axis->y * ((v2->y - v1->y)))) + (this->m_a2 * w2)) - (this->m_a1 * w1));		HX_STACK_VAR(Cdot2,"Cdot2");
			HX_STACK_LINE(536)
			::box2D::common::math::B2Vec3 f1 = this->m_impulse->copy();		HX_STACK_VAR(f1,"f1");
			HX_STACK_LINE(537)
			::box2D::common::math::B2Vec3 _g1 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(537)
			::box2D::common::math::B2Vec3 df = this->m_K->solve33(_g1,-(Cdot1X),-(Cdot1Y),-(Cdot2));		HX_STACK_VAR(df,"df");
			HX_STACK_LINE(539)
			this->m_impulse->add(df);
			HX_STACK_LINE(541)
			if (((this->m_limitState == (int)1))){
				HX_STACK_LINE(543)
				Float _g2 = ::box2D::common::math::B2Math_obj::max(this->m_impulse->z,0.0);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(543)
				this->m_impulse->z = _g2;
			}
			else{
				HX_STACK_LINE(545)
				if (((this->m_limitState == (int)2))){
					HX_STACK_LINE(547)
					Float _g3 = ::box2D::common::math::B2Math_obj::min(this->m_impulse->z,0.0);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(547)
					this->m_impulse->z = _g3;
				}
			}
			HX_STACK_LINE(552)
			Float bX = (-(Cdot1X) - (((this->m_impulse->z - f1->z)) * this->m_K->col3->x));		HX_STACK_VAR(bX,"bX");
			HX_STACK_LINE(553)
			Float bY = (-(Cdot1Y) - (((this->m_impulse->z - f1->z)) * this->m_K->col3->y));		HX_STACK_VAR(bY,"bY");
			HX_STACK_LINE(554)
			::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(554)
			::box2D::common::math::B2Vec2 f2r = this->m_K->solve22(_g4,bX,bY);		HX_STACK_VAR(f2r,"f2r");
			HX_STACK_LINE(555)
			hx::AddEq(f2r->x,f1->x);
			HX_STACK_LINE(556)
			hx::AddEq(f2r->y,f1->y);
			HX_STACK_LINE(557)
			this->m_impulse->x = f2r->x;
			HX_STACK_LINE(558)
			this->m_impulse->y = f2r->y;
			HX_STACK_LINE(560)
			df->x = (this->m_impulse->x - f1->x);
			HX_STACK_LINE(561)
			df->y = (this->m_impulse->y - f1->y);
			HX_STACK_LINE(562)
			df->z = (this->m_impulse->z - f1->z);
			HX_STACK_LINE(564)
			PX = ((df->x * this->m_perp->x) + (df->z * this->m_axis->x));
			HX_STACK_LINE(565)
			PY = ((df->x * this->m_perp->y) + (df->z * this->m_axis->y));
			HX_STACK_LINE(566)
			L1 = (((df->x * this->m_s1) + df->y) + (df->z * this->m_a1));
			HX_STACK_LINE(567)
			L2 = (((df->x * this->m_s2) + df->y) + (df->z * this->m_a2));
			HX_STACK_LINE(569)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_STACK_LINE(570)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_STACK_LINE(571)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_STACK_LINE(573)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_STACK_LINE(574)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_STACK_LINE(575)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		else{
			HX_STACK_LINE(580)
			::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(580)
			::box2D::common::math::B2Vec2 df2 = this->m_K->solve22(_g5,-(Cdot1X),-(Cdot1Y));		HX_STACK_VAR(df2,"df2");
			HX_STACK_LINE(581)
			hx::AddEq(this->m_impulse->x,df2->x);
			HX_STACK_LINE(582)
			hx::AddEq(this->m_impulse->y,df2->y);
			HX_STACK_LINE(584)
			PX = (df2->x * this->m_perp->x);
			HX_STACK_LINE(585)
			PY = (df2->x * this->m_perp->y);
			HX_STACK_LINE(586)
			L1 = ((df2->x * this->m_s1) + df2->y);
			HX_STACK_LINE(587)
			L2 = ((df2->x * this->m_s2) + df2->y);
			HX_STACK_LINE(589)
			hx::SubEq(v1->x,(this->m_invMassA * PX));
			HX_STACK_LINE(590)
			hx::SubEq(v1->y,(this->m_invMassA * PY));
			HX_STACK_LINE(591)
			hx::SubEq(w1,(this->m_invIA * L1));
			HX_STACK_LINE(593)
			hx::AddEq(v2->x,(this->m_invMassB * PX));
			HX_STACK_LINE(594)
			hx::AddEq(v2->y,(this->m_invMassB * PY));
			HX_STACK_LINE(595)
			hx::AddEq(w2,(this->m_invIB * L2));
		}
		HX_STACK_LINE(598)
		bA->m_linearVelocity->setV(v1);
		HX_STACK_LINE(599)
		bA->m_angularVelocity = w1;
		HX_STACK_LINE(600)
		bB->m_linearVelocity->setV(v2);
		HX_STACK_LINE(601)
		bB->m_angularVelocity = w2;
	}
return null();
}


bool B2PrismaticJoint_obj::solvePositionConstraints( Float baumgarte){
	HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJoint","solvePositionConstraints",0x8f5709d4,"box2D.dynamics.joints.B2PrismaticJoint.solvePositionConstraints","box2D/dynamics/joints/B2PrismaticJoint.hx",605,0x93be09d5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baumgarte,"baumgarte")
	HX_STACK_LINE(609)
	Float limitC;		HX_STACK_VAR(limitC,"limitC");
	HX_STACK_LINE(610)
	Float oldLimitImpulse;		HX_STACK_VAR(oldLimitImpulse,"oldLimitImpulse");
	HX_STACK_LINE(612)
	::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
	HX_STACK_LINE(613)
	::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
	HX_STACK_LINE(615)
	::box2D::common::math::B2Vec2 c1 = bA->m_sweep->c;		HX_STACK_VAR(c1,"c1");
	HX_STACK_LINE(616)
	Float a1 = bA->m_sweep->a;		HX_STACK_VAR(a1,"a1");
	HX_STACK_LINE(618)
	::box2D::common::math::B2Vec2 c2 = bB->m_sweep->c;		HX_STACK_VAR(c2,"c2");
	HX_STACK_LINE(619)
	Float a2 = bB->m_sweep->a;		HX_STACK_VAR(a2,"a2");
	HX_STACK_LINE(621)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(622)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(624)
	Float m1;		HX_STACK_VAR(m1,"m1");
	HX_STACK_LINE(625)
	Float m2;		HX_STACK_VAR(m2,"m2");
	HX_STACK_LINE(626)
	Float i1;		HX_STACK_VAR(i1,"i1");
	HX_STACK_LINE(627)
	Float i2;		HX_STACK_VAR(i2,"i2");
	HX_STACK_LINE(630)
	Float linearError = 0.0;		HX_STACK_VAR(linearError,"linearError");
	HX_STACK_LINE(631)
	Float angularError = 0.0;		HX_STACK_VAR(angularError,"angularError");
	HX_STACK_LINE(632)
	bool active = false;		HX_STACK_VAR(active,"active");
	HX_STACK_LINE(633)
	Float C2 = 0.0;		HX_STACK_VAR(C2,"C2");
	HX_STACK_LINE(635)
	::box2D::common::math::B2Mat22 R1 = ::box2D::common::math::B2Mat22_obj::fromAngle(a1);		HX_STACK_VAR(R1,"R1");
	HX_STACK_LINE(636)
	::box2D::common::math::B2Mat22 R2 = ::box2D::common::math::B2Mat22_obj::fromAngle(a2);		HX_STACK_VAR(R2,"R2");
	HX_STACK_LINE(639)
	tMat = R1;
	HX_STACK_LINE(640)
	Float r1X = (this->m_localAnchor1->x - this->m_localCenterA->x);		HX_STACK_VAR(r1X,"r1X");
	HX_STACK_LINE(641)
	Float r1Y = (this->m_localAnchor1->y - this->m_localCenterA->y);		HX_STACK_VAR(r1Y,"r1Y");
	HX_STACK_LINE(642)
	tX = ((tMat->col1->x * r1X) + (tMat->col2->x * r1Y));
	HX_STACK_LINE(643)
	r1Y = ((tMat->col1->y * r1X) + (tMat->col2->y * r1Y));
	HX_STACK_LINE(644)
	r1X = tX;
	HX_STACK_LINE(646)
	tMat = R2;
	HX_STACK_LINE(647)
	Float r2X = (this->m_localAnchor2->x - this->m_localCenterB->x);		HX_STACK_VAR(r2X,"r2X");
	HX_STACK_LINE(648)
	Float r2Y = (this->m_localAnchor2->y - this->m_localCenterB->y);		HX_STACK_VAR(r2Y,"r2Y");
	HX_STACK_LINE(649)
	tX = ((tMat->col1->x * r2X) + (tMat->col2->x * r2Y));
	HX_STACK_LINE(650)
	r2Y = ((tMat->col1->y * r2X) + (tMat->col2->y * r2Y));
	HX_STACK_LINE(651)
	r2X = tX;
	HX_STACK_LINE(653)
	Float dX = (((c2->x + r2X) - c1->x) - r1X);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(654)
	Float dY = (((c2->y + r2Y) - c1->y) - r1Y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(656)
	if ((this->m_enableLimit)){
		HX_STACK_LINE(658)
		::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localXAxis1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(658)
		this->m_axis = _g;
		HX_STACK_LINE(661)
		this->m_a1 = ((((dX + r1X)) * this->m_axis->y) - (((dY + r1Y)) * this->m_axis->x));
		HX_STACK_LINE(663)
		this->m_a2 = ((r2X * this->m_axis->y) - (r2Y * this->m_axis->x));
		HX_STACK_LINE(665)
		Float translation = ((this->m_axis->x * dX) + (this->m_axis->y * dY));		HX_STACK_VAR(translation,"translation");
		HX_STACK_LINE(666)
		Float _g1 = ::box2D::common::math::B2Math_obj::abs((this->m_upperTranslation - this->m_lowerTranslation));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(666)
		if (((_g1 < (2.0 * ::box2D::common::B2Settings_obj::b2_linearSlop)))){
			HX_STACK_LINE(669)
			Float _g2 = ::box2D::common::math::B2Math_obj::clamp(translation,-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),::box2D::common::B2Settings_obj::b2_maxLinearCorrection);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(669)
			C2 = _g2;
			HX_STACK_LINE(670)
			Float _g3 = ::box2D::common::math::B2Math_obj::abs(translation);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(670)
			linearError = _g3;
			HX_STACK_LINE(671)
			active = true;
		}
		else{
			HX_STACK_LINE(673)
			if (((translation <= this->m_lowerTranslation))){
				HX_STACK_LINE(676)
				Float _g4 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_lowerTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(676)
				C2 = _g4;
				HX_STACK_LINE(677)
				linearError = (this->m_lowerTranslation - translation);
				HX_STACK_LINE(678)
				active = true;
			}
			else{
				HX_STACK_LINE(680)
				if (((translation >= this->m_upperTranslation))){
					HX_STACK_LINE(683)
					Float _g5 = ::box2D::common::math::B2Math_obj::clamp(((translation - this->m_upperTranslation) + ::box2D::common::B2Settings_obj::b2_linearSlop),0.0,::box2D::common::B2Settings_obj::b2_maxLinearCorrection);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(683)
					C2 = _g5;
					HX_STACK_LINE(684)
					linearError = (translation - this->m_upperTranslation);
					HX_STACK_LINE(685)
					active = true;
				}
			}
		}
	}
	HX_STACK_LINE(689)
	::box2D::common::math::B2Vec2 _g6 = ::box2D::common::math::B2Math_obj::mulMV(R1,this->m_localYAxis1);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(689)
	this->m_perp = _g6;
	HX_STACK_LINE(692)
	this->m_s1 = ((((dX + r1X)) * this->m_perp->y) - (((dY + r1Y)) * this->m_perp->x));
	HX_STACK_LINE(694)
	this->m_s2 = ((r2X * this->m_perp->y) - (r2Y * this->m_perp->x));
	HX_STACK_LINE(696)
	::box2D::common::math::B2Vec3 impulse = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(impulse,"impulse");
	HX_STACK_LINE(697)
	Float C1X = ((this->m_perp->x * dX) + (this->m_perp->y * dY));		HX_STACK_VAR(C1X,"C1X");
	HX_STACK_LINE(698)
	Float C1Y = ((a2 - a1) - this->m_refAngle);		HX_STACK_VAR(C1Y,"C1Y");
	HX_STACK_LINE(700)
	Float _g7 = ::box2D::common::math::B2Math_obj::abs(C1X);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(700)
	Float _g8 = ::box2D::common::math::B2Math_obj::max(linearError,_g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(700)
	linearError = _g8;
	HX_STACK_LINE(701)
	Float _g9 = ::box2D::common::math::B2Math_obj::abs(C1Y);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(701)
	angularError = _g9;
	HX_STACK_LINE(703)
	if ((active)){
		HX_STACK_LINE(705)
		m1 = this->m_invMassA;
		HX_STACK_LINE(706)
		m2 = this->m_invMassB;
		HX_STACK_LINE(707)
		i1 = this->m_invIA;
		HX_STACK_LINE(708)
		i2 = this->m_invIB;
		HX_STACK_LINE(710)
		this->m_K->col1->x = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));
		HX_STACK_LINE(711)
		this->m_K->col1->y = ((i1 * this->m_s1) + (i2 * this->m_s2));
		HX_STACK_LINE(712)
		this->m_K->col1->z = (((i1 * this->m_s1) * this->m_a1) + ((i2 * this->m_s2) * this->m_a2));
		HX_STACK_LINE(713)
		this->m_K->col2->x = this->m_K->col1->y;
		HX_STACK_LINE(714)
		this->m_K->col2->y = (i1 + i2);
		HX_STACK_LINE(715)
		this->m_K->col2->z = ((i1 * this->m_a1) + (i2 * this->m_a2));
		HX_STACK_LINE(716)
		this->m_K->col3->x = this->m_K->col1->z;
		HX_STACK_LINE(717)
		this->m_K->col3->y = this->m_K->col2->z;
		HX_STACK_LINE(718)
		this->m_K->col3->z = (((m1 + m2) + ((i1 * this->m_a1) * this->m_a1)) + ((i2 * this->m_a2) * this->m_a2));
		HX_STACK_LINE(720)
		this->m_K->solve33(impulse,-(C1X),-(C1Y),-(C2));
	}
	else{
		HX_STACK_LINE(724)
		m1 = this->m_invMassA;
		HX_STACK_LINE(725)
		m2 = this->m_invMassB;
		HX_STACK_LINE(726)
		i1 = this->m_invIA;
		HX_STACK_LINE(727)
		i2 = this->m_invIB;
		HX_STACK_LINE(729)
		Float k11 = (((m1 + m2) + ((i1 * this->m_s1) * this->m_s1)) + ((i2 * this->m_s2) * this->m_s2));		HX_STACK_VAR(k11,"k11");
		HX_STACK_LINE(730)
		Float k12 = ((i1 * this->m_s1) + (i2 * this->m_s2));		HX_STACK_VAR(k12,"k12");
		HX_STACK_LINE(731)
		Float k22 = (i1 + i2);		HX_STACK_VAR(k22,"k22");
		HX_STACK_LINE(733)
		this->m_K->col1->set(k11,k12,0.0);
		HX_STACK_LINE(734)
		this->m_K->col2->set(k12,k22,0.0);
		HX_STACK_LINE(736)
		::box2D::common::math::B2Vec2 _g10 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(736)
		::box2D::common::math::B2Vec2 impulse1 = this->m_K->solve22(_g10,-(C1X),-(C1Y));		HX_STACK_VAR(impulse1,"impulse1");
		HX_STACK_LINE(737)
		impulse->x = impulse1->x;
		HX_STACK_LINE(738)
		impulse->y = impulse1->y;
		HX_STACK_LINE(739)
		impulse->z = 0.0;
	}
	HX_STACK_LINE(742)
	Float PX = ((impulse->x * this->m_perp->x) + (impulse->z * this->m_axis->x));		HX_STACK_VAR(PX,"PX");
	HX_STACK_LINE(743)
	Float PY = ((impulse->x * this->m_perp->y) + (impulse->z * this->m_axis->y));		HX_STACK_VAR(PY,"PY");
	HX_STACK_LINE(744)
	Float L1 = (((impulse->x * this->m_s1) + impulse->y) + (impulse->z * this->m_a1));		HX_STACK_VAR(L1,"L1");
	HX_STACK_LINE(745)
	Float L2 = (((impulse->x * this->m_s2) + impulse->y) + (impulse->z * this->m_a2));		HX_STACK_VAR(L2,"L2");
	HX_STACK_LINE(747)
	hx::SubEq(c1->x,(this->m_invMassA * PX));
	HX_STACK_LINE(748)
	hx::SubEq(c1->y,(this->m_invMassA * PY));
	HX_STACK_LINE(749)
	hx::SubEq(a1,(this->m_invIA * L1));
	HX_STACK_LINE(751)
	hx::AddEq(c2->x,(this->m_invMassB * PX));
	HX_STACK_LINE(752)
	hx::AddEq(c2->y,(this->m_invMassB * PY));
	HX_STACK_LINE(753)
	hx::AddEq(a2,(this->m_invIB * L2));
	HX_STACK_LINE(757)
	bA->m_sweep->a = a1;
	HX_STACK_LINE(759)
	bB->m_sweep->a = a2;
	HX_STACK_LINE(760)
	bA->synchronizeTransform();
	HX_STACK_LINE(761)
	bB->synchronizeTransform();
	HX_STACK_LINE(763)
	return (bool((linearError <= ::box2D::common::B2Settings_obj::b2_linearSlop)) && bool((angularError <= ::box2D::common::B2Settings_obj::b2_angularSlop)));
}



B2PrismaticJoint_obj::B2PrismaticJoint_obj()
{
}

void B2PrismaticJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PrismaticJoint);
	HX_MARK_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_MARK_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_MARK_MEMBER_NAME(m_localXAxis1,"m_localXAxis1");
	HX_MARK_MEMBER_NAME(m_localYAxis1,"m_localYAxis1");
	HX_MARK_MEMBER_NAME(m_refAngle,"m_refAngle");
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

void B2PrismaticJoint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_localAnchor1,"m_localAnchor1");
	HX_VISIT_MEMBER_NAME(m_localAnchor2,"m_localAnchor2");
	HX_VISIT_MEMBER_NAME(m_localXAxis1,"m_localXAxis1");
	HX_VISIT_MEMBER_NAME(m_localYAxis1,"m_localYAxis1");
	HX_VISIT_MEMBER_NAME(m_refAngle,"m_refAngle");
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

Dynamic B2PrismaticJoint_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"m_refAngle") ) { return m_refAngle; }
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

Dynamic B2PrismaticJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_K") ) { m_K=inValue.Cast< ::box2D::common::math::B2Mat33 >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"m_impulse") ) { m_impulse=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_refAngle") ) { m_refAngle=inValue.Cast< Float >(); return inValue; }
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

void B2PrismaticJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchor1"));
	outFields->push(HX_CSTRING("m_localAnchor2"));
	outFields->push(HX_CSTRING("m_localXAxis1"));
	outFields->push(HX_CSTRING("m_localYAxis1"));
	outFields->push(HX_CSTRING("m_refAngle"));
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
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJoint_obj,m_localAnchor1),HX_CSTRING("m_localAnchor1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJoint_obj,m_localAnchor2),HX_CSTRING("m_localAnchor2")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJoint_obj,m_localXAxis1),HX_CSTRING("m_localXAxis1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJoint_obj,m_localYAxis1),HX_CSTRING("m_localYAxis1")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_refAngle),HX_CSTRING("m_refAngle")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJoint_obj,m_axis),HX_CSTRING("m_axis")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJoint_obj,m_perp),HX_CSTRING("m_perp")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_s1),HX_CSTRING("m_s1")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_s2),HX_CSTRING("m_s2")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_a1),HX_CSTRING("m_a1")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_a2),HX_CSTRING("m_a2")},
	{hx::fsObject /*::box2D::common::math::B2Mat33*/ ,(int)offsetof(B2PrismaticJoint_obj,m_K),HX_CSTRING("m_K")},
	{hx::fsObject /*::box2D::common::math::B2Vec3*/ ,(int)offsetof(B2PrismaticJoint_obj,m_impulse),HX_CSTRING("m_impulse")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_motorMass),HX_CSTRING("m_motorMass")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_motorImpulse),HX_CSTRING("m_motorImpulse")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_lowerTranslation),HX_CSTRING("m_lowerTranslation")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_upperTranslation),HX_CSTRING("m_upperTranslation")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_maxMotorForce),HX_CSTRING("m_maxMotorForce")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJoint_obj,m_motorSpeed),HX_CSTRING("m_motorSpeed")},
	{hx::fsBool,(int)offsetof(B2PrismaticJoint_obj,m_enableLimit),HX_CSTRING("m_enableLimit")},
	{hx::fsBool,(int)offsetof(B2PrismaticJoint_obj,m_enableMotor),HX_CSTRING("m_enableMotor")},
	{hx::fsInt,(int)offsetof(B2PrismaticJoint_obj,m_limitState),HX_CSTRING("m_limitState")},
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
	HX_CSTRING("getMotorForce"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchor1"),
	HX_CSTRING("m_localAnchor2"),
	HX_CSTRING("m_localXAxis1"),
	HX_CSTRING("m_localYAxis1"),
	HX_CSTRING("m_refAngle"),
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
	HX_MARK_MEMBER_NAME(B2PrismaticJoint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PrismaticJoint_obj::__mClass,"__mClass");
};

#endif

Class B2PrismaticJoint_obj::__mClass;

void B2PrismaticJoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PrismaticJoint"), hx::TCanCast< B2PrismaticJoint_obj> ,sStaticFields,sMemberFields,
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

void B2PrismaticJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
