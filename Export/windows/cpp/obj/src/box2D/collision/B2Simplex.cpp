#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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

Void B2Simplex_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2Simplex","new",0x6d491e5b,"box2D.collision.B2Simplex.new","box2D/collision/B2Simplex.hx",28,0x494f6bb7)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(374)
	this->m_count = (int)0;
	HX_STACK_LINE(33)
	::box2D::collision::B2SimplexVertex _g = ::box2D::collision::B2SimplexVertex_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->m_v1 = _g;
	HX_STACK_LINE(34)
	::box2D::collision::B2SimplexVertex _g1 = ::box2D::collision::B2SimplexVertex_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->m_v2 = _g1;
	HX_STACK_LINE(35)
	::box2D::collision::B2SimplexVertex _g2 = ::box2D::collision::B2SimplexVertex_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(35)
	this->m_v3 = _g2;
	HX_STACK_LINE(36)
	Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(36)
	this->m_vertices = _g3;
	HX_STACK_LINE(38)
	this->m_vertices[(int)0] = this->m_v1;
	HX_STACK_LINE(39)
	this->m_vertices[(int)1] = this->m_v2;
	HX_STACK_LINE(40)
	this->m_vertices[(int)2] = this->m_v3;
}
;
	return null();
}

//B2Simplex_obj::~B2Simplex_obj() { }

Dynamic B2Simplex_obj::__CreateEmpty() { return  new B2Simplex_obj; }
hx::ObjectPtr< B2Simplex_obj > B2Simplex_obj::__new()
{  hx::ObjectPtr< B2Simplex_obj > result = new B2Simplex_obj();
	result->__construct();
	return result;}

Dynamic B2Simplex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Simplex_obj > result = new B2Simplex_obj();
	result->__construct();
	return result;}

Void B2Simplex_obj::readCache( ::box2D::collision::B2SimplexCache cache,::box2D::collision::B2DistanceProxy proxyA,::box2D::common::math::B2Transform transformA,::box2D::collision::B2DistanceProxy proxyB,::box2D::common::math::B2Transform transformB){
{
		HX_STACK_FRAME("box2D.collision.B2Simplex","readCache",0xdef46347,"box2D.collision.B2Simplex.readCache","box2D/collision/B2Simplex.hx",46,0x494f6bb7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cache,"cache")
		HX_STACK_ARG(proxyA,"proxyA")
		HX_STACK_ARG(transformA,"transformA")
		HX_STACK_ARG(proxyB,"proxyB")
		HX_STACK_ARG(transformB,"transformB")
		HX_STACK_LINE(47)
		::box2D::common::B2Settings_obj::b2Assert((bool(((int)0 <= cache->count)) && bool((cache->count <= (int)3))));
		HX_STACK_LINE(49)
		::box2D::common::math::B2Vec2 wALocal;		HX_STACK_VAR(wALocal,"wALocal");
		HX_STACK_LINE(50)
		::box2D::common::math::B2Vec2 wBLocal;		HX_STACK_VAR(wBLocal,"wBLocal");
		HX_STACK_LINE(53)
		this->m_count = cache->count;
		HX_STACK_LINE(54)
		Array< ::Dynamic > vertices = this->m_vertices;		HX_STACK_VAR(vertices,"vertices");
		HX_STACK_LINE(55)
		::box2D::collision::B2SimplexVertex v;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(56)
		{
			HX_STACK_LINE(56)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(56)
			int _g = this->m_count;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(56)
			while((true)){
				HX_STACK_LINE(56)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(56)
					break;
				}
				HX_STACK_LINE(56)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(58)
				v = vertices->__get(i).StaticCast< ::box2D::collision::B2SimplexVertex >();
				HX_STACK_LINE(59)
				v->indexA = cache->indexA->__get(i);
				HX_STACK_LINE(60)
				v->indexB = cache->indexB->__get(i);
				HX_STACK_LINE(61)
				::box2D::common::math::B2Vec2 _g2 = proxyA->getVertex(v->indexA);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(61)
				wALocal = _g2;
				HX_STACK_LINE(62)
				::box2D::common::math::B2Vec2 _g11 = proxyB->getVertex(v->indexB);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(62)
				wBLocal = _g11;
				HX_STACK_LINE(63)
				::box2D::common::math::B2Vec2 _g21 = ::box2D::common::math::B2Math_obj::mulX(transformA,wALocal);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(63)
				v->wA = _g21;
				HX_STACK_LINE(64)
				::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::mulX(transformB,wBLocal);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(64)
				v->wB = _g3;
				HX_STACK_LINE(65)
				::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Math_obj::subtractVV(v->wB,v->wA);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(65)
				v->w = _g4;
				HX_STACK_LINE(66)
				v->a = (int)0;
			}
		}
		HX_STACK_LINE(71)
		if (((this->m_count > (int)1))){
			HX_STACK_LINE(73)
			Float metric1 = cache->metric;		HX_STACK_VAR(metric1,"metric1");
			HX_STACK_LINE(74)
			Float metric2 = this->getMetric();		HX_STACK_VAR(metric2,"metric2");
			HX_STACK_LINE(75)
			if (((bool((bool((metric2 < (.5 * metric1))) || bool(((2.0 * metric1) < metric2)))) || bool((metric2 < 2.2250738585072014e-308))))){
				HX_STACK_LINE(78)
				this->m_count = (int)0;
			}
		}
		HX_STACK_LINE(83)
		if (((this->m_count == (int)0))){
			HX_STACK_LINE(85)
			v = vertices->__get((int)0).StaticCast< ::box2D::collision::B2SimplexVertex >();
			HX_STACK_LINE(86)
			v->indexA = (int)0;
			HX_STACK_LINE(87)
			v->indexB = (int)0;
			HX_STACK_LINE(88)
			::box2D::common::math::B2Vec2 _g5 = proxyA->getVertex((int)0);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(88)
			wALocal = _g5;
			HX_STACK_LINE(89)
			::box2D::common::math::B2Vec2 _g6 = proxyB->getVertex((int)0);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(89)
			wBLocal = _g6;
			HX_STACK_LINE(90)
			::box2D::common::math::B2Vec2 _g7 = ::box2D::common::math::B2Math_obj::mulX(transformA,wALocal);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(90)
			v->wA = _g7;
			HX_STACK_LINE(91)
			::box2D::common::math::B2Vec2 _g8 = ::box2D::common::math::B2Math_obj::mulX(transformB,wBLocal);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(91)
			v->wB = _g8;
			HX_STACK_LINE(92)
			::box2D::common::math::B2Vec2 _g9 = ::box2D::common::math::B2Math_obj::subtractVV(v->wB,v->wA);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(92)
			v->w = _g9;
			HX_STACK_LINE(93)
			this->m_count = (int)1;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(B2Simplex_obj,readCache,(void))

Void B2Simplex_obj::writeCache( ::box2D::collision::B2SimplexCache cache){
{
		HX_STACK_FRAME("box2D.collision.B2Simplex","writeCache",0x624acc48,"box2D.collision.B2Simplex.writeCache","box2D/collision/B2Simplex.hx",98,0x494f6bb7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cache,"cache")
		HX_STACK_LINE(99)
		Float _g = this->getMetric();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(99)
		cache->metric = _g;
		HX_STACK_LINE(100)
		int _g1 = ::Std_obj::_int(this->m_count);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(100)
		cache->count = _g1;
		HX_STACK_LINE(101)
		Array< ::Dynamic > vertices = this->m_vertices;		HX_STACK_VAR(vertices,"vertices");
		HX_STACK_LINE(102)
		{
			HX_STACK_LINE(102)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(102)
			int _g2 = this->m_count;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(102)
			while((true)){
				HX_STACK_LINE(102)
				if ((!(((_g11 < _g2))))){
					HX_STACK_LINE(102)
					break;
				}
				HX_STACK_LINE(102)
				int i = (_g11)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(104)
				cache->indexA[i] = ::Std_obj::_int(vertices->__get(i).StaticCast< ::box2D::collision::B2SimplexVertex >()->indexA);
				HX_STACK_LINE(105)
				cache->indexB[i] = ::Std_obj::_int(vertices->__get(i).StaticCast< ::box2D::collision::B2SimplexVertex >()->indexB);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Simplex_obj,writeCache,(void))

::box2D::common::math::B2Vec2 B2Simplex_obj::getSearchDirection( ){
	HX_STACK_FRAME("box2D.collision.B2Simplex","getSearchDirection",0x00f7ba26,"box2D.collision.B2Simplex.getSearchDirection","box2D/collision/B2Simplex.hx",111,0x494f6bb7)
	HX_STACK_THIS(this)
	HX_STACK_LINE(111)
	int _g = this->m_count;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(111)
	switch( (int)(_g)){
		case (int)1: {
			HX_STACK_LINE(114)
			return this->m_v1->w->getNegative();
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(118)
			::box2D::common::math::B2Vec2 e12 = ::box2D::common::math::B2Math_obj::subtractVV(this->m_v2->w,this->m_v1->w);		HX_STACK_VAR(e12,"e12");
			HX_STACK_LINE(119)
			::box2D::common::math::B2Vec2 _g1 = this->m_v1->w->getNegative();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(119)
			Float sgn = ::box2D::common::math::B2Math_obj::crossVV(e12,_g1);		HX_STACK_VAR(sgn,"sgn");
			HX_STACK_LINE(120)
			if (((sgn > 0.0))){
				HX_STACK_LINE(123)
				return ::box2D::common::math::B2Math_obj::crossFV(1.0,e12);
			}
			else{
				HX_STACK_LINE(126)
				return ::box2D::common::math::B2Math_obj::crossVF(e12,1.0);
			}
		}
		;break;
		default: {
			HX_STACK_LINE(130)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_STACK_LINE(131)
			return ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
	HX_STACK_LINE(111)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,getSearchDirection,return )

::box2D::common::math::B2Vec2 B2Simplex_obj::getClosestPoint( ){
	HX_STACK_FRAME("box2D.collision.B2Simplex","getClosestPoint",0xdca15768,"box2D.collision.B2Simplex.getClosestPoint","box2D/collision/B2Simplex.hx",137,0x494f6bb7)
	HX_STACK_THIS(this)
	HX_STACK_LINE(137)
	int _g = this->m_count;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(137)
	switch( (int)(_g)){
		case (int)0: {
			HX_STACK_LINE(140)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_STACK_LINE(141)
			return ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(143)
			return this->m_v1->w;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(145)
			return ::box2D::common::math::B2Vec2_obj::__new(((this->m_v1->a * this->m_v1->w->x) + (this->m_v2->a * this->m_v2->w->x)),((this->m_v1->a * this->m_v1->w->y) + (this->m_v2->a * this->m_v2->w->y)));
		}
		;break;
		default: {
			HX_STACK_LINE(149)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_STACK_LINE(150)
			return ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
	HX_STACK_LINE(137)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,getClosestPoint,return )

Void B2Simplex_obj::getWitnessPoints( ::box2D::common::math::B2Vec2 pA,::box2D::common::math::B2Vec2 pB){
{
		HX_STACK_FRAME("box2D.collision.B2Simplex","getWitnessPoints",0x77a4f36b,"box2D.collision.B2Simplex.getWitnessPoints","box2D/collision/B2Simplex.hx",156,0x494f6bb7)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pA,"pA")
		HX_STACK_ARG(pB,"pB")
		HX_STACK_LINE(156)
		int _g = this->m_count;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(156)
		switch( (int)(_g)){
			case (int)0: {
				HX_STACK_LINE(159)
				::box2D::common::B2Settings_obj::b2Assert(false);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(162)
				pA->setV(this->m_v1->wA);
				HX_STACK_LINE(163)
				pB->setV(this->m_v1->wB);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(166)
				pA->x = ((this->m_v1->a * this->m_v1->wA->x) + (this->m_v2->a * this->m_v2->wA->x));
				HX_STACK_LINE(167)
				pA->y = ((this->m_v1->a * this->m_v1->wA->y) + (this->m_v2->a * this->m_v2->wA->y));
				HX_STACK_LINE(168)
				pB->x = ((this->m_v1->a * this->m_v1->wB->x) + (this->m_v2->a * this->m_v2->wB->x));
				HX_STACK_LINE(169)
				pB->y = ((this->m_v1->a * this->m_v1->wB->y) + (this->m_v2->a * this->m_v2->wB->y));
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(172)
				Float _g1 = pA->x = (((this->m_v1->a * this->m_v1->wA->x) + (this->m_v2->a * this->m_v2->wA->x)) + (this->m_v3->a * this->m_v3->wA->x));		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(172)
				pB->x = _g1;
				HX_STACK_LINE(173)
				Float _g11 = pA->y = (((this->m_v1->a * this->m_v1->wA->y) + (this->m_v2->a * this->m_v2->wA->y)) + (this->m_v3->a * this->m_v3->wA->y));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(173)
				pB->y = _g11;
			}
			;break;
			default: {
				HX_STACK_LINE(176)
				::box2D::common::B2Settings_obj::b2Assert(false);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Simplex_obj,getWitnessPoints,(void))

Float B2Simplex_obj::getMetric( ){
	HX_STACK_FRAME("box2D.collision.B2Simplex","getMetric",0x52b18da1,"box2D.collision.B2Simplex.getMetric","box2D/collision/B2Simplex.hx",183,0x494f6bb7)
	HX_STACK_THIS(this)
	HX_STACK_LINE(183)
	int _g = this->m_count;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(183)
	switch( (int)(_g)){
		case (int)0: {
			HX_STACK_LINE(186)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_STACK_LINE(187)
			return 0.0;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(190)
			return 0.0;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(193)
			return ::box2D::common::math::B2Math_obj::subtractVV(this->m_v1->w,this->m_v2->w)->length();
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(196)
			::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Math_obj::subtractVV(this->m_v2->w,this->m_v1->w);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(196)
			::box2D::common::math::B2Vec2 _g11 = ::box2D::common::math::B2Math_obj::subtractVV(this->m_v3->w,this->m_v1->w);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(196)
			return ::box2D::common::math::B2Math_obj::crossVV(_g1,_g11);
		}
		;break;
		default: {
			HX_STACK_LINE(199)
			::box2D::common::B2Settings_obj::b2Assert(false);
			HX_STACK_LINE(200)
			return 0.0;
		}
	}
	HX_STACK_LINE(183)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,getMetric,return )

Void B2Simplex_obj::solve2( ){
{
		HX_STACK_FRAME("box2D.collision.B2Simplex","solve2",0x11c330b8,"box2D.collision.B2Simplex.solve2","box2D/collision/B2Simplex.hx",228,0x494f6bb7)
		HX_STACK_THIS(this)
		HX_STACK_LINE(229)
		::box2D::common::math::B2Vec2 w1 = this->m_v1->w;		HX_STACK_VAR(w1,"w1");
		HX_STACK_LINE(230)
		::box2D::common::math::B2Vec2 w2 = this->m_v2->w;		HX_STACK_VAR(w2,"w2");
		HX_STACK_LINE(231)
		::box2D::common::math::B2Vec2 e12 = ::box2D::common::math::B2Math_obj::subtractVV(w2,w1);		HX_STACK_VAR(e12,"e12");
		HX_STACK_LINE(234)
		Float d12_2 = -((((w1->x * e12->x) + (w1->y * e12->y))));		HX_STACK_VAR(d12_2,"d12_2");
		HX_STACK_LINE(235)
		if (((d12_2 <= 0.0))){
			HX_STACK_LINE(238)
			this->m_v1->a = 1.0;
			HX_STACK_LINE(239)
			this->m_count = (int)1;
			HX_STACK_LINE(240)
			return null();
		}
		HX_STACK_LINE(244)
		Float d12_1 = ((w2->x * e12->x) + (w2->y * e12->y));		HX_STACK_VAR(d12_1,"d12_1");
		HX_STACK_LINE(245)
		if (((d12_1 <= 0.0))){
			HX_STACK_LINE(248)
			this->m_v2->a = 1.0;
			HX_STACK_LINE(249)
			this->m_count = (int)1;
			HX_STACK_LINE(250)
			this->m_v1->set(this->m_v2);
			HX_STACK_LINE(251)
			return null();
		}
		HX_STACK_LINE(255)
		Float inv_d12 = (Float(1.0) / Float(((d12_1 + d12_2))));		HX_STACK_VAR(inv_d12,"inv_d12");
		HX_STACK_LINE(256)
		this->m_v1->a = (d12_1 * inv_d12);
		HX_STACK_LINE(257)
		this->m_v2->a = (d12_2 * inv_d12);
		HX_STACK_LINE(258)
		this->m_count = (int)2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,solve2,(void))

Void B2Simplex_obj::solve3( ){
{
		HX_STACK_FRAME("box2D.collision.B2Simplex","solve3",0x11c330b9,"box2D.collision.B2Simplex.solve3","box2D/collision/B2Simplex.hx",262,0x494f6bb7)
		HX_STACK_THIS(this)
		HX_STACK_LINE(263)
		::box2D::common::math::B2Vec2 w1 = this->m_v1->w;		HX_STACK_VAR(w1,"w1");
		HX_STACK_LINE(264)
		::box2D::common::math::B2Vec2 w2 = this->m_v2->w;		HX_STACK_VAR(w2,"w2");
		HX_STACK_LINE(265)
		::box2D::common::math::B2Vec2 w3 = this->m_v3->w;		HX_STACK_VAR(w3,"w3");
		HX_STACK_LINE(271)
		::box2D::common::math::B2Vec2 e12 = ::box2D::common::math::B2Math_obj::subtractVV(w2,w1);		HX_STACK_VAR(e12,"e12");
		HX_STACK_LINE(272)
		Float w1e12 = ::box2D::common::math::B2Math_obj::dot(w1,e12);		HX_STACK_VAR(w1e12,"w1e12");
		HX_STACK_LINE(273)
		Float w2e12 = ::box2D::common::math::B2Math_obj::dot(w2,e12);		HX_STACK_VAR(w2e12,"w2e12");
		HX_STACK_LINE(274)
		Float d12_1 = w2e12;		HX_STACK_VAR(d12_1,"d12_1");
		HX_STACK_LINE(275)
		Float d12_2 = -(w1e12);		HX_STACK_VAR(d12_2,"d12_2");
		HX_STACK_LINE(281)
		::box2D::common::math::B2Vec2 e13 = ::box2D::common::math::B2Math_obj::subtractVV(w3,w1);		HX_STACK_VAR(e13,"e13");
		HX_STACK_LINE(282)
		Float w1e13 = ::box2D::common::math::B2Math_obj::dot(w1,e13);		HX_STACK_VAR(w1e13,"w1e13");
		HX_STACK_LINE(283)
		Float w3e13 = ::box2D::common::math::B2Math_obj::dot(w3,e13);		HX_STACK_VAR(w3e13,"w3e13");
		HX_STACK_LINE(284)
		Float d13_1 = w3e13;		HX_STACK_VAR(d13_1,"d13_1");
		HX_STACK_LINE(285)
		Float d13_2 = -(w1e13);		HX_STACK_VAR(d13_2,"d13_2");
		HX_STACK_LINE(291)
		::box2D::common::math::B2Vec2 e23 = ::box2D::common::math::B2Math_obj::subtractVV(w3,w2);		HX_STACK_VAR(e23,"e23");
		HX_STACK_LINE(292)
		Float w2e23 = ::box2D::common::math::B2Math_obj::dot(w2,e23);		HX_STACK_VAR(w2e23,"w2e23");
		HX_STACK_LINE(293)
		Float w3e23 = ::box2D::common::math::B2Math_obj::dot(w3,e23);		HX_STACK_VAR(w3e23,"w3e23");
		HX_STACK_LINE(294)
		Float d23_1 = w3e23;		HX_STACK_VAR(d23_1,"d23_1");
		HX_STACK_LINE(295)
		Float d23_2 = -(w2e23);		HX_STACK_VAR(d23_2,"d23_2");
		HX_STACK_LINE(298)
		Float n123 = ::box2D::common::math::B2Math_obj::crossVV(e12,e13);		HX_STACK_VAR(n123,"n123");
		HX_STACK_LINE(300)
		Float _g = ::box2D::common::math::B2Math_obj::crossVV(w2,w3);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(300)
		Float d123_1 = (n123 * _g);		HX_STACK_VAR(d123_1,"d123_1");
		HX_STACK_LINE(301)
		Float _g1 = ::box2D::common::math::B2Math_obj::crossVV(w3,w1);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(301)
		Float d123_2 = (n123 * _g1);		HX_STACK_VAR(d123_2,"d123_2");
		HX_STACK_LINE(302)
		Float _g2 = ::box2D::common::math::B2Math_obj::crossVV(w1,w2);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(302)
		Float d123_3 = (n123 * _g2);		HX_STACK_VAR(d123_3,"d123_3");
		HX_STACK_LINE(305)
		if (((bool((d12_2 <= 0.0)) && bool((d13_2 <= 0.0))))){
			HX_STACK_LINE(307)
			this->m_v1->a = 1.0;
			HX_STACK_LINE(308)
			this->m_count = (int)1;
			HX_STACK_LINE(309)
			return null();
		}
		HX_STACK_LINE(313)
		if (((bool((bool((d12_1 > 0.0)) && bool((d12_2 > 0.0)))) && bool((d123_3 <= 0.0))))){
			HX_STACK_LINE(315)
			Float inv_d12 = (Float(1.0) / Float(((d12_1 + d12_2))));		HX_STACK_VAR(inv_d12,"inv_d12");
			HX_STACK_LINE(316)
			this->m_v1->a = (d12_1 * inv_d12);
			HX_STACK_LINE(317)
			this->m_v2->a = (d12_2 * inv_d12);
			HX_STACK_LINE(318)
			this->m_count = (int)2;
			HX_STACK_LINE(319)
			return null();
		}
		HX_STACK_LINE(323)
		if (((bool((bool((d13_1 > 0.0)) && bool((d13_2 > 0.0)))) && bool((d123_2 <= 0.0))))){
			HX_STACK_LINE(325)
			Float inv_d13 = (Float(1.0) / Float(((d13_1 + d13_2))));		HX_STACK_VAR(inv_d13,"inv_d13");
			HX_STACK_LINE(326)
			this->m_v1->a = (d13_1 * inv_d13);
			HX_STACK_LINE(327)
			this->m_v3->a = (d13_2 * inv_d13);
			HX_STACK_LINE(328)
			this->m_count = (int)2;
			HX_STACK_LINE(329)
			this->m_v2->set(this->m_v3);
			HX_STACK_LINE(330)
			return null();
		}
		HX_STACK_LINE(334)
		if (((bool((d12_1 <= 0.0)) && bool((d23_2 <= 0.0))))){
			HX_STACK_LINE(336)
			this->m_v2->a = 1.0;
			HX_STACK_LINE(337)
			this->m_count = (int)1;
			HX_STACK_LINE(338)
			this->m_v1->set(this->m_v2);
			HX_STACK_LINE(339)
			return null();
		}
		HX_STACK_LINE(343)
		if (((bool((d13_1 <= 0.0)) && bool((d23_1 <= 0.0))))){
			HX_STACK_LINE(345)
			this->m_v3->a = 1.0;
			HX_STACK_LINE(346)
			this->m_count = (int)1;
			HX_STACK_LINE(347)
			this->m_v1->set(this->m_v3);
			HX_STACK_LINE(348)
			return null();
		}
		HX_STACK_LINE(352)
		if (((bool((bool((d23_1 > 0.0)) && bool((d23_2 > 0.0)))) && bool((d123_1 <= 0.0))))){
			HX_STACK_LINE(354)
			Float inv_d23 = (Float(1.0) / Float(((d23_1 + d23_2))));		HX_STACK_VAR(inv_d23,"inv_d23");
			HX_STACK_LINE(355)
			this->m_v2->a = (d23_1 * inv_d23);
			HX_STACK_LINE(356)
			this->m_v3->a = (d23_2 * inv_d23);
			HX_STACK_LINE(357)
			this->m_count = (int)2;
			HX_STACK_LINE(358)
			this->m_v1->set(this->m_v3);
			HX_STACK_LINE(359)
			return null();
		}
		HX_STACK_LINE(363)
		Float inv_d123 = (Float(1.0) / Float((((d123_1 + d123_2) + d123_3))));		HX_STACK_VAR(inv_d123,"inv_d123");
		HX_STACK_LINE(364)
		this->m_v1->a = (d123_1 * inv_d123);
		HX_STACK_LINE(365)
		this->m_v2->a = (d123_2 * inv_d123);
		HX_STACK_LINE(366)
		this->m_v3->a = (d123_3 * inv_d123);
		HX_STACK_LINE(367)
		this->m_count = (int)3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Simplex_obj,solve3,(void))


B2Simplex_obj::B2Simplex_obj()
{
}

void B2Simplex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Simplex);
	HX_MARK_MEMBER_NAME(m_v1,"m_v1");
	HX_MARK_MEMBER_NAME(m_v2,"m_v2");
	HX_MARK_MEMBER_NAME(m_v3,"m_v3");
	HX_MARK_MEMBER_NAME(m_vertices,"m_vertices");
	HX_MARK_MEMBER_NAME(m_count,"m_count");
	HX_MARK_END_CLASS();
}

void B2Simplex_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_v1,"m_v1");
	HX_VISIT_MEMBER_NAME(m_v2,"m_v2");
	HX_VISIT_MEMBER_NAME(m_v3,"m_v3");
	HX_VISIT_MEMBER_NAME(m_vertices,"m_vertices");
	HX_VISIT_MEMBER_NAME(m_count,"m_count");
}

Dynamic B2Simplex_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { return m_v1; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { return m_v2; }
		if (HX_FIELD_EQ(inName,"m_v3") ) { return m_v3; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"solve2") ) { return solve2_dyn(); }
		if (HX_FIELD_EQ(inName,"solve3") ) { return solve3_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { return m_count; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readCache") ) { return readCache_dyn(); }
		if (HX_FIELD_EQ(inName,"getMetric") ) { return getMetric_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeCache") ) { return writeCache_dyn(); }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { return m_vertices; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getClosestPoint") ) { return getClosestPoint_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getWitnessPoints") ) { return getWitnessPoints_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getSearchDirection") ) { return getSearchDirection_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Simplex_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { m_v1=inValue.Cast< ::box2D::collision::B2SimplexVertex >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { m_v2=inValue.Cast< ::box2D::collision::B2SimplexVertex >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v3") ) { m_v3=inValue.Cast< ::box2D::collision::B2SimplexVertex >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { m_count=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_vertices") ) { m_vertices=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Simplex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_v1"));
	outFields->push(HX_CSTRING("m_v2"));
	outFields->push(HX_CSTRING("m_v3"));
	outFields->push(HX_CSTRING("m_vertices"));
	outFields->push(HX_CSTRING("m_count"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::collision::B2SimplexVertex*/ ,(int)offsetof(B2Simplex_obj,m_v1),HX_CSTRING("m_v1")},
	{hx::fsObject /*::box2D::collision::B2SimplexVertex*/ ,(int)offsetof(B2Simplex_obj,m_v2),HX_CSTRING("m_v2")},
	{hx::fsObject /*::box2D::collision::B2SimplexVertex*/ ,(int)offsetof(B2Simplex_obj,m_v3),HX_CSTRING("m_v3")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2Simplex_obj,m_vertices),HX_CSTRING("m_vertices")},
	{hx::fsInt,(int)offsetof(B2Simplex_obj,m_count),HX_CSTRING("m_count")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("readCache"),
	HX_CSTRING("writeCache"),
	HX_CSTRING("getSearchDirection"),
	HX_CSTRING("getClosestPoint"),
	HX_CSTRING("getWitnessPoints"),
	HX_CSTRING("getMetric"),
	HX_CSTRING("solve2"),
	HX_CSTRING("solve3"),
	HX_CSTRING("m_v1"),
	HX_CSTRING("m_v2"),
	HX_CSTRING("m_v3"),
	HX_CSTRING("m_vertices"),
	HX_CSTRING("m_count"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Simplex_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Simplex_obj::__mClass,"__mClass");
};

#endif

Class B2Simplex_obj::__mClass;

void B2Simplex_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2Simplex"), hx::TCanCast< B2Simplex_obj> ,sStaticFields,sMemberFields,
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

void B2Simplex_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
