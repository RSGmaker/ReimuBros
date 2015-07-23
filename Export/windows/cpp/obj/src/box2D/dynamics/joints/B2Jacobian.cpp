#include <hxcpp.h>

#ifndef INCLUDED_box2D_common_math_B2Vec2
#include <box2D/common/math/B2Vec2.h>
#endif
#ifndef INCLUDED_box2D_dynamics_joints_B2Jacobian
#include <box2D/dynamics/joints/B2Jacobian.h>
#endif
namespace box2D{
namespace dynamics{
namespace joints{

Void B2Jacobian_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.joints.B2Jacobian","new",0x44acc115,"box2D.dynamics.joints.B2Jacobian.new","box2D/dynamics/joints/B2Jacobian.hx",31,0x5b8fb33a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(33)
	::box2D::common::math::B2Vec2 _g = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->linearA = _g;
	HX_STACK_LINE(34)
	::box2D::common::math::B2Vec2 _g1 = ::box2D::common::math::B2Vec2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(34)
	this->linearB = _g1;
}
;
	return null();
}

//B2Jacobian_obj::~B2Jacobian_obj() { }

Dynamic B2Jacobian_obj::__CreateEmpty() { return  new B2Jacobian_obj; }
hx::ObjectPtr< B2Jacobian_obj > B2Jacobian_obj::__new()
{  hx::ObjectPtr< B2Jacobian_obj > result = new B2Jacobian_obj();
	result->__construct();
	return result;}

Dynamic B2Jacobian_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2Jacobian_obj > result = new B2Jacobian_obj();
	result->__construct();
	return result;}

Void B2Jacobian_obj::setZero( ){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2Jacobian","setZero",0xc98d3f1f,"box2D.dynamics.joints.B2Jacobian.setZero","box2D/dynamics/joints/B2Jacobian.hx",43,0x5b8fb33a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(44)
		this->linearA->setZero();
		HX_STACK_LINE(44)
		this->angularA = 0.0;
		HX_STACK_LINE(45)
		this->linearB->setZero();
		HX_STACK_LINE(45)
		this->angularB = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(B2Jacobian_obj,setZero,(void))

Void B2Jacobian_obj::set( ::box2D::common::math::B2Vec2 x1,Float a1,::box2D::common::math::B2Vec2 x2,Float a2){
{
		HX_STACK_FRAME("box2D.dynamics.joints.B2Jacobian","set",0x44b08c57,"box2D.dynamics.joints.B2Jacobian.set","box2D/dynamics/joints/B2Jacobian.hx",47,0x5b8fb33a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(x1,"x1")
		HX_STACK_ARG(a1,"a1")
		HX_STACK_ARG(x2,"x2")
		HX_STACK_ARG(a2,"a2")
		HX_STACK_LINE(48)
		this->linearA->setV(x1);
		HX_STACK_LINE(48)
		this->angularA = a1;
		HX_STACK_LINE(49)
		this->linearB->setV(x2);
		HX_STACK_LINE(49)
		this->angularB = a2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(B2Jacobian_obj,set,(void))

Float B2Jacobian_obj::compute( ::box2D::common::math::B2Vec2 x1,Float a1,::box2D::common::math::B2Vec2 x2,Float a2){
	HX_STACK_FRAME("box2D.dynamics.joints.B2Jacobian","compute",0x369036ac,"box2D.dynamics.joints.B2Jacobian.compute","box2D/dynamics/joints/B2Jacobian.hx",54,0x5b8fb33a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x1,"x1")
	HX_STACK_ARG(a1,"a1")
	HX_STACK_ARG(x2,"x2")
	HX_STACK_ARG(a2,"a2")
	HX_STACK_LINE(54)
	return (((((this->linearA->x * x1->x) + (this->linearA->y * x1->y)) + (this->angularA * a1)) + (((this->linearB->x * x2->x) + (this->linearB->y * x2->y)))) + (this->angularB * a2));
}


HX_DEFINE_DYNAMIC_FUNC4(B2Jacobian_obj,compute,return )


B2Jacobian_obj::B2Jacobian_obj()
{
}

void B2Jacobian_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(B2Jacobian);
	HX_MARK_MEMBER_NAME(linearA,"linearA");
	HX_MARK_MEMBER_NAME(angularA,"angularA");
	HX_MARK_MEMBER_NAME(linearB,"linearB");
	HX_MARK_MEMBER_NAME(angularB,"angularB");
	HX_MARK_END_CLASS();
}

void B2Jacobian_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(linearA,"linearA");
	HX_VISIT_MEMBER_NAME(angularA,"angularA");
	HX_VISIT_MEMBER_NAME(linearB,"linearB");
	HX_VISIT_MEMBER_NAME(angularB,"angularB");
}

Dynamic B2Jacobian_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"linearA") ) { return linearA; }
		if (HX_FIELD_EQ(inName,"linearB") ) { return linearB; }
		if (HX_FIELD_EQ(inName,"setZero") ) { return setZero_dyn(); }
		if (HX_FIELD_EQ(inName,"compute") ) { return compute_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"angularA") ) { return angularA; }
		if (HX_FIELD_EQ(inName,"angularB") ) { return angularB; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2Jacobian_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"linearA") ) { linearA=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"linearB") ) { linearB=inValue.Cast< ::box2D::common::math::B2Vec2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"angularA") ) { angularA=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angularB") ) { angularB=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2Jacobian_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("linearA"));
	outFields->push(HX_CSTRING("angularA"));
	outFields->push(HX_CSTRING("linearB"));
	outFields->push(HX_CSTRING("angularB"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Jacobian_obj,linearA),HX_CSTRING("linearA")},
	{hx::fsFloat,(int)offsetof(B2Jacobian_obj,angularA),HX_CSTRING("angularA")},
	{hx::fsObject /*::box2D::common::math::B2Vec2*/ ,(int)offsetof(B2Jacobian_obj,linearB),HX_CSTRING("linearB")},
	{hx::fsFloat,(int)offsetof(B2Jacobian_obj,angularB),HX_CSTRING("angularB")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("linearA"),
	HX_CSTRING("angularA"),
	HX_CSTRING("linearB"),
	HX_CSTRING("angularB"),
	HX_CSTRING("setZero"),
	HX_CSTRING("set"),
	HX_CSTRING("compute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2Jacobian_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2Jacobian_obj::__mClass,"__mClass");
};

#endif

Class B2Jacobian_obj::__mClass;

void B2Jacobian_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.joints.B2Jacobian"), hx::TCanCast< B2Jacobian_obj> ,sStaticFields,sMemberFields,
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

void B2Jacobian_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
} // end namespace joints
