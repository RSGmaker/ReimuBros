#ifndef INCLUDED_box2D_collision_B2DynamicTreePair
#define INCLUDED_box2D_collision_B2DynamicTreePair

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DynamicTreeNode)
HX_DECLARE_CLASS2(box2D,collision,B2DynamicTreePair)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  B2DynamicTreePair_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DynamicTreePair_obj OBJ_;
		B2DynamicTreePair_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2DynamicTreePair_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2DynamicTreePair_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DynamicTreePair"); }

		::box2D::collision::B2DynamicTreeNode proxyA;
		::box2D::collision::B2DynamicTreeNode proxyB;
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DynamicTreePair */ 
