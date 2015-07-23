#include <hxcpp.h>

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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Math_obj::__construct()
{
	return null();
}

//B2Math_obj::~B2Math_obj() { }

Dynamic B2Math_obj::__CreateEmpty() { return  new B2Math_obj; }
hx::ObjectPtr< B2Math_obj > B2Math_obj::__new()
{  hx::ObjectPtr< B2Math_obj > result = new B2Math_obj();
	result->__construct();
	return result;}

Dynamic B2Math_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Math_obj > result = new B2Math_obj();
	result->__construct();
	return result;}

bool B2Math_obj::isValid( Float x){
	HX_STACK_FRAME("box2D.common.math.B2Math","isValid",0xc613d730,"box2D.common.math.B2Math.isValid","box2D/common/math/B2Math.hx",35,0x06538f51)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(36)
	if (((  ((!(((  ((!(::Math_obj::isNaN(x)))) ? bool((x == ::Math_obj::NEGATIVE_INFINITY)) : bool(true) ))))) ? bool((x == ::Math_obj::POSITIVE_INFINITY)) : bool(true) ))){
		HX_STACK_LINE(38)
		return false;
	}
	HX_STACK_LINE(42)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,isValid,return )

Float B2Math_obj::dot( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","dot",0xba856a07,"box2D.common.math.B2Math.dot","box2D/common/math/B2Math.hx",63,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(63)
	return ((a->x * b->x) + (a->y * b->y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,dot,return )

Float B2Math_obj::crossVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","crossVV",0xd727493e,"box2D.common.math.B2Math.crossVV","box2D/common/math/B2Math.hx",68,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(68)
	return ((a->x * b->y) - (a->y * b->x));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,crossVV,return )

::box2D::common::math::B2Vec2 B2Math_obj::crossVF( ::box2D::common::math::B2Vec2 a,Float s){
	HX_STACK_FRAME("box2D.common.math.B2Math","crossVF",0xd727492e,"box2D.common.math.B2Math.crossVF","box2D/common/math/B2Math.hx",72,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(73)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((s * a->y),(-(s) * a->x));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(74)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,crossVF,return )

::box2D::common::math::B2Vec2 B2Math_obj::crossFV( Float s,::box2D::common::math::B2Vec2 a){
	HX_STACK_FRAME("box2D.common.math.B2Math","crossFV",0xd7273b4e,"box2D.common.math.B2Math.crossFV","box2D/common/math/B2Math.hx",78,0x06538f51)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(79)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((-(s) * a->y),(s * a->x));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(80)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,crossFV,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v){
	HX_STACK_FRAME("box2D.common.math.B2Math","mulMV",0xa8c5eb6b,"box2D.common.math.B2Math.mulMV","box2D/common/math/B2Math.hx",84,0x06538f51)
	HX_STACK_ARG(A,"A")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(87)
	::box2D::common::math::B2Vec2 u = ::box2D::common::math::B2Vec2_obj::__new(((A->col1->x * v->x) + (A->col2->x * v->y)),((A->col1->y * v->x) + (A->col2->y * v->y)));		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(88)
	return u;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulMV,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulTMV( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Vec2 v){
	HX_STACK_FRAME("box2D.common.math.B2Math","mulTMV",0x046d5a7b,"box2D.common.math.B2Math.mulTMV","box2D/common/math/B2Math.hx",92,0x06538f51)
	HX_STACK_ARG(A,"A")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(95)
	Float _g = ::box2D::common::math::B2Math_obj::dot(v,A->col1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(95)
	Float _g1 = ::box2D::common::math::B2Math_obj::dot(v,A->col2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(95)
	::box2D::common::math::B2Vec2 u = ::box2D::common::math::B2Vec2_obj::__new(_g,_g1);		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(96)
	return u;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulTMV,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulX( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v){
	HX_STACK_FRAME("box2D.common.math.B2Math","mulX",0x802ece96,"box2D.common.math.B2Math.mulX","box2D/common/math/B2Math.hx",100,0x06538f51)
	HX_STACK_ARG(T,"T")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(101)
	::box2D::common::math::B2Vec2 a = ::box2D::common::math::B2Math_obj::mulMV(T->R,v);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(102)
	hx::AddEq(a->x,T->position->x);
	HX_STACK_LINE(103)
	hx::AddEq(a->y,T->position->y);
	HX_STACK_LINE(105)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulX,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulXT( ::box2D::common::math::B2Transform T,::box2D::common::math::B2Vec2 v){
	HX_STACK_FRAME("box2D.common.math.B2Math","mulXT",0xa8c5f4fe,"box2D.common.math.B2Math.mulXT","box2D/common/math/B2Math.hx",109,0x06538f51)
	HX_STACK_ARG(T,"T")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(110)
	::box2D::common::math::B2Vec2 a = ::box2D::common::math::B2Math_obj::subtractVV(v,T->position);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(112)
	Float tX = ((a->x * T->R->col1->x) + (a->y * T->R->col1->y));		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(113)
	a->y = ((a->x * T->R->col2->x) + (a->y * T->R->col2->y));
	HX_STACK_LINE(114)
	a->x = tX;
	HX_STACK_LINE(115)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulXT,return )

::box2D::common::math::B2Vec2 B2Math_obj::addVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","addVV",0xb4b44a9f,"box2D.common.math.B2Math.addVV","box2D/common/math/B2Math.hx",119,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(120)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((a->x + b->x),(a->y + b->y));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(121)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,addVV,return )

::box2D::common::math::B2Vec2 B2Math_obj::subtractVV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","subtractVV",0xfc461196,"box2D.common.math.B2Math.subtractVV","box2D/common/math/B2Math.hx",125,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(126)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((a->x - b->x),(a->y - b->y));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(127)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,subtractVV,return )

Float B2Math_obj::distance( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","distance",0x4f2a82f7,"box2D.common.math.B2Math.distance","box2D/common/math/B2Math.hx",130,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(131)
	Float cX = (a->x - b->x);		HX_STACK_VAR(cX,"cX");
	HX_STACK_LINE(132)
	Float cY = (a->y - b->y);		HX_STACK_VAR(cY,"cY");
	HX_STACK_LINE(133)
	return ::Math_obj::sqrt(((cX * cX) + (cY * cY)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,distance,return )

Float B2Math_obj::distanceSquared( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","distanceSquared",0x5fd58af0,"box2D.common.math.B2Math.distanceSquared","box2D/common/math/B2Math.hx",136,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(137)
	Float cX = (a->x - b->x);		HX_STACK_VAR(cX,"cX");
	HX_STACK_LINE(138)
	Float cY = (a->y - b->y);		HX_STACK_VAR(cY,"cY");
	HX_STACK_LINE(139)
	return ((cX * cX) + (cY * cY));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,distanceSquared,return )

::box2D::common::math::B2Vec2 B2Math_obj::mulFV( Float s,::box2D::common::math::B2Vec2 a){
	HX_STACK_FRAME("box2D.common.math.B2Math","mulFV",0xa8c5e552,"box2D.common.math.B2Math.mulFV","box2D/common/math/B2Math.hx",143,0x06538f51)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(144)
	::box2D::common::math::B2Vec2 v = ::box2D::common::math::B2Vec2_obj::__new((s * a->x),(s * a->y));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(145)
	return v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulFV,return )

::box2D::common::math::B2Mat22 B2Math_obj::addMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B){
	HX_STACK_FRAME("box2D.common.math.B2Math","addMM",0xb4b442bf,"box2D.common.math.B2Math.addMM","box2D/common/math/B2Math.hx",149,0x06538f51)
	HX_STACK_ARG(A,"A")
	HX_STACK_ARG(B,"B")
	HX_STACK_LINE(150)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::addVV(A->col1,B->col1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(150)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Math_obj::addVV(A->col2,B->col2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(150)
	::box2D::common::math::B2Mat22 C = ::box2D::common::math::B2Mat22_obj::fromVV(_g,_g1);		HX_STACK_VAR(C,"C");
	HX_STACK_LINE(151)
	return C;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,addMM,return )

::box2D::common::math::B2Mat22 B2Math_obj::mulMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B){
	HX_STACK_FRAME("box2D.common.math.B2Math","mulMM",0xa8c5eb62,"box2D.common.math.B2Math.mulMM","box2D/common/math/B2Math.hx",156,0x06538f51)
	HX_STACK_ARG(A,"A")
	HX_STACK_ARG(B,"B")
	HX_STACK_LINE(157)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::mulMV(A,B->col1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(157)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Math_obj::mulMV(A,B->col2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(157)
	::box2D::common::math::B2Mat22 C = ::box2D::common::math::B2Mat22_obj::fromVV(_g,_g1);		HX_STACK_VAR(C,"C");
	HX_STACK_LINE(158)
	return C;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulMM,return )

::box2D::common::math::B2Mat22 B2Math_obj::mulTMM( ::box2D::common::math::B2Mat22 A,::box2D::common::math::B2Mat22 B){
	HX_STACK_FRAME("box2D.common.math.B2Math","mulTMM",0x046d5a72,"box2D.common.math.B2Math.mulTMM","box2D/common/math/B2Math.hx",163,0x06538f51)
	HX_STACK_ARG(A,"A")
	HX_STACK_ARG(B,"B")
	HX_STACK_LINE(164)
	Float _g = ::box2D::common::math::B2Math_obj::dot(A->col1,B->col1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(164)
	Float _g1 = ::box2D::common::math::B2Math_obj::dot(A->col2,B->col1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(164)
	::box2D::common::math::B2Vec2 c1 = ::box2D::common::math::B2Vec2_obj::__new(_g,_g1);		HX_STACK_VAR(c1,"c1");
	HX_STACK_LINE(165)
	Float _g2 = ::box2D::common::math::B2Math_obj::dot(A->col1,B->col2);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(165)
	Float _g3 = ::box2D::common::math::B2Math_obj::dot(A->col2,B->col2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(165)
	::box2D::common::math::B2Vec2 c2 = ::box2D::common::math::B2Vec2_obj::__new(_g2,_g3);		HX_STACK_VAR(c2,"c2");
	HX_STACK_LINE(166)
	::box2D::common::math::B2Mat22 C = ::box2D::common::math::B2Mat22_obj::fromVV(c1,c2);		HX_STACK_VAR(C,"C");
	HX_STACK_LINE(167)
	return C;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,mulTMM,return )

Float B2Math_obj::abs( Float a){
	HX_STACK_FRAME("box2D.common.math.B2Math","abs",0xba8317f0,"box2D.common.math.B2Math.abs","box2D/common/math/B2Math.hx",172,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(172)
	if (((a > 0.0))){
		HX_STACK_LINE(172)
		return a;
	}
	else{
		HX_STACK_LINE(172)
		return -(a);
	}
	HX_STACK_LINE(172)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,abs,return )

::box2D::common::math::B2Vec2 B2Math_obj::absV( ::box2D::common::math::B2Vec2 a){
	HX_STACK_FRAME("box2D.common.math.B2Math","absV",0x7831da66,"box2D.common.math.B2Math.absV","box2D/common/math/B2Math.hx",176,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(177)
	Float _g = ::box2D::common::math::B2Math_obj::abs(a->x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(177)
	Float _g1 = ::box2D::common::math::B2Math_obj::abs(a->y);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(177)
	::box2D::common::math::B2Vec2 b = ::box2D::common::math::B2Vec2_obj::__new(_g,_g1);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(178)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,absV,return )

::box2D::common::math::B2Mat22 B2Math_obj::absM( ::box2D::common::math::B2Mat22 A){
	HX_STACK_FRAME("box2D.common.math.B2Math","absM",0x7831da5d,"box2D.common.math.B2Math.absM","box2D/common/math/B2Math.hx",182,0x06538f51)
	HX_STACK_ARG(A,"A")
	HX_STACK_LINE(183)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::absV(A->col1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(183)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Math_obj::absV(A->col2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(183)
	::box2D::common::math::B2Mat22 B = ::box2D::common::math::B2Mat22_obj::fromVV(_g,_g1);		HX_STACK_VAR(B,"B");
	HX_STACK_LINE(184)
	return B;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,absM,return )

Float B2Math_obj::min( Float a,Float b){
	HX_STACK_FRAME("box2D.common.math.B2Math","min",0xba8c3910,"box2D.common.math.B2Math.min","box2D/common/math/B2Math.hx",189,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(189)
	if (((a < b))){
		HX_STACK_LINE(189)
		return a;
	}
	else{
		HX_STACK_LINE(189)
		return b;
	}
	HX_STACK_LINE(189)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,min,return )

::box2D::common::math::B2Vec2 B2Math_obj::minV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","minV",0x8025b546,"box2D.common.math.B2Math.minV","box2D/common/math/B2Math.hx",193,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(194)
	Float _g = ::box2D::common::math::B2Math_obj::min(a->x,b->x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(194)
	Float _g1 = ::box2D::common::math::B2Math_obj::min(a->y,b->y);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(194)
	::box2D::common::math::B2Vec2 c = ::box2D::common::math::B2Vec2_obj::__new(_g,_g1);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(195)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,minV,return )

Float B2Math_obj::max( Float a,Float b){
	HX_STACK_FRAME("box2D.common.math.B2Math","max",0xba8c3222,"box2D.common.math.B2Math.max","box2D/common/math/B2Math.hx",200,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(200)
	if (((a > b))){
		HX_STACK_LINE(200)
		return a;
	}
	else{
		HX_STACK_LINE(200)
		return b;
	}
	HX_STACK_LINE(200)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,max,return )

::box2D::common::math::B2Vec2 B2Math_obj::maxV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 b){
	HX_STACK_FRAME("box2D.common.math.B2Math","maxV",0x801fabf4,"box2D.common.math.B2Math.maxV","box2D/common/math/B2Math.hx",204,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(205)
	Float _g = ::box2D::common::math::B2Math_obj::max(a->x,b->x);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(205)
	Float _g1 = ::box2D::common::math::B2Math_obj::max(a->y,b->y);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(205)
	::box2D::common::math::B2Vec2 c = ::box2D::common::math::B2Vec2_obj::__new(_g,_g1);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(206)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,maxV,return )

Float B2Math_obj::clamp( Float a,Float low,Float high){
	HX_STACK_FRAME("box2D.common.math.B2Math","clamp",0xe0c8f5f9,"box2D.common.math.B2Math.clamp","box2D/common/math/B2Math.hx",211,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(low,"low")
	HX_STACK_ARG(high,"high")
	HX_STACK_LINE(211)
	if (((a < low))){
		HX_STACK_LINE(211)
		return low;
	}
	else{
		HX_STACK_LINE(211)
		if (((a > high))){
			HX_STACK_LINE(211)
			return high;
		}
		else{
			HX_STACK_LINE(211)
			return a;
		}
	}
	HX_STACK_LINE(211)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(B2Math_obj,clamp,return )

::box2D::common::math::B2Vec2 B2Math_obj::clampV( ::box2D::common::math::B2Vec2 a,::box2D::common::math::B2Vec2 low,::box2D::common::math::B2Vec2 high){
	HX_STACK_FRAME("box2D.common.math.B2Math","clampV",0xcf0e443d,"box2D.common.math.B2Math.clampV","box2D/common/math/B2Math.hx",215,0x06538f51)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(low,"low")
	HX_STACK_ARG(high,"high")
	HX_STACK_LINE(216)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::minV(a,high);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(216)
	return ::box2D::common::math::B2Math_obj::maxV(low,_g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(B2Math_obj,clampV,return )

Void B2Math_obj::swap( Dynamic a,Dynamic b){
{
		HX_STACK_FRAME("box2D.common.math.B2Math","swap",0x84279155,"box2D.common.math.B2Math.swap","box2D/common/math/B2Math.hx",220,0x06538f51)
		HX_STACK_ARG(a,"a")
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(221)
		Dynamic tmp = a->__GetItem((int)0);		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(222)
		hx::IndexRef((a).mPtr,(int)0) = b->__GetItem((int)0);
		HX_STACK_LINE(223)
		hx::IndexRef((b).mPtr,(int)0) = tmp;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,swap,(void))

Float B2Math_obj::random( ){
	HX_STACK_FRAME("box2D.common.math.B2Math","random",0x81913d45,"box2D.common.math.B2Math.random","box2D/common/math/B2Math.hx",228,0x06538f51)
	HX_STACK_LINE(229)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(229)
	Float _g1 = (_g * (int)2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(229)
	return (_g1 - (int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(B2Math_obj,random,return )

Float B2Math_obj::randomRange( Float lo,Float hi){
	HX_STACK_FRAME("box2D.common.math.B2Math","randomRange",0x03be9e38,"box2D.common.math.B2Math.randomRange","box2D/common/math/B2Math.hx",233,0x06538f51)
	HX_STACK_ARG(lo,"lo")
	HX_STACK_ARG(hi,"hi")
	HX_STACK_LINE(234)
	Float r = ::Math_obj::random();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(235)
	r = ((((hi - lo)) * r) + lo);
	HX_STACK_LINE(236)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Math_obj,randomRange,return )

int B2Math_obj::nextPowerOfTwo( int x){
	HX_STACK_FRAME("box2D.common.math.B2Math","nextPowerOfTwo",0xb7a14285,"box2D.common.math.B2Math.nextPowerOfTwo","box2D/common/math/B2Math.hx",245,0x06538f51)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(246)
	hx::OrEq(x,(int((int(x) >> int((int)1))) & int((int)2147483647)));
	HX_STACK_LINE(247)
	hx::OrEq(x,(int((int(x) >> int((int)2))) & int((int)1073741823)));
	HX_STACK_LINE(248)
	hx::OrEq(x,(int((int(x) >> int((int)4))) & int((int)268435455)));
	HX_STACK_LINE(249)
	hx::OrEq(x,(int((int(x) >> int((int)8))) & int((int)16777215)));
	HX_STACK_LINE(250)
	hx::OrEq(x,(int((int(x) >> int((int)16))) & int((int)65535)));
	HX_STACK_LINE(251)
	return (x + (int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,nextPowerOfTwo,return )

bool B2Math_obj::isPowerOfTwo( int x){
	HX_STACK_FRAME("box2D.common.math.B2Math","isPowerOfTwo",0x705edfbc,"box2D.common.math.B2Math.isPowerOfTwo","box2D/common/math/B2Math.hx",255,0x06538f51)
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(256)
	bool result = (bool((x > (int)0)) && bool((((int(x) & int((x - (int)1)))) == (int)0)));		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(257)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Math_obj,isPowerOfTwo,return )

::box2D::common::math::B2Vec2 B2Math_obj::b2Vec2_zero;

::box2D::common::math::B2Mat22 B2Math_obj::b2Mat22_identity;

::box2D::common::math::B2Transform B2Math_obj::b2Transform_identity;

Float B2Math_obj::MIN_VALUE;

Float B2Math_obj::MAX_VALUE;

Float B2Math_obj::get_MIN_VALUE( ){
	HX_STACK_FRAME("box2D.common.math.B2Math","get_MIN_VALUE",0x45c3d259,"box2D.common.math.B2Math.get_MIN_VALUE","box2D/common/math/B2Math.hx",293,0x06538f51)
	HX_STACK_LINE(293)
	return 2.2250738585072014e-308;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(B2Math_obj,get_MIN_VALUE,return )

Float B2Math_obj::get_MAX_VALUE( ){
	HX_STACK_FRAME("box2D.common.math.B2Math","get_MAX_VALUE",0x1c06e4eb,"box2D.common.math.B2Math.get_MAX_VALUE","box2D/common/math/B2Math.hx",312,0x06538f51)
	HX_STACK_LINE(312)
	return 1.7976931348623158e+308;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(B2Math_obj,get_MAX_VALUE,return )


B2Math_obj::B2Math_obj()
{
}

Dynamic B2Math_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"dot") ) { return dot_dyn(); }
		if (HX_FIELD_EQ(inName,"abs") ) { return abs_dyn(); }
		if (HX_FIELD_EQ(inName,"min") ) { return min_dyn(); }
		if (HX_FIELD_EQ(inName,"max") ) { return max_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mulX") ) { return mulX_dyn(); }
		if (HX_FIELD_EQ(inName,"absV") ) { return absV_dyn(); }
		if (HX_FIELD_EQ(inName,"absM") ) { return absM_dyn(); }
		if (HX_FIELD_EQ(inName,"minV") ) { return minV_dyn(); }
		if (HX_FIELD_EQ(inName,"maxV") ) { return maxV_dyn(); }
		if (HX_FIELD_EQ(inName,"swap") ) { return swap_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mulMV") ) { return mulMV_dyn(); }
		if (HX_FIELD_EQ(inName,"mulXT") ) { return mulXT_dyn(); }
		if (HX_FIELD_EQ(inName,"addVV") ) { return addVV_dyn(); }
		if (HX_FIELD_EQ(inName,"mulFV") ) { return mulFV_dyn(); }
		if (HX_FIELD_EQ(inName,"addMM") ) { return addMM_dyn(); }
		if (HX_FIELD_EQ(inName,"mulMM") ) { return mulMM_dyn(); }
		if (HX_FIELD_EQ(inName,"clamp") ) { return clamp_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mulTMV") ) { return mulTMV_dyn(); }
		if (HX_FIELD_EQ(inName,"mulTMM") ) { return mulTMM_dyn(); }
		if (HX_FIELD_EQ(inName,"clampV") ) { return clampV_dyn(); }
		if (HX_FIELD_EQ(inName,"random") ) { return random_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		if (HX_FIELD_EQ(inName,"crossVV") ) { return crossVV_dyn(); }
		if (HX_FIELD_EQ(inName,"crossVF") ) { return crossVF_dyn(); }
		if (HX_FIELD_EQ(inName,"crossFV") ) { return crossFV_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"distance") ) { return distance_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MIN_VALUE") ) { return inCallProp ? get_MIN_VALUE() : MIN_VALUE; }
		if (HX_FIELD_EQ(inName,"MAX_VALUE") ) { return inCallProp ? get_MAX_VALUE() : MAX_VALUE; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"subtractVV") ) { return subtractVV_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"randomRange") ) { return randomRange_dyn(); }
		if (HX_FIELD_EQ(inName,"b2Vec2_zero") ) { return b2Vec2_zero; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isPowerOfTwo") ) { return isPowerOfTwo_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_MIN_VALUE") ) { return get_MIN_VALUE_dyn(); }
		if (HX_FIELD_EQ(inName,"get_MAX_VALUE") ) { return get_MAX_VALUE_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"nextPowerOfTwo") ) { return nextPowerOfTwo_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"distanceSquared") ) { return distanceSquared_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2Mat22_identity") ) { return b2Mat22_identity; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2Transform_identity") ) { return b2Transform_identity; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Math_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"MIN_VALUE") ) { MIN_VALUE=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MAX_VALUE") ) { MAX_VALUE=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"b2Vec2_zero") ) { b2Vec2_zero=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"b2Mat22_identity") ) { b2Mat22_identity=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2Transform_identity") ) { b2Transform_identity=inValue.Cast< ::box2D::common::math::B2Transform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Math_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isValid"),
	HX_CSTRING("dot"),
	HX_CSTRING("crossVV"),
	HX_CSTRING("crossVF"),
	HX_CSTRING("crossFV"),
	HX_CSTRING("mulMV"),
	HX_CSTRING("mulTMV"),
	HX_CSTRING("mulX"),
	HX_CSTRING("mulXT"),
	HX_CSTRING("addVV"),
	HX_CSTRING("subtractVV"),
	HX_CSTRING("distance"),
	HX_CSTRING("distanceSquared"),
	HX_CSTRING("mulFV"),
	HX_CSTRING("addMM"),
	HX_CSTRING("mulMM"),
	HX_CSTRING("mulTMM"),
	HX_CSTRING("abs"),
	HX_CSTRING("absV"),
	HX_CSTRING("absM"),
	HX_CSTRING("min"),
	HX_CSTRING("minV"),
	HX_CSTRING("max"),
	HX_CSTRING("maxV"),
	HX_CSTRING("clamp"),
	HX_CSTRING("clampV"),
	HX_CSTRING("swap"),
	HX_CSTRING("random"),
	HX_CSTRING("randomRange"),
	HX_CSTRING("nextPowerOfTwo"),
	HX_CSTRING("isPowerOfTwo"),
	HX_CSTRING("b2Vec2_zero"),
	HX_CSTRING("b2Mat22_identity"),
	HX_CSTRING("b2Transform_identity"),
	HX_CSTRING("MIN_VALUE"),
	HX_CSTRING("MAX_VALUE"),
	HX_CSTRING("get_MIN_VALUE"),
	HX_CSTRING("get_MAX_VALUE"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Math_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Math_obj::b2Vec2_zero,"b2Vec2_zero");
	HX_MARK_MEMBER_NAME(B2Math_obj::b2Mat22_identity,"b2Mat22_identity");
	HX_MARK_MEMBER_NAME(B2Math_obj::b2Transform_identity,"b2Transform_identity");
	HX_MARK_MEMBER_NAME(B2Math_obj::MIN_VALUE,"MIN_VALUE");
	HX_MARK_MEMBER_NAME(B2Math_obj::MAX_VALUE,"MAX_VALUE");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Math_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Math_obj::b2Vec2_zero,"b2Vec2_zero");
	HX_VISIT_MEMBER_NAME(B2Math_obj::b2Mat22_identity,"b2Mat22_identity");
	HX_VISIT_MEMBER_NAME(B2Math_obj::b2Transform_identity,"b2Transform_identity");
	HX_VISIT_MEMBER_NAME(B2Math_obj::MIN_VALUE,"MIN_VALUE");
	HX_VISIT_MEMBER_NAME(B2Math_obj::MAX_VALUE,"MAX_VALUE");
};

#endif

Class B2Math_obj::__mClass;

void B2Math_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Math"), hx::TCanCast< B2Math_obj> ,sStaticFields,sMemberFields,
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

void B2Math_obj::__boot()
{
	b2Vec2_zero= ::box2D::common::math::B2Vec2_obj::__new(0.0,0.0);
struct _Function_0_1{
	inline static ::box2D::common::math::B2Mat22 Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","box2D/common/math/B2Math.hx",273,0x06538f51)
		{
			HX_STACK_LINE(273)
			::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(1.0,0.0);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(273)
			::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(0.0,1.0);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(273)
			return ::box2D::common::math::B2Mat22_obj::fromVV(_g,_g1);
		}
		return null();
	}
};
	b2Mat22_identity= _Function_0_1::Block();
	b2Transform_identity= ::box2D::common::math::B2Transform_obj::__new(::box2D::common::math::B2Math_obj::b2Vec2_zero,::box2D::common::math::B2Math_obj::b2Mat22_identity);
}

} // end namespace box2D
} // end namespace common
} // end namespace math
