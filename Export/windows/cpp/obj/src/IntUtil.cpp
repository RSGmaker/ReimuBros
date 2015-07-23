#include <hxcpp.h>

#ifndef INCLUDED_IntUtil
#include <IntUtil.h>
#endif

Void IntUtil_obj::__construct()
{
	return null();
}

//IntUtil_obj::~IntUtil_obj() { }

Dynamic IntUtil_obj::__CreateEmpty() { return  new IntUtil_obj; }
hx::ObjectPtr< IntUtil_obj > IntUtil_obj::__new()
{  hx::ObjectPtr< IntUtil_obj > result = new IntUtil_obj();
	result->__construct();
	return result;}

Dynamic IntUtil_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IntUtil_obj > result = new IntUtil_obj();
	result->__construct();
	return result;}

int IntUtil_obj::rol( int x,int n){
	HX_STACK_FRAME("IntUtil","rol",0x13c79b92,"IntUtil.rol","IntUtil.hx",51,0x507282ed)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(n,"n")
	HX_STACK_LINE(51)
	return (int((int(x) << int(n))) | int(hx::UShr(x,((int)32 - n))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(IntUtil_obj,rol,return )

int IntUtil_obj::ror( int x,int n){
	HX_STACK_FRAME("IntUtil","ror",0x13c79b98,"IntUtil.ror","IntUtil.hx",61,0x507282ed)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(n,"n")
	HX_STACK_LINE(62)
	int nn = ((int)32 - n);		HX_STACK_VAR(nn,"nn");
	HX_STACK_LINE(63)
	return (int((int(x) << int(nn))) | int(hx::UShr(x,((int)32 - nn))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(IntUtil_obj,ror,return )

::String IntUtil_obj::hexChars;

::String IntUtil_obj::toHex( int n,hx::Null< bool >  __o_bigEndian){
bool bigEndian = __o_bigEndian.Default(false);
	HX_STACK_FRAME("IntUtil","toHex",0x70455463,"IntUtil.toHex","IntUtil.hx",81,0x507282ed)
	HX_STACK_ARG(n,"n")
	HX_STACK_ARG(bigEndian,"bigEndian")
{
		HX_STACK_LINE(82)
		::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(84)
		if ((bigEndian)){
			HX_STACK_LINE(86)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(87)
			while((true)){
				HX_STACK_LINE(87)
				if ((!(((i < (int)4))))){
					HX_STACK_LINE(87)
					break;
				}
				HX_STACK_LINE(88)
				::String _g = ::IntUtil_obj::hexChars.charAt((int((int(n) >> int((((((int)3 - i)) * (int)8) + (int)4)))) & int((int)15)));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(89)
				::String _g1 = ::IntUtil_obj::hexChars.charAt((int((int(n) >> int(((((int)3 - i)) * (int)8)))) & int((int)15)));		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(88)
				::String _g2 = (_g + _g1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(88)
				hx::AddEq(s,_g2);
				HX_STACK_LINE(90)
				(i)++;
			}
		}
		else{
			HX_STACK_LINE(94)
			int x = (int)0;		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(95)
			while((true)){
				HX_STACK_LINE(95)
				if ((!(((x < (int)4))))){
					HX_STACK_LINE(95)
					break;
				}
				HX_STACK_LINE(96)
				::String _g3 = ::IntUtil_obj::hexChars.charAt((int((int(n) >> int(((x * (int)8) + (int)4)))) & int((int)15)));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(97)
				::String _g4 = ::IntUtil_obj::hexChars.charAt((int((int(n) >> int((x * (int)8)))) & int((int)15)));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(96)
				::String _g5 = (_g3 + _g4);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(96)
				hx::AddEq(s,_g5);
				HX_STACK_LINE(98)
				(x)++;
			}
		}
		HX_STACK_LINE(102)
		return s;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(IntUtil_obj,toHex,return )


IntUtil_obj::IntUtil_obj()
{
}

Dynamic IntUtil_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rol") ) { return rol_dyn(); }
		if (HX_FIELD_EQ(inName,"ror") ) { return ror_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"toHex") ) { return toHex_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hexChars") ) { return hexChars; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic IntUtil_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"hexChars") ) { hexChars=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void IntUtil_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("rol"),
	HX_CSTRING("ror"),
	HX_CSTRING("hexChars"),
	HX_CSTRING("toHex"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IntUtil_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(IntUtil_obj::hexChars,"hexChars");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IntUtil_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(IntUtil_obj::hexChars,"hexChars");
};

#endif

Class IntUtil_obj::__mClass;

void IntUtil_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("IntUtil"), hx::TCanCast< IntUtil_obj> ,sStaticFields,sMemberFields,
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

void IntUtil_obj::__boot()
{
	hexChars= HX_CSTRING("0123456789abcdef");
}

