#ifndef INCLUDED_Enemy
#define INCLUDED_Enemy

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Entity.h>
HX_DECLARE_CLASS0(Animation)
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(Entity)
HX_DECLARE_CLASS3(openfl,_v2,display,Bitmap)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)


class HXCPP_CLASS_ATTRIBUTES  Enemy_obj : public ::Entity_obj{
	public:
		typedef ::Entity_obj super;
		typedef Enemy_obj OBJ_;
		Enemy_obj();
		Void __construct(::String ani);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Enemy_obj > __new(::String ani);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Enemy_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Enemy"); }

		bool killable;
		::String charname;
		int flipped;
		bool enraged;
		bool visuallyEnraged;
		bool reward;
		int pointvalue;
		bool respawn;
		int rank;
		int HP;
		bool started;
		int currentrank;
		virtual int getdangerlevel( );
		Dynamic getdangerlevel_dyn();

		virtual Void powerup( );
		Dynamic powerup_dyn();

		virtual Void increaserank( );
		Dynamic increaserank_dyn();

		virtual Void setrank( int r);
		Dynamic setrank_dyn();

		virtual Void enrage( );
		Dynamic enrage_dyn();

		virtual Void updateanimation( ::String name);
		Dynamic updateanimation_dyn();

};


#endif /* INCLUDED_Enemy */ 
