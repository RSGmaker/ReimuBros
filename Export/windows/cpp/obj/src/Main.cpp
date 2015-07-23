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
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_MD5
#include <MD5.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_OptionView
#include <OptionView.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
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
#ifndef INCLUDED_openfl__v2_net_SharedObject
#include <openfl/_v2/net/SharedObject.h>
#endif
#ifndef INCLUDED_openfl__v2_text_TextField
#include <openfl/_v2/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_net_SharedObjectFlushStatus
#include <openfl/net/SharedObjectFlushStatus.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",36,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(51)
	this->DEBUG = false;
	HX_STACK_LINE(75)
	super::__construct();
	HX_STACK_LINE(76)
	::Animationloader _g = ::Animationloader_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(76)
	this->AL = _g;
	HX_STACK_LINE(77)
	::Main_obj::_this = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(78)
	this->optionscreen = null();
	HX_STACK_LINE(79)
	::SoundManager_obj::__new();
	HX_STACK_LINE(81)
	this->online = false;
	HX_STACK_LINE(82)
	this->playerspick = HX_CSTRING("");
	HX_STACK_LINE(84)
	::openfl::_v2::net::SharedObject _g1 = ::openfl::_v2::net::SharedObject_obj::getLocal(HX_CSTRING("ReimuBrosData"),HX_CSTRING("/"),false);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(84)
	this->savedata = _g1;
	HX_STACK_LINE(85)
	this->gamemode = (int)0;
	HX_STACK_LINE(91)
	this->playername = this->savedata->data->__Field(HX_CSTRING("playername"),true);
	HX_STACK_LINE(92)
	if (((this->playername == null()))){
		HX_STACK_LINE(94)
		this->playername = HX_CSTRING("PlayerName");
	}
	HX_STACK_LINE(96)
	if (((this->savedata->data->__Field(HX_CSTRING("soundvolume"),true) == null()))){
		HX_STACK_LINE(98)
		this->savedata->data->__FieldRef(HX_CSTRING("soundvolume")) = 1.0;
	}
	HX_STACK_LINE(100)
	if (((this->savedata->data->__Field(HX_CSTRING("musicvolume"),true) == null()))){
		HX_STACK_LINE(102)
		this->savedata->data->__FieldRef(HX_CSTRING("musicvolume")) = 1.0;
	}
	HX_STACK_LINE(104)
	if (((this->savedata->data->__Field(HX_CSTRING("controlscheme"),true) == null()))){
		HX_STACK_LINE(106)
		Array< int > _g2 = Array_obj< int >::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(106)
		this->controlscheme = _g2;
		HX_STACK_LINE(107)
		this->controlscheme[(int)0] = (int)38;
		HX_STACK_LINE(108)
		this->controlscheme[(int)1] = (int)40;
		HX_STACK_LINE(109)
		this->controlscheme[(int)2] = (int)37;
		HX_STACK_LINE(110)
		this->controlscheme[(int)3] = (int)39;
		HX_STACK_LINE(111)
		this->savedata->data->__FieldRef(HX_CSTRING("controlscheme")) = this->controlscheme;
	}
	else{
		HX_STACK_LINE(115)
		this->controlscheme = this->savedata->data->__Field(HX_CSTRING("controlscheme"),true);
	}
	HX_STACK_LINE(117)
	::SoundManager_obj::_this->SetSoundVolume(this->savedata->data->__Field(HX_CSTRING("soundvolume"),true));
	HX_STACK_LINE(118)
	::SoundManager_obj::_this->SetMusicVolume(this->savedata->data->__Field(HX_CSTRING("musicvolume"),true));
	HX_STACK_LINE(119)
	if (((this->savedata->data->__Field(HX_CSTRING("unlock"),true) == null()))){
		HX_STACK_LINE(121)
		Array< bool > O = Array_obj< bool >::__new();		HX_STACK_VAR(O,"O");
		HX_STACK_LINE(122)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(123)
		while((true)){
			HX_STACK_LINE(123)
			if ((!(((i < ::Player_obj::characters->length))))){
				HX_STACK_LINE(123)
				break;
			}
			HX_STACK_LINE(125)
			O[i] = (i < (int)2);
			HX_STACK_LINE(126)
			(i)++;
		}
		HX_STACK_LINE(128)
		this->savedata->data->__FieldRef(HX_CSTRING("unlock")) = O;
	}
	HX_STACK_LINE(130)
	if (((this->savedata->data->__Field(HX_CSTRING("hidden"),true) == null()))){
		HX_STACK_LINE(132)
		Array< bool > O = Array_obj< bool >::__new();		HX_STACK_VAR(O,"O");
		HX_STACK_LINE(133)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(134)
		while((true)){
			HX_STACK_LINE(134)
			if ((!(((i < ::Player_obj::hiddencharacters->length))))){
				HX_STACK_LINE(134)
				break;
			}
			HX_STACK_LINE(136)
			O[i] = false;
			HX_STACK_LINE(137)
			(i)++;
		}
		HX_STACK_LINE(139)
		this->savedata->data->__FieldRef(HX_CSTRING("hidden")) = O;
	}
	HX_STACK_LINE(141)
	if (((this->savedata->data->__Field(HX_CSTRING("alts"),true) == null()))){
		HX_STACK_LINE(143)
		Array< bool > O = Array_obj< bool >::__new();		HX_STACK_VAR(O,"O");
		HX_STACK_LINE(144)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(145)
		while((true)){
			HX_STACK_LINE(145)
			if ((!(((i < ::Player_obj::characters->length))))){
				HX_STACK_LINE(145)
				break;
			}
			HX_STACK_LINE(147)
			O[i] = false;
			HX_STACK_LINE(148)
			(i)++;
		}
		HX_STACK_LINE(150)
		this->savedata->data->__FieldRef(HX_CSTRING("alts")) = O;
	}
	HX_STACK_LINE(152)
	if (((this->savedata->data->__Field(HX_CSTRING("highscore"),true) == null()))){
		HX_STACK_LINE(154)
		this->savedata->data->__FieldRef(HX_CSTRING("highscore")) = (int)0;
	}
	HX_STACK_LINE(156)
	this->Room = HX_CSTRING("public1");
	HX_STACK_LINE(157)
	this->get_stage()->addEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->this_onEnterFrame_dyn(),null(),null(),null());
	HX_STACK_LINE(158)
	this->get_stage()->addEventListener(::openfl::_v2::events::KeyboardEvent_obj::KEY_UP,this->stage_onKeyUp_dyn(),null(),null(),null());
	HX_STACK_LINE(159)
	this->get_stage()->addEventListener(::openfl::_v2::events::KeyboardEvent_obj::KEY_DOWN,this->stage_onKeyDown_dyn(),null(),null(),null());
	HX_STACK_LINE(160)
	this->showtitlescreen();
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::stage_onKeyUp( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("Main","stage_onKeyUp",0x131bf3a5,"Main.stage_onKeyUp","Main.hx",162,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(164)
		{
			HX_STACK_LINE(164)
			int _g = event->keyCode;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(164)
			switch( (int)(_g)){
				case (int)77: {
					HX_STACK_LINE(166)
					if (((this->characterselect == null()))){
						HX_STACK_LINE(168)
						::SoundManager_obj::_this->ToggleMute();
					}
				}
				;break;
				case (int)120: {
					HX_STACK_LINE(170)
					if (((bool((this->characterselect != null())) && bool(this->DEBUG)))){
						HX_STACK_LINE(172)
						::String _g1 = this->characterselect->Nameinput->get_text();		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(172)
						::String _g11 = ::MD5_obj::hash(_g1);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(172)
						this->characterselect->Nameinput->set_text(_g11);
					}
				}
				;break;
				case (int)81: {
					HX_STACK_LINE(175)
					if (((this->titlescreen != null()))){
						HX_STACK_LINE(177)
						this->showtitlescreen();
					}
				}
				;break;
				case (int)219: {
					HX_STACK_LINE(181)
					Float _g2 = ::SoundManager_obj::_this->GetMusicVolume();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(181)
					if (((_g2 > 0.0))){
						HX_STACK_LINE(183)
						Float _g3 = ::SoundManager_obj::_this->GetMusicVolume();		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(183)
						Float _g4 = (_g3 - 0.1);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(183)
						::SoundManager_obj::_this->SetMusicVolume(_g4);
					}
				}
				;break;
				case (int)221: {
					HX_STACK_LINE(188)
					Float _g5 = ::SoundManager_obj::_this->GetMusicVolume();		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(188)
					if (((_g5 < 1.0))){
						HX_STACK_LINE(190)
						Float _g6 = ::SoundManager_obj::_this->GetMusicVolume();		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(190)
						Float _g7 = (_g6 + 0.1);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(190)
						::SoundManager_obj::_this->SetMusicVolume(_g7);
					}
				}
				;break;
				case (int)189: {
					HX_STACK_LINE(195)
					Float _g8 = ::SoundManager_obj::_this->GetSoundVolume();		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(195)
					if (((_g8 > 0.0))){
						HX_STACK_LINE(197)
						Float _g9 = ::SoundManager_obj::_this->GetSoundVolume();		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(197)
						Float _g10 = (_g9 - 0.1);		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(197)
						::SoundManager_obj::_this->SetSoundVolume(_g10);
					}
				}
				;break;
				case (int)187: {
					HX_STACK_LINE(202)
					Float _g11 = ::SoundManager_obj::_this->GetSoundVolume();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(202)
					if (((_g11 < 1.0))){
						HX_STACK_LINE(204)
						Float _g12 = ::SoundManager_obj::_this->GetSoundVolume();		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(204)
						Float _g13 = (_g12 + 0.1);		HX_STACK_VAR(_g13,"_g13");
						HX_STACK_LINE(204)
						::SoundManager_obj::_this->SetSoundVolume(_g13);
					}
				}
				;break;
			}
		}
		HX_STACK_LINE(208)
		if (((this->game != null()))){
			HX_STACK_LINE(210)
			this->game->stage_onKeyUp(event);
		}
		HX_STACK_LINE(212)
		if (((this->optionscreen != null()))){
			HX_STACK_LINE(214)
			this->optionscreen->stage_onKeyUp(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,stage_onKeyUp,(void))

Void Main_obj::stage_onKeyDown( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("Main","stage_onKeyDown",0xfd7eec2c,"Main.stage_onKeyDown","Main.hx",218,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(218)
		if (((this->game != null()))){
			HX_STACK_LINE(220)
			this->game->stage_onKeyDown(event);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,stage_onKeyDown,(void))

Void Main_obj::this_onEnterFrame( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("Main","this_onEnterFrame",0x64786a60,"Main.this_onEnterFrame","Main.hx",224,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(224)
		if (((this->titlescreen != null()))){
			HX_STACK_LINE(226)
			if (((this->titlescreen->status != HX_CSTRING("")))){
				HX_STACK_LINE(228)
				this->status = this->titlescreen->status;
				HX_STACK_LINE(229)
				if (((bool((this->status == HX_CSTRING("OpenPlay"))) || bool((this->status == HX_CSTRING("SinglePlayer")))))){
					HX_STACK_LINE(231)
					this->online = false;
					HX_STACK_LINE(232)
					if (((this->status == HX_CSTRING("OpenPlay")))){
						HX_STACK_LINE(234)
						this->online = true;
					}
					HX_STACK_LINE(236)
					this->showcharacterselect();
				}
				HX_STACK_LINE(238)
				if (((this->status == HX_CSTRING("Options")))){
					HX_STACK_LINE(240)
					this->showoptions();
				}
			}
		}
		else{
			HX_STACK_LINE(244)
			if (((this->characterselect != null()))){
				HX_STACK_LINE(246)
				::String S = this->characterselect->status;		HX_STACK_VAR(S,"S");
				HX_STACK_LINE(247)
				if (((S == HX_CSTRING("PlayGame")))){
					HX_STACK_LINE(250)
					::String code = this->characterselect->Nameinput->get_text();		HX_STACK_VAR(code,"code");
					HX_STACK_LINE(251)
					bool valid = true;		HX_STACK_VAR(valid,"valid");
					HX_STACK_LINE(257)
					if (((code.length > (int)0))){
						HX_STACK_LINE(261)
						::String _g = code.toLowerCase().split(HX_CSTRING(" "))->join(HX_CSTRING(""));		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(261)
						code = _g;
						HX_STACK_LINE(262)
						::String _g1 = ::MD5_obj::hash(code);		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(262)
						code = _g1;
						HX_STACK_LINE(264)
						int _g2 = ::Main_obj::codes->indexOf(code,null());		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(264)
						int _g3 = (_g2 + (int)1);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(264)
						this->gamemode = _g3;
						HX_STACK_LINE(266)
						if (((bool((bool(this->online) && bool((this->gamemode > (int)0)))) && bool(!(this->characterselect->custom))))){
							HX_STACK_LINE(269)
							valid = false;
						}
						else{
							HX_STACK_LINE(271)
							if (((this->gamemode > (int)0))){
								HX_STACK_LINE(273)
								valid = true;
								HX_STACK_LINE(275)
								this->characterselect->Nameinput->set_text(this->characterselect->playername);
							}
						}
					}
					HX_STACK_LINE(280)
					this->characterselect->status = HX_CSTRING("");
					HX_STACK_LINE(281)
					if ((valid)){
						HX_STACK_LINE(283)
						this->playerspick = this->characterselect->selected;
						HX_STACK_LINE(284)
						if (((this->gamemode == (int)3))){
							HX_STACK_LINE(286)
							this->playerspick = HX_CSTRING("prinny");
						}
						HX_STACK_LINE(288)
						if (((this->gamemode == (int)6))){
							HX_STACK_LINE(290)
							this->playerspick = HX_CSTRING("pika");
						}
						HX_STACK_LINE(292)
						this->Room = this->characterselect->Room;
						HX_STACK_LINE(293)
						this->savedata->data->__FieldRef(HX_CSTRING("characterselected")) = this->playerspick;
						HX_STACK_LINE(294)
						this->showgame();
					}
				}
				HX_STACK_LINE(297)
				if (((S == HX_CSTRING("TitleScreen")))){
					HX_STACK_LINE(299)
					this->showtitlescreen();
				}
			}
			else{
				HX_STACK_LINE(302)
				if (((this->game != null()))){
					HX_STACK_LINE(304)
					if (((this->game->status == HX_CSTRING("quitting")))){
						HX_STACK_LINE(306)
						this->showtitlescreen();
					}
				}
				else{
					HX_STACK_LINE(309)
					if (((this->optionscreen != null()))){
						HX_STACK_LINE(311)
						if (((this->optionscreen->status == HX_CSTRING("Back")))){
							HX_STACK_LINE(313)
							this->showtitlescreen();
						}
						else{
							HX_STACK_LINE(315)
							if (((this->optionscreen->status == HX_CSTRING("refresh")))){
								HX_STACK_LINE(317)
								this->showoptions();
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,this_onEnterFrame,(void))

Void Main_obj::clear( ){
{
		HX_STACK_FRAME("Main","clear",0xc48eb7b8,"Main.clear","Main.hx",322,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(324)
		::SoundManager_obj::StopAll();
		HX_STACK_LINE(325)
		if (((this->titlescreen != null()))){
			HX_STACK_LINE(327)
			this->get_stage()->removeChild(this->titlescreen);
			HX_STACK_LINE(328)
			this->titlescreen = null();
		}
		HX_STACK_LINE(330)
		if (((this->game != null()))){
			HX_STACK_LINE(332)
			this->game->end();
			HX_STACK_LINE(333)
			this->get_stage()->removeChild(this->game);
			HX_STACK_LINE(334)
			::GameView_obj::_this = null();
			HX_STACK_LINE(335)
			this->savedata->flush(null());
			HX_STACK_LINE(336)
			this->game = null();
		}
		HX_STACK_LINE(338)
		if (((this->characterselect != null()))){
			HX_STACK_LINE(340)
			this->get_stage()->removeChild(this->characterselect);
			HX_STACK_LINE(341)
			::String code = this->characterselect->Nameinput->get_text();		HX_STACK_VAR(code,"code");
			HX_STACK_LINE(342)
			if (((code.length > (int)0))){
				HX_STACK_LINE(344)
				::String _g = code.toLowerCase().split(HX_CSTRING(" "))->join(HX_CSTRING(""));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(344)
				code = _g;
				HX_STACK_LINE(345)
				::String _g1 = ::MD5_obj::hash(code);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(345)
				code = _g1;
				HX_STACK_LINE(347)
				int _g2 = ::Main_obj::codes->indexOf(code,null());		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(347)
				int _g3 = (_g2 + (int)1);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(347)
				if (((_g3 == (int)0))){
					HX_STACK_LINE(349)
					::String _g4 = this->characterselect->Nameinput->get_text();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(349)
					this->playername = _g4;
				}
			}
			HX_STACK_LINE(353)
			this->savedata->data->__FieldRef(HX_CSTRING("playername")) = this->playername;
			HX_STACK_LINE(355)
			this->Room = this->characterselect->Room;
			HX_STACK_LINE(356)
			this->characterselect = null();
		}
		HX_STACK_LINE(358)
		if (((this->optionscreen != null()))){
			HX_STACK_LINE(360)
			this->get_stage()->removeChild(this->optionscreen);
			HX_STACK_LINE(361)
			this->optionscreen = null();
			HX_STACK_LINE(362)
			this->savedata->flush(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,clear,(void))

Void Main_obj::showgame( ){
{
		HX_STACK_FRAME("Main","showgame",0x08153224,"Main.showgame","Main.hx",366,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(367)
		this->clear();
		HX_STACK_LINE(368)
		::GameView _g = ::GameView_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(368)
		this->game = _g;
		HX_STACK_LINE(369)
		this->game->AL = this->AL;
		HX_STACK_LINE(370)
		this->get_stage()->addChild(this->game);
		HX_STACK_LINE(371)
		this->game->playerspick = this->playerspick;
		HX_STACK_LINE(372)
		this->game->playername = this->playername;
		HX_STACK_LINE(373)
		this->game->online = this->online;
		HX_STACK_LINE(374)
		this->game->Room = this->Room;
		HX_STACK_LINE(375)
		this->game->gamemode = this->gamemode;
		HX_STACK_LINE(376)
		this->game->start();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,showgame,(void))

Void Main_obj::showtitlescreen( ){
{
		HX_STACK_FRAME("Main","showtitlescreen",0xcbdc5f12,"Main.showtitlescreen","Main.hx",379,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(380)
		this->clear();
		HX_STACK_LINE(381)
		::TitleScreenView _g = ::TitleScreenView_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(381)
		this->titlescreen = _g;
		HX_STACK_LINE(382)
		this->titlescreen->AL = this->AL;
		HX_STACK_LINE(383)
		this->get_stage()->addChild(this->titlescreen);
		HX_STACK_LINE(384)
		this->titlescreen->start();
		HX_STACK_LINE(385)
		this->status = HX_CSTRING("titlescreen");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,showtitlescreen,(void))

Void Main_obj::showcharacterselect( ){
{
		HX_STACK_FRAME("Main","showcharacterselect",0xef008673,"Main.showcharacterselect","Main.hx",388,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(389)
		this->clear();
		HX_STACK_LINE(390)
		::CharacterSelect _g = ::CharacterSelect_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(390)
		this->characterselect = _g;
		HX_STACK_LINE(391)
		this->characterselect->AL = this->AL;
		HX_STACK_LINE(392)
		this->get_stage()->addChild(this->characterselect);
		HX_STACK_LINE(393)
		this->characterselect->playername = this->savedata->data->__Field(HX_CSTRING("playername"),true);
		HX_STACK_LINE(394)
		this->characterselect->selected = this->savedata->data->__Field(HX_CSTRING("characterselected"),true);
		HX_STACK_LINE(395)
		this->characterselect->online = this->online;
		HX_STACK_LINE(396)
		if (((this->characterselect->selected == null()))){
			HX_STACK_LINE(398)
			this->characterselect->selected = HX_CSTRING("reimu");
		}
		HX_STACK_LINE(400)
		this->characterselect->start();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,showcharacterselect,(void))

Void Main_obj::showoptions( ){
{
		HX_STACK_FRAME("Main","showoptions",0xee4f606c,"Main.showoptions","Main.hx",404,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(405)
		this->clear();
		HX_STACK_LINE(406)
		::OptionView _g = ::OptionView_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(406)
		this->optionscreen = _g;
		HX_STACK_LINE(408)
		this->get_stage()->addChild(this->optionscreen);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,showoptions,(void))

::Main Main_obj::_this;

Array< ::String > Main_obj::codes;


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(game,"game");
	HX_MARK_MEMBER_NAME(titlescreen,"titlescreen");
	HX_MARK_MEMBER_NAME(optionscreen,"optionscreen");
	HX_MARK_MEMBER_NAME(AL,"AL");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(characterselect,"characterselect");
	HX_MARK_MEMBER_NAME(playerspick,"playerspick");
	HX_MARK_MEMBER_NAME(online,"online");
	HX_MARK_MEMBER_NAME(playername,"playername");
	HX_MARK_MEMBER_NAME(savedata,"savedata");
	HX_MARK_MEMBER_NAME(Room,"Room");
	HX_MARK_MEMBER_NAME(DEBUG,"DEBUG");
	HX_MARK_MEMBER_NAME(controlscheme,"controlscheme");
	HX_MARK_MEMBER_NAME(gamemode,"gamemode");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(game,"game");
	HX_VISIT_MEMBER_NAME(titlescreen,"titlescreen");
	HX_VISIT_MEMBER_NAME(optionscreen,"optionscreen");
	HX_VISIT_MEMBER_NAME(AL,"AL");
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(characterselect,"characterselect");
	HX_VISIT_MEMBER_NAME(playerspick,"playerspick");
	HX_VISIT_MEMBER_NAME(online,"online");
	HX_VISIT_MEMBER_NAME(playername,"playername");
	HX_VISIT_MEMBER_NAME(savedata,"savedata");
	HX_VISIT_MEMBER_NAME(Room,"Room");
	HX_VISIT_MEMBER_NAME(DEBUG,"DEBUG");
	HX_VISIT_MEMBER_NAME(controlscheme,"controlscheme");
	HX_VISIT_MEMBER_NAME(gamemode,"gamemode");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AL") ) { return AL; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"game") ) { return game; }
		if (HX_FIELD_EQ(inName,"Room") ) { return Room; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_this") ) { return _this; }
		if (HX_FIELD_EQ(inName,"codes") ) { return codes; }
		if (HX_FIELD_EQ(inName,"DEBUG") ) { return DEBUG; }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		if (HX_FIELD_EQ(inName,"online") ) { return online; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"savedata") ) { return savedata; }
		if (HX_FIELD_EQ(inName,"gamemode") ) { return gamemode; }
		if (HX_FIELD_EQ(inName,"showgame") ) { return showgame_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"playername") ) { return playername; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"titlescreen") ) { return titlescreen; }
		if (HX_FIELD_EQ(inName,"playerspick") ) { return playerspick; }
		if (HX_FIELD_EQ(inName,"showoptions") ) { return showoptions_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"optionscreen") ) { return optionscreen; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"controlscheme") ) { return controlscheme; }
		if (HX_FIELD_EQ(inName,"stage_onKeyUp") ) { return stage_onKeyUp_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"characterselect") ) { return characterselect; }
		if (HX_FIELD_EQ(inName,"stage_onKeyDown") ) { return stage_onKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"showtitlescreen") ) { return showtitlescreen_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"this_onEnterFrame") ) { return this_onEnterFrame_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"showcharacterselect") ) { return showcharacterselect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"AL") ) { AL=inValue.Cast< ::Animationloader >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"game") ) { game=inValue.Cast< ::GameView >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Room") ) { Room=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_this") ) { _this=inValue.Cast< ::Main >(); return inValue; }
		if (HX_FIELD_EQ(inName,"codes") ) { codes=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DEBUG") ) { DEBUG=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"online") ) { online=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"savedata") ) { savedata=inValue.Cast< ::openfl::_v2::net::SharedObject >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gamemode") ) { gamemode=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"playername") ) { playername=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"titlescreen") ) { titlescreen=inValue.Cast< ::TitleScreenView >(); return inValue; }
		if (HX_FIELD_EQ(inName,"playerspick") ) { playerspick=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"optionscreen") ) { optionscreen=inValue.Cast< ::OptionView >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"controlscheme") ) { controlscheme=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"characterselect") ) { characterselect=inValue.Cast< ::CharacterSelect >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("game"));
	outFields->push(HX_CSTRING("titlescreen"));
	outFields->push(HX_CSTRING("optionscreen"));
	outFields->push(HX_CSTRING("AL"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("characterselect"));
	outFields->push(HX_CSTRING("playerspick"));
	outFields->push(HX_CSTRING("online"));
	outFields->push(HX_CSTRING("playername"));
	outFields->push(HX_CSTRING("savedata"));
	outFields->push(HX_CSTRING("Room"));
	outFields->push(HX_CSTRING("DEBUG"));
	outFields->push(HX_CSTRING("controlscheme"));
	outFields->push(HX_CSTRING("gamemode"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_this"),
	HX_CSTRING("codes"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::GameView*/ ,(int)offsetof(Main_obj,game),HX_CSTRING("game")},
	{hx::fsObject /*::TitleScreenView*/ ,(int)offsetof(Main_obj,titlescreen),HX_CSTRING("titlescreen")},
	{hx::fsObject /*::OptionView*/ ,(int)offsetof(Main_obj,optionscreen),HX_CSTRING("optionscreen")},
	{hx::fsObject /*::Animationloader*/ ,(int)offsetof(Main_obj,AL),HX_CSTRING("AL")},
	{hx::fsString,(int)offsetof(Main_obj,status),HX_CSTRING("status")},
	{hx::fsObject /*::CharacterSelect*/ ,(int)offsetof(Main_obj,characterselect),HX_CSTRING("characterselect")},
	{hx::fsString,(int)offsetof(Main_obj,playerspick),HX_CSTRING("playerspick")},
	{hx::fsBool,(int)offsetof(Main_obj,online),HX_CSTRING("online")},
	{hx::fsString,(int)offsetof(Main_obj,playername),HX_CSTRING("playername")},
	{hx::fsObject /*::openfl::_v2::net::SharedObject*/ ,(int)offsetof(Main_obj,savedata),HX_CSTRING("savedata")},
	{hx::fsString,(int)offsetof(Main_obj,Room),HX_CSTRING("Room")},
	{hx::fsBool,(int)offsetof(Main_obj,DEBUG),HX_CSTRING("DEBUG")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Main_obj,controlscheme),HX_CSTRING("controlscheme")},
	{hx::fsInt,(int)offsetof(Main_obj,gamemode),HX_CSTRING("gamemode")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("game"),
	HX_CSTRING("titlescreen"),
	HX_CSTRING("optionscreen"),
	HX_CSTRING("AL"),
	HX_CSTRING("status"),
	HX_CSTRING("characterselect"),
	HX_CSTRING("playerspick"),
	HX_CSTRING("online"),
	HX_CSTRING("playername"),
	HX_CSTRING("savedata"),
	HX_CSTRING("Room"),
	HX_CSTRING("DEBUG"),
	HX_CSTRING("controlscheme"),
	HX_CSTRING("gamemode"),
	HX_CSTRING("stage_onKeyUp"),
	HX_CSTRING("stage_onKeyDown"),
	HX_CSTRING("this_onEnterFrame"),
	HX_CSTRING("clear"),
	HX_CSTRING("showgame"),
	HX_CSTRING("showtitlescreen"),
	HX_CSTRING("showcharacterselect"),
	HX_CSTRING("showoptions"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Main_obj::_this,"_this");
	HX_MARK_MEMBER_NAME(Main_obj::codes,"codes");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Main_obj::_this,"_this");
	HX_VISIT_MEMBER_NAME(Main_obj::codes,"codes");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
	codes= Array_obj< ::String >::__new().Add(HX_CSTRING("75efc70c0e990c49b8ee4fbdaca89dae")).Add(HX_CSTRING("6718c4714daa73a63e1e4ea54757449c")).Add(HX_CSTRING("9e6122001ea0464018c634c285233853")).Add(HX_CSTRING("7d51b214e0069ac6361aaaf2034279a6")).Add(HX_CSTRING("2b59c79dfe67f2a5d0f17c646ae894ed")).Add(HX_CSTRING("fa55036379520473353e15548f2a388e")).Add(HX_CSTRING("69034dbf1b3882954b3a9b8bf9686d1c")).Add(HX_CSTRING("c16404177908ade1a1f1b0e3f8835ec9")).Add(HX_CSTRING("6170e8e40fdf20f6fbeefd88815a2086")).Add(HX_CSTRING("525afc6a26124022359a9ad101e71e99")).Add(HX_CSTRING("5aed71982de151ff05492c9babb533ea")).Add(HX_CSTRING("45c48cce2e2d7fbdea1afc51c7c6ad26")).Add(HX_CSTRING("1c0108249de204153f4e296913fcacea")).Add(HX_CSTRING("09e1ca57cc1c4e73bd7fc9f5642883db")).Add(HX_CSTRING("f9df7933994ea2e532cc30a842d36766"));
}

