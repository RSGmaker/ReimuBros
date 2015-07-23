#ifndef INCLUDED_openfl_events_NetStatusEvent
#define INCLUDED_openfl_events_NetStatusEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/events/Event.h>
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS2(openfl,events,NetStatusEvent)
namespace openfl{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  NetStatusEvent_obj : public ::openfl::_v2::events::Event_obj{
	public:
		typedef ::openfl::_v2::events::Event_obj super;
		typedef NetStatusEvent_obj OBJ_;
		NetStatusEvent_obj();
		Void __construct(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,Dynamic info);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< NetStatusEvent_obj > __new(::String type,hx::Null< bool >  __o_bubbles,hx::Null< bool >  __o_cancelable,Dynamic info);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~NetStatusEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("NetStatusEvent"); }

		Dynamic info;
		static ::String NET_STATUS;
};

} // end namespace openfl
} // end namespace events

#endif /* INCLUDED_openfl_events_NetStatusEvent */ 
