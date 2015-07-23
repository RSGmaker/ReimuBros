#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2AABB
#include <box2D/collision/B2AABB.h>
#endif
#ifndef INCLUDED_box2D_collision_B2DynamicTreeNode
#include <box2D/collision/B2DynamicTreeNode.h>
#endif
namespace box2D{
namespace collision{

Void B2DynamicTreeNode_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2DynamicTreeNode","new",0xe4e65af4,"box2D.collision.B2DynamicTreeNode.new","box2D/collision/B2DynamicTreeNode.hx",32,0x6f9b973e)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(33)
	::box2D::collision::B2AABB _g = ::box2D::collision::B2AABB_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->aabb = _g;
	HX_STACK_LINE(34)
	int _g1 = (::box2D::collision::B2DynamicTreeNode_obj::currentID)++;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->id = _g1;
}
;
	return null();
}

//B2DynamicTreeNode_obj::~B2DynamicTreeNode_obj() { }

Dynamic B2DynamicTreeNode_obj::__CreateEmpty() { return  new B2DynamicTreeNode_obj; }
hx::ObjectPtr< B2DynamicTreeNode_obj > B2DynamicTreeNode_obj::__new()
{  hx::ObjectPtr< B2DynamicTreeNode_obj > result = new B2DynamicTreeNode_obj();
	result->__construct();
	return result;}

Dynamic B2DynamicTreeNode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2DynamicTreeNode_obj > result = new B2DynamicTreeNode_obj();
	result->__construct();
	return result;}

bool B2DynamicTreeNode_obj::isLeaf( ){
	HX_STACK_FRAME("box2D.collision.B2DynamicTreeNode","isLeaf",0xc10a1294,"box2D.collision.B2DynamicTreeNode.isLeaf","box2D/collision/B2DynamicTreeNode.hx",39,0x6f9b973e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(39)
	return (this->child1 == null());
}


HX_DEFINE_DYNAMIC_FUNC0(B2DynamicTreeNode_obj,isLeaf,return )

int B2DynamicTreeNode_obj::currentID;


B2DynamicTreeNode_obj::B2DynamicTreeNode_obj()
{
}

void B2DynamicTreeNode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2DynamicTreeNode);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(userData,"userData");
	HX_MARK_MEMBER_NAME(aabb,"aabb");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(child1,"child1");
	HX_MARK_MEMBER_NAME(child2,"child2");
	HX_MARK_END_CLASS();
}

void B2DynamicTreeNode_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(userData,"userData");
	HX_VISIT_MEMBER_NAME(aabb,"aabb");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(child1,"child1");
	HX_VISIT_MEMBER_NAME(child2,"child2");
}

Dynamic B2DynamicTreeNode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"aabb") ) { return aabb; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"isLeaf") ) { return isLeaf_dyn(); }
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		if (HX_FIELD_EQ(inName,"child1") ) { return child1; }
		if (HX_FIELD_EQ(inName,"child2") ) { return child2; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { return userData; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"currentID") ) { return currentID; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2DynamicTreeNode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"aabb") ) { aabb=inValue.Cast< ::box2D::collision::B2AABB >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"child1") ) { child1=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		if (HX_FIELD_EQ(inName,"child2") ) { child2=inValue.Cast< ::box2D::collision::B2DynamicTreeNode >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"userData") ) { userData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"currentID") ) { currentID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2DynamicTreeNode_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("userData"));
	outFields->push(HX_CSTRING("aabb"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("child1"));
	outFields->push(HX_CSTRING("child2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("currentID"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(B2DynamicTreeNode_obj,id),HX_CSTRING("id")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(B2DynamicTreeNode_obj,userData),HX_CSTRING("userData")},
	{hx::fsObject /*::box2D::collision::B2AABB*/ ,(int)offsetof(B2DynamicTreeNode_obj,aabb),HX_CSTRING("aabb")},
	{hx::fsObject /*::box2D::collision::B2DynamicTreeNode*/ ,(int)offsetof(B2DynamicTreeNode_obj,parent),HX_CSTRING("parent")},
	{hx::fsObject /*::box2D::collision::B2DynamicTreeNode*/ ,(int)offsetof(B2DynamicTreeNode_obj,child1),HX_CSTRING("child1")},
	{hx::fsObject /*::box2D::collision::B2DynamicTreeNode*/ ,(int)offsetof(B2DynamicTreeNode_obj,child2),HX_CSTRING("child2")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("isLeaf"),
	HX_CSTRING("userData"),
	HX_CSTRING("aabb"),
	HX_CSTRING("parent"),
	HX_CSTRING("child1"),
	HX_CSTRING("child2"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2DynamicTreeNode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(B2DynamicTreeNode_obj::currentID,"currentID");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2DynamicTreeNode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(B2DynamicTreeNode_obj::currentID,"currentID");
};

#endif

Class B2DynamicTreeNode_obj::__mClass;

void B2DynamicTreeNode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2DynamicTreeNode"), hx::TCanCast< B2DynamicTreeNode_obj> ,sStaticFields,sMemberFields,
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

void B2DynamicTreeNode_obj::__boot()
{
	currentID= (int)0;
}

} // end namespace box2D
} // end namespace collision
