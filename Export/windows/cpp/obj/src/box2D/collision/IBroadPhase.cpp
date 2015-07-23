#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2RayCastInput
#include <box2D/collision/B2RayCastInput.h>
#endif
#ifndef INCLUDED_box2D_collision_IBroadPhase
#include <box2D/collision/IBroadPhase.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

HX_DEFINE_DYNAMIC_FUNC2(IBroadPhase_obj,createProxy,return )

HX_DEFINE_DYNAMIC_FUNC1(IBroadPhase_obj,destroyProxy,)

HX_DEFINE_DYNAMIC_FUNC3(IBroadPhase_obj,moveProxy,)

HX_DEFINE_DYNAMIC_FUNC2(IBroadPhase_obj,testOverlap,return )

HX_DEFINE_DYNAMIC_FUNC1(IBroadPhase_obj,getUserData,return )

HX_DEFINE_DYNAMIC_FUNC1(IBroadPhase_obj,getFatAABB,return )

HX_DEFINE_DYNAMIC_FUNC0(IBroadPhase_obj,getProxyCount,return )

HX_DEFINE_DYNAMIC_FUNC1(IBroadPhase_obj,updatePairs,)

HX_DEFINE_DYNAMIC_FUNC2(IBroadPhase_obj,query,)

HX_DEFINE_DYNAMIC_FUNC2(IBroadPhase_obj,rayCast,)

HX_DEFINE_DYNAMIC_FUNC0(IBroadPhase_obj,validate,)

HX_DEFINE_DYNAMIC_FUNC1(IBroadPhase_obj,rebalance,)


static ::String sMemberFields[] = {
	HX_CSTRING("createProxy"),
	HX_CSTRING("destroyProxy"),
	HX_CSTRING("moveProxy"),
	HX_CSTRING("testOverlap"),
	HX_CSTRING("getUserData"),
	HX_CSTRING("getFatAABB"),
	HX_CSTRING("getProxyCount"),
	HX_CSTRING("updatePairs"),
	HX_CSTRING("query"),
	HX_CSTRING("rayCast"),
	HX_CSTRING("validate"),
	HX_CSTRING("rebalance"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IBroadPhase_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IBroadPhase_obj::__mClass,"__mClass");
};

#endif

Class IBroadPhase_obj::__mClass;

void IBroadPhase_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.IBroadPhase"), hx::TCanCast< IBroadPhase_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void IBroadPhase_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
