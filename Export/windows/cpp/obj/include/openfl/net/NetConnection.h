#ifndef INCLUDED_openfl_net_NetConnection
#define INCLUDED_openfl_net_NetConnection

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/events/EventDispatcher.h>
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,net,NetConnection)
namespace openfl{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  NetConnection_obj : public ::openfl::_v2::events::EventDispatcher_obj{
	public:
		typedef ::openfl::_v2::events::EventDispatcher_obj super;
		typedef NetConnection_obj OBJ_;
		NetConnection_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< NetConnection_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~NetConnection_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("NetConnection"); }

		virtual Void connect( ::String command,Dynamic _,Dynamic _1,Dynamic _2,Dynamic _3,Dynamic _4);
		Dynamic connect_dyn();

		static ::String CONNECT_SUCCESS;
};

} // end namespace openfl
} // end namespace net

#endif /* INCLUDED_openfl_net_NetConnection */ 
