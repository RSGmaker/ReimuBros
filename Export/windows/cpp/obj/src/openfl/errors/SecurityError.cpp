#include <hxcpp.h>

#ifndef INCLUDED_openfl_errors_Error
#include <openfl/errors/Error.h>
#endif
#ifndef INCLUDED_openfl_errors_SecurityError
#include <openfl/errors/SecurityError.h>
#endif
namespace openfl{
namespace errors{

Void SecurityError_obj::__construct(::String __o_inMessage)
{
HX_STACK_FRAME("openfl.errors.SecurityError","new",0x60f5f8d5,"openfl.errors.SecurityError.new","openfl/errors/SecurityError.hx",9,0x04006a5b)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_inMessage,"inMessage")
::String inMessage = __o_inMessage.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(9)
	super::__construct(inMessage,(int)0);
}
;
	return null();
}

//SecurityError_obj::~SecurityError_obj() { }

Dynamic SecurityError_obj::__CreateEmpty() { return  new SecurityError_obj; }
hx::ObjectPtr< SecurityError_obj > SecurityError_obj::__new(::String __o_inMessage)
{  hx::ObjectPtr< SecurityError_obj > result = new SecurityError_obj();
	result->__construct(__o_inMessage);
	return result;}

Dynamic SecurityError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SecurityError_obj > result = new SecurityError_obj();
	result->__construct(inArgs[0]);
	return result;}


SecurityError_obj::SecurityError_obj()
{
}

Dynamic SecurityError_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic SecurityError_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void SecurityError_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SecurityError_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SecurityError_obj::__mClass,"__mClass");
};

#endif

Class SecurityError_obj::__mClass;

void SecurityError_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.errors.SecurityError"), hx::TCanCast< SecurityError_obj> ,sStaticFields,sMemberFields,
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

void SecurityError_obj::__boot()
{
}

} // end namespace openfl
} // end namespace errors
