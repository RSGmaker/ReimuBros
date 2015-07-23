#ifndef INCLUDED_MD5
#define INCLUDED_MD5

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(MD5)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS3(openfl,_v2,utils,ByteArray)
HX_DECLARE_CLASS3(openfl,_v2,utils,IDataInput)
HX_DECLARE_CLASS3(openfl,_v2,utils,IDataOutput)
HX_DECLARE_CLASS3(openfl,_v2,utils,IMemoryRange)


class HXCPP_CLASS_ATTRIBUTES  MD5_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MD5_obj OBJ_;
		MD5_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MD5_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MD5_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("MD5"); }

		static ::openfl::_v2::utils::ByteArray digest;
		static ::String hash( ::String s);
		static Dynamic hash_dyn();

		static ::String hashBytes( ::openfl::_v2::utils::ByteArray s);
		static Dynamic hashBytes_dyn();

		static ::String hashBinary( ::openfl::_v2::utils::ByteArray s);
		static Dynamic hashBinary_dyn();

		static int f( int x,int y,int z);
		static Dynamic f_dyn();

		static int g( int x,int y,int z);
		static Dynamic g_dyn();

		static int h( int x,int y,int z);
		static Dynamic h_dyn();

		static int i( int x,int y,int z);
		static Dynamic i_dyn();

		static int transform( Dynamic func,int a,int b,int c,int d,int x,int s,int t);
		static Dynamic transform_dyn();

		static int ff( int a,int b,int c,int d,int x,int s,int t);
		static Dynamic ff_dyn();

		static int gg( int a,int b,int c,int d,int x,int s,int t);
		static Dynamic gg_dyn();

		static int hh( int a,int b,int c,int d,int x,int s,int t);
		static Dynamic hh_dyn();

		static int ii( int a,int b,int c,int d,int x,int s,int t);
		static Dynamic ii_dyn();

		static Array< int > createBlocks( ::openfl::_v2::utils::ByteArray s);
		static Dynamic createBlocks_dyn();

};


#endif /* INCLUDED_MD5 */ 
