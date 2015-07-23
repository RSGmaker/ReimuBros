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
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
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

Void EntityItem_obj::__construct(::String ani)
{
HX_STACK_FRAME("EntityItem","new",0x57cea9e8,"EntityItem.new","EntityItem.hx",12,0x9b5f0a88)
HX_STACK_THIS(this)
HX_STACK_ARG(ani,"ani")
{
	HX_STACK_LINE(13)
	super::__construct(ani);
	HX_STACK_LINE(14)
	this->charname = ani;
	HX_STACK_LINE(15)
	this->touchable = true;
	HX_STACK_LINE(16)
	this->type = HX_CSTRING("Item");
	HX_STACK_LINE(17)
	this->deccel = 0.1;
	HX_STACK_LINE(18)
	this->Ldir = (int)1;
}
;
	return null();
}

//EntityItem_obj::~EntityItem_obj() { }

Dynamic EntityItem_obj::__CreateEmpty() { return  new EntityItem_obj; }
hx::ObjectPtr< EntityItem_obj > EntityItem_obj::__new(::String ani)
{  hx::ObjectPtr< EntityItem_obj > result = new EntityItem_obj();
	result->__construct(ani);
	return result;}

Dynamic EntityItem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EntityItem_obj > result = new EntityItem_obj();
	result->__construct(inArgs[0]);
	return result;}

Void EntityItem_obj::Collect( ::Player player){
{
		HX_STACK_FRAME("EntityItem","Collect",0x998c0b12,"EntityItem.Collect","EntityItem.hx",22,0x9b5f0a88)
		HX_STACK_THIS(this)
		HX_STACK_ARG(player,"player")
		HX_STACK_LINE(22)
		this->alive = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(EntityItem_obj,Collect,(void))

Void EntityItem_obj::update( ){
{
		HX_STACK_FRAME("EntityItem","update",0x60fd5181,"EntityItem.update","EntityItem.hx",25,0x9b5f0a88)
		HX_STACK_THIS(this)
		HX_STACK_LINE(26)
		if (((this->Hspeed > (int)0))){
			HX_STACK_LINE(28)
			this->Ldir = (int)1;
		}
		HX_STACK_LINE(30)
		if (((this->Hspeed < (int)0))){
			HX_STACK_LINE(32)
			this->Ldir = (int)-1;
		}
		HX_STACK_LINE(34)
		if (((this->Ldir == (int)1))){
			HX_STACK_LINE(36)
			this->Hspeed = (int)4;
		}
		HX_STACK_LINE(38)
		if (((this->Ldir == (int)-1))){
			HX_STACK_LINE(40)
			this->Hspeed = (int)-4;
		}
		HX_STACK_LINE(43)
		this->updphysics();
		HX_STACK_LINE(44)
		Float _g = this->get_y();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(44)
		if (((  (((_g > (int)408))) ? bool(this->wrapped) : bool(false) ))){
			HX_STACK_LINE(46)
			this->alive = false;
			HX_STACK_LINE(47)
			this->set_visible(false);
		}
		HX_STACK_LINE(49)
		if (((this->ground != null()))){
			HX_STACK_LINE(51)
			if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
				HX_STACK_LINE(53)
				if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
					HX_STACK_LINE(62)
					::GameView_obj::_this->SendEvent(HX_CSTRING("Collect"),this->UID);
				}
			}
		}
	}
return null();
}



EntityItem_obj::EntityItem_obj()
{
}

void EntityItem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EntityItem);
	HX_MARK_MEMBER_NAME(charname,"charname");
	::Entity_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void EntityItem_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(charname,"charname");
	::Entity_obj::__Visit(HX_VISIT_ARG);
}

Dynamic EntityItem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Collect") ) { return Collect_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"charname") ) { return charname; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EntityItem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"charname") ) { charname=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EntityItem_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("charname"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(EntityItem_obj,charname),HX_CSTRING("charname")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("charname"),
	HX_CSTRING("Collect"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EntityItem_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EntityItem_obj::__mClass,"__mClass");
};

#endif

Class EntityItem_obj::__mClass;

void EntityItem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("EntityItem"), hx::TCanCast< EntityItem_obj> ,sStaticFields,sMemberFields,
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

void EntityItem_obj::__boot()
{
}

