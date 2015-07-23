#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Cirno
#include <Cirno.h>
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

Void Cirno_obj::__construct()
{
HX_STACK_FRAME("Cirno","new",0x32e5e19f,"Cirno.new","Cirno.hx",27,0x3ac676b1)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(29)
	super::__construct(HX_CSTRING("Cirno"));
	HX_STACK_LINE(31)
	this->accel = 0.5;
	HX_STACK_LINE(32)
	this->deccel = 0.1;
	HX_STACK_LINE(33)
	this->mxspd = (int)4;
	HX_STACK_LINE(34)
	this->Ldir = (int)1;
	HX_STACK_LINE(35)
	this->killed = false;
	HX_STACK_LINE(36)
	this->flipped = (int)-1;
	HX_STACK_LINE(37)
	this->selfdestruct = false;
	HX_STACK_LINE(38)
	this->reward = false;
	HX_STACK_LINE(39)
	this->pointvalue = (int)150;
	HX_STACK_LINE(40)
	this->mxtimer = (int)90;
	HX_STACK_LINE(42)
	this->respawn = false;
	HX_STACK_LINE(43)
	this->rename = HX_CSTRING("ECirno");
}
;
	return null();
}

//Cirno_obj::~Cirno_obj() { }

Dynamic Cirno_obj::__CreateEmpty() { return  new Cirno_obj; }
hx::ObjectPtr< Cirno_obj > Cirno_obj::__new()
{  hx::ObjectPtr< Cirno_obj > result = new Cirno_obj();
	result->__construct();
	return result;}

Dynamic Cirno_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Cirno_obj > result = new Cirno_obj();
	result->__construct();
	return result;}

Void Cirno_obj::enrage( ){
{
		HX_STACK_FRAME("Cirno","enrage",0x9eb68897,"Cirno.enrage","Cirno.hx",50,0x3ac676b1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		this->enraged = false;
	}
return null();
}


Void Cirno_obj::update( ){
{
		HX_STACK_FRAME("Cirno","update",0x21f8862a,"Cirno.update","Cirno.hx",55,0x3ac676b1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(55)
		if ((!(this->killed))){
			HX_STACK_LINE(57)
			if (((this->rng == null()))){
				HX_STACK_LINE(59)
				::MersenneTwister _g = ::MersenneTwister_obj::__new();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(59)
				this->rng = _g;
				HX_STACK_LINE(60)
				int seed = ::Math_obj::floor((this->UID * (int)100000));		HX_STACK_VAR(seed,"seed");
				HX_STACK_LINE(61)
				Array< int > _g1 = this->rng->twist(seed,(int)1,(int)900);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(61)
				int _g2 = _g1->__get((int)0);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(61)
				int _g3 = ((int)60 + _g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(61)
				this->timer = _g3;
				struct _Function_3_1{
					inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",62,0x3ac676b1)
						{
							HX_STACK_LINE(62)
							Array< int > _g4 = __this->rng->twist(__this->rng->seed,(int)1,(int)100);		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(62)
							int _g5 = _g4->__get((int)0);		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(62)
							return (_g5 > (int)90);
						}
						return null();
					}
				};
				HX_STACK_LINE(62)
				if (((  ((!(((::GameView_obj::_this->RoundType == ::TypeofRound_obj::FireCirno))))) ? bool(_Function_3_1::Block(this)) : bool(true) ))){
					HX_STACK_LINE(64)
					this->flaming = true;
					HX_STACK_LINE(65)
					this->rename = HX_CSTRING("firecirno");
					HX_STACK_LINE(66)
					this->mxtimer = (int)120;
				}
				HX_STACK_LINE(68)
				this->countdown = this->mxtimer;
			}
			HX_STACK_LINE(70)
			if (((this->timer <= (int)0))){
				struct _Function_3_1{
					inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",72,0x3ac676b1)
						{
							struct _Function_4_1{
								inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",72,0x3ac676b1)
									{
										struct _Function_5_1{
											inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
												HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",72,0x3ac676b1)
												{
													HX_STACK_LINE(72)
													Float _g6 = __this->get_y();		HX_STACK_VAR(_g6,"_g6");
													HX_STACK_LINE(72)
													return (_g6 < (int)500);
												}
												return null();
											}
										};
										HX_STACK_LINE(72)
										return (  (((bool(!(__this->ground->dangerous)) && bool(__this->flaming)))) ? bool(_Function_5_1::Block(__this)) : bool(false) );
									}
									return null();
								}
							};
							HX_STACK_LINE(72)
							return (  ((!(((bool(!(__this->ground->icy)) && bool(!(__this->flaming))))))) ? bool(_Function_4_1::Block(__this)) : bool(true) );
						}
						return null();
					}
				};
				struct _Function_3_2{
					inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",72,0x3ac676b1)
						{
							HX_STACK_LINE(72)
							Float _g7 = __this->get_x();		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(72)
							return (_g7 > (int)0);
						}
						return null();
					}
				};
				struct _Function_3_3{
					inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",72,0x3ac676b1)
						{
							HX_STACK_LINE(72)
							Float _g8 = __this->get_x();		HX_STACK_VAR(_g8,"_g8");
							HX_STACK_LINE(72)
							return (_g8 < (int)780);
						}
						return null();
					}
				};
				HX_STACK_LINE(72)
				if (((  (((  (((  (((this->ground != null()))) ? bool(_Function_3_1::Block(this)) : bool(false) ))) ? bool(_Function_3_2::Block(this)) : bool(false) ))) ? bool(_Function_3_3::Block(this)) : bool(false) ))){
					HX_STACK_LINE(74)
					this->selfdestruct = true;
				}
				else{
					HX_STACK_LINE(78)
					this->selfdestruct = false;
				}
			}
			else{
				HX_STACK_LINE(83)
				hx::SubEq(this->timer,(int)1);
			}
			HX_STACK_LINE(85)
			if ((this->selfdestruct)){
				HX_STACK_LINE(87)
				hx::SubEq(this->countdown,(int)1);
				HX_STACK_LINE(89)
				this->visuallyEnraged = !(this->visuallyEnraged);
				HX_STACK_LINE(90)
				if (((this->countdown <= (int)0))){
					struct _Function_4_1{
						inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",93,0x3ac676b1)
							{
								struct _Function_5_1{
									inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",93,0x3ac676b1)
										{
											struct _Function_6_1{
												inline static bool Block( hx::ObjectPtr< ::Cirno_obj > __this){
													HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",93,0x3ac676b1)
													{
														HX_STACK_LINE(93)
														Float _g9 = __this->get_y();		HX_STACK_VAR(_g9,"_g9");
														HX_STACK_LINE(93)
														return (_g9 < (int)500);
													}
													return null();
												}
											};
											HX_STACK_LINE(93)
											return (  (((bool(!(__this->ground->dangerous)) && bool(__this->flaming)))) ? bool(_Function_6_1::Block(__this)) : bool(false) );
										}
										return null();
									}
								};
								HX_STACK_LINE(93)
								return (  ((!(((bool(!(__this->ground->icy)) && bool(!(__this->flaming))))))) ? bool(_Function_5_1::Block(__this)) : bool(true) );
							}
							return null();
						}
					};
					HX_STACK_LINE(93)
					if (((  (((bool(::GameView_obj::_this->Hoster) && bool((this->ground != null()))))) ? bool(_Function_4_1::Block(this)) : bool(false) ))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",95,0x3ac676b1)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(95)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(96)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(97)
						Float _g10 = this->ground->get_y();		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(97)
						D->__FieldRef(HX_CSTRING("y")) = _g10;
						HX_STACK_LINE(98)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Cirnobomb"),D);
					}
				}
				HX_STACK_LINE(101)
				this->Hspeed = (int)0;
			}
			else{
				HX_STACK_LINE(105)
				this->countdown = (int)90;
				HX_STACK_LINE(107)
				this->visuallyEnraged = false;
			}
			HX_STACK_LINE(109)
			if ((!(this->killed))){
				HX_STACK_LINE(111)
				int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
				HX_STACK_LINE(112)
				if (((this->flipped > (int)0))){
					HX_STACK_LINE(114)
					hx::SubEq(this->flipped,(int)1);
					HX_STACK_LINE(115)
					this->dangerous = false;
				}
				else{
					HX_STACK_LINE(119)
					this->dangerous = true;
				}
				HX_STACK_LINE(121)
				if (((bool((bool((bool((this->Hspeed < this->mxspd)) && bool((dir == (int)1)))) && bool((this->flipped < (int)1)))) && bool(!(this->selfdestruct))))){
					HX_STACK_LINE(123)
					hx::AddEq(this->Hspeed,this->accel);
					HX_STACK_LINE(124)
					if (((this->Hspeed > this->mxspd))){
						HX_STACK_LINE(126)
						this->Hspeed = this->mxspd;
					}
				}
				HX_STACK_LINE(129)
				if (((bool((bool((bool((this->Hspeed > -(this->mxspd))) && bool((dir == (int)-1)))) && bool((this->flipped < (int)1)))) && bool(!(this->selfdestruct))))){
					HX_STACK_LINE(131)
					hx::SubEq(this->Hspeed,this->accel);
					HX_STACK_LINE(132)
					if (((this->Hspeed < -(this->mxspd)))){
						HX_STACK_LINE(134)
						this->Hspeed = -(this->mxspd);
					}
				}
				HX_STACK_LINE(137)
				this->updphysics();
				HX_STACK_LINE(138)
				this->updateanimation(this->rename);
				HX_STACK_LINE(140)
				if (((this->ground != null()))){
					HX_STACK_LINE(143)
					if (((bool((this->ground->bonked > (int)-1000)) && bool((this->Vspeed >= (int)0))))){
						HX_STACK_LINE(146)
						if (((::GameView_obj::_this->myplayer == this->ground->bonkedby))){
							struct _Function_6_1{
								inline static Dynamic Block( ){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Cirno.hx",150,0x3ac676b1)
									{
										hx::Anon __result = hx::Anon_obj::Create();
										return __result;
									}
									return null();
								}
							};
							HX_STACK_LINE(150)
							Dynamic D = _Function_6_1::Block();		HX_STACK_VAR(D,"D");
							HX_STACK_LINE(151)
							D->__FieldRef(HX_CSTRING("UID")) = this->UID;
							HX_STACK_LINE(152)
							Float _g11 = this->get_x();		HX_STACK_VAR(_g11,"_g11");
							HX_STACK_LINE(152)
							D->__FieldRef(HX_CSTRING("x")) = _g11;
							HX_STACK_LINE(153)
							Float _g12 = this->get_y();		HX_STACK_VAR(_g12,"_g12");
							HX_STACK_LINE(153)
							D->__FieldRef(HX_CSTRING("y")) = _g12;
							HX_STACK_LINE(154)
							D->__FieldRef(HX_CSTRING("Hspeed")) = this->Hspeed;
							HX_STACK_LINE(155)
							D->__FieldRef(HX_CSTRING("Vspeed")) = (int)-10;
							HX_STACK_LINE(157)
							::GameView_obj::_this->SendEvent(HX_CSTRING("Bump"),D);
						}
					}
					else{
						HX_STACK_LINE(163)
						if (((bool((this->flipped > (int)0)) && bool((this->flipped < (int)60))))){
							HX_STACK_LINE(166)
							this->Vspeed = (int)-4;
						}
					}
				}
				HX_STACK_LINE(172)
				Float _g13 = this->get_y();		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(172)
				if (((  (((_g13 > (int)408))) ? bool(this->wrapped) : bool(false) ))){
					HX_STACK_LINE(174)
					this->killed = true;
					HX_STACK_LINE(175)
					this->alive = false;
					HX_STACK_LINE(176)
					this->set_visible(false);
				}
				HX_STACK_LINE(178)
				this->killable = (this->flipped > (int)0);
			}
			else{
				HX_STACK_LINE(182)
				{
					HX_STACK_LINE(182)
					::Cirno _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(182)
					Float _g14 = _g->get_y();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(182)
					Float _g15 = (_g14 + (int)15);		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(182)
					_g->set_y(_g15);
				}
				HX_STACK_LINE(183)
				Float _g16 = this->get_y();		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(183)
				if (((_g16 > (int)600))){
					HX_STACK_LINE(185)
					this->alive = false;
				}
			}
		}
		else{
			HX_STACK_LINE(191)
			{
				HX_STACK_LINE(191)
				::Cirno _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(191)
				Float _g17 = _g->get_scaleX();		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(191)
				Float _g18 = (_g17 - 0.2);		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(191)
				_g->set_scaleX(_g18);
			}
			HX_STACK_LINE(192)
			{
				HX_STACK_LINE(192)
				::Cirno _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(192)
				Float _g19 = _g->get_scaleY();		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(192)
				Float _g20 = (_g19 - 0.2);		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(192)
				_g->set_scaleY(_g20);
			}
			HX_STACK_LINE(193)
			Float _g21 = this->get_scaleX();		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(193)
			if (((_g21 <= (int)0))){
				HX_STACK_LINE(195)
				if (((bool(this->alive) && bool((this->killedby != null()))))){
					HX_STACK_LINE(197)
					hx::AddEq(this->killedby->score,this->pointvalue);
				}
				HX_STACK_LINE(199)
				this->alive = false;
			}
		}
	}
return null();
}


Void Cirno_obj::bump( ){
{
		HX_STACK_FRAME("Cirno","bump",0x4e5d15d7,"Cirno.bump","Cirno.hx",204,0x3ac676b1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(206)
		this->killed = true;
		HX_STACK_LINE(207)
		if (((bool((bool((this->ground != null())) && bool((this->ground->bonkedby != null())))) && bool((this->ground->bonkedby->type == HX_CSTRING("Player")))))){
			HX_STACK_LINE(209)
			Dynamic D = this->ground->bonkedby;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(211)
			this->killedby = D;
		}
	}
return null();
}



Cirno_obj::Cirno_obj()
{
}

void Cirno_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Cirno);
	HX_MARK_MEMBER_NAME(accel,"accel");
	HX_MARK_MEMBER_NAME(mxspd,"mxspd");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(rng,"rng");
	HX_MARK_MEMBER_NAME(selfdestruct,"selfdestruct");
	HX_MARK_MEMBER_NAME(countdown,"countdown");
	HX_MARK_MEMBER_NAME(flaming,"flaming");
	HX_MARK_MEMBER_NAME(rename,"rename");
	HX_MARK_MEMBER_NAME(mxtimer,"mxtimer");
	HX_MARK_MEMBER_NAME(killedby,"killedby");
	::Enemy_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Cirno_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(accel,"accel");
	HX_VISIT_MEMBER_NAME(mxspd,"mxspd");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(rng,"rng");
	HX_VISIT_MEMBER_NAME(selfdestruct,"selfdestruct");
	HX_VISIT_MEMBER_NAME(countdown,"countdown");
	HX_VISIT_MEMBER_NAME(flaming,"flaming");
	HX_VISIT_MEMBER_NAME(rename,"rename");
	HX_VISIT_MEMBER_NAME(mxtimer,"mxtimer");
	HX_VISIT_MEMBER_NAME(killedby,"killedby");
	::Enemy_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Cirno_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"rename") ) { return rename; }
		if (HX_FIELD_EQ(inName,"enrage") ) { return enrage_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"flaming") ) { return flaming; }
		if (HX_FIELD_EQ(inName,"mxtimer") ) { return mxtimer; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"killedby") ) { return killedby; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"countdown") ) { return countdown; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"selfdestruct") ) { return selfdestruct; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Cirno_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"rename") ) { rename=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"flaming") ) { flaming=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mxtimer") ) { mxtimer=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"killedby") ) { killedby=inValue.Cast< ::Player >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"countdown") ) { countdown=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"selfdestruct") ) { selfdestruct=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Cirno_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("accel"));
	outFields->push(HX_CSTRING("mxspd"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("rng"));
	outFields->push(HX_CSTRING("selfdestruct"));
	outFields->push(HX_CSTRING("countdown"));
	outFields->push(HX_CSTRING("flaming"));
	outFields->push(HX_CSTRING("rename"));
	outFields->push(HX_CSTRING("mxtimer"));
	outFields->push(HX_CSTRING("killedby"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Cirno_obj,accel),HX_CSTRING("accel")},
	{hx::fsFloat,(int)offsetof(Cirno_obj,mxspd),HX_CSTRING("mxspd")},
	{hx::fsInt,(int)offsetof(Cirno_obj,timer),HX_CSTRING("timer")},
	{hx::fsObject /*::MersenneTwister*/ ,(int)offsetof(Cirno_obj,rng),HX_CSTRING("rng")},
	{hx::fsBool,(int)offsetof(Cirno_obj,selfdestruct),HX_CSTRING("selfdestruct")},
	{hx::fsInt,(int)offsetof(Cirno_obj,countdown),HX_CSTRING("countdown")},
	{hx::fsBool,(int)offsetof(Cirno_obj,flaming),HX_CSTRING("flaming")},
	{hx::fsString,(int)offsetof(Cirno_obj,rename),HX_CSTRING("rename")},
	{hx::fsInt,(int)offsetof(Cirno_obj,mxtimer),HX_CSTRING("mxtimer")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(Cirno_obj,killedby),HX_CSTRING("killedby")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("accel"),
	HX_CSTRING("mxspd"),
	HX_CSTRING("timer"),
	HX_CSTRING("rng"),
	HX_CSTRING("selfdestruct"),
	HX_CSTRING("countdown"),
	HX_CSTRING("flaming"),
	HX_CSTRING("rename"),
	HX_CSTRING("mxtimer"),
	HX_CSTRING("killedby"),
	HX_CSTRING("enrage"),
	HX_CSTRING("update"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Cirno_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Cirno_obj::__mClass,"__mClass");
};

#endif

Class Cirno_obj::__mClass;

void Cirno_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Cirno"), hx::TCanCast< Cirno_obj> ,sStaticFields,sMemberFields,
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

void Cirno_obj::__boot()
{
}

