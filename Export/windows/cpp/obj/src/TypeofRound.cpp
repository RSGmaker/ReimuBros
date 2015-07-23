#include <hxcpp.h>

#ifndef INCLUDED_TypeofRound
#include <TypeofRound.h>
#endif

::TypeofRound TypeofRound_obj::Cirno;

::TypeofRound TypeofRound_obj::FireCirno;

::TypeofRound TypeofRound_obj::Normal;

::TypeofRound TypeofRound_obj::Nue;

::TypeofRound TypeofRound_obj::Rumia;

::TypeofRound TypeofRound_obj::Seija;

::TypeofRound TypeofRound_obj::Table;

::TypeofRound TypeofRound_obj::Yukari;

HX_DEFINE_CREATE_ENUM(TypeofRound_obj)

int TypeofRound_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Cirno")) return 3;
	if (inName==HX_CSTRING("FireCirno")) return 7;
	if (inName==HX_CSTRING("Normal")) return 0;
	if (inName==HX_CSTRING("Nue")) return 1;
	if (inName==HX_CSTRING("Rumia")) return 5;
	if (inName==HX_CSTRING("Seija")) return 2;
	if (inName==HX_CSTRING("Table")) return 6;
	if (inName==HX_CSTRING("Yukari")) return 4;
	return super::__FindIndex(inName);
}

int TypeofRound_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Cirno")) return 0;
	if (inName==HX_CSTRING("FireCirno")) return 0;
	if (inName==HX_CSTRING("Normal")) return 0;
	if (inName==HX_CSTRING("Nue")) return 0;
	if (inName==HX_CSTRING("Rumia")) return 0;
	if (inName==HX_CSTRING("Seija")) return 0;
	if (inName==HX_CSTRING("Table")) return 0;
	if (inName==HX_CSTRING("Yukari")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TypeofRound_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Cirno")) return Cirno;
	if (inName==HX_CSTRING("FireCirno")) return FireCirno;
	if (inName==HX_CSTRING("Normal")) return Normal;
	if (inName==HX_CSTRING("Nue")) return Nue;
	if (inName==HX_CSTRING("Rumia")) return Rumia;
	if (inName==HX_CSTRING("Seija")) return Seija;
	if (inName==HX_CSTRING("Table")) return Table;
	if (inName==HX_CSTRING("Yukari")) return Yukari;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Normal"),
	HX_CSTRING("Nue"),
	HX_CSTRING("Seija"),
	HX_CSTRING("Cirno"),
	HX_CSTRING("Yukari"),
	HX_CSTRING("Rumia"),
	HX_CSTRING("Table"),
	HX_CSTRING("FireCirno"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TypeofRound_obj::Cirno,"Cirno");
	HX_MARK_MEMBER_NAME(TypeofRound_obj::FireCirno,"FireCirno");
	HX_MARK_MEMBER_NAME(TypeofRound_obj::Normal,"Normal");
	HX_MARK_MEMBER_NAME(TypeofRound_obj::Nue,"Nue");
	HX_MARK_MEMBER_NAME(TypeofRound_obj::Rumia,"Rumia");
	HX_MARK_MEMBER_NAME(TypeofRound_obj::Seija,"Seija");
	HX_MARK_MEMBER_NAME(TypeofRound_obj::Table,"Table");
	HX_MARK_MEMBER_NAME(TypeofRound_obj::Yukari,"Yukari");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::Cirno,"Cirno");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::FireCirno,"FireCirno");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::Normal,"Normal");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::Nue,"Nue");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::Rumia,"Rumia");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::Seija,"Seija");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::Table,"Table");
	HX_VISIT_MEMBER_NAME(TypeofRound_obj::Yukari,"Yukari");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class TypeofRound_obj::__mClass;

Dynamic __Create_TypeofRound_obj() { return new TypeofRound_obj; }

void TypeofRound_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("TypeofRound"), hx::TCanCast< TypeofRound_obj >,sStaticFields,sMemberFields,
	&__Create_TypeofRound_obj, &__Create,
	&super::__SGetClass(), &CreateTypeofRound_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void TypeofRound_obj::__boot()
{
hx::Static(Cirno) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("Cirno"),3);
hx::Static(FireCirno) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("FireCirno"),7);
hx::Static(Normal) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("Normal"),0);
hx::Static(Nue) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("Nue"),1);
hx::Static(Rumia) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("Rumia"),5);
hx::Static(Seija) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("Seija"),2);
hx::Static(Table) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("Table"),6);
hx::Static(Yukari) = hx::CreateEnum< TypeofRound_obj >(HX_CSTRING("Yukari"),4);
}


