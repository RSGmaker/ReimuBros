#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2SimplexVertex
#include <box2D/collision/B2SimplexVertex.h>
#endif
#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
namespace box2D{
namespace collision{

Void B2SimplexVertex_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2SimplexVertex","new",0xfae6f49f,"box2D.collision.B2SimplexVertex.new","box2D/collision/B2SimplexVertex.hx",25,0x09fd2773)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(43)
	this->indexB = (int)0;
	HX_STACK_LINE(42)
	this->indexA = (int)0;
	HX_STACK_LINE(41)
	this->a = (int)0;
}
;
	return null();
}

//B2SimplexVertex_obj::~B2SimplexVertex_obj() { }

Dynamic B2SimplexVertex_obj::__CreateEmpty() { return  new B2SimplexVertex_obj; }
hx::ObjectPtr< B2SimplexVertex_obj > B2SimplexVertex_obj::__new()
{  hx::ObjectPtr< B2SimplexVertex_obj > result = new B2SimplexVertex_obj();
	result->__construct();
	return result;}

Dynamic B2SimplexVertex_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2SimplexVertex_obj > result = new B2SimplexVertex_obj();
	result->__construct();
	return result;}

Void B2SimplexVertex_obj::set( ::box2D::collision::B2SimplexVertex other){
{
		HX_STACK_FRAME("box2D.collision.B2SimplexVertex","set",0xfaeabfe1,"box2D.collision.B2SimplexVertex.set","box2D/collision/B2SimplexVertex.hx",29,0x09fd2773)
		HX_STACK_THIS(this)
		HX_STACK_ARG(other,"other")
		HX_STACK_LINE(30)
		this->wA->setV(other->wA);
		HX_STACK_LINE(31)
		this->wB->setV(other->wB);
		HX_STACK_LINE(32)
		this->w->setV(other->w);
		HX_STACK_LINE(33)
		this->a = other->a;
		HX_STACK_LINE(34)
		this->indexA = other->indexA;
		HX_STACK_LINE(35)
		this->indexB = other->indexB;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2SimplexVertex_obj,set,(void))


B2SimplexVertex_obj::B2SimplexVertex_obj()
{
}

void B2SimplexVertex_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2SimplexVertex);
	HX_MARK_MEMBER_NAME(wA,"wA");
	HX_MARK_MEMBER_NAME(wB,"wB");
	HX_MARK_MEMBER_NAME(w,"w");
	HX_MARK_MEMBER_NAME(a,"a");
	HX_MARK_MEMBER_NAME(indexA,"indexA");
	HX_MARK_MEMBER_NAME(indexB,"indexB");
	HX_MARK_END_CLASS();
}

void B2SimplexVertex_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(wA,"wA");
	HX_VISIT_MEMBER_NAME(wB,"wB");
	HX_VISIT_MEMBER_NAME(w,"w");
	HX_VISIT_MEMBER_NAME(a,"a");
	HX_VISIT_MEMBER_NAME(indexA,"indexA");
	HX_VISIT_MEMBER_NAME(indexB,"indexB");
}

Dynamic B2SimplexVertex_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { return w; }
		if (HX_FIELD_EQ(inName,"a") ) { return a; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"wA") ) { return wA; }
		if (HX_FIELD_EQ(inName,"wB") ) { return wB; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"indexA") ) { return indexA; }
		if (HX_FIELD_EQ(inName,"indexB") ) { return indexB; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2SimplexVertex_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"w") ) { w=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"a") ) { a=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"wA") ) { wA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wB") ) { wB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"indexA") ) { indexA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexB") ) { indexB=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2SimplexVertex_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("wA"));
	outFields->push(HX_CSTRING("wB"));
	outFields->push(HX_CSTRING("w"));
	outFields->push(HX_CSTRING("a"));
	outFields->push(HX_CSTRING("indexA"));
	outFields->push(HX_CSTRING("indexB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2SimplexVertex_obj,wA),HX_CSTRING("wA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2SimplexVertex_obj,wB),HX_CSTRING("wB")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2SimplexVertex_obj,w),HX_CSTRING("w")},
	{hx::fsFloat,(int)offsetof(B2SimplexVertex_obj,a),HX_CSTRING("a")},
	{hx::fsInt,(int)offsetof(B2SimplexVertex_obj,indexA),HX_CSTRING("indexA")},
	{hx::fsInt,(int)offsetof(B2SimplexVertex_obj,indexB),HX_CSTRING("indexB")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("wA"),
	HX_CSTRING("wB"),
	HX_CSTRING("w"),
	HX_CSTRING("a"),
	HX_CSTRING("indexA"),
	HX_CSTRING("indexB"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2SimplexVertex_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2SimplexVertex_obj::__mClass,"__mClass");
};

#endif

Class B2SimplexVertex_obj::__mClass;

void B2SimplexVertex_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2SimplexVertex"), hx::TCanCast< B2SimplexVertex_obj> ,sStaticFields,sMemberFields,
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

void B2SimplexVertex_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
