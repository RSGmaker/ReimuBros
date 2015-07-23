#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJoint
#include <box2D/dynamics/joints/B2DistanceJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJointDef
#include <box2D/dynamics/joints/B2DistanceJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJoint
#include <box2D/dynamics/joints/B2FrictionJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJointDef
#include <box2D/dynamics/joints/B2FrictionJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2GearJoint
#include <box2D/dynamics/joints/B2GearJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2GearJointDef
#include <box2D/dynamics/joints/B2GearJointDef.h>
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
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJoint
#include <box2D/dynamics/joints/B2LineJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJointDef
#include <box2D/dynamics/joints/B2LineJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJoint
#include <box2D/dynamics/joints/B2MouseJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2MouseJointDef
#include <box2D/dynamics/joints/B2MouseJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJoint
#include <box2D/dynamics/joints/B2PrismaticJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJointDef
#include <box2D/dynamics/joints/B2PrismaticJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJoint
#include <box2D/dynamics/joints/B2PulleyJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PulleyJointDef
#include <box2D/dynamics/joints/B2PulleyJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJoint
#include <box2D/dynamics/joints/B2RevoluteJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2RevoluteJointDef
#include <box2D/dynamics/joints/B2RevoluteJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJoint
#include <box2D/dynamics/joints/B2WeldJoint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJointDef
#include <box2D/dynamics/joints/B2WeldJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2Joint_obj::__construct(::box2D::dynamics::joints::B2JointDef def)
{
HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","new",0x84591630,"box2D.dynamics.joints.B2Joint.new","box2D/dynamics/joints/B2Joint.hx",220,0x64e1d6a1)
HX_STACK_THIS(this)
HX_STACK_ARG(def,"def")
{
	HX_STACK_LINE(222)
	::box2D::dynamics::joints::B2JointEdge _g = ::box2D::dynamics::joints::B2JointEdge_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(222)
	this->m_edgeA = _g;
	HX_STACK_LINE(223)
	::box2D::dynamics::joints::B2JointEdge _g1 = ::box2D::dynamics::joints::B2JointEdge_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(223)
	this->m_edgeB = _g1;
	HX_STACK_LINE(224)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(224)
	this->m_localCenterA = _g2;
	HX_STACK_LINE(225)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(225)
	this->m_localCenterB = _g3;
	HX_STACK_LINE(227)
	::box2D::common::B2Settings_obj::b2Assert((def->bodyA != def->bodyB));
	HX_STACK_LINE(228)
	this->m_type = def->type;
	HX_STACK_LINE(229)
	this->m_prev = null();
	HX_STACK_LINE(230)
	this->m_next = null();
	HX_STACK_LINE(231)
	this->m_bodyA = def->bodyA;
	HX_STACK_LINE(232)
	this->m_bodyB = def->bodyB;
	HX_STACK_LINE(233)
	this->m_collideConnected = def->collideConnected;
	HX_STACK_LINE(234)
	this->m_islandFlag = false;
	HX_STACK_LINE(235)
	this->m_userData = def->userData;
}
;
	return null();
}

//B2Joint_obj::~B2Joint_obj() { }

Dynamic B2Joint_obj::__CreateEmpty() { return  new B2Joint_obj; }
hx::ObjectPtr< B2Joint_obj > B2Joint_obj::__new(::box2D::dynamics::joints::B2JointDef def)
{  hx::ObjectPtr< B2Joint_obj > result = new B2Joint_obj();
	result->__construct(def);
	return result;}

Dynamic B2Joint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Joint_obj > result = new B2Joint_obj();
	result->__construct(inArgs[0]);
	return result;}

int B2Joint_obj::getType( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getType",0xf3701040,"box2D.dynamics.joints.B2Joint.getType","box2D/dynamics/joints/B2Joint.hx",39,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(39)
	return this->m_type;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getType,return )

::box2D::common::math::B2Vec2 B2Joint_obj::getAnchorA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getAnchorA",0x9a5d8666,"box2D.dynamics.joints.B2Joint.getAnchorA","box2D/dynamics/joints/B2Joint.hx",45,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(45)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getAnchorA,return )

::box2D::common::math::B2Vec2 B2Joint_obj::getAnchorB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getAnchorB",0x9a5d8667,"box2D.dynamics.joints.B2Joint.getAnchorB","box2D/dynamics/joints/B2Joint.hx",49,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(49)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getAnchorB,return )

::box2D::common::math::B2Vec2 B2Joint_obj::getReactionForce( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getReactionForce",0xc27fd73c,"box2D.dynamics.joints.B2Joint.getReactionForce","box2D/dynamics/joints/B2Joint.hx",54,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(54)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,getReactionForce,return )

Float B2Joint_obj::getReactionTorque( Float inv_dt){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getReactionTorque",0x06663859,"box2D.dynamics.joints.B2Joint.getReactionTorque","box2D/dynamics/joints/B2Joint.hx",58,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(inv_dt,"inv_dt")
	HX_STACK_LINE(58)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,getReactionTorque,return )

::box2D::dynamics::B2Body B2Joint_obj::getBodyA( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getBodyA",0xaac28b19,"box2D.dynamics.joints.B2Joint.getBodyA","box2D/dynamics/joints/B2Joint.hx",65,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(65)
	return this->m_bodyA;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getBodyA,return )

::box2D::dynamics::B2Body B2Joint_obj::getBodyB( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getBodyB",0xaac28b1a,"box2D.dynamics.joints.B2Joint.getBodyB","box2D/dynamics/joints/B2Joint.hx",73,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(73)
	return this->m_bodyB;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getBodyB,return )

::box2D::dynamics::joints::B2Joint B2Joint_obj::getNext( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getNext",0xef69a279,"box2D.dynamics.joints.B2Joint.getNext","box2D/dynamics/joints/B2Joint.hx",80,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(80)
	return this->m_next;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getNext,return )

Dynamic B2Joint_obj::getUserData( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","getUserData",0x3193ee9b,"box2D.dynamics.joints.B2Joint.getUserData","box2D/dynamics/joints/B2Joint.hx",87,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(87)
	return this->m_userData;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,getUserData,return )

Void B2Joint_obj::setUserData( Dynamic data){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","setUserData",0x3c00f5a7,"box2D.dynamics.joints.B2Joint.setUserData","box2D/dynamics/joints/B2Joint.hx",94,0x64e1d6a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(94)
		this->m_userData = data;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,setUserData,(void))

bool B2Joint_obj::isActive( ){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","isActive",0x02ab8580,"box2D.dynamics.joints.B2Joint.isActive","box2D/dynamics/joints/B2Joint.hx",102,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(102)
	if ((this->m_bodyA->isActive())){
		HX_STACK_LINE(102)
		return this->m_bodyB->isActive();
	}
	else{
		HX_STACK_LINE(102)
		return false;
	}
	HX_STACK_LINE(102)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,isActive,return )

Void B2Joint_obj::initVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","initVelocityConstraints",0x775a06f9,"box2D.dynamics.joints.B2Joint.initVelocityConstraints","box2D/dynamics/joints/B2Joint.hx",239,0x64e1d6a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,initVelocityConstraints,(void))

Void B2Joint_obj::solveVelocityConstraints( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","solveVelocityConstraints",0xcc2f5e4a,"box2D.dynamics.joints.B2Joint.solveVelocityConstraints","box2D/dynamics/joints/B2Joint.hx",240,0x64e1d6a1)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,solveVelocityConstraints,(void))

Void B2Joint_obj::finalizeVelocityConstraints( ){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","finalizeVelocityConstraints",0x6edfb52b,"box2D.dynamics.joints.B2Joint.finalizeVelocityConstraints","box2D/dynamics/joints/B2Joint.hx",241,0x64e1d6a1)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Joint_obj,finalizeVelocityConstraints,(void))

bool B2Joint_obj::solvePositionConstraints( Float baumgarte){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","solvePositionConstraints",0x040b733e,"box2D.dynamics.joints.B2Joint.solvePositionConstraints","box2D/dynamics/joints/B2Joint.hx",244,0x64e1d6a1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(baumgarte,"baumgarte")
	HX_STACK_LINE(244)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Joint_obj,solvePositionConstraints,return )

::box2D::dynamics::joints::B2Joint B2Joint_obj::create( ::box2D::dynamics::joints::B2JointDef def,Dynamic allocator){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","create",0xae5fa32c,"box2D.dynamics.joints.B2Joint.create","box2D/dynamics/joints/B2Joint.hx",107,0x64e1d6a1)
	HX_STACK_ARG(def,"def")
	HX_STACK_ARG(allocator,"allocator")
	HX_STACK_LINE(108)
	::box2D::dynamics::joints::B2Joint joint = null();		HX_STACK_VAR(joint,"joint");
	HX_STACK_LINE(110)
	{
		HX_STACK_LINE(110)
		int _g = def->type;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(110)
		switch( (int)(_g)){
			case (int)3: {
				HX_STACK_LINE(115)
				::box2D::dynamics::joints::B2DistanceJointDef _g1;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(115)
				_g1 = hx::TCast< box2D::dynamics::joints::B2DistanceJointDef >::cast(def);
				HX_STACK_LINE(115)
				::box2D::dynamics::joints::B2DistanceJoint _g11 = ::box2D::dynamics::joints::B2DistanceJoint_obj::__new(_g1);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(115)
				joint = _g11;
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(121)
				::box2D::dynamics::joints::B2MouseJointDef _g2;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(121)
				_g2 = hx::TCast< box2D::dynamics::joints::B2MouseJointDef >::cast(def);
				HX_STACK_LINE(121)
				::box2D::dynamics::joints::B2MouseJoint _g3 = ::box2D::dynamics::joints::B2MouseJoint_obj::__new(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(121)
				joint = _g3;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(127)
				::box2D::dynamics::joints::B2PrismaticJointDef _g4;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(127)
				_g4 = hx::TCast< box2D::dynamics::joints::B2PrismaticJointDef >::cast(def);
				HX_STACK_LINE(127)
				::box2D::dynamics::joints::B2PrismaticJoint _g5 = ::box2D::dynamics::joints::B2PrismaticJoint_obj::__new(_g4);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(127)
				joint = _g5;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(133)
				::box2D::dynamics::joints::B2RevoluteJointDef _g6;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(133)
				_g6 = hx::TCast< box2D::dynamics::joints::B2RevoluteJointDef >::cast(def);
				HX_STACK_LINE(133)
				::box2D::dynamics::joints::B2RevoluteJoint _g7 = ::box2D::dynamics::joints::B2RevoluteJoint_obj::__new(_g6);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(133)
				joint = _g7;
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(139)
				::box2D::dynamics::joints::B2PulleyJointDef _g8;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(139)
				_g8 = hx::TCast< box2D::dynamics::joints::B2PulleyJointDef >::cast(def);
				HX_STACK_LINE(139)
				::box2D::dynamics::joints::B2PulleyJoint _g9 = ::box2D::dynamics::joints::B2PulleyJoint_obj::__new(_g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(139)
				joint = _g9;
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(145)
				::box2D::dynamics::joints::B2GearJointDef _g10;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(145)
				_g10 = hx::TCast< box2D::dynamics::joints::B2GearJointDef >::cast(def);
				HX_STACK_LINE(145)
				::box2D::dynamics::joints::B2GearJoint _g11 = ::box2D::dynamics::joints::B2GearJoint_obj::__new(_g10);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(145)
				joint = _g11;
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(151)
				::box2D::dynamics::joints::B2LineJointDef _g12;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(151)
				_g12 = hx::TCast< box2D::dynamics::joints::B2LineJointDef >::cast(def);
				HX_STACK_LINE(151)
				::box2D::dynamics::joints::B2LineJoint _g13 = ::box2D::dynamics::joints::B2LineJoint_obj::__new(_g12);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(151)
				joint = _g13;
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(157)
				::box2D::dynamics::joints::B2WeldJointDef _g14;		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(157)
				_g14 = hx::TCast< box2D::dynamics::joints::B2WeldJointDef >::cast(def);
				HX_STACK_LINE(157)
				::box2D::dynamics::joints::B2WeldJoint _g15 = ::box2D::dynamics::joints::B2WeldJoint_obj::__new(_g14);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(157)
				joint = _g15;
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(163)
				::box2D::dynamics::joints::B2FrictionJointDef _g16;		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(163)
				_g16 = hx::TCast< box2D::dynamics::joints::B2FrictionJointDef >::cast(def);
				HX_STACK_LINE(163)
				::box2D::dynamics::joints::B2FrictionJoint _g17 = ::box2D::dynamics::joints::B2FrictionJoint_obj::__new(_g16);		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(163)
				joint = _g17;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(170)
	return joint;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Joint_obj,create,return )

Void B2Joint_obj::destroy( ::box2D::dynamics::joints::B2Joint joint,Dynamic allocator){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2Joint","destroy",0xf86a9aca,"box2D.dynamics.joints.B2Joint.destroy","box2D/dynamics/joints/B2Joint.hx",173,0x64e1d6a1)
		HX_STACK_ARG(joint,"joint")
		HX_STACK_ARG(allocator,"allocator")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Joint_obj,destroy,(void))


B2Joint_obj::B2Joint_obj()
{
}

void B2Joint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Joint);
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_prev,"m_prev");
	HX_MARK_MEMBER_NAME(m_next,"m_next");
	HX_MARK_MEMBER_NAME(m_edgeA,"m_edgeA");
	HX_MARK_MEMBER_NAME(m_edgeB,"m_edgeB");
	HX_MARK_MEMBER_NAME(m_bodyA,"m_bodyA");
	HX_MARK_MEMBER_NAME(m_bodyB,"m_bodyB");
	HX_MARK_MEMBER_NAME(m_islandFlag,"m_islandFlag");
	HX_MARK_MEMBER_NAME(m_collideConnected,"m_collideConnected");
	HX_MARK_MEMBER_NAME(m_userData,"m_userData");
	HX_MARK_MEMBER_NAME(m_localCenterA,"m_localCenterA");
	HX_MARK_MEMBER_NAME(m_localCenterB,"m_localCenterB");
	HX_MARK_MEMBER_NAME(m_invMassA,"m_invMassA");
	HX_MARK_MEMBER_NAME(m_invMassB,"m_invMassB");
	HX_MARK_MEMBER_NAME(m_invIA,"m_invIA");
	HX_MARK_MEMBER_NAME(m_invIB,"m_invIB");
	HX_MARK_END_CLASS();
}

void B2Joint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_type,"m_type");
	HX_VISIT_MEMBER_NAME(m_prev,"m_prev");
	HX_VISIT_MEMBER_NAME(m_next,"m_next");
	HX_VISIT_MEMBER_NAME(m_edgeA,"m_edgeA");
	HX_VISIT_MEMBER_NAME(m_edgeB,"m_edgeB");
	HX_VISIT_MEMBER_NAME(m_bodyA,"m_bodyA");
	HX_VISIT_MEMBER_NAME(m_bodyB,"m_bodyB");
	HX_VISIT_MEMBER_NAME(m_islandFlag,"m_islandFlag");
	HX_VISIT_MEMBER_NAME(m_collideConnected,"m_collideConnected");
	HX_VISIT_MEMBER_NAME(m_userData,"m_userData");
	HX_VISIT_MEMBER_NAME(m_localCenterA,"m_localCenterA");
	HX_VISIT_MEMBER_NAME(m_localCenterB,"m_localCenterB");
	HX_VISIT_MEMBER_NAME(m_invMassA,"m_invMassA");
	HX_VISIT_MEMBER_NAME(m_invMassB,"m_invMassB");
	HX_VISIT_MEMBER_NAME(m_invIA,"m_invIA");
	HX_VISIT_MEMBER_NAME(m_invIB,"m_invIB");
}

Dynamic B2Joint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { return m_prev; }
		if (HX_FIELD_EQ(inName,"m_next") ) { return m_next; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"getNext") ) { return getNext_dyn(); }
		if (HX_FIELD_EQ(inName,"m_edgeA") ) { return m_edgeA; }
		if (HX_FIELD_EQ(inName,"m_edgeB") ) { return m_edgeB; }
		if (HX_FIELD_EQ(inName,"m_bodyA") ) { return m_bodyA; }
		if (HX_FIELD_EQ(inName,"m_bodyB") ) { return m_bodyB; }
		if (HX_FIELD_EQ(inName,"m_invIA") ) { return m_invIA; }
		if (HX_FIELD_EQ(inName,"m_invIB") ) { return m_invIB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getBodyA") ) { return getBodyA_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyB") ) { return getBodyB_dyn(); }
		if (HX_FIELD_EQ(inName,"isActive") ) { return isActive_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getAnchorA") ) { return getAnchorA_dyn(); }
		if (HX_FIELD_EQ(inName,"getAnchorB") ) { return getAnchorB_dyn(); }
		if (HX_FIELD_EQ(inName,"m_userData") ) { return m_userData; }
		if (HX_FIELD_EQ(inName,"m_invMassA") ) { return m_invMassA; }
		if (HX_FIELD_EQ(inName,"m_invMassB") ) { return m_invMassB; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getUserData") ) { return getUserData_dyn(); }
		if (HX_FIELD_EQ(inName,"setUserData") ) { return setUserData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_islandFlag") ) { return m_islandFlag; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localCenterA") ) { return m_localCenterA; }
		if (HX_FIELD_EQ(inName,"m_localCenterB") ) { return m_localCenterB; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getReactionForce") ) { return getReactionForce_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getReactionTorque") ) { return getReactionTorque_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_collideConnected") ) { return m_collideConnected; }
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

Dynamic B2Joint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prev") ) { m_prev=inValue.Cast< ::box2D::dynamics::joints::B2Joint >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_next") ) { m_next=inValue.Cast< ::box2D::dynamics::joints::B2Joint >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_edgeA") ) { m_edgeA=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_edgeB") ) { m_edgeB=inValue.Cast< ::box2D::dynamics::joints::B2JointEdge >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyA") ) { m_bodyA=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_bodyB") ) { m_bodyB=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invIA") ) { m_invIA=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invIB") ) { m_invIB=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_userData") ) { m_userData=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invMassA") ) { m_invMassA=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invMassB") ) { m_invMassB=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_islandFlag") ) { m_islandFlag=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_localCenterA") ) { m_localCenterA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_localCenterB") ) { m_localCenterB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_collideConnected") ) { m_collideConnected=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Joint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_prev"));
	outFields->push(HX_CSTRING("m_next"));
	outFields->push(HX_CSTRING("m_edgeA"));
	outFields->push(HX_CSTRING("m_edgeB"));
	outFields->push(HX_CSTRING("m_bodyA"));
	outFields->push(HX_CSTRING("m_bodyB"));
	outFields->push(HX_CSTRING("m_islandFlag"));
	outFields->push(HX_CSTRING("m_collideConnected"));
	outFields->push(HX_CSTRING("m_userData"));
	outFields->push(HX_CSTRING("m_localCenterA"));
	outFields->push(HX_CSTRING("m_localCenterB"));
	outFields->push(HX_CSTRING("m_invMassA"));
	outFields->push(HX_CSTRING("m_invMassB"));
	outFields->push(HX_CSTRING("m_invIA"));
	outFields->push(HX_CSTRING("m_invIB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2Joint_obj,m_type),HX_CSTRING("m_type")},
	{hx::fsObject /*::box2D::dynamics::joints::B2Joint*/ ,(int)offsetof(B2Joint_obj,m_prev),HX_CSTRING("m_prev")},
	{hx::fsObject /*::box2D::dynamics::joints::B2Joint*/ ,(int)offsetof(B2Joint_obj,m_next),HX_CSTRING("m_next")},
	{hx::fsObject /*::box2D::dynamics::joints::B2JointEdge*/ ,(int)offsetof(B2Joint_obj,m_edgeA),HX_CSTRING("m_edgeA")},
	{hx::fsObject /*::box2D::dynamics::joints::B2JointEdge*/ ,(int)offsetof(B2Joint_obj,m_edgeB),HX_CSTRING("m_edgeB")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2Joint_obj,m_bodyA),HX_CSTRING("m_bodyA")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2Joint_obj,m_bodyB),HX_CSTRING("m_bodyB")},
	{hx::fsBool,(int)offsetof(B2Joint_obj,m_islandFlag),HX_CSTRING("m_islandFlag")},
	{hx::fsBool,(int)offsetof(B2Joint_obj,m_collideConnected),HX_CSTRING("m_collideConnected")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2Joint_obj,m_userData),HX_CSTRING("m_userData")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Joint_obj,m_localCenterA),HX_CSTRING("m_localCenterA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Joint_obj,m_localCenterB),HX_CSTRING("m_localCenterB")},
	{hx::fsFloat,(int)offsetof(B2Joint_obj,m_invMassA),HX_CSTRING("m_invMassA")},
	{hx::fsFloat,(int)offsetof(B2Joint_obj,m_invMassB),HX_CSTRING("m_invMassB")},
	{hx::fsFloat,(int)offsetof(B2Joint_obj,m_invIA),HX_CSTRING("m_invIA")},
	{hx::fsFloat,(int)offsetof(B2Joint_obj,m_invIB),HX_CSTRING("m_invIB")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getType"),
	HX_CSTRING("getAnchorA"),
	HX_CSTRING("getAnchorB"),
	HX_CSTRING("getReactionForce"),
	HX_CSTRING("getReactionTorque"),
	HX_CSTRING("getBodyA"),
	HX_CSTRING("getBodyB"),
	HX_CSTRING("getNext"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("setUserData"),
	HX_CSTRING("isActive"),
	HX_CSTRING("initVelocityConstraints"),
	HX_CSTRING("solveVelocityConstraints"),
	HX_CSTRING("finalizeVelocityConstraints"),
	HX_CSTRING("solvePositionConstraints"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_prev"),
	HX_CSTRING("m_next"),
	HX_CSTRING("m_edgeA"),
	HX_CSTRING("m_edgeB"),
	HX_CSTRING("m_bodyA"),
	HX_CSTRING("m_bodyB"),
	HX_CSTRING("m_islandFlag"),
	HX_CSTRING("m_collideConnected"),
	HX_CSTRING("m_userData"),
	HX_CSTRING("m_localCenterA"),
	HX_CSTRING("m_localCenterB"),
	HX_CSTRING("m_invMassA"),
	HX_CSTRING("m_invMassB"),
	HX_CSTRING("m_invIA"),
	HX_CSTRING("m_invIB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Joint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Joint_obj::__mClass,"__mClass");
};

#endif

Class B2Joint_obj::__mClass;

void B2Joint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2Joint"), hx::TCanCast< B2Joint_obj> ,sStaticFields,sMemberFields,
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

void B2Joint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
