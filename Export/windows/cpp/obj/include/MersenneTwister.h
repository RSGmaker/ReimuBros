#ifndef INCLUDED_MersenneTwister
#define INCLUDED_MersenneTwister

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(MersenneTwister)


class HXCPP_CLASS_ATTRIBUTES  MersenneTwister_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MersenneTwister_obj OBJ_;
		MersenneTwister_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MersenneTwister_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MersenneTwister_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MersenneTwister"); }

		int N;
		int M;
		int MATRIX_A;
		int UPPER_MASK;
		int LOWER_MASK;
		Array< int > mt;
		int mti;
		int seed;
		int returnLength;
		int maxSize;
		Array< int > returnArray;
		virtual Array< int > twist( hx::Null< int >  TTseed,int TTreturnLength,int TTmaxSize);
		Dynamic twist_dyn();

		virtual Void init_genrand( int TTseed);
		Dynamic init_genrand_dyn();

		virtual Void init_by_array( Array< int > TTseedArray,int TTseedArrayLength);
		Dynamic init_by_array_dyn();

		virtual int genrand_int32( );
		Dynamic genrand_int32_dyn();

		virtual int genrand_int31( );
		Dynamic genrand_int31_dyn();

};


#endif /* INCLUDED_MersenneTwister */ 
