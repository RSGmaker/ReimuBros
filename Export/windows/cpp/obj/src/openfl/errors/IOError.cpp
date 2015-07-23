#include <hxcpp.h>

#ifndef INCLUDED_openfl_errors_Error
#include <openfl/errors/Error.h>
#endif
#ifndef INCLUDED_openfl_errors_IOError
#include <openfl/errors/IOError.h>
#endif
namespace openfl{
namespace errors{

Void IOError_obj::__construct(::String __o_message)
{
HX_STACK_FRAME("openfl.errors.IOError","new",0xdfaba8cf,"openfl.errors.IOError.new","openfl/errors/IOError.hx",9,0x640bffa1)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_message,"message")
::String message = __o_message.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(9)
	super::__construct(message,null());
}
;
	return null();
}

//IOError_obj::~IOError_obj() { }

Dynamic IOError_obj::__CreateEmpty() { return  new IOError_obj; }
hx::ObjectPtr< IOError_obj > IOError_obj::__new(::String __o_message)
{  hx::ObjectPtr< IOError_obj > result = new IOError_obj();
	result->__construct(__o_message);
	return result;}

Dynamic IOError_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IOError_obj > result = new IOError_obj();
	result->__construct(inArgs[0]);
	return result;}


IOError_obj::IOError_obj()
{
}

Dynamic IOError_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic IOError_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void IOError_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(IOError_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IOError_obj::__mClass,"__mClass");
};

#endif

Class IOError_obj::__mClass;

void IOError_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.errors.IOError"), hx::TCanCast< IOError_obj> ,sStaticFields,sMemberFields,
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

void IOError_obj::__boot()
{
}

} // end namespace openfl
} // end namespace errors
