#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactPoint
#include <box2D/collision/B2ContactPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeBroadPhase
#include <box2D/collision/B2DynamicTreeBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
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
#ifndef INCLUDED_box2D_dynamics_B2Fixture
#include <box2D/dynamics/B2Fixture.h>
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
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactFactory
#include <box2D/dynamics/contacts/B2ContactFactory.h>
#endif
namespace box2D{
namespace dynamics{

Void B2ContactManager_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2ContactManager","new",0x953567f8,"box2D.dynamics.B2ContactManager.new","box2D/dynamics/B2ContactManager.hx",36,0xbc61b298)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(37)
	this->m_world = null();
	HX_STACK_LINE(38)
	this->m_contactCount = (int)0;
	HX_STACK_LINE(39)
	this->m_contactFilter = ::box2D::dynamics::B2ContactFilter_obj::b2_defaultFilter;
	HX_STACK_LINE(40)
	this->m_contactListener = ::box2D::dynamics::B2ContactListener_obj::b2_defaultListener;
	HX_STACK_LINE(41)
	::box2D::dynamics::contacts::B2ContactFactory _g = ::box2D::dynamics::contacts::B2ContactFactory_obj::__new(this->m_allocator);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	this->m_contactFactory = _g;
	HX_STACK_LINE(42)
	::box2D::collision::B2DynamicTreeBroadPhase _g1 = ::box2D::collision::B2DynamicTreeBroadPhase_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(42)
	this->m_broadPhase = _g1;
}
;
	return null();
}

//B2ContactManager_obj::~B2ContactManager_obj() { }

Dynamic B2ContactManager_obj::__CreateEmpty() { return  new B2ContactManager_obj; }
hx::ObjectPtr< B2ContactManager_obj > B2ContactManager_obj::__new()
{  hx::ObjectPtr< B2ContactManager_obj > result = new B2ContactManager_obj();
	result->__construct();
	return result;}

Dynamic B2ContactManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactManager_obj > result = new B2ContactManager_obj();
	result->__construct();
	return result;}

Void B2ContactManager_obj::addPair( Dynamic proxyUserDataA,Dynamic proxyUserDataB){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactManager","addPair",0xa6706273,"box2D.dynamics.B2ContactManager.addPair","box2D/dynamics/B2ContactManager.hx",47,0xbc61b298)
		HX_STACK_THIS(this)
		HX_STACK_ARG(proxyUserDataA,"proxyUserDataA")
		HX_STACK_ARG(proxyUserDataB,"proxyUserDataB")
		HX_STACK_LINE(48)
		::box2D::dynamics::B2Fixture fixtureA;		HX_STACK_VAR(fixtureA,"fixtureA");
		HX_STACK_LINE(48)
		fixtureA = hx::TCast< box2D::dynamics::B2Fixture >::cast(proxyUserDataA);
		HX_STACK_LINE(49)
		::box2D::dynamics::B2Fixture fixtureB;		HX_STACK_VAR(fixtureB,"fixtureB");
		HX_STACK_LINE(49)
		fixtureB = hx::TCast< box2D::dynamics::B2Fixture >::cast(proxyUserDataB);
		HX_STACK_LINE(51)
		::box2D::dynamics::B2Body bodyA = fixtureA->getBody();		HX_STACK_VAR(bodyA,"bodyA");
		HX_STACK_LINE(52)
		::box2D::dynamics::B2Body bodyB = fixtureB->getBody();		HX_STACK_VAR(bodyB,"bodyB");
		HX_STACK_LINE(55)
		if (((bodyA == bodyB))){
			HX_STACK_LINE(56)
			return null();
		}
		HX_STACK_LINE(59)
		::box2D::dynamics::contacts::B2ContactEdge edge = bodyB->getContactList();		HX_STACK_VAR(edge,"edge");
		HX_STACK_LINE(60)
		while((true)){
			HX_STACK_LINE(60)
			if ((!(((edge != null()))))){
				HX_STACK_LINE(60)
				break;
			}
			HX_STACK_LINE(62)
			if (((edge->other == bodyA))){
				HX_STACK_LINE(64)
				::box2D::dynamics::B2Fixture fA = edge->contact->getFixtureA();		HX_STACK_VAR(fA,"fA");
				HX_STACK_LINE(65)
				::box2D::dynamics::B2Fixture fB = edge->contact->getFixtureB();		HX_STACK_VAR(fB,"fB");
				HX_STACK_LINE(66)
				if (((bool((fA == fixtureA)) && bool((fB == fixtureB))))){
					HX_STACK_LINE(67)
					return null();
				}
				HX_STACK_LINE(68)
				if (((bool((fA == fixtureB)) && bool((fB == fixtureA))))){
					HX_STACK_LINE(69)
					return null();
				}
			}
			HX_STACK_LINE(71)
			edge = edge->next;
		}
		HX_STACK_LINE(75)
		bool _g = bodyB->shouldCollide(bodyA);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(75)
		if (((_g == false))){
			HX_STACK_LINE(77)
			return null();
		}
		HX_STACK_LINE(81)
		bool _g1 = this->m_contactFilter->shouldCollide(fixtureA,fixtureB);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(81)
		if (((_g1 == false))){
			HX_STACK_LINE(83)
			return null();
		}
		HX_STACK_LINE(87)
		::box2D::dynamics::contacts::B2Contact c = this->m_contactFactory->create(fixtureA,fixtureB);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(90)
		::box2D::dynamics::B2Fixture _g2 = c->getFixtureA();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(90)
		fixtureA = _g2;
		HX_STACK_LINE(91)
		::box2D::dynamics::B2Fixture _g3 = c->getFixtureB();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(91)
		fixtureB = _g3;
		HX_STACK_LINE(92)
		bodyA = fixtureA->m_body;
		HX_STACK_LINE(93)
		bodyB = fixtureB->m_body;
		HX_STACK_LINE(96)
		c->m_prev = null();
		HX_STACK_LINE(97)
		c->m_next = this->m_world->m_contactList;
		HX_STACK_LINE(98)
		if (((this->m_world->m_contactList != null()))){
			HX_STACK_LINE(100)
			this->m_world->m_contactList->m_prev = c;
		}
		HX_STACK_LINE(102)
		this->m_world->m_contactList = c;
		HX_STACK_LINE(108)
		c->m_nodeA->contact = c;
		HX_STACK_LINE(109)
		c->m_nodeA->other = bodyB;
		HX_STACK_LINE(111)
		c->m_nodeA->prev = null();
		HX_STACK_LINE(112)
		c->m_nodeA->next = bodyA->m_contactList;
		HX_STACK_LINE(113)
		if (((bodyA->m_contactList != null()))){
			HX_STACK_LINE(115)
			bodyA->m_contactList->prev = c->m_nodeA;
		}
		HX_STACK_LINE(117)
		bodyA->m_contactList = c->m_nodeA;
		HX_STACK_LINE(120)
		c->m_nodeB->contact = c;
		HX_STACK_LINE(121)
		c->m_nodeB->other = bodyA;
		HX_STACK_LINE(123)
		c->m_nodeB->prev = null();
		HX_STACK_LINE(124)
		c->m_nodeB->next = bodyB->m_contactList;
		HX_STACK_LINE(125)
		if (((bodyB->m_contactList != null()))){
			HX_STACK_LINE(127)
			bodyB->m_contactList->prev = c->m_nodeB;
		}
		HX_STACK_LINE(129)
		bodyB->m_contactList = c->m_nodeB;
		HX_STACK_LINE(131)
		++(this->m_world->m_contactCount);
		HX_STACK_LINE(132)
		return null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2ContactManager_obj,addPair,(void))

Void B2ContactManager_obj::findNewContacts( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactManager","findNewContacts",0xe90e8a32,"box2D.dynamics.B2ContactManager.findNewContacts","box2D/dynamics/B2ContactManager.hx",138,0xbc61b298)
		HX_STACK_THIS(this)
		HX_STACK_LINE(138)
		this->m_broadPhase->updatePairs(this->addPair_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactManager_obj,findNewContacts,(void))

Void B2ContactManager_obj::destroy( ::box2D::dynamics::contacts::B2Contact c){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactManager","destroy",0x44677092,"box2D.dynamics.B2ContactManager.destroy","box2D/dynamics/B2ContactManager.hx",143,0xbc61b298)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(145)
		::box2D::dynamics::B2Fixture fixtureA = c->getFixtureA();		HX_STACK_VAR(fixtureA,"fixtureA");
		HX_STACK_LINE(146)
		::box2D::dynamics::B2Fixture fixtureB = c->getFixtureB();		HX_STACK_VAR(fixtureB,"fixtureB");
		HX_STACK_LINE(147)
		::box2D::dynamics::B2Body bodyA = fixtureA->getBody();		HX_STACK_VAR(bodyA,"bodyA");
		HX_STACK_LINE(148)
		::box2D::dynamics::B2Body bodyB = fixtureB->getBody();		HX_STACK_VAR(bodyB,"bodyB");
		HX_STACK_LINE(150)
		if ((c->isTouching())){
			HX_STACK_LINE(152)
			this->m_contactListener->endContact(c);
		}
		HX_STACK_LINE(156)
		if (((c->m_prev != null()))){
			HX_STACK_LINE(158)
			c->m_prev->m_next = c->m_next;
		}
		HX_STACK_LINE(161)
		if (((c->m_next != null()))){
			HX_STACK_LINE(163)
			c->m_next->m_prev = c->m_prev;
		}
		HX_STACK_LINE(166)
		if (((c == this->m_world->m_contactList))){
			HX_STACK_LINE(168)
			this->m_world->m_contactList = c->m_next;
		}
		HX_STACK_LINE(172)
		if (((c->m_nodeA->prev != null()))){
			HX_STACK_LINE(174)
			c->m_nodeA->prev->next = c->m_nodeA->next;
		}
		HX_STACK_LINE(177)
		if (((c->m_nodeA->next != null()))){
			HX_STACK_LINE(179)
			c->m_nodeA->next->prev = c->m_nodeA->prev;
		}
		HX_STACK_LINE(182)
		if (((c->m_nodeA == bodyA->m_contactList))){
			HX_STACK_LINE(184)
			bodyA->m_contactList = c->m_nodeA->next;
		}
		HX_STACK_LINE(188)
		if (((c->m_nodeB->prev != null()))){
			HX_STACK_LINE(190)
			c->m_nodeB->prev->next = c->m_nodeB->next;
		}
		HX_STACK_LINE(193)
		if (((c->m_nodeB->next != null()))){
			HX_STACK_LINE(195)
			c->m_nodeB->next->prev = c->m_nodeB->prev;
		}
		HX_STACK_LINE(198)
		if (((c->m_nodeB == bodyB->m_contactList))){
			HX_STACK_LINE(200)
			bodyB->m_contactList = c->m_nodeB->next;
		}
		HX_STACK_LINE(204)
		this->m_contactFactory->destroy(c);
		HX_STACK_LINE(205)
		--(this->m_contactCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactManager_obj,destroy,(void))

Void B2ContactManager_obj::collide( ){
{
		HX_STACK_FRAME("box2D.dynamics.B2ContactManager","collide",0x0d44f316,"box2D.dynamics.B2ContactManager.collide","box2D/dynamics/B2ContactManager.hx",213,0xbc61b298)
		HX_STACK_THIS(this)
		HX_STACK_LINE(215)
		::box2D::dynamics::contacts::B2Contact c = this->m_world->m_contactList;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(216)
		while((true)){
			HX_STACK_LINE(216)
			if ((!(((c != null()))))){
				HX_STACK_LINE(216)
				break;
			}
			HX_STACK_LINE(218)
			::box2D::dynamics::B2Fixture fixtureA = c->getFixtureA();		HX_STACK_VAR(fixtureA,"fixtureA");
			HX_STACK_LINE(219)
			::box2D::dynamics::B2Fixture fixtureB = c->getFixtureB();		HX_STACK_VAR(fixtureB,"fixtureB");
			HX_STACK_LINE(220)
			::box2D::dynamics::B2Body bodyA = fixtureA->getBody();		HX_STACK_VAR(bodyA,"bodyA");
			HX_STACK_LINE(221)
			::box2D::dynamics::B2Body bodyB = fixtureB->getBody();		HX_STACK_VAR(bodyB,"bodyB");
			HX_STACK_LINE(222)
			bool _g = bodyA->isAwake();		HX_STACK_VAR(_g,"_g");
			struct _Function_2_1{
				inline static bool Block( ::box2D::dynamics::B2Body &bodyB){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/dynamics/B2ContactManager.hx",222,0xbc61b298)
					{
						HX_STACK_LINE(222)
						bool _g1 = bodyB->isAwake();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(222)
						return (_g1 == false);
					}
					return null();
				}
			};
			HX_STACK_LINE(222)
			if (((  (((_g == false))) ? bool(_Function_2_1::Block(bodyB)) : bool(false) ))){
				HX_STACK_LINE(224)
				::box2D::dynamics::contacts::B2Contact _g2 = c->getNext();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(224)
				c = _g2;
				HX_STACK_LINE(225)
				continue;
			}
			HX_STACK_LINE(229)
			if (((((int(c->m_flags) & int(::box2D::dynamics::contacts::B2Contact_obj::e_filterFlag))) != (int)0))){
				HX_STACK_LINE(232)
				bool _g3 = bodyB->shouldCollide(bodyA);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(232)
				if (((_g3 == false))){
					HX_STACK_LINE(234)
					::box2D::dynamics::contacts::B2Contact cNuke = c;		HX_STACK_VAR(cNuke,"cNuke");
					HX_STACK_LINE(235)
					::box2D::dynamics::contacts::B2Contact _g4 = cNuke->getNext();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(235)
					c = _g4;
					HX_STACK_LINE(236)
					this->destroy(cNuke);
					HX_STACK_LINE(237)
					continue;
				}
				HX_STACK_LINE(241)
				bool _g5 = this->m_contactFilter->shouldCollide(fixtureA,fixtureB);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(241)
				if (((_g5 == false))){
					HX_STACK_LINE(243)
					::box2D::dynamics::contacts::B2Contact cNuke = c;		HX_STACK_VAR(cNuke,"cNuke");
					HX_STACK_LINE(244)
					::box2D::dynamics::contacts::B2Contact _g6 = cNuke->getNext();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(244)
					c = _g6;
					HX_STACK_LINE(245)
					this->destroy(cNuke);
					HX_STACK_LINE(246)
					continue;
				}
				HX_STACK_LINE(250)
				hx::AndEq(c->m_flags,~(int)(::box2D::dynamics::contacts::B2Contact_obj::e_filterFlag));
			}
			HX_STACK_LINE(253)
			Dynamic proxyA = fixtureA->m_proxy;		HX_STACK_VAR(proxyA,"proxyA");
			HX_STACK_LINE(254)
			Dynamic proxyB = fixtureB->m_proxy;		HX_STACK_VAR(proxyB,"proxyB");
			HX_STACK_LINE(256)
			bool overlap = this->m_broadPhase->testOverlap(proxyA,proxyB);		HX_STACK_VAR(overlap,"overlap");
			HX_STACK_LINE(259)
			if (((overlap == false))){
				HX_STACK_LINE(261)
				::box2D::dynamics::contacts::B2Contact cNuke = c;		HX_STACK_VAR(cNuke,"cNuke");
				HX_STACK_LINE(262)
				::box2D::dynamics::contacts::B2Contact _g7 = cNuke->getNext();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(262)
				c = _g7;
				HX_STACK_LINE(263)
				this->destroy(cNuke);
				HX_STACK_LINE(264)
				continue;
			}
			HX_STACK_LINE(267)
			c->update(this->m_contactListener);
			HX_STACK_LINE(268)
			::box2D::dynamics::contacts::B2Contact _g8 = c->getNext();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(268)
			c = _g8;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactManager_obj,collide,(void))

::box2D::collision::B2ContactPoint B2ContactManager_obj::s_evalCP;


B2ContactManager_obj::B2ContactManager_obj()
{
}

void B2ContactManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactManager);
	HX_MARK_MEMBER_NAME(m_world,"m_world");
	HX_MARK_MEMBER_NAME(m_broadPhase,"m_broadPhase");
	HX_MARK_MEMBER_NAME(m_contactList,"m_contactList");
	HX_MARK_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_MARK_MEMBER_NAME(m_contactFilter,"m_contactFilter");
	HX_MARK_MEMBER_NAME(m_contactListener,"m_contactListener");
	HX_MARK_MEMBER_NAME(m_contactFactory,"m_contactFactory");
	HX_MARK_MEMBER_NAME(m_allocator,"m_allocator");
	HX_MARK_END_CLASS();
}

void B2ContactManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_world,"m_world");
	HX_VISIT_MEMBER_NAME(m_broadPhase,"m_broadPhase");
	HX_VISIT_MEMBER_NAME(m_contactList,"m_contactList");
	HX_VISIT_MEMBER_NAME(m_contactCount,"m_contactCount");
	HX_VISIT_MEMBER_NAME(m_contactFilter,"m_contactFilter");
	HX_VISIT_MEMBER_NAME(m_contactListener,"m_contactListener");
	HX_VISIT_MEMBER_NAME(m_contactFactory,"m_contactFactory");
	HX_VISIT_MEMBER_NAME(m_allocator,"m_allocator");
}

Dynamic B2ContactManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"addPair") ) { return addPair_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"collide") ) { return collide_dyn(); }
		if (HX_FIELD_EQ(inName,"m_world") ) { return m_world; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_evalCP") ) { return s_evalCP; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { return m_allocator; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_broadPhase") ) { return m_broadPhase; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_contactList") ) { return m_contactList; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { return m_contactCount; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"findNewContacts") ) { return findNewContacts_dyn(); }
		if (HX_FIELD_EQ(inName,"m_contactFilter") ) { return m_contactFilter; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_contactFactory") ) { return m_contactFactory; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactListener") ) { return m_contactListener; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_world") ) { m_world=inValue.Cast< ::box2D::dynamics::B2World >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_evalCP") ) { s_evalCP=inValue.Cast< ::box2D::collision::B2ContactPoint >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_allocator") ) { m_allocator=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_broadPhase") ) { m_broadPhase=inValue.Cast< ::box2D::collision::IBroadPhase >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_contactList") ) { m_contactList=inValue.Cast< ::box2D::dynamics::contacts::B2Contact >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_contactCount") ) { m_contactCount=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_contactFilter") ) { m_contactFilter=inValue.Cast< ::box2D::dynamics::B2ContactFilter >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_contactFactory") ) { m_contactFactory=inValue.Cast< ::box2D::dynamics::contacts::B2ContactFactory >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_contactListener") ) { m_contactListener=inValue.Cast< ::box2D::dynamics::B2ContactListener >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_world"));
	outFields->push(HX_CSTRING("m_broadPhase"));
	outFields->push(HX_CSTRING("m_contactList"));
	outFields->push(HX_CSTRING("m_contactCount"));
	outFields->push(HX_CSTRING("m_contactFilter"));
	outFields->push(HX_CSTRING("m_contactListener"));
	outFields->push(HX_CSTRING("m_contactFactory"));
	outFields->push(HX_CSTRING("m_allocator"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("s_evalCP"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::dynamics::B2World*/ ,(int)offsetof(B2ContactManager_obj,m_world),HX_CSTRING("m_world")},
	{hx::fsObject /*::box2D::collision::IBroadPhase*/ ,(int)offsetof(B2ContactManager_obj,m_broadPhase),HX_CSTRING("m_broadPhase")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2Contact*/ ,(int)offsetof(B2ContactManager_obj,m_contactList),HX_CSTRING("m_contactList")},
	{hx::fsInt,(int)offsetof(B2ContactManager_obj,m_contactCount),HX_CSTRING("m_contactCount")},
	{hx::fsObject /*::box2D::dynamics::B2ContactFilter*/ ,(int)offsetof(B2ContactManager_obj,m_contactFilter),HX_CSTRING("m_contactFilter")},
	{hx::fsObject /*::box2D::dynamics::B2ContactListener*/ ,(int)offsetof(B2ContactManager_obj,m_contactListener),HX_CSTRING("m_contactListener")},
	{hx::fsObject /*::box2D::dynamics::contacts::B2ContactFactory*/ ,(int)offsetof(B2ContactManager_obj,m_contactFactory),HX_CSTRING("m_contactFactory")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2ContactManager_obj,m_allocator),HX_CSTRING("m_allocator")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("addPair"),
	HX_CSTRING("findNewContacts"),
	HX_CSTRING("destroy"),
	HX_CSTRING("collide"),
	HX_CSTRING("m_world"),
	HX_CSTRING("m_broadPhase"),
	HX_CSTRING("m_contactList"),
	HX_CSTRING("m_contactCount"),
	HX_CSTRING("m_contactFilter"),
	HX_CSTRING("m_contactListener"),
	HX_CSTRING("m_contactFactory"),
	HX_CSTRING("m_allocator"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2ContactManager_obj::s_evalCP,"s_evalCP");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2ContactManager_obj::s_evalCP,"s_evalCP");
};

#endif

Class B2ContactManager_obj::__mClass;

void B2ContactManager_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2ContactManager"), hx::TCanCast< B2ContactManager_obj> ,sStaticFields,sMemberFields,
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

void B2ContactManager_obj::__boot()
{
	s_evalCP= ::box2D::collision::B2ContactPoint_obj::__new();
}

} // end namespace box2D
} // end namespace dynamics
