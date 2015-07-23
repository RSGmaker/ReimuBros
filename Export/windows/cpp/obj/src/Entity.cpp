#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Animationloader
#include <Animationloader.h>
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
#ifndef INCLUDED_openfl__v2_geom_Point
#include <openfl/_v2/geom/Point.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif

Void Entity_obj::__construct(::String ani)
{
HX_STACK_FRAME("Entity","new",0x9c9485b5,"Entity.new","Entity.hx",41,0x5c8a675b)
HX_STACK_THIS(this)
HX_STACK_ARG(ani,"ani")
{
	HX_STACK_LINE(42)
	this->touchable = false;
	HX_STACK_LINE(43)
	this->solid = false;
	HX_STACK_LINE(44)
	this->platform = false;
	HX_STACK_LINE(45)
	this->bonked = (int)-1000;
	HX_STACK_LINE(47)
	this->alive = true;
	HX_STACK_LINE(48)
	Array< ::Dynamic > _g = ::GameView_obj::_this->AL->GetAnimation(ani);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(48)
	super::__construct(_g);
	HX_STACK_LINE(50)
	this->fallaccel = 0.7;
	HX_STACK_LINE(51)
	this->Hspeed = (int)0;
	HX_STACK_LINE(52)
	this->Vspeed = (int)0;
	HX_STACK_LINE(53)
	this->type = HX_CSTRING("Unknown");
	HX_STACK_LINE(54)
	Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(54)
	this->UID = _g1;
	HX_STACK_LINE(55)
	this->bonking = false;
	HX_STACK_LINE(56)
	this->hitbox = null();
}
;
	return null();
}

//Entity_obj::~Entity_obj() { }

Dynamic Entity_obj::__CreateEmpty() { return  new Entity_obj; }
hx::ObjectPtr< Entity_obj > Entity_obj::__new(::String ani)
{  hx::ObjectPtr< Entity_obj > result = new Entity_obj();
	result->__construct(ani);
	return result;}

Dynamic Entity_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Entity_obj > result = new Entity_obj();
	result->__construct(inArgs[0]);
	return result;}

::openfl::_v2::geom::Rectangle Entity_obj::GetHitbox( ){
	HX_STACK_FRAME("Entity","GetHitbox",0x3d2839c3,"Entity.GetHitbox","Entity.hx",60,0x5c8a675b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(60)
	if (((this->hitbox == null()))){
		HX_STACK_LINE(62)
		return this->getBounds(::GameView_obj::_this);
	}
	else{
		HX_STACK_LINE(66)
		::openfl::_v2::geom::Rectangle rct = this->getBounds(::GameView_obj::_this);		HX_STACK_VAR(rct,"rct");
		HX_STACK_LINE(67)
		Float _g = this->hitbox->get_left();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		Float _g1 = rct->get_left();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(67)
		Float _g2 = (_g + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(67)
		Float _g3 = this->hitbox->get_top();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(67)
		Float _g4 = rct->get_top();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(67)
		Float _g5 = (_g3 + _g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(67)
		Float _g6 = this->hitbox->get_right();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(67)
		::openfl::_v2::geom::Rectangle R = ::openfl::_v2::geom::Rectangle_obj::__new(_g2,_g5,this->hitbox->width,_g6);		HX_STACK_VAR(R,"R");
		HX_STACK_LINE(68)
		return R;
	}
	HX_STACK_LINE(60)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,GetHitbox,return )

bool Entity_obj::CollidesWithPoint( Float X,Float Y){
	HX_STACK_FRAME("Entity","CollidesWithPoint",0xfaf64a6a,"Entity.CollidesWithPoint","Entity.hx",72,0x5c8a675b)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(73)
	::openfl::_v2::geom::Point _g = ::openfl::_v2::geom::Point_obj::__new(X,Y);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(73)
	return this->GetHitbox()->containsPoint(_g);
}


HX_DEFINE_DYNAMIC_FUNC2(Entity_obj,CollidesWithPoint,return )

Void Entity_obj::update( ){
{
		HX_STACK_FRAME("Entity","update",0xee9313d4,"Entity.update","Entity.hx",87,0x5c8a675b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(87)
		this->animate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,update,(void))

::Player Entity_obj::nearestplayer( ){
	HX_STACK_FRAME("Entity","nearestplayer",0xd0f52fd4,"Entity.nearestplayer","Entity.hx",90,0x5c8a675b)
	HX_STACK_THIS(this)
	HX_STACK_LINE(91)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(92)
	Float dist = 999999999.0;		HX_STACK_VAR(dist,"dist");
	HX_STACK_LINE(93)
	::Player ret = null();		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(94)
	while((true)){
		HX_STACK_LINE(94)
		if ((!(((i < ::GameView_obj::_this->entities->length))))){
			HX_STACK_LINE(94)
			break;
		}
		HX_STACK_LINE(96)
		Dynamic E = ::GameView_obj::_this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(97)
		if (((E->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Player")))){
			HX_STACK_LINE(99)
			::Player P = E;		HX_STACK_VAR(P,"P");
			HX_STACK_LINE(100)
			Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(100)
			Float _g1 = P->get_x();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(100)
			Float _g2 = (_g - _g1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(100)
			Float _g3 = ::Math_obj::abs(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(100)
			Float _g4 = this->get_y();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(100)
			Float _g5 = P->get_y();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(100)
			Float _g6 = (_g4 - _g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(100)
			Float _g7 = ::Math_obj::abs(_g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(100)
			Float D = (_g3 + _g7);		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(101)
			if (((D < dist))){
				HX_STACK_LINE(103)
				ret = E;
				HX_STACK_LINE(104)
				dist = D;
			}
		}
		HX_STACK_LINE(107)
		(i)++;
	}
	HX_STACK_LINE(109)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,nearestplayer,return )

Void Entity_obj::rotateentity( Float rot){
{
		HX_STACK_FRAME("Entity","rotateentity",0xea1087c9,"Entity.rotateentity","Entity.hx",114,0x5c8a675b)
		HX_STACK_THIS(this)
		HX_STACK_ARG(rot,"rot")
		HX_STACK_LINE(115)
		::openfl::_v2::geom::Rectangle B = this->getBounds(::GameView_obj::_this);		HX_STACK_VAR(B,"B");
		HX_STACK_LINE(116)
		this->set_rotation(rot);
		HX_STACK_LINE(117)
		::openfl::_v2::geom::Rectangle B2 = this->getBounds(::GameView_obj::_this);		HX_STACK_VAR(B2,"B2");
		HX_STACK_LINE(118)
		{
			HX_STACK_LINE(118)
			::Entity _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(118)
			Float _g1 = _g->get_x();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(118)
			Float _g11 = B->get_left();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(118)
			Float _g2 = B2->get_left();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(118)
			Float _g3 = (_g11 - _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(118)
			Float _g4 = (_g1 + _g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(118)
			_g->set_x(_g4);
		}
		HX_STACK_LINE(119)
		{
			HX_STACK_LINE(119)
			::Entity _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(119)
			Float _g5 = _g->get_y();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(119)
			Float _g6 = B->get_top();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(119)
			Float _g7 = B2->get_top();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(119)
			Float _g8 = (_g6 - _g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(119)
			Float _g9 = (_g5 + _g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(119)
			_g->set_y(_g9);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,rotateentity,(void))

Void Entity_obj::updphysics( ){
{
		HX_STACK_FRAME("Entity","updphysics",0x55dc5589,"Entity.updphysics","Entity.hx",123,0x5c8a675b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(124)
		int dir = this->Ldir;		HX_STACK_VAR(dir,"dir");
		HX_STACK_LINE(125)
		if (((this->Hspeed > (int)0))){
			HX_STACK_LINE(127)
			dir = (int)1;
		}
		HX_STACK_LINE(129)
		if (((this->Hspeed < (int)0))){
			HX_STACK_LINE(131)
			dir = (int)-1;
		}
		HX_STACK_LINE(133)
		if (((this->Hspeed > (int)0))){
			HX_STACK_LINE(135)
			hx::SubEq(this->Hspeed,this->deccel);
			HX_STACK_LINE(136)
			if (((this->Hspeed < (int)0))){
				HX_STACK_LINE(138)
				this->Hspeed = (int)0;
			}
		}
		HX_STACK_LINE(141)
		if (((this->Hspeed < (int)0))){
			HX_STACK_LINE(143)
			hx::AddEq(this->Hspeed,this->deccel);
			HX_STACK_LINE(144)
			if (((this->Hspeed > (int)0))){
				HX_STACK_LINE(146)
				this->Hspeed = (int)0;
			}
		}
		HX_STACK_LINE(150)
		if (((this->Vspeed < (int)12))){
			HX_STACK_LINE(153)
			hx::AddEq(this->Vspeed,this->fallaccel);
		}
		HX_STACK_LINE(158)
		Float _g = this->get_rotation();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(158)
		if (((_g == (int)0))){
			HX_STACK_LINE(160)
			Float _g1 = this->get_x();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(160)
			Float _g2 = this->get_width();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(160)
			int _g3 = ::Math_obj::floor(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(160)
			int _g4 = (int(_g3) >> int((int)1));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(160)
			Float _g5 = (_g1 + _g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(160)
			Float _g6 = this->get_y();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(160)
			Float _g7 = this->get_height();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(160)
			Float _g8 = (_g7 + (int)2);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(160)
			Float _g9 = (_g6 + _g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(160)
			::Entity _g10 = ::GameView_obj::_this->CollisionDetectPoint(_g5,_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(160)
			this->ground = _g10;
		}
		else{
			HX_STACK_LINE(164)
			::openfl::_v2::geom::Rectangle B = this->getBounds(::GameView_obj::_this);		HX_STACK_VAR(B,"B");
			HX_STACK_LINE(165)
			Float _g11 = B->get_left();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(165)
			int _g12 = ::Math_obj::floor(B->width);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(165)
			int _g13 = (int(_g12) >> int((int)1));		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(165)
			Float _g14 = (_g11 + _g13);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(165)
			Float _g15 = B->get_bottom();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(165)
			Float _g16 = (_g15 + (int)2);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(165)
			::Entity _g17 = ::GameView_obj::_this->CollisionDetectPoint(_g14,_g16);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(165)
			this->ground = _g17;
		}
		HX_STACK_LINE(167)
		if (((this->ground == null()))){
		}
		HX_STACK_LINE(172)
		if (((this->ground != null()))){
			HX_STACK_LINE(174)
			if (((this->Vspeed > (int)0))){
				HX_STACK_LINE(176)
				this->bonking = false;
				HX_STACK_LINE(177)
				this->Vspeed = (int)0;
				HX_STACK_LINE(178)
				Float _g18 = this->ground->get_y();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(178)
				Float _g19 = this->get_height();		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(178)
				Float _g20 = (_g18 - _g19);		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(178)
				this->set_y(_g20);
			}
		}
		HX_STACK_LINE(181)
		this->headbonk = null();
		HX_STACK_LINE(182)
		if (((this->Vspeed < (int)0))){
			HX_STACK_LINE(184)
			Float _g21 = this->get_x();		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(184)
			Float _g22 = this->get_width();		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(184)
			int _g23 = ::Math_obj::floor(_g22);		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(184)
			int _g24 = (int(_g23) >> int((int)1));		HX_STACK_VAR(_g24,"_g24");
			HX_STACK_LINE(184)
			Float _g25 = (_g21 + _g24);		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(184)
			Float _g26 = this->get_y();		HX_STACK_VAR(_g26,"_g26");
			HX_STACK_LINE(184)
			Float _g27 = (_g26 + (int)20);		HX_STACK_VAR(_g27,"_g27");
			HX_STACK_LINE(184)
			::Entity _g28 = ::GameView_obj::_this->CollisionDetectPoint(_g25,_g27);		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(184)
			this->headbonk = _g28;
			HX_STACK_LINE(186)
			if (((bool((this->headbonk != null())) && bool(this->headbonk->platform)))){
				HX_STACK_LINE(188)
				this->headbonk = null();
			}
			HX_STACK_LINE(190)
			if (((this->headbonk != null()))){
				HX_STACK_LINE(192)
				hx::AddEq(this->Vspeed,this->fallaccel);
				HX_STACK_LINE(193)
				hx::AddEq(this->Vspeed,this->fallaccel);
				HX_STACK_LINE(194)
				if (((this->type != HX_CSTRING("Player")))){
					HX_STACK_LINE(196)
					this->Vspeed = (int)0;
				}
				HX_STACK_LINE(198)
				if ((!(this->bonking))){
					HX_STACK_LINE(200)
					this->bonking = true;
				}
				else{
					HX_STACK_LINE(205)
					this->headbonk = null();
				}
			}
		}
		HX_STACK_LINE(210)
		{
			HX_STACK_LINE(210)
			::Entity _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(210)
			Float _g29 = _g1->get_x();		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(210)
			Float _g30 = (_g29 + this->Hspeed);		HX_STACK_VAR(_g30,"_g30");
			HX_STACK_LINE(210)
			_g1->set_x(_g30);
		}
		HX_STACK_LINE(211)
		if (((bool((bool((this->headbonk == null())) && bool(!(this->bonking)))) || bool((this->Vspeed > (int)0))))){
			HX_STACK_LINE(213)
			::Entity _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(213)
			Float _g31 = _g1->get_y();		HX_STACK_VAR(_g31,"_g31");
			HX_STACK_LINE(213)
			Float _g32 = (_g31 + this->Vspeed);		HX_STACK_VAR(_g32,"_g32");
			HX_STACK_LINE(213)
			_g1->set_y(_g32);
		}
		HX_STACK_LINE(215)
		this->wrapped = false;
		HX_STACK_LINE(216)
		Float _g33 = this->get_x();		HX_STACK_VAR(_g33,"_g33");
		HX_STACK_LINE(216)
		Float _g34 = -(this->get_width());		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(216)
		if (((_g33 < _g34))){
			HX_STACK_LINE(218)
			this->wrapped = true;
			HX_STACK_LINE(219)
			{
				HX_STACK_LINE(219)
				::Entity _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(219)
				Float _g35 = _g1->get_x();		HX_STACK_VAR(_g35,"_g35");
				HX_STACK_LINE(219)
				Float _g36 = this->get_width();		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(219)
				Float _g37 = ((int)800 + _g36);		HX_STACK_VAR(_g37,"_g37");
				HX_STACK_LINE(219)
				Float _g38 = (_g35 + _g37);		HX_STACK_VAR(_g38,"_g38");
				HX_STACK_LINE(219)
				_g1->set_x(_g38);
			}
		}
		HX_STACK_LINE(221)
		Float _g39 = this->get_x();		HX_STACK_VAR(_g39,"_g39");
		HX_STACK_LINE(221)
		Float _g40 = this->get_width();		HX_STACK_VAR(_g40,"_g40");
		HX_STACK_LINE(221)
		Float _g41 = ((int)800 + _g40);		HX_STACK_VAR(_g41,"_g41");
		HX_STACK_LINE(221)
		if (((_g39 > _g41))){
			HX_STACK_LINE(223)
			this->wrapped = true;
			HX_STACK_LINE(224)
			{
				HX_STACK_LINE(224)
				::Entity _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(224)
				Float _g42 = _g1->get_x();		HX_STACK_VAR(_g42,"_g42");
				HX_STACK_LINE(224)
				Float _g43 = this->get_width();		HX_STACK_VAR(_g43,"_g43");
				HX_STACK_LINE(224)
				Float _g44 = ((int)800 + _g43);		HX_STACK_VAR(_g44,"_g44");
				HX_STACK_LINE(224)
				Float _g45 = this->get_width();		HX_STACK_VAR(_g45,"_g45");
				HX_STACK_LINE(224)
				Float _g46 = (_g44 + _g45);		HX_STACK_VAR(_g46,"_g46");
				HX_STACK_LINE(224)
				Float _g47 = (_g42 - _g46);		HX_STACK_VAR(_g47,"_g47");
				HX_STACK_LINE(224)
				_g1->set_x(_g47);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,updphysics,(void))

Void Entity_obj::catchup( ){
{
		HX_STACK_FRAME("Entity","catchup",0x1df42b2b,"Entity.catchup","Entity.hx",227,0x5c8a675b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(228)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(229)
		this->catchingup = true;
		HX_STACK_LINE(236)
		this->catchingup = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,catchup,(void))

Void Entity_obj::catchupsmall( ){
{
		HX_STACK_FRAME("Entity","catchupsmall",0xd6d369bc,"Entity.catchupsmall","Entity.hx",238,0x5c8a675b)
		HX_STACK_THIS(this)
		HX_STACK_LINE(239)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(240)
		this->catchingup = true;
		HX_STACK_LINE(248)
		this->catchingup = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,catchupsmall,(void))

Void Entity_obj::bump( ){
{
		HX_STACK_FRAME("Entity","bump",0x5d7e0501,"Entity.bump","Entity.hx",250,0x5c8a675b)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,bump,(void))


Entity_obj::Entity_obj()
{
}

void Entity_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Entity);
	HX_MARK_MEMBER_NAME(Hspeed,"Hspeed");
	HX_MARK_MEMBER_NAME(Vspeed,"Vspeed");
	HX_MARK_MEMBER_NAME(alive,"alive");
	HX_MARK_MEMBER_NAME(solid,"solid");
	HX_MARK_MEMBER_NAME(platform,"platform");
	HX_MARK_MEMBER_NAME(bonked,"bonked");
	HX_MARK_MEMBER_NAME(bonkedby,"bonkedby");
	HX_MARK_MEMBER_NAME(dangerous,"dangerous");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(killed,"killed");
	HX_MARK_MEMBER_NAME(UID,"UID");
	HX_MARK_MEMBER_NAME(Ldir,"Ldir");
	HX_MARK_MEMBER_NAME(ground,"ground");
	HX_MARK_MEMBER_NAME(headbonk,"headbonk");
	HX_MARK_MEMBER_NAME(wrapped,"wrapped");
	HX_MARK_MEMBER_NAME(deccel,"deccel");
	HX_MARK_MEMBER_NAME(touchable,"touchable");
	HX_MARK_MEMBER_NAME(catchingup,"catchingup");
	HX_MARK_MEMBER_NAME(fallaccel,"fallaccel");
	HX_MARK_MEMBER_NAME(bonking,"bonking");
	HX_MARK_MEMBER_NAME(hitbox,"hitbox");
	HX_MARK_MEMBER_NAME(icy,"icy");
	::Animation_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Entity_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(Hspeed,"Hspeed");
	HX_VISIT_MEMBER_NAME(Vspeed,"Vspeed");
	HX_VISIT_MEMBER_NAME(alive,"alive");
	HX_VISIT_MEMBER_NAME(solid,"solid");
	HX_VISIT_MEMBER_NAME(platform,"platform");
	HX_VISIT_MEMBER_NAME(bonked,"bonked");
	HX_VISIT_MEMBER_NAME(bonkedby,"bonkedby");
	HX_VISIT_MEMBER_NAME(dangerous,"dangerous");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(killed,"killed");
	HX_VISIT_MEMBER_NAME(UID,"UID");
	HX_VISIT_MEMBER_NAME(Ldir,"Ldir");
	HX_VISIT_MEMBER_NAME(ground,"ground");
	HX_VISIT_MEMBER_NAME(headbonk,"headbonk");
	HX_VISIT_MEMBER_NAME(wrapped,"wrapped");
	HX_VISIT_MEMBER_NAME(deccel,"deccel");
	HX_VISIT_MEMBER_NAME(touchable,"touchable");
	HX_VISIT_MEMBER_NAME(catchingup,"catchingup");
	HX_VISIT_MEMBER_NAME(fallaccel,"fallaccel");
	HX_VISIT_MEMBER_NAME(bonking,"bonking");
	HX_VISIT_MEMBER_NAME(hitbox,"hitbox");
	HX_VISIT_MEMBER_NAME(icy,"icy");
	::Animation_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Entity_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"UID") ) { return UID; }
		if (HX_FIELD_EQ(inName,"icy") ) { return icy; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"Ldir") ) { return Ldir; }
		if (HX_FIELD_EQ(inName,"bump") ) { return bump_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alive") ) { return alive; }
		if (HX_FIELD_EQ(inName,"solid") ) { return solid; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Hspeed") ) { return Hspeed; }
		if (HX_FIELD_EQ(inName,"Vspeed") ) { return Vspeed; }
		if (HX_FIELD_EQ(inName,"bonked") ) { return bonked; }
		if (HX_FIELD_EQ(inName,"killed") ) { return killed; }
		if (HX_FIELD_EQ(inName,"ground") ) { return ground; }
		if (HX_FIELD_EQ(inName,"deccel") ) { return deccel; }
		if (HX_FIELD_EQ(inName,"hitbox") ) { return hitbox; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"wrapped") ) { return wrapped; }
		if (HX_FIELD_EQ(inName,"bonking") ) { return bonking; }
		if (HX_FIELD_EQ(inName,"catchup") ) { return catchup_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"platform") ) { return platform; }
		if (HX_FIELD_EQ(inName,"bonkedby") ) { return bonkedby; }
		if (HX_FIELD_EQ(inName,"headbonk") ) { return headbonk; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"dangerous") ) { return dangerous; }
		if (HX_FIELD_EQ(inName,"touchable") ) { return touchable; }
		if (HX_FIELD_EQ(inName,"fallaccel") ) { return fallaccel; }
		if (HX_FIELD_EQ(inName,"GetHitbox") ) { return GetHitbox_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"catchingup") ) { return catchingup; }
		if (HX_FIELD_EQ(inName,"updphysics") ) { return updphysics_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"rotateentity") ) { return rotateentity_dyn(); }
		if (HX_FIELD_EQ(inName,"catchupsmall") ) { return catchupsmall_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"nearestplayer") ) { return nearestplayer_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"CollidesWithPoint") ) { return CollidesWithPoint_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Entity_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"UID") ) { UID=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"icy") ) { icy=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Ldir") ) { Ldir=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"alive") ) { alive=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"solid") ) { solid=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Hspeed") ) { Hspeed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Vspeed") ) { Vspeed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bonked") ) { bonked=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"killed") ) { killed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ground") ) { ground=inValue.Cast< ::Entity >(); return inValue; }
		if (HX_FIELD_EQ(inName,"deccel") ) { deccel=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hitbox") ) { hitbox=inValue.Cast< ::openfl::_v2::geom::Rectangle >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"wrapped") ) { wrapped=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bonking") ) { bonking=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"platform") ) { platform=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bonkedby") ) { bonkedby=inValue.Cast< ::Entity >(); return inValue; }
		if (HX_FIELD_EQ(inName,"headbonk") ) { headbonk=inValue.Cast< ::Entity >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"dangerous") ) { dangerous=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touchable") ) { touchable=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fallaccel") ) { fallaccel=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"catchingup") ) { catchingup=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Entity_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("Hspeed"));
	outFields->push(HX_CSTRING("Vspeed"));
	outFields->push(HX_CSTRING("alive"));
	outFields->push(HX_CSTRING("solid"));
	outFields->push(HX_CSTRING("platform"));
	outFields->push(HX_CSTRING("bonked"));
	outFields->push(HX_CSTRING("bonkedby"));
	outFields->push(HX_CSTRING("dangerous"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("killed"));
	outFields->push(HX_CSTRING("UID"));
	outFields->push(HX_CSTRING("Ldir"));
	outFields->push(HX_CSTRING("ground"));
	outFields->push(HX_CSTRING("headbonk"));
	outFields->push(HX_CSTRING("wrapped"));
	outFields->push(HX_CSTRING("deccel"));
	outFields->push(HX_CSTRING("touchable"));
	outFields->push(HX_CSTRING("catchingup"));
	outFields->push(HX_CSTRING("fallaccel"));
	outFields->push(HX_CSTRING("bonking"));
	outFields->push(HX_CSTRING("hitbox"));
	outFields->push(HX_CSTRING("icy"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Entity_obj,Hspeed),HX_CSTRING("Hspeed")},
	{hx::fsFloat,(int)offsetof(Entity_obj,Vspeed),HX_CSTRING("Vspeed")},
	{hx::fsBool,(int)offsetof(Entity_obj,alive),HX_CSTRING("alive")},
	{hx::fsBool,(int)offsetof(Entity_obj,solid),HX_CSTRING("solid")},
	{hx::fsBool,(int)offsetof(Entity_obj,platform),HX_CSTRING("platform")},
	{hx::fsInt,(int)offsetof(Entity_obj,bonked),HX_CSTRING("bonked")},
	{hx::fsObject /*::Entity*/ ,(int)offsetof(Entity_obj,bonkedby),HX_CSTRING("bonkedby")},
	{hx::fsBool,(int)offsetof(Entity_obj,dangerous),HX_CSTRING("dangerous")},
	{hx::fsString,(int)offsetof(Entity_obj,type),HX_CSTRING("type")},
	{hx::fsBool,(int)offsetof(Entity_obj,killed),HX_CSTRING("killed")},
	{hx::fsFloat,(int)offsetof(Entity_obj,UID),HX_CSTRING("UID")},
	{hx::fsInt,(int)offsetof(Entity_obj,Ldir),HX_CSTRING("Ldir")},
	{hx::fsObject /*::Entity*/ ,(int)offsetof(Entity_obj,ground),HX_CSTRING("ground")},
	{hx::fsObject /*::Entity*/ ,(int)offsetof(Entity_obj,headbonk),HX_CSTRING("headbonk")},
	{hx::fsBool,(int)offsetof(Entity_obj,wrapped),HX_CSTRING("wrapped")},
	{hx::fsFloat,(int)offsetof(Entity_obj,deccel),HX_CSTRING("deccel")},
	{hx::fsBool,(int)offsetof(Entity_obj,touchable),HX_CSTRING("touchable")},
	{hx::fsBool,(int)offsetof(Entity_obj,catchingup),HX_CSTRING("catchingup")},
	{hx::fsFloat,(int)offsetof(Entity_obj,fallaccel),HX_CSTRING("fallaccel")},
	{hx::fsBool,(int)offsetof(Entity_obj,bonking),HX_CSTRING("bonking")},
	{hx::fsObject /*::openfl::_v2::geom::Rectangle*/ ,(int)offsetof(Entity_obj,hitbox),HX_CSTRING("hitbox")},
	{hx::fsBool,(int)offsetof(Entity_obj,icy),HX_CSTRING("icy")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Hspeed"),
	HX_CSTRING("Vspeed"),
	HX_CSTRING("alive"),
	HX_CSTRING("solid"),
	HX_CSTRING("platform"),
	HX_CSTRING("bonked"),
	HX_CSTRING("bonkedby"),
	HX_CSTRING("dangerous"),
	HX_CSTRING("type"),
	HX_CSTRING("killed"),
	HX_CSTRING("UID"),
	HX_CSTRING("Ldir"),
	HX_CSTRING("ground"),
	HX_CSTRING("headbonk"),
	HX_CSTRING("wrapped"),
	HX_CSTRING("deccel"),
	HX_CSTRING("touchable"),
	HX_CSTRING("catchingup"),
	HX_CSTRING("fallaccel"),
	HX_CSTRING("bonking"),
	HX_CSTRING("hitbox"),
	HX_CSTRING("icy"),
	HX_CSTRING("GetHitbox"),
	HX_CSTRING("CollidesWithPoint"),
	HX_CSTRING("update"),
	HX_CSTRING("nearestplayer"),
	HX_CSTRING("rotateentity"),
	HX_CSTRING("updphysics"),
	HX_CSTRING("catchup"),
	HX_CSTRING("catchupsmall"),
	HX_CSTRING("bump"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Entity_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Entity_obj::__mClass,"__mClass");
};

#endif

Class Entity_obj::__mClass;

void Entity_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Entity"), hx::TCanCast< Entity_obj> ,sStaticFields,sMemberFields,
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

void Entity_obj::__boot()
{
}

