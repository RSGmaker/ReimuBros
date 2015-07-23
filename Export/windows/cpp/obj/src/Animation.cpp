#include <hxcpp.h>

#ifndef INCLUDED_Animation
#include <Animation.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Bitmap
#include <openfl/_v2/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif

Void Animation_obj::__construct(Array< ::Dynamic > ani)
{
HX_STACK_FRAME("Animation","new",0x6e1eb1d6,"Animation.new","Animation.hx",34,0x7224da5a)
HX_STACK_THIS(this)
HX_STACK_ARG(ani,"ani")
{
	HX_STACK_LINE(35)
	super::__construct(ani->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >(),null(),null());
	HX_STACK_LINE(38)
	this->image_index = (int)0;
	HX_STACK_LINE(39)
	this->image_speed = (int)0;
	HX_STACK_LINE(40)
	this->Limage_index = -9999999999999999;
	HX_STACK_LINE(41)
	this->animation = ani;
}
;
	return null();
}

//Animation_obj::~Animation_obj() { }

Dynamic Animation_obj::__CreateEmpty() { return  new Animation_obj; }
hx::ObjectPtr< Animation_obj > Animation_obj::__new(Array< ::Dynamic > ani)
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct(ani);
	return result;}

Dynamic Animation_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Animation_obj > result = new Animation_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Animation_obj::ChangeAnimation( Array< ::Dynamic > ani){
{
		HX_STACK_FRAME("Animation","ChangeAnimation",0xb02dd1ca,"Animation.ChangeAnimation","Animation.hx",44,0x7224da5a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ani,"ani")
		HX_STACK_LINE(44)
		if (((this->animation != ani))){
			HX_STACK_LINE(46)
			this->set_bitmapData(ani->__get((int)0).StaticCast< ::openfl::_v2::display::BitmapData >());
			HX_STACK_LINE(47)
			this->image_index = (int)0;
			HX_STACK_LINE(49)
			this->animation = ani;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animation_obj,ChangeAnimation,(void))

Void Animation_obj::animate( ){
{
		HX_STACK_FRAME("Animation","animate",0xaee4af17,"Animation.animate","Animation.hx",53,0x7224da5a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(54)
		if (((this->animation->length == (int)0))){
			HX_STACK_LINE(56)
			return null();
		}
		HX_STACK_LINE(59)
		int oldindex = ::Math_obj::floor(this->Limage_index);		HX_STACK_VAR(oldindex,"oldindex");
		HX_STACK_LINE(60)
		hx::AddEq(this->image_index,this->image_speed);
		HX_STACK_LINE(61)
		while((true)){
			HX_STACK_LINE(61)
			if ((!(((this->image_index < (int)0))))){
				HX_STACK_LINE(61)
				break;
			}
			HX_STACK_LINE(63)
			hx::AddEq(this->image_index,this->animation->length);
		}
		HX_STACK_LINE(65)
		while((true)){
			HX_STACK_LINE(65)
			if ((!(((this->image_index >= this->animation->length))))){
				HX_STACK_LINE(65)
				break;
			}
			HX_STACK_LINE(67)
			hx::SubEq(this->image_index,this->animation->length);
		}
		HX_STACK_LINE(69)
		int index = ::Math_obj::floor(this->image_index);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(70)
		if (((index != oldindex))){
			HX_STACK_LINE(72)
			this->set_bitmapData(this->animation->__get(index).StaticCast< ::openfl::_v2::display::BitmapData >());
		}
		HX_STACK_LINE(74)
		this->Limage_index = this->image_index;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Animation_obj,animate,(void))


Animation_obj::Animation_obj()
{
}

void Animation_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Animation);
	HX_MARK_MEMBER_NAME(animation,"animation");
	HX_MARK_MEMBER_NAME(Limage_index,"Limage_index");
	HX_MARK_MEMBER_NAME(image_index,"image_index");
	HX_MARK_MEMBER_NAME(image_speed,"image_speed");
	::openfl::_v2::display::Bitmap_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Animation_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(animation,"animation");
	HX_VISIT_MEMBER_NAME(Limage_index,"Limage_index");
	HX_VISIT_MEMBER_NAME(image_index,"image_index");
	HX_VISIT_MEMBER_NAME(image_speed,"image_speed");
	::openfl::_v2::display::Bitmap_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Animation_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"animate") ) { return animate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { return animation; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"image_index") ) { return image_index; }
		if (HX_FIELD_EQ(inName,"image_speed") ) { return image_speed; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"Limage_index") ) { return Limage_index; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"ChangeAnimation") ) { return ChangeAnimation_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Animation_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"animation") ) { animation=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"image_index") ) { image_index=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"image_speed") ) { image_speed=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"Limage_index") ) { Limage_index=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Animation_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("animation"));
	outFields->push(HX_CSTRING("Limage_index"));
	outFields->push(HX_CSTRING("image_index"));
	outFields->push(HX_CSTRING("image_speed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Animation_obj,animation),HX_CSTRING("animation")},
	{hx::fsFloat,(int)offsetof(Animation_obj,Limage_index),HX_CSTRING("Limage_index")},
	{hx::fsFloat,(int)offsetof(Animation_obj,image_index),HX_CSTRING("image_index")},
	{hx::fsFloat,(int)offsetof(Animation_obj,image_speed),HX_CSTRING("image_speed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("animation"),
	HX_CSTRING("Limage_index"),
	HX_CSTRING("image_index"),
	HX_CSTRING("image_speed"),
	HX_CSTRING("ChangeAnimation"),
	HX_CSTRING("animate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Animation_obj::__mClass,"__mClass");
};

#endif

Class Animation_obj::__mClass;

void Animation_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Animation"), hx::TCanCast< Animation_obj> ,sStaticFields,sMemberFields,
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

void Animation_obj::__boot()
{
}

