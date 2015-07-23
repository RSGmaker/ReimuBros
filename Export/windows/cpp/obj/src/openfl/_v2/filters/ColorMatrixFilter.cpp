#include <hxcpp.h>

#ifndef INCLUDED_openfl__v2_filters_BitmapFilter
#include <openfl/_v2/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_openfl__v2_filters_ColorMatrixFilter
#include <openfl/_v2/filters/ColorMatrixFilter.h>
#endif
namespace openfl{
namespace _v2{
namespace filters{

Void ColorMatrixFilter_obj::__construct(Array< Float > matrix)
{
HX_STACK_FRAME("openfl._v2.filters.ColorMatrixFilter","new",0xe5e5dbca,"openfl._v2.filters.ColorMatrixFilter.new","openfl/_v2/filters/ColorMatrixFilter.hx",10,0x85c284e9)
HX_STACK_THIS(this)
HX_STACK_ARG(matrix,"matrix")
{
	HX_STACK_LINE(12)
	super::__construct(HX_CSTRING("ColorMatrixFilter"));
	HX_STACK_LINE(14)
	if (((matrix == null()))){
		HX_STACK_LINE(16)
		matrix = Array_obj< Float >::__new().Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0);
	}
	HX_STACK_LINE(20)
	this->matrix = matrix;
}
;
	return null();
}

//ColorMatrixFilter_obj::~ColorMatrixFilter_obj() { }

Dynamic ColorMatrixFilter_obj::__CreateEmpty() { return  new ColorMatrixFilter_obj; }
hx::ObjectPtr< ColorMatrixFilter_obj > ColorMatrixFilter_obj::__new(Array< Float > matrix)
{  hx::ObjectPtr< ColorMatrixFilter_obj > result = new ColorMatrixFilter_obj();
	result->__construct(matrix);
	return result;}

Dynamic ColorMatrixFilter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColorMatrixFilter_obj > result = new ColorMatrixFilter_obj();
	result->__construct(inArgs[0]);
	return result;}

::openfl::_v2::filters::BitmapFilter ColorMatrixFilter_obj::clone( ){
	HX_STACK_FRAME("openfl._v2.filters.ColorMatrixFilter","clone",0x3f1e4d47,"openfl._v2.filters.ColorMatrixFilter.clone","openfl/_v2/filters/ColorMatrixFilter.hx",27,0x85c284e9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(27)
	return ::openfl::_v2::filters::ColorMatrixFilter_obj::__new(this->matrix);
}



ColorMatrixFilter_obj::ColorMatrixFilter_obj()
{
}

void ColorMatrixFilter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColorMatrixFilter);
	HX_MARK_MEMBER_NAME(matrix,"matrix");
	::openfl::_v2::filters::BitmapFilter_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ColorMatrixFilter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(matrix,"matrix");
	::openfl::_v2::filters::BitmapFilter_obj::__Visit(HX_VISIT_ARG);
}

Dynamic ColorMatrixFilter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { return matrix; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColorMatrixFilter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"matrix") ) { matrix=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColorMatrixFilter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("matrix"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ColorMatrixFilter_obj,matrix),HX_CSTRING("matrix")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("matrix"),
	HX_CSTRING("clone"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColorMatrixFilter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColorMatrixFilter_obj::__mClass,"__mClass");
};

#endif

Class ColorMatrixFilter_obj::__mClass;

void ColorMatrixFilter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl._v2.filters.ColorMatrixFilter"), hx::TCanCast< ColorMatrixFilter_obj> ,sStaticFields,sMemberFields,
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

void ColorMatrixFilter_obj::__boot()
{
}

} // end namespace openfl
} // end namespace _v2
} // end namespace filters
