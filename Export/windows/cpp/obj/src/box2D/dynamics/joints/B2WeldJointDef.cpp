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
#ifndef INCLUDED_box2D_dynamics_joints_B2WeldJointDef
#include <box2D/dynamics/joints/B2WeldJointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2WeldJointDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJointDef","new",0xc60807bf,"box2D.dynamics.joints.B2WeldJointDef.new","box2D/dynamics/joints/B2WeldJointDef.hx",35,0x7b917b50)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(36)
	super::__construct();
	HX_STACK_LINE(37)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(37)
	this->localAnchorA = _g;
	HX_STACK_LINE(38)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(38)
	this->localAnchorB = _g1;
	HX_STACK_LINE(40)
	this->type = (int)8;
	HX_STACK_LINE(41)
	this->referenceAngle = 0.0;
}
;
	return null();
}

//B2WeldJointDef_obj::~B2WeldJointDef_obj() { }

Dynamic B2WeldJointDef_obj::__CreateEmpty() { return  new B2WeldJointDef_obj; }
hx::ObjectPtr< B2WeldJointDef_obj > B2WeldJointDef_obj::__new()
{  hx::ObjectPtr< B2WeldJointDef_obj > result = new B2WeldJointDef_obj();
	result->__construct();
	return result;}

Dynamic B2WeldJointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2WeldJointDef_obj > result = new B2WeldJointDef_obj();
	result->__construct();
	return result;}

Void B2WeldJointDef_obj::initialize( ::box2D::dynamics::B2Body bA,::box2D::dynamics::B2Body bB,::box2D::common::math::B2Vec2 anchor){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2WeldJointDef","initialize",0x15c433d1,"box2D.dynamics.joints.B2WeldJointDef.initialize","box2D/dynamics/joints/B2WeldJointDef.hx",50,0x7b917b50)
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
		HX_STACK_LINE(55)
		Float _g2 = this->bodyB->getAngle();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(55)
		Float _g3 = this->bodyA->getAngle();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(55)
		Float _g4 = (_g2 - _g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(55)
		this->referenceAngle = _g4;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2WeldJointDef_obj,initialize,(void))


B2WeldJointDef_obj::B2WeldJointDef_obj()
{
}

void B2WeldJointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2WeldJointDef);
	HX_MARK_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_MARK_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_MARK_MEMBER_NAME(referenceAngle,"referenceAngle");
	::box2D::dynamics::joints::B2JointDef_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void B2WeldJointDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localAnchorA,"localAnchorA");
	HX_VISIT_MEMBER_NAME(localAnchorB,"localAnchorB");
	HX_VISIT_MEMBER_NAME(referenceAngle,"referenceAngle");
	::box2D::dynamics::joints::B2JointDef_obj::__Visit(HX_VISIT_ARG);
}

Dynamic B2WeldJointDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { return localAnchorA; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { return localAnchorB; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { return referenceAngle; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2WeldJointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"localAnchorA") ) { localAnchorA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"localAnchorB") ) { localAnchorB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"referenceAngle") ) { referenceAngle=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2WeldJointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localAnchorA"));
	outFields->push(HX_CSTRING("localAnchorB"));
	outFields->push(HX_CSTRING("referenceAngle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2WeldJointDef_obj,localAnchorA),HX_CSTRING("localAnchorA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2WeldJointDef_obj,localAnchorB),HX_CSTRING("localAnchorB")},
	{hx::fsFloat,(int)offsetof(B2WeldJointDef_obj,referenceAngle),HX_CSTRING("referenceAngle")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("localAnchorA"),
	HX_CSTRING("localAnchorB"),
	HX_CSTRING("referenceAngle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2WeldJointDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2WeldJointDef_obj::__mClass,"__mClass");
};

#endif

Class B2WeldJointDef_obj::__mClass;

void B2WeldJointDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2WeldJointDef"), hx::TCanCast< B2WeldJointDef_obj> ,sStaticFields,sMemberFields,
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

void B2WeldJointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
