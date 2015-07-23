#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Animationloader
#include <Animationloader.h>
#endif
#ifndef INCLUDED_Bullet
#include <Bullet.h>
#endif
#ifndef INCLUDED_Entity
#include <Entity.h>
#endif
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_TypeofRound
#include <TypeofRound.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
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

Void Bullet_obj::__construct()
{
HX_STACK_FRAME("Bullet","new",0xf3208054,"Bullet.new","Bullet.hx",7,0xb42ce59c)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(11)
	this->gravY = (int)0;
	HX_STACK_LINE(10)
	this->gravX = (int)0;
	HX_STACK_LINE(15)
	super::__construct(HX_CSTRING("bullet"));
	HX_STACK_LINE(17)
	this->dangerous = true;
	HX_STACK_LINE(18)
	this->type = HX_CSTRING("Bullet");
	HX_STACK_LINE(20)
	this->UID = (int)-1;
}
;
	return null();
}

//Bullet_obj::~Bullet_obj() { }

Dynamic Bullet_obj::__CreateEmpty() { return  new Bullet_obj; }
hx::ObjectPtr< Bullet_obj > Bullet_obj::__new()
{  hx::ObjectPtr< Bullet_obj > result = new Bullet_obj();
	result->__construct();
	return result;}

Dynamic Bullet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bullet_obj > result = new Bullet_obj();
	result->__construct();
	return result;}

Void Bullet_obj::update( ){
{
		HX_STACK_FRAME("Bullet","update",0xa9584695,"Bullet.update","Bullet.hx",24,0xb42ce59c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(26)
		if ((!(this->started))){
			HX_STACK_LINE(28)
			if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Table))){
				HX_STACK_LINE(30)
				Array< ::Dynamic > _g = ::GameView_obj::_this->AL->GetAnimation(HX_CSTRING("table"));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(30)
				this->ChangeAnimation(_g);
				HX_STACK_LINE(31)
				this->image_speed = 0.5;
			}
			HX_STACK_LINE(33)
			this->started = true;
		}
		HX_STACK_LINE(35)
		hx::AddEq(this->Hspeed,this->gravX);
		HX_STACK_LINE(36)
		hx::AddEq(this->Vspeed,this->gravY);
		HX_STACK_LINE(37)
		this->animate();
		HX_STACK_LINE(38)
		{
			HX_STACK_LINE(38)
			::Bullet _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(38)
			Float _g1 = _g->get_x();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(38)
			Float _g2 = (_g1 + this->Hspeed);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(38)
			_g->set_x(_g2);
		}
		HX_STACK_LINE(39)
		{
			HX_STACK_LINE(39)
			::Bullet _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(39)
			Float _g3 = _g->get_y();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(39)
			Float _g4 = (_g3 + this->Vspeed);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(39)
			_g->set_y(_g4);
		}
		HX_STACK_LINE(41)
		bool ok = true;		HX_STACK_VAR(ok,"ok");
		HX_STACK_LINE(42)
		Float _g5 = this->get_x();		HX_STACK_VAR(_g5,"_g5");
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::Bullet_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Bullet.hx",42,0xb42ce59c)
				{
					HX_STACK_LINE(42)
					Float _g6 = __this->get_y();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(42)
					return (  (((_g6 < (int)-32))) ? bool((__this->gravY <= (int)0)) : bool(false) );
				}
				return null();
			}
		};
		struct _Function_1_2{
			inline static bool Block( hx::ObjectPtr< ::Bullet_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Bullet.hx",42,0xb42ce59c)
				{
					HX_STACK_LINE(42)
					Float _g7 = __this->get_x();		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(42)
					return (  (((_g7 > (int)832))) ? bool((__this->gravX >= (int)0)) : bool(false) );
				}
				return null();
			}
		};
		struct _Function_1_3{
			inline static bool Block( hx::ObjectPtr< ::Bullet_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Bullet.hx",42,0xb42ce59c)
				{
					HX_STACK_LINE(42)
					Float _g8 = __this->get_y();		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(42)
					return (  (((_g8 > (int)832))) ? bool((__this->gravY >= (int)0)) : bool(false) );
				}
				return null();
			}
		};
		HX_STACK_LINE(42)
		if (((  ((!(((  ((!(((  ((!(((  (((_g5 < (int)-32))) ? bool((this->gravX <= (int)0)) : bool(false) ))))) ? bool(_Function_1_1::Block(this)) : bool(true) ))))) ? bool(_Function_1_2::Block(this)) : bool(true) ))))) ? bool(_Function_1_3::Block(this)) : bool(true) ))){
			HX_STACK_LINE(44)
			this->alive = false;
			HX_STACK_LINE(45)
			this->killed = true;
		}
	}
return null();
}



Bullet_obj::Bullet_obj()
{
}

Dynamic Bullet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"gravX") ) { return gravX; }
		if (HX_FIELD_EQ(inName,"gravY") ) { return gravY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"started") ) { return started; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bullet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"gravX") ) { gravX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gravY") ) { gravY=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"started") ) { started=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bullet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gravX"));
	outFields->push(HX_CSTRING("gravY"));
	outFields->push(HX_CSTRING("started"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Bullet_obj,gravX),HX_CSTRING("gravX")},
	{hx::fsFloat,(int)offsetof(Bullet_obj,gravY),HX_CSTRING("gravY")},
	{hx::fsBool,(int)offsetof(Bullet_obj,started),HX_CSTRING("started")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("gravX"),
	HX_CSTRING("gravY"),
	HX_CSTRING("started"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bullet_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bullet_obj::__mClass,"__mClass");
};

#endif

Class Bullet_obj::__mClass;

void Bullet_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Bullet"), hx::TCanCast< Bullet_obj> ,sStaticFields,sMemberFields,
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

void Bullet_obj::__boot()
{
}

