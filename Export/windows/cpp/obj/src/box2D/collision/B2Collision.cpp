#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Collision
#include <box2D/collision/B2Collision.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldPoint
#include <box2D/collision/B2ManifoldPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldType
#include <box2D/collision/B2ManifoldType.h>
#endif
#ifndef INCLUDED_box2D_collision_ClipVertex
#include <box2D/collision/ClipVertex.h>
#endif
#ifndef INCLUDED_box2D_collision_Features
#include <box2D/collision/Features.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2PolygonShape
#include <box2D/collision/shapes/B2PolygonShape.h>
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
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2Collision_obj::__construct()
{
	return null();
}

//B2Collision_obj::~B2Collision_obj() { }

Dynamic B2Collision_obj::__CreateEmpty() { return  new B2Collision_obj; }
hx::ObjectPtr< B2Collision_obj > B2Collision_obj::__new()
{  hx::ObjectPtr< B2Collision_obj > result = new B2Collision_obj();
	result->__construct();
	return result;}

Dynamic B2Collision_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Collision_obj > result = new B2Collision_obj();
	result->__construct();
	return result;}

int B2Collision_obj::b2_nullFeature;

int B2Collision_obj::clipSegmentToLine( Array< ::Dynamic > vOut,Array< ::Dynamic > vIn,::box2D::common::math::B2Vec2 normal,Float offset){
	HX_STACK_FRAME("box2D.collision.B2Collision","clipSegmentToLine",0x9c641799,"box2D.collision.B2Collision.clipSegmentToLine","box2D/collision/B2Collision.hx",41,0xb600848b)
	HX_STACK_ARG(vOut,"vOut")
	HX_STACK_ARG(vIn,"vIn")
	HX_STACK_ARG(normal,"normal")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_LINE(42)
	::box2D::collision::ClipVertex cv;		HX_STACK_VAR(cv,"cv");
	HX_STACK_LINE(45)
	int numOut = (int)0;		HX_STACK_VAR(numOut,"numOut");
	HX_STACK_LINE(47)
	cv = vIn->__get((int)0).StaticCast< ::box2D::collision::ClipVertex >();
	HX_STACK_LINE(48)
	::box2D::common::math::B2Vec2 vIn0 = cv->v;		HX_STACK_VAR(vIn0,"vIn0");
	HX_STACK_LINE(49)
	cv = vIn->__get((int)1).StaticCast< ::box2D::collision::ClipVertex >();
	HX_STACK_LINE(50)
	::box2D::common::math::B2Vec2 vIn1 = cv->v;		HX_STACK_VAR(vIn1,"vIn1");
	HX_STACK_LINE(53)
	Float distance0 = (((normal->x * vIn0->x) + (normal->y * vIn0->y)) - offset);		HX_STACK_VAR(distance0,"distance0");
	HX_STACK_LINE(54)
	Float distance1 = (((normal->x * vIn1->x) + (normal->y * vIn1->y)) - offset);		HX_STACK_VAR(distance1,"distance1");
	HX_STACK_LINE(57)
	if (((distance0 <= 0.0))){
		HX_STACK_LINE(57)
		int _g = (numOut)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(57)
		vOut->__get(_g).StaticCast< ::box2D::collision::ClipVertex >()->set(vIn->__get((int)0).StaticCast< ::box2D::collision::ClipVertex >());
	}
	HX_STACK_LINE(58)
	if (((distance1 <= 0.0))){
		HX_STACK_LINE(58)
		int _g1 = (numOut)++;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(58)
		vOut->__get(_g1).StaticCast< ::box2D::collision::ClipVertex >()->set(vIn->__get((int)1).StaticCast< ::box2D::collision::ClipVertex >());
	}
	HX_STACK_LINE(61)
	if ((((distance0 * distance1) < 0.0))){
		HX_STACK_LINE(64)
		Float interp = (Float(distance0) / Float(((distance0 - distance1))));		HX_STACK_VAR(interp,"interp");
		HX_STACK_LINE(67)
		cv = vOut->__get(numOut).StaticCast< ::box2D::collision::ClipVertex >();
		HX_STACK_LINE(68)
		::box2D::common::math::B2Vec2 tVec = cv->v;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(69)
		tVec->x = (vIn0->x + (interp * ((vIn1->x - vIn0->x))));
		HX_STACK_LINE(70)
		tVec->y = (vIn0->y + (interp * ((vIn1->y - vIn0->y))));
		HX_STACK_LINE(71)
		cv = vOut->__get(numOut).StaticCast< ::box2D::collision::ClipVertex >();
		HX_STACK_LINE(72)
		::box2D::collision::ClipVertex cv2;		HX_STACK_VAR(cv2,"cv2");
		HX_STACK_LINE(73)
		if (((distance0 > 0.0))){
			HX_STACK_LINE(75)
			cv2 = vIn->__get((int)0).StaticCast< ::box2D::collision::ClipVertex >();
			HX_STACK_LINE(76)
			cv->id = cv2->id;
		}
		else{
			HX_STACK_LINE(80)
			cv2 = vIn->__get((int)1).StaticCast< ::box2D::collision::ClipVertex >();
			HX_STACK_LINE(81)
			cv->id = cv2->id;
		}
		HX_STACK_LINE(83)
		++(numOut);
	}
	HX_STACK_LINE(86)
	return numOut;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(B2Collision_obj,clipSegmentToLine,return )

Float B2Collision_obj::edgeSeparation( ::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2){
	HX_STACK_FRAME("box2D.collision.B2Collision","edgeSeparation",0x1bcec31c,"box2D.collision.B2Collision.edgeSeparation","box2D/collision/B2Collision.hx",93,0xb600848b)
	HX_STACK_ARG(poly1,"poly1")
	HX_STACK_ARG(xf1,"xf1")
	HX_STACK_ARG(edge1,"edge1")
	HX_STACK_ARG(poly2,"poly2")
	HX_STACK_ARG(xf2,"xf2")
	HX_STACK_LINE(94)
	int count1 = poly1->m_vertexCount;		HX_STACK_VAR(count1,"count1");
	HX_STACK_LINE(95)
	Array< ::Dynamic > vertices1 = poly1->m_vertices;		HX_STACK_VAR(vertices1,"vertices1");
	HX_STACK_LINE(96)
	Array< ::Dynamic > normals1 = poly1->m_normals;		HX_STACK_VAR(normals1,"normals1");
	HX_STACK_LINE(98)
	int count2 = poly2->m_vertexCount;		HX_STACK_VAR(count2,"count2");
	HX_STACK_LINE(99)
	Array< ::Dynamic > vertices2 = poly2->m_vertices;		HX_STACK_VAR(vertices2,"vertices2");
	HX_STACK_LINE(103)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(104)
	::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
	HX_STACK_LINE(108)
	tMat = xf1->R;
	HX_STACK_LINE(109)
	tVec = normals1->__get(edge1).StaticCast< ::box2D::common::math::B2Vec2 >();
	HX_STACK_LINE(110)
	Float normal1WorldX = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));		HX_STACK_VAR(normal1WorldX,"normal1WorldX");
	HX_STACK_LINE(111)
	Float normal1WorldY = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));		HX_STACK_VAR(normal1WorldY,"normal1WorldY");
	HX_STACK_LINE(113)
	tMat = xf2->R;
	HX_STACK_LINE(114)
	Float normal1X = ((tMat->col1->x * normal1WorldX) + (tMat->col1->y * normal1WorldY));		HX_STACK_VAR(normal1X,"normal1X");
	HX_STACK_LINE(115)
	Float normal1Y = ((tMat->col2->x * normal1WorldX) + (tMat->col2->y * normal1WorldY));		HX_STACK_VAR(normal1Y,"normal1Y");
	HX_STACK_LINE(118)
	int index = (int)0;		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(119)
	Float minDot = 1.7976931348623158e+308;		HX_STACK_VAR(minDot,"minDot");
	HX_STACK_LINE(120)
	{
		HX_STACK_LINE(120)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(120)
		while((true)){
			HX_STACK_LINE(120)
			if ((!(((_g < count2))))){
				HX_STACK_LINE(120)
				break;
			}
			HX_STACK_LINE(120)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(123)
			tVec = vertices2->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
			HX_STACK_LINE(124)
			Float dot = ((tVec->x * normal1X) + (tVec->y * normal1Y));		HX_STACK_VAR(dot,"dot");
			HX_STACK_LINE(125)
			if (((dot < minDot))){
				HX_STACK_LINE(127)
				minDot = dot;
				HX_STACK_LINE(128)
				index = i;
			}
		}
	}
	HX_STACK_LINE(133)
	tVec = vertices1->__get(edge1).StaticCast< ::box2D::common::math::B2Vec2 >();
	HX_STACK_LINE(134)
	tMat = xf1->R;
	HX_STACK_LINE(135)
	Float v1X = (xf1->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(v1X,"v1X");
	HX_STACK_LINE(136)
	Float v1Y = (xf1->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(v1Y,"v1Y");
	HX_STACK_LINE(138)
	tVec = vertices2->__get(index).StaticCast< ::box2D::common::math::B2Vec2 >();
	HX_STACK_LINE(139)
	tMat = xf2->R;
	HX_STACK_LINE(140)
	Float v2X = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(v2X,"v2X");
	HX_STACK_LINE(141)
	Float v2Y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(v2Y,"v2Y");
	HX_STACK_LINE(144)
	hx::SubEq(v2X,v1X);
	HX_STACK_LINE(145)
	hx::SubEq(v2Y,v1Y);
	HX_STACK_LINE(147)
	Float separation = ((v2X * normal1WorldX) + (v2Y * normal1WorldY));		HX_STACK_VAR(separation,"separation");
	HX_STACK_LINE(148)
	return separation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,edgeSeparation,return )

Float B2Collision_obj::findMaxSeparation( Array< int > edgeIndex,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2){
	HX_STACK_FRAME("box2D.collision.B2Collision","findMaxSeparation",0x5c03e578,"box2D.collision.B2Collision.findMaxSeparation","box2D/collision/B2Collision.hx",159,0xb600848b)
	HX_STACK_ARG(edgeIndex,"edgeIndex")
	HX_STACK_ARG(poly1,"poly1")
	HX_STACK_ARG(xf1,"xf1")
	HX_STACK_ARG(poly2,"poly2")
	HX_STACK_ARG(xf2,"xf2")
	HX_STACK_LINE(160)
	int count1 = poly1->m_vertexCount;		HX_STACK_VAR(count1,"count1");
	HX_STACK_LINE(161)
	Array< ::Dynamic > normals1 = poly1->m_normals;		HX_STACK_VAR(normals1,"normals1");
	HX_STACK_LINE(163)
	::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
	HX_STACK_LINE(164)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(168)
	tMat = xf2->R;
	HX_STACK_LINE(169)
	tVec = poly2->m_centroid;
	HX_STACK_LINE(170)
	Float dX = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(171)
	Float dY = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(172)
	tMat = xf1->R;
	HX_STACK_LINE(173)
	tVec = poly1->m_centroid;
	HX_STACK_LINE(174)
	hx::SubEq(dX,(xf1->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y)))));
	HX_STACK_LINE(175)
	hx::SubEq(dY,(xf1->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y)))));
	HX_STACK_LINE(178)
	Float dLocal1X = ((dX * xf1->R->col1->x) + (dY * xf1->R->col1->y));		HX_STACK_VAR(dLocal1X,"dLocal1X");
	HX_STACK_LINE(179)
	Float dLocal1Y = ((dX * xf1->R->col2->x) + (dY * xf1->R->col2->y));		HX_STACK_VAR(dLocal1Y,"dLocal1Y");
	HX_STACK_LINE(182)
	int edge = (int)0;		HX_STACK_VAR(edge,"edge");
	HX_STACK_LINE(183)
	Float maxDot = -1.7976931348623157e+308;		HX_STACK_VAR(maxDot,"maxDot");
	HX_STACK_LINE(184)
	{
		HX_STACK_LINE(184)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(184)
		while((true)){
			HX_STACK_LINE(184)
			if ((!(((_g < count1))))){
				HX_STACK_LINE(184)
				break;
			}
			HX_STACK_LINE(184)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(187)
			tVec = normals1->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
			HX_STACK_LINE(188)
			Float dot = ((tVec->x * dLocal1X) + (tVec->y * dLocal1Y));		HX_STACK_VAR(dot,"dot");
			HX_STACK_LINE(189)
			if (((dot > maxDot))){
				HX_STACK_LINE(191)
				maxDot = dot;
				HX_STACK_LINE(192)
				edge = i;
			}
		}
	}
	HX_STACK_LINE(197)
	Float s = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,edge,poly2,xf2);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(200)
	int prevEdge;		HX_STACK_VAR(prevEdge,"prevEdge");
	HX_STACK_LINE(200)
	if ((((edge - (int)1) >= (int)0))){
		HX_STACK_LINE(200)
		prevEdge = (edge - (int)1);
	}
	else{
		HX_STACK_LINE(200)
		prevEdge = (count1 - (int)1);
	}
	HX_STACK_LINE(201)
	Float sPrev = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,prevEdge,poly2,xf2);		HX_STACK_VAR(sPrev,"sPrev");
	HX_STACK_LINE(204)
	int nextEdge;		HX_STACK_VAR(nextEdge,"nextEdge");
	HX_STACK_LINE(204)
	if ((((edge + (int)1) < count1))){
		HX_STACK_LINE(204)
		nextEdge = (edge + (int)1);
	}
	else{
		HX_STACK_LINE(204)
		nextEdge = (int)0;
	}
	HX_STACK_LINE(205)
	Float sNext = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,nextEdge,poly2,xf2);		HX_STACK_VAR(sNext,"sNext");
	HX_STACK_LINE(208)
	int bestEdge;		HX_STACK_VAR(bestEdge,"bestEdge");
	HX_STACK_LINE(209)
	Float bestSeparation;		HX_STACK_VAR(bestSeparation,"bestSeparation");
	HX_STACK_LINE(210)
	int increment;		HX_STACK_VAR(increment,"increment");
	HX_STACK_LINE(211)
	if (((bool((sPrev > s)) && bool((sPrev > sNext))))){
		HX_STACK_LINE(213)
		increment = (int)-1;
		HX_STACK_LINE(214)
		bestEdge = prevEdge;
		HX_STACK_LINE(215)
		bestSeparation = sPrev;
	}
	else{
		HX_STACK_LINE(217)
		if (((sNext > s))){
			HX_STACK_LINE(219)
			increment = (int)1;
			HX_STACK_LINE(220)
			bestEdge = nextEdge;
			HX_STACK_LINE(221)
			bestSeparation = sNext;
		}
		else{
			HX_STACK_LINE(226)
			edgeIndex[(int)0] = edge;
			HX_STACK_LINE(227)
			return s;
		}
	}
	HX_STACK_LINE(231)
	while((true)){
		HX_STACK_LINE(234)
		if (((increment == (int)-1))){
			HX_STACK_LINE(235)
			if ((((bestEdge - (int)1) >= (int)0))){
				HX_STACK_LINE(235)
				edge = (bestEdge - (int)1);
			}
			else{
				HX_STACK_LINE(235)
				edge = (count1 - (int)1);
			}
		}
		else{
			HX_STACK_LINE(237)
			if ((((bestEdge + (int)1) < count1))){
				HX_STACK_LINE(237)
				edge = (bestEdge + (int)1);
			}
			else{
				HX_STACK_LINE(237)
				edge = (int)0;
			}
		}
		HX_STACK_LINE(239)
		Float _g = ::box2D::collision::B2Collision_obj::edgeSeparation(poly1,xf1,edge,poly2,xf2);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(239)
		s = _g;
		HX_STACK_LINE(241)
		if (((s > bestSeparation))){
			HX_STACK_LINE(243)
			bestEdge = edge;
			HX_STACK_LINE(244)
			bestSeparation = s;
		}
		else{
			HX_STACK_LINE(248)
			break;
		}
	}
	HX_STACK_LINE(253)
	edgeIndex[(int)0] = bestEdge;
	HX_STACK_LINE(254)
	return bestSeparation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,findMaxSeparation,return )

Void B2Collision_obj::findIncidentEdge( Array< ::Dynamic > c,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2){
{
		HX_STACK_FRAME("box2D.collision.B2Collision","findIncidentEdge",0x9f9a2501,"box2D.collision.B2Collision.findIncidentEdge","box2D/collision/B2Collision.hx",262,0xb600848b)
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(poly1,"poly1")
		HX_STACK_ARG(xf1,"xf1")
		HX_STACK_ARG(edge1,"edge1")
		HX_STACK_ARG(poly2,"poly2")
		HX_STACK_ARG(xf2,"xf2")
		HX_STACK_LINE(263)
		int count1 = poly1->m_vertexCount;		HX_STACK_VAR(count1,"count1");
		HX_STACK_LINE(264)
		Array< ::Dynamic > normals1 = poly1->m_normals;		HX_STACK_VAR(normals1,"normals1");
		HX_STACK_LINE(266)
		int count2 = poly2->m_vertexCount;		HX_STACK_VAR(count2,"count2");
		HX_STACK_LINE(267)
		Array< ::Dynamic > vertices2 = poly2->m_vertices;		HX_STACK_VAR(vertices2,"vertices2");
		HX_STACK_LINE(268)
		Array< ::Dynamic > normals2 = poly2->m_normals;		HX_STACK_VAR(normals2,"normals2");
		HX_STACK_LINE(272)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(273)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(277)
		tMat = xf1->R;
		HX_STACK_LINE(278)
		tVec = normals1->__get(edge1).StaticCast< ::box2D::common::math::B2Vec2 >();
		HX_STACK_LINE(279)
		Float normal1X = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));		HX_STACK_VAR(normal1X,"normal1X");
		HX_STACK_LINE(280)
		Float normal1Y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));		HX_STACK_VAR(normal1Y,"normal1Y");
		HX_STACK_LINE(281)
		tMat = xf2->R;
		HX_STACK_LINE(282)
		Float tX = ((tMat->col1->x * normal1X) + (tMat->col1->y * normal1Y));		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(283)
		normal1Y = ((tMat->col2->x * normal1X) + (tMat->col2->y * normal1Y));
		HX_STACK_LINE(284)
		normal1X = tX;
		HX_STACK_LINE(287)
		int index = (int)0;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(288)
		Float minDot = 1.7976931348623158e+308;		HX_STACK_VAR(minDot,"minDot");
		HX_STACK_LINE(289)
		{
			HX_STACK_LINE(289)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(289)
			while((true)){
				HX_STACK_LINE(289)
				if ((!(((_g < count2))))){
					HX_STACK_LINE(289)
					break;
				}
				HX_STACK_LINE(289)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(292)
				tVec = normals2->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
				HX_STACK_LINE(293)
				Float dot = ((normal1X * tVec->x) + (normal1Y * tVec->y));		HX_STACK_VAR(dot,"dot");
				HX_STACK_LINE(294)
				if (((dot < minDot))){
					HX_STACK_LINE(296)
					minDot = dot;
					HX_STACK_LINE(297)
					index = i;
				}
			}
		}
		HX_STACK_LINE(301)
		::box2D::collision::ClipVertex tClip;		HX_STACK_VAR(tClip,"tClip");
		HX_STACK_LINE(303)
		int i1 = index;		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(304)
		int i2;		HX_STACK_VAR(i2,"i2");
		HX_STACK_LINE(304)
		if ((((i1 + (int)1) < count2))){
			HX_STACK_LINE(304)
			i2 = (i1 + (int)1);
		}
		else{
			HX_STACK_LINE(304)
			i2 = (int)0;
		}
		HX_STACK_LINE(306)
		tClip = c->__get((int)0).StaticCast< ::box2D::collision::ClipVertex >();
		HX_STACK_LINE(308)
		tVec = vertices2->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >();
		HX_STACK_LINE(309)
		tMat = xf2->R;
		HX_STACK_LINE(310)
		tClip->v->x = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_STACK_LINE(311)
		tClip->v->y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_STACK_LINE(313)
		tClip->id->features->set_referenceEdge(edge1);
		HX_STACK_LINE(314)
		tClip->id->features->set_incidentEdge(i1);
		HX_STACK_LINE(315)
		tClip->id->features->set_incidentVertex((int)0);
		HX_STACK_LINE(317)
		tClip = c->__get((int)1).StaticCast< ::box2D::collision::ClipVertex >();
		HX_STACK_LINE(319)
		tVec = vertices2->__get(i2).StaticCast< ::box2D::common::math::B2Vec2 >();
		HX_STACK_LINE(320)
		tMat = xf2->R;
		HX_STACK_LINE(321)
		tClip->v->x = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));
		HX_STACK_LINE(322)
		tClip->v->y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));
		HX_STACK_LINE(324)
		tClip->id->features->set_referenceEdge(edge1);
		HX_STACK_LINE(325)
		tClip->id->features->set_incidentEdge(i2);
		HX_STACK_LINE(326)
		tClip->id->features->set_incidentVertex((int)1);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(B2Collision_obj,findIncidentEdge,(void))

Array< ::Dynamic > B2Collision_obj::makeClipPointVector( ){
	HX_STACK_FRAME("box2D.collision.B2Collision","makeClipPointVector",0x2990ab1c,"box2D.collision.B2Collision.makeClipPointVector","box2D/collision/B2Collision.hx",331,0xb600848b)
	HX_STACK_LINE(332)
	Array< ::Dynamic > r = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(333)
	r[(int)0] = ::box2D::collision::ClipVertex_obj::__new();
	HX_STACK_LINE(334)
	r[(int)1] = ::box2D::collision::ClipVertex_obj::__new();
	HX_STACK_LINE(335)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(B2Collision_obj,makeClipPointVector,return )

Array< ::Dynamic > B2Collision_obj::s_incidentEdge;

Array< ::Dynamic > B2Collision_obj::s_clipPoints1;

Array< ::Dynamic > B2Collision_obj::s_clipPoints2;

Array< int > B2Collision_obj::s_edgeAO;

Array< int > B2Collision_obj::s_edgeBO;

::box2D::common::math::B2Vec2 B2Collision_obj::s_localTangent;

::box2D::common::math::B2Vec2 B2Collision_obj::s_localNormal;

::box2D::common::math::B2Vec2 B2Collision_obj::s_planePoint;

::box2D::common::math::B2Vec2 B2Collision_obj::s_normal;

::box2D::common::math::B2Vec2 B2Collision_obj::s_tangent;

::box2D::common::math::B2Vec2 B2Collision_obj::s_tangent2;

::box2D::common::math::B2Vec2 B2Collision_obj::s_v11;

::box2D::common::math::B2Vec2 B2Collision_obj::s_v12;

::box2D::common::math::B2Vec2 B2Collision_obj::b2CollidePolyTempVec;

Void B2Collision_obj::collidePolygons( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polyA,::box2D::common::math::B2Transform xfA,::box2D::collision::shapes::B2PolygonShape polyB,::box2D::common::math::B2Transform xfB){
{
		HX_STACK_FRAME("box2D.collision.B2Collision","collidePolygons",0xd48a73fe,"box2D.collision.B2Collision.collidePolygons","box2D/collision/B2Collision.hx",360,0xb600848b)
		HX_STACK_ARG(manifold,"manifold")
		HX_STACK_ARG(polyA,"polyA")
		HX_STACK_ARG(xfA,"xfA")
		HX_STACK_ARG(polyB,"polyB")
		HX_STACK_ARG(xfB,"xfB")
		HX_STACK_LINE(361)
		::box2D::collision::ClipVertex cv;		HX_STACK_VAR(cv,"cv");
		HX_STACK_LINE(363)
		manifold->m_pointCount = (int)0;
		HX_STACK_LINE(364)
		Float totalRadius = (polyA->m_radius + polyB->m_radius);		HX_STACK_VAR(totalRadius,"totalRadius");
		HX_STACK_LINE(366)
		int edgeA = (int)0;		HX_STACK_VAR(edgeA,"edgeA");
		HX_STACK_LINE(367)
		::box2D::collision::B2Collision_obj::s_edgeAO[(int)0] = edgeA;
		HX_STACK_LINE(368)
		Float separationA = ::box2D::collision::B2Collision_obj::findMaxSeparation(::box2D::collision::B2Collision_obj::s_edgeAO,polyA,xfA,polyB,xfB);		HX_STACK_VAR(separationA,"separationA");
		HX_STACK_LINE(369)
		edgeA = ::box2D::collision::B2Collision_obj::s_edgeAO->__get((int)0);
		HX_STACK_LINE(370)
		if (((separationA > totalRadius))){
			HX_STACK_LINE(371)
			return null();
		}
		HX_STACK_LINE(373)
		int edgeB = (int)0;		HX_STACK_VAR(edgeB,"edgeB");
		HX_STACK_LINE(374)
		::box2D::collision::B2Collision_obj::s_edgeBO[(int)0] = edgeB;
		HX_STACK_LINE(375)
		Float separationB = ::box2D::collision::B2Collision_obj::findMaxSeparation(::box2D::collision::B2Collision_obj::s_edgeBO,polyB,xfB,polyA,xfA);		HX_STACK_VAR(separationB,"separationB");
		HX_STACK_LINE(376)
		edgeB = ::box2D::collision::B2Collision_obj::s_edgeBO->__get((int)0);
		HX_STACK_LINE(377)
		if (((separationB > totalRadius))){
			HX_STACK_LINE(378)
			return null();
		}
		HX_STACK_LINE(380)
		::box2D::collision::shapes::B2PolygonShape poly1;		HX_STACK_VAR(poly1,"poly1");
		HX_STACK_LINE(381)
		::box2D::collision::shapes::B2PolygonShape poly2;		HX_STACK_VAR(poly2,"poly2");
		HX_STACK_LINE(382)
		::box2D::common::math::B2Transform xf1;		HX_STACK_VAR(xf1,"xf1");
		HX_STACK_LINE(383)
		::box2D::common::math::B2Transform xf2;		HX_STACK_VAR(xf2,"xf2");
		HX_STACK_LINE(384)
		int edge1;		HX_STACK_VAR(edge1,"edge1");
		HX_STACK_LINE(385)
		int flip;		HX_STACK_VAR(flip,"flip");
		HX_STACK_LINE(386)
		Float k_relativeTol = 0.98;		HX_STACK_VAR(k_relativeTol,"k_relativeTol");
		HX_STACK_LINE(387)
		Float k_absoluteTol = 0.001;		HX_STACK_VAR(k_absoluteTol,"k_absoluteTol");
		HX_STACK_LINE(388)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(390)
		if (((separationB > ((k_relativeTol * separationA) + k_absoluteTol)))){
			HX_STACK_LINE(392)
			poly1 = polyB;
			HX_STACK_LINE(393)
			poly2 = polyA;
			HX_STACK_LINE(394)
			xf1 = xfB;
			HX_STACK_LINE(395)
			xf2 = xfA;
			HX_STACK_LINE(396)
			edge1 = edgeB;
			HX_STACK_LINE(397)
			manifold->m_type = ::box2D::collision::B2ManifoldType_obj::FACE_B;
			HX_STACK_LINE(398)
			flip = (int)1;
		}
		else{
			HX_STACK_LINE(402)
			poly1 = polyA;
			HX_STACK_LINE(403)
			poly2 = polyB;
			HX_STACK_LINE(404)
			xf1 = xfA;
			HX_STACK_LINE(405)
			xf2 = xfB;
			HX_STACK_LINE(406)
			edge1 = edgeA;
			HX_STACK_LINE(407)
			manifold->m_type = ::box2D::collision::B2ManifoldType_obj::FACE_A;
			HX_STACK_LINE(408)
			flip = (int)0;
		}
		HX_STACK_LINE(411)
		Array< ::Dynamic > incidentEdge = ::box2D::collision::B2Collision_obj::s_incidentEdge;		HX_STACK_VAR(incidentEdge,"incidentEdge");
		HX_STACK_LINE(412)
		::box2D::collision::B2Collision_obj::findIncidentEdge(incidentEdge,poly1,xf1,edge1,poly2,xf2);
		HX_STACK_LINE(414)
		int count1 = poly1->m_vertexCount;		HX_STACK_VAR(count1,"count1");
		HX_STACK_LINE(415)
		Array< ::Dynamic > vertices1 = poly1->m_vertices;		HX_STACK_VAR(vertices1,"vertices1");
		HX_STACK_LINE(417)
		::box2D::common::math::B2Vec2 local_v11 = vertices1->__get(edge1).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(local_v11,"local_v11");
		HX_STACK_LINE(418)
		::box2D::common::math::B2Vec2 local_v12;		HX_STACK_VAR(local_v12,"local_v12");
		HX_STACK_LINE(419)
		if ((((edge1 + (int)1) < count1))){
			HX_STACK_LINE(420)
			int _g = ::Std_obj::_int((edge1 + (int)1));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(420)
			::box2D::common::math::B2Vec2 _g1 = vertices1->__get(_g).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(420)
			local_v12 = _g1;
		}
		else{
			HX_STACK_LINE(422)
			local_v12 = vertices1->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >();
		}
		HX_STACK_LINE(425)
		::box2D::common::math::B2Vec2 localTangent = ::box2D::collision::B2Collision_obj::s_localTangent;		HX_STACK_VAR(localTangent,"localTangent");
		HX_STACK_LINE(426)
		localTangent->set((local_v12->x - local_v11->x),(local_v12->y - local_v11->y));
		HX_STACK_LINE(427)
		localTangent->normalize();
		HX_STACK_LINE(429)
		::box2D::common::math::B2Vec2 localNormal = ::box2D::collision::B2Collision_obj::s_localNormal;		HX_STACK_VAR(localNormal,"localNormal");
		HX_STACK_LINE(430)
		localNormal->x = localTangent->y;
		HX_STACK_LINE(431)
		localNormal->y = -(localTangent->x);
		HX_STACK_LINE(433)
		::box2D::common::math::B2Vec2 planePoint = ::box2D::collision::B2Collision_obj::s_planePoint;		HX_STACK_VAR(planePoint,"planePoint");
		HX_STACK_LINE(434)
		planePoint->set((0.5 * ((local_v11->x + local_v12->x))),(0.5 * ((local_v11->y + local_v12->y))));
		HX_STACK_LINE(436)
		::box2D::common::math::B2Vec2 tangent = ::box2D::collision::B2Collision_obj::s_tangent;		HX_STACK_VAR(tangent,"tangent");
		HX_STACK_LINE(438)
		tMat = xf1->R;
		HX_STACK_LINE(439)
		tangent->x = ((tMat->col1->x * localTangent->x) + (tMat->col2->x * localTangent->y));
		HX_STACK_LINE(440)
		tangent->y = ((tMat->col1->y * localTangent->x) + (tMat->col2->y * localTangent->y));
		HX_STACK_LINE(441)
		::box2D::common::math::B2Vec2 tangent2 = ::box2D::collision::B2Collision_obj::s_tangent2;		HX_STACK_VAR(tangent2,"tangent2");
		HX_STACK_LINE(442)
		tangent2->x = -(tangent->x);
		HX_STACK_LINE(443)
		tangent2->y = -(tangent->y);
		HX_STACK_LINE(444)
		::box2D::common::math::B2Vec2 normal = ::box2D::collision::B2Collision_obj::s_normal;		HX_STACK_VAR(normal,"normal");
		HX_STACK_LINE(445)
		normal->x = tangent->y;
		HX_STACK_LINE(446)
		normal->y = -(tangent->x);
		HX_STACK_LINE(450)
		::box2D::common::math::B2Vec2 v11 = ::box2D::collision::B2Collision_obj::s_v11;		HX_STACK_VAR(v11,"v11");
		HX_STACK_LINE(451)
		::box2D::common::math::B2Vec2 v12 = ::box2D::collision::B2Collision_obj::s_v12;		HX_STACK_VAR(v12,"v12");
		HX_STACK_LINE(452)
		v11->x = (xf1->position->x + (((tMat->col1->x * local_v11->x) + (tMat->col2->x * local_v11->y))));
		HX_STACK_LINE(453)
		v11->y = (xf1->position->y + (((tMat->col1->y * local_v11->x) + (tMat->col2->y * local_v11->y))));
		HX_STACK_LINE(454)
		v12->x = (xf1->position->x + (((tMat->col1->x * local_v12->x) + (tMat->col2->x * local_v12->y))));
		HX_STACK_LINE(455)
		v12->y = (xf1->position->y + (((tMat->col1->y * local_v12->x) + (tMat->col2->y * local_v12->y))));
		HX_STACK_LINE(458)
		Float frontOffset = ((normal->x * v11->x) + (normal->y * v11->y));		HX_STACK_VAR(frontOffset,"frontOffset");
		HX_STACK_LINE(460)
		Float sideOffset1 = (((-(tangent->x) * v11->x) - (tangent->y * v11->y)) + totalRadius);		HX_STACK_VAR(sideOffset1,"sideOffset1");
		HX_STACK_LINE(461)
		Float sideOffset2 = (((tangent->x * v12->x) + (tangent->y * v12->y)) + totalRadius);		HX_STACK_VAR(sideOffset2,"sideOffset2");
		HX_STACK_LINE(464)
		Array< ::Dynamic > clipPoints1 = ::box2D::collision::B2Collision_obj::s_clipPoints1;		HX_STACK_VAR(clipPoints1,"clipPoints1");
		HX_STACK_LINE(465)
		Array< ::Dynamic > clipPoints2 = ::box2D::collision::B2Collision_obj::s_clipPoints2;		HX_STACK_VAR(clipPoints2,"clipPoints2");
		HX_STACK_LINE(466)
		int np;		HX_STACK_VAR(np,"np");
		HX_STACK_LINE(470)
		int _g2 = ::box2D::collision::B2Collision_obj::clipSegmentToLine(clipPoints1,incidentEdge,tangent2,sideOffset1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(470)
		np = _g2;
		HX_STACK_LINE(472)
		if (((np < (int)2))){
			HX_STACK_LINE(473)
			return null();
		}
		HX_STACK_LINE(476)
		int _g3 = ::box2D::collision::B2Collision_obj::clipSegmentToLine(clipPoints2,clipPoints1,tangent,sideOffset2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(476)
		np = _g3;
		HX_STACK_LINE(478)
		if (((np < (int)2))){
			HX_STACK_LINE(479)
			return null();
		}
		HX_STACK_LINE(482)
		manifold->m_localPlaneNormal->setV(localNormal);
		HX_STACK_LINE(483)
		manifold->m_localPoint->setV(planePoint);
		HX_STACK_LINE(485)
		int pointCount = (int)0;		HX_STACK_VAR(pointCount,"pointCount");
		HX_STACK_LINE(486)
		{
			HX_STACK_LINE(486)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(486)
			int _g = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(486)
			while((true)){
				HX_STACK_LINE(486)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(486)
					break;
				}
				HX_STACK_LINE(486)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(488)
				cv = clipPoints2->__get(i).StaticCast< ::box2D::collision::ClipVertex >();
				HX_STACK_LINE(489)
				Float separation = (((normal->x * cv->v->x) + (normal->y * cv->v->y)) - frontOffset);		HX_STACK_VAR(separation,"separation");
				HX_STACK_LINE(490)
				if (((separation <= totalRadius))){
					HX_STACK_LINE(492)
					::box2D::collision::B2ManifoldPoint cp = manifold->m_points->__get(pointCount).StaticCast< ::box2D::collision::B2ManifoldPoint >();		HX_STACK_VAR(cp,"cp");
					HX_STACK_LINE(494)
					tMat = xf2->R;
					HX_STACK_LINE(495)
					Float tX = (cv->v->x - xf2->position->x);		HX_STACK_VAR(tX,"tX");
					HX_STACK_LINE(496)
					Float tY = (cv->v->y - xf2->position->y);		HX_STACK_VAR(tY,"tY");
					HX_STACK_LINE(497)
					cp->m_localPoint->x = ((tX * tMat->col1->x) + (tY * tMat->col1->y));
					HX_STACK_LINE(498)
					cp->m_localPoint->y = ((tX * tMat->col2->x) + (tY * tMat->col2->y));
					HX_STACK_LINE(499)
					cp->m_id->set(cv->id);
					HX_STACK_LINE(500)
					cp->m_id->features->set_flip(flip);
					HX_STACK_LINE(501)
					++(pointCount);
				}
			}
		}
		HX_STACK_LINE(505)
		manifold->m_pointCount = pointCount;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,collidePolygons,(void))

Void B2Collision_obj::collideCircles( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2CircleShape circle1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle2,::box2D::common::math::B2Transform xf2){
{
		HX_STACK_FRAME("box2D.collision.B2Collision","collideCircles",0xe8b0e0be,"box2D.collision.B2Collision.collideCircles","box2D/collision/B2Collision.hx",514,0xb600848b)
		HX_STACK_ARG(manifold,"manifold")
		HX_STACK_ARG(circle1,"circle1")
		HX_STACK_ARG(xf1,"xf1")
		HX_STACK_ARG(circle2,"circle2")
		HX_STACK_ARG(xf2,"xf2")
		HX_STACK_LINE(515)
		manifold->m_pointCount = (int)0;
		HX_STACK_LINE(517)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(518)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(521)
		tMat = xf1->R;
		HX_STACK_LINE(521)
		tVec = circle1->m_p;
		HX_STACK_LINE(522)
		Float p1X = (xf1->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(p1X,"p1X");
		HX_STACK_LINE(523)
		Float p1Y = (xf1->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(p1Y,"p1Y");
		HX_STACK_LINE(525)
		tMat = xf2->R;
		HX_STACK_LINE(525)
		tVec = circle2->m_p;
		HX_STACK_LINE(526)
		Float p2X = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(p2X,"p2X");
		HX_STACK_LINE(527)
		Float p2Y = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(p2Y,"p2Y");
		HX_STACK_LINE(529)
		Float dX = (p2X - p1X);		HX_STACK_VAR(dX,"dX");
		HX_STACK_LINE(530)
		Float dY = (p2Y - p1Y);		HX_STACK_VAR(dY,"dY");
		HX_STACK_LINE(532)
		Float distSqr = ((dX * dX) + (dY * dY));		HX_STACK_VAR(distSqr,"distSqr");
		HX_STACK_LINE(533)
		Float radius = (circle1->m_radius + circle2->m_radius);		HX_STACK_VAR(radius,"radius");
		HX_STACK_LINE(534)
		if (((distSqr > (radius * radius)))){
			HX_STACK_LINE(536)
			return null();
		}
		HX_STACK_LINE(538)
		manifold->m_type = ::box2D::collision::B2ManifoldType_obj::CIRCLES;
		HX_STACK_LINE(539)
		manifold->m_localPoint->setV(circle1->m_p);
		HX_STACK_LINE(540)
		manifold->m_localPlaneNormal->setZero();
		HX_STACK_LINE(541)
		manifold->m_pointCount = (int)1;
		HX_STACK_LINE(542)
		manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint->setV(circle2->m_p);
		HX_STACK_LINE(543)
		manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_id->set_key((int)0);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,collideCircles,(void))

Void B2Collision_obj::collidePolygonAndCircle( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polygon,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle,::box2D::common::math::B2Transform xf2){
{
		HX_STACK_FRAME("box2D.collision.B2Collision","collidePolygonAndCircle",0x55c672b2,"box2D.collision.B2Collision.collidePolygonAndCircle","box2D/collision/B2Collision.hx",552,0xb600848b)
		HX_STACK_ARG(manifold,"manifold")
		HX_STACK_ARG(polygon,"polygon")
		HX_STACK_ARG(xf1,"xf1")
		HX_STACK_ARG(circle,"circle")
		HX_STACK_ARG(xf2,"xf2")
		HX_STACK_LINE(553)
		manifold->m_pointCount = (int)0;
		HX_STACK_LINE(554)
		::box2D::collision::B2ManifoldPoint tPoint;		HX_STACK_VAR(tPoint,"tPoint");
		HX_STACK_LINE(556)
		Float dX;		HX_STACK_VAR(dX,"dX");
		HX_STACK_LINE(557)
		Float dY;		HX_STACK_VAR(dY,"dY");
		HX_STACK_LINE(558)
		Float positionX;		HX_STACK_VAR(positionX,"positionX");
		HX_STACK_LINE(559)
		Float positionY;		HX_STACK_VAR(positionY,"positionY");
		HX_STACK_LINE(561)
		::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(562)
		::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(566)
		tMat = xf2->R;
		HX_STACK_LINE(567)
		tVec = circle->m_p;
		HX_STACK_LINE(568)
		Float cX = (xf2->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(cX,"cX");
		HX_STACK_LINE(569)
		Float cY = (xf2->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(cY,"cY");
		HX_STACK_LINE(572)
		dX = (cX - xf1->position->x);
		HX_STACK_LINE(573)
		dY = (cY - xf1->position->y);
		HX_STACK_LINE(574)
		tMat = xf1->R;
		HX_STACK_LINE(575)
		Float cLocalX = ((dX * tMat->col1->x) + (dY * tMat->col1->y));		HX_STACK_VAR(cLocalX,"cLocalX");
		HX_STACK_LINE(576)
		Float cLocalY = ((dX * tMat->col2->x) + (dY * tMat->col2->y));		HX_STACK_VAR(cLocalY,"cLocalY");
		HX_STACK_LINE(578)
		Float dist;		HX_STACK_VAR(dist,"dist");
		HX_STACK_LINE(581)
		int normalIndex = (int)0;		HX_STACK_VAR(normalIndex,"normalIndex");
		HX_STACK_LINE(582)
		Float separation = -1.7976931348623157e+308;		HX_STACK_VAR(separation,"separation");
		HX_STACK_LINE(583)
		Float radius = (polygon->m_radius + circle->m_radius);		HX_STACK_VAR(radius,"radius");
		HX_STACK_LINE(584)
		int vertexCount = polygon->m_vertexCount;		HX_STACK_VAR(vertexCount,"vertexCount");
		HX_STACK_LINE(585)
		Array< ::Dynamic > vertices = polygon->m_vertices;		HX_STACK_VAR(vertices,"vertices");
		HX_STACK_LINE(586)
		Array< ::Dynamic > normals = polygon->m_normals;		HX_STACK_VAR(normals,"normals");
		HX_STACK_LINE(588)
		{
			HX_STACK_LINE(588)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(588)
			while((true)){
				HX_STACK_LINE(588)
				if ((!(((_g < vertexCount))))){
					HX_STACK_LINE(588)
					break;
				}
				HX_STACK_LINE(588)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(591)
				tVec = vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
				HX_STACK_LINE(592)
				dX = (cLocalX - tVec->x);
				HX_STACK_LINE(593)
				dY = (cLocalY - tVec->y);
				HX_STACK_LINE(594)
				tVec = normals->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
				HX_STACK_LINE(595)
				Float s = ((tVec->x * dX) + (tVec->y * dY));		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(597)
				if (((s > radius))){
					HX_STACK_LINE(600)
					return null();
				}
				HX_STACK_LINE(603)
				if (((s > separation))){
					HX_STACK_LINE(605)
					separation = s;
					HX_STACK_LINE(606)
					normalIndex = i;
				}
			}
		}
		HX_STACK_LINE(610)
		int vertIndex1 = normalIndex;		HX_STACK_VAR(vertIndex1,"vertIndex1");
		HX_STACK_LINE(611)
		int vertIndex2;		HX_STACK_VAR(vertIndex2,"vertIndex2");
		HX_STACK_LINE(611)
		if ((((vertIndex1 + (int)1) < vertexCount))){
			HX_STACK_LINE(611)
			vertIndex2 = (vertIndex1 + (int)1);
		}
		else{
			HX_STACK_LINE(611)
			vertIndex2 = (int)0;
		}
		HX_STACK_LINE(612)
		::box2D::common::math::B2Vec2 v1 = vertices->__get(vertIndex1).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(613)
		::box2D::common::math::B2Vec2 v2 = vertices->__get(vertIndex2).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(616)
		if (((separation < 2.2250738585072014e-308))){
			HX_STACK_LINE(618)
			manifold->m_pointCount = (int)1;
			HX_STACK_LINE(619)
			manifold->m_type = ::box2D::collision::B2ManifoldType_obj::FACE_A;
			HX_STACK_LINE(620)
			manifold->m_localPlaneNormal->setV(normals->__get(normalIndex).StaticCast< ::box2D::common::math::B2Vec2 >());
			HX_STACK_LINE(621)
			manifold->m_localPoint->x = (0.5 * ((v1->x + v2->x)));
			HX_STACK_LINE(622)
			manifold->m_localPoint->y = (0.5 * ((v1->y + v2->y)));
			HX_STACK_LINE(623)
			manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint->setV(circle->m_p);
			HX_STACK_LINE(624)
			manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_id->set_key((int)0);
			HX_STACK_LINE(625)
			return null();
		}
		HX_STACK_LINE(629)
		Float u1 = ((((cLocalX - v1->x)) * ((v2->x - v1->x))) + (((cLocalY - v1->y)) * ((v2->y - v1->y))));		HX_STACK_VAR(u1,"u1");
		HX_STACK_LINE(630)
		Float u2 = ((((cLocalX - v2->x)) * ((v1->x - v2->x))) + (((cLocalY - v2->y)) * ((v1->y - v2->y))));		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(631)
		if (((u1 <= 0.0))){
			HX_STACK_LINE(633)
			if (((((((cLocalX - v1->x)) * ((cLocalX - v1->x))) + (((cLocalY - v1->y)) * ((cLocalY - v1->y)))) > (radius * radius)))){
				HX_STACK_LINE(634)
				return null();
			}
			HX_STACK_LINE(635)
			manifold->m_pointCount = (int)1;
			HX_STACK_LINE(636)
			manifold->m_type = ::box2D::collision::B2ManifoldType_obj::FACE_A;
			HX_STACK_LINE(637)
			manifold->m_localPlaneNormal->x = (cLocalX - v1->x);
			HX_STACK_LINE(638)
			manifold->m_localPlaneNormal->y = (cLocalY - v1->y);
			HX_STACK_LINE(639)
			manifold->m_localPlaneNormal->normalize();
			HX_STACK_LINE(640)
			manifold->m_localPoint->setV(v1);
			HX_STACK_LINE(641)
			manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint->setV(circle->m_p);
			HX_STACK_LINE(642)
			manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_id->set_key((int)0);
		}
		else{
			HX_STACK_LINE(644)
			if (((u2 <= (int)0))){
				HX_STACK_LINE(646)
				if (((((((cLocalX - v2->x)) * ((cLocalX - v2->x))) + (((cLocalY - v2->y)) * ((cLocalY - v2->y)))) > (radius * radius)))){
					HX_STACK_LINE(647)
					return null();
				}
				HX_STACK_LINE(648)
				manifold->m_pointCount = (int)1;
				HX_STACK_LINE(649)
				manifold->m_type = ::box2D::collision::B2ManifoldType_obj::FACE_A;
				HX_STACK_LINE(650)
				manifold->m_localPlaneNormal->x = (cLocalX - v2->x);
				HX_STACK_LINE(651)
				manifold->m_localPlaneNormal->y = (cLocalY - v2->y);
				HX_STACK_LINE(652)
				manifold->m_localPlaneNormal->normalize();
				HX_STACK_LINE(653)
				manifold->m_localPoint->setV(v2);
				HX_STACK_LINE(654)
				manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint->setV(circle->m_p);
				HX_STACK_LINE(655)
				manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_id->set_key((int)0);
			}
			else{
				HX_STACK_LINE(659)
				Float faceCenterX = (0.5 * ((v1->x + v2->x)));		HX_STACK_VAR(faceCenterX,"faceCenterX");
				HX_STACK_LINE(660)
				Float faceCenterY = (0.5 * ((v1->y + v2->y)));		HX_STACK_VAR(faceCenterY,"faceCenterY");
				HX_STACK_LINE(661)
				separation = ((((cLocalX - faceCenterX)) * normals->__get(vertIndex1).StaticCast< ::box2D::common::math::B2Vec2 >()->x) + (((cLocalY - faceCenterY)) * normals->__get(vertIndex1).StaticCast< ::box2D::common::math::B2Vec2 >()->y));
				HX_STACK_LINE(662)
				if (((separation > radius))){
					HX_STACK_LINE(663)
					return null();
				}
				HX_STACK_LINE(664)
				manifold->m_pointCount = (int)1;
				HX_STACK_LINE(665)
				manifold->m_type = ::box2D::collision::B2ManifoldType_obj::FACE_A;
				HX_STACK_LINE(666)
				manifold->m_localPlaneNormal->x = normals->__get(vertIndex1).StaticCast< ::box2D::common::math::B2Vec2 >()->x;
				HX_STACK_LINE(667)
				manifold->m_localPlaneNormal->y = normals->__get(vertIndex1).StaticCast< ::box2D::common::math::B2Vec2 >()->y;
				HX_STACK_LINE(668)
				manifold->m_localPlaneNormal->normalize();
				HX_STACK_LINE(669)
				manifold->m_localPoint->set(faceCenterX,faceCenterY);
				HX_STACK_LINE(670)
				manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_localPoint->setV(circle->m_p);
				HX_STACK_LINE(671)
				manifold->m_points->__get((int)0).StaticCast< ::box2D::collision::B2ManifoldPoint >()->m_id->set_key((int)0);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(B2Collision_obj,collidePolygonAndCircle,(void))

bool B2Collision_obj::testOverlap( ::box2D::collision::B2AABB a,::box2D::collision::B2AABB b){
	HX_STACK_FRAME("box2D.collision.B2Collision","testOverlap",0x8c92c37c,"box2D.collision.B2Collision.testOverlap","box2D/collision/B2Collision.hx",679,0xb600848b)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(680)
	::box2D::common::math::B2Vec2 t1 = b->lowerBound;		HX_STACK_VAR(t1,"t1");
	HX_STACK_LINE(681)
	::box2D::common::math::B2Vec2 t2 = a->upperBound;		HX_STACK_VAR(t2,"t2");
	HX_STACK_LINE(683)
	Float d1X = (t1->x - t2->x);		HX_STACK_VAR(d1X,"d1X");
	HX_STACK_LINE(684)
	Float d1Y = (t1->y - t2->y);		HX_STACK_VAR(d1Y,"d1Y");
	HX_STACK_LINE(686)
	t1 = a->lowerBound;
	HX_STACK_LINE(687)
	t2 = b->upperBound;
	HX_STACK_LINE(688)
	Float d2X = (t1->x - t2->x);		HX_STACK_VAR(d2X,"d2X");
	HX_STACK_LINE(689)
	Float d2Y = (t1->y - t2->y);		HX_STACK_VAR(d2Y,"d2Y");
	HX_STACK_LINE(691)
	if (((bool((d1X > 0.0)) || bool((d1Y > 0.0))))){
		HX_STACK_LINE(692)
		return false;
	}
	HX_STACK_LINE(694)
	if (((bool((d2X > 0.0)) || bool((d2Y > 0.0))))){
		HX_STACK_LINE(695)
		return false;
	}
	HX_STACK_LINE(697)
	return true;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Collision_obj,testOverlap,return )


B2Collision_obj::B2Collision_obj()
{
}

Dynamic B2Collision_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_v11") ) { return s_v11; }
		if (HX_FIELD_EQ(inName,"s_v12") ) { return s_v12; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_edgeAO") ) { return s_edgeAO; }
		if (HX_FIELD_EQ(inName,"s_edgeBO") ) { return s_edgeBO; }
		if (HX_FIELD_EQ(inName,"s_normal") ) { return s_normal; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_tangent") ) { return s_tangent; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_tangent2") ) { return s_tangent2; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_planePoint") ) { return s_planePoint; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"s_clipPoints1") ) { return s_clipPoints1; }
		if (HX_FIELD_EQ(inName,"s_clipPoints2") ) { return s_clipPoints2; }
		if (HX_FIELD_EQ(inName,"s_localNormal") ) { return s_localNormal; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_nullFeature") ) { return b2_nullFeature; }
		if (HX_FIELD_EQ(inName,"edgeSeparation") ) { return edgeSeparation_dyn(); }
		if (HX_FIELD_EQ(inName,"s_incidentEdge") ) { return s_incidentEdge; }
		if (HX_FIELD_EQ(inName,"s_localTangent") ) { return s_localTangent; }
		if (HX_FIELD_EQ(inName,"collideCircles") ) { return collideCircles_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"collidePolygons") ) { return collidePolygons_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"findIncidentEdge") ) { return findIncidentEdge_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"clipSegmentToLine") ) { return clipSegmentToLine_dyn(); }
		if (HX_FIELD_EQ(inName,"findMaxSeparation") ) { return findMaxSeparation_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"makeClipPointVector") ) { return makeClipPointVector_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2CollidePolyTempVec") ) { return b2CollidePolyTempVec; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"collidePolygonAndCircle") ) { return collidePolygonAndCircle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Collision_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_v11") ) { s_v11=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_v12") ) { s_v12=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"s_edgeAO") ) { s_edgeAO=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_edgeBO") ) { s_edgeBO=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_normal") ) { s_normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"s_tangent") ) { s_tangent=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"s_tangent2") ) { s_tangent2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"s_planePoint") ) { s_planePoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"s_clipPoints1") ) { s_clipPoints1=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_clipPoints2") ) { s_clipPoints2=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_localNormal") ) { s_localNormal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"b2_nullFeature") ) { b2_nullFeature=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_incidentEdge") ) { s_incidentEdge=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"s_localTangent") ) { s_localTangent=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"b2CollidePolyTempVec") ) { b2CollidePolyTempVec=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Collision_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("b2_nullFeature"),
	HX_CSTRING("clipSegmentToLine"),
	HX_CSTRING("edgeSeparation"),
	HX_CSTRING("findMaxSeparation"),
	HX_CSTRING("findIncidentEdge"),
	HX_CSTRING("makeClipPointVector"),
	HX_CSTRING("s_incidentEdge"),
	HX_CSTRING("s_clipPoints1"),
	HX_CSTRING("s_clipPoints2"),
	HX_CSTRING("s_edgeAO"),
	HX_CSTRING("s_edgeBO"),
	HX_CSTRING("s_localTangent"),
	HX_CSTRING("s_localNormal"),
	HX_CSTRING("s_planePoint"),
	HX_CSTRING("s_normal"),
	HX_CSTRING("s_tangent"),
	HX_CSTRING("s_tangent2"),
	HX_CSTRING("s_v11"),
	HX_CSTRING("s_v12"),
	HX_CSTRING("b2CollidePolyTempVec"),
	HX_CSTRING("collidePolygons"),
	HX_CSTRING("collideCircles"),
	HX_CSTRING("collidePolygonAndCircle"),
	HX_CSTRING("testOverlap"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Collision_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Collision_obj::b2_nullFeature,"b2_nullFeature");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_incidentEdge,"s_incidentEdge");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_clipPoints1,"s_clipPoints1");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_clipPoints2,"s_clipPoints2");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_edgeAO,"s_edgeAO");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_edgeBO,"s_edgeBO");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_localTangent,"s_localTangent");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_localNormal,"s_localNormal");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_planePoint,"s_planePoint");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_normal,"s_normal");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_tangent,"s_tangent");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_tangent2,"s_tangent2");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_v11,"s_v11");
	HX_MARK_MEMBER_NAME(B2Collision_obj::s_v12,"s_v12");
	HX_MARK_MEMBER_NAME(B2Collision_obj::b2CollidePolyTempVec,"b2CollidePolyTempVec");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Collision_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::b2_nullFeature,"b2_nullFeature");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_incidentEdge,"s_incidentEdge");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_clipPoints1,"s_clipPoints1");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_clipPoints2,"s_clipPoints2");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_edgeAO,"s_edgeAO");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_edgeBO,"s_edgeBO");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_localTangent,"s_localTangent");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_localNormal,"s_localNormal");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_planePoint,"s_planePoint");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_normal,"s_normal");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_tangent,"s_tangent");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_tangent2,"s_tangent2");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_v11,"s_v11");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::s_v12,"s_v12");
	HX_VISIT_MEMBER_NAME(B2Collision_obj::b2CollidePolyTempVec,"b2CollidePolyTempVec");
};

#endif

Class B2Collision_obj::__mClass;

void B2Collision_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2Collision"), hx::TCanCast< B2Collision_obj> ,sStaticFields,sMemberFields,
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

void B2Collision_obj::__boot()
{
	b2_nullFeature= (int)255;
	s_incidentEdge= ::box2D::collision::B2Collision_obj::makeClipPointVector();
	s_clipPoints1= ::box2D::collision::B2Collision_obj::makeClipPointVector();
	s_clipPoints2= ::box2D::collision::B2Collision_obj::makeClipPointVector();
	s_edgeAO= Array_obj< int >::__new();
	s_edgeBO= Array_obj< int >::__new();
	s_localTangent= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	s_localNormal= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	s_planePoint= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	s_normal= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	s_tangent= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	s_tangent2= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	s_v11= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	s_v12= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
	b2CollidePolyTempVec= ::box2D::common::math::B2Vec2_obj::__new(null(),null());
}

} // end namespace box2D
} // end namespace collision
