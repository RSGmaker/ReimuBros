#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Entity
#include <Entity.h>
#endif
#ifndef INCLUDED_EntityGap
#include <EntityGap.h>
#endif
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_openfl__v2_media_SoundChannel
#include <openfl/_v2/media/SoundChannel.h>
#endif

Void EntityGap_obj::__construct()
{
HX_STACK_FRAME("EntityGap","new",0xdb60c005,"EntityGap.new","EntityGap.hx",13,0xd8cde70b)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(14)
	super::__construct(HX_CSTRING("Gap"));
	HX_STACK_LINE(15)
	this->type = HX_CSTRING("Gap");
	HX_STACK_LINE(16)
	this->deccel = 0.1;
	HX_STACK_LINE(17)
	this->frames = (int)0;
	HX_STACK_LINE(18)
	this->set_scaleY((int)0);
	HX_STACK_LINE(19)
	this->SY = 0.01666666666666666666666666666667;
}
;
	return null();
}

//EntityGap_obj::~EntityGap_obj() { }

Dynamic EntityGap_obj::__CreateEmpty() { return  new EntityGap_obj; }
hx::ObjectPtr< EntityGap_obj > EntityGap_obj::__new()
{  hx::ObjectPtr< EntityGap_obj > result = new EntityGap_obj();
	result->__construct();
	return result;}

Dynamic EntityGap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EntityGap_obj > result = new EntityGap_obj();
	result->__construct();
	return result;}

Void EntityGap_obj::update( ){
{
		HX_STACK_FRAME("EntityGap","update",0x82882b84,"EntityGap.update","EntityGap.hx",22,0xd8cde70b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(23)
		this->Ldir = (int)1;
		HX_STACK_LINE(24)
		Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(24)
		if (((_g > (int)400))){
			HX_STACK_LINE(26)
			this->Ldir = (int)-1;
		}
		HX_STACK_LINE(28)
		if (((this->frames < (int)60))){
			HX_STACK_LINE(31)
			::EntityGap _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(31)
			Float _g11 = _g1->get_scaleY();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(31)
			Float _g2 = (_g11 + this->SY);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(31)
			_g1->set_scaleY(_g2);
		}
		HX_STACK_LINE(33)
		if (((this->frames == (int)150))){
			HX_STACK_LINE(35)
			::SoundManager_obj::Play(HX_CSTRING("fireballspawn"));
			HX_STACK_LINE(36)
			if ((::GameView_obj::_this->Hoster)){
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","EntityGap.hx",44,0xd8cde70b)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(44)
				Dynamic D = _Function_3_1::Block();		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(45)
				D->__FieldRef(HX_CSTRING("type")) = HX_CSTRING("Chen");
				HX_STACK_LINE(46)
				Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(46)
				D->__FieldRef(HX_CSTRING("UID")) = _g3;
				HX_STACK_LINE(47)
				Float _g4 = this->get_y();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(47)
				Float _g5 = (_g4 + (int)32);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(47)
				D->__FieldRef(HX_CSTRING("y")) = _g5;
				HX_STACK_LINE(48)
				Float _g6 = this->get_x();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(48)
				D->__FieldRef(HX_CSTRING("x")) = _g6;
				HX_STACK_LINE(49)
				D->__FieldRef(HX_CSTRING("Ldir")) = this->Ldir;
				HX_STACK_LINE(50)
				D->__FieldRef(HX_CSTRING("alive")) = true;
				HX_STACK_LINE(51)
				D->__FieldRef(HX_CSTRING("Hspeed")) = (int)0;
				HX_STACK_LINE(52)
				D->__FieldRef(HX_CSTRING("Vspeed")) = (int)0;
				HX_STACK_LINE(53)
				D->__FieldRef(HX_CSTRING("enraged")) = false;
				HX_STACK_LINE(54)
				D->__FieldRef(HX_CSTRING("visible")) = true;
				HX_STACK_LINE(55)
				::GameView_obj::_this->SendEvent(HX_CSTRING("SpawnEnemy"),D);
			}
		}
		HX_STACK_LINE(58)
		if (((this->frames > (int)180))){
			HX_STACK_LINE(61)
			{
				HX_STACK_LINE(61)
				::EntityGap _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(61)
				Float _g7 = _g1->get_scaleY();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(61)
				Float _g8 = (_g7 - ((this->SY + this->SY)));		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(61)
				_g1->set_scaleY(_g8);
			}
			HX_STACK_LINE(62)
			Float _g9 = this->get_scaleY();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(62)
			if (((_g9 <= (int)0))){
				HX_STACK_LINE(64)
				this->alive = false;
			}
		}
		HX_STACK_LINE(67)
		hx::AddEq(this->frames,(int)1);
	}
return null();
}



EntityGap_obj::EntityGap_obj()
{
}

Dynamic EntityGap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"SY") ) { return SY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EntityGap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"SY") ) { SY=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EntityGap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("SY"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(EntityGap_obj,frames),HX_CSTRING("frames")},
	{hx::fsFloat,(int)offsetof(EntityGap_obj,SY),HX_CSTRING("SY")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("frames"),
	HX_CSTRING("SY"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EntityGap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EntityGap_obj::__mClass,"__mClass");
};

#endif

Class EntityGap_obj::__mClass;

void EntityGap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("EntityGap"), hx::TCanCast< EntityGap_obj> ,sStaticFields,sMemberFields,
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

void EntityGap_obj::__boot()
{
}

