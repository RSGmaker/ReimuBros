#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Entity
#include <Entity.h>
#endif
#ifndef INCLUDED_EntityItem
#include <EntityItem.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_PointItem
#include <PointItem.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_media_SoundChannel
#include <openfl/_v2/media/SoundChannel.h>
#endif

Void PointItem_obj::__construct()
{
HX_STACK_FRAME("PointItem","new",0xc9557bd5,"PointItem.new","PointItem.hx",12,0x8611953b)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(12)
	super::__construct(HX_CSTRING("Point"));
}
;
	return null();
}

//PointItem_obj::~PointItem_obj() { }

Dynamic PointItem_obj::__CreateEmpty() { return  new PointItem_obj; }
hx::ObjectPtr< PointItem_obj > PointItem_obj::__new()
{  hx::ObjectPtr< PointItem_obj > result = new PointItem_obj();
	result->__construct();
	return result;}

Dynamic PointItem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PointItem_obj > result = new PointItem_obj();
	result->__construct();
	return result;}

Void PointItem_obj::Collect( ::Player player){
{
		HX_STACK_FRAME("PointItem","Collect",0x7b46d77f,"PointItem.Collect","PointItem.hx",15,0x8611953b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(player,"player")
		HX_STACK_LINE(16)
		this->alive = false;
		HX_STACK_LINE(17)
		hx::AddEq(player->score,(int)300);
		HX_STACK_LINE(18)
		::SoundManager_obj::Play(HX_CSTRING("collectcoin"));
	}
return null();
}



PointItem_obj::PointItem_obj()
{
}

Dynamic PointItem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"Collect") ) { return Collect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PointItem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void PointItem_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Collect"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PointItem_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PointItem_obj::__mClass,"__mClass");
};

#endif

Class PointItem_obj::__mClass;

void PointItem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PointItem"), hx::TCanCast< PointItem_obj> ,sStaticFields,sMemberFields,
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

void PointItem_obj::__boot()
{
}

