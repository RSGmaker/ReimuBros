#ifndef INCLUDED_box2D_dynamics_B2ContactImpulse
#define INCLUDED_box2D_dynamics_B2ContactImpulse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2ContactImpulse)
namespace box2D{
namespace dynamics{


class HXCPP_CLASS_ATTRIBUTES  B2ContactImpulse_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2ContactImpulse_obj OBJ_;
		B2ContactImpulse_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2ContactImpulse_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2ContactImpulse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2ContactImpulse"); }

		Array< Float > normalImpulses;
		Array< Float > tangentImpulses;
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2ContactImpulse */ 
