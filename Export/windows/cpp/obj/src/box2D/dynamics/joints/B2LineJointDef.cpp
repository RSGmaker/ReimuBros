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
#ifndef INCLUDED_box2D_dynamics_joints_B2LineJointDef
#include <box2D/dynamics/joints/B2LineJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2LineJointDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2LineJointDef","new",0x55ffe6ad,"box2D.dynamics.joints.B2LineJointDef.new","box2D/dynamics/joints/B2LineJointDef.hx",35,0xecb75422)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(35)
	super::__construct();
}
;
	return null();
}

//B2LineJointDef_obj::~B2LineJointDef_obj() { }

Dynamic B2LineJointDef_obj::__CreateEmpty() { return  new B2LineJointDef_obj; }
hx::ObjectPtr< B2LineJointDef_obj > B2LineJointDef_obj::__new()
{  hx::ObjectPtr< B2LineJointDef_obj > result = new B2LineJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2LineJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2LineJointDef_obj > result = new B2LineJointDef_obj();
	result->__construct();
	return result;}

Void B2LineJointDef_obj::b2LineJointDef( ){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJointDef","b2LineJointDef",0x39e36732,"box2D.dynamics.joints.B2LineJointDef.b2LineJointDef","box2D/dynamics/joints/B2LineJointDef.hx",38,0xecb75422)
		HX_STACK_THIS(this)
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
		this->type = (int)7;
		HX_STACK_LINE(47)
		this->localAxisA->set(1.0,0.0);
		HX_STACK_LINE(48)
		this->enableLimit = false;
		HX_STACK_LINE(49)
		this->lowerTranslation = 0.0;
		HX_STACK_LINE(50)
		this->upperTranslation = 0.0;
		HX_STACK_LINE(51)
		this->enableMotor = false;
		HX_STACK_LINE(52)
		this->maxMotorForce = 0.0;
		HX_STACK_LINE(53)
		this->motorSpeed = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2LineJointDef_obj,b2LineJointDef,(void))

Void B2LineJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor,::box2D::common::math::B2Vec2 axis){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2LineJointDef","initialize",0x6e8a2ea3,"box2D.dynamics.joints.B2LineJointDef.initialize","box2D/dynamics/joints/B2LineJointDef.hx",57,0xecb75422)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bA,"bA")
		HX_STACK_ARG(bB,"bB")
		HX_STACK_ARG(anchor,"anchor")
		HX_STACK_ARG(axis,"axis")
		HX_STACK_LINE(58)
		this->bodyA = bA;
		HX_STACK_LINE(59)
		this->bodyB = bB;
		HX_STACK_LINE(60)
		::box2D::common::math::B2Vec2 _g = this->bodyA->getLocalPoint(anchor);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(60)
		this->localAnchorA = _g;
		HX_STACK_LINE(61)
		::box2D::common::math::B2Vec2 _g1 = this->bodyB->getLocalPoint(anchor);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(61)
		this->localAnchorB = _g1;
		HX_STACK_LINE(62)
		::box2D::common::math::B2Vec2 _g2 = this->bodyA->getLocalVector(axis);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(62)
		this->localAxisA = _g2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2LineJointDef_obj,initialize,(void))


B2LineJointDef_obj::B2LineJointDef_obj()
{
}

void B2LineJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2LineJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(localAxisA,"localAxisA");
	HX_MARK_MEMBER_NAME(enableLimit,"enableLimit");
	HX_MARK_MEMBER_NAME(lowerTranslation,"lowerTranslation");
	HX_MARK_MEMBER_NAME(upperTranslation,"upperTranslation");
	HX_MARK_MEMBER_NAME(enableMotor,"enableMotor");
	HX_MARK_MEMBER_NAME(maxMotorForce,"maxMotorForce");
	HX_MARK_MEMBER_NAME(motorSpeed,"motorSpeed");
	::box2D::dynamics::joints::B2JointDef_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2LineJointDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_VISIT_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_VISIT_MEMBER_NAME(localAxisA,"localAxisA");
	HX_VISIT_MEMBER_NAME(enableLimit,"enableLimit");
	HX_VISIT_MEMBER_NAME(lowerTranslation,"lowerTranslation");
	HX_VISIT_MEMBER_NAME(upperTranslation,"upperTranslation");
	HX_VISIT_MEMBER_NAME(enableMotor,"enableMotor");
	HX_VISIT_MEMBER_NAME(maxMotorForce,"maxMotorForce");
	HX_VISIT_MEMBER_NAME(motorSpeed,"motorSpeed");
	::box2D::dynamics::joints::B2JointDef_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2LineJointDef_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"b2LineJointDef") ) { return b2LineJointDef_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { return lowerTranslation; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { return upperTranslation; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2LineJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	case 16:
		if (HX_FIELD_EQ(inName,"lowerTranslation") ) { lowerTranslation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upperTranslation") ) { upperTranslation=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2LineJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("localAxisA"));
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
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJointDef_obj,localAnchorA),HX_CSTRING("localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJointDef_obj,localAnchorB),HX_CSTRING("localAnchorB")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2LineJointDef_obj,localAxisA),HX_CSTRING("localAxisA")},
	{hx::fsBool,(int)offsetof(B2LineJointDef_obj,enableLimit),HX_CSTRING("enableLimit")},
	{hx::fsFloat,(int)offsetof(B2LineJointDef_obj,lowerTranslation),HX_CSTRING("lowerTranslation")},
	{hx::fsFloat,(int)offsetof(B2LineJointDef_obj,upperTranslation),HX_CSTRING("upperTranslation")},
	{hx::fsBool,(int)offsetof(B2LineJointDef_obj,enableMotor),HX_CSTRING("enableMotor")},
	{hx::fsFloat,(int)offsetof(B2LineJointDef_obj,maxMotorForce),HX_CSTRING("maxMotorForce")},
	{hx::fsFloat,(int)offsetof(B2LineJointDef_obj,motorSpeed),HX_CSTRING("motorSpeed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("b2LineJointDef"),
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("localAxisA"),
	HX_CSTRING("enableLimit"),
	HX_CSTRING("lowerTranslation"),
	HX_CSTRING("upperTranslation"),
	HX_CSTRING("enableMotor"),
	HX_CSTRING("maxMotorForce"),
	HX_CSTRING("motorSpeed"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2LineJointDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2LineJointDef_obj::__mClass,"__mClass");
};

#endif

Class B2LineJointDef_obj::__mClass;

void B2LineJointDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2LineJointDef"), hx::TCanCast< B2LineJointDef_obj> ,sStaticFields,sMemberFields,
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

void B2LineJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
