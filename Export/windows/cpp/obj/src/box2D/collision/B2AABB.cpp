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
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace box2D{
namespace collision{

Void B2AABB_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2AABB","new",0xc171b92f,"box2D.collision.B2AABB.new","box2D/collision/B2AABB.hx",215,0x658add9f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(217)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(217)
	this->lowerBound = _g;
	HX_STACK_LINE(218)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(218)
	this->upperBound = _g1;
}
;
	return null();
}

//B2AABB_obj::~B2AABB_obj() { }

Dynamic B2AABB_obj::__CreateEmpty() { return  new B2AABB_obj; }
hx::ObjectPtr< B2AABB_obj > B2AABB_obj::__new()
{  hx::ObjectPtr< B2AABB_obj > result = new B2AABB_obj();
	result->__construct();
	return result;}

Dynamic B2AABB_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2AABB_obj > result = new B2AABB_obj();
	result->__construct();
	return result;}

bool B2AABB_obj::isValid( ){
	HX_STACK_FRAME("box2D.collision.B2AABB","isValid",0x08621501,"box2D.collision.B2AABB.isValid","box2D/collision/B2AABB.hx",34,0x658add9f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(36)
	Float dX = (this->upperBound->x - this->lowerBound->x);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(37)
	Float dY = (this->upperBound->y - this->lowerBound->y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(38)
	bool valid = (bool((dX >= 0.0)) && bool((dY >= 0.0)));		HX_STACK_VAR(valid,"valid");
	HX_STACK_LINE(39)
	bool _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(39)
	if (((  ((valid)) ? bool(this->lowerBound->isValid()) : bool(false) ))){
		HX_STACK_LINE(39)
		_g = this->upperBound->isValid();
	}
	else{
		HX_STACK_LINE(39)
		_g = false;
	}
	HX_STACK_LINE(39)
	valid = _g;
	HX_STACK_LINE(40)
	return valid;
}


HX_DEFINE_DYNAMIC_FUNC0(B2AABB_obj,isValid,return )

::box2D::common::math::B2Vec2 B2AABB_obj::getCenter( ){
	HX_STACK_FRAME("box2D.collision.B2AABB","getCenter",0x8a889d1a,"box2D.collision.B2AABB.getCenter","box2D/collision/B2AABB.hx",46,0x658add9f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(46)
	return ::box2D::common::math::B2Vec2_obj::__new((Float(((this->lowerBound->x + this->upperBound->x))) / Float((int)2)),(Float(((this->lowerBound->y + this->upperBound->y))) / Float((int)2)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2AABB_obj,getCenter,return )

::box2D::common::math::B2Vec2 B2AABB_obj::getExtents( ){
	HX_STACK_FRAME("box2D.collision.B2AABB","getExtents",0x0377c064,"box2D.collision.B2AABB.getExtents","box2D/collision/B2AABB.hx",53,0x658add9f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(53)
	return ::box2D::common::math::B2Vec2_obj::__new((Float(((this->upperBound->x - this->lowerBound->x))) / Float((int)2)),(Float(((this->upperBound->y - this->lowerBound->y))) / Float((int)2)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2AABB_obj,getExtents,return )

bool B2AABB_obj::contains( ::box2D::collision::B2AABB aabb){
	HX_STACK_FRAME("box2D.collision.B2AABB","contains",0xd1d422f0,"box2D.collision.B2AABB.contains","box2D/collision/B2AABB.hx",61,0x658add9f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(aabb,"aabb")
	HX_STACK_LINE(62)
	bool result = true;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(63)
	result = (bool(result) && bool((this->lowerBound->x <= aabb->lowerBound->x)));
	HX_STACK_LINE(64)
	result = (bool(result) && bool((this->lowerBound->y <= aabb->lowerBound->y)));
	HX_STACK_LINE(65)
	result = (bool(result) && bool((aabb->upperBound->x <= this->upperBound->x)));
	HX_STACK_LINE(66)
	result = (bool(result) && bool((aabb->upperBound->y <= this->upperBound->y)));
	HX_STACK_LINE(67)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(B2AABB_obj,contains,return )

bool B2AABB_obj::rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input){
	HX_STACK_FRAME("box2D.collision.B2AABB","rayCast",0x5f605a18,"box2D.collision.B2AABB.rayCast","box2D/collision/B2AABB.hx",75,0x658add9f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(output,"output")
	HX_STACK_ARG(input,"input")
	HX_STACK_LINE(76)
	Float tmin = -1.7976931348623157e+308;		HX_STACK_VAR(tmin,"tmin");
	HX_STACK_LINE(77)
	Float tmax = 1.7976931348623158e+308;		HX_STACK_VAR(tmax,"tmax");
	HX_STACK_LINE(79)
	Float pX = input->p1->x;		HX_STACK_VAR(pX,"pX");
	HX_STACK_LINE(80)
	Float pY = input->p1->y;		HX_STACK_VAR(pY,"pY");
	HX_STACK_LINE(81)
	Float dX = (input->p2->x - input->p1->x);		HX_STACK_VAR(dX,"dX");
	HX_STACK_LINE(82)
	Float dY = (input->p2->y - input->p1->y);		HX_STACK_VAR(dY,"dY");
	HX_STACK_LINE(83)
	Float absDX = ::Math_obj::abs(dX);		HX_STACK_VAR(absDX,"absDX");
	HX_STACK_LINE(84)
	Float absDY = ::Math_obj::abs(dY);		HX_STACK_VAR(absDY,"absDY");
	HX_STACK_LINE(86)
	::box2D::common::math::B2Vec2 normal = output->normal;		HX_STACK_VAR(normal,"normal");
	HX_STACK_LINE(88)
	Float inv_d;		HX_STACK_VAR(inv_d,"inv_d");
	HX_STACK_LINE(89)
	Float t1;		HX_STACK_VAR(t1,"t1");
	HX_STACK_LINE(90)
	Float t2;		HX_STACK_VAR(t2,"t2");
	HX_STACK_LINE(91)
	Float t3;		HX_STACK_VAR(t3,"t3");
	HX_STACK_LINE(92)
	Float s;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(96)
	if (((absDX < 2.2250738585072014e-308))){
		HX_STACK_LINE(99)
		if (((bool((pX < this->lowerBound->x)) || bool((this->upperBound->x < pX))))){
			HX_STACK_LINE(100)
			return false;
		}
	}
	else{
		HX_STACK_LINE(104)
		inv_d = (Float(1.0) / Float(dX));
		HX_STACK_LINE(105)
		t1 = (((this->lowerBound->x - pX)) * inv_d);
		HX_STACK_LINE(106)
		t2 = (((this->upperBound->x - pX)) * inv_d);
		HX_STACK_LINE(109)
		s = -1.0;
		HX_STACK_LINE(111)
		if (((t1 > t2))){
			HX_STACK_LINE(113)
			t3 = t1;
			HX_STACK_LINE(114)
			t1 = t2;
			HX_STACK_LINE(115)
			t2 = t3;
			HX_STACK_LINE(116)
			s = 1.0;
		}
		HX_STACK_LINE(120)
		if (((t1 > tmin))){
			HX_STACK_LINE(122)
			normal->x = s;
			HX_STACK_LINE(123)
			normal->y = (int)0;
			HX_STACK_LINE(124)
			tmin = t1;
		}
		HX_STACK_LINE(128)
		Float _g = ::Math_obj::min(tmax,t2);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(128)
		tmax = _g;
		HX_STACK_LINE(130)
		if (((tmin > tmax))){
			HX_STACK_LINE(131)
			return false;
		}
	}
	HX_STACK_LINE(136)
	if (((absDY < 2.2250738585072014e-308))){
		HX_STACK_LINE(139)
		if (((bool((pY < this->lowerBound->y)) || bool((this->upperBound->y < pY))))){
			HX_STACK_LINE(140)
			return false;
		}
	}
	else{
		HX_STACK_LINE(144)
		inv_d = (Float(1.0) / Float(dY));
		HX_STACK_LINE(145)
		t1 = (((this->lowerBound->y - pY)) * inv_d);
		HX_STACK_LINE(146)
		t2 = (((this->upperBound->y - pY)) * inv_d);
		HX_STACK_LINE(149)
		s = -1.0;
		HX_STACK_LINE(151)
		if (((t1 > t2))){
			HX_STACK_LINE(153)
			t3 = t1;
			HX_STACK_LINE(154)
			t1 = t2;
			HX_STACK_LINE(155)
			t2 = t3;
			HX_STACK_LINE(156)
			s = 1.0;
		}
		HX_STACK_LINE(160)
		if (((t1 > tmin))){
			HX_STACK_LINE(162)
			normal->y = s;
			HX_STACK_LINE(163)
			normal->x = (int)0;
			HX_STACK_LINE(164)
			tmin = t1;
		}
		HX_STACK_LINE(168)
		Float _g1 = ::Math_obj::min(tmax,t2);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(168)
		tmax = _g1;
		HX_STACK_LINE(170)
		if (((tmin > tmax))){
			HX_STACK_LINE(171)
			return false;
		}
	}
	HX_STACK_LINE(175)
	output->fraction = tmin;
	HX_STACK_LINE(176)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(B2AABB_obj,rayCast,return )

bool B2AABB_obj::testOverlap( ::box2D::collision::B2AABB other){
	HX_STACK_FRAME("box2D.collision.B2AABB","testOverlap",0x64530124,"box2D.collision.B2AABB.testOverlap","box2D/collision/B2AABB.hx",183,0x658add9f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(other,"other")
	HX_STACK_LINE(184)
	Float d1X = (other->lowerBound->x - this->upperBound->x);		HX_STACK_VAR(d1X,"d1X");
	HX_STACK_LINE(185)
	Float d1Y = (other->lowerBound->y - this->upperBound->y);		HX_STACK_VAR(d1Y,"d1Y");
	HX_STACK_LINE(186)
	Float d2X = (this->lowerBound->x - other->upperBound->x);		HX_STACK_VAR(d2X,"d2X");
	HX_STACK_LINE(187)
	Float d2Y = (this->lowerBound->y - other->upperBound->y);		HX_STACK_VAR(d2Y,"d2Y");
	HX_STACK_LINE(189)
	if (((bool((d1X > 0.0)) || bool((d1Y > 0.0))))){
		HX_STACK_LINE(190)
		return false;
	}
	HX_STACK_LINE(192)
	if (((bool((d2X > 0.0)) || bool((d2Y > 0.0))))){
		HX_STACK_LINE(193)
		return false;
	}
	HX_STACK_LINE(195)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(B2AABB_obj,testOverlap,return )

Void B2AABB_obj::combine( ::box2D::collision::B2AABB aabb1,::box2D::collision::B2AABB aabb2){
{
		HX_STACK_FRAME("box2D.collision.B2AABB","combine",0xb45226ce,"box2D.collision.B2AABB.combine","box2D/collision/B2AABB.hx",208,0x658add9f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(aabb1,"aabb1")
		HX_STACK_ARG(aabb2,"aabb2")
		HX_STACK_LINE(209)
		Float _g = ::Math_obj::min(aabb1->lowerBound->x,aabb2->lowerBound->x);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(209)
		this->lowerBound->x = _g;
		HX_STACK_LINE(210)
		Float _g1 = ::Math_obj::min(aabb1->lowerBound->y,aabb2->lowerBound->y);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(210)
		this->lowerBound->y = _g1;
		HX_STACK_LINE(211)
		Float _g2 = ::Math_obj::max(aabb1->upperBound->x,aabb2->upperBound->x);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(211)
		this->upperBound->x = _g2;
		HX_STACK_LINE(212)
		Float _g3 = ::Math_obj::max(aabb1->upperBound->y,aabb2->upperBound->y);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(212)
		this->upperBound->y = _g3;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2AABB_obj,combine,(void))


B2AABB_obj::B2AABB_obj()
{
}

void B2AABB_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2AABB);
	HX_MARK_MEMBER_NAME(lowerBound,"lowerBound");
	HX_MARK_MEMBER_NAME(upperBound,"upperBound");
	HX_MARK_END_CLASS();
}

void B2AABB_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lowerBound,"lowerBound");
	HX_VISIT_MEMBER_NAME(upperBound,"upperBound");
}

Dynamic B2AABB_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		if (HX_FIELD_EQ(inName,"rayCast") ) { return rayCast_dyn(); }
		if (HX_FIELD_EQ(inName,"combine") ) { return combine_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getCenter") ) { return getCenter_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getExtents") ) { return getExtents_dyn(); }
		if (HX_FIELD_EQ(inName,"lowerBound") ) { return lowerBound; }
		if (HX_FIELD_EQ(inName,"upperBound") ) { return upperBound; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"testOverlap") ) { return testOverlap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2AABB_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"lowerBound") ) { lowerBound=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"upperBound") ) { upperBound=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2AABB_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("lowerBound"));
	outFields->push(HX_CSTRING("upperBound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2AABB_obj,lowerBound),HX_CSTRING("lowerBound")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2AABB_obj,upperBound),HX_CSTRING("upperBound")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("isValid"),
	HX_CSTRING("getCenter"),
	HX_CSTRING("getExtents"),
	HX_CSTRING("contains"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("testOverlap"),
	HX_CSTRING("combine"),
	HX_CSTRING("lowerBound"),
	HX_CSTRING("upperBound"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2AABB_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2AABB_obj::__mClass,"__mClass");
};

#endif

Class B2AABB_obj::__mClass;

void B2AABB_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2AABB"), hx::TCanCast< B2AABB_obj> ,sStaticFields,sMemberFields,
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

void B2AABB_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
