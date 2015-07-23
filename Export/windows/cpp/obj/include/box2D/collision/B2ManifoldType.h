#ifndef INCLUDED_box2D_collision_B2ManifoldType
#define INCLUDED_box2D_collision_B2ManifoldType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(box2D,collision,B2ManifoldType)
namespace box2D{
namespace collision{


class B2ManifoldType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef B2ManifoldType_obj OBJ_;

	public:
		B2ManifoldType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("box2D.collision.B2ManifoldType"); }
		::String __ToString() const { return HX_CSTRING("B2ManifoldType.") + tag; }

		static ::box2D::collision::B2ManifoldType CIRCLES;
		static inline ::box2D::collision::B2ManifoldType CIRCLES_dyn() { return CIRCLES; }
		static ::box2D::collision::B2ManifoldType FACE_A;
		static inline ::box2D::collision::B2ManifoldType FACE_A_dyn() { return FACE_A; }
		static ::box2D::collision::B2ManifoldType FACE_B;
		static inline ::box2D::collision::B2ManifoldType FACE_B_dyn() { return FACE_B; }
};

} // end namespace box2D
} // end namespace collision

#endif /* INCLUDED_box2D_collision_B2ManifoldType */ 
