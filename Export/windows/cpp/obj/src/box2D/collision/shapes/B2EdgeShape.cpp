#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#include <box2D/collision/shapes/B2EdgeShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace collision{
namespace shapes{

Void B2EdgeShape_obj::__construct(::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2)
{
HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","new",0x3e45fdf7,"box2D.collision.shapes.B2EdgeShape.new","box2D/collision/shapes/B2EdgeShape.hx",343,0x6bc8ae98)
HX_STACK_THIS(this)
HX_STACK_ARG(v1,"v1")
HX_STACK_ARG(v2,"v2")
{
	HX_STACK_LINE(344)
	super::__construct();
	HX_STACK_LINE(346)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(346)
	this->s_supportVec = _g;
	HX_STACK_LINE(347)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(347)
	this->m_v1 = _g1;
	HX_STACK_LINE(348)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(348)
	this->m_v2 = _g2;
	HX_STACK_LINE(350)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(350)
	this->m_coreV1 = _g3;
	HX_STACK_LINE(351)
	::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(351)
	this->m_coreV2 = _g4;
	HX_STACK_LINE(353)
	::box2D::common::math::B2Vec2 _g5 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(353)
	this->m_normal = _g5;
	HX_STACK_LINE(355)
	::box2D::common::math::B2Vec2 _g6 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(355)
	this->m_direction = _g6;
	HX_STACK_LINE(357)
	::box2D::common::math::B2Vec2 _g7 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(357)
	this->m_cornerDir1 = _g7;
	HX_STACK_LINE(359)
	::box2D::common::math::B2Vec2 _g8 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(359)
	this->m_cornerDir2 = _g8;
	HX_STACK_LINE(361)
	this->m_type = (int)3;
	HX_STACK_LINE(363)
	this->m_prevEdge = null();
	HX_STACK_LINE(364)
	this->m_nextEdge = null();
	HX_STACK_LINE(366)
	this->m_v1 = v1;
	HX_STACK_LINE(367)
	this->m_v2 = v2;
	HX_STACK_LINE(369)
	this->m_direction->set((this->m_v2->x - this->m_v1->x),(this->m_v2->y - this->m_v1->y));
	HX_STACK_LINE(370)
	Float _g9 = this->m_direction->normalize();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(370)
	this->m_length = _g9;
	HX_STACK_LINE(371)
	this->m_normal->set(this->m_direction->y,-(this->m_direction->x));
	HX_STACK_LINE(373)
	this->m_coreV1->set(((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->x - this->m_direction->x))) + this->m_v1->x),((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->y - this->m_direction->y))) + this->m_v1->y));
	HX_STACK_LINE(375)
	this->m_coreV2->set(((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->x + this->m_direction->x))) + this->m_v2->x),((-(::box2D::common::B2Settings_obj::b2_toiSlop) * ((this->m_normal->y + this->m_direction->y))) + this->m_v2->y));
	HX_STACK_LINE(378)
	this->m_cornerDir1 = this->m_normal;
	HX_STACK_LINE(379)
	this->m_cornerDir2->set(-(this->m_normal->x),-(this->m_normal->y));
}
;
	return null();
}

//B2EdgeShape_obj::~B2EdgeShape_obj() { }

Dynamic B2EdgeShape_obj::__CreateEmpty() { return  new B2EdgeShape_obj; }
hx::ObjectPtr< B2EdgeShape_obj > B2EdgeShape_obj::__new(::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2)
{  hx::ObjectPtr< B2EdgeShape_obj > result = new B2EdgeShape_obj();
	result->__construct(v1,v2);
	return result;}

Dynamic B2EdgeShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2EdgeShape_obj > result = new B2EdgeShape_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool B2EdgeShape_obj::testPoint( ::box2D::common::math::B2Transform transform,::box2D::common::math::B2Vec2 p){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","testPoint",0x9c0ceb75,"box2D.collision.shapes.B2EdgeShape.testPoint","box2D/collision/shapes/B2EdgeShape.hx",43,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_ARG(transform,"transform")
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(43)
	return false;
}


bool B2EdgeShape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","rayCast",0x3dcaa2e0,"box2D.collision.shapes.B2EdgeShape.rayCast","box2D/collision/shapes/B2EdgeShape.hx",50,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(input,"input")
	HX_STACK_ARG(transform,"transform")
	HX_STACK_LINE(51)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(52)
	Float rX = (input->p2->x - input->p1->x);		HX_STACK_VAR(rX,"rX");
	HX_STACK_LINE(53)
	Float rY = (input->p2->y - input->p1->y);		HX_STACK_VAR(rY,"rY");
	HX_STACK_LINE(56)
	tMat = transform->R;
	HX_STACK_LINE(57)
	Float v1X = (transform->position->x + (((tMat->col1->x * this->m_v1->x) + (tMat->col2->x * this->m_v1->y))));		HX_STACK_VAR(v1X,"v1X");
	HX_STACK_LINE(58)
	Float v1Y = (transform->position->y + (((tMat->col1->y * this->m_v1->x) + (tMat->col2->y * this->m_v1->y))));		HX_STACK_VAR(v1Y,"v1Y");
	HX_STACK_LINE(61)
	Float nX = ((transform->position->y + (((tMat->col1->y * this->m_v2->x) + (tMat->col2->y * this->m_v2->y)))) - v1Y);		HX_STACK_VAR(nX,"nX");
	HX_STACK_LINE(62)
	Float nY = -((((transform->position->x + (((tMat->col1->x * this->m_v2->x) + (tMat->col2->x * this->m_v2->y)))) - v1X)));		HX_STACK_VAR(nY,"nY");
	HX_STACK_LINE(64)
	Float k_slop = 2.2250738585072014e-306;		HX_STACK_VAR(k_slop,"k_slop");
	HX_STACK_LINE(65)
	Float denom = -((((rX * nX) + (rY * nY))));		HX_STACK_VAR(denom,"denom");
	HX_STACK_LINE(68)
	if (((denom > k_slop))){
		HX_STACK_LINE(71)
		Float bX = (input->p1->x - v1X);		HX_STACK_VAR(bX,"bX");
		HX_STACK_LINE(72)
		Float bY = (input->p1->y - v1Y);		HX_STACK_VAR(bY,"bY");
		HX_STACK_LINE(73)
		Float a = ((bX * nX) + (bY * nY));		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(75)
		if (((bool((0.0 <= a)) && bool((a <= (input->maxFraction * denom)))))){
			HX_STACK_LINE(77)
			Float mu2 = ((-(rX) * bY) + (rY * bX));		HX_STACK_VAR(mu2,"mu2");
			HX_STACK_LINE(80)
			if (((bool(((-(k_slop) * denom) <= mu2)) && bool((mu2 <= (denom * ((1.0 + k_slop)))))))){
				HX_STACK_LINE(82)
				hx::DivEq(a,denom);
				HX_STACK_LINE(83)
				output->fraction = a;
				HX_STACK_LINE(84)
				Float nLen = ::Math_obj::sqrt(((nX * nX) + (nY * nY)));		HX_STACK_VAR(nLen,"nLen");
				HX_STACK_LINE(85)
				output->normal->x = (Float(nX) / Float(nLen));
				HX_STACK_LINE(86)
				output->normal->y = (Float(nY) / Float(nLen));
				HX_STACK_LINE(87)
				return true;
			}
		}
	}
	HX_STACK_LINE(92)
	return false;
}


Void B2EdgeShape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform transform){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","computeAABB",0x1e4b562e,"box2D.collision.shapes.B2EdgeShape.computeAABB","box2D/collision/shapes/B2EdgeShape.hx",98,0x6bc8ae98)
		HX_STACK_THIS(this)
		HX_STACK_ARG(aabb,"aabb")
		HX_STACK_ARG(transform,"transform")
		HX_STACK_LINE(99)
		::box2D::common::math::B2Mat22 tMat = transform->R;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(101)
		Float v1X = (transform->position->x + (((tMat->col1->x * this->m_v1->x) + (tMat->col2->x * this->m_v1->y))));		HX_STACK_VAR(v1X,"v1X");
		HX_STACK_LINE(102)
		Float v1Y = (transform->position->y + (((tMat->col1->y * this->m_v1->x) + (tMat->col2->y * this->m_v1->y))));		HX_STACK_VAR(v1Y,"v1Y");
		HX_STACK_LINE(104)
		Float v2X = (transform->position->x + (((tMat->col1->x * this->m_v2->x) + (tMat->col2->x * this->m_v2->y))));		HX_STACK_VAR(v2X,"v2X");
		HX_STACK_LINE(105)
		Float v2Y = (transform->position->y + (((tMat->col1->y * this->m_v2->x) + (tMat->col2->y * this->m_v2->y))));		HX_STACK_VAR(v2Y,"v2Y");
		HX_STACK_LINE(106)
		if (((v1X < v2X))){
			HX_STACK_LINE(107)
			aabb->lowerBound->x = v1X;
			HX_STACK_LINE(108)
			aabb->upperBound->x = v2X;
		}
		else{
			HX_STACK_LINE(110)
			aabb->lowerBound->x = v2X;
			HX_STACK_LINE(111)
			aabb->upperBound->x = v1X;
		}
		HX_STACK_LINE(113)
		if (((v1Y < v2Y))){
			HX_STACK_LINE(114)
			aabb->lowerBound->y = v1Y;
			HX_STACK_LINE(115)
			aabb->upperBound->y = v2Y;
		}
		else{
			HX_STACK_LINE(117)
			aabb->lowerBound->y = v2Y;
			HX_STACK_LINE(118)
			aabb->upperBound->y = v1Y;
		}
	}
return null();
}


Void B2EdgeShape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,Float density){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","computeMass",0x265258a2,"box2D.collision.shapes.B2EdgeShape.computeMass","box2D/collision/shapes/B2EdgeShape.hx",125,0x6bc8ae98)
		HX_STACK_THIS(this)
		HX_STACK_ARG(massData,"massData")
		HX_STACK_ARG(density,"density")
		HX_STACK_LINE(126)
		massData->mass = (int)0;
		HX_STACK_LINE(127)
		massData->center->setV(this->m_v1);
		HX_STACK_LINE(128)
		massData->I = (int)0;
	}
return null();
}


Float B2EdgeShape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,Float offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","computeSubmergedArea",0x0af9486b,"box2D.collision.shapes.B2EdgeShape.computeSubmergedArea","box2D/collision/shapes/B2EdgeShape.hx",139,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_ARG(normal,"normal")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(xf,"xf")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(143)
	::box2D::common::math::B2Vec2 v0 = ::box2D::common::math::B2Vec2_obj::__new((normal->x * offset),(normal->y * offset));		HX_STACK_VAR(v0,"v0");
	HX_STACK_LINE(145)
	::box2D::common::math::B2Vec2 v1 = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_v1);		HX_STACK_VAR(v1,"v1");
	HX_STACK_LINE(146)
	::box2D::common::math::B2Vec2 v2 = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_v2);		HX_STACK_VAR(v2,"v2");
	HX_STACK_LINE(148)
	Float _g = ::box2D::common::math::B2Math_obj::dot(normal,v1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(148)
	Float d1 = (_g - offset);		HX_STACK_VAR(d1,"d1");
	HX_STACK_LINE(149)
	Float _g1 = ::box2D::common::math::B2Math_obj::dot(normal,v2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(149)
	Float d2 = (_g1 - offset);		HX_STACK_VAR(d2,"d2");
	HX_STACK_LINE(150)
	if (((d1 > (int)0))){
		HX_STACK_LINE(152)
		if (((d2 > (int)0))){
			HX_STACK_LINE(154)
			return (int)0;
		}
		else{
			HX_STACK_LINE(159)
			v1->x = (((Float(-(d2)) / Float(((d1 - d2)))) * v1->x) + ((Float(d1) / Float(((d1 - d2)))) * v2->x));
			HX_STACK_LINE(160)
			v1->y = (((Float(-(d2)) / Float(((d1 - d2)))) * v1->y) + ((Float(d1) / Float(((d1 - d2)))) * v2->y));
		}
	}
	else{
		HX_STACK_LINE(165)
		if (((d2 > (int)0))){
			HX_STACK_LINE(168)
			v2->x = (((Float(-(d2)) / Float(((d1 - d2)))) * v1->x) + ((Float(d1) / Float(((d1 - d2)))) * v2->x));
			HX_STACK_LINE(169)
			v2->y = (((Float(-(d2)) / Float(((d1 - d2)))) * v1->y) + ((Float(d1) / Float(((d1 - d2)))) * v2->y));
		}
		else{
		}
	}
	HX_STACK_LINE(178)
	c->x = (Float((((v0->x + v1->x) + v2->x))) / Float((int)3));
	HX_STACK_LINE(179)
	c->y = (Float((((v0->y + v1->y) + v2->y))) / Float((int)3));
	HX_STACK_LINE(184)
	return (0.5 * (((((v1->x - v0->x)) * ((v2->y - v0->y))) - (((v1->y - v0->y)) * ((v2->x - v0->x))))));
}


Float B2EdgeShape_obj::getLength( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getLength",0x27d916f3,"box2D.collision.shapes.B2EdgeShape.getLength","box2D/collision/shapes/B2EdgeShape.hx",192,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(192)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getLength,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getVertex1( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getVertex1",0xac1865a0,"box2D.collision.shapes.B2EdgeShape.getVertex1","box2D/collision/shapes/B2EdgeShape.hx",200,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(200)
	return this->m_v1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getVertex1,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getVertex2( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getVertex2",0xac1865a1,"box2D.collision.shapes.B2EdgeShape.getVertex2","box2D/collision/shapes/B2EdgeShape.hx",208,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(208)
	return this->m_v2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getVertex2,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCoreVertex1( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getCoreVertex1",0x7ab96f81,"box2D.collision.shapes.B2EdgeShape.getCoreVertex1","box2D/collision/shapes/B2EdgeShape.hx",218,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(218)
	return this->m_coreV1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCoreVertex1,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCoreVertex2( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getCoreVertex2",0x7ab96f82,"box2D.collision.shapes.B2EdgeShape.getCoreVertex2","box2D/collision/shapes/B2EdgeShape.hx",228,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(228)
	return this->m_coreV2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCoreVertex2,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getNormalVector( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getNormalVector",0x14383817,"box2D.collision.shapes.B2EdgeShape.getNormalVector","box2D/collision/shapes/B2EdgeShape.hx",237,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(237)
	return this->m_normal;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getNormalVector,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getDirectionVector( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getDirectionVector",0xe92694b5,"box2D.collision.shapes.B2EdgeShape.getDirectionVector","box2D/collision/shapes/B2EdgeShape.hx",247,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(247)
	return this->m_direction;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getDirectionVector,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCorner1Vector( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getCorner1Vector",0x1a91fe32,"box2D.collision.shapes.B2EdgeShape.getCorner1Vector","box2D/collision/shapes/B2EdgeShape.hx",256,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(256)
	return this->m_cornerDir1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCorner1Vector,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getCorner2Vector( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getCorner2Vector",0x442774f3,"box2D.collision.shapes.B2EdgeShape.getCorner2Vector","box2D/collision/shapes/B2EdgeShape.hx",265,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(265)
	return this->m_cornerDir2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getCorner2Vector,return )

bool B2EdgeShape_obj::corner1IsConvex( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","corner1IsConvex",0x851339e4,"box2D.collision.shapes.B2EdgeShape.corner1IsConvex","box2D/collision/shapes/B2EdgeShape.hx",274,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(274)
	return this->m_cornerConvex1;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,corner1IsConvex,return )

bool B2EdgeShape_obj::corner2IsConvex( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","corner2IsConvex",0x5804a2e5,"box2D.collision.shapes.B2EdgeShape.corner2IsConvex","box2D/collision/shapes/B2EdgeShape.hx",283,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(283)
	return this->m_cornerConvex2;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,corner2IsConvex,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::getFirstVertex( ::box2D::common::math::B2Transform xf){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getFirstVertex",0xff04fa87,"box2D.collision.shapes.B2EdgeShape.getFirstVertex","box2D/collision/shapes/B2EdgeShape.hx",290,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_ARG(xf,"xf")
	HX_STACK_LINE(292)
	::box2D::common::math::B2Mat22 tMat = xf->R;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(293)
	return ::box2D::common::math::B2Vec2_obj::__new((xf->position->x + (((tMat->col1->x * this->m_coreV1->x) + (tMat->col2->x * this->m_coreV1->y)))),(xf->position->y + (((tMat->col1->y * this->m_coreV1->x) + (tMat->col2->y * this->m_coreV1->y)))));
}


HX_DEFINE_DYNAMIC_FUNC1(B2EdgeShape_obj,getFirstVertex,return )

::box2D::collision::shapes::B2EdgeShape B2EdgeShape_obj::getNextEdge( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getNextEdge",0x709b4e1d,"box2D.collision.shapes.B2EdgeShape.getNextEdge","box2D/collision/shapes/B2EdgeShape.hx",302,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(302)
	return this->m_nextEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getNextEdge,return )

::box2D::collision::shapes::B2EdgeShape B2EdgeShape_obj::getPrevEdge( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","getPrevEdge",0x8d9c881d,"box2D.collision.shapes.B2EdgeShape.getPrevEdge","box2D/collision/shapes/B2EdgeShape.hx",310,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_LINE(310)
	return this->m_prevEdge;
}


HX_DEFINE_DYNAMIC_FUNC0(B2EdgeShape_obj,getPrevEdge,return )

::box2D::common::math::B2Vec2 B2EdgeShape_obj::support( ::box2D::common::math::B2Transform xf,Float dX,Float dY){
	HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","support",0x55b15126,"box2D.collision.shapes.B2EdgeShape.support","box2D/collision/shapes/B2EdgeShape.hx",318,0x6bc8ae98)
	HX_STACK_THIS(this)
	HX_STACK_ARG(xf,"xf")
	HX_STACK_ARG(dX,"dX")
	HX_STACK_ARG(dY,"dY")
	HX_STACK_LINE(319)
	::box2D::common::math::B2Mat22 tMat = xf->R;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(321)
	Float v1X = (xf->position->x + (((tMat->col1->x * this->m_coreV1->x) + (tMat->col2->x * this->m_coreV1->y))));		HX_STACK_VAR(v1X,"v1X");
	HX_STACK_LINE(322)
	Float v1Y = (xf->position->y + (((tMat->col1->y * this->m_coreV1->x) + (tMat->col2->y * this->m_coreV1->y))));		HX_STACK_VAR(v1Y,"v1Y");
	HX_STACK_LINE(325)
	Float v2X = (xf->position->x + (((tMat->col1->x * this->m_coreV2->x) + (tMat->col2->x * this->m_coreV2->y))));		HX_STACK_VAR(v2X,"v2X");
	HX_STACK_LINE(326)
	Float v2Y = (xf->position->y + (((tMat->col1->y * this->m_coreV2->x) + (tMat->col2->y * this->m_coreV2->y))));		HX_STACK_VAR(v2Y,"v2Y");
	HX_STACK_LINE(328)
	if (((((v1X * dX) + (v1Y * dY)) > ((v2X * dX) + (v2Y * dY))))){
		HX_STACK_LINE(329)
		this->s_supportVec->x = v1X;
		HX_STACK_LINE(330)
		this->s_supportVec->y = v1Y;
	}
	else{
		HX_STACK_LINE(332)
		this->s_supportVec->x = v2X;
		HX_STACK_LINE(333)
		this->s_supportVec->y = v2Y;
	}
	HX_STACK_LINE(335)
	return this->s_supportVec;
}


HX_DEFINE_DYNAMIC_FUNC3(B2EdgeShape_obj,support,return )

Void B2EdgeShape_obj::setPrevEdge( ::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Vec2 core,::box2D::common::math::B2Vec2 cornerDir,bool convex){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","setPrevEdge",0x98098f29,"box2D.collision.shapes.B2EdgeShape.setPrevEdge","box2D/collision/shapes/B2EdgeShape.hx",386,0x6bc8ae98)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edge,"edge")
		HX_STACK_ARG(core,"core")
		HX_STACK_ARG(cornerDir,"cornerDir")
		HX_STACK_ARG(convex,"convex")
		HX_STACK_LINE(387)
		this->m_prevEdge = edge;
		HX_STACK_LINE(388)
		this->m_coreV1 = core;
		HX_STACK_LINE(389)
		this->m_cornerDir1 = cornerDir;
		HX_STACK_LINE(390)
		this->m_cornerConvex1 = convex;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2EdgeShape_obj,setPrevEdge,(void))

Void B2EdgeShape_obj::setNextEdge( ::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Vec2 core,::box2D::common::math::B2Vec2 cornerDir,bool convex){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2EdgeShape","setNextEdge",0x7b085529,"box2D.collision.shapes.B2EdgeShape.setNextEdge","box2D/collision/shapes/B2EdgeShape.hx",397,0x6bc8ae98)
		HX_STACK_THIS(this)
		HX_STACK_ARG(edge,"edge")
		HX_STACK_ARG(core,"core")
		HX_STACK_ARG(cornerDir,"cornerDir")
		HX_STACK_ARG(convex,"convex")
		HX_STACK_LINE(398)
		this->m_nextEdge = edge;
		HX_STACK_LINE(399)
		this->m_coreV2 = core;
		HX_STACK_LINE(400)
		this->m_cornerDir2 = cornerDir;
		HX_STACK_LINE(401)
		this->m_cornerConvex2 = convex;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2EdgeShape_obj,setNextEdge,(void))


B2EdgeShape_obj::B2EdgeShape_obj()
{
}

void B2EdgeShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2EdgeShape);
	HX_MARK_MEMBER_NAME(s_supportVec,"s_supportVec");
	HX_MARK_MEMBER_NAME(m_v1,"m_v1");
	HX_MARK_MEMBER_NAME(m_v2,"m_v2");
	HX_MARK_MEMBER_NAME(m_coreV1,"m_coreV1");
	HX_MARK_MEMBER_NAME(m_coreV2,"m_coreV2");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(m_normal,"m_normal");
	HX_MARK_MEMBER_NAME(m_direction,"m_direction");
	HX_MARK_MEMBER_NAME(m_cornerDir1,"m_cornerDir1");
	HX_MARK_MEMBER_NAME(m_cornerDir2,"m_cornerDir2");
	HX_MARK_MEMBER_NAME(m_cornerConvex1,"m_cornerConvex1");
	HX_MARK_MEMBER_NAME(m_cornerConvex2,"m_cornerConvex2");
	HX_MARK_MEMBER_NAME(m_nextEdge,"m_nextEdge");
	HX_MARK_MEMBER_NAME(m_prevEdge,"m_prevEdge");
	HX_MARK_END_CLASS();
}

void B2EdgeShape_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(s_supportVec,"s_supportVec");
	HX_VISIT_MEMBER_NAME(m_v1,"m_v1");
	HX_VISIT_MEMBER_NAME(m_v2,"m_v2");
	HX_VISIT_MEMBER_NAME(m_coreV1,"m_coreV1");
	HX_VISIT_MEMBER_NAME(m_coreV2,"m_coreV2");
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	HX_VISIT_MEMBER_NAME(m_normal,"m_normal");
	HX_VISIT_MEMBER_NAME(m_direction,"m_direction");
	HX_VISIT_MEMBER_NAME(m_cornerDir1,"m_cornerDir1");
	HX_VISIT_MEMBER_NAME(m_cornerDir2,"m_cornerDir2");
	HX_VISIT_MEMBER_NAME(m_cornerConvex1,"m_cornerConvex1");
	HX_VISIT_MEMBER_NAME(m_cornerConvex2,"m_cornerConvex2");
	HX_VISIT_MEMBER_NAME(m_nextEdge,"m_nextEdge");
	HX_VISIT_MEMBER_NAME(m_prevEdge,"m_prevEdge");
}

Dynamic B2EdgeShape_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { return m_v1; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { return m_v2; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"support") ) { return support_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_coreV1") ) { return m_coreV1; }
		if (HX_FIELD_EQ(inName,"m_coreV2") ) { return m_coreV2; }
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		if (HX_FIELD_EQ(inName,"m_normal") ) { return m_normal; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getVertex1") ) { return getVertex1_dyn(); }
		if (HX_FIELD_EQ(inName,"getVertex2") ) { return getVertex2_dyn(); }
		if (HX_FIELD_EQ(inName,"m_nextEdge") ) { return m_nextEdge; }
		if (HX_FIELD_EQ(inName,"m_prevEdge") ) { return m_prevEdge; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		if (HX_FIELD_EQ(inName,"getNextEdge") ) { return getNextEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"getPrevEdge") ) { return getPrevEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"setPrevEdge") ) { return setPrevEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"setNextEdge") ) { return setNextEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"m_direction") ) { return m_direction; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_supportVec") ) { return s_supportVec; }
		if (HX_FIELD_EQ(inName,"m_cornerDir1") ) { return m_cornerDir1; }
		if (HX_FIELD_EQ(inName,"m_cornerDir2") ) { return m_cornerDir2; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getCoreVertex1") ) { return getCoreVertex1_dyn(); }
		if (HX_FIELD_EQ(inName,"getCoreVertex2") ) { return getCoreVertex2_dyn(); }
		if (HX_FIELD_EQ(inName,"getFirstVertex") ) { return getFirstVertex_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getNormalVector") ) { return getNormalVector_dyn(); }
		if (HX_FIELD_EQ(inName,"corner1IsConvex") ) { return corner1IsConvex_dyn(); }
		if (HX_FIELD_EQ(inName,"corner2IsConvex") ) { return corner2IsConvex_dyn(); }
		if (HX_FIELD_EQ(inName,"m_cornerConvex1") ) { return m_cornerConvex1; }
		if (HX_FIELD_EQ(inName,"m_cornerConvex2") ) { return m_cornerConvex2; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getCorner1Vector") ) { return getCorner1Vector_dyn(); }
		if (HX_FIELD_EQ(inName,"getCorner2Vector") ) { return getCorner2Vector_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getDirectionVector") ) { return getDirectionVector_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2EdgeShape_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_v1") ) { m_v1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v2") ) { m_v2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_coreV1") ) { m_coreV1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_coreV2") ) { m_coreV2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_normal") ) { m_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_nextEdge") ) { m_nextEdge=inValue.Cast< ::box2D::collision::shapes::B2EdgeShape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_prevEdge") ) { m_prevEdge=inValue.Cast< ::box2D::collision::shapes::B2EdgeShape >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_direction") ) { m_direction=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_supportVec") ) { s_supportVec=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cornerDir1") ) { m_cornerDir1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cornerDir2") ) { m_cornerDir2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_cornerConvex1") ) { m_cornerConvex1=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cornerConvex2") ) { m_cornerConvex2=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2EdgeShape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("s_supportVec"));
	outFields->push(HX_CSTRING("m_v1"));
	outFields->push(HX_CSTRING("m_v2"));
	outFields->push(HX_CSTRING("m_coreV1"));
	outFields->push(HX_CSTRING("m_coreV2"));
	outFields->push(HX_CSTRING("m_length"));
	outFields->push(HX_CSTRING("m_normal"));
	outFields->push(HX_CSTRING("m_direction"));
	outFields->push(HX_CSTRING("m_cornerDir1"));
	outFields->push(HX_CSTRING("m_cornerDir2"));
	outFields->push(HX_CSTRING("m_cornerConvex1"));
	outFields->push(HX_CSTRING("m_cornerConvex2"));
	outFields->push(HX_CSTRING("m_nextEdge"));
	outFields->push(HX_CSTRING("m_prevEdge"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,s_supportVec),HX_CSTRING("s_supportVec")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_v1),HX_CSTRING("m_v1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_v2),HX_CSTRING("m_v2")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_coreV1),HX_CSTRING("m_coreV1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_coreV2),HX_CSTRING("m_coreV2")},
	{hx::fsFloat,(int)offsetof(B2EdgeShape_obj,m_length),HX_CSTRING("m_length")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_normal),HX_CSTRING("m_normal")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_direction),HX_CSTRING("m_direction")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_cornerDir1),HX_CSTRING("m_cornerDir1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2EdgeShape_obj,m_cornerDir2),HX_CSTRING("m_cornerDir2")},
	{hx::fsBool,(int)offsetof(B2EdgeShape_obj,m_cornerConvex1),HX_CSTRING("m_cornerConvex1")},
	{hx::fsBool,(int)offsetof(B2EdgeShape_obj,m_cornerConvex2),HX_CSTRING("m_cornerConvex2")},
	{hx::fsObject /*::box2D::collision::shapes::B2EdgeShape*/ ,(int)offsetof(B2EdgeShape_obj,m_nextEdge),HX_CSTRING("m_nextEdge")},
	{hx::fsObject /*::box2D::collision::shapes::B2EdgeShape*/ ,(int)offsetof(B2EdgeShape_obj,m_prevEdge),HX_CSTRING("m_prevEdge")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("getLength"),
	HX_CSTRING("getVertex1"),
	HX_CSTRING("getVertex2"),
	HX_CSTRING("getCoreVertex1"),
	HX_CSTRING("getCoreVertex2"),
	HX_CSTRING("getNormalVector"),
	HX_CSTRING("getDirectionVector"),
	HX_CSTRING("getCorner1Vector"),
	HX_CSTRING("getCorner2Vector"),
	HX_CSTRING("corner1IsConvex"),
	HX_CSTRING("corner2IsConvex"),
	HX_CSTRING("getFirstVertex"),
	HX_CSTRING("getNextEdge"),
	HX_CSTRING("getPrevEdge"),
	HX_CSTRING("s_supportVec"),
	HX_CSTRING("support"),
	HX_CSTRING("setPrevEdge"),
	HX_CSTRING("setNextEdge"),
	HX_CSTRING("m_v1"),
	HX_CSTRING("m_v2"),
	HX_CSTRING("m_coreV1"),
	HX_CSTRING("m_coreV2"),
	HX_CSTRING("m_length"),
	HX_CSTRING("m_normal"),
	HX_CSTRING("m_direction"),
	HX_CSTRING("m_cornerDir1"),
	HX_CSTRING("m_cornerDir2"),
	HX_CSTRING("m_cornerConvex1"),
	HX_CSTRING("m_cornerConvex2"),
	HX_CSTRING("m_nextEdge"),
	HX_CSTRING("m_prevEdge"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2EdgeShape_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2EdgeShape_obj::__mClass,"__mClass");
};

#endif

Class B2EdgeShape_obj::__mClass;

void B2EdgeShape_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2EdgeShape"), hx::TCanCast< B2EdgeShape_obj> ,sStaticFields,sMemberFields,
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

void B2EdgeShape_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
