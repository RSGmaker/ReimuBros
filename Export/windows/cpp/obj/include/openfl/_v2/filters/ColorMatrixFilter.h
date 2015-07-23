#ifndef INCLUDED_openfl__v2_filters_ColorMatrixFilter
#define INCLUDED_openfl__v2_filters_ColorMatrixFilter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/_v2/filters/BitmapFilter.h>
HX_DECLARE_CLASS3(openfl,_v2,filters,BitmapFilter)
HX_DECLARE_CLASS3(openfl,_v2,filters,ColorMatrixFilter)
namespace openfl{
namespace _v2{
namespace filters{


class HXCPP_CLASS_ATTRIBUTES  ColorMatrixFilter_obj : public ::openfl::_v2::filters::BitmapFilter_obj{
	public:
		typedef ::openfl::_v2::filters::BitmapFilter_obj super;
		typedef ColorMatrixFilter_obj OBJ_;
		ColorMatrixFilter_obj();
		Void __construct(Array< Float > matrix);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColorMatrixFilter_obj > __new(Array< Float > matrix);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColorMatrixFilter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColorMatrixFilter"); }

		Array< Float > matrix;
		virtual ::openfl::_v2::filters::BitmapFilter clone( );

};

} // end namespace openfl
} // end namespace _v2
} // end namespace filters

#endif /* INCLUDED_openfl__v2_filters_ColorMatrixFilter */ 
