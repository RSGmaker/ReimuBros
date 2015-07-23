#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_shapes_B2MassData
#include <box2D/collision/shapes/B2MassData.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{
namespace shapes{

Void B2MassData_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.shapes.B2MassData","new",0xefc7beef,"box2D.collision.shapes.B2MassData.new","box2D/collision/shapes/B2MassData.hx",30,0x0b4d5f02)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(32)
	this->mass = 0.0;
	HX_STACK_LINE(33)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new((int)0,(int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->center = _g;
	HX_STACK_LINE(34)
	this->I = 0.0;
}
;
	return null();
}

//B2MassData_obj::~B2MassData_obj() { }

Dynamic B2MassData_obj::__CreateEmpty() { return  new B2MassData_obj; }
hx::ObjectPtr< B2MassData_obj > B2MassData_obj::__new()
{  hx::ObjectPtr< B2MassData_obj > result = new B2MassData_obj();
	result->__construct();
	return result;}

Dynamic B2MassData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2MassData_obj > result = new B2MassData_obj();
	result->__construct();
	return result;}


B2MassData_obj::B2MassData_obj()
{
}

void B2MassData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2MassData);
	HX_MARK_MEMBER_NAME(mass,"mass");
	HX_MARK_MEMBER_NAME(center,"center");
	HX_MARK_MEMBER_NAME(I,"I");
	HX_MARK_END_CLASS();
}

void B2MassData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mass,"mass");
	HX_VISIT_MEMBER_NAME(center,"center");
	HX_VISIT_MEMBER_NAME(I,"I");
}

Dynamic B2MassData_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"I") ) { return I; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mass") ) { return mass; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { return center; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2MassData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"I") ) { I=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mass") ) { mass=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"center") ) { center=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2MassData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mass"));
	outFields->push(HX_CSTRING("center"));
	outFields->push(HX_CSTRING("I"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(B2MassData_obj,mass),HX_CSTRING("mass")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2MassData_obj,center),HX_CSTRING("center")},
	{hx::fsFloat,(int)offsetof(B2MassData_obj,I),HX_CSTRING("I")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mass"),
	HX_CSTRING("center"),
	HX_CSTRING("I"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2MassData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2MassData_obj::__mClass,"__mClass");
};

#endif

Class B2MassData_obj::__mClass;

void B2MassData_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes.B2MassData"), hx::TCanCast< B2MassData_obj> ,sStaticFields,sMemberFields,
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

void B2MassData_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
