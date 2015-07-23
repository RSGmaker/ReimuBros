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
#ifndef INCLUDED_UFO
#include <UFO.h>
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
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif

Void UFO_obj::__construct()
{
HX_STACK_FRAME("UFO","new",0x66ff24d0,"UFO.new","UFO.hx",24,0x7ebd64a0)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(26)
	super::__construct(HX_CSTRING("UFO"));
	HX_STACK_LINE(30)
	this->deccel = (int)100;
	HX_STACK_LINE(32)
	this->Ldir = (int)1;
	HX_STACK_LINE(33)
	this->flipped = (int)-1;
	HX_STACK_LINE(34)
	this->fallaccel = (int)0;
	HX_STACK_LINE(39)
	this->ascend = true;
	HX_STACK_LINE(40)
	this->rng = null();
	HX_STACK_LINE(41)
	this->iter = (int)30;
	HX_STACK_LINE(42)
	this->reward = false;
	HX_STACK_LINE(43)
	this->pointvalue = (int)400;
	HX_STACK_LINE(44)
	this->rot = (int)0;
	HX_STACK_LINE(45)
	this->image_speed = 0.5;
	HX_STACK_LINE(46)
	this->respawn = false;
	HX_STACK_LINE(47)
	this->rename = HX_CSTRING("");
	HX_STACK_LINE(56)
	this->hitbox = ::UFO_obj::HB;
}
;
	return null();
}

//UFO_obj::~UFO_obj() { }

Dynamic UFO_obj::__CreateEmpty() { return  new UFO_obj; }
hx::ObjectPtr< UFO_obj > UFO_obj::__new()
{  hx::ObjectPtr< UFO_obj > result = new UFO_obj();
	result->__construct();
	return result;}

Dynamic UFO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UFO_obj > result = new UFO_obj();
	result->__construct();
	return result;}

Void UFO_obj::enrage( ){
{
		HX_STACK_FRAME("UFO","enrage",0xa9ec9a06,"UFO.enrage","UFO.hx",61,0x7ebd64a0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(61)
		::haxe::Log_obj::trace(HX_CSTRING("enraged UFO??? wut?"),hx::SourceInfo(HX_CSTRING("UFO.hx"),61,HX_CSTRING("UFO"),HX_CSTRING("enrage")));
	}
return null();
}


Void UFO_obj::update( ){
{
		HX_STACK_FRAME("UFO","update",0x2d2e9799,"UFO.update","UFO.hx",66,0x7ebd64a0)
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
			HX_STACK_LINE(72)
			Array< int > _g4 = this->rng->twist(seed,(int)1,(int)10);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(72)
			int R = _g4->__get((int)0);		HX_STACK_VAR(R,"R");
			HX_STACK_LINE(73)
			if (((R > (int)6))){
				HX_STACK_LINE(76)
				this->ufotype = HX_CSTRING("Red");
			}
			else{
				HX_STACK_LINE(78)
				if (((R < (int)3))){
					HX_STACK_LINE(81)
					this->ufotype = HX_CSTRING("Green");
				}
				else{
					HX_STACK_LINE(85)
					this->ufotype = HX_CSTRING("Blue");
				}
			}
			HX_STACK_LINE(87)
			Array< int > _g5 = this->rng->twist((int)0,(int)1,(int)240);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(87)
			int _g6 = _g5->__get((int)0);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(87)
			int _g7 = ((int)15 + _g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(87)
			this->iter = _g7;
			HX_STACK_LINE(88)
			Array< int > _g8 = this->rng->twist((int)0,(int)1,((int)900 + (this->rank * (int)150)));		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(88)
			int _g9 = _g8->__get((int)0);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(88)
			int _g10 = ((int)90 + _g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(88)
			this->fuel = _g10;
			HX_STACK_LINE(89)
			this->reducetime = (this->rank * (int)30);
		}
		HX_STACK_LINE(92)
		this->rename = (this->ufotype + HX_CSTRING("ufo"));
		HX_STACK_LINE(94)
		this->animate();
		HX_STACK_LINE(95)
		this->killed = false;
		HX_STACK_LINE(96)
		this->dangerous = true;
		HX_STACK_LINE(97)
		this->killable = false;
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			::UFO _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(98)
			Float _g11 = _g->get_x();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(98)
			Float _g12 = (_g11 - (int)2);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(98)
			_g->set_x(_g12);
		}
		HX_STACK_LINE(99)
		Float _g13 = this->get_x();		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(99)
		if (((_g13 < (int)-64))){
			HX_STACK_LINE(101)
			this->set_x((int)900);
		}
		HX_STACK_LINE(103)
		if (((this->fuel > (int)0))){
			HX_STACK_LINE(105)
			(this->fuel)--;
			HX_STACK_LINE(106)
			Float _g14 = this->get_y();		HX_STACK_VAR(_g14,"_g14");
			struct _Function_2_1{
				inline static bool Block( hx::ObjectPtr< ::UFO_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","UFO.hx",106,0x7ebd64a0)
					{
						HX_STACK_LINE(106)
						Float _g15 = __this->get_x();		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(106)
						return (_g15 > (int)0);
					}
					return null();
				}
			};
			struct _Function_2_2{
				inline static bool Block( hx::ObjectPtr< ::UFO_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","UFO.hx",106,0x7ebd64a0)
					{
						HX_STACK_LINE(106)
						Float _g16 = __this->get_x();		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(106)
						return (_g16 < (int)800);
					}
					return null();
				}
			};
			HX_STACK_LINE(106)
			if (((  (((  (((_g14 == (int)10))) ? bool(_Function_2_1::Block(this)) : bool(false) ))) ? bool(_Function_2_2::Block(this)) : bool(false) ))){
				HX_STACK_LINE(108)
				if (((this->iter > (int)0))){
					HX_STACK_LINE(110)
					(this->iter)--;
				}
				else{
					HX_STACK_LINE(119)
					{
						HX_STACK_LINE(120)
						Array< int > _g17 = this->rng->twist((int)0,(int)1,((int)270 - this->reducetime));		HX_STACK_VAR(_g17,"_g17");
						HX_STACK_LINE(120)
						int _g18 = _g17->__get((int)0);		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(120)
						int _g19 = ((int)15 + _g18);		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(120)
						this->iter = _g19;
					}
					HX_STACK_LINE(122)
					if ((::GameView_obj::_this->Hoster)){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","UFO.hx",125,0x7ebd64a0)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(125)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(126)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(127)
						::GameView_obj::_this->SendEvent(HX_CSTRING("UFOStrike"),D);
					}
				}
			}
			else{
				HX_STACK_LINE(133)
				Float _g20 = this->get_y();		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(133)
				if (((_g20 < (int)10))){
					HX_STACK_LINE(135)
					::UFO _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(135)
					Float _g1 = _g->get_y();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(135)
					_g->set_y((_g1 + (int)1));
					HX_STACK_LINE(135)
					_g1;
				}
			}
		}
		else{
			HX_STACK_LINE(141)
			{
				HX_STACK_LINE(141)
				::UFO _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(141)
				Float _g1 = _g->get_y();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(141)
				_g->set_y((_g1 - (int)1));
				HX_STACK_LINE(141)
				_g1;
			}
			HX_STACK_LINE(142)
			Float _g21 = this->get_y();		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(142)
			if (((_g21 < (int)-200))){
				HX_STACK_LINE(144)
				if ((this->alive)){
					HX_STACK_LINE(146)
					(::GameView_obj::_this->ufos)--;
				}
				HX_STACK_LINE(148)
				this->alive = false;
				HX_STACK_LINE(149)
				this->killed = true;
			}
		}
		HX_STACK_LINE(169)
		{
			HX_STACK_LINE(172)
			this->updateanimation(this->rename);
			HX_STACK_LINE(174)
			if (((this->ground != null()))){
				HX_STACK_LINE(176)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(178)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","UFO.hx",180,0x7ebd64a0)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(180)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(181)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(182)
						Float _g22 = this->get_x();		HX_STACK_VAR(_g22,"_g22");
						HX_STACK_LINE(182)
						D->__FieldRef(HX_CSTRING("x")) = _g22;
						HX_STACK_LINE(183)
						Float _g23 = this->get_y();		HX_STACK_VAR(_g23,"_g23");
						HX_STACK_LINE(183)
						D->__FieldRef(HX_CSTRING("y")) = _g23;
						HX_STACK_LINE(184)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(185)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(186)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
			}
			HX_STACK_LINE(191)
			if ((this->wrapped)){
				HX_STACK_LINE(194)
				this->killed = true;
				HX_STACK_LINE(195)
				this->alive = false;
				HX_STACK_LINE(196)
				this->set_visible(false);
			}
		}
	}
return null();
}


Void UFO_obj::bump( ){
{
		HX_STACK_FRAME("UFO","bump",0xb05e9d86,"UFO.bump","UFO.hx",202,0x7ebd64a0)
		HX_STACK_THIS(this)
		HX_STACK_LINE(203)
		this->alive = false;
		HX_STACK_LINE(204)
		this->killed = true;
		HX_STACK_LINE(205)
		if (((bool((bool((this->ground != null())) && bool((this->ground->bonkedby != null())))) && bool((this->ground->bonkedby->type == HX_CSTRING("Player")))))){
			HX_STACK_LINE(207)
			Dynamic D = this->ground->bonkedby;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(208)
			hx::AddEq(D->__FieldRef(HX_CSTRING("score")),this->pointvalue);
		}
	}
return null();
}


::openfl::_v2::geom::Rectangle UFO_obj::HB;


UFO_obj::UFO_obj()
{
}

void UFO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UFO);
	HX_MARK_MEMBER_NAME(ascend,"ascend");
	HX_MARK_MEMBER_NAME(iter,"iter");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(rot,"rot");
	HX_MARK_MEMBER_NAME(rename,"rename");
	HX_MARK_MEMBER_NAME(ufotype,"ufotype");
	HX_MARK_MEMBER_NAME(fuel,"fuel");
	HX_MARK_MEMBER_NAME(reducetime,"reducetime");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void UFO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ascend,"ascend");
	HX_VISIT_MEMBER_NAME(iter,"iter");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(rot,"rot");
	HX_VISIT_MEMBER_NAME(rename,"rename");
	HX_VISIT_MEMBER_NAME(ufotype,"ufotype");
	HX_VISIT_MEMBER_NAME(fuel,"fuel");
	HX_VISIT_MEMBER_NAME(reducetime,"reducetime");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic UFO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"HB") ) { return HB; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { return rng; }
		if (HX_FIELD_EQ(inName,"rot") ) { return rot; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"iter") ) { return iter; }
		if (HX_FIELD_EQ(inName,"fuel") ) { return fuel; }
		if (HX_FIELD_EQ(inName,"bump") ) { return bump_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ascend") ) { return ascend; }
		if (HX_FIELD_EQ(inName,"rename") ) { return rename; }
		if (HX_FIELD_EQ(inName,"enrage") ) { return enrage_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ufotype") ) { return ufotype; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"reducetime") ) { return reducetime; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UFO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"HB") ) { HB=inValue.Cast< ::openfl::_v2::geom::Rectangle >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { rng=inValue.Cast< ::MersenneTwister >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rot") ) { rot=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"iter") ) { iter=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fuel") ) { fuel=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ascend") ) { ascend=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rename") ) { rename=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ufotype") ) { ufotype=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"reducetime") ) { reducetime=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void UFO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ascend"));
	outFields->push(HX_CSTRING("iter"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("rot"));
	outFields->push(HX_CSTRING("rename"));
	outFields->push(HX_CSTRING("ufotype"));
	outFields->push(HX_CSTRING("fuel"));
	outFields->push(HX_CSTRING("reducetime"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HB"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(UFO_obj,ascend),HX_CSTRING("ascend")},
	{hx::fsInt,(int)offsetof(UFO_obj,iter),HX_CSTRING("iter")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(UFO_obj,rng),HX_CSTRING("rng")},
	{hx::fsFloat,(int)offsetof(UFO_obj,rot),HX_CSTRING("rot")},
	{hx::fsString,(int)offsetof(UFO_obj,rename),HX_CSTRING("rename")},
	{hx::fsString,(int)offsetof(UFO_obj,ufotype),HX_CSTRING("ufotype")},
	{hx::fsInt,(int)offsetof(UFO_obj,fuel),HX_CSTRING("fuel")},
	{hx::fsInt,(int)offsetof(UFO_obj,reducetime),HX_CSTRING("reducetime")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("ascend"),
	HX_CSTRING("iter"),
	HX_CSTRING("rng"),
	HX_CSTRING("rot"),
	HX_CSTRING("rename"),
	HX_CSTRING("ufotype"),
	HX_CSTRING("fuel"),
	HX_CSTRING("reducetime"),
	HX_CSTRING("enrage"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UFO_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(UFO_obj::HB,"HB");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UFO_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(UFO_obj::HB,"HB");
};

#endif

Class UFO_obj::__mClass;

void UFO_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("UFO"), hx::TCanCast< UFO_obj> ,sStaticFields,sMemberFields,
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

void UFO_obj::__boot()
{
	HB= ::openfl::_v2::geom::Rectangle_obj::__new((int)9,(int)9,(int)10,(int)10);
}

