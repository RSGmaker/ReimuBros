#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Entity
#include <Entity.h>
#endif
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_PowBlock
#include <PowBlock.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif

Void PowBlock_obj::__construct(::String ani)
{
HX_STACK_FRAME("PowBlock","new",0xaa249c27,"PowBlock.new","PowBlock.hx",11,0xa7386529)
HX_STACK_THIS(this)
HX_STACK_ARG(ani,"ani")
{
	HX_STACK_LINE(12)
	super::__construct(ani);
	HX_STACK_LINE(17)
	this->solid = true;
	HX_STACK_LINE(18)
	this->type = HX_CSTRING("PowBlock");
	HX_STACK_LINE(19)
	this->HP = (int)4;
	HX_STACK_LINE(20)
	this->bonked = (int)-1000;
	HX_STACK_LINE(21)
	this->UID = ((int)-100 - ::GameView_obj::_this->entities->length);
}
;
	return null();
}

//PowBlock_obj::~PowBlock_obj() { }

Dynamic PowBlock_obj::__CreateEmpty() { return  new PowBlock_obj; }
hx::ObjectPtr< PowBlock_obj > PowBlock_obj::__new(::String ani)
{  hx::ObjectPtr< PowBlock_obj > result = new PowBlock_obj();
	result->__construct(ani);
	return result;}

Dynamic PowBlock_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PowBlock_obj > result = new PowBlock_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PowBlock_obj::update( ){
{
		HX_STACK_FRAME("PowBlock","update",0x910f10a2,"PowBlock.update","PowBlock.hx",41,0xa7386529)
		HX_STACK_THIS(this)
		HX_STACK_LINE(41)
		this->bonked = (int)-1000;
	}
return null();
}



PowBlock_obj::PowBlock_obj()
{
}

Dynamic PowBlock_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"HP") ) { return HP; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PowBlock_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"HP") ) { HP=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PowBlock_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("HP"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(PowBlock_obj,HP),HX_CSTRING("HP")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("HP"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PowBlock_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PowBlock_obj::__mClass,"__mClass");
};

#endif

Class PowBlock_obj::__mClass;

void PowBlock_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PowBlock"), hx::TCanCast< PowBlock_obj> ,sStaticFields,sMemberFields,
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

void PowBlock_obj::__boot()
{
}

