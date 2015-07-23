#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2DistanceJointDef
#include <box2D/dynamics/joints/B2DistanceJointDef.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2DistanceJointDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2DistanceJointDef","new",0x43b3756e,"box2D.dynamics.joints.B2DistanceJointDef.new","box2D/dynamics/joints/B2DistanceJointDef.hx",38,0x9ac36401)
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
	HX_STACK_LINE(43)
	this->type = (int)3;
	HX_STACK_LINE(46)
	this->length = 1.0;
	HX_STACK_LINE(47)
	this->frequencyHz = 0.0;
	HX_STACK_LINE(48)
	this->dampingRatio = 0.0;
}
;
	return null();
}

//B2DistanceJointDef_obj::~B2DistanceJointDef_obj() { }

Dynamic B2DistanceJointDef_obj::__CreateEmpty() { return  new B2DistanceJointDef_obj; }
hx::ObjectPtr< B2DistanceJointDef_obj > B2DistanceJointDef_obj::__new()
{  hx::ObjectPtr< B2DistanceJointDef_obj > result = new B2DistanceJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2DistanceJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DistanceJointDef_obj > result = new B2DistanceJointDef_obj();
	result->__construct();
	return result;}

Void B2DistanceJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchorA,::box2D::common::math::B2Vec2 anchorB){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2DistanceJointDef","initialize",0x078c6a02,"box2D.dynamics.joints.B2DistanceJointDef.initialize","box2D/dynamics/joints/B2DistanceJointDef.hx",57,0x9ac36401)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bA,"bA")
		HX_STACK_ARG(bB,"bB")
		HX_STACK_ARG(anchorA,"anchorA")
		HX_STACK_ARG(anchorB,"anchorB")
		HX_STACK_LINE(58)
		this->bodyA = bA;
		HX_STACK_LINE(59)
		this->bodyB = bB;
		HX_STACK_LINE(60)
		::box2D::common::math::B2Vec2 _g = this->bodyA->getLocalPoint(anchorA);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(60)
		this->localAnchorA->setV(_g);
		HX_STACK_LINE(61)
		::box2D::common::math::B2Vec2 _g1 = this->bodyB->getLocalPoint(anchorB);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(61)
		this->localAnchorB->setV(_g1);
		HX_STACK_LINE(62)
		Float dX = (anchorB->x - anchorA->x);		HX_STACK_VAR(dX,"dX");
		HX_STACK_LINE(63)
		Float dY = (anchorB->y - anchorA->y);		HX_STACK_VAR(dY,"dY");
		HX_STACK_LINE(64)
		Float _g2 = ::Math_obj::sqrt(((dX * dX) + (dY * dY)));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(64)
		this->length = _g2;
		HX_STACK_LINE(65)
		this->frequencyHz = 0.0;
		HX_STACK_LINE(66)
		this->dampingRatio = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2DistanceJointDef_obj,initialize,(void))


B2DistanceJointDef_obj::B2DistanceJointDef_obj()
{
}

void B2DistanceJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DistanceJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(frequencyHz,"frequencyHz");
	HX_MARK_MEMBER_NAME(dampingRatio,"dampingRatio");
	::box2D::dynamics::joints::B2JointDef_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2DistanceJointDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_VISIT_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(frequencyHz,"frequencyHz");
	HX_VISIT_MEMBER_NAME(dampingRatio,"dampingRatio");
	::box2D::dynamics::joints::B2JointDef_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2DistanceJointDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frequencyHz") ) { return frequencyHz; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		if (HX_FIELD_EQ(inName,"dampingRatio") ) { return dampingRatio; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2DistanceJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"frequencyHz") ) { frequencyHz=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dampingRatio") ) { dampingRatio=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2DistanceJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("frequencyHz"));
	outFields->push(HX_CSTRING("dampingRatio"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2DistanceJointDef_obj,localAnchorA),HX_CSTRING("localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2DistanceJointDef_obj,localAnchorB),HX_CSTRING("localAnchorB")},
	{hx::fsFloat,(int)offsetof(B2DistanceJointDef_obj,length),HX_CSTRING("length")},
	{hx::fsFloat,(int)offsetof(B2DistanceJointDef_obj,frequencyHz),HX_CSTRING("frequencyHz")},
	{hx::fsFloat,(int)offsetof(B2DistanceJointDef_obj,dampingRatio),HX_CSTRING("dampingRatio")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("length"),
	HX_CSTRING("frequencyHz"),
	HX_CSTRING("dampingRatio"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DistanceJointDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2DistanceJointDef_obj::__mClass,"__mClass");
};

#endif

Class B2DistanceJointDef_obj::__mClass;

void B2DistanceJointDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2DistanceJointDef"), hx::TCanCast< B2DistanceJointDef_obj> ,sStaticFields,sMemberFields,
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

void B2DistanceJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
