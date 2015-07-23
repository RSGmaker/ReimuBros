#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Animationloader
#include <Animationloader.h>
#endif
#ifndef INCLUDED_Block
#include <Block.h>
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

Void Block_obj::__construct(::String ani)
{
HX_STACK_FRAME("Block","new",0xdb44209f,"Block.new","Block.hx",13,0xf33517b1)
HX_STACK_THIS(this)
HX_STACK_ARG(ani,"ani")
{
	HX_STACK_LINE(14)
	super::__construct(ani);
	HX_STACK_LINE(15)
	this->set_visible(false);
	HX_STACK_LINE(16)
	::Entity _g = ::Entity_obj::__new(ani);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(16)
	this->Visual = _g;
	HX_STACK_LINE(17)
	::GameView_obj::_this->addChild(this->Visual);
	HX_STACK_LINE(18)
	::Entity _g1 = ::Entity_obj::__new(HX_CSTRING("flames"));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(18)
	this->Flames = _g1;
	HX_STACK_LINE(19)
	this->Flames->set_visible(false);
	HX_STACK_LINE(20)
	this->Flames->image_speed = 0.5;
	HX_STACK_LINE(21)
	::GameView_obj::_this->addChild(this->Flames);
	HX_STACK_LINE(22)
	this->type = HX_CSTRING("Block");
	HX_STACK_LINE(23)
	this->UID = ((int)-100 - ::GameView_obj::_this->entities->length);
	HX_STACK_LINE(24)
	this->started = false;
}
;
	return null();
}

//Block_obj::~Block_obj() { }

Dynamic Block_obj::__CreateEmpty() { return  new Block_obj; }
hx::ObjectPtr< Block_obj > Block_obj::__new(::String ani)
{  hx::ObjectPtr< Block_obj > result = new Block_obj();
	result->__construct(ani);
	return result;}

Dynamic Block_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Block_obj > result = new Block_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Block_obj::Burn( ){
{
		HX_STACK_FRAME("Block","Burn",0xe34f2750,"Block.Burn","Block.hx",30,0xf33517b1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(30)
		if ((this->solid)){
			HX_STACK_LINE(32)
			this->dangerous = true;
			HX_STACK_LINE(33)
			if ((this->icy)){
				HX_STACK_LINE(35)
				this->icy = false;
				HX_STACK_LINE(36)
				this->Visual->ChangeAnimation(this->animation);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Block_obj,Burn,(void))

Void Block_obj::Freeze( ){
{
		HX_STACK_FRAME("Block","Freeze",0x897f1f98,"Block.Freeze","Block.hx",42,0xf33517b1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(42)
		if ((!(this->icy))){
			HX_STACK_LINE(44)
			this->dangerous = false;
			HX_STACK_LINE(45)
			this->icy = true;
			HX_STACK_LINE(46)
			Array< ::Dynamic > _g = ::GameView_obj::_this->AL->GetAnimation(HX_CSTRING("icyblock"));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(46)
			this->Visual->ChangeAnimation(_g);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Block_obj,Freeze,(void))

Void Block_obj::Defrost( ){
{
		HX_STACK_FRAME("Block","Defrost",0xdbe3f582,"Block.Defrost","Block.hx",50,0xf33517b1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(51)
		this->dangerous = false;
		HX_STACK_LINE(52)
		if ((this->icy)){
			HX_STACK_LINE(55)
			this->icy = false;
			HX_STACK_LINE(56)
			this->Visual->ChangeAnimation(this->animation);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Block_obj,Defrost,(void))

Void Block_obj::update( ){
{
		HX_STACK_FRAME("Block","update",0x2ccba72a,"Block.update","Block.hx",60,0xf33517b1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(61)
		if ((!(this->started))){
			HX_STACK_LINE(63)
			Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(63)
			Float _g1 = (_g - (int)10);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(63)
			this->Flames->set_x(_g1);
			HX_STACK_LINE(64)
			Float _g2 = this->get_y();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(64)
			Float _g3 = (_g2 - (int)20);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(64)
			this->Flames->set_y(_g3);
		}
		HX_STACK_LINE(66)
		this->Flames->set_visible(this->dangerous);
		HX_STACK_LINE(67)
		this->Flames->update();
		HX_STACK_LINE(68)
		this->Visual->set_visible(this->solid);
		HX_STACK_LINE(69)
		if ((!(this->solid))){
			HX_STACK_LINE(71)
			this->Flames->set_visible(false);
			HX_STACK_LINE(72)
			this->dangerous = false;
		}
		HX_STACK_LINE(74)
		Float _g4 = this->get_x();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(74)
		this->Visual->set_x(_g4);
		HX_STACK_LINE(75)
		if (((this->bonked == (int)-1000))){
			HX_STACK_LINE(77)
			Float _g5 = this->get_y();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(77)
			this->Visual->set_y(_g5);
		}
		HX_STACK_LINE(79)
		if (((this->bonked > (int)0))){
			HX_STACK_LINE(81)
			{
				HX_STACK_LINE(81)
				::Entity _g = this->Visual;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(81)
				Float _g6 = _g->get_y();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(81)
				Float _g7 = (_g6 - (int)2);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(81)
				_g->set_y(_g7);
			}
			HX_STACK_LINE(82)
			hx::SubEq(this->bonked,(int)1);
			HX_STACK_LINE(83)
			this->Defrost();
		}
		else{
			HX_STACK_LINE(88)
			Float _g8 = this->Visual->get_y();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(88)
			Float _g9 = this->get_y();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(88)
			if (((_g8 < _g9))){
				HX_STACK_LINE(90)
				{
					HX_STACK_LINE(90)
					::Entity _g = this->Visual;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(90)
					Float _g10 = _g->get_y();		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(90)
					Float _g11 = (_g10 + (int)2);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(90)
					_g->set_y(_g11);
				}
				HX_STACK_LINE(91)
				hx::SubEq(this->bonked,(int)1);
			}
			else{
				HX_STACK_LINE(95)
				Float _g12 = this->get_y();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(95)
				this->Visual->set_y(_g12);
				HX_STACK_LINE(96)
				this->bonked = (int)-1000;
			}
		}
	}
return null();
}



Block_obj::Block_obj()
{
}

void Block_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Block);
	HX_MARK_MEMBER_NAME(Visual,"Visual");
	HX_MARK_MEMBER_NAME(Flames,"Flames");
	HX_MARK_MEMBER_NAME(started,"started");
	::Entity_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Block_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(Visual,"Visual");
	HX_VISIT_MEMBER_NAME(Flames,"Flames");
	HX_VISIT_MEMBER_NAME(started,"started");
	::Entity_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Block_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Burn") ) { return Burn_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Visual") ) { return Visual; }
		if (HX_FIELD_EQ(inName,"Flames") ) { return Flames; }
		if (HX_FIELD_EQ(inName,"Freeze") ) { return Freeze_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"started") ) { return started; }
		if (HX_FIELD_EQ(inName,"Defrost") ) { return Defrost_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Block_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"Visual") ) { Visual=inValue.Cast< ::Entity >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Flames") ) { Flames=inValue.Cast< ::Entity >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"started") ) { started=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Block_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("Visual"));
	outFields->push(HX_CSTRING("Flames"));
	outFields->push(HX_CSTRING("started"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Entity*/ ,(int)offsetof(Block_obj,Visual),HX_CSTRING("Visual")},
	{hx::fsObject /*::Entity*/ ,(int)offsetof(Block_obj,Flames),HX_CSTRING("Flames")},
	{hx::fsBool,(int)offsetof(Block_obj,started),HX_CSTRING("started")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Visual"),
	HX_CSTRING("Flames"),
	HX_CSTRING("started"),
	HX_CSTRING("Burn"),
	HX_CSTRING("Freeze"),
	HX_CSTRING("Defrost"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Block_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Block_obj::__mClass,"__mClass");
};

#endif

Class Block_obj::__mClass;

void Block_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Block"), hx::TCanCast< Block_obj> ,sStaticFields,sMemberFields,
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

void Block_obj::__boot()
{
}

