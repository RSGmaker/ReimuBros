#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_B2ContactPoint
#include <box2D/collision/B2ContactPoint.h>
#endif
#ifndef INCLUDED_box2D_collision_shapes_B2Shape
#include <box2D/collision/shapes/B2Shape.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2ContactPoint_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2ContactPoint","new",0x236eed3f,"box2D.collision.B2ContactPoint.new","box2D/collision/B2ContactPoint.hx",32,0x89b9898f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(34)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	this->position = _g;
	HX_STACK_LINE(35)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(35)
	this->velocity = _g1;
	HX_STACK_LINE(36)
	::box2D::common::math::B2Vec2 _g2 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(36)
	this->normal = _g2;
	HX_STACK_LINE(37)
	::box2D::collision::B2ContactID _g3 = ::box2D::collision::B2ContactID_obj::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(37)
	this->id = _g3;
}
;
	return null();
}

//B2ContactPoint_obj::~B2ContactPoint_obj() { }

Dynamic B2ContactPoint_obj::__CreateEmpty() { return  new B2ContactPoint_obj; }
hx::ObjectPtr< B2ContactPoint_obj > B2ContactPoint_obj::__new()
{  hx::ObjectPtr< B2ContactPoint_obj > result = new B2ContactPoint_obj();
	result->__construct();
	return result;}

Dynamic B2ContactPoint_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactPoint_obj > result = new B2ContactPoint_obj();
	result->__construct();
	return result;}


B2ContactPoint_obj::B2ContactPoint_obj()
{
}

void B2ContactPoint_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactPoint);
	HX_MARK_MEMBER_NAME(shape1,"shape1");
	HX_MARK_MEMBER_NAME(shape2,"shape2");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(velocity,"velocity");
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_MEMBER_NAME(separation,"separation");
	HX_MARK_MEMBER_NAME(friction,"friction");
	HX_MARK_MEMBER_NAME(restitution,"restitution");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_END_CLASS();
}

void B2ContactPoint_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(shape1,"shape1");
	HX_VISIT_MEMBER_NAME(shape2,"shape2");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(velocity,"velocity");
	HX_VISIT_MEMBER_NAME(normal,"normal");
	HX_VISIT_MEMBER_NAME(separation,"separation");
	HX_VISIT_MEMBER_NAME(friction,"friction");
	HX_VISIT_MEMBER_NAME(restitution,"restitution");
	HX_VISIT_MEMBER_NAME(id,"id");
}

Dynamic B2ContactPoint_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shape1") ) { return shape1; }
		if (HX_FIELD_EQ(inName,"shape2") ) { return shape2; }
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"velocity") ) { return velocity; }
		if (HX_FIELD_EQ(inName,"friction") ) { return friction; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"separation") ) { return separation; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { return restitution; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactPoint_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::box2D::collision::B2ContactID >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shape1") ) { shape1=inValue.Cast< ::box2D::collision::shapes::B2Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shape2") ) { shape2=inValue.Cast< ::box2D::collision::shapes::B2Shape >(); return inValue; }
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"velocity") ) { velocity=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"friction") ) { friction=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"separation") ) { separation=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"restitution") ) { restitution=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactPoint_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("shape1"));
	outFields->push(HX_CSTRING("shape2"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("velocity"));
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("separation"));
	outFields->push(HX_CSTRING("friction"));
	outFields->push(HX_CSTRING("restitution"));
	outFields->push(HX_CSTRING("id"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::collision::shapes::B2Shape*/ ,(int)offsetof(B2ContactPoint_obj,shape1),HX_CSTRING("shape1")},
	{hx::fsObject /*::box2D::collision::shapes::B2Shape*/ ,(int)offsetof(B2ContactPoint_obj,shape2),HX_CSTRING("shape2")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactPoint_obj,position),HX_CSTRING("position")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactPoint_obj,velocity),HX_CSTRING("velocity")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2ContactPoint_obj,normal),HX_CSTRING("normal")},
	{hx::fsFloat,(int)offsetof(B2ContactPoint_obj,separation),HX_CSTRING("separation")},
	{hx::fsFloat,(int)offsetof(B2ContactPoint_obj,friction),HX_CSTRING("friction")},
	{hx::fsFloat,(int)offsetof(B2ContactPoint_obj,restitution),HX_CSTRING("restitution")},
	{hx::fsObject /*::box2D::collision::B2ContactID*/ ,(int)offsetof(B2ContactPoint_obj,id),HX_CSTRING("id")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("shape1"),
	HX_CSTRING("shape2"),
	HX_CSTRING("position"),
	HX_CSTRING("velocity"),
	HX_CSTRING("normal"),
	HX_CSTRING("separation"),
	HX_CSTRING("friction"),
	HX_CSTRING("restitution"),
	HX_CSTRING("id"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactPoint_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactPoint_obj::__mClass,"__mClass");
};

#endif

Class B2ContactPoint_obj::__mClass;

void B2ContactPoint_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2ContactPoint"), hx::TCanCast< B2ContactPoint_obj> ,sStaticFields,sMemberFields,
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

void B2ContactPoint_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
