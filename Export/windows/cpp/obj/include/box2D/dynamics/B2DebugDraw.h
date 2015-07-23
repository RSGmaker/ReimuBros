#ifndef INCLUDED_box2D_dynamics_B2DebugDraw
#define INCLUDED_box2D_dynamics_B2DebugDraw

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,common,B2Color)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2DebugDraw)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObject)
HX_DECLARE_CLASS3(openfl,_v2,display,DisplayObjectContainer)
HX_DECLARE_CLASS3(openfl,_v2,display,IBitmapDrawable)
HX_DECLARE_CLASS3(openfl,_v2,display,InteractiveObject)
HX_DECLARE_CLASS3(openfl,_v2,display,Sprite)
HX_DECLARE_CLASS3(openfl,_v2,events,EventDispatcher)
HX_DECLARE_CLASS3(openfl,_v2,events,IEventDispatcher)
namespace box2D{
namespace dynamics{


class HXCPP_CLASS_ATTRIBUTES  B2DebugDraw_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DebugDraw_obj OBJ_;
		B2DebugDraw_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2DebugDraw_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2DebugDraw_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DebugDraw"); }

		virtual Void setFlags( int flags);
		Dynamic setFlags_dyn();

		virtual int getFlags( );
		Dynamic getFlags_dyn();

		virtual Void appendFlags( int flags);
		Dynamic appendFlags_dyn();

		virtual Void clearFlags( int flags);
		Dynamic clearFlags_dyn();

		virtual Void setSprite( ::openfl::_v2::display::Sprite sprite);
		Dynamic setSprite_dyn();

		virtual ::openfl::_v2::display::Sprite getSprite( );
		Dynamic getSprite_dyn();

		virtual Void setDrawScale( Float drawScale);
		Dynamic setDrawScale_dyn();

		virtual Float getDrawScale( );
		Dynamic getDrawScale_dyn();

		virtual Void setLineThickness( Float lineThickness);
		Dynamic setLineThickness_dyn();

		virtual Float getLineThickness( );
		Dynamic getLineThickness_dyn();

		virtual Void setAlpha( Float alpha);
		Dynamic setAlpha_dyn();

		virtual Float getAlpha( );
		Dynamic getAlpha_dyn();

		virtual Void setFillAlpha( Float alpha);
		Dynamic setFillAlpha_dyn();

		virtual Float getFillAlpha( );
		Dynamic getFillAlpha_dyn();

		virtual Void setXFormScale( Float xformScale);
		Dynamic setXFormScale_dyn();

		virtual Float getXFormScale( );
		Dynamic getXFormScale_dyn();

		virtual Void drawPolygon( Array< ::Dynamic > vertices,int vertexCount,::box2D::common::B2Color color);
		Dynamic drawPolygon_dyn();

		virtual Void drawSolidPolygon( Array< ::Dynamic > vertices,int vertexCount,::box2D::common::B2Color color);
		Dynamic drawSolidPolygon_dyn();

		virtual Void drawCircle( ::box2D::common::math::B2Vec2 center,Float radius,::box2D::common::B2Color color);
		Dynamic drawCircle_dyn();

		virtual Void drawSolidCircle( ::box2D::common::math::B2Vec2 center,Float radius,::box2D::common::math::B2Vec2 axis,::box2D::common::B2Color color);
		Dynamic drawSolidCircle_dyn();

		virtual Void drawSegment( ::box2D::common::math::B2Vec2 p1,::box2D::common::math::B2Vec2 p2,::box2D::common::B2Color color);
		Dynamic drawSegment_dyn();

		virtual Void drawTransform( ::box2D::common::math::B2Transform xf);
		Dynamic drawTransform_dyn();

		int m_drawFlags;
		::openfl::_v2::display::Sprite m_sprite;
		Float m_drawScale;
		Float m_lineThickness;
		Float m_alpha;
		Float m_fillAlpha;
		Float m_xformScale;
		static int e_shapeBit;
		static int e_jointBit;
		static int e_aabbBit;
		static int e_pairBit;
		static int e_centerOfMassBit;
		static int e_controllerBit;
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2DebugDraw */ 
