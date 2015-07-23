#ifndef INCLUDED_box2D_collision_shapes__B2ShapeType_B2ShapeType_Impl_
#define INCLUDED_box2D_collision_shapes__B2ShapeType_B2ShapeType_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS4(box2D,collision,shapes,_B2ShapeType,B2ShapeType_Impl_)
namespace box2D{
namespace collision{
namespace shapes{
namespace _B2ShapeType{


class HXCPP_CLASS_ATTRIBUTES  B2ShapeType_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ShapeType_Impl__obj OBJ_;
		B2ShapeType_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2ShapeType_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2ShapeType_Impl__obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2ShapeType_Impl_"); }

		static int UNKNOWN_SHAPE;
		static int CIRCLE_SHAPE;
		static int POLYGON_SHAPE;
		static int EDGE_SHAPE;
};

} // end namespace box2D
} // end namespace collision
} // end namespace shapes
} // end namespace _B2ShapeType

#endif /* INCLUDED_box2D_collision_shapes__B2ShapeType_B2ShapeType_Impl_ */ 
