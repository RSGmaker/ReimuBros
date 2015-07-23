#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_Animationloader
#include <Animationloader.h>
#endif
#ifndef INCLUDED_CharacterSelect
#include <CharacterSelect.h>
#endif
#ifndef INCLUDED_Entity
#include <Entity.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
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
#ifndef INCLUDED_openfl__v2_display_Stage
#include <openfl/_v2/display/Stage.h>
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
#ifndef INCLUDED_openfl__v2_media_SoundChannel
#include <openfl/_v2/media/SoundChannel.h>
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
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_openfl_display_StageAlign
#include <openfl/display/StageAlign.h>
#endif
#ifndef INCLUDED_openfl_display_StageScaleMode
#include <openfl/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_openfl_text_TextFieldType
#include <openfl/text/TextFieldType.h>
#endif

Void CharacterSelect_obj::__construct()
{
HX_STACK_FRAME("CharacterSelect","new",0x6132ced7,"CharacterSelect.new","CharacterSelect.hx",34,0x05071879)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(474)
	this->BH = 0.86;
	HX_STACK_LINE(473)
	this->BW = (int)86;
	HX_STACK_LINE(55)
	super::__construct();
	HX_STACK_LINE(56)
	this->selected = HX_CSTRING("reimu");
	HX_STACK_LINE(57)
	this->status = HX_CSTRING("");
	HX_STACK_LINE(58)
	this->playername = HX_CSTRING("PlayerName");
	HX_STACK_LINE(59)
	this->online = false;
	HX_STACK_LINE(60)
	this->Room = HX_CSTRING("public1");
	HX_STACK_LINE(61)
	this->currentpage = (int)0;
	HX_STACK_LINE(62)
	this->custom = false;
}
;
	return null();
}

//CharacterSelect_obj::~CharacterSelect_obj() { }

Dynamic CharacterSelect_obj::__CreateEmpty() { return  new CharacterSelect_obj; }
hx::ObjectPtr< CharacterSelect_obj > CharacterSelect_obj::__new()
{  hx::ObjectPtr< CharacterSelect_obj > result = new CharacterSelect_obj();
	result->__construct();
	return result;}

Dynamic CharacterSelect_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CharacterSelect_obj > result = new CharacterSelect_obj();
	result->__construct();
	return result;}

Void CharacterSelect_obj::start( ){
{
		HX_STACK_FRAME("CharacterSelect","start",0x19803e99,"CharacterSelect.start","CharacterSelect.hx",64,0x05071879)
		HX_STACK_THIS(this)
		HX_STACK_LINE(64)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(65)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(65)
		this->ButtonsPage = _g1;
		HX_STACK_LINE(66)
		this->get_stage()->set_color((int)0);
		HX_STACK_LINE(67)
		this->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::SHOW_ALL);
		HX_STACK_LINE(68)
		this->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP);
		HX_STACK_LINE(69)
		::openfl::_v2::text::TextFormat tmp = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(70)
		tmp->font = HX_CSTRING("Arial");
		HX_STACK_LINE(71)
		tmp->size = (int)22;
		HX_STACK_LINE(72)
		tmp->color = (int)16777215;
		HX_STACK_LINE(73)
		::openfl::_v2::text::TextField _g11 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(73)
		this->selectedcharacter = _g11;
		HX_STACK_LINE(74)
		this->selectedcharacter->set_x((int)20);
		HX_STACK_LINE(75)
		this->selectedcharacter->set_y((int)20);
		HX_STACK_LINE(76)
		this->selectedcharacter->set_text(HX_CSTRING(""));
		HX_STACK_LINE(78)
		this->addChild(this->selectedcharacter);
		HX_STACK_LINE(79)
		this->makebuttons();
		HX_STACK_LINE(92)
		this->refreshbuttons();
		HX_STACK_LINE(93)
		this->selectedcharacter->setTextFormat(tmp,null(),null());
		HX_STACK_LINE(95)
		::SoundManager_obj::PlayMusic(HX_CSTRING("characterselect"));
		HX_STACK_LINE(96)
		if (((this->ButtonsPage->length > (int)1))){
			HX_STACK_LINE(99)
			::openfl::_v2::display::Sprite _g2 = this->AddButton(HX_CSTRING("\xe2""\x86""\x92"""));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(99)
			this->NextButton = _g2;
			HX_STACK_LINE(101)
			this->NextButton->set_x((int)384);
			HX_STACK_LINE(102)
			this->NextButton->set_y((int)530);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","CharacterSelect.hx",103,0x05071879)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(106)
					(_g->__get((int)0).StaticCast< ::CharacterSelect >()->currentpage)++;
					HX_STACK_LINE(107)
					if (((_g->__get((int)0).StaticCast< ::CharacterSelect >()->currentpage >= _g->__get((int)0).StaticCast< ::CharacterSelect >()->ButtonsPage->length))){
						HX_STACK_LINE(109)
						hx::SubEq(_g->__get((int)0).StaticCast< ::CharacterSelect >()->currentpage,_g->__get((int)0).StaticCast< ::CharacterSelect >()->ButtonsPage->length);
					}
					HX_STACK_LINE(111)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->refreshbuttons();
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(103)
			this->NextButton->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_1(_g)),null(),null(),null());
			HX_STACK_LINE(116)
			::openfl::_v2::display::Sprite _g3 = this->AddButton(HX_CSTRING("\xe2""\x86""\x90"""));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(116)
			this->PrevButton = _g3;
			HX_STACK_LINE(118)
			this->PrevButton->set_x((int)244);
			HX_STACK_LINE(119)
			this->PrevButton->set_y((int)530);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_2,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","CharacterSelect.hx",120,0x05071879)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(123)
					(_g->__get((int)0).StaticCast< ::CharacterSelect >()->currentpage)--;
					HX_STACK_LINE(124)
					if (((_g->__get((int)0).StaticCast< ::CharacterSelect >()->currentpage < (int)0))){
						HX_STACK_LINE(126)
						hx::AddEq(_g->__get((int)0).StaticCast< ::CharacterSelect >()->currentpage,_g->__get((int)0).StaticCast< ::CharacterSelect >()->ButtonsPage->length);
					}
					HX_STACK_LINE(128)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->refreshbuttons();
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(120)
			this->PrevButton->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_2(_g)),null(),null(),null());
		}
		HX_STACK_LINE(134)
		::openfl::_v2::display::Sprite _g4 = this->AddButton(HX_CSTRING("Title Screen"));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(134)
		this->ExitButton = _g4;
		HX_STACK_LINE(136)
		this->ExitButton->set_x((int)554);
		HX_STACK_LINE(137)
		this->ExitButton->set_y((int)530);

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g)
		Void run(Dynamic ev){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","CharacterSelect.hx",138,0x05071879)
			HX_STACK_ARG(ev,"ev")
			{
				HX_STACK_LINE(139)
				_g->__get((int)0).StaticCast< ::CharacterSelect >()->status = HX_CSTRING("TitleScreen");
				HX_STACK_LINE(140)
				{
					HX_STACK_LINE(140)
					::openfl::_v2::display::Sprite _g12 = _g->__get((int)0).StaticCast< ::CharacterSelect >()->ExitButton;		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(140)
					_g12->set_x((_g12->get_x() - (int)10));
				}
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(138)
		this->ExitButton->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_1(_g)),null(),null(),null());
		HX_STACK_LINE(143)
		if ((!(this->online))){
			HX_STACK_LINE(145)
			::openfl::_v2::display::Sprite _g5 = this->AddButton(HX_CSTRING("Start Game"));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(145)
			this->StartButton = _g5;
			HX_STACK_LINE(146)
			this->StartButton->set_x((int)554);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","CharacterSelect.hx",147,0x05071879)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(148)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->status = HX_CSTRING("PlayGame");
					HX_STACK_LINE(149)
					{
						HX_STACK_LINE(149)
						::openfl::_v2::display::Sprite _g12 = _g->__get((int)0).StaticCast< ::CharacterSelect >()->StartButton;		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(149)
						_g12->set_x((_g12->get_x() - (int)10));
					}
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(147)
			this->StartButton->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_1(_g)),null(),null(),null());
		}
		else{
			HX_STACK_LINE(154)
			::openfl::_v2::display::Sprite B = this->AddButton(HX_CSTRING("Room#1"));		HX_STACK_VAR(B,"B");
			HX_STACK_LINE(155)
			B->set_x((int)554);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","CharacterSelect.hx",156,0x05071879)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(157)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->status = HX_CSTRING("PlayGame");
					HX_STACK_LINE(159)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room = HX_CSTRING("public1");
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(156)
			B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_1(_g)),null(),null(),null());
			HX_STACK_LINE(161)
			::openfl::_v2::display::Sprite _g6 = this->AddButton(HX_CSTRING("Room#2"));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(161)
			B = _g6;
			HX_STACK_LINE(162)
			B->set_x((int)554);
			HX_STACK_LINE(163)
			B->set_y((int)100);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_2,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","CharacterSelect.hx",164,0x05071879)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(165)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room = HX_CSTRING("public2");
					HX_STACK_LINE(166)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->status = HX_CSTRING("PlayGame");
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(164)
			B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_2(_g)),null(),null(),null());
			HX_STACK_LINE(170)
			::openfl::_v2::display::Sprite _g7 = this->AddButton(HX_CSTRING("Room#3"));		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(170)
			B = _g7;
			HX_STACK_LINE(171)
			B->set_x((int)554);
			HX_STACK_LINE(172)
			B->set_y((int)200);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_3,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_3",0x5201af7a,"*._Function_2_3","CharacterSelect.hx",173,0x05071879)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(174)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room = HX_CSTRING("public3");
					HX_STACK_LINE(175)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->status = HX_CSTRING("PlayGame");
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(173)
			B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_3(_g)),null(),null(),null());
			HX_STACK_LINE(178)
			::openfl::_v2::text::TextField _g8 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(178)
			this->CustomRoom = _g8;
			HX_STACK_LINE(179)
			this->CustomRoom->set_width((int)200);
			HX_STACK_LINE(180)
			this->CustomRoom->set_height((int)30);
			HX_STACK_LINE(181)
			::openfl::_v2::text::TextFormat tmp1 = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp1,"tmp1");
			HX_STACK_LINE(182)
			tmp1->font = HX_CSTRING("Arial");
			HX_STACK_LINE(183)
			tmp1->size = (int)18;
			HX_STACK_LINE(184)
			this->CustomRoom->set_x((int)554);
			HX_STACK_LINE(185)
			this->CustomRoom->set_y((int)400);
			HX_STACK_LINE(186)
			this->CustomRoom->set_text(HX_CSTRING("CustomRoom"));
			HX_STACK_LINE(187)
			this->CustomRoom->set_border(true);
			HX_STACK_LINE(188)
			this->CustomRoom->set_background(true);
			HX_STACK_LINE(189)
			this->CustomRoom->setTextFormat(tmp1,null(),null());
			HX_STACK_LINE(190)
			this->CustomRoom->set_wordWrap(true);
			HX_STACK_LINE(191)
			this->CustomRoom->set_type(::openfl::text::TextFieldType_obj::INPUT);
			HX_STACK_LINE(192)
			this->CustomRoom->set_borderColor((int)255);
			HX_STACK_LINE(193)
			this->CustomRoom->set_backgroundColor((int)16777215);
			HX_STACK_LINE(194)
			this->addChild(this->CustomRoom);
			HX_STACK_LINE(195)
			::openfl::_v2::display::Sprite _g9 = this->AddButton(HX_CSTRING("Custom"));		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(195)
			B = _g9;
			HX_STACK_LINE(196)
			B->set_x((int)554);
			HX_STACK_LINE(197)
			B->set_y((int)450);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_4,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_4",0x5201af7b,"*._Function_2_4","CharacterSelect.hx",198,0x05071879)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(199)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room = _g->__get((int)0).StaticCast< ::CharacterSelect >()->CustomRoom->get_text();
					HX_STACK_LINE(200)
					if (((bool((bool((bool((_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room != HX_CSTRING("public1"))) && bool((_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room != HX_CSTRING("public2"))))) && bool((_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room != HX_CSTRING("public3"))))) && bool((_g->__get((int)0).StaticCast< ::CharacterSelect >()->Room != HX_CSTRING("CustomRoom")))))){
						HX_STACK_LINE(202)
						_g->__get((int)0).StaticCast< ::CharacterSelect >()->custom = true;
					}
					HX_STACK_LINE(204)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->status = HX_CSTRING("PlayGame");
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(198)
			B->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_4(_g)),null(),null(),null());
		}
		HX_STACK_LINE(210)
		::openfl::_v2::text::TextField _g10 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(210)
		this->Nameinput = _g10;
		HX_STACK_LINE(211)
		this->Nameinput->set_width((int)300);
		HX_STACK_LINE(212)
		this->Nameinput->set_height((int)30);
		HX_STACK_LINE(215)
		::openfl::_v2::text::TextFormat _g111 = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g111,"_g111");
		HX_STACK_LINE(215)
		tmp = _g111;
		HX_STACK_LINE(216)
		tmp->font = HX_CSTRING("Arial");
		HX_STACK_LINE(217)
		tmp->size = (int)22;
		HX_STACK_LINE(219)
		this->Nameinput->set_x((int)160);
		HX_STACK_LINE(220)
		this->Nameinput->set_y((int)20);
		HX_STACK_LINE(221)
		if (((bool((this->playername == null())) || bool((this->playername == HX_CSTRING("")))))){
			HX_STACK_LINE(223)
			this->playername = HX_CSTRING("PlayerName");
		}
		HX_STACK_LINE(225)
		this->Nameinput->set_text(this->playername);
		HX_STACK_LINE(226)
		this->Nameinput->set_border(true);
		HX_STACK_LINE(227)
		this->Nameinput->set_background(true);
		HX_STACK_LINE(228)
		this->Nameinput->setTextFormat(tmp,null(),null());
		HX_STACK_LINE(229)
		this->Nameinput->set_wordWrap(true);
		HX_STACK_LINE(230)
		this->Nameinput->set_type(::openfl::text::TextFieldType_obj::INPUT);
		HX_STACK_LINE(231)
		this->Nameinput->set_borderColor((int)255);
		HX_STACK_LINE(232)
		this->Nameinput->set_backgroundColor((int)16777215);
		HX_STACK_LINE(235)
		this->addChild(this->Nameinput);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CharacterSelect_obj,start,(void))

Void CharacterSelect_obj::stage_onKeyDown( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("CharacterSelect","stage_onKeyDown",0x4bba7738,"CharacterSelect.stage_onKeyDown","CharacterSelect.hx",240,0x05071879)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(242)
		::openfl::_v2::text::TextFormat A = this->Nameinput->getTextFormat(null(),null());		HX_STACK_VAR(A,"A");
		HX_STACK_LINE(243)
		if (((event->keyCode == (int)8))){
			HX_STACK_LINE(245)
			::String _g = this->Nameinput->get_text().substr((int)0,(this->Nameinput->get_text().length - (int)1));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(245)
			this->Nameinput->set_text(_g);
		}
		else{
			HX_STACK_LINE(249)
			::String _g1 = this->Nameinput->get_text();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(249)
			::String _g2 = ::String::fromCharCode(event->charCode);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(249)
			::String _g3 = (_g1 + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(249)
			this->Nameinput->set_text(_g3);
		}
		HX_STACK_LINE(251)
		this->Nameinput->setTextFormat(A,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CharacterSelect_obj,stage_onKeyDown,(void))

Void CharacterSelect_obj::refreshbuttons( ){
{
		HX_STACK_FRAME("CharacterSelect","refreshbuttons",0xa0daf0af,"CharacterSelect.refreshbuttons","CharacterSelect.hx",255,0x05071879)
		HX_STACK_THIS(this)
		HX_STACK_LINE(256)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(258)
		while((true)){
			HX_STACK_LINE(258)
			if ((!(((i < this->Buttons->length))))){
				HX_STACK_LINE(258)
				break;
			}
			HX_STACK_LINE(260)
			::openfl::_v2::display::Sprite B = this->Buttons->__get(i).StaticCast< ::openfl::_v2::display::Sprite >();		HX_STACK_VAR(B,"B");
			HX_STACK_LINE(261)
			int _g = this->ButtonsPage->__get(this->currentpage).StaticCast< Array< ::Dynamic > >()->indexOf(B,null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(261)
			bool _g1 = (_g > (int)-1);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(261)
			B->set_visible(_g1);
			HX_STACK_LINE(262)
			Dynamic tf = B->getChildByName(HX_CSTRING("textField"));		HX_STACK_VAR(tf,"tf");
			HX_STACK_LINE(274)
			::String S = tf->__Field(HX_CSTRING("text"),true)->__Field(HX_CSTRING("toLowerCase"),true)();		HX_STACK_VAR(S,"S");
			HX_STACK_LINE(276)
			::String _g2 = S.charAt((int)0).toUpperCase();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(276)
			::String _g3 = S.substr((int)1,null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(276)
			::String SS = (_g2 + _g3);		HX_STACK_VAR(SS,"SS");
			HX_STACK_LINE(277)
			Dynamic O = B->getChildByName(HX_CSTRING("selectedshape"));		HX_STACK_VAR(O,"O");
			HX_STACK_LINE(278)
			Dynamic V = B->getChildByName(HX_CSTRING("selectedshape2"));		HX_STACK_VAR(V,"V");
			HX_STACK_LINE(280)
			::openfl::_v2::text::TextFormat SC = this->selectedcharacter->getTextFormat(null(),null());		HX_STACK_VAR(SC,"SC");
			HX_STACK_LINE(281)
			if (((S == this->selected))){
				HX_STACK_LINE(283)
				O->__FieldRef(HX_CSTRING("visible")) = true;
				HX_STACK_LINE(284)
				V->__FieldRef(HX_CSTRING("visible")) = false;
				HX_STACK_LINE(286)
				this->selectedcharacter->set_text(SS);
				HX_STACK_LINE(287)
				this->selectedcharacter->setTextFormat(SC,null(),null());
			}
			else{
				HX_STACK_LINE(291)
				O->__FieldRef(HX_CSTRING("visible")) = false;
				HX_STACK_LINE(292)
				if ((((S + HX_CSTRING("ALT")) == this->selected))){
					HX_STACK_LINE(294)
					V->__FieldRef(HX_CSTRING("visible")) = true;
					HX_STACK_LINE(295)
					this->selectedcharacter->set_text((SS + HX_CSTRING("\xe2""\x98""\x86""")));
					HX_STACK_LINE(296)
					this->selectedcharacter->setTextFormat(SC,null(),null());
				}
				else{
					HX_STACK_LINE(300)
					V->__FieldRef(HX_CSTRING("visible")) = false;
				}
			}
			HX_STACK_LINE(307)
			hx::AddEq(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CharacterSelect_obj,refreshbuttons,(void))

::String CharacterSelect_obj::gettext( int i){
	HX_STACK_FRAME("CharacterSelect","gettext",0xa888563a,"CharacterSelect.gettext","CharacterSelect.hx",311,0x05071879)
	HX_STACK_THIS(this)
	HX_STACK_ARG(i,"i")
	HX_STACK_LINE(324)
	Dynamic tf = this->Buttons->__get(i).StaticCast< ::openfl::_v2::display::Sprite >()->getChildByName(HX_CSTRING("textField"));		HX_STACK_VAR(tf,"tf");
	HX_STACK_LINE(325)
	return tf->__Field(HX_CSTRING("text"),true)->__Field(HX_CSTRING("toLowerCase"),true)();
}


HX_DEFINE_DYNAMIC_FUNC1(CharacterSelect_obj,gettext,return )

Void CharacterSelect_obj::makebuttons( ){
{
		HX_STACK_FRAME("CharacterSelect","makebuttons",0x44731f8a,"CharacterSelect.makebuttons","CharacterSelect.hx",330,0x05071879)
		HX_STACK_THIS(this)
		HX_STACK_LINE(331)
		Float X = 0.0;		HX_STACK_VAR(X,"X");
		HX_STACK_LINE(332)
		Float Y = 76.0;		HX_STACK_VAR(Y,"Y");
		HX_STACK_LINE(333)
		int S = (int)3;		HX_STACK_VAR(S,"S");
		HX_STACK_LINE(334)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(335)
		int j = (int)0;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(336)
		int ST = (int)20;		HX_STACK_VAR(ST,"ST");
		HX_STACK_LINE(337)
		ST = (int)0;
		HX_STACK_LINE(338)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(338)
		this->Buttons = _g;
		HX_STACK_LINE(339)
		Array< bool > O = ::Main_obj::_this->savedata->data->__Field(HX_CSTRING("unlock"),true);		HX_STACK_VAR(O,"O");
		HX_STACK_LINE(341)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(342)
		Array< ::Dynamic > page = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(page,"page");
		HX_STACK_LINE(343)
		Array< ::String > PC = ::Player_obj::characters->copy();		HX_STACK_VAR(PC,"PC");
		HX_STACK_LINE(344)
		Array< ::String > _g1 = PC->concat(::Player_obj::hiddencharacters);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(344)
		PC = _g1;
		HX_STACK_LINE(345)
		while((true)){
			HX_STACK_LINE(345)
			if ((!(((i < PC->length))))){
				HX_STACK_LINE(345)
				break;
			}
			HX_STACK_LINE(347)
			X = (int)0;
			HX_STACK_LINE(348)
			Y = (int)76;
			HX_STACK_LINE(349)
			Array< ::Dynamic > _g2 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(349)
			page = _g2;
			HX_STACK_LINE(350)
			this->ButtonsPage[this->ButtonsPage->length] = page;
			HX_STACK_LINE(351)
			while((true)){
				HX_STACK_LINE(351)
				if ((!(((bool((i < PC->length)) && bool((k < (int)5))))))){
					HX_STACK_LINE(351)
					break;
				}
				HX_STACK_LINE(353)
				X = (int)0;
				HX_STACK_LINE(354)
				while((true)){
					HX_STACK_LINE(354)
					if ((!(((bool((i < PC->length)) && bool((j < (int)5))))))){
						HX_STACK_LINE(354)
						break;
					}
					HX_STACK_LINE(356)
					::openfl::_v2::display::Sprite B;		HX_STACK_VAR(B,"B");
					HX_STACK_LINE(357)
					bool ok = false;		HX_STACK_VAR(ok,"ok");
					HX_STACK_LINE(358)
					if (((i < ::Player_obj::characters->length))){
						HX_STACK_LINE(360)
						::openfl::_v2::display::Sprite _g3 = this->AddCharacterButton(PC->__get(i),O->__get(i));		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(360)
						B = _g3;
						HX_STACK_LINE(361)
						ok = true;
					}
					else{
						HX_STACK_LINE(365)
						if ((::Main_obj::_this->savedata->data->__Field(HX_CSTRING("hidden"),true)->__GetItem((i - ::Player_obj::characters->length)))){
							HX_STACK_LINE(367)
							::openfl::_v2::display::Sprite _g4 = this->AddCharacterButton(PC->__get(i),true);		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(367)
							B = _g4;
							HX_STACK_LINE(368)
							ok = true;
						}
						else{
							HX_STACK_LINE(372)
							B = null();
							HX_STACK_LINE(373)
							ok = false;
						}
					}
					HX_STACK_LINE(376)
					if ((ok)){
						HX_STACK_LINE(378)
						page[page->length] = B;
						HX_STACK_LINE(380)
						{
							HX_STACK_LINE(380)
							::openfl::_v2::display::Sprite _g3 = B;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(380)
							Float _g5 = _g3->get_x();		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(380)
							Float _g6 = (_g5 + X);		HX_STACK_VAR(_g6,"_g6");
							HX_STACK_LINE(380)
							_g3->set_x(_g6);
						}
						HX_STACK_LINE(381)
						{
							HX_STACK_LINE(381)
							::openfl::_v2::display::Sprite _g3 = B;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(381)
							Float _g7 = _g3->get_y();		HX_STACK_VAR(_g7,"_g7");
							HX_STACK_LINE(381)
							Float _g8 = (_g7 + Y);		HX_STACK_VAR(_g8,"_g8");
							HX_STACK_LINE(381)
							_g3->set_y(_g8);
						}
						HX_STACK_LINE(382)
						B->set_visible((this->ButtonsPage->length == (int)1));
						HX_STACK_LINE(383)
						this->Buttons[this->Buttons->length] = B;
						HX_STACK_LINE(384)
						hx::AddEq(X,(this->BW + S));
						HX_STACK_LINE(385)
						hx::AddEq(j,(int)1);
					}
					HX_STACK_LINE(387)
					hx::AddEq(i,(int)1);
				}
				HX_STACK_LINE(390)
				hx::AddEq(Y,((this->BW + S) + ST));
				HX_STACK_LINE(391)
				(k)++;
				HX_STACK_LINE(392)
				j = (int)0;
			}
			HX_STACK_LINE(394)
			k = (int)0;
		}
		HX_STACK_LINE(397)
		i = (int)0;
		HX_STACK_LINE(399)
		Y = (int)76;
		HX_STACK_LINE(400)
		hx::SubEq(Y,(((int)76 + S) + ST));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CharacterSelect_obj,makebuttons,(void))

::openfl::_v2::display::Sprite CharacterSelect_obj::AddButton( ::String text){
	HX_STACK_FRAME("CharacterSelect","AddButton",0x2f83288a,"CharacterSelect.AddButton","CharacterSelect.hx",427,0x05071879)
	HX_STACK_THIS(this)
	HX_STACK_ARG(text,"text")
	HX_STACK_LINE(428)
	::openfl::_v2::text::TextFormat tmp = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(429)
	tmp->font = HX_CSTRING("Arial");
	HX_STACK_LINE(430)
	tmp->size = (int)44;
	HX_STACK_LINE(431)
	::openfl::_v2::text::TextField textField = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(textField,"textField");
	HX_STACK_LINE(432)
	textField->set_name(HX_CSTRING("textField"));
	HX_STACK_LINE(433)
	textField->setTextFormat(tmp,null(),null());
	HX_STACK_LINE(434)
	textField->set_width((int)500);
	HX_STACK_LINE(435)
	textField->set_height((int)500);
	HX_STACK_LINE(436)
	textField->set_text(text);
	HX_STACK_LINE(437)
	textField->setTextFormat(tmp,null(),null());
	HX_STACK_LINE(438)
	textField->set_mouseEnabled(false);
	HX_STACK_LINE(439)
	int SZ = (int)6;		HX_STACK_VAR(SZ,"SZ");
	HX_STACK_LINE(440)
	int SZ2 = (SZ + SZ);		HX_STACK_VAR(SZ2,"SZ2");
	HX_STACK_LINE(441)
	int SZ3 = ((SZ + SZ) + SZ);		HX_STACK_VAR(SZ3,"SZ3");
	HX_STACK_LINE(442)
	textField->set_x(SZ);
	HX_STACK_LINE(443)
	textField->set_y(SZ);
	HX_STACK_LINE(444)
	Float _g = textField->get_textWidth();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(444)
	Float _g1 = (_g + SZ2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(444)
	textField->set_width(_g1);
	HX_STACK_LINE(445)
	Float _g2 = textField->get_textHeight();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(445)
	Float _g3 = (_g2 + SZ2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(445)
	textField->set_height(_g3);
	HX_STACK_LINE(447)
	::openfl::_v2::display::Shape rectangleShape = ::openfl::_v2::display::Shape_obj::__new();		HX_STACK_VAR(rectangleShape,"rectangleShape");
	HX_STACK_LINE(451)
	rectangleShape->get_graphics()->beginFill((int)43571,null());
	HX_STACK_LINE(452)
	Float _g4 = textField->get_textWidth();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(452)
	Float _g5 = (_g4 + SZ3);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(452)
	Float _g6 = textField->get_textHeight();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(452)
	Float _g7 = (_g6 + SZ3);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(452)
	rectangleShape->get_graphics()->drawRect((int)0,(int)0,_g5,_g7);
	HX_STACK_LINE(453)
	rectangleShape->get_graphics()->endFill();
	HX_STACK_LINE(454)
	rectangleShape->get_graphics()->beginFill((int)1166421,null());
	HX_STACK_LINE(455)
	Float _g8 = textField->get_textWidth();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(455)
	Float _g9 = (_g8 + SZ);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(455)
	Float _g10 = textField->get_textHeight();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(455)
	Float _g11 = (_g10 + SZ);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(455)
	rectangleShape->get_graphics()->drawRect(SZ,SZ,_g9,_g11);
	HX_STACK_LINE(456)
	rectangleShape->get_graphics()->endFill();
	HX_STACK_LINE(458)
	::openfl::_v2::display::Sprite buttonSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(buttonSprite,"buttonSprite");
	HX_STACK_LINE(461)
	buttonSprite->addChild(rectangleShape);
	HX_STACK_LINE(462)
	buttonSprite->addChild(textField);
	HX_STACK_LINE(463)
	this->addChild(buttonSprite);
	HX_STACK_LINE(464)
	{
		HX_STACK_LINE(464)
		::openfl::_v2::display::Sprite _g12 = buttonSprite;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(464)
		Float _g121 = _g12->get_x();		HX_STACK_VAR(_g121,"_g121");
		HX_STACK_LINE(464)
		Float _g13 = textField->get_width();		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(464)
		Float _g14 = (Float(_g13) / Float((int)2));		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(464)
		Float _g15 = (_g121 - _g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(464)
		_g12->set_x(_g15);
	}
	HX_STACK_LINE(465)
	Float _g16 = textField->get_width();		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(465)
	buttonSprite->set_width(_g16);
	HX_STACK_LINE(466)
	Float _g17 = textField->get_height();		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(466)
	buttonSprite->set_height(_g17);
	HX_STACK_LINE(471)
	return buttonSprite;
}


HX_DEFINE_DYNAMIC_FUNC1(CharacterSelect_obj,AddButton,return )

::openfl::_v2::display::Sprite CharacterSelect_obj::AddCharacterButton( ::String text,bool unlocked){
	HX_STACK_FRAME("CharacterSelect","AddCharacterButton",0xfe53fce3,"CharacterSelect.AddCharacterButton","CharacterSelect.hx",476,0x05071879)
	HX_STACK_THIS(this)
	HX_STACK_ARG(text,"text")
	HX_STACK_ARG(unlocked,"unlocked")
	HX_STACK_LINE(475)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(477)
	::openfl::_v2::text::TextFormat tmp = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(478)
	tmp->font = HX_CSTRING("Arial");
	HX_STACK_LINE(479)
	tmp->size = (int)20;
	HX_STACK_LINE(480)
	tmp->color = (int)16777215;
	HX_STACK_LINE(481)
	::openfl::_v2::text::TextField textField = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(textField,"textField");
	HX_STACK_LINE(482)
	textField->set_name(HX_CSTRING("textField"));
	HX_STACK_LINE(483)
	int W = this->BW;		HX_STACK_VAR(W,"W");
	HX_STACK_LINE(484)
	Float WH = (Float(W) / Float((int)2));		HX_STACK_VAR(WH,"WH");
	HX_STACK_LINE(486)
	textField->set_y(W);
	HX_STACK_LINE(488)
	if ((unlocked)){
		HX_STACK_LINE(490)
		::String _g1 = text.charAt((int)0).toUpperCase();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(490)
		::String _g11 = text.substr((int)1,null());		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(490)
		::String _g2 = (_g1 + _g11);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(490)
		textField->set_text(_g2);
	}
	else{
		HX_STACK_LINE(494)
		tmp->size = (int)12;
		HX_STACK_LINE(495)
		textField->set_text(HX_CSTRING("Not Unlocked"));
	}
	HX_STACK_LINE(497)
	textField->setTextFormat(tmp,null(),null());
	HX_STACK_LINE(498)
	Float _g3 = textField->get_textWidth();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(498)
	Float _g4 = (Float(_g3) / Float((int)2));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(498)
	Float _g5 = (WH - _g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(498)
	textField->set_x(_g5);
	HX_STACK_LINE(499)
	textField->set_mouseEnabled(false);
	HX_STACK_LINE(500)
	int SZ = (int)5;		HX_STACK_VAR(SZ,"SZ");
	HX_STACK_LINE(501)
	int SZ2 = (SZ + SZ);		HX_STACK_VAR(SZ2,"SZ2");
	HX_STACK_LINE(502)
	int SZ3 = ((SZ + SZ) + SZ);		HX_STACK_VAR(SZ3,"SZ3");
	HX_STACK_LINE(503)
	Array< ::Dynamic > _g6 = this->AL->GetAnimation(text);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(503)
	::openfl::_v2::display::BitmapData _g7 = _g6->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(503)
	::openfl::_v2::display::Bitmap bitmap = ::openfl::_v2::display::Bitmap_obj::__new(_g7,null(),null());		HX_STACK_VAR(bitmap,"bitmap");
	HX_STACK_LINE(504)
	bitmap->set_scaleX(this->BH);
	HX_STACK_LINE(505)
	bitmap->set_scaleY(this->BH);
	HX_STACK_LINE(506)
	::openfl::_v2::display::Sprite buttonSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(buttonSprite,"buttonSprite");
	HX_STACK_LINE(507)
	::openfl::_v2::display::Shape rectangleShape = ::openfl::_v2::display::Shape_obj::__new();		HX_STACK_VAR(rectangleShape,"rectangleShape");
	HX_STACK_LINE(508)
	bitmap->set_x(SZ);
	HX_STACK_LINE(509)
	bitmap->set_y(SZ);
	HX_STACK_LINE(511)
	Float _g8 = bitmap->get_width();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(511)
	Float _g9 = (Float(_g8) / Float((int)2));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(511)
	Float _g10 = (WH - _g9);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(511)
	bitmap->set_x(_g10);
	HX_STACK_LINE(512)
	Float _g11 = bitmap->get_height();		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(512)
	Float _g12 = (Float(_g11) / Float((int)2));		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(512)
	Float _g13 = (WH - _g12);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(512)
	bitmap->set_y(_g13);
	HX_STACK_LINE(513)
	if ((unlocked)){
		HX_STACK_LINE(515)
		rectangleShape->get_graphics()->beginFill((int)43571,null());
		HX_STACK_LINE(516)
		rectangleShape->get_graphics()->drawRect((int)0,(int)0,W,W);
		HX_STACK_LINE(517)
		rectangleShape->get_graphics()->endFill();
		HX_STACK_LINE(518)
		rectangleShape->get_graphics()->beginFill((int)1166421,null());
		HX_STACK_LINE(519)
		rectangleShape->get_graphics()->drawRect(SZ,SZ,(W - SZ2),(W - SZ2));
		HX_STACK_LINE(520)
		rectangleShape->get_graphics()->endFill();
	}
	else{
		HX_STACK_LINE(524)
		rectangleShape->get_graphics()->beginFill((int)16711680,null());
		HX_STACK_LINE(525)
		rectangleShape->get_graphics()->drawRect((int)0,(int)0,W,W);
		HX_STACK_LINE(526)
		rectangleShape->get_graphics()->endFill();
		HX_STACK_LINE(527)
		rectangleShape->get_graphics()->beginFill((int)0,null());
		HX_STACK_LINE(528)
		rectangleShape->get_graphics()->drawRect(SZ,SZ,(W - SZ2),(W - SZ2));
		HX_STACK_LINE(529)
		rectangleShape->get_graphics()->endFill();
	}
	HX_STACK_LINE(532)
	::openfl::_v2::display::Shape rectangleShape2 = ::openfl::_v2::display::Shape_obj::__new();		HX_STACK_VAR(rectangleShape2,"rectangleShape2");
	HX_STACK_LINE(533)
	rectangleShape2->set_name(HX_CSTRING("selectedshape"));
	HX_STACK_LINE(534)
	rectangleShape2->get_graphics()->beginFill((int)16777215,null());
	HX_STACK_LINE(535)
	rectangleShape2->get_graphics()->drawRect((int)0,(int)0,W,W);
	HX_STACK_LINE(536)
	rectangleShape2->get_graphics()->endFill();
	HX_STACK_LINE(537)
	rectangleShape2->get_graphics()->beginFill((int)16711680,null());
	HX_STACK_LINE(538)
	rectangleShape2->get_graphics()->drawRect(SZ,SZ,(W - SZ2),(W - SZ2));
	HX_STACK_LINE(539)
	rectangleShape2->get_graphics()->endFill();
	HX_STACK_LINE(540)
	rectangleShape2->set_visible(false);
	HX_STACK_LINE(542)
	::openfl::_v2::display::Shape rectangleShape3 = ::openfl::_v2::display::Shape_obj::__new();		HX_STACK_VAR(rectangleShape3,"rectangleShape3");
	HX_STACK_LINE(543)
	rectangleShape3->set_name(HX_CSTRING("selectedshape2"));
	HX_STACK_LINE(544)
	rectangleShape3->get_graphics()->beginFill((int)255,null());
	HX_STACK_LINE(545)
	rectangleShape3->get_graphics()->drawRect((int)0,(int)0,W,W);
	HX_STACK_LINE(546)
	rectangleShape3->get_graphics()->endFill();
	HX_STACK_LINE(547)
	rectangleShape3->get_graphics()->beginFill((int)16711935,null());
	HX_STACK_LINE(548)
	rectangleShape3->get_graphics()->drawRect(SZ,SZ,(W - SZ2),(W - SZ2));
	HX_STACK_LINE(549)
	rectangleShape3->get_graphics()->endFill();
	HX_STACK_LINE(550)
	rectangleShape3->set_visible(false);
	HX_STACK_LINE(551)
	textField->set_visible(false);
	HX_STACK_LINE(552)
	buttonSprite->addChild(textField);
	HX_STACK_LINE(553)
	buttonSprite->addChild(rectangleShape);
	HX_STACK_LINE(554)
	buttonSprite->addChild(rectangleShape2);
	HX_STACK_LINE(555)
	buttonSprite->addChild(rectangleShape3);
	HX_STACK_LINE(556)
	if (((text == this->selected))){
		HX_STACK_LINE(558)
		rectangleShape2->set_visible(true);
		HX_STACK_LINE(559)
		this->currentpage = (this->ButtonsPage->length - (int)1);
	}
	HX_STACK_LINE(561)
	if ((((text + HX_CSTRING("ALT")) == this->selected))){
		HX_STACK_LINE(563)
		rectangleShape3->set_visible(true);
		HX_STACK_LINE(564)
		this->currentpage = (this->ButtonsPage->length - (int)1);
	}
	HX_STACK_LINE(566)
	if ((unlocked)){
		HX_STACK_LINE(568)
		buttonSprite->addChild(bitmap);
	}
	HX_STACK_LINE(570)
	this->addChild(buttonSprite);
	HX_STACK_LINE(571)
	if ((unlocked)){

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
		Void run(Dynamic ev){
			HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","CharacterSelect.hx",573,0x05071879)
			HX_STACK_ARG(ev,"ev")
			{
				HX_STACK_LINE(574)
				Dynamic D = ev->__Field(HX_CSTRING("target"),true);		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(575)
				Dynamic tf = D->__Field(HX_CSTRING("getChildByName"),true)(HX_CSTRING("textField"));		HX_STACK_VAR(tf,"tf");
				HX_STACK_LINE(577)
				::String S = _g->__get((int)0).StaticCast< ::CharacterSelect >()->gettext(_g->__get((int)0).StaticCast< ::CharacterSelect >()->Buttons->indexOf(D,null())).toLowerCase();		HX_STACK_VAR(S,"S");
				HX_STACK_LINE(578)
				if (((S == _g->__get((int)0).StaticCast< ::CharacterSelect >()->selected))){
					HX_STACK_LINE(580)
					Array< ::Dynamic > A = ::Main_obj::_this->AL->GetAnimation((_g->__get((int)0).StaticCast< ::CharacterSelect >()->selected + HX_CSTRING("ALT")));		HX_STACK_VAR(A,"A");
					HX_STACK_LINE(581)
					if (((bool((bool((A != null())) && bool((A->length > (int)0)))) && bool(((bool(::Main_obj::_this->savedata->data->__Field(HX_CSTRING("alts"),true)->__GetItem(_g->__get((int)0).StaticCast< ::CharacterSelect >()->Buttons->indexOf(D,null()))) || bool((_g->__get((int)0).StaticCast< ::CharacterSelect >()->Buttons->indexOf(D,null()) >= ::Player_obj::characters->length)))))))){
						HX_STACK_LINE(583)
						_g->__get((int)0).StaticCast< ::CharacterSelect >()->selected = (_g->__get((int)0).StaticCast< ::CharacterSelect >()->selected + HX_CSTRING("ALT"));
					}
				}
				else{
					HX_STACK_LINE(588)
					_g->__get((int)0).StaticCast< ::CharacterSelect >()->selected = S;
				}
				HX_STACK_LINE(592)
				_g->__get((int)0).StaticCast< ::CharacterSelect >()->refreshbuttons();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(573)
		buttonSprite->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_1(_g)),null(),null(),null());
	}
	HX_STACK_LINE(596)
	return buttonSprite;
}


HX_DEFINE_DYNAMIC_FUNC2(CharacterSelect_obj,AddCharacterButton,return )


CharacterSelect_obj::CharacterSelect_obj()
{
}

void CharacterSelect_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharacterSelect);
	HX_MARK_MEMBER_NAME(AL,"AL");
	HX_MARK_MEMBER_NAME(selected,"selected");
	HX_MARK_MEMBER_NAME(Buttons,"Buttons");
	HX_MARK_MEMBER_NAME(ButtonsPage,"ButtonsPage");
	HX_MARK_MEMBER_NAME(Nameinput,"Nameinput");
	HX_MARK_MEMBER_NAME(StartButton,"StartButton");
	HX_MARK_MEMBER_NAME(ExitButton,"ExitButton");
	HX_MARK_MEMBER_NAME(NextButton,"NextButton");
	HX_MARK_MEMBER_NAME(PrevButton,"PrevButton");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(playername,"playername");
	HX_MARK_MEMBER_NAME(online,"online");
	HX_MARK_MEMBER_NAME(Room,"Room");
	HX_MARK_MEMBER_NAME(CustomRoom,"CustomRoom");
	HX_MARK_MEMBER_NAME(selectedcharacter,"selectedcharacter");
	HX_MARK_MEMBER_NAME(currentpage,"currentpage");
	HX_MARK_MEMBER_NAME(custom,"custom");
	HX_MARK_MEMBER_NAME(BW,"BW");
	HX_MARK_MEMBER_NAME(BH,"BH");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CharacterSelect_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(AL,"AL");
	HX_VISIT_MEMBER_NAME(selected,"selected");
	HX_VISIT_MEMBER_NAME(Buttons,"Buttons");
	HX_VISIT_MEMBER_NAME(ButtonsPage,"ButtonsPage");
	HX_VISIT_MEMBER_NAME(Nameinput,"Nameinput");
	HX_VISIT_MEMBER_NAME(StartButton,"StartButton");
	HX_VISIT_MEMBER_NAME(ExitButton,"ExitButton");
	HX_VISIT_MEMBER_NAME(NextButton,"NextButton");
	HX_VISIT_MEMBER_NAME(PrevButton,"PrevButton");
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(playername,"playername");
	HX_VISIT_MEMBER_NAME(online,"online");
	HX_VISIT_MEMBER_NAME(Room,"Room");
	HX_VISIT_MEMBER_NAME(CustomRoom,"CustomRoom");
	HX_VISIT_MEMBER_NAME(selectedcharacter,"selectedcharacter");
	HX_VISIT_MEMBER_NAME(currentpage,"currentpage");
	HX_VISIT_MEMBER_NAME(custom,"custom");
	HX_VISIT_MEMBER_NAME(BW,"BW");
	HX_VISIT_MEMBER_NAME(BH,"BH");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic CharacterSelect_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AL") ) { return AL; }
		if (HX_FIELD_EQ(inName,"BW") ) { return BW; }
		if (HX_FIELD_EQ(inName,"BH") ) { return BH; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Room") ) { return Room; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		if (HX_FIELD_EQ(inName,"online") ) { return online; }
		if (HX_FIELD_EQ(inName,"custom") ) { return custom; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Buttons") ) { return Buttons; }
		if (HX_FIELD_EQ(inName,"gettext") ) { return gettext_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selected") ) { return selected; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"Nameinput") ) { return Nameinput; }
		if (HX_FIELD_EQ(inName,"AddButton") ) { return AddButton_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ExitButton") ) { return ExitButton; }
		if (HX_FIELD_EQ(inName,"NextButton") ) { return NextButton; }
		if (HX_FIELD_EQ(inName,"PrevButton") ) { return PrevButton; }
		if (HX_FIELD_EQ(inName,"playername") ) { return playername; }
		if (HX_FIELD_EQ(inName,"CustomRoom") ) { return CustomRoom; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ButtonsPage") ) { return ButtonsPage; }
		if (HX_FIELD_EQ(inName,"StartButton") ) { return StartButton; }
		if (HX_FIELD_EQ(inName,"currentpage") ) { return currentpage; }
		if (HX_FIELD_EQ(inName,"makebuttons") ) { return makebuttons_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"refreshbuttons") ) { return refreshbuttons_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stage_onKeyDown") ) { return stage_onKeyDown_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"selectedcharacter") ) { return selectedcharacter; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"AddCharacterButton") ) { return AddCharacterButton_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CharacterSelect_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AL") ) { AL=inValue.Cast< ::Animationloader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BW") ) { BW=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BH") ) { BH=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Room") ) { Room=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"online") ) { online=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"custom") ) { custom=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Buttons") ) { Buttons=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"selected") ) { selected=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"Nameinput") ) { Nameinput=inValue.Cast< ::openfl::_v2::text::TextField >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ExitButton") ) { ExitButton=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NextButton") ) { NextButton=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PrevButton") ) { PrevButton=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"playername") ) { playername=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CustomRoom") ) { CustomRoom=inValue.Cast< ::openfl::_v2::text::TextField >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"ButtonsPage") ) { ButtonsPage=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"StartButton") ) { StartButton=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentpage") ) { currentpage=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"selectedcharacter") ) { selectedcharacter=inValue.Cast< ::openfl::_v2::text::TextField >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CharacterSelect_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("AL"));
	outFields->push(HX_CSTRING("selected"));
	outFields->push(HX_CSTRING("Buttons"));
	outFields->push(HX_CSTRING("ButtonsPage"));
	outFields->push(HX_CSTRING("Nameinput"));
	outFields->push(HX_CSTRING("StartButton"));
	outFields->push(HX_CSTRING("ExitButton"));
	outFields->push(HX_CSTRING("NextButton"));
	outFields->push(HX_CSTRING("PrevButton"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("playername"));
	outFields->push(HX_CSTRING("online"));
	outFields->push(HX_CSTRING("Room"));
	outFields->push(HX_CSTRING("CustomRoom"));
	outFields->push(HX_CSTRING("selectedcharacter"));
	outFields->push(HX_CSTRING("currentpage"));
	outFields->push(HX_CSTRING("custom"));
	outFields->push(HX_CSTRING("BW"));
	outFields->push(HX_CSTRING("BH"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Animationloader*/ ,(int)offsetof(CharacterSelect_obj,AL),HX_CSTRING("AL")},
	{hx::fsString,(int)offsetof(CharacterSelect_obj,selected),HX_CSTRING("selected")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CharacterSelect_obj,Buttons),HX_CSTRING("Buttons")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CharacterSelect_obj,ButtonsPage),HX_CSTRING("ButtonsPage")},
	{hx::fsObject /*::openfl::_v2::text::TextField*/ ,(int)offsetof(CharacterSelect_obj,Nameinput),HX_CSTRING("Nameinput")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(CharacterSelect_obj,StartButton),HX_CSTRING("StartButton")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(CharacterSelect_obj,ExitButton),HX_CSTRING("ExitButton")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(CharacterSelect_obj,NextButton),HX_CSTRING("NextButton")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(CharacterSelect_obj,PrevButton),HX_CSTRING("PrevButton")},
	{hx::fsString,(int)offsetof(CharacterSelect_obj,status),HX_CSTRING("status")},
	{hx::fsString,(int)offsetof(CharacterSelect_obj,playername),HX_CSTRING("playername")},
	{hx::fsBool,(int)offsetof(CharacterSelect_obj,online),HX_CSTRING("online")},
	{hx::fsString,(int)offsetof(CharacterSelect_obj,Room),HX_CSTRING("Room")},
	{hx::fsObject /*::openfl::_v2::text::TextField*/ ,(int)offsetof(CharacterSelect_obj,CustomRoom),HX_CSTRING("CustomRoom")},
	{hx::fsObject /*::openfl::_v2::text::TextField*/ ,(int)offsetof(CharacterSelect_obj,selectedcharacter),HX_CSTRING("selectedcharacter")},
	{hx::fsInt,(int)offsetof(CharacterSelect_obj,currentpage),HX_CSTRING("currentpage")},
	{hx::fsBool,(int)offsetof(CharacterSelect_obj,custom),HX_CSTRING("custom")},
	{hx::fsInt,(int)offsetof(CharacterSelect_obj,BW),HX_CSTRING("BW")},
	{hx::fsFloat,(int)offsetof(CharacterSelect_obj,BH),HX_CSTRING("BH")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("AL"),
	HX_CSTRING("selected"),
	HX_CSTRING("Buttons"),
	HX_CSTRING("ButtonsPage"),
	HX_CSTRING("Nameinput"),
	HX_CSTRING("StartButton"),
	HX_CSTRING("ExitButton"),
	HX_CSTRING("NextButton"),
	HX_CSTRING("PrevButton"),
	HX_CSTRING("status"),
	HX_CSTRING("playername"),
	HX_CSTRING("online"),
	HX_CSTRING("Room"),
	HX_CSTRING("CustomRoom"),
	HX_CSTRING("selectedcharacter"),
	HX_CSTRING("currentpage"),
	HX_CSTRING("custom"),
	HX_CSTRING("start"),
	HX_CSTRING("stage_onKeyDown"),
	HX_CSTRING("refreshbuttons"),
	HX_CSTRING("gettext"),
	HX_CSTRING("makebuttons"),
	HX_CSTRING("AddButton"),
	HX_CSTRING("BW"),
	HX_CSTRING("BH"),
	HX_CSTRING("AddCharacterButton"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CharacterSelect_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CharacterSelect_obj::__mClass,"__mClass");
};

#endif

Class CharacterSelect_obj::__mClass;

void CharacterSelect_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("CharacterSelect"), hx::TCanCast< CharacterSelect_obj> ,sStaticFields,sMemberFields,
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

void CharacterSelect_obj::__boot()
{
}

