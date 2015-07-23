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
#ifndef INCLUDED_Mystia
#include <Mystia.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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

Void Mystia_obj::__construct()
{
HX_STACK_FRAME("Mystia","new",0x07f68bb7,"Mystia.new","Mystia.hx",18,0x40529799)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(20)
	super::__construct(HX_CSTRING("Mystia"));
	HX_STACK_LINE(22)
	this->accel = 0.8;
	HX_STACK_LINE(23)
	this->deccel = 0.1;
	HX_STACK_LINE(24)
	this->mxspd = (int)6;
	HX_STACK_LINE(25)
	this->Ldir = (int)1;
	HX_STACK_LINE(26)
	this->killed = false;
	HX_STACK_LINE(27)
	this->flipped = (int)-1;
	HX_STACK_LINE(28)
	this->frames = (int)0;
	HX_STACK_LINE(29)
	this->image_speed = 0.4;
	HX_STACK_LINE(30)
	this->rng = null();
	HX_STACK_LINE(31)
	this->mntime = (int)1;
	HX_STACK_LINE(32)
	this->pointvalue = (int)200;
}
;
	return null();
}

//Mystia_obj::~Mystia_obj() { }

Dynamic Mystia_obj::__CreateEmpty() { return  new Mystia_obj; }
hx::ObjectPtr< Mystia_obj > Mystia_obj::__new()
{  hx::ObjectPtr< Mystia_obj > result = new Mystia_obj();
	result->__construct();
	return result;}

Dynamic Mystia_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mystia_obj > result = new Mystia_obj();
	result->__construct();
	return result;}

Void Mystia_obj::increaserank( ){
{
		HX_STACK_FRAME("Mystia","increaserank",0x17103437,"Mystia.increaserank","Mystia.hx",42,0x40529799)
		HX_STACK_THIS(this)
		HX_STACK_LINE(43)
		hx::AddEq(this->accel,0.15);
		HX_STACK_LINE(44)
		hx::AddEq(this->mxspd,(int)1);
		HX_STACK_LINE(45)
		hx::AddEq(this->mntime,(int)5);
		HX_STACK_LINE(46)
		hx::AddEq(this->pointvalue,(int)100);
	}
return null();
}


Void Mystia_obj::update( ){
{
		HX_STACK_FRAME("Mystia","update",0x450b3b12,"Mystia.update","Mystia.hx",49,0x40529799)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		if ((!(this->started))){
			HX_STACK_LINE(61)
			this->started = true;
		}
		HX_STACK_LINE(63)
		if (((this->rng == null()))){
			HX_STACK_LINE(65)
			::MersenneTwister _g = ::MersenneTwister_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(65)
			this->rng = _g;
			HX_STACK_LINE(66)
			int seed = ::Math_obj::floor((this->UID * (int)100000));		HX_STACK_VAR(seed,"seed");
			HX_STACK_LINE(67)
			this->rng->twist(seed,(int)1,(int)100000);
		}
		HX_STACK_LINE(70)
		if ((!(this->killed))){
			HX_STACK_LINE(72)
			int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(73)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(75)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(76)
				this->dangerous = false;
				HX_STACK_LINE(77)
				if (((this->flipped == (int)0))){
					HX_STACK_LINE(79)
					this->flipped = (int)-1;
					HX_STACK_LINE(80)
					this->powerup();
				}
			}
			else{
				HX_STACK_LINE(85)
				this->dangerous = true;
			}
			HX_STACK_LINE(89)
			this->updphysics();
			HX_STACK_LINE(90)
			if (((bool((this->ground == null())) || bool((this->Vspeed < (int)0))))){
				HX_STACK_LINE(92)
				if (((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
					HX_STACK_LINE(94)
					hx::AddEq(this->Hspeed,this->accel);
					HX_STACK_LINE(95)
					if (((this->Hspeed > this->mxspd))){
						HX_STACK_LINE(97)
						this->Hspeed = this->mxspd;
					}
				}
				HX_STACK_LINE(100)
				if (((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
					HX_STACK_LINE(102)
					hx::SubEq(this->Hspeed,this->accel);
					HX_STACK_LINE(103)
					if (((this->Hspeed < -(this->mxspd)))){
						HX_STACK_LINE(105)
						this->Hspeed = -(this->mxspd);
					}
				}
				HX_STACK_LINE(108)
				this->frames = (int)0;
			}
			else{
				HX_STACK_LINE(113)
				this->image_index = -0.001;
				HX_STACK_LINE(114)
				if (((this->flipped <= (int)0))){
					HX_STACK_LINE(116)
					if (((this->frames == (int)0))){
						HX_STACK_LINE(118)
						int _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(118)
						{
							HX_STACK_LINE(118)
							Array< int > _g1 = this->rng->twist(this->rng->seed,(int)1,(int)30);		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(118)
							int b = _g1->__get((int)0);		HX_STACK_VAR(b,"b");
							HX_STACK_LINE(118)
							_g2 = (this->rng->seed + b);
						}
						HX_STACK_LINE(118)
						this->rng->seed = _g2;
						HX_STACK_LINE(119)
						int _g3;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(119)
						{
							struct _Function_6_1{
								inline static Float Block( hx::ObjectPtr< ::Mystia_obj > __this){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mystia.hx",119,0x40529799)
									{
										HX_STACK_LINE(119)
										int _int = __this->rng->seed;		HX_STACK_VAR(_int,"int");
										HX_STACK_LINE(119)
										return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
									}
									return null();
								}
							};
							struct _Function_6_2{
								inline static Float Block( ){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mystia.hx",119,0x40529799)
									{
										HX_STACK_LINE(119)
										int _int = (int)30;		HX_STACK_VAR(_int,"int");
										HX_STACK_LINE(119)
										return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
									}
									return null();
								}
							};
							HX_STACK_LINE(119)
							int b = ::Std_obj::_int(hx::Mod(_Function_6_1::Block(this),_Function_6_2::Block()));		HX_STACK_VAR(b,"b");
							HX_STACK_LINE(119)
							_g3 = (this->mntime + b);
						}
						HX_STACK_LINE(119)
						this->frames = _g3;
					}
					HX_STACK_LINE(121)
					this->Hspeed = (int)0;
					HX_STACK_LINE(122)
					hx::AddEq(this->frames,(int)1);
					HX_STACK_LINE(123)
					if (((this->frames > (int)90))){
						HX_STACK_LINE(126)
						int _g5;		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(126)
						{
							HX_STACK_LINE(126)
							Array< int > _g4 = this->rng->twist(this->rng->seed,(int)1,(int)800);		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(126)
							int b = _g4->__get((int)0);		HX_STACK_VAR(b,"b");
							HX_STACK_LINE(126)
							_g5 = (this->rng->seed + b);
						}
						HX_STACK_LINE(126)
						this->rng->seed = _g5;
						HX_STACK_LINE(127)
						Float _g6;		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(127)
						{
							struct _Function_6_1{
								inline static Float Block( hx::ObjectPtr< ::Mystia_obj > __this){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mystia.hx",127,0x40529799)
									{
										HX_STACK_LINE(127)
										int _int = __this->rng->seed;		HX_STACK_VAR(_int,"int");
										HX_STACK_LINE(127)
										return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
									}
									return null();
								}
							};
							struct _Function_6_2{
								inline static Float Block( ){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mystia.hx",127,0x40529799)
									{
										HX_STACK_LINE(127)
										int _int = (int)800;		HX_STACK_VAR(_int,"int");
										HX_STACK_LINE(127)
										return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
									}
									return null();
								}
							};
							HX_STACK_LINE(127)
							int a = ::Std_obj::_int(hx::Mod(_Function_6_1::Block(this),_Function_6_2::Block()));		HX_STACK_VAR(a,"a");
							struct _Function_6_3{
								inline static Float Block( int &a){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mystia.hx",127,0x40529799)
									{
										HX_STACK_LINE(127)
										int _int = a;		HX_STACK_VAR(_int,"int");
										HX_STACK_LINE(127)
										return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
									}
									return null();
								}
							};
							HX_STACK_LINE(127)
							_g6 = (_Function_6_3::Block(a) * 0.01);
						}
						HX_STACK_LINE(127)
						Float _g7 = ((int)-4 - _g6);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(127)
						this->Vspeed = _g7;
					}
				}
			}
			HX_STACK_LINE(132)
			this->animate();
			HX_STACK_LINE(133)
			this->updateanimation(null());
			HX_STACK_LINE(135)
			if (((this->ground != null()))){
				HX_STACK_LINE(138)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(141)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mystia.hx",145,0x40529799)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(145)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(146)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(147)
						Float _g8 = this->get_x();		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(147)
						D->__FieldRef(HX_CSTRING("x")) = _g8;
						HX_STACK_LINE(148)
						Float _g9 = this->get_y();		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(148)
						D->__FieldRef(HX_CSTRING("y")) = _g9;
						HX_STACK_LINE(149)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(150)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(152)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(158)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(161)
						this->Vspeed = (int)-4;
					}
				}
			}
			HX_STACK_LINE(167)
			Float _g10 = this->get_y();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(167)
			if (((  (((_g10 > (int)408))) ? bool(this->wrapped) : bool(false) ))){
				HX_STACK_LINE(169)
				this->alive = false;
				HX_STACK_LINE(170)
				this->set_visible(false);
			}
			HX_STACK_LINE(172)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(176)
			{
				HX_STACK_LINE(176)
				::Mystia _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(176)
				Float _g11 = _g->get_y();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(176)
				Float _g12 = (_g11 + (int)15);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(176)
				_g->set_y(_g12);
			}
			HX_STACK_LINE(177)
			Float _g13 = this->get_y();		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(177)
			if (((_g13 > (int)600))){
				HX_STACK_LINE(179)
				this->alive = false;
			}
		}
	}
return null();
}


Void Mystia_obj::bump( ){
{
		HX_STACK_FRAME("Mystia","bump",0xe7e140bf,"Mystia.bump","Mystia.hx",186,0x40529799)
		HX_STACK_THIS(this)
		HX_STACK_LINE(186)
		if (((this->flipped < (int)1))){
			HX_STACK_LINE(188)
			if ((this->enraged)){
				HX_STACK_LINE(190)
				this->flipped = (int)150;
			}
			else{
				HX_STACK_LINE(194)
				this->flipped = (int)210;
			}
		}
		else{
			HX_STACK_LINE(199)
			this->flipped = (int)-1;
		}
	}
return null();
}



Mystia_obj::Mystia_obj()
{
}

void Mystia_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Mystia);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(mntime,"mntime");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Mystia_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(mntime,"mntime");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Mystia_obj::__Field(const ::String &inName,bool inCallProp)
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
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"mntime") ) { return mntime; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"increaserank") ) { return increaserank_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mystia_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { rng=inValue.Cast< ::MersenneTwister >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { accel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { mxspd=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mntime") ) { mntime=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mystia_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("mntime"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Mystia_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Mystia_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsInt,(int)offsetof(Mystia_obj,frames),HX_CSTRING("frames")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(Mystia_obj,rng),HX_CSTRING("rng")},
	{hx::fsInt,(int)offsetof(Mystia_obj,mntime),HX_CSTRING("mntime")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("frames"),
	HX_CSTRING("rng"),
	HX_CSTRING("mntime"),
	HX_CSTRING("increaserank"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mystia_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mystia_obj::__mClass,"__mClass");
};

#endif

Class Mystia_obj::__mClass;

void Mystia_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Mystia"), hx::TCanCast< Mystia_obj> ,sStaticFields,sMemberFields,
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

void Mystia_obj::__boot()
{
}

