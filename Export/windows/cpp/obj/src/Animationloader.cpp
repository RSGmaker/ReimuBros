#include <hxcpp.h>

#ifndef INCLUDED_Animationloader
#include <Animationloader.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl__v2_Assets
#include <openfl/_v2/Assets.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BitmapData
#include <openfl/_v2/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__v2_display_BlendMode
#include <openfl/_v2/display/BlendMode.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_ColorTransform
#include <openfl/_v2/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Matrix
#include <openfl/_v2/geom/Matrix.h>
#endif
#ifndef INCLUDED_openfl__v2_geom_Rectangle
#include <openfl/_v2/geom/Rectangle.h>
#endif

Void Animationloader_obj::__construct()
{
HX_STACK_FRAME("Animationloader","new",0x8138c269,"Animationloader.new","Animationloader.hx",34,0xe3e13d27)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(35)
	::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(35)
	this->Dictionary = _g;
}
;
	return null();
}

//Animationloader_obj::~Animationloader_obj() { }

Dynamic Animationloader_obj::__CreateEmpty() { return  new Animationloader_obj; }
hx::ObjectPtr< Animationloader_obj > Animationloader_obj::__new()
{  hx::ObjectPtr< Animationloader_obj > result = new Animationloader_obj();
	result->__construct();
	return result;}

Dynamic Animationloader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Animationloader_obj > result = new Animationloader_obj();
	result->__construct();
	return result;}

Array< ::Dynamic > Animationloader_obj::GetAnimation( ::String path){
	HX_STACK_FRAME("Animationloader","GetAnimation",0x8d28dc85,"Animationloader.GetAnimation","Animationloader.hx",40,0xe3e13d27)
	HX_STACK_THIS(this)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(40)
	if ((this->Dictionary->exists(path))){
		HX_STACK_LINE(42)
		return this->Dictionary->get(path);
	}
	else{
		HX_STACK_LINE(46)
		int _g = path.lastIndexOf(HX_CSTRING("E"),null());		HX_STACK_VAR(_g,"_g");
		struct _Function_2_1{
			inline static bool Block( ::String &path){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Animationloader.hx",46,0xe3e13d27)
				{
					HX_STACK_LINE(46)
					int _g1 = path.lastIndexOf(HX_CSTRING("U"),null());		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(46)
					return (_g1 == (path.length - (int)1));
				}
				return null();
			}
		};
		struct _Function_2_2{
			inline static bool Block( ::String &path){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Animationloader.hx",46,0xe3e13d27)
				{
					HX_STACK_LINE(46)
					int _g2 = path.lastIndexOf(HX_CSTRING("S"),null());		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(46)
					return (_g2 == (path.length - (int)1));
				}
				return null();
			}
		};
		HX_STACK_LINE(46)
		if (((  ((!(((  ((!(((_g == (path.length - (int)1)))))) ? bool(_Function_2_1::Block(path)) : bool(true) ))))) ? bool(_Function_2_2::Block(path)) : bool(true) ))){
			HX_STACK_LINE(48)
			int color = (int)16711680;		HX_STACK_VAR(color,"color");
			HX_STACK_LINE(49)
			Float value = (int)40;		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(50)
			int red = (int)0;		HX_STACK_VAR(red,"red");
			HX_STACK_LINE(51)
			int green = (int)0;		HX_STACK_VAR(green,"green");
			HX_STACK_LINE(52)
			int blue = (int)0;		HX_STACK_VAR(blue,"blue");
			HX_STACK_LINE(53)
			int _g3 = path.lastIndexOf(HX_CSTRING("E"),null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(53)
			if (((_g3 == (path.length - (int)1)))){
				HX_STACK_LINE(55)
				red = (int)255;
			}
			else{
				HX_STACK_LINE(57)
				int _g4 = path.lastIndexOf(HX_CSTRING("U"),null());		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(57)
				if (((_g4 == (path.length - (int)1)))){
					HX_STACK_LINE(59)
					blue = (int)255;
				}
				else{
					HX_STACK_LINE(61)
					int _g5 = path.lastIndexOf(HX_CSTRING("S"),null());		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(61)
					if (((_g5 == (path.length - (int)1)))){
						HX_STACK_LINE(63)
						green = (int)255;
					}
				}
			}
			HX_STACK_LINE(66)
			Float mul = (Float(value) / Float((int)100));		HX_STACK_VAR(mul,"mul");
			HX_STACK_LINE(68)
			Float ctMul = ((int)1 - mul);		HX_STACK_VAR(ctMul,"ctMul");
			struct _Function_3_1{
				inline static Float Block( int &red){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Animationloader.hx",70,0xe3e13d27)
					{
						HX_STACK_LINE(70)
						int _int = red;		HX_STACK_VAR(_int,"int");
						HX_STACK_LINE(70)
						return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(70)
			Float ctRedOff = ::Math_obj::round((_Function_3_1::Block(red) * mul));		HX_STACK_VAR(ctRedOff,"ctRedOff");
			struct _Function_3_2{
				inline static Float Block( int &green){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Animationloader.hx",72,0xe3e13d27)
					{
						HX_STACK_LINE(72)
						int _int = green;		HX_STACK_VAR(_int,"int");
						HX_STACK_LINE(72)
						return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(72)
			Float ctGreenOff = ::Math_obj::round((_Function_3_2::Block(green) * mul));		HX_STACK_VAR(ctGreenOff,"ctGreenOff");
			struct _Function_3_3{
				inline static Float Block( int &blue){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Animationloader.hx",74,0xe3e13d27)
					{
						HX_STACK_LINE(74)
						int _int = blue;		HX_STACK_VAR(_int,"int");
						HX_STACK_LINE(74)
						return (  (((_int < (int)0))) ? Float((4294967296.0 + _int)) : Float((_int + 0.0)) );
					}
					return null();
				}
			};
			HX_STACK_LINE(74)
			Float ctBlueOff = ::Math_obj::round((_Function_3_3::Block(blue) * mul));		HX_STACK_VAR(ctBlueOff,"ctBlueOff");
			HX_STACK_LINE(76)
			::openfl::_v2::geom::ColorTransform ct = ::openfl::_v2::geom::ColorTransform_obj::__new(ctMul,ctMul,ctMul,(int)1,ctRedOff,ctGreenOff,ctBlueOff,(int)0);		HX_STACK_VAR(ct,"ct");
			HX_STACK_LINE(80)
			::String P = path.substring((int)0,(path.length - (int)1));		HX_STACK_VAR(P,"P");
			HX_STACK_LINE(81)
			Array< ::Dynamic > lst = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(lst,"lst");
			HX_STACK_LINE(82)
			Array< ::Dynamic > O = this->GetAnimation(P);		HX_STACK_VAR(O,"O");
			HX_STACK_LINE(83)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(84)
			while((true)){
				HX_STACK_LINE(84)
				if ((!(((i < O->length))))){
					HX_STACK_LINE(84)
					break;
				}
				HX_STACK_LINE(88)
				::openfl::_v2::display::BitmapData OO = O->__get(i).StaticCast< ::openfl::_v2::display::BitmapData >()->clone();		HX_STACK_VAR(OO,"OO");
				HX_STACK_LINE(89)
				::openfl::_v2::geom::Rectangle _g6 = O->__get(i).StaticCast< ::openfl::_v2::display::BitmapData >()->get_rect();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(89)
				OO->colorTransform(_g6,ct);
				HX_STACK_LINE(90)
				lst[lst->length] = OO;
				HX_STACK_LINE(91)
				hx::AddEq(i,(int)1);
			}
			HX_STACK_LINE(93)
			this->Dictionary->set(path,lst);
			HX_STACK_LINE(94)
			return lst;
		}
		HX_STACK_LINE(96)
		int _g7 = path.lastIndexOf(HX_CSTRING("F"),null());		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(96)
		if (((_g7 == (path.length - (int)1)))){
			HX_STACK_LINE(98)
			::String P = path.substring((int)0,(path.length - (int)1));		HX_STACK_VAR(P,"P");
			HX_STACK_LINE(99)
			Array< ::Dynamic > lst = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(lst,"lst");
			HX_STACK_LINE(100)
			Array< ::Dynamic > O = this->GetAnimation(P);		HX_STACK_VAR(O,"O");
			HX_STACK_LINE(101)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(102)
			while((true)){
				HX_STACK_LINE(102)
				if ((!(((i < O->length))))){
					HX_STACK_LINE(102)
					break;
				}
				HX_STACK_LINE(105)
				lst[lst->length] = this->flipBitmapData(O->__get(i).StaticCast< ::openfl::_v2::display::BitmapData >(),HX_CSTRING("x"));
				HX_STACK_LINE(106)
				hx::AddEq(i,(int)1);
			}
			HX_STACK_LINE(108)
			this->Dictionary->set(path,lst);
			HX_STACK_LINE(109)
			return lst;
		}
		else{
			HX_STACK_LINE(114)
			Array< ::Dynamic > lst = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(lst,"lst");
			HX_STACK_LINE(115)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(117)
			::String str = (((HX_CSTRING("assets/Sprites/") + path) + i) + HX_CSTRING(".png"));		HX_STACK_VAR(str,"str");
			HX_STACK_LINE(118)
			::openfl::_v2::display::BitmapData bd = ::openfl::_v2::Assets_obj::getBitmapData(str,null());		HX_STACK_VAR(bd,"bd");
			HX_STACK_LINE(120)
			while((true)){
				HX_STACK_LINE(120)
				if ((!(((bd != null()))))){
					HX_STACK_LINE(120)
					break;
				}
				HX_STACK_LINE(122)
				lst[lst->length] = bd;
				HX_STACK_LINE(123)
				hx::AddEq(i,(int)1);
				HX_STACK_LINE(124)
				str = (((HX_CSTRING("assets/Sprites/") + path) + i) + HX_CSTRING(".png"));
				HX_STACK_LINE(125)
				::openfl::_v2::display::BitmapData _g8 = ::openfl::_v2::Assets_obj::getBitmapData(str,null());		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(125)
				bd = _g8;
			}
			HX_STACK_LINE(127)
			this->Dictionary->set(path,lst);
			HX_STACK_LINE(129)
			return lst;
		}
	}
	HX_STACK_LINE(40)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Animationloader_obj,GetAnimation,return )

::openfl::_v2::display::BitmapData Animationloader_obj::flipBitmapData( ::openfl::_v2::display::BitmapData original,::String __o_axis){
::String axis = __o_axis.Default(HX_CSTRING("x"));
	HX_STACK_FRAME("Animationloader","flipBitmapData",0xe87fef5d,"Animationloader.flipBitmapData","Animationloader.hx",135,0xe3e13d27)
	HX_STACK_THIS(this)
	HX_STACK_ARG(original,"original")
	HX_STACK_ARG(axis,"axis")
{
		HX_STACK_LINE(136)
		int _g = original->get_width();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(136)
		int _g1 = original->get_height();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(136)
		::openfl::_v2::display::BitmapData flipped = ::openfl::_v2::display::BitmapData_obj::__new(_g,_g1,true,(int)0,null());		HX_STACK_VAR(flipped,"flipped");
		HX_STACK_LINE(137)
		::openfl::_v2::geom::Matrix matrix;		HX_STACK_VAR(matrix,"matrix");
		HX_STACK_LINE(138)
		if (((axis == HX_CSTRING("x")))){
			HX_STACK_LINE(139)
			int _g2 = original->get_width();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(139)
			::openfl::_v2::geom::Matrix _g3 = ::openfl::_v2::geom::Matrix_obj::__new((int)-1,(int)0,(int)0,(int)1,_g2,(int)0);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(139)
			matrix = _g3;
		}
		else{
			HX_STACK_LINE(141)
			int _g4 = original->get_height();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(141)
			::openfl::_v2::geom::Matrix _g5 = ::openfl::_v2::geom::Matrix_obj::__new((int)1,(int)0,(int)0,(int)-1,(int)0,_g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(141)
			matrix = _g5;
		}
		HX_STACK_LINE(143)
		flipped->draw(original,matrix,null(),null(),null(),true);
		HX_STACK_LINE(144)
		return flipped;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Animationloader_obj,flipBitmapData,return )


Animationloader_obj::Animationloader_obj()
{
}

void Animationloader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Animationloader);
	HX_MARK_MEMBER_NAME(Dictionary,"Dictionary");
	HX_MARK_END_CLASS();
}

void Animationloader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(Dictionary,"Dictionary");
}

Dynamic Animationloader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"Dictionary") ) { return Dictionary; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"GetAnimation") ) { return GetAnimation_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"flipBitmapData") ) { return flipBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Animationloader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"Dictionary") ) { Dictionary=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Animationloader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("Dictionary"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Animationloader_obj,Dictionary),HX_CSTRING("Dictionary")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Dictionary"),
	HX_CSTRING("GetAnimation"),
	HX_CSTRING("flipBitmapData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Animationloader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Animationloader_obj::__mClass,"__mClass");
};

#endif

Class Animationloader_obj::__mClass;

void Animationloader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Animationloader"), hx::TCanCast< Animationloader_obj> ,sStaticFields,sMemberFields,
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

void Animationloader_obj::__boot()
{
}

