#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2JointDef
#include <box2D/dynamics/joints/B2JointDef.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2JointDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2JointDef","new",0x00ceae99,"box2D.dynamics.joints.B2JointDef.new","box2D/dynamics/joints/B2JointDef.hx",33,0x01b6e236)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(34)
	this->type = (int)0;
	HX_STACK_LINE(35)
	this->userData = null();
	HX_STACK_LINE(36)
	this->bodyA = null();
	HX_STACK_LINE(37)
	this->bodyB = null();
	HX_STACK_LINE(38)
	this->collideConnected = false;
}
;
	return null();
}

//B2JointDef_obj::~B2JointDef_obj() { }

Dynamic B2JointDef_obj::__CreateEmpty() { return  new B2JointDef_obj; }
hx::ObjectPtr< B2JointDef_obj > B2JointDef_obj::__new()
{  hx::ObjectPtr< B2JointDef_obj > result = new B2JointDef_obj();
	result->__construct();
	return result;}

Dynamic B2JointDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2JointDef_obj > result = new B2JointDef_obj();
	result->__construct();
	return result;}


B2JointDef_obj::B2JointDef_obj()
{
}

void B2JointDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2JointDef);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(bodyA,"bodyA");
	HX_MARK_MEMBER_NAME(bodyB,"bodyB");
	HX_MARK_MEMBER_NAME(collideConnected,"collideConnected");
	HX_MARK_END_CLASS();
}

void B2JointDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(userData,"userData");
	HX_VISIT_MEMBER_NAME(bodyA,"bodyA");
	HX_VISIT_MEMBER_NAME(bodyB,"bodyB");
	HX_VISIT_MEMBER_NAME(collideConnected,"collideConnected");
}

Dynamic B2JointDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bodyA") ) { return bodyA; }
		if (HX_FIELD_EQ(inName,"bodyB") ) { return bodyB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"collideConnected") ) { return collideConnected; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2JointDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bodyA") ) { bodyA=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bodyB") ) { bodyB=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"collideConnected") ) { collideConnected=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2JointDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("bodyA"));
	outFields->push(HX_CSTRING("bodyB"));
	outFields->push(HX_CSTRING("collideConnected"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2JointDef_obj,type),HX_CSTRING("type")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2JointDef_obj,userData),HX_CSTRING("userData")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2JointDef_obj,bodyA),HX_CSTRING("bodyA")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2JointDef_obj,bodyB),HX_CSTRING("bodyB")},
	{hx::fsBool,(int)offsetof(B2JointDef_obj,collideConnected),HX_CSTRING("collideConnected")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("userData"),
	HX_CSTRING("bodyA"),
	HX_CSTRING("bodyB"),
	HX_CSTRING("collideConnected"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2JointDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2JointDef_obj::__mClass,"__mClass");
};

#endif

Class B2JointDef_obj::__mClass;

void B2JointDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2JointDef"), hx::TCanCast< B2JointDef_obj> ,sStaticFields,sMemberFields,
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

void B2JointDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
