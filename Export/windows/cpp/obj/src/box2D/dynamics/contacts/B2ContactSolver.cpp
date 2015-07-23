#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldType
#include <box2D/collision/B2ManifoldType.h>
#endif
#ifndef INCLUDED_box2D_collision_B2WorldManifold
#include <box2D/collision/B2WorldManifold.h>
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
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraint
#include <box2D/dynamics/contacts/B2ContactConstraint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactSolver
#include <box2D/dynamics/contacts/B2ContactSolver.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2PositionSolverManifold
#include <box2D/dynamics/contacts/B2PositionSolverManifold.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactSolver_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactSolver","new",0x08cbbf63,"box2D.dynamics.contacts.B2ContactSolver.new","box2D/dynamics/contacts/B2ContactSolver.hx",38,0x75c0a5ce)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(932)
	this->m_constraintCount = (int)0;
	HX_STACK_LINE(44)
	::box2D::dynamics::B2TimeStep _g = ::box2D::dynamics::B2TimeStep_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	this->m_step = _g;
	HX_STACK_LINE(45)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(45)
	this->m_constraints = _g1;
}
;
	return null();
}

//B2ContactSolver_obj::~B2ContactSolver_obj() { }

Dynamic B2ContactSolver_obj::__CreateEmpty() { return  new B2ContactSolver_obj; }
hx::ObjectPtr< B2ContactSolver_obj > B2ContactSolver_obj::__new()
{  hx::ObjectPtr< B2ContactSolver_obj > result = new B2ContactSolver_obj();
	result->__construct();
	return result;}

Dynamic B2ContactSolver_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactSolver_obj > result = new B2ContactSolver_obj();
	result->__construct();
	return result;}

Void B2ContactSolver_obj::initialize( ::box2D::dynamics::B2TimeStep step,Array< ::Dynamic > contacts,int contactCount,Dynamic allocator){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactSolver","initialize",0xb54678ad,"box2D.dynamics.contacts.B2ContactSolver.initialize","box2D/dynamics/contacts/B2ContactSolver.hx",50,0x75c0a5ce)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_ARG(contacts,"contacts")
		HX_STACK_ARG(contactCount,"contactCount")
		HX_STACK_ARG(allocator,"allocator")
		HX_STACK_LINE(51)
		::box2D::dynamics::contacts::B2Contact contact;		HX_STACK_VAR(contact,"contact");
		HX_STACK_LINE(53)
		this->m_step->set(step);
		HX_STACK_LINE(55)
		this->m_allocator = allocator;
		HX_STACK_LINE(57)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(58)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(59)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(61)
		this->m_constraintCount = contactCount;
		HX_STACK_LINE(64)
		while((true)){
			HX_STACK_LINE(64)
			if ((!(((this->m_constraints->length < this->m_constraintCount))))){
				HX_STACK_LINE(64)
				break;
			}
			HX_STACK_LINE(66)
			this->m_constraints[this->m_constraints->length] = ::box2D::dynamics::contacts::B2ContactConstraint_obj::__new();
		}
		HX_STACK_LINE(69)
		{
			HX_STACK_LINE(69)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(69)
			while((true)){
				HX_STACK_LINE(69)
				if ((!(((_g < contactCount))))){
					HX_STACK_LINE(69)
					break;
				}
				HX_STACK_LINE(69)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(71)
				contact = contacts->__get(i1).StaticCast< ::box2D::dynamics::contacts::B2Contact >();
				HX_STACK_LINE(72)
				::box2D::dynamics::B2Fixture fixtureA = contact->m_fixtureA;		HX_STACK_VAR(fixtureA,"fixtureA");
				HX_STACK_LINE(73)
				::box2D::dynamics::B2Fixture fixtureB = contact->m_fixtureB;		HX_STACK_VAR(fixtureB,"fixtureB");
				HX_STACK_LINE(74)
				::box2D::collision::shapes::B2Shape shapeA = fixtureA->m_shape;		HX_STACK_VAR(shapeA,"shapeA");
				HX_STACK_LINE(75)
				::box2D::collision::shapes::B2Shape shapeB = fixtureB->m_shape;		HX_STACK_VAR(shapeB,"shapeB");
				HX_STACK_LINE(76)
				Float radiusA = shapeA->m_radius;		HX_STACK_VAR(radiusA,"radiusA");
				HX_STACK_LINE(77)
				Float radiusB = shapeB->m_radius;		HX_STACK_VAR(radiusB,"radiusB");
				HX_STACK_LINE(78)
				::box2D::dynamics::B2Body bodyA = fixtureA->m_body;		HX_STACK_VAR(bodyA,"bodyA");
				HX_STACK_LINE(79)
				::box2D::dynamics::B2Body bodyB = fixtureB->m_body;		HX_STACK_VAR(bodyB,"bodyB");
				HX_STACK_LINE(80)
				::box2D::collision::B2Manifold manifold = contact->getManifold();		HX_STACK_VAR(manifold,"manifold");
				HX_STACK_LINE(82)
				Float _g1 = fixtureA->getFriction();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(82)
				Float _g11 = fixtureB->getFriction();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(82)
				Float friction = ::box2D::common::B2Settings_obj::b2MixFriction(_g1,_g11);		HX_STACK_VAR(friction,"friction");
				HX_STACK_LINE(83)
				Float _g2 = fixtureA->getRestitution();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(83)
				Float _g3 = fixtureB->getRestitution();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(83)
				Float restitution = ::box2D::common::B2Settings_obj::b2MixRestitution(_g2,_g3);		HX_STACK_VAR(restitution,"restitution");
				HX_STACK_LINE(86)
				Float vAX = bodyA->m_linearVelocity->x;		HX_STACK_VAR(vAX,"vAX");
				HX_STACK_LINE(87)
				Float vAY = bodyA->m_linearVelocity->y;		HX_STACK_VAR(vAY,"vAY");
				HX_STACK_LINE(89)
				Float vBX = bodyB->m_linearVelocity->x;		HX_STACK_VAR(vBX,"vBX");
				HX_STACK_LINE(90)
				Float vBY = bodyB->m_linearVelocity->y;		HX_STACK_VAR(vBY,"vBY");
				HX_STACK_LINE(91)
				Float wA = bodyA->m_angularVelocity;		HX_STACK_VAR(wA,"wA");
				HX_STACK_LINE(92)
				Float wB = bodyB->m_angularVelocity;		HX_STACK_VAR(wB,"wB");
				HX_STACK_LINE(94)
				::box2D::common::B2Settings_obj::b2Assert((manifold->m_pointCount > (int)0));
				HX_STACK_LINE(96)
				::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->initialize(manifold,bodyA->m_xf,radiusA,bodyB->m_xf,radiusB);
				HX_STACK_LINE(98)
				Float normalX = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_normal->x;		HX_STACK_VAR(normalX,"normalX");
				HX_STACK_LINE(99)
				Float normalY = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_normal->y;		HX_STACK_VAR(normalY,"normalY");
				HX_STACK_LINE(101)
				::box2D::dynamics::contacts::B2ContactConstraint cc = this->m_constraints->__get(i1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraint >();		HX_STACK_VAR(cc,"cc");
				HX_STACK_LINE(102)
				cc->bodyA = bodyA;
				HX_STACK_LINE(103)
				cc->bodyB = bodyB;
				HX_STACK_LINE(104)
				cc->manifold = manifold;
				HX_STACK_LINE(106)
				cc->normal->x = normalX;
				HX_STACK_LINE(107)
				cc->normal->y = normalY;
				HX_STACK_LINE(108)
				cc->pointCount = manifold->m_pointCount;
				HX_STACK_LINE(109)
				cc->friction = friction;
				HX_STACK_LINE(110)
				cc->restitution = restitution;
				HX_STACK_LINE(112)
				cc->localPlaneNormal->x = manifold->m_localPlaneNormal->x;
				HX_STACK_LINE(113)
				cc->localPlaneNormal->y = manifold->m_localPlaneNormal->y;
				HX_STACK_LINE(114)
				cc->localPoint->x = manifold->m_localPoint->x;
				HX_STACK_LINE(115)
				cc->localPoint->y = manifold->m_localPoint->y;
				HX_STACK_LINE(116)
				cc->radius = (radiusA + radiusB);
				HX_STACK_LINE(117)
				cc->type = manifold->m_type;
				HX_STACK_LINE(119)
				{
					HX_STACK_LINE(119)
					int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(119)
					int _g12 = cc->pointCount;		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(119)
					while((true)){
						HX_STACK_LINE(119)
						if ((!(((_g21 < _g12))))){
							HX_STACK_LINE(119)
							break;
						}
						HX_STACK_LINE(119)
						int k = (_g21)++;		HX_STACK_VAR(k,"k");
						HX_STACK_LINE(121)
						::box2D::collision::B2ManifoldPoint cp = manifold->m_points->__get(k).StaticCast< ::box2D::collision::B2ManifoldPoint >();		HX_STACK_VAR(cp,"cp");
						HX_STACK_LINE(122)
						::box2D::dynamics::contacts::B2ContactConstraintPoint ccp = cc->points->__get(k).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(ccp,"ccp");
						HX_STACK_LINE(124)
						ccp->normalImpulse = cp->m_normalImpulse;
						HX_STACK_LINE(125)
						ccp->tangentImpulse = cp->m_tangentImpulse;
						HX_STACK_LINE(127)
						ccp->localPoint->setV(cp->m_localPoint);
						HX_STACK_LINE(129)
						Float rAX = ccp->rA->x = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k).StaticCast< ::box2D::common::math::B2Vec2 >()->x - bodyA->m_sweep->c->x);		HX_STACK_VAR(rAX,"rAX");
						HX_STACK_LINE(130)
						Float rAY = ccp->rA->y = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k).StaticCast< ::box2D::common::math::B2Vec2 >()->y - bodyA->m_sweep->c->y);		HX_STACK_VAR(rAY,"rAY");
						HX_STACK_LINE(131)
						Float rBX = ccp->rB->x = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k).StaticCast< ::box2D::common::math::B2Vec2 >()->x - bodyB->m_sweep->c->x);		HX_STACK_VAR(rBX,"rBX");
						HX_STACK_LINE(132)
						Float rBY = ccp->rB->y = (::box2D::dynamics::contacts::B2ContactSolver_obj::s_worldManifold->m_points->__get(k).StaticCast< ::box2D::common::math::B2Vec2 >()->y - bodyB->m_sweep->c->y);		HX_STACK_VAR(rBY,"rBY");
						HX_STACK_LINE(134)
						Float rnA = ((rAX * normalY) - (rAY * normalX));		HX_STACK_VAR(rnA,"rnA");
						HX_STACK_LINE(135)
						Float rnB = ((rBX * normalY) - (rBY * normalX));		HX_STACK_VAR(rnB,"rnB");
						HX_STACK_LINE(137)
						hx::MultEq(rnA,rnA);
						HX_STACK_LINE(138)
						hx::MultEq(rnB,rnB);
						HX_STACK_LINE(140)
						Float kNormal = (((bodyA->m_invMass + bodyB->m_invMass) + (bodyA->m_invI * rnA)) + (bodyB->m_invI * rnB));		HX_STACK_VAR(kNormal,"kNormal");
						HX_STACK_LINE(142)
						ccp->normalMass = (Float(1.0) / Float(kNormal));
						HX_STACK_LINE(144)
						Float kEqualized = ((bodyA->m_mass * bodyA->m_invMass) + (bodyB->m_mass * bodyB->m_invMass));		HX_STACK_VAR(kEqualized,"kEqualized");
						HX_STACK_LINE(145)
						hx::AddEq(kEqualized,(((bodyA->m_mass * bodyA->m_invI) * rnA) + ((bodyB->m_mass * bodyB->m_invI) * rnB)));
						HX_STACK_LINE(147)
						ccp->equalizedMass = (Float(1.0) / Float(kEqualized));
						HX_STACK_LINE(150)
						Float tangentX = normalY;		HX_STACK_VAR(tangentX,"tangentX");
						HX_STACK_LINE(151)
						Float tangentY = -(normalX);		HX_STACK_VAR(tangentY,"tangentY");
						HX_STACK_LINE(154)
						Float rtA = ((rAX * tangentY) - (rAY * tangentX));		HX_STACK_VAR(rtA,"rtA");
						HX_STACK_LINE(156)
						Float rtB = ((rBX * tangentY) - (rBY * tangentX));		HX_STACK_VAR(rtB,"rtB");
						HX_STACK_LINE(158)
						hx::MultEq(rtA,rtA);
						HX_STACK_LINE(159)
						hx::MultEq(rtB,rtB);
						HX_STACK_LINE(161)
						Float kTangent = (((bodyA->m_invMass + bodyB->m_invMass) + (bodyA->m_invI * rtA)) + (bodyB->m_invI * rtB));		HX_STACK_VAR(kTangent,"kTangent");
						HX_STACK_LINE(163)
						ccp->tangentMass = (Float(1.0) / Float(kTangent));
						HX_STACK_LINE(166)
						ccp->velocityBias = 0.0;
						HX_STACK_LINE(168)
						Float tX = (((vBX + (-(wB) * rBY)) - vAX) - (-(wA) * rAY));		HX_STACK_VAR(tX,"tX");
						HX_STACK_LINE(169)
						Float tY = (((vBY + (wB * rBX)) - vAY) - (wA * rAX));		HX_STACK_VAR(tY,"tY");
						HX_STACK_LINE(171)
						Float vRel = ((cc->normal->x * tX) + (cc->normal->y * tY));		HX_STACK_VAR(vRel,"vRel");
						HX_STACK_LINE(172)
						if (((vRel < -(::box2D::common::B2Settings_obj::b2_velocityThreshold)))){
							HX_STACK_LINE(174)
							hx::AddEq(ccp->velocityBias,(-(cc->restitution) * vRel));
						}
					}
				}
				HX_STACK_LINE(179)
				if (((cc->pointCount == (int)2))){
					HX_STACK_LINE(181)
					::box2D::dynamics::contacts::B2ContactConstraintPoint ccp1 = cc->points->__get((int)0).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(ccp1,"ccp1");
					HX_STACK_LINE(182)
					::box2D::dynamics::contacts::B2ContactConstraintPoint ccp2 = cc->points->__get((int)1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(ccp2,"ccp2");
					HX_STACK_LINE(184)
					Float invMassA = bodyA->m_invMass;		HX_STACK_VAR(invMassA,"invMassA");
					HX_STACK_LINE(185)
					Float invIA = bodyA->m_invI;		HX_STACK_VAR(invIA,"invIA");
					HX_STACK_LINE(186)
					Float invMassB = bodyB->m_invMass;		HX_STACK_VAR(invMassB,"invMassB");
					HX_STACK_LINE(187)
					Float invIB = bodyB->m_invI;		HX_STACK_VAR(invIB,"invIB");
					HX_STACK_LINE(193)
					Float rn1A = ((ccp1->rA->x * normalY) - (ccp1->rA->y * normalX));		HX_STACK_VAR(rn1A,"rn1A");
					HX_STACK_LINE(194)
					Float rn1B = ((ccp1->rB->x * normalY) - (ccp1->rB->y * normalX));		HX_STACK_VAR(rn1B,"rn1B");
					HX_STACK_LINE(195)
					Float rn2A = ((ccp2->rA->x * normalY) - (ccp2->rA->y * normalX));		HX_STACK_VAR(rn2A,"rn2A");
					HX_STACK_LINE(196)
					Float rn2B = ((ccp2->rB->x * normalY) - (ccp2->rB->y * normalX));		HX_STACK_VAR(rn2B,"rn2B");
					HX_STACK_LINE(198)
					Float k11 = (((invMassA + invMassB) + ((invIA * rn1A) * rn1A)) + ((invIB * rn1B) * rn1B));		HX_STACK_VAR(k11,"k11");
					HX_STACK_LINE(199)
					Float k22 = (((invMassA + invMassB) + ((invIA * rn2A) * rn2A)) + ((invIB * rn2B) * rn2B));		HX_STACK_VAR(k22,"k22");
					HX_STACK_LINE(200)
					Float k12 = (((invMassA + invMassB) + ((invIA * rn1A) * rn2A)) + ((invIB * rn1B) * rn2B));		HX_STACK_VAR(k12,"k12");
					HX_STACK_LINE(203)
					Float k_maxConditionNumber = 100.0;		HX_STACK_VAR(k_maxConditionNumber,"k_maxConditionNumber");
					HX_STACK_LINE(204)
					if ((((k11 * k11) < (k_maxConditionNumber * (((k11 * k22) - (k12 * k12))))))){
						HX_STACK_LINE(207)
						cc->K->col1->set(k11,k12);
						HX_STACK_LINE(208)
						cc->K->col2->set(k12,k22);
						HX_STACK_LINE(209)
						cc->K->getInverse(cc->normalMass);
					}
					else{
						HX_STACK_LINE(215)
						cc->pointCount = (int)1;
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2ContactSolver_obj,initialize,(void))

Void B2ContactSolver_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactSolver","initVelocityConstraints",0xac9c9bac,"box2D.dynamics.contacts.B2ContactSolver.initVelocityConstraints","box2D/dynamics/contacts/B2ContactSolver.hx",224,0x75c0a5ce)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(225)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(226)
		::box2D::common::math::B2Vec2 tVec2;		HX_STACK_VAR(tVec2,"tVec2");
		HX_STACK_LINE(227)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(230)
		{
			HX_STACK_LINE(230)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(230)
			int _g = this->m_constraintCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(230)
			while((true)){
				HX_STACK_LINE(230)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(230)
					break;
				}
				HX_STACK_LINE(230)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(232)
				::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraint >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(234)
				::box2D::dynamics::B2Body bodyA = c->bodyA;		HX_STACK_VAR(bodyA,"bodyA");
				HX_STACK_LINE(235)
				::box2D::dynamics::B2Body bodyB = c->bodyB;		HX_STACK_VAR(bodyB,"bodyB");
				HX_STACK_LINE(236)
				Float invMassA = bodyA->m_invMass;		HX_STACK_VAR(invMassA,"invMassA");
				HX_STACK_LINE(237)
				Float invIA = bodyA->m_invI;		HX_STACK_VAR(invIA,"invIA");
				HX_STACK_LINE(238)
				Float invMassB = bodyB->m_invMass;		HX_STACK_VAR(invMassB,"invMassB");
				HX_STACK_LINE(239)
				Float invIB = bodyB->m_invI;		HX_STACK_VAR(invIB,"invIB");
				HX_STACK_LINE(241)
				Float normalX = c->normal->x;		HX_STACK_VAR(normalX,"normalX");
				HX_STACK_LINE(242)
				Float normalY = c->normal->y;		HX_STACK_VAR(normalY,"normalY");
				HX_STACK_LINE(244)
				Float tangentX = normalY;		HX_STACK_VAR(tangentX,"tangentX");
				HX_STACK_LINE(245)
				Float tangentY = -(normalX);		HX_STACK_VAR(tangentY,"tangentY");
				HX_STACK_LINE(247)
				Float tX;		HX_STACK_VAR(tX,"tX");
				HX_STACK_LINE(249)
				int j;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(250)
				int tCount;		HX_STACK_VAR(tCount,"tCount");
				HX_STACK_LINE(251)
				if ((step->warmStarting)){
					HX_STACK_LINE(253)
					tCount = c->pointCount;
					HX_STACK_LINE(254)
					{
						HX_STACK_LINE(254)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(254)
						while((true)){
							HX_STACK_LINE(254)
							if ((!(((_g2 < tCount))))){
								HX_STACK_LINE(254)
								break;
							}
							HX_STACK_LINE(254)
							int j1 = (_g2)++;		HX_STACK_VAR(j1,"j1");
							HX_STACK_LINE(256)
							::box2D::dynamics::contacts::B2ContactConstraintPoint ccp = c->points->__get(j1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(ccp,"ccp");
							HX_STACK_LINE(257)
							hx::MultEq(ccp->normalImpulse,step->dtRatio);
							HX_STACK_LINE(258)
							hx::MultEq(ccp->tangentImpulse,step->dtRatio);
							HX_STACK_LINE(260)
							Float PX = ((ccp->normalImpulse * normalX) + (ccp->tangentImpulse * tangentX));		HX_STACK_VAR(PX,"PX");
							HX_STACK_LINE(261)
							Float PY = ((ccp->normalImpulse * normalY) + (ccp->tangentImpulse * tangentY));		HX_STACK_VAR(PY,"PY");
							HX_STACK_LINE(264)
							hx::SubEq(bodyA->m_angularVelocity,(invIA * (((ccp->rA->x * PY) - (ccp->rA->y * PX)))));
							HX_STACK_LINE(266)
							hx::SubEq(bodyA->m_linearVelocity->x,(invMassA * PX));
							HX_STACK_LINE(267)
							hx::SubEq(bodyA->m_linearVelocity->y,(invMassA * PY));
							HX_STACK_LINE(269)
							hx::AddEq(bodyB->m_angularVelocity,(invIB * (((ccp->rB->x * PY) - (ccp->rB->y * PX)))));
							HX_STACK_LINE(271)
							hx::AddEq(bodyB->m_linearVelocity->x,(invMassB * PX));
							HX_STACK_LINE(272)
							hx::AddEq(bodyB->m_linearVelocity->y,(invMassB * PY));
						}
					}
				}
				else{
					HX_STACK_LINE(277)
					tCount = c->pointCount;
					HX_STACK_LINE(278)
					{
						HX_STACK_LINE(278)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(278)
						while((true)){
							HX_STACK_LINE(278)
							if ((!(((_g2 < tCount))))){
								HX_STACK_LINE(278)
								break;
							}
							HX_STACK_LINE(278)
							int j1 = (_g2)++;		HX_STACK_VAR(j1,"j1");
							HX_STACK_LINE(280)
							::box2D::dynamics::contacts::B2ContactConstraintPoint ccp2 = c->points->__get(j1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(ccp2,"ccp2");
							HX_STACK_LINE(281)
							ccp2->normalImpulse = 0.0;
							HX_STACK_LINE(282)
							ccp2->tangentImpulse = 0.0;
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactSolver_obj,initVelocityConstraints,(void))

Void B2ContactSolver_obj::solveVelocityConstraints( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactSolver","solveVelocityConstraints",0x312ee637,"box2D.dynamics.contacts.B2ContactSolver.solveVelocityConstraints","box2D/dynamics/contacts/B2ContactSolver.hx",287,0x75c0a5ce)
		HX_STACK_THIS(this)
		HX_STACK_LINE(288)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(289)
		::box2D::dynamics::contacts::B2ContactConstraintPoint ccp;		HX_STACK_VAR(ccp,"ccp");
		HX_STACK_LINE(290)
		Float rAX;		HX_STACK_VAR(rAX,"rAX");
		HX_STACK_LINE(291)
		Float rAY;		HX_STACK_VAR(rAY,"rAY");
		HX_STACK_LINE(292)
		Float rBX;		HX_STACK_VAR(rBX,"rBX");
		HX_STACK_LINE(293)
		Float rBY;		HX_STACK_VAR(rBY,"rBY");
		HX_STACK_LINE(294)
		Float dvX;		HX_STACK_VAR(dvX,"dvX");
		HX_STACK_LINE(295)
		Float dvY;		HX_STACK_VAR(dvY,"dvY");
		HX_STACK_LINE(296)
		Float vn;		HX_STACK_VAR(vn,"vn");
		HX_STACK_LINE(297)
		Float vt;		HX_STACK_VAR(vt,"vt");
		HX_STACK_LINE(298)
		Float lambda;		HX_STACK_VAR(lambda,"lambda");
		HX_STACK_LINE(299)
		Float maxFriction;		HX_STACK_VAR(maxFriction,"maxFriction");
		HX_STACK_LINE(300)
		Float newImpulse;		HX_STACK_VAR(newImpulse,"newImpulse");
		HX_STACK_LINE(301)
		Float PX;		HX_STACK_VAR(PX,"PX");
		HX_STACK_LINE(302)
		Float PY;		HX_STACK_VAR(PY,"PY");
		HX_STACK_LINE(303)
		Float dX;		HX_STACK_VAR(dX,"dX");
		HX_STACK_LINE(304)
		Float dY;		HX_STACK_VAR(dY,"dY");
		HX_STACK_LINE(305)
		Float P1X;		HX_STACK_VAR(P1X,"P1X");
		HX_STACK_LINE(306)
		Float P1Y;		HX_STACK_VAR(P1Y,"P1Y");
		HX_STACK_LINE(307)
		Float P2X;		HX_STACK_VAR(P2X,"P2X");
		HX_STACK_LINE(308)
		Float P2Y;		HX_STACK_VAR(P2Y,"P2Y");
		HX_STACK_LINE(310)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(311)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(313)
		{
			HX_STACK_LINE(313)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(313)
			int _g = this->m_constraintCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(313)
			while((true)){
				HX_STACK_LINE(313)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(313)
					break;
				}
				HX_STACK_LINE(313)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(315)
				::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraint >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(316)
				::box2D::dynamics::B2Body bodyA = c->bodyA;		HX_STACK_VAR(bodyA,"bodyA");
				HX_STACK_LINE(317)
				::box2D::dynamics::B2Body bodyB = c->bodyB;		HX_STACK_VAR(bodyB,"bodyB");
				HX_STACK_LINE(318)
				Float wA = bodyA->m_angularVelocity;		HX_STACK_VAR(wA,"wA");
				HX_STACK_LINE(319)
				Float wB = bodyB->m_angularVelocity;		HX_STACK_VAR(wB,"wB");
				HX_STACK_LINE(320)
				::box2D::common::math::B2Vec2 vA = bodyA->m_linearVelocity;		HX_STACK_VAR(vA,"vA");
				HX_STACK_LINE(321)
				::box2D::common::math::B2Vec2 vB = bodyB->m_linearVelocity;		HX_STACK_VAR(vB,"vB");
				HX_STACK_LINE(323)
				Float invMassA = bodyA->m_invMass;		HX_STACK_VAR(invMassA,"invMassA");
				HX_STACK_LINE(324)
				Float invIA = bodyA->m_invI;		HX_STACK_VAR(invIA,"invIA");
				HX_STACK_LINE(325)
				Float invMassB = bodyB->m_invMass;		HX_STACK_VAR(invMassB,"invMassB");
				HX_STACK_LINE(326)
				Float invIB = bodyB->m_invI;		HX_STACK_VAR(invIB,"invIB");
				HX_STACK_LINE(328)
				Float normalX = c->normal->x;		HX_STACK_VAR(normalX,"normalX");
				HX_STACK_LINE(329)
				Float normalY = c->normal->y;		HX_STACK_VAR(normalY,"normalY");
				HX_STACK_LINE(331)
				Float tangentX = normalY;		HX_STACK_VAR(tangentX,"tangentX");
				HX_STACK_LINE(332)
				Float tangentY = -(normalX);		HX_STACK_VAR(tangentY,"tangentY");
				HX_STACK_LINE(333)
				Float friction = c->friction;		HX_STACK_VAR(friction,"friction");
				HX_STACK_LINE(335)
				Float tX;		HX_STACK_VAR(tX,"tX");
				HX_STACK_LINE(339)
				{
					HX_STACK_LINE(339)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(339)
					int _g2 = c->pointCount;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(339)
					while((true)){
						HX_STACK_LINE(339)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(339)
							break;
						}
						HX_STACK_LINE(339)
						int j1 = (_g3)++;		HX_STACK_VAR(j1,"j1");
						HX_STACK_LINE(341)
						ccp = c->points->__get(j1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();
						HX_STACK_LINE(345)
						dvX = (((vB->x - (wB * ccp->rB->y)) - vA->x) + (wA * ccp->rA->y));
						HX_STACK_LINE(346)
						dvY = (((vB->y + (wB * ccp->rB->x)) - vA->y) - (wA * ccp->rA->x));
						HX_STACK_LINE(349)
						vt = ((dvX * tangentX) + (dvY * tangentY));
						HX_STACK_LINE(350)
						lambda = (ccp->tangentMass * -(vt));
						HX_STACK_LINE(353)
						maxFriction = (friction * ccp->normalImpulse);
						HX_STACK_LINE(354)
						Float _g4 = ::box2D::common::math::B2Math_obj::clamp((ccp->tangentImpulse + lambda),-(maxFriction),maxFriction);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(354)
						newImpulse = _g4;
						HX_STACK_LINE(355)
						lambda = (newImpulse - ccp->tangentImpulse);
						HX_STACK_LINE(358)
						PX = (lambda * tangentX);
						HX_STACK_LINE(359)
						PY = (lambda * tangentY);
						HX_STACK_LINE(361)
						hx::SubEq(vA->x,(invMassA * PX));
						HX_STACK_LINE(362)
						hx::SubEq(vA->y,(invMassA * PY));
						HX_STACK_LINE(363)
						hx::SubEq(wA,(invIA * (((ccp->rA->x * PY) - (ccp->rA->y * PX)))));
						HX_STACK_LINE(365)
						hx::AddEq(vB->x,(invMassB * PX));
						HX_STACK_LINE(366)
						hx::AddEq(vB->y,(invMassB * PY));
						HX_STACK_LINE(367)
						hx::AddEq(wB,(invIB * (((ccp->rB->x * PY) - (ccp->rB->y * PX)))));
						HX_STACK_LINE(369)
						ccp->tangentImpulse = newImpulse;
					}
				}
				HX_STACK_LINE(373)
				int tCount = c->pointCount;		HX_STACK_VAR(tCount,"tCount");
				HX_STACK_LINE(374)
				if (((c->pointCount == (int)1))){
					HX_STACK_LINE(376)
					ccp = c->points->__get((int)0).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();
					HX_STACK_LINE(380)
					dvX = (((vB->x + (-(wB) * ccp->rB->y)) - vA->x) - (-(wA) * ccp->rA->y));
					HX_STACK_LINE(381)
					dvY = (((vB->y + (wB * ccp->rB->x)) - vA->y) - (wA * ccp->rA->x));
					HX_STACK_LINE(385)
					vn = ((dvX * normalX) + (dvY * normalY));
					HX_STACK_LINE(386)
					lambda = (-(ccp->normalMass) * ((vn - ccp->velocityBias)));
					HX_STACK_LINE(390)
					newImpulse = (ccp->normalImpulse + lambda);
					HX_STACK_LINE(391)
					if (((newImpulse > (int)0))){
						HX_STACK_LINE(391)
						newImpulse = newImpulse;
					}
					else{
						HX_STACK_LINE(391)
						newImpulse = 0.0;
					}
					HX_STACK_LINE(392)
					lambda = (newImpulse - ccp->normalImpulse);
					HX_STACK_LINE(396)
					PX = (lambda * normalX);
					HX_STACK_LINE(397)
					PY = (lambda * normalY);
					HX_STACK_LINE(400)
					hx::SubEq(vA->x,(invMassA * PX));
					HX_STACK_LINE(401)
					hx::SubEq(vA->y,(invMassA * PY));
					HX_STACK_LINE(402)
					hx::SubEq(wA,(invIA * (((ccp->rA->x * PY) - (ccp->rA->y * PX)))));
					HX_STACK_LINE(405)
					hx::AddEq(vB->x,(invMassB * PX));
					HX_STACK_LINE(406)
					hx::AddEq(vB->y,(invMassB * PY));
					HX_STACK_LINE(407)
					hx::AddEq(wB,(invIB * (((ccp->rB->x * PY) - (ccp->rB->y * PX)))));
					HX_STACK_LINE(409)
					ccp->normalImpulse = newImpulse;
				}
				else{
					HX_STACK_LINE(441)
					::box2D::dynamics::contacts::B2ContactConstraintPoint cp1 = c->points->__get((int)0).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(cp1,"cp1");
					HX_STACK_LINE(442)
					::box2D::dynamics::contacts::B2ContactConstraintPoint cp2 = c->points->__get((int)1).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(cp2,"cp2");
					HX_STACK_LINE(444)
					Float aX = cp1->normalImpulse;		HX_STACK_VAR(aX,"aX");
					HX_STACK_LINE(445)
					Float aY = cp2->normalImpulse;		HX_STACK_VAR(aY,"aY");
					HX_STACK_LINE(450)
					Float dv1X = (((vB->x - (wB * cp1->rB->y)) - vA->x) + (wA * cp1->rA->y));		HX_STACK_VAR(dv1X,"dv1X");
					HX_STACK_LINE(451)
					Float dv1Y = (((vB->y + (wB * cp1->rB->x)) - vA->y) - (wA * cp1->rA->x));		HX_STACK_VAR(dv1Y,"dv1Y");
					HX_STACK_LINE(453)
					Float dv2X = (((vB->x - (wB * cp2->rB->y)) - vA->x) + (wA * cp2->rA->y));		HX_STACK_VAR(dv2X,"dv2X");
					HX_STACK_LINE(454)
					Float dv2Y = (((vB->y + (wB * cp2->rB->x)) - vA->y) - (wA * cp2->rA->x));		HX_STACK_VAR(dv2Y,"dv2Y");
					HX_STACK_LINE(458)
					Float vn1 = ((dv1X * normalX) + (dv1Y * normalY));		HX_STACK_VAR(vn1,"vn1");
					HX_STACK_LINE(460)
					Float vn2 = ((dv2X * normalX) + (dv2Y * normalY));		HX_STACK_VAR(vn2,"vn2");
					HX_STACK_LINE(462)
					Float bX = (vn1 - cp1->velocityBias);		HX_STACK_VAR(bX,"bX");
					HX_STACK_LINE(463)
					Float bY = (vn2 - cp2->velocityBias);		HX_STACK_VAR(bY,"bY");
					HX_STACK_LINE(466)
					tMat = c->K;
					HX_STACK_LINE(467)
					hx::SubEq(bX,((tMat->col1->x * aX) + (tMat->col2->x * aY)));
					HX_STACK_LINE(468)
					hx::SubEq(bY,((tMat->col1->y * aX) + (tMat->col2->y * aY)));
					HX_STACK_LINE(470)
					Float k_errorTol = 0.001;		HX_STACK_VAR(k_errorTol,"k_errorTol");
					HX_STACK_LINE(471)
					{
						HX_STACK_LINE(471)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(471)
						while((true)){
							HX_STACK_LINE(471)
							if ((!(((_g2 < (int)1))))){
								HX_STACK_LINE(471)
								break;
							}
							HX_STACK_LINE(471)
							int i1 = (_g2)++;		HX_STACK_VAR(i1,"i1");
							HX_STACK_LINE(484)
							tMat = c->normalMass;
							HX_STACK_LINE(485)
							Float xX = -((((tMat->col1->x * bX) + (tMat->col2->x * bY))));		HX_STACK_VAR(xX,"xX");
							HX_STACK_LINE(486)
							Float xY = -((((tMat->col1->y * bX) + (tMat->col2->y * bY))));		HX_STACK_VAR(xY,"xY");
							HX_STACK_LINE(488)
							if (((bool((xX >= 0.0)) && bool((xY >= 0.0))))){
								HX_STACK_LINE(491)
								dX = (xX - aX);
								HX_STACK_LINE(492)
								dY = (xY - aY);
								HX_STACK_LINE(496)
								P1X = (dX * normalX);
								HX_STACK_LINE(497)
								P1Y = (dX * normalY);
								HX_STACK_LINE(499)
								P2X = (dY * normalX);
								HX_STACK_LINE(500)
								P2Y = (dY * normalY);
								HX_STACK_LINE(503)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_STACK_LINE(504)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_STACK_LINE(506)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_STACK_LINE(509)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_STACK_LINE(510)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_STACK_LINE(512)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_STACK_LINE(515)
								cp1->normalImpulse = xX;
								HX_STACK_LINE(516)
								cp2->normalImpulse = xY;
								HX_STACK_LINE(535)
								break;
							}
							HX_STACK_LINE(545)
							xX = (-(cp1->normalMass) * bX);
							HX_STACK_LINE(546)
							xY = 0.0;
							HX_STACK_LINE(547)
							vn1 = 0.0;
							HX_STACK_LINE(548)
							vn2 = ((c->K->col1->y * xX) + bY);
							HX_STACK_LINE(550)
							if (((bool((xX >= 0.0)) && bool((vn2 >= 0.0))))){
								HX_STACK_LINE(554)
								dX = (xX - aX);
								HX_STACK_LINE(555)
								dY = (xY - aY);
								HX_STACK_LINE(559)
								P1X = (dX * normalX);
								HX_STACK_LINE(560)
								P1Y = (dX * normalY);
								HX_STACK_LINE(562)
								P2X = (dY * normalX);
								HX_STACK_LINE(563)
								P2Y = (dY * normalY);
								HX_STACK_LINE(566)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_STACK_LINE(567)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_STACK_LINE(569)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_STACK_LINE(572)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_STACK_LINE(573)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_STACK_LINE(575)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_STACK_LINE(578)
								cp1->normalImpulse = xX;
								HX_STACK_LINE(579)
								cp2->normalImpulse = xY;
								HX_STACK_LINE(598)
								break;
							}
							HX_STACK_LINE(608)
							xX = 0.0;
							HX_STACK_LINE(609)
							xY = (-(cp2->normalMass) * bY);
							HX_STACK_LINE(610)
							vn1 = ((c->K->col2->x * xY) + bX);
							HX_STACK_LINE(611)
							vn2 = 0.0;
							HX_STACK_LINE(612)
							if (((bool((xY >= 0.0)) && bool((vn1 >= 0.0))))){
								HX_STACK_LINE(616)
								dX = (xX - aX);
								HX_STACK_LINE(617)
								dY = (xY - aY);
								HX_STACK_LINE(621)
								P1X = (dX * normalX);
								HX_STACK_LINE(622)
								P1Y = (dX * normalY);
								HX_STACK_LINE(624)
								P2X = (dY * normalX);
								HX_STACK_LINE(625)
								P2Y = (dY * normalY);
								HX_STACK_LINE(628)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_STACK_LINE(629)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_STACK_LINE(631)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_STACK_LINE(634)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_STACK_LINE(635)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_STACK_LINE(637)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_STACK_LINE(640)
								cp1->normalImpulse = xX;
								HX_STACK_LINE(641)
								cp2->normalImpulse = xY;
								HX_STACK_LINE(660)
								break;
							}
							HX_STACK_LINE(669)
							xX = 0.0;
							HX_STACK_LINE(670)
							xY = 0.0;
							HX_STACK_LINE(671)
							vn1 = bX;
							HX_STACK_LINE(672)
							vn2 = bY;
							HX_STACK_LINE(674)
							if (((bool((vn1 >= 0.0)) && bool((vn2 >= 0.0))))){
								HX_STACK_LINE(677)
								dX = (xX - aX);
								HX_STACK_LINE(678)
								dY = (xY - aY);
								HX_STACK_LINE(682)
								P1X = (dX * normalX);
								HX_STACK_LINE(683)
								P1Y = (dX * normalY);
								HX_STACK_LINE(685)
								P2X = (dY * normalX);
								HX_STACK_LINE(686)
								P2Y = (dY * normalY);
								HX_STACK_LINE(689)
								hx::SubEq(vA->x,(invMassA * ((P1X + P2X))));
								HX_STACK_LINE(690)
								hx::SubEq(vA->y,(invMassA * ((P1Y + P2Y))));
								HX_STACK_LINE(692)
								hx::SubEq(wA,(invIA * (((((cp1->rA->x * P1Y) - (cp1->rA->y * P1X)) + (cp2->rA->x * P2Y)) - (cp2->rA->y * P2X)))));
								HX_STACK_LINE(695)
								hx::AddEq(vB->x,(invMassB * ((P1X + P2X))));
								HX_STACK_LINE(696)
								hx::AddEq(vB->y,(invMassB * ((P1Y + P2Y))));
								HX_STACK_LINE(698)
								hx::AddEq(wB,(invIB * (((((cp1->rB->x * P1Y) - (cp1->rB->y * P1X)) + (cp2->rB->x * P2Y)) - (cp2->rB->y * P2X)))));
								HX_STACK_LINE(701)
								cp1->normalImpulse = xX;
								HX_STACK_LINE(702)
								cp2->normalImpulse = xY;
								HX_STACK_LINE(721)
								break;
							}
							HX_STACK_LINE(725)
							break;
						}
					}
				}
				HX_STACK_LINE(736)
				bodyA->m_angularVelocity = wA;
				HX_STACK_LINE(737)
				bodyB->m_angularVelocity = wB;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactSolver_obj,solveVelocityConstraints,(void))

Void B2ContactSolver_obj::finalizeVelocityConstraints( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactSolver","finalizeVelocityConstraints",0xcbb61f5e,"box2D.dynamics.contacts.B2ContactSolver.finalizeVelocityConstraints","box2D/dynamics/contacts/B2ContactSolver.hx",743,0x75c0a5ce)
		HX_STACK_THIS(this)
		HX_STACK_LINE(743)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(743)
		int _g = this->m_constraintCount;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(743)
		while((true)){
			HX_STACK_LINE(743)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(743)
				break;
			}
			HX_STACK_LINE(743)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(745)
			::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraint >();		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(746)
			::box2D::collision::B2Manifold m = c->manifold;		HX_STACK_VAR(m,"m");
			HX_STACK_LINE(748)
			{
				HX_STACK_LINE(748)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(748)
				int _g2 = c->pointCount;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(748)
				while((true)){
					HX_STACK_LINE(748)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(748)
						break;
					}
					HX_STACK_LINE(748)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(750)
					::box2D::collision::B2ManifoldPoint point1 = m->m_points->__get(j).StaticCast< ::box2D::collision::B2ManifoldPoint >();		HX_STACK_VAR(point1,"point1");
					HX_STACK_LINE(751)
					::box2D::dynamics::contacts::B2ContactConstraintPoint point2 = c->points->__get(j).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(point2,"point2");
					HX_STACK_LINE(752)
					point1->m_normalImpulse = point2->normalImpulse;
					HX_STACK_LINE(753)
					point1->m_tangentImpulse = point2->tangentImpulse;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactSolver_obj,finalizeVelocityConstraints,(void))

bool B2ContactSolver_obj::solvePositionConstraints( Float baumgarte){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactSolver","solvePositionConstraints",0x690afb2b,"box2D.dynamics.contacts.B2ContactSolver.solvePositionConstraints","box2D/dynamics/contacts/B2ContactSolver.hx",864,0x75c0a5ce)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baumgarte,"baumgarte")
	HX_STACK_LINE(865)
	Float minSeparation = 0.0;		HX_STACK_VAR(minSeparation,"minSeparation");
	HX_STACK_LINE(867)
	{
		HX_STACK_LINE(867)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(867)
		int _g = this->m_constraintCount;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(867)
		while((true)){
			HX_STACK_LINE(867)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(867)
				break;
			}
			HX_STACK_LINE(867)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(869)
			::box2D::dynamics::contacts::B2ContactConstraint c = this->m_constraints->__get(i).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraint >();		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(870)
			::box2D::dynamics::B2Body bodyA = c->bodyA;		HX_STACK_VAR(bodyA,"bodyA");
			HX_STACK_LINE(871)
			::box2D::dynamics::B2Body bodyB = c->bodyB;		HX_STACK_VAR(bodyB,"bodyB");
			HX_STACK_LINE(873)
			Float invMassA = (bodyA->m_mass * bodyA->m_invMass);		HX_STACK_VAR(invMassA,"invMassA");
			HX_STACK_LINE(874)
			Float invIA = (bodyA->m_mass * bodyA->m_invI);		HX_STACK_VAR(invIA,"invIA");
			HX_STACK_LINE(875)
			Float invMassB = (bodyB->m_mass * bodyB->m_invMass);		HX_STACK_VAR(invMassB,"invMassB");
			HX_STACK_LINE(876)
			Float invIB = (bodyB->m_mass * bodyB->m_invI);		HX_STACK_VAR(invIB,"invIB");
			HX_STACK_LINE(879)
			::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->initialize(c);
			HX_STACK_LINE(880)
			::box2D::common::math::B2Vec2 normal = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->m_normal;		HX_STACK_VAR(normal,"normal");
			HX_STACK_LINE(883)
			{
				HX_STACK_LINE(883)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(883)
				int _g2 = c->pointCount;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(883)
				while((true)){
					HX_STACK_LINE(883)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(883)
						break;
					}
					HX_STACK_LINE(883)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(885)
					::box2D::dynamics::contacts::B2ContactConstraintPoint ccp = c->points->__get(j).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >();		HX_STACK_VAR(ccp,"ccp");
					HX_STACK_LINE(887)
					::box2D::common::math::B2Vec2 point = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->m_points->__get(j).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(point,"point");
					HX_STACK_LINE(888)
					Float separation = ::box2D::dynamics::contacts::B2ContactSolver_obj::s_psm->m_separations->__get(j);		HX_STACK_VAR(separation,"separation");
					HX_STACK_LINE(890)
					Float rAX = (point->x - bodyA->m_sweep->c->x);		HX_STACK_VAR(rAX,"rAX");
					HX_STACK_LINE(891)
					Float rAY = (point->y - bodyA->m_sweep->c->y);		HX_STACK_VAR(rAY,"rAY");
					HX_STACK_LINE(892)
					Float rBX = (point->x - bodyB->m_sweep->c->x);		HX_STACK_VAR(rBX,"rBX");
					HX_STACK_LINE(893)
					Float rBY = (point->y - bodyB->m_sweep->c->y);		HX_STACK_VAR(rBY,"rBY");
					HX_STACK_LINE(896)
					if (((minSeparation < separation))){
						HX_STACK_LINE(896)
						minSeparation = minSeparation;
					}
					else{
						HX_STACK_LINE(896)
						minSeparation = separation;
					}
					HX_STACK_LINE(899)
					Float C = ::box2D::common::math::B2Math_obj::clamp((baumgarte * ((separation + ::box2D::common::B2Settings_obj::b2_linearSlop))),-(::box2D::common::B2Settings_obj::b2_maxLinearCorrection),0.0);		HX_STACK_VAR(C,"C");
					HX_STACK_LINE(902)
					Float impulse = (-(ccp->equalizedMass) * C);		HX_STACK_VAR(impulse,"impulse");
					HX_STACK_LINE(904)
					Float PX = (impulse * normal->x);		HX_STACK_VAR(PX,"PX");
					HX_STACK_LINE(905)
					Float PY = (impulse * normal->y);		HX_STACK_VAR(PY,"PY");
					HX_STACK_LINE(908)
					hx::SubEq(bodyA->m_sweep->c->x,(invMassA * PX));
					HX_STACK_LINE(909)
					hx::SubEq(bodyA->m_sweep->c->y,(invMassA * PY));
					HX_STACK_LINE(911)
					hx::SubEq(bodyA->m_sweep->a,(invIA * (((rAX * PY) - (rAY * PX)))));
					HX_STACK_LINE(912)
					bodyA->synchronizeTransform();
					HX_STACK_LINE(915)
					hx::AddEq(bodyB->m_sweep->c->x,(invMassB * PX));
					HX_STACK_LINE(916)
					hx::AddEq(bodyB->m_sweep->c->y,(invMassB * PY));
					HX_STACK_LINE(918)
					hx::AddEq(bodyB->m_sweep->a,(invIB * (((rBX * PY) - (rBY * PX)))));
					HX_STACK_LINE(919)
					bodyB->synchronizeTransform();
				}
			}
		}
	}
	HX_STACK_LINE(925)
	return (minSeparation > (-1.5 * ::box2D::common::B2Settings_obj::b2_linearSlop));
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactSolver_obj,solvePositionConstraints,return )

int B2ContactSolver_obj::staticFix;

::box2D::collision::B2WorldManifold B2ContactSolver_obj::s_worldManifold;

::box2D::dynamics::contacts::B2PositionSolverManifold B2ContactSolver_obj::s_psm;


B2ContactSolver_obj::B2ContactSolver_obj()
{
}

void B2ContactSolver_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactSolver);
	HX_MARK_MEMBER_NAME(m_step,"m_step");
	HX_MARK_MEMBER_NAME(m_allocator,"m_allocator");
	HX_MARK_MEMBER_NAME(m_constraints,"m_constraints");
	HX_MARK_MEMBER_NAME(m_constraintCount,"m_constraintCount");
	HX_MARK_END_CLASS();
}

void B2ContactSolver_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_step,"m_step");
	HX_VISIT_MEMBER_NAME(m_allocator,"m_allocator");
	HX_VISIT_MEMBER_NAME(m_constraints,"m_constraints");
	HX_VISIT_MEMBER_NAME(m_constraintCount,"m_constraintCount");
}

Dynamic B2ContactSolver_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_psm") ) { return s_psm; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_step") ) { return m_step; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"staticFix") ) { return staticFix; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { return m_allocator; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_constraints") ) { return m_constraints; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"s_worldManifold") ) { return s_worldManifold; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_constraintCount") ) { return m_constraintCount; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"initVelocityConstraints") ) { return initVelocityConstraints_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"solveVelocityConstraints") ) { return solveVelocityConstraints_dyn(); }
		if (HX_FIELD_EQ(inName,"solvePositionConstraints") ) { return solvePositionConstraints_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"finalizeVelocityConstraints") ) { return finalizeVelocityConstraints_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactSolver_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_psm") ) { s_psm=inValue.Cast< ::box2D::dynamics::contacts::B2PositionSolverManifold >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_step") ) { m_step=inValue.Cast< ::box2D::dynamics::B2TimeStep >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"staticFix") ) { staticFix=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { m_allocator=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_constraints") ) { m_constraints=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"s_worldManifold") ) { s_worldManifold=inValue.Cast< ::box2D::collision::B2WorldManifold >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_constraintCount") ) { m_constraintCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactSolver_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_step"));
	outFields->push(HX_CSTRING("m_allocator"));
	outFields->push(HX_CSTRING("m_constraints"));
	outFields->push(HX_CSTRING("m_constraintCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("staticFix"),
	HX_CSTRING("s_worldManifold"),
	HX_CSTRING("s_psm"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::dynamics::B2TimeStep*/ ,(int)offsetof(B2ContactSolver_obj,m_step),HX_CSTRING("m_step")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2ContactSolver_obj,m_allocator),HX_CSTRING("m_allocator")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2ContactSolver_obj,m_constraints),HX_CSTRING("m_constraints")},
	{hx::fsInt,(int)offsetof(B2ContactSolver_obj,m_constraintCount),HX_CSTRING("m_constraintCount")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("finalizeVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_step"),
	HX_CSTRING("m_allocator"),
	HX_CSTRING("m_constraints"),
	HX_CSTRING("m_constraintCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactSolver_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2ContactSolver_obj::staticFix,"staticFix");
	HX_MARK_MEMBER_NAME(B2ContactSolver_obj::s_worldManifold,"s_worldManifold");
	HX_MARK_MEMBER_NAME(B2ContactSolver_obj::s_psm,"s_psm");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactSolver_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2ContactSolver_obj::staticFix,"staticFix");
	HX_VISIT_MEMBER_NAME(B2ContactSolver_obj::s_worldManifold,"s_worldManifold");
	HX_VISIT_MEMBER_NAME(B2ContactSolver_obj::s_psm,"s_psm");
};

#endif

Class B2ContactSolver_obj::__mClass;

void B2ContactSolver_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactSolver"), hx::TCanCast< B2ContactSolver_obj> ,sStaticFields,sMemberFields,
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

void B2ContactSolver_obj::__boot()
{
	staticFix= ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;
	s_worldManifold= ::box2D::collision::B2WorldManifold_obj::__new();
	s_psm= ::box2D::dynamics::contacts::B2PositionSolverManifold_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
