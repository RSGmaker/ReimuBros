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
#ifndef INCLUDED_Seija
#include <Seija.h>
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

Void Seija_obj::__construct()
{
HX_STACK_FRAME("Seija","new",0x5de7ebe0,"Seija.new","Seija.hx",19,0x37862f90)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(20)
	super::__construct(HX_CSTRING("seija"));
	HX_STACK_LINE(21)
	this->accel = 0.6;
	HX_STACK_LINE(22)
	this->deccel = 0.1;
	HX_STACK_LINE(23)
	this->mxspd = (int)6;
	HX_STACK_LINE(24)
	this->Ldir = (int)1;
	HX_STACK_LINE(25)
	this->killed = false;
	HX_STACK_LINE(26)
	this->flipped = (int)-1;
	HX_STACK_LINE(27)
	this->started = false;
	HX_STACK_LINE(28)
	this->pointvalue = (int)500;
	HX_STACK_LINE(29)
	this->flipping = false;
	HX_STACK_LINE(30)
	this->set_scaleX(0.8);
	HX_STACK_LINE(31)
	this->set_scaleY(0.8);
}
;
	return null();
}

//Seija_obj::~Seija_obj() { }

Dynamic Seija_obj::__CreateEmpty() { return  new Seija_obj; }
hx::ObjectPtr< Seija_obj > Seija_obj::__new()
{  hx::ObjectPtr< Seija_obj > result = new Seija_obj();
	result->__construct();
	return result;}

Dynamic Seija_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Seija_obj > result = new Seija_obj();
	result->__construct();
	return result;}

Void Seija_obj::update( ){
{
		HX_STACK_FRAME("Seija","update",0x0b4f9a89,"Seija.update","Seija.hx",40,0x37862f90)
		HX_STACK_THIS(this)
		HX_STACK_LINE(41)
		if ((!(this->started))){
			HX_STACK_LINE(43)
			this->started = true;
		}
		HX_STACK_LINE(46)
		if (((this->rng == null()))){
			HX_STACK_LINE(48)
			::MersenneTwister _g = ::MersenneTwister_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(48)
			this->rng = _g;
			HX_STACK_LINE(49)
			int seed = ::Math_obj::floor((this->UID * (int)100000));		HX_STACK_VAR(seed,"seed");
			HX_STACK_LINE(50)
			Array< int > _g1 = this->rng->twist(seed,(int)1,(int)240);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(50)
			int _g2 = _g1->__get((int)0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(50)
			int _g3 = ((int)60 + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(50)
			this->timer = _g3;
			HX_STACK_LINE(51)
			this->countdown = (int)90;
		}
		HX_STACK_LINE(62)
		if ((!(this->killed))){
			HX_STACK_LINE(64)
			if (((this->flipped < (int)1))){
				HX_STACK_LINE(66)
				if (((this->timer <= (int)0))){
					HX_STACK_LINE(68)
					if (((this->ground != null()))){
						HX_STACK_LINE(70)
						this->flipping = true;
					}
					else{
						HX_STACK_LINE(74)
						this->flipping = false;
					}
				}
				else{
					HX_STACK_LINE(79)
					hx::SubEq(this->timer,(int)1);
				}
				HX_STACK_LINE(81)
				if ((this->flipping)){
					HX_STACK_LINE(83)
					hx::SubEq(this->countdown,(int)1);
					HX_STACK_LINE(85)
					this->visuallyEnraged = !(this->visuallyEnraged);
					HX_STACK_LINE(86)
					if (((this->countdown <= (int)0))){
						HX_STACK_LINE(89)
						if (((bool(::GameView_obj::_this->Hoster) && bool((this->ground != null()))))){
							HX_STACK_LINE(94)
							::GameView_obj::_this->SendEvent(HX_CSTRING("FLIP!"),null());
							HX_STACK_LINE(96)
							Array< int > _g4 = this->rng->twist(this->rng->seed,(int)1,(int)240);		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(96)
							int _g5 = _g4->__get((int)0);		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(96)
							int _g6 = ((int)60 + _g5);		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(96)
							this->timer = _g6;
							HX_STACK_LINE(97)
							this->flipping = false;
							HX_STACK_LINE(98)
							this->countdown = (int)90;
						}
					}
					HX_STACK_LINE(101)
					this->Hspeed = (int)0;
				}
				else{
					HX_STACK_LINE(107)
					this->visuallyEnraged = false;
				}
			}
			else{
				HX_STACK_LINE(112)
				this->flipping = false;
			}
			HX_STACK_LINE(114)
			int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(115)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(117)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(118)
				this->dangerous = false;
				HX_STACK_LINE(119)
				if (((this->flipped == (int)0))){
					HX_STACK_LINE(121)
					this->flipped = (int)-1;
					HX_STACK_LINE(122)
					if ((!(this->enraged))){
						HX_STACK_LINE(124)
						(this->rank)++;
					}
				}
			}
			else{
				HX_STACK_LINE(130)
				this->dangerous = true;
			}
			HX_STACK_LINE(132)
			if ((!(this->flipping))){
				HX_STACK_LINE(134)
				if (((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
					HX_STACK_LINE(136)
					hx::AddEq(this->Hspeed,this->accel);
					HX_STACK_LINE(137)
					if (((this->Hspeed > this->mxspd))){
						HX_STACK_LINE(139)
						this->Hspeed = this->mxspd;
					}
				}
				HX_STACK_LINE(142)
				if (((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
					HX_STACK_LINE(144)
					hx::SubEq(this->Hspeed,this->accel);
					HX_STACK_LINE(145)
					if (((this->Hspeed < -(this->mxspd)))){
						HX_STACK_LINE(147)
						this->Hspeed = -(this->mxspd);
					}
				}
			}
			HX_STACK_LINE(151)
			int F = this->flipped;		HX_STACK_VAR(F,"F");
			HX_STACK_LINE(152)
			Float LX = this->get_x();		HX_STACK_VAR(LX,"LX");
			HX_STACK_LINE(153)
			Float LY = this->get_y();		HX_STACK_VAR(LY,"LY");
			HX_STACK_LINE(154)
			this->flipped = (int)0;
			HX_STACK_LINE(155)
			this->updphysics();
			HX_STACK_LINE(156)
			this->updateanimation(null());
			HX_STACK_LINE(157)
			this->flipped = F;
			HX_STACK_LINE(158)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(160)
				this->set_rotation((int)90);
			}
			else{
				HX_STACK_LINE(164)
				this->set_rotation((int)0);
			}
			HX_STACK_LINE(175)
			if (((this->ground != null()))){
				HX_STACK_LINE(178)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(181)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Seija.hx",185,0x37862f90)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(185)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(186)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(187)
						Float _g7 = this->get_x();		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(187)
						D->__FieldRef(HX_CSTRING("x")) = _g7;
						HX_STACK_LINE(188)
						Float _g8 = this->get_y();		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(188)
						D->__FieldRef(HX_CSTRING("y")) = _g8;
						HX_STACK_LINE(189)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(190)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(192)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(198)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(201)
						this->Vspeed = (int)-4;
					}
				}
			}
			HX_STACK_LINE(207)
			Float _g9 = this->get_y();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(207)
			if (((  (((_g9 > (int)408))) ? bool(this->wrapped) : bool(false) ))){
				HX_STACK_LINE(209)
				this->alive = false;
				HX_STACK_LINE(210)
				this->set_visible(false);
			}
			HX_STACK_LINE(212)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(216)
			{
				HX_STACK_LINE(216)
				::Seija _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(216)
				Float _g10 = _g->get_y();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(216)
				Float _g11 = (_g10 + (int)15);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(216)
				_g->set_y(_g11);
			}
			HX_STACK_LINE(217)
			Float _g12 = this->get_y();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(217)
			if (((_g12 > (int)600))){
				HX_STACK_LINE(219)
				this->alive = false;
			}
		}
	}
return null();
}


Void Seija_obj::bump( ){
{
		HX_STACK_FRAME("Seija","bump",0xc5240476,"Seija.bump","Seija.hx",226,0x37862f90)
		HX_STACK_THIS(this)
		HX_STACK_LINE(226)
		if (((this->flipped < (int)1))){
			HX_STACK_LINE(228)
			if ((this->enraged)){
				HX_STACK_LINE(230)
				this->flipped = (int)120;
			}
			else{
				HX_STACK_LINE(234)
				this->flipped = (int)210;
			}
		}
		else{
			HX_STACK_LINE(239)
			this->flipped = (int)0;
		}
	}
return null();
}



Seija_obj::Seija_obj()
{
}

void Seija_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Seija);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(flipping,"flipping");
	HX_MARK_MEMBER_NAME(countdown,"countdown");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Seija_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(flipping,"flipping");
	HX_VISIT_MEMBER_NAME(countdown,"countdown");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Seija_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"flipping") ) { return flipping; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"countdown") ) { return countdown; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Seija_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	case 8:
		if (HX_FIELD_EQ(inName,"flipping") ) { flipping=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"countdown") ) { countdown=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Seija_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("flipping"));
	outFields->push(HX_CSTRING("countdown"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Seija_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Seija_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsInt,(int)offsetof(Seija_obj,timer),HX_CSTRING("timer")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(Seija_obj,rng),HX_CSTRING("rng")},
	{hx::fsBool,(int)offsetof(Seija_obj,flipping),HX_CSTRING("flipping")},
	{hx::fsInt,(int)offsetof(Seija_obj,countdown),HX_CSTRING("countdown")},
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
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Seija_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Seija_obj::__mClass,"__mClass");
};

#endif

Class Seija_obj::__mClass;

void Seija_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Seija"), hx::TCanCast< Seija_obj> ,sStaticFields,sMemberFields,
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

void Seija_obj::__boot()
{
}

