#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
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

Void B2Mat22_obj::__construct()
{
HX_STACK_FRAME("box2D.common.math.B2Mat22","new",0x0cd9ddae,"box2D.common.math.B2Mat22.new","box2D/common/math/B2Mat22.hx",28,0x6d9f4ea3)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(29)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new((int)0,1.0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(29)
	this->col1 = _g;
	HX_STACK_LINE(30)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new((int)0,1.0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(30)
	this->col2 = _g1;
}
;
	return null();
}

//B2Mat22_obj::~B2Mat22_obj() { }

Dynamic B2Mat22_obj::__CreateEmpty() { return  new B2Mat22_obj; }
hx::ObjectPtr< B2Mat22_obj > B2Mat22_obj::__new()
{  hx::ObjectPtr< B2Mat22_obj > result = new B2Mat22_obj();
	result->__construct();
	return result;}

Dynamic B2Mat22_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Mat22_obj > result = new B2Mat22_obj();
	result->__construct();
	return result;}

Void B2Mat22_obj::set( Float angle){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat22","set",0x0cdda8f0,"box2D.common.math.B2Mat22.set","box2D/common/math/B2Mat22.hx",48,0x6d9f4ea3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(angle,"angle")
		HX_STACK_LINE(49)
		Float c = ::Math_obj::cos(angle);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(50)
		Float s = ::Math_obj::sin(angle);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(51)
		this->col1->x = c;
		HX_STACK_LINE(51)
		this->col2->x = -(s);
		HX_STACK_LINE(52)
		this->col1->y = s;
		HX_STACK_LINE(52)
		this->col2->y = c;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,set,(void))

Void B2Mat22_obj::setVV( ::box2D::common::math::B2Vec2 c1,::box2D::common::math::B2Vec2 c2){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat22","setVV",0x3e4e1030,"box2D.common.math.B2Mat22.setVV","box2D/common/math/B2Mat22.hx",56,0x6d9f4ea3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c1,"c1")
		HX_STACK_ARG(c2,"c2")
		HX_STACK_LINE(57)
		this->col1->setV(c1);
		HX_STACK_LINE(58)
		this->col2->setV(c2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Mat22_obj,setVV,(void))

::box2D::common::math::B2Mat22 B2Mat22_obj::copy( ){
	HX_STACK_FRAME("box2D.common.math.B2Mat22","copy",0x2a8a52a7,"box2D.common.math.B2Mat22.copy","box2D/common/math/B2Mat22.hx",61,0x6d9f4ea3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	::box2D::common::math::B2Mat22 mat = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(mat,"mat");
	HX_STACK_LINE(63)
	mat->setM(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(64)
	return mat;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,copy,return )

Void B2Mat22_obj::setM( ::box2D::common::math::B2Mat22 m){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat22","setM",0x3516295d,"box2D.common.math.B2Mat22.setM","box2D/common/math/B2Mat22.hx",68,0x6d9f4ea3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(69)
		this->col1->setV(m->col1);
		HX_STACK_LINE(70)
		this->col2->setV(m->col2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,setM,(void))

Void B2Mat22_obj::addM( ::box2D::common::math::B2Mat22 m){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat22","addM",0x292f81fe,"box2D.common.math.B2Mat22.addM","box2D/common/math/B2Mat22.hx",74,0x6d9f4ea3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(75)
		hx::AddEq(this->col1->x,m->col1->x);
		HX_STACK_LINE(76)
		hx::AddEq(this->col1->y,m->col1->y);
		HX_STACK_LINE(77)
		hx::AddEq(this->col2->x,m->col2->x);
		HX_STACK_LINE(78)
		hx::AddEq(this->col2->y,m->col2->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,addM,(void))

Void B2Mat22_obj::setIdentity( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat22","setIdentity",0x73f91a4e,"box2D.common.math.B2Mat22.setIdentity","box2D/common/math/B2Mat22.hx",82,0x6d9f4ea3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(83)
		this->col1->x = 1.0;
		HX_STACK_LINE(83)
		this->col2->x = 0.0;
		HX_STACK_LINE(84)
		this->col1->y = 0.0;
		HX_STACK_LINE(84)
		this->col2->y = 1.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,setIdentity,(void))

Void B2Mat22_obj::setZero( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat22","setZero",0xfcc71c38,"box2D.common.math.B2Mat22.setZero","box2D/common/math/B2Mat22.hx",88,0x6d9f4ea3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(89)
		this->col1->x = 0.0;
		HX_STACK_LINE(89)
		this->col2->x = 0.0;
		HX_STACK_LINE(90)
		this->col1->y = 0.0;
		HX_STACK_LINE(90)
		this->col2->y = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,setZero,(void))

Float B2Mat22_obj::getAngle( ){
	HX_STACK_FRAME("box2D.common.math.B2Mat22","getAngle",0x23fa4b4f,"box2D.common.math.B2Mat22.getAngle","box2D/common/math/B2Mat22.hx",95,0x6d9f4ea3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(95)
	return ::Math_obj::atan2(this->col1->y,this->col1->x);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,getAngle,return )

::box2D::common::math::B2Mat22 B2Mat22_obj::getInverse( ::box2D::common::math::B2Mat22 out){
	HX_STACK_FRAME("box2D.common.math.B2Mat22","getInverse",0xbab72a2c,"box2D.common.math.B2Mat22.getInverse","box2D/common/math/B2Mat22.hx",102,0x6d9f4ea3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(out,"out")
	HX_STACK_LINE(103)
	Float a = this->col1->x;		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(104)
	Float b = this->col2->x;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(105)
	Float c = this->col1->y;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(106)
	Float d = this->col2->y;		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(108)
	Float det = ((a * d) - (b * c));		HX_STACK_VAR(det,"det");
	HX_STACK_LINE(109)
	if (((det != 0.0))){
		HX_STACK_LINE(111)
		det = (Float(1.0) / Float(det));
	}
	HX_STACK_LINE(113)
	out->col1->x = (det * d);
	HX_STACK_LINE(113)
	out->col2->x = (-(det) * b);
	HX_STACK_LINE(114)
	out->col1->y = (-(det) * c);
	HX_STACK_LINE(114)
	out->col2->y = (det * a);
	HX_STACK_LINE(115)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,getInverse,return )

::box2D::common::math::B2Vec2 B2Mat22_obj::solve( ::box2D::common::math::B2Vec2 out,Float bX,Float bY){
	HX_STACK_FRAME("box2D.common.math.B2Mat22","solve",0x44e43c4d,"box2D.common.math.B2Mat22.solve","box2D/common/math/B2Mat22.hx",120,0x6d9f4ea3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(out,"out")
	HX_STACK_ARG(bX,"bX")
	HX_STACK_ARG(bY,"bY")
	HX_STACK_LINE(122)
	Float a11 = this->col1->x;		HX_STACK_VAR(a11,"a11");
	HX_STACK_LINE(123)
	Float a12 = this->col2->x;		HX_STACK_VAR(a12,"a12");
	HX_STACK_LINE(124)
	Float a21 = this->col1->y;		HX_STACK_VAR(a21,"a21");
	HX_STACK_LINE(125)
	Float a22 = this->col2->y;		HX_STACK_VAR(a22,"a22");
	HX_STACK_LINE(127)
	Float det = ((a11 * a22) - (a12 * a21));		HX_STACK_VAR(det,"det");
	HX_STACK_LINE(128)
	if (((det != 0.0))){
		HX_STACK_LINE(130)
		det = (Float(1.0) / Float(det));
	}
	HX_STACK_LINE(132)
	out->x = (det * (((a22 * bX) - (a12 * bY))));
	HX_STACK_LINE(133)
	out->y = (det * (((a11 * bY) - (a21 * bX))));
	HX_STACK_LINE(135)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Mat22_obj,solve,return )

Void B2Mat22_obj::abs( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat22","abs",0x0ccffdc0,"box2D.common.math.B2Mat22.abs","box2D/common/math/B2Mat22.hx",139,0x6d9f4ea3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(140)
		this->col1->abs();
		HX_STACK_LINE(141)
		this->col2->abs();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat22_obj,abs,(void))

::box2D::common::math::B2Mat22 B2Mat22_obj::fromAngle( Float angle){
	HX_STACK_FRAME("box2D.common.math.B2Mat22","fromAngle",0x4f0329d7,"box2D.common.math.B2Mat22.fromAngle","box2D/common/math/B2Mat22.hx",34,0x6d9f4ea3)
	HX_STACK_ARG(angle,"angle")
	HX_STACK_LINE(35)
	::box2D::common::math::B2Mat22 mat = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(mat,"mat");
	HX_STACK_LINE(36)
	mat->set(angle);
	HX_STACK_LINE(37)
	return mat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(B2Mat22_obj,fromAngle,return )

::box2D::common::math::B2Mat22 B2Mat22_obj::fromVV( ::box2D::common::math::B2Vec2 c1,::box2D::common::math::B2Vec2 c2){
	HX_STACK_FRAME("box2D.common.math.B2Mat22","fromVV",0x8c55569c,"box2D.common.math.B2Mat22.fromVV","box2D/common/math/B2Mat22.hx",41,0x6d9f4ea3)
	HX_STACK_ARG(c1,"c1")
	HX_STACK_ARG(c2,"c2")
	HX_STACK_LINE(42)
	::box2D::common::math::B2Mat22 mat = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(mat,"mat");
	HX_STACK_LINE(43)
	mat->setVV(c1,c2);
	HX_STACK_LINE(44)
	return mat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Mat22_obj,fromVV,return )


B2Mat22_obj::B2Mat22_obj()
{
}

void B2Mat22_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Mat22);
	HX_MARK_MEMBER_NAME(col1,"col1");
	HX_MARK_MEMBER_NAME(col2,"col2");
	HX_MARK_END_CLASS();
}

void B2Mat22_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(col1,"col1");
	HX_VISIT_MEMBER_NAME(col2,"col2");
}

Dynamic B2Mat22_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"abs") ) { return abs_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"setM") ) { return setM_dyn(); }
		if (HX_FIELD_EQ(inName,"addM") ) { return addM_dyn(); }
		if (HX_FIELD_EQ(inName,"col1") ) { return col1; }
		if (HX_FIELD_EQ(inName,"col2") ) { return col2; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"setVV") ) { return setVV_dyn(); }
		if (HX_FIELD_EQ(inName,"solve") ) { return solve_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fromVV") ) { return fromVV_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAngle") ) { return getAngle_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromAngle") ) { return fromAngle_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getInverse") ) { return getInverse_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setIdentity") ) { return setIdentity_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Mat22_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"col1") ) { col1=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"col2") ) { col2=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Mat22_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("col1"));
	outFields->push(HX_CSTRING("col2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromAngle"),
	HX_CSTRING("fromVV"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Mat22_obj,col1),HX_CSTRING("col1")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Mat22_obj,col2),HX_CSTRING("col2")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("setVV"),
	HX_CSTRING("copy"),
	HX_CSTRING("setM"),
	HX_CSTRING("addM"),
	HX_CSTRING("setIdentity"),
	HX_CSTRING("setZero"),
	HX_CSTRING("getAngle"),
	HX_CSTRING("getInverse"),
	HX_CSTRING("solve"),
	HX_CSTRING("abs"),
	HX_CSTRING("col1"),
	HX_CSTRING("col2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Mat22_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Mat22_obj::__mClass,"__mClass");
};

#endif

Class B2Mat22_obj::__mClass;

void B2Mat22_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Mat22"), hx::TCanCast< B2Mat22_obj> ,sStaticFields,sMemberFields,
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

void B2Mat22_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
