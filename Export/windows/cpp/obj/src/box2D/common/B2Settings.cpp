#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace common{

Void B2Settings_obj::__construct()
{
	return null();
}

//B2Settings_obj::~B2Settings_obj() { }

Dynamic B2Settings_obj::__CreateEmpty() { return  new B2Settings_obj; }
hx::ObjectPtr< B2Settings_obj > B2Settings_obj::__new()
{  hx::ObjectPtr< B2Settings_obj > result = new B2Settings_obj();
	result->__construct();
	return result;}

Dynamic B2Settings_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Settings_obj > result = new B2Settings_obj();
	result->__construct();
	return result;}

::String B2Settings_obj::VERSION;

Float B2Settings_obj::b2_pi;

int B2Settings_obj::b2_maxManifoldPoints;

Float B2Settings_obj::b2_aabbExtension;

Float B2Settings_obj::b2_aabbMultiplier;

Float B2Settings_obj::b2_polygonRadius;

Float B2Settings_obj::b2_linearSlop;

Float B2Settings_obj::b2_angularSlop;

Float B2Settings_obj::b2_toiSlop;

int B2Settings_obj::b2_maxTOIContactsPerIsland;

int B2Settings_obj::b2_maxTOIJointsPerIsland;

Float B2Settings_obj::b2_velocityThreshold;

Float B2Settings_obj::b2_maxLinearCorrection;

Float B2Settings_obj::b2_maxAngularCorrection;

Float B2Settings_obj::b2_maxTranslation;

Float B2Settings_obj::b2_maxTranslationSquared;

Float B2Settings_obj::b2_maxRotation;

Float B2Settings_obj::b2_maxRotationSquared;

Float B2Settings_obj::b2_contactBaumgarte;

Float B2Settings_obj::b2MixFriction( Float friction1,Float friction2){
	HX_STACK_FRAME("box2D.common.B2Settings","b2MixFriction",0x9b573fdd,"box2D.common.B2Settings.b2MixFriction","box2D/common/B2Settings.hx",150,0xc79dd6b9)
	HX_STACK_ARG(friction1,"friction1")
	HX_STACK_ARG(friction2,"friction2")
	HX_STACK_LINE(150)
	return ::Math_obj::sqrt((friction1 * friction2));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Settings_obj,b2MixFriction,return )

Float B2Settings_obj::b2MixRestitution( Float restitution1,Float restitution2){
	HX_STACK_FRAME("box2D.common.B2Settings","b2MixRestitution",0x712a9567,"box2D.common.B2Settings.b2MixRestitution","box2D/common/B2Settings.hx",158,0xc79dd6b9)
	HX_STACK_ARG(restitution1,"restitution1")
	HX_STACK_ARG(restitution2,"restitution2")
	HX_STACK_LINE(158)
	if (((restitution1 > restitution2))){
		HX_STACK_LINE(158)
		return restitution1;
	}
	else{
		HX_STACK_LINE(158)
		return restitution2;
	}
	HX_STACK_LINE(158)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Settings_obj,b2MixRestitution,return )

Float B2Settings_obj::b2_timeToSleep;

Float B2Settings_obj::b2_linearSleepTolerance;

Float B2Settings_obj::b2_angularSleepTolerance;

Void B2Settings_obj::b2Assert( bool a){
{
		HX_STACK_FRAME("box2D.common.B2Settings","b2Assert",0x783e5aff,"box2D.common.B2Settings.b2Assert","box2D/common/B2Settings.hx",185,0xc79dd6b9)
		HX_STACK_ARG(a,"a")
		HX_STACK_LINE(185)
		if ((!(a))){
			HX_STACK_LINE(188)
			HX_STACK_DO_THROW(HX_CSTRING("Assertion Failed"));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Settings_obj,b2Assert,(void))


B2Settings_obj::B2Settings_obj()
{
}

Dynamic B2Settings_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"b2_pi") ) { return b2_pi; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"VERSION") ) { return VERSION; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"b2Assert") ) { return b2Assert_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"b2_toiSlop") ) { return b2_toiSlop; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_linearSlop") ) { return b2_linearSlop; }
		if (HX_FIELD_EQ(inName,"b2MixFriction") ) { return b2MixFriction_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_angularSlop") ) { return b2_angularSlop; }
		if (HX_FIELD_EQ(inName,"b2_maxRotation") ) { return b2_maxRotation; }
		if (HX_FIELD_EQ(inName,"b2_timeToSleep") ) { return b2_timeToSleep; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2_aabbExtension") ) { return b2_aabbExtension; }
		if (HX_FIELD_EQ(inName,"b2_polygonRadius") ) { return b2_polygonRadius; }
		if (HX_FIELD_EQ(inName,"b2MixRestitution") ) { return b2MixRestitution_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"b2_aabbMultiplier") ) { return b2_aabbMultiplier; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslation") ) { return b2_maxTranslation; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"b2_contactBaumgarte") ) { return b2_contactBaumgarte; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2_maxManifoldPoints") ) { return b2_maxManifoldPoints; }
		if (HX_FIELD_EQ(inName,"b2_velocityThreshold") ) { return b2_velocityThreshold; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"b2_maxRotationSquared") ) { return b2_maxRotationSquared; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"b2_maxLinearCorrection") ) { return b2_maxLinearCorrection; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"b2_maxAngularCorrection") ) { return b2_maxAngularCorrection; }
		if (HX_FIELD_EQ(inName,"b2_linearSleepTolerance") ) { return b2_linearSleepTolerance; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"b2_maxTOIJointsPerIsland") ) { return b2_maxTOIJointsPerIsland; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslationSquared") ) { return b2_maxTranslationSquared; }
		if (HX_FIELD_EQ(inName,"b2_angularSleepTolerance") ) { return b2_angularSleepTolerance; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"b2_maxTOIContactsPerIsland") ) { return b2_maxTOIContactsPerIsland; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Settings_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"b2_pi") ) { b2_pi=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"VERSION") ) { VERSION=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"b2_toiSlop") ) { b2_toiSlop=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"b2_linearSlop") ) { b2_linearSlop=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_angularSlop") ) { b2_angularSlop=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_maxRotation") ) { b2_maxRotation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_timeToSleep") ) { b2_timeToSleep=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2_aabbExtension") ) { b2_aabbExtension=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_polygonRadius") ) { b2_polygonRadius=inValue.Cast< Float >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"b2_aabbMultiplier") ) { b2_aabbMultiplier=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslation") ) { b2_maxTranslation=inValue.Cast< Float >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"b2_contactBaumgarte") ) { b2_contactBaumgarte=inValue.Cast< Float >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2_maxManifoldPoints") ) { b2_maxManifoldPoints=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_velocityThreshold") ) { b2_velocityThreshold=inValue.Cast< Float >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"b2_maxRotationSquared") ) { b2_maxRotationSquared=inValue.Cast< Float >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"b2_maxLinearCorrection") ) { b2_maxLinearCorrection=inValue.Cast< Float >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"b2_maxAngularCorrection") ) { b2_maxAngularCorrection=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_linearSleepTolerance") ) { b2_linearSleepTolerance=inValue.Cast< Float >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"b2_maxTOIJointsPerIsland") ) { b2_maxTOIJointsPerIsland=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_maxTranslationSquared") ) { b2_maxTranslationSquared=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_angularSleepTolerance") ) { b2_angularSleepTolerance=inValue.Cast< Float >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"b2_maxTOIContactsPerIsland") ) { b2_maxTOIContactsPerIsland=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Settings_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("VERSION"),
	HX_CSTRING("b2_pi"),
	HX_CSTRING("b2_maxManifoldPoints"),
	HX_CSTRING("b2_aabbExtension"),
	HX_CSTRING("b2_aabbMultiplier"),
	HX_CSTRING("b2_polygonRadius"),
	HX_CSTRING("b2_linearSlop"),
	HX_CSTRING("b2_angularSlop"),
	HX_CSTRING("b2_toiSlop"),
	HX_CSTRING("b2_maxTOIContactsPerIsland"),
	HX_CSTRING("b2_maxTOIJointsPerIsland"),
	HX_CSTRING("b2_velocityThreshold"),
	HX_CSTRING("b2_maxLinearCorrection"),
	HX_CSTRING("b2_maxAngularCorrection"),
	HX_CSTRING("b2_maxTranslation"),
	HX_CSTRING("b2_maxTranslationSquared"),
	HX_CSTRING("b2_maxRotation"),
	HX_CSTRING("b2_maxRotationSquared"),
	HX_CSTRING("b2_contactBaumgarte"),
	HX_CSTRING("b2MixFriction"),
	HX_CSTRING("b2MixRestitution"),
	HX_CSTRING("b2_timeToSleep"),
	HX_CSTRING("b2_linearSleepTolerance"),
	HX_CSTRING("b2_angularSleepTolerance"),
	HX_CSTRING("b2Assert"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Settings_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Settings_obj::VERSION,"VERSION");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_pi,"b2_pi");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxManifoldPoints,"b2_maxManifoldPoints");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_aabbExtension,"b2_aabbExtension");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_aabbMultiplier,"b2_aabbMultiplier");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_polygonRadius,"b2_polygonRadius");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_linearSlop,"b2_linearSlop");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_angularSlop,"b2_angularSlop");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_toiSlop,"b2_toiSlop");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTOIContactsPerIsland,"b2_maxTOIContactsPerIsland");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTOIJointsPerIsland,"b2_maxTOIJointsPerIsland");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_velocityThreshold,"b2_velocityThreshold");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxLinearCorrection,"b2_maxLinearCorrection");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxAngularCorrection,"b2_maxAngularCorrection");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTranslation,"b2_maxTranslation");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxTranslationSquared,"b2_maxTranslationSquared");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxRotation,"b2_maxRotation");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_maxRotationSquared,"b2_maxRotationSquared");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_contactBaumgarte,"b2_contactBaumgarte");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_timeToSleep,"b2_timeToSleep");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_linearSleepTolerance,"b2_linearSleepTolerance");
	HX_MARK_MEMBER_NAME(B2Settings_obj::b2_angularSleepTolerance,"b2_angularSleepTolerance");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Settings_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::VERSION,"VERSION");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_pi,"b2_pi");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxManifoldPoints,"b2_maxManifoldPoints");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_aabbExtension,"b2_aabbExtension");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_aabbMultiplier,"b2_aabbMultiplier");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_polygonRadius,"b2_polygonRadius");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_linearSlop,"b2_linearSlop");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_angularSlop,"b2_angularSlop");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_toiSlop,"b2_toiSlop");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxTOIContactsPerIsland,"b2_maxTOIContactsPerIsland");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxTOIJointsPerIsland,"b2_maxTOIJointsPerIsland");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_velocityThreshold,"b2_velocityThreshold");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxLinearCorrection,"b2_maxLinearCorrection");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxAngularCorrection,"b2_maxAngularCorrection");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxTranslation,"b2_maxTranslation");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxTranslationSquared,"b2_maxTranslationSquared");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxRotation,"b2_maxRotation");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_maxRotationSquared,"b2_maxRotationSquared");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_contactBaumgarte,"b2_contactBaumgarte");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_timeToSleep,"b2_timeToSleep");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_linearSleepTolerance,"b2_linearSleepTolerance");
	HX_VISIT_MEMBER_NAME(B2Settings_obj::b2_angularSleepTolerance,"b2_angularSleepTolerance");
};

#endif

Class B2Settings_obj::__mClass;

void B2Settings_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.B2Settings"), hx::TCanCast< B2Settings_obj> ,sStaticFields,sMemberFields,
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

void B2Settings_obj::__boot()
{
	VERSION= HX_CSTRING("2.1alpha");
	b2_pi= ::Math_obj::PI;
	b2_maxManifoldPoints= (int)2;
	b2_aabbExtension= 0.1;
	b2_aabbMultiplier= 2.0;
	b2_polygonRadius= 0.01;
	b2_linearSlop= 0.005;
	b2_angularSlop= (0.011111111111111112 * ::Math_obj::PI);
	b2_toiSlop= 0.04;
	b2_maxTOIContactsPerIsland= (int)32;
	b2_maxTOIJointsPerIsland= (int)32;
	b2_velocityThreshold= 1.0;
	b2_maxLinearCorrection= 0.2;
	b2_maxAngularCorrection= (0.044444444444444446 * ::Math_obj::PI);
	b2_maxTranslation= 2.0;
	b2_maxTranslationSquared= 4.0;
	b2_maxRotation= (0.5 * ::Math_obj::PI);
	b2_maxRotationSquared= ((0.5 * ::Math_obj::PI) * ((0.5 * ::Math_obj::PI)));
	b2_contactBaumgarte= 0.2;
	b2_timeToSleep= 0.5;
	b2_linearSleepTolerance= 0.01;
	b2_angularSleepTolerance= (0.011111111111111112 * ::Math_obj::PI);
}

} // end namespace box2D
} // end namespace common
