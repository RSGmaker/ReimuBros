#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#define INCLUDED_box2D_collision_B2DynamicTreeNode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2AABB)
HX_DECLARE_CLASS2(box2D,collision,B2DynamicTreeNode)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  B2DynamicTreeNode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DynamicTreeNode_obj OBJ_;
		B2DynamicTreeNode_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2DynamicTreeNode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2DynamicTreeNode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DynamicTreeNode"); }

		int id;
		virtual bool isLeaf( );
		Dynamic isLeaf_dyn();

		Dynamic userData;
		::box2D::collision::B2AABB aabb;
		::box2D::collision::B2DynamicTreeNode parent;
		::box2D::collision::B2DynamicTreeNode child1;
		::box2D::collision::B2DynamicTreeNode child2;
		static int currentID;
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DynamicTreeNode */ 
