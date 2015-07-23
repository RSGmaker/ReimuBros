#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2PrismaticJointDef
#include <box2D/dynamics/joints/B2PrismaticJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2PrismaticJointDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJointDef","new",0x43a047af,"box2D.dynamics.joints.B2PrismaticJointDef.new","box2D/dynamics/joints/B2PrismaticJointDef.hx",38,0x5c9ba782)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(39)
	super::__construct();
	HX_STACK_LINE(40)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	this->localAnchorA = _g;
	HX_STACK_LINE(41)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(41)
	this->localAnchorB = _g1;
	HX_STACK_LINE(42)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(42)
	this->localAxisA = _g2;
	HX_STACK_LINE(44)
	this->type = (int)2;
	HX_STACK_LINE(47)
	this->localAxisA->set(1.0,0.0);
	HX_STACK_LINE(48)
	this->referenceAngle = 0.0;
	HX_STACK_LINE(49)
	this->enableLimit = false;
	HX_STACK_LINE(50)
	this->lowerTranslation = 0.0;
	HX_STACK_LINE(51)
	this->upperTranslation = 0.0;
	HX_STACK_LINE(52)
	this->enableMotor = false;
	HX_STACK_LINE(53)
	this->maxMotorForce = 0.0;
	HX_STACK_LINE(54)
	this->motorSpeed = 0.0;
}
;
	return null();
}

//B2PrismaticJointDef_obj::~B2PrismaticJointDef_obj() { }

Dynamic B2PrismaticJointDef_obj::__CreateEmpty() { return  new B2PrismaticJointDef_obj; }
hx::ObjectPtr< B2PrismaticJointDef_obj > B2PrismaticJointDef_obj::__new()
{  hx::ObjectPtr< B2PrismaticJointDef_obj > result = new B2PrismaticJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2PrismaticJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PrismaticJointDef_obj > result = new B2PrismaticJointDef_obj();
	result->__construct();
	return result;}

Void B2PrismaticJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor,::box2D::common::math::B2Vec2 axis){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2PrismaticJointDef","initialize",0x048cd1e1,"box2D.dynamics.joints.B2PrismaticJointDef.initialize","box2D/dynamics/joints/B2PrismaticJointDef.hx",58,0x5c9ba782)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bA,"bA")
		HX_STACK_ARG(bB,"bB")
		HX_STACK_ARG(anchor,"anchor")
		HX_STACK_ARG(axis,"axis")
		HX_STACK_LINE(59)
		this->bodyA = bA;
		HX_STACK_LINE(60)
		this->bodyB = bB;
		HX_STACK_LINE(61)
		::box2D::common::math::B2Vec2 _g = this->bodyA->getLocalPoint(anchor);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		this->localAnchorA = _g;
		HX_STACK_LINE(62)
		::box2D::common::math::B2Vec2 _g1 = this->bodyB->getLocalPoint(anchor);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		this->localAnchorB = _g1;
		HX_STACK_LINE(63)
		::box2D::common::math::B2Vec2 _g2 = this->bodyA->getLocalVector(axis);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(63)
		this->localAxisA = _g2;
		HX_STACK_LINE(64)
		Float _g3 = this->bodyB->getAngle();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(64)
		Float _g4 = this->bodyA->getAngle();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(64)
		Float _g5 = (_g3 - _g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(64)
		this->referenceAngle = _g5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2PrismaticJointDef_obj,initialize,(void))


B2PrismaticJointDef_obj::B2PrismaticJointDef_obj()
{
}

void B2PrismaticJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PrismaticJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(localAxisA,"localAxisA");
	HX_MARK_MEMBER_NAME(referenceAngle,"referenceAngle");
	HX_MARK_MEMBER_NAME(enableLimit,"enableLimit");
	HX_MARK_MEMBER_NAME(lowerTranslation,"lowerTranslation");
	HX_MARK_MEMBER_NAME(upperTranslation,"upperTranslation");
	HX_MARK_MEMBER_NAME(enableMotor,"enableMotor");
	HX_MARK_MEMBER_NAME(maxMotorForce,"maxMotorForce");
	HX_MARK_MEMBER_NAME(motorSpeed,"motorSpeed");
	::box2D::dynamics::joints::B2JointDef_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2PrismaticJointDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_VISIT_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_VISIT_MEMBER_NAME(localAxisA,"localAxisA");
	HX_VISIT_MEMBER_NAME(referenceAngle,"referenceAngle");
	HX_VISIT_MEMBER_NAME(enableLimit,"enableLimit");
	HX_VISIT_MEMBER_NAME(lowerTranslation,"lowerTranslation");
	HX_VISIT_MEMBER_NAME(upperTranslation,"upperTranslation");
	HX_VISIT_MEMBER_NAME(enableMotor,"enableMotor");
	HX_VISIT_MEMBER_NAME(maxMotorForce,"maxMotorForce");
	HX_VISIT_MEMBER_NAME(motorSpeed,"motorSpeed");
	::box2D::dynamics::joints::B2JointDef_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2PrismaticJointDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"localAxisA") ) { return localAxisA; }
		if (HX_FIELD_EQ(inName,"motorSpeed") ) { return motorSpeed; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enableLimit") ) { return enableLimit; }
		if (HX_FIELD_EQ(inName,"enableMotor") ) { return enableMotor; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"maxMotorForce") ) { return maxMotorForce; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { return referenceAngle; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { return lowerTranslation; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { return upperTranslation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2PrismaticJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"localAxisA") ) { localAxisA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"motorSpeed") ) { motorSpeed=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enableLimit") ) { enableLimit=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enableMotor") ) { enableMotor=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"maxMotorForce") ) { maxMotorForce=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { referenceAngle=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { lowerTranslation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { upperTranslation=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2PrismaticJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("localAxisA"));
	outFields->push(HX_CSTRING("referenceAngle"));
	outFields->push(HX_CSTRING("enableLimit"));
	outFields->push(HX_CSTRING("lowerTranslation"));
	outFields->push(HX_CSTRING("upperTranslation"));
	outFields->push(HX_CSTRING("enableMotor"));
	outFields->push(HX_CSTRING("maxMotorForce"));
	outFields->push(HX_CSTRING("motorSpeed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJointDef_obj,localAnchorA),HX_CSTRING("localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJointDef_obj,localAnchorB),HX_CSTRING("localAnchorB")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PrismaticJointDef_obj,localAxisA),HX_CSTRING("localAxisA")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJointDef_obj,referenceAngle),HX_CSTRING("referenceAngle")},
	{hx::fsBool,(int)offsetof(B2PrismaticJointDef_obj,enableLimit),HX_CSTRING("enableLimit")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJointDef_obj,lowerTranslation),HX_CSTRING("lowerTranslation")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJointDef_obj,upperTranslation),HX_CSTRING("upperTranslation")},
	{hx::fsBool,(int)offsetof(B2PrismaticJointDef_obj,enableMotor),HX_CSTRING("enableMotor")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJointDef_obj,maxMotorForce),HX_CSTRING("maxMotorForce")},
	{hx::fsFloat,(int)offsetof(B2PrismaticJointDef_obj,motorSpeed),HX_CSTRING("motorSpeed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("localAxisA"),
	HX_CSTRING("referenceAngle"),
	HX_CSTRING("enableLimit"),
	HX_CSTRING("lowerTranslation"),
	HX_CSTRING("upperTranslation"),
	HX_CSTRING("enableMotor"),
	HX_CSTRING("maxMotorForce"),
	HX_CSTRING("motorSpeed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PrismaticJointDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PrismaticJointDef_obj::__mClass,"__mClass");
};

#endif

Class B2PrismaticJointDef_obj::__mClass;

void B2PrismaticJointDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2PrismaticJointDef"), hx::TCanCast< B2PrismaticJointDef_obj> ,sStaticFields,sMemberFields,
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

void B2PrismaticJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
