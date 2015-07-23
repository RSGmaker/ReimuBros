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
#ifndef INCLUDED_Imposter
#include <Imposter.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
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

Void Imposter_obj::__construct()
{
HX_STACK_FRAME("Imposter","new",0xe3632d43,"Imposter.new","Imposter.hx",33,0x381f6b8d)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(35)
	super::__construct(HX_CSTRING("Imposter"));
	HX_STACK_LINE(37)
	this->accel = 0.5;
	HX_STACK_LINE(38)
	this->deccel = 0.1;
	HX_STACK_LINE(39)
	this->mxspd = (int)5;
	HX_STACK_LINE(40)
	this->Ldir = (int)1;
	HX_STACK_LINE(41)
	this->killed = false;
	HX_STACK_LINE(42)
	this->flipped = (int)-1;
	HX_STACK_LINE(43)
	this->HP = (int)0;
	HX_STACK_LINE(44)
	this->rename = HX_CSTRING("reimu");
	HX_STACK_LINE(45)
	this->frames = (int)0;
	HX_STACK_LINE(46)
	this->alternate = false;
	HX_STACK_LINE(47)
	this->pointvalue = (int)500;
	HX_STACK_LINE(48)
	this->mxcountdown = (int)35;
	HX_STACK_LINE(50)
	this->countdown = this->mxcountdown;
	HX_STACK_LINE(51)
	this->mxtimer = (int)300;
}
;
	return null();
}

//Imposter_obj::~Imposter_obj() { }

Dynamic Imposter_obj::__CreateEmpty() { return  new Imposter_obj; }
hx::ObjectPtr< Imposter_obj > Imposter_obj::__new()
{  hx::ObjectPtr< Imposter_obj > result = new Imposter_obj();
	result->__construct();
	return result;}

Dynamic Imposter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Imposter_obj > result = new Imposter_obj();
	result->__construct();
	return result;}

Void Imposter_obj::increaserank( ){
{
		HX_STACK_FRAME("Imposter","increaserank",0x6c41012b,"Imposter.increaserank","Imposter.hx",60,0x381f6b8d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(61)
		hx::AddEq(this->accel,0.1);
		HX_STACK_LINE(62)
		hx::AddEq(this->mxspd,0.5);
		HX_STACK_LINE(63)
		hx::AddEq(this->pointvalue,(int)300);
		HX_STACK_LINE(64)
		hx::SubEq(this->mxcountdown,(int)5);
		HX_STACK_LINE(65)
		hx::SubEq(this->mxtimer,(int)60);
		HX_STACK_LINE(66)
		if (((this->mxcountdown < (int)15))){
			HX_STACK_LINE(68)
			this->mxcountdown = (int)15;
		}
		HX_STACK_LINE(70)
		if (((this->mxtimer < (int)150))){
			HX_STACK_LINE(72)
			this->mxtimer = (int)150;
		}
		HX_STACK_LINE(74)
		hx::SubEq(this->timer,(int)30);
		HX_STACK_LINE(75)
		if (((this->timer < (int)0))){
			HX_STACK_LINE(77)
			this->timer = (int)0;
		}
	}
return null();
}


Void Imposter_obj::update( ){
{
		HX_STACK_FRAME("Imposter","update",0x1d031906,"Imposter.update","Imposter.hx",81,0x381f6b8d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(82)
		if (((this->rng == null()))){
			HX_STACK_LINE(85)
			::MersenneTwister _g = ::MersenneTwister_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(85)
			this->rng = _g;
			HX_STACK_LINE(86)
			int seed = ::Math_obj::floor((this->UID * (int)100000));		HX_STACK_VAR(seed,"seed");
			HX_STACK_LINE(87)
			this->rng->seed = seed;
			HX_STACK_LINE(88)
			Array< int > _g1 = this->rng->twist(this->rng->seed,(int)1,this->mxtimer);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(88)
			int _g2 = _g1->__get((int)0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(88)
			int _g3 = (((int)60 + this->mxcountdown) + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(88)
			this->timer = _g3;
			HX_STACK_LINE(89)
			if (((bool((bool((bool((bool((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Cirno)) || bool((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Nue)))) || bool((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Yukari)))) || bool((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Seija)))) || bool((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Rumia))))){
				HX_STACK_LINE(91)
				this->hidden = true;
				HX_STACK_LINE(92)
				if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Cirno))){
					HX_STACK_LINE(94)
					this->rename = HX_CSTRING("cirno");
					HX_STACK_LINE(95)
					this->unlock = (int)4;
				}
				HX_STACK_LINE(97)
				if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Nue))){
					HX_STACK_LINE(99)
					this->rename = HX_CSTRING("nue");
					HX_STACK_LINE(100)
					this->unlock = (int)5;
				}
				HX_STACK_LINE(102)
				if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Seija))){
					HX_STACK_LINE(104)
					this->rename = HX_CSTRING("seija");
					HX_STACK_LINE(105)
					this->unlock = (int)2;
				}
				HX_STACK_LINE(107)
				if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Rumia))){
					HX_STACK_LINE(109)
					this->rename = HX_CSTRING("rumia");
					HX_STACK_LINE(110)
					this->unlock = (int)3;
				}
				HX_STACK_LINE(112)
				if (((::GameView_obj::_this->RoundType == ::TypeofRound_obj::Yukari))){
					HX_STACK_LINE(114)
					Array< int > _g4 = this->rng->twist(this->rng->seed,(int)1,(int)3);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(114)
					int A = _g4->__get((int)0);		HX_STACK_VAR(A,"A");
					HX_STACK_LINE(115)
					if (((A == (int)0))){
						HX_STACK_LINE(117)
						this->rename = HX_CSTRING("yukari");
						HX_STACK_LINE(118)
						this->unlock = (int)1;
					}
					HX_STACK_LINE(120)
					if (((A == (int)1))){
						HX_STACK_LINE(122)
						this->rename = HX_CSTRING("ran");
						HX_STACK_LINE(123)
						this->unlock = (int)7;
					}
					HX_STACK_LINE(125)
					if (((A == (int)2))){
						HX_STACK_LINE(127)
						this->rename = HX_CSTRING("chen");
						HX_STACK_LINE(128)
						this->unlock = (int)6;
					}
				}
				HX_STACK_LINE(131)
				this->have = ::Main_obj::_this->savedata->data->__Field(HX_CSTRING("hidden"),true)->__GetItem(this->unlock);
			}
			else{
				HX_STACK_LINE(135)
				Array< int > _g5 = this->rng->twist(this->rng->seed,(int)1,::Player_obj::characters->length);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(135)
				int _g6 = _g5->__get((int)0);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(135)
				this->unlock = _g6;
				HX_STACK_LINE(137)
				this->rename = ::Player_obj::characters->__get(this->unlock);
				HX_STACK_LINE(138)
				Array< int > _g7 = this->rng->twist(this->rng->seed,(int)1,(int)100);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(138)
				int _g8 = _g7->__get((int)0);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(138)
				if (((_g8 < (int)30))){
					HX_STACK_LINE(140)
					Array< ::Dynamic > A = ::GameView_obj::_this->AL->GetAnimation((this->rename + HX_CSTRING("ALT")));		HX_STACK_VAR(A,"A");
					HX_STACK_LINE(141)
					if (((bool((A != null())) && bool((A->length > (int)0))))){
						HX_STACK_LINE(143)
						this->rename = (this->rename + HX_CSTRING("ALT"));
						HX_STACK_LINE(144)
						this->alternate = true;
					}
				}
				HX_STACK_LINE(147)
				this->have = ::Main_obj::_this->savedata->data->__Field(HX_CSTRING("unlock"),true)->__GetItem(this->unlock);
				HX_STACK_LINE(148)
				if (((bool(!(this->have)) && bool(this->alternate)))){
					HX_STACK_LINE(150)
					this->have = ::Main_obj::_this->savedata->data->__Field(HX_CSTRING("alts"),true)->__GetItem(this->unlock);
				}
			}
		}
		HX_STACK_LINE(154)
		bool active = false;		HX_STACK_VAR(active,"active");
		HX_STACK_LINE(155)
		if (((bool((this->rank > (int)0)) && bool((this->flipped < (int)1))))){
			HX_STACK_LINE(157)
			if (((this->timer > (int)0))){
				HX_STACK_LINE(159)
				(this->timer)--;
			}
			else{
				HX_STACK_LINE(163)
				Float _g9 = this->get_x();		HX_STACK_VAR(_g9,"_g9");
				struct _Function_3_1{
					inline static bool Block( hx::ObjectPtr< ::Imposter_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Imposter.hx",163,0x381f6b8d)
						{
							HX_STACK_LINE(163)
							Float _g10 = __this->get_x();		HX_STACK_VAR(_g10,"_g10");
							HX_STACK_LINE(163)
							return (_g10 < (int)760);
						}
						return null();
					}
				};
				HX_STACK_LINE(163)
				if (((  (((  (((_g9 > (int)0))) ? bool(_Function_3_1::Block(this)) : bool(false) ))) ? bool((this->ground != null())) : bool(false) ))){
					HX_STACK_LINE(165)
					if (((this->countdown > (int)0))){
						HX_STACK_LINE(167)
						(this->countdown)--;
						HX_STACK_LINE(168)
						active = true;
					}
					else{
						HX_STACK_LINE(172)
						this->countdown = this->mxcountdown;
						HX_STACK_LINE(173)
						Array< int > _g11 = this->rng->twist(this->rng->seed,(int)1,this->mxtimer);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(173)
						int _g12 = _g11->__get((int)0);		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(173)
						int _g13 = (((int)60 + this->mxcountdown) + _g12);		HX_STACK_VAR(_g13,"_g13");
						HX_STACK_LINE(173)
						this->timer = _g13;
						HX_STACK_LINE(174)
						if ((::GameView_obj::_this->Hoster)){
							HX_STACK_LINE(176)
							::Player P = this->nearestplayer();		HX_STACK_VAR(P,"P");
							struct _Function_6_1{
								inline static Dynamic Block( ){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Imposter.hx",178,0x381f6b8d)
									{
										hx::Anon __result = hx::Anon_obj::Create();
										return __result;
									}
									return null();
								}
							};
							HX_STACK_LINE(178)
							Dynamic D = _Function_6_1::Block();		HX_STACK_VAR(D,"D");
							HX_STACK_LINE(179)
							Float _g14 = this->get_x();		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(179)
							D->__FieldRef(HX_CSTRING("x")) = _g14;
							HX_STACK_LINE(180)
							Float _g15 = this->get_y();		HX_STACK_VAR(_g15,"_g15");
							HX_STACK_LINE(180)
							D->__FieldRef(HX_CSTRING("y")) = _g15;
							HX_STACK_LINE(181)
							D->__FieldRef(HX_CSTRING("gravX")) = (int)0;
							HX_STACK_LINE(182)
							D->__FieldRef(HX_CSTRING("gravY")) = (int)0;
							HX_STACK_LINE(183)
							D->__FieldRef(HX_CSTRING("image")) = HX_CSTRING("bullet");
							HX_STACK_LINE(185)
							Float _g16 = P->get_y();		HX_STACK_VAR(_g16,"_g16");
							HX_STACK_LINE(185)
							Float _g17 = (_g16 + (int)30);		HX_STACK_VAR(_g17,"_g17");
							HX_STACK_LINE(185)
							Float _g18 = this->get_y();		HX_STACK_VAR(_g18,"_g18");
							HX_STACK_LINE(185)
							Float _g19 = (_g17 - _g18);		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(185)
							Float _g20 = P->get_x();		HX_STACK_VAR(_g20,"_g20");
							HX_STACK_LINE(185)
							Float _g21 = this->get_x();		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(185)
							Float _g22 = (_g20 - _g21);		HX_STACK_VAR(_g22,"_g22");
							HX_STACK_LINE(185)
							Float degradian = ::Math_obj::atan2(_g19,_g22);		HX_STACK_VAR(degradian,"degradian");
							HX_STACK_LINE(186)
							Float _g23 = ::Math_obj::cos(degradian);		HX_STACK_VAR(_g23,"_g23");
							HX_STACK_LINE(186)
							Float _g24 = (_g23 * (int)6);		HX_STACK_VAR(_g24,"_g24");
							HX_STACK_LINE(186)
							D->__FieldRef(HX_CSTRING("Hspeed")) = _g24;
							HX_STACK_LINE(187)
							Float _g25 = ::Math_obj::sin(degradian);		HX_STACK_VAR(_g25,"_g25");
							HX_STACK_LINE(187)
							Float _g26 = (_g25 * (int)6);		HX_STACK_VAR(_g26,"_g26");
							HX_STACK_LINE(187)
							D->__FieldRef(HX_CSTRING("Vspeed")) = _g26;
							HX_STACK_LINE(188)
							::GameView_obj::_this->SendEvent(HX_CSTRING("ShootBullet"),D);
						}
					}
				}
			}
		}
		else{
			HX_STACK_LINE(198)
			this->countdown = this->mxcountdown;
		}
		HX_STACK_LINE(200)
		(this->frames)++;
		HX_STACK_LINE(201)
		::String S = this->rename;		HX_STACK_VAR(S,"S");
		HX_STACK_LINE(202)
		this->visuallyEnraged = false;
		HX_STACK_LINE(203)
		if (((bool(active) && bool((((int(this->frames) & int((int)1))) < (int)1))))){
			HX_STACK_LINE(206)
			if ((this->enraged)){
				HX_STACK_LINE(208)
				S = (S + HX_CSTRING("S"));
			}
			else{
				HX_STACK_LINE(212)
				this->visuallyEnraged = true;
			}
			HX_STACK_LINE(214)
			this->Hspeed = (int)0;
		}
		else{
			HX_STACK_LINE(216)
			if (((bool((((int(this->frames) & int((int)1))) > (int)0)) && bool(!(this->have))))){
				HX_STACK_LINE(219)
				S = (S + HX_CSTRING("U"));
			}
			else{
				HX_STACK_LINE(221)
				if ((this->have)){
					HX_STACK_LINE(223)
					S = (S + HX_CSTRING("U"));
				}
			}
		}
		HX_STACK_LINE(225)
		this->enraged = false;
		HX_STACK_LINE(228)
		if ((!(this->killed))){
			HX_STACK_LINE(230)
			int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(231)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(233)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(234)
				this->dangerous = false;
				HX_STACK_LINE(235)
				if (((this->flipped == (int)0))){
					HX_STACK_LINE(237)
					this->flipped = (int)-1;
					HX_STACK_LINE(238)
					this->powerup();
				}
			}
			else{
				HX_STACK_LINE(243)
				this->dangerous = true;
			}
			HX_STACK_LINE(245)
			if ((!(active))){
				HX_STACK_LINE(247)
				if (((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
					HX_STACK_LINE(249)
					hx::AddEq(this->Hspeed,this->accel);
					HX_STACK_LINE(250)
					if (((this->Hspeed > this->mxspd))){
						HX_STACK_LINE(252)
						this->Hspeed = this->mxspd;
					}
				}
				HX_STACK_LINE(255)
				if (((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
					HX_STACK_LINE(257)
					hx::SubEq(this->Hspeed,this->accel);
					HX_STACK_LINE(258)
					if (((this->Hspeed < -(this->mxspd)))){
						HX_STACK_LINE(260)
						this->Hspeed = -(this->mxspd);
					}
				}
			}
			HX_STACK_LINE(264)
			int F = this->flipped;		HX_STACK_VAR(F,"F");
			HX_STACK_LINE(265)
			this->flipped = (int)0;
			HX_STACK_LINE(266)
			this->updphysics();
			HX_STACK_LINE(268)
			this->updateanimation(S);
			HX_STACK_LINE(269)
			this->flipped = F;
			HX_STACK_LINE(270)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(272)
				this->set_rotation((int)90);
			}
			else{
				HX_STACK_LINE(288)
				this->set_rotation((int)0);
			}
			HX_STACK_LINE(290)
			this->set_scaleX(0.8);
			HX_STACK_LINE(291)
			this->set_scaleY(0.8);
			HX_STACK_LINE(292)
			if (((this->ground != null()))){
				HX_STACK_LINE(295)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(298)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Imposter.hx",302,0x381f6b8d)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(302)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(303)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(304)
						Float _g27 = this->get_x();		HX_STACK_VAR(_g27,"_g27");
						HX_STACK_LINE(304)
						D->__FieldRef(HX_CSTRING("x")) = _g27;
						HX_STACK_LINE(305)
						Float _g28 = this->get_y();		HX_STACK_VAR(_g28,"_g28");
						HX_STACK_LINE(305)
						D->__FieldRef(HX_CSTRING("y")) = _g28;
						HX_STACK_LINE(306)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(307)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(309)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(315)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(318)
						this->Vspeed = (int)-4;
						HX_STACK_LINE(319)
						this->HP = (int)0;
					}
				}
			}
			HX_STACK_LINE(325)
			Float _g29 = this->get_y();		HX_STACK_VAR(_g29,"_g29");
			struct _Function_2_1{
				inline static bool Block( hx::ObjectPtr< ::Imposter_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Imposter.hx",325,0x381f6b8d)
					{
						HX_STACK_LINE(325)
						Float _g30 = __this->get_y();		HX_STACK_VAR(_g30,"_g30");
						HX_STACK_LINE(325)
						return (_g30 > (int)800);
					}
					return null();
				}
			};
			HX_STACK_LINE(325)
			if (((  ((!(((  (((_g29 > (int)408))) ? bool(this->wrapped) : bool(false) ))))) ? bool(_Function_2_1::Block(this)) : bool(true) ))){
				HX_STACK_LINE(327)
				this->alive = false;
				HX_STACK_LINE(328)
				this->set_visible(false);
			}
			HX_STACK_LINE(330)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(334)
			{
				HX_STACK_LINE(334)
				::Imposter _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(334)
				Float _g31 = _g->get_y();		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(334)
				Float _g32 = (_g31 + (int)15);		HX_STACK_VAR(_g32,"_g32");
				HX_STACK_LINE(334)
				_g->set_y(_g32);
			}
			HX_STACK_LINE(335)
			Float _g33 = this->get_y();		HX_STACK_VAR(_g33,"_g33");
			HX_STACK_LINE(335)
			if (((_g33 > (int)600))){
				HX_STACK_LINE(337)
				this->alive = false;
			}
		}
	}
return null();
}


Void Imposter_obj::bump( ){
{
		HX_STACK_FRAME("Imposter","bump",0x0b81f9b3,"Imposter.bump","Imposter.hx",344,0x381f6b8d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(344)
		if (((this->HP > (int)0))){
			HX_STACK_LINE(346)
			(this->HP)--;
		}
		else{
			HX_STACK_LINE(350)
			if (((this->flipped < (int)1))){
				HX_STACK_LINE(352)
				if ((this->enraged)){
					HX_STACK_LINE(354)
					this->flipped = (int)120;
				}
				else{
					HX_STACK_LINE(358)
					this->flipped = (int)210;
				}
			}
			else{
				HX_STACK_LINE(363)
				this->flipped = (int)0;
				HX_STACK_LINE(364)
				this->HP = (int)0;
			}
		}
	}
return null();
}



Imposter_obj::Imposter_obj()
{
}

void Imposter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Imposter);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(rename,"rename");
	HX_MARK_MEMBER_NAME(frames,"frames");
	HX_MARK_MEMBER_NAME(unlock,"unlock");
	HX_MARK_MEMBER_NAME(have,"have");
	HX_MARK_MEMBER_NAME(alternate,"alternate");
	HX_MARK_MEMBER_NAME(hidden,"hidden");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(countdown,"countdown");
	HX_MARK_MEMBER_NAME(mxcountdown,"mxcountdown");
	HX_MARK_MEMBER_NAME(mxtimer,"mxtimer");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Imposter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(rename,"rename");
	HX_VISIT_MEMBER_NAME(frames,"frames");
	HX_VISIT_MEMBER_NAME(unlock,"unlock");
	HX_VISIT_MEMBER_NAME(have,"have");
	HX_VISIT_MEMBER_NAME(alternate,"alternate");
	HX_VISIT_MEMBER_NAME(hidden,"hidden");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(countdown,"countdown");
	HX_VISIT_MEMBER_NAME(mxcountdown,"mxcountdown");
	HX_VISIT_MEMBER_NAME(mxtimer,"mxtimer");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Imposter_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"frames") ) { return frames; }
		if (HX_FIELD_EQ(inName,"unlock") ) { return unlock; }
		if (HX_FIELD_EQ(inName,"hidden") ) { return hidden; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mxtimer") ) { return mxtimer; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alternate") ) { return alternate; }
		if (HX_FIELD_EQ(inName,"countdown") ) { return countdown; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mxcountdown") ) { return mxcountdown; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"increaserank") ) { return increaserank_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Imposter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"frames") ) { frames=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"unlock") ) { unlock=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hidden") ) { hidden=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mxtimer") ) { mxtimer=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"alternate") ) { alternate=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"countdown") ) { countdown=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"mxcountdown") ) { mxcountdown=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Imposter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("rename"));
	outFields->push(HX_CSTRING("frames"));
	outFields->push(HX_CSTRING("unlock"));
	outFields->push(HX_CSTRING("have"));
	outFields->push(HX_CSTRING("alternate"));
	outFields->push(HX_CSTRING("hidden"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("countdown"));
	outFields->push(HX_CSTRING("mxcountdown"));
	outFields->push(HX_CSTRING("mxtimer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Imposter_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Imposter_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(Imposter_obj,rng),HX_CSTRING("rng")},
	{hx::fsString,(int)offsetof(Imposter_obj,rename),HX_CSTRING("rename")},
	{hx::fsInt,(int)offsetof(Imposter_obj,frames),HX_CSTRING("frames")},
	{hx::fsInt,(int)offsetof(Imposter_obj,unlock),HX_CSTRING("unlock")},
	{hx::fsBool,(int)offsetof(Imposter_obj,have),HX_CSTRING("have")},
	{hx::fsBool,(int)offsetof(Imposter_obj,alternate),HX_CSTRING("alternate")},
	{hx::fsBool,(int)offsetof(Imposter_obj,hidden),HX_CSTRING("hidden")},
	{hx::fsInt,(int)offsetof(Imposter_obj,timer),HX_CSTRING("timer")},
	{hx::fsInt,(int)offsetof(Imposter_obj,countdown),HX_CSTRING("countdown")},
	{hx::fsInt,(int)offsetof(Imposter_obj,mxcountdown),HX_CSTRING("mxcountdown")},
	{hx::fsInt,(int)offsetof(Imposter_obj,mxtimer),HX_CSTRING("mxtimer")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("rng"),
	HX_CSTRING("rename"),
	HX_CSTRING("frames"),
	HX_CSTRING("unlock"),
	HX_CSTRING("have"),
	HX_CSTRING("alternate"),
	HX_CSTRING("hidden"),
	HX_CSTRING("timer"),
	HX_CSTRING("countdown"),
	HX_CSTRING("mxcountdown"),
	HX_CSTRING("mxtimer"),
	HX_CSTRING("increaserank"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Imposter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Imposter_obj::__mClass,"__mClass");
};

#endif

Class Imposter_obj::__mClass;

void Imposter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Imposter"), hx::TCanCast< Imposter_obj> ,sStaticFields,sMemberFields,
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

void Imposter_obj::__boot()
{
}

