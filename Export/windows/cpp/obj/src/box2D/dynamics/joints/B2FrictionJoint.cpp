#include <hxcpp.h>

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
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJoint
#include <box2D/dynamics/joints/B2FrictionJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJointDef
#include <box2D/dynamics/joints/B2FrictionJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2FrictionJoint_obj::__construct(::box2D::dynamics::joints::B2FrictionJointDef def)
{
HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","new",0x53c2a1d6,"box2D.dynamics.joints.B2FrictionJoint.new","box2D/dynamics/joints/B2FrictionJoint.hx",93,0xaf05cabb)
HX_STACK_THIS(this)
HX_STACK_ARG(def,"def")
{
	HX_STACK_LINE(94)
	super::__construct(def);
	HX_STACK_LINE(96)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(96)
	this->m_localAnchorA = _g;
	HX_STACK_LINE(97)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(97)
	this->m_localAnchorB = _g1;
	HX_STACK_LINE(98)
	::box2D::common::math::B2Mat22 _g2 = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(98)
	this->m_linearMass = _g2;
	HX_STACK_LINE(99)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(99)
	this->m_linearImpulse = _g3;
	HX_STACK_LINE(101)
	this->m_localAnchorA->setV(def->localAnchorA);
	HX_STACK_LINE(102)
	this->m_localAnchorB->setV(def->localAnchorB);
	HX_STACK_LINE(104)
	this->m_linearMass->setZero();
	HX_STACK_LINE(105)
	this->m_angularMass = 0.0;
	HX_STACK_LINE(107)
	this->m_linearImpulse->setZero();
	HX_STACK_LINE(108)
	this->m_angularImpulse = 0.0;
	HX_STACK_LINE(110)
	this->m_maxForce = def->maxForce;
	HX_STACK_LINE(111)
	this->m_maxTorque = def->maxTorque;
}
;
	return null();
}

//B2FrictionJoint_obj::~B2FrictionJoint_obj() { }

Dynamic B2FrictionJoint_obj::__CreateEmpty() { return  new B2FrictionJoint_obj; }
hx::ObjectPtr< B2FrictionJoint_obj > B2FrictionJoint_obj::__new(::box2D::dynamics::joints::B2FrictionJointDef def)
{  hx::ObjectPtr< B2FrictionJoint_obj > result = new B2FrictionJoint_obj();
	result->__construct(def);
	return result;}

Dynamic B2FrictionJoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2FrictionJoint_obj > result = new B2FrictionJoint_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::common::math::B2Vec2 B2FrictionJoint_obj::getAnchorA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","getAnchorA",0xf4c15b80,"box2D.dynamics.joints.B2FrictionJoint.getAnchorA","box2D/dynamics/joints/B2FrictionJoint.hx",50,0xaf05cabb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(50)
	return this->m_bodyA->getWorldPoint(this->m_localAnchorA);
}


::box2D::common::math::B2Vec2 B2FrictionJoint_obj::getAnchorB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","getAnchorB",0xf4c15b81,"box2D.dynamics.joints.B2FrictionJoint.getAnchorB","box2D/dynamics/joints/B2FrictionJoint.hx",54,0xaf05cabb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(54)
	return this->m_bodyB->getWorldPoint(this->m_localAnchorB);
}


::box2D::common::math::B2Vec2 B2FrictionJoint_obj::getReactionForce( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","getReactionForce",0x1e1f7bd6,"box2D.dynamics.joints.B2FrictionJoint.getReactionForce","box2D/dynamics/joints/B2FrictionJoint.hx",60,0xaf05cabb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(60)
	return ::box2D::common::math::B2Vec2_obj::__new((inv_dt * this->m_linearImpulse->x),(inv_dt * this->m_linearImpulse->y));
}


Float B2FrictionJoint_obj::getReactionTorque( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","getReactionTorque",0xd6769a7f,"box2D.dynamics.joints.B2FrictionJoint.getReactionTorque","box2D/dynamics/joints/B2FrictionJoint.hx",67,0xaf05cabb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(67)
	return (inv_dt * this->m_angularImpulse);
}


Void B2FrictionJoint_obj::setMaxForce( Float force){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","setMaxForce",0xa28105df,"box2D.dynamics.joints.B2FrictionJoint.setMaxForce","box2D/dynamics/joints/B2FrictionJoint.hx",72,0xaf05cabb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(force,"force")
		HX_STACK_LINE(72)
		this->m_maxForce = force;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,setMaxForce,(void))

Float B2FrictionJoint_obj::getMaxForce( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","getMaxForce",0x9813fed3,"box2D.dynamics.joints.B2FrictionJoint.getMaxForce","box2D/dynamics/joints/B2FrictionJoint.hx",77,0xaf05cabb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return this->m_maxForce;
}


HX_DEFINE_DYNAMIC_FUNC0(B2FrictionJoint_obj,getMaxForce,return )

Void B2FrictionJoint_obj::setMaxTorque( Float torque){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","setMaxTorque",0x276dd856,"box2D.dynamics.joints.B2FrictionJoint.setMaxTorque","box2D/dynamics/joints/B2FrictionJoint.hx",82,0xaf05cabb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(torque,"torque")
		HX_STACK_LINE(82)
		this->m_maxTorque = torque;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2FrictionJoint_obj,setMaxTorque,(void))

Float B2FrictionJoint_obj::getMaxTorque( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","getMaxTorque",0x1274b4e2,"box2D.dynamics.joints.B2FrictionJoint.getMaxTorque","box2D/dynamics/joints/B2FrictionJoint.hx",87,0xaf05cabb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(87)
	return this->m_maxTorque;
}


HX_DEFINE_DYNAMIC_FUNC0(B2FrictionJoint_obj,getMaxTorque,return )

Void B2FrictionJoint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","initVelocityConstraints",0x170f899f,"box2D.dynamics.joints.B2FrictionJoint.initVelocityConstraints","box2D/dynamics/joints/B2FrictionJoint.hx",114,0xaf05cabb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(115)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(116)
		Float tX;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(118)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(119)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(123)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(124)
		Float rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(rAX,"rAX");
		HX_STACK_LINE(125)
		Float rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(rAY,"rAY");
		HX_STACK_LINE(126)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_STACK_LINE(127)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_STACK_LINE(128)
		rAX = tX;
		HX_STACK_LINE(130)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(131)
		Float rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(rBX,"rBX");
		HX_STACK_LINE(132)
		Float rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(rBY,"rBY");
		HX_STACK_LINE(133)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_STACK_LINE(134)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_STACK_LINE(135)
		rBX = tX;
		HX_STACK_LINE(146)
		Float mA = bA->m_invMass;		HX_STACK_VAR(mA,"mA");
		HX_STACK_LINE(147)
		Float mB = bB->m_invMass;		HX_STACK_VAR(mB,"mB");
		HX_STACK_LINE(148)
		Float iA = bA->m_invI;		HX_STACK_VAR(iA,"iA");
		HX_STACK_LINE(149)
		Float iB = bB->m_invI;		HX_STACK_VAR(iB,"iB");
		HX_STACK_LINE(151)
		::box2D::common::math::B2Mat22 K = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(K,"K");
		HX_STACK_LINE(152)
		K->col1->x = (mA + mB);
		HX_STACK_LINE(152)
		K->col2->x = 0.0;
		HX_STACK_LINE(153)
		K->col1->y = 0.0;
		HX_STACK_LINE(153)
		K->col2->y = (mA + mB);
		HX_STACK_LINE(155)
		hx::AddEq(K->col1->x,((iA * rAY) * rAY));
		HX_STACK_LINE(155)
		hx::AddEq(K->col2->x,((-(iA) * rAX) * rAY));
		HX_STACK_LINE(156)
		hx::AddEq(K->col1->y,((-(iA) * rAX) * rAY));
		HX_STACK_LINE(156)
		hx::AddEq(K->col2->y,((iA * rAX) * rAX));
		HX_STACK_LINE(158)
		hx::AddEq(K->col1->x,((iB * rBY) * rBY));
		HX_STACK_LINE(158)
		hx::AddEq(K->col2->x,((-(iB) * rBX) * rBY));
		HX_STACK_LINE(159)
		hx::AddEq(K->col1->y,((-(iB) * rBX) * rBY));
		HX_STACK_LINE(159)
		hx::AddEq(K->col2->y,((iB * rBX) * rBX));
		HX_STACK_LINE(161)
		K->getInverse(this->m_linearMass);
		HX_STACK_LINE(163)
		this->m_angularMass = (iA + iB);
		HX_STACK_LINE(164)
		if (((this->m_angularMass > 0.0))){
			HX_STACK_LINE(166)
			this->m_angularMass = (Float(1.0) / Float(this->m_angularMass));
		}
		HX_STACK_LINE(169)
		if ((step->warmStarting)){
			HX_STACK_LINE(172)
			hx::MultEq(this->m_linearImpulse->x,step->dtRatio);
			HX_STACK_LINE(173)
			hx::MultEq(this->m_linearImpulse->y,step->dtRatio);
			HX_STACK_LINE(174)
			hx::MultEq(this->m_angularImpulse,step->dtRatio);
			HX_STACK_LINE(176)
			::box2D::common::math::B2Vec2 P = this->m_linearImpulse;		HX_STACK_VAR(P,"P");
			HX_STACK_LINE(178)
			hx::SubEq(bA->m_linearVelocity->x,(mA * P->x));
			HX_STACK_LINE(179)
			hx::SubEq(bA->m_linearVelocity->y,(mA * P->y));
			HX_STACK_LINE(180)
			hx::SubEq(bA->m_angularVelocity,(iA * ((((rAX * P->y) - (rAY * P->x)) + this->m_angularImpulse))));
			HX_STACK_LINE(182)
			hx::AddEq(bB->m_linearVelocity->x,(mB * P->x));
			HX_STACK_LINE(183)
			hx::AddEq(bB->m_linearVelocity->y,(mB * P->y));
			HX_STACK_LINE(184)
			hx::AddEq(bB->m_angularVelocity,(iB * ((((rBX * P->y) - (rBY * P->x)) + this->m_angularImpulse))));
		}
		else{
			HX_STACK_LINE(188)
			this->m_linearImpulse->setZero();
			HX_STACK_LINE(189)
			this->m_angularImpulse = 0.0;
		}
	}
return null();
}


Void B2FrictionJoint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","solveVelocityConstraints",0xeb4c2ce4,"box2D.dynamics.joints.B2FrictionJoint.solveVelocityConstraints","box2D/dynamics/joints/B2FrictionJoint.hx",196,0xaf05cabb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(198)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(199)
		Float tX;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(201)
		::box2D::dynamics::B2Body bA = this->m_bodyA;		HX_STACK_VAR(bA,"bA");
		HX_STACK_LINE(202)
		::box2D::dynamics::B2Body bB = this->m_bodyB;		HX_STACK_VAR(bB,"bB");
		HX_STACK_LINE(204)
		::box2D::common::math::B2Vec2 vA = bA->m_linearVelocity;		HX_STACK_VAR(vA,"vA");
		HX_STACK_LINE(205)
		Float wA = bA->m_angularVelocity;		HX_STACK_VAR(wA,"wA");
		HX_STACK_LINE(206)
		::box2D::common::math::B2Vec2 vB = bB->m_linearVelocity;		HX_STACK_VAR(vB,"vB");
		HX_STACK_LINE(207)
		Float wB = bB->m_angularVelocity;		HX_STACK_VAR(wB,"wB");
		HX_STACK_LINE(209)
		Float mA = bA->m_invMass;		HX_STACK_VAR(mA,"mA");
		HX_STACK_LINE(210)
		Float mB = bB->m_invMass;		HX_STACK_VAR(mB,"mB");
		HX_STACK_LINE(211)
		Float iA = bA->m_invI;		HX_STACK_VAR(iA,"iA");
		HX_STACK_LINE(212)
		Float iB = bB->m_invI;		HX_STACK_VAR(iB,"iB");
		HX_STACK_LINE(215)
		tMat = bA->m_xf->R;
		HX_STACK_LINE(216)
		Float rAX = (this->m_localAnchorA->x - bA->m_sweep->localCenter->x);		HX_STACK_VAR(rAX,"rAX");
		HX_STACK_LINE(217)
		Float rAY = (this->m_localAnchorA->y - bA->m_sweep->localCenter->y);		HX_STACK_VAR(rAY,"rAY");
		HX_STACK_LINE(218)
		tX = ((tMat->col1->x * rAX) + (tMat->col2->x * rAY));
		HX_STACK_LINE(219)
		rAY = ((tMat->col1->y * rAX) + (tMat->col2->y * rAY));
		HX_STACK_LINE(220)
		rAX = tX;
		HX_STACK_LINE(222)
		tMat = bB->m_xf->R;
		HX_STACK_LINE(223)
		Float rBX = (this->m_localAnchorB->x - bB->m_sweep->localCenter->x);		HX_STACK_VAR(rBX,"rBX");
		HX_STACK_LINE(224)
		Float rBY = (this->m_localAnchorB->y - bB->m_sweep->localCenter->y);		HX_STACK_VAR(rBY,"rBY");
		HX_STACK_LINE(225)
		tX = ((tMat->col1->x * rBX) + (tMat->col2->x * rBY));
		HX_STACK_LINE(226)
		rBY = ((tMat->col1->y * rBX) + (tMat->col2->y * rBY));
		HX_STACK_LINE(227)
		rBX = tX;
		HX_STACK_LINE(229)
		Float maxImpulse;		HX_STACK_VAR(maxImpulse,"maxImpulse");
		HX_STACK_LINE(232)
		{
			HX_STACK_LINE(233)
			Float Cdot = (wB - wA);		HX_STACK_VAR(Cdot,"Cdot");
			HX_STACK_LINE(234)
			Float impulse = (-(this->m_angularMass) * Cdot);		HX_STACK_VAR(impulse,"impulse");
			HX_STACK_LINE(236)
			Float oldImpulse = this->m_angularImpulse;		HX_STACK_VAR(oldImpulse,"oldImpulse");
			HX_STACK_LINE(237)
			maxImpulse = (step->dt * this->m_maxTorque);
			HX_STACK_LINE(238)
			Float _g = ::box2D::common::math::B2Math_obj::clamp((this->m_angularImpulse + impulse),-(maxImpulse),maxImpulse);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(238)
			this->m_angularImpulse = _g;
			HX_STACK_LINE(239)
			impulse = (this->m_angularImpulse - oldImpulse);
			HX_STACK_LINE(241)
			hx::SubEq(wA,(iA * impulse));
			HX_STACK_LINE(242)
			hx::AddEq(wB,(iB * impulse));
		}
		HX_STACK_LINE(246)
		{
			HX_STACK_LINE(248)
			Float CdotX = (((vB->x - (wB * rBY)) - vA->x) + (wA * rAY));		HX_STACK_VAR(CdotX,"CdotX");
			HX_STACK_LINE(249)
			Float CdotY = (((vB->y + (wB * rBX)) - vA->y) - (wA * rAX));		HX_STACK_VAR(CdotY,"CdotY");
			HX_STACK_LINE(251)
			::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(-(CdotX),-(CdotY));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(251)
			::box2D::common::math::B2Vec2 impulseV = ::box2D::common::math::B2Math_obj::mulMV(this->m_linearMass,_g1);		HX_STACK_VAR(impulseV,"impulseV");
			HX_STACK_LINE(252)
			::box2D::common::math::B2Vec2 oldImpulseV = this->m_linearImpulse->copy();		HX_STACK_VAR(oldImpulseV,"oldImpulseV");
			HX_STACK_LINE(254)
			this->m_linearImpulse->add(impulseV);
			HX_STACK_LINE(256)
			maxImpulse = (step->dt * this->m_maxForce);
			HX_STACK_LINE(258)
			Float _g2 = this->m_linearImpulse->lengthSquared();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(258)
			if (((_g2 > (maxImpulse * maxImpulse)))){
				HX_STACK_LINE(260)
				this->m_linearImpulse->normalize();
				HX_STACK_LINE(261)
				this->m_linearImpulse->multiply(maxImpulse);
			}
			HX_STACK_LINE(264)
			::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::subtractVV(this->m_linearImpulse,oldImpulseV);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(264)
			impulseV = _g3;
			HX_STACK_LINE(266)
			hx::SubEq(vA->x,(mA * impulseV->x));
			HX_STACK_LINE(267)
			hx::SubEq(vA->y,(mA * impulseV->y));
			HX_STACK_LINE(268)
			hx::SubEq(wA,(iA * (((rAX * impulseV->y) - (rAY * impulseV->x)))));
			HX_STACK_LINE(270)
			hx::AddEq(vB->x,(mB * impulseV->x));
			HX_STACK_LINE(271)
			hx::AddEq(vB->y,(mB * impulseV->y));
			HX_STACK_LINE(272)
			hx::AddEq(wB,(iB * (((rBX * impulseV->y) - (rBY * impulseV->x)))));
		}
		HX_STACK_LINE(277)
		bA->m_angularVelocity = wA;
		HX_STACK_LINE(279)
		bB->m_angularVelocity = wB;
	}
return null();
}


bool B2FrictionJoint_obj::solvePositionConstraints( Float baumgarte){
	HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJoint","solvePositionConstraints",0x232841d8,"box2D.dynamics.joints.B2FrictionJoint.solvePositionConstraints","box2D/dynamics/joints/B2FrictionJoint.hx",287,0xaf05cabb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baumgarte,"baumgarte")
	HX_STACK_LINE(287)
	return true;
}



B2FrictionJoint_obj::B2FrictionJoint_obj()
{
}

void B2FrictionJoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2FrictionJoint);
	HX_MARK_MEMBER_NAME(m_localAnchorA,"m_localAnchorA");
	HX_MARK_MEMBER_NAME(m_localAnchorB,"m_localAnchorB");
	HX_MARK_MEMBER_NAME(m_linearMass,"m_linearMass");
	HX_MARK_MEMBER_NAME(m_angularMass,"m_angularMass");
	HX_MARK_MEMBER_NAME(m_linearImpulse,"m_linearImpulse");
	HX_MARK_MEMBER_NAME(m_angularImpulse,"m_angularImpulse");
	HX_MARK_MEMBER_NAME(m_maxForce,"m_maxForce");
	HX_MARK_MEMBER_NAME(m_maxTorque,"m_maxTorque");
	::box2D::dynamics::joints::B2Joint_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2FrictionJoint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_localAnchorA,"m_localAnchorA");
	HX_VISIT_MEMBER_NAME(m_localAnchorB,"m_localAnchorB");
	HX_VISIT_MEMBER_NAME(m_linearMass,"m_linearMass");
	HX_VISIT_MEMBER_NAME(m_angularMass,"m_angularMass");
	HX_VISIT_MEMBER_NAME(m_linearImpulse,"m_linearImpulse");
	HX_VISIT_MEMBER_NAME(m_angularImpulse,"m_angularImpulse");
	HX_VISIT_MEMBER_NAME(m_maxForce,"m_maxForce");
	HX_VISIT_MEMBER_NAME(m_maxTorque,"m_maxTorque");
	::box2D::dynamics::joints::B2Joint_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2FrictionJoint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"m_maxForce") ) { return m_maxForce; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setMaxForce") ) { return setMaxForce_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxForce") ) { return getMaxForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_maxTorque") ) { return m_maxTorque; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setMaxTorque") ) { return setMaxTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"getMaxTorque") ) { return getMaxTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"m_linearMass") ) { return m_linearMass; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_angularMass") ) { return m_angularMass; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { return m_localAnchorA; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { return m_localAnchorB; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_linearImpulse") ) { return m_linearImpulse; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		if (HX_FIELD_EQ(inName,"m_angularImpulse") ) { return m_angularImpulse; }
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

Dynamic B2FrictionJoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"m_maxForce") ) { m_maxForce=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_maxTorque") ) { m_maxTorque=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_linearMass") ) { m_linearMass=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_angularMass") ) { m_angularMass=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localAnchorA") ) { m_localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localAnchorB") ) { m_localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_linearImpulse") ) { m_linearImpulse=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_angularImpulse") ) { m_angularImpulse=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2FrictionJoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_localAnchorA"));
	outFields->push(HX_CSTRING("m_localAnchorB"));
	outFields->push(HX_CSTRING("m_linearMass"));
	outFields->push(HX_CSTRING("m_angularMass"));
	outFields->push(HX_CSTRING("m_linearImpulse"));
	outFields->push(HX_CSTRING("m_angularImpulse"));
	outFields->push(HX_CSTRING("m_maxForce"));
	outFields->push(HX_CSTRING("m_maxTorque"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2FrictionJoint_obj,m_localAnchorA),HX_CSTRING("m_localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2FrictionJoint_obj,m_localAnchorB),HX_CSTRING("m_localAnchorB")},
	{hx::fsObject /*::box2D::common::math::B2Mat22*/ ,(int)offsetof(B2FrictionJoint_obj,m_linearMass),HX_CSTRING("m_linearMass")},
	{hx::fsFloat,(int)offsetof(B2FrictionJoint_obj,m_angularMass),HX_CSTRING("m_angularMass")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2FrictionJoint_obj,m_linearImpulse),HX_CSTRING("m_linearImpulse")},
	{hx::fsFloat,(int)offsetof(B2FrictionJoint_obj,m_angularImpulse),HX_CSTRING("m_angularImpulse")},
	{hx::fsFloat,(int)offsetof(B2FrictionJoint_obj,m_maxForce),HX_CSTRING("m_maxForce")},
	{hx::fsFloat,(int)offsetof(B2FrictionJoint_obj,m_maxTorque),HX_CSTRING("m_maxTorque")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("setMaxForce"),
	HX_CSTRING("getMaxForce"),
	HX_CSTRING("setMaxTorque"),
	HX_CSTRING("getMaxTorque"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_localAnchorA"),
	HX_CSTRING("m_localAnchorB"),
	HX_CSTRING("m_linearMass"),
	HX_CSTRING("m_angularMass"),
	HX_CSTRING("m_linearImpulse"),
	HX_CSTRING("m_angularImpulse"),
	HX_CSTRING("m_maxForce"),
	HX_CSTRING("m_maxTorque"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2FrictionJoint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2FrictionJoint_obj::__mClass,"__mClass");
};

#endif

Class B2FrictionJoint_obj::__mClass;

void B2FrictionJoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2FrictionJoint"), hx::TCanCast< B2FrictionJoint_obj> ,sStaticFields,sMemberFields,
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

void B2FrictionJoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
