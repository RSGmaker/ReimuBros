#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactConstraintPoint_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactConstraintPoint","new",0x9af9d487,"box2D.dynamics.contacts.B2ContactConstraintPoint.new","box2D/dynamics/contacts/B2ContactConstraintPoint.hx",31,0xd1309c48)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(33)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->localPoint = _g;
	HX_STACK_LINE(34)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->rA = _g1;
	HX_STACK_LINE(35)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(35)
	this->rB = _g2;
}
;
	return null();
}

//B2ContactConstraintPoint_obj::~B2ContactConstraintPoint_obj() { }

Dynamic B2ContactConstraintPoint_obj::__CreateEmpty() { return  new B2ContactConstraintPoint_obj; }
hx::ObjectPtr< B2ContactConstraintPoint_obj > B2ContactConstraintPoint_obj::__new()
{  hx::ObjectPtr< B2ContactConstraintPoint_obj > result = new B2ContactConstraintPoint_obj();
	result->__construct();
	return result;}

Dynamic B2ContactConstraintPoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactConstraintPoint_obj > result = new B2ContactConstraintPoint_obj();
	result->__construct();
	return result;}


B2ContactConstraintPoint_obj::B2ContactConstraintPoint_obj()
{
}

void B2ContactConstraintPoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactConstraintPoint);
	HX_MARK_MEMBER_NAME(localPoint,"localPoint");
	HX_MARK_MEMBER_NAME(rA,"rA");
	HX_MARK_MEMBER_NAME(rB,"rB");
	HX_MARK_MEMBER_NAME(normalImpulse,"normalImpulse");
	HX_MARK_MEMBER_NAME(tangentImpulse,"tangentImpulse");
	HX_MARK_MEMBER_NAME(normalMass,"normalMass");
	HX_MARK_MEMBER_NAME(tangentMass,"tangentMass");
	HX_MARK_MEMBER_NAME(equalizedMass,"equalizedMass");
	HX_MARK_MEMBER_NAME(velocityBias,"velocityBias");
	HX_MARK_END_CLASS();
}

void B2ContactConstraintPoint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localPoint,"localPoint");
	HX_VISIT_MEMBER_NAME(rA,"rA");
	HX_VISIT_MEMBER_NAME(rB,"rB");
	HX_VISIT_MEMBER_NAME(normalImpulse,"normalImpulse");
	HX_VISIT_MEMBER_NAME(tangentImpulse,"tangentImpulse");
	HX_VISIT_MEMBER_NAME(normalMass,"normalMass");
	HX_VISIT_MEMBER_NAME(tangentMass,"tangentMass");
	HX_VISIT_MEMBER_NAME(equalizedMass,"equalizedMass");
	HX_VISIT_MEMBER_NAME(velocityBias,"velocityBias");
}

Dynamic B2ContactConstraintPoint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"rA") ) { return rA; }
		if (HX_FIELD_EQ(inName,"rB") ) { return rB; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { return localPoint; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { return normalMass; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tangentMass") ) { return tangentMass; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"velocityBias") ) { return velocityBias; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"normalImpulse") ) { return normalImpulse; }
		if (HX_FIELD_EQ(inName,"equalizedMass") ) { return equalizedMass; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"tangentImpulse") ) { return tangentImpulse; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactConstraintPoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"rA") ) { rA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rB") ) { rB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { localPoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { normalMass=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"tangentMass") ) { tangentMass=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"velocityBias") ) { velocityBias=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"normalImpulse") ) { normalImpulse=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"equalizedMass") ) { equalizedMass=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"tangentImpulse") ) { tangentImpulse=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactConstraintPoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localPoint"));
	outFields->push(HX_CSTRING("rA"));
	outFields->push(HX_CSTRING("rB"));
	outFields->push(HX_CSTRING("normalImpulse"));
	outFields->push(HX_CSTRING("tangentImpulse"));
	outFields->push(HX_CSTRING("normalMass"));
	outFields->push(HX_CSTRING("tangentMass"));
	outFields->push(HX_CSTRING("equalizedMass"));
	outFields->push(HX_CSTRING("velocityBias"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactConstraintPoint_obj,localPoint),HX_CSTRING("localPoint")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactConstraintPoint_obj,rA),HX_CSTRING("rA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactConstraintPoint_obj,rB),HX_CSTRING("rB")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraintPoint_obj,normalImpulse),HX_CSTRING("normalImpulse")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraintPoint_obj,tangentImpulse),HX_CSTRING("tangentImpulse")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraintPoint_obj,normalMass),HX_CSTRING("normalMass")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraintPoint_obj,tangentMass),HX_CSTRING("tangentMass")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraintPoint_obj,equalizedMass),HX_CSTRING("equalizedMass")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraintPoint_obj,velocityBias),HX_CSTRING("velocityBias")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("localPoint"),
	HX_CSTRING("rA"),
	HX_CSTRING("rB"),
	HX_CSTRING("normalImpulse"),
	HX_CSTRING("tangentImpulse"),
	HX_CSTRING("normalMass"),
	HX_CSTRING("tangentMass"),
	HX_CSTRING("equalizedMass"),
	HX_CSTRING("velocityBias"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactConstraintPoint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactConstraintPoint_obj::__mClass,"__mClass");
};

#endif

Class B2ContactConstraintPoint_obj::__mClass;

void B2ContactConstraintPoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactConstraintPoint"), hx::TCanCast< B2ContactConstraintPoint_obj> ,sStaticFields,sMemberFields,
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

void B2ContactConstraintPoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
