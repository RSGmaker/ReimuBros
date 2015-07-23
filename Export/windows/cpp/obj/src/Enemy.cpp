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

Void Enemy_obj::__construct(::String ani)
{
HX_STACK_FRAME("Enemy","new",0x35d4571a,"Enemy.new","Enemy.hx",32,0xbda88996)
HX_STACK_THIS(this)
HX_STACK_ARG(ani,"ani")
{
	HX_STACK_LINE(33)
	super::__construct(ani);
	HX_STACK_LINE(34)
	this->type = HX_CSTRING("Enemy");
	HX_STACK_LINE(35)
	this->killable = false;
	HX_STACK_LINE(37)
	this->charname = ani;
	HX_STACK_LINE(38)
	this->flipped = (int)-1;
	HX_STACK_LINE(39)
	this->touchable = true;
	HX_STACK_LINE(40)
	this->reward = true;
	HX_STACK_LINE(41)
	this->pointvalue = (int)100;
	HX_STACK_LINE(42)
	this->respawn = true;
	HX_STACK_LINE(43)
	this->HP = (int)0;
	HX_STACK_LINE(44)
	this->started = false;
	HX_STACK_LINE(45)
	this->rank = ::GameView_obj::_this->rank;
	HX_STACK_LINE(46)
	this->currentrank = (int)0;
	HX_STACK_LINE(47)
	this->visuallyEnraged = false;
}
;
	return null();
}

//Enemy_obj::~Enemy_obj() { }

Dynamic Enemy_obj::__CreateEmpty() { return  new Enemy_obj; }
hx::ObjectPtr< Enemy_obj > Enemy_obj::__new(::String ani)
{  hx::ObjectPtr< Enemy_obj > result = new Enemy_obj();
	result->__construct(ani);
	return result;}

Dynamic Enemy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Enemy_obj > result = new Enemy_obj();
	result->__construct(inArgs[0]);
	return result;}

int Enemy_obj::getdangerlevel( ){
	HX_STACK_FRAME("Enemy","getdangerlevel",0x9f8d0671,"Enemy.getdangerlevel","Enemy.hx",55,0xbda88996)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->rank;
}


HX_DEFINE_DYNAMIC_FUNC0(Enemy_obj,getdangerlevel,return )

Void Enemy_obj::powerup( ){
{
		HX_STACK_FRAME("Enemy","powerup",0x1a8ce95a,"Enemy.powerup","Enemy.hx",60,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(60)
		if (((this->rank < (::GameView_obj::_this->rank + (int)2)))){
			HX_STACK_LINE(62)
			(this->rank)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Enemy_obj,powerup,(void))

Void Enemy_obj::increaserank( ){
{
		HX_STACK_FRAME("Enemy","increaserank",0x2f6d6474,"Enemy.increaserank","Enemy.hx",66,0xbda88996)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Enemy_obj,increaserank,(void))

Void Enemy_obj::setrank( int r){
{
		HX_STACK_FRAME("Enemy","setrank",0xe612ce08,"Enemy.setrank","Enemy.hx",70,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(71)
		r = (r - this->currentrank);
		HX_STACK_LINE(72)
		while((true)){
			HX_STACK_LINE(72)
			if ((!(((r > (int)0))))){
				HX_STACK_LINE(72)
				break;
			}
			HX_STACK_LINE(75)
			this->increaserank();
			HX_STACK_LINE(77)
			(r)--;
			HX_STACK_LINE(78)
			(this->currentrank)++;
		}
		HX_STACK_LINE(80)
		this->rank = this->currentrank;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Enemy_obj,setrank,(void))

Void Enemy_obj::enrage( ){
{
		HX_STACK_FRAME("Enemy","enrage",0x4bcc71fc,"Enemy.enrage","Enemy.hx",84,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(84)
		if (((this->rank < (::GameView_obj::_this->rank + (int)2)))){
			HX_STACK_LINE(86)
			this->rank = (::GameView_obj::_this->rank + (int)2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Enemy_obj,enrage,(void))

Void Enemy_obj::updateanimation( ::String __o_name){
::String name = __o_name.Default(HX_CSTRING(""));
	HX_STACK_FRAME("Enemy","updateanimation",0xddf99595,"Enemy.updateanimation","Enemy.hx",90,0xbda88996)
	HX_STACK_THIS(this)
	HX_STACK_ARG(name,"name")
{
		HX_STACK_LINE(91)
		if (((name == HX_CSTRING("")))){
			HX_STACK_LINE(93)
			name = this->charname;
		}
		HX_STACK_LINE(95)
		if (((this->currentrank < this->rank))){
			HX_STACK_LINE(97)
			this->setrank(this->rank);
		}
		HX_STACK_LINE(99)
		if (((this->rank < ::GameView_obj::_this->rank))){
			HX_STACK_LINE(101)
			this->rank = ::GameView_obj::_this->rank;
		}
		HX_STACK_LINE(103)
		::String C = name;		HX_STACK_VAR(C,"C");
		HX_STACK_LINE(104)
		if (((this->flipped >= (int)1))){
			HX_STACK_LINE(106)
			C = (C + HX_CSTRING("flipped"));
		}
		HX_STACK_LINE(110)
		bool enr = (bool(this->visuallyEnraged) || bool(this->enraged));		HX_STACK_VAR(enr,"enr");
		HX_STACK_LINE(111)
		if (((this->rank == (::GameView_obj::_this->rank + (int)1)))){
			HX_STACK_LINE(113)
			if ((!(enr))){
				HX_STACK_LINE(115)
				C = (C + HX_CSTRING("S"));
			}
		}
		HX_STACK_LINE(118)
		if (((this->rank > (::GameView_obj::_this->rank + (int)1)))){
			HX_STACK_LINE(120)
			this->enraged = true;
			HX_STACK_LINE(121)
			enr = true;
		}
		HX_STACK_LINE(123)
		if ((enr)){
			HX_STACK_LINE(125)
			C = (C + HX_CSTRING("E"));
		}
		HX_STACK_LINE(129)
		if (((this->Ldir > (int)0))){
			HX_STACK_LINE(131)
			Array< ::Dynamic > _g = ::GameView_obj::_this->AL->GetAnimation(C);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(131)
			this->ChangeAnimation(_g);
		}
		HX_STACK_LINE(133)
		if (((this->Ldir < (int)0))){
			HX_STACK_LINE(135)
			Array< ::Dynamic > _g1 = ::GameView_obj::_this->AL->GetAnimation((C + HX_CSTRING("F")));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(135)
			this->ChangeAnimation(_g1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Enemy_obj,updateanimation,(void))


Enemy_obj::Enemy_obj()
{
}

void Enemy_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Enemy);
	HX_MARK_MEMBER_NAME(killable,"killable");
	HX_MARK_MEMBER_NAME(charname,"charname");
	HX_MARK_MEMBER_NAME(flipped,"flipped");
	HX_MARK_MEMBER_NAME(enraged,"enraged");
	HX_MARK_MEMBER_NAME(visuallyEnraged,"visuallyEnraged");
	HX_MARK_MEMBER_NAME(reward,"reward");
	HX_MARK_MEMBER_NAME(pointvalue,"pointvalue");
	HX_MARK_MEMBER_NAME(respawn,"respawn");
	HX_MARK_MEMBER_NAME(rank,"rank");
	HX_MARK_MEMBER_NAME(HP,"HP");
	HX_MARK_MEMBER_NAME(started,"started");
	HX_MARK_MEMBER_NAME(currentrank,"currentrank");
	::Entity_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Enemy_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(killable,"killable");
	HX_VISIT_MEMBER_NAME(charname,"charname");
	HX_VISIT_MEMBER_NAME(flipped,"flipped");
	HX_VISIT_MEMBER_NAME(enraged,"enraged");
	HX_VISIT_MEMBER_NAME(visuallyEnraged,"visuallyEnraged");
	HX_VISIT_MEMBER_NAME(reward,"reward");
	HX_VISIT_MEMBER_NAME(pointvalue,"pointvalue");
	HX_VISIT_MEMBER_NAME(respawn,"respawn");
	HX_VISIT_MEMBER_NAME(rank,"rank");
	HX_VISIT_MEMBER_NAME(HP,"HP");
	HX_VISIT_MEMBER_NAME(started,"started");
	HX_VISIT_MEMBER_NAME(currentrank,"currentrank");
	::Entity_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Enemy_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"HP") ) { return HP; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rank") ) { return rank; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"reward") ) { return reward; }
		if (HX_FIELD_EQ(inName,"enrage") ) { return enrage_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"flipped") ) { return flipped; }
		if (HX_FIELD_EQ(inName,"enraged") ) { return enraged; }
		if (HX_FIELD_EQ(inName,"respawn") ) { return respawn; }
		if (HX_FIELD_EQ(inName,"started") ) { return started; }
		if (HX_FIELD_EQ(inName,"powerup") ) { return powerup_dyn(); }
		if (HX_FIELD_EQ(inName,"setrank") ) { return setrank_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"killable") ) { return killable; }
		if (HX_FIELD_EQ(inName,"charname") ) { return charname; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"pointvalue") ) { return pointvalue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentrank") ) { return currentrank; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"increaserank") ) { return increaserank_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getdangerlevel") ) { return getdangerlevel_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"visuallyEnraged") ) { return visuallyEnraged; }
		if (HX_FIELD_EQ(inName,"updateanimation") ) { return updateanimation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Enemy_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"HP") ) { HP=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rank") ) { rank=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"reward") ) { reward=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"flipped") ) { flipped=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"enraged") ) { enraged=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"respawn") ) { respawn=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"started") ) { started=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"killable") ) { killable=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"charname") ) { charname=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"pointvalue") ) { pointvalue=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentrank") ) { currentrank=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"visuallyEnraged") ) { visuallyEnraged=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Enemy_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("killable"));
	outFields->push(HX_CSTRING("charname"));
	outFields->push(HX_CSTRING("flipped"));
	outFields->push(HX_CSTRING("enraged"));
	outFields->push(HX_CSTRING("visuallyEnraged"));
	outFields->push(HX_CSTRING("reward"));
	outFields->push(HX_CSTRING("pointvalue"));
	outFields->push(HX_CSTRING("respawn"));
	outFields->push(HX_CSTRING("rank"));
	outFields->push(HX_CSTRING("HP"));
	outFields->push(HX_CSTRING("started"));
	outFields->push(HX_CSTRING("currentrank"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Enemy_obj,killable),HX_CSTRING("killable")},
	{hx::fsString,(int)offsetof(Enemy_obj,charname),HX_CSTRING("charname")},
	{hx::fsInt,(int)offsetof(Enemy_obj,flipped),HX_CSTRING("flipped")},
	{hx::fsBool,(int)offsetof(Enemy_obj,enraged),HX_CSTRING("enraged")},
	{hx::fsBool,(int)offsetof(Enemy_obj,visuallyEnraged),HX_CSTRING("visuallyEnraged")},
	{hx::fsBool,(int)offsetof(Enemy_obj,reward),HX_CSTRING("reward")},
	{hx::fsInt,(int)offsetof(Enemy_obj,pointvalue),HX_CSTRING("pointvalue")},
	{hx::fsBool,(int)offsetof(Enemy_obj,respawn),HX_CSTRING("respawn")},
	{hx::fsInt,(int)offsetof(Enemy_obj,rank),HX_CSTRING("rank")},
	{hx::fsInt,(int)offsetof(Enemy_obj,HP),HX_CSTRING("HP")},
	{hx::fsBool,(int)offsetof(Enemy_obj,started),HX_CSTRING("started")},
	{hx::fsInt,(int)offsetof(Enemy_obj,currentrank),HX_CSTRING("currentrank")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("killable"),
	HX_CSTRING("charname"),
	HX_CSTRING("flipped"),
	HX_CSTRING("enraged"),
	HX_CSTRING("visuallyEnraged"),
	HX_CSTRING("reward"),
	HX_CSTRING("pointvalue"),
	HX_CSTRING("respawn"),
	HX_CSTRING("rank"),
	HX_CSTRING("HP"),
	HX_CSTRING("started"),
	HX_CSTRING("currentrank"),
	HX_CSTRING("getdangerlevel"),
	HX_CSTRING("powerup"),
	HX_CSTRING("increaserank"),
	HX_CSTRING("setrank"),
	HX_CSTRING("enrage"),
	HX_CSTRING("updateanimation"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Enemy_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Enemy_obj::__mClass,"__mClass");
};

#endif

Class Enemy_obj::__mClass;

void Enemy_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Enemy"), hx::TCanCast< Enemy_obj> ,sStaticFields,sMemberFields,
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

void Enemy_obj::__boot()
{
}

