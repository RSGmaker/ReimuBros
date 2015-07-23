#include <hxcpp.h>

#ifndef INCLUDED_box2D_dynamics_B2TimeStep
#include <box2D/dynamics/B2TimeStep.h>
#endif
namespace box2D{
namespace dynamics{

Void B2TimeStep_obj::__construct()
{
HX_STACK_FRAME("box2D.dynamics.B2TimeStep","new",0x06687b84,"box2D.dynamics.B2TimeStep.new","box2D/dynamics/B2TimeStep.hx",25,0xaed07c8c)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(40)
	this->positionIterations = (int)0;
	HX_STACK_LINE(39)
	this->velocityIterations = (int)0;
	HX_STACK_LINE(38)
	this->dtRatio = (int)0;
	HX_STACK_LINE(37)
	this->inv_dt = (int)0;
	HX_STACK_LINE(36)
	this->dt = (int)0;
}
;
	return null();
}

//B2TimeStep_obj::~B2TimeStep_obj() { }

Dynamic B2TimeStep_obj::__CreateEmpty() { return  new B2TimeStep_obj; }
hx::ObjectPtr< B2TimeStep_obj > B2TimeStep_obj::__new()
{  hx::ObjectPtr< B2TimeStep_obj > result = new B2TimeStep_obj();
	result->__construct();
	return result;}

Dynamic B2TimeStep_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< B2TimeStep_obj > result = new B2TimeStep_obj();
	result->__construct();
	return result;}

Void B2TimeStep_obj::set( ::box2D::dynamics::B2TimeStep step){
{
		HX_STACK_FRAME("box2D.dynamics.B2TimeStep","set",0x066c46c6,"box2D.dynamics.B2TimeStep.set","box2D/dynamics/B2TimeStep.hx",29,0xaed07c8c)
		HX_STACK_THIS(this)
		HX_STACK_ARG(step,"step")
		HX_STACK_LINE(30)
		this->dt = step->dt;
		HX_STACK_LINE(31)
		this->inv_dt = step->inv_dt;
		HX_STACK_LINE(32)
		this->positionIterations = step->positionIterations;
		HX_STACK_LINE(33)
		this->velocityIterations = step->velocityIterations;
		HX_STACK_LINE(34)
		this->warmStarting = step->warmStarting;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(B2TimeStep_obj,set,(void))


B2TimeStep_obj::B2TimeStep_obj()
{
}

Dynamic B2TimeStep_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dt") ) { return dt; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inv_dt") ) { return inv_dt; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dtRatio") ) { return dtRatio; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"warmStarting") ) { return warmStarting; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"velocityIterations") ) { return velocityIterations; }
		if (HX_FIELD_EQ(inName,"positionIterations") ) { return positionIterations; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic B2TimeStep_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dt") ) { dt=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inv_dt") ) { inv_dt=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dtRatio") ) { dtRatio=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"warmStarting") ) { warmStarting=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"velocityIterations") ) { velocityIterations=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"positionIterations") ) { positionIterations=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void B2TimeStep_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("dt"));
	outFields->push(HX_CSTRING("inv_dt"));
	outFields->push(HX_CSTRING("dtRatio"));
	outFields->push(HX_CSTRING("velocityIterations"));
	outFields->push(HX_CSTRING("positionIterations"));
	outFields->push(HX_CSTRING("warmStarting"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(B2TimeStep_obj,dt),HX_CSTRING("dt")},
	{hx::fsFloat,(int)offsetof(B2TimeStep_obj,inv_dt),HX_CSTRING("inv_dt")},
	{hx::fsFloat,(int)offsetof(B2TimeStep_obj,dtRatio),HX_CSTRING("dtRatio")},
	{hx::fsInt,(int)offsetof(B2TimeStep_obj,velocityIterations),HX_CSTRING("velocityIterations")},
	{hx::fsInt,(int)offsetof(B2TimeStep_obj,positionIterations),HX_CSTRING("positionIterations")},
	{hx::fsBool,(int)offsetof(B2TimeStep_obj,warmStarting),HX_CSTRING("warmStarting")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("dt"),
	HX_CSTRING("inv_dt"),
	HX_CSTRING("dtRatio"),
	HX_CSTRING("velocityIterations"),
	HX_CSTRING("positionIterations"),
	HX_CSTRING("warmStarting"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(B2TimeStep_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(B2TimeStep_obj::__mClass,"__mClass");
};

#endif

Class B2TimeStep_obj::__mClass;

void B2TimeStep_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("box2D.dynamics.B2TimeStep"), hx::TCanCast< B2TimeStep_obj> ,sStaticFields,sMemberFields,
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

void B2TimeStep_obj::__boot()
{
}

} // end namespace box2D
} // end namespace dynamics
