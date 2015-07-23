#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_OptionView
#include <OptionView.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Graphics
#include <openfl/_v2/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Shape
#include <openfl/_v2/display/Shape.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_Event
#include <openfl/_v2/events/Event.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_KeyboardEvent
#include <openfl/_v2/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_events_MouseEvent
#include <openfl/_v2/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_net_SharedObject
#include <openfl/_v2/net/SharedObject.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextFormat
#include <openfl/_v2/text/TextFormat.h>
#endif

Void OptionView_obj::__construct()
{
HX_STACK_FRAME("OptionView","new",0x8c668a8c,"OptionView.new","OptionView.hx",42,0x01c70a64)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(41)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(43)
	super::__construct();
	HX_STACK_LINE(44)
	this->selection = (int)-1;
	HX_STACK_LINE(45)
	::openfl::_v2::display::Shape rectangleShape = ::openfl::_v2::display::Shape_obj::__new();		HX_STACK_VAR(rectangleShape,"rectangleShape");
	HX_STACK_LINE(46)
	rectangleShape->get_graphics()->beginFill((int)0,null());
	HX_STACK_LINE(47)
	rectangleShape->get_graphics()->drawRect((int)0,(int)0,(int)800,(int)600);
	HX_STACK_LINE(48)
	rectangleShape->get_graphics()->endFill();
	HX_STACK_LINE(49)
	this->addChild(rectangleShape);
	HX_STACK_LINE(50)
	::openfl::_v2::text::TextField T = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(T,"T");
	HX_STACK_LINE(51)
	T->set_x((int)0);
	HX_STACK_LINE(52)
	T->set_y((int)30);
	HX_STACK_LINE(53)
	T->set_text(HX_CSTRING("SoundVolume:"));
	HX_STACK_LINE(54)
	T->set_scaleX(1.5);
	HX_STACK_LINE(55)
	T->set_scaleY(1.5);
	HX_STACK_LINE(56)
	T->set_textColor((int)16777215);
	HX_STACK_LINE(57)
	this->addChild(T);
	HX_STACK_LINE(58)
	Array< int > XX = Array_obj< int >::__new().Add((int)120);		HX_STACK_VAR(XX,"XX");
	HX_STACK_LINE(59)
	Array< int > YY = Array_obj< int >::__new().Add((int)20);		HX_STACK_VAR(YY,"YY");
	HX_STACK_LINE(60)
	::openfl::_v2::display::Sprite _g1 = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(60)
	this->sndmeter = _g1;
	HX_STACK_LINE(61)
	this->sndmeter->get_graphics()->beginFill((int)3355443,null());
	HX_STACK_LINE(62)
	this->sndmeter->get_graphics()->drawRect(XX->__get((int)0),YY->__get((int)0),(int)200,(int)50);
	HX_STACK_LINE(63)
	this->sndmeter->get_graphics()->endFill();
	HX_STACK_LINE(65)
	this->sndmeter->get_graphics()->beginFill((int)43554,null());
	HX_STACK_LINE(66)
	this->sndmeter->get_graphics()->drawRect(XX->__get((int)0),YY->__get((int)0),(::Main_obj::_this->savedata->data->__Field(HX_CSTRING("soundvolume"),true) * (int)200),(int)50);
	HX_STACK_LINE(67)
	this->sndmeter->get_graphics()->endFill();
	HX_STACK_LINE(68)
	this->addChild(this->sndmeter);
	HX_STACK_LINE(69)
	Array< int > X1 = Array_obj< int >::__new().Add(XX->__get((int)0));		HX_STACK_VAR(X1,"X1");
	HX_STACK_LINE(70)
	Array< int > Y1 = Array_obj< int >::__new().Add(YY->__get((int)0));		HX_STACK_VAR(Y1,"Y1");

	HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g,Array< int >,X1,Array< int >,Y1)
	Void run(Dynamic ev){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","OptionView.hx",71,0x01c70a64)
		HX_STACK_ARG(ev,"ev")
		{
			HX_STACK_LINE(74)
			Float X = (Float(((_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_mouseX() - X1->__get((int)0)))) / Float(200.0));		HX_STACK_VAR(X,"X");
			HX_STACK_LINE(75)
			::SoundManager_obj::_this->SetSoundVolume(X);
			HX_STACK_LINE(76)
			X = ::SoundManager_obj::_this->GetSoundVolume();
			HX_STACK_LINE(77)
			_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_graphics()->clear();
			HX_STACK_LINE(78)
			::Main_obj::_this->savedata->data->__FieldRef(HX_CSTRING("soundvolume")) = X;
			HX_STACK_LINE(79)
			_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_graphics()->beginFill((int)3355443,null());
			HX_STACK_LINE(80)
			_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_graphics()->drawRect(X1->__get((int)0),Y1->__get((int)0),(int)200,(int)50);
			HX_STACK_LINE(81)
			_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_graphics()->endFill();
			HX_STACK_LINE(83)
			_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_graphics()->beginFill((int)43554,null());
			HX_STACK_LINE(84)
			_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_graphics()->drawRect(X1->__get((int)0),Y1->__get((int)0),(X * (int)200),(int)50);
			HX_STACK_LINE(85)
			_g->__get((int)0).StaticCast< ::OptionView >()->sndmeter->get_graphics()->endFill();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(71)
	this->sndmeter->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_1(_g,X1,Y1)),null(),null(),null());
	HX_STACK_LINE(89)
	::openfl::_v2::text::TextField _g11 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(89)
	T = _g11;
	HX_STACK_LINE(90)
	T->set_x((int)0);
	HX_STACK_LINE(91)
	T->set_y((int)130);
	HX_STACK_LINE(92)
	T->set_text(HX_CSTRING("MusicVolume:"));
	HX_STACK_LINE(93)
	T->set_scaleX(1.5);
	HX_STACK_LINE(94)
	T->set_scaleY(1.5);
	HX_STACK_LINE(95)
	T->set_textColor((int)16777215);
	HX_STACK_LINE(96)
	this->addChild(T);
	HX_STACK_LINE(97)
	XX[(int)0] = (int)120;
	HX_STACK_LINE(98)
	YY[(int)0] = (int)120;
	HX_STACK_LINE(99)
	::openfl::_v2::display::Sprite _g2 = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(99)
	this->musicmeter = _g2;
	HX_STACK_LINE(100)
	this->musicmeter->get_graphics()->beginFill((int)3355443,null());
	HX_STACK_LINE(101)
	this->musicmeter->get_graphics()->drawRect(XX->__get((int)0),YY->__get((int)0),(int)200,(int)50);
	HX_STACK_LINE(102)
	this->musicmeter->get_graphics()->endFill();
	HX_STACK_LINE(104)
	this->musicmeter->get_graphics()->beginFill((int)43554,null());
	HX_STACK_LINE(105)
	this->musicmeter->get_graphics()->drawRect(XX->__get((int)0),YY->__get((int)0),(::Main_obj::_this->savedata->data->__Field(HX_CSTRING("musicvolume"),true) * (int)200),(int)50);
	HX_STACK_LINE(106)
	this->musicmeter->get_graphics()->endFill();
	HX_STACK_LINE(107)
	this->addChild(this->musicmeter);

	HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,_g,Array< int >,YY,Array< int >,XX)
	Void run(Dynamic ev){
		HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","OptionView.hx",108,0x01c70a64)
		HX_STACK_ARG(ev,"ev")
		{
			HX_STACK_LINE(111)
			Float X = (Float(((_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_mouseX() - XX->__get((int)0)))) / Float(200.0));		HX_STACK_VAR(X,"X");
			HX_STACK_LINE(112)
			::SoundManager_obj::_this->SetMusicVolume(X);
			HX_STACK_LINE(113)
			X = ::SoundManager_obj::_this->GetMusicVolume();
			HX_STACK_LINE(114)
			_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_graphics()->clear();
			HX_STACK_LINE(115)
			::Main_obj::_this->savedata->data->__FieldRef(HX_CSTRING("musicvolume")) = X;
			HX_STACK_LINE(116)
			_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_graphics()->beginFill((int)3355443,null());
			HX_STACK_LINE(117)
			_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_graphics()->drawRect(XX->__get((int)0),YY->__get((int)0),(int)200,(int)50);
			HX_STACK_LINE(118)
			_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_graphics()->endFill();
			HX_STACK_LINE(120)
			_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_graphics()->beginFill((int)43554,null());
			HX_STACK_LINE(121)
			_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_graphics()->drawRect(XX->__get((int)0),YY->__get((int)0),(X * (int)200),(int)50);
			HX_STACK_LINE(122)
			_g->__get((int)0).StaticCast< ::OptionView >()->musicmeter->get_graphics()->endFill();
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(108)
	this->musicmeter->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_2(_g,YY,XX)),null(),null(),null());
	HX_STACK_LINE(125)
	::openfl::_v2::text::TextField _g3 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(125)
	T = _g3;
	HX_STACK_LINE(126)
	T->set_x((int)0);
	HX_STACK_LINE(127)
	T->set_y((int)250);
	HX_STACK_LINE(128)
	T->set_text(HX_CSTRING("Jump:"));
	HX_STACK_LINE(129)
	T->set_scaleX(1.5);
	HX_STACK_LINE(130)
	T->set_scaleY(1.5);
	HX_STACK_LINE(131)
	T->set_textColor((int)16777215);
	HX_STACK_LINE(132)
	T->set_mouseEnabled(false);
	HX_STACK_LINE(133)
	this->addChild(T);
	HX_STACK_LINE(134)
	::String _g4 = this->stringfromcode(::Main_obj::_this->savedata->data->__Field(HX_CSTRING("controlscheme"),true)->__GetItem((int)0));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(134)
	::openfl::_v2::display::Sprite B = this->AddButton(_g4);		HX_STACK_VAR(B,"B");
	HX_STACK_LINE(135)
	B->set_x((int)70);
	HX_STACK_LINE(136)
	B->set_y((int)250);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_3,Array< ::Dynamic >,_g)
	Void run(Dynamic ev){
		HX_STACK_FRAME("*","_Function_1_3",0x5200ed39,"*._Function_1_3","OptionView.hx",139,0x01c70a64)
		HX_STACK_ARG(ev,"ev")
		{
			HX_STACK_LINE(139)
			_g->__get((int)0).StaticCast< ::OptionView >()->selection = (int)0;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(137)
	B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_3(_g)),null(),null(),null());
	HX_STACK_LINE(142)
	::openfl::_v2::text::TextField _g5 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(142)
	T = _g5;
	HX_STACK_LINE(143)
	T->set_x((int)130);
	HX_STACK_LINE(144)
	T->set_y((int)250);
	HX_STACK_LINE(145)
	T->set_text(HX_CSTRING("Throw:"));
	HX_STACK_LINE(146)
	T->set_scaleX(1.5);
	HX_STACK_LINE(147)
	T->set_scaleY(1.5);
	HX_STACK_LINE(148)
	T->set_textColor((int)16777215);
	HX_STACK_LINE(149)
	T->set_mouseEnabled(false);
	HX_STACK_LINE(150)
	this->addChild(T);
	HX_STACK_LINE(151)
	::String _g6 = this->stringfromcode(::Main_obj::_this->savedata->data->__Field(HX_CSTRING("controlscheme"),true)->__GetItem((int)1));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(151)
	::openfl::_v2::display::Sprite _g7 = this->AddButton(_g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(151)
	B = _g7;
	HX_STACK_LINE(152)
	B->set_x((int)210);
	HX_STACK_LINE(153)
	B->set_y((int)250);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_4,Array< ::Dynamic >,_g)
	Void run(Dynamic ev){
		HX_STACK_FRAME("*","_Function_1_4",0x5200ed3a,"*._Function_1_4","OptionView.hx",156,0x01c70a64)
		HX_STACK_ARG(ev,"ev")
		{
			HX_STACK_LINE(156)
			_g->__get((int)0).StaticCast< ::OptionView >()->selection = (int)1;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(154)
	B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_4(_g)),null(),null(),null());
	HX_STACK_LINE(160)
	::openfl::_v2::text::TextField _g8 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(160)
	T = _g8;
	HX_STACK_LINE(161)
	T->set_x((int)0);
	HX_STACK_LINE(162)
	T->set_y((int)350);
	HX_STACK_LINE(163)
	T->set_text(HX_CSTRING("Left:"));
	HX_STACK_LINE(164)
	T->set_scaleX(1.5);
	HX_STACK_LINE(165)
	T->set_scaleY(1.5);
	HX_STACK_LINE(166)
	T->set_textColor((int)16777215);
	HX_STACK_LINE(167)
	T->set_mouseEnabled(false);
	HX_STACK_LINE(168)
	this->addChild(T);
	HX_STACK_LINE(169)
	::String _g9 = this->stringfromcode(::Main_obj::_this->savedata->data->__Field(HX_CSTRING("controlscheme"),true)->__GetItem((int)2));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(169)
	::openfl::_v2::display::Sprite _g10 = this->AddButton(_g9);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(169)
	B = _g10;
	HX_STACK_LINE(170)
	B->set_x((int)70);
	HX_STACK_LINE(171)
	B->set_y((int)350);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_5,Array< ::Dynamic >,_g)
	Void run(Dynamic ev){
		HX_STACK_FRAME("*","_Function_1_5",0x5200ed3b,"*._Function_1_5","OptionView.hx",174,0x01c70a64)
		HX_STACK_ARG(ev,"ev")
		{
			HX_STACK_LINE(174)
			_g->__get((int)0).StaticCast< ::OptionView >()->selection = (int)2;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(172)
	B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_5(_g)),null(),null(),null());
	HX_STACK_LINE(177)
	::openfl::_v2::text::TextField _g111 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g111,"_g111");
	HX_STACK_LINE(177)
	T = _g111;
	HX_STACK_LINE(178)
	T->set_x((int)130);
	HX_STACK_LINE(179)
	T->set_y((int)350);
	HX_STACK_LINE(180)
	T->set_text(HX_CSTRING("Right:"));
	HX_STACK_LINE(181)
	T->set_scaleX(1.5);
	HX_STACK_LINE(182)
	T->set_scaleY(1.5);
	HX_STACK_LINE(183)
	T->set_textColor((int)16777215);
	HX_STACK_LINE(184)
	T->set_mouseEnabled(false);
	HX_STACK_LINE(185)
	this->addChild(T);
	HX_STACK_LINE(186)
	::String _g12 = this->stringfromcode(::Main_obj::_this->savedata->data->__Field(HX_CSTRING("controlscheme"),true)->__GetItem((int)3));		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(186)
	::openfl::_v2::display::Sprite _g13 = this->AddButton(_g12);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(186)
	B = _g13;
	HX_STACK_LINE(187)
	B->set_x((int)210);
	HX_STACK_LINE(188)
	B->set_y((int)350);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_6,Array< ::Dynamic >,_g)
	Void run(Dynamic ev){
		HX_STACK_FRAME("*","_Function_1_6",0x5200ed3c,"*._Function_1_6","OptionView.hx",191,0x01c70a64)
		HX_STACK_ARG(ev,"ev")
		{
			HX_STACK_LINE(191)
			_g->__get((int)0).StaticCast< ::OptionView >()->selection = (int)3;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(189)
	B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_6(_g)),null(),null(),null());
	HX_STACK_LINE(195)
	this->status = HX_CSTRING("");
	HX_STACK_LINE(196)
	::openfl::_v2::display::Sprite _g14 = this->AddButton(HX_CSTRING("Back"));		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(196)
	this->BackButton = _g14;
	HX_STACK_LINE(197)
	this->BackButton->set_x((int)700);
	HX_STACK_LINE(198)
	this->BackButton->set_y((int)550);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_7,Array< ::Dynamic >,_g)
	Void run(Dynamic ev){
		HX_STACK_FRAME("*","_Function_1_7",0x5200ed3d,"*._Function_1_7","OptionView.hx",200,0x01c70a64)
		HX_STACK_ARG(ev,"ev")
		{
			HX_STACK_LINE(200)
			_g->__get((int)0).StaticCast< ::OptionView >()->status = HX_CSTRING("Back");
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(199)
	this->BackButton->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_7(_g)),null(),null(),null());
}
;
	return null();
}

//OptionView_obj::~OptionView_obj() { }

Dynamic OptionView_obj::__CreateEmpty() { return  new OptionView_obj; }
hx::ObjectPtr< OptionView_obj > OptionView_obj::__new()
{  hx::ObjectPtr< OptionView_obj > result = new OptionView_obj();
	result->__construct();
	return result;}

Dynamic OptionView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< OptionView_obj > result = new OptionView_obj();
	result->__construct();
	return result;}

Void OptionView_obj::stage_onKeyUp( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("OptionView","stage_onKeyUp",0x115fb3a6,"OptionView.stage_onKeyUp","OptionView.hx",205,0x01c70a64)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(205)
		if (((this->selection > (int)-1))){
			HX_STACK_LINE(207)
			hx::IndexRef((::Main_obj::_this->savedata->data->__Field(HX_CSTRING("controlscheme"),true)).mPtr,this->selection) = event->keyCode;
			HX_STACK_LINE(208)
			this->status = HX_CSTRING("refresh");
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(OptionView_obj,stage_onKeyUp,(void))

::String OptionView_obj::stringfromcode( int code){
	HX_STACK_FRAME("OptionView","stringfromcode",0x712092bc,"OptionView.stringfromcode","OptionView.hx",220,0x01c70a64)
	HX_STACK_THIS(this)
	HX_STACK_ARG(code,"code")
	struct _Function_1_1{
		inline static Float Block( int &code){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","OptionView.hx",221,0x01c70a64)
			{
				HX_STACK_LINE(221)
				int _int = code;		HX_STACK_VAR(_int,"int");
				HX_STACK_LINE(221)
				return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(221)
	if (((_Function_1_1::Block(code) == (int)37))){
		HX_STACK_LINE(223)
		return HX_CSTRING("Left");
	}
	struct _Function_1_2{
		inline static Float Block( int &code){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","OptionView.hx",225,0x01c70a64)
			{
				HX_STACK_LINE(225)
				int _int = code;		HX_STACK_VAR(_int,"int");
				HX_STACK_LINE(225)
				return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(225)
	if (((_Function_1_2::Block(code) == (int)39))){
		HX_STACK_LINE(227)
		return HX_CSTRING("Right");
	}
	struct _Function_1_3{
		inline static Float Block( int &code){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","OptionView.hx",229,0x01c70a64)
			{
				HX_STACK_LINE(229)
				int _int = code;		HX_STACK_VAR(_int,"int");
				HX_STACK_LINE(229)
				return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(229)
	if (((_Function_1_3::Block(code) == (int)38))){
		HX_STACK_LINE(231)
		return HX_CSTRING("Up");
	}
	struct _Function_1_4{
		inline static Float Block( int &code){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","OptionView.hx",233,0x01c70a64)
			{
				HX_STACK_LINE(233)
				int _int = code;		HX_STACK_VAR(_int,"int");
				HX_STACK_LINE(233)
				return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(233)
	if (((_Function_1_4::Block(code) == (int)40))){
		HX_STACK_LINE(235)
		return HX_CSTRING("Down");
	}
	HX_STACK_LINE(237)
	return ::String::fromCharCode(code);
}


HX_DEFINE_DYNAMIC_FUNC1(OptionView_obj,stringfromcode,return )

::openfl::_v2::display::Sprite OptionView_obj::AddButton( ::String text){
	HX_STACK_FRAME("OptionView","AddButton",0xd76219ff,"OptionView.AddButton","OptionView.hx",240,0x01c70a64)
	HX_STACK_THIS(this)
	HX_STACK_ARG(text,"text")
	HX_STACK_LINE(241)
	::openfl::_v2::text::TextFormat tmp = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(242)
	tmp->font = HX_CSTRING("Arial");
	HX_STACK_LINE(243)
	tmp->size = (int)32;
	HX_STACK_LINE(244)
	::openfl::_v2::text::TextField textField = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(textField,"textField");
	HX_STACK_LINE(245)
	textField->set_name(HX_CSTRING("textField"));
	HX_STACK_LINE(246)
	textField->setTextFormat(tmp,null(),null());
	HX_STACK_LINE(247)
	textField->set_width((int)500);
	HX_STACK_LINE(248)
	textField->set_height((int)500);
	HX_STACK_LINE(249)
	textField->set_text(text);
	HX_STACK_LINE(250)
	textField->setTextFormat(tmp,null(),null());
	HX_STACK_LINE(251)
	textField->set_mouseEnabled(false);
	HX_STACK_LINE(252)
	int SZ = (int)6;		HX_STACK_VAR(SZ,"SZ");
	HX_STACK_LINE(253)
	int SZ2 = (SZ + SZ);		HX_STACK_VAR(SZ2,"SZ2");
	HX_STACK_LINE(254)
	int SZ3 = ((SZ + SZ) + SZ);		HX_STACK_VAR(SZ3,"SZ3");
	HX_STACK_LINE(255)
	textField->set_x(SZ);
	HX_STACK_LINE(256)
	textField->set_y(SZ);
	HX_STACK_LINE(257)
	Float _g = textField->get_textWidth();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(257)
	Float _g1 = (_g + SZ2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(257)
	textField->set_width(_g1);
	HX_STACK_LINE(258)
	Float _g2 = textField->get_textHeight();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(258)
	Float _g3 = (_g2 + SZ2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(258)
	textField->set_height(_g3);
	HX_STACK_LINE(260)
	::openfl::_v2::display::Shape rectangleShape = ::openfl::_v2::display::Shape_obj::__new();		HX_STACK_VAR(rectangleShape,"rectangleShape");
	HX_STACK_LINE(261)
	rectangleShape->get_graphics()->beginFill((int)43571,null());
	HX_STACK_LINE(262)
	Float _g4 = textField->get_textWidth();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(262)
	Float _g5 = (_g4 + SZ3);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(262)
	Float _g6 = textField->get_textHeight();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(262)
	Float _g7 = (_g6 + SZ3);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(262)
	rectangleShape->get_graphics()->drawRect((int)0,(int)0,_g5,_g7);
	HX_STACK_LINE(263)
	rectangleShape->get_graphics()->endFill();
	HX_STACK_LINE(264)
	rectangleShape->get_graphics()->beginFill((int)1166421,null());
	HX_STACK_LINE(265)
	Float _g8 = textField->get_textWidth();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(265)
	Float _g9 = (_g8 + SZ);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(265)
	Float _g10 = textField->get_textHeight();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(265)
	Float _g11 = (_g10 + SZ);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(265)
	rectangleShape->get_graphics()->drawRect(SZ,SZ,_g9,_g11);
	HX_STACK_LINE(266)
	rectangleShape->get_graphics()->endFill();
	HX_STACK_LINE(268)
	::openfl::_v2::display::Sprite buttonSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(buttonSprite,"buttonSprite");
	HX_STACK_LINE(270)
	buttonSprite->addChild(rectangleShape);
	HX_STACK_LINE(271)
	buttonSprite->addChild(textField);
	HX_STACK_LINE(272)
	this->addChild(buttonSprite);
	HX_STACK_LINE(273)
	{
		HX_STACK_LINE(273)
		::openfl::_v2::display::Sprite _g12 = buttonSprite;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(273)
		Float _g121 = _g12->get_x();		HX_STACK_VAR(_g121,"_g121");
		HX_STACK_LINE(273)
		Float _g13 = textField->get_width();		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(273)
		Float _g14 = (Float(_g13) / Float((int)2));		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(273)
		Float _g15 = (_g121 - _g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(273)
		_g12->set_x(_g15);
	}
	HX_STACK_LINE(274)
	Float _g16 = textField->get_width();		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(274)
	buttonSprite->set_width(_g16);
	HX_STACK_LINE(275)
	Float _g17 = textField->get_height();		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(275)
	buttonSprite->set_height(_g17);
	HX_STACK_LINE(280)
	return buttonSprite;
}


HX_DEFINE_DYNAMIC_FUNC1(OptionView_obj,AddButton,return )


OptionView_obj::OptionView_obj()
{
}

void OptionView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(OptionView);
	HX_MARK_MEMBER_NAME(BackButton,"BackButton");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(sndmeter,"sndmeter");
	HX_MARK_MEMBER_NAME(musicmeter,"musicmeter");
	HX_MARK_MEMBER_NAME(selection,"selection");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void OptionView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(BackButton,"BackButton");
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(sndmeter,"sndmeter");
	HX_VISIT_MEMBER_NAME(musicmeter,"musicmeter");
	HX_VISIT_MEMBER_NAME(selection,"selection");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic OptionView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sndmeter") ) { return sndmeter; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"selection") ) { return selection; }
		if (HX_FIELD_EQ(inName,"AddButton") ) { return AddButton_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"BackButton") ) { return BackButton; }
		if (HX_FIELD_EQ(inName,"musicmeter") ) { return musicmeter; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"stage_onKeyUp") ) { return stage_onKeyUp_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"stringfromcode") ) { return stringfromcode_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic OptionView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sndmeter") ) { sndmeter=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"selection") ) { selection=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"BackButton") ) { BackButton=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"musicmeter") ) { musicmeter=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void OptionView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("BackButton"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("sndmeter"));
	outFields->push(HX_CSTRING("musicmeter"));
	outFields->push(HX_CSTRING("selection"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(OptionView_obj,BackButton),HX_CSTRING("BackButton")},
	{hx::fsString,(int)offsetof(OptionView_obj,status),HX_CSTRING("status")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(OptionView_obj,sndmeter),HX_CSTRING("sndmeter")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(OptionView_obj,musicmeter),HX_CSTRING("musicmeter")},
	{hx::fsInt,(int)offsetof(OptionView_obj,selection),HX_CSTRING("selection")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("BackButton"),
	HX_CSTRING("status"),
	HX_CSTRING("sndmeter"),
	HX_CSTRING("musicmeter"),
	HX_CSTRING("selection"),
	HX_CSTRING("stage_onKeyUp"),
	HX_CSTRING("stringfromcode"),
	HX_CSTRING("AddButton"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(OptionView_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(OptionView_obj::__mClass,"__mClass");
};

#endif

Class OptionView_obj::__mClass;

void OptionView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("OptionView"), hx::TCanCast< OptionView_obj> ,sStaticFields,sMemberFields,
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

void OptionView_obj::__boot()
{
}

