#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2Manifold
#include <box2D/collision/B2Manifold.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ManifoldType
#include <box2D/collision/B2ManifoldType.h>
#endif
#ifndef INCLUDED_box2D_common_B2Settings
#include <box2D/common/B2Settings.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Mat22
#include <box2D/common/math/B2Mat22.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_B2Body
#include <box2D/dynamics/B2Body.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraint
#include <box2D/dynamics/contacts/B2ContactConstraint.h>
#endif
#ifndef INCLUDED_box2D_dynamics_contacts_B2ContactConstraintPoint
#include <box2D/dynamics/contacts/B2ContactConstraintPoint.h>
#endif
namespace box2D{
namespace dynamics{
namespace contacts{

Void B2ContactConstraint_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.contacts.B2ContactConstraint","new",0x010da3ad,"box2D.dynamics.contacts.B2ContactConstraint.new","box2D/dynamics/contacts/B2ContactConstraint.hx",33,0x0aed9d44)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(58)
	this->pointCount = (int)0;
	HX_STACK_LINE(57)
	this->restitution = (int)0;
	HX_STACK_LINE(56)
	this->friction = (int)0;
	HX_STACK_LINE(55)
	this->radius = (int)0;
	HX_STACK_LINE(36)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(36)
	this->localPlaneNormal = _g;
	HX_STACK_LINE(37)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(37)
	this->localPoint = _g1;
	HX_STACK_LINE(38)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(38)
	this->normal = _g2;
	HX_STACK_LINE(39)
	::box2D::common::math::B2Mat22 _g3 = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(39)
	this->normalMass = _g3;
	HX_STACK_LINE(40)
	::box2D::common::math::B2Mat22 _g4 = ::box2D::common::math::B2Mat22_obj::__new();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(40)
	this->K = _g4;
	HX_STACK_LINE(41)
	Array< ::Dynamic > _g5 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(41)
	this->points = _g5;
	HX_STACK_LINE(42)
	{
		HX_STACK_LINE(42)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(42)
		int _g6 = ::box2D::common::B2Settings_obj::b2_maxManifoldPoints;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(42)
		while((true)){
			HX_STACK_LINE(42)
			if ((!(((_g11 < _g6))))){
				HX_STACK_LINE(42)
				break;
			}
			HX_STACK_LINE(42)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(43)
			this->points[i] = ::box2D::dynamics::contacts::B2ContactConstraintPoint_obj::__new();
		}
	}
}
;
	return null();
}

//B2ContactConstraint_obj::~B2ContactConstraint_obj() { }

Dynamic B2ContactConstraint_obj::__CreateEmpty() { return  new B2ContactConstraint_obj; }
hx::ObjectPtr< B2ContactConstraint_obj > B2ContactConstraint_obj::__new()
{  hx::ObjectPtr< B2ContactConstraint_obj > result = new B2ContactConstraint_obj();
	result->__construct();
	return result;}

Dynamic B2ContactConstraint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactConstraint_obj > result = new B2ContactConstraint_obj();
	result->__construct();
	return result;}


B2ContactConstraint_obj::B2ContactConstraint_obj()
{
}

void B2ContactConstraint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactConstraint);
	HX_MARK_MEMBER_NAME(points,"points");
	HX_MARK_MEMBER_NAME(localPlaneNormal,"localPlaneNormal");
	HX_MARK_MEMBER_NAME(localPoint,"localPoint");
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_MEMBER_NAME(normalMass,"normalMass");
	HX_MARK_MEMBER_NAME(K,"K");
	HX_MARK_MEMBER_NAME(bodyA,"bodyA");
	HX_MARK_MEMBER_NAME(bodyB,"bodyB");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(radius,"radius");
	HX_MARK_MEMBER_NAME(friction,"friction");
	HX_MARK_MEMBER_NAME(restitution,"restitution");
	HX_MARK_MEMBER_NAME(pointCount,"pointCount");
	HX_MARK_MEMBER_NAME(manifold,"manifold");
	HX_MARK_END_CLASS();
}

void B2ContactConstraint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(points,"points");
	HX_VISIT_MEMBER_NAME(localPlaneNormal,"localPlaneNormal");
	HX_VISIT_MEMBER_NAME(localPoint,"localPoint");
	HX_VISIT_MEMBER_NAME(normal,"normal");
	HX_VISIT_MEMBER_NAME(normalMass,"normalMass");
	HX_VISIT_MEMBER_NAME(K,"K");
	HX_VISIT_MEMBER_NAME(bodyA,"bodyA");
	HX_VISIT_MEMBER_NAME(bodyB,"bodyB");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(radius,"radius");
	HX_VISIT_MEMBER_NAME(friction,"friction");
	HX_VISIT_MEMBER_NAME(restitution,"restitution");
	HX_VISIT_MEMBER_NAME(pointCount,"pointCount");
	HX_VISIT_MEMBER_NAME(manifold,"manifold");
}

Dynamic B2ContactConstraint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { return K; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bodyA") ) { return bodyA; }
		if (HX_FIELD_EQ(inName,"bodyB") ) { return bodyB; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"points") ) { return points; }
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"friction") ) { return friction; }
		if (HX_FIELD_EQ(inName,"manifold") ) { return manifold; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { return localPoint; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { return normalMass; }
		if (HX_FIELD_EQ(inName,"pointCount") ) { return pointCount; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { return restitution; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"localPlaneNormal") ) { return localPlaneNormal; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactConstraint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"K") ) { K=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::box2D::collision::B2ManifoldType >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"bodyA") ) { bodyA=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bodyB") ) { bodyB=inValue.Cast< ::box2D::dynamics::B2Body >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"points") ) { points=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"friction") ) { friction=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"manifold") ) { manifold=inValue.Cast< ::box2D::collision::B2Manifold >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"localPoint") ) { localPoint=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normalMass") ) { normalMass=inValue.Cast< ::box2D::common::math::B2Mat22 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pointCount") ) { pointCount=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { restitution=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"localPlaneNormal") ) { localPlaneNormal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactConstraint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("points"));
	outFields->push(HX_CSTRING("localPlaneNormal"));
	outFields->push(HX_CSTRING("localPoint"));
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("normalMass"));
	outFields->push(HX_CSTRING("K"));
	outFields->push(HX_CSTRING("bodyA"));
	outFields->push(HX_CSTRING("bodyB"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("friction"));
	outFields->push(HX_CSTRING("restitution"));
	outFields->push(HX_CSTRING("pointCount"));
	outFields->push(HX_CSTRING("manifold"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(B2ContactConstraint_obj,points),HX_CSTRING("points")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactConstraint_obj,localPlaneNormal),HX_CSTRING("localPlaneNormal")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactConstraint_obj,localPoint),HX_CSTRING("localPoint")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactConstraint_obj,normal),HX_CSTRING("normal")},
	{hx::fsObject /*::box2D::common::math::B2Mat22*/ ,(int)offsetof(B2ContactConstraint_obj,normalMass),HX_CSTRING("normalMass")},
	{hx::fsObject /*::box2D::common::math::B2Mat22*/ ,(int)offsetof(B2ContactConstraint_obj,K),HX_CSTRING("K")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2ContactConstraint_obj,bodyA),HX_CSTRING("bodyA")},
	{hx::fsObject /*::box2D::dynamics::B2Body*/ ,(int)offsetof(B2ContactConstraint_obj,bodyB),HX_CSTRING("bodyB")},
	{hx::fsObject /*::box2D::collision::B2ManifoldType*/ ,(int)offsetof(B2ContactConstraint_obj,type),HX_CSTRING("type")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraint_obj,radius),HX_CSTRING("radius")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraint_obj,friction),HX_CSTRING("friction")},
	{hx::fsFloat,(int)offsetof(B2ContactConstraint_obj,restitution),HX_CSTRING("restitution")},
	{hx::fsInt,(int)offsetof(B2ContactConstraint_obj,pointCount),HX_CSTRING("pointCount")},
	{hx::fsObject /*::box2D::collision::B2Manifold*/ ,(int)offsetof(B2ContactConstraint_obj,manifold),HX_CSTRING("manifold")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("points"),
	HX_CSTRING("localPlaneNormal"),
	HX_CSTRING("localPoint"),
	HX_CSTRING("normal"),
	HX_CSTRING("normalMass"),
	HX_CSTRING("K"),
	HX_CSTRING("bodyA"),
	HX_CSTRING("bodyB"),
	HX_CSTRING("type"),
	HX_CSTRING("radius"),
	HX_CSTRING("friction"),
	HX_CSTRING("restitution"),
	HX_CSTRING("pointCount"),
	HX_CSTRING("manifold"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactConstraint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactConstraint_obj::__mClass,"__mClass");
};

#endif

Class B2ContactConstraint_obj::__mClass;

void B2ContactConstraint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.contacts.B2ContactConstraint"), hx::TCanCast< B2ContactConstraint_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void B2ContactConstraint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace contacts
