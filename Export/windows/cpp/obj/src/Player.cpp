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
#ifndef INCLUDED_EntityItem
#include <EntityItem.h>
#endif
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
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
#ifndef INCLUDED_openfl__v2_display_BlendMode
#include <openfl/_v2/display/BlendMode.h>
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
#ifndef INCLUDED_openfl__v2_media_SoundChannel
#include <openfl/_v2/media/SoundChannel.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextFormat
#include <openfl/_v2/text/TextFormat.h>
#endif

Void Player_obj::__construct(::String charname,Array< bool > controller)
{
HX_STACK_FRAME("Player","new",0x8d5554f3,"Player.new","Player.hx",51,0xa27fc9dd)
HX_STACK_THIS(this)
HX_STACK_ARG(charname,"charname")
HX_STACK_ARG(controller,"controller")
{
	HX_STACK_LINE(52)
	super::__construct(charname);
	HX_STACK_LINE(53)
	this->type = HX_CSTRING("Player");
	HX_STACK_LINE(54)
	this->charname = charname;
	HX_STACK_LINE(55)
	this->controller = controller;
	HX_STACK_LINE(58)
	this->deccel = 0.4;
	HX_STACK_LINE(60)
	this->accel = (0.7 + this->deccel);
	HX_STACK_LINE(62)
	this->Haccel = (this->accel * 0.35);
	HX_STACK_LINE(63)
	this->Hdeccel = (this->deccel * 0.35);
	HX_STACK_LINE(66)
	this->mxspd = (int)7;
	HX_STACK_LINE(67)
	this->killed = false;
	HX_STACK_LINE(68)
	this->lives = (int)3;
	HX_STACK_LINE(69)
	this->ID = HX_CSTRING("");
	HX_STACK_LINE(70)
	this->score = (int)0;
	HX_STACK_LINE(71)
	this->steps = (int)0;
	HX_STACK_LINE(72)
	this->invincibility = (int)0;
	HX_STACK_LINE(74)
	this->fallaccel = 1.0;
	HX_STACK_LINE(75)
	this->playername = HX_CSTRING("");
	HX_STACK_LINE(76)
	::openfl::_v2::text::TextField _g = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(76)
	this->nameplate = _g;
	HX_STACK_LINE(78)
	this->nameplate->set_x((int)100);
	HX_STACK_LINE(79)
	this->nameplate->set_y((int)100);
	HX_STACK_LINE(80)
	::openfl::_v2::text::TextFormat _g1 = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(80)
	this->format = _g1;
	HX_STACK_LINE(81)
	this->format->font = HX_CSTRING("Arial");
	HX_STACK_LINE(82)
	this->format->size = (int)16;
	HX_STACK_LINE(83)
	this->format->color = (int)16777215;
	HX_STACK_LINE(84)
	this->nameplate->set_mouseEnabled(false);
	HX_STACK_LINE(86)
	this->nameplate->setTextFormat(this->format,null(),null());
	HX_STACK_LINE(87)
	::GameView_obj::_this->addChild(this->nameplate);
	HX_STACK_LINE(88)
	this->frame = ::GameView_obj::_this->frame;
}
;
	return null();
}

//Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hx::ObjectPtr< Player_obj > Player_obj::__new(::String charname,Array< bool > controller)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(charname,controller);
	return result;}

Dynamic Player_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Player_obj::update( ){
{
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",95,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(96)
		if (((bool(!(this->killed)) && bool((this->lives > (int)-1))))){
			HX_STACK_LINE(98)
			Float DCL = this->deccel;		HX_STACK_VAR(DCL,"DCL");
			HX_STACK_LINE(99)
			if (((bool((this->ground != null())) && bool(this->ground->icy)))){
				HX_STACK_LINE(101)
				this->deccel = this->Hdeccel;
			}
			HX_STACK_LINE(103)
			this->updphysics();
			HX_STACK_LINE(104)
			this->deccel = DCL;
			HX_STACK_LINE(113)
			if ((!(this->catchingup))){
				HX_STACK_LINE(115)
				if (((this->invincibility > (int)0))){
					HX_STACK_LINE(117)
					this->set_visible((((int(this->invincibility) & int((int)1))) > (int)0));
					HX_STACK_LINE(118)
					hx::SubEq(this->invincibility,(int)1);
				}
				else{
					HX_STACK_LINE(122)
					this->set_visible(true);
				}
			}
			HX_STACK_LINE(125)
			Float _g = this->get_rotation();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(125)
			if (((_g != (int)0))){
				HX_STACK_LINE(127)
				this->set_rotation((int)0);
			}
			HX_STACK_LINE(129)
			if (((bool((this->Hspeed < this->mxspd)) && bool(this->controller->__get((int)3))))){
				HX_STACK_LINE(131)
				if (((bool((this->ground != null())) && bool(this->ground->icy)))){
					HX_STACK_LINE(134)
					hx::AddEq(this->Hspeed,this->Haccel);
				}
				else{
					HX_STACK_LINE(138)
					hx::AddEq(this->Hspeed,this->accel);
				}
				HX_STACK_LINE(140)
				if (((this->Hspeed > this->mxspd))){
					HX_STACK_LINE(142)
					this->Hspeed = this->mxspd;
				}
			}
			HX_STACK_LINE(145)
			if (((bool((this->Hspeed > -(this->mxspd))) && bool(this->controller->__get((int)2))))){
				HX_STACK_LINE(147)
				if (((bool((this->ground != null())) && bool(this->ground->icy)))){
					HX_STACK_LINE(150)
					hx::SubEq(this->Hspeed,this->Haccel);
				}
				else{
					HX_STACK_LINE(154)
					hx::SubEq(this->Hspeed,this->accel);
				}
				HX_STACK_LINE(156)
				if (((this->Hspeed < -(this->mxspd)))){
					HX_STACK_LINE(158)
					this->Hspeed = -(this->mxspd);
				}
			}
			HX_STACK_LINE(162)
			if (((bool((this->ground != null())) && bool((this->Vspeed == (int)0))))){
				HX_STACK_LINE(164)
				if ((!(this->catchingup))){
					HX_STACK_LINE(166)
					Float _g1 = ::Math_obj::abs(this->Hspeed);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(166)
					hx::AddEq(this->steps,_g1);
					HX_STACK_LINE(167)
					if (((this->steps > (int)35))){
						HX_STACK_LINE(169)
						hx::SubEq(this->steps,(int)35);
						HX_STACK_LINE(170)
						Float _g2 = ::Math_obj::random();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(170)
						Float _g3 = (_g2 * (int)3);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(170)
						int _g4 = ::Math_obj::ceil(_g3);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(170)
						::String S = (HX_CSTRING("step") + _g4);		HX_STACK_VAR(S,"S");
						HX_STACK_LINE(171)
						::SoundManager_obj::Play(S);
						HX_STACK_LINE(172)
						Float _g5 = this->get_rotation();		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(172)
						if (((_g5 != (int)0))){
						}
						else{
							HX_STACK_LINE(178)
							{
								HX_STACK_LINE(178)
								::Player _g6 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g6,"_g6");
								HX_STACK_LINE(178)
								Float _g61 = _g6->get_y();		HX_STACK_VAR(_g61,"_g61");
								HX_STACK_LINE(178)
								Float _g7 = (_g61 - (int)2);		HX_STACK_VAR(_g7,"_g7");
								HX_STACK_LINE(178)
								_g6->set_y(_g7);
							}
							HX_STACK_LINE(180)
							if (((this->Hspeed > (int)0))){
							}
							else{
							}
						}
					}
				}
			}
			HX_STACK_LINE(192)
			if (((this->Hspeed > (int)0))){
				HX_STACK_LINE(194)
				Array< ::Dynamic > _g8 = ::GameView_obj::_this->AL->GetAnimation(this->charname);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(194)
				this->ChangeAnimation(_g8);
			}
			HX_STACK_LINE(196)
			if (((this->Hspeed < (int)0))){
				HX_STACK_LINE(198)
				Array< ::Dynamic > _g9 = ::GameView_obj::_this->AL->GetAnimation((this->charname + HX_CSTRING("F")));		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(198)
				this->ChangeAnimation(_g9);
			}
			HX_STACK_LINE(201)
			if (((this->ground != null()))){
				HX_STACK_LINE(203)
				if (((this->ground->bonked > (int)-1000))){
					HX_STACK_LINE(205)
					this->Vspeed = (int)-4;
				}
				else{
					HX_STACK_LINE(209)
					if (((bool(this->controller->__get((int)1)) && bool((this->Vspeed == (int)0))))){
						HX_STACK_LINE(212)
						this->Vspeed = (int)-19;
					}
				}
				HX_STACK_LINE(215)
				if ((this->ground->dangerous)){
					HX_STACK_LINE(218)
					if (((this->invincibility <= (int)0))){
						HX_STACK_LINE(220)
						::GameView_obj::_this->SendEvent(HX_CSTRING("PlayerDeath"),null());
					}
				}
			}
			HX_STACK_LINE(226)
			if (((bool((bool((bool((this->headbonk != null())) && bool((hx::ObjectPtr<OBJ_>(this) == ::GameView_obj::_this->myplayer)))) && bool((this->headbonk->bonked == (int)-1000)))) && bool(((bool((::GameView_obj::_this->RoundType != ::TypeofRound_obj::Table)) || bool((this->headbonk->type != HX_CSTRING("Block"))))))))){
				HX_STACK_LINE(229)
				::GameView_obj::_this->SendEvent(HX_CSTRING("Headbonk"),this->headbonk->UID);
			}
			HX_STACK_LINE(231)
			if (((hx::ObjectPtr<OBJ_>(this) == ::GameView_obj::_this->myplayer))){
				HX_STACK_LINE(234)
				Float _g10 = this->get_width();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(234)
				int _g11 = ::Math_obj::round(_g10);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(234)
				int W = (int(_g11) >> int((int)1));		HX_STACK_VAR(W,"W");
				HX_STACK_LINE(235)
				Float _g12 = this->get_height();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(235)
				int _g13 = ::Math_obj::round(_g12);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(235)
				int H = (int(_g13) >> int((int)2));		HX_STACK_VAR(H,"H");
				HX_STACK_LINE(236)
				Float _g14 = this->get_x();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(236)
				Float _g15 = (_g14 + W);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(236)
				Float _g16 = this->get_y();		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(236)
				Float _g17 = this->get_height();		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(236)
				Float _g18 = (_g17 - H);		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(236)
				Float _g19 = (_g16 + _g18);		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(236)
				::Entity danger = ::GameView_obj::_this->CollisionDetectPointDangerous(_g15,_g19);		HX_STACK_VAR(danger,"danger");
				HX_STACK_LINE(237)
				Float _g20 = this->get_x();		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(237)
				Float _g21 = (_g20 + W);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(237)
				Float _g22 = this->get_y();		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(237)
				Float _g23 = this->get_height();		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(237)
				Float _g24 = (_g23 - H);		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(237)
				Float _g25 = (_g22 + _g24);		HX_STACK_VAR(_g25,"_g25");
				HX_STACK_LINE(237)
				::Enemy enemy = ::GameView_obj::_this->CollisionDetectPointEnemy(_g21,_g25);		HX_STACK_VAR(enemy,"enemy");
				HX_STACK_LINE(238)
				Float _g26 = this->get_x();		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(238)
				Float _g27 = (_g26 + W);		HX_STACK_VAR(_g27,"_g27");
				HX_STACK_LINE(238)
				Float _g28 = this->get_y();		HX_STACK_VAR(_g28,"_g28");
				HX_STACK_LINE(238)
				Float _g29 = this->get_height();		HX_STACK_VAR(_g29,"_g29");
				HX_STACK_LINE(238)
				Float _g30 = (_g29 - H);		HX_STACK_VAR(_g30,"_g30");
				HX_STACK_LINE(238)
				Float _g31 = (_g28 + _g30);		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(238)
				::EntityItem eItem = ::GameView_obj::_this->CollisionDetectPointItem(_g27,_g31);		HX_STACK_VAR(eItem,"eItem");
				HX_STACK_LINE(240)
				if (((eItem != null()))){
					HX_STACK_LINE(242)
					::GameView_obj::_this->SendEvent(HX_CSTRING("Collect"),eItem->UID);
				}
				HX_STACK_LINE(244)
				if (((bool((danger != null())) && bool((this->lives >= (int)0))))){
					HX_STACK_LINE(252)
					if (((this->invincibility <= (int)0))){
						HX_STACK_LINE(254)
						::GameView_obj::_this->SendEvent(HX_CSTRING("PlayerDeath"),null());
					}
				}
				HX_STACK_LINE(258)
				if (((bool((enemy != null())) && bool((this->lives >= (int)0))))){
					HX_STACK_LINE(260)
					if ((enemy->killable)){
						HX_STACK_LINE(262)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Kill"),enemy->UID);
					}
				}
			}
		}
		else{
			HX_STACK_LINE(276)
			Float _g32 = this->get_rotation();		HX_STACK_VAR(_g32,"_g32");
			HX_STACK_LINE(276)
			if (((_g32 == (int)0))){
				HX_STACK_LINE(278)
				this->set_rotation((int)90);
				HX_STACK_LINE(279)
				{
					HX_STACK_LINE(279)
					::Player _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(279)
					Float _g33 = _g->get_x();		HX_STACK_VAR(_g33,"_g33");
					HX_STACK_LINE(279)
					Float _g34 = this->get_height();		HX_STACK_VAR(_g34,"_g34");
					HX_STACK_LINE(279)
					int _g35 = ::Math_obj::floor(_g34);		HX_STACK_VAR(_g35,"_g35");
					HX_STACK_LINE(279)
					int _g36 = (int(_g35) >> int((int)1));		HX_STACK_VAR(_g36,"_g36");
					HX_STACK_LINE(279)
					Float _g37 = (_g33 + _g36);		HX_STACK_VAR(_g37,"_g37");
					HX_STACK_LINE(279)
					_g->set_x(_g37);
				}
			}
			HX_STACK_LINE(281)
			if (((this->lives > (int)-1))){
				HX_STACK_LINE(283)
				hx::AddEq(this->Vspeed,0.5);
				HX_STACK_LINE(284)
				if (((this->Vspeed > (int)20))){
					HX_STACK_LINE(286)
					this->Vspeed = (int)20;
				}
				HX_STACK_LINE(288)
				{
					HX_STACK_LINE(288)
					::Player _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(288)
					Float _g38 = _g->get_y();		HX_STACK_VAR(_g38,"_g38");
					HX_STACK_LINE(288)
					Float _g39 = (_g38 + this->Vspeed);		HX_STACK_VAR(_g39,"_g39");
					HX_STACK_LINE(288)
					_g->set_y(_g39);
				}
				HX_STACK_LINE(289)
				Float _g40 = this->get_y();		HX_STACK_VAR(_g40,"_g40");
				HX_STACK_LINE(289)
				if (((  (((_g40 > (int)600))) ? bool((hx::ObjectPtr<OBJ_>(this) == ::GameView_obj::_this->myplayer)) : bool(false) ))){
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",292,0xa27fc9dd)
							{
								hx::Anon __result = hx::Anon_obj::Create();
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(292)
					Dynamic D = _Function_4_1::Block();		HX_STACK_VAR(D,"D");
					HX_STACK_LINE(293)
					D->__FieldRef(HX_CSTRING("x")) = (int)400;
					HX_STACK_LINE(294)
					D->__FieldRef(HX_CSTRING("y")) = (int)0;
					HX_STACK_LINE(295)
					D->__FieldRef(HX_CSTRING("lives")) = (this->lives - (int)1);
					HX_STACK_LINE(296)
					::GameView_obj::_this->SendEvent(HX_CSTRING("PlayerRespawn"),D);
				}
			}
		}
		HX_STACK_LINE(302)
		if (((::GameView_obj::_this->myplayer != hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(305)
			if ((((::GameView_obj::_this->frame - this->frame) > (int)600))){
				HX_STACK_LINE(311)
				this->set_blendMode(::openfl::_v2::display::BlendMode_obj::SCREEN);
			}
			else{
				HX_STACK_LINE(315)
				this->set_blendMode(::openfl::_v2::display::BlendMode_obj::NORMAL);
			}
		}
		HX_STACK_LINE(320)
		if (((  (((bool((this->playername != HX_CSTRING(""))) && bool(::GameView_obj::_this->online)))) ? bool(this->get_visible()) : bool(false) ))){
			HX_STACK_LINE(322)
			this->nameplate->set_visible(true);
			HX_STACK_LINE(323)
			if (((this->playername != HX_CSTRING("PlayerName")))){
				HX_STACK_LINE(325)
				this->nameplate->set_text((HX_CSTRING("") + this->playername));
			}
			else{
				HX_STACK_LINE(329)
				this->nameplate->set_text(HX_CSTRING("???"));
			}
			HX_STACK_LINE(332)
			this->nameplate->setTextFormat(this->format,null(),null());
			HX_STACK_LINE(333)
			::openfl::_v2::geom::Rectangle B = this->getBounds(::GameView_obj::_this);		HX_STACK_VAR(B,"B");
			HX_STACK_LINE(334)
			Float _g41 = B->get_left();		HX_STACK_VAR(_g41,"_g41");
			HX_STACK_LINE(334)
			Float _g42 = this->nameplate->get_textWidth();		HX_STACK_VAR(_g42,"_g42");
			HX_STACK_LINE(334)
			int _g43 = ::Math_obj::floor(_g42);		HX_STACK_VAR(_g43,"_g43");
			HX_STACK_LINE(334)
			int _g44 = (int(_g43) >> int((int)1));		HX_STACK_VAR(_g44,"_g44");
			HX_STACK_LINE(334)
			Float _g45 = (_g41 - _g44);		HX_STACK_VAR(_g45,"_g45");
			HX_STACK_LINE(334)
			int _g46 = ::Math_obj::floor(B->width);		HX_STACK_VAR(_g46,"_g46");
			HX_STACK_LINE(334)
			int _g47 = (int(_g46) >> int((int)1));		HX_STACK_VAR(_g47,"_g47");
			HX_STACK_LINE(334)
			Float _g48 = (_g45 + _g47);		HX_STACK_VAR(_g48,"_g48");
			HX_STACK_LINE(334)
			this->nameplate->set_x(_g48);
			HX_STACK_LINE(335)
			Float _g49 = B->get_top();		HX_STACK_VAR(_g49,"_g49");
			HX_STACK_LINE(335)
			Float _g50 = (_g49 - (int)20);		HX_STACK_VAR(_g50,"_g50");
			HX_STACK_LINE(335)
			this->nameplate->set_y(_g50);
		}
		else{
			HX_STACK_LINE(347)
			this->nameplate->set_visible(false);
		}
		HX_STACK_LINE(349)
		if (((this->Hspeed > (int)0))){
			HX_STACK_LINE(351)
			this->Ldir = (int)1;
		}
		HX_STACK_LINE(353)
		if (((this->Hspeed < (int)0))){
			HX_STACK_LINE(355)
			this->Ldir = (int)-1;
		}
	}
return null();
}


Array< ::String > Player_obj::characters;

Array< ::String > Player_obj::hiddencharacters;

::String Player_obj::getRandomCharacter( ){
	HX_STACK_FRAME("Player","getRandomCharacter",0x8bc0f9fd,"Player.getRandomCharacter","Player.hx",45,0xa27fc9dd)
	HX_STACK_LINE(46)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(46)
	Float _g1 = (_g * ::Player_obj::characters->length);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(46)
	int _g2 = ::Math_obj::floor(_g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(46)
	return ::Player_obj::characters->__get(_g2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Player_obj,getRandomCharacter,return )


Player_obj::Player_obj()
{
}

void Player_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Player);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(Haccel,"Haccel");
	HX_MARK_MEMBER_NAME(Hdeccel,"Hdeccel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(controller,"controller");
	HX_MARK_MEMBER_NAME(charname,"charname");
	HX_MARK_MEMBER_NAME(lives,"lives");
	HX_MARK_MEMBER_NAME(ID,"ID");
	HX_MARK_MEMBER_NAME(score,"score");
	HX_MARK_MEMBER_NAME(spentscore,"spentscore");
	HX_MARK_MEMBER_NAME(steps,"steps");
	HX_MARK_MEMBER_NAME(invincibility,"invincibility");
	HX_MARK_MEMBER_NAME(playername,"playername");
	HX_MARK_MEMBER_NAME(nameplate,"nameplate");
	HX_MARK_MEMBER_NAME(format,"format");
	HX_MARK_MEMBER_NAME(frame,"frame");
	::Entity_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Player_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(Haccel,"Haccel");
	HX_VISIT_MEMBER_NAME(Hdeccel,"Hdeccel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(controller,"controller");
	HX_VISIT_MEMBER_NAME(charname,"charname");
	HX_VISIT_MEMBER_NAME(lives,"lives");
	HX_VISIT_MEMBER_NAME(ID,"ID");
	HX_VISIT_MEMBER_NAME(score,"score");
	HX_VISIT_MEMBER_NAME(spentscore,"spentscore");
	HX_VISIT_MEMBER_NAME(steps,"steps");
	HX_VISIT_MEMBER_NAME(invincibility,"invincibility");
	HX_VISIT_MEMBER_NAME(playername,"playername");
	HX_VISIT_MEMBER_NAME(nameplate,"nameplate");
	HX_VISIT_MEMBER_NAME(format,"format");
	HX_VISIT_MEMBER_NAME(frame,"frame");
	::Entity_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { return ID; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { return accel; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { return mxspd; }
		if (HX_FIELD_EQ(inName,"lives") ) { return lives; }
		if (HX_FIELD_EQ(inName,"score") ) { return score; }
		if (HX_FIELD_EQ(inName,"steps") ) { return steps; }
		if (HX_FIELD_EQ(inName,"frame") ) { return frame; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Haccel") ) { return Haccel; }
		if (HX_FIELD_EQ(inName,"format") ) { return format; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Hdeccel") ) { return Hdeccel; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"charname") ) { return charname; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nameplate") ) { return nameplate; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"characters") ) { return characters; }
		if (HX_FIELD_EQ(inName,"controller") ) { return controller; }
		if (HX_FIELD_EQ(inName,"spentscore") ) { return spentscore; }
		if (HX_FIELD_EQ(inName,"playername") ) { return playername; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"invincibility") ) { return invincibility; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hiddencharacters") ) { return hiddencharacters; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getRandomCharacter") ) { return getRandomCharacter_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ID") ) { ID=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { accel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { mxspd=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lives") ) { lives=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"score") ) { score=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"steps") ) { steps=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frame") ) { frame=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Haccel") ) { Haccel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"format") ) { format=inValue.Cast< ::openfl::_v2::text::TextFormat >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Hdeccel") ) { Hdeccel=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"charname") ) { charname=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nameplate") ) { nameplate=inValue.Cast< ::openfl::_v2::text::TextField >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"characters") ) { characters=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"controller") ) { controller=inValue.Cast< Array< bool > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"spentscore") ) { spentscore=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"playername") ) { playername=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"invincibility") ) { invincibility=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"hiddencharacters") ) { hiddencharacters=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Player_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("Haccel"));
	outFields->push(HX_CSTRING("Hdeccel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("controller"));
	outFields->push(HX_CSTRING("charname"));
	outFields->push(HX_CSTRING("lives"));
	outFields->push(HX_CSTRING("ID"));
	outFields->push(HX_CSTRING("score"));
	outFields->push(HX_CSTRING("spentscore"));
	outFields->push(HX_CSTRING("steps"));
	outFields->push(HX_CSTRING("invincibility"));
	outFields->push(HX_CSTRING("playername"));
	outFields->push(HX_CSTRING("nameplate"));
	outFields->push(HX_CSTRING("format"));
	outFields->push(HX_CSTRING("frame"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("characters"),
	HX_CSTRING("hiddencharacters"),
	HX_CSTRING("getRandomCharacter"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Player_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Player_obj,Haccel),HX_CSTRING("Haccel")},
	{hx::fsFloat,(int)offsetof(Player_obj,Hdeccel),HX_CSTRING("Hdeccel")},
	{hx::fsFloat,(int)offsetof(Player_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(Player_obj,controller),HX_CSTRING("controller")},
	{hx::fsString,(int)offsetof(Player_obj,charname),HX_CSTRING("charname")},
	{hx::fsInt,(int)offsetof(Player_obj,lives),HX_CSTRING("lives")},
	{hx::fsString,(int)offsetof(Player_obj,ID),HX_CSTRING("ID")},
	{hx::fsInt,(int)offsetof(Player_obj,score),HX_CSTRING("score")},
	{hx::fsInt,(int)offsetof(Player_obj,spentscore),HX_CSTRING("spentscore")},
	{hx::fsFloat,(int)offsetof(Player_obj,steps),HX_CSTRING("steps")},
	{hx::fsInt,(int)offsetof(Player_obj,invincibility),HX_CSTRING("invincibility")},
	{hx::fsString,(int)offsetof(Player_obj,playername),HX_CSTRING("playername")},
	{hx::fsObject /*::openfl::_v2::text::TextField*/ ,(int)offsetof(Player_obj,nameplate),HX_CSTRING("nameplate")},
	{hx::fsObject /*::openfl::_v2::text::TextFormat*/ ,(int)offsetof(Player_obj,format),HX_CSTRING("format")},
	{hx::fsInt,(int)offsetof(Player_obj,frame),HX_CSTRING("frame")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("Haccel"),
	HX_CSTRING("Hdeccel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("controller"),
	HX_CSTRING("charname"),
	HX_CSTRING("lives"),
	HX_CSTRING("ID"),
	HX_CSTRING("score"),
	HX_CSTRING("spentscore"),
	HX_CSTRING("steps"),
	HX_CSTRING("invincibility"),
	HX_CSTRING("playername"),
	HX_CSTRING("nameplate"),
	HX_CSTRING("format"),
	HX_CSTRING("frame"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Player_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Player_obj::characters,"characters");
	HX_MARK_MEMBER_NAME(Player_obj::hiddencharacters,"hiddencharacters");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Player_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Player_obj::characters,"characters");
	HX_VISIT_MEMBER_NAME(Player_obj::hiddencharacters,"hiddencharacters");
};

#endif

Class Player_obj::__mClass;

void Player_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Player"), hx::TCanCast< Player_obj> ,sStaticFields,sMemberFields,
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

void Player_obj::__boot()
{
	characters= Array_obj< ::String >::__new().Add(HX_CSTRING("reimu")).Add(HX_CSTRING("marisa")).Add(HX_CSTRING("patchouli")).Add(HX_CSTRING("remilia")).Add(HX_CSTRING("sanae")).Add(HX_CSTRING("sakuya")).Add(HX_CSTRING("suwako")).Add(HX_CSTRING("yuyuko")).Add(HX_CSTRING("tenshi")).Add(HX_CSTRING("iku")).Add(HX_CSTRING("aya")).Add(HX_CSTRING("alice")).Add(HX_CSTRING("youmu")).Add(HX_CSTRING("shikieiki")).Add(HX_CSTRING("flandre")).Add(HX_CSTRING("satori")).Add(HX_CSTRING("koishi")).Add(HX_CSTRING("momiji")).Add(HX_CSTRING("nitori")).Add(HX_CSTRING("reisen")).Add(HX_CSTRING("komachi")).Add(HX_CSTRING("yuuka")).Add(HX_CSTRING("mokou")).Add(HX_CSTRING("meiling")).Add(HX_CSTRING("parsee")).Add(HX_CSTRING("kokoro")).Add(HX_CSTRING("kogasa")).Add(HX_CSTRING("kasen")).Add(HX_CSTRING("utsuho")).Add(HX_CSTRING("suika")).Add(HX_CSTRING("kaguya")).Add(HX_CSTRING("eirin")).Add(HX_CSTRING("nazrin")).Add(HX_CSTRING("orin")).Add(HX_CSTRING("hina")).Add(HX_CSTRING("byakuren")).Add(HX_CSTRING("chiyuri")).Add(HX_CSTRING("ellen")).Add(HX_CSTRING("elly")).Add(HX_CSTRING("gengetsu")).Add(HX_CSTRING("kana")).Add(HX_CSTRING("kotohime")).Add(HX_CSTRING("kurumi")).Add(HX_CSTRING("luize")).Add(HX_CSTRING("mai")).Add(HX_CSTRING("meira")).Add(HX_CSTRING("mugetsu")).Add(HX_CSTRING("orange")).Add(HX_CSTRING("rika")).Add(HX_CSTRING("rikako")).Add(HX_CSTRING("sarah")).Add(HX_CSTRING("yuki")).Add(HX_CSTRING("yumeko")).Add(HX_CSTRING("yumemi")).Add(HX_CSTRING("akyu")).Add(HX_CSTRING("futo")).Add(HX_CSTRING("kagerou")).Add(HX_CSTRING("keine")).Add(HX_CSTRING("kosuzu")).Add(HX_CSTRING("lunachild")).Add(HX_CSTRING("mamizou")).Add(HX_CSTRING("medicine")).Add(HX_CSTRING("minoriko")).Add(HX_CSTRING("murasa")).Add(HX_CSTRING("seiga")).Add(HX_CSTRING("sekibanki")).Add(HX_CSTRING("shanghai")).Add(HX_CSTRING("shinmyoumaru")).Add(HX_CSTRING("shizuha")).Add(HX_CSTRING("shou")).Add(HX_CSTRING("sunnymilk")).Add(HX_CSTRING("tokiko")).Add(HX_CSTRING("wriggle")).Add(HX_CSTRING("yoshika")).Add(HX_CSTRING("starsaphire")).Add(HX_CSTRING("lily")).Add(HX_CSTRING("letty"));
	hiddencharacters= Array_obj< ::String >::__new().Add(HX_CSTRING("mima")).Add(HX_CSTRING("yukari")).Add(HX_CSTRING("seija")).Add(HX_CSTRING("rumia")).Add(HX_CSTRING("cirno")).Add(HX_CSTRING("nue")).Add(HX_CSTRING("chen")).Add(HX_CSTRING("ran"));
}

