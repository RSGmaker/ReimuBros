#ifndef INCLUDED_box2D_collision_B2DistanceInput
#define INCLUDED_box2D_collision_B2DistanceInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceInput)
HX_DECLARE_CLASS2(box2D,collision,B2DistanceProxy)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  B2DistanceInput_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2DistanceInput_obj OBJ_;
		B2DistanceInput_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2DistanceInput_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2DistanceInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2DistanceInput"); }

		::box2D::collision::B2DistanceProxy proxyA;
		::box2D::collision::B2DistanceProxy proxyB;
		::box2D::common::math::B2Transform transformA;
		::box2D::common::math::B2Transform transformB;
		bool useRadii;
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2DistanceInput */ 
