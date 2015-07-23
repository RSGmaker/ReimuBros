#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Distance
#include <box2D/collision/B2Distance.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceInput
#include <box2D/collision/B2DistanceInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceOutput
#include <box2D/collision/B2DistanceOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SeparationFunction
#include <box2D/collision/B2SeparationFunction.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TOIInput
#include <box2D/collision/B2TOIInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2TimeOfImpact
#include <box2D/collision/B2TimeOfImpact.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2TimeOfImpact_obj::__construct()
{
	return null();
}

//B2TimeOfImpact_obj::~B2TimeOfImpact_obj() { }

Dynamic B2TimeOfImpact_obj::__CreateEmpty() { return  new B2TimeOfImpact_obj; }
hx::ObjectPtr< B2TimeOfImpact_obj > B2TimeOfImpact_obj::__new()
{  hx::ObjectPtr< B2TimeOfImpact_obj > result = new B2TimeOfImpact_obj();
	result->__construct();
	return result;}

Dynamic B2TimeOfImpact_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2TimeOfImpact_obj > result = new B2TimeOfImpact_obj();
	result->__construct();
	return result;}

int B2TimeOfImpact_obj::b2_toiCalls;

int B2TimeOfImpact_obj::b2_toiIters;

int B2TimeOfImpact_obj::b2_toiMaxIters;

int B2TimeOfImpact_obj::b2_toiRootIters;

int B2TimeOfImpact_obj::b2_toiMaxRootIters;

::box2D::collision::B2SimplexCache B2TimeOfImpact_obj::s_cache;

::box2D::collision::B2DistanceInput B2TimeOfImpact_obj::s_distanceInput;

::box2D::common::math::B2Transform B2TimeOfImpact_obj::s_xfA;

::box2D::common::math::B2Transform B2TimeOfImpact_obj::s_xfB;

::box2D::collision::B2SeparationFunction B2TimeOfImpact_obj::s_fcn;

::box2D::collision::B2DistanceOutput B2TimeOfImpact_obj::s_distanceOutput;

Float B2TimeOfImpact_obj::timeOfImpact( ::box2D::collision::B2TOIInput input){
	HX_STACK_FRAME("box2D.collision.B2TimeOfImpact","timeOfImpact",0xdebd7491,"box2D.collision.B2TimeOfImpact.timeOfImpact","box2D/collision/B2TimeOfImpact.hx",47,0x9d1fa0f5)
	HX_STACK_ARG(input,"input")
	HX_STACK_LINE(48)
	++(::box2D::collision::B2TimeOfImpact_obj::b2_toiCalls);
	HX_STACK_LINE(50)
	::box2D::collision::B2DistanceProxy proxyA = input->proxyA;		HX_STACK_VAR(proxyA,"proxyA");
	HX_STACK_LINE(51)
	::box2D::collision::B2DistanceProxy proxyB = input->proxyB;		HX_STACK_VAR(proxyB,"proxyB");
	HX_STACK_LINE(53)
	::box2D::common::math::B2Sweep sweepA = input->sweepA;		HX_STACK_VAR(sweepA,"sweepA");
	HX_STACK_LINE(54)
	::box2D::common::math::B2Sweep sweepB = input->sweepB;		HX_STACK_VAR(sweepB,"sweepB");
	HX_STACK_LINE(56)
	::box2D::common::B2Settings_obj::b2Assert((sweepA->t0 == sweepB->t0));
	HX_STACK_LINE(57)
	::box2D::common::B2Settings_obj::b2Assert(((1.0 - sweepA->t0) > 2.2250738585072014e-308));
	HX_STACK_LINE(59)
	Float radius = (proxyA->m_radius + proxyB->m_radius);		HX_STACK_VAR(radius,"radius");
	HX_STACK_LINE(60)
	Float tolerance = input->tolerance;		HX_STACK_VAR(tolerance,"tolerance");
	HX_STACK_LINE(62)
	Float alpha = 0.0;		HX_STACK_VAR(alpha,"alpha");
	HX_STACK_LINE(64)
	int k_maxIterations = (int)1000;		HX_STACK_VAR(k_maxIterations,"k_maxIterations");
	HX_STACK_LINE(65)
	int iter = (int)0;		HX_STACK_VAR(iter,"iter");
	HX_STACK_LINE(66)
	Float target = 0.0;		HX_STACK_VAR(target,"target");
	HX_STACK_LINE(69)
	::box2D::collision::B2TimeOfImpact_obj::s_cache->count = (int)0;
	HX_STACK_LINE(70)
	::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->useRadii = false;
	HX_STACK_LINE(72)
	while((true)){
		HX_STACK_LINE(74)
		sweepA->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfA,alpha);
		HX_STACK_LINE(75)
		sweepB->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfB,alpha);
		HX_STACK_LINE(78)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->proxyA = proxyA;
		HX_STACK_LINE(79)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->proxyB = proxyB;
		HX_STACK_LINE(80)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->transformA = ::box2D::collision::B2TimeOfImpact_obj::s_xfA;
		HX_STACK_LINE(81)
		::box2D::collision::B2TimeOfImpact_obj::s_distanceInput->transformB = ::box2D::collision::B2TimeOfImpact_obj::s_xfB;
		HX_STACK_LINE(83)
		::box2D::collision::B2Distance_obj::distance(::box2D::collision::B2TimeOfImpact_obj::s_distanceOutput,::box2D::collision::B2TimeOfImpact_obj::s_cache,::box2D::collision::B2TimeOfImpact_obj::s_distanceInput);
		HX_STACK_LINE(85)
		if (((::box2D::collision::B2TimeOfImpact_obj::s_distanceOutput->distance <= 0.0))){
			HX_STACK_LINE(87)
			alpha = 1.0;
			HX_STACK_LINE(88)
			break;
		}
		HX_STACK_LINE(91)
		::box2D::collision::B2TimeOfImpact_obj::s_fcn->initialize(::box2D::collision::B2TimeOfImpact_obj::s_cache,proxyA,::box2D::collision::B2TimeOfImpact_obj::s_xfA,proxyB,::box2D::collision::B2TimeOfImpact_obj::s_xfB);
		HX_STACK_LINE(93)
		Float separation = ::box2D::collision::B2TimeOfImpact_obj::s_fcn->evaluate(::box2D::collision::B2TimeOfImpact_obj::s_xfA,::box2D::collision::B2TimeOfImpact_obj::s_xfB);		HX_STACK_VAR(separation,"separation");
		HX_STACK_LINE(94)
		if (((separation <= 0.0))){
			HX_STACK_LINE(96)
			alpha = 1.0;
			HX_STACK_LINE(97)
			break;
		}
		HX_STACK_LINE(100)
		if (((iter == (int)0))){
			HX_STACK_LINE(105)
			if (((separation > radius))){
				HX_STACK_LINE(107)
				Float _g = ::box2D::common::math::B2Math_obj::max((radius - tolerance),(0.75 * radius));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(107)
				target = _g;
			}
			else{
				HX_STACK_LINE(111)
				Float _g1 = ::box2D::common::math::B2Math_obj::max((separation - tolerance),(0.02 * radius));		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(111)
				target = _g1;
			}
		}
		HX_STACK_LINE(115)
		if ((((separation - target) < (0.5 * tolerance)))){
			HX_STACK_LINE(117)
			if (((iter == (int)0))){
				HX_STACK_LINE(119)
				alpha = 1.0;
				HX_STACK_LINE(120)
				break;
			}
			HX_STACK_LINE(122)
			break;
		}
		HX_STACK_LINE(149)
		Float newAlpha = alpha;		HX_STACK_VAR(newAlpha,"newAlpha");
		HX_STACK_LINE(150)
		{
			HX_STACK_LINE(151)
			Float x1 = alpha;		HX_STACK_VAR(x1,"x1");
			HX_STACK_LINE(152)
			Float x2 = 1.0;		HX_STACK_VAR(x2,"x2");
			HX_STACK_LINE(154)
			Float f1 = separation;		HX_STACK_VAR(f1,"f1");
			HX_STACK_LINE(156)
			sweepA->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfA,x2);
			HX_STACK_LINE(157)
			sweepB->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfB,x2);
			HX_STACK_LINE(159)
			Float f2 = ::box2D::collision::B2TimeOfImpact_obj::s_fcn->evaluate(::box2D::collision::B2TimeOfImpact_obj::s_xfA,::box2D::collision::B2TimeOfImpact_obj::s_xfB);		HX_STACK_VAR(f2,"f2");
			HX_STACK_LINE(162)
			if (((f2 >= target))){
				HX_STACK_LINE(164)
				alpha = 1.0;
				HX_STACK_LINE(165)
				break;
			}
			HX_STACK_LINE(169)
			int rootIterCount = (int)0;		HX_STACK_VAR(rootIterCount,"rootIterCount");
			HX_STACK_LINE(170)
			while((true)){
				HX_STACK_LINE(173)
				Float x;		HX_STACK_VAR(x,"x");
				HX_STACK_LINE(174)
				if (((((int(rootIterCount) & int((int)1))) != (int)0))){
					HX_STACK_LINE(177)
					x = (x1 + (Float((((target - f1)) * ((x2 - x1)))) / Float(((f2 - f1)))));
				}
				else{
					HX_STACK_LINE(182)
					x = (0.5 * ((x1 + x2)));
				}
				HX_STACK_LINE(185)
				sweepA->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfA,x);
				HX_STACK_LINE(186)
				sweepB->getTransform(::box2D::collision::B2TimeOfImpact_obj::s_xfB,x);
				HX_STACK_LINE(188)
				Float f = ::box2D::collision::B2TimeOfImpact_obj::s_fcn->evaluate(::box2D::collision::B2TimeOfImpact_obj::s_xfA,::box2D::collision::B2TimeOfImpact_obj::s_xfB);		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(190)
				Float _g2 = ::box2D::common::math::B2Math_obj::abs((f - target));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(190)
				if (((_g2 < (0.025 * tolerance)))){
					HX_STACK_LINE(192)
					newAlpha = x;
					HX_STACK_LINE(193)
					break;
				}
				HX_STACK_LINE(197)
				if (((f > target))){
					HX_STACK_LINE(199)
					x1 = x;
					HX_STACK_LINE(200)
					f1 = f;
				}
				else{
					HX_STACK_LINE(204)
					x2 = x;
					HX_STACK_LINE(205)
					f2 = f;
				}
				HX_STACK_LINE(208)
				++(rootIterCount);
				HX_STACK_LINE(209)
				++(::box2D::collision::B2TimeOfImpact_obj::b2_toiRootIters);
				HX_STACK_LINE(210)
				if (((rootIterCount == (int)50))){
					HX_STACK_LINE(212)
					break;
				}
			}
			HX_STACK_LINE(216)
			Float _g3 = ::box2D::common::math::B2Math_obj::max(::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxRootIters,rootIterCount);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(216)
			int _g4 = ::Std_obj::_int(_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(216)
			::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxRootIters = _g4;
		}
		HX_STACK_LINE(220)
		if (((newAlpha < alpha))){
			HX_STACK_LINE(222)
			break;
		}
		HX_STACK_LINE(225)
		alpha = newAlpha;
		HX_STACK_LINE(227)
		(iter)++;
		HX_STACK_LINE(228)
		++(::box2D::collision::B2TimeOfImpact_obj::b2_toiIters);
		HX_STACK_LINE(230)
		if (((iter == k_maxIterations))){
			HX_STACK_LINE(232)
			break;
		}
	}
	HX_STACK_LINE(236)
	Float _g5 = ::box2D::common::math::B2Math_obj::max(::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxIters,iter);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(236)
	int _g6 = ::Std_obj::_int(_g5);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(236)
	::box2D::collision::B2TimeOfImpact_obj::b2_toiMaxIters = _g6;
	HX_STACK_LINE(238)
	return alpha;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2TimeOfImpact_obj,timeOfImpact,return )


B2TimeOfImpact_obj::B2TimeOfImpact_obj()
{
}

Dynamic B2TimeOfImpact_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_xfA") ) { return s_xfA; }
		if (HX_FIELD_EQ(inName,"s_xfB") ) { return s_xfB; }
		if (HX_FIELD_EQ(inName,"s_fcn") ) { return s_fcn; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_cache") ) { return s_cache; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2_toiCalls") ) { return b2_toiCalls; }
		if (HX_FIELD_EQ(inName,"b2_toiIters") ) { return b2_toiIters; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"timeOfImpact") ) { return timeOfImpact_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_toiMaxIters") ) { return b2_toiMaxIters; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"b2_toiRootIters") ) { return b2_toiRootIters; }
		if (HX_FIELD_EQ(inName,"s_distanceInput") ) { return s_distanceInput; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"s_distanceOutput") ) { return s_distanceOutput; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_toiMaxRootIters") ) { return b2_toiMaxRootIters; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2TimeOfImpact_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_xfA") ) { s_xfA=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_xfB") ) { s_xfB=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_fcn") ) { s_fcn=inValue.Cast< ::box2D::collision::B2SeparationFunction >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"s_cache") ) { s_cache=inValue.Cast< ::box2D::collision::B2SimplexCache >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2_toiCalls") ) { b2_toiCalls=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_toiIters") ) { b2_toiIters=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_toiMaxIters") ) { b2_toiMaxIters=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"b2_toiRootIters") ) { b2_toiRootIters=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_distanceInput") ) { s_distanceInput=inValue.Cast< ::box2D::collision::B2DistanceInput >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"s_distanceOutput") ) { s_distanceOutput=inValue.Cast< ::box2D::collision::B2DistanceOutput >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"b2_toiMaxRootIters") ) { b2_toiMaxRootIters=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2TimeOfImpact_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_toiCalls"),
	HX_CSTRING("b2_toiIters"),
	HX_CSTRING("b2_toiMaxIters"),
	HX_CSTRING("b2_toiRootIters"),
	HX_CSTRING("b2_toiMaxRootIters"),
	HX_CSTRING("s_cache"),
	HX_CSTRING("s_distanceInput"),
	HX_CSTRING("s_xfA"),
	HX_CSTRING("s_xfB"),
	HX_CSTRING("s_fcn"),
	HX_CSTRING("s_distanceOutput"),
	HX_CSTRING("timeOfImpact"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiCalls,"b2_toiCalls");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiIters,"b2_toiIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiMaxIters,"b2_toiMaxIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiRootIters,"b2_toiRootIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiMaxRootIters,"b2_toiMaxRootIters");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_cache,"s_cache");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_distanceInput,"s_distanceInput");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_xfA,"s_xfA");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_xfB,"s_xfB");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_fcn,"s_fcn");
	HX_MARK_MEMBER_NAME(B2TimeOfImpact_obj::s_distanceOutput,"s_distanceOutput");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiCalls,"b2_toiCalls");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiIters,"b2_toiIters");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiMaxIters,"b2_toiMaxIters");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiRootIters,"b2_toiRootIters");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::b2_toiMaxRootIters,"b2_toiMaxRootIters");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::s_cache,"s_cache");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::s_distanceInput,"s_distanceInput");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::s_xfA,"s_xfA");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::s_xfB,"s_xfB");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::s_fcn,"s_fcn");
	HX_VISIT_MEMBER_NAME(B2TimeOfImpact_obj::s_distanceOutput,"s_distanceOutput");
};

#endif

Class B2TimeOfImpact_obj::__mClass;

void B2TimeOfImpact_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2TimeOfImpact"), hx::TCanCast< B2TimeOfImpact_obj> ,sStaticFields,sMemberFields,
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

void B2TimeOfImpact_obj::__boot()
{
	b2_toiCalls= (int)0;
	b2_toiIters= (int)0;
	b2_toiMaxIters= (int)0;
	b2_toiRootIters= (int)0;
	b2_toiMaxRootIters= (int)0;
	s_cache= ::box2D::collision::B2SimplexCache_obj::__new();
	s_distanceInput= ::box2D::collision::B2DistanceInput_obj::__new();
	s_xfA= ::box2D::common::math::B2Transform_obj::__new(null(),null());
	s_xfB= ::box2D::common::math::B2Transform_obj::__new(null(),null());
	s_fcn= ::box2D::collision::B2SeparationFunction_obj::__new();
	s_distanceOutput= ::box2D::collision::B2DistanceOutput_obj::__new();
}

} // end namespace box2D
} // end namespace collision
