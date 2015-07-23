#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2DistanceProxy
#include <box2D/collision/B2DistanceProxy.h>
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
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2DistanceProxy_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2DistanceProxy","new",0xe841e30e,"box2D.collision.B2DistanceProxy.new","box2D/collision/B2DistanceProxy.hx",34,0x90381be4)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(129)
	this->m_radius = (int)0;
	HX_STACK_LINE(128)
	this->m_count = (int)0;
	HX_STACK_LINE(123)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(123)
	this->m_vertices = _g;
}
;
	return null();
}

//B2DistanceProxy_obj::~B2DistanceProxy_obj() { }

Dynamic B2DistanceProxy_obj::__CreateEmpty() { return  new B2DistanceProxy_obj; }
hx::ObjectPtr< B2DistanceProxy_obj > B2DistanceProxy_obj::__new()
{  hx::ObjectPtr< B2DistanceProxy_obj > result = new B2DistanceProxy_obj();
	result->__construct();
	return result;}

Dynamic B2DistanceProxy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DistanceProxy_obj > result = new B2DistanceProxy_obj();
	result->__construct();
	return result;}

Void B2DistanceProxy_obj::set( ::box2D::collision::shapes::B2Shape shape){
{
		HX_STACK_FRAME("box2D.collision.B2DistanceProxy","set",0xe845ae50,"box2D.collision.B2DistanceProxy.set","box2D/collision/B2DistanceProxy.hx",42,0x90381be4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(shape,"shape")
		HX_STACK_LINE(42)
		int _g = shape->getType();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		switch( (int)(_g)){
			case (int)1: {
				HX_STACK_LINE(46)
				::box2D::collision::shapes::B2CircleShape circle;		HX_STACK_VAR(circle,"circle");
				HX_STACK_LINE(46)
				circle = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(shape);
				HX_STACK_LINE(47)
				Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(47)
				this->m_vertices = _g1;
				HX_STACK_LINE(48)
				this->m_vertices[(int)0] = circle->m_p;
				HX_STACK_LINE(49)
				this->m_count = (int)1;
				HX_STACK_LINE(50)
				this->m_radius = circle->m_radius;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(55)
				::box2D::collision::shapes::B2PolygonShape polygon;		HX_STACK_VAR(polygon,"polygon");
				HX_STACK_LINE(55)
				polygon = hx::TCast< box2D::collision::shapes::B2PolygonShape >::cast(shape);
				HX_STACK_LINE(56)
				this->m_vertices = polygon->m_vertices;
				HX_STACK_LINE(57)
				this->m_count = polygon->m_vertexCount;
				HX_STACK_LINE(58)
				this->m_radius = polygon->m_radius;
			}
			;break;
			default: {
				HX_STACK_LINE(62)
				::box2D::common::B2Settings_obj::b2Assert(false);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,set,(void))

Float B2DistanceProxy_obj::getSupport( ::box2D::common::math::B2Vec2 d){
	HX_STACK_FRAME("box2D.collision.B2DistanceProxy","getSupport",0x0aa6512b,"box2D.collision.B2DistanceProxy.getSupport","box2D/collision/B2DistanceProxy.hx",70,0x90381be4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(71)
	int bestIndex = (int)0;		HX_STACK_VAR(bestIndex,"bestIndex");
	HX_STACK_LINE(72)
	Float bestValue = ((this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(bestValue,"bestValue");
	HX_STACK_LINE(73)
	{
		HX_STACK_LINE(73)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(73)
		int _g = this->m_count;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(73)
		while((true)){
			HX_STACK_LINE(73)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(73)
				break;
			}
			HX_STACK_LINE(73)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(75)
			Float value = ((this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(76)
			if (((value > bestValue))){
				HX_STACK_LINE(78)
				bestIndex = i;
				HX_STACK_LINE(79)
				bestValue = value;
			}
		}
	}
	HX_STACK_LINE(82)
	return bestIndex;
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,getSupport,return )

::box2D::common::math::B2Vec2 B2DistanceProxy_obj::getSupportVertex( ::box2D::common::math::B2Vec2 d){
	HX_STACK_FRAME("box2D.collision.B2DistanceProxy","getSupportVertex",0xa7b052ef,"box2D.collision.B2DistanceProxy.getSupportVertex","box2D/collision/B2DistanceProxy.hx",89,0x90381be4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(d,"d")
	HX_STACK_LINE(90)
	int bestIndex = (int)0;		HX_STACK_VAR(bestIndex,"bestIndex");
	HX_STACK_LINE(91)
	Float bestValue = ((this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get((int)0).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(bestValue,"bestValue");
	HX_STACK_LINE(92)
	{
		HX_STACK_LINE(92)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(92)
		int _g = this->m_count;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(92)
		while((true)){
			HX_STACK_LINE(92)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(92)
				break;
			}
			HX_STACK_LINE(92)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(94)
			Float value = ((this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->x * d->x) + (this->m_vertices->__get(i).StaticCast< ::box2D::common::math::B2Vec2 >()->y * d->y));		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(95)
			if (((value > bestValue))){
				HX_STACK_LINE(97)
				bestIndex = i;
				HX_STACK_LINE(98)
				bestValue = value;
			}
		}
	}
	HX_STACK_LINE(101)
	return this->m_vertices->__get(bestIndex).StaticCast< ::box2D::common::math::B2Vec2 >();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,getSupportVertex,return )

int B2DistanceProxy_obj::getVertexCount( ){
	HX_STACK_FRAME("box2D.collision.B2DistanceProxy","getVertexCount",0x6ee111e7,"box2D.collision.B2DistanceProxy.getVertexCount","box2D/collision/B2DistanceProxy.hx",108,0x90381be4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(108)
	return this->m_count;
}


HX_DEFINE_DYNAMIC_FUNC0(B2DistanceProxy_obj,getVertexCount,return )

::box2D::common::math::B2Vec2 B2DistanceProxy_obj::getVertex( int index){
	HX_STACK_FRAME("box2D.collision.B2DistanceProxy","getVertex",0x71fcadc8,"box2D.collision.B2DistanceProxy.getVertex","box2D/collision/B2DistanceProxy.hx",115,0x90381be4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(index,"index")
	HX_STACK_LINE(116)
	::box2D::common::B2Settings_obj::b2Assert((bool(((int)0 <= index)) && bool((index < this->m_count))));
	HX_STACK_LINE(117)
	return this->m_vertices->__get(index).StaticCast< ::box2D::common::math::B2Vec2 >();
}


HX_DEFINE_DYNAMIC_FUNC1(B2DistanceProxy_obj,getVertex,return )


B2DistanceProxy_obj::B2DistanceProxy_obj()
{
}

void B2DistanceProxy_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DistanceProxy);
	HX_MARK_MEMBER_NAME(m_vertices,"m_vertices");
	HX_MARK_MEMBER_NAME(m_count,"m_count");
	HX_MARK_MEMBER_NAME(m_radius,"m_radius");
	HX_MARK_END_CLASS();
}

void B2DistanceProxy_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_vertices,"m_vertices");
	HX_VISIT_MEMBER_NAME(m_count,"m_count");
	HX_VISIT_MEMBER_NAME(m_radius,"m_radius");
}

Dynamic B2DistanceProxy_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { return m_count; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { return m_radius; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getVertex") ) { return getVertex_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getSupport") ) { return getSupport_dyn(); }
		if (HX_FIELD_EQ(inName,"m_vertices") ) { return m_vertices; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getVertexCount") ) { return getVertexCount_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getSupportVertex") ) { return getSupportVertex_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2DistanceProxy_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { m_count=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { m_radius=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_vertices") ) { m_vertices=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2DistanceProxy_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_vertices"));
	outFields->push(HX_CSTRING("m_count"));
	outFields->push(HX_CSTRING("m_radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2DistanceProxy_obj,m_vertices),HX_CSTRING("m_vertices")},
	{hx::fsInt,(int)offsetof(B2DistanceProxy_obj,m_count),HX_CSTRING("m_count")},
	{hx::fsFloat,(int)offsetof(B2DistanceProxy_obj,m_radius),HX_CSTRING("m_radius")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("getSupport"),
	HX_CSTRING("getSupportVertex"),
	HX_CSTRING("getVertexCount"),
	HX_CSTRING("getVertex"),
	HX_CSTRING("m_vertices"),
	HX_CSTRING("m_count"),
	HX_CSTRING("m_radius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DistanceProxy_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2DistanceProxy_obj::__mClass,"__mClass");
};

#endif

Class B2DistanceProxy_obj::__mClass;

void B2DistanceProxy_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DistanceProxy"), hx::TCanCast< B2DistanceProxy_obj> ,sStaticFields,sMemberFields,
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

void B2DistanceProxy_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
