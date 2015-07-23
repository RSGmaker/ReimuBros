#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2SimplexCache
#include <box2D/collision/B2SimplexCache.h>
#endif
namespace box2D{
namespace collision{

Void B2SimplexCache_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2SimplexCache","new",0x3b50aa0b,"box2D.collision.B2SimplexCache.new","box2D/collision/B2SimplexCache.hx",25,0x405c6a43)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(37)
	this->count = (int)0;
	HX_STACK_LINE(36)
	this->metric = (int)0;
	HX_STACK_LINE(30)
	Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->indexA = _g;
	HX_STACK_LINE(31)
	Array< int > _g1 = Array_obj< int >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(31)
	this->indexB = _g1;
}
;
	return null();
}

//B2SimplexCache_obj::~B2SimplexCache_obj() { }

Dynamic B2SimplexCache_obj::__CreateEmpty() { return  new B2SimplexCache_obj; }
hx::ObjectPtr< B2SimplexCache_obj > B2SimplexCache_obj::__new()
{  hx::ObjectPtr< B2SimplexCache_obj > result = new B2SimplexCache_obj();
	result->__construct();
	return result;}

Dynamic B2SimplexCache_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2SimplexCache_obj > result = new B2SimplexCache_obj();
	result->__construct();
	return result;}


B2SimplexCache_obj::B2SimplexCache_obj()
{
}

void B2SimplexCache_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2SimplexCache);
	HX_MARK_MEMBER_NAME(metric,"metric");
	HX_MARK_MEMBER_NAME(count,"count");
	HX_MARK_MEMBER_NAME(indexA,"indexA");
	HX_MARK_MEMBER_NAME(indexB,"indexB");
	HX_MARK_END_CLASS();
}

void B2SimplexCache_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(metric,"metric");
	HX_VISIT_MEMBER_NAME(count,"count");
	HX_VISIT_MEMBER_NAME(indexA,"indexA");
	HX_VISIT_MEMBER_NAME(indexB,"indexB");
}

Dynamic B2SimplexCache_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return count; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"metric") ) { return metric; }
		if (HX_FIELD_EQ(inName,"indexA") ) { return indexA; }
		if (HX_FIELD_EQ(inName,"indexB") ) { return indexB; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2SimplexCache_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { count=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"metric") ) { metric=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexA") ) { indexA=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexB") ) { indexB=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2SimplexCache_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("metric"));
	outFields->push(HX_CSTRING("count"));
	outFields->push(HX_CSTRING("indexA"));
	outFields->push(HX_CSTRING("indexB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(B2SimplexCache_obj,metric),HX_CSTRING("metric")},
	{hx::fsInt,(int)offsetof(B2SimplexCache_obj,count),HX_CSTRING("count")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(B2SimplexCache_obj,indexA),HX_CSTRING("indexA")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(B2SimplexCache_obj,indexB),HX_CSTRING("indexB")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("metric"),
	HX_CSTRING("count"),
	HX_CSTRING("indexA"),
	HX_CSTRING("indexB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2SimplexCache_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2SimplexCache_obj::__mClass,"__mClass");
};

#endif

Class B2SimplexCache_obj::__mClass;

void B2SimplexCache_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2SimplexCache"), hx::TCanCast< B2SimplexCache_obj> ,sStaticFields,sMemberFields,
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

void B2SimplexCache_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
