#include <hxcpp.h>

#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_NetStatusEvent
#include <openfl/events/NetStatusEvent.h>
#endif
namespace openfl{
namespace events{

Void NetStatusEvent_obj::__construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,Dynamic info)
{
HX_STACK_FRAME("openfl.events.NetStatusEvent","new",0x7499fa94,"openfl.events.NetStatusEvent.new","openfl/events/NetStatusEvent.hx",12,0xf85a9d3c)
HX_STACK_THIS(this)
HX_STACK_ARG(type,"type")
HX_STACK_ARG(__o_bubbles,"bubbles")
HX_STACK_ARG(__o_cancelable,"cancelable")
HX_STACK_ARG(info,"info")
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
{
	HX_STACK_LINE(14)
	this->info = info;
	HX_STACK_LINE(16)
	super::__construct(type,bubbles,cancelable);
}
;
	return null();
}

//NetStatusEvent_obj::~NetStatusEvent_obj() { }

Dynamic NetStatusEvent_obj::__CreateEmpty() { return  new NetStatusEvent_obj; }
hx::ObjectPtr< NetStatusEvent_obj > NetStatusEvent_obj::__new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,Dynamic info)
{  hx::ObjectPtr< NetStatusEvent_obj > result = new NetStatusEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,info);
	return result;}

Dynamic NetStatusEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NetStatusEvent_obj > result = new NetStatusEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::String NetStatusEvent_obj::NET_STATUS;


NetStatusEvent_obj::NetStatusEvent_obj()
{
}

void NetStatusEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NetStatusEvent);
	HX_MARK_MEMBER_NAME(info,"info");
	::openfl::_v2::events::Event_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NetStatusEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(info,"info");
	::openfl::_v2::events::Event_obj::__Visit(HX_VISIT_ARG);
}

Dynamic NetStatusEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"info") ) { return info; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"NET_STATUS") ) { return NET_STATUS; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NetStatusEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"info") ) { info=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"NET_STATUS") ) { NET_STATUS=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void NetStatusEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("info"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NET_STATUS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(NetStatusEvent_obj,info),HX_CSTRING("info")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("info"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NetStatusEvent_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(NetStatusEvent_obj::NET_STATUS,"NET_STATUS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NetStatusEvent_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(NetStatusEvent_obj::NET_STATUS,"NET_STATUS");
};

#endif

Class NetStatusEvent_obj::__mClass;

void NetStatusEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.events.NetStatusEvent"), hx::TCanCast< NetStatusEvent_obj> ,sStaticFields,sMemberFields,
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

void NetStatusEvent_obj::__boot()
{
	NET_STATUS= HX_CSTRING("netStatus");
}

} // end namespace openfl
} // end namespace events
