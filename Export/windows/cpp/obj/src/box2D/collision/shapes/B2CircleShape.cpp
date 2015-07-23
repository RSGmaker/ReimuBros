#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastOutput
#include <box2D/collision/B2RayCastOutput.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2CircleShape
#include <box2D/collision/shapes/B2CircleShape.h>
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

Void B2CircleShape_obj::__construct(hx::Null< Float >  __o_radius)
{
HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","new",0x65b9dc04,"box2D.collision.shapes.B2CircleShape.new","box2D/collision/shapes/B2CircleShape.hx",218,0x60fd1eeb)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_radius,"radius")
Float radius = __o_radius.Default(0);
{
	HX_STACK_LINE(219)
	super::__construct();
	HX_STACK_LINE(220)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(220)
	this->m_p = _g;
	HX_STACK_LINE(221)
	this->m_type = (int)1;
	HX_STACK_LINE(222)
	this->m_radius = radius;
}
;
	return null();
}

//B2CircleShape_obj::~B2CircleShape_obj() { }

Dynamic B2CircleShape_obj::__CreateEmpty() { return  new B2CircleShape_obj; }
hx::ObjectPtr< B2CircleShape_obj > B2CircleShape_obj::__new(hx::Null< Float >  __o_radius)
{  hx::ObjectPtr< B2CircleShape_obj > result = new B2CircleShape_obj();
	result->__construct(__o_radius);
	return result;}

Dynamic B2CircleShape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2CircleShape_obj > result = new B2CircleShape_obj();
	result->__construct(inArgs[0]);
	return result;}

::box2D::collision::shapes::B2Shape B2CircleShape_obj::copy( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","copy",0x95a8df91,"box2D.collision.shapes.B2CircleShape.copy","box2D/collision/shapes/B2CircleShape.hx",39,0x60fd1eeb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	::box2D::collision::shapes::B2Shape s = ::box2D::collision::shapes::B2CircleShape_obj::__new(null());		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(41)
	s->set(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(42)
	return s;
}


Void B2CircleShape_obj::set( ::box2D::collision::shapes::B2Shape other){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","set",0x65bda746,"box2D.collision.shapes.B2CircleShape.set","box2D/collision/shapes/B2CircleShape.hx",46,0x60fd1eeb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(other,"other")
		HX_STACK_LINE(47)
		this->super::set(other);
		HX_STACK_LINE(48)
		if ((::Std_obj::is(other,hx::ClassOf< ::box2D::collision::shapes::B2CircleShape >()))){
			HX_STACK_LINE(50)
			::box2D::collision::shapes::B2CircleShape other2;		HX_STACK_VAR(other2,"other2");
			HX_STACK_LINE(50)
			other2 = hx::TCast< box2D::collision::shapes::B2CircleShape >::cast(other);
			HX_STACK_LINE(51)
			this->m_p->setV(other2->m_p);
		}
	}
return null();
}


bool B2CircleShape_obj::testPoint( ::box2D::common::math::B2Transform transform,::box2D::common::math::B2Vec2 p){
	HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","testPoint",0x15525142,"box2D.collision.shapes.B2CircleShape.testPoint","box2D/collision/shapes/B2CircleShape.hx",58,0x60fd1eeb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(transform,"transform")
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(60)
	::box2D::common::math::B2Mat22 tMat = transform->R;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(61)
	Float dX = (transform->position->x + (((tMat->col1->x * this->m_p->x) + (tMat->col2->x * this->m_p->y))));		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(62)
	Float dY = (transform->position->y + (((tMat->col1->y * this->m_p->x) + (tMat->col2->y * this->m_p->y))));		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(64)
	dX = (p->x - dX);
	HX_STACK_LINE(65)
	dY = (p->y - dY);
	HX_STACK_LINE(67)
	return (((dX * dX) + (dY * dY)) <= (this->m_radius * this->m_radius));
}


bool B2CircleShape_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform){
	HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","rayCast",0x0bbb0b6d,"box2D.collision.shapes.B2CircleShape.rayCast","box2D/collision/shapes/B2CircleShape.hx",74,0x60fd1eeb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(input,"input")
	HX_STACK_ARG(transform,"transform")
	HX_STACK_LINE(76)
	::box2D::common::math::B2Mat22 tMat = transform->R;		HX_STACK_VAR(tMat,"tMat");
	HX_STACK_LINE(77)
	Float positionX = (transform->position->x + (((tMat->col1->x * this->m_p->x) + (tMat->col2->x * this->m_p->y))));		HX_STACK_VAR(positionX,"positionX");
	HX_STACK_LINE(78)
	Float positionY = (transform->position->y + (((tMat->col1->y * this->m_p->x) + (tMat->col2->y * this->m_p->y))));		HX_STACK_VAR(positionY,"positionY");
	HX_STACK_LINE(81)
	Float sX = (input->p1->x - positionX);		HX_STACK_VAR(sX,"sX");
	HX_STACK_LINE(82)
	Float sY = (input->p1->y - positionY);		HX_STACK_VAR(sY,"sY");
	HX_STACK_LINE(84)
	Float b = (((sX * sX) + (sY * sY)) - (this->m_radius * this->m_radius));		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(96)
	Float rX = (input->p2->x - input->p1->x);		HX_STACK_VAR(rX,"rX");
	HX_STACK_LINE(97)
	Float rY = (input->p2->y - input->p1->y);		HX_STACK_VAR(rY,"rY");
	HX_STACK_LINE(99)
	Float c = ((sX * rX) + (sY * rY));		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(101)
	Float rr = ((rX * rX) + (rY * rY));		HX_STACK_VAR(rr,"rr");
	HX_STACK_LINE(102)
	Float sigma = ((c * c) - (rr * b));		HX_STACK_VAR(sigma,"sigma");
	HX_STACK_LINE(105)
	if (((bool((sigma < 0.0)) || bool((rr < 2.2250738585072014e-308))))){
		HX_STACK_LINE(107)
		return false;
	}
	HX_STACK_LINE(111)
	Float _g = ::Math_obj::sqrt(sigma);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(111)
	Float a = -(((c + _g)));		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(114)
	if (((bool((0.0 <= a)) && bool((a <= (input->maxFraction * rr)))))){
		HX_STACK_LINE(116)
		hx::DivEq(a,rr);
		HX_STACK_LINE(117)
		output->fraction = a;
		HX_STACK_LINE(119)
		output->normal->x = (sX + (a * rX));
		HX_STACK_LINE(120)
		output->normal->y = (sY + (a * rY));
		HX_STACK_LINE(121)
		output->normal->normalize();
		HX_STACK_LINE(122)
		return true;
	}
	HX_STACK_LINE(125)
	return false;
}


Void B2CircleShape_obj::computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform transform){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","computeAABB",0x800f893b,"box2D.collision.shapes.B2CircleShape.computeAABB","box2D/collision/shapes/B2CircleShape.hx",131,0x60fd1eeb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(aabb,"aabb")
		HX_STACK_ARG(transform,"transform")
		HX_STACK_LINE(133)
		::box2D::common::math::B2Mat22 tMat = transform->R;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(134)
		Float pX = (transform->position->x + (((tMat->col1->x * this->m_p->x) + (tMat->col2->x * this->m_p->y))));		HX_STACK_VAR(pX,"pX");
		HX_STACK_LINE(135)
		Float pY = (transform->position->y + (((tMat->col1->y * this->m_p->x) + (tMat->col2->y * this->m_p->y))));		HX_STACK_VAR(pY,"pY");
		HX_STACK_LINE(136)
		aabb->lowerBound->set((pX - this->m_radius),(pY - this->m_radius));
		HX_STACK_LINE(137)
		aabb->upperBound->set((pX + this->m_radius),(pY + this->m_radius));
	}
return null();
}


Void B2CircleShape_obj::computeMass( ::box2D::collision::shapes::B2MassData massData,Float density){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","computeMass",0x88168baf,"box2D.collision.shapes.B2CircleShape.computeMass","box2D/collision/shapes/B2CircleShape.hx",143,0x60fd1eeb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(massData,"massData")
		HX_STACK_ARG(density,"density")
		HX_STACK_LINE(144)
		massData->mass = (((density * ::box2D::common::B2Settings_obj::b2_pi) * this->m_radius) * this->m_radius);
		HX_STACK_LINE(145)
		massData->center->setV(this->m_p);
		HX_STACK_LINE(149)
		massData->I = (massData->mass * ((((0.5 * this->m_radius) * this->m_radius) + (((this->m_p->x * this->m_p->x) + (this->m_p->y * this->m_p->y))))));
	}
return null();
}


Float B2CircleShape_obj::computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,Float offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c){
	HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","computeSubmergedArea",0xea5ecbbe,"box2D.collision.shapes.B2CircleShape.computeSubmergedArea","box2D/collision/shapes/B2CircleShape.hx",160,0x60fd1eeb)
	HX_STACK_THIS(this)
	HX_STACK_ARG(normal,"normal")
	HX_STACK_ARG(offset,"offset")
	HX_STACK_ARG(xf,"xf")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(161)
	::box2D::common::math::B2Vec2 p = ::box2D::common::math::B2Math_obj::mulX(xf,this->m_p);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(162)
	Float _g = ::box2D::common::math::B2Math_obj::dot(normal,p);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(162)
	Float l = -(((_g - offset)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(164)
	if (((l < (-(this->m_radius) + 2.2250738585072014e-308)))){
		HX_STACK_LINE(167)
		return (int)0;
	}
	HX_STACK_LINE(169)
	if (((l > this->m_radius))){
		HX_STACK_LINE(172)
		c->setV(p);
		HX_STACK_LINE(173)
		return ((::Math_obj::PI * this->m_radius) * this->m_radius);
	}
	HX_STACK_LINE(177)
	Float r2 = (this->m_radius * this->m_radius);		HX_STACK_VAR(r2,"r2");
	HX_STACK_LINE(178)
	Float l2 = (l * l);		HX_STACK_VAR(l2,"l2");
	HX_STACK_LINE(179)
	Float _g1 = ::Math_obj::asin((Float(l) / Float(this->m_radius)));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(179)
	Float _g2 = (_g1 + (Float(::Math_obj::PI) / Float((int)2)));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(179)
	Float _g3 = (r2 * _g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(179)
	Float _g4 = ::Math_obj::sqrt((r2 - l2));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(179)
	Float _g5 = (l * _g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(179)
	Float area = (_g3 + _g5);		HX_STACK_VAR(area,"area");
	HX_STACK_LINE(180)
	Float _g6 = ::Math_obj::pow((r2 - l2),1.5);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(180)
	Float _g7 = (-0.66666666666666663 * _g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(180)
	Float com = (Float(_g7) / Float(area));		HX_STACK_VAR(com,"com");
	HX_STACK_LINE(182)
	c->x = (p->x + (normal->x * com));
	HX_STACK_LINE(183)
	c->y = (p->y + (normal->y * com));
	HX_STACK_LINE(185)
	return area;
}


::box2D::common::math::B2Vec2 B2CircleShape_obj::getLocalPosition( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","getLocalPosition",0x8a8e309a,"box2D.collision.shapes.B2CircleShape.getLocalPosition","box2D/collision/shapes/B2CircleShape.hx",192,0x60fd1eeb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(192)
	return this->m_p;
}


HX_DEFINE_DYNAMIC_FUNC0(B2CircleShape_obj,getLocalPosition,return )

Void B2CircleShape_obj::setLocalPosition( ::box2D::common::math::B2Vec2 position){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","setLocalPosition",0xe0d01e0e,"box2D.collision.shapes.B2CircleShape.setLocalPosition","box2D/collision/shapes/B2CircleShape.hx",199,0x60fd1eeb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(position,"position")
		HX_STACK_LINE(199)
		this->m_p->setV(position);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2CircleShape_obj,setLocalPosition,(void))

Float B2CircleShape_obj::getRadius( ){
	HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","getRadius",0xb30db82c,"box2D.collision.shapes.B2CircleShape.getRadius","box2D/collision/shapes/B2CircleShape.hx",207,0x60fd1eeb)
	HX_STACK_THIS(this)
	HX_STACK_LINE(207)
	return this->m_radius;
}


HX_DEFINE_DYNAMIC_FUNC0(B2CircleShape_obj,getRadius,return )

Void B2CircleShape_obj::setRadius( Float radius){
{
		HX_STACK_FRAME("box2D.collision.shapes.B2CircleShape","setRadius",0x965ea438,"box2D.collision.shapes.B2CircleShape.setRadius","box2D/collision/shapes/B2CircleShape.hx",215,0x60fd1eeb)
		HX_STACK_THIS(this)
		HX_STACK_ARG(radius,"radius")
		HX_STACK_LINE(215)
		this->m_radius = radius;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2CircleShape_obj,setRadius,(void))


B2CircleShape_obj::B2CircleShape_obj()
{
}

void B2CircleShape_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2CircleShape);
	HX_MARK_MEMBER_NAME(m_p,"m_p");
	HX_MARK_END_CLASS();
}

void B2CircleShape_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_p,"m_p");
}

Dynamic B2CircleShape_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"m_p") ) { return m_p; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"testPoint") ) { return testPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"getRadius") ) { return getRadius_dyn(); }
		if (HX_FIELD_EQ(inName,"setRadius") ) { return setRadius_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"computeAABB") ) { return computeAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"computeMass") ) { return computeMass_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getLocalPosition") ) { return getLocalPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"setLocalPosition") ) { return setLocalPosition_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeSubmergedArea") ) { return computeSubmergedArea_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2CircleShape_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_p") ) { m_p=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2CircleShape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_p"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2CircleShape_obj,m_p),HX_CSTRING("m_p")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("copy"),
	HX_CSTRING("set"),
	HX_CSTRING("testPoint"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("computeAABB"),
	HX_CSTRING("computeMass"),
	HX_CSTRING("computeSubmergedArea"),
	HX_CSTRING("getLocalPosition"),
	HX_CSTRING("setLocalPosition"),
	HX_CSTRING("getRadius"),
	HX_CSTRING("setRadius"),
	HX_CSTRING("m_p"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2CircleShape_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2CircleShape_obj::__mClass,"__mClass");
};

#endif

Class B2CircleShape_obj::__mClass;

void B2CircleShape_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2CircleShape"), hx::TCanCast< B2CircleShape_obj> ,sStaticFields,sMemberFields,
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

void B2CircleShape_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
