#ifndef INCLUDED_openfl_errors_IOError
#define INCLUDED_openfl_errors_IOError

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/errors/Error.h>
HX_DECLARE_CLASS2(openfl,errors,Error)
HX_DECLARE_CLASS2(openfl,errors,IOError)
namespace openfl{
namespace errors{


class HXCPP_CLASS_ATTRIBUTES  IOError_obj : public ::openfl::errors::Error_obj{
	public:
		typedef ::openfl::errors::Error_obj super;
		typedef IOError_obj OBJ_;
		IOError_obj();
		Void __construct(::String __o_message);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< IOError_obj > __new(::String __o_message);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~IOError_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("IOError"); }

};

} // end namespace openfl
} // end namespace errors

#endif /* INCLUDED_openfl_errors_IOError */ 
