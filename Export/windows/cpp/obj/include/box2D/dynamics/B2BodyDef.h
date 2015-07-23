#ifndef INCLUDED_box2D_dynamics_B2BodyDef
#define INCLUDED_box2D_dynamics_B2BodyDef

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(box2D,common,math,B2Vec2)
HX_DECLARE_CLASS2(box2D,dynamics,B2BodyDef)
namespace box2D{
namespace dynamics{


class HXCPP_CLASS_ATTRIBUTES  B2BodyDef_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2BodyDef_obj OBJ_;
		B2BodyDef_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2BodyDef_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2BodyDef_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("B2BodyDef"); }

		int type;
		::box2D::common::math::B2Vec2 position;
		Float angle;
		::box2D::common::math::B2Vec2 linearVelocity;
		Float angularVelocity;
		Float linearDamping;
		Float angularDamping;
		bool allowSleep;
		bool awake;
		bool fixedRotation;
		bool bullet;
		bool active;
		Dynamic userData;
		Float inertiaScale;
};

} // end namespace box2D
} // end namespace dynamics

#endif /* INCLUDED_box2D_dynamics_B2BodyDef */ 
