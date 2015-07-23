#ifndef INCLUDED_GameView
#define INCLUDED_GameView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/display/Sprite.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Animationloader)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(EntityItem)
HX_DECLARE_CLASS0(GameView)
HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS0(PowBlock)
HX_DECLARE_CLASS0(TypeofRound)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,Event)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,KeyboardEvent)
HX_DECLARE_CLASS3(openfl,_v2,events,MouseEvent)
HX_DECLARE_CLASS3(openfl,_v2,events,TouchEvent)
HX_DECLARE_CLASS3(openfl,_v2,media,Sound)
HX_DECLARE_CLASS3(openfl,_v2,media,SoundChannel)
HX_DECLARE_CLASS3(openfl,_v2,text,TextField)


class HXCPP_CLASS_ATTRIBUTES  GameView_obj : public ::openfl::_v2::display::Sprite_obj{
	public:
		typedef ::openfl::_v2::display::Sprite_obj super;
		typedef GameView_obj OBJ_;
		GameView_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GameView_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GameView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameView"); }

		::String text;
		::openfl::_v2::text::TextField TF;
		Array< bool > control;
		::Player myplayer;
		int direction;
		int nmax;
		Array< ::Dynamic > entities;
		::Animationloader AL;
		int frame;
		bool MSE;
		::openfl::_v2::media::Sound music;
		::openfl::_v2::media::SoundChannel musicchannel;
		Float ltime;
		Float missingTime;
		::List SpawnList;
		int SpawnTimer;
		Array< ::Dynamic > activeEnemies;
		Array< ::Dynamic > activeItems;
		int level;
		::openfl::_v2::media::Sound snd_killenemy;
		::openfl::_v2::media::Sound snd_finalkillenemy;
		int totalenemies;
		bool Hoster;
		bool touched;
		::haxe::ds::StringMap Players;
		bool ControlEvent;
		::openfl::_v2::display::Bitmap Dpad;
		::openfl::_v2::display::Bitmap BGCRight;
		::openfl::_v2::display::Bitmap BGCLeft;
		::openfl::_v2::display::Bitmap BGCBottom;
		::PowBlock powblock;
		bool roundstarted;
		int maxspawns;
		int spawns;
		::String playerspick;
		bool online;
		::openfl::_v2::text::TextField gameover;
		::String playername;
		::openfl::_v2::text::TextField scoreboard;
		::String Room;
		::String status;
		int ufos;
		int HighScore;
		::openfl::_v2::display::Bitmap Background;
		int syncdelay;
		int gamemode;
		::TypeofRound RoundType;
		Float epm;
		Float ept;
		Float rept;
		int PointsToLife;
		int CombinedScore;
		int CombinedScoreALL;
		Array< ::String > Obstacles;
		int platformformation;
		int currentformation;
		bool spawnedChar;
		int rank;
		virtual Void end( );
		Dynamic end_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void setformation( );
		Dynamic setformation_dyn();

		virtual Void spawnplatform( Float Y);
		Dynamic spawnplatform_dyn();

		virtual Void setholeinplatform( Float Y,Float minx,Float maxx,bool inverse);
		Dynamic setholeinplatform_dyn();

		virtual Void setplatformasplatform( Float Y,bool platform);
		Dynamic setplatformasplatform_dyn();

		virtual Void on_touchend( ::openfl::_v2::events::TouchEvent event);
		Dynamic on_touchend_dyn();

		virtual Void on_touchbegin( ::openfl::_v2::events::TouchEvent event);
		Dynamic on_touchbegin_dyn();

		virtual Void on_mousedown( ::openfl::_v2::events::MouseEvent event);
		Dynamic on_mousedown_dyn();

		virtual Void on_mouseup( ::openfl::_v2::events::MouseEvent event);
		Dynamic on_mouseup_dyn();

		virtual ::String GetNetworkID( );
		Dynamic GetNetworkID_dyn();

		virtual Void PlayMusic( );
		Dynamic PlayMusic_dyn();

		virtual ::Player GetPlayer( ::String ID);
		Dynamic GetPlayer_dyn();

		virtual Void AddPlayer( ::Player P);
		Dynamic AddPlayer_dyn();

		virtual Void SendGap( );
		Dynamic SendGap_dyn();

		virtual Void RemovePlayer( ::String P);
		Dynamic RemovePlayer_dyn();

		virtual Void AddEntityItem( ::EntityItem E);
		Dynamic AddEntityItem_dyn();

		virtual Void AddEnemy( ::Enemy E);
		Dynamic AddEnemy_dyn();

		virtual Void AddObject( ::Entity E);
		Dynamic AddObject_dyn();

		virtual Void RemoveEntityItem( ::Entity I);
		Dynamic RemoveEntityItem_dyn();

		virtual Void RemoveEnemy( ::Entity I);
		Dynamic RemoveEnemy_dyn();

		virtual Void RemoveObject( ::Entity I);
		Dynamic RemoveObject_dyn();

		virtual ::Entity CollisionDetectPoint( Float X,Float Y);
		Dynamic CollisionDetectPoint_dyn();

		virtual ::EntityItem CollisionDetectPointItem( Float X,Float Y);
		Dynamic CollisionDetectPointItem_dyn();

		virtual ::Player CollisionDetectPointPlayer( Float X,Float Y);
		Dynamic CollisionDetectPointPlayer_dyn();

		virtual ::Enemy CollisionDetectPointEnemy( Float X,Float Y);
		Dynamic CollisionDetectPointEnemy_dyn();

		virtual ::Entity CollisionDetectPointDangerous( Float X,Float Y);
		Dynamic CollisionDetectPointDangerous_dyn();

		virtual ::Enemy CollisionDetectTouchEnemy( ::Entity target);
		Dynamic CollisionDetectTouchEnemy_dyn();

		virtual ::EntityItem CollisionDetectTouchItem( ::Entity target);
		Dynamic CollisionDetectTouchItem_dyn();

		virtual bool ismyplayer( ::Entity E);
		Dynamic ismyplayer_dyn();

		virtual Void SendEvent( ::String evt,Dynamic data);
		Dynamic SendEvent_dyn();

		virtual Void ProcessEvent( ::String evt,::String ID,Dynamic data);
		Dynamic ProcessEvent_dyn();

		virtual Void stage_onKeyDown( ::openfl::_v2::events::KeyboardEvent event);
		Dynamic stage_onKeyDown_dyn();

		virtual Void stage_onKeyUp( ::openfl::_v2::events::KeyboardEvent event);
		Dynamic stage_onKeyUp_dyn();

		virtual Dynamic todyn( Dynamic Dyn);
		Dynamic todyn_dyn();

		virtual Dynamic AddEntityFromData( Dynamic D);
		Dynamic AddEntityFromData_dyn();

		virtual Dynamic SpawnEntityFromData( Dynamic D);
		Dynamic SpawnEntityFromData_dyn();

		virtual ::Entity EntityFromUID( Float UID);
		Dynamic EntityFromUID_dyn();

		virtual Void this_onEnterFrame( ::openfl::_v2::events::Event event);
		Dynamic this_onEnterFrame_dyn();

		virtual Void SendStatus( );
		Dynamic SendStatus_dyn();

		virtual Void updategame( ::openfl::_v2::events::Event event);
		Dynamic updategame_dyn();

		virtual Void AddToArrayMultiple( Dynamic array,Dynamic value,int times);
		Dynamic AddToArrayMultiple_dyn();

		virtual Void CalculateLevelData( );
		Dynamic CalculateLevelData_dyn();

		static ::GameView _this;
		static Float onetickperminutechance;
		static Float onetickperminutechance2;
};


#endif /* INCLUDED_GameView */ 
