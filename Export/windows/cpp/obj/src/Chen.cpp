#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Chen
#include <Chen.h>
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
#ifndef INCLUDED_TypeofRound
#include <TypeofRound.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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

Void Chen_obj::__construct()
{
HX_STACK_FRAME("Chen","new",0xb3c6fe60,"Chen.new","Chen.hx",22,0xe78ced10)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(24)
	super::__construct(HX_CSTRING("Chen"));
	HX_STACK_LINE(28)
	this->deccel = (int)100;
	HX_STACK_LINE(30)
	this->Ldir = (int)1;
	HX_STACK_LINE(31)
	this->flipped = (int)-1;
	HX_STACK_LINE(32)
	this->fallaccel = (int)0;
	HX_STACK_LINE(37)
	this->ascend = true;
	HX_STACK_LINE(38)
	this->rng = null();
	HX_STACK_LINE(40)
	this->iter = (int)15;
	HX_STACK_LINE(41)
	this->reward = false;
	HX_STACK_LINE(42)
	this->pointvalue = (int)400;
	HX_STACK_LINE(43)
	this->rot = (int)0;
	HX_STACK_LINE(45)
	this->image_speed = 0.5;
	HX_STACK_LINE(46)
	this->respawn = false;
	HX_STACK_LINE(47)
	this->rename = (HX_CSTRING("E") + this->charname);
	HX_STACK_LINE(48)
	this->danmaku = (int)-1000;
}
;
	return null();
}

//Chen_obj::~Chen_obj() { }

Dynamic Chen_obj::__CreateEmpty() { return  new Chen_obj; }
hx::ObjectPtr< Chen_obj > Chen_obj::__new()
{  hx::ObjectPtr< Chen_obj > result = new Chen_obj();
	result->__construct();
	return result;}

Dynamic Chen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Chen_obj > result = new Chen_obj();
	result->__construct();
	return result;}

Void Chen_obj::enrage( ){
{
		HX_STACK_FRAME("Chen","enrage",0x22011a76,"Chen.enrage","Chen.hx",61,0xe78ced10)
		HX_STACK_THIS(this)
		HX_STACK_LINE(61)
		::haxe::Log_obj::trace(HX_CSTRING("enraged chen??? wut?"),hx::SourceInfo(HX_CSTRING("Chen.hx"),61,HX_CSTRING("Chen"),HX_CSTRING("enrage")));
	}
return null();
}


Void Chen_obj::update( ){
{
		HX_STACK_FRAME("Chen","update",0xa5431809,"Chen.update","Chen.hx",66,0xe78ced10)
		HX_STACK_THIS(this)
		HX_STACK_LINE(67)
		if (((this->rng == null()))){
			HX_STACK_LINE(69)
			::MersenneTwister _g = ::MersenneTwister_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(69)
			this->rng = _g;
			HX_STACK_LINE(70)
			int seed = ::Math_obj::floor((this->UID * (int)100000));		HX_STACK_VAR(seed,"seed");
			HX_STACK_LINE(71)
			Array< int > _g1 = this->rng->twist(seed,(int)1,(int)100);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(71)
			int _g2 = _g1->__get((int)0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(71)
			bool _g3 = (_g2 > (int)50);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(71)
			this->ascend = _g3;
			HX_STACK_LINE(73)
			Array< int > _g4 = this->rng->twist(seed,(int)1,(int)10);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(73)
			int _g5 = _g4->__get((int)0);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(73)
			if (((_g5 > (int)6))){
				HX_STACK_LINE(76)
				this->rename = HX_CSTRING("ERan");
			}
			HX_STACK_LINE(80)
			this->reducetime = (this->rank * (int)30);
			HX_STACK_LINE(81)
			if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Yukari))){
				HX_STACK_LINE(83)
				hx::AddEq(this->reducetime,(int)200);
			}
			HX_STACK_LINE(85)
			if (((bool((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Yukari)) || bool((this->rank > (int)0))))){
				HX_STACK_LINE(87)
				Array< int > _g6 = this->rng->twist(this->rng->seed,(int)1,((int)540 - this->reducetime));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(87)
				int _g7 = _g6->__get((int)0);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(87)
				int _g8 = ((int)15 + _g7);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(87)
				this->danmaku = _g8;
			}
			HX_STACK_LINE(89)
			if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Table))){
				HX_STACK_LINE(91)
				this->rename = HX_CSTRING("table");
			}
		}
		HX_STACK_LINE(94)
		hx::AddEq(this->rot,0.25);
		HX_STACK_LINE(95)
		if (((bool((this->danmaku == (int)-1000)) && bool((this->rank > (int)0))))){
			HX_STACK_LINE(97)
			Array< int > _g9 = this->rng->twist(this->rng->seed,(int)1,((int)540 - this->reducetime));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(97)
			int _g10 = _g9->__get((int)0);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(97)
			int _g11 = ((int)15 + _g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(97)
			this->danmaku = _g11;
		}
		HX_STACK_LINE(99)
		if (((bool((this->danmaku > (int)-1000)) && bool(::GameView_obj::_this->Hoster)))){
			HX_STACK_LINE(101)
			if (((this->danmaku < (int)1))){
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Chen.hx",103,0xe78ced10)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(103)
				Dynamic D = _Function_3_1::Block();		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(104)
				D->__FieldRef(HX_CSTRING("UID")) = this->UID;
				HX_STACK_LINE(105)
				::GameView_obj::_this->SendEvent(HX_CSTRING("ChenDanmaku"),D);
				HX_STACK_LINE(106)
				Array< int > _g12 = this->rng->twist(this->rng->seed,(int)1,((int)540 - this->reducetime));		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(106)
				int _g13 = _g12->__get((int)0);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(106)
				int _g14 = ((int)15 + _g13);		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(106)
				this->danmaku = _g14;
			}
			else{
				HX_STACK_LINE(110)
				hx::SubEq(this->danmaku,(int)1);
			}
		}
		HX_STACK_LINE(121)
		this->animate();
		HX_STACK_LINE(155)
		this->killed = false;
		HX_STACK_LINE(156)
		this->dangerous = true;
		HX_STACK_LINE(157)
		this->killable = false;
		HX_STACK_LINE(158)
		{
			HX_STACK_LINE(158)
			::Chen _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(158)
			Float _g15 = _g->get_x();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(158)
			Float _g16 = (_g15 + ((int)4 * this->Ldir));		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(158)
			_g->set_x(_g16);
		}
		HX_STACK_LINE(159)
		if ((this->ascend)){
			HX_STACK_LINE(161)
			::Chen _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(161)
			Float _g17 = _g->get_y();		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(161)
			Float _g18 = (_g17 - (int)3);		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(161)
			_g->set_y(_g18);
		}
		else{
			HX_STACK_LINE(165)
			::Chen _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(165)
			Float _g19 = _g->get_y();		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(165)
			Float _g20 = (_g19 + (int)3);		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(165)
			_g->set_y(_g20);
		}
		HX_STACK_LINE(167)
		hx::SubEq(this->iter,(int)1);
		HX_STACK_LINE(168)
		if (((this->iter <= (int)0))){
			HX_STACK_LINE(170)
			this->iter = (int)30;
			HX_STACK_LINE(171)
			this->ascend = !(this->ascend);
		}
		HX_STACK_LINE(175)
		{
			HX_STACK_LINE(203)
			this->updphysics();
			HX_STACK_LINE(204)
			this->updateanimation(this->rename);
			HX_STACK_LINE(206)
			if (((this->ground != null()))){
				HX_STACK_LINE(209)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(212)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Chen.hx",216,0xe78ced10)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(216)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(217)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(218)
						Float _g21 = this->get_x();		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(218)
						D->__FieldRef(HX_CSTRING("x")) = _g21;
						HX_STACK_LINE(219)
						Float _g22 = this->get_y();		HX_STACK_VAR(_g22,"_g22");
						HX_STACK_LINE(219)
						D->__FieldRef(HX_CSTRING("y")) = _g22;
						HX_STACK_LINE(220)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(221)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(223)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
			}
			HX_STACK_LINE(228)
			if ((this->wrapped)){
				HX_STACK_LINE(231)
				this->killed = true;
				HX_STACK_LINE(232)
				this->alive = false;
				HX_STACK_LINE(233)
				this->set_visible(false);
			}
		}
	}
return null();
}


Void Chen_obj::bump( ){
{
		HX_STACK_FRAME("Chen","bump",0x927521f6,"Chen.bump","Chen.hx",239,0xe78ced10)
		HX_STACK_THIS(this)
		HX_STACK_LINE(240)
		this->alive = false;
		HX_STACK_LINE(241)
		this->killed = true;
		HX_STACK_LINE(242)
		if (((bool((bool((this->ground != null())) && bool((this->ground->bonkedby != null())))) && bool((this->ground->bonkedby->type == HX_CSTRING("Player")))))){
			HX_STACK_LINE(244)
			Dynamic D = this->ground->bonkedby;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(245)
			hx::AddEq(D->__FieldRef(HX_CSTRING("score")),this->pointvalue);
		}
	}
return null();
}



Chen_obj::Chen_obj()
{
}

void Chen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Chen);
	HX_MARK_MEMBER_NAME(ascend,"ascend");
	HX_MARK_MEMBER_NAME(iter,"iter");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(rot,"rot");
	HX_MARK_MEMBER_NAME(rename,"rename");
	HX_MARK_MEMBER_NAME(danmaku,"danmaku");
	HX_MARK_MEMBER_NAME(reducetime,"reducetime");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Chen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ascend,"ascend");
	HX_VISIT_MEMBER_NAME(iter,"iter");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(rot,"rot");
	HX_VISIT_MEMBER_NAME(rename,"rename");
	HX_VISIT_MEMBER_NAME(danmaku,"danmaku");
	HX_VISIT_MEMBER_NAME(reducetime,"reducetime");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Chen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { return rng; }
		if (HX_FIELD_EQ(inName,"rot") ) { return rot; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"iter") ) { return iter; }
		if (HX_FIELD_EQ(inName,"bump") ) { return bump_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ascend") ) { return ascend; }
		if (HX_FIELD_EQ(inName,"rename") ) { return rename; }
		if (HX_FIELD_EQ(inName,"enrage") ) { return enrage_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"danmaku") ) { return danmaku; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"reducetime") ) { return reducetime; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Chen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { rng=inValue.Cast< ::MersenneTwister >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rot") ) { rot=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"iter") ) { iter=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ascend") ) { ascend=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rename") ) { rename=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"danmaku") ) { danmaku=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"reducetime") ) { reducetime=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Chen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ascend"));
	outFields->push(HX_CSTRING("iter"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("rot"));
	outFields->push(HX_CSTRING("rename"));
	outFields->push(HX_CSTRING("danmaku"));
	outFields->push(HX_CSTRING("reducetime"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Chen_obj,ascend),HX_CSTRING("ascend")},
	{hx::fsInt,(int)offsetof(Chen_obj,iter),HX_CSTRING("iter")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(Chen_obj,rng),HX_CSTRING("rng")},
	{hx::fsFloat,(int)offsetof(Chen_obj,rot),HX_CSTRING("rot")},
	{hx::fsString,(int)offsetof(Chen_obj,rename),HX_CSTRING("rename")},
	{hx::fsInt,(int)offsetof(Chen_obj,danmaku),HX_CSTRING("danmaku")},
	{hx::fsInt,(int)offsetof(Chen_obj,reducetime),HX_CSTRING("reducetime")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("ascend"),
	HX_CSTRING("iter"),
	HX_CSTRING("rng"),
	HX_CSTRING("rot"),
	HX_CSTRING("rename"),
	HX_CSTRING("danmaku"),
	HX_CSTRING("reducetime"),
	HX_CSTRING("enrage"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Chen_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Chen_obj::__mClass,"__mClass");
};

#endif

Class Chen_obj::__mClass;

void Chen_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Chen"), hx::TCanCast< Chen_obj> ,sStaticFields,sMemberFields,
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

void Chen_obj::__boot()
{
}

