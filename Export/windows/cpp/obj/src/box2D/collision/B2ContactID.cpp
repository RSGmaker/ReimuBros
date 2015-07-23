#include <hxcpp.h>

#ifndef INCLUDED_box2D_collision_B2ContactID
#include <box2D/collision/B2ContactID.h>
#endif
#ifndef INCLUDED_box2D_collision_Features
#include <box2D/collision/Features.h>
#endif
namespace box2D{
namespace collision{

Void B2ContactID_obj::__construct()
{
HX_STACK_FRAME("box2D.collision.B2ContactID","new",0x28619610,"box2D.collision.B2ContactID.new","box2D/collision/B2ContactID.hx",26,0xd425b622)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(56)
	this->_key = (int)0;
	HX_STACK_LINE(29)
	::box2D::collision::Features _g = ::box2D::collision::Features_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(29)
	this->features = _g;
	HX_STACK_LINE(30)
	this->features->_m_id = hx::ObjectPtr<OBJ_>(this);
}
;
	return null();
}

//B2ContactID_obj::~B2ContactID_obj() { }

Dynamic B2ContactID_obj::__CreateEmpty() { return  new B2ContactID_obj; }
hx::ObjectPtr< B2ContactID_obj > B2ContactID_obj::__new()
{  hx::ObjectPtr< B2ContactID_obj > result = new B2ContactID_obj();
	result->__construct();
	return result;}

Dynamic B2ContactID_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2ContactID_obj > result = new B2ContactID_obj();
	result->__construct();
	return result;}

Void B2ContactID_obj::set( ::box2D::collision::B2ContactID id){
{
		HX_STACK_FRAME("box2D.collision.B2ContactID","set",0x28656152,"box2D.collision.B2ContactID.set","box2D/collision/B2ContactID.hx",33,0xd425b622)
		HX_STACK_THIS(this)
		HX_STACK_ARG(id,"id")
		HX_STACK_LINE(33)
		this->set_key(id->_key);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactID_obj,set,(void))

::box2D::collision::B2ContactID B2ContactID_obj::copy( ){
	HX_STACK_FRAME("box2D.collision.B2ContactID","copy",0x25c3f005,"box2D.collision.B2ContactID.copy","box2D/collision/B2ContactID.hx",35,0xd425b622)
	HX_STACK_THIS(this)
	HX_STACK_LINE(36)
	::box2D::collision::B2ContactID id = ::box2D::collision::B2ContactID_obj::__new();		HX_STACK_VAR(id,"id");
	HX_STACK_LINE(37)
	int _g = this->get_key();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(37)
	id->set_key(_g);
	HX_STACK_LINE(38)
	return id;
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactID_obj,copy,return )

int B2ContactID_obj::get_key( ){
	HX_STACK_FRAME("box2D.collision.B2ContactID","get_key",0x2020afe6,"box2D.collision.B2ContactID.get_key","box2D/collision/B2ContactID.hx",44,0xd425b622)
	HX_STACK_THIS(this)
	HX_STACK_LINE(44)
	return this->_key;
}


HX_DEFINE_DYNAMIC_FUNC0(B2ContactID_obj,get_key,return )

int B2ContactID_obj::set_key( int value){
	HX_STACK_FRAME("box2D.collision.B2ContactID","set_key",0x132240f2,"box2D.collision.B2ContactID.set_key","box2D/collision/B2ContactID.hx",46,0xd425b622)
	HX_STACK_THIS(this)
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(47)
	this->_key = value;
	HX_STACK_LINE(48)
	this->features->_referenceEdge = (int(this->_key) & int((int)255));
	HX_STACK_LINE(49)
	this->features->_incidentEdge = (int((int(((int(this->_key) & int((int)65280)))) >> int((int)8))) & int((int)255));
	HX_STACK_LINE(50)
	this->features->_incidentVertex = (int((int(((int(this->_key) & int((int)16711680)))) >> int((int)16))) & int((int)255));
	HX_STACK_LINE(51)
	this->features->_flip = (int((int(((int(this->_key) & int((int)-16777216)))) >> int((int)24))) & int((int)255));
	HX_STACK_LINE(52)
	return this->_key;
}


HX_DEFINE_DYNAMIC_FUNC1(B2ContactID_obj,set_key,return )


B2ContactID_obj::B2ContactID_obj()
{
}

void B2ContactID_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2ContactID);
	HX_MARK_MEMBER_NAME(features,"features");
	HX_MARK_MEMBER_NAME(_key,"_key");
	HX_MARK_END_CLASS();
}

void B2ContactID_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(features,"features");
	HX_VISIT_MEMBER_NAME(_key,"_key");
}

Dynamic B2ContactID_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		if (HX_FIELD_EQ(inName,"key") ) { return get_key(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		if (HX_FIELD_EQ(inName,"_key") ) { return _key; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_key") ) { return get_key_dyn(); }
		if (HX_FIELD_EQ(inName,"set_key") ) { return set_key_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"features") ) { return features; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2ContactID_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"key") ) { return set_key(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"_key") ) { _key=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"features") ) { features=inValue.Cast< ::box2D::collision::Features >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2ContactID_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("key"));
	outFields->push(HX_CSTRING("features"));
	outFields->push(HX_CSTRING("_key"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::collision::Features*/ ,(int)offsetof(B2ContactID_obj,features),HX_CSTRING("features")},
	{hx::fsInt,(int)offsetof(B2ContactID_obj,_key),HX_CSTRING("_key")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("copy"),
	HX_CSTRING("get_key"),
	HX_CSTRING("set_key"),
	HX_CSTRING("features"),
	HX_CSTRING("_key"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2ContactID_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2ContactID_obj::__mClass,"__mClass");
};

#endif

Class B2ContactID_obj::__mClass;

void B2ContactID_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.collision.B2ContactID"), hx::TCanCast< B2ContactID_obj> ,sStaticFields,sMemberFields,
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

void B2ContactID_obj::__boot()
{
}

} // end namespace box2D
} // end namespace collision
