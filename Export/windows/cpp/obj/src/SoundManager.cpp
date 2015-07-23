#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_SoundManager
#include <SoundManager.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_openfl__v2_Assets
#include <openfl/_v2/Assets.h>
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
#ifndef INCLUDED_openfl__v2_media_Sound
#include <openfl/_v2/media/Sound.h>
#endif
#ifndef INCLUDED_openfl__v2_media_SoundChannel
#include <openfl/_v2/media/SoundChannel.h>
#endif
#ifndef INCLUDED_openfl_media_SoundTransform
#include <openfl/media/SoundTransform.h>
#endif

Void SoundManager_obj::__construct()
{
HX_STACK_FRAME("SoundManager","new",0x9cf97970,"SoundManager.new","SoundManager.hx",23,0xe9be8400)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(24)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	this->channels = _g;
	HX_STACK_LINE(25)
	::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(25)
	this->Dictionary = _g1;
	HX_STACK_LINE(26)
	this->muted = false;
	HX_STACK_LINE(27)
	::SoundManager_obj::_this = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(28)
	this->sndvol = 1.0;
	HX_STACK_LINE(29)
	this->musicvol = 1.0;
}
;
	return null();
}

//SoundManager_obj::~SoundManager_obj() { }

Dynamic SoundManager_obj::__CreateEmpty() { return  new SoundManager_obj; }
hx::ObjectPtr< SoundManager_obj > SoundManager_obj::__new()
{  hx::ObjectPtr< SoundManager_obj > result = new SoundManager_obj();
	result->__construct();
	return result;}

Dynamic SoundManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SoundManager_obj > result = new SoundManager_obj();
	result->__construct();
	return result;}

::openfl::_v2::media::Sound SoundManager_obj::GetSound( ::String path){
	HX_STACK_FRAME("SoundManager","GetSound",0xdd40d569,"SoundManager.GetSound","SoundManager.hx",36,0xe9be8400)
	HX_STACK_THIS(this)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(36)
	if ((this->Dictionary->exists(path))){
		HX_STACK_LINE(38)
		return this->Dictionary->get(path);
	}
	else{
		HX_STACK_LINE(50)
		::openfl::_v2::media::Sound S = ::openfl::_v2::Assets_obj::getSound(((HX_CSTRING("assets/Audio/Ogg/") + path) + HX_CSTRING(".OGG")),null());		HX_STACK_VAR(S,"S");
		HX_STACK_LINE(53)
		this->Dictionary->set(path,S);
		HX_STACK_LINE(54)
		return S;
	}
	HX_STACK_LINE(36)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,GetSound,return )

::openfl::_v2::media::SoundChannel SoundManager_obj::_PlayJingle( ::String path){
	HX_STACK_FRAME("SoundManager","_PlayJingle",0x66f6c294,"SoundManager._PlayJingle","SoundManager.hx",62,0xe9be8400)
	HX_STACK_THIS(this)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(63)
	if (((this->music != null()))){
		HX_STACK_LINE(70)
		::openfl::media::SoundTransform _g = ::openfl::media::SoundTransform_obj::__new((int)0,(int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(70)
		this->music->set_soundTransform(_g);
	}
	HX_STACK_LINE(72)
	::openfl::_v2::media::SoundChannel S = this->_Play(path,(int)0,(int)0,this->musicvol);		HX_STACK_VAR(S,"S");
	HX_STACK_LINE(73)
	S->addEventListener(::openfl::_v2::events::Event_obj::SOUND_COMPLETE,this->jingleend_dyn(),null(),null(),null());
	HX_STACK_LINE(74)
	return S;
}


HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,_PlayJingle,return )

::openfl::_v2::media::SoundChannel SoundManager_obj::_PlayMusic( ::String path){
	HX_STACK_FRAME("SoundManager","_PlayMusic",0x812cf2a2,"SoundManager._PlayMusic","SoundManager.hx",103,0xe9be8400)
	HX_STACK_THIS(this)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(103)
	if (((this->_song != path))){
		HX_STACK_LINE(105)
		if (((this->music != null()))){
			HX_STACK_LINE(107)
			this->music->stop();
			HX_STACK_LINE(108)
			this->music = null();
		}
		HX_STACK_LINE(110)
		this->_songposition = -1.0;
		HX_STACK_LINE(111)
		::openfl::_v2::media::SoundChannel _g = this->_Play(path,(int)0,(int)999999999,this->musicvol);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(111)
		this->music = _g;
		HX_STACK_LINE(112)
		this->_song = path;
		HX_STACK_LINE(113)
		return this->music;
	}
	else{
		HX_STACK_LINE(117)
		return null();
	}
	HX_STACK_LINE(103)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,_PlayMusic,return )

::openfl::_v2::media::SoundChannel SoundManager_obj::_Play( ::String path,hx::Null< Float >  __o_position,hx::Null< int >  __o_Loops,hx::Null< Float >  __o_volume){
Float position = __o_position.Default(0.0);
int Loops = __o_Loops.Default(0);
Float volume = __o_volume.Default(-1000);
	HX_STACK_FRAME("SoundManager","_Play",0x38728303,"SoundManager._Play","SoundManager.hx",120,0xe9be8400)
	HX_STACK_THIS(this)
	HX_STACK_ARG(path,"path")
	HX_STACK_ARG(position,"position")
	HX_STACK_ARG(Loops,"Loops")
	HX_STACK_ARG(volume,"volume")
{
		HX_STACK_LINE(130)
		::openfl::_v2::media::Sound S = this->GetSound(path);		HX_STACK_VAR(S,"S");
		HX_STACK_LINE(131)
		if (((volume == (int)-1000))){
			HX_STACK_LINE(133)
			volume = this->sndvol;
		}
		HX_STACK_LINE(135)
		if (((S != null()))){
			HX_STACK_LINE(137)
			::openfl::media::SoundTransform T = ::openfl::media::SoundTransform_obj::__new(volume,(int)0);		HX_STACK_VAR(T,"T");
			HX_STACK_LINE(138)
			if ((this->muted)){
				HX_STACK_LINE(140)
				T->volume = (int)0;
			}
			else{
			}
			HX_STACK_LINE(145)
			::openfl::_v2::media::SoundChannel C = S->play(position,Loops,T);		HX_STACK_VAR(C,"C");
			HX_STACK_LINE(147)
			this->channels[this->channels->length] = C;
			HX_STACK_LINE(148)
			C->addEventListener(::openfl::_v2::events::Event_obj::SOUND_COMPLETE,this->ended_dyn(),null(),null(),null());
			HX_STACK_LINE(149)
			return C;
		}
		HX_STACK_LINE(151)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC4(SoundManager_obj,_Play,return )

Void SoundManager_obj::jingleend( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("SoundManager","jingleend",0xb819865a,"SoundManager.jingleend","SoundManager.hx",153,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(154)
		Dynamic D = event;		HX_STACK_VAR(D,"D");
		HX_STACK_LINE(156)
		if (((bool((this->music != null())) && bool(!(this->muted))))){
			HX_STACK_LINE(158)
			::openfl::media::SoundTransform _g = ::openfl::media::SoundTransform_obj::__new(this->musicvol,(int)0);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(158)
			this->music->set_soundTransform(_g);
		}
		HX_STACK_LINE(162)
		this->channels->remove(D);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,jingleend,(void))

Void SoundManager_obj::ended( ::openfl::_v2::events::Event event){
{
		HX_STACK_FRAME("SoundManager","ended",0xc0a8560a,"SoundManager.ended","SoundManager.hx",164,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(165)
		Dynamic D = event;		HX_STACK_VAR(D,"D");
		HX_STACK_LINE(166)
		if (((this->music == D))){
			HX_STACK_LINE(168)
			this->music = null();
			HX_STACK_LINE(169)
			this->_song = null();
		}
		HX_STACK_LINE(171)
		this->channels->remove(D);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,ended,(void))

Void SoundManager_obj::_StopAll( ){
{
		HX_STACK_FRAME("SoundManager","_StopAll",0x6d332c90,"SoundManager._StopAll","SoundManager.hx",176,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_LINE(177)
		while((true)){
			HX_STACK_LINE(177)
			if ((!(((this->channels->length > (int)0))))){
				HX_STACK_LINE(177)
				break;
			}
			HX_STACK_LINE(179)
			::openfl::_v2::media::SoundChannel C = this->channels->__get((int)0).StaticCast< ::openfl::_v2::media::SoundChannel >();		HX_STACK_VAR(C,"C");
			HX_STACK_LINE(180)
			C->stop();
			HX_STACK_LINE(181)
			int _g = this->channels->indexOf(C,null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(181)
			if (((_g > (int)-1))){
				HX_STACK_LINE(183)
				this->channels->remove(C);
			}
		}
		HX_STACK_LINE(186)
		this->music = null();
		HX_STACK_LINE(187)
		this->_song = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,_StopAll,(void))

Void SoundManager_obj::SetSoundVolume( Float volume){
{
		HX_STACK_FRAME("SoundManager","SetSoundVolume",0x6b63d097,"SoundManager.SetSoundVolume","SoundManager.hx",189,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_ARG(volume,"volume")
		HX_STACK_LINE(190)
		if ((!(this->muted))){
			HX_STACK_LINE(192)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(193)
			if (((volume < 0.1))){
				HX_STACK_LINE(195)
				volume = (int)0;
			}
			HX_STACK_LINE(197)
			if (((volume > 0.9))){
				HX_STACK_LINE(199)
				volume = (int)1;
			}
			HX_STACK_LINE(201)
			while((true)){
				HX_STACK_LINE(201)
				if ((!(((i < this->channels->length))))){
					HX_STACK_LINE(201)
					break;
				}
				HX_STACK_LINE(203)
				::openfl::_v2::media::SoundChannel C = this->channels->__get(i).StaticCast< ::openfl::_v2::media::SoundChannel >();		HX_STACK_VAR(C,"C");
				HX_STACK_LINE(204)
				if (((C != this->music))){
					HX_STACK_LINE(206)
					::openfl::media::SoundTransform _g = ::openfl::media::SoundTransform_obj::__new(volume,(int)0);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(206)
					C->set_soundTransform(_g);
				}
				HX_STACK_LINE(208)
				hx::AddEq(i,(int)1);
			}
		}
		HX_STACK_LINE(211)
		this->sndvol = volume;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,SetSoundVolume,(void))

Float SoundManager_obj::GetMusicVolume( ){
	HX_STACK_FRAME("SoundManager","GetMusicVolume",0xda57b079,"SoundManager.GetMusicVolume","SoundManager.hx",214,0xe9be8400)
	HX_STACK_THIS(this)
	HX_STACK_LINE(214)
	return this->musicvol;
}


HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,GetMusicVolume,return )

Float SoundManager_obj::GetSoundVolume( ){
	HX_STACK_FRAME("SoundManager","GetSoundVolume",0x4b43e823,"SoundManager.GetSoundVolume","SoundManager.hx",217,0xe9be8400)
	HX_STACK_THIS(this)
	HX_STACK_LINE(217)
	return this->sndvol;
}


HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,GetSoundVolume,return )

Void SoundManager_obj::SetMusicVolume( Float volume){
{
		HX_STACK_FRAME("SoundManager","SetMusicVolume",0xfa7798ed,"SoundManager.SetMusicVolume","SoundManager.hx",219,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_ARG(volume,"volume")
		HX_STACK_LINE(220)
		if ((!(this->muted))){
			HX_STACK_LINE(222)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(223)
			if (((volume < 0.1))){
				HX_STACK_LINE(225)
				volume = (int)0;
			}
			HX_STACK_LINE(227)
			if (((volume > 0.9))){
				HX_STACK_LINE(229)
				volume = (int)1;
			}
			HX_STACK_LINE(231)
			while((true)){
				HX_STACK_LINE(231)
				if ((!(((i < this->channels->length))))){
					HX_STACK_LINE(231)
					break;
				}
				HX_STACK_LINE(233)
				::openfl::_v2::media::SoundChannel C = this->channels->__get(i).StaticCast< ::openfl::_v2::media::SoundChannel >();		HX_STACK_VAR(C,"C");
				HX_STACK_LINE(234)
				if (((C == this->music))){
					HX_STACK_LINE(236)
					::openfl::media::SoundTransform _g = ::openfl::media::SoundTransform_obj::__new(volume,(int)0);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(236)
					C->set_soundTransform(_g);
				}
				HX_STACK_LINE(238)
				hx::AddEq(i,(int)1);
			}
		}
		HX_STACK_LINE(241)
		this->musicvol = volume;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,SetMusicVolume,(void))

Void SoundManager_obj::Mute( ){
{
		HX_STACK_FRAME("SoundManager","Mute",0xa78cdfe9,"SoundManager.Mute","SoundManager.hx",243,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_LINE(244)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(245)
		this->muted = true;
		HX_STACK_LINE(246)
		while((true)){
			HX_STACK_LINE(246)
			if ((!(((i < this->channels->length))))){
				HX_STACK_LINE(246)
				break;
			}
			HX_STACK_LINE(248)
			::openfl::_v2::media::SoundChannel C = this->channels->__get(i).StaticCast< ::openfl::_v2::media::SoundChannel >();		HX_STACK_VAR(C,"C");
			HX_STACK_LINE(250)
			::openfl::media::SoundTransform _g = ::openfl::media::SoundTransform_obj::__new((int)0,(int)0);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(250)
			C->set_soundTransform(_g);
			HX_STACK_LINE(251)
			hx::AddEq(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,Mute,(void))

Void SoundManager_obj::Unmute( ){
{
		HX_STACK_FRAME("SoundManager","Unmute",0x72ec4ac2,"SoundManager.Unmute","SoundManager.hx",254,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_LINE(255)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(256)
		this->muted = false;
		HX_STACK_LINE(257)
		while((true)){
			HX_STACK_LINE(257)
			if ((!(((i < this->channels->length))))){
				HX_STACK_LINE(257)
				break;
			}
			HX_STACK_LINE(259)
			::openfl::_v2::media::SoundChannel C = this->channels->__get(i).StaticCast< ::openfl::_v2::media::SoundChannel >();		HX_STACK_VAR(C,"C");
			HX_STACK_LINE(261)
			Float V = this->sndvol;		HX_STACK_VAR(V,"V");
			HX_STACK_LINE(262)
			if (((C == this->music))){
				HX_STACK_LINE(264)
				V = this->musicvol;
			}
			HX_STACK_LINE(266)
			::openfl::media::SoundTransform _g = ::openfl::media::SoundTransform_obj::__new(V,(int)0);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(266)
			C->set_soundTransform(_g);
			HX_STACK_LINE(267)
			hx::AddEq(i,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,Unmute,(void))

Void SoundManager_obj::ToggleMute( ){
{
		HX_STACK_FRAME("SoundManager","ToggleMute",0x2945519d,"SoundManager.ToggleMute","SoundManager.hx",271,0xe9be8400)
		HX_STACK_THIS(this)
		HX_STACK_LINE(271)
		if ((this->muted)){
			HX_STACK_LINE(273)
			this->Unmute();
		}
		else{
			HX_STACK_LINE(277)
			this->Mute();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,ToggleMute,(void))

::SoundManager SoundManager_obj::_this;

::openfl::_v2::media::SoundChannel SoundManager_obj::Play( ::String path){
	HX_STACK_FRAME("SoundManager","Play",0xa9819f04,"SoundManager.Play","SoundManager.hx",32,0xe9be8400)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(32)
	return ::SoundManager_obj::_this->_Play(path,null(),null(),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,Play,return )

::openfl::_v2::media::SoundChannel SoundManager_obj::PlayJingle( ::String path){
	HX_STACK_FRAME("SoundManager","PlayJingle",0x0fd85555,"SoundManager.PlayJingle","SoundManager.hx",59,0xe9be8400)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(59)
	return ::SoundManager_obj::_this->_PlayJingle(path);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,PlayJingle,return )

::openfl::_v2::media::SoundChannel SoundManager_obj::PlayMusic( ::String path){
	HX_STACK_FRAME("SoundManager","PlayMusic",0x3e33b301,"SoundManager.PlayMusic","SoundManager.hx",76,0xe9be8400)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(76)
	Array< ::String > path1 = Array_obj< ::String >::__new().Add(path);		HX_STACK_VAR(path1,"path1");
	HX_STACK_LINE(78)
	if (((::SoundManager_obj::_this->_song != path1->__get((int)0)))){
		HX_STACK_LINE(80)
		::openfl::_v2::media::SoundChannel A = ::SoundManager_obj::_this->_Play((path1->__get((int)0) + HX_CSTRING("intro")),(int)0,(int)0,::SoundManager_obj::_this->musicvol);		HX_STACK_VAR(A,"A");
		HX_STACK_LINE(81)
		if (((A != null()))){
			HX_STACK_LINE(83)
			if (((::SoundManager_obj::_this->music != null()))){
				HX_STACK_LINE(85)
				::SoundManager_obj::_this->music->stop();
				HX_STACK_LINE(86)
				::SoundManager_obj::_this->music = null();
			}

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::String >,path1)
			Void run(::openfl::_v2::events::Event e){
				HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","SoundManager.hx",89,0xe9be8400)
				HX_STACK_ARG(e,"e")
				{
					HX_STACK_LINE(89)
					::SoundManager_obj::_this->_PlayMusic(path1->__get((int)0));
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(88)
			A->addEventListener(::openfl::_v2::events::Event_obj::SOUND_COMPLETE, Dynamic(new _Function_3_1(path1)),null(),null(),null());
			HX_STACK_LINE(92)
			return A;
		}
		else{
			HX_STACK_LINE(96)
			return ::SoundManager_obj::_this->_PlayMusic(path1->__get((int)0));
		}
	}
	HX_STACK_LINE(99)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(SoundManager_obj,PlayMusic,return )

Void SoundManager_obj::StopAll( ){
{
		HX_STACK_FRAME("SoundManager","StopAll",0x5226c72f,"SoundManager.StopAll","SoundManager.hx",174,0xe9be8400)
		HX_STACK_LINE(174)
		return null(::SoundManager_obj::_this->_StopAll());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(SoundManager_obj,StopAll,(void))


SoundManager_obj::SoundManager_obj()
{
}

void SoundManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SoundManager);
	HX_MARK_MEMBER_NAME(Dictionary,"Dictionary");
	HX_MARK_MEMBER_NAME(channels,"channels");
	HX_MARK_MEMBER_NAME(muted,"muted");
	HX_MARK_MEMBER_NAME(music,"music");
	HX_MARK_MEMBER_NAME(sndvol,"sndvol");
	HX_MARK_MEMBER_NAME(musicvol,"musicvol");
	HX_MARK_MEMBER_NAME(_song,"_song");
	HX_MARK_MEMBER_NAME(_songposition,"_songposition");
	HX_MARK_END_CLASS();
}

void SoundManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(Dictionary,"Dictionary");
	HX_VISIT_MEMBER_NAME(channels,"channels");
	HX_VISIT_MEMBER_NAME(muted,"muted");
	HX_VISIT_MEMBER_NAME(music,"music");
	HX_VISIT_MEMBER_NAME(sndvol,"sndvol");
	HX_VISIT_MEMBER_NAME(musicvol,"musicvol");
	HX_VISIT_MEMBER_NAME(_song,"_song");
	HX_VISIT_MEMBER_NAME(_songposition,"_songposition");
}

Dynamic SoundManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Play") ) { return Play_dyn(); }
		if (HX_FIELD_EQ(inName,"Mute") ) { return Mute_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_this") ) { return _this; }
		if (HX_FIELD_EQ(inName,"muted") ) { return muted; }
		if (HX_FIELD_EQ(inName,"music") ) { return music; }
		if (HX_FIELD_EQ(inName,"_song") ) { return _song; }
		if (HX_FIELD_EQ(inName,"_Play") ) { return _Play_dyn(); }
		if (HX_FIELD_EQ(inName,"ended") ) { return ended_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"sndvol") ) { return sndvol; }
		if (HX_FIELD_EQ(inName,"Unmute") ) { return Unmute_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"StopAll") ) { return StopAll_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"channels") ) { return channels; }
		if (HX_FIELD_EQ(inName,"musicvol") ) { return musicvol; }
		if (HX_FIELD_EQ(inName,"GetSound") ) { return GetSound_dyn(); }
		if (HX_FIELD_EQ(inName,"_StopAll") ) { return _StopAll_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"PlayMusic") ) { return PlayMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"jingleend") ) { return jingleend_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"PlayJingle") ) { return PlayJingle_dyn(); }
		if (HX_FIELD_EQ(inName,"Dictionary") ) { return Dictionary; }
		if (HX_FIELD_EQ(inName,"_PlayMusic") ) { return _PlayMusic_dyn(); }
		if (HX_FIELD_EQ(inName,"ToggleMute") ) { return ToggleMute_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_PlayJingle") ) { return _PlayJingle_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_songposition") ) { return _songposition; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"SetSoundVolume") ) { return SetSoundVolume_dyn(); }
		if (HX_FIELD_EQ(inName,"GetMusicVolume") ) { return GetMusicVolume_dyn(); }
		if (HX_FIELD_EQ(inName,"GetSoundVolume") ) { return GetSoundVolume_dyn(); }
		if (HX_FIELD_EQ(inName,"SetMusicVolume") ) { return SetMusicVolume_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SoundManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_this") ) { _this=inValue.Cast< ::SoundManager >(); return inValue; }
		if (HX_FIELD_EQ(inName,"muted") ) { muted=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"music") ) { music=inValue.Cast< ::openfl::_v2::media::SoundChannel >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_song") ) { _song=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"sndvol") ) { sndvol=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"channels") ) { channels=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"musicvol") ) { musicvol=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Dictionary") ) { Dictionary=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_songposition") ) { _songposition=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SoundManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("Dictionary"));
	outFields->push(HX_CSTRING("channels"));
	outFields->push(HX_CSTRING("muted"));
	outFields->push(HX_CSTRING("music"));
	outFields->push(HX_CSTRING("sndvol"));
	outFields->push(HX_CSTRING("musicvol"));
	outFields->push(HX_CSTRING("_song"));
	outFields->push(HX_CSTRING("_songposition"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_this"),
	HX_CSTRING("Play"),
	HX_CSTRING("PlayJingle"),
	HX_CSTRING("PlayMusic"),
	HX_CSTRING("StopAll"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(SoundManager_obj,Dictionary),HX_CSTRING("Dictionary")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SoundManager_obj,channels),HX_CSTRING("channels")},
	{hx::fsBool,(int)offsetof(SoundManager_obj,muted),HX_CSTRING("muted")},
	{hx::fsObject /*::openfl::_v2::media::SoundChannel*/ ,(int)offsetof(SoundManager_obj,music),HX_CSTRING("music")},
	{hx::fsFloat,(int)offsetof(SoundManager_obj,sndvol),HX_CSTRING("sndvol")},
	{hx::fsFloat,(int)offsetof(SoundManager_obj,musicvol),HX_CSTRING("musicvol")},
	{hx::fsString,(int)offsetof(SoundManager_obj,_song),HX_CSTRING("_song")},
	{hx::fsFloat,(int)offsetof(SoundManager_obj,_songposition),HX_CSTRING("_songposition")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Dictionary"),
	HX_CSTRING("channels"),
	HX_CSTRING("muted"),
	HX_CSTRING("music"),
	HX_CSTRING("sndvol"),
	HX_CSTRING("musicvol"),
	HX_CSTRING("_song"),
	HX_CSTRING("_songposition"),
	HX_CSTRING("GetSound"),
	HX_CSTRING("_PlayJingle"),
	HX_CSTRING("_PlayMusic"),
	HX_CSTRING("_Play"),
	HX_CSTRING("jingleend"),
	HX_CSTRING("ended"),
	HX_CSTRING("_StopAll"),
	HX_CSTRING("SetSoundVolume"),
	HX_CSTRING("GetMusicVolume"),
	HX_CSTRING("GetSoundVolume"),
	HX_CSTRING("SetMusicVolume"),
	HX_CSTRING("Mute"),
	HX_CSTRING("Unmute"),
	HX_CSTRING("ToggleMute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SoundManager_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SoundManager_obj::_this,"_this");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SoundManager_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SoundManager_obj::_this,"_this");
};

#endif

Class SoundManager_obj::__mClass;

void SoundManager_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("SoundManager"), hx::TCanCast< SoundManager_obj> ,sStaticFields,sMemberFields,
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

void SoundManager_obj::__boot()
{
}

