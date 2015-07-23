#ifndef INCLUDED_box2D_collision_shapes_B2EdgeShape
#define INCLUDED_box2D_collision_shapes_B2EdgeShape

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <box2D/collision/shapes/B2Shape.h>
HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastInput)
HX_DECLARE_CLASS2(box2D,collision,B2RayCastOutput)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2EdgeShape)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2MassData)
HX_DECLARE_CLASS3(box2D,collision,shapes,B2Shape)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
namespace box2D{
namespace collision{
namespace shapes{


class HXCPP_CLASS_ATTRIBUTES  B2EdgeShape_obj : public ::box2D::collision::shapes::B2Shape_obj{
	public:
		typedef ::box2D::collision::shapes::B2Shape_obj super;
		typedef B2EdgeShape_obj OBJ_;
		B2EdgeShape_obj();
		Void __construct(::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2EdgeShape_obj > __new(::box2D::common::math::B2Vec2 v1,::box2D::common::math::B2Vec2 v2);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2EdgeShape_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2EdgeShape"); }

		virtual bool testPoint( ::box2D::common::math::B2Transform transform,::box2D::common::math::B2Vec2 p);

		virtual bool rayCast( ::box2D::collision::B2RayCastOutput output,::box2D::collision::B2RayCastInput input,::box2D::common::math::B2Transform transform);

		virtual Void computeAABB( ::box2D::collision::B2AABB aabb,::box2D::common::math::B2Transform transform);

		virtual Void computeMass( ::box2D::collision::shapes::B2MassData massData,Float density);

		virtual Float computeSubmergedArea( ::box2D::common::math::B2Vec2 normal,Float offset,::box2D::common::math::B2Transform xf,::box2D::common::math::B2Vec2 c);

		virtual Float getLength( );
		Dynamic getLength_dyn();

		virtual ::box2D::common::math::B2Vec2 getVertex1( );
		Dynamic getVertex1_dyn();

		virtual ::box2D::common::math::B2Vec2 getVertex2( );
		Dynamic getVertex2_dyn();

		virtual ::box2D::common::math::B2Vec2 getCoreVertex1( );
		Dynamic getCoreVertex1_dyn();

		virtual ::box2D::common::math::B2Vec2 getCoreVertex2( );
		Dynamic getCoreVertex2_dyn();

		virtual ::box2D::common::math::B2Vec2 getNormalVector( );
		Dynamic getNormalVector_dyn();

		virtual ::box2D::common::math::B2Vec2 getDirectionVector( );
		Dynamic getDirectionVector_dyn();

		virtual ::box2D::common::math::B2Vec2 getCorner1Vector( );
		Dynamic getCorner1Vector_dyn();

		virtual ::box2D::common::math::B2Vec2 getCorner2Vector( );
		Dynamic getCorner2Vector_dyn();

		virtual bool corner1IsConvex( );
		Dynamic corner1IsConvex_dyn();

		virtual bool corner2IsConvex( );
		Dynamic corner2IsConvex_dyn();

		virtual ::box2D::common::math::B2Vec2 getFirstVertex( ::box2D::common::math::B2Transform xf);
		Dynamic getFirstVertex_dyn();

		virtual ::box2D::collision::shapes::B2EdgeShape getNextEdge( );
		Dynamic getNextEdge_dyn();

		virtual ::box2D::collision::shapes::B2EdgeShape getPrevEdge( );
		Dynamic getPrevEdge_dyn();

		::box2D::common::math::B2Vec2 s_supportVec;
		virtual ::box2D::common::math::B2Vec2 support( ::box2D::common::math::B2Transform xf,Float dX,Float dY);
		Dynamic support_dyn();

		virtual Void setPrevEdge( ::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Vec2 core,::box2D::common::math::B2Vec2 cornerDir,bool convex);
		Dynamic setPrevEdge_dyn();

		virtual Void setNextEdge( ::box2D::collision::shapes::B2EdgeShape edge,::box2D::common::math::B2Vec2 core,::box2D::common::math::B2Vec2 cornerDir,bool convex);
		Dynamic setNextEdge_dyn();

		::box2D::common::math::B2Vec2 m_v1;
		::box2D::common::math::B2Vec2 m_v2;
		::box2D::common::math::B2Vec2 m_coreV1;
		::box2D::common::math::B2Vec2 m_coreV2;
		Float m_length;
		::box2D::common::math::B2Vec2 m_normal;
		::box2D::common::math::B2Vec2 m_direction;
		::box2D::common::math::B2Vec2 m_cornerDir1;
		::box2D::common::math::B2Vec2 m_cornerDir2;
		bool m_cornerConvex1;
		bool m_cornerConvex2;
		::box2D::collision::shapes::B2EdgeShape m_nextEdge;
		::box2D::collision::shapes::B2EdgeShape m_prevEdge;
};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes

#endif /* INCLUDED_box2D_collision_shapes_B2EdgeShape */ 
