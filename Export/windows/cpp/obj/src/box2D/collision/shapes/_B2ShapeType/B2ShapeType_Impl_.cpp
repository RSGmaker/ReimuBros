#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_shapes__B2ShapeType_B2ShapeType_Impl_
#include <box2D/collision/shapes/_B2ShapeType/B2ShapeType_Impl_.h>
#endif
namespace box2D{
namespace collision{
namespace shapes{
namespace _B2ShapeType{

Void B2ShapeType_Impl__obj::__construct()
{
	return null();
}

//B2ShapeType_Impl__obj::~B2ShapeType_Impl__obj() { }

Dynamic B2ShapeType_Impl__obj::__CreateEmpty() { return  new B2ShapeType_Impl__obj; }
hx::ObjectPtr< B2ShapeType_Impl__obj > B2ShapeType_Impl__obj::__new()
{  hx::ObjectPtr< B2ShapeType_Impl__obj > result = new B2ShapeType_Impl__obj();
	result->__construct();
	return result;}

Dynamic B2ShapeType_Impl__obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ShapeType_Impl__obj > result = new B2ShapeType_Impl__obj();
	result->__construct();
	return result;}

int B2ShapeType_Impl__obj::UNKNOWN_SHAPE;

int B2ShapeType_Impl__obj::CIRCLE_SHAPE;

int B2ShapeType_Impl__obj::POLYGON_SHAPE;

int B2ShapeType_Impl__obj::EDGE_SHAPE;


B2ShapeType_Impl__obj::B2ShapeType_Impl__obj()
{
}

Dynamic B2ShapeType_Impl__obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic B2ShapeType_Impl__obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ShapeType_Impl__obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("UNKNOWN_SHAPE"),
	HX_CSTRING("CIRCLE_SHAPE"),
	HX_CSTRING("POLYGON_SHAPE"),
	HX_CSTRING("EDGE_SHAPE"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ShapeType_Impl__obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2ShapeType_Impl__obj::UNKNOWN_SHAPE,"UNKNOWN_SHAPE");
	HX_MARK_MEMBER_NAME(B2ShapeType_Impl__obj::CIRCLE_SHAPE,"CIRCLE_SHAPE");
	HX_MARK_MEMBER_NAME(B2ShapeType_Impl__obj::POLYGON_SHAPE,"POLYGON_SHAPE");
	HX_MARK_MEMBER_NAME(B2ShapeType_Impl__obj::EDGE_SHAPE,"EDGE_SHAPE");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ShapeType_Impl__obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2ShapeType_Impl__obj::UNKNOWN_SHAPE,"UNKNOWN_SHAPE");
	HX_VISIT_MEMBER_NAME(B2ShapeType_Impl__obj::CIRCLE_SHAPE,"CIRCLE_SHAPE");
	HX_VISIT_MEMBER_NAME(B2ShapeType_Impl__obj::POLYGON_SHAPE,"POLYGON_SHAPE");
	HX_VISIT_MEMBER_NAME(B2ShapeType_Impl__obj::EDGE_SHAPE,"EDGE_SHAPE");
};

#endif

Class B2ShapeType_Impl__obj::__mClass;

void B2ShapeType_Impl__obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.shapes._B2ShapeType.B2ShapeType_Impl_"), hx::TCanCast< B2ShapeType_Impl__obj> ,sStaticFields,sMemberFields,
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

void B2ShapeType_Impl__obj::__boot()
{
	UNKNOWN_SHAPE= (int)0;
	CIRCLE_SHAPE= (int)1;
	POLYGON_SHAPE= (int)2;
	EDGE_SHAPE= (int)3;
}

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
} // end namespace _B2ShapeType
