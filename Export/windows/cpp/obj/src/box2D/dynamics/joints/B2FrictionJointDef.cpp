#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2FrictionJointDef
#include <box2D/dynamics/joints/B2FrictionJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2FrictionJointDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJointDef","new",0x47676eb3,"box2D.dynamics.joints.B2FrictionJointDef.new","box2D/dynamics/joints/B2FrictionJointDef.hx",34,0xc8b2fa5c)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(35)
	super::__construct();
	HX_STACK_LINE(36)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	this->localAnchorA = _g;
	HX_STACK_LINE(37)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(37)
	this->localAnchorB = _g1;
	HX_STACK_LINE(39)
	this->type = (int)9;
	HX_STACK_LINE(40)
	this->maxForce = 0.0;
	HX_STACK_LINE(41)
	this->maxTorque = 0.0;
}
;
	return null();
}

//B2FrictionJointDef_obj::~B2FrictionJointDef_obj() { }

Dynamic B2FrictionJointDef_obj::__CreateEmpty() { return  new B2FrictionJointDef_obj; }
hx::ObjectPtr< B2FrictionJointDef_obj > B2FrictionJointDef_obj::__new()
{  hx::ObjectPtr< B2FrictionJointDef_obj > result = new B2FrictionJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2FrictionJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2FrictionJointDef_obj > result = new B2FrictionJointDef_obj();
	result->__construct();
	return result;}

Void B2FrictionJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2FrictionJointDef","initialize",0xabd2535d,"box2D.dynamics.joints.B2FrictionJointDef.initialize","box2D/dynamics/joints/B2FrictionJointDef.hx",50,0xc8b2fa5c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bA,"bA")
		HX_STACK_ARG(bB,"bB")
		HX_STACK_ARG(anchor,"anchor")
		HX_STACK_LINE(51)
		this->bodyA = bA;
		HX_STACK_LINE(52)
		this->bodyB = bB;
		HX_STACK_LINE(53)
		::box2D::common::math::B2Vec2 _g = this->bodyA->getLocalPoint(anchor);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(53)
		this->localAnchorA->setV(_g);
		HX_STACK_LINE(54)
		::box2D::common::math::B2Vec2 _g1 = this->bodyB->getLocalPoint(anchor);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(54)
		this->localAnchorB->setV(_g1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2FrictionJointDef_obj,initialize,(void))


B2FrictionJointDef_obj::B2FrictionJointDef_obj()
{
}

void B2FrictionJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2FrictionJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(maxForce,"maxForce");
	HX_MARK_MEMBER_NAME(maxTorque,"maxTorque");
	::box2D::dynamics::joints::B2JointDef_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2FrictionJointDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_VISIT_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_VISIT_MEMBER_NAME(maxForce,"maxForce");
	HX_VISIT_MEMBER_NAME(maxTorque,"maxTorque");
	::box2D::dynamics::joints::B2JointDef_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2FrictionJointDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"maxForce") ) { return maxForce; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxTorque") ) { return maxTorque; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2FrictionJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"maxForce") ) { maxForce=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"maxTorque") ) { maxTorque=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2FrictionJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("maxForce"));
	outFields->push(HX_CSTRING("maxTorque"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2FrictionJointDef_obj,localAnchorA),HX_CSTRING("localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2FrictionJointDef_obj,localAnchorB),HX_CSTRING("localAnchorB")},
	{hx::fsFloat,(int)offsetof(B2FrictionJointDef_obj,maxForce),HX_CSTRING("maxForce")},
	{hx::fsFloat,(int)offsetof(B2FrictionJointDef_obj,maxTorque),HX_CSTRING("maxTorque")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("maxForce"),
	HX_CSTRING("maxTorque"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2FrictionJointDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2FrictionJointDef_obj::__mClass,"__mClass");
};

#endif

Class B2FrictionJointDef_obj::__mClass;

void B2FrictionJointDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2FrictionJointDef"), hx::TCanCast< B2FrictionJointDef_obj> ,sStaticFields,sMemberFields,
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

void B2FrictionJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
