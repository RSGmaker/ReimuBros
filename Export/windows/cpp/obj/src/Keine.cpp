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
#ifndef INCLUDED_Keine
#include <Keine.h>
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

Void Keine_obj::__construct()
{
HX_STACK_FRAME("Keine","new",0xad646758,"Keine.new","Keine.hx",15,0xbe31cb18)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(16)
	super::__construct(HX_CSTRING("Keine"));
	HX_STACK_LINE(17)
	this->accel = 0.3;
	HX_STACK_LINE(18)
	this->deccel = 0.1;
	HX_STACK_LINE(19)
	this->mxspd = (int)3;
	HX_STACK_LINE(20)
	this->Ldir = (int)1;
	HX_STACK_LINE(21)
	this->killed = false;
	HX_STACK_LINE(22)
	this->flipped = (int)-1;
	HX_STACK_LINE(23)
	this->ex = false;
	HX_STACK_LINE(24)
	this->pointvalue = (int)300;
}
;
	return null();
}

//Keine_obj::~Keine_obj() { }

Dynamic Keine_obj::__CreateEmpty() { return  new Keine_obj; }
hx::ObjectPtr< Keine_obj > Keine_obj::__new()
{  hx::ObjectPtr< Keine_obj > result = new Keine_obj();
	result->__construct();
	return result;}

Dynamic Keine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Keine_obj > result = new Keine_obj();
	result->__construct();
	return result;}

Void Keine_obj::increaserank( ){
{
		HX_STACK_FRAME("Keine","increaserank",0x7f645c76,"Keine.increaserank","Keine.hx",33,0xbe31cb18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(34)
		hx::AddEq(this->accel,0.05);
		HX_STACK_LINE(35)
		hx::AddEq(this->mxspd,1.5);
		HX_STACK_LINE(36)
		hx::AddEq(this->pointvalue,(int)150);
	}
return null();
}


Void Keine_obj::update( ){
{
		HX_STACK_FRAME("Keine","update",0x2de39a11,"Keine.update","Keine.hx",39,0xbe31cb18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(41)
		if ((!(this->started))){
			HX_STACK_LINE(51)
			this->started = true;
		}
		HX_STACK_LINE(53)
		Float MXS = this->mxspd;		HX_STACK_VAR(MXS,"MXS");
		HX_STACK_LINE(54)
		Float acl = this->accel;		HX_STACK_VAR(acl,"acl");
		HX_STACK_LINE(55)
		int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
		HX_STACK_LINE(57)
		this->charname = HX_CSTRING("Keine");
		HX_STACK_LINE(61)
		if ((this->ex)){
			HX_STACK_LINE(63)
			hx::AddEq(MXS,(int)4);
			HX_STACK_LINE(64)
			hx::AddEq(acl,0.1);
			HX_STACK_LINE(65)
			this->charname = (this->charname + HX_CSTRING("ex"));
		}
		HX_STACK_LINE(73)
		if ((!(this->killed))){
			HX_STACK_LINE(76)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(78)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(79)
				this->dangerous = false;
			}
			else{
				HX_STACK_LINE(83)
				this->dangerous = true;
				HX_STACK_LINE(84)
				if (((this->flipped == (int)0))){
					HX_STACK_LINE(86)
					this->flipped = (int)-1;
					HX_STACK_LINE(87)
					this->ex = false;
					HX_STACK_LINE(88)
					this->powerup();
				}
			}
			HX_STACK_LINE(92)
			if (((bool((bool((this->Hspeed < MXS)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(94)
				hx::AddEq(this->Hspeed,acl);
				HX_STACK_LINE(95)
				if (((this->Hspeed > MXS))){
					HX_STACK_LINE(97)
					this->Hspeed = MXS;
				}
			}
			HX_STACK_LINE(100)
			if (((bool((bool((this->Hspeed > -(MXS))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(102)
				hx::SubEq(this->Hspeed,acl);
				HX_STACK_LINE(103)
				if (((this->Hspeed < -(MXS)))){
					HX_STACK_LINE(105)
					this->Hspeed = -(MXS);
				}
			}
			HX_STACK_LINE(108)
			this->updphysics();
			HX_STACK_LINE(109)
			this->updateanimation((HX_CSTRING("E") + this->charname));
			HX_STACK_LINE(111)
			if (((this->ground != null()))){
				HX_STACK_LINE(114)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(117)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Keine.hx",121,0xbe31cb18)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(121)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(122)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(123)
						Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(123)
						D->__FieldRef(HX_CSTRING("x")) = _g;
						HX_STACK_LINE(124)
						Float _g1 = this->get_y();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(124)
						D->__FieldRef(HX_CSTRING("y")) = _g1;
						HX_STACK_LINE(125)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(126)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(128)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(134)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(137)
						this->Vspeed = (int)-4;
					}
				}
			}
			HX_STACK_LINE(143)
			Float _g2 = this->get_y();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(143)
			if (((  (((_g2 > (int)408))) ? bool(this->wrapped) : bool(false) ))){
				HX_STACK_LINE(145)
				this->alive = false;
				HX_STACK_LINE(146)
				this->set_visible(false);
			}
			HX_STACK_LINE(148)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(152)
			{
				HX_STACK_LINE(152)
				::Keine _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(152)
				Float _g3 = _g->get_y();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(152)
				Float _g4 = (_g3 + (int)15);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(152)
				_g->set_y(_g4);
			}
			HX_STACK_LINE(153)
			Float _g5 = this->get_y();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(153)
			if (((_g5 > (int)600))){
				HX_STACK_LINE(155)
				this->alive = false;
			}
		}
		HX_STACK_LINE(158)
		this->Ldir = dir;
	}
return null();
}


Void Keine_obj::bump( ){
{
		HX_STACK_FRAME("Keine","bump",0x029391fe,"Keine.bump","Keine.hx",161,0xbe31cb18)
		HX_STACK_THIS(this)
		HX_STACK_LINE(164)
		this->Hspeed = (this->accel * -(this->Ldir));
		HX_STACK_LINE(165)
		if (((this->flipped < (int)1))){
			HX_STACK_LINE(167)
			if ((!(this->ex))){
				HX_STACK_LINE(169)
				this->ex = true;
			}
			else{
				HX_STACK_LINE(173)
				if ((this->enraged)){
					HX_STACK_LINE(175)
					this->flipped = (int)150;
				}
				else{
					HX_STACK_LINE(179)
					this->flipped = (int)240;
				}
			}
		}
		else{
			HX_STACK_LINE(185)
			this->flipped = (int)-1;
		}
	}
return null();
}



Keine_obj::Keine_obj()
{
}

Dynamic Keine_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ex") ) { return ex; }
		break;
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

Dynamic Keine_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ex") ) { ex=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { accel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { mxspd=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Keine_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("ex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Keine_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Keine_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsBool,(int)offsetof(Keine_obj,ex),HX_CSTRING("ex")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("ex"),
	HX_CSTRING("increaserank"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Keine_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Keine_obj::__mClass,"__mClass");
};

#endif

Class Keine_obj::__mClass;

void Keine_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Keine"), hx::TCanCast< Keine_obj> ,sStaticFields,sMemberFields,
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

void Keine_obj::__boot()
{
}

