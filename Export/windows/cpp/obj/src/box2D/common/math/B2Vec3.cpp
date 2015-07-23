#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec3
#include <box2D/common/math/B2Vec3.h>
#endif
namespace box2D{
namespace common{
namespace math{

Void B2Vec3_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z)
{
HX_STACK_FRAME("box2D.common.math.B2Vec3","new",0x135af4f5,"box2D.common.math.B2Vec3.new","box2D/common/math/B2Vec3.hx",32,0x292a021a)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_x,"x")
HX_STACK_ARG(__o_y,"y")
HX_STACK_ARG(__o_z,"z")
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
Float z = __o_z.Default(0);
{
	HX_STACK_LINE(33)
	this->x = x;
	HX_STACK_LINE(34)
	this->y = y;
	HX_STACK_LINE(35)
	this->z = z;
}
;
	return null();
}

//B2Vec3_obj::~B2Vec3_obj() { }

Dynamic B2Vec3_obj::__CreateEmpty() { return  new B2Vec3_obj; }
hx::ObjectPtr< B2Vec3_obj > B2Vec3_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_z)
{  hx::ObjectPtr< B2Vec3_obj > result = new B2Vec3_obj();
	result->__construct(__o_x,__o_y,__o_z);
	return result;}

Dynamic B2Vec3_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Vec3_obj > result = new B2Vec3_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void B2Vec3_obj::setZero( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec3","setZero",0xf092e2ff,"box2D.common.math.B2Vec3.setZero","box2D/common/math/B2Vec3.hx",42,0x292a021a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(43)
		Float _g = this->z = 0.0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		Float _g1 = this->y = _g;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(43)
		this->x = _g1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,setZero,(void))

Void B2Vec3_obj::set( Float x,Float y,Float z){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec3","set",0x135ec037,"box2D.common.math.B2Vec3.set","box2D/common/math/B2Vec3.hx",50,0x292a021a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_ARG(y,"y")
		HX_STACK_ARG(z,"z")
		HX_STACK_LINE(51)
		this->x = x;
		HX_STACK_LINE(52)
		this->y = y;
		HX_STACK_LINE(53)
		this->z = z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Vec3_obj,set,(void))

Void B2Vec3_obj::setV( ::box2D::common::math::B2Vec3 v){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec3","setV",0xdf89703f,"box2D.common.math.B2Vec3.setV","box2D/common/math/B2Vec3.hx",57,0x292a021a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(58)
		this->x = v->x;
		HX_STACK_LINE(59)
		this->y = v->y;
		HX_STACK_LINE(60)
		this->z = v->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,setV,(void))

::box2D::common::math::B2Vec3 B2Vec3_obj::getNegative( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec3","getNegative",0x22832ac0,"box2D.common.math.B2Vec3.getNegative","box2D/common/math/B2Vec3.hx",66,0x292a021a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(66)
	return ::box2D::common::math::B2Vec3_obj::__new(-(this->x),-(this->y),-(this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,getNegative,return )

Void B2Vec3_obj::negativeSelf( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec3","negativeSelf",0x21a4dd6c,"box2D.common.math.B2Vec3.negativeSelf","box2D/common/math/B2Vec3.hx",68,0x292a021a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(68)
		this->x = -(this->x);
		HX_STACK_LINE(68)
		this->y = -(this->y);
		HX_STACK_LINE(68)
		this->z = -(this->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,negativeSelf,(void))

::box2D::common::math::B2Vec3 B2Vec3_obj::copy( ){
	HX_STACK_FRAME("box2D.common.math.B2Vec3","copy",0xd4fd9980,"box2D.common.math.B2Vec3.copy","box2D/common/math/B2Vec3.hx",71,0x292a021a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(71)
	return ::box2D::common::math::B2Vec3_obj::__new(this->x,this->y,this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Vec3_obj,copy,return )

Void B2Vec3_obj::add( ::box2D::common::math::B2Vec3 v){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec3","add",0x135116b6,"box2D.common.math.B2Vec3.add","box2D/common/math/B2Vec3.hx",75,0x292a021a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(76)
		hx::AddEq(this->x,v->x);
		HX_STACK_LINE(76)
		hx::AddEq(this->y,v->y);
		HX_STACK_LINE(76)
		hx::AddEq(this->z,v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,add,(void))

Void B2Vec3_obj::subtract( ::box2D::common::math::B2Vec3 v){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec3","subtract",0xf7d4945f,"box2D.common.math.B2Vec3.subtract","box2D/common/math/B2Vec3.hx",80,0x292a021a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(81)
		hx::SubEq(this->x,v->x);
		HX_STACK_LINE(81)
		hx::SubEq(this->y,v->y);
		HX_STACK_LINE(81)
		hx::SubEq(this->z,v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,subtract,(void))

Void B2Vec3_obj::multiply( Float a){
{
		HX_STACK_FRAME("box2D.common.math.B2Vec3","multiply",0x9a50016f,"box2D.common.math.B2Vec3.multiply","box2D/common/math/B2Vec3.hx",85,0x292a021a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(a,"a")
		HX_STACK_LINE(86)
		hx::MultEq(this->x,a);
		HX_STACK_LINE(86)
		hx::MultEq(this->y,a);
		HX_STACK_LINE(86)
		hx::MultEq(this->z,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Vec3_obj,multiply,(void))


B2Vec3_obj::B2Vec3_obj()
{
}

Dynamic B2Vec3_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"setV") ) { return setV_dyn(); }
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		if (HX_FIELD_EQ(inName,"multiply") ) { return multiply_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getNegative") ) { return getNegative_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"negativeSelf") ) { return negativeSelf_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Vec3_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Vec3_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(B2Vec3_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(B2Vec3_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(B2Vec3_obj,z),HX_CSTRING("z")},
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
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("z"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Vec3_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Vec3_obj::__mClass,"__mClass");
};

#endif

Class B2Vec3_obj::__mClass;

void B2Vec3_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Vec3"), hx::TCanCast< B2Vec3_obj> ,sStaticFields,sMemberFields,
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

void B2Vec3_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
