#ifndef INCLUDED_box2D_collision_B2SeparationFunctionType
#define INCLUDED_box2D_collision_B2SeparationFunctionType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2SeparationFunctionType)
namespace box2D{
namespace collision{


class B2SeparationFunctionType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef B2SeparationFunctionType_obj OBJ_;

	public:
		B2SeparationFunctionType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("box2D.collision.B2SeparationFunctionType"); }
		::String __ToString() const { return HX_CSTRING("B2SeparationFunctionType.") + tag; }

		static ::box2D::collision::B2SeparationFunctionType FACE_A;
		static inline ::box2D::collision::B2SeparationFunctionType FACE_A_dyn() { return FACE_A; }
		static ::box2D::collision::B2SeparationFunctionType FACE_B;
		static inline ::box2D::collision::B2SeparationFunctionType FACE_B_dyn() { return FACE_B; }
		static ::box2D::collision::B2SeparationFunctionType POINTS;
		static inline ::box2D::collision::B2SeparationFunctionType POINTS_dyn() { return POINTS; }
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2SeparationFunctionType */ 
