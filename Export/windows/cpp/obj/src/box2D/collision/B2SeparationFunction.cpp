#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SeparationFunction
#include <box2D/collision/B2SeparationFunction.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SeparationFunctionType
#include <box2D/collision/B2SeparationFunctionType.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
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

Void B2SeparationFunction_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2SeparationFunction","new",0x092307ed,"box2D.collision.B2SeparationFunction.new","box2D/collision/B2SeparationFunction.hx",320,0x4bd3d121)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(322)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(322)
	this->m_localPoint = _g;
	HX_STACK_LINE(323)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(323)
	this->m_axis = _g1;
}
;
	return null();
}

//B2SeparationFunction_obj::~B2SeparationFunction_obj() { }

Dynamic B2SeparationFunction_obj::__CreateEmpty() { return  new B2SeparationFunction_obj; }
hx::ObjectPtr< B2SeparationFunction_obj > B2SeparationFunction_obj::__new()
{  hx::ObjectPtr< B2SeparationFunction_obj > result = new B2SeparationFunction_obj();
	result->__construct();
	return result;}

Dynamic B2SeparationFunction_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2SeparationFunction_obj > result = new B2SeparationFunction_obj();
	result->__construct();
	return result;}

Void B2SeparationFunction_obj::initialize( ::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceProxy proxyA,::box2D::common::math::B2Transform transformA,::box2D::collision::B2DistanceProxy proxyB,::box2D::common::math::B2Transform transformB){
{
		HX_STACK_FRAME("box2D.collision.B2SeparationFunction","initialize",0x8319b563,"box2D.collision.B2SeparationFunction.initialize","box2D/collision/B2SeparationFunction.hx",39,0x4bd3d121)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cache,"cache")
		HX_STACK_ARG(proxyA,"proxyA")
		HX_STACK_ARG(transformA,"transformA")
		HX_STACK_ARG(proxyB,"proxyB")
		HX_STACK_ARG(transformB,"transformB")
		HX_STACK_LINE(40)
		this->m_proxyA = proxyA;
		HX_STACK_LINE(41)
		this->m_proxyB = proxyB;
		HX_STACK_LINE(42)
		int count = cache->count;		HX_STACK_VAR(count,"count");
		HX_STACK_LINE(43)
		::box2D::common::B2Settings_obj::b2Assert((bool(((int)0 < count)) && bool((count < (int)3))));
		HX_STACK_LINE(45)
		::box2D::common::math::B2Vec2 localPointA = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(localPointA,"localPointA");
		HX_STACK_LINE(46)
		::box2D::common::math::B2Vec2 localPointA1;		HX_STACK_VAR(localPointA1,"localPointA1");
		HX_STACK_LINE(47)
		::box2D::common::math::B2Vec2 localPointA2;		HX_STACK_VAR(localPointA2,"localPointA2");
		HX_STACK_LINE(48)
		::box2D::common::math::B2Vec2 localPointB = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(localPointB,"localPointB");
		HX_STACK_LINE(49)
		::box2D::common::math::B2Vec2 localPointB1;		HX_STACK_VAR(localPointB1,"localPointB1");
		HX_STACK_LINE(50)
		::box2D::common::math::B2Vec2 localPointB2;		HX_STACK_VAR(localPointB2,"localPointB2");
		HX_STACK_LINE(51)
		Float pointAX;		HX_STACK_VAR(pointAX,"pointAX");
		HX_STACK_LINE(52)
		Float pointAY;		HX_STACK_VAR(pointAY,"pointAY");
		HX_STACK_LINE(53)
		Float pointBX;		HX_STACK_VAR(pointBX,"pointBX");
		HX_STACK_LINE(54)
		Float pointBY;		HX_STACK_VAR(pointBY,"pointBY");
		HX_STACK_LINE(55)
		Float normalX;		HX_STACK_VAR(normalX,"normalX");
		HX_STACK_LINE(56)
		Float normalY;		HX_STACK_VAR(normalY,"normalY");
		HX_STACK_LINE(57)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(58)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(59)
		Float s;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(60)
		Float sgn;		HX_STACK_VAR(sgn,"sgn");
		HX_STACK_LINE(62)
		if (((count == (int)1))){
			HX_STACK_LINE(64)
			this->m_type = ::box2D::collision::B2SeparationFunctionType_obj::POINTS;
			HX_STACK_LINE(65)
			::box2D::common::math::B2Vec2 _g = this->m_proxyA->getVertex(cache->indexA->__get((int)0));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(65)
			localPointA = _g;
			HX_STACK_LINE(66)
			::box2D::common::math::B2Vec2 _g1 = this->m_proxyB->getVertex(cache->indexB->__get((int)0));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(66)
			localPointB = _g1;
			HX_STACK_LINE(68)
			tVec = localPointA;
			HX_STACK_LINE(69)
			tMat = transformA->R;
			HX_STACK_LINE(70)
			pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_STACK_LINE(71)
			pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_STACK_LINE(73)
			tVec = localPointB;
			HX_STACK_LINE(74)
			tMat = transformB->R;
			HX_STACK_LINE(75)
			pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
			HX_STACK_LINE(76)
			pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
			HX_STACK_LINE(78)
			this->m_axis->x = (pointBX - pointAX);
			HX_STACK_LINE(79)
			this->m_axis->y = (pointBY - pointAY);
			HX_STACK_LINE(80)
			this->m_axis->normalize();
		}
		else{
			HX_STACK_LINE(82)
			if (((cache->indexB->__get((int)0) == cache->indexB->__get((int)1)))){
				HX_STACK_LINE(85)
				this->m_type = ::box2D::collision::B2SeparationFunctionType_obj::FACE_A;
				HX_STACK_LINE(86)
				::box2D::common::math::B2Vec2 _g2 = this->m_proxyA->getVertex(cache->indexA->__get((int)0));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(86)
				localPointA1 = _g2;
				HX_STACK_LINE(87)
				::box2D::common::math::B2Vec2 _g3 = this->m_proxyA->getVertex(cache->indexA->__get((int)1));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(87)
				localPointA2 = _g3;
				HX_STACK_LINE(88)
				::box2D::common::math::B2Vec2 _g4 = this->m_proxyB->getVertex(cache->indexB->__get((int)0));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(88)
				localPointB = _g4;
				HX_STACK_LINE(89)
				this->m_localPoint->x = (0.5 * ((localPointA1->x + localPointA2->x)));
				HX_STACK_LINE(90)
				this->m_localPoint->y = (0.5 * ((localPointA1->y + localPointA2->y)));
				HX_STACK_LINE(91)
				::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Math_obj::subtractVV(localPointA2,localPointA1);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(91)
				::box2D::common::math::B2Vec2 _g6 = ::box2D::common::math::B2Math_obj::crossVF(_g5,1.0);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(91)
				this->m_axis = _g6;
				HX_STACK_LINE(92)
				this->m_axis->normalize();
				HX_STACK_LINE(95)
				tVec = this->m_axis;
				HX_STACK_LINE(96)
				tMat = transformA->R;
				HX_STACK_LINE(97)
				normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
				HX_STACK_LINE(98)
				normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
				HX_STACK_LINE(100)
				tVec = this->m_localPoint;
				HX_STACK_LINE(101)
				tMat = transformA->R;
				HX_STACK_LINE(102)
				pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
				HX_STACK_LINE(103)
				pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
				HX_STACK_LINE(105)
				tVec = localPointB;
				HX_STACK_LINE(106)
				tMat = transformB->R;
				HX_STACK_LINE(107)
				pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
				HX_STACK_LINE(108)
				pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
				HX_STACK_LINE(111)
				s = ((((pointBX - pointAX)) * normalX) + (((pointBY - pointAY)) * normalY));
				HX_STACK_LINE(112)
				if (((s < 0.0))){
					HX_STACK_LINE(114)
					this->m_axis->negativeSelf();
				}
			}
			else{
				HX_STACK_LINE(117)
				if (((cache->indexA->__get((int)0) == cache->indexA->__get((int)0)))){
					HX_STACK_LINE(120)
					this->m_type = ::box2D::collision::B2SeparationFunctionType_obj::FACE_B;
					HX_STACK_LINE(121)
					::box2D::common::math::B2Vec2 _g7 = this->m_proxyB->getVertex(cache->indexB->__get((int)0));		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(121)
					localPointB1 = _g7;
					HX_STACK_LINE(122)
					::box2D::common::math::B2Vec2 _g8 = this->m_proxyB->getVertex(cache->indexB->__get((int)1));		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(122)
					localPointB2 = _g8;
					HX_STACK_LINE(123)
					::box2D::common::math::B2Vec2 _g9 = this->m_proxyA->getVertex(cache->indexA->__get((int)0));		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(123)
					localPointA = _g9;
					HX_STACK_LINE(124)
					this->m_localPoint->x = (0.5 * ((localPointB1->x + localPointB2->x)));
					HX_STACK_LINE(125)
					this->m_localPoint->y = (0.5 * ((localPointB1->y + localPointB2->y)));
					HX_STACK_LINE(126)
					::box2D::common::math::B2Vec2 _g10 = ::box2D::common::math::B2Math_obj::subtractVV(localPointB2,localPointB1);		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(126)
					::box2D::common::math::B2Vec2 _g11 = ::box2D::common::math::B2Math_obj::crossVF(_g10,1.0);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(126)
					this->m_axis = _g11;
					HX_STACK_LINE(127)
					this->m_axis->normalize();
					HX_STACK_LINE(130)
					tVec = this->m_axis;
					HX_STACK_LINE(131)
					tMat = transformB->R;
					HX_STACK_LINE(132)
					normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
					HX_STACK_LINE(133)
					normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
					HX_STACK_LINE(135)
					tVec = this->m_localPoint;
					HX_STACK_LINE(136)
					tMat = transformB->R;
					HX_STACK_LINE(137)
					pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_STACK_LINE(138)
					pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_STACK_LINE(140)
					tVec = localPointA;
					HX_STACK_LINE(141)
					tMat = transformA->R;
					HX_STACK_LINE(142)
					pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
					HX_STACK_LINE(143)
					pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
					HX_STACK_LINE(146)
					s = ((((pointAX - pointBX)) * normalX) + (((pointAY - pointBY)) * normalY));
					HX_STACK_LINE(147)
					if (((s < 0.0))){
						HX_STACK_LINE(149)
						this->m_axis->negativeSelf();
					}
				}
				else{
					HX_STACK_LINE(156)
					::box2D::common::math::B2Vec2 _g12 = this->m_proxyA->getVertex(cache->indexA->__get((int)0));		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(156)
					localPointA1 = _g12;
					HX_STACK_LINE(157)
					::box2D::common::math::B2Vec2 _g13 = this->m_proxyA->getVertex(cache->indexA->__get((int)1));		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(157)
					localPointA2 = _g13;
					HX_STACK_LINE(158)
					::box2D::common::math::B2Vec2 _g14 = this->m_proxyB->getVertex(cache->indexB->__get((int)0));		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(158)
					localPointB1 = _g14;
					HX_STACK_LINE(159)
					::box2D::common::math::B2Vec2 _g15 = this->m_proxyB->getVertex(cache->indexB->__get((int)1));		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(159)
					localPointB2 = _g15;
					HX_STACK_LINE(161)
					::box2D::common::math::B2Vec2 pA = ::box2D::common::math::B2Math_obj::mulX(transformA,localPointA);		HX_STACK_VAR(pA,"pA");
					HX_STACK_LINE(162)
					::box2D::common::math::B2Vec2 _g16 = ::box2D::common::math::B2Math_obj::subtractVV(localPointA2,localPointA1);		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(162)
					::box2D::common::math::B2Vec2 dA = ::box2D::common::math::B2Math_obj::mulMV(transformA->R,_g16);		HX_STACK_VAR(dA,"dA");
					HX_STACK_LINE(163)
					::box2D::common::math::B2Vec2 pB = ::box2D::common::math::B2Math_obj::mulX(transformB,localPointB);		HX_STACK_VAR(pB,"pB");
					HX_STACK_LINE(164)
					::box2D::common::math::B2Vec2 _g17 = ::box2D::common::math::B2Math_obj::subtractVV(localPointB2,localPointB1);		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(164)
					::box2D::common::math::B2Vec2 dB = ::box2D::common::math::B2Math_obj::mulMV(transformB->R,_g17);		HX_STACK_VAR(dB,"dB");
					HX_STACK_LINE(166)
					Float a = ((dA->x * dA->x) + (dA->y * dA->y));		HX_STACK_VAR(a,"a");
					HX_STACK_LINE(167)
					Float e = ((dB->x * dB->x) + (dB->y * dB->y));		HX_STACK_VAR(e,"e");
					HX_STACK_LINE(168)
					::box2D::common::math::B2Vec2 r = ::box2D::common::math::B2Math_obj::subtractVV(dB,dA);		HX_STACK_VAR(r,"r");
					HX_STACK_LINE(169)
					Float c = ((dA->x * r->x) + (dA->y * r->y));		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(170)
					Float f = ((dB->x * r->x) + (dB->y * r->y));		HX_STACK_VAR(f,"f");
					HX_STACK_LINE(172)
					Float b = ((dA->x * dB->x) + (dA->y * dB->y));		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(173)
					Float denom = ((a * e) - (b * b));		HX_STACK_VAR(denom,"denom");
					HX_STACK_LINE(175)
					s = 0.0;
					HX_STACK_LINE(176)
					if (((denom != 0.0))){
						HX_STACK_LINE(178)
						Float _g18 = ::box2D::common::math::B2Math_obj::clamp((Float((((b * f) - (c * e)))) / Float(denom)),0.0,1.0);		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(178)
						s = _g18;
					}
					HX_STACK_LINE(181)
					Float t = (Float((((b * s) + f))) / Float(e));		HX_STACK_VAR(t,"t");
					HX_STACK_LINE(182)
					if (((t < 0.0))){
						HX_STACK_LINE(184)
						t = 0.0;
						HX_STACK_LINE(185)
						Float _g19 = ::box2D::common::math::B2Math_obj::clamp((Float(((b - c))) / Float(a)),0.0,1.0);		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(185)
						s = _g19;
					}
					HX_STACK_LINE(189)
					::box2D::common::math::B2Vec2 _g20 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(189)
					localPointA = _g20;
					HX_STACK_LINE(190)
					localPointA->x = (localPointA1->x + (s * ((localPointA2->x - localPointA1->x))));
					HX_STACK_LINE(191)
					localPointA->y = (localPointA1->y + (s * ((localPointA2->y - localPointA1->y))));
					HX_STACK_LINE(193)
					::box2D::common::math::B2Vec2 _g21 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(193)
					localPointB = _g21;
					HX_STACK_LINE(194)
					localPointB->x = (localPointB1->x + (s * ((localPointB2->x - localPointB1->x))));
					HX_STACK_LINE(195)
					localPointB->y = (localPointB1->y + (s * ((localPointB2->y - localPointB1->y))));
					HX_STACK_LINE(197)
					if (((bool((s == 0.0)) || bool((s == 1.0))))){
						HX_STACK_LINE(199)
						this->m_type = ::box2D::collision::B2SeparationFunctionType_obj::FACE_B;
						HX_STACK_LINE(200)
						::box2D::common::math::B2Vec2 _g22 = ::box2D::common::math::B2Math_obj::subtractVV(localPointB2,localPointB1);		HX_STACK_VAR(_g22,"_g22");
						HX_STACK_LINE(200)
						::box2D::common::math::B2Vec2 _g23 = ::box2D::common::math::B2Math_obj::crossVF(_g22,1.0);		HX_STACK_VAR(_g23,"_g23");
						HX_STACK_LINE(200)
						this->m_axis = _g23;
						HX_STACK_LINE(201)
						this->m_axis->normalize();
						HX_STACK_LINE(203)
						this->m_localPoint = localPointB;
						HX_STACK_LINE(206)
						tVec = this->m_axis;
						HX_STACK_LINE(207)
						tMat = transformB->R;
						HX_STACK_LINE(208)
						normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
						HX_STACK_LINE(209)
						normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
						HX_STACK_LINE(211)
						tVec = this->m_localPoint;
						HX_STACK_LINE(212)
						tMat = transformB->R;
						HX_STACK_LINE(213)
						pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_STACK_LINE(214)
						pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_STACK_LINE(216)
						tVec = localPointA;
						HX_STACK_LINE(217)
						tMat = transformA->R;
						HX_STACK_LINE(218)
						pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_STACK_LINE(219)
						pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_STACK_LINE(222)
						sgn = ((((pointAX - pointBX)) * normalX) + (((pointAY - pointBY)) * normalY));
						HX_STACK_LINE(223)
						if (((s < 0.0))){
							HX_STACK_LINE(225)
							this->m_axis->negativeSelf();
						}
					}
					else{
						HX_STACK_LINE(230)
						this->m_type = ::box2D::collision::B2SeparationFunctionType_obj::FACE_A;
						HX_STACK_LINE(231)
						::box2D::common::math::B2Vec2 _g24 = ::box2D::common::math::B2Math_obj::subtractVV(localPointA2,localPointA1);		HX_STACK_VAR(_g24,"_g24");
						HX_STACK_LINE(231)
						::box2D::common::math::B2Vec2 _g25 = ::box2D::common::math::B2Math_obj::crossVF(_g24,1.0);		HX_STACK_VAR(_g25,"_g25");
						HX_STACK_LINE(231)
						this->m_axis = _g25;
						HX_STACK_LINE(233)
						this->m_localPoint = localPointA;
						HX_STACK_LINE(236)
						tVec = this->m_axis;
						HX_STACK_LINE(237)
						tMat = transformA->R;
						HX_STACK_LINE(238)
						normalX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
						HX_STACK_LINE(239)
						normalY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
						HX_STACK_LINE(241)
						tVec = this->m_localPoint;
						HX_STACK_LINE(242)
						tMat = transformA->R;
						HX_STACK_LINE(243)
						pointAX = (transformA->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_STACK_LINE(244)
						pointAY = (transformA->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_STACK_LINE(246)
						tVec = localPointB;
						HX_STACK_LINE(247)
						tMat = transformB->R;
						HX_STACK_LINE(248)
						pointBX = (transformB->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
						HX_STACK_LINE(249)
						pointBY = (transformB->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
						HX_STACK_LINE(252)
						sgn = ((((pointBX - pointAX)) * normalX) + (((pointBY - pointAY)) * normalY));
						HX_STACK_LINE(253)
						if (((s < 0.0))){
							HX_STACK_LINE(255)
							this->m_axis->negativeSelf();
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2SeparationFunction_obj,initialize,(void))

Float B2SeparationFunction_obj::evaluate( ::box2D::common::math::B2Transform transformA,::box2D::common::math::B2Transform transformB){
	HX_STACK_FRAME("box2D.collision.B2SeparationFunction","evaluate",0xab4ba9ac,"box2D.collision.B2SeparationFunction.evaluate","box2D/collision/B2SeparationFunction.hx",262,0x4bd3d121)
	HX_STACK_THIS(this)
	HX_STACK_ARG(transformA,"transformA")
	HX_STACK_ARG(transformB,"transformB")
	HX_STACK_LINE(263)
	::box2D::common::math::B2Vec2 axisA;		HX_STACK_VAR(axisA,"axisA");
	HX_STACK_LINE(264)
	::box2D::common::math::B2Vec2 axisB;		HX_STACK_VAR(axisB,"axisB");
	HX_STACK_LINE(265)
	::box2D::common::math::B2Vec2 localPointA;		HX_STACK_VAR(localPointA,"localPointA");
	HX_STACK_LINE(266)
	::box2D::common::math::B2Vec2 localPointB;		HX_STACK_VAR(localPointB,"localPointB");
	HX_STACK_LINE(267)
	::box2D::common::math::B2Vec2 pointA;		HX_STACK_VAR(pointA,"pointA");
	HX_STACK_LINE(268)
	::box2D::common::math::B2Vec2 pointB;		HX_STACK_VAR(pointB,"pointB");
	HX_STACK_LINE(269)
	Float seperation;		HX_STACK_VAR(seperation,"seperation");
	HX_STACK_LINE(270)
	::box2D::common::math::B2Vec2 normal;		HX_STACK_VAR(normal,"normal");
	HX_STACK_LINE(271)
	::box2D::collision::B2SeparationFunctionType _g = this->m_type;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(271)
	switch( (int)(_g->__Index())){
		case (int)0: {
			HX_STACK_LINE(275)
			::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Math_obj::mulTMV(transformA->R,this->m_axis);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(275)
			axisA = _g1;
			HX_STACK_LINE(276)
			::box2D::common::math::B2Vec2 _g11 = this->m_axis->getNegative();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(276)
			::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Math_obj::mulTMV(transformB->R,_g11);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(276)
			axisB = _g2;
			HX_STACK_LINE(277)
			::box2D::common::math::B2Vec2 _g3 = this->m_proxyA->getSupportVertex(axisA);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(277)
			localPointA = _g3;
			HX_STACK_LINE(278)
			::box2D::common::math::B2Vec2 _g4 = this->m_proxyB->getSupportVertex(axisB);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(278)
			localPointB = _g4;
			HX_STACK_LINE(279)
			::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Math_obj::mulX(transformA,localPointA);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(279)
			pointA = _g5;
			HX_STACK_LINE(280)
			::box2D::common::math::B2Vec2 _g6 = ::box2D::common::math::B2Math_obj::mulX(transformB,localPointB);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(280)
			pointB = _g6;
			HX_STACK_LINE(282)
			seperation = ((((pointB->x - pointA->x)) * this->m_axis->x) + (((pointB->y - pointA->y)) * this->m_axis->y));
			HX_STACK_LINE(283)
			return seperation;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(287)
			::box2D::common::math::B2Vec2 _g7 = ::box2D::common::math::B2Math_obj::mulMV(transformA->R,this->m_axis);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(287)
			normal = _g7;
			HX_STACK_LINE(288)
			::box2D::common::math::B2Vec2 _g8 = ::box2D::common::math::B2Math_obj::mulX(transformA,this->m_localPoint);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(288)
			pointA = _g8;
			HX_STACK_LINE(290)
			::box2D::common::math::B2Vec2 _g9 = normal->getNegative();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(290)
			::box2D::common::math::B2Vec2 _g10 = ::box2D::common::math::B2Math_obj::mulTMV(transformB->R,_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(290)
			axisB = _g10;
			HX_STACK_LINE(292)
			::box2D::common::math::B2Vec2 _g11 = this->m_proxyB->getSupportVertex(axisB);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(292)
			localPointB = _g11;
			HX_STACK_LINE(293)
			::box2D::common::math::B2Vec2 _g12 = ::box2D::common::math::B2Math_obj::mulX(transformB,localPointB);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(293)
			pointB = _g12;
			HX_STACK_LINE(296)
			seperation = ((((pointB->x - pointA->x)) * normal->x) + (((pointB->y - pointA->y)) * normal->y));
			HX_STACK_LINE(297)
			return seperation;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(301)
			::box2D::common::math::B2Vec2 _g13 = ::box2D::common::math::B2Math_obj::mulMV(transformB->R,this->m_axis);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(301)
			normal = _g13;
			HX_STACK_LINE(302)
			::box2D::common::math::B2Vec2 _g14 = ::box2D::common::math::B2Math_obj::mulX(transformB,this->m_localPoint);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(302)
			pointB = _g14;
			HX_STACK_LINE(304)
			::box2D::common::math::B2Vec2 _g15 = normal->getNegative();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(304)
			::box2D::common::math::B2Vec2 _g16 = ::box2D::common::math::B2Math_obj::mulTMV(transformA->R,_g15);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(304)
			axisA = _g16;
			HX_STACK_LINE(306)
			::box2D::common::math::B2Vec2 _g17 = this->m_proxyA->getSupportVertex(axisA);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(306)
			localPointA = _g17;
			HX_STACK_LINE(307)
			::box2D::common::math::B2Vec2 _g18 = ::box2D::common::math::B2Math_obj::mulX(transformA,localPointA);		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(307)
			pointA = _g18;
			HX_STACK_LINE(310)
			seperation = ((((pointA->x - pointB->x)) * normal->x) + (((pointA->y - pointB->y)) * normal->y));
			HX_STACK_LINE(311)
			return seperation;
		}
		;break;
	}
	HX_STACK_LINE(271)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC2(B2SeparationFunction_obj,evaluate,return )


B2SeparationFunction_obj::B2SeparationFunction_obj()
{
}

void B2SeparationFunction_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2SeparationFunction);
	HX_MARK_MEMBER_NAME(m_proxyA,"m_proxyA");
	HX_MARK_MEMBER_NAME(m_proxyB,"m_proxyB");
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(m_localPoint,"m_localPoint");
	HX_MARK_MEMBER_NAME(m_axis,"m_axis");
	HX_MARK_END_CLASS();
}

void B2SeparationFunction_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_proxyA,"m_proxyA");
	HX_VISIT_MEMBER_NAME(m_proxyB,"m_proxyB");
	HX_VISIT_MEMBER_NAME(m_type,"m_type");
	HX_VISIT_MEMBER_NAME(m_localPoint,"m_localPoint");
	HX_VISIT_MEMBER_NAME(m_axis,"m_axis");
}

Dynamic B2SeparationFunction_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		if (HX_FIELD_EQ(inName,"m_axis") ) { return m_axis; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"evaluate") ) { return evaluate_dyn(); }
		if (HX_FIELD_EQ(inName,"m_proxyA") ) { return m_proxyA; }
		if (HX_FIELD_EQ(inName,"m_proxyB") ) { return m_proxyB; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localPoint") ) { return m_localPoint; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2SeparationFunction_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< ::box2D::collision::B2SeparationFunctionType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_axis") ) { m_axis=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_proxyA") ) { m_proxyA=inValue.Cast< ::box2D::collision::B2DistanceProxy >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_proxyB") ) { m_proxyB=inValue.Cast< ::box2D::collision::B2DistanceProxy >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_localPoint") ) { m_localPoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2SeparationFunction_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_proxyA"));
	outFields->push(HX_CSTRING("m_proxyB"));
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_localPoint"));
	outFields->push(HX_CSTRING("m_axis"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::collision::B2DistanceProxy*/ ,(int)offsetof(B2SeparationFunction_obj,m_proxyA),HX_CSTRING("m_proxyA")},
	{hx::fsObject /*::box2D::collision::B2DistanceProxy*/ ,(int)offsetof(B2SeparationFunction_obj,m_proxyB),HX_CSTRING("m_proxyB")},
	{hx::fsObject /*::box2D::collision::B2SeparationFunctionType*/ ,(int)offsetof(B2SeparationFunction_obj,m_type),HX_CSTRING("m_type")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2SeparationFunction_obj,m_localPoint),HX_CSTRING("m_localPoint")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2SeparationFunction_obj,m_axis),HX_CSTRING("m_axis")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("evaluate"),
	HX_CSTRING("m_proxyA"),
	HX_CSTRING("m_proxyB"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_localPoint"),
	HX_CSTRING("m_axis"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2SeparationFunction_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2SeparationFunction_obj::__mClass,"__mClass");
};

#endif

Class B2SeparationFunction_obj::__mClass;

void B2SeparationFunction_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2SeparationFunction"), hx::TCanCast< B2SeparationFunction_obj> ,sStaticFields,sMemberFields,
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

void B2SeparationFunction_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
