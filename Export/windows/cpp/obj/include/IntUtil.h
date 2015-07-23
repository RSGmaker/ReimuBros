#ifndef INCLUDED_IntUtil
#define INCLUDED_IntUtil

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IntUtil)


class HXCPP_CLASS_ATTRIBUTES  IntUtil_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef IntUtil_obj OBJ_;
		IntUtil_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< IntUtil_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~IntUtil_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("IntUtil"); }

		static int rol( int x,int n);
		static Dynamic rol_dyn();

		static int ror( int x,int n);
		static Dynamic ror_dyn();

		static ::String hexChars;
		static ::String toHex( int n,hx::Null< bool >  bigEndian);
		static Dynamic toHex_dyn();

};


#endif /* INCLUDED_IntUtil */ 
