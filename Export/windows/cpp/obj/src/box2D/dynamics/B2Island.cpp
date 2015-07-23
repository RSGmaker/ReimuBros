#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactImpulse
#include <box2D/dynamics/B2ContactImpulse.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Island
#include <box2D/dynamics/B2Island.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2Joint
#include <box2D/dynamics/joints/B2Joint.h>
#endif
namespace box2D{
namespace dynamics{

Void B2Island_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2Island","new",0x0c9ee620,"box2D.dynamics.B2Island.new","box2D/dynamics/B2Island.hx",114,0xbaa61170)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(499)
	this->m_jointCapacity = (int)0;
	HX_STACK_LINE(498)
	this->m_contactCapacity = (int)0;
	HX_STACK_LINE(497)
	this->m_bodyCapacity = (int)0;
	HX_STACK_LINE(495)
	this->m_contactCount = (int)0;
	HX_STACK_LINE(494)
	this->m_jointCount = (int)0;
	HX_STACK_LINE(493)
	this->m_bodyCount = (int)0;
	HX_STACK_LINE(119)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(119)
	this->m_bodies = _g;
	HX_STACK_LINE(120)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(120)
	this->m_contacts = _g1;
	HX_STACK_LINE(121)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(121)
	this->m_joints = _g2;
}
;
	return null();
}

//B2Island_obj::~B2Island_obj() { }

Dynamic B2Island_obj::__CreateEmpty() { return  new B2Island_obj; }
hx::ObjectPtr< B2Island_obj > B2Island_obj::__new()
{  hx::ObjectPtr< B2Island_obj > result = new B2Island_obj();
	result->__construct();
	return result;}

Dynamic B2Island_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Island_obj > result = new B2Island_obj();
	result->__construct();
	return result;}

Void B2Island_obj::initialize( int bodyCapacity,int contactCapacity,int jointCapacity,Dynamic allocator,::box2D::dynamics::B2ContactListener listener,::box2D::dynamics::contacts::B2ContactSolver contactSolver){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","initialize",0xd9025390,"box2D.dynamics.B2Island.initialize","box2D/dynamics/B2Island.hx",131,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bodyCapacity,"bodyCapacity")
		HX_STACK_ARG(contactCapacity,"contactCapacity")
		HX_STACK_ARG(jointCapacity,"jointCapacity")
		HX_STACK_ARG(allocator,"allocator")
		HX_STACK_ARG(listener,"listener")
		HX_STACK_ARG(contactSolver,"contactSolver")
		HX_STACK_LINE(132)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(134)
		this->m_bodyCapacity = bodyCapacity;
		HX_STACK_LINE(135)
		this->m_contactCapacity = contactCapacity;
		HX_STACK_LINE(136)
		this->m_jointCapacity = jointCapacity;
		HX_STACK_LINE(137)
		this->m_bodyCount = (int)0;
		HX_STACK_LINE(138)
		this->m_contactCount = (int)0;
		HX_STACK_LINE(139)
		this->m_jointCount = (int)0;
		HX_STACK_LINE(141)
		this->m_allocator = allocator;
		HX_STACK_LINE(142)
		this->m_listener = listener;
		HX_STACK_LINE(143)
		this->m_contactSolver = contactSolver;
		HX_STACK_LINE(145)
		{
			HX_STACK_LINE(145)
			int _g = this->m_bodies->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(145)
			while((true)){
				HX_STACK_LINE(145)
				if ((!(((_g < bodyCapacity))))){
					HX_STACK_LINE(145)
					break;
				}
				HX_STACK_LINE(145)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(146)
				this->m_bodies[i1] = null();
			}
		}
		HX_STACK_LINE(148)
		{
			HX_STACK_LINE(148)
			int _g = this->m_contacts->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(148)
			while((true)){
				HX_STACK_LINE(148)
				if ((!(((_g < contactCapacity))))){
					HX_STACK_LINE(148)
					break;
				}
				HX_STACK_LINE(148)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(149)
				this->m_contacts[i1] = null();
			}
		}
		HX_STACK_LINE(151)
		{
			HX_STACK_LINE(151)
			int _g = this->m_joints->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(151)
			while((true)){
				HX_STACK_LINE(151)
				if ((!(((_g < jointCapacity))))){
					HX_STACK_LINE(151)
					break;
				}
				HX_STACK_LINE(151)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(152)
				this->m_joints[i1] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(B2Island_obj,initialize,(void))

Void B2Island_obj::clear( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","clear",0x4de7774d,"box2D.dynamics.B2Island.clear","box2D/dynamics/B2Island.hx",158,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_LINE(159)
		this->m_bodyCount = (int)0;
		HX_STACK_LINE(160)
		this->m_contactCount = (int)0;
		HX_STACK_LINE(161)
		this->m_jointCount = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Island_obj,clear,(void))

Void B2Island_obj::solve( ::box2D::dynamics::B2TimeStep step,::box2D::common::math::B2Vec2 gravity,bool allowSleep){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","solve",0x8651c53f,"box2D.dynamics.B2Island.solve","box2D/dynamics/B2Island.hx",165,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_ARG(gravity,"gravity")
		HX_STACK_ARG(allowSleep,"allowSleep")
		HX_STACK_LINE(166)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(167)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(168)
		::box2D::dynamics::B2Body b;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(169)
		::box2D::dynamics::joints::B2Joint joint;		HX_STACK_VAR(joint,"joint");
		HX_STACK_LINE(172)
		{
			HX_STACK_LINE(172)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(172)
			int _g = this->m_bodyCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(172)
			while((true)){
				HX_STACK_LINE(172)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(172)
					break;
				}
				HX_STACK_LINE(172)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(174)
				b = this->m_bodies->__get(i1).StaticCast< ::box2D::dynamics::B2Body >();
				HX_STACK_LINE(176)
				int _g2 = b->getType();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(176)
				if (((_g2 != (int)2))){
					HX_STACK_LINE(177)
					continue;
				}
				HX_STACK_LINE(181)
				hx::AddEq(b->m_linearVelocity->x,(step->dt * ((gravity->x + (b->m_invMass * b->m_force->x)))));
				HX_STACK_LINE(182)
				hx::AddEq(b->m_linearVelocity->y,(step->dt * ((gravity->y + (b->m_invMass * b->m_force->y)))));
				HX_STACK_LINE(183)
				hx::AddEq(b->m_angularVelocity,((step->dt * b->m_invI) * b->m_torque));
				HX_STACK_LINE(192)
				Float _g11 = ::box2D::common::math::B2Math_obj::clamp((1.0 - (step->dt * b->m_linearDamping)),0.0,1.0);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(192)
				b->m_linearVelocity->multiply(_g11);
				HX_STACK_LINE(193)
				Float _g21 = ::box2D::common::math::B2Math_obj::clamp((1.0 - (step->dt * b->m_angularDamping)),0.0,1.0);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(193)
				hx::MultEq(b->m_angularVelocity,_g21);
			}
		}
		HX_STACK_LINE(196)
		this->m_contactSolver->initialize(step,this->m_contacts,this->m_contactCount,this->m_allocator);
		HX_STACK_LINE(197)
		::box2D::dynamics::contacts::B2ContactSolver contactSolver = this->m_contactSolver;		HX_STACK_VAR(contactSolver,"contactSolver");
		HX_STACK_LINE(200)
		contactSolver->initVelocityConstraints(step);
		HX_STACK_LINE(202)
		{
			HX_STACK_LINE(202)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(202)
			int _g = this->m_jointCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(202)
			while((true)){
				HX_STACK_LINE(202)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(202)
					break;
				}
				HX_STACK_LINE(202)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(204)
				joint = this->m_joints->__get(i1).StaticCast< ::box2D::dynamics::joints::B2Joint >();
				HX_STACK_LINE(205)
				joint->initVelocityConstraints(step);
			}
		}
		HX_STACK_LINE(209)
		{
			HX_STACK_LINE(209)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(209)
			int _g = step->velocityIterations;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(209)
			while((true)){
				HX_STACK_LINE(209)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(209)
					break;
				}
				HX_STACK_LINE(209)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(211)
				{
					HX_STACK_LINE(211)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(211)
					int _g2 = this->m_jointCount;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(211)
					while((true)){
						HX_STACK_LINE(211)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(211)
							break;
						}
						HX_STACK_LINE(211)
						int j1 = (_g3)++;		HX_STACK_VAR(j1,"j1");
						HX_STACK_LINE(213)
						joint = this->m_joints->__get(j1).StaticCast< ::box2D::dynamics::joints::B2Joint >();
						HX_STACK_LINE(214)
						joint->solveVelocityConstraints(step);
					}
				}
				HX_STACK_LINE(217)
				contactSolver->solveVelocityConstraints();
			}
		}
		HX_STACK_LINE(221)
		{
			HX_STACK_LINE(221)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(221)
			int _g = this->m_jointCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(221)
			while((true)){
				HX_STACK_LINE(221)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(221)
					break;
				}
				HX_STACK_LINE(221)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(223)
				joint = this->m_joints->__get(i1).StaticCast< ::box2D::dynamics::joints::B2Joint >();
				HX_STACK_LINE(224)
				joint->finalizeVelocityConstraints();
			}
		}
		HX_STACK_LINE(226)
		contactSolver->finalizeVelocityConstraints();
		HX_STACK_LINE(229)
		{
			HX_STACK_LINE(229)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(229)
			int _g = this->m_bodyCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(229)
			while((true)){
				HX_STACK_LINE(229)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(229)
					break;
				}
				HX_STACK_LINE(229)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(231)
				b = this->m_bodies->__get(i1).StaticCast< ::box2D::dynamics::B2Body >();
				HX_STACK_LINE(233)
				int _g3 = b->getType();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(233)
				if (((_g3 == (int)0))){
					HX_STACK_LINE(234)
					continue;
				}
				HX_STACK_LINE(238)
				Float translationX = (step->dt * b->m_linearVelocity->x);		HX_STACK_VAR(translationX,"translationX");
				HX_STACK_LINE(239)
				Float translationY = (step->dt * b->m_linearVelocity->y);		HX_STACK_VAR(translationY,"translationY");
				HX_STACK_LINE(241)
				if (((((translationX * translationX) + (translationY * translationY)) > ::box2D::common::B2Settings_obj::b2_maxTranslationSquared))){
					HX_STACK_LINE(243)
					b->m_linearVelocity->normalize();
					HX_STACK_LINE(244)
					hx::MultEq(b->m_linearVelocity->x,(::box2D::common::B2Settings_obj::b2_maxTranslation * step->inv_dt));
					HX_STACK_LINE(245)
					hx::MultEq(b->m_linearVelocity->y,(::box2D::common::B2Settings_obj::b2_maxTranslation * step->inv_dt));
				}
				HX_STACK_LINE(247)
				Float rotation = (step->dt * b->m_angularVelocity);		HX_STACK_VAR(rotation,"rotation");
				HX_STACK_LINE(248)
				if ((((rotation * rotation) > ::box2D::common::B2Settings_obj::b2_maxRotationSquared))){
					HX_STACK_LINE(250)
					if (((b->m_angularVelocity < 0.0))){
						HX_STACK_LINE(252)
						b->m_angularVelocity = (-(::box2D::common::B2Settings_obj::b2_maxRotation) * step->inv_dt);
					}
					else{
						HX_STACK_LINE(256)
						b->m_angularVelocity = (::box2D::common::B2Settings_obj::b2_maxRotation * step->inv_dt);
					}
				}
				HX_STACK_LINE(261)
				b->m_sweep->c0->setV(b->m_sweep->c);
				HX_STACK_LINE(262)
				b->m_sweep->a0 = b->m_sweep->a;
				HX_STACK_LINE(266)
				hx::AddEq(b->m_sweep->c->x,(step->dt * b->m_linearVelocity->x));
				HX_STACK_LINE(267)
				hx::AddEq(b->m_sweep->c->y,(step->dt * b->m_linearVelocity->y));
				HX_STACK_LINE(268)
				hx::AddEq(b->m_sweep->a,(step->dt * b->m_angularVelocity));
				HX_STACK_LINE(271)
				b->synchronizeTransform();
			}
		}
		HX_STACK_LINE(277)
		{
			HX_STACK_LINE(277)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(277)
			int _g = step->positionIterations;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(277)
			while((true)){
				HX_STACK_LINE(277)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(277)
					break;
				}
				HX_STACK_LINE(277)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(279)
				bool contactsOkay = contactSolver->solvePositionConstraints(::box2D::common::B2Settings_obj::b2_contactBaumgarte);		HX_STACK_VAR(contactsOkay,"contactsOkay");
				HX_STACK_LINE(281)
				bool jointsOkay = true;		HX_STACK_VAR(jointsOkay,"jointsOkay");
				HX_STACK_LINE(282)
				{
					HX_STACK_LINE(282)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(282)
					int _g2 = this->m_jointCount;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(282)
					while((true)){
						HX_STACK_LINE(282)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(282)
							break;
						}
						HX_STACK_LINE(282)
						int j1 = (_g3)++;		HX_STACK_VAR(j1,"j1");
						HX_STACK_LINE(284)
						joint = this->m_joints->__get(j1).StaticCast< ::box2D::dynamics::joints::B2Joint >();
						HX_STACK_LINE(285)
						bool jointOkay = joint->solvePositionConstraints(::box2D::common::B2Settings_obj::b2_contactBaumgarte);		HX_STACK_VAR(jointOkay,"jointOkay");
						HX_STACK_LINE(286)
						jointsOkay = (bool(jointsOkay) && bool(jointOkay));
					}
				}
				HX_STACK_LINE(289)
				if (((bool(contactsOkay) && bool(jointsOkay)))){
					HX_STACK_LINE(291)
					break;
				}
			}
		}
		HX_STACK_LINE(295)
		this->report(contactSolver->m_constraints);
		HX_STACK_LINE(297)
		if ((allowSleep)){
			HX_STACK_LINE(299)
			Float minSleepTime = 1.7976931348623158e+308;		HX_STACK_VAR(minSleepTime,"minSleepTime");
			HX_STACK_LINE(301)
			Float linTolSqr = (::box2D::common::B2Settings_obj::b2_linearSleepTolerance * ::box2D::common::B2Settings_obj::b2_linearSleepTolerance);		HX_STACK_VAR(linTolSqr,"linTolSqr");
			HX_STACK_LINE(302)
			Float angTolSqr = (::box2D::common::B2Settings_obj::b2_angularSleepTolerance * ::box2D::common::B2Settings_obj::b2_angularSleepTolerance);		HX_STACK_VAR(angTolSqr,"angTolSqr");
			HX_STACK_LINE(304)
			{
				HX_STACK_LINE(304)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(304)
				int _g = this->m_bodyCount;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(304)
				while((true)){
					HX_STACK_LINE(304)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(304)
						break;
					}
					HX_STACK_LINE(304)
					int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(306)
					b = this->m_bodies->__get(i1).StaticCast< ::box2D::dynamics::B2Body >();
					HX_STACK_LINE(307)
					int _g4 = b->getType();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(307)
					if (((_g4 == (int)0))){
						HX_STACK_LINE(309)
						continue;
					}
					HX_STACK_LINE(312)
					if (((((int(b->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == (int)0))){
						HX_STACK_LINE(314)
						b->m_sleepTime = 0.0;
						HX_STACK_LINE(315)
						minSleepTime = 0.0;
					}
					struct _Function_4_1{
						inline static bool Block( Float &linTolSqr,::box2D::dynamics::B2Body &b){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2Island.hx",320,0xbaa61170)
							{
								HX_STACK_LINE(320)
								Float _g5 = ::box2D::common::math::B2Math_obj::dot(b->m_linearVelocity,b->m_linearVelocity);		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(320)
								return (_g5 > linTolSqr);
							}
							return null();
						}
					};
					HX_STACK_LINE(318)
					if (((  ((!(((bool((((int(b->m_flags) & int(::box2D::dynamics::B2Body_obj::e_allowSleepFlag))) == (int)0)) || bool(((b->m_angularVelocity * b->m_angularVelocity) > angTolSqr))))))) ? bool(_Function_4_1::Block(linTolSqr,b)) : bool(true) ))){
						HX_STACK_LINE(322)
						b->m_sleepTime = 0.0;
						HX_STACK_LINE(323)
						minSleepTime = 0.0;
					}
					else{
						HX_STACK_LINE(327)
						hx::AddEq(b->m_sleepTime,step->dt);
						HX_STACK_LINE(328)
						Float _g6 = ::box2D::common::math::B2Math_obj::min(minSleepTime,b->m_sleepTime);		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(328)
						minSleepTime = _g6;
					}
				}
			}
			HX_STACK_LINE(332)
			if (((minSleepTime >= ::box2D::common::B2Settings_obj::b2_timeToSleep))){
				HX_STACK_LINE(334)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(334)
				int _g = this->m_bodyCount;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(334)
				while((true)){
					HX_STACK_LINE(334)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(334)
						break;
					}
					HX_STACK_LINE(334)
					int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(336)
					b = this->m_bodies->__get(i1).StaticCast< ::box2D::dynamics::B2Body >();
					HX_STACK_LINE(337)
					b->setAwake(false);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Island_obj,solve,(void))

Void B2Island_obj::solveTOI( ::box2D::dynamics::B2TimeStep subStep){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","solveTOI",0xe33bce8f,"box2D.dynamics.B2Island.solveTOI","box2D/dynamics/B2Island.hx",345,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_ARG(subStep,"subStep")
		HX_STACK_LINE(346)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(347)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(348)
		this->m_contactSolver->initialize(subStep,this->m_contacts,this->m_contactCount,this->m_allocator);
		HX_STACK_LINE(349)
		::box2D::dynamics::contacts::B2ContactSolver contactSolver = this->m_contactSolver;		HX_STACK_VAR(contactSolver,"contactSolver");
		HX_STACK_LINE(356)
		{
			HX_STACK_LINE(356)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(356)
			int _g = this->m_jointCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(356)
			while((true)){
				HX_STACK_LINE(356)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(356)
					break;
				}
				HX_STACK_LINE(356)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(358)
				this->m_joints->__get(i1).StaticCast< ::box2D::dynamics::joints::B2Joint >()->initVelocityConstraints(subStep);
			}
		}
		HX_STACK_LINE(363)
		{
			HX_STACK_LINE(363)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(363)
			int _g = subStep->velocityIterations;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(363)
			while((true)){
				HX_STACK_LINE(363)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(363)
					break;
				}
				HX_STACK_LINE(363)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(365)
				contactSolver->solveVelocityConstraints();
				HX_STACK_LINE(366)
				{
					HX_STACK_LINE(366)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(366)
					int _g2 = this->m_jointCount;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(366)
					while((true)){
						HX_STACK_LINE(366)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(366)
							break;
						}
						HX_STACK_LINE(366)
						int j1 = (_g3)++;		HX_STACK_VAR(j1,"j1");
						HX_STACK_LINE(368)
						this->m_joints->__get(j1).StaticCast< ::box2D::dynamics::joints::B2Joint >()->solveVelocityConstraints(subStep);
					}
				}
			}
		}
		HX_STACK_LINE(376)
		{
			HX_STACK_LINE(376)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(376)
			int _g = this->m_bodyCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(376)
			while((true)){
				HX_STACK_LINE(376)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(376)
					break;
				}
				HX_STACK_LINE(376)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(378)
				::box2D::dynamics::B2Body b = this->m_bodies->__get(i1).StaticCast< ::box2D::dynamics::B2Body >();		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(380)
				int _g2 = b->getType();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(380)
				if (((_g2 == (int)0))){
					HX_STACK_LINE(381)
					continue;
				}
				HX_STACK_LINE(385)
				Float translationX = (subStep->dt * b->m_linearVelocity->x);		HX_STACK_VAR(translationX,"translationX");
				HX_STACK_LINE(386)
				Float translationY = (subStep->dt * b->m_linearVelocity->y);		HX_STACK_VAR(translationY,"translationY");
				HX_STACK_LINE(388)
				if (((((translationX * translationX) + (translationY * translationY)) > ::box2D::common::B2Settings_obj::b2_maxTranslationSquared))){
					HX_STACK_LINE(390)
					b->m_linearVelocity->normalize();
					HX_STACK_LINE(391)
					hx::MultEq(b->m_linearVelocity->x,(::box2D::common::B2Settings_obj::b2_maxTranslation * subStep->inv_dt));
					HX_STACK_LINE(392)
					hx::MultEq(b->m_linearVelocity->y,(::box2D::common::B2Settings_obj::b2_maxTranslation * subStep->inv_dt));
				}
				HX_STACK_LINE(395)
				Float rotation = (subStep->dt * b->m_angularVelocity);		HX_STACK_VAR(rotation,"rotation");
				HX_STACK_LINE(396)
				if ((((rotation * rotation) > ::box2D::common::B2Settings_obj::b2_maxRotationSquared))){
					HX_STACK_LINE(398)
					if (((b->m_angularVelocity < 0.0))){
						HX_STACK_LINE(400)
						b->m_angularVelocity = (-(::box2D::common::B2Settings_obj::b2_maxRotation) * subStep->inv_dt);
					}
					else{
						HX_STACK_LINE(404)
						b->m_angularVelocity = (::box2D::common::B2Settings_obj::b2_maxRotation * subStep->inv_dt);
					}
				}
				HX_STACK_LINE(409)
				b->m_sweep->c0->setV(b->m_sweep->c);
				HX_STACK_LINE(410)
				b->m_sweep->a0 = b->m_sweep->a;
				HX_STACK_LINE(413)
				hx::AddEq(b->m_sweep->c->x,(subStep->dt * b->m_linearVelocity->x));
				HX_STACK_LINE(414)
				hx::AddEq(b->m_sweep->c->y,(subStep->dt * b->m_linearVelocity->y));
				HX_STACK_LINE(415)
				hx::AddEq(b->m_sweep->a,(subStep->dt * b->m_angularVelocity));
				HX_STACK_LINE(418)
				b->synchronizeTransform();
			}
		}
		HX_STACK_LINE(424)
		Float k_toiBaumgarte = 0.75;		HX_STACK_VAR(k_toiBaumgarte,"k_toiBaumgarte");
		HX_STACK_LINE(425)
		{
			HX_STACK_LINE(425)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(425)
			int _g = subStep->positionIterations;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(425)
			while((true)){
				HX_STACK_LINE(425)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(425)
					break;
				}
				HX_STACK_LINE(425)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(427)
				bool contactsOkay = contactSolver->solvePositionConstraints(k_toiBaumgarte);		HX_STACK_VAR(contactsOkay,"contactsOkay");
				HX_STACK_LINE(428)
				bool jointsOkay = true;		HX_STACK_VAR(jointsOkay,"jointsOkay");
				HX_STACK_LINE(429)
				{
					HX_STACK_LINE(429)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(429)
					int _g2 = this->m_jointCount;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(429)
					while((true)){
						HX_STACK_LINE(429)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(429)
							break;
						}
						HX_STACK_LINE(429)
						int j1 = (_g3)++;		HX_STACK_VAR(j1,"j1");
						HX_STACK_LINE(431)
						bool jointOkay = this->m_joints->__get(j1).StaticCast< ::box2D::dynamics::joints::B2Joint >()->solvePositionConstraints(::box2D::common::B2Settings_obj::b2_contactBaumgarte);		HX_STACK_VAR(jointOkay,"jointOkay");
						HX_STACK_LINE(432)
						jointsOkay = (bool(jointsOkay) && bool(jointOkay));
					}
				}
				HX_STACK_LINE(435)
				if (((bool(contactsOkay) && bool(jointsOkay)))){
					HX_STACK_LINE(437)
					break;
				}
			}
		}
		HX_STACK_LINE(440)
		this->report(contactSolver->m_constraints);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,solveTOI,(void))

Void B2Island_obj::report( Array< ::Dynamic > constraints){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","report",0xdb7d3ef4,"box2D.dynamics.B2Island.report","box2D/dynamics/B2Island.hx",445,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_ARG(constraints,"constraints")
		HX_STACK_LINE(446)
		if (((this->m_listener == null()))){
			HX_STACK_LINE(448)
			return null();
		}
		HX_STACK_LINE(451)
		{
			HX_STACK_LINE(451)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(451)
			int _g = this->m_contactCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(451)
			while((true)){
				HX_STACK_LINE(451)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(451)
					break;
				}
				HX_STACK_LINE(451)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(453)
				::box2D::dynamics::contacts::B2Contact c = this->m_contacts->__get(i).StaticCast< ::box2D::dynamics::contacts::B2Contact >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(454)
				::box2D::dynamics::contacts::B2ContactConstraint cc = constraints->__get(i).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraint >();		HX_STACK_VAR(cc,"cc");
				HX_STACK_LINE(456)
				{
					HX_STACK_LINE(456)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(456)
					int _g2 = cc->pointCount;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(456)
					while((true)){
						HX_STACK_LINE(456)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(456)
							break;
						}
						HX_STACK_LINE(456)
						int j = (_g3)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(458)
						::box2D::dynamics::B2Island_obj::s_impulse->normalImpulses[j] = cc->points->__get(j).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >()->normalImpulse;
						HX_STACK_LINE(459)
						::box2D::dynamics::B2Island_obj::s_impulse->tangentImpulses[j] = cc->points->__get(j).StaticCast< ::box2D::dynamics::contacts::B2ContactConstraintPoint >()->tangentImpulse;
					}
				}
				HX_STACK_LINE(461)
				this->m_listener->postSolve(c,::box2D::dynamics::B2Island_obj::s_impulse);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,report,(void))

Void B2Island_obj::addBody( ::box2D::dynamics::B2Body body){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","addBody",0x0241b323,"box2D.dynamics.B2Island.addBody","box2D/dynamics/B2Island.hx",467,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_ARG(body,"body")
		HX_STACK_LINE(469)
		body->m_islandIndex = this->m_bodyCount;
		HX_STACK_LINE(470)
		int _g = (this->m_bodyCount)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(470)
		this->m_bodies[_g] = body;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,addBody,(void))

Void B2Island_obj::addContact( ::box2D::dynamics::contacts::B2Contact contact){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","addContact",0x6d45c8bf,"box2D.dynamics.B2Island.addContact","box2D/dynamics/B2Island.hx",474,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_ARG(contact,"contact")
		HX_STACK_LINE(476)
		int _g = (this->m_contactCount)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(476)
		this->m_contacts[_g] = contact;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,addContact,(void))

Void B2Island_obj::addJoint( ::box2D::dynamics::joints::B2Joint joint){
{
		HX_STACK_FRAME("box2D.dynamics.B2Island","addJoint",0x927371a9,"box2D.dynamics.B2Island.addJoint","box2D/dynamics/B2Island.hx",480,0xbaa61170)
		HX_STACK_THIS(this)
		HX_STACK_ARG(joint,"joint")
		HX_STACK_LINE(482)
		int _g = (this->m_jointCount)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(482)
		this->m_joints[_g] = joint;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Island_obj,addJoint,(void))

::box2D::dynamics::B2ContactImpulse B2Island_obj::s_impulse;


B2Island_obj::B2Island_obj()
{
}

void B2Island_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Island);
	HX_MARK_MEMBER_NAME(m_allocator,"m_allocator");
	HX_MARK_MEMBER_NAME(m_listener,"m_listener");
	HX_MARK_MEMBER_NAME(m_contactSolver,"m_contactSolver");
	HX_MARK_MEMBER_NAME(m_bodies,"m_bodies");
	HX_MARK_MEMBER_NAME(m_contacts,"m_contacts");
	HX_MARK_MEMBER_NAME(m_joints,"m_joints");
	HX_MARK_MEMBER_NAME(m_bodyCount,"m_bodyCount");
	HX_MARK_MEMBER_NAME(m_jointCount,"m_jointCount");
	HX_MARK_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_MARK_MEMBER_NAME(m_bodyCapacity,"m_bodyCapacity");
	HX_MARK_MEMBER_NAME(m_contactCapacity,"m_contactCapacity");
	HX_MARK_MEMBER_NAME(m_jointCapacity,"m_jointCapacity");
	HX_MARK_END_CLASS();
}

void B2Island_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_allocator,"m_allocator");
	HX_VISIT_MEMBER_NAME(m_listener,"m_listener");
	HX_VISIT_MEMBER_NAME(m_contactSolver,"m_contactSolver");
	HX_VISIT_MEMBER_NAME(m_bodies,"m_bodies");
	HX_VISIT_MEMBER_NAME(m_contacts,"m_contacts");
	HX_VISIT_MEMBER_NAME(m_joints,"m_joints");
	HX_VISIT_MEMBER_NAME(m_bodyCount,"m_bodyCount");
	HX_VISIT_MEMBER_NAME(m_jointCount,"m_jointCount");
	HX_VISIT_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_VISIT_MEMBER_NAME(m_bodyCapacity,"m_bodyCapacity");
	HX_VISIT_MEMBER_NAME(m_contactCapacity,"m_contactCapacity");
	HX_VISIT_MEMBER_NAME(m_jointCapacity,"m_jointCapacity");
}

Dynamic B2Island_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"solve") ) { return solve_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"report") ) { return report_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addBody") ) { return addBody_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"solveTOI") ) { return solveTOI_dyn(); }
		if (HX_FIELD_EQ(inName,"addJoint") ) { return addJoint_dyn(); }
		if (HX_FIELD_EQ(inName,"m_bodies") ) { return m_bodies; }
		if (HX_FIELD_EQ(inName,"m_joints") ) { return m_joints; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_impulse") ) { return s_impulse; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"addContact") ) { return addContact_dyn(); }
		if (HX_FIELD_EQ(inName,"m_listener") ) { return m_listener; }
		if (HX_FIELD_EQ(inName,"m_contacts") ) { return m_contacts; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { return m_allocator; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { return m_bodyCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { return m_jointCount; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { return m_contactCount; }
		if (HX_FIELD_EQ(inName,"m_bodyCapacity") ) { return m_bodyCapacity; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { return m_contactSolver; }
		if (HX_FIELD_EQ(inName,"m_jointCapacity") ) { return m_jointCapacity; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactCapacity") ) { return m_contactCapacity; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Island_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"m_bodies") ) { m_bodies=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_joints") ) { m_joints=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_impulse") ) { s_impulse=inValue.Cast< ::box2D::dynamics::B2ContactImpulse >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_listener") ) { m_listener=inValue.Cast< ::box2D::dynamics::B2ContactListener >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_contacts") ) { m_contacts=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { m_allocator=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyCount") ) { m_bodyCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_jointCount") ) { m_jointCount=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { m_contactCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyCapacity") ) { m_bodyCapacity=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactSolver") ) { m_contactSolver=inValue.Cast< ::box2D::dynamics::contacts::B2ContactSolver >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_jointCapacity") ) { m_jointCapacity=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactCapacity") ) { m_contactCapacity=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Island_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_allocator"));
	outFields->push(HX_CSTRING("m_listener"));
	outFields->push(HX_CSTRING("m_contactSolver"));
	outFields->push(HX_CSTRING("m_bodies"));
	outFields->push(HX_CSTRING("m_contacts"));
	outFields->push(HX_CSTRING("m_joints"));
	outFields->push(HX_CSTRING("m_bodyCount"));
	outFields->push(HX_CSTRING("m_jointCount"));
	outFields->push(HX_CSTRING("m_contactCount"));
	outFields->push(HX_CSTRING("m_bodyCapacity"));
	outFields->push(HX_CSTRING("m_contactCapacity"));
	outFields->push(HX_CSTRING("m_jointCapacity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_impulse"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2Island_obj,m_allocator),HX_CSTRING("m_allocator")},
	{hx::fsObject /*::box2D::dynamics::B2ContactListener*/ ,(int)offsetof(B2Island_obj,m_listener),HX_CSTRING("m_listener")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactSolver*/ ,(int)offsetof(B2Island_obj,m_contactSolver),HX_CSTRING("m_contactSolver")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2Island_obj,m_bodies),HX_CSTRING("m_bodies")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2Island_obj,m_contacts),HX_CSTRING("m_contacts")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2Island_obj,m_joints),HX_CSTRING("m_joints")},
	{hx::fsInt,(int)offsetof(B2Island_obj,m_bodyCount),HX_CSTRING("m_bodyCount")},
	{hx::fsInt,(int)offsetof(B2Island_obj,m_jointCount),HX_CSTRING("m_jointCount")},
	{hx::fsInt,(int)offsetof(B2Island_obj,m_contactCount),HX_CSTRING("m_contactCount")},
	{hx::fsInt,(int)offsetof(B2Island_obj,m_bodyCapacity),HX_CSTRING("m_bodyCapacity")},
	{hx::fsInt,(int)offsetof(B2Island_obj,m_contactCapacity),HX_CSTRING("m_contactCapacity")},
	{hx::fsInt,(int)offsetof(B2Island_obj,m_jointCapacity),HX_CSTRING("m_jointCapacity")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("clear"),
	HX_CSTRING("solve"),
	HX_CSTRING("solveTOI"),
	HX_CSTRING("report"),
	HX_CSTRING("addBody"),
	HX_CSTRING("addContact"),
	HX_CSTRING("addJoint"),
	HX_CSTRING("m_allocator"),
	HX_CSTRING("m_listener"),
	HX_CSTRING("m_contactSolver"),
	HX_CSTRING("m_bodies"),
	HX_CSTRING("m_contacts"),
	HX_CSTRING("m_joints"),
	HX_CSTRING("m_bodyCount"),
	HX_CSTRING("m_jointCount"),
	HX_CSTRING("m_contactCount"),
	HX_CSTRING("m_bodyCapacity"),
	HX_CSTRING("m_contactCapacity"),
	HX_CSTRING("m_jointCapacity"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Island_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Island_obj::s_impulse,"s_impulse");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Island_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Island_obj::s_impulse,"s_impulse");
};

#endif

Class B2Island_obj::__mClass;

void B2Island_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2Island"), hx::TCanCast< B2Island_obj> ,sStaticFields,sMemberFields,
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

void B2Island_obj::__boot()
{
	s_impulse= ::box2D::dynamics::B2ContactImpulse_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
