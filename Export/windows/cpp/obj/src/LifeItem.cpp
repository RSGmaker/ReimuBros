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
#ifndef INCLUDED_LifeItem
#include <LifeItem.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
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

Void LifeItem_obj::__construct()
{
HX_STACK_FRAME("LifeItem","new",0xa18960c1,"LifeItem.new","LifeItem.hx",12,0x6a56b1cf)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(12)
	super::__construct(HX_CSTRING("1up"));
}
;
	return null();
}

//LifeItem_obj::~LifeItem_obj() { }

Dynamic LifeItem_obj::__CreateEmpty() { return  new LifeItem_obj; }
hx::ObjectPtr< LifeItem_obj > LifeItem_obj::__new()
{  hx::ObjectPtr< LifeItem_obj > result = new LifeItem_obj();
	result->__construct();
	return result;}

Dynamic LifeItem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LifeItem_obj > result = new LifeItem_obj();
	result->__construct();
	return result;}

Void LifeItem_obj::Collect( ::Player player){
{
		HX_STACK_FRAME("LifeItem","Collect",0x27cda26b,"LifeItem.Collect","LifeItem.hx",15,0x6a56b1cf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(player,"player")
		HX_STACK_LINE(16)
		this->alive = false;
		HX_STACK_LINE(17)
		(player->lives)++;
		HX_STACK_LINE(18)
		::SoundManager_obj::Play(HX_CSTRING("collectcoin"));
	}
return null();
}



LifeItem_obj::LifeItem_obj()
{
}

Dynamic LifeItem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"Collect") ) { return Collect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LifeItem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void LifeItem_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(LifeItem_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LifeItem_obj::__mClass,"__mClass");
};

#endif

Class LifeItem_obj::__mClass;

void LifeItem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("LifeItem"), hx::TCanCast< LifeItem_obj> ,sStaticFields,sMemberFields,
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

void LifeItem_obj::__boot()
{
}

