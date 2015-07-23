#include <hxcpp.h>

#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_NetStatusEvent
#include <openfl/events/NetStatusEvent.h>
#endif
#ifndef INCLUDED_openfl_net_NetConnection
#include <openfl/net/NetConnection.h>
#endif
namespace openfl{
namespace net{

Void NetConnection_obj::__construct()
{
HX_STACK_FRAME("openfl.net.NetConnection","new",0x5c5dd97e,"openfl.net.NetConnection.new","openfl/net/NetConnection.hx",16,0x3b599834)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(16)
	super::__construct(null());
}
;
	return null();
}

//NetConnection_obj::~NetConnection_obj() { }

Dynamic NetConnection_obj::__CreateEmpty() { return  new NetConnection_obj; }
hx::ObjectPtr< NetConnection_obj > NetConnection_obj::__new()
{  hx::ObjectPtr< NetConnection_obj > result = new NetConnection_obj();
	result->__construct();
	return result;}

Dynamic NetConnection_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NetConnection_obj > result = new NetConnection_obj();
	result->__construct();
	return result;}

Void NetConnection_obj::connect( ::String command,Dynamic _,Dynamic _1,Dynamic _2,Dynamic _3,Dynamic _4){
{
		HX_STACK_FRAME("openfl.net.NetConnection","connect",0x1fc82c08,"openfl.net.NetConnection.connect","openfl/net/NetConnection.hx",21,0x3b599834)
		HX_STACK_THIS(this)
		HX_STACK_ARG(command,"command")
		HX_STACK_ARG(_,"_")
		HX_STACK_ARG(_1,"_1")
		HX_STACK_ARG(_2,"_2")
		HX_STACK_ARG(_3,"_3")
		HX_STACK_ARG(_4,"_4")
		HX_STACK_LINE(23)
		if (((command != null()))){
			HX_STACK_LINE(25)
			HX_STACK_DO_THROW(HX_CSTRING("Error: Can only connect in \"HTTP streaming\" mode"));
		}
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","openfl/net/NetConnection.hx",29,0x3b599834)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("code") , HX_CSTRING("connectSuccess"),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(29)
		::openfl::events::NetStatusEvent _g = ::openfl::events::NetStatusEvent_obj::__new(::openfl::events::NetStatusEvent_obj::NET_STATUS,false,true,_Function_1_1::Block());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		this->dispatchEvent(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(NetConnection_obj,connect,(void))

::String NetConnection_obj::CONNECT_SUCCESS;


NetConnection_obj::NetConnection_obj()
{
}

Dynamic NetConnection_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"connect") ) { return connect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NetConnection_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NetConnection_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CONNECT_SUCCESS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("connect"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NetConnection_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(NetConnection_obj::CONNECT_SUCCESS,"CONNECT_SUCCESS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NetConnection_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(NetConnection_obj::CONNECT_SUCCESS,"CONNECT_SUCCESS");
};

#endif

Class NetConnection_obj::__mClass;

void NetConnection_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.net.NetConnection"), hx::TCanCast< NetConnection_obj> ,sStaticFields,sMemberFields,
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

void NetConnection_obj::__boot()
{
	CONNECT_SUCCESS= HX_CSTRING("connectSuccess");
}

} // end namespace openfl
} // end namespace net
