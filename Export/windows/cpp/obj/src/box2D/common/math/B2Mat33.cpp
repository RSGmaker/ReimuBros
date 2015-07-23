#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Mat33
#include <box2D/common/math/B2Mat33.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec3
#include <box2D/common/math/B2Vec3.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Mat33_obj::__construct(::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3)
{
HX_STACK_FRAME("box2D.common.math.B2Mat33","new",0x069bce8e,"box2D.common.math.B2Mat33.new","box2D/common/math/B2Mat33.hx",28,0x01af19c3)
HX_STACK_THIS(this)
HX_STACK_ARG(c1,"c1")
HX_STACK_ARG(c2,"c2")
HX_STACK_ARG(c3,"c3")
{
	HX_STACK_LINE(30)
	::box2D::common::math::B2Vec3 _g = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->col1 = _g;
	HX_STACK_LINE(31)
	::box2D::common::math::B2Vec3 _g1 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(31)
	this->col2 = _g1;
	HX_STACK_LINE(32)
	::box2D::common::math::B2Vec3 _g2 = ::box2D::common::math::B2Vec3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(32)
	this->col3 = _g2;
	HX_STACK_LINE(34)
	if (((bool((bool((c1 == null())) && bool((c2 == null())))) && bool((c3 == null()))))){
		HX_STACK_LINE(36)
		this->col1->setZero();
		HX_STACK_LINE(37)
		this->col2->setZero();
		HX_STACK_LINE(38)
		this->col3->setZero();
	}
	else{
		HX_STACK_LINE(42)
		this->col1->setV(c1);
		HX_STACK_LINE(43)
		this->col2->setV(c2);
		HX_STACK_LINE(44)
		this->col3->setV(c3);
	}
}
;
	return null();
}

//B2Mat33_obj::~B2Mat33_obj() { }

Dynamic B2Mat33_obj::__CreateEmpty() { return  new B2Mat33_obj; }
hx::ObjectPtr< B2Mat33_obj > B2Mat33_obj::__new(::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3)
{  hx::ObjectPtr< B2Mat33_obj > result = new B2Mat33_obj();
	result->__construct(c1,c2,c3);
	return result;}

Dynamic B2Mat33_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Mat33_obj > result = new B2Mat33_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void B2Mat33_obj::setVVV( ::box2D::common::math::B2Vec3 c1,::box2D::common::math::B2Vec3 c2,::box2D::common::math::B2Vec3 c3){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat33","setVVV",0x5223f546,"box2D.common.math.B2Mat33.setVVV","box2D/common/math/B2Mat33.hx",49,0x01af19c3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c1,"c1")
		HX_STACK_ARG(c2,"c2")
		HX_STACK_ARG(c3,"c3")
		HX_STACK_LINE(50)
		this->col1->setV(c1);
		HX_STACK_LINE(51)
		this->col2->setV(c2);
		HX_STACK_LINE(52)
		this->col3->setV(c3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Mat33_obj,setVVV,(void))

::box2D::common::math::B2Mat33 B2Mat33_obj::copy( ){
	HX_STACK_FRAME("box2D.common.math.B2Mat33","copy",0xba7b25c7,"box2D.common.math.B2Mat33.copy","box2D/common/math/B2Mat33.hx",56,0x01af19c3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(56)
	return ::box2D::common::math::B2Mat33_obj::__new(this->col1,this->col2,this->col3);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat33_obj,copy,return )

Void B2Mat33_obj::setM( ::box2D::common::math::B2Mat33 m){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat33","setM",0xc506fc7d,"box2D.common.math.B2Mat33.setM","box2D/common/math/B2Mat33.hx",60,0x01af19c3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(61)
		this->col1->setV(m->col1);
		HX_STACK_LINE(62)
		this->col2->setV(m->col2);
		HX_STACK_LINE(63)
		this->col3->setV(m->col3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat33_obj,setM,(void))

Void B2Mat33_obj::addM( ::box2D::common::math::B2Mat33 m){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat33","addM",0xb920551e,"box2D.common.math.B2Mat33.addM","box2D/common/math/B2Mat33.hx",67,0x01af19c3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(68)
		hx::AddEq(this->col1->x,m->col1->x);
		HX_STACK_LINE(69)
		hx::AddEq(this->col1->y,m->col1->y);
		HX_STACK_LINE(70)
		hx::AddEq(this->col1->z,m->col1->z);
		HX_STACK_LINE(71)
		hx::AddEq(this->col2->x,m->col2->x);
		HX_STACK_LINE(72)
		hx::AddEq(this->col2->y,m->col2->y);
		HX_STACK_LINE(73)
		hx::AddEq(this->col2->z,m->col2->z);
		HX_STACK_LINE(74)
		hx::AddEq(this->col3->x,m->col3->x);
		HX_STACK_LINE(75)
		hx::AddEq(this->col3->y,m->col3->y);
		HX_STACK_LINE(76)
		hx::AddEq(this->col3->z,m->col3->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Mat33_obj,addM,(void))

Void B2Mat33_obj::setIdentity( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat33","setIdentity",0x7c66eb2e,"box2D.common.math.B2Mat33.setIdentity","box2D/common/math/B2Mat33.hx",80,0x01af19c3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(81)
		this->col1->x = 1.0;
		HX_STACK_LINE(81)
		this->col2->x = 0.0;
		HX_STACK_LINE(81)
		this->col3->x = 0.0;
		HX_STACK_LINE(82)
		this->col1->y = 0.0;
		HX_STACK_LINE(82)
		this->col2->y = 1.0;
		HX_STACK_LINE(82)
		this->col3->y = 0.0;
		HX_STACK_LINE(83)
		this->col1->z = 0.0;
		HX_STACK_LINE(83)
		this->col2->z = 0.0;
		HX_STACK_LINE(83)
		this->col3->z = 1.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat33_obj,setIdentity,(void))

Void B2Mat33_obj::setZero( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Mat33","setZero",0x9002fd18,"box2D.common.math.B2Mat33.setZero","box2D/common/math/B2Mat33.hx",87,0x01af19c3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(88)
		this->col1->x = 0.0;
		HX_STACK_LINE(88)
		this->col2->x = 0.0;
		HX_STACK_LINE(88)
		this->col3->x = 0.0;
		HX_STACK_LINE(89)
		this->col1->y = 0.0;
		HX_STACK_LINE(89)
		this->col2->y = 0.0;
		HX_STACK_LINE(89)
		this->col3->y = 0.0;
		HX_STACK_LINE(90)
		this->col1->z = 0.0;
		HX_STACK_LINE(90)
		this->col2->z = 0.0;
		HX_STACK_LINE(90)
		this->col3->z = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Mat33_obj,setZero,(void))

::box2D::common::math::B2Vec2 B2Mat33_obj::solve22( ::box2D::common::math::B2Vec2 out,Float bX,Float bY){
	HX_STACK_FRAME("box2D.common.math.B2Mat33","solve22",0x06e1b62d,"box2D.common.math.B2Mat33.solve22","box2D/common/math/B2Mat33.hx",95,0x01af19c3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(out,"out")
	HX_STACK_ARG(bX,"bX")
	HX_STACK_ARG(bY,"bY")
	HX_STACK_LINE(97)
	Float a11 = this->col1->x;		HX_STACK_VAR(a11,"a11");
	HX_STACK_LINE(98)
	Float a12 = this->col2->x;		HX_STACK_VAR(a12,"a12");
	HX_STACK_LINE(99)
	Float a21 = this->col1->y;		HX_STACK_VAR(a21,"a21");
	HX_STACK_LINE(100)
	Float a22 = this->col2->y;		HX_STACK_VAR(a22,"a22");
	HX_STACK_LINE(102)
	Float det = ((a11 * a22) - (a12 * a21));		HX_STACK_VAR(det,"det");
	HX_STACK_LINE(103)
	if (((det != 0.0))){
		HX_STACK_LINE(105)
		det = (Float(1.0) / Float(det));
	}
	HX_STACK_LINE(107)
	out->x = (det * (((a22 * bX) - (a12 * bY))));
	HX_STACK_LINE(108)
	out->y = (det * (((a11 * bY) - (a21 * bX))));
	HX_STACK_LINE(110)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC3(B2Mat33_obj,solve22,return )

::box2D::common::math::B2Vec3 B2Mat33_obj::solve33( ::box2D::common::math::B2Vec3 out,Float bX,Float bY,Float bZ){
	HX_STACK_FRAME("box2D.common.math.B2Mat33","solve33",0x06e1b70d,"box2D.common.math.B2Mat33.solve33","box2D/common/math/B2Mat33.hx",115,0x01af19c3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(out,"out")
	HX_STACK_ARG(bX,"bX")
	HX_STACK_ARG(bY,"bY")
	HX_STACK_ARG(bZ,"bZ")
	HX_STACK_LINE(116)
	Float a11 = this->col1->x;		HX_STACK_VAR(a11,"a11");
	HX_STACK_LINE(117)
	Float a21 = this->col1->y;		HX_STACK_VAR(a21,"a21");
	HX_STACK_LINE(118)
	Float a31 = this->col1->z;		HX_STACK_VAR(a31,"a31");
	HX_STACK_LINE(119)
	Float a12 = this->col2->x;		HX_STACK_VAR(a12,"a12");
	HX_STACK_LINE(120)
	Float a22 = this->col2->y;		HX_STACK_VAR(a22,"a22");
	HX_STACK_LINE(121)
	Float a32 = this->col2->z;		HX_STACK_VAR(a32,"a32");
	HX_STACK_LINE(122)
	Float a13 = this->col3->x;		HX_STACK_VAR(a13,"a13");
	HX_STACK_LINE(123)
	Float a23 = this->col3->y;		HX_STACK_VAR(a23,"a23");
	HX_STACK_LINE(124)
	Float a33 = this->col3->z;		HX_STACK_VAR(a33,"a33");
	HX_STACK_LINE(126)
	Float det = (((a11 * (((a22 * a33) - (a32 * a23)))) + (a21 * (((a32 * a13) - (a12 * a33))))) + (a31 * (((a12 * a23) - (a22 * a13)))));		HX_STACK_VAR(det,"det");
	HX_STACK_LINE(129)
	if (((det != 0.0))){
		HX_STACK_LINE(131)
		det = (Float(1.0) / Float(det));
	}
	HX_STACK_LINE(134)
	out->x = (det * ((((bX * (((a22 * a33) - (a32 * a23)))) + (bY * (((a32 * a13) - (a12 * a33))))) + (bZ * (((a12 * a23) - (a22 * a13)))))));
	HX_STACK_LINE(138)
	out->y = (det * ((((a11 * (((bY * a33) - (bZ * a23)))) + (a21 * (((bZ * a13) - (bX * a33))))) + (a31 * (((bX * a23) - (bY * a13)))))));
	HX_STACK_LINE(142)
	out->z = (det * ((((a11 * (((a22 * bZ) - (a32 * bY)))) + (a21 * (((a32 * bX) - (a12 * bZ))))) + (a31 * (((a12 * bY) - (a22 * bX)))))));
	HX_STACK_LINE(145)
	return out;
}


HX_DEFINE_DYNAMIC_FUNC4(B2Mat33_obj,solve33,return )


B2Mat33_obj::B2Mat33_obj()
{
}

void B2Mat33_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Mat33);
	HX_MARK_MEMBER_NAME(col1,"col1");
	HX_MARK_MEMBER_NAME(col2,"col2");
	HX_MARK_MEMBER_NAME(col3,"col3");
	HX_MARK_END_CLASS();
}

void B2Mat33_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(col1,"col1");
	HX_VISIT_MEMBER_NAME(col2,"col2");
	HX_VISIT_MEMBER_NAME(col3,"col3");
}

Dynamic B2Mat33_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"setM") ) { return setM_dyn(); }
		if (HX_FIELD_EQ(inName,"addM") ) { return addM_dyn(); }
		if (HX_FIELD_EQ(inName,"col1") ) { return col1; }
		if (HX_FIELD_EQ(inName,"col2") ) { return col2; }
		if (HX_FIELD_EQ(inName,"col3") ) { return col3; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"setVVV") ) { return setVVV_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		if (HX_FIELD_EQ(inName,"solve22") ) { return solve22_dyn(); }
		if (HX_FIELD_EQ(inName,"solve33") ) { return solve33_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setIdentity") ) { return setIdentity_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Mat33_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"col1") ) { col1=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"col2") ) { col2=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"col3") ) { col3=inValue.Cast< ::box2D::common::math::B2Vec3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Mat33_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("col1"));
	outFields->push(HX_CSTRING("col2"));
	outFields->push(HX_CSTRING("col3"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec3*/ ,(int)offsetof(B2Mat33_obj,col1),HX_CSTRING("col1")},
	{hx::fsObject /*::box2D::common::math::B2Vec3*/ ,(int)offsetof(B2Mat33_obj,col2),HX_CSTRING("col2")},
	{hx::fsObject /*::box2D::common::math::B2Vec3*/ ,(int)offsetof(B2Mat33_obj,col3),HX_CSTRING("col3")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("setVVV"),
	HX_CSTRING("copy"),
	HX_CSTRING("setM"),
	HX_CSTRING("addM"),
	HX_CSTRING("setIdentity"),
	HX_CSTRING("setZero"),
	HX_CSTRING("solve22"),
	HX_CSTRING("solve33"),
	HX_CSTRING("col1"),
	HX_CSTRING("col2"),
	HX_CSTRING("col3"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Mat33_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Mat33_obj::__mClass,"__mClass");
};

#endif

Class B2Mat33_obj::__mClass;

void B2Mat33_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Mat33"), hx::TCanCast< B2Mat33_obj> ,sStaticFields,sMemberFields,
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

void B2Mat33_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
