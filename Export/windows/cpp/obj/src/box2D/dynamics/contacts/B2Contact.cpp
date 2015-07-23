#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TOIInput
#include <box2D/collision/B2TOIInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TimeOfImpact
#include <box2D/collision/B2TimeOfImpact.h>
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
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2ContactListener
#include <box2D/dynamics/B2ContactListener.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2Contact
#include <box2D/dynamics/contacts/B2Contact.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactEdge
#include <box2D/dynamics/contacts/B2ContactEdge.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2Contact_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","new",0x30f3a330,"box2D.dynamics.contacts.B2Contact.new","box2D/dynamics/contacts/B2Contact.hx",47,0xed128be1)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(378)
	this->m_toi = (int)0;
	HX_STACK_LINE(362)
	this->m_flags = (int)0;
	HX_STACK_LINE(186)
	::box2D::dynamics::contacts::B2ContactEdge _g = ::box2D::dynamics::contacts::B2ContactEdge_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(186)
	this->m_nodeA = _g;
	HX_STACK_LINE(187)
	::box2D::dynamics::contacts::B2ContactEdge _g1 = ::box2D::dynamics::contacts::B2ContactEdge_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(187)
	this->m_nodeB = _g1;
	HX_STACK_LINE(188)
	::box2D::collision::B2Manifold _g2 = ::box2D::collision::B2Manifold_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(188)
	this->m_manifold = _g2;
	HX_STACK_LINE(189)
	::box2D::collision::B2Manifold _g3 = ::box2D::collision::B2Manifold_obj::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(189)
	this->m_oldManifold = _g3;
}
;
	return null();
}

//B2Contact_obj::~B2Contact_obj() { }

Dynamic B2Contact_obj::__CreateEmpty() { return  new B2Contact_obj; }
hx::ObjectPtr< B2Contact_obj > B2Contact_obj::__new()
{  hx::ObjectPtr< B2Contact_obj > result = new B2Contact_obj();
	result->__construct();
	return result;}

Dynamic B2Contact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Contact_obj > result = new B2Contact_obj();
	result->__construct();
	return result;}

::box2D::collision::B2Manifold B2Contact_obj::getManifold( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","getManifold",0xca0c7196,"box2D.dynamics.contacts.B2Contact.getManifold","box2D/dynamics/contacts/B2Contact.hx",55,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->m_manifold;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getManifold,return )

Void B2Contact_obj::getWorldManifold( ::box2D::collision::B2WorldManifold worldManifold){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","getWorldManifold",0xde7ad53c,"box2D.dynamics.contacts.B2Contact.getWorldManifold","box2D/dynamics/contacts/B2Contact.hx",62,0xed128be1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(worldManifold,"worldManifold")
		HX_STACK_LINE(63)
		::box2D::dynamics::B2Body bodyA = this->m_fixtureA->getBody();		HX_STACK_VAR(bodyA,"bodyA");
		HX_STACK_LINE(64)
		::box2D::dynamics::B2Body bodyB = this->m_fixtureB->getBody();		HX_STACK_VAR(bodyB,"bodyB");
		HX_STACK_LINE(65)
		::box2D::collision::shapes::B2Shape shapeA = this->m_fixtureA->getShape();		HX_STACK_VAR(shapeA,"shapeA");
		HX_STACK_LINE(66)
		::box2D::collision::shapes::B2Shape shapeB = this->m_fixtureB->getShape();		HX_STACK_VAR(shapeB,"shapeB");
		HX_STACK_LINE(68)
		::box2D::common::math::B2Transform _g = bodyA->getTransform();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		::box2D::common::math::B2Transform _g1 = bodyB->getTransform();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(68)
		worldManifold->initialize(this->m_manifold,_g,shapeA->m_radius,_g1,shapeB->m_radius);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,getWorldManifold,(void))

bool B2Contact_obj::isTouching( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","isTouching",0x06af4fbd,"box2D.dynamics.contacts.B2Contact.isTouching","box2D/dynamics/contacts/B2Contact.hx",76,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(76)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isTouching,return )

bool B2Contact_obj::isContinuous( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","isContinuous",0x468d80c9,"box2D.dynamics.contacts.B2Contact.isContinuous","box2D/dynamics/contacts/B2Contact.hx",84,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(84)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isContinuous,return )

Void B2Contact_obj::setSensor( bool sensor){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","setSensor",0x21f1764c,"box2D.dynamics.contacts.B2Contact.setSensor","box2D/dynamics/contacts/B2Contact.hx",91,0xed128be1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(sensor,"sensor")
		HX_STACK_LINE(91)
		if ((sensor)){
			HX_STACK_LINE(93)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag);
		}
		else{
			HX_STACK_LINE(97)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,setSensor,(void))

bool B2Contact_obj::isSensor( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","isSensor",0x0efbc8f4,"box2D.dynamics.contacts.B2Contact.isSensor","box2D/dynamics/contacts/B2Contact.hx",105,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(105)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isSensor,return )

Void B2Contact_obj::setEnabled( bool flag){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","setEnabled",0x5ceb502f,"box2D.dynamics.contacts.B2Contact.setEnabled","box2D/dynamics/contacts/B2Contact.hx",114,0xed128be1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(flag,"flag")
		HX_STACK_LINE(114)
		if ((flag)){
			HX_STACK_LINE(116)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag);
		}
		else{
			HX_STACK_LINE(120)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,setEnabled,(void))

bool B2Contact_obj::isEnabled( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","isEnabled",0xd8e95087,"box2D.dynamics.contacts.B2Contact.isEnabled","box2D/dynamics/contacts/B2Contact.hx",129,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(129)
	return (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,isEnabled,return )

::box2D::dynamics::contacts::B2Contact B2Contact_obj::getNext( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","getNext",0x70ceaf79,"box2D.dynamics.contacts.B2Contact.getNext","box2D/dynamics/contacts/B2Contact.hx",136,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(136)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getNext,return )

::box2D::dynamics::B2Fixture B2Contact_obj::getFixtureA( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","getFixtureA",0xe53d79de,"box2D.dynamics.contacts.B2Contact.getFixtureA","box2D/dynamics/contacts/B2Contact.hx",144,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	return this->m_fixtureA;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getFixtureA,return )

::box2D::dynamics::B2Fixture B2Contact_obj::getFixtureB( ){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","getFixtureB",0xe53d79df,"box2D.dynamics.contacts.B2Contact.getFixtureB","box2D/dynamics/contacts/B2Contact.hx",152,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(152)
	return this->m_fixtureB;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,getFixtureB,return )

Void B2Contact_obj::flagForFiltering( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","flagForFiltering",0xfdebd4dd,"box2D.dynamics.contacts.B2Contact.flagForFiltering","box2D/dynamics/contacts/B2Contact.hx",160,0xed128be1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(160)
		hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_filterFlag);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,flagForFiltering,(void))

Void B2Contact_obj::reset( ::box2D::dynamics::B2Fixture fixtureA,::box2D::dynamics::B2Fixture fixtureB){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","reset",0x5d1e709f,"box2D.dynamics.contacts.B2Contact.reset","box2D/dynamics/contacts/B2Contact.hx",196,0xed128be1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(fixtureA,"fixtureA")
		HX_STACK_ARG(fixtureB,"fixtureB")
		HX_STACK_LINE(197)
		this->m_flags = ::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag;
		HX_STACK_LINE(199)
		if (((bool((fixtureA == null())) || bool((fixtureB == null()))))){
			HX_STACK_LINE(200)
			this->m_fixtureA = null();
			HX_STACK_LINE(201)
			this->m_fixtureB = null();
			HX_STACK_LINE(202)
			return null();
		}
		HX_STACK_LINE(205)
		if (((  ((!(fixtureA->isSensor()))) ? bool(fixtureB->isSensor()) : bool(true) ))){
			HX_STACK_LINE(207)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag);
		}
		HX_STACK_LINE(210)
		::box2D::dynamics::B2Body bodyA = fixtureA->getBody();		HX_STACK_VAR(bodyA,"bodyA");
		HX_STACK_LINE(211)
		::box2D::dynamics::B2Body bodyB = fixtureB->getBody();		HX_STACK_VAR(bodyB,"bodyB");
		HX_STACK_LINE(213)
		int _g = bodyA->getType();		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static bool Block( ::box2D::dynamics::B2Body &bodyB){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/contacts/B2Contact.hx",213,0xed128be1)
				{
					HX_STACK_LINE(213)
					int _g1 = bodyB->getType();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(213)
					return (_g1 != (int)2);
				}
				return null();
			}
		};
		HX_STACK_LINE(213)
		if (((  ((!(((  ((!(((  ((!(((_g != (int)2))))) ? bool(bodyA->isBullet()) : bool(true) ))))) ? bool(_Function_1_1::Block(bodyB)) : bool(true) ))))) ? bool(bodyB->isBullet()) : bool(true) ))){
			HX_STACK_LINE(215)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag);
		}
		HX_STACK_LINE(218)
		this->m_fixtureA = fixtureA;
		HX_STACK_LINE(219)
		this->m_fixtureB = fixtureB;
		HX_STACK_LINE(221)
		this->m_manifold->m_pointCount = (int)0;
		HX_STACK_LINE(223)
		this->m_prev = null();
		HX_STACK_LINE(224)
		this->m_next = null();
		HX_STACK_LINE(226)
		this->m_nodeA->contact = null();
		HX_STACK_LINE(227)
		this->m_nodeA->prev = null();
		HX_STACK_LINE(228)
		this->m_nodeA->next = null();
		HX_STACK_LINE(229)
		this->m_nodeA->other = null();
		HX_STACK_LINE(231)
		this->m_nodeB->contact = null();
		HX_STACK_LINE(232)
		this->m_nodeB->prev = null();
		HX_STACK_LINE(233)
		this->m_nodeB->next = null();
		HX_STACK_LINE(234)
		this->m_nodeB->other = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Contact_obj,reset,(void))

Void B2Contact_obj::update( ::box2D::dynamics::B2ContactListener listener){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","update",0x9c115539,"box2D.dynamics.contacts.B2Contact.update","box2D/dynamics/contacts/B2Contact.hx",238,0xed128be1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(listener,"listener")
		HX_STACK_LINE(240)
		::box2D::collision::B2Manifold tManifold = this->m_oldManifold;		HX_STACK_VAR(tManifold,"tManifold");
		HX_STACK_LINE(241)
		this->m_oldManifold = this->m_manifold;
		HX_STACK_LINE(242)
		this->m_manifold = tManifold;
		HX_STACK_LINE(245)
		hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_enabledFlag);
		HX_STACK_LINE(247)
		bool touching = false;		HX_STACK_VAR(touching,"touching");
		HX_STACK_LINE(248)
		bool wasTouching = (((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag))) == ::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag);		HX_STACK_VAR(wasTouching,"wasTouching");
		HX_STACK_LINE(250)
		::box2D::dynamics::B2Body bodyA = this->m_fixtureA->m_body;		HX_STACK_VAR(bodyA,"bodyA");
		HX_STACK_LINE(251)
		::box2D::dynamics::B2Body bodyB = this->m_fixtureB->m_body;		HX_STACK_VAR(bodyB,"bodyB");
		HX_STACK_LINE(253)
		bool aabbOverlap = this->m_fixtureA->m_aabb->testOverlap(this->m_fixtureB->m_aabb);		HX_STACK_VAR(aabbOverlap,"aabbOverlap");
		HX_STACK_LINE(256)
		if (((((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag))) != (int)0))){
			HX_STACK_LINE(258)
			if ((aabbOverlap)){
				HX_STACK_LINE(260)
				::box2D::collision::shapes::B2Shape shapeA = this->m_fixtureA->getShape();		HX_STACK_VAR(shapeA,"shapeA");
				HX_STACK_LINE(261)
				::box2D::collision::shapes::B2Shape shapeB = this->m_fixtureB->getShape();		HX_STACK_VAR(shapeB,"shapeB");
				HX_STACK_LINE(262)
				::box2D::common::math::B2Transform xfA = bodyA->getTransform();		HX_STACK_VAR(xfA,"xfA");
				HX_STACK_LINE(263)
				::box2D::common::math::B2Transform xfB = bodyB->getTransform();		HX_STACK_VAR(xfB,"xfB");
				HX_STACK_LINE(264)
				bool _g = ::box2D::collision::shapes::B2Shape_obj::testOverlap(shapeA,xfA,shapeB,xfB);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(264)
				touching = _g;
			}
			HX_STACK_LINE(268)
			this->m_manifold->m_pointCount = (int)0;
		}
		else{
			HX_STACK_LINE(273)
			int _g1 = bodyA->getType();		HX_STACK_VAR(_g1,"_g1");
			struct _Function_2_1{
				inline static bool Block( ::box2D::dynamics::B2Body &bodyB){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/contacts/B2Contact.hx",273,0xed128be1)
					{
						HX_STACK_LINE(273)
						int _g2 = bodyB->getType();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(273)
						return (_g2 != ::box2D::dynamics::B2Body_obj::b2_dynamicBody);
					}
					return null();
				}
			};
			HX_STACK_LINE(273)
			if (((  ((!(((  ((!(((  ((!(((_g1 != ::box2D::dynamics::B2Body_obj::b2_dynamicBody))))) ? bool(bodyA->isBullet()) : bool(true) ))))) ? bool(_Function_2_1::Block(bodyB)) : bool(true) ))))) ? bool(bodyB->isBullet()) : bool(true) ))){
				HX_STACK_LINE(275)
				hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag);
			}
			else{
				HX_STACK_LINE(279)
				hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_continuousFlag));
			}
			HX_STACK_LINE(282)
			if ((aabbOverlap)){
				HX_STACK_LINE(284)
				this->evaluate();
				HX_STACK_LINE(286)
				touching = (this->m_manifold->m_pointCount > (int)0);
				HX_STACK_LINE(290)
				{
					HX_STACK_LINE(290)
					int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(290)
					int _g = this->m_manifold->m_pointCount;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(290)
					while((true)){
						HX_STACK_LINE(290)
						if ((!(((_g11 < _g))))){
							HX_STACK_LINE(290)
							break;
						}
						HX_STACK_LINE(290)
						int i = (_g11)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(292)
						::box2D::collision::B2ManifoldPoint mp2 = this->m_manifold->m_points->__get(i).StaticCast< ::box2D::collision::B2ManifoldPoint >();		HX_STACK_VAR(mp2,"mp2");
						HX_STACK_LINE(293)
						mp2->m_normalImpulse = 0.0;
						HX_STACK_LINE(294)
						mp2->m_tangentImpulse = 0.0;
						HX_STACK_LINE(295)
						::box2D::collision::B2ContactID id2 = mp2->m_id;		HX_STACK_VAR(id2,"id2");
						HX_STACK_LINE(297)
						{
							HX_STACK_LINE(297)
							int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(297)
							int _g2 = this->m_oldManifold->m_pointCount;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(297)
							while((true)){
								HX_STACK_LINE(297)
								if ((!(((_g3 < _g2))))){
									HX_STACK_LINE(297)
									break;
								}
								HX_STACK_LINE(297)
								int j = (_g3)++;		HX_STACK_VAR(j,"j");
								HX_STACK_LINE(299)
								::box2D::collision::B2ManifoldPoint mp1 = this->m_oldManifold->m_points->__get(j).StaticCast< ::box2D::collision::B2ManifoldPoint >();		HX_STACK_VAR(mp1,"mp1");
								HX_STACK_LINE(301)
								int _g31 = mp1->m_id->get_key();		HX_STACK_VAR(_g31,"_g31");
								HX_STACK_LINE(301)
								int _g4 = id2->get_key();		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(301)
								if (((_g31 == _g4))){
									HX_STACK_LINE(303)
									mp2->m_normalImpulse = mp1->m_normalImpulse;
									HX_STACK_LINE(304)
									mp2->m_tangentImpulse = mp1->m_tangentImpulse;
									HX_STACK_LINE(305)
									break;
								}
							}
						}
					}
				}
			}
			else{
				HX_STACK_LINE(313)
				this->m_manifold->m_pointCount = (int)0;
			}
			HX_STACK_LINE(315)
			if (((touching != wasTouching))){
				HX_STACK_LINE(317)
				bodyA->setAwake(true);
				HX_STACK_LINE(318)
				bodyB->setAwake(true);
			}
		}
		HX_STACK_LINE(322)
		if ((touching)){
			HX_STACK_LINE(324)
			hx::OrEq(this->m_flags,::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag);
		}
		else{
			HX_STACK_LINE(328)
			hx::AndEq(this->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_touchingFlag));
		}
		HX_STACK_LINE(331)
		if (((bool((wasTouching == false)) && bool((touching == true))))){
			HX_STACK_LINE(333)
			listener->beginContact(hx::ObjectPtr<OBJ_>(this));
		}
		HX_STACK_LINE(336)
		if (((bool((wasTouching == true)) && bool((touching == false))))){
			HX_STACK_LINE(338)
			listener->endContact(hx::ObjectPtr<OBJ_>(this));
		}
		HX_STACK_LINE(341)
		if (((((int(this->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_sensorFlag))) == (int)0))){
			HX_STACK_LINE(343)
			listener->preSolve(hx::ObjectPtr<OBJ_>(this),this->m_oldManifold);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Contact_obj,update,(void))

Void B2Contact_obj::evaluate( ){
{
		HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","evaluate",0x4c525b89,"box2D.dynamics.contacts.B2Contact.evaluate","box2D/dynamics/contacts/B2Contact.hx",349,0xed128be1)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Contact_obj,evaluate,(void))

Float B2Contact_obj::computeTOI( ::box2D::common::math::B2Sweep sweepA,::box2D::common::math::B2Sweep sweepB){
	HX_STACK_FRAME("box2D.dynamics.contacts.B2Contact","computeTOI",0xc071a687,"box2D.dynamics.contacts.B2Contact.computeTOI","box2D/dynamics/contacts/B2Contact.hx",353,0xed128be1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(sweepA,"sweepA")
	HX_STACK_ARG(sweepB,"sweepB")
	HX_STACK_LINE(354)
	::box2D::collision::shapes::B2Shape _g = this->m_fixtureA->getShape();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(354)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->proxyA->set(_g);
	HX_STACK_LINE(355)
	::box2D::collision::shapes::B2Shape _g1 = this->m_fixtureB->getShape();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(355)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->proxyB->set(_g1);
	HX_STACK_LINE(356)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->sweepA = sweepA;
	HX_STACK_LINE(357)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->sweepB = sweepB;
	HX_STACK_LINE(358)
	::box2D::dynamics::contacts::B2Contact_obj::s_input->tolerance = ::box2D::common::B2Settings_obj::b2_linearSlop;
	HX_STACK_LINE(359)
	return ::box2D::collision::B2TimeOfImpact_obj::timeOfImpact(::box2D::dynamics::contacts::B2Contact_obj::s_input);
}


HX_DEFINE_DYNAMIC_FUNC2(B2Contact_obj,computeTOI,return )

int B2Contact_obj::e_sensorFlag;

int B2Contact_obj::e_continuousFlag;

int B2Contact_obj::e_islandFlag;

int B2Contact_obj::e_toiFlag;

int B2Contact_obj::e_touchingFlag;

int B2Contact_obj::e_enabledFlag;

int B2Contact_obj::e_filterFlag;

::box2D::collision::B2TOIInput B2Contact_obj::s_input;


B2Contact_obj::B2Contact_obj()
{
}

void B2Contact_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Contact);
	HX_MARK_MEMBER_NAME(m_flags,"m_flags");
	HX_MARK_MEMBER_NAME(m_prev,"m_prev");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_nodeA,"m_nodeA");
	HX_MARK_MEMBER_NAME(m_nodeB,"m_nodeB");
	HX_MARK_MEMBER_NAME(m_fixtureA,"m_fixtureA");
	HX_MARK_MEMBER_NAME(m_fixtureB,"m_fixtureB");
	HX_MARK_MEMBER_NAME(m_manifold,"m_manifold");
	HX_MARK_MEMBER_NAME(m_oldManifold,"m_oldManifold");
	HX_MARK_MEMBER_NAME(m_toi,"m_toi");
	HX_MARK_END_CLASS();
}

void B2Contact_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_flags,"m_flags");
	HX_VISIT_MEMBER_NAME(m_prev,"m_prev");
	HX_VISIT_MEMBER_NAME(m_next,"m_next");
	HX_VISIT_MEMBER_NAME(m_nodeA,"m_nodeA");
	HX_VISIT_MEMBER_NAME(m_nodeB,"m_nodeB");
	HX_VISIT_MEMBER_NAME(m_fixtureA,"m_fixtureA");
	HX_VISIT_MEMBER_NAME(m_fixtureB,"m_fixtureB");
	HX_VISIT_MEMBER_NAME(m_manifold,"m_manifold");
	HX_VISIT_MEMBER_NAME(m_oldManifold,"m_oldManifold");
	HX_VISIT_MEMBER_NAME(m_toi,"m_toi");
}

Dynamic B2Contact_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"m_toi") ) { return m_toi; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"m_prev") ) { return m_prev; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_input") ) { return s_input; }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"m_flags") ) { return m_flags; }
		if (HX_FIELD_EQ(inName,"m_nodeA") ) { return m_nodeA; }
		if (HX_FIELD_EQ(inName,"m_nodeB") ) { return m_nodeB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"isSensor") ) { return isSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"evaluate") ) { return evaluate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_toiFlag") ) { return e_toiFlag; }
		if (HX_FIELD_EQ(inName,"setSensor") ) { return setSensor_dyn(); }
		if (HX_FIELD_EQ(inName,"isEnabled") ) { return isEnabled_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"isTouching") ) { return isTouching_dyn(); }
		if (HX_FIELD_EQ(inName,"setEnabled") ) { return setEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"computeTOI") ) { return computeTOI_dyn(); }
		if (HX_FIELD_EQ(inName,"m_fixtureA") ) { return m_fixtureA; }
		if (HX_FIELD_EQ(inName,"m_fixtureB") ) { return m_fixtureB; }
		if (HX_FIELD_EQ(inName,"m_manifold") ) { return m_manifold; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getManifold") ) { return getManifold_dyn(); }
		if (HX_FIELD_EQ(inName,"getFixtureA") ) { return getFixtureA_dyn(); }
		if (HX_FIELD_EQ(inName,"getFixtureB") ) { return getFixtureB_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_sensorFlag") ) { return e_sensorFlag; }
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { return e_islandFlag; }
		if (HX_FIELD_EQ(inName,"e_filterFlag") ) { return e_filterFlag; }
		if (HX_FIELD_EQ(inName,"isContinuous") ) { return isContinuous_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_enabledFlag") ) { return e_enabledFlag; }
		if (HX_FIELD_EQ(inName,"m_oldManifold") ) { return m_oldManifold; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_touchingFlag") ) { return e_touchingFlag; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_continuousFlag") ) { return e_continuousFlag; }
		if (HX_FIELD_EQ(inName,"getWorldManifold") ) { return getWorldManifold_dyn(); }
		if (HX_FIELD_EQ(inName,"flagForFiltering") ) { return flagForFiltering_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Contact_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"m_toi") ) { m_toi=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_prev") ) { m_prev=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_input") ) { s_input=inValue.Cast< ::box2D::collision::B2TOIInput >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_flags") ) { m_flags=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nodeA") ) { m_nodeA=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nodeB") ) { m_nodeB=inValue.Cast< ::box2D::dynamics::contacts::B2ContactEdge >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"e_toiFlag") ) { e_toiFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_fixtureA") ) { m_fixtureA=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fixtureB") ) { m_fixtureB=inValue.Cast< ::box2D::dynamics::B2Fixture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_manifold") ) { m_manifold=inValue.Cast< ::box2D::collision::B2Manifold >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_sensorFlag") ) { e_sensorFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_islandFlag") ) { e_islandFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"e_filterFlag") ) { e_filterFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_enabledFlag") ) { e_enabledFlag=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_oldManifold") ) { m_oldManifold=inValue.Cast< ::box2D::collision::B2Manifold >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"e_touchingFlag") ) { e_touchingFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"e_continuousFlag") ) { e_continuousFlag=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Contact_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_flags"));
	outFields->push(HX_CSTRING("m_prev"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_nodeA"));
	outFields->push(HX_CSTRING("m_nodeB"));
	outFields->push(HX_CSTRING("m_fixtureA"));
	outFields->push(HX_CSTRING("m_fixtureB"));
	outFields->push(HX_CSTRING("m_manifold"));
	outFields->push(HX_CSTRING("m_oldManifold"));
	outFields->push(HX_CSTRING("m_toi"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("e_sensorFlag"),
	HX_CSTRING("e_continuousFlag"),
	HX_CSTRING("e_islandFlag"),
	HX_CSTRING("e_toiFlag"),
	HX_CSTRING("e_touchingFlag"),
	HX_CSTRING("e_enabledFlag"),
	HX_CSTRING("e_filterFlag"),
	HX_CSTRING("s_input"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2Contact_obj,m_flags),HX_CSTRING("m_flags")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2Contact*/ ,(int)offsetof(B2Contact_obj,m_prev),HX_CSTRING("m_prev")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2Contact*/ ,(int)offsetof(B2Contact_obj,m_next),HX_CSTRING("m_next")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactEdge*/ ,(int)offsetof(B2Contact_obj,m_nodeA),HX_CSTRING("m_nodeA")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactEdge*/ ,(int)offsetof(B2Contact_obj,m_nodeB),HX_CSTRING("m_nodeB")},
	{hx::fsObject /*::box2D::dynamics::B2Fixture*/ ,(int)offsetof(B2Contact_obj,m_fixtureA),HX_CSTRING("m_fixtureA")},
	{hx::fsObject /*::box2D::dynamics::B2Fixture*/ ,(int)offsetof(B2Contact_obj,m_fixtureB),HX_CSTRING("m_fixtureB")},
	{hx::fsObject /*::box2D::collision::B2Manifold*/ ,(int)offsetof(B2Contact_obj,m_manifold),HX_CSTRING("m_manifold")},
	{hx::fsObject /*::box2D::collision::B2Manifold*/ ,(int)offsetof(B2Contact_obj,m_oldManifold),HX_CSTRING("m_oldManifold")},
	{hx::fsFloat,(int)offsetof(B2Contact_obj,m_toi),HX_CSTRING("m_toi")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getManifold"),
	HX_CSTRING("getWorldManifold"),
	HX_CSTRING("isTouching"),
	HX_CSTRING("isContinuous"),
	HX_CSTRING("setSensor"),
	HX_CSTRING("isSensor"),
	HX_CSTRING("setEnabled"),
	HX_CSTRING("isEnabled"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getFixtureA"),
	HX_CSTRING("getFixtureB"),
	HX_CSTRING("flagForFiltering"),
	HX_CSTRING("reset"),
	HX_CSTRING("update"),
	HX_CSTRING("evaluate"),
	HX_CSTRING("computeTOI"),
	HX_CSTRING("m_flags"),
	HX_CSTRING("m_prev"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_nodeA"),
	HX_CSTRING("m_nodeB"),
	HX_CSTRING("m_fixtureA"),
	HX_CSTRING("m_fixtureB"),
	HX_CSTRING("m_manifold"),
	HX_CSTRING("m_oldManifold"),
	HX_CSTRING("m_toi"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Contact_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_sensorFlag,"e_sensorFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_continuousFlag,"e_continuousFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_islandFlag,"e_islandFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_toiFlag,"e_toiFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_touchingFlag,"e_touchingFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_enabledFlag,"e_enabledFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::e_filterFlag,"e_filterFlag");
	HX_MARK_MEMBER_NAME(B2Contact_obj::s_input,"s_input");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Contact_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::e_sensorFlag,"e_sensorFlag");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::e_continuousFlag,"e_continuousFlag");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::e_islandFlag,"e_islandFlag");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::e_toiFlag,"e_toiFlag");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::e_touchingFlag,"e_touchingFlag");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::e_enabledFlag,"e_enabledFlag");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::e_filterFlag,"e_filterFlag");
	HX_VISIT_MEMBER_NAME(B2Contact_obj::s_input,"s_input");
};

#endif

Class B2Contact_obj::__mClass;

void B2Contact_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2Contact"), hx::TCanCast< B2Contact_obj> ,sStaticFields,sMemberFields,
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

void B2Contact_obj::__boot()
{
	e_sensorFlag= (int)1;
	e_continuousFlag= (int)2;
	e_islandFlag= (int)4;
	e_toiFlag= (int)8;
	e_touchingFlag= (int)16;
	e_enabledFlag= (int)32;
	e_filterFlag= (int)64;
	s_input= ::box2D::collision::B2TOIInput_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
