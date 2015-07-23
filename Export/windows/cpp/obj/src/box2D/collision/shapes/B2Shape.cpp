#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
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
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
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
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{
namespace shapes{

Void B2Shape_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.shapes.B2Shape","new",0x933fd174,"box2D.collision.shapes.B2Shape.new","box2D/collision/shapes/B2Shape.hx",146,0x3c754e3b)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(147)
	this->m_type = (int)0;
	HX_STACK_LINE(148)
	this->m_radius = ::box2D::common::B2Settings_obj::b2_linearSlop;
}
;
	return null();
}

//B2Shape_obj::~B2Shape_obj() { }

Dynamic B2Shape_obj::__CreateEmpty() { return  new B2Shape_obj; }
hx::ObjectPtr< B2Shape_obj > B2Shape_obj::__new()
{  hx::ObjectPtr< B2Shape_obj > result = new B2Shape_obj();
	result->__construct();
	return result;}

Dynamic B2Shape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Shape_obj > result = new B2Shape_obj();
	result->__construct();
	return result;}

::box2D::collision::shapes::B2Shape B2Shape_obj::copy( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2Shape","copy",0x3d59ac21,"box2D.collision.shapes.B2Shape.copy","box2D/collision/shapes/B2Shape.hx",53,0x3c754e3b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(53)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Shape_obj,copy,return )

Void B2Shape_obj::set( ::box2D::collision::shapes::B2Shape other){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2Shape","set",0x93439cb6,"box2D.collision.shapes.B2Shape.set","box2D/collision/shapes/B2Shape.hx",63,0x3c754e3b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(other,"other")
		HX_STACK_LINE(63)
		this->m_radius = other->m_radius;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Shape_obj,set,(void))

int B2Shape_obj::getType( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2Shape","getType",0x830fbd84,"box2D.collision.shapes.B2Shape.getType","box2D/collision/shapes/B2Shape.hx",72,0x3c754e3b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(72)
	return this->m_type;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Shape_obj,getType,return )

bool B2Shape_obj::testPoint( ::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 p){
	HX_STACK_FRAME("box2D.collision.shapes.B2Shape","testPoint",0xf0a1fab2,"box2D.collision.shapes.B2Shape.testPoint","box2D/collision/shapes/B2Shape.hx",80,0x3c754e3b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(xf,"xf")
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(80)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(B2Shape_obj,testPoint,return )

bool B2Shape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_STACK_FRAME("box2D.collision.shapes.B2Shape","rayCast",0x88c078dd,"box2D.collision.shapes.B2Shape.rayCast","box2D/collision/shapes/B2Shape.hx",90,0x3c754e3b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(input,"input")
	HX_STACK_ARG(transform,"transform")
	HX_STACK_LINE(90)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Shape_obj,rayCast,return )

Void B2Shape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform xf){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2Shape","computeAABB",0x8db06eab,"box2D.collision.shapes.B2Shape.computeAABB","box2D/collision/shapes/B2Shape.hx",98,0x3c754e3b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(aabb,"aabb")
		HX_STACK_ARG(xf,"xf")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Shape_obj,computeAABB,(void))

Void B2Shape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,Float density){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2Shape","computeMass",0x95b7711f,"box2D.collision.shapes.B2Shape.computeMass","box2D/collision/shapes/B2Shape.hx",105,0x3c754e3b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(massData,"massData")
		HX_STACK_ARG(density,"density")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Shape_obj,computeMass,(void))

Float B2Shape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,Float offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_STACK_FRAME("box2D.collision.shapes.B2Shape","computeSubmergedArea",0xe68db84e,"box2D.collision.shapes.B2Shape.computeSubmergedArea","box2D/collision/shapes/B2Shape.hx",119,0x3c754e3b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(normal,"normal")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(xf,"xf")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(119)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC4(B2Shape_obj,computeSubmergedArea,return )

bool B2Shape_obj::testOverlap( ::box2D::collision::shapes::B2Shape shape1,::box2D::common::math::B2Transform transform1,::box2D::collision::shapes::B2Shape shape2,::box2D::common::math::B2Transform transform2){
	HX_STACK_FRAME("box2D.collision.shapes.B2Shape","testOverlap",0x310a6669,"box2D.collision.shapes.B2Shape.testOverlap","box2D/collision/shapes/B2Shape.hx",122,0x3c754e3b)
	HX_STACK_ARG(shape1,"shape1")
	HX_STACK_ARG(transform1,"transform1")
	HX_STACK_ARG(shape2,"shape2")
	HX_STACK_ARG(transform2,"transform2")
	HX_STACK_LINE(126)
	::box2D::collision::B2DistanceInput input = ::box2D::collision::B2DistanceInput_obj::__new();		HX_STACK_VAR(input,"input");
	HX_STACK_LINE(127)
	::box2D::collision::B2DistanceProxy _g = ::box2D::collision::B2DistanceProxy_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(127)
	input->proxyA = _g;
	HX_STACK_LINE(128)
	input->proxyA->set(shape1);
	HX_STACK_LINE(129)
	::box2D::collision::B2DistanceProxy _g1 = ::box2D::collision::B2DistanceProxy_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(129)
	input->proxyB = _g1;
	HX_STACK_LINE(130)
	input->proxyB->set(shape2);
	HX_STACK_LINE(131)
	input->transformA = transform1;
	HX_STACK_LINE(132)
	input->transformB = transform2;
	HX_STACK_LINE(133)
	input->useRadii = true;
	HX_STACK_LINE(134)
	::box2D::collision::B2SimplexCache simplexCache = ::box2D::collision::B2SimplexCache_obj::__new();		HX_STACK_VAR(simplexCache,"simplexCache");
	HX_STACK_LINE(135)
	simplexCache->count = (int)0;
	HX_STACK_LINE(136)
	::box2D::collision::B2DistanceOutput output = ::box2D::collision::B2DistanceOutput_obj::__new();		HX_STACK_VAR(output,"output");
	HX_STACK_LINE(137)
	::box2D::collision::B2Distance_obj::distance(output,simplexCache,input);
	HX_STACK_LINE(138)
	return (output->distance < 2.2250738585072014e-307);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(B2Shape_obj,testOverlap,return )

int B2Shape_obj::e_hitCollide;

int B2Shape_obj::e_missCollide;

int B2Shape_obj::e_startsInsideCollide;


B2Shape_obj::B2Shape_obj()
{
}

Dynamic B2Shape_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { return m_radius; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_hitCollide") ) { return e_hitCollide; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_missCollide") ) { return e_missCollide; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"e_startsInsideCollide") ) { return e_startsInsideCollide; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Shape_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_radius") ) { m_radius=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"e_hitCollide") ) { e_hitCollide=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"e_missCollide") ) { e_missCollide=inValue.Cast< int >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"e_startsInsideCollide") ) { e_startsInsideCollide=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Shape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("m_radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("testOverlap"),
	HX_CSTRING("e_hitCollide"),
	HX_CSTRING("e_missCollide"),
	HX_CSTRING("e_startsInsideCollide"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2Shape_obj,m_type),HX_CSTRING("m_type")},
	{hx::fsFloat,(int)offsetof(B2Shape_obj,m_radius),HX_CSTRING("m_radius")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("copy"),
	HX_CSTRING("set"),
	HX_CSTRING("getType"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("m_type"),
	HX_CSTRING("m_radius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Shape_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_hitCollide,"e_hitCollide");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_missCollide,"e_missCollide");
	HX_MARK_MEMBER_NAME(B2Shape_obj::e_startsInsideCollide,"e_startsInsideCollide");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Shape_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2Shape_obj::e_hitCollide,"e_hitCollide");
	HX_VISIT_MEMBER_NAME(B2Shape_obj::e_missCollide,"e_missCollide");
	HX_VISIT_MEMBER_NAME(B2Shape_obj::e_startsInsideCollide,"e_startsInsideCollide");
};

#endif

Class B2Shape_obj::__mClass;

void B2Shape_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2Shape"), hx::TCanCast< B2Shape_obj> ,sStaticFields,sMemberFields,
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

void B2Shape_obj::__boot()
{
	e_hitCollide= (int)1;
	e_missCollide= (int)0;
	e_startsInsideCollide= (int)-1;
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
