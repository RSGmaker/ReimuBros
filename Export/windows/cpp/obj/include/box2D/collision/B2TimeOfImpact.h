#ifndef INCLUDED_box2D_collision_B2TimeOfImpact
#define INCLUDED_box2D_collision_B2TimeOfImpact

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2DistanceInput)
HX_DECLARE_CLASS2(box2D,collision,B2DistanceOutput)
HX_DECLARE_CLASS2(box2D,collision,B2SeparationFunction)
HX_DECLARE_CLASS2(box2D,collision,B2SimplexCache)
HX_DECLARE_CLASS2(box2D,collision,B2TOIInput)
HX_DECLARE_CLASS2(box2D,collision,B2TimeOfImpact)
HX_DECLARE_CLASS3(box2D,common,math,B2Transform)
namespace box2D{
namespace collision{


class HXCPP_CLASS_ATTRIBUTES  B2TimeOfImpact_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2TimeOfImpact_obj OBJ_;
		B2TimeOfImpact_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2TimeOfImpact_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2TimeOfImpact_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2TimeOfImpact"); }

		static int b2_toiCalls;
		static int b2_toiIters;
		static int b2_toiMaxIters;
		static int b2_toiRootIters;
		static int b2_toiMaxRootIters;
		static ::box2D::collision::B2SimplexCache s_cache;
		static ::box2D::collision::B2DistanceInput s_distanceInput;
		static ::box2D::common::math::B2Transform s_xfA;
		static ::box2D::common::math::B2Transform s_xfB;
		static ::box2D::collision::B2SeparationFunction s_fcn;
		static ::box2D::collision::B2DistanceOutput s_distanceOutput;
		static Float timeOfImpact( ::box2D::collision::B2TOIInput input);
		static Dynamic timeOfImpact_dyn();

};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2TimeOfImpact */ 
