#ifndef INCLUDED_box2D_collision_B2Collision
#define INCLUDED_box2D_collision_B2Collision

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2Collision)
HX_DECLARE_CLASS2(box2D,collision,B2Manifold)
HX_DECLARE_CLASS2(box2D,collision,ClipVertex)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2CircleShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2PolygonShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  B2Collision_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Collision_obj OBJ_;
		B2Collision_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Collision_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Collision_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2Collision"); }

		static int b2_nullFeature;
		static int clipSegmentToLine( Array< ::Dynamic > vOut,Array< ::Dynamic > vIn,::box2D::common::math::B2Vec2 normal,Float offset);
		static Dynamic clipSegmentToLine_dyn();

		static Float edgeSeparation( ::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2);
		static Dynamic edgeSeparation_dyn();

		static Float findMaxSeparation( Array< int > edgeIndex,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2);
		static Dynamic findMaxSeparation_dyn();

		static Void findIncidentEdge( Array< ::Dynamic > c,::box2D::collision::shapes::B2PolygonShape poly1,::box2D::common::math::B2Transform xf1,int edge1,::box2D::collision::shapes::B2PolygonShape poly2,::box2D::common::math::B2Transform xf2);
		static Dynamic findIncidentEdge_dyn();

		static Array< ::Dynamic > makeClipPointVector( );
		static Dynamic makeClipPointVector_dyn();

		static Array< ::Dynamic > s_incidentEdge;
		static Array< ::Dynamic > s_clipPoints1;
		static Array< ::Dynamic > s_clipPoints2;
		static Array< int > s_edgeAO;
		static Array< int > s_edgeBO;
		static ::box2D::common::math::B2Vec2 s_localTangent;
		static ::box2D::common::math::B2Vec2 s_localNormal;
		static ::box2D::common::math::B2Vec2 s_planePoint;
		static ::box2D::common::math::B2Vec2 s_normal;
		static ::box2D::common::math::B2Vec2 s_tangent;
		static ::box2D::common::math::B2Vec2 s_tangent2;
		static ::box2D::common::math::B2Vec2 s_v11;
		static ::box2D::common::math::B2Vec2 s_v12;
		static ::box2D::common::math::B2Vec2 b2CollidePolyTempVec;
		static Void collidePolygons( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polyA,::box2D::common::math::B2Transform xfA,::box2D::collision::shapes::B2PolygonShape polyB,::box2D::common::math::B2Transform xfB);
		static Dynamic collidePolygons_dyn();

		static Void collideCircles( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2CircleShape circle1,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle2,::box2D::common::math::B2Transform xf2);
		static Dynamic collideCircles_dyn();

		static Void collidePolygonAndCircle( ::box2D::collision::B2Manifold manifold,::box2D::collision::shapes::B2PolygonShape polygon,::box2D::common::math::B2Transform xf1,::box2D::collision::shapes::B2CircleShape circle,::box2D::common::math::B2Transform xf2);
		static Dynamic collidePolygonAndCircle_dyn();

		static bool testOverlap( ::box2D::collision::B2AABB a,::box2D::collision::B2AABB b);
		static Dynamic testOverlap_dyn();

};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2Collision */ 
