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
#ifndef INCLUDED_box2D_collision_B2Simplex
#include <box2D/collision/B2Simplex.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexVertex
#include <box2D/collision/B2SimplexVertex.h>
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
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2Distance_obj::__construct()
{
	return null();
}

//B2Distance_obj::~B2Distance_obj() { }

Dynamic B2Distance_obj::__CreateEmpty() { return  new B2Distance_obj; }
hx::ObjectPtr< B2Distance_obj > B2Distance_obj::__new()
{  hx::ObjectPtr< B2Distance_obj > result = new B2Distance_obj();
	result->__construct();
	return result;}

Dynamic B2Distance_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Distance_obj > result = new B2Distance_obj();
	result->__construct();
	return result;}

int B2Distance_obj::b2_gjkCalls;

int B2Distance_obj::b2_gjkIters;

int B2Distance_obj::b2_gjkMaxIters;

::box2D::collision::B2Simplex B2Distance_obj::s_simplex;

Array< int > B2Distance_obj::s_saveA;

Array< int > B2Distance_obj::s_saveB;

Void B2Distance_obj::distance( ::box2D::collision::B2DistanceOutput output,::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceInput input){
{
		HX_STACK_FRAME("box2D.collision.B2Distance","distance",0x0adb1631,"box2D.collision.B2Distance.distance","box2D/collision/B2Distance.hx",45,0x02276c8a)
		HX_STACK_ARG(output,"output")
		HX_STACK_ARG(cache,"cache")
		HX_STACK_ARG(input,"input")
		HX_STACK_LINE(46)
		++(::box2D::collision::B2Distance_obj::b2_gjkCalls);
		HX_STACK_LINE(48)
		::box2D::collision::B2DistanceProxy proxyA = input->proxyA;		HX_STACK_VAR(proxyA,"proxyA");
		HX_STACK_LINE(49)
		::box2D::collision::B2DistanceProxy proxyB = input->proxyB;		HX_STACK_VAR(proxyB,"proxyB");
		HX_STACK_LINE(51)
		::box2D::common::math::B2Transform transformA = input->transformA;		HX_STACK_VAR(transformA,"transformA");
		HX_STACK_LINE(52)
		::box2D::common::math::B2Transform transformB = input->transformB;		HX_STACK_VAR(transformB,"transformB");
		HX_STACK_LINE(55)
		::box2D::collision::B2Simplex simplex = ::box2D::collision::B2Distance_obj::s_simplex;		HX_STACK_VAR(simplex,"simplex");
		HX_STACK_LINE(56)
		simplex->readCache(cache,proxyA,transformA,proxyB,transformB);
		HX_STACK_LINE(59)
		Array< ::Dynamic > vertices = simplex->m_vertices;		HX_STACK_VAR(vertices,"vertices");
		HX_STACK_LINE(60)
		int k_maxIters = (int)20;		HX_STACK_VAR(k_maxIters,"k_maxIters");
		HX_STACK_LINE(64)
		Array< int > saveA = ::box2D::collision::B2Distance_obj::s_saveA;		HX_STACK_VAR(saveA,"saveA");
		HX_STACK_LINE(65)
		Array< int > saveB = ::box2D::collision::B2Distance_obj::s_saveB;		HX_STACK_VAR(saveB,"saveB");
		HX_STACK_LINE(66)
		int saveCount = (int)0;		HX_STACK_VAR(saveCount,"saveCount");
		HX_STACK_LINE(68)
		::box2D::common::math::B2Vec2 closestPoint = simplex->getClosestPoint();		HX_STACK_VAR(closestPoint,"closestPoint");
		HX_STACK_LINE(69)
		Float distanceSqr1 = closestPoint->lengthSquared();		HX_STACK_VAR(distanceSqr1,"distanceSqr1");
		HX_STACK_LINE(70)
		Float distanceSqr2 = distanceSqr1;		HX_STACK_VAR(distanceSqr2,"distanceSqr2");
		HX_STACK_LINE(72)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(73)
		::box2D::common::math::B2Vec2 p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(76)
		int iter = (int)0;		HX_STACK_VAR(iter,"iter");
		HX_STACK_LINE(77)
		while((true)){
			HX_STACK_LINE(77)
			if ((!(((iter < k_maxIters))))){
				HX_STACK_LINE(77)
				break;
			}
			HX_STACK_LINE(81)
			saveCount = simplex->m_count;
			HX_STACK_LINE(82)
			{
				HX_STACK_LINE(82)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(82)
				while((true)){
					HX_STACK_LINE(82)
					if ((!(((_g < saveCount))))){
						HX_STACK_LINE(82)
						break;
					}
					HX_STACK_LINE(82)
					int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(84)
					saveA[i1] = vertices->__get(i1).StaticCast< ::box2D::collision::B2SimplexVertex >()->indexA;
					HX_STACK_LINE(85)
					saveB[i1] = vertices->__get(i1).StaticCast< ::box2D::collision::B2SimplexVertex >()->indexB;
				}
			}
			HX_STACK_LINE(88)
			{
				HX_STACK_LINE(88)
				int _g = simplex->m_count;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(88)
				switch( (int)(_g)){
					case (int)1: {
					}
					;break;
					case (int)2: {
						HX_STACK_LINE(93)
						simplex->solve2();
					}
					;break;
					case (int)3: {
						HX_STACK_LINE(96)
						simplex->solve3();
					}
					;break;
					default: {
						HX_STACK_LINE(99)
						::box2D::common::B2Settings_obj::b2Assert(false);
					}
				}
			}
			HX_STACK_LINE(103)
			if (((simplex->m_count == (int)3))){
				HX_STACK_LINE(105)
				break;
			}
			HX_STACK_LINE(109)
			::box2D::common::math::B2Vec2 _g = simplex->getClosestPoint();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(109)
			p = _g;
			HX_STACK_LINE(110)
			Float _g1 = p->lengthSquared();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(110)
			distanceSqr2 = _g1;
			HX_STACK_LINE(114)
			if (((distanceSqr2 > distanceSqr1))){
			}
			HX_STACK_LINE(118)
			distanceSqr1 = distanceSqr2;
			HX_STACK_LINE(121)
			::box2D::common::math::B2Vec2 d = simplex->getSearchDirection();		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(124)
			Float _g2 = d->lengthSquared();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(124)
			if (((_g2 < 0.))){
				HX_STACK_LINE(132)
				break;
			}
			HX_STACK_LINE(136)
			::box2D::collision::B2SimplexVertex vertex = vertices->__get(simplex->m_count).StaticCast< ::box2D::collision::B2SimplexVertex >();		HX_STACK_VAR(vertex,"vertex");
			HX_STACK_LINE(137)
			::box2D::common::math::B2Vec2 _g3 = d->getNegative();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(137)
			::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Math_obj::mulTMV(transformA->R,_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(137)
			Float _g5 = proxyA->getSupport(_g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(137)
			int _g6 = ::Std_obj::_int(_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(137)
			vertex->indexA = _g6;
			HX_STACK_LINE(138)
			::box2D::common::math::B2Vec2 _g7 = proxyA->getVertex(vertex->indexA);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(138)
			::box2D::common::math::B2Vec2 _g8 = ::box2D::common::math::B2Math_obj::mulX(transformA,_g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(138)
			vertex->wA = _g8;
			HX_STACK_LINE(139)
			::box2D::common::math::B2Vec2 _g9 = ::box2D::common::math::B2Math_obj::mulTMV(transformB->R,d);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(139)
			Float _g10 = proxyB->getSupport(_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(139)
			int _g11 = ::Std_obj::_int(_g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(139)
			vertex->indexB = _g11;
			HX_STACK_LINE(140)
			::box2D::common::math::B2Vec2 _g12 = proxyB->getVertex(vertex->indexB);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(140)
			::box2D::common::math::B2Vec2 _g13 = ::box2D::common::math::B2Math_obj::mulX(transformB,_g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(140)
			vertex->wB = _g13;
			HX_STACK_LINE(141)
			::box2D::common::math::B2Vec2 _g14 = ::box2D::common::math::B2Math_obj::subtractVV(vertex->wB,vertex->wA);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(141)
			vertex->w = _g14;
			HX_STACK_LINE(144)
			++(iter);
			HX_STACK_LINE(145)
			++(::box2D::collision::B2Distance_obj::b2_gjkIters);
			HX_STACK_LINE(148)
			bool duplicate = false;		HX_STACK_VAR(duplicate,"duplicate");
			HX_STACK_LINE(149)
			{
				HX_STACK_LINE(149)
				int _g15 = (int)0;		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(149)
				while((true)){
					HX_STACK_LINE(149)
					if ((!(((_g15 < saveCount))))){
						HX_STACK_LINE(149)
						break;
					}
					HX_STACK_LINE(149)
					int i1 = (_g15)++;		HX_STACK_VAR(i1,"i1");
					HX_STACK_LINE(151)
					if (((bool((vertex->indexA == saveA->__get(i1))) && bool((vertex->indexB == saveB->__get(i1)))))){
						HX_STACK_LINE(153)
						duplicate = true;
						HX_STACK_LINE(154)
						break;
					}
				}
			}
			HX_STACK_LINE(159)
			if ((duplicate)){
				HX_STACK_LINE(161)
				break;
			}
			HX_STACK_LINE(165)
			++(simplex->m_count);
		}
		HX_STACK_LINE(168)
		Float _g15 = ::box2D::common::math::B2Math_obj::max(::box2D::collision::B2Distance_obj::b2_gjkMaxIters,iter);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(168)
		int _g16 = ::Std_obj::_int(_g15);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(168)
		::box2D::collision::B2Distance_obj::b2_gjkMaxIters = _g16;
		HX_STACK_LINE(171)
		simplex->getWitnessPoints(output->pointA,output->pointB);
		HX_STACK_LINE(172)
		Float _g17 = ::box2D::common::math::B2Math_obj::subtractVV(output->pointA,output->pointB)->length();		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(172)
		output->distance = _g17;
		HX_STACK_LINE(173)
		output->iterations = iter;
		HX_STACK_LINE(176)
		simplex->writeCache(cache);
		HX_STACK_LINE(179)
		if ((input->useRadii)){
			HX_STACK_LINE(181)
			Float rA = proxyA->m_radius;		HX_STACK_VAR(rA,"rA");
			HX_STACK_LINE(182)
			Float rB = proxyB->m_radius;		HX_STACK_VAR(rB,"rB");
			HX_STACK_LINE(184)
			if (((bool((output->distance > (rA + rB))) && bool((output->distance > 2.2250738585072014e-308))))){
				HX_STACK_LINE(188)
				hx::SubEq(output->distance,(rA + rB));
				HX_STACK_LINE(189)
				::box2D::common::math::B2Vec2 normal = ::box2D::common::math::B2Math_obj::subtractVV(output->pointB,output->pointA);		HX_STACK_VAR(normal,"normal");
				HX_STACK_LINE(190)
				normal->normalize();
				HX_STACK_LINE(191)
				hx::AddEq(output->pointA->x,(rA * normal->x));
				HX_STACK_LINE(192)
				hx::AddEq(output->pointA->y,(rA * normal->y));
				HX_STACK_LINE(193)
				hx::SubEq(output->pointB->x,(rB * normal->x));
				HX_STACK_LINE(194)
				hx::SubEq(output->pointB->y,(rB * normal->y));
			}
			else{
				HX_STACK_LINE(200)
				::box2D::common::math::B2Vec2 _g18 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(200)
				p = _g18;
				HX_STACK_LINE(201)
				p->x = (.5 * ((output->pointA->x + output->pointB->x)));
				HX_STACK_LINE(202)
				p->y = (.5 * ((output->pointA->y + output->pointB->y)));
				HX_STACK_LINE(203)
				Float _g19 = output->pointB->x = p->x;		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(203)
				output->pointA->x = _g19;
				HX_STACK_LINE(204)
				Float _g20 = output->pointB->y = p->y;		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(204)
				output->pointA->y = _g20;
				HX_STACK_LINE(205)
				output->distance = 0.0;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(B2Distance_obj,distance,(void))


B2Distance_obj::B2Distance_obj()
{
}

Dynamic B2Distance_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"s_saveA") ) { return s_saveA; }
		if (HX_FIELD_EQ(inName,"s_saveB") ) { return s_saveB; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_simplex") ) { return s_simplex; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2_gjkCalls") ) { return b2_gjkCalls; }
		if (HX_FIELD_EQ(inName,"b2_gjkIters") ) { return b2_gjkIters; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_gjkMaxIters") ) { return b2_gjkMaxIters; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Distance_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"s_saveA") ) { s_saveA=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_saveB") ) { s_saveB=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_simplex") ) { s_simplex=inValue.Cast< ::box2D::collision::B2Simplex >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2_gjkCalls") ) { b2_gjkCalls=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b2_gjkIters") ) { b2_gjkIters=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_gjkMaxIters") ) { b2_gjkMaxIters=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Distance_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_gjkCalls"),
	HX_CSTRING("b2_gjkIters"),
	HX_CSTRING("b2_gjkMaxIters"),
	HX_CSTRING("s_simplex"),
	HX_CSTRING("s_saveA"),
	HX_CSTRING("s_saveB"),
	HX_CSTRING("distance"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Distance_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Distance_obj::b2_gjkCalls,"b2_gjkCalls");
	HX_MARK_MEMBER_NAME(B2Distance_obj::b2_gjkIters,"b2_gjkIters");
	HX_MARK_MEMBER_NAME(B2Distance_obj::b2_gjkMaxIters,"b2_gjkMaxIters");
	HX_MARK_MEMBER_NAME(B2Distance_obj::s_simplex,"s_simplex");
	HX_MARK_MEMBER_NAME(B2Distance_obj::s_saveA,"s_saveA");
	HX_MARK_MEMBER_NAME(B2Distance_obj::s_saveB,"s_saveB");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Distance_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Distance_obj::b2_gjkCalls,"b2_gjkCalls");
	HX_VISIT_MEMBER_NAME(B2Distance_obj::b2_gjkIters,"b2_gjkIters");
	HX_VISIT_MEMBER_NAME(B2Distance_obj::b2_gjkMaxIters,"b2_gjkMaxIters");
	HX_VISIT_MEMBER_NAME(B2Distance_obj::s_simplex,"s_simplex");
	HX_VISIT_MEMBER_NAME(B2Distance_obj::s_saveA,"s_saveA");
	HX_VISIT_MEMBER_NAME(B2Distance_obj::s_saveB,"s_saveB");
};

#endif

Class B2Distance_obj::__mClass;

void B2Distance_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2Distance"), hx::TCanCast< B2Distance_obj> ,sStaticFields,sMemberFields,
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

void B2Distance_obj::__boot()
{
	b2_gjkCalls= (int)0;
	b2_gjkIters= (int)0;
	b2_gjkMaxIters= (int)0;
	s_simplex= ::box2D::collision::B2Simplex_obj::__new();
	s_saveA= Array_obj< int >::__new();
	s_saveB= Array_obj< int >::__new();
}

} // end namespace box2D
} // end namespace collision
