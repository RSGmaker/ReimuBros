#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Sweep
#include <box2D/common/math/B2Sweep.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Transform
#include <box2D/common/math/B2Transform.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Sweep_obj::__construct()
{
HX_STACK_FRAME("box2D.common.math.B2Sweep","new",0x90218b3a,"box2D.common.math.B2Sweep.new","box2D/common/math/B2Sweep.hx",31,0xdeb69697)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(33)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->localCenter = _g;
	HX_STACK_LINE(34)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->c0 = _g1;
	HX_STACK_LINE(35)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(35)
	this->c = _g2;
}
;
	return null();
}

//B2Sweep_obj::~B2Sweep_obj() { }

Dynamic B2Sweep_obj::__CreateEmpty() { return  new B2Sweep_obj; }
hx::ObjectPtr< B2Sweep_obj > B2Sweep_obj::__new()
{  hx::ObjectPtr< B2Sweep_obj > result = new B2Sweep_obj();
	result->__construct();
	return result;}

Dynamic B2Sweep_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Sweep_obj > result = new B2Sweep_obj();
	result->__construct();
	return result;}

Void B2Sweep_obj::set( ::box2D::common::math::B2Sweep other){
{
		HX_STACK_FRAME("box2D.common.math.B2Sweep","set",0x9025567c,"box2D.common.math.B2Sweep.set","box2D/common/math/B2Sweep.hx",40,0xdeb69697)
		HX_STACK_THIS(this)
		HX_STACK_ARG(other,"other")
		HX_STACK_LINE(41)
		this->localCenter->setV(other->localCenter);
		HX_STACK_LINE(42)
		this->c0->setV(other->c0);
		HX_STACK_LINE(43)
		this->c->setV(other->c);
		HX_STACK_LINE(44)
		this->a0 = other->a0;
		HX_STACK_LINE(45)
		this->a = other->a;
		HX_STACK_LINE(46)
		this->t0 = other->t0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Sweep_obj,set,(void))

::box2D::common::math::B2Sweep B2Sweep_obj::copy( ){
	HX_STACK_FRAME("box2D.common.math.B2Sweep","copy",0x85fa7f9b,"box2D.common.math.B2Sweep.copy","box2D/common/math/B2Sweep.hx",50,0xdeb69697)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	::box2D::common::math::B2Sweep copy = ::box2D::common::math::B2Sweep_obj::__new();		HX_STACK_VAR(copy,"copy");
	HX_STACK_LINE(52)
	copy->localCenter->setV(this->localCenter);
	HX_STACK_LINE(53)
	copy->c0->setV(this->c0);
	HX_STACK_LINE(54)
	copy->c->setV(this->c);
	HX_STACK_LINE(55)
	copy->a0 = this->a0;
	HX_STACK_LINE(56)
	copy->a = this->a;
	HX_STACK_LINE(57)
	copy->t0 = this->t0;
	HX_STACK_LINE(58)
	return copy;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Sweep_obj,copy,return )

Void B2Sweep_obj::getTransform( ::box2D::common::math::B2Transform xf,Float alpha){
{
		HX_STACK_FRAME("box2D.common.math.B2Sweep","getTransform",0xbdfee3dc,"box2D.common.math.B2Sweep.getTransform","box2D/common/math/B2Sweep.hx",66,0xdeb69697)
		HX_STACK_THIS(this)
		HX_STACK_ARG(xf,"xf")
		HX_STACK_ARG(alpha,"alpha")
		HX_STACK_LINE(67)
		xf->position->x = ((((1.0 - alpha)) * this->c0->x) + (alpha * this->c->x));
		HX_STACK_LINE(68)
		xf->position->y = ((((1.0 - alpha)) * this->c0->y) + (alpha * this->c->y));
		HX_STACK_LINE(69)
		Float angle = ((((1.0 - alpha)) * this->a0) + (alpha * this->a));		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(70)
		xf->R->set(angle);
		HX_STACK_LINE(74)
		::box2D::common::math::B2Mat22 tMat = xf->R;		HX_STACK_VAR(tMat,"tMat");
		HX_STACK_LINE(75)
		hx::SubEq(xf->position->x,((tMat->col1->x * this->localCenter->x) + (tMat->col2->x * this->localCenter->y)));
		HX_STACK_LINE(76)
		hx::SubEq(xf->position->y,((tMat->col1->y * this->localCenter->x) + (tMat->col2->y * this->localCenter->y)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Sweep_obj,getTransform,(void))

Void B2Sweep_obj::advance( Float t){
{
		HX_STACK_FRAME("box2D.common.math.B2Sweep","advance",0xf699385c,"box2D.common.math.B2Sweep.advance","box2D/common/math/B2Sweep.hx",84,0xdeb69697)
		HX_STACK_THIS(this)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(84)
		if (((bool((this->t0 < t)) && bool(((1.0 - this->t0) > 2.2250738585072014e-308))))){
			HX_STACK_LINE(86)
			Float alpha = (Float(((t - this->t0))) / Float(((1.0 - this->t0))));		HX_STACK_VAR(alpha,"alpha");
			HX_STACK_LINE(88)
			this->c0->x = ((((1.0 - alpha)) * this->c0->x) + (alpha * this->c->x));
			HX_STACK_LINE(89)
			this->c0->y = ((((1.0 - alpha)) * this->c0->y) + (alpha * this->c->y));
			HX_STACK_LINE(90)
			this->a0 = ((((1.0 - alpha)) * this->a0) + (alpha * this->a));
			HX_STACK_LINE(91)
			this->t0 = t;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Sweep_obj,advance,(void))


B2Sweep_obj::B2Sweep_obj()
{
}

void B2Sweep_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Sweep);
	HX_MARK_MEMBER_NAME(localCenter,"localCenter");
	HX_MARK_MEMBER_NAME(c0,"c0");
	HX_MARK_MEMBER_NAME(c,"c");
	HX_MARK_MEMBER_NAME(a0,"a0");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(t0,"t0");
	HX_MARK_END_CLASS();
}

void B2Sweep_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(localCenter,"localCenter");
	HX_VISIT_MEMBER_NAME(c0,"c0");
	HX_VISIT_MEMBER_NAME(c,"c");
	HX_VISIT_MEMBER_NAME(a0,"a0");
	HX_VISIT_MEMBER_NAME(a,"a");
	HX_VISIT_MEMBER_NAME(t0,"t0");
}

Dynamic B2Sweep_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { return c; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"c0") ) { return c0; }
		if (HX_FIELD_EQ(inName,"a0") ) { return a0; }
		if (HX_FIELD_EQ(inName,"t0") ) { return t0; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"advance") ) { return advance_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"localCenter") ) { return localCenter; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getTransform") ) { return getTransform_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Sweep_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"c0") ) { c0=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a0") ) { a0=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"t0") ) { t0=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"localCenter") ) { localCenter=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Sweep_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("localCenter"));
	outFields->push(HX_CSTRING("c0"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("a0"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("t0"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Sweep_obj,localCenter),HX_CSTRING("localCenter")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Sweep_obj,c0),HX_CSTRING("c0")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Sweep_obj,c),HX_CSTRING("c")},
	{hx::fsFloat,(int)offsetof(B2Sweep_obj,a0),HX_CSTRING("a0")},
	{hx::fsFloat,(int)offsetof(B2Sweep_obj,a),HX_CSTRING("a")},
	{hx::fsFloat,(int)offsetof(B2Sweep_obj,t0),HX_CSTRING("t0")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("copy"),
	HX_CSTRING("getTransform"),
	HX_CSTRING("advance"),
	HX_CSTRING("localCenter"),
	HX_CSTRING("c0"),
	HX_CSTRING("c"),
	HX_CSTRING("a0"),
	HX_CSTRING("a"),
	HX_CSTRING("t0"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Sweep_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Sweep_obj::__mClass,"__mClass");
};

#endif

Class B2Sweep_obj::__mClass;

void B2Sweep_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Sweep"), hx::TCanCast< B2Sweep_obj> ,sStaticFields,sMemberFields,
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

void B2Sweep_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
