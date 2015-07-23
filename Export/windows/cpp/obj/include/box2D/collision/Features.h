#ifndef INCLUDED_box2D_collision_Features
#define INCLUDED_box2D_collision_Features

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ContactID)
HX_DECLARE_CLASS2(box2D,collision,Features)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  Features_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Features_obj OBJ_;
		Features_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Features_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Features_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Features"); }

		virtual int get_referenceEdge( );
		Dynamic get_referenceEdge_dyn();

		virtual int set_referenceEdge( int value);
		Dynamic set_referenceEdge_dyn();

		int _referenceEdge;
		virtual int get_incidentEdge( );
		Dynamic get_incidentEdge_dyn();

		virtual int set_incidentEdge( int value);
		Dynamic set_incidentEdge_dyn();

		int _incidentEdge;
		virtual int get_incidentVertex( );
		Dynamic get_incidentVertex_dyn();

		virtual int set_incidentVertex( int value);
		Dynamic set_incidentVertex_dyn();

		int _incidentVertex;
		virtual int get_flip( );
		Dynamic get_flip_dyn();

		virtual int set_flip( int value);
		Dynamic set_flip_dyn();

		int _flip;
		::box2D::collision::B2ContactID _m_id;
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_Features */ 
