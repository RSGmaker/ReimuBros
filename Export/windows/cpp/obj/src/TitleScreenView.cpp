#include <hxcpp.h>

#ifndef INCLUDED_Animationloader
#include <Animationloader.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
#endif
#ifndef INCLUDED_TitleScreenView
#include <TitleScreenView.h>
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

Void TitleScreenView_obj::__construct()
{
HX_STACK_FRAME("TitleScreenView","new",0x5bce68fb,"TitleScreenView.new","TitleScreenView.hx",48,0x2ae30ed5)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(49)
	super::__construct();
	HX_STACK_LINE(50)
	this->menu = false;
	HX_STACK_LINE(51)
	this->status = HX_CSTRING("");
}
;
	return null();
}

//TitleScreenView_obj::~TitleScreenView_obj() { }

Dynamic TitleScreenView_obj::__CreateEmpty() { return  new TitleScreenView_obj; }
hx::ObjectPtr< TitleScreenView_obj > TitleScreenView_obj::__new()
{  hx::ObjectPtr< TitleScreenView_obj > result = new TitleScreenView_obj();
	result->__construct();
	return result;}

Dynamic TitleScreenView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TitleScreenView_obj > result = new TitleScreenView_obj();
	result->__construct();
	return result;}

Void TitleScreenView_obj::start( ){
{
		HX_STACK_FRAME("TitleScreenView","start",0xa5d1a9bd,"TitleScreenView.start","TitleScreenView.hx",53,0x2ae30ed5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(53)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(55)
		this->get_stage()->set_color((int)39287);
		HX_STACK_LINE(56)
		this->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::SHOW_ALL);
		HX_STACK_LINE(57)
		this->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP);
		HX_STACK_LINE(58)
		Array< ::Dynamic > _g1 = this->AL->GetAnimation(HX_CSTRING("titlescreen"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(58)
		::openfl::_v2::display::BitmapData _g11 = _g1->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(58)
		::openfl::_v2::display::Bitmap _g2 = ::openfl::_v2::display::Bitmap_obj::__new(_g11,null(),null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(58)
		this->img_titlescreen = _g2;
		HX_STACK_LINE(59)
		this->img_titlescreen->set_x((int)0);
		HX_STACK_LINE(60)
		this->img_titlescreen->set_y((int)0);
		HX_STACK_LINE(61)
		this->addChild(this->img_titlescreen);
		HX_STACK_LINE(62)
		::SoundManager_obj::PlayJingle(HX_CSTRING("titlescreen"));
		HX_STACK_LINE(66)
		if ((::Main_obj::_this->DEBUG)){
			HX_STACK_LINE(68)
			::openfl::_v2::text::TextFormat tmp = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(69)
			tmp->font = HX_CSTRING("Arial");
			HX_STACK_LINE(70)
			tmp->size = (int)44;
			HX_STACK_LINE(71)
			tmp->color = (int)16711680;
			HX_STACK_LINE(72)
			::openfl::_v2::text::TextField warning = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(warning,"warning");
			HX_STACK_LINE(73)
			warning->set_text(HX_CSTRING("DEBUG MODE ACTIVE!!!"));
			HX_STACK_LINE(74)
			warning->setTextFormat(tmp,null(),null());
			HX_STACK_LINE(75)
			Float _g3 = warning->get_textWidth();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(75)
			warning->set_width(_g3);
			HX_STACK_LINE(76)
			warning->set_y((int)500);
			HX_STACK_LINE(77)
			warning->set_x((int)50);
			HX_STACK_LINE(78)
			this->addChild(warning);
		}

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g)
		Void run(Dynamic ev){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","TitleScreenView.hx",80,0x2ae30ed5)
			HX_STACK_ARG(ev,"ev")
			{
				HX_STACK_LINE(80)
				_g->__get((int)0).StaticCast< ::TitleScreenView >()->MSE = true;
				HX_STACK_LINE(80)
				_g->__get((int)0).StaticCast< ::TitleScreenView >()->show_menu();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(80)
		this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_1_1(_g)),null(),null(),null());

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,_g)
		Void run(Dynamic ev){
			HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","TitleScreenView.hx",82,0x2ae30ed5)
			HX_STACK_ARG(ev,"ev")
			{
				HX_STACK_LINE(82)
				_g->__get((int)0).StaticCast< ::TitleScreenView >()->MSE = true;
				HX_STACK_LINE(82)
				_g->__get((int)0).StaticCast< ::TitleScreenView >()->show_menu();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(82)
		this->addEventListener(::openfl::_v2::events::KeyboardEvent_obj::KEY_UP, Dynamic(new _Function_1_2(_g)),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TitleScreenView_obj,start,(void))

Void TitleScreenView_obj::show_menu( ){
{
		HX_STACK_FRAME("TitleScreenView","show_menu",0xb59cd63c,"TitleScreenView.show_menu","TitleScreenView.hx",86,0x2ae30ed5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(85)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(87)
		if (((bool(!(this->menu)) && bool(this->MSE)))){
			HX_STACK_LINE(89)
			this->menu = true;
			HX_STACK_LINE(90)
			::openfl::_v2::display::Sprite _g1 = this->AddButton(HX_CSTRING("Start Game"));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(90)
			this->startgame = _g1;
			HX_STACK_LINE(91)
			{
				HX_STACK_LINE(91)
				::openfl::_v2::display::Sprite _g2 = this->startgame;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(91)
				Float _g11 = _g2->get_x();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(91)
				Float _g21 = (_g11 + (int)400);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(91)
				_g2->set_x(_g21);
			}
			HX_STACK_LINE(92)
			this->startgame->set_y((int)250);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","TitleScreenView.hx",97,0x2ae30ed5)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(97)
					_g->__get((int)0).StaticCast< ::TitleScreenView >()->status = HX_CSTRING("SinglePlayer");
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(93)
			this->startgame->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_1(_g)),null(),null(),null());
			HX_STACK_LINE(113)
			::openfl::_v2::display::Sprite _g3 = this->AddButton(HX_CSTRING("Options"));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(113)
			this->options = _g3;
			HX_STACK_LINE(114)
			this->options->set_x((int)0);
			HX_STACK_LINE(115)
			this->options->set_y((int)0);

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_2,Array< ::Dynamic >,_g)
			Void run(Dynamic ev){
				HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","TitleScreenView.hx",117,0x2ae30ed5)
				HX_STACK_ARG(ev,"ev")
				{
					HX_STACK_LINE(117)
					_g->__get((int)0).StaticCast< ::TitleScreenView >()->status = HX_CSTRING("Options");
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(116)
			this->options->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP, Dynamic(new _Function_2_2(_g)),null(),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TitleScreenView_obj,show_menu,(void))

::openfl::_v2::display::Sprite TitleScreenView_obj::AddButton( ::String text){
	HX_STACK_FRAME("TitleScreenView","AddButton",0x52d2f5ae,"TitleScreenView.AddButton","TitleScreenView.hx",144,0x2ae30ed5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(text,"text")
	HX_STACK_LINE(145)
	::openfl::_v2::text::TextFormat tmp = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(146)
	tmp->font = HX_CSTRING("Arial");
	HX_STACK_LINE(147)
	tmp->size = (int)44;
	HX_STACK_LINE(148)
	::openfl::_v2::text::TextField textField = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(textField,"textField");
	HX_STACK_LINE(149)
	textField->set_name(HX_CSTRING("textField"));
	HX_STACK_LINE(150)
	textField->setTextFormat(tmp,null(),null());
	HX_STACK_LINE(151)
	textField->set_width((int)500);
	HX_STACK_LINE(152)
	textField->set_height((int)500);
	HX_STACK_LINE(153)
	textField->set_text(text);
	HX_STACK_LINE(154)
	textField->setTextFormat(tmp,null(),null());
	HX_STACK_LINE(155)
	textField->set_mouseEnabled(false);
	HX_STACK_LINE(156)
	int SZ = (int)6;		HX_STACK_VAR(SZ,"SZ");
	HX_STACK_LINE(157)
	int SZ2 = (SZ + SZ);		HX_STACK_VAR(SZ2,"SZ2");
	HX_STACK_LINE(158)
	int SZ3 = ((SZ + SZ) + SZ);		HX_STACK_VAR(SZ3,"SZ3");
	HX_STACK_LINE(159)
	textField->set_x(SZ);
	HX_STACK_LINE(160)
	textField->set_y(SZ);
	HX_STACK_LINE(161)
	Float _g = textField->get_textWidth();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(161)
	Float _g1 = (_g + SZ2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(161)
	textField->set_width(_g1);
	HX_STACK_LINE(162)
	Float _g2 = textField->get_textHeight();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(162)
	Float _g3 = (_g2 + SZ2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(162)
	textField->set_height(_g3);
	HX_STACK_LINE(164)
	::openfl::_v2::display::Shape rectangleShape = ::openfl::_v2::display::Shape_obj::__new();		HX_STACK_VAR(rectangleShape,"rectangleShape");
	HX_STACK_LINE(168)
	rectangleShape->get_graphics()->beginFill((int)43571,null());
	HX_STACK_LINE(169)
	Float _g4 = textField->get_textWidth();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(169)
	Float _g5 = (_g4 + SZ3);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(169)
	Float _g6 = textField->get_textHeight();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(169)
	Float _g7 = (_g6 + SZ3);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(169)
	rectangleShape->get_graphics()->drawRect((int)0,(int)0,_g5,_g7);
	HX_STACK_LINE(170)
	rectangleShape->get_graphics()->endFill();
	HX_STACK_LINE(171)
	rectangleShape->get_graphics()->beginFill((int)1166421,null());
	HX_STACK_LINE(172)
	Float _g8 = textField->get_textWidth();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(172)
	Float _g9 = (_g8 + SZ);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(172)
	Float _g10 = textField->get_textHeight();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(172)
	Float _g11 = (_g10 + SZ);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(172)
	rectangleShape->get_graphics()->drawRect(SZ,SZ,_g9,_g11);
	HX_STACK_LINE(173)
	rectangleShape->get_graphics()->endFill();
	HX_STACK_LINE(175)
	::openfl::_v2::display::Sprite buttonSprite = ::openfl::_v2::display::Sprite_obj::__new();		HX_STACK_VAR(buttonSprite,"buttonSprite");
	HX_STACK_LINE(178)
	buttonSprite->addChild(rectangleShape);
	HX_STACK_LINE(179)
	buttonSprite->addChild(textField);
	HX_STACK_LINE(180)
	this->addChild(buttonSprite);
	HX_STACK_LINE(181)
	{
		HX_STACK_LINE(181)
		::openfl::_v2::display::Sprite _g12 = buttonSprite;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(181)
		Float _g121 = _g12->get_x();		HX_STACK_VAR(_g121,"_g121");
		HX_STACK_LINE(181)
		Float _g13 = textField->get_width();		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(181)
		Float _g14 = (Float(_g13) / Float((int)2));		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(181)
		Float _g15 = (_g121 - _g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(181)
		_g12->set_x(_g15);
	}
	HX_STACK_LINE(182)
	Float _g16 = textField->get_width();		HX_STACK_VAR(_g16,"_g16");
	HX_STACK_LINE(182)
	buttonSprite->set_width(_g16);
	HX_STACK_LINE(183)
	Float _g17 = textField->get_height();		HX_STACK_VAR(_g17,"_g17");
	HX_STACK_LINE(183)
	buttonSprite->set_height(_g17);
	HX_STACK_LINE(188)
	return buttonSprite;
}


HX_DEFINE_DYNAMIC_FUNC1(TitleScreenView_obj,AddButton,return )


TitleScreenView_obj::TitleScreenView_obj()
{
}

void TitleScreenView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TitleScreenView);
	HX_MARK_MEMBER_NAME(img_titlescreen,"img_titlescreen");
	HX_MARK_MEMBER_NAME(AL,"AL");
	HX_MARK_MEMBER_NAME(menu,"menu");
	HX_MARK_MEMBER_NAME(MSE,"MSE");
	HX_MARK_MEMBER_NAME(startgame,"startgame");
	HX_MARK_MEMBER_NAME(singleplayer,"singleplayer");
	HX_MARK_MEMBER_NAME(options,"options");
	HX_MARK_MEMBER_NAME(_exit,"_exit");
	HX_MARK_MEMBER_NAME(status,"status");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TitleScreenView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(img_titlescreen,"img_titlescreen");
	HX_VISIT_MEMBER_NAME(AL,"AL");
	HX_VISIT_MEMBER_NAME(menu,"menu");
	HX_VISIT_MEMBER_NAME(MSE,"MSE");
	HX_VISIT_MEMBER_NAME(startgame,"startgame");
	HX_VISIT_MEMBER_NAME(singleplayer,"singleplayer");
	HX_VISIT_MEMBER_NAME(options,"options");
	HX_VISIT_MEMBER_NAME(_exit,"_exit");
	HX_VISIT_MEMBER_NAME(status,"status");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic TitleScreenView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AL") ) { return AL; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"MSE") ) { return MSE; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"menu") ) { return menu; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_exit") ) { return _exit; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"options") ) { return options; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startgame") ) { return startgame; }
		if (HX_FIELD_EQ(inName,"show_menu") ) { return show_menu_dyn(); }
		if (HX_FIELD_EQ(inName,"AddButton") ) { return AddButton_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"singleplayer") ) { return singleplayer; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"img_titlescreen") ) { return img_titlescreen; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TitleScreenView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AL") ) { AL=inValue.Cast< ::Animationloader >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"MSE") ) { MSE=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"menu") ) { menu=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_exit") ) { _exit=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"options") ) { options=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"startgame") ) { startgame=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"singleplayer") ) { singleplayer=inValue.Cast< ::openfl::_v2::display::Sprite >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"img_titlescreen") ) { img_titlescreen=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TitleScreenView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("img_titlescreen"));
	outFields->push(HX_CSTRING("AL"));
	outFields->push(HX_CSTRING("menu"));
	outFields->push(HX_CSTRING("MSE"));
	outFields->push(HX_CSTRING("startgame"));
	outFields->push(HX_CSTRING("singleplayer"));
	outFields->push(HX_CSTRING("options"));
	outFields->push(HX_CSTRING("_exit"));
	outFields->push(HX_CSTRING("status"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(TitleScreenView_obj,img_titlescreen),HX_CSTRING("img_titlescreen")},
	{hx::fsObject /*::Animationloader*/ ,(int)offsetof(TitleScreenView_obj,AL),HX_CSTRING("AL")},
	{hx::fsBool,(int)offsetof(TitleScreenView_obj,menu),HX_CSTRING("menu")},
	{hx::fsBool,(int)offsetof(TitleScreenView_obj,MSE),HX_CSTRING("MSE")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(TitleScreenView_obj,startgame),HX_CSTRING("startgame")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(TitleScreenView_obj,singleplayer),HX_CSTRING("singleplayer")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(TitleScreenView_obj,options),HX_CSTRING("options")},
	{hx::fsObject /*::openfl::_v2::display::Sprite*/ ,(int)offsetof(TitleScreenView_obj,_exit),HX_CSTRING("_exit")},
	{hx::fsString,(int)offsetof(TitleScreenView_obj,status),HX_CSTRING("status")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("img_titlescreen"),
	HX_CSTRING("AL"),
	HX_CSTRING("menu"),
	HX_CSTRING("MSE"),
	HX_CSTRING("startgame"),
	HX_CSTRING("singleplayer"),
	HX_CSTRING("options"),
	HX_CSTRING("_exit"),
	HX_CSTRING("status"),
	HX_CSTRING("start"),
	HX_CSTRING("show_menu"),
	HX_CSTRING("AddButton"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TitleScreenView_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TitleScreenView_obj::__mClass,"__mClass");
};

#endif

Class TitleScreenView_obj::__mClass;

void TitleScreenView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("TitleScreenView"), hx::TCanCast< TitleScreenView_obj> ,sStaticFields,sMemberFields,
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

void TitleScreenView_obj::__boot()
{
}

