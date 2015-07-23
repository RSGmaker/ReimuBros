#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_box2D_common_B2Color
#include <box2D/common/B2Color.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Math
#include <box2D/common/math/B2Math.h>
#endif
namespace box2D{
namespace common{

Void B2Color_obj::__construct(Float rr,Float gg,Float bb)
{
HX_STACK_FRAME("box2D.common.B2Color","new",0x26dfc373,"box2D.common.B2Color.new","box2D/common/B2Color.hx",32,0x57bd057d)
HX_STACK_THIS(this)
HX_STACK_ARG(rr,"rr")
HX_STACK_ARG(gg,"gg")
HX_STACK_ARG(bb,"bb")
{
	HX_STACK_LINE(33)
	Float _g = ::box2D::common::math::B2Math_obj::clamp(rr,0.0,1.0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	Float _g1 = ((int)255 * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(33)
	int _g2 = ::Std_obj::_int(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(33)
	this->_r = _g2;
	HX_STACK_LINE(34)
	Float _g3 = ::box2D::common::math::B2Math_obj::clamp(gg,0.0,1.0);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(34)
	Float _g4 = ((int)255 * _g3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(34)
	int _g5 = ::Std_obj::_int(_g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(34)
	this->_g = _g5;
	HX_STACK_LINE(35)
	Float _g6 = ::box2D::common::math::B2Math_obj::clamp(bb,0.0,1.0);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(35)
	Float _g7 = ((int)255 * _g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(35)
	int _g8 = ::Std_obj::_int(_g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(35)
	this->_b = _g8;
}
;
	return null();
}

//B2Color_obj::~B2Color_obj() { }

Dynamic B2Color_obj::__CreateEmpty() { return  new B2Color_obj; }
hx::ObjectPtr< B2Color_obj > B2Color_obj::__new(Float rr,Float gg,Float bb)
{  hx::ObjectPtr< B2Color_obj > result = new B2Color_obj();
	result->__construct(rr,gg,bb);
	return result;}

Dynamic B2Color_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Color_obj > result = new B2Color_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void B2Color_obj::set( Float rr,Float gg,Float bb){
{
		HX_STACK_FRAME("box2D.common.B2Color","set",0x26e38eb5,"box2D.common.B2Color.set","box2D/common/B2Color.hx",38,0x57bd057d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(rr,"rr")
		HX_STACK_ARG(gg,"gg")
		HX_STACK_ARG(bb,"bb")
		HX_STACK_LINE(39)
		Float _g = ::box2D::common::math::B2Math_obj::clamp(rr,0.0,1.0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(39)
		Float _g1 = ((int)255 * _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(39)
		int _g2 = ::Std_obj::_int(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(39)
		this->_r = _g2;
		HX_STACK_LINE(40)
		Float _g3 = ::box2D::common::math::B2Math_obj::clamp(gg,0.0,1.0);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(40)
		Float _g4 = ((int)255 * _g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(40)
		int _g5 = ::Std_obj::_int(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(40)
		this->_g = _g5;
		HX_STACK_LINE(41)
		Float _g6 = ::box2D::common::math::B2Math_obj::clamp(bb,0.0,1.0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(41)
		Float _g7 = ((int)255 * _g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(41)
		int _g8 = ::Std_obj::_int(_g7);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(41)
		this->_b = _g8;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(B2Color_obj,set,(void))

Float B2Color_obj::set_r( Float rr){
	HX_STACK_FRAME("box2D.common.B2Color","set_r",0x51ecb928,"box2D.common.B2Color.set_r","box2D/common/B2Color.hx",50,0x57bd057d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(rr,"rr")
	HX_STACK_LINE(51)
	Float _g = ::box2D::common::math::B2Math_obj::clamp(rr,0.0,1.0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(51)
	Float _g1 = ((int)255 * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(51)
	int _g2 = ::Std_obj::_int(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(51)
	return this->_r = _g2;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Color_obj,set_r,return )

Float B2Color_obj::set_g( Float gg){
	HX_STACK_FRAME("box2D.common.B2Color","set_g",0x51ecb91d,"box2D.common.B2Color.set_g","box2D/common/B2Color.hx",54,0x57bd057d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(gg,"gg")
	HX_STACK_LINE(55)
	Float _g = ::box2D::common::math::B2Math_obj::clamp(gg,0.0,1.0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(55)
	Float _g1 = ((int)255 * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(55)
	int _g2 = ::Std_obj::_int(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(55)
	return this->_g = _g2;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Color_obj,set_g,return )

Float B2Color_obj::set_b( Float bb){
	HX_STACK_FRAME("box2D.common.B2Color","set_b",0x51ecb918,"box2D.common.B2Color.set_b","box2D/common/B2Color.hx",58,0x57bd057d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(bb,"bb")
	HX_STACK_LINE(59)
	Float _g = ::box2D::common::math::B2Math_obj::clamp(bb,0.0,1.0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(59)
	Float _g1 = ((int)255 * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(59)
	int _g2 = ::Std_obj::_int(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(59)
	return this->_b = _g2;
}


HX_DEFINE_DYNAMIC_FUNC1(B2Color_obj,set_b,return )

int B2Color_obj::get_color( ){
	HX_STACK_FRAME("box2D.common.B2Color","get_color",0xa4a1d10d,"box2D.common.B2Color.get_color","box2D/common/B2Color.hx",64,0x57bd057d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(64)
	return (int((int((int(this->_r) << int((int)16))) | int((int(this->_g) << int((int)8))))) | int(this->_b));
}


HX_DEFINE_DYNAMIC_FUNC0(B2Color_obj,get_color,return )


B2Color_obj::B2Color_obj()
{
}

Dynamic B2Color_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { return r; }
		if (HX_FIELD_EQ(inName,"g") ) { return g; }
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_r") ) { return _r; }
		if (HX_FIELD_EQ(inName,"_g") ) { return _g; }
		if (HX_FIELD_EQ(inName,"_b") ) { return _b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return inCallProp ? get_color() : color; }
		if (HX_FIELD_EQ(inName,"set_r") ) { return set_r_dyn(); }
		if (HX_FIELD_EQ(inName,"set_g") ) { return set_g_dyn(); }
		if (HX_FIELD_EQ(inName,"set_b") ) { return set_b_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Color_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"r") ) { if (inCallProp) return set_r(inValue);r=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"g") ) { if (inCallProp) return set_g(inValue);g=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"b") ) { if (inCallProp) return set_b(inValue);b=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"_r") ) { _r=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_g") ) { _g=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_b") ) { _b=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Color_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("r"));
	outFields->push(HX_CSTRING("g"));
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("_r"));
	outFields->push(HX_CSTRING("_g"));
	outFields->push(HX_CSTRING("_b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(B2Color_obj,r),HX_CSTRING("r")},
	{hx::fsFloat,(int)offsetof(B2Color_obj,g),HX_CSTRING("g")},
	{hx::fsFloat,(int)offsetof(B2Color_obj,b),HX_CSTRING("b")},
	{hx::fsInt,(int)offsetof(B2Color_obj,color),HX_CSTRING("color")},
	{hx::fsInt,(int)offsetof(B2Color_obj,_r),HX_CSTRING("_r")},
	{hx::fsInt,(int)offsetof(B2Color_obj,_g),HX_CSTRING("_g")},
	{hx::fsInt,(int)offsetof(B2Color_obj,_b),HX_CSTRING("_b")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("r"),
	HX_CSTRING("g"),
	HX_CSTRING("b"),
	HX_CSTRING("color"),
	HX_CSTRING("set_r"),
	HX_CSTRING("set_g"),
	HX_CSTRING("set_b"),
	HX_CSTRING("get_color"),
	HX_CSTRING("_r"),
	HX_CSTRING("_g"),
	HX_CSTRING("_b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Color_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Color_obj::__mClass,"__mClass");
};

#endif

Class B2Color_obj::__mClass;

void B2Color_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.common.B2Color"), hx::TCanCast< B2Color_obj> ,sStaticFields,sMemberFields,
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

void B2Color_obj::__boot()
{
}

} // end namespace box2D
} // end namespace common
