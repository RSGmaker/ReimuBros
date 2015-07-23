#ifndef INCLUDED_box2D_common_B2Settings
#define INCLUDED_box2D_common_B2Settings

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,common,B2Settings)
namespace box2D{
namespace common{


class HXCPP_CLASS_ATTRIBUTES  B2Settings_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef B2Settings_obj OBJ_;
		B2Settings_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< B2Settings_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~B2Settings_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("B2Settings"); }

		static ::String VERSION;
		static Float b2_pi;
		static int b2_maxManifoldPoints;
		static Float b2_aabbExtension;
		static Float b2_aabbMultiplier;
		static Float b2_polygonRadius;
		static Float b2_linearSlop;
		static Float b2_angularSlop;
		static Float b2_toiSlop;
		static int b2_maxTOIContactsPerIsland;
		static int b2_maxTOIJointsPerIsland;
		static Float b2_velocityThreshold;
		static Float b2_maxLinearCorrection;
		static Float b2_maxAngularCorrection;
		static Float b2_maxTranslation;
		static Float b2_maxTranslationSquared;
		static Float b2_maxRotation;
		static Float b2_maxRotationSquared;
		static Float b2_contactBaumgarte;
		static Float b2MixFriction( Float friction1,Float friction2);
		static Dynamic b2MixFriction_dyn();

		static Float b2MixRestitution( Float restitution1,Float restitution2);
		static Dynamic b2MixRestitution_dyn();

		static Float b2_timeToSleep;
		static Float b2_linearSleepTolerance;
		static Float b2_angularSleepTolerance;
		static Void b2Assert( bool a);
		static Dynamic b2Assert_dyn();

};

} // end namespace box2D
} // end namespace common

#endif /* INCLUDED_box2D_common_B2Settings */ 
