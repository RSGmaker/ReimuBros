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
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Rumia
#include <Rumia.h>
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
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif

Void Rumia_obj::__construct()
{
HX_STACK_FRAME("Rumia","new",0x5e182374,"Rumia.new","Rumia.hx",17,0x9db2067c)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(18)
	super::__construct(HX_CSTRING("rumia"));
	HX_STACK_LINE(19)
	this->accel = 0.5;
	HX_STACK_LINE(20)
	this->deccel = 0.1;
	HX_STACK_LINE(21)
	this->mxspd = (int)4;
	HX_STACK_LINE(22)
	this->Ldir = (int)1;
	HX_STACK_LINE(23)
	this->killed = false;
	HX_STACK_LINE(24)
	this->flipped = (int)-1;
	HX_STACK_LINE(25)
	this->started = false;
	HX_STACK_LINE(26)
	this->pointvalue = (int)500;
	HX_STACK_LINE(27)
	this->set_scaleX(0.8);
	HX_STACK_LINE(28)
	this->set_scaleY(0.8);
}
;
	return null();
}

//Rumia_obj::~Rumia_obj() { }

Dynamic Rumia_obj::__CreateEmpty() { return  new Rumia_obj; }
hx::ObjectPtr< Rumia_obj > Rumia_obj::__new()
{  hx::ObjectPtr< Rumia_obj > result = new Rumia_obj();
	result->__construct();
	return result;}

Dynamic Rumia_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rumia_obj > result = new Rumia_obj();
	result->__construct();
	return result;}

Void Rumia_obj::increaserank( ){
{
		HX_STACK_FRAME("Rumia","increaserank",0x587e3cda,"Rumia.increaserank","Rumia.hx",38,0x9db2067c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		hx::AddEq(this->accel,0.1);
		HX_STACK_LINE(40)
		hx::AddEq(this->mxspd,0.5);
	}
return null();
}


Void Rumia_obj::update( ){
{
		HX_STACK_FRAME("Rumia","update",0x05af5775,"Rumia.update","Rumia.hx",43,0x9db2067c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(44)
		if ((!(this->started))){
			HX_STACK_LINE(46)
			Array< ::Dynamic > _g = ::GameView_obj::_this->AL->GetAnimation(HX_CSTRING("darkness"));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(46)
			::openfl::_v2::display::BitmapData _g1 = _g->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(46)
			::openfl::_v2::display::Bitmap _g2 = ::openfl::_v2::display::Bitmap_obj::__new(_g1,null(),null());		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(46)
			this->darkness = _g2;
			HX_STACK_LINE(47)
			this->darkness->set_scaleX((int)2);
			HX_STACK_LINE(48)
			this->darkness->set_scaleY((int)2);
			HX_STACK_LINE(49)
			{
				HX_STACK_LINE(49)
				::openfl::_v2::display::Bitmap _g3 = this->darkness;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(49)
				Float _g31 = _g3->get_x();		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(49)
				Float _g4 = this->darkness->get_width();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(49)
				Float _g5 = (Float(_g4) / Float((int)2));		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(49)
				Float _g6 = (_g31 - _g5);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(49)
				_g3->set_x(_g6);
			}
			HX_STACK_LINE(50)
			{
				HX_STACK_LINE(50)
				::openfl::_v2::display::Bitmap _g3 = this->darkness;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(50)
				Float _g7 = _g3->get_y();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(50)
				Float _g8 = this->darkness->get_height();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(50)
				Float _g9 = (Float(_g8) / Float((int)2));		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(50)
				Float _g10 = (_g7 - _g9);		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(50)
				_g3->set_y(_g10);
			}
			HX_STACK_LINE(51)
			{
				HX_STACK_LINE(51)
				::openfl::_v2::display::Bitmap _g3 = this->darkness;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(51)
				Float _g11 = _g3->get_x();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(51)
				Float _g12 = this->get_x();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(51)
				Float _g13 = this->get_width();		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(51)
				Float _g14 = (Float(_g13) / Float((int)2));		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(51)
				Float _g15 = (_g12 + _g14);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(51)
				Float _g16 = (_g11 + _g15);		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(51)
				_g3->set_x(_g16);
			}
			HX_STACK_LINE(52)
			{
				HX_STACK_LINE(52)
				::openfl::_v2::display::Bitmap _g3 = this->darkness;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(52)
				Float _g17 = _g3->get_y();		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(52)
				Float _g18 = this->get_y();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(52)
				Float _g19 = this->get_height();		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(52)
				Float _g20 = (Float(_g19) / Float((int)2));		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(52)
				Float _g21 = (_g18 + _g20);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(52)
				Float _g22 = (_g17 + _g21);		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(52)
				_g3->set_y(_g22);
			}
			HX_STACK_LINE(55)
			::GameView_obj::_this->addChild(this->darkness);
			HX_STACK_LINE(56)
			this->started = true;
		}
		HX_STACK_LINE(66)
		if (((bool((this->darkness != null())) && bool(this->enraged)))){
			HX_STACK_LINE(68)
			Float _g23 = this->darkness->get_scaleX();		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(68)
			if (((_g23 == (int)2))){
				HX_STACK_LINE(70)
				this->darkness->set_scaleX((int)8);
				HX_STACK_LINE(71)
				this->darkness->set_scaleY((int)8);
				HX_STACK_LINE(72)
				{
					HX_STACK_LINE(72)
					::openfl::_v2::display::Bitmap _g = this->darkness;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(72)
					Float _g24 = _g->get_x();		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(72)
					Float _g25 = this->darkness->get_width();		HX_STACK_VAR(_g25,"_g25");
					HX_STACK_LINE(72)
					Float _g26 = (Float(_g25) / Float((int)2));		HX_STACK_VAR(_g26,"_g26");
					HX_STACK_LINE(72)
					Float _g27 = (_g24 - _g26);		HX_STACK_VAR(_g27,"_g27");
					HX_STACK_LINE(72)
					_g->set_x(_g27);
				}
				HX_STACK_LINE(73)
				{
					HX_STACK_LINE(73)
					::openfl::_v2::display::Bitmap _g = this->darkness;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(73)
					Float _g28 = _g->get_y();		HX_STACK_VAR(_g28,"_g28");
					HX_STACK_LINE(73)
					Float _g29 = this->darkness->get_height();		HX_STACK_VAR(_g29,"_g29");
					HX_STACK_LINE(73)
					Float _g30 = (Float(_g29) / Float((int)2));		HX_STACK_VAR(_g30,"_g30");
					HX_STACK_LINE(73)
					Float _g31 = (_g28 - _g30);		HX_STACK_VAR(_g31,"_g31");
					HX_STACK_LINE(73)
					_g->set_y(_g31);
				}
				HX_STACK_LINE(74)
				{
					HX_STACK_LINE(74)
					::openfl::_v2::display::Bitmap _g = this->darkness;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(74)
					Float _g32 = _g->get_x();		HX_STACK_VAR(_g32,"_g32");
					HX_STACK_LINE(74)
					Float _g33 = this->get_x();		HX_STACK_VAR(_g33,"_g33");
					HX_STACK_LINE(74)
					Float _g34 = this->get_width();		HX_STACK_VAR(_g34,"_g34");
					HX_STACK_LINE(74)
					Float _g35 = (Float(_g34) / Float((int)2));		HX_STACK_VAR(_g35,"_g35");
					HX_STACK_LINE(74)
					Float _g36 = (_g33 + _g35);		HX_STACK_VAR(_g36,"_g36");
					HX_STACK_LINE(74)
					Float _g37 = (_g32 + _g36);		HX_STACK_VAR(_g37,"_g37");
					HX_STACK_LINE(74)
					_g->set_x(_g37);
				}
				HX_STACK_LINE(75)
				{
					HX_STACK_LINE(75)
					::openfl::_v2::display::Bitmap _g = this->darkness;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(75)
					Float _g38 = _g->get_y();		HX_STACK_VAR(_g38,"_g38");
					HX_STACK_LINE(75)
					Float _g39 = this->get_y();		HX_STACK_VAR(_g39,"_g39");
					HX_STACK_LINE(75)
					Float _g40 = this->get_height();		HX_STACK_VAR(_g40,"_g40");
					HX_STACK_LINE(75)
					Float _g41 = (Float(_g40) / Float((int)2));		HX_STACK_VAR(_g41,"_g41");
					HX_STACK_LINE(75)
					Float _g42 = (_g39 + _g41);		HX_STACK_VAR(_g42,"_g42");
					HX_STACK_LINE(75)
					Float _g43 = (_g38 + _g42);		HX_STACK_VAR(_g43,"_g43");
					HX_STACK_LINE(75)
					_g->set_y(_g43);
				}
			}
		}
		HX_STACK_LINE(80)
		if ((!(this->killed))){
			HX_STACK_LINE(83)
			int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(84)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(86)
				hx::SubEq(this->flipped,(int)1);
				HX_STACK_LINE(87)
				this->dangerous = false;
				HX_STACK_LINE(88)
				if (((this->flipped == (int)0))){
					HX_STACK_LINE(90)
					this->flipped = (int)-1;
					HX_STACK_LINE(91)
					this->powerup();
				}
			}
			else{
				HX_STACK_LINE(96)
				this->dangerous = true;
			}
			HX_STACK_LINE(98)
			if (((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(100)
				hx::AddEq(this->Hspeed,this->accel);
				HX_STACK_LINE(101)
				if (((this->Hspeed > this->mxspd))){
					HX_STACK_LINE(103)
					this->Hspeed = this->mxspd;
				}
			}
			HX_STACK_LINE(106)
			if (((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1))))){
				HX_STACK_LINE(108)
				hx::SubEq(this->Hspeed,this->accel);
				HX_STACK_LINE(109)
				if (((this->Hspeed < -(this->mxspd)))){
					HX_STACK_LINE(111)
					this->Hspeed = -(this->mxspd);
				}
			}
			HX_STACK_LINE(114)
			int F = this->flipped;		HX_STACK_VAR(F,"F");
			HX_STACK_LINE(115)
			Float LX = this->get_x();		HX_STACK_VAR(LX,"LX");
			HX_STACK_LINE(116)
			Float LY = this->get_y();		HX_STACK_VAR(LY,"LY");
			HX_STACK_LINE(117)
			this->flipped = (int)0;
			HX_STACK_LINE(118)
			this->updphysics();
			HX_STACK_LINE(119)
			this->updateanimation(null());
			HX_STACK_LINE(120)
			this->flipped = F;
			HX_STACK_LINE(121)
			if (((this->darkness != null()))){
				HX_STACK_LINE(123)
				{
					HX_STACK_LINE(123)
					::openfl::_v2::display::Bitmap _g = this->darkness;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(123)
					Float _g44 = _g->get_x();		HX_STACK_VAR(_g44,"_g44");
					HX_STACK_LINE(123)
					Float _g45 = this->get_x();		HX_STACK_VAR(_g45,"_g45");
					HX_STACK_LINE(123)
					Float _g46 = (_g45 - LX);		HX_STACK_VAR(_g46,"_g46");
					HX_STACK_LINE(123)
					Float _g47 = (_g44 + _g46);		HX_STACK_VAR(_g47,"_g47");
					HX_STACK_LINE(123)
					_g->set_x(_g47);
				}
				HX_STACK_LINE(124)
				{
					HX_STACK_LINE(124)
					::openfl::_v2::display::Bitmap _g = this->darkness;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(124)
					Float _g48 = _g->get_y();		HX_STACK_VAR(_g48,"_g48");
					HX_STACK_LINE(124)
					Float _g49 = this->get_y();		HX_STACK_VAR(_g49,"_g49");
					HX_STACK_LINE(124)
					Float _g50 = (_g49 - LY);		HX_STACK_VAR(_g50,"_g50");
					HX_STACK_LINE(124)
					Float _g51 = (_g48 + _g50);		HX_STACK_VAR(_g51,"_g51");
					HX_STACK_LINE(124)
					_g->set_y(_g51);
				}
			}
			HX_STACK_LINE(126)
			if (((this->flipped > (int)0))){
				HX_STACK_LINE(128)
				this->set_rotation((int)90);
			}
			else{
				HX_STACK_LINE(132)
				this->set_rotation((int)0);
			}
			HX_STACK_LINE(143)
			if (((this->ground != null()))){
				HX_STACK_LINE(146)
				if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
					HX_STACK_LINE(149)
					if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Rumia.hx",153,0x9db2067c)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(153)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(154)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(155)
						Float _g52 = this->get_x();		HX_STACK_VAR(_g52,"_g52");
						HX_STACK_LINE(155)
						D->__FieldRef(HX_CSTRING("x")) = _g52;
						HX_STACK_LINE(156)
						Float _g53 = this->get_y();		HX_STACK_VAR(_g53,"_g53");
						HX_STACK_LINE(156)
						D->__FieldRef(HX_CSTRING("y")) = _g53;
						HX_STACK_LINE(157)
						D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
						HX_STACK_LINE(158)
						D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
						HX_STACK_LINE(160)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
					}
				}
				else{
					HX_STACK_LINE(166)
					if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
						HX_STACK_LINE(169)
						this->Vspeed = (int)-4;
					}
				}
			}
			HX_STACK_LINE(175)
			Float _g54 = this->get_y();		HX_STACK_VAR(_g54,"_g54");
			HX_STACK_LINE(175)
			if (((  (((_g54 > (int)408))) ? bool(this->wrapped) : bool(false) ))){
				HX_STACK_LINE(177)
				this->alive = false;
				HX_STACK_LINE(178)
				this->set_visible(false);
				HX_STACK_LINE(179)
				if (((this->darkness != null()))){
					HX_STACK_LINE(181)
					::GameView_obj::_this->removeChild(this->darkness);
					HX_STACK_LINE(182)
					this->darkness = null();
				}
			}
			HX_STACK_LINE(185)
			this->killable = (this->flipped > (int)0);
		}
		else{
			HX_STACK_LINE(189)
			if (((this->darkness != null()))){
				HX_STACK_LINE(191)
				::GameView_obj::_this->removeChild(this->darkness);
				HX_STACK_LINE(192)
				this->darkness = null();
			}
			HX_STACK_LINE(194)
			{
				HX_STACK_LINE(194)
				::Rumia _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(194)
				Float _g55 = _g->get_y();		HX_STACK_VAR(_g55,"_g55");
				HX_STACK_LINE(194)
				Float _g56 = (_g55 + (int)15);		HX_STACK_VAR(_g56,"_g56");
				HX_STACK_LINE(194)
				_g->set_y(_g56);
			}
			HX_STACK_LINE(195)
			Float _g57 = this->get_y();		HX_STACK_VAR(_g57,"_g57");
			HX_STACK_LINE(195)
			if (((_g57 > (int)600))){
				HX_STACK_LINE(197)
				this->alive = false;
			}
		}
	}
return null();
}


Void Rumia_obj::bump( ){
{
		HX_STACK_FRAME("Rumia","bump",0xef246e62,"Rumia.bump","Rumia.hx",204,0x9db2067c)
		HX_STACK_THIS(this)
		HX_STACK_LINE(204)
		if (((this->flipped < (int)1))){
			HX_STACK_LINE(206)
			if ((this->enraged)){
				HX_STACK_LINE(208)
				this->flipped = (int)120;
			}
			else{
				HX_STACK_LINE(212)
				this->flipped = (int)210;
			}
		}
		else{
			HX_STACK_LINE(217)
			this->flipped = (int)0;
		}
	}
return null();
}



Rumia_obj::Rumia_obj()
{
}

void Rumia_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rumia);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(darkness,"darkness");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Rumia_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(darkness,"darkness");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Rumia_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 8:
		if (HX_FIELD_EQ(inName,"darkness") ) { return darkness; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"increaserank") ) { return increaserank_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Rumia_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"accel") ) { accel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxspd") ) { mxspd=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"darkness") ) { darkness=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rumia_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("darkness"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Rumia_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Rumia_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(Rumia_obj,darkness),HX_CSTRING("darkness")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("darkness"),
	HX_CSTRING("increaserank"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Rumia_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Rumia_obj::__mClass,"__mClass");
};

#endif

Class Rumia_obj::__mClass;

void Rumia_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Rumia"), hx::TCanCast< Rumia_obj> ,sStaticFields,sMemberFields,
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

void Rumia_obj::__boot()
{
}

