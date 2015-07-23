#ifndef INCLUDED_Entity
#define INCLUDED_Entity

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Animation.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,geom,Rectangle)


class HXCPP_CLASS_ATTRIBUTES  Entity_obj : public ::Animation_obj{
	public:
		typedef ::Animation_obj super;
		typedef Entity_obj OBJ_;
		Entity_obj();
		Void __construct(::String ani);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Entity_obj > __new(::String ani);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Entity_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Entity"); }

		Float Hspeed;
		Float Vspeed;
		bool alive;
		bool solid;
		bool platform;
		int bonked;
		::Entity bonkedby;
		bool dangerous;
		::String type;
		bool killed;
		Float UID;
		int Ldir;
		::Entity ground;
		::Entity headbonk;
		bool wrapped;
		Float deccel;
		bool touchable;
		bool catchingup;
		Float fallaccel;
		bool bonking;
		::openfl::_v2::geom::Rectangle hitbox;
		bool icy;
		virtual ::openfl::_v2::geom::Rectangle GetHitbox( );
		Dynamic GetHitbox_dyn();

		virtual bool CollidesWithPoint( Float X,Float Y);
		Dynamic CollidesWithPoint_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual ::Player nearestplayer( );
		Dynamic nearestplayer_dyn();

		virtual Void rotateentity( Float rot);
		Dynamic rotateentity_dyn();

		virtual Void updphysics( );
		Dynamic updphysics_dyn();

		virtual Void catchup( );
		Dynamic catchup_dyn();

		virtual Void catchupsmall( );
		Dynamic catchupsmall_dyn();

		virtual Void bump( );
		Dynamic bump_dyn();

};


#endif /* INCLUDED_Entity */ 
