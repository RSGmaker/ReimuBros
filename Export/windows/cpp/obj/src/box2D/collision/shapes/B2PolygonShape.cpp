#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2OBB
#include <box2D/collision/B2OBB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
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

Void B2PolygonShape_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","new",0x68088bf8,"box2D.collision.shapes.B2PolygonShape.new","box2D/collision/shapes/B2PolygonShape.hx",39,0xcb7baa99)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(750)
	this->m_vertexCount = (int)0;
	HX_STACK_LINE(725)
	super::__construct();
	HX_STACK_LINE(728)
	this->m_type = (int)2;
	HX_STACK_LINE(730)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(730)
	this->m_centroid = _g;
	HX_STACK_LINE(731)
	Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(731)
	this->m_vertices = _g1;
	HX_STACK_LINE(732)
	Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(732)
	this->m_normals = _g2;
}
;
	return null();
}

//B2PolygonShape_obj::~B2PolygonShape_obj() { }

Dynamic B2PolygonShape_obj::__CreateEmpty() { return  new B2PolygonShape_obj; }
hx::ObjectPtr< B2PolygonShape_obj > B2PolygonShape_obj::__new()
{  hx::ObjectPtr< B2PolygonShape_obj > result = new B2PolygonShape_obj();
	result->__construct();
	return result;}

Dynamic B2PolygonShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2PolygonShape_obj > result = new B2PolygonShape_obj();
	result->__construct();
	return result;}

::box2D::collision::shapes::B2Shape B2PolygonShape_obj::copy( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","copy",0x9834251d,"box2D.collision.shapes.B2PolygonShape.copy","box2D/collision/shapes/B2PolygonShape.hx",42,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_LINE(43)
	::box2D::collision::shapes::B2PolygonShape s = ::box2D::collision::shapes::B2PolygonShape_obj::__new();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(44)
	s->set(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(45)
	return s;
}


Void B2PolygonShape_obj::set( ::box2D::collision::shapes::B2Shape other){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","set",0x680c573a,"box2D.collision.shapes.B2PolygonShape.set","box2D/collision/shapes/B2PolygonShape.hx",49,0xcb7baa99)
		HX_STACK_THIS(this)
		HX_STACK_ARG(other,"other")
		HX_STACK_LINE(50)
		this->super::set(other);
		HX_STACK_LINE(51)
		if ((::Std_obj::is(other,hx::ClassOf< ::box2D::collision::shapes::B2PolygonShape >()))){
			HX_STACK_LINE(53)
			::box2D::collision::shapes::B2PolygonShape other2;		HX_STACK_VAR(other2,"other2");
			HX_STACK_LINE(53)
			other2 = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(other);
			HX_STACK_LINE(54)
			this->m_centroid->setV(other2->m_centroid);
			HX_STACK_LINE(55)
			this->m_vertexCount = other2->m_vertexCount;
			HX_STACK_LINE(56)
			this->reserve(this->m_vertexCount);
			HX_STACK_LINE(57)
			{
				HX_STACK_LINE(57)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(57)
				int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(57)
				while((true)){
					HX_STACK_LINE(57)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(57)
						break;
					}
					HX_STACK_LINE(57)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(59)
					this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->setV(other2->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >());
					HX_STACK_LINE(60)
					this->m_normals->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->setV(other2->m_normals->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >());
				}
			}
		}
	}
return null();
}


Void B2PolygonShape_obj::setAsArray( Dynamic vertices,hx::Null< Float >  __o_vertexCount){
Float vertexCount = __o_vertexCount.Default(0);
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","setAsArray",0x4e64e72d,"box2D.collision.shapes.B2PolygonShape.setAsArray","box2D/collision/shapes/B2PolygonShape.hx",70,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vertices,"vertices")
	HX_STACK_ARG(vertexCount,"vertexCount")
{
		HX_STACK_LINE(71)
		Array< ::Dynamic > v = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(72)
		{
			HX_STACK_LINE(72)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(72)
			while((true)){
				HX_STACK_LINE(72)
				if ((!(((_g < vertices->__Field(HX_CSTRING("length"),true)))))){
					HX_STACK_LINE(72)
					break;
				}
				HX_STACK_LINE(72)
				Dynamic tVec = vertices->__GetItem(_g);		HX_STACK_VAR(tVec,"tVec");
				HX_STACK_LINE(72)
				++(_g);
				HX_STACK_LINE(74)
				v->push(tVec);
			}
		}
		HX_STACK_LINE(76)
		this->setAsVector(v,vertexCount);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsArray,(void))

Void B2PolygonShape_obj::setAsVector( Array< ::Dynamic > vertices,hx::Null< Float >  __o_vertexCount){
Float vertexCount = __o_vertexCount.Default(0);
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","setAsVector",0x295298af,"box2D.collision.shapes.B2PolygonShape.setAsVector","box2D/collision/shapes/B2PolygonShape.hx",91,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(vertices,"vertices")
	HX_STACK_ARG(vertexCount,"vertexCount")
{
		HX_STACK_LINE(92)
		if (((vertexCount == (int)0))){
			HX_STACK_LINE(93)
			vertexCount = vertices->length;
		}
		HX_STACK_LINE(95)
		::box2D::common::B2Settings_obj::b2Assert(((int)2 <= vertexCount));
		HX_STACK_LINE(96)
		int _g = ::Std_obj::_int(vertexCount);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(96)
		this->m_vertexCount = _g;
		HX_STACK_LINE(98)
		int _g1 = ::Std_obj::_int(vertexCount);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(98)
		this->reserve(_g1);
		HX_STACK_LINE(100)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(103)
		{
			HX_STACK_LINE(103)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(103)
			int _g2 = this->m_vertexCount;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(103)
			while((true)){
				HX_STACK_LINE(103)
				if ((!(((_g11 < _g2))))){
					HX_STACK_LINE(103)
					break;
				}
				HX_STACK_LINE(103)
				int i1 = (_g11)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(105)
				this->m_vertices->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->setV(vertices->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >());
			}
		}
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(109)
			int _g2 = this->m_vertexCount;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(109)
			while((true)){
				HX_STACK_LINE(109)
				if ((!(((_g11 < _g2))))){
					HX_STACK_LINE(109)
					break;
				}
				HX_STACK_LINE(109)
				int i1 = (_g11)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(111)
				int i11 = i1;		HX_STACK_VAR(i11,"i11");
				HX_STACK_LINE(112)
				int i2;		HX_STACK_VAR(i2,"i2");
				HX_STACK_LINE(112)
				if ((((i1 + (int)1) < this->m_vertexCount))){
					HX_STACK_LINE(112)
					i2 = (i1 + (int)1);
				}
				else{
					HX_STACK_LINE(112)
					i2 = (int)0;
				}
				HX_STACK_LINE(113)
				::box2D::common::math::B2Vec2 edge = ::box2D::common::math::B2Math_obj::subtractVV(this->m_vertices->__get(i2).StaticCast< ::box2D::common::math::B2Vec2 >(),this->m_vertices->__get(i11).StaticCast< ::box2D::common::math::B2Vec2 >());		HX_STACK_VAR(edge,"edge");
				HX_STACK_LINE(114)
				Float _g21 = edge->lengthSquared();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(114)
				bool _g3 = (_g21 > 2.2250738585072014e-308);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(114)
				::box2D::common::B2Settings_obj::b2Assert(_g3);
				HX_STACK_LINE(115)
				::box2D::common::math::B2Vec2 _g4 = ::box2D::common::math::B2Math_obj::crossVF(edge,1.0);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(115)
				this->m_normals->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->setV(_g4);
				HX_STACK_LINE(116)
				this->m_normals->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->normalize();
			}
		}
		HX_STACK_LINE(120)
		::box2D::common::math::B2Vec2 _g5 = ::box2D::collision::shapes::B2PolygonShape_obj::computeCentroid(this->m_vertices,this->m_vertexCount);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(120)
		this->m_centroid = _g5;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsVector,(void))

Void B2PolygonShape_obj::setAsBox( Float hx,Float hy){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","setAsBox",0xe2ccea9f,"box2D.collision.shapes.B2PolygonShape.setAsBox","box2D/collision/shapes/B2PolygonShape.hx",136,0xcb7baa99)
		HX_STACK_THIS(this)
		HX_STACK_ARG(hx,"hx")
		HX_STACK_ARG(hy,"hy")
		HX_STACK_LINE(137)
		this->m_vertexCount = (int)4;
		HX_STACK_LINE(138)
		this->reserve((int)4);
		HX_STACK_LINE(139)
		this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->set(-(hx),-(hy));
		HX_STACK_LINE(140)
		this->m_vertices->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->set(hx,-(hy));
		HX_STACK_LINE(141)
		this->m_vertices->__get((int)2).StaticCast< ::box2D::common::math::B2Vec2 >()->set(hx,hy);
		HX_STACK_LINE(142)
		this->m_vertices->__get((int)3).StaticCast< ::box2D::common::math::B2Vec2 >()->set(-(hx),hy);
		HX_STACK_LINE(143)
		this->m_normals->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->set(0.0,-1.0);
		HX_STACK_LINE(144)
		this->m_normals->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->set(1.0,0.0);
		HX_STACK_LINE(145)
		this->m_normals->__get((int)2).StaticCast< ::box2D::common::math::B2Vec2 >()->set(0.0,1.0);
		HX_STACK_LINE(146)
		this->m_normals->__get((int)3).StaticCast< ::box2D::common::math::B2Vec2 >()->set(-1.0,0.0);
		HX_STACK_LINE(147)
		this->m_centroid->setZero();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsBox,(void))

Void B2PolygonShape_obj::setAsOrientedBox( Float hx,Float hy,::box2D::common::math::B2Vec2 center,hx::Null< Float >  __o_angle){
Float angle = __o_angle.Default(0.0);
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","setAsOrientedBox",0xe7071f9b,"box2D.collision.shapes.B2PolygonShape.setAsOrientedBox","box2D/collision/shapes/B2PolygonShape.hx",166,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(hx,"hx")
	HX_STACK_ARG(hy,"hy")
	HX_STACK_ARG(center,"center")
	HX_STACK_ARG(angle,"angle")
{
		HX_STACK_LINE(167)
		this->m_vertexCount = (int)4;
		HX_STACK_LINE(168)
		this->reserve((int)4);
		HX_STACK_LINE(169)
		this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->set(-(hx),-(hy));
		HX_STACK_LINE(170)
		this->m_vertices->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->set(hx,-(hy));
		HX_STACK_LINE(171)
		this->m_vertices->__get((int)2).StaticCast< ::box2D::common::math::B2Vec2 >()->set(hx,hy);
		HX_STACK_LINE(172)
		this->m_vertices->__get((int)3).StaticCast< ::box2D::common::math::B2Vec2 >()->set(-(hx),hy);
		HX_STACK_LINE(173)
		this->m_normals->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->set(0.0,-1.0);
		HX_STACK_LINE(174)
		this->m_normals->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->set(1.0,0.0);
		HX_STACK_LINE(175)
		this->m_normals->__get((int)2).StaticCast< ::box2D::common::math::B2Vec2 >()->set(0.0,1.0);
		HX_STACK_LINE(176)
		this->m_normals->__get((int)3).StaticCast< ::box2D::common::math::B2Vec2 >()->set(-1.0,0.0);
		HX_STACK_LINE(177)
		this->m_centroid = center;
		HX_STACK_LINE(179)
		::box2D::common::math::B2Transform xf = ::box2D::common::math::B2Transform_obj::__new(null(),null());		HX_STACK_VAR(xf,"xf");
		HX_STACK_LINE(180)
		xf->position = center;
		HX_STACK_LINE(181)
		xf->R->set(angle);
		HX_STACK_LINE(184)
		{
			HX_STACK_LINE(184)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(184)
			int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(184)
			while((true)){
				HX_STACK_LINE(184)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(184)
					break;
				}
				HX_STACK_LINE(184)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(186)
				this->m_vertices[i] = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >());
				HX_STACK_LINE(187)
				this->m_normals[i] = ::box2D::common::math::B2Math_obj::mulMV(xf->R,this->m_normals->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2PolygonShape_obj,setAsOrientedBox,(void))

Void B2PolygonShape_obj::setAsEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","setAsEdge",0x92739d29,"box2D.collision.shapes.B2PolygonShape.setAsEdge","box2D/collision/shapes/B2PolygonShape.hx",202,0xcb7baa99)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v1,"v1")
		HX_STACK_ARG(v2,"v2")
		HX_STACK_LINE(203)
		this->m_vertexCount = (int)2;
		HX_STACK_LINE(204)
		this->reserve((int)2);
		HX_STACK_LINE(205)
		this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->setV(v1);
		HX_STACK_LINE(206)
		this->m_vertices->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->setV(v2);
		HX_STACK_LINE(207)
		this->m_centroid->x = (0.5 * ((v1->x + v2->x)));
		HX_STACK_LINE(208)
		this->m_centroid->y = (0.5 * ((v1->y + v2->y)));
		HX_STACK_LINE(209)
		::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Math_obj::subtractVV(v2,v1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(209)
		this->m_normals[(int)0] = ::box2D::common::math::B2Math_obj::crossVF(_g,1.0);
		HX_STACK_LINE(210)
		this->m_normals->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->normalize();
		HX_STACK_LINE(211)
		this->m_normals->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->x = -(this->m_normals->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x);
		HX_STACK_LINE(212)
		this->m_normals->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->y = -(this->m_normals->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,setAsEdge,(void))

bool B2PolygonShape_obj::testPoint( ::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 p){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","testPoint",0x94c37036,"box2D.collision.shapes.B2PolygonShape.testPoint","box2D/collision/shapes/B2PolygonShape.hx",229,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(xf,"xf")
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(230)
	::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
	HX_STACK_LINE(233)
	::box2D::common::math::B2Mat22 tMat = xf->R;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(234)
	Float tX = (p->x - xf->position->x);		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(235)
	Float tY = (p->y - xf->position->y);		HX_STACK_VAR(tY,"tY");
	HX_STACK_LINE(236)
	Float pLocalX = ((tX * tMat->col1->x) + (tY * tMat->col1->y));		HX_STACK_VAR(pLocalX,"pLocalX");
	HX_STACK_LINE(237)
	Float pLocalY = ((tX * tMat->col2->x) + (tY * tMat->col2->y));		HX_STACK_VAR(pLocalY,"pLocalY");
	HX_STACK_LINE(239)
	{
		HX_STACK_LINE(239)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(239)
		int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(239)
		while((true)){
			HX_STACK_LINE(239)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(239)
				break;
			}
			HX_STACK_LINE(239)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(242)
			tVec = this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
			HX_STACK_LINE(243)
			tX = (pLocalX - tVec->x);
			HX_STACK_LINE(244)
			tY = (pLocalY - tVec->y);
			HX_STACK_LINE(245)
			tVec = this->m_normals->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
			HX_STACK_LINE(246)
			Float dot = ((tVec->x * tX) + (tVec->y * tY));		HX_STACK_VAR(dot,"dot");
			HX_STACK_LINE(247)
			if (((dot > 0.0))){
				HX_STACK_LINE(249)
				return false;
			}
		}
	}
	HX_STACK_LINE(253)
	return true;
}


bool B2PolygonShape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","rayCast",0xea52c561,"box2D.collision.shapes.B2PolygonShape.rayCast","box2D/collision/shapes/B2PolygonShape.hx",260,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(input,"input")
	HX_STACK_ARG(transform,"transform")
	HX_STACK_LINE(261)
	Float lower = 0.0;		HX_STACK_VAR(lower,"lower");
	HX_STACK_LINE(262)
	Float upper = input->maxFraction;		HX_STACK_VAR(upper,"upper");
	HX_STACK_LINE(264)
	Float tX;		HX_STACK_VAR(tX,"tX");
	HX_STACK_LINE(265)
	Float tY;		HX_STACK_VAR(tY,"tY");
	HX_STACK_LINE(266)
	::box2D::common::math::B2Mat22 tMat;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(267)
	::box2D::common::math::B2Vec2 tVec;		HX_STACK_VAR(tVec,"tVec");
	HX_STACK_LINE(271)
	tX = (input->p1->x - transform->position->x);
	HX_STACK_LINE(272)
	tY = (input->p1->y - transform->position->y);
	HX_STACK_LINE(273)
	tMat = transform->R;
	HX_STACK_LINE(274)
	Float p1X = ((tX * tMat->col1->x) + (tY * tMat->col1->y));		HX_STACK_VAR(p1X,"p1X");
	HX_STACK_LINE(275)
	Float p1Y = ((tX * tMat->col2->x) + (tY * tMat->col2->y));		HX_STACK_VAR(p1Y,"p1Y");
	HX_STACK_LINE(277)
	tX = (input->p2->x - transform->position->x);
	HX_STACK_LINE(278)
	tY = (input->p2->y - transform->position->y);
	HX_STACK_LINE(279)
	tMat = transform->R;
	HX_STACK_LINE(280)
	Float p2X = ((tX * tMat->col1->x) + (tY * tMat->col1->y));		HX_STACK_VAR(p2X,"p2X");
	HX_STACK_LINE(281)
	Float p2Y = ((tX * tMat->col2->x) + (tY * tMat->col2->y));		HX_STACK_VAR(p2Y,"p2Y");
	HX_STACK_LINE(283)
	Float dX = (p2X - p1X);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(284)
	Float dY = (p2Y - p1Y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(285)
	int index = (int)-1;		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(287)
	{
		HX_STACK_LINE(287)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(287)
		int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(287)
		while((true)){
			HX_STACK_LINE(287)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(287)
				break;
			}
			HX_STACK_LINE(287)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(294)
			tVec = this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
			HX_STACK_LINE(295)
			tX = (tVec->x - p1X);
			HX_STACK_LINE(296)
			tY = (tVec->y - p1Y);
			HX_STACK_LINE(297)
			tVec = this->m_normals->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
			HX_STACK_LINE(298)
			Float numerator = ((tVec->x * tX) + (tVec->y * tY));		HX_STACK_VAR(numerator,"numerator");
			HX_STACK_LINE(300)
			Float denominator = ((tVec->x * dX) + (tVec->y * dY));		HX_STACK_VAR(denominator,"denominator");
			HX_STACK_LINE(302)
			if (((denominator == 0.0))){
				HX_STACK_LINE(304)
				if (((numerator < 0.0))){
					HX_STACK_LINE(306)
					return false;
				}
			}
			else{
				HX_STACK_LINE(315)
				if (((bool((denominator < 0.0)) && bool((numerator < (lower * denominator)))))){
					HX_STACK_LINE(319)
					lower = (Float(numerator) / Float(denominator));
					HX_STACK_LINE(320)
					index = i;
				}
				else{
					HX_STACK_LINE(322)
					if (((bool((denominator > 0.0)) && bool((numerator < (upper * denominator)))))){
						HX_STACK_LINE(326)
						upper = (Float(numerator) / Float(denominator));
					}
				}
			}
			HX_STACK_LINE(330)
			if (((upper < (lower - 2.2250738585072014e-308)))){
				HX_STACK_LINE(332)
				return false;
			}
		}
	}
	HX_STACK_LINE(338)
	if (((index >= (int)0))){
		HX_STACK_LINE(340)
		output->fraction = lower;
		HX_STACK_LINE(342)
		tMat = transform->R;
		HX_STACK_LINE(343)
		tVec = this->m_normals->__get(index).StaticCast< ::box2D::common::math::B2Vec2 >();
		HX_STACK_LINE(344)
		output->normal->x = ((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y));
		HX_STACK_LINE(345)
		output->normal->y = ((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y));
		HX_STACK_LINE(346)
		return true;
	}
	HX_STACK_LINE(349)
	return false;
}


Void B2PolygonShape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform xf){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","computeAABB",0x953d4d2f,"box2D.collision.shapes.B2PolygonShape.computeAABB","box2D/collision/shapes/B2PolygonShape.hx",357,0xcb7baa99)
		HX_STACK_THIS(this)
		HX_STACK_ARG(aabb,"aabb")
		HX_STACK_ARG(xf,"xf")
		HX_STACK_LINE(359)
		::box2D::common::math::B2Mat22 tMat = xf->R;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(360)
		::box2D::common::math::B2Vec2 tVec = this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(tVec,"tVec");
		HX_STACK_LINE(361)
		Float lowerX = (xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(lowerX,"lowerX");
		HX_STACK_LINE(362)
		Float lowerY = (xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(lowerY,"lowerY");
		HX_STACK_LINE(363)
		Float upperX = lowerX;		HX_STACK_VAR(upperX,"upperX");
		HX_STACK_LINE(364)
		Float upperY = lowerY;		HX_STACK_VAR(upperY,"upperY");
		HX_STACK_LINE(366)
		{
			HX_STACK_LINE(366)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(366)
			int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(366)
			while((true)){
				HX_STACK_LINE(366)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(366)
					break;
				}
				HX_STACK_LINE(366)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(368)
				tVec = this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
				HX_STACK_LINE(369)
				Float vX = (xf->position->x + (((tMat->col1->x * tVec->x) + (tMat->col2->x * tVec->y))));		HX_STACK_VAR(vX,"vX");
				HX_STACK_LINE(370)
				Float vY = (xf->position->y + (((tMat->col1->y * tVec->x) + (tMat->col2->y * tVec->y))));		HX_STACK_VAR(vY,"vY");
				HX_STACK_LINE(371)
				if (((lowerX < vX))){
					HX_STACK_LINE(371)
					lowerX = lowerX;
				}
				else{
					HX_STACK_LINE(371)
					lowerX = vX;
				}
				HX_STACK_LINE(372)
				if (((lowerY < vY))){
					HX_STACK_LINE(372)
					lowerY = lowerY;
				}
				else{
					HX_STACK_LINE(372)
					lowerY = vY;
				}
				HX_STACK_LINE(373)
				if (((upperX > vX))){
					HX_STACK_LINE(373)
					upperX = upperX;
				}
				else{
					HX_STACK_LINE(373)
					upperX = vX;
				}
				HX_STACK_LINE(374)
				if (((upperY > vY))){
					HX_STACK_LINE(374)
					upperY = upperY;
				}
				else{
					HX_STACK_LINE(374)
					upperY = vY;
				}
			}
		}
		HX_STACK_LINE(377)
		aabb->lowerBound->x = (lowerX - this->m_radius);
		HX_STACK_LINE(378)
		aabb->lowerBound->y = (lowerY - this->m_radius);
		HX_STACK_LINE(379)
		aabb->upperBound->x = (upperX + this->m_radius);
		HX_STACK_LINE(380)
		aabb->upperBound->y = (upperY + this->m_radius);
	}
return null();
}


Void B2PolygonShape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,Float density){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","computeMass",0x9d444fa3,"box2D.collision.shapes.B2PolygonShape.computeMass","box2D/collision/shapes/B2PolygonShape.hx",387,0xcb7baa99)
		HX_STACK_THIS(this)
		HX_STACK_ARG(massData,"massData")
		HX_STACK_ARG(density,"density")
		HX_STACK_LINE(415)
		if (((this->m_vertexCount == (int)2))){
			HX_STACK_LINE(417)
			massData->center->x = (0.5 * ((this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x + this->m_vertices->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->x)));
			HX_STACK_LINE(418)
			massData->center->y = (0.5 * ((this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y + this->m_vertices->__get((int)1).StaticCast< ::box2D::common::math::B2Vec2 >()->y)));
			HX_STACK_LINE(419)
			massData->mass = 0.0;
			HX_STACK_LINE(420)
			massData->I = 0.0;
			HX_STACK_LINE(421)
			return null();
		}
		HX_STACK_LINE(425)
		Float centerX = 0.0;		HX_STACK_VAR(centerX,"centerX");
		HX_STACK_LINE(426)
		Float centerY = 0.0;		HX_STACK_VAR(centerY,"centerY");
		HX_STACK_LINE(427)
		Float area = 0.0;		HX_STACK_VAR(area,"area");
		HX_STACK_LINE(428)
		Float I = 0.0;		HX_STACK_VAR(I,"I");
		HX_STACK_LINE(433)
		Float p1X = 0.0;		HX_STACK_VAR(p1X,"p1X");
		HX_STACK_LINE(434)
		Float p1Y = 0.0;		HX_STACK_VAR(p1Y,"p1Y");
		HX_STACK_LINE(444)
		Float k_inv3 = 0.33333333333333331;		HX_STACK_VAR(k_inv3,"k_inv3");
		HX_STACK_LINE(446)
		{
			HX_STACK_LINE(446)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(446)
			int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(446)
			while((true)){
				HX_STACK_LINE(446)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(446)
					break;
				}
				HX_STACK_LINE(446)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(452)
				::box2D::common::math::B2Vec2 p2 = this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(p2,"p2");
				HX_STACK_LINE(454)
				::box2D::common::math::B2Vec2 p3;		HX_STACK_VAR(p3,"p3");
				HX_STACK_LINE(454)
				if ((((i + (int)1) < this->m_vertexCount))){
					HX_STACK_LINE(454)
					int _g2 = ::Std_obj::_int((i + (int)1));		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(454)
					p3 = this->m_vertices->__get(_g2).StaticCast< ::box2D::common::math::B2Vec2 >();
				}
				else{
					HX_STACK_LINE(454)
					p3 = this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >();
				}
				HX_STACK_LINE(457)
				Float e1X = (p2->x - p1X);		HX_STACK_VAR(e1X,"e1X");
				HX_STACK_LINE(458)
				Float e1Y = (p2->y - p1Y);		HX_STACK_VAR(e1Y,"e1Y");
				HX_STACK_LINE(460)
				Float e2X = (p3->x - p1X);		HX_STACK_VAR(e2X,"e2X");
				HX_STACK_LINE(461)
				Float e2Y = (p3->y - p1Y);		HX_STACK_VAR(e2Y,"e2Y");
				HX_STACK_LINE(464)
				Float D = ((e1X * e2Y) - (e1Y * e2X));		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(467)
				Float triangleArea = (0.5 * D);		HX_STACK_VAR(triangleArea,"triangleArea");
				HX_STACK_LINE(468)
				hx::AddEq(area,triangleArea);
				HX_STACK_LINE(472)
				hx::AddEq(centerX,((triangleArea * k_inv3) * (((p1X + p2->x) + p3->x))));
				HX_STACK_LINE(473)
				hx::AddEq(centerY,((triangleArea * k_inv3) * (((p1Y + p2->y) + p3->y))));
				HX_STACK_LINE(476)
				Float px = p1X;		HX_STACK_VAR(px,"px");
				HX_STACK_LINE(477)
				Float py = p1Y;		HX_STACK_VAR(py,"py");
				HX_STACK_LINE(479)
				Float ex1 = e1X;		HX_STACK_VAR(ex1,"ex1");
				HX_STACK_LINE(480)
				Float ey1 = e1Y;		HX_STACK_VAR(ey1,"ey1");
				HX_STACK_LINE(482)
				Float ex2 = e2X;		HX_STACK_VAR(ex2,"ex2");
				HX_STACK_LINE(483)
				Float ey2 = e2Y;		HX_STACK_VAR(ey2,"ey2");
				HX_STACK_LINE(486)
				Float intx2 = ((k_inv3 * (((0.25 * ((((ex1 * ex1) + (ex2 * ex1)) + (ex2 * ex2)))) + (((px * ex1) + (px * ex2)))))) + ((0.5 * px) * px));		HX_STACK_VAR(intx2,"intx2");
				HX_STACK_LINE(488)
				Float inty2 = ((k_inv3 * (((0.25 * ((((ey1 * ey1) + (ey2 * ey1)) + (ey2 * ey2)))) + (((py * ey1) + (py * ey2)))))) + ((0.5 * py) * py));		HX_STACK_VAR(inty2,"inty2");
				HX_STACK_LINE(490)
				hx::AddEq(I,(D * ((intx2 + inty2))));
			}
		}
		HX_STACK_LINE(494)
		massData->mass = (density * area);
		HX_STACK_LINE(499)
		hx::MultEq(centerX,(Float(1.0) / Float(area)));
		HX_STACK_LINE(500)
		hx::MultEq(centerY,(Float(1.0) / Float(area)));
		HX_STACK_LINE(502)
		massData->center->set(centerX,centerY);
		HX_STACK_LINE(505)
		massData->I = (density * I);
	}
return null();
}


Float B2PolygonShape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,Float offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","computeSubmergedArea",0x47dae94a,"box2D.collision.shapes.B2PolygonShape.computeSubmergedArea","box2D/collision/shapes/B2PolygonShape.hx",516,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(normal,"normal")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(xf,"xf")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(518)
	::box2D::common::math::B2Vec2 normalL = ::box2D::common::math::B2Math_obj::mulTMV(xf->R,normal);		HX_STACK_VAR(normalL,"normalL");
	HX_STACK_LINE(519)
	Float _g = ::box2D::common::math::B2Math_obj::dot(normal,xf->position);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(519)
	Float offsetL = (offset - _g);		HX_STACK_VAR(offsetL,"offsetL");
	HX_STACK_LINE(521)
	Array< Float > depths = Array_obj< Float >::__new();		HX_STACK_VAR(depths,"depths");
	HX_STACK_LINE(522)
	int diveCount = (int)0;		HX_STACK_VAR(diveCount,"diveCount");
	HX_STACK_LINE(523)
	int intoIndex = (int)-1;		HX_STACK_VAR(intoIndex,"intoIndex");
	HX_STACK_LINE(524)
	int outoIndex = (int)-1;		HX_STACK_VAR(outoIndex,"outoIndex");
	HX_STACK_LINE(526)
	bool lastSubmerged = false;		HX_STACK_VAR(lastSubmerged,"lastSubmerged");
	HX_STACK_LINE(527)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(528)
	{
		HX_STACK_LINE(528)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(528)
		int _g2 = this->m_vertexCount;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(528)
		while((true)){
			HX_STACK_LINE(528)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(528)
				break;
			}
			HX_STACK_LINE(528)
			int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
			HX_STACK_LINE(530)
			Float _g11 = ::box2D::common::math::B2Math_obj::dot(normalL,this->m_vertices->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >());		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(530)
			depths[i1] = (_g11 - offsetL);
			HX_STACK_LINE(531)
			bool isSubmerged = (depths->__get(i1) < -2.2250738585072014e-308);		HX_STACK_VAR(isSubmerged,"isSubmerged");
			HX_STACK_LINE(532)
			if (((i1 > (int)0))){
				HX_STACK_LINE(534)
				if ((isSubmerged)){
					HX_STACK_LINE(536)
					if ((!(lastSubmerged))){
						HX_STACK_LINE(538)
						intoIndex = (i1 - (int)1);
						HX_STACK_LINE(539)
						(diveCount)++;
					}
				}
				else{
					HX_STACK_LINE(544)
					if ((lastSubmerged)){
						HX_STACK_LINE(546)
						outoIndex = (i1 - (int)1);
						HX_STACK_LINE(547)
						(diveCount)++;
					}
				}
			}
			HX_STACK_LINE(551)
			lastSubmerged = isSubmerged;
		}
	}
	HX_STACK_LINE(553)
	switch( (int)(diveCount)){
		case (int)0: {
			HX_STACK_LINE(556)
			if ((lastSubmerged)){
				HX_STACK_LINE(559)
				::box2D::collision::shapes::B2MassData md = ::box2D::collision::shapes::B2MassData_obj::__new();		HX_STACK_VAR(md,"md");
				HX_STACK_LINE(560)
				this->computeMass(md,(int)1);
				HX_STACK_LINE(561)
				::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Math_obj::mulX(xf,md->center);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(561)
				c->setV(_g2);
				HX_STACK_LINE(562)
				return md->mass;
			}
			else{
				HX_STACK_LINE(567)
				return (int)0;
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(571)
			if (((intoIndex == (int)-1))){
				HX_STACK_LINE(573)
				intoIndex = (this->m_vertexCount - (int)1);
			}
			else{
				HX_STACK_LINE(577)
				outoIndex = (this->m_vertexCount - (int)1);
			}
		}
		;break;
	}
	HX_STACK_LINE(581)
	int intoIndex2 = hx::Mod(((intoIndex + (int)1)),this->m_vertexCount);		HX_STACK_VAR(intoIndex2,"intoIndex2");
	HX_STACK_LINE(582)
	int outoIndex2 = hx::Mod(((outoIndex + (int)1)),this->m_vertexCount);		HX_STACK_VAR(outoIndex2,"outoIndex2");
	HX_STACK_LINE(583)
	Float intoLamdda = (Float((((int)0 - depths->__get(intoIndex)))) / Float(((depths->__get(intoIndex2) - depths->__get(intoIndex)))));		HX_STACK_VAR(intoLamdda,"intoLamdda");
	HX_STACK_LINE(584)
	Float outoLamdda = (Float((((int)0 - depths->__get(outoIndex)))) / Float(((depths->__get(outoIndex2) - depths->__get(outoIndex)))));		HX_STACK_VAR(outoLamdda,"outoLamdda");
	HX_STACK_LINE(586)
	::box2D::common::math::B2Vec2 intoVec = ::box2D::common::math::B2Vec2_obj::__new(((this->m_vertices->__get(intoIndex).StaticCast< ::box2D::common::math::B2Vec2 >()->x * (((int)1 - intoLamdda))) + (this->m_vertices->__get(intoIndex2).StaticCast< ::box2D::common::math::B2Vec2 >()->x * intoLamdda)),((this->m_vertices->__get(intoIndex).StaticCast< ::box2D::common::math::B2Vec2 >()->y * (((int)1 - intoLamdda))) + (this->m_vertices->__get(intoIndex2).StaticCast< ::box2D::common::math::B2Vec2 >()->y * intoLamdda)));		HX_STACK_VAR(intoVec,"intoVec");
	HX_STACK_LINE(588)
	::box2D::common::math::B2Vec2 outoVec = ::box2D::common::math::B2Vec2_obj::__new(((this->m_vertices->__get(outoIndex).StaticCast< ::box2D::common::math::B2Vec2 >()->x * (((int)1 - outoLamdda))) + (this->m_vertices->__get(outoIndex2).StaticCast< ::box2D::common::math::B2Vec2 >()->x * outoLamdda)),((this->m_vertices->__get(outoIndex).StaticCast< ::box2D::common::math::B2Vec2 >()->y * (((int)1 - outoLamdda))) + (this->m_vertices->__get(outoIndex2).StaticCast< ::box2D::common::math::B2Vec2 >()->y * outoLamdda)));		HX_STACK_VAR(outoVec,"outoVec");
	HX_STACK_LINE(592)
	Float area = (int)0;		HX_STACK_VAR(area,"area");
	HX_STACK_LINE(593)
	::box2D::common::math::B2Vec2 center = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(center,"center");
	HX_STACK_LINE(594)
	::box2D::common::math::B2Vec2 p2 = this->m_vertices->__get(intoIndex2).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(p2,"p2");
	HX_STACK_LINE(595)
	::box2D::common::math::B2Vec2 p3;		HX_STACK_VAR(p3,"p3");
	HX_STACK_LINE(598)
	i = intoIndex2;
	HX_STACK_LINE(599)
	while((true)){
		HX_STACK_LINE(599)
		if ((!(((i != outoIndex2))))){
			HX_STACK_LINE(599)
			break;
		}
		HX_STACK_LINE(601)
		i = hx::Mod(((i + (int)1)),this->m_vertexCount);
		HX_STACK_LINE(602)
		if (((i == outoIndex2))){
			HX_STACK_LINE(603)
			p3 = outoVec;
		}
		else{
			HX_STACK_LINE(605)
			p3 = this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();
		}
		HX_STACK_LINE(607)
		Float triangleArea = (0.5 * (((((p2->x - intoVec->x)) * ((p3->y - intoVec->y))) - (((p2->y - intoVec->y)) * ((p3->x - intoVec->x))))));		HX_STACK_VAR(triangleArea,"triangleArea");
		HX_STACK_LINE(608)
		hx::AddEq(area,triangleArea);
		HX_STACK_LINE(610)
		hx::AddEq(center->x,(Float((triangleArea * (((intoVec->x + p2->x) + p3->x)))) / Float((int)3)));
		HX_STACK_LINE(611)
		hx::AddEq(center->y,(Float((triangleArea * (((intoVec->y + p2->y) + p3->y)))) / Float((int)3)));
		HX_STACK_LINE(613)
		p2 = p3;
	}
	HX_STACK_LINE(617)
	center->multiply((Float((int)1) / Float(area)));
	HX_STACK_LINE(618)
	::box2D::common::math::B2Vec2 _g3 = ::box2D::common::math::B2Math_obj::mulX(xf,center);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(618)
	c->setV(_g3);
	HX_STACK_LINE(620)
	return area;
}


int B2PolygonShape_obj::getVertexCount( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","getVertexCount",0xd1c59d3d,"box2D.collision.shapes.B2PolygonShape.getVertexCount","box2D/collision/shapes/B2PolygonShape.hx",627,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_LINE(627)
	return this->m_vertexCount;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,getVertexCount,return )

Array< ::Dynamic > B2PolygonShape_obj::getVertices( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","getVertices",0x62c79647,"box2D.collision.shapes.B2PolygonShape.getVertices","box2D/collision/shapes/B2PolygonShape.hx",634,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_LINE(634)
	return this->m_vertices;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,getVertices,return )

Array< ::Dynamic > B2PolygonShape_obj::getNormals( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","getNormals",0x01585dde,"box2D.collision.shapes.B2PolygonShape.getNormals","box2D/collision/shapes/B2PolygonShape.hx",642,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_LINE(642)
	return this->m_normals;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,getNormals,return )

int B2PolygonShape_obj::getSupport( ::box2D::common::math::B2Vec2 d){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","getSupport",0x12a0f981,"box2D.collision.shapes.B2PolygonShape.getSupport","box2D/collision/shapes/B2PolygonShape.hx",649,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(650)
	int bestIndex = (int)0;		HX_STACK_VAR(bestIndex,"bestIndex");
	HX_STACK_LINE(651)
	Float bestValue = ((this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(bestValue,"bestValue");
	HX_STACK_LINE(652)
	{
		HX_STACK_LINE(652)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(652)
		int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(652)
		while((true)){
			HX_STACK_LINE(652)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(652)
				break;
			}
			HX_STACK_LINE(652)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(654)
			Float value = ((this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(655)
			if (((value > bestValue))){
				HX_STACK_LINE(657)
				bestIndex = i;
				HX_STACK_LINE(658)
				bestValue = value;
			}
		}
	}
	HX_STACK_LINE(661)
	return bestIndex;
}


HX_DEFINE_DYNAMIC_FUNC1(B2PolygonShape_obj,getSupport,return )

::box2D::common::math::B2Vec2 B2PolygonShape_obj::getSupportVertex( ::box2D::common::math::B2Vec2 d){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","getSupportVertex",0xf54edfc5,"box2D.collision.shapes.B2PolygonShape.getSupportVertex","box2D/collision/shapes/B2PolygonShape.hx",665,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(666)
	int bestIndex = (int)0;		HX_STACK_VAR(bestIndex,"bestIndex");
	HX_STACK_LINE(667)
	Float bestValue = ((this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(bestValue,"bestValue");
	HX_STACK_LINE(668)
	{
		HX_STACK_LINE(668)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(668)
		int _g = this->m_vertexCount;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(668)
		while((true)){
			HX_STACK_LINE(668)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(668)
				break;
			}
			HX_STACK_LINE(668)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(670)
			Float value = ((this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(671)
			if (((value > bestValue))){
				HX_STACK_LINE(673)
				bestIndex = i;
				HX_STACK_LINE(674)
				bestValue = value;
			}
		}
	}
	HX_STACK_LINE(677)
	return this->m_vertices->__get(bestIndex).StaticCast< ::box2D::common::math::B2Vec2 >();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PolygonShape_obj,getSupportVertex,return )

bool B2PolygonShape_obj::validate( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","validate",0xb3680dfe,"box2D.collision.shapes.B2PolygonShape.validate","box2D/collision/shapes/B2PolygonShape.hx",716,0xcb7baa99)
	HX_STACK_THIS(this)
	HX_STACK_LINE(716)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(B2PolygonShape_obj,validate,return )

Void B2PolygonShape_obj::reserve( int count){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","reserve",0x25dee5d4,"box2D.collision.shapes.B2PolygonShape.reserve","box2D/collision/shapes/B2PolygonShape.hx",737,0xcb7baa99)
		HX_STACK_THIS(this)
		HX_STACK_ARG(count,"count")
		HX_STACK_LINE(737)
		int _g = this->m_vertices->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(737)
		while((true)){
			HX_STACK_LINE(737)
			if ((!(((_g < count))))){
				HX_STACK_LINE(737)
				break;
			}
			HX_STACK_LINE(737)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(739)
			this->m_vertices[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
			HX_STACK_LINE(740)
			this->m_normals[i] = ::box2D::common::math::B2Vec2_obj::__new(null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2PolygonShape_obj,reserve,(void))

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asArray( Dynamic vertices,Float vertexCount){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","asArray",0x3a7fc2df,"box2D.collision.shapes.B2PolygonShape.asArray","box2D/collision/shapes/B2PolygonShape.hx",80,0xcb7baa99)
	HX_STACK_ARG(vertices,"vertices")
	HX_STACK_ARG(vertexCount,"vertexCount")
	HX_STACK_LINE(81)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();		HX_STACK_VAR(polygonShape,"polygonShape");
	HX_STACK_LINE(82)
	polygonShape->setAsArray(vertices,vertexCount);
	HX_STACK_LINE(83)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asArray,return )

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asVector( Array< ::Dynamic > vertices,Float vertexCount){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","asVector",0xd4b7f8bd,"box2D.collision.shapes.B2PolygonShape.asVector","box2D/collision/shapes/B2PolygonShape.hx",124,0xcb7baa99)
	HX_STACK_ARG(vertices,"vertices")
	HX_STACK_ARG(vertexCount,"vertexCount")
	HX_STACK_LINE(125)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();		HX_STACK_VAR(polygonShape,"polygonShape");
	HX_STACK_LINE(126)
	polygonShape->setAsVector(vertices,vertexCount);
	HX_STACK_LINE(127)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asVector,return )

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asBox( Float hx,Float hy){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","asBox",0x712115d1,"box2D.collision.shapes.B2PolygonShape.asBox","box2D/collision/shapes/B2PolygonShape.hx",151,0xcb7baa99)
	HX_STACK_ARG(hx,"hx")
	HX_STACK_ARG(hy,"hy")
	HX_STACK_LINE(152)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();		HX_STACK_VAR(polygonShape,"polygonShape");
	HX_STACK_LINE(153)
	polygonShape->setAsBox(hx,hy);
	HX_STACK_LINE(154)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asBox,return )

::box2D::common::math::B2Mat22 B2PolygonShape_obj::s_mat;

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asOrientedBox( Float hx,Float hy,::box2D::common::math::B2Vec2 center,hx::Null< Float >  __o_angle){
Float angle = __o_angle.Default(0.0);
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","asOrientedBox",0xa924cccd,"box2D.collision.shapes.B2PolygonShape.asOrientedBox","box2D/collision/shapes/B2PolygonShape.hx",192,0xcb7baa99)
	HX_STACK_ARG(hx,"hx")
	HX_STACK_ARG(hy,"hy")
	HX_STACK_ARG(center,"center")
	HX_STACK_ARG(angle,"angle")
{
		HX_STACK_LINE(193)
		::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();		HX_STACK_VAR(polygonShape,"polygonShape");
		HX_STACK_LINE(194)
		polygonShape->setAsOrientedBox(hx,hy,center,angle);
		HX_STACK_LINE(195)
		return polygonShape;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(B2PolygonShape_obj,asOrientedBox,return )

::box2D::collision::shapes::B2PolygonShape B2PolygonShape_obj::asEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","asEdge",0x8dc53db7,"box2D.collision.shapes.B2PolygonShape.asEdge","box2D/collision/shapes/B2PolygonShape.hx",219,0xcb7baa99)
	HX_STACK_ARG(v1,"v1")
	HX_STACK_ARG(v2,"v2")
	HX_STACK_LINE(220)
	::box2D::collision::shapes::B2PolygonShape polygonShape = ::box2D::collision::shapes::B2PolygonShape_obj::__new();		HX_STACK_VAR(polygonShape,"polygonShape");
	HX_STACK_LINE(221)
	polygonShape->setAsEdge(v1,v2);
	HX_STACK_LINE(222)
	return polygonShape;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,asEdge,return )

::box2D::common::math::B2Vec2 B2PolygonShape_obj::computeCentroid( Array< ::Dynamic > vs,int count){
	HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","computeCentroid",0x5b12726f,"box2D.collision.shapes.B2PolygonShape.computeCentroid","box2D/collision/shapes/B2PolygonShape.hx",761,0xcb7baa99)
	HX_STACK_ARG(vs,"vs")
	HX_STACK_ARG(count,"count")
	HX_STACK_LINE(765)
	::box2D::common::math::B2Vec2 c = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(766)
	Float area = 0.0;		HX_STACK_VAR(area,"area");
	HX_STACK_LINE(771)
	Float p1X = 0.0;		HX_STACK_VAR(p1X,"p1X");
	HX_STACK_LINE(772)
	Float p1Y = 0.0;		HX_STACK_VAR(p1Y,"p1Y");
	HX_STACK_LINE(774)
	Float inv3 = 0.33333333333333331;		HX_STACK_VAR(inv3,"inv3");
	HX_STACK_LINE(776)
	{
		HX_STACK_LINE(776)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(776)
		while((true)){
			HX_STACK_LINE(776)
			if ((!(((_g < count))))){
				HX_STACK_LINE(776)
				break;
			}
			HX_STACK_LINE(776)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(782)
			::box2D::common::math::B2Vec2 p2 = vs->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(p2,"p2");
			HX_STACK_LINE(784)
			::box2D::common::math::B2Vec2 p3;		HX_STACK_VAR(p3,"p3");
			HX_STACK_LINE(784)
			if ((((i + (int)1) < count))){
				HX_STACK_LINE(784)
				int _g1 = ::Std_obj::_int((i + (int)1));		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(784)
				p3 = vs->__get(_g1).StaticCast< ::box2D::common::math::B2Vec2 >();
			}
			else{
				HX_STACK_LINE(784)
				p3 = vs->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >();
			}
			HX_STACK_LINE(787)
			Float e1X = (p2->x - p1X);		HX_STACK_VAR(e1X,"e1X");
			HX_STACK_LINE(788)
			Float e1Y = (p2->y - p1Y);		HX_STACK_VAR(e1Y,"e1Y");
			HX_STACK_LINE(790)
			Float e2X = (p3->x - p1X);		HX_STACK_VAR(e2X,"e2X");
			HX_STACK_LINE(791)
			Float e2Y = (p3->y - p1Y);		HX_STACK_VAR(e2Y,"e2Y");
			HX_STACK_LINE(794)
			Float D = ((e1X * e2Y) - (e1Y * e2X));		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(797)
			Float triangleArea = (0.5 * D);		HX_STACK_VAR(triangleArea,"triangleArea");
			HX_STACK_LINE(798)
			hx::AddEq(area,triangleArea);
			HX_STACK_LINE(802)
			hx::AddEq(c->x,((triangleArea * inv3) * (((p1X + p2->x) + p3->x))));
			HX_STACK_LINE(803)
			hx::AddEq(c->y,((triangleArea * inv3) * (((p1Y + p2->y) + p3->y))));
		}
	}
	HX_STACK_LINE(809)
	hx::MultEq(c->x,(Float(1.0) / Float(area)));
	HX_STACK_LINE(810)
	hx::MultEq(c->y,(Float(1.0) / Float(area)));
	HX_STACK_LINE(811)
	return c;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2PolygonShape_obj,computeCentroid,return )

Void B2PolygonShape_obj::computeOBB( ::box2D::collision::B2OBB obb,Array< ::Dynamic > vs,int count){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2PolygonShape","computeOBB",0xbaaf1020,"box2D.collision.shapes.B2PolygonShape.computeOBB","box2D/collision/shapes/B2PolygonShape.hx",819,0xcb7baa99)
		HX_STACK_ARG(obb,"obb")
		HX_STACK_ARG(vs,"vs")
		HX_STACK_ARG(count,"count")
		HX_STACK_LINE(820)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(821)
		Array< ::Dynamic > p = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(822)
		{
			HX_STACK_LINE(822)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(822)
			while((true)){
				HX_STACK_LINE(822)
				if ((!(((_g < count))))){
					HX_STACK_LINE(822)
					break;
				}
				HX_STACK_LINE(822)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(824)
				p[i1] = vs->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >();
			}
		}
		HX_STACK_LINE(826)
		p[count] = p->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >();
		HX_STACK_LINE(828)
		Float minArea = 1.7976931348623158e+308;		HX_STACK_VAR(minArea,"minArea");
		HX_STACK_LINE(830)
		{
			HX_STACK_LINE(830)
			int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(830)
			int _g = (count + (int)1);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(830)
			while((true)){
				HX_STACK_LINE(830)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(830)
					break;
				}
				HX_STACK_LINE(830)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(832)
				int _g2 = ::Std_obj::_int((i1 - (int)1));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(832)
				::box2D::common::math::B2Vec2 root = p->__get(_g2).StaticCast< ::box2D::common::math::B2Vec2 >();		HX_STACK_VAR(root,"root");
				HX_STACK_LINE(834)
				Float uxX = (p->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->x - root->x);		HX_STACK_VAR(uxX,"uxX");
				HX_STACK_LINE(835)
				Float uxY = (p->__get(i1).StaticCast< ::box2D::common::math::B2Vec2 >()->y - root->y);		HX_STACK_VAR(uxY,"uxY");
				HX_STACK_LINE(837)
				Float length = ::Math_obj::sqrt(((uxX * uxX) + (uxY * uxY)));		HX_STACK_VAR(length,"length");
				HX_STACK_LINE(838)
				hx::DivEq(uxX,length);
				HX_STACK_LINE(839)
				hx::DivEq(uxY,length);
				HX_STACK_LINE(842)
				Float uyX = -(uxY);		HX_STACK_VAR(uyX,"uyX");
				HX_STACK_LINE(843)
				Float uyY = uxX;		HX_STACK_VAR(uyY,"uyY");
				HX_STACK_LINE(845)
				Float lowerX = 1.7976931348623158e+308;		HX_STACK_VAR(lowerX,"lowerX");
				HX_STACK_LINE(846)
				Float lowerY = 1.7976931348623158e+308;		HX_STACK_VAR(lowerY,"lowerY");
				HX_STACK_LINE(848)
				Float upperX = -1.7976931348623157e+308;		HX_STACK_VAR(upperX,"upperX");
				HX_STACK_LINE(849)
				Float upperY = -1.7976931348623157e+308;		HX_STACK_VAR(upperY,"upperY");
				HX_STACK_LINE(851)
				{
					HX_STACK_LINE(851)
					int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(851)
					while((true)){
						HX_STACK_LINE(851)
						if ((!(((_g21 < count))))){
							HX_STACK_LINE(851)
							break;
						}
						HX_STACK_LINE(851)
						int j = (_g21)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(854)
						Float dX = (p->__get(j).StaticCast< ::box2D::common::math::B2Vec2 >()->x - root->x);		HX_STACK_VAR(dX,"dX");
						HX_STACK_LINE(855)
						Float dY = (p->__get(j).StaticCast< ::box2D::common::math::B2Vec2 >()->y - root->y);		HX_STACK_VAR(dY,"dY");
						HX_STACK_LINE(858)
						Float rX = ((uxX * dX) + (uxY * dY));		HX_STACK_VAR(rX,"rX");
						HX_STACK_LINE(860)
						Float rY = ((uyX * dX) + (uyY * dY));		HX_STACK_VAR(rY,"rY");
						HX_STACK_LINE(862)
						if (((rX < lowerX))){
							HX_STACK_LINE(862)
							lowerX = rX;
						}
						HX_STACK_LINE(863)
						if (((rY < lowerY))){
							HX_STACK_LINE(863)
							lowerY = rY;
						}
						HX_STACK_LINE(865)
						if (((rX > upperX))){
							HX_STACK_LINE(865)
							upperX = rX;
						}
						HX_STACK_LINE(866)
						if (((rY > upperY))){
							HX_STACK_LINE(866)
							upperY = rY;
						}
					}
				}
				HX_STACK_LINE(869)
				Float area = (((upperX - lowerX)) * ((upperY - lowerY)));		HX_STACK_VAR(area,"area");
				HX_STACK_LINE(870)
				if (((area < (0.95 * minArea)))){
					HX_STACK_LINE(872)
					minArea = area;
					HX_STACK_LINE(874)
					obb->R->col1->x = uxX;
					HX_STACK_LINE(875)
					obb->R->col1->y = uxY;
					HX_STACK_LINE(877)
					obb->R->col2->x = uyX;
					HX_STACK_LINE(878)
					obb->R->col2->y = uyY;
					HX_STACK_LINE(880)
					Float centerX = (0.5 * ((lowerX + upperX)));		HX_STACK_VAR(centerX,"centerX");
					HX_STACK_LINE(881)
					Float centerY = (0.5 * ((lowerY + upperY)));		HX_STACK_VAR(centerY,"centerY");
					HX_STACK_LINE(883)
					::box2D::common::math::B2Mat22 tMat = obb->R;		HX_STACK_VAR(tMat,"tMat");
					HX_STACK_LINE(884)
					obb->center->x = (root->x + (((tMat->col1->x * centerX) + (tMat->col2->x * centerY))));
					HX_STACK_LINE(885)
					obb->center->y = (root->y + (((tMat->col1->y * centerX) + (tMat->col2->y * centerY))));
					HX_STACK_LINE(887)
					obb->extents->x = (0.5 * ((upperX - lowerX)));
					HX_STACK_LINE(888)
					obb->extents->y = (0.5 * ((upperY - lowerY)));
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(B2PolygonShape_obj,computeOBB,(void))


B2PolygonShape_obj::B2PolygonShape_obj()
{
}

void B2PolygonShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2PolygonShape);
	HX_MARK_MEMBER_NAME(m_centroid,"m_centroid");
	HX_MARK_MEMBER_NAME(m_vertices,"m_vertices");
	HX_MARK_MEMBER_NAME(m_normals,"m_normals");
	HX_MARK_MEMBER_NAME(m_vertexCount,"m_vertexCount");
	HX_MARK_END_CLASS();
}

void B2PolygonShape_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_centroid,"m_centroid");
	HX_VISIT_MEMBER_NAME(m_vertices,"m_vertices");
	HX_VISIT_MEMBER_NAME(m_normals,"m_normals");
	HX_VISIT_MEMBER_NAME(m_vertexCount,"m_vertexCount");
}

Dynamic B2PolygonShape_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"asBox") ) { return asBox_dyn(); }
		if (HX_FIELD_EQ(inName,"s_mat") ) { return s_mat; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"asEdge") ) { return asEdge_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"asArray") ) { return asArray_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"reserve") ) { return reserve_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"asVector") ) { return asVector_dyn(); }
		if (HX_FIELD_EQ(inName,"setAsBox") ) { return setAsBox_dyn(); }
		if (HX_FIELD_EQ(inName,"validate") ) { return validate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setAsEdge") ) { return setAsEdge_dyn(); }
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"m_normals") ) { return m_normals; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"computeOBB") ) { return computeOBB_dyn(); }
		if (HX_FIELD_EQ(inName,"setAsArray") ) { return setAsArray_dyn(); }
		if (HX_FIELD_EQ(inName,"getNormals") ) { return getNormals_dyn(); }
		if (HX_FIELD_EQ(inName,"getSupport") ) { return getSupport_dyn(); }
		if (HX_FIELD_EQ(inName,"m_centroid") ) { return m_centroid; }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { return m_vertices; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setAsVector") ) { return setAsVector_dyn(); }
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		if (HX_FIELD_EQ(inName,"getVertices") ) { return getVertices_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"asOrientedBox") ) { return asOrientedBox_dyn(); }
		if (HX_FIELD_EQ(inName,"m_vertexCount") ) { return m_vertexCount; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getVertexCount") ) { return getVertexCount_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"computeCentroid") ) { return computeCentroid_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setAsOrientedBox") ) { return setAsOrientedBox_dyn(); }
		if (HX_FIELD_EQ(inName,"getSupportVertex") ) { return getSupportVertex_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2PolygonShape_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"s_mat") ) { s_mat=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_normals") ) { m_normals=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_centroid") ) { m_centroid=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { m_vertices=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_vertexCount") ) { m_vertexCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2PolygonShape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_centroid"));
	outFields->push(HX_CSTRING("m_vertices"));
	outFields->push(HX_CSTRING("m_normals"));
	outFields->push(HX_CSTRING("m_vertexCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("asArray"),
	HX_CSTRING("asVector"),
	HX_CSTRING("asBox"),
	HX_CSTRING("s_mat"),
	HX_CSTRING("asOrientedBox"),
	HX_CSTRING("asEdge"),
	HX_CSTRING("computeCentroid"),
	HX_CSTRING("computeOBB"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2PolygonShape_obj,m_centroid),HX_CSTRING("m_centroid")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2PolygonShape_obj,m_vertices),HX_CSTRING("m_vertices")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2PolygonShape_obj,m_normals),HX_CSTRING("m_normals")},
	{hx::fsInt,(int)offsetof(B2PolygonShape_obj,m_vertexCount),HX_CSTRING("m_vertexCount")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("copy"),
	HX_CSTRING("set"),
	HX_CSTRING("setAsArray"),
	HX_CSTRING("setAsVector"),
	HX_CSTRING("setAsBox"),
	HX_CSTRING("setAsOrientedBox"),
	HX_CSTRING("setAsEdge"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("getVertexCount"),
	HX_CSTRING("getVertices"),
	HX_CSTRING("getNormals"),
	HX_CSTRING("getSupport"),
	HX_CSTRING("getSupportVertex"),
	HX_CSTRING("validate"),
	HX_CSTRING("reserve"),
	HX_CSTRING("m_centroid"),
	HX_CSTRING("m_vertices"),
	HX_CSTRING("m_normals"),
	HX_CSTRING("m_vertexCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2PolygonShape_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2PolygonShape_obj::s_mat,"s_mat");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2PolygonShape_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2PolygonShape_obj::s_mat,"s_mat");
};

#endif

Class B2PolygonShape_obj::__mClass;

void B2PolygonShape_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2PolygonShape"), hx::TCanCast< B2PolygonShape_obj> ,sStaticFields,sMemberFields,
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

void B2PolygonShape_obj::__boot()
{
	s_mat= ::box2D::common::math::B2Mat22_obj::__new();
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
