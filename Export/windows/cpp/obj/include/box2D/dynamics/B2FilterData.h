#ifndef INCLUDED_box2D_dynamics_B2FilterData
#define INCLUDED_box2D_dynamics_B2FilterData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,dynamics,B2FilterData)
namespace box2D{
namespace dynamics{


class HXCPP_CLASS_ATTRIBUTES  B2FilterData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2FilterData_obj OBJ_;
		B2FilterData_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2FilterData_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2FilterData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2FilterData"); }

		virtual ::box2D::dynamics::B2FilterData copy( );
		Dynamic copy_dyn();

		int categoryBits;
		int maskBits;
		int groupIndex;
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2FilterData */ 
