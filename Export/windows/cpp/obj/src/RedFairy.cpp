#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Enemy
#include <Enemy.h>
#endif
#ifndef INCLUDED_Entity
#include <Entity.h>
#endif
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_RedFairy
#include <RedFairy.h>
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

Void RedFairy_obj::__construct()
{
HX_STACK_FRAME("RedFairy","new",0xcb7cde16,"RedFairy.new","RedFairy.hx",17,0xdf9ef61a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(19)
	super::__construct(HX_CSTRING("RedFairy"));
	HX_STACK_LINE(21)
	this->accel = 0.5;
	HX_STACK_LINE(22)
	this->deccel = 0.1;
	HX_STACK_LINE(23)
	this->mxspd = (int)4;
	HX_STACK_LINE(24)
	this->Ldir = (int)1;
	HX_STACK_LINE(25)
	this->killed = false;
	HX_STACK_LINE(26)
	this->flipped = (int)-1;
}
;
	return null();
}

//RedFairy_obj::~RedFairy_obj() { }

Dynamic RedFairy_obj::__CreateEmpty() { return  new RedFairy_obj; }
hx::ObjectPtr< RedFairy_obj > RedFairy_obj::__new()
{  hx::ObjectPtr< RedFairy_obj > result = new RedFairy_obj();
	result->__construct();
	return result;}

Dynamic RedFairy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RedFairy_obj > result = new RedFairy_obj();
	result->__construct();
	return result;}

Void RedFairy_obj::increaserank( ){
{
		HX_STACK_FRAME("RedFairy","increaserank",0xe8d21df8,"RedFairy.increaserank","RedFairy.hx",38,0xdf9ef61a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		hx::AddEq(this->accel,0.1);
		HX_STACK_LINE(40)
		hx::AddEq(this->mxspd,0.5);
		HX_STACK_LINE(41)
		hx::AddEq(this->pointvalue,(int)50);
	}
return null();
}


Void RedFairy_obj::update( ){
{
		HX_STACK_FRAME("RedFairy","update",0x6b8f6e13,"RedFairy.update","RedFairy.hx",44,0xdf9ef61a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(45)
		if ((!(this->started))){
			HX_STACK_LINE(55)
			this->started = true;
		}
		HX_STACK_LINE(60)
		if ((this->enraged)){
		}
		HX_STACK_LINE(65)
		if ((!(this->killed))){
			HX_STACK_LINE(67)
			int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(68)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(70)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(71)
				this->dangerous = false;
				HX_STACK_LINE(72)
				if (((this->flipped == (int)0))){
					HX_STACK_LINE(74)
					this->flipped = (int)-1;
					HX_STACK_LINE(75)
					this->powerup();
				}
			}
			else{
				HX_STACK_LINE(80)
				this->dangerous = true;
			}
			HX_STACK_LINE(82)
			if (((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(84)
				hx::AddEq(this->Hspeed,this->accel);
				HX_STACK_LINE(85)
				if (((this->Hspeed > this->mxspd))){
					HX_STACK_LINE(87)
					this->Hspeed = this->mxspd;
				}
			}
			HX_STACK_LINE(90)
			if (((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(92)
				hx::SubEq(this->Hspeed,this->accel);
				HX_STACK_LINE(93)
				if (((this->Hspeed < -(this->mxspd)))){
					HX_STACK_LINE(95)
					this->Hspeed = -(this->mxspd);
				}
			}
			HX_STACK_LINE(98)
			this->updphysics();
			HX_STACK_LINE(99)
			this->updateanimation(null());
			HX_STACK_LINE(101)
			if (((this->ground != null()))){
				HX_STACK_LINE(104)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(107)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","RedFairy.hx",111,0xdf9ef61a)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(111)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(112)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(113)
						Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(113)
						D->__FieldRef(HX_CSTRING("x")) = _g;
						HX_STACK_LINE(114)
						Float _g1 = this->get_y();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(114)
						D->__FieldRef(HX_CSTRING("y")) = _g1;
						HX_STACK_LINE(115)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(116)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(118)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(124)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(127)
						this->Vspeed = (int)-4;
					}
				}
			}
			HX_STACK_LINE(133)
			Float _g2 = this->get_y();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(133)
			if (((  (((_g2 > (int)408))) ? bool(this->wrapped) : bool(false) ))){
				HX_STACK_LINE(135)
				this->alive = false;
				HX_STACK_LINE(136)
				this->set_visible(false);
			}
			HX_STACK_LINE(138)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(142)
			{
				HX_STACK_LINE(142)
				::RedFairy _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(142)
				Float _g3 = _g->get_y();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(142)
				Float _g4 = (_g3 + (int)15);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(142)
				_g->set_y(_g4);
			}
			HX_STACK_LINE(143)
			Float _g5 = this->get_y();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(143)
			if (((_g5 > (int)600))){
				HX_STACK_LINE(145)
				this->alive = false;
			}
		}
	}
return null();
}


Void RedFairy_obj::bump( ){
{
		HX_STACK_FRAME("RedFairy","bump",0x39e30180,"RedFairy.bump","RedFairy.hx",152,0xdf9ef61a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(152)
		if (((this->flipped < (int)1))){
			HX_STACK_LINE(154)
			if ((this->enraged)){
				HX_STACK_LINE(156)
				this->flipped = (int)120;
			}
			else{
				HX_STACK_LINE(160)
				this->flipped = (int)210;
			}
		}
		else{
			HX_STACK_LINE(165)
			this->flipped = (int)0;
		}
	}
return null();
}



RedFairy_obj::RedFairy_obj()
{
}

Dynamic RedFairy_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"bump") ) { return bump_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { return accel; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { return mxspd; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"increaserank") ) { return increaserank_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RedFairy_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { accel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { mxspd=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RedFairy_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(RedFairy_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(RedFairy_obj,mxspd),HX_CSTRING("mxspd")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("increaserank"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RedFairy_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RedFairy_obj::__mClass,"__mClass");
};

#endif

Class RedFairy_obj::__mClass;

void RedFairy_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("RedFairy"), hx::TCanCast< RedFairy_obj> ,sStaticFields,sMemberFields,
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

void RedFairy_obj::__boot()
{
}

