#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
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

Void B2Vec2_obj::__construct(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_)
{
HX_STACK_FRAME("box2D.common.math.B2Vec2","new",0x7ff46074,"box2D.common.math.B2Vec2.new","box2D/common/math/B2Vec2.hx",28,0x2880cb7b)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_x_,"x_")
HX_STACK_ARG(__o_y_,"y_")
Float x_ = __o_x_.Default(0);
Float y_ = __o_y_.Default(0);
{
	HX_STACK_LINE(28)
	this->x = x_;
	HX_STACK_LINE(28)
	this->y = y_;
}
;
	return null();
}

//B2Vec2_obj::~B2Vec2_obj() { }

Dynamic B2Vec2_obj::__CreateEmpty() { return  new B2Vec2_obj; }
hx::ObjectPtr< B2Vec2_obj > B2Vec2_obj::__new(hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_)
{  hx::ObjectPtr< B2Vec2_obj > result = new B2Vec2_obj();
	result->__construct(__o_x_,__o_y_);
	return result;}

Dynamic B2Vec2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Vec2_obj > result = new B2Vec2_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void B2Vec2_obj::setZero( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","setZero",0x1da179fe,"box2D.common.math.B2Vec2.setZero","box2D/common/math/B2Vec2.hx",30,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(30)
		this->x = 0.0;
		HX_STACK_LINE(30)
		this->y = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,setZero,(void))

Void B2Vec2_obj::set( hx::Null< Float >  __o_x_,hx::Null< Float >  __o_y_){
Float x_ = __o_x_.Default(0);
Float y_ = __o_y_.Default(0);
	HX_STACK_FRAME("box2D.common.math.B2Vec2","set",0x7ff82bb6,"box2D.common.math.B2Vec2.set","box2D/common/math/B2Vec2.hx",31,0x2880cb7b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x_,"x_")
	HX_STACK_ARG(y_,"y_")
{
		HX_STACK_LINE(31)
		this->x = x_;
		HX_STACK_LINE(31)
		this->y = y_;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Vec2_obj,set,(void))

Void B2Vec2_obj::setV( ::box2D::common::math::B2Vec2 v){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","setV",0x792e13e0,"box2D.common.math.B2Vec2.setV","box2D/common/math/B2Vec2.hx",32,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(32)
		this->x = v->x;
		HX_STACK_LINE(32)
		this->y = v->y;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,setV,(void))

::box2D::common::math::B2Vec2 B2Vec2_obj::getNegative( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec2","getNegative",0xdcc2ad3f,"box2D.common.math.B2Vec2.getNegative","box2D/common/math/B2Vec2.hx",34,0x2880cb7b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	return ::box2D::common::math::B2Vec2_obj::__new(-(this->x),-(this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,getNegative,return )

Void B2Vec2_obj::negativeSelf( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","negativeSelf",0x5ef78a0d,"box2D.common.math.B2Vec2.negativeSelf","box2D/common/math/B2Vec2.hx",35,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(35)
		this->x = -(this->x);
		HX_STACK_LINE(35)
		this->y = -(this->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,negativeSelf,(void))

::box2D::common::math::B2Vec2 B2Vec2_obj::copy( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec2","copy",0x6ea23d21,"box2D.common.math.B2Vec2.copy","box2D/common/math/B2Vec2.hx",43,0x2880cb7b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(43)
	return ::box2D::common::math::B2Vec2_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,copy,return )

Void B2Vec2_obj::add( ::box2D::common::math::B2Vec2 v){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","add",0x7fea8235,"box2D.common.math.B2Vec2.add","box2D/common/math/B2Vec2.hx",47,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(48)
		hx::AddEq(this->x,v->x);
		HX_STACK_LINE(48)
		hx::AddEq(this->y,v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,add,(void))

Void B2Vec2_obj::subtract( ::box2D::common::math::B2Vec2 v){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","subtract",0x378a1c80,"box2D.common.math.B2Vec2.subtract","box2D/common/math/B2Vec2.hx",52,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(53)
		hx::SubEq(this->x,v->x);
		HX_STACK_LINE(53)
		hx::SubEq(this->y,v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,subtract,(void))

Void B2Vec2_obj::multiply( Float a){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","multiply",0xda058990,"box2D.common.math.B2Vec2.multiply","box2D/common/math/B2Vec2.hx",57,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(a,"a")
		HX_STACK_LINE(58)
		hx::MultEq(this->x,a);
		HX_STACK_LINE(58)
		hx::MultEq(this->y,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,multiply,(void))

Void B2Vec2_obj::mulM( ::box2D::common::math::B2Mat22 A){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","mulM",0x7542e935,"box2D.common.math.B2Vec2.mulM","box2D/common/math/B2Vec2.hx",62,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(A,"A")
		HX_STACK_LINE(63)
		Float tX = this->x;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(64)
		this->x = ((A->col1->x * tX) + (A->col2->x * this->y));
		HX_STACK_LINE(65)
		this->y = ((A->col1->y * tX) + (A->col2->y * this->y));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,mulM,(void))

Void B2Vec2_obj::mulTM( ::box2D::common::math::B2Mat22 A){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","mulTM",0x25492b91,"box2D.common.math.B2Vec2.mulTM","box2D/common/math/B2Vec2.hx",69,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(A,"A")
		HX_STACK_LINE(70)
		Float tX = ::box2D::common::math::B2Math_obj::dot(hx::ObjectPtr<OBJ_>(this),A->col1);		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(71)
		Float _g = ::box2D::common::math::B2Math_obj::dot(hx::ObjectPtr<OBJ_>(this),A->col2);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(71)
		this->y = _g;
		HX_STACK_LINE(72)
		this->x = tX;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,mulTM,(void))

Void B2Vec2_obj::crossVF( Float s){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","crossVF",0xe67db4c4,"box2D.common.math.B2Vec2.crossVF","box2D/common/math/B2Vec2.hx",76,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(77)
		Float tX = this->x;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(78)
		this->x = (s * this->y);
		HX_STACK_LINE(79)
		this->y = (-(s) * tX);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,crossVF,(void))

Void B2Vec2_obj::crossFV( Float s){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","crossFV",0xe67da6e4,"box2D.common.math.B2Vec2.crossFV","box2D/common/math/B2Vec2.hx",83,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(84)
		Float tX = this->x;		HX_STACK_VAR(tX,"tX");
		HX_STACK_LINE(85)
		this->x = (-(s) * this->y);
		HX_STACK_LINE(86)
		this->y = (s * tX);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,crossFV,(void))

Void B2Vec2_obj::minV( ::box2D::common::math::B2Vec2 b){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","minV",0x7539cff0,"box2D.common.math.B2Vec2.minV","box2D/common/math/B2Vec2.hx",90,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(91)
		if (((this->x < b->x))){
			HX_STACK_LINE(91)
			this->x = this->x;
		}
		else{
			HX_STACK_LINE(91)
			this->x = b->x;
		}
		HX_STACK_LINE(92)
		if (((this->y < b->y))){
			HX_STACK_LINE(92)
			this->y = this->y;
		}
		else{
			HX_STACK_LINE(92)
			this->y = b->y;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,minV,(void))

Void B2Vec2_obj::maxV( ::box2D::common::math::B2Vec2 b){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","maxV",0x7533c69e,"box2D.common.math.B2Vec2.maxV","box2D/common/math/B2Vec2.hx",96,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(97)
		if (((this->x > b->x))){
			HX_STACK_LINE(97)
			this->x = this->x;
		}
		else{
			HX_STACK_LINE(97)
			this->x = b->x;
		}
		HX_STACK_LINE(98)
		if (((this->y > b->y))){
			HX_STACK_LINE(98)
			this->y = this->y;
		}
		else{
			HX_STACK_LINE(98)
			this->y = b->y;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec2_obj,maxV,(void))

Void B2Vec2_obj::abs( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec2","abs",0x7fea8086,"box2D.common.math.B2Vec2.abs","box2D/common/math/B2Vec2.hx",102,0x2880cb7b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(103)
		if (((this->x < (int)0))){
			HX_STACK_LINE(103)
			this->x = -(this->x);
		}
		HX_STACK_LINE(104)
		if (((this->y < (int)0))){
			HX_STACK_LINE(104)
			this->y = -(this->y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,abs,(void))

Float B2Vec2_obj::length( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec2","length",0xdf594952,"box2D.common.math.B2Vec2.length","box2D/common/math/B2Vec2.hx",109,0x2880cb7b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(109)
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,length,return )

Float B2Vec2_obj::lengthSquared( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec2","lengthSquared",0xaa9a15f5,"box2D.common.math.B2Vec2.lengthSquared","box2D/common/math/B2Vec2.hx",114,0x2880cb7b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(114)
	return ((this->x * this->x) + (this->y * this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,lengthSquared,return )

Float B2Vec2_obj::normalize( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec2","normalize",0xf5bb0ea1,"box2D.common.math.B2Vec2.normalize","box2D/common/math/B2Vec2.hx",118,0x2880cb7b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(119)
	Float length = ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(120)
	if (((length < 2.2250738585072014e-308))){
		HX_STACK_LINE(122)
		return 0.0;
	}
	HX_STACK_LINE(124)
	Float invLength = (Float(1.0) / Float(length));		HX_STACK_VAR(invLength,"invLength");
	HX_STACK_LINE(125)
	hx::MultEq(this->x,invLength);
	HX_STACK_LINE(126)
	hx::MultEq(this->y,invLength);
	HX_STACK_LINE(128)
	return length;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,normalize,return )

bool B2Vec2_obj::isValid( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec2","isValid",0xd56a42c6,"box2D.common.math.B2Vec2.isValid","box2D/common/math/B2Vec2.hx",133,0x2880cb7b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(133)
	if ((::box2D::common::math::B2Math_obj::isValid(this->x))){
		HX_STACK_LINE(133)
		return ::box2D::common::math::B2Math_obj::isValid(this->y);
	}
	else{
		HX_STACK_LINE(133)
		return false;
	}
	HX_STACK_LINE(133)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec2_obj,isValid,return )

::box2D::common::math::B2Vec2 B2Vec2_obj::make( Float x_,Float y_){
	HX_STACK_FRAME("box2D.common.math.B2Vec2","make",0x7533bb5a,"box2D.common.math.B2Vec2.make","box2D/common/math/B2Vec2.hx",39,0x2880cb7b)
	HX_STACK_ARG(x_,"x_")
	HX_STACK_ARG(y_,"y_")
	HX_STACK_LINE(39)
	return ::box2D::common::math::B2Vec2_obj::__new(x_,y_);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(B2Vec2_obj,make,return )


B2Vec2_obj::B2Vec2_obj()
{
}

Dynamic B2Vec2_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"abs") ) { return abs_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"make") ) { return make_dyn(); }
		if (HX_FIELD_EQ(inName,"setV") ) { return setV_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"mulM") ) { return mulM_dyn(); }
		if (HX_FIELD_EQ(inName,"minV") ) { return minV_dyn(); }
		if (HX_FIELD_EQ(inName,"maxV") ) { return maxV_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mulTM") ) { return mulTM_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		if (HX_FIELD_EQ(inName,"crossVF") ) { return crossVF_dyn(); }
		if (HX_FIELD_EQ(inName,"crossFV") ) { return crossFV_dyn(); }
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		if (HX_FIELD_EQ(inName,"multiply") ) { return multiply_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getNegative") ) { return getNegative_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"negativeSelf") ) { return negativeSelf_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lengthSquared") ) { return lengthSquared_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Vec2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Vec2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("make"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(B2Vec2_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(B2Vec2_obj,y),HX_CSTRING("y")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("setZero"),
	HX_CSTRING("set"),
	HX_CSTRING("setV"),
	HX_CSTRING("getNegative"),
	HX_CSTRING("negativeSelf"),
	HX_CSTRING("copy"),
	HX_CSTRING("add"),
	HX_CSTRING("subtract"),
	HX_CSTRING("multiply"),
	HX_CSTRING("mulM"),
	HX_CSTRING("mulTM"),
	HX_CSTRING("crossVF"),
	HX_CSTRING("crossFV"),
	HX_CSTRING("minV"),
	HX_CSTRING("maxV"),
	HX_CSTRING("abs"),
	HX_CSTRING("length"),
	HX_CSTRING("lengthSquared"),
	HX_CSTRING("normalize"),
	HX_CSTRING("isValid"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Vec2_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Vec2_obj::__mClass,"__mClass");
};

#endif

Class B2Vec2_obj::__mClass;

void B2Vec2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Vec2"), hx::TCanCast< B2Vec2_obj> ,sStaticFields,sMemberFields,
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

void B2Vec2_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
