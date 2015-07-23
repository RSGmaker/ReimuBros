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
#ifndef INCLUDED_Bullet
#include <Bullet.h>
#endif
#ifndef INCLUDED_Chen
#include <Chen.h>
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
#ifndef INCLUDED_EntityGap
#include <EntityGap.h>
#endif
#ifndef INCLUDED_EntityItem
#include <EntityItem.h>
#endif
#ifndef INCLUDED_GameView
#include <GameView.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Imposter
#include <Imposter.h>
#endif
#ifndef INCLUDED_Keine
#include <Keine.h>
#endif
#ifndef INCLUDED_LifeItem
#include <LifeItem.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Mystia
#include <Mystia.h>
#endif
#ifndef INCLUDED_Nue
#include <Nue.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_PointItem
#include <PointItem.h>
#endif
#ifndef INCLUDED_PowBlock
#include <PowBlock.h>
#endif
#ifndef INCLUDED_RedFairy
#include <RedFairy.h>
#endif
#ifndef INCLUDED_Rumia
#include <Rumia.h>
#endif
#ifndef INCLUDED_Seija
#include <Seija.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Table
#include <Table.h>
#endif
#ifndef INCLUDED_Tewi
#include <Tewi.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_TypeofRound
#include <TypeofRound.h>
#endif
#ifndef INCLUDED_UFO
#include <UFO.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl__v2_Assets
#include <openfl/_v2/Assets.h>
#endif
#ifndef INCLUDED_openfl__v2_Lib
#include <openfl/_v2/Lib.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BlendMode
#include <openfl/_v2/display/BlendMode.h>
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
#ifndef INCLUDED_openfl__v2_display_MovieClip
#include <openfl/_v2/display/MovieClip.h>
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
#ifndef INCLUDED_openfl__v2_events_TouchEvent
#include <openfl/_v2/events/TouchEvent.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Point
#include <openfl/_v2/geom/Point.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl__v2_media_Sound
#include <openfl/_v2/media/Sound.h>
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
#ifndef INCLUDED_openfl_display_StageDisplayState
#include <openfl/display/StageDisplayState.h>
#endif
#ifndef INCLUDED_openfl_display_StageScaleMode
#include <openfl/display/StageScaleMode.h>
#endif

Void GameView_obj::__construct()
{
HX_STACK_FRAME("GameView","new",0x7407a809,"GameView.new","GameView.hx",43,0x658aeb87)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(130)
	this->currentformation = (int)-1;
	HX_STACK_LINE(129)
	this->platformformation = (int)0;
	HX_STACK_LINE(127)
	this->CombinedScoreALL = (int)0;
	HX_STACK_LINE(125)
	this->CombinedScore = (int)0;
	HX_STACK_LINE(124)
	this->PointsToLife = (int)10000;
	HX_STACK_LINE(138)
	super::__construct();
	HX_STACK_LINE(139)
	this->playername = HX_CSTRING("");
	HX_STACK_LINE(140)
	this->Room = HX_CSTRING("public");
	HX_STACK_LINE(141)
	this->status = HX_CSTRING("playing");
	HX_STACK_LINE(142)
	this->syncdelay = (int)0;
	HX_STACK_LINE(143)
	this->rank = (int)0;
	HX_STACK_LINE(144)
	this->gamemode = (int)0;
}
;
	return null();
}

//GameView_obj::~GameView_obj() { }

Dynamic GameView_obj::__CreateEmpty() { return  new GameView_obj; }
hx::ObjectPtr< GameView_obj > GameView_obj::__new()
{  hx::ObjectPtr< GameView_obj > result = new GameView_obj();
	result->__construct();
	return result;}

Dynamic GameView_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameView_obj > result = new GameView_obj();
	result->__construct();
	return result;}

Void GameView_obj::end( ){
{
		HX_STACK_FRAME("GameView","end",0x7400db84,"GameView.end","GameView.hx",146,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(148)
		if (((this->musicchannel != null()))){
			HX_STACK_LINE(150)
			this->musicchannel->stop();
		}
		HX_STACK_LINE(152)
		Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(152)
		this->Obstacles = _g;
		HX_STACK_LINE(153)
		this->removeChildren(null(),null());
		HX_STACK_LINE(157)
		this->online = false;
		HX_STACK_LINE(159)
		this->removeEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->this_onEnterFrame_dyn(),null());
		HX_STACK_LINE(160)
		this->removeEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_DOWN,this->on_mousedown_dyn(),null());
		HX_STACK_LINE(161)
		this->removeEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP,this->on_mouseup_dyn(),null());
		HX_STACK_LINE(162)
		this->removeEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_BEGIN,this->on_touchbegin_dyn(),null());
		HX_STACK_LINE(163)
		this->removeEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_END,this->on_touchend_dyn(),null());
		HX_STACK_LINE(164)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(164)
		this->entities = _g1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,end,(void))

Void GameView_obj::start( ){
{
		HX_STACK_FRAME("GameView","start",0x2e23484b,"GameView.start","GameView.hx",167,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(167)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g)
		Void run(::openfl::_v2::events::Event e){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","GameView.hx",177,0x658aeb87)
			HX_STACK_ARG(e,"e")
			{
				HX_STACK_LINE(177)
				_g->__get((int)0).StaticCast< ::GameView >()->PlayMusic();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(177)
		::SoundManager_obj::PlayJingle(HX_CSTRING("startgame"))->addEventListener(::openfl::_v2::events::Event_obj::SOUND_COMPLETE, Dynamic(new _Function_1_1(_g)),null(),null(),null());
		HX_STACK_LINE(181)
		this->RoundType = ::TypeofRound_obj::Normal;
		HX_STACK_LINE(182)
		this->spawnedChar = false;
		HX_STACK_LINE(183)
		Array< ::Dynamic > _g1 = this->AL->GetAnimation(HX_CSTRING("BG"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(183)
		::openfl::_v2::display::BitmapData _g11 = _g1->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(183)
		::openfl::_v2::display::Bitmap _g2 = ::openfl::_v2::display::Bitmap_obj::__new(_g11,null(),null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(183)
		this->Background = _g2;
		HX_STACK_LINE(184)
		this->addChild(this->Background);
		HX_STACK_LINE(185)
		this->HighScore = ::Main_obj::_this->savedata->data->__Field(HX_CSTRING("highscore"),true);
		HX_STACK_LINE(186)
		this->ufos = (int)0;
		HX_STACK_LINE(187)
		::haxe::ds::StringMap _g3 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(187)
		this->Players = _g3;
		HX_STACK_LINE(188)
		this->ControlEvent = false;
		HX_STACK_LINE(189)
		this->touched = false;
		HX_STACK_LINE(190)
		this->totalenemies = (int)0;
		HX_STACK_LINE(191)
		Array< ::Dynamic > _g4 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(191)
		this->activeEnemies = _g4;
		HX_STACK_LINE(192)
		Array< ::Dynamic > _g5 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(192)
		this->activeItems = _g5;
		HX_STACK_LINE(193)
		this->SpawnTimer = (int)150;
		HX_STACK_LINE(194)
		this->MSE = false;
		HX_STACK_LINE(195)
		::GameView_obj::_this = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(196)
		this->level = (int)0;
		HX_STACK_LINE(197)
		this->roundstarted = false;
		HX_STACK_LINE(198)
		this->frame = (int)0;
		HX_STACK_LINE(199)
		this->Hoster = true;
		HX_STACK_LINE(217)
		this->nmax = (int)0;
		HX_STACK_LINE(218)
		Array< bool > _g6 = Array_obj< bool >::__new();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(218)
		this->control = _g6;
		HX_STACK_LINE(219)
		this->control[(int)0] = false;
		HX_STACK_LINE(220)
		this->control[(int)1] = false;
		HX_STACK_LINE(221)
		this->control[(int)2] = false;
		HX_STACK_LINE(222)
		this->control[(int)3] = false;
		HX_STACK_LINE(228)
		Array< ::Dynamic > _g7 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(228)
		this->entities = _g7;
		HX_STACK_LINE(229)
		if (((this->AL == null()))){
			HX_STACK_LINE(231)
			::Animationloader _g8 = ::Animationloader_obj::__new();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(231)
			this->AL = _g8;
		}
		HX_STACK_LINE(239)
		if (((this->playerspick == HX_CSTRING("")))){
			HX_STACK_LINE(241)
			::String _g9 = ::Player_obj::getRandomCharacter();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(241)
			this->playerspick = _g9;
		}
		HX_STACK_LINE(243)
		::Player _g10 = ::Player_obj::__new(this->playerspick,this->control);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(243)
		this->myplayer = _g10;
		HX_STACK_LINE(246)
		this->myplayer->set_x((int)140);
		HX_STACK_LINE(247)
		this->myplayer->set_y((int)500);
		HX_STACK_LINE(248)
		this->myplayer->playername = this->playername;
		HX_STACK_LINE(259)
		if (((this->gamemode == (int)2))){
			HX_STACK_LINE(261)
			this->myplayer->lives = (int)30;
		}
		HX_STACK_LINE(263)
		if (((this->gamemode == (int)8))){
			HX_STACK_LINE(265)
			this->level = (int)30;
		}
		HX_STACK_LINE(267)
		if (((this->gamemode == (int)9))){
			HX_STACK_LINE(269)
			this->level = (int)60;
		}
		HX_STACK_LINE(271)
		if (((this->gamemode == (int)10))){
			HX_STACK_LINE(273)
			this->level = (int)90;
		}
		HX_STACK_LINE(275)
		if (((this->gamemode == (int)11))){
			HX_STACK_LINE(277)
			this->level = (int)120;
		}
		HX_STACK_LINE(302)
		this->myplayer->ID = HX_CSTRING("Myself");
		HX_STACK_LINE(306)
		this->spawnplatform((int)568);
		HX_STACK_LINE(307)
		this->spawnplatform((int)408);
		HX_STACK_LINE(309)
		this->spawnplatform((int)248);
		HX_STACK_LINE(311)
		this->spawnplatform((int)88);
		HX_STACK_LINE(314)
		this->setformation();
		HX_STACK_LINE(315)
		::PowBlock _g111 = ::PowBlock_obj::__new(HX_CSTRING("POW"));		HX_STACK_VAR(_g111,"_g111");
		HX_STACK_LINE(315)
		this->powblock = _g111;
		HX_STACK_LINE(316)
		this->powblock->set_x((int)368);
		HX_STACK_LINE(317)
		this->powblock->set_y((int)344);
		HX_STACK_LINE(318)
		this->powblock->solid = true;
		HX_STACK_LINE(319)
		this->AddObject(this->powblock);
		HX_STACK_LINE(321)
		::openfl::_v2::text::TextFormat tmp = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(322)
		tmp->font = HX_CSTRING("Arial");
		HX_STACK_LINE(323)
		tmp->size = (int)22;
		HX_STACK_LINE(324)
		::openfl::_v2::text::TextField _g12 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(324)
		this->TF = _g12;
		HX_STACK_LINE(326)
		this->TF->setTextFormat(tmp,null(),null());
		HX_STACK_LINE(327)
		this->TF->set_x((int)200);
		HX_STACK_LINE(328)
		this->TF->set_y((int)10);
		HX_STACK_LINE(329)
		this->TF->set_visible(true);
		HX_STACK_LINE(330)
		::openfl::_v2::text::TextFormat _g13 = ::openfl::_v2::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(330)
		tmp = _g13;
		HX_STACK_LINE(331)
		tmp->font = HX_CSTRING("Arial");
		HX_STACK_LINE(332)
		tmp->size = (int)66;
		HX_STACK_LINE(333)
		tmp->color = (int)16711680;
		HX_STACK_LINE(334)
		::openfl::_v2::text::TextField _g14 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(334)
		this->gameover = _g14;
		HX_STACK_LINE(335)
		this->gameover->set_x((int)200);
		HX_STACK_LINE(336)
		this->gameover->set_y((int)150);
		HX_STACK_LINE(337)
		this->gameover->set_text(HX_CSTRING("GAME OVER!"));
		HX_STACK_LINE(338)
		this->gameover->setTextFormat(tmp,null(),null());
		HX_STACK_LINE(339)
		this->gameover->set_width((int)450);
		HX_STACK_LINE(340)
		this->gameover->set_mouseEnabled(false);
		HX_STACK_LINE(341)
		this->gameover->set_visible(false);
		HX_STACK_LINE(342)
		this->addChild(this->gameover);
		HX_STACK_LINE(344)
		::openfl::_v2::text::TextField _g15 = ::openfl::_v2::text::TextField_obj::__new();		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(344)
		this->scoreboard = _g15;
		HX_STACK_LINE(345)
		this->scoreboard->set_text(HX_CSTRING(""));
		HX_STACK_LINE(346)
		this->scoreboard->set_x((int)300);
		HX_STACK_LINE(347)
		this->scoreboard->set_y((int)10);
		HX_STACK_LINE(353)
		this->scoreboard->set_blendMode(::openfl::_v2::display::BlendMode_obj::INVERT);
		HX_STACK_LINE(354)
		this->addChild(this->scoreboard);
		HX_STACK_LINE(358)
		Array< ::Dynamic > _g16 = this->AL->GetAnimation(HX_CSTRING("barrier"));		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(358)
		::openfl::_v2::display::BitmapData _g17 = _g16->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(358)
		::openfl::_v2::display::Bitmap B = ::openfl::_v2::display::Bitmap_obj::__new(_g17,null(),null());		HX_STACK_VAR(B,"B");
		HX_STACK_LINE(359)
		B->set_x((int)-60);
		HX_STACK_LINE(360)
		B->set_y((int)430);
		HX_STACK_LINE(361)
		this->addChild(B);
		HX_STACK_LINE(364)
		Array< ::Dynamic > _g18 = this->AL->GetAnimation(HX_CSTRING("barrierF"));		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(364)
		::openfl::_v2::display::BitmapData _g19 = _g18->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(364)
		::openfl::_v2::display::Bitmap _g20 = ::openfl::_v2::display::Bitmap_obj::__new(_g19,null(),null());		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(364)
		B = _g20;
		HX_STACK_LINE(365)
		B->set_x((int)700);
		HX_STACK_LINE(366)
		B->set_y((int)430);
		HX_STACK_LINE(367)
		this->addChild(B);
		HX_STACK_LINE(369)
		Array< ::Dynamic > _g21 = this->AL->GetAnimation(HX_CSTRING("barrier"));		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(369)
		::openfl::_v2::display::BitmapData _g22 = _g21->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(369)
		::openfl::_v2::display::Bitmap _g23 = ::openfl::_v2::display::Bitmap_obj::__new(_g22,null(),null());		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(369)
		B = _g23;
		HX_STACK_LINE(370)
		B->set_x((int)-60);
		HX_STACK_LINE(371)
		B->set_y((int)-40);
		HX_STACK_LINE(372)
		this->addChild(B);
		HX_STACK_LINE(374)
		Array< ::Dynamic > _g24 = this->AL->GetAnimation(HX_CSTRING("barrierF"));		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(374)
		::openfl::_v2::display::BitmapData _g25 = _g24->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >();		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(374)
		::openfl::_v2::display::Bitmap _g26 = ::openfl::_v2::display::Bitmap_obj::__new(_g25,null(),null());		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(374)
		B = _g26;
		HX_STACK_LINE(375)
		B->set_x((int)700);
		HX_STACK_LINE(376)
		B->set_y((int)-40);
		HX_STACK_LINE(377)
		this->addChild(B);
		HX_STACK_LINE(380)
		this->direction = (int)1;
		HX_STACK_LINE(381)
		this->AddPlayer(this->myplayer);
		HX_STACK_LINE(382)
		this->addChild(this->TF);
		HX_STACK_LINE(386)
		this->get_stage()->set_color((int)39287);
		HX_STACK_LINE(388)
		this->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::SHOW_ALL);
		HX_STACK_LINE(400)
		this->addEventListener(::openfl::_v2::events::Event_obj::ENTER_FRAME,this->this_onEnterFrame_dyn(),null(),null(),null());
		HX_STACK_LINE(401)
		this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_DOWN,this->on_mousedown_dyn(),null(),null(),null());
		HX_STACK_LINE(402)
		this->addEventListener(::openfl::_v2::events::MouseEvent_obj::MOUSE_UP,this->on_mouseup_dyn(),null(),null(),null());
		HX_STACK_LINE(403)
		this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_BEGIN,this->on_touchbegin_dyn(),null(),null(),null());
		HX_STACK_LINE(404)
		this->addEventListener(::openfl::_v2::events::TouchEvent_obj::TOUCH_END,this->on_touchend_dyn(),null(),null(),null());

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,_g)
		Void run(Dynamic ev){
			HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","GameView.hx",408,0x658aeb87)
			HX_STACK_ARG(ev,"ev")
			{
				HX_STACK_LINE(408)
				_g->__get((int)0).StaticCast< ::GameView >()->control[(int)2] = true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(408)
		this->get_stage()->addEventListener(HX_CSTRING("axisMove"), Dynamic(new _Function_1_2(_g)),null(),null(),null());
		HX_STACK_LINE(412)
		this->get_stage()->set_align(::openfl::display::StageAlign_obj::LEFT);
		HX_STACK_LINE(416)
		Float _g27 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g27,"_g27");
		HX_STACK_LINE(416)
		this->ltime = _g27;
		HX_STACK_LINE(417)
		this->missingTime = (int)0;
		HX_STACK_LINE(418)
		::List _g28 = ::List_obj::__new();		HX_STACK_VAR(_g28,"_g28");
		HX_STACK_LINE(418)
		this->SpawnList = _g28;
		HX_STACK_LINE(422)
		::openfl::_v2::display::BitmapData _g29 = ::openfl::_v2::Assets_obj::getBitmapData(HX_CSTRING("assets/bgcolor.png"),null());		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(422)
		::openfl::_v2::display::Bitmap _g30 = ::openfl::_v2::display::Bitmap_obj::__new(_g29,null(),null());		HX_STACK_VAR(_g30,"_g30");
		HX_STACK_LINE(422)
		this->BGCRight = _g30;
		HX_STACK_LINE(423)
		this->BGCRight->set_x((int)800);
		HX_STACK_LINE(424)
		this->BGCRight->set_y((int)0);
		HX_STACK_LINE(425)
		this->BGCRight->set_scaleX((int)500);
		HX_STACK_LINE(426)
		this->BGCRight->set_scaleY((int)2000);
		HX_STACK_LINE(430)
		this->addChild(this->BGCRight);
		HX_STACK_LINE(431)
		::openfl::_v2::display::BitmapData _g31 = ::openfl::_v2::Assets_obj::getBitmapData(HX_CSTRING("assets/bgcolor.png"),null());		HX_STACK_VAR(_g31,"_g31");
		HX_STACK_LINE(431)
		::openfl::_v2::display::Bitmap _g32 = ::openfl::_v2::display::Bitmap_obj::__new(_g31,null(),null());		HX_STACK_VAR(_g32,"_g32");
		HX_STACK_LINE(431)
		this->BGCLeft = _g32;
		HX_STACK_LINE(432)
		this->BGCLeft->set_x((int)-500);
		HX_STACK_LINE(433)
		this->BGCLeft->set_y((int)0);
		HX_STACK_LINE(434)
		this->BGCLeft->set_scaleX((int)500);
		HX_STACK_LINE(435)
		this->BGCLeft->set_scaleY((int)2000);
		HX_STACK_LINE(437)
		this->addChild(this->BGCLeft);
		HX_STACK_LINE(438)
		::openfl::_v2::display::BitmapData _g33 = ::openfl::_v2::Assets_obj::getBitmapData(HX_CSTRING("assets/bgcolor.png"),null());		HX_STACK_VAR(_g33,"_g33");
		HX_STACK_LINE(438)
		::openfl::_v2::display::Bitmap _g34 = ::openfl::_v2::display::Bitmap_obj::__new(_g33,null(),null());		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(438)
		this->BGCBottom = _g34;
		HX_STACK_LINE(439)
		this->BGCBottom->set_x((int)-500);
		HX_STACK_LINE(440)
		this->BGCBottom->set_y((int)600);
		HX_STACK_LINE(441)
		this->BGCBottom->set_scaleX((int)1500);
		HX_STACK_LINE(442)
		this->BGCBottom->set_scaleY((int)1000);
		HX_STACK_LINE(444)
		this->addChild(this->BGCBottom);
		HX_STACK_LINE(445)
		::openfl::_v2::display::BitmapData _g35 = ::openfl::_v2::Assets_obj::getBitmapData(HX_CSTRING("assets/Dpad.png"),null());		HX_STACK_VAR(_g35,"_g35");
		HX_STACK_LINE(445)
		::openfl::_v2::display::Bitmap _g36 = ::openfl::_v2::display::Bitmap_obj::__new(_g35,null(),null());		HX_STACK_VAR(_g36,"_g36");
		HX_STACK_LINE(445)
		this->Dpad = _g36;
		HX_STACK_LINE(446)
		this->Dpad->set_x((int)0);
		HX_STACK_LINE(447)
		this->Dpad->set_y((int)600);
		HX_STACK_LINE(448)
		this->addChild(this->Dpad);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,start,(void))

Void GameView_obj::setformation( ){
{
		HX_STACK_FRAME("GameView","setformation",0x159ee646,"GameView.setformation","GameView.hx",452,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(452)
		if (((this->platformformation == (int)0))){
			HX_STACK_LINE(454)
			this->setholeinplatform((int)408,(int)256,(int)512,false);
			HX_STACK_LINE(455)
			this->setholeinplatform((int)248,(int)192,(int)576,true);
			HX_STACK_LINE(456)
			this->setholeinplatform((int)88,(int)256,(int)512,false);
			HX_STACK_LINE(457)
			this->setplatformasplatform((int)408,false);
			HX_STACK_LINE(458)
			this->setplatformasplatform((int)248,false);
			HX_STACK_LINE(459)
			this->setplatformasplatform((int)88,false);
			HX_STACK_LINE(460)
			this->currentformation = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,setformation,(void))

Void GameView_obj::spawnplatform( Float Y){
{
		HX_STACK_FRAME("GameView","spawnplatform",0x6c2ce8d7,"GameView.spawnplatform","GameView.hx",465,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Y,"Y")
		HX_STACK_LINE(466)
		int xx = (int)0;		HX_STACK_VAR(xx,"xx");
		HX_STACK_LINE(467)
		hx::SubEq(xx,(int)256);
		HX_STACK_LINE(468)
		while((true)){
			HX_STACK_LINE(468)
			if ((!(((xx < (int)1056))))){
				HX_STACK_LINE(468)
				break;
			}
			HX_STACK_LINE(470)
			::Block block = ::Block_obj::__new(HX_CSTRING("block"));		HX_STACK_VAR(block,"block");
			HX_STACK_LINE(471)
			block->set_x(xx);
			HX_STACK_LINE(472)
			block->set_y(Y);
			HX_STACK_LINE(473)
			block->solid = true;
			HX_STACK_LINE(474)
			this->AddObject(block);
			HX_STACK_LINE(475)
			hx::AddEq(xx,(int)32);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,spawnplatform,(void))

Void GameView_obj::setholeinplatform( Float Y,Float minx,Float maxx,bool inverse){
{
		HX_STACK_FRAME("GameView","setholeinplatform",0xd3695563,"GameView.setholeinplatform","GameView.hx",479,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Y,"Y")
		HX_STACK_ARG(minx,"minx")
		HX_STACK_ARG(maxx,"maxx")
		HX_STACK_ARG(inverse,"inverse")
		HX_STACK_LINE(480)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(481)
		while((true)){
			HX_STACK_LINE(481)
			if ((!(((i < this->entities->length))))){
				HX_STACK_LINE(481)
				break;
			}
			HX_STACK_LINE(484)
			::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(485)
			Dynamic D = E;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(486)
			::Block B = D;		HX_STACK_VAR(B,"B");
			HX_STACK_LINE(487)
			if (((E->type == HX_CSTRING("Block")))){
				HX_STACK_LINE(490)
				Float _g = B->get_y();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(490)
				if (((_g == Y))){
					HX_STACK_LINE(492)
					Float _g1 = B->get_x();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(492)
					bool ok;		HX_STACK_VAR(ok,"ok");
					HX_STACK_LINE(492)
					if (((_g1 > minx))){
						HX_STACK_LINE(492)
						Float _g2 = B->get_x();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(492)
						ok = (_g2 < maxx);
					}
					else{
						HX_STACK_LINE(492)
						ok = false;
					}
					HX_STACK_LINE(493)
					if ((inverse)){
						HX_STACK_LINE(495)
						ok = !(ok);
					}
					HX_STACK_LINE(497)
					B->solid = !(ok);
				}
			}
			HX_STACK_LINE(500)
			hx::AddEq(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GameView_obj,setholeinplatform,(void))

Void GameView_obj::setplatformasplatform( Float Y,bool platform){
{
		HX_STACK_FRAME("GameView","setplatformasplatform",0xefad9c23,"GameView.setplatformasplatform","GameView.hx",504,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(Y,"Y")
		HX_STACK_ARG(platform,"platform")
		HX_STACK_LINE(505)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(506)
		while((true)){
			HX_STACK_LINE(506)
			if ((!(((i < this->entities->length))))){
				HX_STACK_LINE(506)
				break;
			}
			HX_STACK_LINE(509)
			::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(510)
			Dynamic D = E;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(511)
			::Block B = D;		HX_STACK_VAR(B,"B");
			HX_STACK_LINE(512)
			if (((E->type == HX_CSTRING("Block")))){
				HX_STACK_LINE(515)
				Float _g = B->get_y();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(515)
				if (((_g == Y))){
					HX_STACK_LINE(517)
					B->platform = platform;
				}
			}
			HX_STACK_LINE(520)
			hx::AddEq(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameView_obj,setplatformasplatform,(void))

Void GameView_obj::on_touchend( ::openfl::_v2::events::TouchEvent event){
{
		HX_STACK_FRAME("GameView","on_touchend",0xa7693085,"GameView.on_touchend","GameView.hx",523,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(524)
		this->MSE = false;
		HX_STACK_LINE(524)
		this->control[(int)0] = false;
		HX_STACK_LINE(524)
		this->control[(int)1] = false;
		HX_STACK_LINE(524)
		this->control[(int)2] = false;
		HX_STACK_LINE(524)
		this->control[(int)3] = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,on_touchend,(void))

Void GameView_obj::on_touchbegin( ::openfl::_v2::events::TouchEvent event){
{
		HX_STACK_FRAME("GameView","on_touchbegin",0x78561553,"GameView.on_touchbegin","GameView.hx",526,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(527)
		::openfl::_v2::Lib_obj::get_current()->get_stage()->set_displayState(::openfl::display::StageDisplayState_obj::FULL_SCREEN);
		HX_STACK_LINE(527)
		this->MSE = true;
		HX_STACK_LINE(527)
		this->touched = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,on_touchbegin,(void))

Void GameView_obj::on_mousedown( ::openfl::_v2::events::MouseEvent event){
{
		HX_STACK_FRAME("GameView","on_mousedown",0xbae109de,"GameView.on_mousedown","GameView.hx",530,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(530)
		this->MSE = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,on_mousedown,(void))

Void GameView_obj::on_mouseup( ::openfl::_v2::events::MouseEvent event){
{
		HX_STACK_FRAME("GameView","on_mouseup",0xd702e0d7,"GameView.on_mouseup","GameView.hx",536,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(536)
		if ((!(this->touched))){
			HX_STACK_LINE(537)
			this->MSE = false;
			HX_STACK_LINE(538)
			this->control[(int)0] = false;
			HX_STACK_LINE(539)
			this->control[(int)1] = false;
			HX_STACK_LINE(540)
			this->control[(int)2] = false;
			HX_STACK_LINE(541)
			this->control[(int)3] = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,on_mouseup,(void))

::String GameView_obj::GetNetworkID( ){
	HX_STACK_FRAME("GameView","GetNetworkID",0x27255fea,"GameView.GetNetworkID","GameView.hx",546,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_LINE(547)
	if ((this->online)){
	}
	else{
		HX_STACK_LINE(558)
		return HX_CSTRING("Myself");
	}
	HX_STACK_LINE(560)
	return HX_CSTRING("Myself");
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,GetNetworkID,return )

Void GameView_obj::PlayMusic( ){
{
		HX_STACK_FRAME("GameView","PlayMusic",0x896c5a5a,"GameView.PlayMusic","GameView.hx",563,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(575)
		int L = ::Math_obj::floor((Float(((this->level - (int)1))) / Float((int)5)));		HX_STACK_VAR(L,"L");
		HX_STACK_LINE(576)
		if (((this->gamemode == (int)4))){
			HX_STACK_LINE(578)
			hx::AddEq(L,(int)6);
		}
		HX_STACK_LINE(585)
		Array< int > A = Array_obj< int >::__new().Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)6).Add((int)7).Add((int)8).Add((int)9).Add((int)10).Add((int)11).Add((int)12);		HX_STACK_VAR(A,"A");
		HX_STACK_LINE(586)
		if (((L < (int)0))){
			HX_STACK_LINE(588)
			L = (int)0;
		}
		HX_STACK_LINE(590)
		while((true)){
			HX_STACK_LINE(590)
			if ((!(((L >= A->length))))){
				HX_STACK_LINE(590)
				break;
			}
			HX_STACK_LINE(592)
			hx::SubEq(L,A->length);
		}
		HX_STACK_LINE(597)
		::openfl::_v2::media::SoundChannel _g = ::SoundManager_obj::PlayMusic((HX_CSTRING("theme") + A->__get(L)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(597)
		this->musicchannel = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,PlayMusic,(void))

::Player GameView_obj::GetPlayer( ::String ID){
	HX_STACK_FRAME("GameView","GetPlayer",0x0c3cd0e0,"GameView.GetPlayer","GameView.hx",601,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ID,"ID")
	HX_STACK_LINE(602)
	::String _g = this->GetNetworkID();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(602)
	if ((((HX_CSTRING("") + ID) == _g))){
		HX_STACK_LINE(604)
		ID = HX_CSTRING("Myself");
	}
	HX_STACK_LINE(606)
	return this->Players->get(ID);
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,GetPlayer,return )

Void GameView_obj::AddPlayer( ::Player P){
{
		HX_STACK_FRAME("GameView","AddPlayer",0x480a7cab,"GameView.AddPlayer","GameView.hx",609,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_LINE(610)
		{
			HX_STACK_LINE(610)
			this->Players->set(P->ID,P);
			HX_STACK_LINE(610)
			P;
		}
		HX_STACK_LINE(611)
		this->AddObject(P);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,AddPlayer,(void))

Void GameView_obj::SendGap( ){
{
		HX_STACK_FRAME("GameView","SendGap",0xb487acb7,"GameView.SendGap","GameView.hx",615,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(615)
		if ((this->Hoster)){
			HX_STACK_LINE(617)
			int X = (int)20;		HX_STACK_VAR(X,"X");
			HX_STACK_LINE(618)
			int Y = (int)0;		HX_STACK_VAR(Y,"Y");
			HX_STACK_LINE(619)
			Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(619)
			if (((_g > 0.5))){
				HX_STACK_LINE(621)
				X = (int)780;
			}
			HX_STACK_LINE(623)
			Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(623)
			Float _g2 = ((int)4 * _g1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(623)
			int _g3 = ::Math_obj::floor(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(623)
			int R = (_g3 * (int)160);		HX_STACK_VAR(R,"R");
			HX_STACK_LINE(624)
			hx::AddEq(Y,(R - (int)32));
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",625,0x658aeb87)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(625)
			Dynamic D = _Function_2_1::Block();		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(626)
			D->__FieldRef(HX_CSTRING("x")) = X;
			HX_STACK_LINE(627)
			D->__FieldRef(HX_CSTRING("y")) = Y;
			HX_STACK_LINE(628)
			Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(628)
			D->__FieldRef(HX_CSTRING("UID")) = _g4;
			HX_STACK_LINE(629)
			this->SendEvent(HX_CSTRING("SendGap"),D);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,SendGap,(void))

Void GameView_obj::RemovePlayer( ::String P){
{
		HX_STACK_FRAME("GameView","RemovePlayer",0xe8bb3e1c,"GameView.RemovePlayer","GameView.hx",646,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(P,"P")
		HX_STACK_LINE(646)
		if (((P != HX_CSTRING("Myself")))){
			HX_STACK_LINE(648)
			::Player player = this->Players->get(P);		HX_STACK_VAR(player,"player");
			HX_STACK_LINE(649)
			if (((player != null()))){
				HX_STACK_LINE(651)
				if (((player->nameplate != null()))){
					HX_STACK_LINE(653)
					this->removeChild(player->nameplate);
				}
				HX_STACK_LINE(655)
				this->Players->remove(P);
				HX_STACK_LINE(656)
				this->removeChild(player);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,RemovePlayer,(void))

Void GameView_obj::AddEntityItem( ::EntityItem E){
{
		HX_STACK_FRAME("GameView","AddEntityItem",0x7a55d020,"GameView.AddEntityItem","GameView.hx",663,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(664)
		this->AddObject(E);
		HX_STACK_LINE(665)
		this->activeItems[this->activeItems->length] = E;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,AddEntityItem,(void))

Void GameView_obj::AddEnemy( ::Enemy E){
{
		HX_STACK_FRAME("GameView","AddEnemy",0x53dab83e,"GameView.AddEnemy","GameView.hx",667,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(668)
		this->AddObject(E);
		HX_STACK_LINE(669)
		if ((E->respawn)){
			HX_STACK_LINE(671)
			this->activeEnemies[this->activeEnemies->length] = E;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,AddEnemy,(void))

Void GameView_obj::AddObject( ::Entity E){
{
		HX_STACK_FRAME("GameView","AddObject",0x25911009,"GameView.AddObject","GameView.hx",674,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(E,"E")
		HX_STACK_LINE(678)
		this->entities[this->entities->length] = E;
		HX_STACK_LINE(679)
		this->addChild(E);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,AddObject,(void))

Void GameView_obj::RemoveEntityItem( ::Entity I){
{
		HX_STACK_FRAME("GameView","RemoveEntityItem",0x99429e11,"GameView.RemoveEntityItem","GameView.hx",681,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(I,"I")
		HX_STACK_LINE(682)
		Dynamic D = I;		HX_STACK_VAR(D,"D");
		HX_STACK_LINE(683)
		this->RemoveObject(I);
		HX_STACK_LINE(684)
		this->activeItems->remove(D);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,RemoveEntityItem,(void))

Void GameView_obj::RemoveEnemy( ::Entity I){
{
		HX_STACK_FRAME("GameView","RemoveEnemy",0x3222afed,"GameView.RemoveEnemy","GameView.hx",686,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(I,"I")
		HX_STACK_LINE(687)
		Dynamic D = I;		HX_STACK_VAR(D,"D");
		HX_STACK_LINE(688)
		this->RemoveObject(I);
		HX_STACK_LINE(689)
		this->activeEnemies->remove(D);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,RemoveEnemy,(void))

Void GameView_obj::RemoveObject( ::Entity I){
{
		HX_STACK_FRAME("GameView","RemoveObject",0xc641d17a,"GameView.RemoveObject","GameView.hx",691,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(I,"I")
		HX_STACK_LINE(692)
		this->removeChild(I);
		HX_STACK_LINE(693)
		this->entities->remove(I);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,RemoveObject,(void))

::Entity GameView_obj::CollisionDetectPoint( Float X,Float Y){
	HX_STACK_FRAME("GameView","CollisionDetectPoint",0x48d3ddf2,"GameView.CollisionDetectPoint","GameView.hx",696,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(697)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(698)
	::Entity ret = null();		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(708)
	while((true)){
		HX_STACK_LINE(708)
		if ((!(((i < this->entities->length))))){
			HX_STACK_LINE(708)
			break;
		}
		HX_STACK_LINE(710)
		::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(711)
		if ((E->solid)){
			HX_STACK_LINE(717)
			::openfl::_v2::geom::Point _g = ::openfl::_v2::geom::Point_obj::__new(X,Y);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(717)
			if ((E->GetHitbox()->containsPoint(_g))){
				HX_STACK_LINE(719)
				ret = E;
				HX_STACK_LINE(720)
				i = this->entities->length;
				HX_STACK_LINE(721)
				return E;
			}
		}
		HX_STACK_LINE(724)
		hx::AddEq(i,(int)1);
	}
	HX_STACK_LINE(726)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC2(GameView_obj,CollisionDetectPoint,return )

::EntityItem GameView_obj::CollisionDetectPointItem( Float X,Float Y){
	HX_STACK_FRAME("GameView","CollisionDetectPointItem",0xc417b025,"GameView.CollisionDetectPointItem","GameView.hx",728,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(729)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(730)
	while((true)){
		HX_STACK_LINE(730)
		if ((!(((i < this->activeItems->length))))){
			HX_STACK_LINE(730)
			break;
		}
		HX_STACK_LINE(732)
		::EntityItem E = this->activeItems->__get(i).StaticCast< ::EntityItem >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(733)
		if (((bool(!(E->killed)) && bool(E->alive)))){
			HX_STACK_LINE(737)
			::openfl::_v2::geom::Point _g = ::openfl::_v2::geom::Point_obj::__new(X,Y);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(737)
			if ((E->GetHitbox()->containsPoint(_g))){
				HX_STACK_LINE(739)
				return E;
			}
		}
		HX_STACK_LINE(742)
		hx::AddEq(i,(int)1);
	}
	HX_STACK_LINE(745)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameView_obj,CollisionDetectPointItem,return )

::Player GameView_obj::CollisionDetectPointPlayer( Float X,Float Y){
	HX_STACK_FRAME("GameView","CollisionDetectPointPlayer",0xec2f3ef3,"GameView.CollisionDetectPointPlayer","GameView.hx",747,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(748)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(749)
	Array< ::Dynamic > PL = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(PL,"PL");
	HX_STACK_LINE(750)
	Dynamic A = this->Players->iterator();		HX_STACK_VAR(A,"A");
	HX_STACK_LINE(751)
	while((true)){
		HX_STACK_LINE(751)
		if ((!(A->__Field(HX_CSTRING("hasNext"),true)()))){
			HX_STACK_LINE(751)
			break;
		}
		HX_STACK_LINE(753)
		::Player E = A->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(754)
		if ((!(E->killed))){
			HX_STACK_LINE(756)
			::openfl::_v2::geom::Point _g = ::openfl::_v2::geom::Point_obj::__new(X,Y);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(756)
			if ((E->GetHitbox()->containsPoint(_g))){
				HX_STACK_LINE(758)
				return E;
			}
		}
	}
	HX_STACK_LINE(788)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameView_obj,CollisionDetectPointPlayer,return )

::Enemy GameView_obj::CollisionDetectPointEnemy( Float X,Float Y){
	HX_STACK_FRAME("GameView","CollisionDetectPointEnemy",0x7f10d6f6,"GameView.CollisionDetectPointEnemy","GameView.hx",790,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(791)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(792)
	while((true)){
		HX_STACK_LINE(792)
		if ((!(((i < this->activeEnemies->length))))){
			HX_STACK_LINE(792)
			break;
		}
		HX_STACK_LINE(794)
		::Enemy E = this->activeEnemies->__get(i).StaticCast< ::Enemy >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(795)
		if ((!(E->killed))){
			HX_STACK_LINE(799)
			::openfl::_v2::geom::Point _g = ::openfl::_v2::geom::Point_obj::__new(X,Y);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(799)
			if ((E->GetHitbox()->containsPoint(_g))){
				HX_STACK_LINE(801)
				return E;
			}
		}
		HX_STACK_LINE(804)
		hx::AddEq(i,(int)1);
	}
	HX_STACK_LINE(807)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameView_obj,CollisionDetectPointEnemy,return )

::Entity GameView_obj::CollisionDetectPointDangerous( Float X,Float Y){
	HX_STACK_FRAME("GameView","CollisionDetectPointDangerous",0xc90db138,"GameView.CollisionDetectPointDangerous","GameView.hx",809,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(X,"X")
	HX_STACK_ARG(Y,"Y")
	HX_STACK_LINE(810)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(811)
	::Entity ret = null();		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(812)
	while((true)){
		HX_STACK_LINE(812)
		if ((!(((i < this->entities->length))))){
			HX_STACK_LINE(812)
			break;
		}
		HX_STACK_LINE(814)
		::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(815)
		if (((bool(E->dangerous) && bool(!(E->killed))))){
			HX_STACK_LINE(818)
			::openfl::_v2::geom::Point _g = ::openfl::_v2::geom::Point_obj::__new(X,Y);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(818)
			if ((E->GetHitbox()->containsPoint(_g))){
				HX_STACK_LINE(820)
				ret = E;
				HX_STACK_LINE(821)
				i = this->entities->length;
				HX_STACK_LINE(822)
				return E;
			}
		}
		HX_STACK_LINE(825)
		hx::AddEq(i,(int)1);
	}
	HX_STACK_LINE(827)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC2(GameView_obj,CollisionDetectPointDangerous,return )

::Enemy GameView_obj::CollisionDetectTouchEnemy( ::Entity target){
	HX_STACK_FRAME("GameView","CollisionDetectTouchEnemy",0x98e3a127,"GameView.CollisionDetectTouchEnemy","GameView.hx",829,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(target,"target")
	HX_STACK_LINE(830)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(831)
	::openfl::_v2::geom::Rectangle R = target->getBounds(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(R,"R");
	HX_STACK_LINE(832)
	while((true)){
		HX_STACK_LINE(832)
		if ((!(((i < this->activeEnemies->length))))){
			HX_STACK_LINE(832)
			break;
		}
		HX_STACK_LINE(834)
		::Enemy E = this->activeEnemies->__get(i).StaticCast< ::Enemy >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(836)
		if ((!(E->killed))){
			HX_STACK_LINE(840)
			::openfl::_v2::geom::Rectangle _g = E->getBounds(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(840)
			if ((R->intersects(_g))){
				HX_STACK_LINE(842)
				return E;
			}
		}
		HX_STACK_LINE(845)
		hx::AddEq(i,(int)1);
	}
	HX_STACK_LINE(848)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,CollisionDetectTouchEnemy,return )

::EntityItem GameView_obj::CollisionDetectTouchItem( ::Entity target){
	HX_STACK_FRAME("GameView","CollisionDetectTouchItem",0xb422f714,"GameView.CollisionDetectTouchItem","GameView.hx",850,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(target,"target")
	HX_STACK_LINE(851)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(852)
	::openfl::_v2::geom::Rectangle R = target->getBounds(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(R,"R");
	HX_STACK_LINE(853)
	while((true)){
		HX_STACK_LINE(853)
		if ((!(((i < this->activeItems->length))))){
			HX_STACK_LINE(853)
			break;
		}
		HX_STACK_LINE(855)
		::EntityItem E = this->activeItems->__get(i).StaticCast< ::EntityItem >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(857)
		if ((!(E->killed))){
			HX_STACK_LINE(861)
			::openfl::_v2::geom::Rectangle _g = E->getBounds(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(861)
			if ((R->intersects(_g))){
				HX_STACK_LINE(863)
				return E;
			}
		}
		HX_STACK_LINE(866)
		hx::AddEq(i,(int)1);
	}
	HX_STACK_LINE(869)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,CollisionDetectTouchItem,return )

bool GameView_obj::ismyplayer( ::Entity E){
	HX_STACK_FRAME("GameView","ismyplayer",0xb3a8592e,"GameView.ismyplayer","GameView.hx",873,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(E,"E")
	HX_STACK_LINE(873)
	return (E->UID == this->myplayer->UID);
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,ismyplayer,return )

Void GameView_obj::SendEvent( ::String evt,Dynamic data){
{
		HX_STACK_FRAME("GameView","SendEvent",0x8e61e1fb,"GameView.SendEvent","GameView.hx",875,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_ARG(data,"data")
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",876,0x658aeb87)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(876)
		Dynamic D = _Function_1_1::Block();		HX_STACK_VAR(D,"D");
		HX_STACK_LINE(877)
		D->__FieldRef(HX_CSTRING("evt")) = evt;
		HX_STACK_LINE(878)
		D->__FieldRef(HX_CSTRING("data")) = data;
		HX_STACK_LINE(880)
		::String _g = this->GetNetworkID();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(880)
		(D->__Field(HX_CSTRING("ID"),true) == _g);
		HX_STACK_LINE(887)
		this->ProcessEvent(D->__Field(HX_CSTRING("evt"),true),D->__Field(HX_CSTRING("ID"),true),D->__Field(HX_CSTRING("data"),true));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameView_obj,SendEvent,(void))

Void GameView_obj::ProcessEvent( ::String evt,::String ID,Dynamic data){
{
		HX_STACK_FRAME("GameView","ProcessEvent",0x9f4e1a82,"GameView.ProcessEvent","GameView.hx",889,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(evt,"evt")
		HX_STACK_ARG(ID,"ID")
		HX_STACK_ARG(data,"data")
		HX_STACK_LINE(889)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::GameView_obj > __this,::String &ID){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",890,0x658aeb87)
				{
					HX_STACK_LINE(890)
					::String _g1 = __this->GetNetworkID();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(890)
					return (ID == _g1);
				}
				return null();
			}
		};
		HX_STACK_LINE(890)
		if (((  ((!(((  ((!(((ID == HX_CSTRING("Unknown")))))) ? bool(_Function_1_1::Block(this,ID)) : bool(true) ))))) ? bool((ID == null())) : bool(true) ))){
			HX_STACK_LINE(893)
			ID = HX_CSTRING("Myself");
		}
		HX_STACK_LINE(895)
		::Player P = this->GetPlayer(ID);		HX_STACK_VAR(P,"P");
		HX_STACK_LINE(897)
		bool me = this->ismyplayer(P);		HX_STACK_VAR(me,"me");
		HX_STACK_LINE(898)
		if (((P != null()))){
			HX_STACK_LINE(901)
			P->frame = this->frame;
		}
		HX_STACK_LINE(904)
		if (((evt == HX_CSTRING("PlayerDeath")))){
			HX_STACK_LINE(905)
			if (((P != null()))){
				HX_STACK_LINE(907)
				P->killed = true;
				HX_STACK_LINE(908)
				P->Vspeed = (int)-9;
				HX_STACK_LINE(909)
				::SoundManager_obj::Play(HX_CSTRING("died"));
			}
			else{
				HX_STACK_LINE(913)
				this->TF->set_text(HX_CSTRING("'No one'\ndied???"));
			}
		}
		HX_STACK_LINE(916)
		if (((evt == HX_CSTRING("Kill")))){
			HX_STACK_LINE(917)
			::Entity E = this->EntityFromUID(data);		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(918)
			if (((bool((E != null())) && bool(!(E->killed))))){
				HX_STACK_LINE(920)
				E->killed = true;
				HX_STACK_LINE(921)
				Dynamic D = E;		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(922)
				if (((D->__Field(HX_CSTRING("charname"),true) == HX_CSTRING("Cirno")))){
					HX_STACK_LINE(931)
					if ((D->__Field(HX_CSTRING("alive"),true))){
						HX_STACK_LINE(934)
						D->__FieldRef(HX_CSTRING("killed")) = true;
					}
				}
				HX_STACK_LINE(938)
				if (((bool(me) && bool((D->__Field(HX_CSTRING("charname"),true) == HX_CSTRING("Imposter")))))){
					HX_STACK_LINE(940)
					if ((!(D->__Field(HX_CSTRING("hidden"),true)))){
						HX_STACK_LINE(942)
						hx::IndexRef((::Main_obj::_this->savedata->data->__Field(HX_CSTRING("unlock"),true)).mPtr,D->__Field(HX_CSTRING("unlock"),true)) = true;
						HX_STACK_LINE(943)
						if ((D->__Field(HX_CSTRING("alternate"),true))){
							HX_STACK_LINE(945)
							hx::IndexRef((::Main_obj::_this->savedata->data->__Field(HX_CSTRING("alts"),true)).mPtr,D->__Field(HX_CSTRING("unlock"),true)) = true;
						}
					}
					else{
						HX_STACK_LINE(950)
						hx::IndexRef((::Main_obj::_this->savedata->data->__Field(HX_CSTRING("hidden"),true)).mPtr,D->__Field(HX_CSTRING("unlock"),true)) = true;
					}
				}
				HX_STACK_LINE(953)
				if (((this->totalenemies != (int)1))){
					HX_STACK_LINE(955)
					::SoundManager_obj::Play(HX_CSTRING("killenemy"));
				}
				else{
					HX_STACK_LINE(959)
					Dynamic D1 = E;		HX_STACK_VAR(D1,"D1");
					HX_STACK_LINE(960)
					if (((bool((E->type == HX_CSTRING("Enemy"))) && bool(D1->__Field(HX_CSTRING("enraged"),true))))){
						HX_STACK_LINE(962)
						::SoundManager_obj::Play(HX_CSTRING("finalkill"));
					}
					else{
						HX_STACK_LINE(966)
						::SoundManager_obj::Play(HX_CSTRING("killenemy"));
					}
					HX_STACK_LINE(969)
					::GameView_obj::_this->SpawnTimer = (int)60;
				}
				HX_STACK_LINE(971)
				if ((!(me))){
					HX_STACK_LINE(973)
					E->catchup();
				}
				HX_STACK_LINE(975)
				if (((P != null()))){
					HX_STACK_LINE(977)
					hx::AddEq(P->score,(int)100);
				}
			}
		}
		HX_STACK_LINE(982)
		if (((bool((evt == HX_CSTRING("SpawnEnemy"))) || bool((evt == HX_CSTRING("SpawnItem")))))){
			HX_STACK_LINE(984)
			Dynamic E = this->AddEntityFromData(data);		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(985)
			if (((evt == HX_CSTRING("SpawnEnemy")))){
				HX_STACK_LINE(987)
				if ((E->__Field(HX_CSTRING("respawn"),true))){
					HX_STACK_LINE(989)
					(this->spawns)++;
				}
			}
		}
		HX_STACK_LINE(993)
		if (((evt == HX_CSTRING("Headbonk")))){
			HX_STACK_LINE(995)
			::Entity E = this->EntityFromUID(data);		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(997)
			if (((E != null()))){
				HX_STACK_LINE(999)
				if (((E == this->powblock))){
					HX_STACK_LINE(1002)
					if (((bool(this->Hoster) && bool((this->powblock->HP > (int)0))))){
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1005,0x658aeb87)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(1005)
						Dynamic D = _Function_5_1::Block();		HX_STACK_VAR(D,"D");
						HX_STACK_LINE(1006)
						D->__FieldRef(HX_CSTRING("HP")) = (this->powblock->HP - (int)1);
						HX_STACK_LINE(1007)
						if ((me)){
							HX_STACK_LINE(1009)
							::String _g1 = this->GetNetworkID();		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(1009)
							D->__FieldRef(HX_CSTRING("ID")) = _g1;
						}
						else{
							HX_STACK_LINE(1013)
							D->__FieldRef(HX_CSTRING("ID")) = ID;
						}
						HX_STACK_LINE(1015)
						this->SendEvent(HX_CSTRING("POW!"),D);
					}
				}
				else{
					HX_STACK_LINE(1020)
					E->bonked = (int)10;
					HX_STACK_LINE(1021)
					E->bonkedby = P;
					HX_STACK_LINE(1023)
					::SoundManager_obj::Play(HX_CSTRING("bonk"));
				}
			}
		}
		HX_STACK_LINE(1027)
		if (((evt == HX_CSTRING("TotalEnemies")))){
			HX_STACK_LINE(1029)
			this->totalenemies = data;
			HX_STACK_LINE(1030)
			this->roundstarted = true;
		}
		HX_STACK_LINE(1032)
		if (((evt == HX_CSTRING("NextLevel")))){
			HX_STACK_LINE(1034)
			::TypeofRound _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1034)
			{
				HX_STACK_LINE(1034)
				int index = data->__Field(HX_CSTRING("RoundType"),true);		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(1034)
				_g2 = ::Type_obj::createEnumIndex(hx::ClassOf< ::TypeofRound >(),index,null());
			}
			HX_STACK_LINE(1034)
			this->RoundType = _g2;
			HX_STACK_LINE(1036)
			this->set_x((int)0);
			HX_STACK_LINE(1037)
			this->set_y((int)0);
			HX_STACK_LINE(1038)
			this->set_scaleX((int)1);
			HX_STACK_LINE(1039)
			this->set_scaleY((int)1);
			HX_STACK_LINE(1040)
			if ((this->Hoster)){
				HX_STACK_LINE(1042)
				if (((hx::Mod(this->level,(int)5) == (int)1))){
					HX_STACK_LINE(1044)
					this->powblock->HP = (int)4;
					HX_STACK_LINE(1045)
					this->SendStatus();
				}
			}
			HX_STACK_LINE(1048)
			if (((bool((this->myplayer->score > this->HighScore)) && bool((this->gamemode == (int)0))))){
				HX_STACK_LINE(1050)
				this->HighScore = this->myplayer->score;
				HX_STACK_LINE(1051)
				::Main_obj::_this->savedata->data->__FieldRef(HX_CSTRING("highscore")) = this->HighScore;
			}
			HX_STACK_LINE(1053)
			this->ufos = (int)0;
			HX_STACK_LINE(1054)
			this->spawns = (int)0;
			HX_STACK_LINE(1055)
			this->roundstarted = false;
			HX_STACK_LINE(1056)
			this->level = data->__Field(HX_CSTRING("level"),true);
			HX_STACK_LINE(1057)
			int L = (this->level - (int)1);		HX_STACK_VAR(L,"L");
			HX_STACK_LINE(1058)
			if (((L < (int)0))){
				HX_STACK_LINE(1060)
				L = (int)0;
			}
			HX_STACK_LINE(1062)
			int _g3 = ::Math_obj::floor((Float(L) / Float((int)30)));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(1062)
			this->rank = _g3;
			HX_STACK_LINE(1065)
			int _g4 = ::Math_obj::floor((Float(((this->level - (int)1))) / Float((int)5)));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(1065)
			L = _g4;
			HX_STACK_LINE(1066)
			Array< ::Dynamic > A = this->AL->GetAnimation(HX_CSTRING("BG"));		HX_STACK_VAR(A,"A");
			HX_STACK_LINE(1067)
			if (((L < (int)0))){
				HX_STACK_LINE(1069)
				L = (int)0;
			}
			HX_STACK_LINE(1071)
			while((true)){
				HX_STACK_LINE(1071)
				if ((!(((L >= A->length))))){
					HX_STACK_LINE(1071)
					break;
				}
				HX_STACK_LINE(1073)
				hx::SubEq(L,A->length);
			}
			HX_STACK_LINE(1075)
			this->Background->set_bitmapData(A->__get(L).StaticCast< ::openfl::_v2::display::BitmapData >());

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
			Void run(::openfl::_v2::events::Event e){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","GameView.hx",1081,0x658aeb87)
				HX_STACK_ARG(e,"e")
				{
					HX_STACK_LINE(1081)
					_g->__get((int)0).StaticCast< ::GameView >()->PlayMusic();
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(1081)
			::SoundManager_obj::PlayJingle(HX_CSTRING("nextlevel"))->addEventListener(::openfl::_v2::events::Event_obj::SOUND_COMPLETE, Dynamic(new _Function_2_1(_g)),null(),null(),null());
			HX_STACK_LINE(1082)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1083)
			while((true)){
				HX_STACK_LINE(1083)
				if ((!(((i < this->entities->length))))){
					HX_STACK_LINE(1083)
					break;
				}
				HX_STACK_LINE(1086)
				::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
				HX_STACK_LINE(1087)
				Dynamic D = E;		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(1088)
				if (((bool((bool((E->type == HX_CSTRING("Block"))) && bool((this->RoundType != ::TypeofRound_obj::Cirno)))) && bool((this->RoundType != ::TypeofRound_obj::FireCirno))))){
					HX_STACK_LINE(1090)
					D->__Field(HX_CSTRING("Defrost"),true)();
				}
				HX_STACK_LINE(1092)
				if (((E->type == HX_CSTRING("Enemy")))){
					HX_STACK_LINE(1094)
					D->__FieldRef(HX_CSTRING("reward")) = false;
					HX_STACK_LINE(1095)
					E->killed = true;
					HX_STACK_LINE(1096)
					E->alive = false;
				}
				HX_STACK_LINE(1098)
				if (((E->type == HX_CSTRING("Gap")))){
					HX_STACK_LINE(1100)
					E->killed = true;
					HX_STACK_LINE(1101)
					E->alive = false;
				}
				HX_STACK_LINE(1103)
				if (((E->type == HX_CSTRING("Bullet")))){
					HX_STACK_LINE(1105)
					E->killed = true;
					HX_STACK_LINE(1106)
					E->alive = false;
				}
				HX_STACK_LINE(1109)
				if (((E->type == HX_CSTRING("Table")))){
					HX_STACK_LINE(1111)
					E->killed = true;
					HX_STACK_LINE(1112)
					E->alive = false;
				}
				HX_STACK_LINE(1114)
				hx::AddEq(i,(int)1);
			}
		}
		HX_STACK_LINE(1117)
		if (((evt == HX_CSTRING("Bump")))){
			HX_STACK_LINE(1119)
			::Entity E = this->EntityFromUID(data->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(1120)
			if (((E != null()))){
				HX_STACK_LINE(1122)
				E->set_x(data->__Field(HX_CSTRING("x"),true));
				HX_STACK_LINE(1123)
				E->set_y(data->__Field(HX_CSTRING("y"),true));
				HX_STACK_LINE(1124)
				E->Hspeed = data->__Field(HX_CSTRING("Hspeed"),true);
				HX_STACK_LINE(1125)
				E->Vspeed = data->__Field(HX_CSTRING("Vspeed"),true);
				HX_STACK_LINE(1126)
				E->bump();
				HX_STACK_LINE(1127)
				if ((!(me))){
					HX_STACK_LINE(1129)
					E->catchup();
				}
			}
		}
		HX_STACK_LINE(1133)
		if (((evt == HX_CSTRING("PlayerRespawn")))){
			HX_STACK_LINE(1135)
			P->set_x(data->__Field(HX_CSTRING("x"),true));
			HX_STACK_LINE(1136)
			P->set_y(data->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(1137)
			P->lives = data->__Field(HX_CSTRING("lives"),true);
			HX_STACK_LINE(1138)
			P->Hspeed = (int)0;
			HX_STACK_LINE(1139)
			P->Vspeed = (int)0;
			HX_STACK_LINE(1140)
			P->set_rotation((int)0);
			HX_STACK_LINE(1141)
			P->killed = false;
			HX_STACK_LINE(1142)
			if (((P->lives < (int)0))){
				HX_STACK_LINE(1145)
				P->set_visible(false);
				HX_STACK_LINE(1146)
				if ((me)){
					HX_STACK_LINE(1148)
					::GameView_obj::_this->SendEvent(HX_CSTRING("GameOver"),null());
				}
			}
			else{
				HX_STACK_LINE(1153)
				::SoundManager_obj::Play(HX_CSTRING("respawn"));
				HX_STACK_LINE(1154)
				P->invincibility = (int)150;
			}
			HX_STACK_LINE(1156)
			if ((!(me))){
				HX_STACK_LINE(1158)
				P->catchup();
			}
		}
		HX_STACK_LINE(1161)
		if (((evt == HX_CSTRING("GameOver")))){
			HX_STACK_LINE(1163)
			if ((me)){

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::Dynamic >,_g)
				Void run(::openfl::_v2::events::Event e){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","GameView.hx",1167,0x658aeb87)
					HX_STACK_ARG(e,"e")
					{
						HX_STACK_LINE(1167)
						_g->__get((int)0).StaticCast< ::GameView >()->SendEvent(HX_CSTRING("Continue"),null());
					}
					return null();
				}
				HX_END_LOCAL_FUNC1((void))

				HX_STACK_LINE(1167)
				::SoundManager_obj::PlayJingle(HX_CSTRING("gameover"))->addEventListener(::openfl::_v2::events::Event_obj::SOUND_COMPLETE, Dynamic(new _Function_3_1(_g)),null(),null(),null());
				HX_STACK_LINE(1168)
				this->gameover->set_visible(true);
				HX_STACK_LINE(1169)
				if (((this->myplayer->score > this->HighScore))){
					HX_STACK_LINE(1171)
					this->HighScore = this->myplayer->score;
					HX_STACK_LINE(1172)
					::Main_obj::_this->savedata->data->__FieldRef(HX_CSTRING("highscore")) = this->HighScore;
				}
			}
		}
		HX_STACK_LINE(1176)
		if (((evt == HX_CSTRING("Continue")))){
			HX_STACK_LINE(1178)
			P->lives = (int)3;
			HX_STACK_LINE(1179)
			if (((this->level > (int)0))){
				HX_STACK_LINE(1181)
				(this->level)--;
			}
			HX_STACK_LINE(1183)
			if ((me)){
			}
			HX_STACK_LINE(1187)
			P->score = (int)0;
			HX_STACK_LINE(1188)
			P->spentscore = (int)0;
			HX_STACK_LINE(1189)
			if ((me)){
				HX_STACK_LINE(1191)
				this->gameover->set_visible(false);
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1192,0x658aeb87)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(1192)
				Dynamic D = _Function_3_1::Block();		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(1193)
				D->__FieldRef(HX_CSTRING("x")) = (int)400;
				HX_STACK_LINE(1194)
				D->__FieldRef(HX_CSTRING("y")) = (int)0;
				HX_STACK_LINE(1195)
				D->__FieldRef(HX_CSTRING("lives")) = P->lives;
				HX_STACK_LINE(1197)
				::GameView_obj::_this->SendEvent(HX_CSTRING("PlayerRespawn"),D);
			}
		}
		HX_STACK_LINE(1200)
		if (((evt == HX_CSTRING("Status")))){
			HX_STACK_LINE(1202)
			this->level = data->__Field(HX_CSTRING("level"),true);
			HX_STACK_LINE(1203)
			this->totalenemies = data->__Field(HX_CSTRING("totalenemies"),true);
			HX_STACK_LINE(1204)
			::TypeofRound _g5;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(1204)
			{
				HX_STACK_LINE(1204)
				int index = data->__Field(HX_CSTRING("RoundType"),true);		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(1204)
				_g5 = ::Type_obj::createEnumIndex(hx::ClassOf< ::TypeofRound >(),index,null());
			}
			HX_STACK_LINE(1204)
			this->RoundType = _g5;
			HX_STACK_LINE(1205)
			this->gamemode = data->__Field(HX_CSTRING("gamemode"),true);
			HX_STACK_LINE(1207)
			{
				HX_STACK_LINE(1208)
				this->powblock->HP = data->__Field(HX_CSTRING("HP"),true);
				HX_STACK_LINE(1209)
				if (((this->powblock->HP == (int)0))){
					HX_STACK_LINE(1211)
					this->powblock->set_visible(false);
					HX_STACK_LINE(1212)
					this->powblock->solid = false;
				}
				else{
					HX_STACK_LINE(1216)
					this->powblock->set_visible(true);
					HX_STACK_LINE(1217)
					this->powblock->set_scaleY((this->powblock->HP * 0.25));
					HX_STACK_LINE(1218)
					this->powblock->solid = true;
				}
			}
			HX_STACK_LINE(1221)
			if (((bool((data->__Field(HX_CSTRING("activeEnemies"),true) != this->activeEnemies->length)) && bool((this->syncdelay < (int)1))))){
				HX_STACK_LINE(1224)
				this->SendEvent(HX_CSTRING("EnemySync"),null());
				HX_STACK_LINE(1225)
				this->syncdelay = (int)60;
			}
			HX_STACK_LINE(1227)
			if (((bool((data->__Field(HX_CSTRING("activeItems"),true) != this->activeItems->length)) && bool((this->syncdelay < (int)1))))){
				HX_STACK_LINE(1230)
				this->SendEvent(HX_CSTRING("ItemSync"),null());
				HX_STACK_LINE(1231)
				this->syncdelay = (int)60;
			}
		}
		HX_STACK_LINE(1234)
		if (((bool((bool((evt == HX_CSTRING("EnemySync"))) && bool(this->Hoster))) && bool((this->syncdelay < (int)1))))){
			HX_STACK_LINE(1236)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1237,0x658aeb87)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(1237)
			Dynamic dat = _Function_2_1::Block();		HX_STACK_VAR(dat,"dat");
			HX_STACK_LINE(1238)
			Dynamic DD = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(DD,"DD");
			HX_STACK_LINE(1239)
			dat->__FieldRef(HX_CSTRING("enemies")) = DD;
			HX_STACK_LINE(1240)
			while((true)){
				HX_STACK_LINE(1240)
				if ((!(((i < this->activeEnemies->length))))){
					HX_STACK_LINE(1240)
					break;
				}
				HX_STACK_LINE(1242)
				::Enemy E = this->activeEnemies->__get(i).StaticCast< ::Enemy >();		HX_STACK_VAR(E,"E");
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1243,0x658aeb87)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(1243)
				Dynamic D = _Function_3_1::Block();		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(1244)
				D->__FieldRef(HX_CSTRING("UID")) = E->UID;
				HX_STACK_LINE(1245)
				Float _g6 = E->get_y();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(1245)
				D->__FieldRef(HX_CSTRING("y")) = _g6;
				HX_STACK_LINE(1246)
				Float _g7 = E->get_x();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(1246)
				D->__FieldRef(HX_CSTRING("x")) = _g7;
				HX_STACK_LINE(1247)
				D->__FieldRef(HX_CSTRING("Ldir")) = E->Ldir;
				HX_STACK_LINE(1248)
				D->__FieldRef(HX_CSTRING("alive")) = E->alive;
				HX_STACK_LINE(1249)
				D->__FieldRef(HX_CSTRING("Hspeed")) = E->Hspeed;
				HX_STACK_LINE(1250)
				D->__FieldRef(HX_CSTRING("Vspeed")) = E->Vspeed;
				HX_STACK_LINE(1251)
				bool _g8 = E->get_visible();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(1251)
				D->__FieldRef(HX_CSTRING("visible")) = _g8;
				HX_STACK_LINE(1252)
				D->__FieldRef(HX_CSTRING("type")) = E->charname;
				HX_STACK_LINE(1253)
				hx::IndexRef((DD).mPtr,DD->__Field(HX_CSTRING("length"),true)) = D;
				HX_STACK_LINE(1254)
				hx::AddEq(i,(int)1);
			}
			HX_STACK_LINE(1256)
			this->SendEvent(HX_CSTRING("EnemyList"),dat);
		}
		HX_STACK_LINE(1258)
		if (((bool(((bool((evt == HX_CSTRING("EnemyList"))) || bool((evt == HX_CSTRING("ItemList")))))) && bool(!(this->Hoster))))){
			HX_STACK_LINE(1260)
			Dynamic DD = null();		HX_STACK_VAR(DD,"DD");
			HX_STACK_LINE(1261)
			if (((evt == HX_CSTRING("EnemyList")))){
				HX_STACK_LINE(1263)
				DD = data->__Field(HX_CSTRING("enemies"),true);
			}
			HX_STACK_LINE(1265)
			if (((evt == HX_CSTRING("ItemList")))){
				HX_STACK_LINE(1267)
				DD = data->__Field(HX_CSTRING("items"),true);
			}
			HX_STACK_LINE(1269)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1270)
			while((true)){
				HX_STACK_LINE(1270)
				if ((!(((i < DD->__Field(HX_CSTRING("length"),true)))))){
					HX_STACK_LINE(1270)
					break;
				}
				HX_STACK_LINE(1272)
				Dynamic D = DD->__GetItem(i);		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(1273)
				::Entity _g9 = this->EntityFromUID(D->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(1273)
				if (((_g9 == null()))){
					HX_STACK_LINE(1275)
					this->AddEntityFromData(D);
				}
				HX_STACK_LINE(1278)
				hx::AddEq(i,(int)1);
			}
			HX_STACK_LINE(1280)
			this->syncdelay = (int)60;
		}
		HX_STACK_LINE(1282)
		if (((bool((bool((evt == HX_CSTRING("ItemSync"))) && bool(this->Hoster))) && bool((this->syncdelay < (int)1))))){
			HX_STACK_LINE(1284)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			struct _Function_2_1{
				inline static Dynamic Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1285,0x658aeb87)
					{
						hx::Anon __result = hx::Anon_obj::Create();
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(1285)
			Dynamic dat = _Function_2_1::Block();		HX_STACK_VAR(dat,"dat");
			HX_STACK_LINE(1286)
			Dynamic DD = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(DD,"DD");
			HX_STACK_LINE(1287)
			dat->__FieldRef(HX_CSTRING("items")) = DD;
			HX_STACK_LINE(1288)
			while((true)){
				HX_STACK_LINE(1288)
				if ((!(((i < this->activeItems->length))))){
					HX_STACK_LINE(1288)
					break;
				}
				HX_STACK_LINE(1290)
				::EntityItem E = this->activeItems->__get(i).StaticCast< ::EntityItem >();		HX_STACK_VAR(E,"E");
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1291,0x658aeb87)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(1291)
				Dynamic D = _Function_3_1::Block();		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(1292)
				D->__FieldRef(HX_CSTRING("UID")) = E->UID;
				HX_STACK_LINE(1293)
				Float _g10 = E->get_y();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(1293)
				D->__FieldRef(HX_CSTRING("y")) = _g10;
				HX_STACK_LINE(1294)
				Float _g11 = E->get_x();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(1294)
				D->__FieldRef(HX_CSTRING("x")) = _g11;
				HX_STACK_LINE(1295)
				D->__FieldRef(HX_CSTRING("Ldir")) = E->Ldir;
				HX_STACK_LINE(1296)
				D->__FieldRef(HX_CSTRING("alive")) = E->alive;
				HX_STACK_LINE(1297)
				D->__FieldRef(HX_CSTRING("Hspeed")) = E->Hspeed;
				HX_STACK_LINE(1298)
				D->__FieldRef(HX_CSTRING("Vspeed")) = E->Vspeed;
				HX_STACK_LINE(1299)
				bool _g12 = E->get_visible();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(1299)
				D->__FieldRef(HX_CSTRING("visible")) = _g12;
				HX_STACK_LINE(1300)
				D->__FieldRef(HX_CSTRING("type")) = E->charname;
				HX_STACK_LINE(1301)
				hx::IndexRef((DD).mPtr,DD->__Field(HX_CSTRING("length"),true)) = D;
				HX_STACK_LINE(1302)
				hx::AddEq(i,(int)1);
			}
			HX_STACK_LINE(1304)
			this->SendEvent(HX_CSTRING("ItemList"),dat);
			HX_STACK_LINE(1305)
			this->syncdelay = (int)60;
		}
		HX_STACK_LINE(1307)
		if (((evt == HX_CSTRING("Collect")))){
			HX_STACK_LINE(1309)
			if (((P != null()))){
				HX_STACK_LINE(1311)
				Dynamic D = this->EntityFromUID(data);		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(1312)
				if ((D->__Field(HX_CSTRING("alive"),true))){
					HX_STACK_LINE(1314)
					D->__Field(HX_CSTRING("Collect"),true)(P);
				}
			}
		}
		HX_STACK_LINE(1318)
		if (((evt == HX_CSTRING("POW!")))){
			HX_STACK_LINE(1321)
			this->powblock->HP = data->__Field(HX_CSTRING("HP"),true);
			HX_STACK_LINE(1322)
			::SoundManager_obj::Play(HX_CSTRING("pow"));
			HX_STACK_LINE(1323)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1324)
			while((true)){
				HX_STACK_LINE(1324)
				if ((!(((i < this->entities->length))))){
					HX_STACK_LINE(1324)
					break;
				}
				HX_STACK_LINE(1326)
				::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
				HX_STACK_LINE(1327)
				if (((E->type == HX_CSTRING("Block")))){
					HX_STACK_LINE(1329)
					E->bonked = (int)10;
					HX_STACK_LINE(1330)
					::Player _g13 = this->GetPlayer(ID);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(1330)
					E->bonkedby = _g13;
				}
				HX_STACK_LINE(1333)
				(i)++;
			}
			HX_STACK_LINE(1335)
			if (((this->powblock->HP == (int)0))){
				HX_STACK_LINE(1337)
				this->powblock->set_visible(false);
				HX_STACK_LINE(1338)
				this->powblock->solid = false;
			}
			else{
				HX_STACK_LINE(1342)
				this->powblock->set_scaleY((this->powblock->HP * 0.25));
				HX_STACK_LINE(1343)
				this->powblock->solid = true;
				HX_STACK_LINE(1344)
				this->powblock->set_visible(true);
			}
		}
		HX_STACK_LINE(1347)
		if (((evt == HX_CSTRING("Enrage")))){
			HX_STACK_LINE(1349)
			Dynamic D = this->EntityFromUID(data);		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(1350)
			if (((bool((D != null())) && bool((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Enemy")))))){
				HX_STACK_LINE(1352)
				D->__Field(HX_CSTRING("enrage"),true)();
				HX_STACK_LINE(1353)
				D->__FieldRef(HX_CSTRING("enraged")) = true;
				HX_STACK_LINE(1354)
				if ((!(this->Hoster))){
					HX_STACK_LINE(1356)
					D->__Field(HX_CSTRING("catchup"),true)();
				}
			}
		}
		HX_STACK_LINE(1360)
		if (((evt == HX_CSTRING("SendGap")))){
			HX_STACK_LINE(1362)
			::EntityGap E = ::EntityGap_obj::__new();		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(1363)
			E->set_x(data->__Field(HX_CSTRING("x"),true));
			HX_STACK_LINE(1364)
			E->set_y(data->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(1365)
			E->UID = data->__Field(HX_CSTRING("UID"),true);
			HX_STACK_LINE(1366)
			this->AddObject(E);
		}
		HX_STACK_LINE(1368)
		if (((evt == HX_CSTRING("Cirnobomb")))){
			HX_STACK_LINE(1370)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1371)
			Dynamic C = this->EntityFromUID(data->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(C,"C");
			HX_STACK_LINE(1372)
			while((true)){
				HX_STACK_LINE(1372)
				if ((!(((i < this->entities->length))))){
					HX_STACK_LINE(1372)
					break;
				}
				HX_STACK_LINE(1375)
				::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
				struct _Function_3_1{
					inline static bool Block( Dynamic &data,::Entity &E){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1376,0x658aeb87)
						{
							HX_STACK_LINE(1376)
							Float _g14 = E->get_y();		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(1376)
							return (_g14 == data->__Field(HX_CSTRING("y"),true));
						}
						return null();
					}
				};
				HX_STACK_LINE(1376)
				if (((  (((E->type == HX_CSTRING("Block")))) ? bool(_Function_3_1::Block(data,E)) : bool(false) ))){
					HX_STACK_LINE(1379)
					Dynamic D = E;		HX_STACK_VAR(D,"D");
					HX_STACK_LINE(1380)
					if ((C->__Field(HX_CSTRING("flaming"),true))){
						HX_STACK_LINE(1382)
						D->__Field(HX_CSTRING("Burn"),true)();
					}
					else{
						HX_STACK_LINE(1386)
						D->__Field(HX_CSTRING("Freeze"),true)();
					}
				}
				HX_STACK_LINE(1389)
				if (((E->UID == data->__Field(HX_CSTRING("UID"),true)))){
					HX_STACK_LINE(1391)
					E->killed = true;
					HX_STACK_LINE(1392)
					E->alive = false;
				}
				HX_STACK_LINE(1394)
				hx::AddEq(i,(int)1);
			}
		}
		HX_STACK_LINE(1397)
		if (((evt == HX_CSTRING("UFOStrike")))){
			HX_STACK_LINE(1399)
			Dynamic E = this->EntityFromUID(data->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(1400)
			::UFO D = E;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(1402)
			if (((D->ufotype == HX_CSTRING("Red")))){
				HX_STACK_LINE(1405)
				::Bullet O = ::Bullet_obj::__new();		HX_STACK_VAR(O,"O");
				HX_STACK_LINE(1406)
				Float _g15 = D->get_x();		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(1406)
				O->set_x(_g15);
				HX_STACK_LINE(1407)
				Float _g16 = D->get_y();		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(1407)
				O->set_y(_g16);
				HX_STACK_LINE(1408)
				O->Hspeed = (int)-2;
				HX_STACK_LINE(1409)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1410)
				this->AddObject(O);
				HX_STACK_LINE(1411)
				::Bullet _g17 = ::Bullet_obj::__new();		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(1411)
				O = _g17;
				HX_STACK_LINE(1412)
				Float _g18 = D->get_x();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(1412)
				O->set_x(_g18);
				HX_STACK_LINE(1413)
				Float _g19 = D->get_y();		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(1413)
				O->set_y(_g19);
				HX_STACK_LINE(1414)
				O->Hspeed = (int)-3;
				HX_STACK_LINE(1415)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1416)
				this->AddObject(O);
				HX_STACK_LINE(1417)
				::Bullet _g20 = ::Bullet_obj::__new();		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(1417)
				O = _g20;
				HX_STACK_LINE(1418)
				Float _g21 = D->get_x();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(1418)
				O->set_x(_g21);
				HX_STACK_LINE(1419)
				Float _g22 = D->get_y();		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(1419)
				O->set_y(_g22);
				HX_STACK_LINE(1420)
				O->Hspeed = (int)2;
				HX_STACK_LINE(1421)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1422)
				this->AddObject(O);
				HX_STACK_LINE(1423)
				::Bullet _g23 = ::Bullet_obj::__new();		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(1423)
				O = _g23;
				HX_STACK_LINE(1424)
				Float _g24 = D->get_x();		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(1424)
				O->set_x(_g24);
				HX_STACK_LINE(1425)
				Float _g25 = D->get_y();		HX_STACK_VAR(_g25,"_g25");
				HX_STACK_LINE(1425)
				O->set_y(_g25);
				HX_STACK_LINE(1426)
				O->Hspeed = (int)3;
				HX_STACK_LINE(1427)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1428)
				this->AddObject(O);
			}
			HX_STACK_LINE(1430)
			if (((D->ufotype == HX_CSTRING("Green")))){
				HX_STACK_LINE(1433)
				::Bullet O = ::Bullet_obj::__new();		HX_STACK_VAR(O,"O");
				HX_STACK_LINE(1434)
				Float _g26 = D->get_x();		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(1434)
				Float _g27 = (_g26 - (int)10);		HX_STACK_VAR(_g27,"_g27");
				HX_STACK_LINE(1434)
				O->set_x(_g27);
				HX_STACK_LINE(1435)
				Float _g28 = D->get_y();		HX_STACK_VAR(_g28,"_g28");
				HX_STACK_LINE(1435)
				O->set_y(_g28);
				HX_STACK_LINE(1436)
				O->Hspeed = (int)0;
				HX_STACK_LINE(1437)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1438)
				this->AddObject(O);
				HX_STACK_LINE(1439)
				::Bullet _g29 = ::Bullet_obj::__new();		HX_STACK_VAR(_g29,"_g29");
				HX_STACK_LINE(1439)
				O = _g29;
				HX_STACK_LINE(1440)
				Float _g30 = D->get_x();		HX_STACK_VAR(_g30,"_g30");
				HX_STACK_LINE(1440)
				Float _g31 = (_g30 + (int)10);		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(1440)
				O->set_x(_g31);
				HX_STACK_LINE(1441)
				Float _g32 = D->get_y();		HX_STACK_VAR(_g32,"_g32");
				HX_STACK_LINE(1441)
				O->set_y(_g32);
				HX_STACK_LINE(1442)
				O->Hspeed = (int)0;
				HX_STACK_LINE(1443)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1444)
				this->AddObject(O);
			}
			HX_STACK_LINE(1446)
			if (((D->ufotype == HX_CSTRING("Blue")))){
				HX_STACK_LINE(1449)
				::Bullet O = ::Bullet_obj::__new();		HX_STACK_VAR(O,"O");
				HX_STACK_LINE(1450)
				Float _g33 = D->get_x();		HX_STACK_VAR(_g33,"_g33");
				HX_STACK_LINE(1450)
				O->set_x(_g33);
				HX_STACK_LINE(1451)
				Float _g34 = D->get_y();		HX_STACK_VAR(_g34,"_g34");
				HX_STACK_LINE(1451)
				O->set_y(_g34);
				HX_STACK_LINE(1452)
				O->Hspeed = (int)0;
				HX_STACK_LINE(1453)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1454)
				this->AddObject(O);
				HX_STACK_LINE(1455)
				::Bullet _g35 = ::Bullet_obj::__new();		HX_STACK_VAR(_g35,"_g35");
				HX_STACK_LINE(1455)
				O = _g35;
				HX_STACK_LINE(1456)
				Float _g36 = D->get_x();		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(1456)
				O->set_x(_g36);
				HX_STACK_LINE(1457)
				Float _g37 = D->get_y();		HX_STACK_VAR(_g37,"_g37");
				HX_STACK_LINE(1457)
				O->set_y(_g37);
				HX_STACK_LINE(1458)
				O->Hspeed = (int)2;
				HX_STACK_LINE(1459)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1460)
				this->AddObject(O);
				HX_STACK_LINE(1461)
				::Bullet _g38 = ::Bullet_obj::__new();		HX_STACK_VAR(_g38,"_g38");
				HX_STACK_LINE(1461)
				O = _g38;
				HX_STACK_LINE(1462)
				Float _g39 = D->get_x();		HX_STACK_VAR(_g39,"_g39");
				HX_STACK_LINE(1462)
				O->set_x(_g39);
				HX_STACK_LINE(1463)
				Float _g40 = D->get_y();		HX_STACK_VAR(_g40,"_g40");
				HX_STACK_LINE(1463)
				O->set_y(_g40);
				HX_STACK_LINE(1464)
				O->Hspeed = (int)-2;
				HX_STACK_LINE(1465)
				O->Vspeed = (int)4;
				HX_STACK_LINE(1466)
				this->AddObject(O);
			}
		}
		HX_STACK_LINE(1469)
		if (((evt == HX_CSTRING("ChenDanmaku")))){
			HX_STACK_LINE(1471)
			Dynamic E = this->EntityFromUID(data->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(1472)
			::Chen D = E;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(1474)
			::Bullet O = ::Bullet_obj::__new();		HX_STACK_VAR(O,"O");
			HX_STACK_LINE(1475)
			Float _g41 = D->get_x();		HX_STACK_VAR(_g41,"_g41");
			HX_STACK_LINE(1475)
			O->set_x(_g41);
			HX_STACK_LINE(1476)
			Float _g42 = D->get_y();		HX_STACK_VAR(_g42,"_g42");
			HX_STACK_LINE(1476)
			O->set_y(_g42);
			HX_STACK_LINE(1477)
			O->Hspeed = (int)-2;
			HX_STACK_LINE(1478)
			O->Vspeed = (int)2;
			HX_STACK_LINE(1479)
			this->AddObject(O);
			HX_STACK_LINE(1480)
			::Bullet _g43 = ::Bullet_obj::__new();		HX_STACK_VAR(_g43,"_g43");
			HX_STACK_LINE(1480)
			O = _g43;
			HX_STACK_LINE(1481)
			Float _g44 = D->get_x();		HX_STACK_VAR(_g44,"_g44");
			HX_STACK_LINE(1481)
			O->set_x(_g44);
			HX_STACK_LINE(1482)
			Float _g45 = D->get_y();		HX_STACK_VAR(_g45,"_g45");
			HX_STACK_LINE(1482)
			O->set_y(_g45);
			HX_STACK_LINE(1483)
			O->Hspeed = (int)0;
			HX_STACK_LINE(1484)
			O->Vspeed = (int)4;
			HX_STACK_LINE(1485)
			this->AddObject(O);
			HX_STACK_LINE(1486)
			::Bullet _g46 = ::Bullet_obj::__new();		HX_STACK_VAR(_g46,"_g46");
			HX_STACK_LINE(1486)
			O = _g46;
			HX_STACK_LINE(1487)
			Float _g47 = D->get_x();		HX_STACK_VAR(_g47,"_g47");
			HX_STACK_LINE(1487)
			O->set_x(_g47);
			HX_STACK_LINE(1488)
			Float _g48 = D->get_y();		HX_STACK_VAR(_g48,"_g48");
			HX_STACK_LINE(1488)
			O->set_y(_g48);
			HX_STACK_LINE(1489)
			O->Hspeed = (int)2;
			HX_STACK_LINE(1490)
			O->Vspeed = (int)2;
			HX_STACK_LINE(1491)
			this->AddObject(O);
			HX_STACK_LINE(1492)
			::Bullet _g49 = ::Bullet_obj::__new();		HX_STACK_VAR(_g49,"_g49");
			HX_STACK_LINE(1492)
			O = _g49;
			HX_STACK_LINE(1493)
			Float _g50 = D->get_x();		HX_STACK_VAR(_g50,"_g50");
			HX_STACK_LINE(1493)
			O->set_x(_g50);
			HX_STACK_LINE(1494)
			Float _g51 = D->get_y();		HX_STACK_VAR(_g51,"_g51");
			HX_STACK_LINE(1494)
			O->set_y(_g51);
			HX_STACK_LINE(1495)
			O->Hspeed = (int)4;
			HX_STACK_LINE(1496)
			O->Vspeed = (int)0;
			HX_STACK_LINE(1497)
			this->AddObject(O);
			HX_STACK_LINE(1498)
			::Bullet _g52 = ::Bullet_obj::__new();		HX_STACK_VAR(_g52,"_g52");
			HX_STACK_LINE(1498)
			O = _g52;
			HX_STACK_LINE(1499)
			Float _g53 = D->get_x();		HX_STACK_VAR(_g53,"_g53");
			HX_STACK_LINE(1499)
			O->set_x(_g53);
			HX_STACK_LINE(1500)
			Float _g54 = D->get_y();		HX_STACK_VAR(_g54,"_g54");
			HX_STACK_LINE(1500)
			O->set_y(_g54);
			HX_STACK_LINE(1501)
			O->Hspeed = (int)-4;
			HX_STACK_LINE(1502)
			O->Vspeed = (int)0;
			HX_STACK_LINE(1503)
			this->AddObject(O);
			HX_STACK_LINE(1506)
			::Bullet _g55 = ::Bullet_obj::__new();		HX_STACK_VAR(_g55,"_g55");
			HX_STACK_LINE(1506)
			O = _g55;
			HX_STACK_LINE(1507)
			Float _g56 = D->get_x();		HX_STACK_VAR(_g56,"_g56");
			HX_STACK_LINE(1507)
			O->set_x(_g56);
			HX_STACK_LINE(1508)
			Float _g57 = D->get_y();		HX_STACK_VAR(_g57,"_g57");
			HX_STACK_LINE(1508)
			O->set_y(_g57);
			HX_STACK_LINE(1509)
			O->Hspeed = (int)-2;
			HX_STACK_LINE(1510)
			O->Vspeed = (int)-2;
			HX_STACK_LINE(1511)
			this->AddObject(O);
			HX_STACK_LINE(1512)
			::Bullet _g58 = ::Bullet_obj::__new();		HX_STACK_VAR(_g58,"_g58");
			HX_STACK_LINE(1512)
			O = _g58;
			HX_STACK_LINE(1513)
			Float _g59 = D->get_x();		HX_STACK_VAR(_g59,"_g59");
			HX_STACK_LINE(1513)
			O->set_x(_g59);
			HX_STACK_LINE(1514)
			Float _g60 = D->get_y();		HX_STACK_VAR(_g60,"_g60");
			HX_STACK_LINE(1514)
			O->set_y(_g60);
			HX_STACK_LINE(1515)
			O->Hspeed = (int)0;
			HX_STACK_LINE(1516)
			O->Vspeed = (int)-4;
			HX_STACK_LINE(1517)
			this->AddObject(O);
			HX_STACK_LINE(1518)
			::Bullet _g61 = ::Bullet_obj::__new();		HX_STACK_VAR(_g61,"_g61");
			HX_STACK_LINE(1518)
			O = _g61;
			HX_STACK_LINE(1519)
			Float _g62 = D->get_x();		HX_STACK_VAR(_g62,"_g62");
			HX_STACK_LINE(1519)
			O->set_x(_g62);
			HX_STACK_LINE(1520)
			Float _g63 = D->get_y();		HX_STACK_VAR(_g63,"_g63");
			HX_STACK_LINE(1520)
			O->set_y(_g63);
			HX_STACK_LINE(1521)
			O->Hspeed = (int)2;
			HX_STACK_LINE(1522)
			O->Vspeed = (int)-2;
			HX_STACK_LINE(1523)
			this->AddObject(O);
			HX_STACK_LINE(1524)
			::Bullet _g64 = ::Bullet_obj::__new();		HX_STACK_VAR(_g64,"_g64");
			HX_STACK_LINE(1524)
			O = _g64;
		}
		HX_STACK_LINE(1530)
		if (((evt == HX_CSTRING("FLIP!")))){
			HX_STACK_LINE(1532)
			Float _g65 = ::Math_obj::random();		HX_STACK_VAR(_g65,"_g65");
			HX_STACK_LINE(1532)
			if (((_g65 > 0.5))){
				HX_STACK_LINE(1534)
				Float _g66 = this->get_scaleY();		HX_STACK_VAR(_g66,"_g66");
				HX_STACK_LINE(1534)
				if (((_g66 == (int)1))){
					HX_STACK_LINE(1536)
					this->set_scaleY((int)-1);
					HX_STACK_LINE(1537)
					this->set_y((int)600);
				}
				else{
					HX_STACK_LINE(1541)
					this->set_scaleY((int)1);
					HX_STACK_LINE(1542)
					this->set_y((int)0);
				}
			}
			else{
				HX_STACK_LINE(1547)
				Float _g67 = this->get_scaleX();		HX_STACK_VAR(_g67,"_g67");
				HX_STACK_LINE(1547)
				if (((_g67 == (int)1))){
					HX_STACK_LINE(1549)
					this->set_scaleX((int)-1);
					HX_STACK_LINE(1550)
					this->set_x((int)800);
				}
				else{
					HX_STACK_LINE(1554)
					this->set_scaleX((int)1);
					HX_STACK_LINE(1555)
					this->set_x((int)0);
				}
			}
		}
		HX_STACK_LINE(1560)
		if (((evt == HX_CSTRING("Hammerthrow")))){
			HX_STACK_LINE(1562)
			Dynamic E = this->EntityFromUID(data->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(1563)
			::Tewi D = E;		HX_STACK_VAR(D,"D");
			HX_STACK_LINE(1564)
			::Bullet O = ::Bullet_obj::__new();		HX_STACK_VAR(O,"O");
			HX_STACK_LINE(1565)
			Float _g68 = D->get_x();		HX_STACK_VAR(_g68,"_g68");
			HX_STACK_LINE(1565)
			O->set_x(_g68);
			HX_STACK_LINE(1566)
			Float _g69 = D->get_y();		HX_STACK_VAR(_g69,"_g69");
			HX_STACK_LINE(1566)
			O->set_y(_g69);
			HX_STACK_LINE(1567)
			if (((D->Ldir > (int)0))){
				HX_STACK_LINE(1569)
				O->Hspeed = (int)2;
			}
			else{
				HX_STACK_LINE(1573)
				O->Hspeed = (int)-2;
			}
			HX_STACK_LINE(1575)
			O->image_speed = 0.35;
			HX_STACK_LINE(1576)
			O->Vspeed = (int)-10;
			HX_STACK_LINE(1577)
			Float _g70 = ::Math_obj::random();		HX_STACK_VAR(_g70,"_g70");
			HX_STACK_LINE(1577)
			if (((_g70 > 0.9))){
				HX_STACK_LINE(1579)
				Array< ::Dynamic > _g71 = this->AL->GetAnimation(HX_CSTRING("table"));		HX_STACK_VAR(_g71,"_g71");
				HX_STACK_LINE(1579)
				O->ChangeAnimation(_g71);
			}
			else{
				HX_STACK_LINE(1583)
				Array< ::Dynamic > _g72 = this->AL->GetAnimation(HX_CSTRING("hammer"));		HX_STACK_VAR(_g72,"_g72");
				HX_STACK_LINE(1583)
				O->ChangeAnimation(_g72);
			}
			HX_STACK_LINE(1585)
			O->gravY = 0.3;
			HX_STACK_LINE(1586)
			this->AddObject(O);
		}
		HX_STACK_LINE(1588)
		if (((evt == HX_CSTRING("Tableflip")))){
			HX_STACK_LINE(1590)
			Dynamic E = this->EntityFromUID(data->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(1592)
			if (((data->__Field(HX_CSTRING("TUID"),true) != null()))){
				HX_STACK_LINE(1594)
				E->__FieldRef(HX_CSTRING("tossedBy")) = P;
			}
			HX_STACK_LINE(1596)
			E->__FieldRef(HX_CSTRING("image_speed")) = data->__Field(HX_CSTRING("image_speed"),true);
			HX_STACK_LINE(1597)
			E->__FieldRef(HX_CSTRING("Vspeed")) = (int)-7;
			HX_STACK_LINE(1598)
			E->__FieldRef(HX_CSTRING("gravY")) = 0.8;
			HX_STACK_LINE(1599)
			E->__FieldRef(HX_CSTRING("dangerous")) = data->__Field(HX_CSTRING("dangerous"),true);
			HX_STACK_LINE(1600)
			E->__FieldRef(HX_CSTRING("Hspeed")) = data->__Field(HX_CSTRING("Hspeed"),true);
		}
		HX_STACK_LINE(1602)
		if (((evt == HX_CSTRING("Spawntables")))){
			HX_STACK_LINE(1604)
			::Table Tbl = ::Table_obj::__new();		HX_STACK_VAR(Tbl,"Tbl");
			HX_STACK_LINE(1605)
			Tbl->set_x((int)140);
			HX_STACK_LINE(1606)
			Tbl->set_y((int)375);
			HX_STACK_LINE(1607)
			Tbl->UID = 1.1;
			HX_STACK_LINE(1608)
			this->AddObject(Tbl);
			HX_STACK_LINE(1610)
			::Table _g73 = ::Table_obj::__new();		HX_STACK_VAR(_g73,"_g73");
			HX_STACK_LINE(1610)
			Tbl = _g73;
			HX_STACK_LINE(1611)
			Tbl->set_x((int)640);
			HX_STACK_LINE(1612)
			Tbl->set_y((int)375);
			HX_STACK_LINE(1613)
			Tbl->UID = 1.2;
			HX_STACK_LINE(1614)
			this->AddObject(Tbl);
			HX_STACK_LINE(1616)
			::Table _g74 = ::Table_obj::__new();		HX_STACK_VAR(_g74,"_g74");
			HX_STACK_LINE(1616)
			Tbl = _g74;
			HX_STACK_LINE(1617)
			Tbl->set_x((int)140);
			HX_STACK_LINE(1618)
			Tbl->set_y((int)535);
			HX_STACK_LINE(1619)
			Tbl->UID = 1.3;
			HX_STACK_LINE(1620)
			this->AddObject(Tbl);
			HX_STACK_LINE(1622)
			::Table _g75 = ::Table_obj::__new();		HX_STACK_VAR(_g75,"_g75");
			HX_STACK_LINE(1622)
			Tbl = _g75;
			HX_STACK_LINE(1623)
			Tbl->set_x((int)640);
			HX_STACK_LINE(1624)
			Tbl->set_y((int)535);
			HX_STACK_LINE(1625)
			Tbl->UID = 1.4;
			HX_STACK_LINE(1626)
			this->AddObject(Tbl);
			HX_STACK_LINE(1629)
			::Table _g76 = ::Table_obj::__new();		HX_STACK_VAR(_g76,"_g76");
			HX_STACK_LINE(1629)
			Tbl = _g76;
			HX_STACK_LINE(1630)
			Tbl->set_x((int)140);
			HX_STACK_LINE(1631)
			Tbl->set_y((int)55);
			HX_STACK_LINE(1632)
			Tbl->UID = 1.5;
			HX_STACK_LINE(1633)
			this->AddObject(Tbl);
			HX_STACK_LINE(1635)
			::Table _g77 = ::Table_obj::__new();		HX_STACK_VAR(_g77,"_g77");
			HX_STACK_LINE(1635)
			Tbl = _g77;
			HX_STACK_LINE(1636)
			Tbl->set_x((int)640);
			HX_STACK_LINE(1637)
			Tbl->set_y((int)55);
			HX_STACK_LINE(1638)
			Tbl->UID = 1.6;
			HX_STACK_LINE(1639)
			this->AddObject(Tbl);
			HX_STACK_LINE(1640)
			this->RoundType = ::TypeofRound_obj::Table;
		}
		HX_STACK_LINE(1642)
		if (((evt == HX_CSTRING("ShootBullet")))){
			HX_STACK_LINE(1644)
			::Bullet O = ::Bullet_obj::__new();		HX_STACK_VAR(O,"O");
			HX_STACK_LINE(1645)
			O->set_x(data->__Field(HX_CSTRING("x"),true));
			HX_STACK_LINE(1646)
			O->set_y(data->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(1647)
			O->Hspeed = data->__Field(HX_CSTRING("Hspeed"),true);
			HX_STACK_LINE(1648)
			O->Vspeed = data->__Field(HX_CSTRING("Vspeed"),true);
			HX_STACK_LINE(1649)
			O->gravX = data->__Field(HX_CSTRING("gravX"),true);
			HX_STACK_LINE(1650)
			O->gravY = data->__Field(HX_CSTRING("gravY"),true);
			HX_STACK_LINE(1652)
			if (((data->__Field(HX_CSTRING("image_speed"),true) != null()))){
				HX_STACK_LINE(1654)
				O->image_speed = data->__Field(HX_CSTRING("image_speed"),true);
			}
			HX_STACK_LINE(1656)
			if (((data->__Field(HX_CSTRING("image"),true) != null()))){
				HX_STACK_LINE(1658)
				Array< ::Dynamic > _g78 = this->AL->GetAnimation(data->__Field(HX_CSTRING("image"),true));		HX_STACK_VAR(_g78,"_g78");
				HX_STACK_LINE(1658)
				O->ChangeAnimation(_g78);
			}
			HX_STACK_LINE(1660)
			this->AddObject(O);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GameView_obj,ProcessEvent,(void))

Void GameView_obj::stage_onKeyDown( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("GameView","stage_onKeyDown",0x1689536a,"GameView.stage_onKeyDown","GameView.hx",1699,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(1701)
		if (((event->keyCode == (int)32))){
		}
		HX_STACK_LINE(1704)
		{
			HX_STACK_LINE(1704)
			int _g = event->keyCode;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1704)
			switch( (int)(_g)){
				case (int)81: {
					HX_STACK_LINE(1712)
					this->status = HX_CSTRING("quitting");
				}
				;break;
				case (int)32: {
					HX_STACK_LINE(1714)
					if (((bool(this->Hoster) && bool(::Main_obj::_this->DEBUG)))){
						HX_STACK_LINE(1716)
						this->TF->set_text(HX_CSTRING("Gaps!!!"));
						HX_STACK_LINE(1718)
						if (((this->SpawnList->length == (int)0))){
							HX_STACK_LINE(1720)
							(this->level)++;
						}
						HX_STACK_LINE(1722)
						if (((this->activeEnemies->length > (int)0))){
							HX_STACK_LINE(1724)
							this->SpawnList->clear();
						}
						else{
							HX_STACK_LINE(1726)
							if (((this->SpawnList->length > (int)1))){
								HX_STACK_LINE(1728)
								::Enemy E = this->SpawnList->pop();		HX_STACK_VAR(E,"E");
								HX_STACK_LINE(1729)
								this->SpawnList->clear();
								HX_STACK_LINE(1730)
								this->SpawnList->add(E);
							}
						}
					}
				}
				;break;
			}
		}
		struct _Function_1_1{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1735,0x658aeb87)
				{
					HX_STACK_LINE(1735)
					int _int = ::Main_obj::_this->controlscheme->__get((int)1);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1735)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1735)
		if (((_Function_1_1::Block() == event->keyCode))){
			HX_STACK_LINE(1737)
			this->control[(int)0] = true;
		}
		struct _Function_1_2{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1739,0x658aeb87)
				{
					HX_STACK_LINE(1739)
					int _int = ::Main_obj::_this->controlscheme->__get((int)2);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1739)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1739)
		if (((_Function_1_2::Block() == event->keyCode))){
			HX_STACK_LINE(1741)
			this->control[(int)2] = true;
		}
		struct _Function_1_3{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1743,0x658aeb87)
				{
					HX_STACK_LINE(1743)
					int _int = ::Main_obj::_this->controlscheme->__get((int)3);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1743)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1743)
		if (((_Function_1_3::Block() == event->keyCode))){
			HX_STACK_LINE(1745)
			this->control[(int)3] = true;
		}
		struct _Function_1_4{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1747,0x658aeb87)
				{
					HX_STACK_LINE(1747)
					int _int = ::Main_obj::_this->controlscheme->__get((int)0);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1747)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1747)
		if (((_Function_1_4::Block() == event->keyCode))){
			HX_STACK_LINE(1749)
			this->control[(int)1] = true;
		}
		HX_STACK_LINE(1751)
		this->ControlEvent = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,stage_onKeyDown,(void))

Void GameView_obj::stage_onKeyUp( ::openfl::_v2::events::KeyboardEvent event){
{
		HX_STACK_FRAME("GameView","stage_onKeyUp",0x4b016f63,"GameView.stage_onKeyUp","GameView.hx",1755,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		struct _Function_1_1{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1767,0x658aeb87)
				{
					HX_STACK_LINE(1767)
					int _int = ::Main_obj::_this->controlscheme->__get((int)1);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1767)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1767)
		if (((_Function_1_1::Block() == event->keyCode))){
			HX_STACK_LINE(1769)
			this->control[(int)0] = false;
		}
		struct _Function_1_2{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1771,0x658aeb87)
				{
					HX_STACK_LINE(1771)
					int _int = ::Main_obj::_this->controlscheme->__get((int)2);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1771)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1771)
		if (((_Function_1_2::Block() == event->keyCode))){
			HX_STACK_LINE(1773)
			this->control[(int)2] = false;
		}
		struct _Function_1_3{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1775,0x658aeb87)
				{
					HX_STACK_LINE(1775)
					int _int = ::Main_obj::_this->controlscheme->__get((int)3);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1775)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1775)
		if (((_Function_1_3::Block() == event->keyCode))){
			HX_STACK_LINE(1777)
			this->control[(int)3] = false;
		}
		struct _Function_1_4{
			inline static Float Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",1779,0x658aeb87)
				{
					HX_STACK_LINE(1779)
					int _int = ::Main_obj::_this->controlscheme->__get((int)0);		HX_STACK_VAR(_int,"int");
					HX_STACK_LINE(1779)
					return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
				}
				return null();
			}
		};
		HX_STACK_LINE(1779)
		if (((_Function_1_4::Block() == event->keyCode))){
			HX_STACK_LINE(1781)
			this->control[(int)1] = false;
		}
		HX_STACK_LINE(1783)
		this->ControlEvent = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,stage_onKeyUp,(void))

Dynamic GameView_obj::todyn( Dynamic Dyn){
	HX_STACK_FRAME("GameView","todyn",0xbe3e1887,"GameView.todyn","GameView.hx",1792,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(Dyn,"Dyn")
	HX_STACK_LINE(1792)
	return Dyn;
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,todyn,return )

Dynamic GameView_obj::AddEntityFromData( Dynamic D){
	HX_STACK_FRAME("GameView","AddEntityFromData",0xbc5c3a41,"GameView.AddEntityFromData","GameView.hx",1795,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(D,"D")
	HX_STACK_LINE(1796)
	Dynamic E = this->SpawnEntityFromData(D);		HX_STACK_VAR(E,"E");
	HX_STACK_LINE(1797)
	if (((E != null()))){
		HX_STACK_LINE(1799)
		if (((E->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Enemy")))){
			HX_STACK_LINE(1801)
			this->AddEnemy(E);
		}
		HX_STACK_LINE(1803)
		if (((E->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Item")))){
			HX_STACK_LINE(1805)
			this->AddEntityItem(E);
		}
		HX_STACK_LINE(1807)
		if ((!(this->Hoster))){
			HX_STACK_LINE(1809)
			E->__Field(HX_CSTRING("catchup"),true)();
		}
	}
	HX_STACK_LINE(1812)
	return E;
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,AddEntityFromData,return )

Dynamic GameView_obj::SpawnEntityFromData( Dynamic D){
	HX_STACK_FRAME("GameView","SpawnEntityFromData",0xd200c41b,"GameView.SpawnEntityFromData","GameView.hx",1815,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(D,"D")
	HX_STACK_LINE(1816)
	Dynamic E = null();		HX_STACK_VAR(E,"E");
	HX_STACK_LINE(1817)
	::String type = HX_CSTRING("");		HX_STACK_VAR(type,"type");
	HX_STACK_LINE(1818)
	::Entity _g = this->EntityFromUID(D->__Field(HX_CSTRING("UID"),true));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1818)
	if (((_g == null()))){
		HX_STACK_LINE(1820)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("RedFairy")))){
			HX_STACK_LINE(1822)
			::RedFairy _g1 = ::RedFairy_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1822)
			E = _g1;
			HX_STACK_LINE(1823)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1825)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Mystia")))){
			HX_STACK_LINE(1827)
			::Mystia _g2 = ::Mystia_obj::__new();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1827)
			E = _g2;
			HX_STACK_LINE(1828)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1830)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Keine")))){
			HX_STACK_LINE(1832)
			::Keine _g3 = ::Keine_obj::__new();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(1832)
			E = _g3;
			HX_STACK_LINE(1833)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1835)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Keineex")))){
			HX_STACK_LINE(1837)
			::Keine _g4 = ::Keine_obj::__new();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(1837)
			E = _g4;
			HX_STACK_LINE(1838)
			type = HX_CSTRING("Enemy");
			HX_STACK_LINE(1839)
			E->__FieldRef(HX_CSTRING("ex")) = true;
		}
		HX_STACK_LINE(1841)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Chen")))){
			HX_STACK_LINE(1843)
			::Chen _g5 = ::Chen_obj::__new();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(1843)
			E = _g5;
			HX_STACK_LINE(1844)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1846)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("UFO")))){
			HX_STACK_LINE(1848)
			::UFO _g6 = ::UFO_obj::__new();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(1848)
			E = _g6;
			HX_STACK_LINE(1849)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1851)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Cirno")))){
			HX_STACK_LINE(1853)
			::Cirno _g7 = ::Cirno_obj::__new();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(1853)
			E = _g7;
			HX_STACK_LINE(1854)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1856)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Imposter")))){
			HX_STACK_LINE(1858)
			::Imposter _g8 = ::Imposter_obj::__new();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(1858)
			E = _g8;
			HX_STACK_LINE(1859)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1861)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("rumia")))){
			HX_STACK_LINE(1863)
			::Rumia _g9 = ::Rumia_obj::__new();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(1863)
			E = _g9;
			HX_STACK_LINE(1864)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1866)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("seija")))){
			HX_STACK_LINE(1868)
			::Seija _g10 = ::Seija_obj::__new();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(1868)
			E = _g10;
			HX_STACK_LINE(1869)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1871)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Nue")))){
			HX_STACK_LINE(1873)
			::Nue _g11 = ::Nue_obj::__new();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(1873)
			E = _g11;
			HX_STACK_LINE(1874)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1876)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Nue")))){
			HX_STACK_LINE(1878)
			::Nue _g12 = ::Nue_obj::__new();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(1878)
			E = _g12;
			HX_STACK_LINE(1879)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1881)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("tewi")))){
			HX_STACK_LINE(1883)
			::Tewi _g13 = ::Tewi_obj::__new();		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(1883)
			E = _g13;
			HX_STACK_LINE(1884)
			type = HX_CSTRING("Enemy");
		}
		HX_STACK_LINE(1886)
		if (((bool((E != null())) && bool((type == HX_CSTRING("Enemy")))))){
			HX_STACK_LINE(1888)
			E->__FieldRef(HX_CSTRING("UID")) = D->__Field(HX_CSTRING("UID"),true);
			HX_STACK_LINE(1889)
			E->__FieldRef(HX_CSTRING("y")) = D->__Field(HX_CSTRING("y"),true);
			HX_STACK_LINE(1890)
			E->__FieldRef(HX_CSTRING("x")) = D->__Field(HX_CSTRING("x"),true);
			HX_STACK_LINE(1891)
			E->__FieldRef(HX_CSTRING("Ldir")) = D->__Field(HX_CSTRING("Ldir"),true);
			HX_STACK_LINE(1892)
			E->__FieldRef(HX_CSTRING("alive")) = D->__Field(HX_CSTRING("alive"),true);
			HX_STACK_LINE(1893)
			E->__FieldRef(HX_CSTRING("Hspeed")) = D->__Field(HX_CSTRING("Hspeed"),true);
			HX_STACK_LINE(1894)
			E->__FieldRef(HX_CSTRING("Vspeed")) = D->__Field(HX_CSTRING("Vspeed"),true);
			HX_STACK_LINE(1895)
			E->__FieldRef(HX_CSTRING("enraged")) = D->__Field(HX_CSTRING("enraged"),true);
			HX_STACK_LINE(1896)
			E->__FieldRef(HX_CSTRING("rank")) = D->__Field(HX_CSTRING("rank"),true);
			HX_STACK_LINE(1897)
			E->__FieldRef(HX_CSTRING("visible")) = D->__Field(HX_CSTRING("visible"),true);
			HX_STACK_LINE(1898)
			if ((D->__Field(HX_CSTRING("enraged"),true))){
				HX_STACK_LINE(1900)
				E->__Field(HX_CSTRING("enrage"),true)();
			}
		}
		HX_STACK_LINE(1903)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("Point")))){
			HX_STACK_LINE(1905)
			::PointItem _g14 = ::PointItem_obj::__new();		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(1905)
			E = _g14;
			HX_STACK_LINE(1906)
			::SoundManager_obj::Play(HX_CSTRING("spawncoin"));
			HX_STACK_LINE(1907)
			type = HX_CSTRING("Item");
		}
		HX_STACK_LINE(1909)
		if (((D->__Field(HX_CSTRING("type"),true) == HX_CSTRING("1up")))){
			HX_STACK_LINE(1911)
			::LifeItem _g15 = ::LifeItem_obj::__new();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(1911)
			E = _g15;
			HX_STACK_LINE(1912)
			::SoundManager_obj::Play(HX_CSTRING("spawncoin"));
			HX_STACK_LINE(1913)
			type = HX_CSTRING("Item");
		}
		HX_STACK_LINE(1915)
		if (((bool((E != null())) && bool((type == HX_CSTRING("Item")))))){
			HX_STACK_LINE(1917)
			E->__FieldRef(HX_CSTRING("UID")) = D->__Field(HX_CSTRING("UID"),true);
			HX_STACK_LINE(1918)
			E->__FieldRef(HX_CSTRING("x")) = D->__Field(HX_CSTRING("x"),true);
			HX_STACK_LINE(1919)
			E->__FieldRef(HX_CSTRING("y")) = D->__Field(HX_CSTRING("y"),true);
			HX_STACK_LINE(1920)
			E->__FieldRef(HX_CSTRING("Ldir")) = D->__Field(HX_CSTRING("Ldir"),true);
		}
	}
	HX_STACK_LINE(1923)
	return E;
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,SpawnEntityFromData,return )

::Entity GameView_obj::EntityFromUID( Float UID){
	HX_STACK_FRAME("GameView","EntityFromUID",0x24629c2c,"GameView.EntityFromUID","GameView.hx",1928,0x658aeb87)
	HX_STACK_THIS(this)
	HX_STACK_ARG(UID,"UID")
	HX_STACK_LINE(1929)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1930)
	while((true)){
		HX_STACK_LINE(1930)
		if ((!(((i < this->entities->length))))){
			HX_STACK_LINE(1930)
			break;
		}
		HX_STACK_LINE(1932)
		::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
		HX_STACK_LINE(1933)
		if (((E->UID == UID))){
			HX_STACK_LINE(1935)
			return E;
		}
		HX_STACK_LINE(1937)
		hx::AddEq(i,(int)1);
	}
	HX_STACK_LINE(1939)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,EntityFromUID,return )

Void GameView_obj::this_onEnterFrame( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("GameView","this_onEnterFrame",0xa2599d1e,"GameView.this_onEnterFrame","GameView.hx",1941,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(1942)
		Float currentTime = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(currentTime,"currentTime");
		HX_STACK_LINE(1943)
		Float T = (currentTime - this->ltime);		HX_STACK_VAR(T,"T");
		HX_STACK_LINE(1944)
		hx::AddEq(this->missingTime,T);
		HX_STACK_LINE(1945)
		this->TF->set_blendMode(::openfl::_v2::display::BlendMode_obj::INVERT);
		HX_STACK_LINE(1946)
		if ((this->online)){
			HX_STACK_LINE(1948)
			this->TF->set_text((((((HX_CSTRING("Room:") + this->Room) + HX_CSTRING("\nLevel:")) + this->level) + HX_CSTRING("\nLives:")) + this->myplayer->lives));
		}
		else{
			HX_STACK_LINE(1952)
			this->TF->set_text((((HX_CSTRING("Level:") + this->level) + HX_CSTRING("\nLives:")) + this->myplayer->lives));
		}
		HX_STACK_LINE(1954)
		if ((::Main_obj::_this->DEBUG)){
			HX_STACK_LINE(1956)
			::String _g = this->TF->get_text();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1956)
			::String _g1 = (_g + HX_CSTRING("\nEPM:"));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1956)
			int _g2 = ::Math_obj::round(this->epm);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1956)
			::String _g3 = (_g1 + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(1956)
			::String _g4 = (_g3 + HX_CSTRING("\nmaxspawns:"));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(1956)
			::String _g5 = (_g4 + this->maxspawns);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(1956)
			this->TF->set_text(_g5);
		}
		HX_STACK_LINE(1958)
		this->TF->set_textColor((int)16777215);
		HX_STACK_LINE(1960)
		while((true)){
			HX_STACK_LINE(1960)
			if ((!(((this->missingTime > 0.05))))){
				HX_STACK_LINE(1960)
				break;
			}
			HX_STACK_LINE(1962)
			this->updategame(event);
			HX_STACK_LINE(1963)
			hx::SubEq(this->missingTime,0.034);
		}
		HX_STACK_LINE(1965)
		bool cameraenabled = false;		HX_STACK_VAR(cameraenabled,"cameraenabled");
		HX_STACK_LINE(1966)
		if ((cameraenabled)){
			HX_STACK_LINE(1968)
			Float _g6 = -(this->myplayer->get_y());		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(1968)
			Float _g7 = (_g6 + (int)300);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(1968)
			this->set_y(_g7);
			HX_STACK_LINE(1975)
			Float _g8 = this->get_y();		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(1975)
			if (((_g8 < (int)0))){
				HX_STACK_LINE(1977)
				this->set_y((int)0);
			}
		}
		HX_STACK_LINE(1980)
		::String S = HX_CSTRING("");		HX_STACK_VAR(S,"S");
		HX_STACK_LINE(1981)
		this->CombinedScore = (int)0;
		HX_STACK_LINE(1982)
		this->CombinedScoreALL = (int)0;
		HX_STACK_LINE(1983)
		if ((this->online)){
			HX_STACK_LINE(1985)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(1988)
			Array< ::Dynamic > PL = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(PL,"PL");
			HX_STACK_LINE(1989)
			Dynamic A = this->Players->iterator();		HX_STACK_VAR(A,"A");
			HX_STACK_LINE(1990)
			while((true)){
				HX_STACK_LINE(1990)
				if ((!(A->__Field(HX_CSTRING("hasNext"),true)()))){
					HX_STACK_LINE(1990)
					break;
				}
				HX_STACK_LINE(1992)
				::Player E = A->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(E,"E");
				HX_STACK_LINE(1993)
				PL[PL->length] = E;
				HX_STACK_LINE(1994)
				hx::AddEq(this->CombinedScoreALL,E->score);
				HX_STACK_LINE(1995)
				hx::AddEq(this->CombinedScore,(E->score - E->spentscore));
			}

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
			int run(Dynamic a,Dynamic b){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","GameView.hx",2005,0x658aeb87)
				HX_STACK_ARG(a,"a")
				HX_STACK_ARG(b,"b")
				{
					HX_STACK_LINE(2006)
					if (((a->__Field(HX_CSTRING("score"),true) < b->__Field(HX_CSTRING("score"),true)))){
						HX_STACK_LINE(2006)
						return (int)-1;
					}
					HX_STACK_LINE(2007)
					if (((a->__Field(HX_CSTRING("score"),true) > b->__Field(HX_CSTRING("score"),true)))){
						HX_STACK_LINE(2007)
						return (int)1;
					}
					HX_STACK_LINE(2008)
					return (int)0;
				}
				return null();
			}
			HX_END_LOCAL_FUNC2(return)

			HX_STACK_LINE(2005)
			PL->sort( Dynamic(new _Function_2_1()));
			HX_STACK_LINE(2010)
			while((true)){
				HX_STACK_LINE(2010)
				if ((!(((i < PL->length))))){
					HX_STACK_LINE(2010)
					break;
				}
				HX_STACK_LINE(2012)
				::Player E = PL->__get(i).StaticCast< ::Player >();		HX_STACK_VAR(E,"E");
				HX_STACK_LINE(2013)
				if (((S == HX_CSTRING("")))){
					HX_STACK_LINE(2015)
					S = ((E->playername + HX_CSTRING(":")) + E->score);
				}
				else{
					HX_STACK_LINE(2019)
					S = ((((S + HX_CSTRING("\n")) + E->playername) + HX_CSTRING(":")) + E->score);
				}
				HX_STACK_LINE(2021)
				(i)++;
			}
		}
		else{
			HX_STACK_LINE(2027)
			this->CombinedScore = (this->myplayer->score - this->myplayer->spentscore);
			HX_STACK_LINE(2028)
			this->CombinedScoreALL = this->myplayer->score;
			HX_STACK_LINE(2029)
			S = ((((this->myplayer->playername + HX_CSTRING(":")) + this->myplayer->score) + HX_CSTRING("\nHighscore:")) + this->HighScore);
		}
		HX_STACK_LINE(2031)
		this->scoreboard->set_text(S);
		HX_STACK_LINE(2032)
		Float _g9 = this->scoreboard->get_textWidth();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(2032)
		Float _g10 = (_g9 + (int)4);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(2032)
		this->scoreboard->set_width(_g10);
		HX_STACK_LINE(2033)
		Float _g11 = this->scoreboard->get_textHeight();		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(2033)
		Float _g12 = (_g11 + (int)4);		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(2033)
		this->scoreboard->set_height(_g12);
		HX_STACK_LINE(2034)
		hx::AddEq(this->frame,(int)1);
		HX_STACK_LINE(2088)
		this->removeChild(this->BGCBottom);
		HX_STACK_LINE(2089)
		this->removeChild(this->BGCLeft);
		HX_STACK_LINE(2090)
		this->removeChild(this->BGCRight);
		HX_STACK_LINE(2091)
		this->removeChild(this->Dpad);
		HX_STACK_LINE(2093)
		this->addChild(this->BGCBottom);
		HX_STACK_LINE(2094)
		this->addChild(this->BGCLeft);
		HX_STACK_LINE(2095)
		this->addChild(this->BGCRight);
		HX_STACK_LINE(2096)
		this->addChild(this->Dpad);
		HX_STACK_LINE(2097)
		this->ltime = currentTime;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,this_onEnterFrame,(void))

Void GameView_obj::SendStatus( ){
{
		HX_STACK_FRAME("GameView","SendStatus",0x76d57231,"GameView.SendStatus","GameView.hx",2099,0x658aeb87)
		HX_STACK_THIS(this)
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2100,0x658aeb87)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(2100)
		Dynamic D = _Function_1_1::Block();		HX_STACK_VAR(D,"D");
		HX_STACK_LINE(2101)
		D->__FieldRef(HX_CSTRING("level")) = this->level;
		HX_STACK_LINE(2102)
		D->__FieldRef(HX_CSTRING("totalenemies")) = (this->activeEnemies->length + this->SpawnList->length);
		HX_STACK_LINE(2103)
		D->__FieldRef(HX_CSTRING("activeEnemies")) = this->activeEnemies->length;
		HX_STACK_LINE(2104)
		D->__FieldRef(HX_CSTRING("HP")) = this->powblock->HP;
		HX_STACK_LINE(2105)
		D->__FieldRef(HX_CSTRING("activeItems")) = this->activeItems->length;
		HX_STACK_LINE(2106)
		int _g = this->RoundType->__Index();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2106)
		D->__FieldRef(HX_CSTRING("RoundType")) = _g;
		HX_STACK_LINE(2107)
		D->__FieldRef(HX_CSTRING("gamemode")) = this->gamemode;
		HX_STACK_LINE(2108)
		this->SendEvent(HX_CSTRING("Status"),D);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,SendStatus,(void))

Void GameView_obj::updategame( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("GameView","updategame",0xeb0d11f2,"GameView.updategame","GameView.hx",2110,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(2111)
		if (((this->missingTime < 0.01))){
			HX_STACK_LINE(2113)
			return null();
		}
		HX_STACK_LINE(2115)
		if (((this->platformformation != this->currentformation))){
			HX_STACK_LINE(2117)
			this->setformation();
		}
		HX_STACK_LINE(2119)
		if ((!(this->online))){
			HX_STACK_LINE(2121)
			this->Hoster = true;
		}
		HX_STACK_LINE(2123)
		if (((this->syncdelay > (int)0))){
			HX_STACK_LINE(2125)
			(this->syncdelay)--;
		}
		HX_STACK_LINE(2134)
		if ((this->Hoster)){
			HX_STACK_LINE(2136)
			this->totalenemies = (this->SpawnList->length + this->activeEnemies->length);
			HX_STACK_LINE(2137)
			hx::SubEq(this->SpawnTimer,(int)1);
			HX_STACK_LINE(2138)
			if (((bool((this->activeEnemies->length < (int)1)) && bool((this->spawns > (int)0))))){
				HX_STACK_LINE(2140)
				hx::SubEq(this->SpawnTimer,(int)2);
			}
			HX_STACK_LINE(2142)
			if (((bool((this->totalenemies == (int)1)) && bool(this->Hoster)))){
				HX_STACK_LINE(2144)
				if (((bool((this->activeEnemies->length > (int)0)) && bool(!(this->activeEnemies->__get((int)0).StaticCast< ::Enemy >()->enraged))))){
					HX_STACK_LINE(2146)
					this->SendEvent(HX_CSTRING("Enrage"),this->activeEnemies->__get((int)0).StaticCast< ::Enemy >()->UID);
				}
			}
			HX_STACK_LINE(2149)
			if (((bool(!(this->spawnedChar)) && bool((this->CombinedScore > (int(this->PointsToLife) >> int((int)1))))))){
				HX_STACK_LINE(2151)
				if (((this->totalenemies > (int)0))){
					HX_STACK_LINE(2153)
					if (((bool((bool((this->totalenemies == (int)1)) && bool((this->activeEnemies->length == (int)1)))) && bool(this->activeEnemies->__get((int)0).StaticCast< ::Enemy >()->killed)))){
					}
					else{
						HX_STACK_LINE(2159)
						::Imposter enemy = ::Imposter_obj::__new();		HX_STACK_VAR(enemy,"enemy");
						HX_STACK_LINE(2160)
						enemy->UID = (int)0;
						HX_STACK_LINE(2161)
						this->SpawnList->add(enemy);
						HX_STACK_LINE(2162)
						this->spawnedChar = true;
					}
				}
			}
			HX_STACK_LINE(2166)
			if (((this->CombinedScore > this->PointsToLife))){
				HX_STACK_LINE(2169)
				Dynamic A = this->Players->iterator();		HX_STACK_VAR(A,"A");
				HX_STACK_LINE(2171)
				int cost = this->PointsToLife;		HX_STACK_VAR(cost,"cost");
				HX_STACK_LINE(2172)
				while((true)){
					HX_STACK_LINE(2172)
					if ((!(A->__Field(HX_CSTRING("hasNext"),true)()))){
						HX_STACK_LINE(2172)
						break;
					}
					HX_STACK_LINE(2174)
					::Player E = A->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(E,"E");
					HX_STACK_LINE(2175)
					if (((cost > (E->score - E->spentscore)))){
						HX_STACK_LINE(2177)
						hx::SubEq(cost,(E->score - E->spentscore));
						HX_STACK_LINE(2178)
						E->spentscore = E->score;
					}
					else{
						HX_STACK_LINE(2182)
						hx::AddEq(E->spentscore,cost);
						HX_STACK_LINE(2183)
						cost = (int)0;
					}
				}
				struct _Function_3_1{
					inline static Dynamic Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2187,0x658aeb87)
						{
							hx::Anon __result = hx::Anon_obj::Create();
							return __result;
						}
						return null();
					}
				};
				HX_STACK_LINE(2187)
				Dynamic D = _Function_3_1::Block();		HX_STACK_VAR(D,"D");
				HX_STACK_LINE(2188)
				D->__FieldRef(HX_CSTRING("type")) = HX_CSTRING("1up");
				HX_STACK_LINE(2189)
				Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(2189)
				D->__FieldRef(HX_CSTRING("UID")) = _g;
				HX_STACK_LINE(2190)
				Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(2190)
				if (((_g1 > 0.5))){
					HX_STACK_LINE(2192)
					D->__FieldRef(HX_CSTRING("x")) = (int)800;
					HX_STACK_LINE(2193)
					D->__FieldRef(HX_CSTRING("Ldir")) = (int)-1;
				}
				else{
					HX_STACK_LINE(2197)
					D->__FieldRef(HX_CSTRING("x")) = (int)-16;
					HX_STACK_LINE(2198)
					D->__FieldRef(HX_CSTRING("Ldir")) = (int)1;
				}
				HX_STACK_LINE(2200)
				D->__FieldRef(HX_CSTRING("y")) = (int)-100;
				HX_STACK_LINE(2201)
				this->spawnedChar = false;
				HX_STACK_LINE(2202)
				this->SendEvent(HX_CSTRING("SpawnItem"),D);
				HX_STACK_LINE(2203)
				hx::SubEq(this->CombinedScore,this->PointsToLife);
			}
		}
		HX_STACK_LINE(2217)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(2218)
		while((true)){
			HX_STACK_LINE(2218)
			if ((!(((i < this->entities->length))))){
				HX_STACK_LINE(2218)
				break;
			}
			HX_STACK_LINE(2220)
			::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(2221)
			E->update();
			HX_STACK_LINE(2222)
			if ((!(E->alive))){
				HX_STACK_LINE(2224)
				if (((E->type == HX_CSTRING("Enemy")))){
					HX_STACK_LINE(2226)
					this->RemoveEnemy(E);
					HX_STACK_LINE(2227)
					if ((this->Hoster)){
						HX_STACK_LINE(2229)
						this->totalenemies = (this->SpawnList->length + this->activeEnemies->length);
					}
					else{
						HX_STACK_LINE(2234)
						(this->totalenemies)--;
					}
				}
				else{
					HX_STACK_LINE(2237)
					if (((E->type == HX_CSTRING("Item")))){
						HX_STACK_LINE(2239)
						this->RemoveEntityItem(E);
					}
					else{
						HX_STACK_LINE(2243)
						this->RemoveObject(E);
					}
				}
				HX_STACK_LINE(2247)
				if (((E->type == HX_CSTRING("Enemy")))){
					HX_STACK_LINE(2249)
					if ((!(E->killed))){
						HX_STACK_LINE(2251)
						if ((this->Hoster)){
							HX_STACK_LINE(2253)
							Dynamic D = E;		HX_STACK_VAR(D,"D");
							HX_STACK_LINE(2254)
							::Enemy EE = D;		HX_STACK_VAR(EE,"EE");
							HX_STACK_LINE(2255)
							this->SpawnList->add(EE);
						}
					}
					else{
						HX_STACK_LINE(2260)
						Dynamic EE = E;		HX_STACK_VAR(EE,"EE");
						HX_STACK_LINE(2261)
						if (((bool(this->Hoster) && bool(EE->__Field(HX_CSTRING("reward"),true))))){
							struct _Function_6_1{
								inline static Dynamic Block( ){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2264,0x658aeb87)
									{
										hx::Anon __result = hx::Anon_obj::Create();
										return __result;
									}
									return null();
								}
							};
							HX_STACK_LINE(2264)
							Dynamic D = _Function_6_1::Block();		HX_STACK_VAR(D,"D");
							HX_STACK_LINE(2267)
							D->__FieldRef(HX_CSTRING("type")) = HX_CSTRING("Point");
							HX_STACK_LINE(2272)
							Float _g2 = ::Math_obj::random();		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(2272)
							D->__FieldRef(HX_CSTRING("UID")) = _g2;
							HX_STACK_LINE(2273)
							Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(2273)
							if (((_g3 > 0.5))){
								HX_STACK_LINE(2275)
								D->__FieldRef(HX_CSTRING("x")) = (int)800;
								HX_STACK_LINE(2276)
								D->__FieldRef(HX_CSTRING("Ldir")) = (int)-1;
							}
							else{
								HX_STACK_LINE(2280)
								D->__FieldRef(HX_CSTRING("x")) = (int)-16;
								HX_STACK_LINE(2281)
								D->__FieldRef(HX_CSTRING("Ldir")) = (int)1;
							}
							HX_STACK_LINE(2283)
							D->__FieldRef(HX_CSTRING("y")) = (int)-100;
							HX_STACK_LINE(2284)
							this->SendEvent(HX_CSTRING("SpawnItem"),D);
						}
					}
				}
			}
			HX_STACK_LINE(2291)
			hx::AddEq(i,(int)1);
		}
		HX_STACK_LINE(2293)
		int i1 = (int)0;		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(2294)
		if ((this->MSE)){
			HX_STACK_LINE(2296)
			Float _g4 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(2296)
			if (((_g4 < (int)600))){
				HX_STACK_LINE(2298)
				Float _g5 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(2298)
				this->control[(int)0] = (_g5 > (int)500);
				HX_STACK_LINE(2299)
				Float _g6 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(2299)
				this->control[(int)1] = (_g6 < (int)100);
				HX_STACK_LINE(2300)
				Float _g7 = this->get_stage()->get_mouseX();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(2300)
				this->control[(int)2] = (_g7 < (int)200);
				HX_STACK_LINE(2301)
				Float _g8 = this->get_stage()->get_mouseX();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(2301)
				this->control[(int)3] = (_g8 > (int)600);
			}
			else{
				HX_STACK_LINE(2309)
				Float _g9 = this->Dpad->get_y();		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(2309)
				Float _g10 = (_g9 + (int)384);		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(2309)
				Float _g11 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(2309)
				if (((_g10 < _g11))){
					HX_STACK_LINE(2311)
					Float _g12 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(2311)
					Float _g13 = (_g12 - (int)383);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(2311)
					this->Dpad->set_y(_g13);
				}
				HX_STACK_LINE(2317)
				Float _g14 = this->Dpad->get_y();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(2317)
				Float _g15 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(2317)
				if (((_g14 > _g15))){
					HX_STACK_LINE(2319)
					Float _g16 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(2319)
					Float _g17 = (_g16 - (int)1);		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(2319)
					this->Dpad->set_y(_g17);
				}
				HX_STACK_LINE(2321)
				Float _g18 = this->get_stage()->get_mouseX();		HX_STACK_VAR(_g18,"_g18");
				struct _Function_3_1{
					inline static bool Block( hx::ObjectPtr< ::GameView_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2321,0x658aeb87)
						{
							HX_STACK_LINE(2321)
							Float _g19 = __this->get_stage()->get_mouseY();		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(2321)
							Float _g20 = __this->Dpad->get_y();		HX_STACK_VAR(_g20,"_g20");
							HX_STACK_LINE(2321)
							Float _g21 = (_g20 + (int)384);		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(2321)
							return (_g19 < _g21);
						}
						return null();
					}
				};
				HX_STACK_LINE(2321)
				if (((  (((_g18 < (int)384))) ? bool(_Function_3_1::Block(this)) : bool(false) ))){
					HX_STACK_LINE(2323)
					Float _g22 = this->get_stage()->get_mouseX();		HX_STACK_VAR(_g22,"_g22");
					HX_STACK_LINE(2323)
					Float _g23 = (Float(_g22) / Float((int)128));		HX_STACK_VAR(_g23,"_g23");
					HX_STACK_LINE(2323)
					int X = ::Math_obj::floor(_g23);		HX_STACK_VAR(X,"X");
					HX_STACK_LINE(2324)
					Float _g24 = this->get_stage()->get_mouseY();		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(2324)
					Float _g25 = this->Dpad->get_y();		HX_STACK_VAR(_g25,"_g25");
					HX_STACK_LINE(2324)
					Float _g26 = (_g24 - _g25);		HX_STACK_VAR(_g26,"_g26");
					HX_STACK_LINE(2324)
					Float _g27 = (Float(_g26) / Float((int)128));		HX_STACK_VAR(_g27,"_g27");
					HX_STACK_LINE(2324)
					int Y = ::Math_obj::floor(_g27);		HX_STACK_VAR(Y,"Y");
					HX_STACK_LINE(2325)
					this->control[(int)0] = (Y == (int)2);
					HX_STACK_LINE(2326)
					this->control[(int)1] = (Y == (int)0);
					HX_STACK_LINE(2327)
					this->control[(int)2] = (X == (int)0);
					HX_STACK_LINE(2328)
					this->control[(int)3] = (X == (int)2);
				}
			}
		}
		HX_STACK_LINE(2355)
		if ((this->Hoster)){
			HX_STACK_LINE(2358)
			if (((this->totalenemies > (int)0))){
				HX_STACK_LINE(2433)
				Float R = this->ept;		HX_STACK_VAR(R,"R");
				HX_STACK_LINE(2434)
				if (((this->spawns > (this->maxspawns + ((int(this->maxspawns) >> int((int)1))))))){
					HX_STACK_LINE(2436)
					R = this->rept;
				}
				struct _Function_3_1{
					inline static bool Block( Float &R){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2438,0x658aeb87)
						{
							HX_STACK_LINE(2438)
							Float _g28 = ::Math_obj::random();		HX_STACK_VAR(_g28,"_g28");
							HX_STACK_LINE(2438)
							return (_g28 < R);
						}
						return null();
					}
				};
				HX_STACK_LINE(2438)
				if (((  (((bool((R > (int)0)) && bool((((int(this->frame) & int((int)2))) > (int)0))))) ? bool(_Function_3_1::Block(R)) : bool(false) ))){
					HX_STACK_LINE(2440)
					Float evt = ::Math_obj::random();		HX_STACK_VAR(evt,"evt");
					HX_STACK_LINE(2441)
					::String E = HX_CSTRING("");		HX_STACK_VAR(E,"E");
					HX_STACK_LINE(2442)
					if (((this->Obstacles->length > (int)0))){
						HX_STACK_LINE(2444)
						Float _g29 = ::Math_obj::random();		HX_STACK_VAR(_g29,"_g29");
						HX_STACK_LINE(2444)
						Float _g30 = (this->Obstacles->length * _g29);		HX_STACK_VAR(_g30,"_g30");
						HX_STACK_LINE(2444)
						int _g31 = ::Math_obj::floor(_g30);		HX_STACK_VAR(_g31,"_g31");
						HX_STACK_LINE(2444)
						::String _g32 = this->Obstacles->__get(_g31);		HX_STACK_VAR(_g32,"_g32");
						HX_STACK_LINE(2444)
						E = _g32;
					}
					HX_STACK_LINE(2449)
					if (((E == HX_CSTRING("Gap")))){
						HX_STACK_LINE(2451)
						this->SendGap();
					}
					else{
						HX_STACK_LINE(2453)
						if (((E == HX_CSTRING("Cirno")))){
							struct _Function_6_1{
								inline static Dynamic Block( ){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2455,0x658aeb87)
									{
										hx::Anon __result = hx::Anon_obj::Create();
										return __result;
									}
									return null();
								}
							};
							HX_STACK_LINE(2455)
							Dynamic D = _Function_6_1::Block();		HX_STACK_VAR(D,"D");
							HX_STACK_LINE(2456)
							D->__FieldRef(HX_CSTRING("type")) = HX_CSTRING("Cirno");
							HX_STACK_LINE(2457)
							Float _g33 = ::Math_obj::random();		HX_STACK_VAR(_g33,"_g33");
							HX_STACK_LINE(2457)
							D->__FieldRef(HX_CSTRING("UID")) = _g33;
							HX_STACK_LINE(2458)
							Float _g34 = ::Math_obj::random();		HX_STACK_VAR(_g34,"_g34");
							HX_STACK_LINE(2458)
							if (((_g34 > 0.5))){
								HX_STACK_LINE(2460)
								D->__FieldRef(HX_CSTRING("x")) = (int)800;
								HX_STACK_LINE(2461)
								D->__FieldRef(HX_CSTRING("Ldir")) = (int)-1;
							}
							else{
								HX_STACK_LINE(2465)
								D->__FieldRef(HX_CSTRING("x")) = (int)-16;
								HX_STACK_LINE(2466)
								D->__FieldRef(HX_CSTRING("Ldir")) = (int)1;
							}
							HX_STACK_LINE(2468)
							D->__FieldRef(HX_CSTRING("y")) = (int)-100;
							HX_STACK_LINE(2469)
							D->__FieldRef(HX_CSTRING("alive")) = true;
							HX_STACK_LINE(2470)
							D->__FieldRef(HX_CSTRING("Hspeed")) = (int)0;
							HX_STACK_LINE(2471)
							D->__FieldRef(HX_CSTRING("Vspeed")) = (int)0;
							HX_STACK_LINE(2472)
							D->__FieldRef(HX_CSTRING("enraged")) = false;
							HX_STACK_LINE(2473)
							D->__FieldRef(HX_CSTRING("visible")) = true;
							HX_STACK_LINE(2474)
							D->__FieldRef(HX_CSTRING("rank")) = this->rank;
							HX_STACK_LINE(2475)
							::GameView_obj::_this->SendEvent(HX_CSTRING("SpawnEnemy"),D);
						}
						else{
							HX_STACK_LINE(2477)
							if (((bool((this->ufos < (int)8)) && bool((E == HX_CSTRING("UFO")))))){
								struct _Function_7_1{
									inline static Dynamic Block( ){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2479,0x658aeb87)
										{
											hx::Anon __result = hx::Anon_obj::Create();
											return __result;
										}
										return null();
									}
								};
								HX_STACK_LINE(2479)
								Dynamic D = _Function_7_1::Block();		HX_STACK_VAR(D,"D");
								HX_STACK_LINE(2480)
								D->__FieldRef(HX_CSTRING("type")) = HX_CSTRING("UFO");
								HX_STACK_LINE(2481)
								Float _g35 = ::Math_obj::random();		HX_STACK_VAR(_g35,"_g35");
								HX_STACK_LINE(2481)
								D->__FieldRef(HX_CSTRING("UID")) = _g35;
								HX_STACK_LINE(2482)
								Float _g36 = ::Math_obj::random();		HX_STACK_VAR(_g36,"_g36");
								HX_STACK_LINE(2482)
								if (((_g36 > 0.5))){
									HX_STACK_LINE(2484)
									Float _g37 = ::Math_obj::random();		HX_STACK_VAR(_g37,"_g37");
									HX_STACK_LINE(2484)
									Float _g38 = (_g37 * (int)800);		HX_STACK_VAR(_g38,"_g38");
									HX_STACK_LINE(2484)
									D->__FieldRef(HX_CSTRING("x")) = _g38;
									HX_STACK_LINE(2485)
									D->__FieldRef(HX_CSTRING("Ldir")) = (int)-1;
								}
								else{
									HX_STACK_LINE(2489)
									Float _g39 = ::Math_obj::random();		HX_STACK_VAR(_g39,"_g39");
									HX_STACK_LINE(2489)
									Float _g40 = (_g39 * (int)800);		HX_STACK_VAR(_g40,"_g40");
									HX_STACK_LINE(2489)
									D->__FieldRef(HX_CSTRING("x")) = _g40;
									HX_STACK_LINE(2490)
									D->__FieldRef(HX_CSTRING("Ldir")) = (int)1;
								}
								HX_STACK_LINE(2492)
								D->__FieldRef(HX_CSTRING("y")) = (int)-100;
								HX_STACK_LINE(2493)
								D->__FieldRef(HX_CSTRING("alive")) = true;
								HX_STACK_LINE(2494)
								D->__FieldRef(HX_CSTRING("Hspeed")) = (int)0;
								HX_STACK_LINE(2495)
								D->__FieldRef(HX_CSTRING("Vspeed")) = (int)0;
								HX_STACK_LINE(2496)
								D->__FieldRef(HX_CSTRING("enraged")) = false;
								HX_STACK_LINE(2497)
								D->__FieldRef(HX_CSTRING("visible")) = true;
								HX_STACK_LINE(2498)
								D->__FieldRef(HX_CSTRING("rank")) = this->rank;
								HX_STACK_LINE(2499)
								(this->ufos)++;
								HX_STACK_LINE(2500)
								::GameView_obj::_this->SendEvent(HX_CSTRING("SpawnEnemy"),D);
							}
						}
					}
				}
			}
			HX_STACK_LINE(2526)
			if (((this->SpawnTimer <= (int)0))){
				HX_STACK_LINE(2528)
				if (((this->SpawnList->length > (int)1))){
					HX_STACK_LINE(2530)
					Float _g41 = ::Math_obj::random();		HX_STACK_VAR(_g41,"_g41");
					HX_STACK_LINE(2530)
					Float _g42 = (_g41 * (int)5);		HX_STACK_VAR(_g42,"_g42");
					HX_STACK_LINE(2530)
					Float _g43 = ((int)2 + _g42);		HX_STACK_VAR(_g43,"_g43");
					HX_STACK_LINE(2530)
					Float _g44 = ((int)30 * _g43);		HX_STACK_VAR(_g44,"_g44");
					HX_STACK_LINE(2530)
					int _g45 = ::Std_obj::_int(_g44);		HX_STACK_VAR(_g45,"_g45");
					HX_STACK_LINE(2530)
					this->SpawnTimer = _g45;
				}
				HX_STACK_LINE(2535)
				if ((!(this->SpawnList->isEmpty()))){
					HX_STACK_LINE(2537)
					::Enemy E = this->SpawnList->pop();		HX_STACK_VAR(E,"E");
					struct _Function_4_1{
						inline static Dynamic Block( ){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2538,0x658aeb87)
							{
								hx::Anon __result = hx::Anon_obj::Create();
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(2538)
					Dynamic data = _Function_4_1::Block();		HX_STACK_VAR(data,"data");
					HX_STACK_LINE(2539)
					data->__FieldRef(HX_CSTRING("UID")) = E->UID;
					HX_STACK_LINE(2540)
					if (((data->__Field(HX_CSTRING("UID"),true) == (int)0))){
						HX_STACK_LINE(2543)
						Float _g46 = ::Math_obj::random();		HX_STACK_VAR(_g46,"_g46");
						HX_STACK_LINE(2543)
						data->__FieldRef(HX_CSTRING("UID")) = _g46;
					}
					HX_STACK_LINE(2545)
					Float _g47 = ::Math_obj::random();		HX_STACK_VAR(_g47,"_g47");
					HX_STACK_LINE(2545)
					if (((_g47 > 0.5))){
						HX_STACK_LINE(2547)
						data->__FieldRef(HX_CSTRING("x")) = (int)800;
						HX_STACK_LINE(2548)
						data->__FieldRef(HX_CSTRING("Ldir")) = (int)-1;
					}
					else{
						HX_STACK_LINE(2552)
						data->__FieldRef(HX_CSTRING("x")) = (int)-16;
						HX_STACK_LINE(2553)
						data->__FieldRef(HX_CSTRING("Ldir")) = (int)1;
					}
					HX_STACK_LINE(2555)
					data->__FieldRef(HX_CSTRING("y")) = (int)-100;
					HX_STACK_LINE(2556)
					data->__FieldRef(HX_CSTRING("alive")) = true;
					HX_STACK_LINE(2557)
					data->__FieldRef(HX_CSTRING("Hspeed")) = (int)0;
					HX_STACK_LINE(2558)
					data->__FieldRef(HX_CSTRING("Vspeed")) = (int)0;
					HX_STACK_LINE(2559)
					data->__FieldRef(HX_CSTRING("visible")) = true;
					HX_STACK_LINE(2560)
					data->__FieldRef(HX_CSTRING("enraged")) = E->enraged;
					HX_STACK_LINE(2561)
					data->__FieldRef(HX_CSTRING("type")) = E->charname;
					HX_STACK_LINE(2562)
					data->__FieldRef(HX_CSTRING("rank")) = E->rank;
					HX_STACK_LINE(2563)
					this->SendEvent(HX_CSTRING("SpawnEnemy"),data);
				}
				else{
					HX_STACK_LINE(2567)
					if (((this->activeEnemies->length < (int)1))){
						HX_STACK_LINE(2569)
						Float _g48 = ::Math_obj::random();		HX_STACK_VAR(_g48,"_g48");
						HX_STACK_LINE(2569)
						Float _g49 = (_g48 * (int)3);		HX_STACK_VAR(_g49,"_g49");
						HX_STACK_LINE(2569)
						Float _g50 = ((int)1 + _g49);		HX_STACK_VAR(_g50,"_g50");
						HX_STACK_LINE(2569)
						Float _g51 = ((int)30 * _g50);		HX_STACK_VAR(_g51,"_g51");
						HX_STACK_LINE(2569)
						int _g52 = ::Std_obj::_int(_g51);		HX_STACK_VAR(_g52,"_g52");
						HX_STACK_LINE(2569)
						this->SpawnTimer = _g52;
						HX_STACK_LINE(2570)
						hx::AddEq(this->level,(int)1);
						HX_STACK_LINE(2571)
						int tmp = (int)0;		HX_STACK_VAR(tmp,"tmp");
						HX_STACK_LINE(2572)
						this->CalculateLevelData();
						struct _Function_5_1{
							inline static Dynamic Block( ){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","GameView.hx",2573,0x658aeb87)
								{
									hx::Anon __result = hx::Anon_obj::Create();
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(2573)
						Dynamic data = _Function_5_1::Block();		HX_STACK_VAR(data,"data");
						HX_STACK_LINE(2574)
						data->__FieldRef(HX_CSTRING("level")) = this->level;
						HX_STACK_LINE(2575)
						int _g53 = this->RoundType->__Index();		HX_STACK_VAR(_g53,"_g53");
						HX_STACK_LINE(2575)
						data->__FieldRef(HX_CSTRING("RoundType")) = _g53;
						HX_STACK_LINE(2576)
						if (((bool((this->level > (int)1)) && bool(this->roundstarted)))){
							HX_STACK_LINE(2578)
							this->SendEvent(HX_CSTRING("NextLevel"),data);
						}
						HX_STACK_LINE(2580)
						if (((this->RoundType == ::TypeofRound_obj::Table))){
							HX_STACK_LINE(2582)
							::GameView_obj::_this->SendEvent(HX_CSTRING("Spawntables"),null());
						}
						HX_STACK_LINE(2617)
						this->totalenemies = (this->SpawnList->length + this->activeEnemies->length);
						HX_STACK_LINE(2618)
						this->SendEvent(HX_CSTRING("TotalEnemies"),this->totalenemies);
					}
				}
			}
		}
		else{
			HX_STACK_LINE(2627)
			if (((this->SpawnList->length == (int)0))){
				HX_STACK_LINE(2629)
				::RedFairy enemy = ::RedFairy_obj::__new();		HX_STACK_VAR(enemy,"enemy");
				HX_STACK_LINE(2630)
				this->SpawnList->add(enemy);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameView_obj,updategame,(void))

Void GameView_obj::AddToArrayMultiple( Dynamic array,Dynamic value,int times){
{
		HX_STACK_FRAME("GameView","AddToArrayMultiple",0xf0e19bc4,"GameView.AddToArrayMultiple","GameView.hx",2635,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(array,"array")
		HX_STACK_ARG(value,"value")
		HX_STACK_ARG(times,"times")
		HX_STACK_LINE(2636)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(2637)
		while((true)){
			HX_STACK_LINE(2637)
			if ((!(((i < times))))){
				HX_STACK_LINE(2637)
				break;
			}
			HX_STACK_LINE(2639)
			hx::IndexRef((array).mPtr,array->__Field(HX_CSTRING("length"),true)) = value;
			HX_STACK_LINE(2640)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GameView_obj,AddToArrayMultiple,(void))

Void GameView_obj::CalculateLevelData( ){
{
		HX_STACK_FRAME("GameView","CalculateLevelData",0x5f4f6a1f,"GameView.CalculateLevelData","GameView.hx",2644,0x658aeb87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(2645)
		int L = (this->level - (int)1);		HX_STACK_VAR(L,"L");
		HX_STACK_LINE(2646)
		if (((L < (int)0))){
			HX_STACK_LINE(2648)
			L = (int)0;
		}
		HX_STACK_LINE(2650)
		int _g = ::Math_obj::floor((Float(L) / Float((int)30)));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(2650)
		this->rank = _g;
		HX_STACK_LINE(2652)
		hx::SubEq(L,(this->rank * (int)15));
		HX_STACK_LINE(2653)
		Float points = (L + (int)2);		HX_STACK_VAR(points,"points");
		HX_STACK_LINE(2654)
		this->epm = (int)0;
		HX_STACK_LINE(2655)
		Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(2655)
		Float _g2 = (_g1 * 0.2);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(2655)
		Float R = (0.5 + _g2);		HX_STACK_VAR(R,"R");
		HX_STACK_LINE(2656)
		R = (R * points);
		HX_STACK_LINE(2659)
		Float AR = R;		HX_STACK_VAR(AR,"AR");
		HX_STACK_LINE(2660)
		while((true)){
			HX_STACK_LINE(2660)
			if ((!(((AR > (int)1))))){
				HX_STACK_LINE(2660)
				break;
			}
			HX_STACK_LINE(2662)
			(this->epm)++;
			HX_STACK_LINE(2663)
			Float tmp = (this->epm * 0.2);		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(2664)
			if (((tmp < (int)1))){
				HX_STACK_LINE(2666)
				tmp = (int)1;
			}
			HX_STACK_LINE(2668)
			hx::SubEq(AR,tmp);
		}
		HX_STACK_LINE(2670)
		hx::SubEq(points,R);
		HX_STACK_LINE(2672)
		Dynamic A = this->Players->keys();		HX_STACK_VAR(A,"A");
		HX_STACK_LINE(2673)
		int P = (int)0;		HX_STACK_VAR(P,"P");
		HX_STACK_LINE(2674)
		while((true)){
			HX_STACK_LINE(2674)
			if ((!(A->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(2674)
				break;
			}
			HX_STACK_LINE(2676)
			A->__Field(HX_CSTRING("next"),true)();
			HX_STACK_LINE(2677)
			(P)++;
		}
		HX_STACK_LINE(2687)
		Float EVT = ::Math_obj::random();		HX_STACK_VAR(EVT,"EVT");
		HX_STACK_LINE(2688)
		if (((this->level == (int)9))){
			HX_STACK_LINE(2691)
			hx::MultEq(EVT,0.25);
		}
		HX_STACK_LINE(2693)
		this->RoundType = ::TypeofRound_obj::Normal;
		HX_STACK_LINE(2694)
		Array< ::Dynamic > enemytypes = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(enemytypes,"enemytypes");
		HX_STACK_LINE(2695)
		int _g3 = ::Math_obj::ceil(points);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(2695)
		int _g4 = (_g3 + P);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(2695)
		int _g5 = (_g4 + (int)1);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(2695)
		this->maxspawns = _g5;
		HX_STACK_LINE(2697)
		Array< ::String > _g6 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(2697)
		this->Obstacles = _g6;
		HX_STACK_LINE(2702)
		if (((this->gamemode == (int)13))){
			HX_STACK_LINE(2704)
			EVT = (int)0;
		}
		HX_STACK_LINE(2706)
		if (((EVT < 0.08))){
			HX_STACK_LINE(2708)
			Array< ::Dynamic > E = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(E,"E");
			HX_STACK_LINE(2709)
			if (((bool((this->level != (int)9)) || bool((this->gamemode == (int)13))))){
				HX_STACK_LINE(2711)
				E[E->length] = ::TypeofRound_obj::Rumia;
				HX_STACK_LINE(2712)
				E[E->length] = ::TypeofRound_obj::Table;
				HX_STACK_LINE(2713)
				E[E->length] = ::TypeofRound_obj::Cirno;
				HX_STACK_LINE(2714)
				if (((bool((this->level >= (int)11)) || bool((this->gamemode == (int)13))))){
					HX_STACK_LINE(2716)
					E[E->length] = ::TypeofRound_obj::Nue;
				}
				HX_STACK_LINE(2718)
				if (((bool((this->level > (int)5)) || bool((this->gamemode == (int)13))))){
					HX_STACK_LINE(2720)
					E[E->length] = ::TypeofRound_obj::Seija;
				}
				HX_STACK_LINE(2722)
				if (((bool((this->level > (int)15)) || bool((this->gamemode == (int)13))))){
					HX_STACK_LINE(2724)
					E[E->length] = ::TypeofRound_obj::FireCirno;
				}
			}
			else{
				HX_STACK_LINE(2729)
				E[E->length] = ::TypeofRound_obj::Cirno;
			}
			HX_STACK_LINE(2731)
			Float _g7 = ::Math_obj::random();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(2731)
			Float _g8 = (_g7 * E->length);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(2731)
			int _g9 = ::Math_obj::floor(_g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(2731)
			::TypeofRound _g10 = E->__get(_g9).StaticCast< ::TypeofRound >();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(2731)
			this->RoundType = _g10;
		}
		HX_STACK_LINE(2735)
		if (((this->gamemode == (int)5))){
			HX_STACK_LINE(2737)
			this->RoundType = ::TypeofRound_obj::Table;
		}
		HX_STACK_LINE(2740)
		if (((this->gamemode == (int)12))){
			HX_STACK_LINE(2742)
			this->RoundType = ::TypeofRound_obj::Cirno;
		}
		HX_STACK_LINE(2744)
		if (((this->gamemode == (int)1))){
			HX_STACK_LINE(2746)
			this->RoundType = ::TypeofRound_obj::FireCirno;
		}
		HX_STACK_LINE(2748)
		if (((this->gamemode == (int)15))){
			HX_STACK_LINE(2750)
			this->RoundType = ::TypeofRound_obj::Nue;
		}
		HX_STACK_LINE(2754)
		if (((bool((bool((this->RoundType == ::TypeofRound_obj::Normal)) || bool((this->RoundType == ::TypeofRound_obj::Rumia)))) || bool((this->RoundType == ::TypeofRound_obj::Table))))){
			HX_STACK_LINE(2756)
			if (((this->level > (int)5))){
				HX_STACK_LINE(2758)
				this->AddToArrayMultiple(this->Obstacles,HX_CSTRING("Cirno"),(int)4);
			}
			HX_STACK_LINE(2761)
			this->AddToArrayMultiple(this->Obstacles,HX_CSTRING("Gap"),(int)5);
			HX_STACK_LINE(2763)
			if (((this->level > (int)10))){
				HX_STACK_LINE(2765)
				this->AddToArrayMultiple(this->Obstacles,HX_CSTRING("UFO"),(int)2);
			}
		}
		HX_STACK_LINE(2769)
		if (((this->RoundType == ::TypeofRound_obj::Nue))){
			HX_STACK_LINE(2771)
			this->Obstacles[this->Obstacles->length] = HX_CSTRING("UFO");
			HX_STACK_LINE(2772)
			::Imposter _g11 = ::Imposter_obj::__new();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(2772)
			this->AddToArrayMultiple(enemytypes,_g11,(int)2);
		}
		HX_STACK_LINE(2774)
		if (((this->RoundType == ::TypeofRound_obj::Yukari))){
			HX_STACK_LINE(2776)
			this->Obstacles[this->Obstacles->length] = HX_CSTRING("Gap");
			HX_STACK_LINE(2777)
			::Imposter _g12 = ::Imposter_obj::__new();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(2777)
			this->AddToArrayMultiple(enemytypes,_g12,(int)2);
		}
		HX_STACK_LINE(2782)
		if (((bool((this->RoundType == ::TypeofRound_obj::Cirno)) || bool((this->RoundType == ::TypeofRound_obj::FireCirno))))){
			HX_STACK_LINE(2784)
			this->Obstacles[this->Obstacles->length] = HX_CSTRING("Cirno");
			HX_STACK_LINE(2785)
			::Imposter _g13 = ::Imposter_obj::__new();		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(2785)
			this->AddToArrayMultiple(enemytypes,_g13,(int)1);
			HX_STACK_LINE(2786)
			if (((this->RoundType == ::TypeofRound_obj::FireCirno))){
				HX_STACK_LINE(2788)
				hx::AddEq(this->epm,(int)7);
			}
			HX_STACK_LINE(2790)
			this->SpawnTimer = ((int)30 * ((this->maxspawns * (int)5)));
			HX_STACK_LINE(2791)
			if (((this->gamemode != (int)13))){
				HX_STACK_LINE(2793)
				if (((this->gamemode == (int)12))){
					HX_STACK_LINE(2795)
					hx::AddEq(this->maxspawns,(int)9);
				}
				else{
					HX_STACK_LINE(2799)
					if (((this->RoundType != ::TypeofRound_obj::FireCirno))){
						HX_STACK_LINE(2801)
						this->maxspawns = (int)9;
					}
				}
			}
			HX_STACK_LINE(2805)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(2806)
			while((true)){
				HX_STACK_LINE(2806)
				if ((!(((i < this->entities->length))))){
					HX_STACK_LINE(2806)
					break;
				}
				HX_STACK_LINE(2809)
				::Entity E = this->entities->__get(i).StaticCast< ::Entity >();		HX_STACK_VAR(E,"E");
				HX_STACK_LINE(2810)
				if (((E->type == HX_CSTRING("Block")))){
					HX_STACK_LINE(2813)
					Dynamic D = E;		HX_STACK_VAR(D,"D");
					HX_STACK_LINE(2814)
					D->__Field(HX_CSTRING("Freeze"),true)();
				}
				HX_STACK_LINE(2816)
				hx::AddEq(i,(int)1);
			}
		}
		HX_STACK_LINE(2820)
		if (((this->RoundType == ::TypeofRound_obj::Rumia))){
			HX_STACK_LINE(2822)
			::Rumia _g14 = ::Rumia_obj::__new();		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(2822)
			this->AddToArrayMultiple(enemytypes,_g14,(int)100);
			HX_STACK_LINE(2823)
			::Imposter _g15 = ::Imposter_obj::__new();		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(2823)
			this->AddToArrayMultiple(enemytypes,_g15,(int)2);
		}
		HX_STACK_LINE(2825)
		if (((this->RoundType == ::TypeofRound_obj::Seija))){
			HX_STACK_LINE(2827)
			::Seija _g16 = ::Seija_obj::__new();		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(2827)
			this->AddToArrayMultiple(enemytypes,_g16,(int)50);
			HX_STACK_LINE(2828)
			::Imposter _g17 = ::Imposter_obj::__new();		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(2828)
			this->AddToArrayMultiple(enemytypes,_g17,(int)2);
		}
		HX_STACK_LINE(2830)
		if (((bool((bool((bool((bool((bool((this->RoundType == ::TypeofRound_obj::Normal)) || bool((this->RoundType == ::TypeofRound_obj::Rumia)))) || bool((this->RoundType == ::TypeofRound_obj::Seija)))) || bool((this->RoundType == ::TypeofRound_obj::Nue)))) || bool((this->RoundType == ::TypeofRound_obj::Table)))) || bool((this->RoundType == ::TypeofRound_obj::FireCirno))))){
			HX_STACK_LINE(2832)
			::RedFairy _g18 = ::RedFairy_obj::__new();		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(2832)
			this->AddToArrayMultiple(enemytypes,_g18,(int)48);
			HX_STACK_LINE(2833)
			if (((this->level > (int)3))){
				HX_STACK_LINE(2835)
				::Keine _g19 = ::Keine_obj::__new();		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(2835)
				this->AddToArrayMultiple(enemytypes,_g19,(int)16);
			}
			HX_STACK_LINE(2837)
			::Mystia _g20 = ::Mystia_obj::__new();		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(2837)
			this->AddToArrayMultiple(enemytypes,_g20,(int)28);
			HX_STACK_LINE(2838)
			if (((this->level > (int)25))){
				HX_STACK_LINE(2840)
				::Tewi _g21 = ::Tewi_obj::__new();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(2840)
				this->AddToArrayMultiple(enemytypes,_g21,(int)30);
				HX_STACK_LINE(2841)
				::Imposter _g22 = ::Imposter_obj::__new();		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(2841)
				this->AddToArrayMultiple(enemytypes,_g22,(int)1);
			}
		}
		HX_STACK_LINE(2845)
		if (((this->RoundType == ::TypeofRound_obj::Nue))){
			HX_STACK_LINE(2847)
			::Nue _g23 = ::Nue_obj::__new();		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(2847)
			this->AddToArrayMultiple(enemytypes,_g23,(int)50);
			HX_STACK_LINE(2848)
			::Imposter _g24 = ::Imposter_obj::__new();		HX_STACK_VAR(_g24,"_g24");
			HX_STACK_LINE(2848)
			this->AddToArrayMultiple(enemytypes,_g24,(int)2);
			HX_STACK_LINE(2849)
			hx::MultEq(this->epm,0.5);
			HX_STACK_LINE(2852)
			int _g25 = ::Math_obj::ceil((this->maxspawns * 0.7));		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(2852)
			this->maxspawns = _g25;
		}
		HX_STACK_LINE(2854)
		if (((this->RoundType == ::TypeofRound_obj::Table))){
			HX_STACK_LINE(2908)
			hx::MultEq(this->epm,0.5);
			HX_STACK_LINE(2909)
			int _g26 = ::Math_obj::ceil((this->maxspawns * 0.7));		HX_STACK_VAR(_g26,"_g26");
			HX_STACK_LINE(2909)
			this->maxspawns = _g26;
		}
		HX_STACK_LINE(2911)
		::Imposter _g27 = ::Imposter_obj::__new();		HX_STACK_VAR(_g27,"_g27");
		HX_STACK_LINE(2911)
		this->AddToArrayMultiple(enemytypes,_g27,(int)2);
		HX_STACK_LINE(2912)
		if (((this->gamemode == (int)14))){
			HX_STACK_LINE(2914)
			::Imposter _g28 = ::Imposter_obj::__new();		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(2914)
			this->AddToArrayMultiple(enemytypes,_g28,(int)100);
		}
		HX_STACK_LINE(2916)
		if (((this->rank > (int)0))){
			HX_STACK_LINE(2918)
			::Imposter _g29 = ::Imposter_obj::__new();		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(2918)
			this->AddToArrayMultiple(enemytypes,_g29,(int)2);
		}
		HX_STACK_LINE(2920)
		int C = (this->CombinedScoreALL + (this->level * (int)3000));		HX_STACK_VAR(C,"C");
		HX_STACK_LINE(2921)
		int limit = (int)10;		HX_STACK_VAR(limit,"limit");
		HX_STACK_LINE(2922)
		while((true)){
			HX_STACK_LINE(2922)
			if ((!(((C >= (int)35000))))){
				HX_STACK_LINE(2922)
				break;
			}
			HX_STACK_LINE(2924)
			if (((limit > (int)0))){
				HX_STACK_LINE(2926)
				::Imposter _g30 = ::Imposter_obj::__new();		HX_STACK_VAR(_g30,"_g30");
				HX_STACK_LINE(2926)
				this->AddToArrayMultiple(enemytypes,_g30,(int)1);
				HX_STACK_LINE(2927)
				(limit)--;
			}
			HX_STACK_LINE(2929)
			hx::SubEq(C,(int)30000);
		}
		HX_STACK_LINE(2932)
		int tmp = (int)0;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(2933)
		while((true)){
			HX_STACK_LINE(2933)
			if ((!(((tmp < this->maxspawns))))){
				HX_STACK_LINE(2933)
				break;
			}
			HX_STACK_LINE(2935)
			Float _g31 = ::Math_obj::random();		HX_STACK_VAR(_g31,"_g31");
			HX_STACK_LINE(2935)
			Float _g32 = (_g31 * enemytypes->length);		HX_STACK_VAR(_g32,"_g32");
			HX_STACK_LINE(2935)
			int _g33 = ::Math_obj::floor(_g32);		HX_STACK_VAR(_g33,"_g33");
			HX_STACK_LINE(2935)
			::Enemy enemy = enemytypes->__get(_g33).StaticCast< ::Enemy >();		HX_STACK_VAR(enemy,"enemy");
			HX_STACK_LINE(2936)
			enemy->UID = (int)0;
			HX_STACK_LINE(2937)
			this->SpawnList->add(enemy);
			HX_STACK_LINE(2938)
			(tmp)++;
		}
		HX_STACK_LINE(2972)
		this->ept = (this->epm * ::GameView_obj::onetickperminutechance2);
		HX_STACK_LINE(2973)
		int _g34 = ::Math_obj::floor(this->epm);		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(2973)
		int _g35 = (int(_g34) >> int((int)1));		HX_STACK_VAR(_g35,"_g35");
		HX_STACK_LINE(2973)
		Float _g36 = ((this->epm + (int)3) + _g35);		HX_STACK_VAR(_g36,"_g36");
		HX_STACK_LINE(2973)
		Float _g37 = (_g36 * ::GameView_obj::onetickperminutechance2);		HX_STACK_VAR(_g37,"_g37");
		HX_STACK_LINE(2973)
		this->rept = _g37;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameView_obj,CalculateLevelData,(void))

::GameView GameView_obj::_this;

Float GameView_obj::onetickperminutechance;

Float GameView_obj::onetickperminutechance2;


GameView_obj::GameView_obj()
{
}

void GameView_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameView);
	HX_MARK_MEMBER_NAME(text,"text");
	HX_MARK_MEMBER_NAME(TF,"TF");
	HX_MARK_MEMBER_NAME(control,"control");
	HX_MARK_MEMBER_NAME(myplayer,"myplayer");
	HX_MARK_MEMBER_NAME(direction,"direction");
	HX_MARK_MEMBER_NAME(nmax,"nmax");
	HX_MARK_MEMBER_NAME(entities,"entities");
	HX_MARK_MEMBER_NAME(AL,"AL");
	HX_MARK_MEMBER_NAME(frame,"frame");
	HX_MARK_MEMBER_NAME(MSE,"MSE");
	HX_MARK_MEMBER_NAME(music,"music");
	HX_MARK_MEMBER_NAME(musicchannel,"musicchannel");
	HX_MARK_MEMBER_NAME(ltime,"ltime");
	HX_MARK_MEMBER_NAME(missingTime,"missingTime");
	HX_MARK_MEMBER_NAME(SpawnList,"SpawnList");
	HX_MARK_MEMBER_NAME(SpawnTimer,"SpawnTimer");
	HX_MARK_MEMBER_NAME(activeEnemies,"activeEnemies");
	HX_MARK_MEMBER_NAME(activeItems,"activeItems");
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(snd_killenemy,"snd_killenemy");
	HX_MARK_MEMBER_NAME(snd_finalkillenemy,"snd_finalkillenemy");
	HX_MARK_MEMBER_NAME(totalenemies,"totalenemies");
	HX_MARK_MEMBER_NAME(Hoster,"Hoster");
	HX_MARK_MEMBER_NAME(touched,"touched");
	HX_MARK_MEMBER_NAME(Players,"Players");
	HX_MARK_MEMBER_NAME(ControlEvent,"ControlEvent");
	HX_MARK_MEMBER_NAME(Dpad,"Dpad");
	HX_MARK_MEMBER_NAME(BGCRight,"BGCRight");
	HX_MARK_MEMBER_NAME(BGCLeft,"BGCLeft");
	HX_MARK_MEMBER_NAME(BGCBottom,"BGCBottom");
	HX_MARK_MEMBER_NAME(powblock,"powblock");
	HX_MARK_MEMBER_NAME(roundstarted,"roundstarted");
	HX_MARK_MEMBER_NAME(maxspawns,"maxspawns");
	HX_MARK_MEMBER_NAME(spawns,"spawns");
	HX_MARK_MEMBER_NAME(playerspick,"playerspick");
	HX_MARK_MEMBER_NAME(online,"online");
	HX_MARK_MEMBER_NAME(gameover,"gameover");
	HX_MARK_MEMBER_NAME(playername,"playername");
	HX_MARK_MEMBER_NAME(scoreboard,"scoreboard");
	HX_MARK_MEMBER_NAME(Room,"Room");
	HX_MARK_MEMBER_NAME(status,"status");
	HX_MARK_MEMBER_NAME(ufos,"ufos");
	HX_MARK_MEMBER_NAME(HighScore,"HighScore");
	HX_MARK_MEMBER_NAME(Background,"Background");
	HX_MARK_MEMBER_NAME(syncdelay,"syncdelay");
	HX_MARK_MEMBER_NAME(gamemode,"gamemode");
	HX_MARK_MEMBER_NAME(RoundType,"RoundType");
	HX_MARK_MEMBER_NAME(epm,"epm");
	HX_MARK_MEMBER_NAME(ept,"ept");
	HX_MARK_MEMBER_NAME(rept,"rept");
	HX_MARK_MEMBER_NAME(PointsToLife,"PointsToLife");
	HX_MARK_MEMBER_NAME(CombinedScore,"CombinedScore");
	HX_MARK_MEMBER_NAME(CombinedScoreALL,"CombinedScoreALL");
	HX_MARK_MEMBER_NAME(Obstacles,"Obstacles");
	HX_MARK_MEMBER_NAME(platformformation,"platformformation");
	HX_MARK_MEMBER_NAME(currentformation,"currentformation");
	HX_MARK_MEMBER_NAME(spawnedChar,"spawnedChar");
	HX_MARK_MEMBER_NAME(rank,"rank");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GameView_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(text,"text");
	HX_VISIT_MEMBER_NAME(TF,"TF");
	HX_VISIT_MEMBER_NAME(control,"control");
	HX_VISIT_MEMBER_NAME(myplayer,"myplayer");
	HX_VISIT_MEMBER_NAME(direction,"direction");
	HX_VISIT_MEMBER_NAME(nmax,"nmax");
	HX_VISIT_MEMBER_NAME(entities,"entities");
	HX_VISIT_MEMBER_NAME(AL,"AL");
	HX_VISIT_MEMBER_NAME(frame,"frame");
	HX_VISIT_MEMBER_NAME(MSE,"MSE");
	HX_VISIT_MEMBER_NAME(music,"music");
	HX_VISIT_MEMBER_NAME(musicchannel,"musicchannel");
	HX_VISIT_MEMBER_NAME(ltime,"ltime");
	HX_VISIT_MEMBER_NAME(missingTime,"missingTime");
	HX_VISIT_MEMBER_NAME(SpawnList,"SpawnList");
	HX_VISIT_MEMBER_NAME(SpawnTimer,"SpawnTimer");
	HX_VISIT_MEMBER_NAME(activeEnemies,"activeEnemies");
	HX_VISIT_MEMBER_NAME(activeItems,"activeItems");
	HX_VISIT_MEMBER_NAME(level,"level");
	HX_VISIT_MEMBER_NAME(snd_killenemy,"snd_killenemy");
	HX_VISIT_MEMBER_NAME(snd_finalkillenemy,"snd_finalkillenemy");
	HX_VISIT_MEMBER_NAME(totalenemies,"totalenemies");
	HX_VISIT_MEMBER_NAME(Hoster,"Hoster");
	HX_VISIT_MEMBER_NAME(touched,"touched");
	HX_VISIT_MEMBER_NAME(Players,"Players");
	HX_VISIT_MEMBER_NAME(ControlEvent,"ControlEvent");
	HX_VISIT_MEMBER_NAME(Dpad,"Dpad");
	HX_VISIT_MEMBER_NAME(BGCRight,"BGCRight");
	HX_VISIT_MEMBER_NAME(BGCLeft,"BGCLeft");
	HX_VISIT_MEMBER_NAME(BGCBottom,"BGCBottom");
	HX_VISIT_MEMBER_NAME(powblock,"powblock");
	HX_VISIT_MEMBER_NAME(roundstarted,"roundstarted");
	HX_VISIT_MEMBER_NAME(maxspawns,"maxspawns");
	HX_VISIT_MEMBER_NAME(spawns,"spawns");
	HX_VISIT_MEMBER_NAME(playerspick,"playerspick");
	HX_VISIT_MEMBER_NAME(online,"online");
	HX_VISIT_MEMBER_NAME(gameover,"gameover");
	HX_VISIT_MEMBER_NAME(playername,"playername");
	HX_VISIT_MEMBER_NAME(scoreboard,"scoreboard");
	HX_VISIT_MEMBER_NAME(Room,"Room");
	HX_VISIT_MEMBER_NAME(status,"status");
	HX_VISIT_MEMBER_NAME(ufos,"ufos");
	HX_VISIT_MEMBER_NAME(HighScore,"HighScore");
	HX_VISIT_MEMBER_NAME(Background,"Background");
	HX_VISIT_MEMBER_NAME(syncdelay,"syncdelay");
	HX_VISIT_MEMBER_NAME(gamemode,"gamemode");
	HX_VISIT_MEMBER_NAME(RoundType,"RoundType");
	HX_VISIT_MEMBER_NAME(epm,"epm");
	HX_VISIT_MEMBER_NAME(ept,"ept");
	HX_VISIT_MEMBER_NAME(rept,"rept");
	HX_VISIT_MEMBER_NAME(PointsToLife,"PointsToLife");
	HX_VISIT_MEMBER_NAME(CombinedScore,"CombinedScore");
	HX_VISIT_MEMBER_NAME(CombinedScoreALL,"CombinedScoreALL");
	HX_VISIT_MEMBER_NAME(Obstacles,"Obstacles");
	HX_VISIT_MEMBER_NAME(platformformation,"platformformation");
	HX_VISIT_MEMBER_NAME(currentformation,"currentformation");
	HX_VISIT_MEMBER_NAME(spawnedChar,"spawnedChar");
	HX_VISIT_MEMBER_NAME(rank,"rank");
	::openfl::_v2::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic GameView_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"TF") ) { return TF; }
		if (HX_FIELD_EQ(inName,"AL") ) { return AL; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"MSE") ) { return MSE; }
		if (HX_FIELD_EQ(inName,"epm") ) { return epm; }
		if (HX_FIELD_EQ(inName,"ept") ) { return ept; }
		if (HX_FIELD_EQ(inName,"end") ) { return end_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { return text; }
		if (HX_FIELD_EQ(inName,"nmax") ) { return nmax; }
		if (HX_FIELD_EQ(inName,"Dpad") ) { return Dpad; }
		if (HX_FIELD_EQ(inName,"Room") ) { return Room; }
		if (HX_FIELD_EQ(inName,"ufos") ) { return ufos; }
		if (HX_FIELD_EQ(inName,"rept") ) { return rept; }
		if (HX_FIELD_EQ(inName,"rank") ) { return rank; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_this") ) { return _this; }
		if (HX_FIELD_EQ(inName,"frame") ) { return frame; }
		if (HX_FIELD_EQ(inName,"music") ) { return music; }
		if (HX_FIELD_EQ(inName,"ltime") ) { return ltime; }
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		if (HX_FIELD_EQ(inName,"todyn") ) { return todyn_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Hoster") ) { return Hoster; }
		if (HX_FIELD_EQ(inName,"spawns") ) { return spawns; }
		if (HX_FIELD_EQ(inName,"online") ) { return online; }
		if (HX_FIELD_EQ(inName,"status") ) { return status; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"control") ) { return control; }
		if (HX_FIELD_EQ(inName,"touched") ) { return touched; }
		if (HX_FIELD_EQ(inName,"Players") ) { return Players; }
		if (HX_FIELD_EQ(inName,"BGCLeft") ) { return BGCLeft; }
		if (HX_FIELD_EQ(inName,"SendGap") ) { return SendGap_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"myplayer") ) { return myplayer; }
		if (HX_FIELD_EQ(inName,"entities") ) { return entities; }
		if (HX_FIELD_EQ(inName,"BGCRight") ) { return BGCRight; }
		if (HX_FIELD_EQ(inName,"powblock") ) { return powblock; }
		if (HX_FIELD_EQ(inName,"gameover") ) { return gameover; }
		if (HX_FIELD_EQ(inName,"gamemode") ) { return gamemode; }
		if (HX_FIELD_EQ(inName,"AddEnemy") ) { return AddEnemy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"direction") ) { return direction; }
		if (HX_FIELD_EQ(inName,"SpawnList") ) { return SpawnList; }
		if (HX_FIELD_EQ(inName,"BGCBottom") ) { return BGCBottom; }
		if (HX_FIELD_EQ(inName,"maxspawns") ) { return maxspawns; }
		if (HX_FIELD_EQ(inName,"HighScore") ) { return HighScore; }
		if (HX_FIELD_EQ(inName,"syncdelay") ) { return syncdelay; }
		if (HX_FIELD_EQ(inName,"RoundType") ) { return RoundType; }
		if (HX_FIELD_EQ(inName,"Obstacles") ) { return Obstacles; }
		if (HX_FIELD_EQ(inName,"PlayMusic") ) { return PlayMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"GetPlayer") ) { return GetPlayer_dyn(); }
		if (HX_FIELD_EQ(inName,"AddPlayer") ) { return AddPlayer_dyn(); }
		if (HX_FIELD_EQ(inName,"AddObject") ) { return AddObject_dyn(); }
		if (HX_FIELD_EQ(inName,"SendEvent") ) { return SendEvent_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"SpawnTimer") ) { return SpawnTimer; }
		if (HX_FIELD_EQ(inName,"playername") ) { return playername; }
		if (HX_FIELD_EQ(inName,"scoreboard") ) { return scoreboard; }
		if (HX_FIELD_EQ(inName,"Background") ) { return Background; }
		if (HX_FIELD_EQ(inName,"on_mouseup") ) { return on_mouseup_dyn(); }
		if (HX_FIELD_EQ(inName,"ismyplayer") ) { return ismyplayer_dyn(); }
		if (HX_FIELD_EQ(inName,"SendStatus") ) { return SendStatus_dyn(); }
		if (HX_FIELD_EQ(inName,"updategame") ) { return updategame_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"missingTime") ) { return missingTime; }
		if (HX_FIELD_EQ(inName,"activeItems") ) { return activeItems; }
		if (HX_FIELD_EQ(inName,"playerspick") ) { return playerspick; }
		if (HX_FIELD_EQ(inName,"spawnedChar") ) { return spawnedChar; }
		if (HX_FIELD_EQ(inName,"on_touchend") ) { return on_touchend_dyn(); }
		if (HX_FIELD_EQ(inName,"RemoveEnemy") ) { return RemoveEnemy_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"musicchannel") ) { return musicchannel; }
		if (HX_FIELD_EQ(inName,"totalenemies") ) { return totalenemies; }
		if (HX_FIELD_EQ(inName,"ControlEvent") ) { return ControlEvent; }
		if (HX_FIELD_EQ(inName,"roundstarted") ) { return roundstarted; }
		if (HX_FIELD_EQ(inName,"PointsToLife") ) { return PointsToLife; }
		if (HX_FIELD_EQ(inName,"setformation") ) { return setformation_dyn(); }
		if (HX_FIELD_EQ(inName,"on_mousedown") ) { return on_mousedown_dyn(); }
		if (HX_FIELD_EQ(inName,"GetNetworkID") ) { return GetNetworkID_dyn(); }
		if (HX_FIELD_EQ(inName,"RemovePlayer") ) { return RemovePlayer_dyn(); }
		if (HX_FIELD_EQ(inName,"RemoveObject") ) { return RemoveObject_dyn(); }
		if (HX_FIELD_EQ(inName,"ProcessEvent") ) { return ProcessEvent_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeEnemies") ) { return activeEnemies; }
		if (HX_FIELD_EQ(inName,"snd_killenemy") ) { return snd_killenemy; }
		if (HX_FIELD_EQ(inName,"CombinedScore") ) { return CombinedScore; }
		if (HX_FIELD_EQ(inName,"spawnplatform") ) { return spawnplatform_dyn(); }
		if (HX_FIELD_EQ(inName,"on_touchbegin") ) { return on_touchbegin_dyn(); }
		if (HX_FIELD_EQ(inName,"AddEntityItem") ) { return AddEntityItem_dyn(); }
		if (HX_FIELD_EQ(inName,"stage_onKeyUp") ) { return stage_onKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"EntityFromUID") ) { return EntityFromUID_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stage_onKeyDown") ) { return stage_onKeyDown_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"CombinedScoreALL") ) { return CombinedScoreALL; }
		if (HX_FIELD_EQ(inName,"currentformation") ) { return currentformation; }
		if (HX_FIELD_EQ(inName,"RemoveEntityItem") ) { return RemoveEntityItem_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"platformformation") ) { return platformformation; }
		if (HX_FIELD_EQ(inName,"setholeinplatform") ) { return setholeinplatform_dyn(); }
		if (HX_FIELD_EQ(inName,"AddEntityFromData") ) { return AddEntityFromData_dyn(); }
		if (HX_FIELD_EQ(inName,"this_onEnterFrame") ) { return this_onEnterFrame_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"snd_finalkillenemy") ) { return snd_finalkillenemy; }
		if (HX_FIELD_EQ(inName,"AddToArrayMultiple") ) { return AddToArrayMultiple_dyn(); }
		if (HX_FIELD_EQ(inName,"CalculateLevelData") ) { return CalculateLevelData_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"SpawnEntityFromData") ) { return SpawnEntityFromData_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"CollisionDetectPoint") ) { return CollisionDetectPoint_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"setplatformasplatform") ) { return setplatformasplatform_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"onetickperminutechance") ) { return onetickperminutechance; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"onetickperminutechance2") ) { return onetickperminutechance2; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"CollisionDetectPointItem") ) { return CollisionDetectPointItem_dyn(); }
		if (HX_FIELD_EQ(inName,"CollisionDetectTouchItem") ) { return CollisionDetectTouchItem_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"CollisionDetectPointEnemy") ) { return CollisionDetectPointEnemy_dyn(); }
		if (HX_FIELD_EQ(inName,"CollisionDetectTouchEnemy") ) { return CollisionDetectTouchEnemy_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"CollisionDetectPointPlayer") ) { return CollisionDetectPointPlayer_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"CollisionDetectPointDangerous") ) { return CollisionDetectPointDangerous_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameView_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"TF") ) { TF=inValue.Cast< ::openfl::_v2::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"AL") ) { AL=inValue.Cast< ::Animationloader >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"MSE") ) { MSE=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"epm") ) { epm=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ept") ) { ept=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"text") ) { text=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmax") ) { nmax=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Dpad") ) { Dpad=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Room") ) { Room=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ufos") ) { ufos=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rept") ) { rept=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rank") ) { rank=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_this") ) { _this=inValue.Cast< ::GameView >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frame") ) { frame=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"music") ) { music=inValue.Cast< ::openfl::_v2::media::Sound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ltime") ) { ltime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Hoster") ) { Hoster=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"spawns") ) { spawns=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"online") ) { online=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"status") ) { status=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"control") ) { control=inValue.Cast< Array< bool > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"touched") ) { touched=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Players") ) { Players=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BGCLeft") ) { BGCLeft=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"myplayer") ) { myplayer=inValue.Cast< ::Player >(); return inValue; }
		if (HX_FIELD_EQ(inName,"entities") ) { entities=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BGCRight") ) { BGCRight=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"powblock") ) { powblock=inValue.Cast< ::PowBlock >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameover") ) { gameover=inValue.Cast< ::openfl::_v2::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gamemode") ) { gamemode=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"direction") ) { direction=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SpawnList") ) { SpawnList=inValue.Cast< ::List >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BGCBottom") ) { BGCBottom=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxspawns") ) { maxspawns=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HighScore") ) { HighScore=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"syncdelay") ) { syncdelay=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RoundType") ) { RoundType=inValue.Cast< ::TypeofRound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Obstacles") ) { Obstacles=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"SpawnTimer") ) { SpawnTimer=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"playername") ) { playername=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scoreboard") ) { scoreboard=inValue.Cast< ::openfl::_v2::text::TextField >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Background") ) { Background=inValue.Cast< ::openfl::_v2::display::Bitmap >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"missingTime") ) { missingTime=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"activeItems") ) { activeItems=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"playerspick") ) { playerspick=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"spawnedChar") ) { spawnedChar=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"musicchannel") ) { musicchannel=inValue.Cast< ::openfl::_v2::media::SoundChannel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"totalenemies") ) { totalenemies=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ControlEvent") ) { ControlEvent=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"roundstarted") ) { roundstarted=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PointsToLife") ) { PointsToLife=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeEnemies") ) { activeEnemies=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"snd_killenemy") ) { snd_killenemy=inValue.Cast< ::openfl::_v2::media::Sound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CombinedScore") ) { CombinedScore=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"CombinedScoreALL") ) { CombinedScoreALL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentformation") ) { currentformation=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"platformformation") ) { platformformation=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"snd_finalkillenemy") ) { snd_finalkillenemy=inValue.Cast< ::openfl::_v2::media::Sound >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"onetickperminutechance") ) { onetickperminutechance=inValue.Cast< Float >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"onetickperminutechance2") ) { onetickperminutechance2=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameView_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("text"));
	outFields->push(HX_CSTRING("TF"));
	outFields->push(HX_CSTRING("control"));
	outFields->push(HX_CSTRING("myplayer"));
	outFields->push(HX_CSTRING("direction"));
	outFields->push(HX_CSTRING("nmax"));
	outFields->push(HX_CSTRING("entities"));
	outFields->push(HX_CSTRING("AL"));
	outFields->push(HX_CSTRING("frame"));
	outFields->push(HX_CSTRING("MSE"));
	outFields->push(HX_CSTRING("music"));
	outFields->push(HX_CSTRING("musicchannel"));
	outFields->push(HX_CSTRING("ltime"));
	outFields->push(HX_CSTRING("missingTime"));
	outFields->push(HX_CSTRING("SpawnList"));
	outFields->push(HX_CSTRING("SpawnTimer"));
	outFields->push(HX_CSTRING("activeEnemies"));
	outFields->push(HX_CSTRING("activeItems"));
	outFields->push(HX_CSTRING("level"));
	outFields->push(HX_CSTRING("snd_killenemy"));
	outFields->push(HX_CSTRING("snd_finalkillenemy"));
	outFields->push(HX_CSTRING("totalenemies"));
	outFields->push(HX_CSTRING("Hoster"));
	outFields->push(HX_CSTRING("touched"));
	outFields->push(HX_CSTRING("Players"));
	outFields->push(HX_CSTRING("ControlEvent"));
	outFields->push(HX_CSTRING("Dpad"));
	outFields->push(HX_CSTRING("BGCRight"));
	outFields->push(HX_CSTRING("BGCLeft"));
	outFields->push(HX_CSTRING("BGCBottom"));
	outFields->push(HX_CSTRING("powblock"));
	outFields->push(HX_CSTRING("roundstarted"));
	outFields->push(HX_CSTRING("maxspawns"));
	outFields->push(HX_CSTRING("spawns"));
	outFields->push(HX_CSTRING("playerspick"));
	outFields->push(HX_CSTRING("online"));
	outFields->push(HX_CSTRING("gameover"));
	outFields->push(HX_CSTRING("playername"));
	outFields->push(HX_CSTRING("scoreboard"));
	outFields->push(HX_CSTRING("Room"));
	outFields->push(HX_CSTRING("status"));
	outFields->push(HX_CSTRING("ufos"));
	outFields->push(HX_CSTRING("HighScore"));
	outFields->push(HX_CSTRING("Background"));
	outFields->push(HX_CSTRING("syncdelay"));
	outFields->push(HX_CSTRING("gamemode"));
	outFields->push(HX_CSTRING("RoundType"));
	outFields->push(HX_CSTRING("epm"));
	outFields->push(HX_CSTRING("ept"));
	outFields->push(HX_CSTRING("rept"));
	outFields->push(HX_CSTRING("PointsToLife"));
	outFields->push(HX_CSTRING("CombinedScore"));
	outFields->push(HX_CSTRING("CombinedScoreALL"));
	outFields->push(HX_CSTRING("Obstacles"));
	outFields->push(HX_CSTRING("platformformation"));
	outFields->push(HX_CSTRING("currentformation"));
	outFields->push(HX_CSTRING("spawnedChar"));
	outFields->push(HX_CSTRING("rank"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_this"),
	HX_CSTRING("onetickperminutechance"),
	HX_CSTRING("onetickperminutechance2"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(GameView_obj,text),HX_CSTRING("text")},
	{hx::fsObject /*::openfl::_v2::text::TextField*/ ,(int)offsetof(GameView_obj,TF),HX_CSTRING("TF")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(GameView_obj,control),HX_CSTRING("control")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(GameView_obj,myplayer),HX_CSTRING("myplayer")},
	{hx::fsInt,(int)offsetof(GameView_obj,direction),HX_CSTRING("direction")},
	{hx::fsInt,(int)offsetof(GameView_obj,nmax),HX_CSTRING("nmax")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(GameView_obj,entities),HX_CSTRING("entities")},
	{hx::fsObject /*::Animationloader*/ ,(int)offsetof(GameView_obj,AL),HX_CSTRING("AL")},
	{hx::fsInt,(int)offsetof(GameView_obj,frame),HX_CSTRING("frame")},
	{hx::fsBool,(int)offsetof(GameView_obj,MSE),HX_CSTRING("MSE")},
	{hx::fsObject /*::openfl::_v2::media::Sound*/ ,(int)offsetof(GameView_obj,music),HX_CSTRING("music")},
	{hx::fsObject /*::openfl::_v2::media::SoundChannel*/ ,(int)offsetof(GameView_obj,musicchannel),HX_CSTRING("musicchannel")},
	{hx::fsFloat,(int)offsetof(GameView_obj,ltime),HX_CSTRING("ltime")},
	{hx::fsFloat,(int)offsetof(GameView_obj,missingTime),HX_CSTRING("missingTime")},
	{hx::fsObject /*::List*/ ,(int)offsetof(GameView_obj,SpawnList),HX_CSTRING("SpawnList")},
	{hx::fsInt,(int)offsetof(GameView_obj,SpawnTimer),HX_CSTRING("SpawnTimer")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(GameView_obj,activeEnemies),HX_CSTRING("activeEnemies")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(GameView_obj,activeItems),HX_CSTRING("activeItems")},
	{hx::fsInt,(int)offsetof(GameView_obj,level),HX_CSTRING("level")},
	{hx::fsObject /*::openfl::_v2::media::Sound*/ ,(int)offsetof(GameView_obj,snd_killenemy),HX_CSTRING("snd_killenemy")},
	{hx::fsObject /*::openfl::_v2::media::Sound*/ ,(int)offsetof(GameView_obj,snd_finalkillenemy),HX_CSTRING("snd_finalkillenemy")},
	{hx::fsInt,(int)offsetof(GameView_obj,totalenemies),HX_CSTRING("totalenemies")},
	{hx::fsBool,(int)offsetof(GameView_obj,Hoster),HX_CSTRING("Hoster")},
	{hx::fsBool,(int)offsetof(GameView_obj,touched),HX_CSTRING("touched")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(GameView_obj,Players),HX_CSTRING("Players")},
	{hx::fsBool,(int)offsetof(GameView_obj,ControlEvent),HX_CSTRING("ControlEvent")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(GameView_obj,Dpad),HX_CSTRING("Dpad")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(GameView_obj,BGCRight),HX_CSTRING("BGCRight")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(GameView_obj,BGCLeft),HX_CSTRING("BGCLeft")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(GameView_obj,BGCBottom),HX_CSTRING("BGCBottom")},
	{hx::fsObject /*::PowBlock*/ ,(int)offsetof(GameView_obj,powblock),HX_CSTRING("powblock")},
	{hx::fsBool,(int)offsetof(GameView_obj,roundstarted),HX_CSTRING("roundstarted")},
	{hx::fsInt,(int)offsetof(GameView_obj,maxspawns),HX_CSTRING("maxspawns")},
	{hx::fsInt,(int)offsetof(GameView_obj,spawns),HX_CSTRING("spawns")},
	{hx::fsString,(int)offsetof(GameView_obj,playerspick),HX_CSTRING("playerspick")},
	{hx::fsBool,(int)offsetof(GameView_obj,online),HX_CSTRING("online")},
	{hx::fsObject /*::openfl::_v2::text::TextField*/ ,(int)offsetof(GameView_obj,gameover),HX_CSTRING("gameover")},
	{hx::fsString,(int)offsetof(GameView_obj,playername),HX_CSTRING("playername")},
	{hx::fsObject /*::openfl::_v2::text::TextField*/ ,(int)offsetof(GameView_obj,scoreboard),HX_CSTRING("scoreboard")},
	{hx::fsString,(int)offsetof(GameView_obj,Room),HX_CSTRING("Room")},
	{hx::fsString,(int)offsetof(GameView_obj,status),HX_CSTRING("status")},
	{hx::fsInt,(int)offsetof(GameView_obj,ufos),HX_CSTRING("ufos")},
	{hx::fsInt,(int)offsetof(GameView_obj,HighScore),HX_CSTRING("HighScore")},
	{hx::fsObject /*::openfl::_v2::display::Bitmap*/ ,(int)offsetof(GameView_obj,Background),HX_CSTRING("Background")},
	{hx::fsInt,(int)offsetof(GameView_obj,syncdelay),HX_CSTRING("syncdelay")},
	{hx::fsInt,(int)offsetof(GameView_obj,gamemode),HX_CSTRING("gamemode")},
	{hx::fsObject /*::TypeofRound*/ ,(int)offsetof(GameView_obj,RoundType),HX_CSTRING("RoundType")},
	{hx::fsFloat,(int)offsetof(GameView_obj,epm),HX_CSTRING("epm")},
	{hx::fsFloat,(int)offsetof(GameView_obj,ept),HX_CSTRING("ept")},
	{hx::fsFloat,(int)offsetof(GameView_obj,rept),HX_CSTRING("rept")},
	{hx::fsInt,(int)offsetof(GameView_obj,PointsToLife),HX_CSTRING("PointsToLife")},
	{hx::fsInt,(int)offsetof(GameView_obj,CombinedScore),HX_CSTRING("CombinedScore")},
	{hx::fsInt,(int)offsetof(GameView_obj,CombinedScoreALL),HX_CSTRING("CombinedScoreALL")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(GameView_obj,Obstacles),HX_CSTRING("Obstacles")},
	{hx::fsInt,(int)offsetof(GameView_obj,platformformation),HX_CSTRING("platformformation")},
	{hx::fsInt,(int)offsetof(GameView_obj,currentformation),HX_CSTRING("currentformation")},
	{hx::fsBool,(int)offsetof(GameView_obj,spawnedChar),HX_CSTRING("spawnedChar")},
	{hx::fsInt,(int)offsetof(GameView_obj,rank),HX_CSTRING("rank")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("text"),
	HX_CSTRING("TF"),
	HX_CSTRING("control"),
	HX_CSTRING("myplayer"),
	HX_CSTRING("direction"),
	HX_CSTRING("nmax"),
	HX_CSTRING("entities"),
	HX_CSTRING("AL"),
	HX_CSTRING("frame"),
	HX_CSTRING("MSE"),
	HX_CSTRING("music"),
	HX_CSTRING("musicchannel"),
	HX_CSTRING("ltime"),
	HX_CSTRING("missingTime"),
	HX_CSTRING("SpawnList"),
	HX_CSTRING("SpawnTimer"),
	HX_CSTRING("activeEnemies"),
	HX_CSTRING("activeItems"),
	HX_CSTRING("level"),
	HX_CSTRING("snd_killenemy"),
	HX_CSTRING("snd_finalkillenemy"),
	HX_CSTRING("totalenemies"),
	HX_CSTRING("Hoster"),
	HX_CSTRING("touched"),
	HX_CSTRING("Players"),
	HX_CSTRING("ControlEvent"),
	HX_CSTRING("Dpad"),
	HX_CSTRING("BGCRight"),
	HX_CSTRING("BGCLeft"),
	HX_CSTRING("BGCBottom"),
	HX_CSTRING("powblock"),
	HX_CSTRING("roundstarted"),
	HX_CSTRING("maxspawns"),
	HX_CSTRING("spawns"),
	HX_CSTRING("playerspick"),
	HX_CSTRING("online"),
	HX_CSTRING("gameover"),
	HX_CSTRING("playername"),
	HX_CSTRING("scoreboard"),
	HX_CSTRING("Room"),
	HX_CSTRING("status"),
	HX_CSTRING("ufos"),
	HX_CSTRING("HighScore"),
	HX_CSTRING("Background"),
	HX_CSTRING("syncdelay"),
	HX_CSTRING("gamemode"),
	HX_CSTRING("RoundType"),
	HX_CSTRING("epm"),
	HX_CSTRING("ept"),
	HX_CSTRING("rept"),
	HX_CSTRING("PointsToLife"),
	HX_CSTRING("CombinedScore"),
	HX_CSTRING("CombinedScoreALL"),
	HX_CSTRING("Obstacles"),
	HX_CSTRING("platformformation"),
	HX_CSTRING("currentformation"),
	HX_CSTRING("spawnedChar"),
	HX_CSTRING("rank"),
	HX_CSTRING("end"),
	HX_CSTRING("start"),
	HX_CSTRING("setformation"),
	HX_CSTRING("spawnplatform"),
	HX_CSTRING("setholeinplatform"),
	HX_CSTRING("setplatformasplatform"),
	HX_CSTRING("on_touchend"),
	HX_CSTRING("on_touchbegin"),
	HX_CSTRING("on_mousedown"),
	HX_CSTRING("on_mouseup"),
	HX_CSTRING("GetNetworkID"),
	HX_CSTRING("PlayMusic"),
	HX_CSTRING("GetPlayer"),
	HX_CSTRING("AddPlayer"),
	HX_CSTRING("SendGap"),
	HX_CSTRING("RemovePlayer"),
	HX_CSTRING("AddEntityItem"),
	HX_CSTRING("AddEnemy"),
	HX_CSTRING("AddObject"),
	HX_CSTRING("RemoveEntityItem"),
	HX_CSTRING("RemoveEnemy"),
	HX_CSTRING("RemoveObject"),
	HX_CSTRING("CollisionDetectPoint"),
	HX_CSTRING("CollisionDetectPointItem"),
	HX_CSTRING("CollisionDetectPointPlayer"),
	HX_CSTRING("CollisionDetectPointEnemy"),
	HX_CSTRING("CollisionDetectPointDangerous"),
	HX_CSTRING("CollisionDetectTouchEnemy"),
	HX_CSTRING("CollisionDetectTouchItem"),
	HX_CSTRING("ismyplayer"),
	HX_CSTRING("SendEvent"),
	HX_CSTRING("ProcessEvent"),
	HX_CSTRING("stage_onKeyDown"),
	HX_CSTRING("stage_onKeyUp"),
	HX_CSTRING("todyn"),
	HX_CSTRING("AddEntityFromData"),
	HX_CSTRING("SpawnEntityFromData"),
	HX_CSTRING("EntityFromUID"),
	HX_CSTRING("this_onEnterFrame"),
	HX_CSTRING("SendStatus"),
	HX_CSTRING("updategame"),
	HX_CSTRING("AddToArrayMultiple"),
	HX_CSTRING("CalculateLevelData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameView_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(GameView_obj::_this,"_this");
	HX_MARK_MEMBER_NAME(GameView_obj::onetickperminutechance,"onetickperminutechance");
	HX_MARK_MEMBER_NAME(GameView_obj::onetickperminutechance2,"onetickperminutechance2");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameView_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GameView_obj::_this,"_this");
	HX_VISIT_MEMBER_NAME(GameView_obj::onetickperminutechance,"onetickperminutechance");
	HX_VISIT_MEMBER_NAME(GameView_obj::onetickperminutechance2,"onetickperminutechance2");
};

#endif

Class GameView_obj::__mClass;

void GameView_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("GameView"), hx::TCanCast< GameView_obj> ,sStaticFields,sMemberFields,
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

void GameView_obj::__boot()
{
	onetickperminutechance= 0.00055555555555555556;
	onetickperminutechance2= (::GameView_obj::onetickperminutechance * (int)2);
}

