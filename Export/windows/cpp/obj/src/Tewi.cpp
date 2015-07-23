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
#ifndef INCLUDED_MersenneTwister
#include <MersenneTwister.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Tewi
#include <Tewi.h>
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

Void Tewi_obj::__construct()
{
HX_STACK_FRAME("Tewi","new",0x54cbc655,"Tewi.new","Tewi.hx",21,0xd1501abb)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(23)
	super::__construct(HX_CSTRING("tewi"));
	HX_STACK_LINE(25)
	this->accel = 0.4;
	HX_STACK_LINE(26)
	this->deccel = 0.1;
	HX_STACK_LINE(27)
	this->mxspd = (int)4;
	HX_STACK_LINE(28)
	this->Ldir = (int)1;
	HX_STACK_LINE(29)
	this->killed = false;
	HX_STACK_LINE(30)
	this->flipped = (int)-1;
	HX_STACK_LINE(31)
	this->set_scaleX(0.7);
	HX_STACK_LINE(32)
	this->set_scaleY(0.7);
	HX_STACK_LINE(33)
	this->pointvalue = (int)200;
	HX_STACK_LINE(34)
	this->mntime = (int)0;
}
;
	return null();
}

//Tewi_obj::~Tewi_obj() { }

Dynamic Tewi_obj::__CreateEmpty() { return  new Tewi_obj; }
hx::ObjectPtr< Tewi_obj > Tewi_obj::__new()
{  hx::ObjectPtr< Tewi_obj > result = new Tewi_obj();
	result->__construct();
	return result;}

Dynamic Tewi_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Tewi_obj > result = new Tewi_obj();
	result->__construct();
	return result;}

Void Tewi_obj::increaserank( ){
{
		HX_STACK_FRAME("Tewi","increaserank",0x94b9b5d9,"Tewi.increaserank","Tewi.hx",46,0xd1501abb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(47)
		hx::AddEq(this->accel,0.1);
		HX_STACK_LINE(48)
		hx::AddEq(this->mxspd,0.5);
		HX_STACK_LINE(49)
		hx::AddEq(this->pointvalue,(int)100);
		HX_STACK_LINE(50)
		hx::AddEq(this->mntime,(int)30);
	}
return null();
}


Void Tewi_obj::update( ){
{
		HX_STACK_FRAME("Tewi","update",0xaa25f734,"Tewi.update","Tewi.hx",53,0xd1501abb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(55)
		if ((!(this->started))){
			HX_STACK_LINE(65)
			this->started = true;
		}
		HX_STACK_LINE(67)
		if (((this->rng == null()))){
			HX_STACK_LINE(69)
			::MersenneTwister _g = ::MersenneTwister_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(69)
			this->rng = _g;
			HX_STACK_LINE(70)
			int seed = ::Math_obj::floor((this->UID * (int)100000));		HX_STACK_VAR(seed,"seed");
			HX_STACK_LINE(71)
			Array< int > _g1 = this->rng->twist(seed,(int)1,(int)210);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(71)
			int _g2 = _g1->__get((int)0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(71)
			int _g3 = ((int)45 + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(71)
			this->timer = _g3;
			HX_STACK_LINE(72)
			hx::SubEq(this->timer,this->mntime);
		}
		HX_STACK_LINE(77)
		if (((bool(::GameView_obj::_this->Hoster) && bool((this->flipped <= (int)0))))){
			HX_STACK_LINE(79)
			if (((this->timer > (int)0))){
				HX_STACK_LINE(81)
				(this->timer)--;
			}
			else{
				HX_STACK_LINE(85)
				Array< int > _g4 = this->rng->twist(this->rng->seed,(int)1,(int)210);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(85)
				int _g5 = _g4->__get((int)0);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(85)
				int _g6 = ((int)45 + _g5);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(85)
				this->timer = _g6;
				HX_STACK_LINE(86)
				hx::SubEq(this->timer,this->mntime);
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Tewi.hx",87,0xd1501abb)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(87)
				Dynamic D = _Function_3_1::Block();		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(88)
				D->__FieldRef(HX_CSTRING("UID")) = this->UID;
				HX_STACK_LINE(89)
				::GameView_obj::_this->SendEvent(HX_CSTRING("Hammerthrow"),D);
			}
		}
		HX_STACK_LINE(92)
		if ((this->enraged)){
		}
		HX_STACK_LINE(97)
		if ((!(this->killed))){
			HX_STACK_LINE(99)
			int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(100)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(102)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(103)
				this->dangerous = false;
				HX_STACK_LINE(104)
				if (((this->flipped == (int)0))){
					HX_STACK_LINE(106)
					this->flipped = (int)-1;
					HX_STACK_LINE(107)
					this->powerup();
				}
			}
			else{
				HX_STACK_LINE(112)
				this->dangerous = true;
			}
			HX_STACK_LINE(114)
			if (((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(116)
				hx::AddEq(this->Hspeed,this->accel);
				HX_STACK_LINE(117)
				if (((this->Hspeed > this->mxspd))){
					HX_STACK_LINE(119)
					this->Hspeed = this->mxspd;
				}
			}
			HX_STACK_LINE(122)
			if (((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(124)
				hx::SubEq(this->Hspeed,this->accel);
				HX_STACK_LINE(125)
				if (((this->Hspeed < -(this->mxspd)))){
					HX_STACK_LINE(127)
					this->Hspeed = -(this->mxspd);
				}
			}
			HX_STACK_LINE(132)
			int F = this->flipped;		HX_STACK_VAR(F,"F");
			HX_STACK_LINE(133)
			this->flipped = (int)0;
			HX_STACK_LINE(134)
			this->updphysics();
			HX_STACK_LINE(135)
			this->updateanimation(null());
			HX_STACK_LINE(136)
			this->flipped = F;
			HX_STACK_LINE(137)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(139)
				this->set_rotation((int)90);
			}
			else{
				HX_STACK_LINE(143)
				this->set_rotation((int)0);
			}
			HX_STACK_LINE(146)
			if (((this->ground != null()))){
				HX_STACK_LINE(149)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(152)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Tewi.hx",156,0xd1501abb)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(156)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(157)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(158)
						Float _g7 = this->get_x();		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(158)
						D->__FieldRef(HX_CSTRING("x")) = _g7;
						HX_STACK_LINE(159)
						Float _g8 = this->get_y();		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(159)
						D->__FieldRef(HX_CSTRING("y")) = _g8;
						HX_STACK_LINE(160)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(161)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(163)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(169)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(172)
						this->Vspeed = (int)-4;
					}
				}
			}
			HX_STACK_LINE(178)
			Float _g9 = this->get_y();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(178)
			if (((  (((_g9 > (int)408))) ? bool(this->wrapped) : bool(false) ))){
				HX_STACK_LINE(180)
				this->alive = false;
				HX_STACK_LINE(181)
				this->set_visible(false);
			}
			HX_STACK_LINE(183)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(187)
			{
				HX_STACK_LINE(187)
				::Tewi _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(187)
				Float _g10 = _g->get_y();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(187)
				Float _g11 = (_g10 + (int)15);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(187)
				_g->set_y(_g11);
			}
			HX_STACK_LINE(188)
			Float _g12 = this->get_y();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(188)
			if (((_g12 > (int)600))){
				HX_STACK_LINE(190)
				this->alive = false;
			}
		}
	}
return null();
}


Void Tewi_obj::bump( ){
{
		HX_STACK_FRAME("Tewi","bump",0xd59f5061,"Tewi.bump","Tewi.hx",197,0xd1501abb)
		HX_STACK_THIS(this)
		HX_STACK_LINE(197)
		if (((this->flipped < (int)1))){
			HX_STACK_LINE(199)
			if ((this->enraged)){
				HX_STACK_LINE(201)
				this->flipped = (int)120;
			}
			else{
				HX_STACK_LINE(205)
				this->flipped = (int)210;
			}
		}
		else{
			HX_STACK_LINE(210)
			this->flipped = (int)0;
		}
	}
return null();
}



Tewi_obj::Tewi_obj()
{
}

void Tewi_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Tewi);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(mntime,"mntime");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Tewi_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(mntime,"mntime");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Tewi_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { return rng; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bump") ) { return bump_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { return accel; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { return mxspd; }
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mntime") ) { return mntime; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"increaserank") ) { return increaserank_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Tewi_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { rng=inValue.Cast< ::MersenneTwister >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { accel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { mxspd=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"mntime") ) { mntime=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Tewi_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("mntime"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Tewi_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Tewi_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsInt,(int)offsetof(Tewi_obj,timer),HX_CSTRING("timer")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(Tewi_obj,rng),HX_CSTRING("rng")},
	{hx::fsInt,(int)offsetof(Tewi_obj,mntime),HX_CSTRING("mntime")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("timer"),
	HX_CSTRING("rng"),
	HX_CSTRING("mntime"),
	HX_CSTRING("increaserank"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Tewi_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Tewi_obj::__mClass,"__mClass");
};

#endif

Class Tewi_obj::__mClass;

void Tewi_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Tewi"), hx::TCanCast< Tewi_obj> ,sStaticFields,sMemberFields,
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

void Tewi_obj::__boot()
{
}

