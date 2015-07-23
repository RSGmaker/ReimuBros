#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
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

Void B2PulleyJointDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJointDef","new",0xeb521cb2,"box2D.dynamics.joints.B2PulleyJointDef.new","box2D/dynamics/joints/B2PulleyJointDef.hx",37,0x784ef37d)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(38)
	super::__construct();
	HX_STACK_LINE(39)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(39)
	this->groundAnchorA = _g;
	HX_STACK_LINE(40)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(40)
	this->groundAnchorB = _g1;
	HX_STACK_LINE(41)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(41)
	this->localAnchorA = _g2;
	HX_STACK_LINE(42)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(42)
	this->localAnchorB = _g3;
	HX_STACK_LINE(44)
	this->type = (int)4;
	HX_STACK_LINE(45)
	this->groundAnchorA->set(-1.0,1.0);
	HX_STACK_LINE(46)
	this->groundAnchorB->set(1.0,1.0);
	HX_STACK_LINE(47)
	this->localAnchorA->set(-1.0,0.0);
	HX_STACK_LINE(48)
	this->localAnchorB->set(1.0,0.0);
	HX_STACK_LINE(49)
	this->lengthA = 0.0;
	HX_STACK_LINE(50)
	this->maxLengthA = 0.0;
	HX_STACK_LINE(51)
	this->lengthB = 0.0;
	HX_STACK_LINE(52)
	this->maxLengthB = 0.0;
	HX_STACK_LINE(53)
	this->ratio = 1.0;
	HX_STACK_LINE(54)
	this->collideConnected = true;
}
;
	return null();
}

//B2PulleyJointDef_obj::~B2PulleyJointDef_obj() { }

Dynamic B2PulleyJointDef_obj::__CreateEmpty() { return  new B2PulleyJointDef_obj; }
hx::ObjectPtr< B2PulleyJointDef_obj > B2PulleyJointDef_obj::__new()
{  hx::ObjectPtr< B2PulleyJointDef_obj > result = new B2PulleyJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2PulleyJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PulleyJointDef_obj > result = new B2PulleyJointDef_obj();
	result->__construct();
	return result;}

Void B2PulleyJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 gaA,::box2D::common::math::B2Vec2 gaB,::box2D::common::math::B2Vec2 anchorA,::box2D::common::math::B2Vec2 anchorB,Float r){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PulleyJointDef","initialize",0xc986f33e,"box2D.dynamics.joints.B2PulleyJointDef.initialize","box2D/dynamics/joints/B2PulleyJointDef.hx",61,0x784ef37d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bA,"bA")
		HX_STACK_ARG(bB,"bB")
		HX_STACK_ARG(gaA,"gaA")
		HX_STACK_ARG(gaB,"gaB")
		HX_STACK_ARG(anchorA,"anchorA")
		HX_STACK_ARG(anchorB,"anchorB")
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(62)
		this->bodyA = bA;
		HX_STACK_LINE(63)
		this->bodyB = bB;
		HX_STACK_LINE(64)
		this->groundAnchorA->setV(gaA);
		HX_STACK_LINE(65)
		this->groundAnchorB->setV(gaB);
		HX_STACK_LINE(66)
		::box2D::common::math::B2Vec2 _g = this->bodyA->getLocalPoint(anchorA);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(66)
		this->localAnchorA = _g;
		HX_STACK_LINE(67)
		::box2D::common::math::B2Vec2 _g1 = this->bodyB->getLocalPoint(anchorB);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(67)
		this->localAnchorB = _g1;
		HX_STACK_LINE(69)
		Float d1X = (anchorA->x - gaA->x);		HX_STACK_VAR(d1X,"d1X");
		HX_STACK_LINE(70)
		Float d1Y = (anchorA->y - gaA->y);		HX_STACK_VAR(d1Y,"d1Y");
		HX_STACK_LINE(72)
		Float _g2 = ::Math_obj::sqrt(((d1X * d1X) + (d1Y * d1Y)));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(72)
		this->lengthA = _g2;
		HX_STACK_LINE(75)
		Float d2X = (anchorB->x - gaB->x);		HX_STACK_VAR(d2X,"d2X");
		HX_STACK_LINE(76)
		Float d2Y = (anchorB->y - gaB->y);		HX_STACK_VAR(d2Y,"d2Y");
		HX_STACK_LINE(78)
		Float _g3 = ::Math_obj::sqrt(((d2X * d2X) + (d2Y * d2Y)));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(78)
		this->lengthB = _g3;
		HX_STACK_LINE(80)
		this->ratio = r;
		HX_STACK_LINE(82)
		Float C = (this->lengthA + (this->ratio * this->lengthB));		HX_STACK_VAR(C,"C");
		HX_STACK_LINE(83)
		this->maxLengthA = (C - (this->ratio * ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength));
		HX_STACK_LINE(84)
		this->maxLengthB = (Float(((C - ::box2D::dynamics::joints::B2PulleyJoint_obj::b2_minPulleyLength))) / Float(this->ratio));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(B2PulleyJointDef_obj,initialize,(void))


B2PulleyJointDef_obj::B2PulleyJointDef_obj()
{
}

void B2PulleyJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PulleyJointDef);
	HX_MARK_MEMBER_NAME(groundAnchorA,"groundAnchorA");
	HX_MARK_MEMBER_NAME(groundAnchorB,"groundAnchorB");
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(lengthA,"lengthA");
	HX_MARK_MEMBER_NAME(maxLengthA,"maxLengthA");
	HX_MARK_MEMBER_NAME(lengthB,"lengthB");
	HX_MARK_MEMBER_NAME(maxLengthB,"maxLengthB");
	HX_MARK_MEMBER_NAME(ratio,"ratio");
	::box2D::dynamics::joints::B2JointDef_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2PulleyJointDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(groundAnchorA,"groundAnchorA");
	HX_VISIT_MEMBER_NAME(groundAnchorB,"groundAnchorB");
	HX_VISIT_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_VISIT_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_VISIT_MEMBER_NAME(lengthA,"lengthA");
	HX_VISIT_MEMBER_NAME(maxLengthA,"maxLengthA");
	HX_VISIT_MEMBER_NAME(lengthB,"lengthB");
	HX_VISIT_MEMBER_NAME(maxLengthB,"maxLengthB");
	HX_VISIT_MEMBER_NAME(ratio,"ratio");
	::box2D::dynamics::joints::B2JointDef_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2PulleyJointDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ratio") ) { return ratio; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"lengthA") ) { return lengthA; }
		if (HX_FIELD_EQ(inName,"lengthB") ) { return lengthB; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"maxLengthA") ) { return maxLengthA; }
		if (HX_FIELD_EQ(inName,"maxLengthB") ) { return maxLengthB; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"groundAnchorA") ) { return groundAnchorA; }
		if (HX_FIELD_EQ(inName,"groundAnchorB") ) { return groundAnchorB; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2PulleyJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ratio") ) { ratio=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"lengthA") ) { lengthA=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lengthB") ) { lengthB=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxLengthA") ) { maxLengthA=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxLengthB") ) { maxLengthB=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"groundAnchorA") ) { groundAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"groundAnchorB") ) { groundAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2PulleyJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("groundAnchorA"));
	outFields->push(HX_CSTRING("groundAnchorB"));
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("lengthA"));
	outFields->push(HX_CSTRING("maxLengthA"));
	outFields->push(HX_CSTRING("lengthB"));
	outFields->push(HX_CSTRING("maxLengthB"));
	outFields->push(HX_CSTRING("ratio"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJointDef_obj,groundAnchorA),HX_CSTRING("groundAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJointDef_obj,groundAnchorB),HX_CSTRING("groundAnchorB")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJointDef_obj,localAnchorA),HX_CSTRING("localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PulleyJointDef_obj,localAnchorB),HX_CSTRING("localAnchorB")},
	{hx::fsFloat,(int)offsetof(B2PulleyJointDef_obj,lengthA),HX_CSTRING("lengthA")},
	{hx::fsFloat,(int)offsetof(B2PulleyJointDef_obj,maxLengthA),HX_CSTRING("maxLengthA")},
	{hx::fsFloat,(int)offsetof(B2PulleyJointDef_obj,lengthB),HX_CSTRING("lengthB")},
	{hx::fsFloat,(int)offsetof(B2PulleyJointDef_obj,maxLengthB),HX_CSTRING("maxLengthB")},
	{hx::fsFloat,(int)offsetof(B2PulleyJointDef_obj,ratio),HX_CSTRING("ratio")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("groundAnchorA"),
	HX_CSTRING("groundAnchorB"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("lengthA"),
	HX_CSTRING("maxLengthA"),
	HX_CSTRING("lengthB"),
	HX_CSTRING("maxLengthB"),
	HX_CSTRING("ratio"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PulleyJointDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PulleyJointDef_obj::__mClass,"__mClass");
};

#endif

Class B2PulleyJointDef_obj::__mClass;

void B2PulleyJointDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PulleyJointDef"), hx::TCanCast< B2PulleyJointDef_obj> ,sStaticFields,sMemberFields,
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

void B2PulleyJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
