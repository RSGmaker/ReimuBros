#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
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
namespace common{
namespace math{

Void B2Transform_obj::__construct(::box2D::common::math::B2Vec2 pos,::box2D::common::math::B2Mat22 r)
{
HX_STACK_FRAME("box2D.common.math.B2Transform","new",0x3d78c0ba,"box2D.common.math.B2Transform.new","box2D/common/math/B2Transform.hx",32,0x09863597)
HX_STACK_THIS(this)
HX_STACK_ARG(pos,"pos")
HX_STACK_ARG(r,"r")
{
	HX_STACK_LINE(34)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	this->position = _g;
	HX_STACK_LINE(35)
	::box2D::common::math::B2Mat22 _g1 = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(35)
	this->R = _g1;
	HX_STACK_LINE(37)
	if (((pos != null()))){
		HX_STACK_LINE(39)
		this->position->setV(pos);
		HX_STACK_LINE(40)
		this->R->setM(r);
	}
}
;
	return null();
}

//B2Transform_obj::~B2Transform_obj() { }

Dynamic B2Transform_obj::__CreateEmpty() { return  new B2Transform_obj; }
hx::ObjectPtr< B2Transform_obj > B2Transform_obj::__new(::box2D::common::math::B2Vec2 pos,::box2D::common::math::B2Mat22 r)
{  hx::ObjectPtr< B2Transform_obj > result = new B2Transform_obj();
	result->__construct(pos,r);
	return result;}

Dynamic B2Transform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Transform_obj > result = new B2Transform_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void B2Transform_obj::initialize( ::box2D::common::math::B2Vec2 pos,::box2D::common::math::B2Mat22 r){
{
		HX_STACK_FRAME("box2D.common.math.B2Transform","initialize",0xc2d06036,"box2D.common.math.B2Transform.initialize","box2D/common/math/B2Transform.hx",50,0x09863597)
		HX_STACK_THIS(this)
		HX_STACK_ARG(pos,"pos")
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(51)
		this->position->setV(pos);
		HX_STACK_LINE(52)
		this->R->setM(r);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(B2Transform_obj,initialize,(void))

Void B2Transform_obj::setIdentity( ){
{
		HX_STACK_FRAME("box2D.common.math.B2Transform","setIdentity",0x6603e95a,"box2D.common.math.B2Transform.setIdentity","box2D/common/math/B2Transform.hx",59,0x09863597)
		HX_STACK_THIS(this)
		HX_STACK_LINE(60)
		this->position->setZero();
		HX_STACK_LINE(61)
		this->R->setIdentity();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Transform_obj,setIdentity,(void))

Void B2Transform_obj::set( ::box2D::common::math::B2Transform x){
{
		HX_STACK_FRAME("box2D.common.math.B2Transform","set",0x3d7c8bfc,"box2D.common.math.B2Transform.set","box2D/common/math/B2Transform.hx",64,0x09863597)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x,"x")
		HX_STACK_LINE(66)
		this->position->setV(x->position);
		HX_STACK_LINE(68)
		this->R->setM(x->R);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2Transform_obj,set,(void))

Float B2Transform_obj::getAngle( ){
	HX_STACK_FRAME("box2D.common.math.B2Transform","getAngle",0xc5ccdcc3,"box2D.common.math.B2Transform.getAngle","box2D/common/math/B2Transform.hx",77,0x09863597)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return ::Math_obj::atan2(this->R->col1->y,this->R->col1->x);
}


HX_DEFINE_DYNAMIC_FUNC0(B2Transform_obj,getAngle,return )


B2Transform_obj::B2Transform_obj()
{
}

void B2Transform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Transform);
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(R,"R");
	HX_MARK_END_CLASS();
}

void B2Transform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(R,"R");
}

Dynamic B2Transform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"R") ) { return R; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAngle") ) { return getAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setIdentity") ) { return setIdentity_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Transform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"R") ) { R=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Transform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("R"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Transform_obj,position),HX_CSTRING("position")},
	{hx::fsObject /*::box2D::common::math::B2Mat22*/ ,(int)offsetof(B2Transform_obj,R),HX_CSTRING("R")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("initialize"),
	HX_CSTRING("setIdentity"),
	HX_CSTRING("set"),
	HX_CSTRING("getAngle"),
	HX_CSTRING("position"),
	HX_CSTRING("R"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Transform_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Transform_obj::__mClass,"__mClass");
};

#endif

Class B2Transform_obj::__mClass;

void B2Transform_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.math.B2Transform"), hx::TCanCast< B2Transform_obj> ,sStaticFields,sMemberFields,
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

void B2Transform_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
} // end namespace math
