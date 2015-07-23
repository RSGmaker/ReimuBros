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
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Table
#include <Table.h>
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

Void Table_obj::__construct()
{
HX_STACK_FRAME("Table","new",0x434a57e0,"Table.new","Table.hx",7,0x27554390)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(13)
	this->gravY = (int)0;
	HX_STACK_LINE(12)
	this->gravX = (int)0;
	HX_STACK_LINE(18)
	super::__construct(HX_CSTRING("table"));
	HX_STACK_LINE(19)
	this->started = false;
	HX_STACK_LINE(20)
	this->dangerous = false;
	HX_STACK_LINE(22)
	this->type = HX_CSTRING("Table");
	HX_STACK_LINE(25)
	this->image_speed = (int)0;
	HX_STACK_LINE(26)
	this->tossedBy = null();
	HX_STACK_LINE(27)
	this->respawn = (int)240;
}
;
	return null();
}

//Table_obj::~Table_obj() { }

Dynamic Table_obj::__CreateEmpty() { return  new Table_obj; }
hx::ObjectPtr< Table_obj > Table_obj::__new()
{  hx::ObjectPtr< Table_obj > result = new Table_obj();
	result->__construct();
	return result;}

Dynamic Table_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Table_obj > result = new Table_obj();
	result->__construct();
	return result;}

Void Table_obj::update( ){
{
		HX_STACK_FRAME("Table","update",0x9238ae89,"Table.update","Table.hx",31,0x27554390)
		HX_STACK_THIS(this)
		HX_STACK_LINE(33)
		if ((!(this->started))){
			HX_STACK_LINE(35)
			this->started = true;
			HX_STACK_LINE(36)
			Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(36)
			this->startx = _g;
			HX_STACK_LINE(37)
			Float _g1 = this->get_y();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(37)
			this->starty = _g1;
		}
		HX_STACK_LINE(39)
		hx::AddEq(this->Hspeed,this->gravX);
		HX_STACK_LINE(40)
		hx::AddEq(this->Vspeed,this->gravY);
		HX_STACK_LINE(41)
		this->animate();
		HX_STACK_LINE(42)
		{
			HX_STACK_LINE(42)
			::Table _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(42)
			Float _g2 = _g->get_x();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(42)
			Float _g3 = (_g2 + this->Hspeed);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(42)
			_g->set_x(_g3);
		}
		HX_STACK_LINE(43)
		{
			HX_STACK_LINE(43)
			::Table _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(43)
			Float _g4 = _g->get_y();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(43)
			Float _g5 = (_g4 + this->Vspeed);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(43)
			_g->set_y(_g5);
		}
		HX_STACK_LINE(45)
		bool ok = true;		HX_STACK_VAR(ok,"ok");
		HX_STACK_LINE(47)
		if ((this->get_visible())){
			HX_STACK_LINE(49)
			Float _g6 = this->get_x();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(49)
			Float _g7 = (_g6 + (int)24);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(49)
			Float _g8 = this->get_y();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(49)
			Float _g9 = (_g8 + (int)24);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(49)
			::Player player = ::GameView_obj::_this->CollisionDetectPointPlayer(_g7,_g9);		HX_STACK_VAR(player,"player");
			HX_STACK_LINE(50)
			Float _g10 = this->get_x();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(50)
			Float _g11 = (_g10 + (int)24);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(50)
			Float _g12 = this->get_y();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(50)
			Float _g13 = (_g12 + (int)24);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(50)
			::Enemy enemy = ::GameView_obj::_this->CollisionDetectPointEnemy(_g11,_g13);		HX_STACK_VAR(enemy,"enemy");
			HX_STACK_LINE(51)
			Float _g14 = this->get_x();		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(51)
			Float _g15 = (_g14 + (int)24);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(51)
			Float _g16 = this->get_y();		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(51)
			Float _g17 = (_g16 + (int)24);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(51)
			::Entity danger = ::GameView_obj::_this->CollisionDetectPointDangerous(_g15,_g17);		HX_STACK_VAR(danger,"danger");
			HX_STACK_LINE(52)
			if (((bool((this->Hspeed == (int)0)) && bool((this->Vspeed == (int)0))))){
				HX_STACK_LINE(54)
				if (((bool((player != null())) && bool(((bool(player->controller->__get((int)0)) || bool(player->controller->__get((int)1)))))))){
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Table.hx",69,0x27554390)
							{
								hx::Anon __result = hx::Anon_obj::Create();
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(69)
					Dynamic D = _Function_4_1::Block();		HX_STACK_VAR(D,"D");
					HX_STACK_LINE(70)
					D->__FieldRef(HX_CSTRING("UID")) = this->UID;
					HX_STACK_LINE(71)
					D->__FieldRef(HX_CSTRING("dangerous")) = false;
					HX_STACK_LINE(72)
					D->__FieldRef(HX_CSTRING("TUID")) = player->UID;
					HX_STACK_LINE(73)
					if (((player->Ldir < (int)0))){
						HX_STACK_LINE(75)
						D->__FieldRef(HX_CSTRING("Hspeed")) = (int)-10;
						HX_STACK_LINE(76)
						D->__FieldRef(HX_CSTRING("image_speed")) = 0.5;
					}
					else{
						HX_STACK_LINE(80)
						D->__FieldRef(HX_CSTRING("Hspeed")) = (int)10;
						HX_STACK_LINE(81)
						D->__FieldRef(HX_CSTRING("image_speed")) = -0.5;
					}
					HX_STACK_LINE(83)
					::GameView_obj::_this->SendEvent(HX_CSTRING("Tableflip"),D);
				}
				else{
					HX_STACK_LINE(86)
					if (((bool((bool((enemy != null())) && bool(enemy->enraged))) && bool(::GameView_obj::_this->Hoster)))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Table.hx",102,0x27554390)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(102)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(103)
						D->__FieldRef(HX_CSTRING("UID")) = this->UID;
						HX_STACK_LINE(104)
						D->__FieldRef(HX_CSTRING("dangerous")) = true;
						HX_STACK_LINE(105)
						D->__FieldRef(HX_CSTRING("TUID")) = null();
						HX_STACK_LINE(106)
						if (((enemy->Hspeed < (int)0))){
							HX_STACK_LINE(108)
							D->__FieldRef(HX_CSTRING("Hspeed")) = (int)-10;
							HX_STACK_LINE(109)
							D->__FieldRef(HX_CSTRING("image_speed")) = 0.5;
						}
						else{
							HX_STACK_LINE(113)
							D->__FieldRef(HX_CSTRING("Hspeed")) = (int)10;
							HX_STACK_LINE(114)
							D->__FieldRef(HX_CSTRING("image_speed")) = -0.5;
						}
						HX_STACK_LINE(116)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Tableflip"),D);
					}
				}
			}
			else{
				HX_STACK_LINE(121)
				if (((bool((this->tossedBy != null())) && bool((this->tossedBy == ::GameView_obj::_this->myplayer))))){
					HX_STACK_LINE(123)
					if (((bool((enemy != null())) && bool(!(enemy->killed))))){
						HX_STACK_LINE(125)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Kill"),enemy->UID);
					}
					HX_STACK_LINE(127)
					Dynamic DD = danger;		HX_STACK_VAR(DD,"DD");
					HX_STACK_LINE(128)
					if (((bool((bool((danger != null())) && bool((danger->type == HX_CSTRING("Enemy"))))) && bool((DD->__Field(HX_CSTRING("charname"),true) == HX_CSTRING("Cirno")))))){
						HX_STACK_LINE(130)
						::GameView_obj::_this->SendEvent(HX_CSTRING("Kill"),danger->UID);
					}
				}
			}
			HX_STACK_LINE(135)
			Float _g18 = this->get_x();		HX_STACK_VAR(_g18,"_g18");
			struct _Function_2_1{
				inline static bool Block( hx::ObjectPtr< ::Table_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Table.hx",135,0x27554390)
					{
						HX_STACK_LINE(135)
						Float _g19 = __this->get_y();		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(135)
						return (  (((_g19 < (int)-32))) ? bool((__this->gravY <= (int)0)) : bool(false) );
					}
					return null();
				}
			};
			struct _Function_2_2{
				inline static bool Block( hx::ObjectPtr< ::Table_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Table.hx",135,0x27554390)
					{
						HX_STACK_LINE(135)
						Float _g20 = __this->get_x();		HX_STACK_VAR(_g20,"_g20");
						HX_STACK_LINE(135)
						return (  (((_g20 > (int)832))) ? bool((__this->gravX >= (int)0)) : bool(false) );
					}
					return null();
				}
			};
			struct _Function_2_3{
				inline static bool Block( hx::ObjectPtr< ::Table_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Table.hx",135,0x27554390)
					{
						HX_STACK_LINE(135)
						Float _g21 = __this->get_y();		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(135)
						return (  (((_g21 > (int)832))) ? bool((__this->gravY >= (int)0)) : bool(false) );
					}
					return null();
				}
			};
			HX_STACK_LINE(135)
			if (((  ((!(((  ((!(((  ((!(((  (((_g18 < (int)-32))) ? bool((this->gravX <= (int)0)) : bool(false) ))))) ? bool(_Function_2_1::Block(this)) : bool(true) ))))) ? bool(_Function_2_2::Block(this)) : bool(true) ))))) ? bool(_Function_2_3::Block(this)) : bool(true) ))){
				HX_STACK_LINE(137)
				this->set_visible(false);
				HX_STACK_LINE(138)
				this->dangerous = false;
				HX_STACK_LINE(139)
				this->tossedBy = null();
				HX_STACK_LINE(140)
				this->Hspeed = (int)0;
				HX_STACK_LINE(141)
				this->Vspeed = (int)0;
				HX_STACK_LINE(142)
				this->image_index = -0.1;
				HX_STACK_LINE(143)
				this->image_speed = 0.1;
				HX_STACK_LINE(144)
				this->animate();
				HX_STACK_LINE(145)
				this->image_speed = (int)0;
				HX_STACK_LINE(146)
				this->gravX = (int)0;
				HX_STACK_LINE(147)
				this->gravY = (int)0;
				HX_STACK_LINE(148)
				this->set_x(this->startx);
				HX_STACK_LINE(149)
				this->set_y(this->starty);
				HX_STACK_LINE(150)
				this->respawn = (int)240;
			}
		}
		else{
			HX_STACK_LINE(157)
			if (((this->respawn > (int)0))){
				HX_STACK_LINE(159)
				(this->respawn)--;
			}
			else{
				HX_STACK_LINE(163)
				this->set_visible(true);
			}
		}
	}
return null();
}



Table_obj::Table_obj()
{
}

void Table_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Table);
	HX_MARK_MEMBER_NAME(started,"started");
	HX_MARK_MEMBER_NAME(startx,"startx");
	HX_MARK_MEMBER_NAME(starty,"starty");
	HX_MARK_MEMBER_NAME(gravX,"gravX");
	HX_MARK_MEMBER_NAME(gravY,"gravY");
	HX_MARK_MEMBER_NAME(tossedBy,"tossedBy");
	HX_MARK_MEMBER_NAME(respawn,"respawn");
	::Entity_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Table_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(started,"started");
	HX_VISIT_MEMBER_NAME(startx,"startx");
	HX_VISIT_MEMBER_NAME(starty,"starty");
	HX_VISIT_MEMBER_NAME(gravX,"gravX");
	HX_VISIT_MEMBER_NAME(gravY,"gravY");
	HX_VISIT_MEMBER_NAME(tossedBy,"tossedBy");
	HX_VISIT_MEMBER_NAME(respawn,"respawn");
	::Entity_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Table_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"gravX") ) { return gravX; }
		if (HX_FIELD_EQ(inName,"gravY") ) { return gravY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"startx") ) { return startx; }
		if (HX_FIELD_EQ(inName,"starty") ) { return starty; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"started") ) { return started; }
		if (HX_FIELD_EQ(inName,"respawn") ) { return respawn; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tossedBy") ) { return tossedBy; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Table_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"gravX") ) { gravX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gravY") ) { gravY=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"startx") ) { startx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"starty") ) { starty=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"started") ) { started=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"respawn") ) { respawn=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"tossedBy") ) { tossedBy=inValue.Cast< ::Player >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Table_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("started"));
	outFields->push(HX_CSTRING("startx"));
	outFields->push(HX_CSTRING("starty"));
	outFields->push(HX_CSTRING("gravX"));
	outFields->push(HX_CSTRING("gravY"));
	outFields->push(HX_CSTRING("tossedBy"));
	outFields->push(HX_CSTRING("respawn"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Table_obj,started),HX_CSTRING("started")},
	{hx::fsFloat,(int)offsetof(Table_obj,startx),HX_CSTRING("startx")},
	{hx::fsFloat,(int)offsetof(Table_obj,starty),HX_CSTRING("starty")},
	{hx::fsFloat,(int)offsetof(Table_obj,gravX),HX_CSTRING("gravX")},
	{hx::fsFloat,(int)offsetof(Table_obj,gravY),HX_CSTRING("gravY")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(Table_obj,tossedBy),HX_CSTRING("tossedBy")},
	{hx::fsInt,(int)offsetof(Table_obj,respawn),HX_CSTRING("respawn")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("started"),
	HX_CSTRING("startx"),
	HX_CSTRING("starty"),
	HX_CSTRING("gravX"),
	HX_CSTRING("gravY"),
	HX_CSTRING("tossedBy"),
	HX_CSTRING("respawn"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Table_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Table_obj::__mClass,"__mClass");
};

#endif

Class Table_obj::__mClass;

void Table_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Table"), hx::TCanCast< Table_obj> ,sStaticFields,sMemberFields,
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

void Table_obj::__boot()
{
}

