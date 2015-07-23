#ifndef INCLUDED_box2D_dynamics__B2BodyType_B2BodyType_Impl_
#define INCLUDED_box2D_dynamics__B2BodyType_B2BodyType_Impl_

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,dynamics,_B2BodyType,B2BodyType_Impl_)
namespace box2D{
namespace dynamics{
namespace _B2BodyType{


class HXCPP_CLASS_ATTRIBUTES  B2BodyType_Impl__obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2BodyType_Impl__obj OBJ_;
		B2BodyType_Impl__obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2BodyType_Impl__obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2BodyType_Impl__obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2BodyType_Impl_"); }

		static int STATIC_BODY;
		static int KINEMATIC_BODY;
		static int DYNAMIC_BODY;
};

} // end namespace box2D
} // end namespace dynamics
} // end namespace _B2BodyType

#endif /* INCLUDED_box2D_dynamics__B2BodyType_B2BodyType_Impl_ */ 
