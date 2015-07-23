#ifndef INCLUDED_box2D_collision_shapes_B2PolygonShape
#define INCLUDED_box2D_collision_shapes_B2PolygonShape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/collision/shapes/B2Shape.h>
HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2OBB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2PolygonShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Mat22)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{
namespace shapes{


class HXCPP_CLASS_ATTRIBUTES  B2PolygonShape_obj : public ::box2D::collision::shapes::B2Shape_obj{
	public:
		typedef ::box2D::collision::shapes::B2Shape_obj super;
		typedef B2PolygonShape_obj OBJ_;
		B2PolygonShape_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2PolygonShape_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2PolygonShape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2PolygonShape"); }

		virtual ::box2D::collision::shapes::B2Shape copy( );

		virtual Void set( ::box2D::collision::shapes::B2Shape other);

		virtual Void setAsArray( Dynamic vertices,hx::Null< Float >  vertexCount);
		Dynamic setAsArray_dyn();

		virtual Void setAsVector( Array< ::Dynamic > vertices,hx::Null< Float >  vertexCount);
		Dynamic setAsVector_dyn();

		virtual Void setAsBox( Float hx,Float hy);
		Dynamic setAsBox_dyn();

		virtual Void setAsOrientedBox( Float hx,Float hy,::box2D::common::math::B2Vec2 center,hx::Null< Float >  angle);
		Dynamic setAsOrientedBox_dyn();

		virtual Void setAsEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2);
		Dynamic setAsEdge_dyn();

		virtual bool testPoint( ::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 p);

		virtual bool rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform);

		virtual Void computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform xf);

		virtual Void computeMass( ::box2D::collision::shapes::B2MassData massData,Float density);

		virtual Float computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,Float offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c);

		virtual int getVertexCount( );
		Dynamic getVertexCount_dyn();

		virtual Array< ::Dynamic > getVertices( );
		Dynamic getVertices_dyn();

		virtual Array< ::Dynamic > getNormals( );
		Dynamic getNormals_dyn();

		virtual int getSupport( ::box2D::common::math::B2Vec2 d);
		Dynamic getSupport_dyn();

		virtual ::box2D::common::math::B2Vec2 getSupportVertex( ::box2D::common::math::B2Vec2 d);
		Dynamic getSupportVertex_dyn();

		virtual bool validate( );
		Dynamic validate_dyn();

		virtual Void reserve( int count);
		Dynamic reserve_dyn();

		::box2D::common::math::B2Vec2 m_centroid;
		Array< ::Dynamic > m_vertices;
		Array< ::Dynamic > m_normals;
		int m_vertexCount;
		static ::box2D::collision::shapes::B2PolygonShape asArray( Dynamic vertices,Float vertexCount);
		static Dynamic asArray_dyn();

		static ::box2D::collision::shapes::B2PolygonShape asVector( Array< ::Dynamic > vertices,Float vertexCount);
		static Dynamic asVector_dyn();

		static ::box2D::collision::shapes::B2PolygonShape asBox( Float hx,Float hy);
		static Dynamic asBox_dyn();

		static ::box2D::common::math::B2Mat22 s_mat;
		static ::box2D::collision::shapes::B2PolygonShape asOrientedBox( Float hx,Float hy,::box2D::common::math::B2Vec2 center,hx::Null< Float >  angle);
		static Dynamic asOrientedBox_dyn();

		static ::box2D::collision::shapes::B2PolygonShape asEdge( ::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2);
		static Dynamic asEdge_dyn();

		static ::box2D::common::math::B2Vec2 computeCentroid( Array< ::Dynamic > vs,int count);
		static Dynamic computeCentroid_dyn();

		static Void computeOBB( ::box2D::collision::B2OBB obb,Array< ::Dynamic > vs,int count);
		static Dynamic computeOBB_dyn();

};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes

#endif /* INCLUDED_box2D_collision_shapes_B2PolygonShape */ 
