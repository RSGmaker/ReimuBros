#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2BodyDef
#include <box2D/dynamics/B2BodyDef.h>
#endif
namespace box2D{
namespace dynamics{

Void B2BodyDef_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2BodyDef","new",0xe45a8cbc,"box2D.dynamics.B2BodyDef.new","box2D/dynamics/B2BodyDef.hx",35,0x128b2614)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(36)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	this->position = _g;
	HX_STACK_LINE(37)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(37)
	this->linearVelocity = _g1;
	HX_STACK_LINE(39)
	this->userData = null();
	HX_STACK_LINE(41)
	this->angle = 0.0;
	HX_STACK_LINE(43)
	this->angularVelocity = 0.0;
	HX_STACK_LINE(44)
	this->linearDamping = 0.0;
	HX_STACK_LINE(45)
	this->angularDamping = 0.0;
	HX_STACK_LINE(46)
	this->allowSleep = true;
	HX_STACK_LINE(47)
	this->awake = true;
	HX_STACK_LINE(48)
	this->fixedRotation = false;
	HX_STACK_LINE(49)
	this->bullet = false;
	HX_STACK_LINE(50)
	this->type = (int)0;
	HX_STACK_LINE(51)
	this->active = true;
	HX_STACK_LINE(52)
	this->inertiaScale = 1.0;
}
;
	return null();
}

//B2BodyDef_obj::~B2BodyDef_obj() { }

Dynamic B2BodyDef_obj::__CreateEmpty() { return  new B2BodyDef_obj; }
hx::ObjectPtr< B2BodyDef_obj > B2BodyDef_obj::__new()
{  hx::ObjectPtr< B2BodyDef_obj > result = new B2BodyDef_obj();
	result->__construct();
	return result;}

Dynamic B2BodyDef_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2BodyDef_obj > result = new B2BodyDef_obj();
	result->__construct();
	return result;}


B2BodyDef_obj::B2BodyDef_obj()
{
}

void B2BodyDef_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2BodyDef);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(linearVelocity,"linearVelocity");
	HX_MARK_MEMBER_NAME(angularVelocity,"angularVelocity");
	HX_MARK_MEMBER_NAME(linearDamping,"linearDamping");
	HX_MARK_MEMBER_NAME(angularDamping,"angularDamping");
	HX_MARK_MEMBER_NAME(allowSleep,"allowSleep");
	HX_MARK_MEMBER_NAME(awake,"awake");
	HX_MARK_MEMBER_NAME(fixedRotation,"fixedRotation");
	HX_MARK_MEMBER_NAME(bullet,"bullet");
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(inertiaScale,"inertiaScale");
	HX_MARK_END_CLASS();
}

void B2BodyDef_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(linearVelocity,"linearVelocity");
	HX_VISIT_MEMBER_NAME(angularVelocity,"angularVelocity");
	HX_VISIT_MEMBER_NAME(linearDamping,"linearDamping");
	HX_VISIT_MEMBER_NAME(angularDamping,"angularDamping");
	HX_VISIT_MEMBER_NAME(allowSleep,"allowSleep");
	HX_VISIT_MEMBER_NAME(awake,"awake");
	HX_VISIT_MEMBER_NAME(fixedRotation,"fixedRotation");
	HX_VISIT_MEMBER_NAME(bullet,"bullet");
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(userData,"userData");
	HX_VISIT_MEMBER_NAME(inertiaScale,"inertiaScale");
}

Dynamic B2BodyDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"awake") ) { return awake; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bullet") ) { return bullet; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"allowSleep") ) { return allowSleep; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"inertiaScale") ) { return inertiaScale; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"linearDamping") ) { return linearDamping; }
		if (HX_FIELD_EQ(inName,"fixedRotation") ) { return fixedRotation; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"linearVelocity") ) { return linearVelocity; }
		if (HX_FIELD_EQ(inName,"angularDamping") ) { return angularDamping; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { return angularVelocity; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2BodyDef_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"awake") ) { awake=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bullet") ) { bullet=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"allowSleep") ) { allowSleep=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"inertiaScale") ) { inertiaScale=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"linearDamping") ) { linearDamping=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fixedRotation") ) { fixedRotation=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"linearVelocity") ) { linearVelocity=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angularDamping") ) { angularDamping=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { angularVelocity=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2BodyDef_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("linearVelocity"));
	outFields->push(HX_CSTRING("angularVelocity"));
	outFields->push(HX_CSTRING("linearDamping"));
	outFields->push(HX_CSTRING("angularDamping"));
	outFields->push(HX_CSTRING("allowSleep"));
	outFields->push(HX_CSTRING("awake"));
	outFields->push(HX_CSTRING("fixedRotation"));
	outFields->push(HX_CSTRING("bullet"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("inertiaScale"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2BodyDef_obj,type),HX_CSTRING("type")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2BodyDef_obj,position),HX_CSTRING("position")},
	{hx::fsFloat,(int)offsetof(B2BodyDef_obj,angle),HX_CSTRING("angle")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2BodyDef_obj,linearVelocity),HX_CSTRING("linearVelocity")},
	{hx::fsFloat,(int)offsetof(B2BodyDef_obj,angularVelocity),HX_CSTRING("angularVelocity")},
	{hx::fsFloat,(int)offsetof(B2BodyDef_obj,linearDamping),HX_CSTRING("linearDamping")},
	{hx::fsFloat,(int)offsetof(B2BodyDef_obj,angularDamping),HX_CSTRING("angularDamping")},
	{hx::fsBool,(int)offsetof(B2BodyDef_obj,allowSleep),HX_CSTRING("allowSleep")},
	{hx::fsBool,(int)offsetof(B2BodyDef_obj,awake),HX_CSTRING("awake")},
	{hx::fsBool,(int)offsetof(B2BodyDef_obj,fixedRotation),HX_CSTRING("fixedRotation")},
	{hx::fsBool,(int)offsetof(B2BodyDef_obj,bullet),HX_CSTRING("bullet")},
	{hx::fsBool,(int)offsetof(B2BodyDef_obj,active),HX_CSTRING("active")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2BodyDef_obj,userData),HX_CSTRING("userData")},
	{hx::fsFloat,(int)offsetof(B2BodyDef_obj,inertiaScale),HX_CSTRING("inertiaScale")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("position"),
	HX_CSTRING("angle"),
	HX_CSTRING("linearVelocity"),
	HX_CSTRING("angularVelocity"),
	HX_CSTRING("linearDamping"),
	HX_CSTRING("angularDamping"),
	HX_CSTRING("allowSleep"),
	HX_CSTRING("awake"),
	HX_CSTRING("fixedRotation"),
	HX_CSTRING("bullet"),
	HX_CSTRING("active"),
	HX_CSTRING("userData"),
	HX_CSTRING("inertiaScale"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2BodyDef_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2BodyDef_obj::__mClass,"__mClass");
};

#endif

Class B2BodyDef_obj::__mClass;

void B2BodyDef_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2BodyDef"), hx::TCanCast< B2BodyDef_obj> ,sStaticFields,sMemberFields,
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

void B2BodyDef_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
