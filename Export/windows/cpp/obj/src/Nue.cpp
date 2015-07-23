#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Animationloader
#include <Animationloader.h>
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
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_MersenneTwister
#include <MersenneTwister.h>
#endif
#ifndef INCLUDED_Nue
#include <Nue.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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
#ifndef INCLUDED_openfl__v2_net_SharedObject
#include <openfl/_v2/net/SharedObject.h>
#endif

Void Nue_obj::__construct()
{
HX_STACK_FRAME("Nue","new",0xb97f9e10,"Nue.new","Nue.hx",27,0xd09dd360)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(29)
	super::__construct(HX_CSTRING("Nue"));
	HX_STACK_LINE(31)
	this->accel = 0.5;
	HX_STACK_LINE(32)
	this->deccel = 0.1;
	HX_STACK_LINE(33)
	this->mxspd = (int)5;
	HX_STACK_LINE(34)
	this->Ldir = (int)1;
	HX_STACK_LINE(35)
	this->killed = false;
	HX_STACK_LINE(36)
	this->flipped = (int)-1;
	HX_STACK_LINE(37)
	this->HP = (int)0;
	HX_STACK_LINE(38)
	this->rename = HX_CSTRING("reimu");
	HX_STACK_LINE(39)
	this->frames = (int)0;
	HX_STACK_LINE(40)
	this->alternate = false;
	HX_STACK_LINE(41)
	this->isChar = false;
	HX_STACK_LINE(42)
	this->disguised = false;
}
;
	return null();
}

//Nue_obj::~Nue_obj() { }

Dynamic Nue_obj::__CreateEmpty() { return  new Nue_obj; }
hx::ObjectPtr< Nue_obj > Nue_obj::__new()
{  hx::ObjectPtr< Nue_obj > result = new Nue_obj();
	result->__construct();
	return result;}

Dynamic Nue_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Nue_obj > result = new Nue_obj();
	result->__construct();
	return result;}

Void Nue_obj::enrage( ){
{
		HX_STACK_FRAME("Nue","enrage",0x0c8b68c6,"Nue.enrage","Nue.hx",46,0xd09dd360)
		HX_STACK_THIS(this)
	}
return null();
}


Void Nue_obj::update( ){
{
		HX_STACK_FRAME("Nue","update",0x8fcd6659,"Nue.update","Nue.hx",51,0xd09dd360)
		HX_STACK_THIS(this)
		HX_STACK_LINE(52)
		if (((this->rng == null()))){
			HX_STACK_LINE(54)
			::MersenneTwister _g = ::MersenneTwister_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(54)
			this->rng = _g;
			HX_STACK_LINE(55)
			int _g1 = ::Math_obj::floor((this->UID * (int)100000));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(55)
			this->rng->seed = _g1;
			HX_STACK_LINE(56)
			Array< int > _g2 = this->rng->twist(this->rng->seed,(int)1,(int)100);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(56)
			int _g3 = _g2->__get((int)0);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(56)
			if (((_g3 < (int)50))){
				HX_STACK_LINE(58)
				Array< int > _g4 = this->rng->twist(this->rng->seed,(int)1,::Player_obj::characters->length);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(58)
				int _g5 = _g4->__get((int)0);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(58)
				this->unlock = _g5;
				HX_STACK_LINE(60)
				this->rename = ::Player_obj::characters->__get(this->unlock);
				HX_STACK_LINE(61)
				Array< int > _g6 = this->rng->twist(this->rng->seed,(int)1,(int)100);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(61)
				int _g7 = _g6->__get((int)0);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(61)
				if (((_g7 < (int)30))){
					HX_STACK_LINE(63)
					Array< ::Dynamic > A = ::GameView_obj::_this->AL->GetAnimation((this->rename + HX_CSTRING("ALT")));		HX_STACK_VAR(A,"A");
					HX_STACK_LINE(64)
					if (((bool((A != null())) && bool((A->length > (int)0))))){
						HX_STACK_LINE(66)
						this->rename = (this->rename + HX_CSTRING("ALT"));
						HX_STACK_LINE(67)
						this->alternate = true;
					}
				}
				HX_STACK_LINE(70)
				this->have = ::Main_obj::_this->savedata->data->__Field(HX_CSTRING("unlock"),true)->__GetItem(this->unlock);
				HX_STACK_LINE(71)
				if (((bool(!(this->have)) && bool(this->alternate)))){
					HX_STACK_LINE(73)
					this->have = ::Main_obj::_this->savedata->data->__Field(HX_CSTRING("alts"),true)->__GetItem(this->unlock);
				}
				HX_STACK_LINE(75)
				this->isChar = true;
				HX_STACK_LINE(76)
				this->set_scaleX(0.8);
				HX_STACK_LINE(77)
				this->set_scaleY(0.8);
			}
			else{
				HX_STACK_LINE(81)
				this->isChar = false;
				HX_STACK_LINE(82)
				Array< int > _g8 = this->rng->twist(this->rng->seed,(int)1,(int)100);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(82)
				int _g9 = _g8->__get((int)0);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(82)
				if (((_g9 < (int)60))){
					HX_STACK_LINE(84)
					this->rename = HX_CSTRING("Point");
				}
				else{
					HX_STACK_LINE(88)
					this->rename = HX_CSTRING("1up");
				}
			}
			HX_STACK_LINE(91)
			this->disguised = true;
		}
		HX_STACK_LINE(93)
		(this->frames)++;
		HX_STACK_LINE(94)
		::String S = this->rename;		HX_STACK_VAR(S,"S");
		HX_STACK_LINE(95)
		if ((this->isChar)){
			HX_STACK_LINE(97)
			if (((bool((((int(this->frames) & int((int)1))) > (int)0)) && bool(!(this->have))))){
				HX_STACK_LINE(100)
				S = (S + HX_CSTRING("U"));
			}
			HX_STACK_LINE(102)
			if ((this->have)){
				HX_STACK_LINE(105)
				S = (S + HX_CSTRING("U"));
			}
		}
		HX_STACK_LINE(108)
		this->enraged = false;
		HX_STACK_LINE(111)
		if ((!(this->killed))){
			HX_STACK_LINE(113)
			int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(114)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(116)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(117)
				this->dangerous = false;
			}
			else{
				HX_STACK_LINE(121)
				this->dangerous = true;
			}
			HX_STACK_LINE(123)
			if (((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(125)
				hx::AddEq(this->Hspeed,this->accel);
				HX_STACK_LINE(126)
				if (((this->Hspeed > this->mxspd))){
					HX_STACK_LINE(128)
					this->Hspeed = this->mxspd;
				}
			}
			HX_STACK_LINE(131)
			if (((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(133)
				hx::SubEq(this->Hspeed,this->accel);
				HX_STACK_LINE(134)
				if (((this->Hspeed < -(this->mxspd)))){
					HX_STACK_LINE(136)
					this->Hspeed = -(this->mxspd);
				}
			}
			HX_STACK_LINE(139)
			int F = this->flipped;		HX_STACK_VAR(F,"F");
			HX_STACK_LINE(140)
			this->flipped = (int)0;
			HX_STACK_LINE(141)
			this->updphysics();
			HX_STACK_LINE(143)
			this->updateanimation(S);
			HX_STACK_LINE(144)
			this->flipped = F;
			HX_STACK_LINE(145)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(147)
				this->set_rotation((int)90);
			}
			else{
				HX_STACK_LINE(163)
				this->set_rotation((int)0);
			}
			HX_STACK_LINE(166)
			if (((this->ground != null()))){
				HX_STACK_LINE(169)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(172)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Nue.hx",176,0xd09dd360)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(176)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(177)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(178)
						Float _g10 = this->get_x();		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(178)
						D->__FieldRef(HX_CSTRING("x")) = _g10;
						HX_STACK_LINE(179)
						Float _g11 = this->get_y();		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(179)
						D->__FieldRef(HX_CSTRING("y")) = _g11;
						HX_STACK_LINE(180)
						D->__FieldRef(HX_CSTRING("Hspeed")) = (this->Hspeed * 0.5);
						HX_STACK_LINE(181)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(183)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(189)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(192)
						this->Vspeed = (int)-4;
						HX_STACK_LINE(193)
						this->HP = (int)0;
					}
				}
			}
			HX_STACK_LINE(199)
			Float _g12 = this->get_y();		HX_STACK_VAR(_g12,"_g12");
			struct _Function_2_1{
				inline static bool Block( hx::ObjectPtr< ::Nue_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Nue.hx",199,0xd09dd360)
					{
						HX_STACK_LINE(199)
						Float _g13 = __this->get_y();		HX_STACK_VAR(_g13,"_g13");
						HX_STACK_LINE(199)
						return (_g13 > (int)800);
					}
					return null();
				}
			};
			HX_STACK_LINE(199)
			if (((  ((!(((  (((_g12 > (int)408))) ? bool(this->wrapped) : bool(false) ))))) ? bool(_Function_2_1::Block(this)) : bool(true) ))){
				HX_STACK_LINE(201)
				this->alive = false;
				HX_STACK_LINE(202)
				this->set_visible(false);
			}
			HX_STACK_LINE(204)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(208)
			{
				HX_STACK_LINE(208)
				::Nue _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(208)
				Float _g14 = _g->get_y();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(208)
				Float _g15 = (_g14 + (int)15);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(208)
				_g->set_y(_g15);
			}
			HX_STACK_LINE(209)
			Float _g16 = this->get_y();		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(209)
			if (((_g16 > (int)600))){
				HX_STACK_LINE(211)
				this->alive = false;
			}
		}
	}
return null();
}


Void Nue_obj::bump( ){
{
		HX_STACK_FRAME("Nue","bump",0x8e483c46,"Nue.bump","Nue.hx",218,0xd09dd360)
		HX_STACK_THIS(this)
		HX_STACK_LINE(218)
		if ((this->disguised)){
			HX_STACK_LINE(220)
			this->rename = HX_CSTRING("nue");
			HX_STACK_LINE(221)
			this->disguised = false;
			HX_STACK_LINE(222)
			this->isChar = false;
			HX_STACK_LINE(223)
			this->set_scaleX(0.8);
			HX_STACK_LINE(224)
			this->set_scaleY(0.8);
		}
		else{
			HX_STACK_LINE(228)
			if (((this->HP > (int)0))){
				HX_STACK_LINE(230)
				(this->HP)--;
			}
			else{
				HX_STACK_LINE(234)
				if (((this->flipped < (int)1))){
					HX_STACK_LINE(236)
					if ((this->enraged)){
						HX_STACK_LINE(238)
						this->flipped = (int)120;
					}
					else{
						HX_STACK_LINE(242)
						this->flipped = (int)210;
					}
				}
				else{
					HX_STACK_LINE(247)
					this->flipped = (int)0;
					HX_STACK_LINE(248)
					this->HP = (int)0;
				}
			}
		}
	}
return null();
}



Nue_obj::Nue_obj()
{
}

void Nue_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Nue);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(flipping,"flipping");
	HX_MARK_MEMBER_NAME(countdown,"countdown");
	HX_MARK_MEMBER_NAME(rename,"rename");
	HX_MARK_MEMBER_NAME(have,"have");
	HX_MARK_MEMBER_NAME(isChar,"isChar");
	HX_MARK_MEMBER_NAME(disguised,"disguised");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(unlock,"unlock");
	HX_MARK_MEMBER_NAME(alternate,"alternate");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Nue_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(flipping,"flipping");
	HX_VISIT_MEMBER_NAME(countdown,"countdown");
	HX_VISIT_MEMBER_NAME(rename,"rename");
	HX_VISIT_MEMBER_NAME(have,"have");
	HX_VISIT_MEMBER_NAME(isChar,"isChar");
	HX_VISIT_MEMBER_NAME(disguised,"disguised");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(unlock,"unlock");
	HX_VISIT_MEMBER_NAME(alternate,"alternate");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Nue_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { return rng; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"have") ) { return have; }
		if (HX_FIELD_EQ(inName,"bump") ) { return bump_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { return accel; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { return mxspd; }
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rename") ) { return rename; }
		if (HX_FIELD_EQ(inName,"isChar") ) { return isChar; }
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"unlock") ) { return unlock; }
		if (HX_FIELD_EQ(inName,"enrage") ) { return enrage_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flipping") ) { return flipping; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"countdown") ) { return countdown; }
		if (HX_FIELD_EQ(inName,"disguised") ) { return disguised; }
		if (HX_FIELD_EQ(inName,"alternate") ) { return alternate; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Nue_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rng") ) { rng=inValue.Cast< ::MersenneTwister >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"have") ) { have=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { accel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { mxspd=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rename") ) { rename=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isChar") ) { isChar=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"unlock") ) { unlock=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flipping") ) { flipping=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"countdown") ) { countdown=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disguised") ) { disguised=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"alternate") ) { alternate=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Nue_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("flipping"));
	outFields->push(HX_CSTRING("countdown"));
	outFields->push(HX_CSTRING("rename"));
	outFields->push(HX_CSTRING("have"));
	outFields->push(HX_CSTRING("isChar"));
	outFields->push(HX_CSTRING("disguised"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("unlock"));
	outFields->push(HX_CSTRING("alternate"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Nue_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Nue_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsInt,(int)offsetof(Nue_obj,timer),HX_CSTRING("timer")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(Nue_obj,rng),HX_CSTRING("rng")},
	{hx::fsBool,(int)offsetof(Nue_obj,flipping),HX_CSTRING("flipping")},
	{hx::fsInt,(int)offsetof(Nue_obj,countdown),HX_CSTRING("countdown")},
	{hx::fsString,(int)offsetof(Nue_obj,rename),HX_CSTRING("rename")},
	{hx::fsBool,(int)offsetof(Nue_obj,have),HX_CSTRING("have")},
	{hx::fsBool,(int)offsetof(Nue_obj,isChar),HX_CSTRING("isChar")},
	{hx::fsBool,(int)offsetof(Nue_obj,disguised),HX_CSTRING("disguised")},
	{hx::fsInt,(int)offsetof(Nue_obj,frames),HX_CSTRING("frames")},
	{hx::fsInt,(int)offsetof(Nue_obj,unlock),HX_CSTRING("unlock")},
	{hx::fsBool,(int)offsetof(Nue_obj,alternate),HX_CSTRING("alternate")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("timer"),
	HX_CSTRING("rng"),
	HX_CSTRING("flipping"),
	HX_CSTRING("countdown"),
	HX_CSTRING("rename"),
	HX_CSTRING("have"),
	HX_CSTRING("isChar"),
	HX_CSTRING("disguised"),
	HX_CSTRING("frames"),
	HX_CSTRING("unlock"),
	HX_CSTRING("alternate"),
	HX_CSTRING("enrage"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Nue_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Nue_obj::__mClass,"__mClass");
};

#endif

Class Nue_obj::__mClass;

void Nue_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Nue"), hx::TCanCast< Nue_obj> ,sStaticFields,sMemberFields,
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

void Nue_obj::__boot()
{
}

